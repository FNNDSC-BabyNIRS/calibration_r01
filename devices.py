
from __future__ import absolute_import, division, print_function
from builtins import *  # @UnusedWildImport

from mcculw import ul
from mcculw.device_info import DaqDeviceInfo
from mcculw.enums import *


try:
    from mcculw.console_examples_util import config_first_detected_device
except ImportError:
    from mcculw.console_examples_util import config_first_detected_device
import numpy as np
from time import perf_counter_ns 
import matplotlib.pyplot as plt
import pandas as pd

import time
import os
import sys
import libtiepie
from tiepie.printinfo import *
from matplotlib import rc
import socket


# Using the DAC device for outputting a signal 


# Before using this function check the maximum voltage of the DAC device with the following code: 


def steps_voltage_dac(total_time_measurement_,time_per_step_,board_num_,channel_out_,ao_range_,voltage_array_,,read_voltage):
    time = 0; time_recording = [time]; n = 0
    time_per_step_updated_ = time_per_step_
    ul.v_out(board_num_, channel_out_, ao_range_, voltage_array_[n])
    if read_voltage: 
        voltage_recording = [ul.v_in(board_num_,0,ULRange.BIP20VOLTS)]
        time_zero = perf_counter_ns()
        while time < total_time_measurement_:
                if time > time_per_step_updated_:
                    n=n+1
                    ul.v_out(board_num_,channel_out_,ao_range_,voltage_array_[n])
                    time_per_step_updated_ = time_per_step_ * (n+1)

                value = ul.v_in(board_num_,0,ULRange.BIP20VOLTS)
                time = (perf_counter_ns()-time_zero) * (10**(-9))
                voltage_recording = np.append(voltage_recording,value)
                time_recording = np.append(time_recording,time)
        return time_recording, voltage_recording
    
    else: 
        time_zero = perf_counter_ns()
        while time < total_time_measurement_:
                    if time > time_per_step_updated_:
                        n=n+1
                        ul.v_out(board_num_,channel_out_,ao_range_,voltage_array_[n])
                        time_per_step_updated_ = time_per_step_ * (n+1)

                    value = ul.v_in(board_num_,0,ULRange.BIP20VOLTS)
                    time = (perf_counter_ns()-time_zero) * (10**(-9))
                    time_recording = np.append(time_recording,time)
        return time_recording


'''
    use_device_detection = True
    dev_id_list = []
    board_num = 0
    channel_in= 0
    channel_out = 0
    config_first_detected_device(board_num, dev_id_list)
    daq_dev_info = DaqDeviceInfo(board_num)
    ao_info = daq_dev_info.get_ao_info()
    ao_range = ao_info.supported_ranges[0]
    max_voltage = ao_range.range_max
'''
def output_voltage_dac(voltage_array,time_per_step,read, tiepie_channel_range, tiepie_sample_frequency):
    use_device_detection = True
    dev_id_list = []
    board_num = 0
    channel_in= 0
    channel_out = 0
    config_first_detected_device(board_num, dev_id_list)
    daq_dev_info = DaqDeviceInfo(board_num)
    ao_info = daq_dev_info.get_ao_info()
    ao_range = ao_info.supported_ranges[0]
    max_voltage = ao_range.range_max
    if any(voltage_array>max_voltage):
        raise ValueError(f"Voltage array is higher than the max_voltage of the device: {max_voltage}")
    
    n = 0
    ul.v_out(board_num, channel_out, ao_range, voltage_array[n])

    time_per_step_updated = time_per_step
    total_time_measurement = time_per_step * len(voltage_array) 

    if read == 'BlueBox': 
        
        time_recording_bb, voltage_recording_bb = steps_voltage_dac(total_time_measurement,time_per_step,board_num,channel_out,ao_range,voltage_array,True)
        return voltage_recording_bb, time_recording_bb

    elif read == 'Tiepie':
        print('Tiepie information')
        print_library_info() 
        libtiepie.network.auto_detect_enabled = True

        # Search for devices:
        libtiepie.device_list.update()

        # Try to open an oscilloscope with block measurement support:
        scp = None
        for item in libtiepie.device_list:
            if item.can_open(libtiepie.DEVICETYPE_OSCILLOSCOPE):
                scp = item.open_oscilloscope()
                if scp.measure_modes & libtiepie.MM_BLOCK:
                    break
                else:
                    scp = None

        if scp:
            try:
                # Set measure mode:
                scp.measure_mode = libtiepie.MM_BLOCK
                # Set sample frequency:
                scp.sample_frequency = tiepie_sample_frequency  # 1 MHz = 1e6

                # Set record length:
                extra_samples = 100
                scp.record_length = (scp.sample_frequency*total_time_measurement) + extra_samples

                # Set pre sample ratio:
                scp.pre_sample_ratio = 0  # 0 %

                # For all channels:
                for ch in scp.channels:
                    # Enable channel to measure it:
                    ch.enabled = True

                    # Set range:
                    ch.range = tiepie_channel_range  # 400mv

                    # Set coupling:
                    ch.coupling = libtiepie.CK_DCV  # DC Volt

                # Set trigger timeout:
                scp.trigger_time_out = 100e-3  # 100 ms

                # Disable all channel trigger sources:
                for ch in scp.channels:
                    ch.trigger.enabled = False

                # Setup channel trigger:
                ch = scp.channels[0]  # Ch 1

                # Enable trigger source:
                ch.trigger.enabled = True

                # Kind:
                ch.trigger.kind = libtiepie.TK_RISINGEDGE  # Rising edge

                # Level:
                ch.trigger.levels[0] = 0.5  # 50 %

                # Hysteresis:
                ch.trigger.hystereses[0] = 0.05  # 5 %

                # Print oscilloscope info:

                print_device_info(scp)

                # Start measurement:
                scp.start()
                time_recording_bb = steps_voltage_dac(total_time_measurement,time_per_step,board_num,channel_out,ao_range,voltage_array,False)

                # Wait for measurement to complete:
                while not scp.is_data_ready:
                    time.sleep(0.01)  # 10 ms delay, to save CPU time

                # Get data:
                data = scp.get_data()

                csv_file = open('OscilloscopeBlock_.csv', 'w')
                try:
                    csv_file.write('Sample')
                    for i in range(len(data)):
                        csv_file.write(';Ch' + str(i + 1))
                    csv_file.write(os.linesep)
                    for i in range(len(data[0])):
                        csv_file.write(str(i))
                        for j in range(len(data)):
                            csv_file.write(';' + str(data[j][i]))
                        csv_file.write(os.linesep)

                    print()
                    print('Data written to: ' + csv_file.name)
                    df = pd.read_csv('OscilloscopeBlock_.csv', delimiter=';')  


                finally:
                    csv_file.close()


            except Exception as e:
                print('Exception: ' + e.message)
                sys.exit

        else:
            print('No oscilloscope available with block measurement support!')
            exit

        exit
        return df, time_recording_bb

    


        
                






