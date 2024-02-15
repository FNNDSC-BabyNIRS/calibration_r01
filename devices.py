
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
from tiepie.Tiepie_Examples.printinfo import *
from matplotlib import rc
import socket


# Using the DAC device for outputting a signal 


# Before using this function check the maximum voltage of the DAC device with the following code: 
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
def output_voltage_dac(min_voltage, max_voltage, number_of_steps,time_per_steps,time_per_step):
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
    