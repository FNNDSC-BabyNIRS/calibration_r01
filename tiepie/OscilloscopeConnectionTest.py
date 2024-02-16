# OscilloscopeConnectionTest.py
#
# This example performs a connection test.
#
# Find more information on http://www.tiepie.com/LibTiePie .

import time
import sys
import libtiepie
from printinfo import *

# Print library info:
print_library_info()

# Enable network search:
libtiepie.network.auto_detect_enabled = True

# Search for devices:
libtiepie.device_list.update()

# Try to open an oscilloscope with connection test support:
scp = None
for item in libtiepie.device_list:
    if item.can_open(libtiepie.DEVICETYPE_OSCILLOSCOPE):
        scp = item.open_oscilloscope()
        if scp.has_sureconnect:
            break
        else:
            scp = None

if scp:
    try:
        # Enable all channels that support connection testing:
        for ch in scp.channels:
            ch.enabled = ch.has_sureconnect

        # Print oscilloscope info:
        print_device_info(scp)

        # Start connection test:
        scp.start_sureconnect()

        # Wait for connection test to complete:
        while not scp.is_sureconnect_completed:
            time.sleep(0.01)  # 10 ms delay, to save CPU time

        # Get data:
        result = scp.get_sureconnect_data()

        # Print result:
        print()
        print('Connection test result:')
        ch = 1
        for value in result:
            print(f'Ch{ch} = {value}')
            ch += 1

    except Exception as e:
        print(f'Exception: {e}')
        sys.exit(1)

    # Close oscilloscope:
    del scp

else:
    print('No oscilloscope available with connection test support!')
    sys.exit(1)

sys.exit(0)
