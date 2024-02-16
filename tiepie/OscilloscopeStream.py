# OscilloscopeStream.py
#
# This example performs a stream mode measurement and writes the data to OscilloscopeStream.csv.
#
# Find more information on http://www.tiepie.com/LibTiePie .

import time
import sys
import csv
import libtiepie
from printinfo import *

# Print library info:
print_library_info()

# Enable network search:
libtiepie.network.auto_detect_enabled = True

# Search for devices:
libtiepie.device_list.update()

# Try to open an oscilloscope with stream measurement support:
scp = None
for item in libtiepie.device_list:
    if item.can_open(libtiepie.DEVICETYPE_OSCILLOSCOPE):
        scp = item.open_oscilloscope()
        if scp.measure_modes & libtiepie.MM_STREAM:
            break
        else:
            scp = None

if scp:
    try:
        # Set measure mode:
        scp.measure_mode = libtiepie.MM_STREAM

        # Set sample rate:
        scp.sample_rate = 1e3  # 1 kHz

        # Set record length:
        scp.record_length = 1000  # 1 kS

        # For all channels:
        for ch in scp.channels:
            # Enable channel to measure it:
            ch.enabled = True

            # Set range:
            ch.range = 8  # 8 V

            # Set coupling:
            ch.coupling = libtiepie.CK_DCV  # DC Volt

        # Print oscilloscope info:
        print_device_info(scp)

        # Start measurement:
        scp.start()

        with open('OscilloscopeStream.csv', 'w', newline='') as csvfile:
            writer = csv.writer(csvfile)

            # Write csv header:
            writer.writerow(['Sample'] + [f'Ch{i + 1}' for i in range(len(scp.channels))])

            # Measure 10 chunks:
            print()
            sample = 0
            for chunk in range(10):
                # Print a message, to inform the user that we still do something:
                print(f'Data chunk {chunk + 1}')

                # Wait for measurement to complete:
                while not (scp.is_data_ready or scp.is_data_overflow):
                    time.sleep(0.01)  # 10 ms delay, to save CPU time

                if scp.is_data_overflow:
                    print('Data overflow!')
                    break

                # Get data:
                data = scp.get_data()

                # Output CSV data:
                for i in range(len(data[0])):
                    writer.writerow([i] + [(data[j][i] if i < len(data[j]) else '') for j in range(len(data))])

                sample += len(data[0])

            print()
            print(f'Data written to: {csvfile.name}')

        # Stop stream:
        scp.stop()

    except Exception as e:
        print(f'Exception: {e}')
        sys.exit(1)

    # Close oscilloscope:
    del scp

else:
    print('No oscilloscope available with stream measurement support!')
    sys.exit(1)

sys.exit(0)
