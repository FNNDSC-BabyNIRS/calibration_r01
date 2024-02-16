# printinfo.py
#
# This file is part of the LibTiePie programming examples.
#
# Find more information on http://www.tiepie.com/LibTiePie .

from libtiepie import *
from libtiepie.exceptions import LibTiePieException
from libtiepie.device import Device
from libtiepie.oscilloscope import Oscilloscope
from libtiepie.generator import Generator
from libtiepie.server import Server


def print_library_info():
    print('Library:')
    print(f'  Version      : {library.version}')
    print(f'  Configuration: {library.config_str}')


def print_device_info(dev, full=True):
    if not isinstance(dev, Device):
        raise

    print('Device:')
    print(f'  Name                      : {dev.name}')
    print(f'  Short name                : {dev.name_short}')
    print(f'  Serial number             : {dev.serial_number}')
    try:
        print('  Calibration date          : {0:%Y-%m-%d}'.format(dev.calibration_date))
    except LibTiePieException:
        pass
    print(f'  Product id                : {dev.product_id}')
    try:
        print(f'  IP address              : {dev.ip_address}')
    except LibTiePieException:
        pass
    try:
        print(f'  IP port                   : {dev.ip_port}')
    except LibTiePieException:
        pass

    print(f'  Has battery               : {dev.has_battery}')
    if dev.has_battery:
        print('  Battery:')
        try:
            print(f'    Charge                  : {dev.battery_charge} %')
        except LibTiePieException:
            pass
        try:
            print(f'    Time to empty           : {dev.battery_time_to_empty} minutes')
        except LibTiePieException:
            pass
        try:
            print(f'    Time to full            : {dev.battery_time_to_full} minutes')
        except LibTiePieException:
            pass
        try:
            print(f'    Charger connected       : {dev.is_battery_charger_connected}')
        except LibTiePieException:
            pass
        try:
            print(f'    Charging                : {dev.is_battery_charging}')
        except LibTiePieException:
            pass
        try:
            print(f'    Broken                  : {dev.is_battery_broken}')
        except LibTiePieException:
            pass

    if full:
        if isinstance(dev, Oscilloscope):
            print_oscilloscope_info(dev)
        elif isinstance(dev, Generator):
            print_generator_info(dev)


def print_oscilloscope_info(scp):
    if not isinstance(scp, Oscilloscope):
        raise

    print('Oscilloscope:')
    print(f'  Channel count             : {len(scp.channels)}')
    print(f'  SureConnect               : {scp.has_sureconnect}')
    print(f'  Measure modes             : {measure_mode_str(scp.measure_modes)}')
    print(f'  Measure mode              : {measure_mode_str(scp.measure_mode)}')
    print(f'  Auto resolution modes     : {auto_resolution_mode_str(scp.auto_resolution_modes)}')
    print(f'  Auto resolution mode      : {auto_resolution_mode_str(scp.auto_resolution_mode)}')
    print(f'  Resolutions               : {", ".join(map(str, scp.resolutions))}')
    print(f'  Resolution                : {scp.resolution}')
    print(f'  Resolution enhanced       : {scp.is_resolution_enhanced}')
    print(f'  Clock outputs             : {clock_output_str(scp.clock_outputs)}')
    print(f'  Clock output              : {clock_output_str(scp.clock_output)}')
    try:
        print(f'  Clock output frequecies   : {", ".join(map(str, scp.clock_output_frequencies))}')
        print(f'  Clock output frequency    : {scp.clock_output_frequency}')
    except LibTiePieException:
        pass
    print(f'  Clock sources             : {clock_source_str(scp.clock_sources)}')
    print(f'  Clock source              : {clock_source_str(scp.clock_source)}')
    try:
        print(f'  Clock source frequecies   : {", ".join(map(str, scp.clock_source_frequencies))}')
        print(f'  Clock source frequency    : {scp.clock_source_frequency}')
    except LibTiePieException:
        pass

    print(f'  Record length max         : {scp.record_length_max}')
    print(f'  Record length             : {scp.record_length}')
    print(f'  Sample rate max           : {scp.sample_rate_max}')
    print(f'  Sample rate               : {scp.sample_rate}')

    if scp.measure_mode == MM_BLOCK:
        print(f'  Segment count max         : {scp.segment_count_max}')
        if scp.segment_count_max > 1:
            print(f'  Segment count             : {scp.segment_count}')

    if scp.has_trigger:
        print(f'  Pre sample ratio          : {scp.pre_sample_ratio}')
        to = scp.trigger.timeout
        if to == TO_INFINITY:
            to = 'Infinite'
        print(f'  Trigger time out          : {to}')
        if scp.trigger.has_delay:
            print(f'  Trigger delay max         : {scp.trigger.delay_max}')
            print(f'  Trigger delay             : {scp.trigger.delay}')
        if scp.has_presamples_valid:
            print(f'  Presamples valid          : {scp.presamples_valid}')

    if len(scp.channels) > 0:
        num = 1
        for ch in scp.channels:
            print(f'  Channel {num}:')
            print(f'    Connector type          : {connector_type_str(ch.connector_type)}')
            print(f'    Differential            : {ch.is_differential}')
            print(f'    Impedance               : {ch.impedance}')
            print(f'    SureConnect             : {ch.has_sureconnect}')
            print(f'    Available               : {ch.is_available}')
            print(f'    Enabled                 : {ch.enabled}')
            print(f'    Bandwidths              : {", ".join(map(str, ch.bandwidths))}')
            print(f'    Bandwidth               : {ch.bandwidth}')
            print(f'    Couplings               : {coupling_str(ch.couplings)}')
            print(f'    Coupling                : {coupling_str(ch.coupling)}')
            print(f'    Auto ranging            : {ch.auto_ranging}')
            print(f'    Ranges                  : {", ".join(map(str, ch.ranges))}')
            print(f'    Range                   : {ch.range}')
            if ch.has_trigger:
                tr = ch.trigger
                print(f'    Trigger:')
                print(f'      Available             : {tr.is_available}')
                print(f'      Enabled               : {tr.enabled}')
                print(f'      Kinds                 : {trigger_kind_str(tr.kinds)}')
                print(f'      Kind                  : {trigger_kind_str(tr.kind)}')
                print(f'      Level modes           : {trigger_level_mode_str(tr.level_modes)}')
                print(f'      Level mode            : {trigger_level_mode_str(tr.level_mode)}')
                print(f'      Levels                : {", ".join(map(str, tr.levels))}')
                if len(tr.hystereses) > 0:
                    print(f'      Hystereses            : {", ".join(map(str, tr.hystereses))}')
                print(f'      Conditions            : {trigger_condition_str(tr.conditions)}')
                if tr.conditions != TCM_NONE:
                    print(f'      Condition             : {trigger_condition_str(tr.condition)}')
                if len(tr.times) > 0:
                    print(f'      Times                 : {", ".join(map(str, tr.times))}')
            num += 1

    print_trigger_inputs_info(scp)
    print_trigger_outputs_info(scp)


def print_generator_info(gen):
    if not isinstance(gen, Generator):
        raise

    print('Generator:')
    print(f'  Connector type            : {connector_type_str(gen.connector_type)}')
    print(f'  Differential              : {gen.is_differential}')
    print(f'  Controllable              : {gen.is_controllable}')
    print(f'  Impedance                 : {gen.impedance}')
    print(f'  Resolution                : {gen.resolution}')
    print(f'  Output value min          : {gen.output_value_min}')
    print(f'  Output value max          : {gen.output_value_max}')
    print(f'  Output enable             : {gen.output_enable}')
    if gen.has_output_invert:
        print(f'  Output invert             : {gen.output_invert}')

    print(f'  Modes native              : {generator_mode_str(gen.modes_native)}')
    print(f'  Modes                     : {generator_mode_str(gen.modes)}')
    if gen.modes != GMM_NONE:
        print(f'  Mode                      : {generator_mode_str(gen.mode)}')
        if (gen.mode & GMM_BURST_COUNT) != 0:
            print(f'  Burst active              : {gen.is_burst_active}')
            print(f'  Burst count max           : {gen.burst_count_max}')
            print(f'  Burst count               : {gen.burst_count}')
        if (gen.mode & GMM_BURST_SAMPLE_COUNT) != 0:
            print(f'  Burst sample count max    : {gen.burst_sample_count_max}')
            print(f'  Burst sample count        : {gen.burst_sample_count}')
        if (gen.mode & GMM_BURST_SEGMENT_COUNT) != 0:
            print(f'  Burst segment count max   : {gen.burst_segment_count_max}')
            print(f'  Burst segment count       : {gen.burst_segment_count}')

    print(f'  Signal types              : {signal_type_str(gen.signal_types)}')
    print(f'  Signal type               : {signal_type_str(gen.signal_type)}')

    if gen.has_amplitude:
        print(f'  Amplitude min             : {gen.amplitude_min}')
        print(f'  Amplitude max             : {gen.amplitude_max}')
        print(f'  Amplitude                 : {gen.amplitude}')
        print(f'  Amplitude ranges          : {", ".join(map(str, gen.amplitude_ranges))}')
        print(f'  Amplitude range           : {gen.amplitude_range}')
        print(f'  Amplitude auto ranging    : {gen.amplitude_auto_ranging}')

    if gen.has_frequency:
        print(f'  Frequency modes           : {frequency_mode_str(gen.frequency_modes)}')
        print(f'  Frequency mode            : {frequency_mode_str(gen.frequency_mode)}')
        print(f'  Frequency min             : {gen.frequency_min}')
        print(f'  Frequency max             : {gen.frequency_max}')
        print(f'  Frequency                 : {gen.frequency}')

    if gen.has_offset:
        print(f'  Offset min                : {gen.offset_min}')
        print(f'  Offset max                : {gen.offset_max}')
        print(f'  Offset                    : {gen.offset}')

    if gen.has_phase:
        print(f'  Phase min                 : {gen.phase_min}')
        print(f'  Phase max                 : {gen.phase_max}')
        print(f'  Phase                     : {gen.phase}')

    if gen.has_symmetry:
        print(f'  Symmetry min              : {gen.symmetry_min}')
        print(f'  Symmetry max              : {gen.symmetry_max}')
        print(f'  Symmetry                  : {gen.symmetry}')

    if gen.has_width:
        print(f'  Width min                 : {gen.width_min}')
        print(f'  Width max                 : {gen.width_max}')
        print(f'  Width                     : {gen.width}')

    if gen.has_edge_time:
        print(f'  Leading edge time min     : {gen.leading_edge_time_min}')
        print(f'  Leading edge time max     : {gen.leading_edge_time_max}')
        print(f'  Leading edge time         : {gen.leading_edge_time}')
        print(f'  Trailing edge time min    : {gen.trailing_edge_time_min}')
        print(f'  Trailing edge time max    : {gen.trailing_edge_time_max}')
        print(f'  Trailing edge time        : {gen.trailing_edge_time}')

    if gen.has_data:
        print(f'  Data length min           : {gen.data_length_min}')
        print(f'  Data length max           : {gen.data_length_max}')
        print(f'  Data length               : {gen.data_length}')

    print_trigger_inputs_info(gen)
    print_trigger_outputs_info(gen)


def print_trigger_inputs_info(dev):
    if not isinstance(dev, Device):
        raise

    if len(dev.trigger_inputs) > 0:
        num = 1
        for trin in dev.trigger_inputs:
            print(f'  Trigger input {num}:')
            print(f'    Id                      : {trin.id}')
            print(f'    Name                    : {trin.name}')
            print(f'    Available               : {trin.is_available}')
            if trin.is_available:
                print(f'    Enabled                 : {trin.enabled}')
                print(f'    Kinds                   : {trigger_kind_str(trin.kinds)}')
                if trin.kinds != TKM_NONE:
                    print(f'    Kind                    : {trigger_kind_str(trin.kind)}')
            num += 1


def print_trigger_outputs_info(dev):
    if not isinstance(dev, Device):
        raise

    if len(dev.trigger_outputs) > 0:
        num = 1
        for trout in dev.trigger_outputs:
            print(f'  Trigger output {num}:')
            print(f'    Id                      : {trout.id}')
            print(f'    Name                    : {trout.name}')
            print(f'    Enabled                 : {trout.enabled}')
            print(f'    Events                  : {trigger_output_event_str(trout.events)}')
            print(f'    Event                   : {trigger_output_event_str(trout.event)}')
            num += 1


def print_server_info(srv):
    if not isinstance(srv, Server):
        raise

    print('Server:')
    print(f'  URL                       : {srv.url}')
    print(f'  Name                      : {srv.name}')
    print(f'  Description               : {srv.description}')
    print(f'  IP address                : {srv.ip_address}')
    print(f'  IP port                   : {srv.ip_port}')
    print(f'  Id                        : {srv.id}')
    print(f'  Version                   : {srv.version}{srv.version_extra}')
    print(f'  Status                    : {server_status_str(srv.status)}')
    if srv.last_error != SERVER_ERROR_NONE:
        print(f'  Last error                : {server_error_str(srv.last_error)}')
