# Generator.py
#
# This example generates a 100 kHz triangle waveform, 4 Vpp.
#
# Find more information on http://www.tiepie.com/LibTiePie .

import sys
import libtiepie
from printinfo import *

# Print library info:
print_library_info()

# Enable network search:
libtiepie.network.auto_detect_enabled = True

# Search for devices:
libtiepie.device_list.update()

# Try to open a generator:
gen = None
for item in libtiepie.device_list:
    if item.can_open(libtiepie.DEVICETYPE_GENERATOR):
        gen = item.open_generator()
        if gen:
            break

if gen:
    try:
        # Set signal type:
        gen.signal_type = libtiepie.ST_TRIANGLE

        # Set frequency:
        gen.frequency = 100e3  # 100 kHz

        # Set amplitude:
        gen.amplitude = 2  # 2 V

        # Set offset:
        gen.offset = 0  # 0 V

        # Enable output:
        gen.output_enable = True

        # Print generator info:
        print_device_info(gen)

        # Start signal generation:
        gen.start()

        # Wait for keystroke:
        print('Press Enter to stop signal generation...')
        input()

        # Stop generator:
        gen.stop()

        # Disable output:
        gen.output_enable = False

    except Exception as e:
        print(f'Exception: {e}')
        sys.exit(1)

    # Close generator:
    del gen

else:
    print('No generator available!')
    sys.exit(1)

sys.exit(0)
