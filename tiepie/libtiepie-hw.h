/**
 * \file libtiepie-hw.h
 * \brief TiePie engineering hardware interfacing library header
 */

#ifndef _LIBTIEPIE_HW_H_
#define _LIBTIEPIE_HW_H_

#ifdef __cplusplus
  #include <cstdlib>
  #include <cstdint>
#else
  #include <stdlib.h>
  #include <stdint.h>
#endif

#ifndef TIEPIE_HW_API
  #define TIEPIE_HW_API
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#define TIEPIE_HW_VERSION_MAJOR   1
#define TIEPIE_HW_VERSION_MINOR   2
#define TIEPIE_HW_VERSION_PATCH   1
#define TIEPIE_HW_VERSION_NUMBER  "1.2.1"
#define TIEPIE_HW_VERSION         "1.2.1"

/**
 * \mainpage
 *
 * \section Intro Introduction
 *
 * The libtiepie-hw library is a library for using TiePie engineering USB instruments through third party software.
 *
 * \subsection instruments Supported instruments
 *
 * <table>
 *   <tr> <th>WiFiScopes</th>                                                                                 <th>Handyscopes</th>                                                                                 <th>Automotive Test WiFi Scopes</th>                                                                   <th>Automotive Test Scopes</th>                                                                      </tr>
 *   <tr> <td rowspan="2"><a class="External" href="https://www.tiepie.com/WS6D">WiFiScope WS6 DIFF</a></td>  <td rowspan="2"><a class="External" href="https://www.tiepie.com/HS6D">Handyscope HS6 DIFF</a></td>  <td><a class="External" href="https://www.tiepie-automotive.com/ATS610004DW">ATS610004DW-XMSG</a></td> <td><a class="External" href="https://www.tiepie-automotive.com/ATS610004D">ATS610004D-XMSG</a></td> </tr>
 *   <tr>                                                                                                                                                                                                          <td><a class="External" href="https://www.tiepie-automotive.com/ATS605004DW">ATS605004DW-XMS</a></td>  <td><a class="External" href="https://www.tiepie-automotive.com/ATS605004D">ATS605004D-XMS</a></td>  </tr>
 *   <tr> <td            ><a class="External" href="https://www.tiepie.com/WS6">WiFiScope WS6</a></td>        <td            ><a class="External" href="https://www.tiepie.com/HS6">Handyscope HS6</a></td>        <td> </td>                                                                                             <td> </td>                                                                                           </tr>
 *   <tr> <td            ><a class="External" href="https://www.tiepie.com/WS5">WiFiScope WS5</a></td>        <td            ><a class="External" href="https://www.tiepie.com/HS5">Handyscope HS5</a></td>        <td> </td>                                                                                             <td> </td>                                                                                           </tr>
 *   <tr> <td            ><a class="External" href="https://www.tiepie.com/WS4D">WiFiScope WS4 DIFF</a></td>  <td            ><a class="External" href="https://www.tiepie.com/HS4D">Handyscope HS4 DIFF</a></td>  <td><a class="External" href="https://www.tiepie-automotive.com/ATS5004DW">ATS5004DW</a></td>          <td><a class="External" href="https://www.tiepie-automotive.com/ATS5004D">ATS5004D</a></td>          </tr>
 *   <tr> <td            > </td>                                                                              <td            ><a class="External" href="https://www.tiepie.com/HS4">Handyscope HS4</a></td>        <td> </td>                                                                                             <td> </td>                                                                                           </tr>
 *   <tr> <td            > </td>                                                                              <td            ><a class="External" href="https://www.tiepie.com/HS3">Handyscope HS3</a></td>        <td> </td>                                                                                             <td> </td>                                                                                           </tr>
 *   <tr> <td            >&nbsp;</td>                                                                         <td            > </td>                                                                               <td> </td>                                                                                             <td> </td>                                                                                           </tr>
 *   <tr> <td            > </td>                                                                              <td            ><a class="External" href="https://www.tiepie.com/HP3">Handyprobe HP3</a></td>        <td> </td>                                                                                             <td> </td>                                                                                           </tr>
 *   <tr> <td            > </td>                                                                              <td            ><a class="External" href="https://www.tiepie.com/TP450">Handyscope TP450</a></td>    <td> </td>                                                                                             <td> </td>                                                                                           </tr>
 * </table>
 *
 *
 * \subsection structure Library structure
 *
 * LibTiePie maintains a \ref lst, containing all available supported devices.
 * Possible devices are \ref scp "oscilloscopes" and \ref gen "generators".
 * Instruments can contain multiple devices, e.g. the Handyscope HS5 and WiFiScope WS5 contain an oscilloscope and a generator.
 *
 * Devices can contain sub devices.
 * E.g. devices contain \ref dev_trigger "trigger systems", oscilloscopes contain \ref scp_channels "channels", channels contain \ref scp_ch_tr "channel trigger systems".
 *
 * The LibTiePie library contains functions to control all aspects of the device list and the (sub) devices.
 *
 * \subsubsection prefixes LibTiePie function name prefixes
 *
 * All functions are prefixed, so it is easily determined where the function can be used for.
 *
 * <table>
 *   <tr><th>Prefix</th>     <th>Description</th>                                                      </tr>
 *   <tr><td>\b Lib</td>     <td>Common \ref lib related functions</td>                                </tr>
 *   <tr><td>\b Lst</td>     <td>\ref lst related functions</td>                                       </tr>
 *   <tr><td>\b Obj</td>     <td>\ref obj "Common object" related functions</td>                       </tr>
 *   <tr><td>\b Dev</td>     <td>\ref dev "Common device" related functions</td>                       </tr>
 *   <tr><td>\b DevTrIn</td> <td>\ref dev_trigger_input "Device trigger input" related functions</td>  </tr>
 *   <tr><td>\b DevTrOut</td><td>\ref dev_trigger_output "Device trigger output" related functions</td></tr>
 *   <tr><td>\b Scp</td>     <td>\ref scp related functions</td>                                       </tr>
 *   <tr><td>\b ScpCh</td>   <td>\ref scp_channels "Oscilloscope channel" related functions</td>       </tr>
 *   <tr><td>\b ScpChTr</td> <td>\ref scp_ch_tr "Oscilloscope channel trigger" related functions</td>  </tr>
 *   <tr><td>\b Gen</td>     <td>\ref gen related functions</td>                                       </tr>
 *   <tr><td>\b Hlp</td>     <td>\ref hlp for bypassing limitations of some programming languages</td> </tr>
 * </table>
 *
 * \subsection UsingLibTiePie Using LibTiePie
 *
 * When using LibTiePie, to control instruments and perform measurements, the following steps are required:
 *
 * - \ref lib "Initialize" the library
 * - \ref lst "Update" the device list
 * - \ref lst "Open" the required device(s)
 * - Setup the \ref scp
 *   - Setup the \ref scp_channels "oscilloscope channels"
 *   - Setup the \ref scp_timebase "oscilloscope timebase"
 *   - Setup the trigger (\ref scp_ch_tr "channels" and \ref dev_trigger_input "device")
 * - Setup the \ref gen
 * - Start a \ref scp_measurements "measurement"
 * - Wait for the measurement to be \ref scp_measurements_status "ready"
 * - Retrieve the \ref scp_data "measured data"
 * - \ref tiepie_hw_object_close "Close" the device(s)
 * - \ref lib "Exit" the library
 *
 *
 * \subsection errorhandling Error handling
 * On each function call a status flag is set, use tiepie_hw_get_last_status() to read the status flag. See also \ref tiepie_hw_status "Status return codes".
 *
 * \page TriggerSystem Trigger system
 *
 * To trigger a device, several trigger sources can be available. These are divided in
 * \subpage triggering_devin sources and
 * \subpage triggering_scpch sources.
 *
 * Use tiepie_hw_oscilloscope_channel_has_trigger() to check whether an oscilloscope channel supports trigger.
 *
 * To select a trigger source, enable it. Multiple trigger sources can be used, in that case they will be OR'ed.
 *
 * \subpage triggering_hs5 specific trigger information
 *
 * \subpage triggering_hs6d specific trigger information
 *
 * \subpage triggering_combi specific trigger information
 * \page triggering_devin Device trigger inputs
 *
 * A device can have zero or more device trigger inputs.
 * These can be available as pins on an extension connector on the instrument.
 * Internal signals inside the instrument from e.g. a generator can also be available as device trigger input.
 * Use the function #tiepie_hw_device_trigger_get_input_count to determine the amount of available device trigger inputs.
 * To use a device trigger input as trigger source, use the function #tiepie_hw_device_trigger_input_set_enabled to enable it.
 *
 * \section triggering_devin_kind Kind
 *
 * The Kind setting controls how a device trigger input responds to its signal.
 * Use tiepie_hw_device_trigger_input_get_kinds() to find out which trigger kinds are supported by the device trigger input.
 * Use tiepie_hw_device_trigger_input_get_kind() and tiepie_hw_device_trigger_input_set_kind() to access the trigger kind of a trigger input.
 * Available kinds are:
 *
 * \subsection triggering_devin_kind_rising Rising edge (TIEPIE_HW_TK_RISINGEDGE)
 *
 * The device trigger responds to a \b rising edge in the input signal.
 *
 *
 * \subsection triggering_devin_kind_falling Falling edge (TIEPIE_HW_TK_FALLINGEDGE)
 *
 * The device trigger responds to a \b falling edge in the input signal.
 *
 * Related:
 * - \ref dev_trigger_input_kind "all trigger input kind routines"
 * - \ref dev_trigger_input "trigger inputs".
 * \page triggering_scpch Oscilloscope channel trigger
 *
 * Each oscilloscope channel can be used as trigger source. To use an oscilloscope channel as trigger input, enable it using #tiepie_hw_oscilloscope_channel_trigger_set_enabled.
 *
 * To control how and when the channel trigger responds to the channel input signal, several properties are available:
 * - \ref triggering_scpch_kind "Kind"
 * - \ref triggering_scpch_level "Level"
 * - \ref triggering_scpch_hysteresis "Hysteresis"
 * - \ref triggering_scpch_condition "Condition"
 * - \ref triggering_scpch_time "Time"
 *
 * \section triggering_scpch_kind Kind
 *
 * The kind property is used to control how the channel trigger responds to the channel input signal.
 * The other properties depend on the trigger kind that is selected.
 * Use tiepie_hw_oscilloscope_channel_trigger_get_kinds() to find out which trigger kinds are supported by the channel.
 * Available kinds are:
 *
 * \subsection triggering_scpch_kind_risingedge Rising edge (TIEPIE_HW_TK_RISINGEDGE)
 *
 * The channel trigger responds to a \b rising edge in the input signal.
 * The trigger uses Level[0] and Hysteresis[0] below the level to determine the rising edge.
 *
 * \subsection triggering_scpch_kind_fallingedge Falling edge (TIEPIE_HW_TK_FALLINGEDGE)
 *
 * The channel trigger responds to a \b falling edge in the input signal.
 * The trigger uses Level[0] and Hysteresis[0] above the level to determine the falling edge.
 *
 * \subsection triggering_scpch_kind_anyedge Any edge (TIEPIE_HW_TK_ANYEDGE)
 *
 * The channel trigger responds to \b any edge, either rising or falling, in the input signal.
 * The trigger uses Level[0], Hysteresis[0] above the level and Hysteresis[1] below level to determine the edges.
 *
 * \subsection triggering_scpch_kind_inwindow Inside window (TIEPIE_HW_TK_INWINDOW)
 *
 * The channel trigger responds when the input signal is \b inside a predefined window.
 * The trigger uses Level[0] and Level[1] to determine the window, there is no restriction to which level must be high and which must be low.
 * The trigger remains active as long as the signal is inside the window.
 *
 * \subsection triggering_scpch_kind_outwindow Outside window (TIEPIE_HW_TK_OUTWINDOW)
 *
 * The channel trigger responds when the input signal is \b outside a predefined window.
 * The trigger uses Level[0] and Level[1] to determine the window, there is no restriction to which level must be high and which must be low.
 * The trigger remains active as long as the signal is outside the window.
 *
 * \subsection triggering_scpch_kind_enterwindow Enter window (TIEPIE_HW_TK_ENTERWINDOW)
 *
 * The channel trigger responds when the input signal \b enters a predefined window.
 * The trigger uses Level[0] and Hysteresis[0] to define one limit of the window and Level[1] and Hysteresis[1] to determine the other limit of the window,
 * there is no restriction to which level must be high and which must be low. The hysteresis is outside the window defined by the levels.
 *
 * \subsection triggering_scpch_kind_exitwindow Exit window (TIEPIE_HW_TK_EXITWINDOW)
 *
 * The channel trigger responds when the input signal \b exits a predefined window.
 * The trigger uses Level[0] and Hysteresis[0] to define one limit of the window and Level[1] and Hysteresis[1] to determine the other limit of the window,
 * there is no restriction to which level must be high and which must be low. The hysteresis is inside the window defined by the levels.
 *
 * \subsection triggering_scpch_kind_pulsewidthpositive Pulse width positive (TIEPIE_HW_TK_PULSEWIDTHPOSITIVE)
 *
 * The channel trigger responds when the input signal contains a \b positive \b pulse with a length longer or shorter than a predefined value.
 * The trigger uses Level[0] and Hysteresis[0] to determine the rising and falling edges of the pulse.
 * It also uses Time[0] to define the required length of the pulse and Condition to indicate whether the pulse must be longer or shorter than the defined time.
 *
 * \subsection triggering_scpch_kind_pulsewidthnegative Pulse width negative (TIEPIE_HW_TK_PULSEWIDTHNEGATIVE)
 *
 * The channel trigger responds when the input signal contains a \b negative \b pulse with a length longer or shorter than a predefined value.
 * The trigger uses Level[0] and Hysteresis[0] to determine the falling and rising edges of the pulse.
 * It also uses Time[0] to define the required length of the pulse and Condition to indicate whether the pulse must be longer or shorter than the defined time.
 *
 * Read more about the channel trigger kind \ref scp_ch_tr_kind "related functions".
 *
 *
 * \section triggering_scpch_level Level
 *
 * Most trigger kinds use one or more level properties to indicate at which level(s) of the input signal the channel trigger must respond.
 * Use tiepie_hw_oscilloscope_channel_trigger_get_level_count() to find out how many trigger levels are used by the currently set trigger kind.
 *
 * The trigger level is set as a floating point value between 0 and 1, corresponding to a percentage of the full scale input range:
 * - 0.0 (0%) equals -full scale
 * - 0.5 (50%) equals mid level or 0 Volt
 * - 1.0 (100%) equals full scale.
 *
 * Read more about the trigger level \ref scp_ch_tr_level "related functions".
 *
 *
 * \section triggering_scpch_hysteresis Hysteresis
 *
 * Most trigger kinds use one or more hysteresis properties to indicate the sensitivity of the channel trigger.
 * With a small hysteresis, the trigger system responds to small input signal changes, with a large hysteresis, the input signal change must be large for the channel trigger to respond.
 * Use tiepie_hw_oscilloscope_channel_trigger_get_hysteresis_count() to determine the number of trigger hystereses for the currently set trigger kind.
 *
 * The trigger hysteresis is set as a floating point value between 0 and 1, corresponding to a percentage of the full scale input range:
 * - 0.0 (0%) equals 0 Volt (no hysteresis)
 * - 0.5 (50%) equals full scale
 * - 1.0 (100%) equals 2 * full scale.
 *
 * Read more about the trigger hysteresis \ref scp_ch_tr_hysteresis "related functions".
 *
 *
 * \section triggering_scpch_condition Condition
 *
 * Some trigger kinds require an additional condition to indicate how the channel trigger must respond to the input signal.
 *
 * The available trigger conditions depend on the currently set trigger kind.
 * Use tiepie_hw_oscilloscope_channel_trigger_get_conditions() to determine the available trigger conditions for the currently selected trigger kind.
 * Available conditions are:
 *
 * \subsection triggering_scpch_condition_larger Larger than (TIEPIE_HW_TC_LARGER)
 *
 * This trigger condition is available with pulse width trigger and uses property Time[0].
 * The trigger system responds when a trigger pulse lasts longer than the selected time.
 *
 * \subsection triggering_scpch_condition_smaller Smaller than (TIEPIE_HW_TC_SMALLER)
 *
 * This trigger condition is available with pulse width trigger and uses property Time[0].
 * The trigger system responds when a trigger pulse lasts shorter than the selected time.
 *
 * \subsection triggering_scpch_condition_inside Larger than (TIEPIE_HW_TC_INSIDE)
 *
 * This trigger condition is available with pulse width trigger and uses property Time[0] and Time[1].
 * The trigger system responds when a trigger pulse width is inside the specified time frame.
 *
 * \subsection triggering_scpch_condition_outside Smaller than (TIEPIE_HW_TC_OUTSIDE)
 *
 * This trigger condition is available with pulse width trigger and uses property Time[0] and Time[1].
 * The trigger system responds when a trigger pulse width is outside the specified time frame.
 *
 * Read more about the trigger condition \ref scp_ch_tr_condition "related functions".
 *
 *
 * \section triggering_scpch_time Time
 *
 * Some trigger kinds and conditions use one or more Time properties to determine how long a specific condition must last for the channel trigger to respond.
 * Use tiepie_hw_oscilloscope_channel_trigger_get_time_count() to determine the number of trigger time properties for the currently set trigger kind and condition.
 *
 * The Time property is set as a value in seconds.
 *
 * Read more about the trigger time \ref scp_ch_tr_time "related functions".
 *
 * \page triggering_hs5 Handyscope HS5 / WiFiScope WS5
 *
 * The <a class="External" href="http://www.tiepie.com/HS5">Handyscope HS5</a> and <a class="External" href="http://www.tiepie.com/WS5">WiFiScope WS5</a> consist
 * of an oscilloscope and a generator.
 * Available trigger inputs for these devices are listed below.
 *
 * \section tr_hs5_scp Oscilloscope
 *
 * \subsection tr_hs5_scp_devin Device trigger inputs
 *
 * The Handyscope HS5 and WiFiScope WS5 oscilloscopes support the following device trigger inputs:
 *
 * - Input[ 0 ]: <b>EXT 1</b> (pin 1 on D-sub connector)
 * - Input[ 1 ]: <b>EXT 2</b> (pin 2 on D-sub connector)
 * - Input[ 2 ]: <b>EXT 3</b> (pin 3 on D-sub connector)
 * - Input[ 3 ]: <b>Generator start</b>
 * - Input[ 4 ]: <b>Generator stop</b>
 * - Input[ 5 ]: <b>Generator new period</b>
 *
 * \subsection  tr_hs5_scp_chin Channel trigger inputs
 *
 * The Handyscope HS5 and WiFiScope WS5 oscilloscopes support the following channel trigger inputs:
 *
 * - Channel[ 0 ]: <b>CH1</b>
 * - Channel[ 1 ]: <b>CH2</b>
 *
 * \section tr_hs5_gen Generator
 *
 * \subsection tr_hs5_gen_devin Device trigger inputs
 *
 * The Handyscope HS5 and WiFiScope WS5 oscilloscopes support the following device trigger inputs:
 *
 * - Input[ 0 ]: <b>EXT 1</b> (pin 1 on D-sub connector)
 * - Input[ 1 ]: <b>EXT 2</b> (pin 2 on D-sub connector)
 * - Input[ 2 ]: <b>EXT 3</b> (pin 3 on D-sub connector)
 *
 * \page triggering_hs6d Handyscope HS6 / Handyscope HS6 DIFF / WiFiScope WS6 / WiFiScope WS6 DIFF
 *
 * The following information applies to
 *
 * - <a class="External" href="http://www.tiepie.com/HS6">Handyscope HS6</a>
 * - <a class="External" href="http://www.tiepie.com/HS6D">Handyscope HS6 DIFF</a>
 * - <a class="External" href="http://www.tiepie.com/WS6">WiFiScope HS6</a>
 * - <a class="External" href="http://www.tiepie.com/WS6D">WiFiScope HS6 DIFF</a>
 *
 * The instruments have external trigger inputs, listed below.
 *
 * \section tr_hs6d_scp Oscilloscope
 *
 * \subsection tr_hs6d_scp_devin Device trigger inputs
 *
 * The oscilloscope supports the following device trigger inputs:
 *
 * - Input[ 0 ]: <b>EXT 1</b> (pin 1 on D-sub connector)
 * - Input[ 1 ]: <b>EXT 2</b> (pin 2 on D-sub connector)
 *
 * \subsection  tr_hs6d_scp_chin Channel trigger inputs
 *
 * The oscilloscope supports the following channel trigger inputs:
 *
 * - Channel[ 0 ]: <b>CH1</b>
 * - Channel[ 1 ]: <b>CH2</b>
 * - Channel[ 2 ]: <b>CH3</b>
 * - Channel[ 3 ]: <b>CH4</b>
 *
 * \page triggering_combi Combined instruments
 *
 * When multiple instruments are combined, lists of trigger inputs are created by combining the trigger inputs of the individual instruments.
 * The lists starts with all trigger inputs of the first instrument in the chain, the instrument at the outside of the chain with the lowest serial number,
 * then subsequently the inputs of the next instrument(s) in the chain are added.
 * The name properties of device trigger inputs with a name will be prefixed with the instrument short name and serial number.
 *
 * The listed available trigger inputs below assume a combined instrument consisting of three Handyscope HS5s, with serial numbers 28000, 28002 and 28001 (connected in that order).
 *
 * \section tr_combi_scp Oscilloscope
 *
 * \subsection tr_combi_scp_devin Device trigger inputs
 *
 * The combined oscilloscope supports the following device trigger inputs:
 *
 * - Input[ 0 ]: <b>HS5(28000).EXT 1</b> (pin 1 on D-sub connector)
 * - Input[ 1 ]: <b>HS5(28000).EXT 2</b> (pin 2 on D-sub connector)
 * - Input[ 2 ]: <b>HS5(28000).EXT 3</b> (pin 3 on D-sub connector)
 * - Input[ 3 ]: <b>HS5(28000).Generator start</b>
 * - Input[ 4 ]: <b>HS5(28000).Generator stop</b>
 * - Input[ 5 ]: <b>HS5(28000).Generator new period</b>
 * - Input[ 6 ]: <b>HS5(28002).EXT 1</b> (pin 1 on D-sub connector)
 * - Input[ 7 ]: <b>HS5(28002).EXT 2</b> (pin 2 on D-sub connector)
 * - Input[ 8 ]: <b>HS5(28002).EXT 3</b> (pin 3 on D-sub connector)
 * - Input[ 9 ]: <b>HS5(28002).Generator start</b>
 * - Input[ 10 ]: <b>HS5(28002).Generator stop</b>
 * - Input[ 11 ]: <b>HS5(28002).Generator new period</b>
 * - Input[ 12 ]: <b>HS5(28001).EXT 1</b> (pin 1 on D-sub connector)
 * - Input[ 13 ]: <b>HS5(28001).EXT 2</b> (pin 2 on D-sub connector)
 * - Input[ 14 ]: <b>HS5(28001).EXT 3</b> (pin 3 on D-sub connector)
 * - Input[ 15 ]: <b>HS5(28001).Generator start</b>
 * - Input[ 16 ]: <b>HS5(28001).Generator stop</b>
 * - Input[ 17 ]: <b>HS5(28001).Generator new period</b>
 *
 * \subsection tr_combi_scp_chin Channel trigger inputs
 *
 * The combined oscilloscope supports the following channel trigger inputs:
 *
 * - Channel[ 0 ]: <b>HS5(28000).CH1</b>
 * - Channel[ 1 ]: <b>HS5(28000).CH2</b>
 * - Channel[ 2 ]: <b>HS5(28002).CH1</b>
 * - Channel[ 3 ]: <b>HS5(28002).CH2</b>
 * - Channel[ 4 ]: <b>HS5(28001).CH1</b>
 * - Channel[ 5 ]: <b>HS5(28001).CH2</b>
 *
 * \page migrate Migrate from LibTiePie
 *
 * libtiepie-hw is very simelar to LibTiePie. Alltough all functions have a new name most functions still behave the same.
 *
 * \section migrate_differences Differences
 *
 * Support for Windows event/messages and Linux events is removed, only callbacks are supported.
 * Oscilloscope channel probe gain/offset is removed.
 * All deprecated device/oscilloscope/generator callbacks are removed, it is now required to use the object event callback.
 *
 * The I<sup>2</sup>C host from LibTiePie is removed in libtiepie-hw.
 *
 * Support for Trigger Hold-off is removed.
 * For setting all presamples valid, see \ref scp_trigger_presamples_valid.
 *
 * \section migrate_functions Functions
 *
 * <table>
 *   <tr><th>LibTiePie function name</th><th>libtiepie-hw function name</th><th>Remark</th></tr>
 *   <tr><td>DevClose</td><td>#tiepie_hw_object_close</td><td></td></tr>
 *   <tr><td>DevGetBatteryCharge</td><td>#tiepie_hw_device_get_battery_charge</td><td></td></tr>
 *   <tr><td>DevGetBatteryTimeToEmpty</td><td>#tiepie_hw_device_get_battery_time_to_empty</td><td></td></tr>
 *   <tr><td>DevGetBatteryTimeToFull</td><td>#tiepie_hw_device_get_battery_time_to_full</td><td></td></tr>
 *   <tr><td>DevGetCalibrationDate</td><td>#tiepie_hw_device_get_calibration_date</td><td></td></tr>
 *   <tr><td>DevGetIPPort</td><td>#tiepie_hw_device_get_ip_port</td><td></td></tr>
 *   <tr><td>DevGetIPv4Address</td><td>#tiepie_hw_device_get_ip_address</td><td></td></tr>
 *   <tr><td>DevGetName</td><td>#tiepie_hw_device_get_name</td><td></td></tr>
 *   <tr><td>DevGetNameShort</td><td>#tiepie_hw_device_get_name_short</td><td></td></tr>
 *   <tr><td>DevGetNameShortest</td><td>#tiepie_hw_device_get_name_shortest</td><td></td></tr>
 *   <tr><td>DevGetProductId</td><td>#tiepie_hw_device_get_product_id</td><td></td></tr>
 *   <tr><td>DevGetSerialNumber</td><td>#tiepie_hw_device_get_serial_number</td><td></td></tr>
 *   <tr><td>DevGetType</td><td>#tiepie_hw_device_get_type</td><td></td></tr>
 *   <tr><td>DevHasBattery</td><td>#tiepie_hw_device_has_battery</td><td></td></tr>
 *   <tr><td>DevIsBatteryBroken</td><td>#tiepie_hw_device_is_battery_broken</td><td></td></tr>
 *   <tr><td>DevIsBatteryChargerConnected</td><td>#tiepie_hw_device_is_battery_charger_connected</td><td></td></tr>
 *   <tr><td>DevIsBatteryCharging</td><td>#tiepie_hw_device_is_battery_charging</td><td></td></tr>
 *   <tr><td>DevIsRemoved</td><td>#tiepie_hw_object_is_removed</td><td></td></tr>
 *   <tr><td>DevTrGetInputCount</td><td>#tiepie_hw_device_trigger_get_input_count</td><td></td></tr>
 *   <tr><td>DevTrGetInputIndexById</td><td>#tiepie_hw_device_trigger_get_input_index_by_id</td><td></td></tr>
 *   <tr><td>DevTrGetOutputCount</td><td>#tiepie_hw_device_trigger_get_output_count</td><td></td></tr>
 *   <tr><td>DevTrGetOutputIndexById</td><td>#tiepie_hw_device_trigger_get_output_index_by_id</td><td></td></tr>
 *   <tr><td>DevTrInGetEnabled</td><td>#tiepie_hw_device_trigger_input_get_enabled</td><td></td></tr>
 *   <tr><td>DevTrInGetId</td><td>#tiepie_hw_device_trigger_input_get_id</td><td></td></tr>
 *   <tr><td>DevTrInGetKind</td><td>#tiepie_hw_device_trigger_input_get_kind</td><td></td></tr>
 *   <tr><td>DevTrInGetKinds</td><td>#tiepie_hw_device_trigger_input_get_kinds</td><td></td></tr>
 *   <tr><td>DevTrInGetName</td><td>#tiepie_hw_device_trigger_input_get_name</td><td></td></tr>
 *   <tr><td>DevTrInIsAvailable</td><td>#tiepie_hw_device_trigger_input_is_available</td><td></td></tr>
 *   <tr><td>DevTrInSetEnabled</td><td>#tiepie_hw_device_trigger_input_set_enabled</td><td></td></tr>
 *   <tr><td>DevTrInSetKind</td><td>#tiepie_hw_device_trigger_input_set_kind</td><td></td></tr>
 *   <tr><td>DevTrOutGetEnabled</td><td>#tiepie_hw_device_trigger_output_get_enabled</td><td></td></tr>
 *   <tr><td>DevTrOutGetEvent</td><td>#tiepie_hw_device_trigger_output_get_event</td><td></td></tr>
 *   <tr><td>DevTrOutGetEvents</td><td>#tiepie_hw_device_trigger_output_get_events</td><td></td></tr>
 *   <tr><td>DevTrOutGetId</td><td>#tiepie_hw_device_trigger_output_get_id</td><td></td></tr>
 *   <tr><td>DevTrOutGetName</td><td>#tiepie_hw_device_trigger_output_get_name</td><td></td></tr>
 *   <tr><td>DevTrOutSetEnabled</td><td>#tiepie_hw_device_trigger_output_set_enabled</td><td></td></tr>
 *   <tr><td>DevTrOutSetEvent</td><td>#tiepie_hw_device_trigger_output_set_event</td><td></td></tr>
 *   <tr><td>DevTrOutTrigger</td><td>#tiepie_hw_device_trigger_output_trigger</td><td></td></tr>
 *   <tr><td>GenGetAmplitude</td><td>#tiepie_hw_generator_get_amplitude</td><td></td></tr>
 *   <tr><td>GenGetAmplitudeAutoRanging</td><td>#tiepie_hw_generator_get_amplitude_auto_ranging</td><td></td></tr>
 *   <tr><td>GenGetAmplitudeMax</td><td>#tiepie_hw_generator_get_amplitude_max</td><td></td></tr>
 *   <tr><td>GenGetAmplitudeMin</td><td>#tiepie_hw_generator_get_amplitude_min</td><td></td></tr>
 *   <tr><td>GenGetAmplitudeRange</td><td>#tiepie_hw_generator_get_amplitude_range</td><td></td></tr>
 *   <tr><td>GenGetAmplitudeRanges</td><td>#tiepie_hw_generator_get_amplitude_ranges</td><td></td></tr>
 *   <tr><td>GenGetBurstCount</td><td>#tiepie_hw_generator_get_burst_count</td><td></td></tr>
 *   <tr><td>GenGetBurstCountMax</td><td>#tiepie_hw_generator_get_burst_count_max</td><td></td></tr>
 *   <tr><td>GenGetBurstCountMin</td><td>#tiepie_hw_generator_get_burst_count_min</td><td></td></tr>
 *   <tr><td>GenGetBurstSampleCount</td><td>#tiepie_hw_generator_get_burst_sample_count</td><td></td></tr>
 *   <tr><td>GenGetBurstSampleCountMax</td><td>#tiepie_hw_generator_get_burst_sample_count_max</td><td></td></tr>
 *   <tr><td>GenGetBurstSampleCountMin</td><td>#tiepie_hw_generator_get_burst_sample_count_min</td><td></td></tr>
 *   <tr><td>GenGetBurstSegmentCount</td><td>#tiepie_hw_generator_get_burst_segment_count</td><td></td></tr>
 *   <tr><td>GenGetBurstSegmentCountMax</td><td>#tiepie_hw_generator_get_burst_segment_count_max</td><td></td></tr>
 *   <tr><td>GenGetBurstSegmentCountMin</td><td>#tiepie_hw_generator_get_burst_segment_count_min</td><td></td></tr>
 *   <tr><td>GenGetConnectorType</td><td>#tiepie_hw_generator_get_connector_type</td><td></td></tr>
 *   <tr><td>GenGetDataLength</td><td>#tiepie_hw_generator_get_data_length</td><td></td></tr>
 *   <tr><td>GenGetDataLengthMax</td><td>#tiepie_hw_generator_get_data_length_max</td><td></td></tr>
 *   <tr><td>GenGetDataLengthMin</td><td>#tiepie_hw_generator_get_data_length_min</td><td></td></tr>
 *   <tr><td>GenGetFrequency</td><td>#tiepie_hw_generator_get_frequency</td><td></td></tr>
 *   <tr><td>GenGetFrequencyMax</td><td>#tiepie_hw_generator_get_frequency_max</td><td></td></tr>
 *   <tr><td>GenGetFrequencyMin</td><td>#tiepie_hw_generator_get_frequency_min</td><td></td></tr>
 *   <tr><td>GenGetFrequencyMode</td><td>#tiepie_hw_generator_get_frequency_mode</td><td></td></tr>
 *   <tr><td>GenGetFrequencyModes</td><td>#tiepie_hw_generator_get_frequency_modes</td><td></td></tr>
 *   <tr><td>GenGetImpedance</td><td>#tiepie_hw_generator_get_impedance</td><td></td></tr>
 *   <tr><td>GenGetLeadingEdgeTime</td><td>#tiepie_hw_generator_get_leading_edge_time</td><td></td></tr>
 *   <tr><td>GenGetLeadingEdgeTimeMax</td><td>#tiepie_hw_generator_get_leading_edge_time_max</td><td></td></tr>
 *   <tr><td>GenGetLeadingEdgeTimeMin</td><td>#tiepie_hw_generator_get_leading_edge_time_min</td><td></td></tr>
 *   <tr><td>GenGetMode</td><td>#tiepie_hw_generator_get_mode</td><td></td></tr>
 *   <tr><td>GenGetModes</td><td>#tiepie_hw_generator_get_modes</td><td></td></tr>
 *   <tr><td>GenGetModesNative</td><td>#tiepie_hw_generator_get_modes_native</td><td></td></tr>
 *   <tr><td>GenGetOffset</td><td>#tiepie_hw_generator_get_offset</td><td></td></tr>
 *   <tr><td>GenGetOffsetMax</td><td>#tiepie_hw_generator_get_offset_max</td><td></td></tr>
 *   <tr><td>GenGetOffsetMin</td><td>#tiepie_hw_generator_get_offset_min</td><td></td></tr>
 *   <tr><td>GenGetOutputInvert</td><td>#tiepie_hw_generator_get_output_invert</td><td></td></tr>
 *   <tr><td>GenGetOutputOn</td><td>#tiepie_hw_generator_get_output_enable</td><td></td></tr>
 *   <tr><td>GenGetOutputValueMax</td><td>#tiepie_hw_generator_get_output_value_max</td><td></td></tr>
 *   <tr><td>GenGetOutputValueMin</td><td>#tiepie_hw_generator_get_output_value_min</td><td></td></tr>
 *   <tr><td>GenGetPhase</td><td>#tiepie_hw_generator_get_phase</td><td></td></tr>
 *   <tr><td>GenGetPhaseMax</td><td>#tiepie_hw_generator_get_phase_max</td><td></td></tr>
 *   <tr><td>GenGetPhaseMin</td><td>#tiepie_hw_generator_get_phase_min</td><td></td></tr>
 *   <tr><td>GenGetResolution</td><td>#tiepie_hw_generator_get_resolution</td><td></td></tr>
 *   <tr><td>GenGetSignalType</td><td>#tiepie_hw_generator_get_signal_type</td><td></td></tr>
 *   <tr><td>GenGetSignalTypes</td><td>#tiepie_hw_generator_get_signal_types</td><td></td></tr>
 *   <tr><td>GenGetStatus</td><td>#tiepie_hw_generator_get_status</td><td></td></tr>
 *   <tr><td>GenGetSymmetry</td><td>#tiepie_hw_generator_get_symmetry</td><td></td></tr>
 *   <tr><td>GenGetSymmetryMax</td><td>#tiepie_hw_generator_get_symmetry_max</td><td></td></tr>
 *   <tr><td>GenGetSymmetryMin</td><td>#tiepie_hw_generator_get_symmetry_min</td><td></td></tr>
 *   <tr><td>GenGetTrailingEdgeTime</td><td>#tiepie_hw_generator_get_trailing_edge_time</td><td></td></tr>
 *   <tr><td>GenGetTrailingEdgeTimeMax</td><td>#tiepie_hw_generator_get_trailing_edge_time_max</td><td></td></tr>
 *   <tr><td>GenGetTrailingEdgeTimeMin</td><td>#tiepie_hw_generator_get_trailing_edge_time_min</td><td></td></tr>
 *   <tr><td>GenGetWidth</td><td>#tiepie_hw_generator_get_width</td><td></td></tr>
 *   <tr><td>GenGetWidthMax</td><td>#tiepie_hw_generator_get_width_max</td><td></td></tr>
 *   <tr><td>GenGetWidthMin</td><td>#tiepie_hw_generator_get_width_min</td><td></td></tr>
 *   <tr><td>GenHasAmplitude</td><td>#tiepie_hw_generator_has_amplitude</td><td></td></tr>
 *   <tr><td>GenHasData</td><td>#tiepie_hw_generator_has_data</td><td></td></tr>
 *   <tr><td>GenHasEdgeTime</td><td>#tiepie_hw_generator_has_edge_time</td><td></td></tr>
 *   <tr><td>GenHasFrequency</td><td>#tiepie_hw_generator_has_frequency</td><td></td></tr>
 *   <tr><td>GenHasOffset</td><td>#tiepie_hw_generator_has_offset</td><td></td></tr>
 *   <tr><td>GenHasOutputInvert</td><td>#tiepie_hw_generator_has_output_invert</td><td></td></tr>
 *   <tr><td>GenHasPhase</td><td>#tiepie_hw_generator_has_phase</td><td></td></tr>
 *   <tr><td>GenHasSymmetry</td><td>#tiepie_hw_generator_has_symmetry</td><td></td></tr>
 *   <tr><td>GenHasWidth</td><td>#tiepie_hw_generator_has_width</td><td></td></tr>
 *   <tr><td>GenIsBurstActive</td><td>#tiepie_hw_generator_is_burst_active</td><td></td></tr>
 *   <tr><td>GenIsControllable</td><td>#tiepie_hw_generator_is_controllable</td><td></td></tr>
 *   <tr><td>GenIsDifferential</td><td>#tiepie_hw_generator_is_differential</td><td></td></tr>
 *   <tr><td>GenIsRunning</td><td>#tiepie_hw_generator_is_running</td><td></td></tr>
 *   <tr><td>GenSetAmplitude</td><td>#tiepie_hw_generator_set_amplitude</td><td></td></tr>
 *   <tr><td>GenSetAmplitudeAutoRanging</td><td>#tiepie_hw_generator_set_amplitude_auto_ranging</td><td></td></tr>
 *   <tr><td>GenSetAmplitudeRange</td><td>#tiepie_hw_generator_set_amplitude_range</td><td></td></tr>
 *   <tr><td>GenSetBurstCount</td><td>#tiepie_hw_generator_set_burst_count</td><td></td></tr>
 *   <tr><td>GenSetBurstSampleCount</td><td>#tiepie_hw_generator_set_burst_sample_count</td><td></td></tr>
 *   <tr><td>GenSetBurstSegmentCount</td><td>#tiepie_hw_generator_set_burst_segment_count</td><td></td></tr>
 *   <tr><td>GenSetData</td><td>#tiepie_hw_generator_set_data</td><td></td></tr>
 *   <tr><td>GenSetEventBurstCompleted</td><td></td><td>Removed, use: #tiepie_hw_object_set_event_callback</td></tr>
 *   <tr><td>GenSetEventControllableChanged</td><td></td><td>Removed, use: #tiepie_hw_object_set_event_callback</td></tr>
 *   <tr><td>GenSetFrequency</td><td>#tiepie_hw_generator_set_frequency</td><td></td></tr>
 *   <tr><td>GenSetFrequencyMode</td><td>#tiepie_hw_generator_set_frequency_mode</td><td></td></tr>
 *   <tr><td>GenSetLeadingEdgeTime</td><td>#tiepie_hw_generator_set_leading_edge_time</td><td></td></tr>
 *   <tr><td>GenSetMessageBurstCompleted</td><td></td><td>Removed, use: #tiepie_hw_object_set_event_callback</td></tr>
 *   <tr><td>GenSetMessageControllableChanged</td><td></td><td>Removed, use: #tiepie_hw_object_set_event_callback</td></tr>
 *   <tr><td>GenSetMode</td><td>#tiepie_hw_generator_set_mode</td><td></td></tr>
 *   <tr><td>GenSetOffset</td><td>#tiepie_hw_generator_set_offset</td><td></td></tr>
 *   <tr><td>GenSetOutputInvert</td><td>#tiepie_hw_generator_set_output_invert</td><td></td></tr>
 *   <tr><td>GenSetOutputOn</td><td>#tiepie_hw_generator_set_output_enable</td><td></td></tr>
 *   <tr><td>GenSetPhase</td><td>#tiepie_hw_generator_set_phase</td><td></td></tr>
 *   <tr><td>GenSetSignalType</td><td>#tiepie_hw_generator_set_signal_type</td><td></td></tr>
 *   <tr><td>GenSetSymmetry</td><td>#tiepie_hw_generator_set_symmetry</td><td></td></tr>
 *   <tr><td>GenSetTrailingEdgeTime</td><td>#tiepie_hw_generator_set_trailing_edge_time</td><td></td></tr>
 *   <tr><td>GenSetWidth</td><td>#tiepie_hw_generator_set_width</td><td></td></tr>
 *   <tr><td>GenStart</td><td>#tiepie_hw_generator_start</td><td></td></tr>
 *   <tr><td>GenStop</td><td>#tiepie_hw_generator_stop</td><td></td></tr>
 *   <tr><td>HlpPointerArrayDelete</td><td>#tiepie_hw_pointerarray_delete</td><td></td></tr>
 *   <tr><td>HlpPointerArrayNew</td><td>#tiepie_hw_pointerarray_new</td><td></td></tr>
 *   <tr><td>HlpPointerArraySet</td><td>#tiepie_hw_pointerarray_set</td><td></td></tr>
 *   <tr><td>I2C</td><td></td><td>Removed, no replacement</td></tr>
 *   <tr><td>LibExit</td><td>#tiepie_hw_fini</td><td></td></tr>
 *   <tr><td>LibGetConfig</td><td>#tiepie_hw_get_config</td><td></td></tr>
 *   <tr><td>LibGetLastStatus</td><td>#tiepie_hw_get_last_status</td><td></td></tr>
 *   <tr><td>LibGetLastStatusStr</td><td></td><td>Use: #tiepie_hw_get_last_status_str</td></tr>
 *   <tr><td>LibGetVersion</td><td></td><td>Use: #tiepie_hw_get_version</td></tr>
 *   <tr><td>LibGetVersionExtra</td><td></td><td>Use: #tiepie_hw_get_version</td></tr>
 *   <tr><td>LibInit</td><td>#tiepie_hw_init</td><td></td></tr>
 *   <tr><td>LibIsInitialized</td><td>#tiepie_hw_is_initialized</td><td></td></tr>
 *   <tr><td>LstCbDevGetCalibrationDate</td><td>#tiepie_hw_devicelistitemcombined_get_calibration_date</td><td></td></tr>
 *   <tr><td>LstCbDevGetName</td><td>#tiepie_hw_devicelistitemcombined_get_name</td><td></td></tr>
 *   <tr><td>LstCbDevGetNameShort</td><td>#tiepie_hw_devicelistitemcombined_get_name_short</td><td></td></tr>
 *   <tr><td>LstCbDevGetNameShortest</td><td>#tiepie_hw_devicelistitemcombined_get_name_shortest</td><td></td></tr>
 *   <tr><td>LstCbDevGetProductId</td><td>#tiepie_hw_devicelistitemcombined_get_product_id</td><td></td></tr>
 *   <tr><td>LstCbScpGetChannelCount</td><td>#tiepie_hw_devicelistitemcombined_get_oscilloscope_channel_count</td><td></td></tr>
 *   <tr><td>LstCreateAndOpenCombinedDevice</td><td>#tiepie_hw_devicelist_create_and_open_combined_device</td><td></td></tr>
 *   <tr><td>LstCreateCombinedDevice</td><td>#tiepie_hw_devicelist_create_combined_device</td><td></td></tr>
 *   <tr><td>LstDevCanOpen</td><td>#tiepie_hw_devicelistitem_can_open</td><td></td></tr>
 *   <tr><td>LstDevGetCalibrationDate</td><td>#tiepie_hw_devicelistitem_get_calibration_date</td><td></td></tr>
 *   <tr><td>LstDevGetContainedSerialNumbers</td><td>#tiepie_hw_devicelistitem_get_contained_serial_numbers</td><td></td></tr>
 *   <tr><td>LstDevGetIPPort</td><td>#tiepie_hw_devicelistitem_get_ip_port</td><td></td></tr>
 *   <tr><td>LstDevGetIPv4Address</td><td></td><td>Use: #tiepie_hw_devicelistitem_get_ip_address</td></tr>
 *   <tr><td>LstDevGetName</td><td>#tiepie_hw_devicelistitem_get_name</td><td></td></tr>
 *   <tr><td>LstDevGetNameShort</td><td>#tiepie_hw_devicelistitem_get_name_short</td><td></td></tr>
 *   <tr><td>LstDevGetNameShortest</td><td>#tiepie_hw_devicelistitem_get_name_shortest</td><td></td></tr>
 *   <tr><td>LstDevGetProductId</td><td>#tiepie_hw_devicelistitem_get_product_id</td><td></td></tr>
 *   <tr><td>LstDevGetSerialNumber</td><td>#tiepie_hw_devicelistitem_get_serial_number</td><td></td></tr>
 *   <tr><td>LstDevGetServer</td><td>#tiepie_hw_devicelistitem_get_server</td><td></td></tr>
 *   <tr><td>LstDevGetTypes</td><td>#tiepie_hw_devicelistitem_get_types</td><td></td></tr>
 *   <tr><td>LstDevHasServer</td><td>#tiepie_hw_devicelistitem_has_server</td><td></td></tr>
 *   <tr><td>LstGetCount</td><td>#tiepie_hw_devicelist_get_count</td><td></td></tr>
 *   <tr><td>LstOpenDevice</td><td>#tiepie_hw_devicelistitem_open_device</td><td></td></tr>
 *   <tr><td>LstOpenGenerator</td><td>#tiepie_hw_devicelistitem_open_generator</td><td></td></tr>
 *   <tr><td>LstOpenOscilloscope</td><td>#tiepie_hw_devicelistitem_open_oscilloscope</td><td></td></tr>
 *   <tr><td>LstRemoveDevice</td><td>#tiepie_hw_devicelist_remove_device</td><td>set force parameter to false</td></tr>
 *   <tr><td>LstRemoveDeviceForce</td><td>#tiepie_hw_devicelist_remove_device</td><td>set force parameter to true</td></tr>
 *   <tr><td>LstSetCallbackDeviceAdded</td><td>#tiepie_hw_devicelist_set_callback_device_added</td><td></td></tr>
 *   <tr><td>LstSetCallbackDeviceCanOpenChanged</td><td>#tiepie_hw_devicelist_set_callback_device_can_open_changed</td><td></td></tr>
 *   <tr><td>LstSetCallbackDeviceRemoved</td><td>#tiepie_hw_devicelist_set_callback_device_removed</td><td></td></tr>
 *   <tr><td>LstSetEventDeviceAdded</td><td></td><td>Removed, use: #tiepie_hw_devicelist_set_callback_device_added</td></tr>
 *   <tr><td>LstSetEventDeviceCanOpenChanged</td><td></td><td>Removed, use: #tiepie_hw_devicelist_set_callback_device_can_open_changed</td></tr>
 *   <tr><td>LstSetEventDeviceRemoved</td><td></td><td>Removed, use: #tiepie_hw_devicelist_set_callback_device_removed</td></tr>
 *   <tr><td>LstSetMessageDeviceAdded</td><td></td><td>Removed, use: #tiepie_hw_devicelist_set_callback_device_added</td></tr>
 *   <tr><td>LstSetMessageDeviceCanOpenChanged</td><td></td><td>Removed, use: #tiepie_hw_devicelist_set_callback_device_can_open_changed</td></tr>
 *   <tr><td>LstSetMessageDeviceRemoved</td><td></td><td>Removed, use: #tiepie_hw_devicelist_set_callback_device_removed</td></tr>
 *   <tr><td>LstUpdate</td><td>#tiepie_hw_devicelist_update</td><td></td></tr>
 *   <tr><td>NetGetAutoDetectEnabled</td><td>#tiepie_hw_network_get_auto_detect_enabled</td><td></td></tr>
 *   <tr><td>NetSetAutoDetectEnabled</td><td>#tiepie_hw_network_set_auto_detect_enabled</td><td></td></tr>
 *   <tr><td>NetSrvAdd</td><td>#tiepie_hw_network_servers_add</td><td></td></tr>
 *   <tr><td>NetSrvGetByIndex</td><td>#tiepie_hw_network_servers_get_by_index</td><td></td></tr>
 *   <tr><td>NetSrvGetByURL</td><td>#tiepie_hw_network_servers_get_by_url</td><td></td></tr>
 *   <tr><td>NetSrvGetCount</td><td>#tiepie_hw_network_servers_get_count</td><td></td></tr>
 *   <tr><td>NetSrvRemove</td><td>#tiepie_hw_network_servers_remove</td><td></td></tr>
 *   <tr><td>NetSrvSetCallbackAdded</td><td>#tiepie_hw_network_servers_set_callback_added</td><td></td></tr>
 *   <tr><td>NetSrvSetEventAdded</td><td></td><td>Removed, use: #tiepie_hw_network_servers_set_callback_added</td></tr>
 *   <tr><td>NetSrvSetMessageAdded</td><td></td><td>Removed, use: #tiepie_hw_network_servers_set_callback_added</td></tr>
 *   <tr><td>ObjClose</td><td>#tiepie_hw_object_close</td><td></td></tr>
 *   <tr><td>ObjGetInterfaces</td><td>#tiepie_hw_object_get_interfaces</td><td></td></tr>
 *   <tr><td>ObjIsRemoved</td><td>#tiepie_hw_object_is_removed</td><td></td></tr>
 *   <tr><td>ObjSetEventCallback</td><td>#tiepie_hw_object_set_event_callback</td><td></td></tr>
 *   <tr><td>ObjSetEventEvent</td><td></td><td>Removed, use:#tiepie_hw_object_set_event_callback</td></tr>
 *   <tr><td>ObjSetEventWindowHandle</td><td></td><td>Removed, use:#tiepie_hw_object_set_event_callback</td></tr>
 *   <tr><td>ScpChGetAutoRanging</td><td>#tiepie_hw_oscilloscope_channel_get_auto_ranging</td><td></td></tr>
 *   <tr><td>ScpChGetBandwidth</td><td>#tiepie_hw_oscilloscope_channel_get_bandwidth</td><td></td></tr>
 *   <tr><td>ScpChGetBandwidths</td><td>#tiepie_hw_oscilloscope_channel_get_bandwidths</td><td></td></tr>
 *   <tr><td>ScpChGetConnectorType</td><td>#tiepie_hw_oscilloscope_channel_get_connector_type</td><td></td></tr>
 *   <tr><td>ScpChGetCoupling</td><td>#tiepie_hw_oscilloscope_channel_get_coupling</td><td></td></tr>
 *   <tr><td>ScpChGetCouplings</td><td>#tiepie_hw_oscilloscope_channel_get_couplings</td><td></td></tr>
 *   <tr><td>ScpChGetDataValueMax</td><td>#tiepie_hw_oscilloscope_channel_get_data_value_max</td><td></td></tr>
 *   <tr><td>ScpChGetDataValueMin</td><td>#tiepie_hw_oscilloscope_channel_get_data_value_min</td><td></td></tr>
 *   <tr><td>ScpChGetDataValueRange</td><td>#tiepie_hw_oscilloscope_channel_get_data_value_range</td><td></td></tr>
 *   <tr><td>ScpChGetEnabled</td><td>#tiepie_hw_oscilloscope_channel_get_enabled</td><td></td></tr>
 *   <tr><td>ScpChGetImpedance</td><td>#tiepie_hw_oscilloscope_channel_get_impedance</td><td></td></tr>
 *   <tr><td>ScpChGetProbeGain</td><td></td><td>Removed, no replacement</td></tr>
 *   <tr><td>ScpChGetProbeOffset</td><td></td><td>Removed, no replacement</td></tr>
 *   <tr><td>ScpChGetRange</td><td>#tiepie_hw_oscilloscope_channel_get_range</td><td></td></tr>
 *   <tr><td>ScpChGetRanges</td><td>#tiepie_hw_oscilloscope_channel_get_ranges</td><td></td></tr>
 *   <tr><td>ScpChGetSafeGroundEnabled</td><td>#tiepie_hw_oscilloscope_channel_get_safeground_enabled</td><td></td></tr>
 *   <tr><td>ScpChGetSafeGroundThreshold</td><td>#tiepie_hw_oscilloscope_channel_get_safeground_threshold</td><td></td></tr>
 *   <tr><td>ScpChGetSafeGroundThresholdMax</td><td>#tiepie_hw_oscilloscope_channel_get_safeground_threshold_max</td><td></td></tr>
 *   <tr><td>ScpChGetSafeGroundThresholdMin</td><td>#tiepie_hw_oscilloscope_channel_get_safeground_threshold_min</td><td></td></tr>
 *   <tr><td>ScpChHasConnectionTest</td><td>#tiepie_hw_oscilloscope_channel_has_sureconnect</td><td></td></tr>
 *   <tr><td>ScpChHasSafeGround</td><td>#tiepie_hw_oscilloscope_channel_has_safeground</td><td></td></tr>
 *   <tr><td>ScpChHasTrigger</td><td>#tiepie_hw_oscilloscope_channel_has_trigger</td><td></td></tr>
 *   <tr><td>ScpChIsAvailable</td><td>#tiepie_hw_oscilloscope_channel_is_available</td><td></td></tr>
 *   <tr><td>ScpChIsDifferential</td><td>#tiepie_hw_oscilloscope_channel_is_differential</td><td></td></tr>
 *   <tr><td>ScpChSetAutoRanging</td><td>#tiepie_hw_oscilloscope_channel_set_auto_ranging</td><td></td></tr>
 *   <tr><td>ScpChSetBandwidth</td><td>#tiepie_hw_oscilloscope_channel_set_bandwidth</td><td></td></tr>
 *   <tr><td>ScpChSetCoupling</td><td>#tiepie_hw_oscilloscope_channel_set_coupling</td><td></td></tr>
 *   <tr><td>ScpChSetEnabled</td><td>#tiepie_hw_oscilloscope_channel_set_enabled</td><td></td></tr>
 *   <tr><td>ScpChSetProbeGain</td><td></td><td>Removed, no replacement</td></tr>
 *   <tr><td>ScpChSetProbeOffset</td><td></td><td>Removed, no replacement</td></tr>
 *   <tr><td>ScpChSetRange</td><td>#tiepie_hw_oscilloscope_channel_set_range</td><td></td></tr>
 *   <tr><td>ScpChSetSafeGroundEnabled</td><td>#tiepie_hw_oscilloscope_channel_set_safeground_enabled</td><td></td></tr>
 *   <tr><td>ScpChSetSafeGroundThreshold</td><td>#tiepie_hw_oscilloscope_channel_set_safeground_threshold</td><td></td></tr>
 *   <tr><td>ScpChTrGetCondition</td><td>#tiepie_hw_oscilloscope_channel_trigger_get_condition</td><td></td></tr>
 *   <tr><td>ScpChTrGetConditions</td><td>#tiepie_hw_oscilloscope_channel_trigger_get_conditions</td><td></td></tr>
 *   <tr><td>ScpChTrGetEnabled</td><td>#tiepie_hw_oscilloscope_channel_trigger_get_enabled</td><td></td></tr>
 *   <tr><td>ScpChTrGetHysteresis</td><td>#tiepie_hw_oscilloscope_channel_trigger_get_hysteresis</td><td></td></tr>
 *   <tr><td>ScpChTrGetHysteresisCount</td><td>#tiepie_hw_oscilloscope_channel_trigger_get_hysteresis_count</td><td></td></tr>
 *   <tr><td>ScpChTrGetKind</td><td>#tiepie_hw_oscilloscope_channel_trigger_get_kind</td><td></td></tr>
 *   <tr><td>ScpChTrGetKinds</td><td>#tiepie_hw_oscilloscope_channel_trigger_get_kinds</td><td></td></tr>
 *   <tr><td>ScpChTrGetLevel</td><td>#tiepie_hw_oscilloscope_channel_trigger_get_level</td><td></td></tr>
 *   <tr><td>ScpChTrGetLevelCount</td><td>#tiepie_hw_oscilloscope_channel_trigger_get_level_count</td><td></td></tr>
 *   <tr><td>ScpChTrGetLevelMode</td><td>#tiepie_hw_oscilloscope_channel_trigger_get_level_mode</td><td></td></tr>
 *   <tr><td>ScpChTrGetLevelModes</td><td>#tiepie_hw_oscilloscope_channel_trigger_get_level_modes</td><td></td></tr>
 *   <tr><td>ScpChTrGetTime</td><td>#tiepie_hw_oscilloscope_channel_trigger_get_time</td><td></td></tr>
 *   <tr><td>ScpChTrGetTimeCount</td><td>#tiepie_hw_oscilloscope_channel_trigger_get_time_count</td><td></td></tr>
 *   <tr><td>ScpChTrIsAvailable</td><td>#tiepie_hw_oscilloscope_channel_trigger_is_available</td><td></td></tr>
 *   <tr><td>ScpChTrIsTriggered</td><td>#tiepie_hw_oscilloscope_channel_trigger_is_triggered</td><td></td></tr>
 *   <tr><td>ScpChTrSetCondition</td><td>#tiepie_hw_oscilloscope_channel_trigger_set_condition</td><td></td></tr>
 *   <tr><td>ScpChTrSetEnabled</td><td>#tiepie_hw_oscilloscope_channel_trigger_set_enabled</td><td></td></tr>
 *   <tr><td>ScpChTrSetHysteresis</td><td>#tiepie_hw_oscilloscope_channel_trigger_set_hysteresis</td><td></td></tr>
 *   <tr><td>ScpChTrSetKind</td><td>#tiepie_hw_oscilloscope_channel_trigger_set_kind</td><td></td></tr>
 *   <tr><td>ScpChTrSetLevel</td><td>#tiepie_hw_oscilloscope_channel_trigger_set_level</td><td></td></tr>
 *   <tr><td>ScpChTrSetLevelMode</td><td>#tiepie_hw_oscilloscope_channel_trigger_set_level_mode</td><td></td></tr>
 *   <tr><td>ScpChTrSetTime</td><td>#tiepie_hw_oscilloscope_channel_trigger_set_time</td><td></td></tr>
 *   <tr><td>ScpForceTrigger</td><td>#tiepie_hw_oscilloscope_force_trigger</td><td></td></tr>
 *   <tr><td>ScpGetAutoResolutionMode</td><td>#tiepie_hw_oscilloscope_get_auto_resolution_mode</td><td></td></tr>
 *   <tr><td>ScpGetAutoResolutionModes</td><td>#tiepie_hw_oscilloscope_get_auto_resolution_modes</td><td></td></tr>
 *   <tr><td>ScpGetChannelCount</td><td>#tiepie_hw_oscilloscope_get_channel_count</td><td></td></tr>
 *   <tr><td>ScpGetClockOutput</td><td>#tiepie_hw_oscilloscope_get_clock_output</td><td></td></tr>
 *   <tr><td>ScpGetClockOutputFrequencies</td><td>#tiepie_hw_oscilloscope_get_clock_output_frequencies</td><td></td></tr>
 *   <tr><td>ScpGetClockOutputFrequency</td><td>#tiepie_hw_oscilloscope_get_clock_output_frequency</td><td></td></tr>
 *   <tr><td>ScpGetClockOutputs</td><td>#tiepie_hw_oscilloscope_get_clock_outputs</td><td></td></tr>
 *   <tr><td>ScpGetClockSource</td><td>#tiepie_hw_oscilloscope_get_clock_source</td><td></td></tr>
 *   <tr><td>ScpGetClockSourceFrequencies</td><td>#tiepie_hw_oscilloscope_get_clock_source_frequencies</td><td></td></tr>
 *   <tr><td>ScpGetClockSourceFrequency</td><td>#tiepie_hw_oscilloscope_get_clock_source_frequency</td><td></td></tr>
 *   <tr><td>ScpGetClockSources</td><td>#tiepie_hw_oscilloscope_get_clock_sources</td><td></td></tr>
 *   <tr><td>ScpGetConnectionTestData</td><td>#tiepie_hw_oscilloscope_get_sureconnect_data</td><td></td></tr>
 *   <tr><td>ScpGetData1Ch</td><td>#tiepie_hw_oscilloscope_get_data_1ch</td><td></td></tr>
 *   <tr><td>ScpGetData2Ch</td><td>#tiepie_hw_oscilloscope_get_data_2ch</td><td></td></tr>
 *   <tr><td>ScpGetData3Ch</td><td>#tiepie_hw_oscilloscope_get_data_3ch</td><td></td></tr>
 *   <tr><td>ScpGetData4Ch</td><td>#tiepie_hw_oscilloscope_get_data_4ch</td><td></td></tr>
 *   <tr><td>ScpGetData5Ch</td><td>#tiepie_hw_oscilloscope_get_data_5ch</td><td></td></tr>
 *   <tr><td>ScpGetData6Ch</td><td>#tiepie_hw_oscilloscope_get_data_6ch</td><td></td></tr>
 *   <tr><td>ScpGetData7Ch</td><td>#tiepie_hw_oscilloscope_get_data_7ch</td><td></td></tr>
 *   <tr><td>ScpGetData8Ch</td><td>#tiepie_hw_oscilloscope_get_data_8ch</td><td></td></tr>
 *   <tr><td>ScpGetData</td><td>#tiepie_hw_oscilloscope_get_data</td><td></td></tr>
 *   <tr><td>ScpGetMeasureMode</td><td>#tiepie_hw_oscilloscope_get_measure_mode</td><td></td></tr>
 *   <tr><td>ScpGetMeasureModes</td><td>#tiepie_hw_oscilloscope_get_measure_modes</td><td></td></tr>
 *   <tr><td>ScpGetPreSampleRatio</td><td>#tiepie_hw_oscilloscope_get_pre_sample_ratio</td><td></td></tr>
 *   <tr><td>ScpGetRecordLength</td><td>#tiepie_hw_oscilloscope_get_record_length</td><td></td></tr>
 *   <tr><td>ScpGetRecordLengthMax</td><td>#tiepie_hw_oscilloscope_get_record_length_max</td><td></td></tr>
 *   <tr><td>ScpGetResolution</td><td>#tiepie_hw_oscilloscope_get_resolution</td><td></td></tr>
 *   <tr><td>ScpGetResolutions</td><td>#tiepie_hw_oscilloscope_get_resolutions</td><td></td></tr>
 *   <tr><td>ScpGetSampleFrequency</td><td>#tiepie_hw_oscilloscope_get_sample_rate</td><td></td></tr>
 *   <tr><td>ScpGetSampleFrequencyMax</td><td>#tiepie_hw_oscilloscope_get_sample_rate_max</td><td></td></tr>
 *   <tr><td>ScpGetSegmentCount</td><td>#tiepie_hw_oscilloscope_get_segment_count</td><td></td></tr>
 *   <tr><td>ScpGetSegmentCountMax</td><td>#tiepie_hw_oscilloscope_get_segment_count_max</td><td></td></tr>
 *   <tr><td>ScpGetTriggerDelay</td><td>#tiepie_hw_oscilloscope_trigger_get_delay</td><td></td></tr>
 *   <tr><td>ScpGetTriggerDelayMax</td><td>#tiepie_hw_oscilloscope_trigger_get_delay_max</td><td></td></tr>
 *   <tr><td>ScpGetTriggerHoldOffCount</td><td></td><td>Removed, no replacement</td></tr>
 *   <tr><td>ScpGetTriggerHoldOffCountMax</td><td></td><td>Removed, no replacement</td></tr>
 *   <tr><td>ScpGetTriggerTimeOut</td><td>#tiepie_hw_oscilloscope_trigger_get_timeout</td><td></td></tr>
 *   <tr><td>ScpGetValidPreSampleCount</td><td>#tiepie_hw_oscilloscope_get_valid_pre_sample_count</td><td></td></tr>
 *   <tr><td>ScpHasConnectionTest</td><td>#tiepie_hw_oscilloscope_has_sureconnect</td><td></td></tr>
 *   <tr><td>ScpHasTrigger</td><td>#tiepie_hw_oscilloscope_has_trigger</td><td></td></tr>
 *   <tr><td>ScpHasTriggerDelay</td><td>#tiepie_hw_oscilloscope_trigger_has_delay</td><td></td></tr>
 *   <tr><td>ScpHasTriggerHoldOff</td><td></td><td>Removed, no replacement</td></tr>
 *   <tr><td>ScpIsConnectionTestCompleted</td><td>#tiepie_hw_oscilloscope_is_sureconnect_completed</td><td></td></tr>
 *   <tr><td>ScpIsDataOverflow</td><td>#tiepie_hw_oscilloscope_is_data_overflow</td><td></td></tr>
 *   <tr><td>ScpIsDataReady</td><td>#tiepie_hw_oscilloscope_is_data_ready</td><td></td></tr>
 *   <tr><td>ScpIsForceTriggered</td><td>#tiepie_hw_oscilloscope_is_force_triggered</td><td></td></tr>
 *   <tr><td>ScpIsResolutionEnhanced</td><td>#tiepie_hw_oscilloscope_is_resolution_enhanced</td><td></td></tr>
 *   <tr><td>ScpIsRunning</td><td>#tiepie_hw_oscilloscope_is_running</td><td></td></tr>
 *   <tr><td>ScpIsTimeOutTriggered</td><td>#tiepie_hw_oscilloscope_is_timeout_triggered</td><td></td></tr>
 *   <tr><td>ScpIsTriggered</td><td>#tiepie_hw_oscilloscope_is_triggered</td><td></td></tr>
 *   <tr><td>ScpSetAutoResolutionMode</td><td>#tiepie_hw_oscilloscope_set_auto_resolution_mode</td><td></td></tr>
 *   <tr><td>ScpSetCallbackConnectionTestCompleted</td><td></td><td>Removed, use: #tiepie_hw_object_set_event_callback</td></tr>
 *   <tr><td>ScpSetCallbackDataOverflow</td><td></td><td>Removed, use: #tiepie_hw_object_set_event_callback</td></tr>
 *   <tr><td>ScpSetCallbackDataReady</td><td></td><td>Removed, use: #tiepie_hw_object_set_event_callback</td></tr>
 *   <tr><td>ScpSetCallbackTriggered</td><td></td><td>Removed, use: #tiepie_hw_object_set_event_callback</td></tr>
 *   <tr><td>ScpSetClockOutput</td><td>#tiepie_hw_oscilloscope_set_clock_output</td><td></td></tr>
 *   <tr><td>ScpSetClockOutputFrequency</td><td>#tiepie_hw_oscilloscope_set_clock_output_frequency</td><td></td></tr>
 *   <tr><td>ScpSetClockSource</td><td>#tiepie_hw_oscilloscope_set_clock_source</td><td></td></tr>
 *   <tr><td>ScpSetClockSourceFrequency</td><td>#tiepie_hw_oscilloscope_set_clock_source_frequency</td><td></td></tr>
 *   <tr><td>ScpSetEventConnectionTestCompleted</td><td></td><td>Removed, use: #tiepie_hw_object_set_event_callback</td></tr>
 *   <tr><td>ScpSetEventDataOverflow</td><td></td><td>Removed, use: #tiepie_hw_object_set_event_callback</td></tr>
 *   <tr><td>ScpSetEventDataReady</td><td></td><td>Removed, use: #tiepie_hw_object_set_event_callback</td></tr>
 *   <tr><td>ScpSetEventTriggered</td><td></td><td>Removed, use: #tiepie_hw_object_set_event_callback</td></tr>
 *   <tr><td>ScpSetMeasureMode</td><td>#tiepie_hw_oscilloscope_set_measure_mode</td><td></td></tr>
 *   <tr><td>ScpSetMessageConnectionTestCompleted</td><td></td><td>Removed, use: #tiepie_hw_object_set_event_callback</td></tr>
 *   <tr><td>ScpSetMessageDataOverflow</td><td></td><td>Removed, use: #tiepie_hw_object_set_event_callback</td></tr>
 *   <tr><td>ScpSetMessageDataReady</td><td></td><td>Removed, use: #tiepie_hw_object_set_event_callback</td></tr>
 *   <tr><td>ScpSetMessageTriggered</td><td></td><td>Removed, use: #tiepie_hw_object_set_event_callback</td></tr>
 *   <tr><td>ScpSetPreSampleRatio</td><td>#tiepie_hw_oscilloscope_set_pre_sample_ratio</td><td></td></tr>
 *   <tr><td>ScpSetRecordLength</td><td>#tiepie_hw_oscilloscope_set_record_length</td><td></td></tr>
 *   <tr><td>ScpSetResolution</td><td>#tiepie_hw_oscilloscope_set_resolution</td><td></td></tr>
 *   <tr><td>ScpSetSampleFrequency</td><td>#tiepie_hw_oscilloscope_set_sample_rate</td><td></td></tr>
 *   <tr><td>ScpSetSegmentCount</td><td>#tiepie_hw_oscilloscope_set_segment_count</td><td></td></tr>
 *   <tr><td>ScpSetTriggerDelay</td><td>#tiepie_hw_oscilloscope_trigger_set_delay</td><td></td></tr>
 *   <tr><td>ScpSetTriggerHoldOffCount</td><td></td> <td>Removed, no replacement. For setting all presamples valid, see \ref scp_trigger_presamples_valid</td></tr>
 *   <tr><td>ScpSetTriggerTimeOut</td><td>#tiepie_hw_oscilloscope_trigger_set_timeout</td><td></td></tr>
 *   <tr><td>ScpStart</td><td>#tiepie_hw_oscilloscope_start</td><td></td></tr>
 *   <tr><td>ScpStartConnectionTest</td><td>#tiepie_hw_oscilloscope_start_sureconnect</td><td></td></tr>
 *   <tr><td>ScpStop</td><td>#tiepie_hw_oscilloscope_stop</td><td></td></tr>
 *   <tr><td>ScpTrInIsTriggered</td><td>#tiepie_hw_oscilloscope_trigger_input_is_triggered</td><td></td></tr>
 *   <tr><td>SrvConnect</td><td>#tiepie_hw_server_connect</td><td></td></tr>
 *   <tr><td>SrvDisconnect</td><td>#tiepie_hw_server_disconnect</td><td></td></tr>
 *   <tr><td>SrvGetDescription</td><td>#tiepie_hw_server_get_description</td><td></td></tr>
 *   <tr><td>SrvGetID</td><td>#tiepie_hw_server_get_id</td><td></td></tr>
 *   <tr><td>SrvGetIPPort</td><td>#tiepie_hw_server_get_ip_port</td><td></td></tr>
 *   <tr><td>SrvGetIPv4Address</td><td>#tiepie_hw_server_get_ip_address</td><td></td></tr>
 *   <tr><td>SrvGetLastError</td><td>#tiepie_hw_server_get_last_error</td><td></td></tr>
 *   <tr><td>SrvGetName</td><td>#tiepie_hw_server_get_name</td><td></td></tr>
 *   <tr><td>SrvGetStatus</td><td>#tiepie_hw_server_get_status</td><td></td></tr>
 *   <tr><td>SrvGetURL</td><td>#tiepie_hw_server_get_url</td><td></td></tr>
 *   <tr><td>SrvGetVersion</td><td>#tiepie_hw_server_get_version</td><td></td></tr>
 *   <tr><td>SrvRemove</td><td>#tiepie_hw_server_remove</td><td></td></tr>
 * </table>
 *
 * \defgroup Const Constants
 * \{
 * \defgroup TIEPIE_HW_HANDLE Handles
 * \{
 */

#define TIEPIE_HW_HANDLE_INVALID  0

/**
 * \}
 * \defgroup TIEPIE_HW_BOOL_ tiepie_hw_bool values
 * \{
 */

#define TIEPIE_HW_BOOL_FALSE 0
#define TIEPIE_HW_BOOL_TRUE 1

/**
 * \}
 * \defgroup TIEPIE_HW_INTERFACE Interfaces
 * \{
 */

#define TIEPIE_HW_INTERFACE_DEVICE        0x0000000000000001
#define TIEPIE_HW_INTERFACE_OSCILLOSCOPE  0x0000000000000002
#define TIEPIE_HW_INTERFACE_GENERATOR     0x0000000000000004
#define TIEPIE_HW_INTERFACE_SERVER        0x0000000000000010

#define TIEPIE_HW_INTERFACE_COUNT 4

/**
 * \}
 * \defgroup TIEPIE_HW_DEVICETYPE Device type
 * \{
 */

#define TIEPIE_HW_DEVICETYPE_OSCILLOSCOPE  0x00000001 //!< Oscilloscope
#define TIEPIE_HW_DEVICETYPE_GENERATOR     0x00000002 //!< Generator

#define TIEPIE_HW_DEVICETYPE_COUNT  2   //!< Number of device types

/**
 *   \}
 *   \defgroup TIEPIE_HW_CONNECTORTYPE Connector types
 *   \{
 */

#define TIEPIE_HW_CONNECTORTYPE_UNKNOWN  0x00000000

#define TIEPIE_HW_CONNECTORTYPE_BNC        0x00000001
#define TIEPIE_HW_CONNECTORTYPE_BANANA     0x00000002
#define TIEPIE_HW_CONNECTORTYPE_POWERPLUG  0x00000004

#define TIEPIE_HW_CONNECTORTYPE_COUNT  3  //!< Number of connector types

/**
 *     \defgroup TIEPIE_HW_CONNECTORTYPE_MASK Masks
 *     \{
 */

#define TIEPIE_HW_CONNECTORTYPE_MASK  (TIEPIE_HW_CONNECTORTYPE_BNC | TIEPIE_HW_CONNECTORTYPE_BANANA | TIEPIE_HW_CONNECTORTYPE_POWERPLUG)

/**
 *     \}
 *   \}
 *   \defgroup TIEPIE_HW_DATARAWTYPE Raw data types
 *   \{
 */

#define TIEPIE_HW_DATARAWTYPE_UNKNOWN  0x00000000

#define TIEPIE_HW_DATARAWTYPE_INT8     0x00000001 //!< int8_t
#define TIEPIE_HW_DATARAWTYPE_INT16    0x00000002 //!< int16_t
#define TIEPIE_HW_DATARAWTYPE_INT32    0x00000004 //!< int32_t
#define TIEPIE_HW_DATARAWTYPE_INT64    0x00000008 //!< int64_t

#define TIEPIE_HW_DATARAWTYPE_UINT8    0x00000010 //!< uint8_t
#define TIEPIE_HW_DATARAWTYPE_UINT16   0x00000020 //!< uint16_t
#define TIEPIE_HW_DATARAWTYPE_UINT32   0x00000040 //!< uint32_t
#define TIEPIE_HW_DATARAWTYPE_UINT64   0x00000080 //!< uint64_t

#define TIEPIE_HW_DATARAWTYPE_FLOAT32  0x00000100 //!< float
#define TIEPIE_HW_DATARAWTYPE_FLOAT64  0x00000200 //!< double

#define TIEPIE_HW_DATARAWTYPE_COUNT  10  //!< Number of raw data types

/**
 *     \defgroup DATARAWTYPE_MASK_ Masks
 *     \{
 */

#define TIEPIE_HW_DATARAWTYPE_MASK_INT (TIEPIE_HW_DATARAWTYPE_INT8 | TIEPIE_HW_DATARAWTYPE_INT16 | TIEPIE_HW_DATARAWTYPE_INT32 | TIEPIE_HW_DATARAWTYPE_INT64)
#define TIEPIE_HW_DATARAWTYPE_MASK_UINT (TIEPIE_HW_DATARAWTYPE_UINT8 | TIEPIE_HW_DATARAWTYPE_UINT16 | TIEPIE_HW_DATARAWTYPE_UINT32 | TIEPIE_HW_DATARAWTYPE_UINT64)
#define TIEPIE_HW_DATARAWTYPE_MASK_FLOAT (TIEPIE_HW_DATARAWTYPE_FLOAT32 | TIEPIE_HW_DATARAWTYPE_FLOAT64 )
#define TIEPIE_HW_DATARAWTYPE_MASK_FIXED (TIEPIE_HW_DATARAWTYPE_MASK_INT | TIEPIE_HW_DATARAWTYPE_MASK_UINT)

/**
 *     \}
 *   \}
 *   \defgroup TIEPIE_HW_TRISTATE_ tiepie_hw_tristate values
 *   \{
 */

#define TIEPIE_HW_TRISTATE_UNDEFINED 0 //!< Undefined
#define TIEPIE_HW_TRISTATE_FALSE     1 //!< False
#define TIEPIE_HW_TRISTATE_TRUE      2 //!< True

/**
 *   \}
 *   \defgroup TIEPIE_HW_TRIGGERINPUT_INDEX_ Trigger input index values
 *   \{
 */

#define TIEPIE_HW_TRIGGERIO_INDEX_INVALID  0xffff

/**
 *   \}
 *   \defgroup TIEPIE_HW_STRING_LENGTH_ String length values
 *   \{
 */

#define TIEPIE_HW_STRING_LENGTH_NULL_TERMINATED  0xffffffff

/**
 *   \}
 *   \defgroup TIEPIE_HW_SERVER_STATUS_ Server status
 *   \{
 */

#define TIEPIE_HW_SERVER_STATUS_DISCONNECTED   0
#define TIEPIE_HW_SERVER_STATUS_CONNECTING     1
#define TIEPIE_HW_SERVER_STATUS_CONNECTED      2
#define TIEPIE_HW_SERVER_STATUS_DISCONNECTING  3

/**
 *   \}
 *   \defgroup TIEPIE_HW_SERVER_ERROR Server error codes
 *   \{
 */

#define TIEPIE_HW_SERVER_ERROR_NONE                  0
#define TIEPIE_HW_SERVER_ERROR_UNKNOWN               1
#define TIEPIE_HW_SERVER_ERROR_CONNECTIONREFUSED     2
#define TIEPIE_HW_SERVER_ERROR_NETWORKUNREACHABLE    3
#define TIEPIE_HW_SERVER_ERROR_TIMEDOUT              4
#define TIEPIE_HW_SERVER_ERROR_HOSTNAMELOOKUPFAILED  5

/**
  *   \}
  */

//! \cond EXTENDED_API

/**
 *   \defgroup TIEPIE_HW_RANGEINDEX_ Range index values
 *   \{
 */

#define TIEPIE_HW_RANGEINDEX_AUTO  0xffffffff //!< Auto ranging

/**
 *   \}
 */

//! \endcond

/**
 *   \defgroup TIEPIE_HW_HELPER_FUNNCTION Helper functions values
 *   \{
 */

#define TIEPIE_HW_POINTER_ARRAY_MAX_LENGTH 256

/**
 *   \}
 * \}
 */

/**
 * \addtogroup Const
 * \{
 *   \defgroup TIEPIE_HW_AR_ Auto resolution modes
 *   \{
 */

#define TIEPIE_HW_ARMN_COUNT  3 //!< Number of auto resolution modes

/**
 *     \defgroup TIEPIE_HW_ARB_ Bit numbers
 *     \{
 */

#define TIEPIE_HW_ARMB_DISABLED    0
#define TIEPIE_HW_ARMB_NATIVEONLY  1
#define TIEPIE_HW_ARMB_ALL         2

/**
 *     \}
 */

#define TIEPIE_HW_ARM_UNKNOWN     0 //!< Unknown/invalid mode

#define TIEPIE_HW_ARM_DISABLED    (1 << TIEPIE_HW_ARMB_DISABLED)   //!< Resolution does not automatically change.
#define TIEPIE_HW_ARM_NATIVEONLY  (1 << TIEPIE_HW_ARMB_NATIVEONLY) //!< Highest possible native resolution for the current sample rate is used.
#define TIEPIE_HW_ARM_ALL         (1 << TIEPIE_HW_ARMB_ALL)        //!< Highest possible native or enhanced resolution for the current sample rate is used.

/**
 *     \defgroup TIEPIE_HW_ARM_ Masks
 *     \{
 */

#define TIEPIE_HW_ARMM_NONE    0
#define TIEPIE_HW_ARMM_ALL     ((1 << TIEPIE_HW_ARMN_COUNT) - 1)
#define TIEPIE_HW_ARMM_ENABLED (TIEPIE_HW_ARMM_ALL & ~TIEPIE_HW_ARM_DISABLED)

/**
 *     \}
 *   \}
 * \}
 */
/**
 * \addtogroup Const
 * \{
 *   \defgroup TIEPIE_HW_CK_ Coupling
 *   \{
 */

#define TIEPIE_HW_CKN_COUNT  5 //!< Number of couplings

/**
 *     \defgroup TIEPIE_HW_CKB_ Bit numbers
 *     \{
 */

#define TIEPIE_HW_CKB_DCV    0  //!< Volt TIEPIE_HW_DC
#define TIEPIE_HW_CKB_ACV    1  //!< Volt TIEPIE_HW_AC
#define TIEPIE_HW_CKB_DCA    2  //!< Ampere TIEPIE_HW_DC
#define TIEPIE_HW_CKB_ACA    3  //!< Ampere TIEPIE_HW_AC
#define TIEPIE_HW_CKB_OHM    4  //!< Ohm

/**
 *     \}
 */

#define TIEPIE_HW_CK_UNKNOWN 0                  //!< Unknown/invalid coupling

#define TIEPIE_HW_CK_DCV     (1 << TIEPIE_HW_CKB_DCV)   //!< Volt TIEPIE_HW_DC
#define TIEPIE_HW_CK_ACV     (1 << TIEPIE_HW_CKB_ACV)   //!< Volt TIEPIE_HW_AC
#define TIEPIE_HW_CK_DCA     (1 << TIEPIE_HW_CKB_DCA)   //!< Ampere TIEPIE_HW_DC
#define TIEPIE_HW_CK_ACA     (1 << TIEPIE_HW_CKB_ACA)   //!< Ampere TIEPIE_HW_AC
#define TIEPIE_HW_CK_OHM     (1 << TIEPIE_HW_CKB_OHM)   //!< Ohm

/**
 *     \defgroup TIEPIE_HW_CKM_ Masks
 *     \{
 */

#define TIEPIE_HW_CKM_NONE  0
#define TIEPIE_HW_CKM_V     (TIEPIE_HW_CK_DCV | TIEPIE_HW_CK_ACV) //!< Volt
#define TIEPIE_HW_CKM_A     (TIEPIE_HW_CK_DCA | TIEPIE_HW_CK_ACA) //!< Ampere
#define TIEPIE_HW_CKM_OHM   (TIEPIE_HW_CK_OHM)          //!< Ohm

#define TIEPIE_HW_CKM_ASYMMETRICRANGE (TIEPIE_HW_CKM_OHM)       //!< 0 to +Range
#define TIEPIE_HW_CKM_SYMMETRICRANGE  (TIEPIE_HW_CKM_V | TIEPIE_HW_CKM_A) //!< -Range to +Range

#define TIEPIE_HW_CKM_DC (TIEPIE_HW_CK_DCV | TIEPIE_HW_CK_DCA | TIEPIE_HW_CK_OHM)
#define TIEPIE_HW_CKM_AC (TIEPIE_HW_CK_ACV | TIEPIE_HW_CK_ACA)

/**
 *     \}
 *   \}
 * \}
 */
/**
 * \addtogroup Const
 * \{
 *   \defgroup TIEPIE_HW_CO_ Clock output types
 *   \{
 */

#define TIEPIE_HW_CON_COUNT  3 //!< Number of clock output types

/**
 *     \defgroup TIEPIE_HW_COB_ Bit numbers
 *     \{
 */

#define TIEPIE_HW_COB_DISABLED  0 //!< No clock output
#define TIEPIE_HW_COB_SAMPLE    1 //!< Sample clock
#define TIEPIE_HW_COB_FIXED     2 //!< Fixed clock

/**
 *     \}
 */

#define TIEPIE_HW_CO_DISABLED  (1 << TIEPIE_HW_COB_DISABLED) //!< No clock output
#define TIEPIE_HW_CO_SAMPLE    (1 << TIEPIE_HW_COB_SAMPLE)   //!< Sample clock
#define TIEPIE_HW_CO_FIXED     (1 << TIEPIE_HW_COB_FIXED)    //!< Fixed clock

/**
 *     \defgroup TIEPIE_HW_COB_ Bit numbers
 *     \{
 */

#define TIEPIE_HW_COM_NONE       0
#define TIEPIE_HW_COM_ALL        ((1 << TIEPIE_HW_CON_COUNT) - 1)
#define TIEPIE_HW_COM_ENABLED    (TIEPIE_HW_COM_ALL & ~TIEPIE_HW_CO_DISABLED)
#define TIEPIE_HW_COM_FREQUENCY  (TIEPIE_HW_CO_FIXED)

/**
 *     \}
 *   \}
 * \}
 */
/**
 * \addtogroup Const
 * \{
 *   \defgroup TIEPIE_HW_CS_ Clock sources
 *   \{
 */

#define TIEPIE_HW_CSN_COUNT  2 //!< Number of clock sources

/**
 *     \defgroup TIEPIE_HW_CSB_ Bit numbers
 *     \{
 */

#define TIEPIE_HW_CSB_EXTERNAL  0 //!< External clock
#define TIEPIE_HW_CSB_INTERNAL  1 //!< Internal clock

/**
 *     \}
 */

#define TIEPIE_HW_CS_EXTERNAL  (1 << TIEPIE_HW_CSB_EXTERNAL)  //!< External clock
#define TIEPIE_HW_CS_INTERNAL  (1 << TIEPIE_HW_CSB_INTERNAL)  //!< Internal clock

/**
 *     \defgroup TIEPIE_HW_CSM_ Masks
 *     \{
 */

#define TIEPIE_HW_CSM_NONE       0
#define TIEPIE_HW_CSM_ALL        ((1 << TIEPIE_HW_CSN_COUNT) - 1)
#define TIEPIE_HW_CSM_FREQUENCY  (TIEPIE_HW_CS_EXTERNAL)

/**
 *     \}
 *   \}
 * \}
 */
/**
 * \addtogroup Const
 * \{
 *   \defgroup TIEPIE_HW_FM_ Frequency modes
 *   \{
 */

#define TIEPIE_HW_FMN_COUNT  2 //!< Number of frequency modes

/**
 *     \defgroup TIEPIE_HW_FMB_ Bit numbers
 *     \{
 */

#define TIEPIE_HW_FMB_SIGNALFREQUENCY  0
#define TIEPIE_HW_FMB_SAMPLERATE       1

/**
 *     \}
 */

#define TIEPIE_HW_FM_UNKNOWN 0x00000000

#define TIEPIE_HW_FM_SIGNALFREQUENCY (1 << TIEPIE_HW_FMB_SIGNALFREQUENCY)
#define TIEPIE_HW_FM_SAMPLERATE      (1 << TIEPIE_HW_FMB_SAMPLERATE)

/**
 *     \defgroup TIEPIE_HW_FMM_ Masks
 *     \{
 */

#define TIEPIE_HW_FMM_NONE  0x00000000
#define TIEPIE_HW_FMM_ALL   ((1 << TIEPIE_HW_FMN_COUNT) - 1)

/**
 *     \}
 *   \}
 * \}
 */
/**
 * \addtogroup Const
 * \{
 *   \defgroup TIEPIE_HW_GM_ Generator modes
 *   \{
 */

#define TIEPIE_HW_GMN_COUNT  12 //!< Number of generator modes

/**
 *     \defgroup TIEPIE_HW_GMB_ Bit numbers
 *     \{
 */

#define TIEPIE_HW_GMB_CONTINUOUS                  0
#define TIEPIE_HW_GMB_BURST_COUNT                 1
#define TIEPIE_HW_GMB_GATED_PERIODS               2
#define TIEPIE_HW_GMB_GATED                       3
#define TIEPIE_HW_GMB_GATED_PERIOD_START          4
#define TIEPIE_HW_GMB_GATED_PERIOD_FINISH         5
#define TIEPIE_HW_GMB_GATED_RUN                   6
#define TIEPIE_HW_GMB_GATED_RUN_OUTPUT            7
#define TIEPIE_HW_GMB_BURST_SAMPLE_COUNT          8
#define TIEPIE_HW_GMB_BURST_SAMPLE_COUNT_OUTPUT   9
#define TIEPIE_HW_GMB_BURST_SEGMENT_COUNT         10
#define TIEPIE_HW_GMB_BURST_SEGMENT_COUNT_OUTPUT  11

/**
 *     \}
 */

#define TIEPIE_HW_GM_UNKNOWN  0

#define TIEPIE_HW_GM_CONTINUOUS                  (1 << TIEPIE_HW_GMB_CONTINUOUS)
#define TIEPIE_HW_GM_BURST_COUNT                 (1 << TIEPIE_HW_GMB_BURST_COUNT)
#define TIEPIE_HW_GM_GATED_PERIODS               (1 << TIEPIE_HW_GMB_GATED_PERIODS)
#define TIEPIE_HW_GM_GATED                       (1 << TIEPIE_HW_GMB_GATED)
#define TIEPIE_HW_GM_GATED_PERIOD_START          (1 << TIEPIE_HW_GMB_GATED_PERIOD_START)
#define TIEPIE_HW_GM_GATED_PERIOD_FINISH         (1 << TIEPIE_HW_GMB_GATED_PERIOD_FINISH)
#define TIEPIE_HW_GM_GATED_RUN                   (1 << TIEPIE_HW_GMB_GATED_RUN)
#define TIEPIE_HW_GM_GATED_RUN_OUTPUT            (1 << TIEPIE_HW_GMB_GATED_RUN_OUTPUT)
#define TIEPIE_HW_GM_BURST_SAMPLE_COUNT          (1 << TIEPIE_HW_GMB_BURST_SAMPLE_COUNT)
#define TIEPIE_HW_GM_BURST_SAMPLE_COUNT_OUTPUT   (1 << TIEPIE_HW_GMB_BURST_SAMPLE_COUNT_OUTPUT)
#define TIEPIE_HW_GM_BURST_SEGMENT_COUNT         (1 << TIEPIE_HW_GMB_BURST_SEGMENT_COUNT)
#define TIEPIE_HW_GM_BURST_SEGMENT_COUNT_OUTPUT  (1 << TIEPIE_HW_GMB_BURST_SEGMENT_COUNT_OUTPUT)

/**
 *     \defgroup TIEPIE_HW_GMM_ Masks
 *     \{
 */

#define TIEPIE_HW_GMM_NONE                 0
#define TIEPIE_HW_GMM_BURST_COUNT          (TIEPIE_HW_GM_BURST_COUNT)
#define TIEPIE_HW_GMM_GATED                (TIEPIE_HW_GM_GATED_PERIODS | TIEPIE_HW_GM_GATED | TIEPIE_HW_GM_GATED_PERIOD_START | TIEPIE_HW_GM_GATED_PERIOD_FINISH | TIEPIE_HW_GM_GATED_RUN | TIEPIE_HW_GM_GATED_RUN_OUTPUT)
#define TIEPIE_HW_GMM_BURST_SAMPLE_COUNT   (TIEPIE_HW_GM_BURST_SAMPLE_COUNT | TIEPIE_HW_GM_BURST_SAMPLE_COUNT_OUTPUT)
#define TIEPIE_HW_GMM_BURST_SEGMENT_COUNT  (TIEPIE_HW_GM_BURST_SEGMENT_COUNT | TIEPIE_HW_GM_BURST_SEGMENT_COUNT_OUTPUT)
#define TIEPIE_HW_GMM_BURST                (TIEPIE_HW_GMM_BURST_COUNT | TIEPIE_HW_GMM_BURST_SAMPLE_COUNT | TIEPIE_HW_GMM_BURST_SEGMENT_COUNT)
#define TIEPIE_HW_GMM_REQUIRE_TRIGGER      (TIEPIE_HW_GMM_GATED | TIEPIE_HW_GMM_BURST_SAMPLE_COUNT | TIEPIE_HW_GMM_BURST_SEGMENT_COUNT)  //!< Generator modes that require an enabeld trigger input.
#define TIEPIE_HW_GMM_ALL                  ((1ULL << TIEPIE_HW_GMN_COUNT) - 1)

#define TIEPIE_HW_GMM_SIGNALFREQUENCY  (TIEPIE_HW_GMM_ALL & ~TIEPIE_HW_GMM_BURST_SAMPLE_COUNT)  //!< Supported generator modes when frequency mode is signal frequency.
#define TIEPIE_HW_GMM_SAMPLERATE       (TIEPIE_HW_GMM_ALL)                            //!< Supported generator modes when frequency mode is sample rate.

#define TIEPIE_HW_GMM_SINE         (TIEPIE_HW_GMM_SIGNALFREQUENCY)                             //!< Supported generator modes when signal type is sine.
#define TIEPIE_HW_GMM_TRIANGLE     (TIEPIE_HW_GMM_SIGNALFREQUENCY)                             //!< Supported generator modes when signal type is triangle.
#define TIEPIE_HW_GMM_SQUARE       (TIEPIE_HW_GMM_SIGNALFREQUENCY)                             //!< Supported generator modes when signal type is square.
#define TIEPIE_HW_GMM_DC           (TIEPIE_HW_GM_CONTINUOUS)                                   //!< Supported generator modes when signal type is TIEPIE_HW_DC.
#define TIEPIE_HW_GMM_NOISE        (TIEPIE_HW_GM_CONTINUOUS | TIEPIE_HW_GM_GATED)                        //!< Supported generator modes when signal type is noise.
#define TIEPIE_HW_GMM_ARBITRARY    (TIEPIE_HW_GMM_SIGNALFREQUENCY | TIEPIE_HW_GMM_SAMPLERATE)            //!< Supported generator modes when signal type is arbitrary.
#define TIEPIE_HW_GMM_PULSE        (TIEPIE_HW_GMM_SIGNALFREQUENCY & ~TIEPIE_HW_GMM_BURST_SEGMENT_COUNT)  //!< Supported generator modes when signal type is pulse.

/**
 *     \}
 *   \}
 * \}
 */
/**
 * \addtogroup Const
 * \{
 *   \defgroup TIEPIE_HW_GS_ Generator status flags
 *   \{
 *     \brief Flags to indicate the signal generation status of a generator.
 */

#define TIEPIE_HW_GSN_COUNT  4 //!< The number of generator status flags.

/**
 *     \defgroup TIEPIE_HW_GSB_ Bit numbers
 *     \{
 *       \brief Bit numbers used to create the signal generation status flags of a generator.
 */

#define TIEPIE_HW_GSB_STOPPED      0
#define TIEPIE_HW_GSB_RUNNING      1
#define TIEPIE_HW_GSB_BURSTACTIVE  2
#define TIEPIE_HW_GSB_WAITING      3

/**
 *     \}
 */

#define TIEPIE_HW_GS_STOPPED      (1 << TIEPIE_HW_GSB_STOPPED)     //!< The signal generation is stopped.
#define TIEPIE_HW_GS_RUNNING      (1 << TIEPIE_HW_GSB_RUNNING)     //!< The signal generation is running.
#define TIEPIE_HW_GS_BURSTACTIVE  (1 << TIEPIE_HW_GSB_BURSTACTIVE) //!< The generator is operating in burst mode.
#define TIEPIE_HW_GS_WAITING      (1 << TIEPIE_HW_GSB_WAITING)     //!< The generator is waiting for a burst to be started.

/**
 *     \defgroup TIEPIE_HW_GSM_ Masks
 *     \{
 */

#define TIEPIE_HW_GSM_NONE  0
#define TIEPIE_HW_GSM_ALL   ((1UL << TIEPIE_HW_GSN_COUNT) - 1)

/**
 *     \}
 *   \}
 * \}
 */
/**
 * \addtogroup Const
 * \{
 *   \defgroup TIEPIE_HW_MM_ Measure modes
 *   \{
 */

#define TIEPIE_HW_MMN_COUNT  2 //!< Number of measure modes

/**
 *     \defgroup TIEPIE_HW_MMB_ Bit numbers
 *     \{
 */

#define TIEPIE_HW_MMB_STREAM 0 //!< Stream mode bit number
#define TIEPIE_HW_MMB_BLOCK  1 //!< Block mode bit number

/**
 *     \}
 *     \defgroup TIEPIE_HW_MMM_ Masks
 *     \{
 */

#define TIEPIE_HW_MMM_NONE 0
#define TIEPIE_HW_MMM_ALL  ((1 << TIEPIE_HW_MMN_COUNT) - 1)

/**
 *     \}
 */

#define TIEPIE_HW_MM_UNKNOWN 0                   //!< Unknown/invalid mode

#define TIEPIE_HW_MM_STREAM  (1 << TIEPIE_HW_MMB_STREAM) //!< Stream mode
#define TIEPIE_HW_MM_BLOCK   (1 << TIEPIE_HW_MMB_BLOCK ) //!< Block mode

/**
 *   \}
 * \}
 */
/**
 * \addtogroup Const
 * \{
 *   \defgroup TIEPIE_HW_ST_ Signal types
 *   \{
 */

#define TIEPIE_HW_STN_COUNT  7 //!< Number of signal types

/**
 *     \defgroup TIEPIE_HW_STB_ Bit numbers
 *     \{
 */

#define TIEPIE_HW_STB_SINE       0
#define TIEPIE_HW_STB_TRIANGLE   1
#define TIEPIE_HW_STB_SQUARE     2
#define TIEPIE_HW_STB_DC         3
#define TIEPIE_HW_STB_NOISE      4
#define TIEPIE_HW_STB_ARBITRARY  5
#define TIEPIE_HW_STB_PULSE      6

/**
 *     \}
 */

#define TIEPIE_HW_ST_UNKNOWN     0

#define TIEPIE_HW_ST_SINE        (1 << TIEPIE_HW_STB_SINE)
#define TIEPIE_HW_ST_TRIANGLE    (1 << TIEPIE_HW_STB_TRIANGLE)
#define TIEPIE_HW_ST_SQUARE      (1 << TIEPIE_HW_STB_SQUARE)
#define TIEPIE_HW_ST_DC          (1 << TIEPIE_HW_STB_DC)
#define TIEPIE_HW_ST_NOISE       (1 << TIEPIE_HW_STB_NOISE)
#define TIEPIE_HW_ST_ARBITRARY   (1 << TIEPIE_HW_STB_ARBITRARY)
#define TIEPIE_HW_ST_PULSE       (1 << TIEPIE_HW_STB_PULSE)

/**
 *     \defgroup TIEPIE_HW_STM_ Signal type masks
 *     \{
 */

#define TIEPIE_HW_STM_NONE       0

#define TIEPIE_HW_STM_AMPLITUDE         (TIEPIE_HW_ST_SINE | TIEPIE_HW_ST_TRIANGLE | TIEPIE_HW_ST_SQUARE         | TIEPIE_HW_ST_NOISE | TIEPIE_HW_ST_ARBITRARY | TIEPIE_HW_ST_PULSE)
#define TIEPIE_HW_STM_OFFSET            (TIEPIE_HW_ST_SINE | TIEPIE_HW_ST_TRIANGLE | TIEPIE_HW_ST_SQUARE | TIEPIE_HW_ST_DC | TIEPIE_HW_ST_NOISE | TIEPIE_HW_ST_ARBITRARY | TIEPIE_HW_ST_PULSE)
#define TIEPIE_HW_STM_FREQUENCY         (TIEPIE_HW_ST_SINE | TIEPIE_HW_ST_TRIANGLE | TIEPIE_HW_ST_SQUARE         | TIEPIE_HW_ST_NOISE | TIEPIE_HW_ST_ARBITRARY | TIEPIE_HW_ST_PULSE)
#define TIEPIE_HW_STM_PHASE             (TIEPIE_HW_ST_SINE | TIEPIE_HW_ST_TRIANGLE | TIEPIE_HW_ST_SQUARE                    | TIEPIE_HW_ST_ARBITRARY | TIEPIE_HW_ST_PULSE)
#define TIEPIE_HW_STM_SYMMETRY          (TIEPIE_HW_ST_SINE | TIEPIE_HW_ST_TRIANGLE | TIEPIE_HW_ST_SQUARE                                             )
#define TIEPIE_HW_STM_WIDTH             (                                                                      TIEPIE_HW_ST_PULSE)
#define TIEPIE_HW_STM_LEADINGEDGETIME   (                                                                      TIEPIE_HW_ST_PULSE)
#define TIEPIE_HW_STM_TRAILINGEDGETIME  (                                                                      TIEPIE_HW_ST_PULSE)
#define TIEPIE_HW_STM_DATALENGTH        (                                                       TIEPIE_HW_ST_ARBITRARY           )
#define TIEPIE_HW_STM_DATA              (                                                       TIEPIE_HW_ST_ARBITRARY           )

#define TIEPIE_HW_STM_EDGETIME (TIEPIE_HW_STM_LEADINGEDGETIME & TIEPIE_HW_STM_TRAILINGEDGETIME)

/**
 *     \}
 *   \}
 * \}
 */
/**
 * \addtogroup Const
 * \{
 *   \defgroup TIEPIE_HW_TC_ Trigger conditions
 *   \{
 */

#define TIEPIE_HW_TCN_COUNT  5 //!< Number of trigger conditions

/**
 *     \defgroup TIEPIE_HW_TCB_ Bit numbers
 *     \{
 */

#define TIEPIE_HW_TCB_NONE     0
#define TIEPIE_HW_TCB_SMALLER  1
#define TIEPIE_HW_TCB_LARGER   2
#define TIEPIE_HW_TCB_INSIDE   3
#define TIEPIE_HW_TCB_OUTSIDE  4

/**
 *     \}
 */

#define TIEPIE_HW_TC_UNKNOWN  0

#define TIEPIE_HW_TC_NONE     (1 << TIEPIE_HW_TCB_NONE)
#define TIEPIE_HW_TC_SMALLER  (1 << TIEPIE_HW_TCB_SMALLER)
#define TIEPIE_HW_TC_LARGER   (1 << TIEPIE_HW_TCB_LARGER)
#define TIEPIE_HW_TC_INSIDE   (1 << TIEPIE_HW_TCB_INSIDE)
#define TIEPIE_HW_TC_OUTSIDE  (1 << TIEPIE_HW_TCB_OUTSIDE)

/**
 *     \defgroup TIEPIE_HW_TCM_ Masks
 *     \{
 */

#define TIEPIE_HW_TCM_NONE     0 //!< No conditions
#define TIEPIE_HW_TCM_ALL      ((1 << TIEPIE_HW_TCN_COUNT) - 1) //!< All conditions
#define TIEPIE_HW_TCM_ENABLED  (TIEPIE_HW_TCM_ALL & ~TIEPIE_HW_TC_NONE) //!< All conditions except #TIEPIE_HW_TC_NONE.

/**
 *     \}
 *   \}
 * \}
 */
/**
 * \addtogroup macro
 * \{
 */

#define TIEPIE_HW_TRIGGER_IO_ID(pgid , sgid, fid)  ((TIEPIE_HW_DN_MAIN << TIEPIE_HW_TIOID_SHIFT_DN) | ((pgid) << TIEPIE_HW_TIOID_SHIFT_PGID) | ((sgid) << TIEPIE_HW_TIOID_SHIFT_SGID) | ((fid) << TIEPIE_HW_TIOID_SHIFT_FID))

#define TIEPIE_HW_COMBI_TRIGGER_IO_ID(dn, tiid)  (((dn) << TIEPIE_HW_TIOID_SHIFT_DN) | ((tiid) & ((1 << TIEPIE_HW_TIOID_SHIFT_DN) - 1)))

/**
 * \}
 * \addtogroup Const
 * \{
 *   \defgroup TIEPIE_HW_TIOID_ Trigger input/output TIEPIE_HW_ID's
 *   \{
 *     \defgroup TIEPIE_HW_DN_ Device Numbers
 *     \{
 */

#define TIEPIE_HW_DN_MAIN        0 //!< The device itself.
#define TIEPIE_HW_DN_SUB_FIRST   1 //!< First sub device in a combined device.
#define TIEPIE_HW_DN_SUB_SECOND  2 //!< Second sub device in a combined device.

/**
 *     \}
 *     \defgroup TIEPIE_HW_PGID_ Port Group TIEPIE_HW_ID's
 *     \{
 */

#define TIEPIE_HW_PGID_OSCILLOSCOPE   1 //!< Oscilloscope
#define TIEPIE_HW_PGID_GENERATOR      2 //!< Generator
#define TIEPIE_HW_PGID_EXTERNAL_DSUB  3 //!< External D-sub

/**
 *     \}
 *     \defgroup TIEPIE_HW_SGID_ Device Sub Group TIEPIE_HW_ID's
 *     \{
 *       \defgroup SGID_scpgen Oscilloscope or generator
 *       \{
 */

#define TIEPIE_HW_SGID_MAIN      0 //!< The oscilloscope or function generator itself.
#define TIEPIE_HW_SGID_CHANNEL1  1
#define TIEPIE_HW_SGID_CHANNEL2  2

/**
 *       \}
 *       \defgroup SGID_ext External
 *       \{
 */

#define TIEPIE_HW_SGID_PIN1  1
#define TIEPIE_HW_SGID_PIN2  2
#define TIEPIE_HW_SGID_PIN3  3

/**
 *       \}
 *     \}
 *     \defgroup TIEPIE_HW_FID_ Function TIEPIE_HW_ID's
 *     \{
 *       \defgroup TIEPIE_HW_FID_SCP Oscilloscopes and oscilloscope channels
 *       \{
 */

#define TIEPIE_HW_FID_SCP_TRIGGERED  0

/**
 *       \}
 *       \defgroup TIEPIE_HW_FID_GEN Generators
 *       \{
 */

#define TIEPIE_HW_FID_GEN_START       0
#define TIEPIE_HW_FID_GEN_STOP        1
#define TIEPIE_HW_FID_GEN_NEW_PERIOD  2


/**
 *       \}
 *       \defgroup TIEPIE_HW_FID_EXT External
 *       \{
 */

#define TIEPIE_HW_FID_EXT_TRIGGERED  0

/**
 *       \}
 *     \}
 *     \defgroup TIEPIE_HW_TIOID_SC_ Shift constants
 *     \{
 */

#define TIEPIE_HW_TIOID_SHIFT_PGID  20
#define TIEPIE_HW_TIOID_SHIFT_DN    24
#define TIEPIE_HW_TIOID_SHIFT_SGID  8
#define TIEPIE_HW_TIOID_SHIFT_FID   0

/**
 *     \}
 *     \defgroup TIEPIE_HW_TIID_ Trigger input TIEPIE_HW_ID's
 *     \{
 */

#define TIEPIE_HW_TIID_INVALID              0
#define TIEPIE_HW_TIID_EXT1                 TIEPIE_HW_TRIGGER_IO_ID(TIEPIE_HW_PGID_EXTERNAL_DSUB, TIEPIE_HW_SGID_PIN1, TIEPIE_HW_FID_EXT_TRIGGERED )
#define TIEPIE_HW_TIID_EXT2                 TIEPIE_HW_TRIGGER_IO_ID(TIEPIE_HW_PGID_EXTERNAL_DSUB, TIEPIE_HW_SGID_PIN2, TIEPIE_HW_FID_EXT_TRIGGERED )
#define TIEPIE_HW_TIID_EXT3                 TIEPIE_HW_TRIGGER_IO_ID(TIEPIE_HW_PGID_EXTERNAL_DSUB, TIEPIE_HW_SGID_PIN3, TIEPIE_HW_FID_EXT_TRIGGERED )
#define TIEPIE_HW_TIID_GENERATOR_START      TIEPIE_HW_TRIGGER_IO_ID(TIEPIE_HW_PGID_GENERATOR    , TIEPIE_HW_SGID_MAIN, TIEPIE_HW_FID_GEN_START     )
#define TIEPIE_HW_TIID_GENERATOR_STOP       TIEPIE_HW_TRIGGER_IO_ID(TIEPIE_HW_PGID_GENERATOR    , TIEPIE_HW_SGID_MAIN, TIEPIE_HW_FID_GEN_STOP      )
#define TIEPIE_HW_TIID_GENERATOR_NEW_PERIOD TIEPIE_HW_TRIGGER_IO_ID(TIEPIE_HW_PGID_GENERATOR    , TIEPIE_HW_SGID_MAIN, TIEPIE_HW_FID_GEN_NEW_PERIOD)

/**
 *     \}
 *     \defgroup TIEPIE_HW_TOID_ Trigger output TIEPIE_HW_ID's
 *     \{
 */

#define TIEPIE_HW_TOID_INVALID  0
#define TIEPIE_HW_TOID_EXT1     TIEPIE_HW_TRIGGER_IO_ID(TIEPIE_HW_PGID_EXTERNAL_DSUB, TIEPIE_HW_SGID_PIN1, TIEPIE_HW_FID_EXT_TRIGGERED)
#define TIEPIE_HW_TOID_EXT2     TIEPIE_HW_TRIGGER_IO_ID(TIEPIE_HW_PGID_EXTERNAL_DSUB, TIEPIE_HW_SGID_PIN2, TIEPIE_HW_FID_EXT_TRIGGERED)
#define TIEPIE_HW_TOID_EXT3     TIEPIE_HW_TRIGGER_IO_ID(TIEPIE_HW_PGID_EXTERNAL_DSUB, TIEPIE_HW_SGID_PIN3, TIEPIE_HW_FID_EXT_TRIGGERED)

/**
 *     \}
 *   \}
 * \}
 */
/**
 * \addtogroup Const
 * \{
 *   \defgroup TIEPIE_HW_TK_ Trigger kinds
 *   \{
 */

#define TIEPIE_HW_TKN_COUNT  15 //!< Number of trigger kinds

/**
 *     \defgroup TIEPIE_HW_TKB_ Bit numbers
 *     \{
 */

#define TIEPIE_HW_TKB_RISINGEDGE          0
#define TIEPIE_HW_TKB_FALLINGEDGE         1
#define TIEPIE_HW_TKB_INWINDOW            2
#define TIEPIE_HW_TKB_OUTWINDOW           3
#define TIEPIE_HW_TKB_ANYEDGE             4
#define TIEPIE_HW_TKB_ENTERWINDOW         5
#define TIEPIE_HW_TKB_EXITWINDOW          6
#define TIEPIE_HW_TKB_PULSEWIDTHPOSITIVE  7
#define TIEPIE_HW_TKB_PULSEWIDTHNEGATIVE  8
#define TIEPIE_HW_TKB_PULSEWIDTHEITHER    9
#define TIEPIE_HW_TKB_RUNTPULSEPOSITIVE  10
#define TIEPIE_HW_TKB_RUNTPULSENEGATIVE  11
#define TIEPIE_HW_TKB_RUNTPULSEEITHER    12
#define TIEPIE_HW_TKB_INTERVALRISING     13
#define TIEPIE_HW_TKB_INTERVALFALLING    14

/**
 *     \}
 */

#define TIEPIE_HW_TK_UNKNOWN            0                                   //!< Unknown/invalid trigger kind
#define TIEPIE_HW_TK_RISINGEDGE         (1ULL << TIEPIE_HW_TKB_RISINGEDGE)          //!< Rising edge
#define TIEPIE_HW_TK_FALLINGEDGE        (1ULL << TIEPIE_HW_TKB_FALLINGEDGE)         //!< Falling edge
#define TIEPIE_HW_TK_INWINDOW           (1ULL << TIEPIE_HW_TKB_INWINDOW)            //!< Inside window
#define TIEPIE_HW_TK_OUTWINDOW          (1ULL << TIEPIE_HW_TKB_OUTWINDOW)           //!< Outside window
#define TIEPIE_HW_TK_ANYEDGE            (1ULL << TIEPIE_HW_TKB_ANYEDGE)             //!< Any edge
#define TIEPIE_HW_TK_ENTERWINDOW        (1ULL << TIEPIE_HW_TKB_ENTERWINDOW)         //!< Enter window
#define TIEPIE_HW_TK_EXITWINDOW         (1ULL << TIEPIE_HW_TKB_EXITWINDOW)          //!< Exit window
#define TIEPIE_HW_TK_PULSEWIDTHPOSITIVE (1ULL << TIEPIE_HW_TKB_PULSEWIDTHPOSITIVE)  //!< Positive pulse width
#define TIEPIE_HW_TK_PULSEWIDTHNEGATIVE (1ULL << TIEPIE_HW_TKB_PULSEWIDTHNEGATIVE)  //!< Negative pulse width
#define TIEPIE_HW_TK_PULSEWIDTHEITHER   (1ULL << TIEPIE_HW_TKB_PULSEWIDTHEITHER)    //!< Positive or negative pulse width
#define TIEPIE_HW_TK_RUNTPULSEPOSITIVE  (1ULL << TIEPIE_HW_TKB_RUNTPULSEPOSITIVE)   //!< Positive runt pulse
#define TIEPIE_HW_TK_RUNTPULSENEGATIVE  (1ULL << TIEPIE_HW_TKB_RUNTPULSENEGATIVE)   //!< Negative runt pulse
#define TIEPIE_HW_TK_RUNTPULSEEITHER    (1ULL << TIEPIE_HW_TKB_RUNTPULSEEITHER)     //!< Positive or negative runt pulse
#define TIEPIE_HW_TK_INTERVALRISING     (1ULL << TIEPIE_HW_TKB_INTERVALRISING)      //!< Interval (rising edge)
#define TIEPIE_HW_TK_INTERVALFALLING    (1ULL << TIEPIE_HW_TKB_INTERVALFALLING)     //!< Interval (falling edge)

/**
 *     \defgroup TIEPIE_HW_TKM_ Masks
 *     \{
 */

#define TIEPIE_HW_TKM_NONE             0 //!< No trigger kinds
#define TIEPIE_HW_TKM_EDGE             (TIEPIE_HW_TK_RISINGEDGE | TIEPIE_HW_TK_FALLINGEDGE | TIEPIE_HW_TK_ANYEDGE) //!< All edge triggers
#define TIEPIE_HW_TKM_WINDOW           (TIEPIE_HW_TK_INWINDOW | TIEPIE_HW_TK_OUTWINDOW | TIEPIE_HW_TK_ENTERWINDOW | TIEPIE_HW_TK_EXITWINDOW) //!< All window triggers
#define TIEPIE_HW_TKM_PULSEWIDTH       (TIEPIE_HW_TK_PULSEWIDTHPOSITIVE | TIEPIE_HW_TK_PULSEWIDTHNEGATIVE | TIEPIE_HW_TK_PULSEWIDTHEITHER) //!< All pulse width triggers
#define TIEPIE_HW_TKM_RUNTPULSE        (TIEPIE_HW_TK_RUNTPULSEPOSITIVE | TIEPIE_HW_TK_RUNTPULSENEGATIVE | TIEPIE_HW_TK_RUNTPULSEEITHER) //!< All runt pulse triggers
#define TIEPIE_HW_TKM_PULSE            (TIEPIE_HW_TKM_PULSEWIDTH | TIEPIE_HW_TKM_RUNTPULSE) //!< All pulse triggers
#define TIEPIE_HW_TKM_INTERVAL         (TIEPIE_HW_TK_INTERVALRISING | TIEPIE_HW_TK_INTERVALFALLING) //!< All interval triggers
#define TIEPIE_HW_TKM_TIME             (TIEPIE_HW_TKM_PULSEWIDTH | TIEPIE_HW_TKM_WINDOW | TIEPIE_HW_TKM_RUNTPULSE | TIEPIE_HW_TKM_INTERVAL) //!< All trigger kinds that may have a time property.
#define TIEPIE_HW_TKM_ALL              ((1ULL << TIEPIE_HW_TKN_COUNT) - 1) //!< All trigger kinds

/**
 *     \}
 *   \}
 * \}
 */
/**
 * \addtogroup Const
 * \{
 *   \defgroup TIEPIE_HW_TLM_ Trigger level modes
 *   \{
 */

#define TIEPIE_HW_TLMN_COUNT  2 //!< Number of trigger level modes

/**
 *     \defgroup TIEPIE_HW_TLMB_ Bit numbers
 *     \{
 */

#define TIEPIE_HW_TLMB_RELATIVE  0
#define TIEPIE_HW_TLMB_ABSOLUTE  1

/**
 *     \}
 */

#define TIEPIE_HW_TLM_UNKNOWN  0

#define TIEPIE_HW_TLM_RELATIVE  (1 << TIEPIE_HW_TLMB_RELATIVE)
#define TIEPIE_HW_TLM_ABSOLUTE  (1 << TIEPIE_HW_TLMB_ABSOLUTE)

/**
 *     \defgroup TIEPIE_HW_TLMM_ Masks
 *     \{
 */

#define TIEPIE_HW_TLMM_NONE  0
#define TIEPIE_HW_TLMM_ALL   ((1 << TIEPIE_HW_TLMN_COUNT) - 1)

/**
 *     \}
 *   \}
 * \}
 */
/**
 * \addtogroup Const
 * \{
 *   \defgroup TIEPIE_HW_TO_ Trigger time outs
 *   \{
 */

#define TIEPIE_HW_TO_INFINITY (-1.0) //!< No time out

/**
 *   \}
 * \}
 */
/**
 * \addtogroup Const
 * \{
 *   \defgroup TIEPIE_HW_TOE_ Trigger output events
 *   \{
 */

#define TIEPIE_HW_TOEN_COUNT  6 //!< Number of trigger output events

/**
 *     \defgroup TIEPIE_HW_TOEB_ Bit numbers
 *     \{
 */

#define TIEPIE_HW_TOEB_GENERATOR_START         0
#define TIEPIE_HW_TOEB_GENERATOR_STOP          1
#define TIEPIE_HW_TOEB_GENERATOR_NEWPERIOD     2
#define TIEPIE_HW_TOEB_OSCILLOSCOPE_RUNNING    3
#define TIEPIE_HW_TOEB_OSCILLOSCOPE_TRIGGERED  4
#define TIEPIE_HW_TOEB_MANUAL                  5

/**
 *     \}
 */

#define TIEPIE_HW_TOE_UNKNOWN                 0
#define TIEPIE_HW_TOE_GENERATOR_START         (1 << TIEPIE_HW_TOEB_GENERATOR_START)
#define TIEPIE_HW_TOE_GENERATOR_STOP          (1 << TIEPIE_HW_TOEB_GENERATOR_STOP)
#define TIEPIE_HW_TOE_GENERATOR_NEWPERIOD     (1 << TIEPIE_HW_TOEB_GENERATOR_NEWPERIOD)
#define TIEPIE_HW_TOE_OSCILLOSCOPE_RUNNING    (1 << TIEPIE_HW_TOEB_OSCILLOSCOPE_RUNNING)
#define TIEPIE_HW_TOE_OSCILLOSCOPE_TRIGGERED  (1 << TIEPIE_HW_TOEB_OSCILLOSCOPE_TRIGGERED)
#define TIEPIE_HW_TOE_MANUAL                  (1 << TIEPIE_HW_TOEB_MANUAL)

/**
 *     \defgroup TIEPIE_HW_TOEM_ Masks
 *     \{
 */

#define TIEPIE_HW_TOEM_NONE             0 //!< No trigger output events
#define TIEPIE_HW_TOEM_GENERATOR        (TIEPIE_HW_TOE_GENERATOR_START | TIEPIE_HW_TOE_GENERATOR_STOP | TIEPIE_HW_TOE_GENERATOR_NEWPERIOD) //!< All generator trigger output events
#define TIEPIE_HW_TOEM_OSCILLOSCOPE     (TIEPIE_HW_TOE_OSCILLOSCOPE_RUNNING | TIEPIE_HW_TOE_OSCILLOSCOPE_TRIGGERED) //!< All oscilloscope trigger output events
#define TIEPIE_HW_TOEM_ALL              ((1ULL << TIEPIE_HW_TOEN_COUNT) - 1) //!< All trigger output events

/**
 *     \}
 *   \}
 * \}
 */

/**
 * \defgroup types Types
 * \{
 */

/**
 * \brief Status code
 *
 *   These codes show the status of the last called LibTiePie function.
 *
 *   0  means ok\n
 *   <0 means error\n
 *   >0 means ok, but with a side effect\n
 */
typedef enum tiepie_hw_status
{
  TIEPIE_HW_STATUS_VALUE_MODIFIED = 2, //!< \brief One of the parameters of the last called function was within the valid range but not available. The closest valid value is set.
  TIEPIE_HW_STATUS_VALUE_CLIPPED = 1, //!< \brief One of the parameters of the last called function was outside the valid range and clipped to the closest limit.
  TIEPIE_HW_STATUS_SUCCESS = 0, //!< \brief The function executed successfully.
  TIEPIE_HW_STATUS_UNSUCCESSFUL = -1, //!< \brief An error occurred during execution of the last called function.
  TIEPIE_HW_STATUS_NOT_SUPPORTED = -2, //!< \brief The requested functionality is not supported by the hardware.
  TIEPIE_HW_STATUS_INVALID_HANDLE = -3, //!< \brief The handle to the device is invalid.
  TIEPIE_HW_STATUS_INVALID_VALUE = -4, //!< \brief The requested value is invalid.
  TIEPIE_HW_STATUS_INVALID_CHANNEL = -5, //!< \brief The requested channel number is invalid.
  TIEPIE_HW_STATUS_INVALID_TRIGGER_SOURCE = -6, //!< \brief The requested trigger source is invalid.
  TIEPIE_HW_STATUS_INVALID_DEVICE_TYPE = -7, //!< \brief The device type is invalid.
  TIEPIE_HW_STATUS_INVALID_DEVICE_INDEX = -8, //!< \brief The device index is invalid, must be < LstGetCount().
  TIEPIE_HW_STATUS_INVALID_PRODUCT_ID = -9, //!< \brief There is no device with the requested product ID.
  TIEPIE_HW_STATUS_INVALID_DEVICE_SERIALNUMBER = -10, //!< \brief There is no device with the requested serial number.
  TIEPIE_HW_STATUS_OBJECT_GONE = -11, //!< \brief The object indicated by the handle is no longer available.
  TIEPIE_HW_STATUS_INTERNAL_ADDRESS = -12, //!< \brief The requested I<sup>2</sup>C address is an internally used address in the device.
  TIEPIE_HW_STATUS_NOT_CONTROLLABLE = -13, //!< \brief The generator is currently not controllable, see #tiepie_hw_generator_is_controllable.
  TIEPIE_HW_STATUS_BIT_ERROR = -14, //!< \brief The requested I<sup>2</sup>C operation generated a bit error.
  TIEPIE_HW_STATUS_NO_ACKNOWLEDGE = -15, //!< \brief The requested I<sup>2</sup>C operation generated "No acknowledge".
  TIEPIE_HW_STATUS_INVALID_CONTAINED_DEVICE_SERIALNUMBER = -16, //!< \brief A device with the requested serial number is not available in the combined instrument, see #tiepie_hw_devicelistitem_get_contained_serial_numbers.
  TIEPIE_HW_STATUS_INVALID_INPUT = -17, //!< \brief The requested trigger input is invalid.
  TIEPIE_HW_STATUS_INVALID_OUTPUT = -18, //!< \brief The requested trigger output is invalid.
  TIEPIE_HW_STATUS_NOT_AVAILABLE = -20, //!< \brief With the current settings, the requested functionality is not available.
  TIEPIE_HW_STATUS_INVALID_FIRMWARE = -21, //!< \brief The currently used firmware is not supported.
  TIEPIE_HW_STATUS_INVALID_INDEX = -22, //!< \brief The requested index is invalid.
  TIEPIE_HW_STATUS_INVALID_EEPROM = -23, //!< \brief The instrument's EEPROM content is damaged, please contact TiePie engineering support.
  TIEPIE_HW_STATUS_INITIALIZATION_FAILED = -24, //!< \brief The instrument's initialization failed, please contact TiePie engineering support.
  TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED = -25, //!< \brief The library is not initialized, see tiepie_hw_init().
  TIEPIE_HW_STATUS_NO_TRIGGER_ENABLED = -26, //!< \brief The current setup requires a trigger input to be enabled.
  TIEPIE_HW_STATUS_SYNCHRONIZATION_FAILED = -29, //!< \brief Synchronization of the instruments has failed.
  TIEPIE_HW_STATUS_INVALID_HS56_COMBINED_DEVICE = -30, //!< \brief At least one Handyscope HS6 (DIFF) / WiFiScope WS6 (DIFF) must be located at the beginning or end of the CMI daisy chain.
  TIEPIE_HW_STATUS_MEASUREMENT_RUNNING = -31, //!< \brief A measurement is already running.
  TIEPIE_HW_STATUS_WIRELESSTRIGGERMODULENOTCONNECTED = -32,
  TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10001 = -10001, //!< \brief Initialization error 10001
  TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10002 = -10002, //!< \brief Initialization error 10002
  TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10003 = -10003, //!< \brief Initialization error 10003
  TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10004 = -10004, //!< \brief Initialization error 10004
  TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10005 = -10005, //!< \brief Initialization error 10005
  TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10006 = -10006, //!< \brief Initialization error 10006
  TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10007 = -10007, //!< \brief Initialization error 10007
} tiepie_hw_status;

typedef uint32_t tiepie_hw_handle; //!< Generic handle.
typedef uint8_t tiepie_hw_bool; //!< Boolean value one byte wide. \see TIEPIE_HW_BOOL_

/**
 * \brief ProductID IDs for products
 */
typedef enum tiepie_hw_productid
{
  TIEPIE_HW_PRODUCTID_NONE = 0, //!< \brief Unknown/invalid TIEPIE_HW_ID
  TIEPIE_HW_PRODUCTID_COMBI = 2, //!< \brief Combined instrument
  TIEPIE_HW_PRODUCTID_HS3 = 13, //!< \brief Handyscope TIEPIE_HW_HS3
  TIEPIE_HW_PRODUCTID_HS4 = 15, //!< \brief Handyscope TIEPIE_HW_HS4
  TIEPIE_HW_PRODUCTID_HP3 = 18, //!< \brief Handyprobe TIEPIE_HW_HP3
  TIEPIE_HW_PRODUCTID_TP450 = 19, //!< \brief TIEPIE_HW_TP450
  TIEPIE_HW_PRODUCTID_HS4D = 20, //!< \brief Handyscope TIEPIE_HW_HS4-TIEPIE_HW_DIFF
  TIEPIE_HW_PRODUCTID_HS5 = 22, //!< \brief Handyscope TIEPIE_HW_HS5
  TIEPIE_HW_PRODUCTID_HS6 = 24, //!< \brief Handyscope TIEPIE_HW_HS6
  TIEPIE_HW_PRODUCTID_HS6D = 25, //!< \brief Handyscope TIEPIE_HW_HS6 TIEPIE_HW_DIFF
  TIEPIE_HW_PRODUCTID_ATS610004D = 31, //!< \brief TIEPIE_HW_ATS610004D
  TIEPIE_HW_PRODUCTID_ATS605004D = 32, //!< \brief TIEPIE_HW_ATS605004D
  TIEPIE_HW_PRODUCTID_WS6 = 34, //!< \brief WiFiScope TIEPIE_HW_WS6
  TIEPIE_HW_PRODUCTID_WS5 = 35, //!< \brief WiFiScope TIEPIE_HW_WS5
  TIEPIE_HW_PRODUCTID_WS6D = 36, //!< \brief WiFiScope TIEPIE_HW_WS6D
  TIEPIE_HW_PRODUCTID_ATS610004DW = 37, //!< \brief TIEPIE_HW_ATS610004DW
  TIEPIE_HW_PRODUCTID_ATS605004DW = 38, //!< \brief TIEPIE_HW_ATS605004DW
  TIEPIE_HW_PRODUCTID_WS4D = 39, //!< \brief WiFiScope TIEPIE_HW_WS4D
  TIEPIE_HW_PRODUCTID_ATS5004DW = 40, //!< \brief TIEPIE_HW_ATS5004DW
} tiepie_hw_productid;

/**
 * \brief Event IDs for events that can be used by LibTiePie to \ref obj_callbacks "notify" the calling application of changes with the instrument.
 *
 * See also \ref obj_callbacks "object callbacks".
 */
typedef enum tiepie_hw_event
{
  TIEPIE_HW_EVENT_INVALID = 0,                             //!< \brief This event ID value should not occur.
  TIEPIE_HW_EVENT_OBJECT_REMOVED = 1,                       //!< \brief Event ID for the event indicating that an object was removed.
  TIEPIE_HW_EVENT_OSCILLOSCOPE_DATA_READY = 2,               //!< \brief Event ID for the event indicating that the \ref tiepie_hw_oscilloscope_is_data_ready "oscilloscope measurement is ready".
  TIEPIE_HW_EVENT_OSCILLOSCOPE_DATA_OVERFLOW = 3,            //!< \brief Event ID for the event indicating that the \ref tiepie_hw_oscilloscope_is_data_overflow "data overflow" occurred during a streaming measurement.
  TIEPIE_HW_EVENT_OSCILLOSCOPE_SURE_CONNECT_COMPLETED = 4,    //!< \brief Event ID for the event indicating that the \ref scp_ct "connection test is ready.
  TIEPIE_HW_EVENT_OSCILLOSCOPE_TRIGGERED = 5,               //!< \brief Event ID for the event indicating that the oscilloscope has triggered.
  TIEPIE_HW_EVENT_GENERATOR_BURST_COMPLETED = 6,             //!< \brief Event ID for the event indicating that the generator burst is completed.
  TIEPIE_HW_EVENT_GENERATOR_CONTROLLABLE_CHANGED = 7,        //!< \brief Event ID for the event indicating that the generator controllable state has changed.
  TIEPIE_HW_EVENT_SERVER_STATUS_CHANGED = 8,                 //!< \brief XXX
  TIEPIE_HW_EVENT_OSCILLOSCOPE_SAFEGROUND_ERROR = 9,         //!< \brief Event ID for the event indicating that the oscilloscope channel \ref scp_ch_safeground "SafeGround" was disabled because of a too large ground current. The value parameter of the event contains the channel number (\c 0 to \c ChannelCount-1).
  TIEPIE_HW_EVENT_DEVICE_BATTERY_STATUS_CHANGED = 11,    //!< \brief XXX
  TIEPIE_HW_EVENT_OSCILLOSCOPE_WIRELESS_SYNCHRONIZATION_ERROR = 12, //!< \brief XXX
} tiepie_hw_event;

/**
 * \brief Demo signal type IDs, for demo oscilloscope channels. See \ref scp_ch_demo.
 */
typedef enum tiepie_hw_demosignal
{
  TIEPIE_HW_DEMOSIGNAL_NONE = 0,                  //!< \brief Disable signal
  TIEPIE_HW_DEMOSIGNAL_SINE = 1,                  //!< \brief Generate a sine wave signal.
  TIEPIE_HW_DEMOSIGNAL_TRIANGLE = 2,              //!< \brief Generate a triangular signal.
  TIEPIE_HW_DEMOSIGNAL_SQUARE = 3,                //!< \brief Generate a square wave signal.
  TIEPIE_HW_DEMOSIGNAL_DC = 4,                    //!< \brief Generate a DC level.
  TIEPIE_HW_DEMOSIGNAL_RUNT = 5,                  //!< \brief Generate a pulse signal with a runt pulse
  TIEPIE_HW_DEMOSIGNAL_I2C_SCL = 100,             //!< \brief Generate an I2C SCL signal
  TIEPIE_HW_DEMOSIGNAL_I2C_SDA = 101,             //!< \brief Generate an I2C SDA signal
  TIEPIE_HW_DEMOSIGNAL_UART_9600_8N1 = 200,       //!< \brief Generate a UART signal, 9600 baud, 8 bits, no parity, 1 stop bit
  TIEPIE_HW_DEMOSIGNAL_UART_9600_7E2 = 201,       //!< \brief Generate a UART signal, 9600 baud, 7 bits, even parity, 2 stop bits
  TIEPIE_HW_DEMOSIGNAL_RS232_9600_8N1 = 300,      //!< \brief Generate a RS232 signal, 9600 baud, 8 bits, no parity, 1 stop bit
  TIEPIE_HW_DEMOSIGNAL_RS232_9600_8O15 = 301,     //!< \brief Generate a RS232 signal, 9600 baud, 8 bits, odd parity, 1.5 stop bits
  TIEPIE_HW_DEMOSIGNAL_RS485_9600_8N1 = 400,      //!< \brief Generate a RS458 signal, 9600 baud, 8 bits, no parity, 1 stop bit
  TIEPIE_HW_DEMOSIGNAL_RS485_9600_8N1MD = 401,    //!< \brief Generate a RS458 signal, 9600 baud, 8 bits, no parity, 1 stop bit MultiDrop
  TIEPIE_HW_DEMOSIGNAL_CAN_250000 = 500,          //!< \brief Generate a differential CAN signal, 250 kbps
  TIEPIE_HW_DEMOSIGNAL_CAN_250000_HI = 501,       //!< \brief Generate a CAN-High signal, 250 kbps
  TIEPIE_HW_DEMOSIGNAL_CAN_250000_LO = 502,       //!< \brief Generate a CAN-Low signal, 250 kbps
  TIEPIE_HW_DEMOSIGNAL_CANFD_250000 = 600,        //!< \brief Generate a differential CANFD signal, 250 kbps
  TIEPIE_HW_DEMOSIGNAL_CANFD_250000_HI = 601,     //!< \brief Generate a CANFD-High signal, 250 kbps
  TIEPIE_HW_DEMOSIGNAL_CANFD_250000_LO = 602,     //!< \brief Generate a CANFD-Low signal, 250 kbps
  TIEPIE_HW_DEMOSIGNAL_DMX512 = 700,              //!< \brief Generate a DMX 512 signal
  TIEPIE_HW_DEMOSIGNAL_LIN_19200 = 800,           //!< \brief Generate a LIN bus signal, 19200 bps
} tiepie_hw_demosignal;

typedef uint8_t tiepie_hw_tristate;     //!< TriState value one byte wide. \see TIEPIE_HW_TRISTATE_
typedef void**  tiepie_hw_pointerarray; //!< Pointer array \see hlp_ptrar

typedef struct tiepie_hw_date
{
  uint16_t year;
  uint8_t month;
  uint8_t day;
} tiepie_hw_date;

typedef struct tiepie_hw_demo_info
{
  tiepie_hw_productid product_id;
  const char* name;
  const char* name_short;
} tiepie_hw_demo_info;

#ifdef INCLUDED_BY_MATLAB
  typedef void* tiepie_hw_devicelist_callback;
  typedef void* tiepie_hw_handle_callback;
  typedef void* tiepie_hw_event_callback;
#else
  typedef void(*tiepie_hw_devicelist_callback)(void* data, uint32_t device_types, uint32_t serial_number);
  typedef void(*tiepie_hw_handle_callback)(void* data, tiepie_hw_handle handle);
  typedef void(*tiepie_hw_event_callback)(void* data, tiepie_hw_event event, uint32_t value);
#endif

/**
 * \}
 * \defgroup functions Functions
 * \{
 * \defgroup lib Library initialization/deinitialization/version
 * \{
 *   \brief Functions to initialize and exit the library and retrieve information from the library itself.
 *
 *   After loading the library, it must be \ref tiepie_hw_init "initialized" first, before functions in the library can be used.
 *   Before closing the library, when the application using the library no longer requires it, tiepie_hw_fini() must be called, to clear
 *   and free resources used by the library.
 *
 *   The library has a version number and a configuration number that can be queried.
 *   These can be used when requesting support from TiePie engineering.
 *
 *   On each library function call a status flag is set, indicating how the function was executed.
 *   When a function call behaves different than expected, check the status for possible causes.
 */

/**
 * \brief Create and initialize internal resources used by the library.
 *
 * This function must be called after loading the library, before non library related functions in the library can be used.
 * Calling non library related functions before the library is initialized will set the status flag to #TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED.
 *
 * \remark
 * tiepie_hw_init() can be called multiple times, an internal reference counter is used to keep track of the number of times it is called.
 * tiepie_hw_fini() must then be called equally often.
 * \par Status values
 *   This function does not affect the status flag.
 * \see tiepie_hw_is_initialized
 * \see tiepie_hw_fini
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_init(void);

/**
 * \brief Check whether the library's internal resources are initialized.
 *
 * \return #TIEPIE_HW_BOOL_TRUE if initialized, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   This function does not affect the status flag.
 * \see tiepie_hw_init
 * \see tiepie_hw_fini
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_is_initialized(void);

/**
 * \brief Clear and free internal resources used by the library.
 *
 * This function must be called before closing the library, when the application using the library no longer requires it.
 *
 * \par Status values
 *   This function does not affect the status flag.
 * \see tiepie_hw_init
 * \see tiepie_hw_is_initialized
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_fini(void);

/**
 * \brief Structure with library version info.
 */
typedef struct tiepie_hw_version
{
  uint16_t major; //!< Major version number.
  uint16_t minor; //!< Minor version number.
  uint16_t patch; //!< Patch level.
  uint16_t build; //!< Build number.
  const char* extra; //!< Additional version text.
} tiepie_hw_version;

/**
 * \brief Get library version info.
 *
 * \return Pointer to struct with version info.
 * \par Status values
 *   This function does not affect the status flag.
 * \par Example
 * \code{.c}
 * const tiepie_hw_version* version = tiepie_hw_get_version();
 * printf("libtiepie-hw v%u.%u.%u%s\n", version->major, version->minor, version->patch, version->extra);
 * \endcode
 * \since 1.0
 */
TIEPIE_HW_API const tiepie_hw_version* tiepie_hw_get_version(void);

/**
 * \brief Get the library configuration number.
 *
 * \param[out] buffer A pointer to the buffer to write to.
 * \param[in] length The length of the buffer, in bytes.
 * \return The library configuration number length in bytes.
 * \par Status values
 *   This function does not affect the status flag.
 * \par Example
 * \code{.c}
 * uint32_t length = tiepie_hw_get_config(NULL, 0);
 * uint8_t* buffer = malloc(sizeof(uint8_t) * length);
 * length = tiepie_hw_get_config(buffer, length);
 *
 * printf("libtiepie-hw config: 0x");
 * for(uint32_t i = 0; i < length; i++)
 *   printf("%02x", buffer[i]);
 * printf("\n");
 *
 * free(buffer);
 * \endcode
 *
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_get_config(uint8_t* buffer, uint32_t length);

/**
 * \brief Get the last status value.
 *
 * After each call to a library function, a status flag is set, indicating how the function was executed.
 *
 * \return \ref tiepie_hw_status "Status code".
 * \par Status values
 *   This function does not affect the status flag.
 * \see tiepie_hw_get_last_status_str
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_status tiepie_hw_get_last_status(void);

/**
 * \brief Get the last status value as text.
 *
 * After each call to a library function, a status flag is set, indicating how the function was executed.
 *
 * \return \ref tiepie_hw_status "Status code" as text.
 * \par Status values
 *   This function does not affect the status flag.
 * \see tiepie_hw_get_last_status
 *
 * \par Example
 * \code{.c}
 * printf("tiepie_hw_get_last_status_str = %s\n", tiepie_hw_get_last_status_str());
 * \endcode
 *
 * \since 1.1
 */
TIEPIE_HW_API const char* tiepie_hw_get_last_status_str(void);

/**
 *   \}
 *   \defgroup lst Device list
 *   \{
 *     \brief Functions to control the device list: open and close devices and retrieve device information.
 *
 * libtiepie-hw maintains a device list, containing all available supported devices.
 * Possible devices are oscilloscopes and, generators.
 * Instruments can contain multiple devices, e.g. the Handyscope HS5 contains an oscilloscope and a generator.
 *
 * After starting the application, the device list must be filled with all available devices, using tiepie_hw_devicelist_update().
 * When the application is running, the device list is automatically maintained.
 * When new compatible devices are connected to the computer, they will be added to the device list automatically.
 * When devices are disconnected from the computer, they are automatically removed from the list.
 *
 * <h3>Getting device information</h3>
 *
 * Before opening a device, information from the \ref tiepie_hw_devicelist_instruments "listed devices" can be retrieved.
 * This information can help opening the required device, when multiple devices are available in the list.
 *
 * \anchor Open_dev
 * <h3>Opening a device</h3>
 *
 * Before any device action can be performed a device needs to be opened.
 * When a device in the device list is opened, a unique handle to the device is assigned.
 * This handle is required to access the device.
 *
 * libtiepie-hw has three functions for opening devices.
 * One function for each \ref TIEPIE_HW_DEVICETYPE "device type" (\ref tiepie_hw_devicelistitem_open_oscilloscope, \ref tiepie_hw_devicelistitem_open_generator),
 * and one (\ref tiepie_hw_devicelistitem_open_device) to open a device by specifying its \ref TIEPIE_HW_DEVICETYPE "device type".
 * A device can only be opened once.
 *
 * <h4>Device open methods</h4>
 *
 * libtiepie-hw supports three different methods for opening devices.
 *
 * - Open by device list index, e.g.:
 * \code{.c}
 * tiepie_hw_handle devicelist_item_handle = tiepie_hw_devicelist_get_item_by_index(4);
 * tiepie_hw_handle scp = tiepie_hw_devicelistitem_open_device(devicelist_item_handle, TIEPIE_HW_DEVICETYPE_OSCILLOSCOPE); // Try to open oscilloscope at device list index 4.
 * tiepie_hw_object_close(devicelist_item_handle);
 * \endcode
 * - Open by serial number, e.g.:
 * \code{.c}
 * tiepie_hw_handle devicelist_item_handle = tiepie_hw_devicelist_get_item_by_serial_number(22110);
 * tiepie_hw_handle gen = tiepie_hw_devicelistitem_open_device(devicelist_item_handle, TIEPIE_HW_DEVICETYPE_GENERATOR); // Try to open generator with serial number 22110.
 * tiepie_hw_object_close(devicelist_item_handle);
 * \endcode
 * - Open by product id, e.g.:
 * \code{.c}
 * tiepie_hw_handle devicelist_item_handle = tiepie_hw_devicelist_get_item_by_product_id(TIEPIE_HW_PRODUCTID_HS5);
 * tiepie_hw_handle scp = tiepie_hw_devicelistitem_open_device(devicelist_item_handle, TIEPIE_HW_DEVICETYPE_OSCILLOSCOPE); // Try to open a Handyscope HS5 oscilloscope.
 * tiepie_hw_object_close(devicelist_item_handle);
 * \endcode
 *
 * When a device cannot be opened the function to open returns #TIEPIE_HW_HANDLE_INVALID.
 *
 * <h3>Closing a disconnected device</h3>
 *
 * When an open device is disconnected from the computer, the handle to that device will be no longer valid and the device needs to be
 * closed using tiepie_hw_object_close().
 * Calling functions pointing to a disconnected device will set the status flag to \ref TIEPIE_HW_STATUS_OBJECT_GONE.
 *
 * \anchor Combining
 * <h3>Combining devices</h3>
 * Several devices support combining, where multiple units can be combined to form a larger device.
 * Two different methods are possible.
 *
 * <h4>Automatic combining</h4>
 *
 * This applies to all instruments with CMI interface: the Handyscope HS5, Handyscope HS6, Handyscope HS6 DIFF, WiFiScope WS5, WiFiScope WS6, WiFiScope WS6 DIFF
 * and the Automotive Test Scopes ATS610004D-XMSG, ATS605004D-XMS, ATS610004DW-XMSG, and ATS605004DW-XMS.
 * For the WiFiScopes this only applies when connected via USB, when connected via LAN or Wifi, combining is no possible.
 *
 * Connect the instruments to each other using a special coupling cable and update the device list using tiepie_hw_devicelist_update().
 * A new combined device with a new (virtual) serial number will be added to the device list, the original devices remain present in the device list but can not be accessed anymore.
 *
 * To undo an automatic combination, remove the coupling cable(s) and update the device list using tiepie_hw_devicelist_update().
 *
 *
 * <h4>Manual combining</h4>
 *
 * This applies to the Handyscope HS3, Handyscope HS4, Handyscope HS4 DIFF and WiFiScope WS4 DIFF and and the Automotive Test Scopes ATS5004D and ATS5004DW.
 * For the WiFiScopes this only applies when connected via USB, when connected via LAN or Wifi, combining is no possible.
 *
 * Connect the instruments to each other using a special coupling cable and open the individual oscilloscopes to retrieve their handles.
 * Then call a \ref tiepie_hw_devicelist_create_combined_device "coupling function", supplying the handles of the devices to combine.
 * A new combined device with a new (virtual) serial number will be added to the device list, the original devices remain present in the device list but their handles become invalid.
 * These should be closed using tiepie_hw_object_close().
 * An <a class="External" href="http://www.tiepie.com/software/LibTiePie/C/Examples/Oscilloscope_combineHS4.c"><b>example</b></a> in C is available on the TiePie engineering website.
 *
 * To undo a manual combination, remove the coupling cable, close the combined device using tiepie_hw_object_close() with the handle of the combined device.
 * Finally remove the combined device from the device list using tiepie_hw_devicelist_remove_device() with the serial number of the combined device.
 *
 * <h4>Opening a combined device</h4>
 *
 * Opening a combined device can be done in the ways described before, with one restriction.
 * When opening a combined device by product id, the id #TIEPIE_HW_PRODUCTID_COMBI must be used.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Update the device list.
 *
 * This function searches for new instruments and adds these to the device list.
 *
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_devicelist_set_usb_hotplug_detect_enabled
 * \par Example
 * \code{.c}
 * tiepie_hw_devicelist_update(); // Search for new instruments
 * \endcode
 *
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_devicelist_update(void);

/**
 * \brief Get the current enabled state of the USB hot plug detection.
 *
 * \return #TIEPIE_HW_BOOL_TRUE if enabled, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_devicelist_set_usb_hotplug_detect_enabled
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_devicelist_get_usb_hotplug_detect_enabled(void);

/**
 * \brief Set the USB hot plug detection enabled state.
 *
 * When hot plug detection is enabled, a USB device that is connected to the computer and detected by the operating system,
 * will be automatically added to the device list.
 *
 * When hot plug detection is disabled, a USB device that is connected to the computer and detected by the operating system,
 * will not be automatically added to the device list. This allows another instance of libtiepie to open the instrument.
 * To add the instrument to the device list anyway, use tiepie_hw_devicelist_update().
 *
 * \param[in] value #TIEPIE_HW_BOOL_TRUE to enable, #TIEPIE_HW_BOOL_FALSE to disable.
 * \return #TIEPIE_HW_BOOL_TRUE if enabled, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_devicelist_get_usb_hotplug_detect_enabled
 * \see tiepie_hw_devicelist_update
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_devicelist_set_usb_hotplug_detect_enabled(tiepie_hw_bool value);

/**
 * \brief Get the number of devices in the device list.
 *
 * \return The number of devices in the device list.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_devicelist_get_count(void);

/**
 * \brief Get handle to device list item by product id.
 *
 * \return handle.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_PRODUCT_ID</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_object_close
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_handle tiepie_hw_devicelist_get_item_by_product_id(tiepie_hw_productid product_id);

/**
 * \brief Get handle to device list item by product id.
 *
 * \return handle.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_DEVICE_INDEX</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_object_close
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_handle tiepie_hw_devicelist_get_item_by_index(uint32_t index);

/**
 * \brief Get handle to device list item by product id.
 *
 * \return handle.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_DEVICE_SERIALNUMBER</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_object_close
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_handle tiepie_hw_devicelist_get_item_by_serial_number(uint32_t serial_number);

/**
 * \brief Open a device and get a handle to the device.
 *
 * \param[in] handle A handle identifying the object.
 * \param[in] device_type A \ref TIEPIE_HW_DEVICETYPE "device type".
 * \return A device handle, or #TIEPIE_HW_HANDLE_INVALID on error.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INITIALIZATION_FAILED</td>      <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_EEPROM</td>             <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_FIRMWARE</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>              <td>The value of Id_kind or Device_type is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_DEVICE_TYPE</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>               <td>The device is already open or an other error occurred.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                    <td></td></tr>
 *   </table>
 * \par Examples
 * \code{.c}
 * tiepie_hw_handle devicelist_item_handle = tiepie_hw_devicelist_get_item_by_index(4);
 * tiepie_hw_handle scp = tiepie_hw_devicelistitem_open_device(devicelist_item_handle, TIEPIE_HW_DEVICETYPE_OSCILLOSCOPE); // Try to open oscilloscope at device list index 4.
 * tiepie_hw_object_close(devicelist_item_handle);
 * \endcode
 * \code{.c}
 * tiepie_hw_handle devicelist_item_handle = tiepie_hw_devicelist_get_item_by_serial_number(22110);
 * tiepie_hw_handle gen = tiepie_hw_devicelistitem_open_device(devicelist_item_handle, TIEPIE_HW_DEVICETYPE_GENERATOR); // Try to open generator with serial number 22110.
 * tiepie_hw_object_close(devicelist_item_handle);
 * \endcode
 * \see tiepie_hw_devicelistitem_open_oscilloscope
 * \see tiepie_hw_devicelistitem_open_generator
 * \see tiepie_hw_object_close
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_handle tiepie_hw_devicelistitem_open_device(tiepie_hw_handle handle, uint32_t device_type);

/**
 * \brief Open an oscilloscope and get a handle to the oscilloscope.
 *
 * \param[in] handle A handle identifying the object.
 * \return A device handle, or #TIEPIE_HW_HANDLE_INVALID on error.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INITIALIZATION_FAILED</td>      <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_EEPROM</td>             <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_FIRMWARE</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>              <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>               <td>The device is already open or an other error occured.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                    <td></td></tr>
 *   </table>
 * \par Examples
 * \code{.c}
 * tiepie_hw_handle devicelist_item_handle = tiepie_hw_devicelist_get_item_by_index(4);
 * tiepie_hw_handle scp = tiepie_hw_devicelistitem_open_oscilloscope(devicelist_item_handle); // Try to open oscilloscope at device list index 4.
 * tiepie_hw_object_close(devicelist_item_handle);
 * \endcode
 * \code{.c}
 * tiepie_hw_handle devicelist_item_handle = tiepie_hw_devicelist_get_item_by_serial_number(27917);
 * tiepie_hw_handle scp = tiepie_hw_devicelistitem_open_oscilloscope(devicelist_item_handle); // Try to open oscilloscope with serial number 27917.
 * tiepie_hw_object_close(devicelist_item_handle);
 * \endcode
 * \code{.c}
 * tiepie_hw_handle devicelist_item_handle = tiepie_hw_devicelist_get_item_by_product_id(TIEPIE_HW_PRODUCTID_HS5);
 * tiepie_hw_handle scp = tiepie_hw_devicelistitem_open_oscilloscope(devicelist_item_handle); // Try to open a Handyscope HS5 oscilloscope.
 * tiepie_hw_object_close(devicelist_item_handle);
 * \endcode
 * \see tiepie_hw_devicelistitem_open_device
 * \see tiepie_hw_devicelistitem_open_generator
 * \see tiepie_hw_object_close
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_handle tiepie_hw_devicelistitem_open_oscilloscope(tiepie_hw_handle handle);

/**
 * \brief Open a generator and get a handle to the generator.
 *
 * \param[in] handle A handle identifying the object.
 * \return A device handle, or #TIEPIE_HW_HANDLE_INVALID on error.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INITIALIZATION_FAILED</td>      <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_EEPROM</td>             <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_FIRMWARE</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>              <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>               <td>The device is already open or an other error occured.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                    <td></td></tr>
 *   </table>
 * \par Examples
 * \code{.c}
 * tiepie_hw_handle devicelist_item_handle = tiepie_hw_devicelist_get_item_by_index(2);
 * tiepie_hw_handle gen = tiepie_hw_devicelistitem_open_generator(devicelist_item_handle); // Try to open generator at device list index 2.
 * tiepie_hw_object_close(devicelist_item_handle);
 * \endcode
 * \code{.c}
 * tiepie_hw_handle devicelist_item_handle = tiepie_hw_devicelist_get_item_by_serial_number(22110);
 * tiepie_hw_handle gen = tiepie_hw_devicelistitem_open_generator(devicelist_item_handle); // Try to open generator with serial number 22110.
 * tiepie_hw_object_close(devicelist_item_handle);
 * \endcode
 * \code{.c}
 * tiepie_hw_handle devicelist_item_handle = tiepie_hw_devicelist_get_item_by_product_id(TIEPIE_HW_PRODUCTID_HS5);
 * tiepie_hw_handle gen = tiepie_hw_devicelistitem_open_generator(devicelist_item_handle); // Try to open a Handyscope HS5 generator.
 * tiepie_hw_object_close(devicelist_item_handle);
 * \endcode
 * \see tiepie_hw_devicelistitem_open_device
 * \see tiepie_hw_devicelistitem_open_oscilloscope
 * \see tiepie_hw_object_close
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_handle tiepie_hw_devicelistitem_open_generator(tiepie_hw_handle handle);

/**
 * \brief Get list of available demo devices.
 * \return A list of available demo devices.
 * \since 1.0
 * \par Example
 * \code{.c}
 *  const tiepie_hw_demo_info* item = tiepie_hw_devicelist_get_demo_device_info();
 *  if(item)
 *    for(; item->product_id != TIEPIE_HW_PRODUCTID_NONE; item++)
 *      printf("name: %s, name_short: %s, product_id: %d\n", item->name, item->name_short, item->product_id);
 * \endcode
 */
TIEPIE_HW_API const tiepie_hw_demo_info* tiepie_hw_devicelist_get_demo_device_info(void);

/**
 * \brief Create a demo instrument.
 * \param[in] product_id The product ID of the demo instrument to create
 * \return Serial number of the demo device, or zero on error.
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_devicelist_create_demo_device(tiepie_hw_productid product_id);

/**
 * \brief Create a combined instrument.
 *
 * This function creates \ref Combining "combined instrument" from the indicated devices.
 *
 * \param[in] handles Pointer to an array of handles of the devices to combine.
 * \param[in] count The number of device handles.
 * \return Serial number of the combined device, or zero on error.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>Combining is not supported.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>One or more device handles are invalid or incompatible.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>p_device_handles must be != \c NULL and the number of device handles must be >= 2.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td>One or more devices indicated by the device handles is no longer available.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_devicelist_create_and_open_combined_device
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_devicelist_create_combined_device(const tiepie_hw_handle* handles, uint32_t count);

/**
 * \brief Create and open a combined instrument.
 *
 * This function creates a \ref Combining "combined instrument" from the indicated devices and opens it.
 *
 * \param[in] handles Pointer to an array of handles of the devices to combine.
 * \param[in] count The number of device handles.
 * \return A device handle, or #TIEPIE_HW_HANDLE_INVALID on error.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>Combining is not supported.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>One or more device handles are invalid or incompatible.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>p_device_handles must be != \c NULL and the number of device handles must be >= 2.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td>One or more devices indicated by the device handles is no longer available.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_devicelist_create_combined_device
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_handle tiepie_hw_devicelist_create_and_open_combined_device(const tiepie_hw_handle* handles, uint32_t count);

/**
 * \brief Remove an instrument from the device list so it can be used by other applications.
 *
 * \param[in] serial_number Serial number of the device to remove.
 * \param[in] force Force the removal, even when the device is open.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>               <td>Device is still open?</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>              <td>Device can't be removed from the list. To remove a combined Handyscope HS5, unplug the coupling cable and call tiepie_hw_devicelist_update().</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_DEVICE_SERIALNUMBER</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                    <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_devicelist_remove_device(uint32_t serial_number, tiepie_hw_bool force);

/**
 * \brief Remove unused instruments from the device list so they can be used by other applications.
 *
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                    <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_devicelist_remove_unused_devices(void);

/**
 *     \defgroup tiepie_hw_devicelist_instruments Listed devices
 *     \{
 *       \brief Functions to retrieve information from the listed devices.
 *
 * Before opening a device, device specific information can be retrieved.
 * This information can help opening the required device, when multiple devices are available in the list.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether the listed device is a demo device.
 *
 * \param[in] handle A handle identifying the object.
 * \return #TIEPIE_HW_BOOL_TRUE if the device is a demo device or #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>              <td>The value of id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                    <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_devicelistitem_is_demo(tiepie_hw_handle handle);

/**
 * \brief Check whether the listed device can be opened.
 *
 * \param[in] handle A handle identifying the object.
 * \param[in] device_type A \ref TIEPIE_HW_DEVICETYPE "device type".
 * \return #TIEPIE_HW_BOOL_TRUE if the device can be opened or #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INITIALIZATION_FAILED</td>      <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_EEPROM</td>             <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_FIRMWARE</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_DEVICE_TYPE</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>              <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                    <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_devicelistitem_can_open(tiepie_hw_handle handle, uint32_t device_type);

/**
 * \brief See who is using the device.
 *
 * \param[in] handle A handle identifying the object.
 * \param[in] device_type A \ref TIEPIE_HW_DEVICETYPE "device type".
 * \param[out] buffer A pointer to a buffer for the status.
 * \param[in] length The length of the buffer, in bytes.
 * \return The length of the string in bytes, excluding terminating zero.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_DEVICE_TYPE</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>              <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>             <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                    <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_devicelistitem_opened_by(tiepie_hw_handle handle, uint32_t device_type, char* buffer, uint32_t length);

/**
 * \brief Get the product id of the listed device.
 *
 * \param[in] handle A handle identifying the object.
 * \return The #tiepie_hw_productid "product id" of the listed device.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>              <td>The indicated device does not support reading a product id.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>              <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                    <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_productid tiepie_hw_devicelistitem_get_product_id(tiepie_hw_handle handle);

/**
 * \brief Get the full name of the listed device.
 *
 * E.g. <tt>Handyscope HS5-530XMS</tt>
 *
 * \param[in] handle A handle identifying the object.
 * \param[out] buffer A pointer to a buffer for the name.
 * \param[in] length The length of the buffer, in bytes.
 * \return The length of the name in bytes, excluding terminating zero.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>              <td>The indicated device does not support reading a name.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>              <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                    <td></td></tr>
 *   </table>
 * \see tiepie_hw_devicelistitem_get_name_short
 * \see tiepie_hw_devicelistitem_get_name_shortest
 *
 * \par Example
 * \code{.c}
 * uint32_t length = tiepie_hw_devicelistitem_get_name(handle, NULL, 0) + 1; // Add one for the terminating zero
 * char* s_name = malloc(sizeof(char) * length);
 * length = tiepie_hw_devicelistitem_get_name(handle, s_name, length);
 *
 * printf("tiepie_hw_devicelistitem_get_name = %s\n", s_name);
 *
 * free(s_name);
 * \endcode
 *
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_devicelistitem_get_name(tiepie_hw_handle handle, char* buffer, uint32_t length);

/**
 * \brief Get the short name of the listed device.
 *
 * E.g. <tt>HS5-530XMS</tt>
 *
 * \param[in] handle A handle identifying the object.
 * \param[out] buffer A pointer to a buffer for the name.
 * \param[in] length The length of the buffer, in bytes.
 * \return The length of the name in bytes, excluding terminating zero.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>              <td>The indicated device does not support reading a name.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>              <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                    <td></td></tr>
 *   </table>
 * \see tiepie_hw_devicelistitem_get_name
 * \see tiepie_hw_devicelistitem_get_name_shortest
 *
 * \par Example
 * \code{.c}
 * uint32_t length = tiepie_hw_devicelistitem_get_name_short(handle, NULL, 0) + 1; // Add one for the terminating zero
 * char* s_name_short = malloc(sizeof(char) * Length);
 * Length = tiepie_hw_devicelistitem_get_name_short(handle, s_name_short, Length);
 *
 * printf("Lst_devget_name_short = %s\n", s_name_short);
 *
 * free(s_name_short);
 * \endcode
 *
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_devicelistitem_get_name_short(tiepie_hw_handle handle, char* buffer, uint32_t length);

/**
 * \brief Get the short name of the listed device wihout model postfix.
 *
 * E.g. <tt>HS5</tt>
 *
 * \param[in] handle A handle identifying the object.
 * \param[out] buffer A pointer to a buffer for the name.
 * \param[in] length The length of the buffer, in bytes.
 * \return The length of the name in bytes, excluding terminating zero.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>              <td>The indicated device does not support reading a name.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>              <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                    <td></td></tr>
 *   </table>
 * \see tiepie_hw_devicelistitem_get_name
 * \see tiepie_hw_devicelistitem_get_name_short
 *
 * \par Example
 * \code{.c}
 * uint32_t length = tiepie_hw_devicelistitem_get_name_shortest(handle, NULL, 0) + 1; // Add one for the terminating zero
 * char* s_name_shortest = malloc(sizeof(char) * Length);
 * Length = tiepie_hw_devicelistitem_get_name_shortest(handle, s_name_shortest, Length);
 *
 * printf("Lst_devget_name_shortest = %s\n", s_name_shortest);
 *
 * free(s_name_shortest);
 * \endcode
 *
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_devicelistitem_get_name_shortest(tiepie_hw_handle handle, char* buffer, uint32_t length);

/**
 * \brief Get the calibration date of the listed device.
 *
 * \param[in] handle A handle identifying the object.
 * \return The calibration \ref tiepie_hw_date "date" of the listed device, or zero if no calibration date is available.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>              <td>The indicated device does not have a calibration date.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>              <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                    <td></td></tr>
 *   </table>
 * \par Example
 * \code{.c}
 * tiepie_hw_date date = tiepie_hw_devicelistitem_get_calibration_date(handle);
 *
 * printf("tiepie_hw_devicelistitem_get_calibration_date = %u-%u-%u\n", date.year, date.month, date.day);
 * \endcode
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_date tiepie_hw_devicelistitem_get_calibration_date(tiepie_hw_handle handle);

/**
 * \brief Get the serial number of the listed device.
 *
 * \param[in] handle A handle identifying the object.
 * \return The serial number of the listed device.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INITIALIZATION_FAILED</td>      <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_EEPROM</td>             <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_FIRMWARE</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>              <td>The indicated device does not support reading a serial number.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>              <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                    <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_devicelistitem_get_serial_number(tiepie_hw_handle handle);

/**
 * \brief Get the IP address of the listed device.
 *
 * \param[in] handle A handle identifying the object.
 * \param[out] buffer A pointer to a buffer for the IP address.
 * \param[in] length The length of the buffer, in bytes.
 * \return The length of the IP address in bytes, excluding terminating zero.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>              <td>The indicated device is not a network device.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>              <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                    <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_devicelistitem_get_ip_address(tiepie_hw_handle handle, char* buffer, uint32_t length);

/**
 * \brief Get the IP port number of the listed device.
 *
 * \param[in] handle A handle identifying the object.
 * \return The IP port number of the listed device.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>              <td>The indicated device is not a network device.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>              <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                    <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint16_t tiepie_hw_devicelistitem_get_ip_port(tiepie_hw_handle handle);

/**
 * \brief Check whether the listed device is connected to a server.
 *
 * \param[in] handle A handle identifying the object.
 * \return #TIEPIE_HW_BOOL_TRUE if the device isconnected to a server, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_devicelistitem_has_server(tiepie_hw_handle handle);

/**
 * \brief Get the server handle of the server the listed device is connected to.
 *
 * \param[in] handle A handle identifying the object.
 * \return A server handle, or #TIEPIE_HW_STATUS_INVALID_HANDLE on error.
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_handle tiepie_hw_devicelistitem_get_server(tiepie_hw_handle handle);

/**
 * \brief Get the device types of the listed device.
 *
 * \param[in] handle A handle identifying the object.
 * \return OR-ed mask of \ref TIEPIE_HW_DEVICETYPE "device types".
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INITIALIZATION_FAILED</td>      <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_EEPROM</td>             <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_FIRMWARE</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>              <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                    <td></td></tr>
 *   </table>
 *
 * \par Example
 * \code{.c}
 * uint32_t device_types = tiepie_hw_devicelistitem_get_types(handle);
 *
 * // Test all device types:
 * if(device_types & TIEPIE_HW_DEVICETYPE_OSCILLOSCOPE)
 *   printf("DEVICETYPE_OSCILLOSCOPE\n");
 *
 * if(device_types & TIEPIE_HW_DEVICETYPE_GENERATOR)
 *   printf("DEVICETYPE_GENERATOR\n");
 * \endcode
 *
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_devicelistitem_get_types(tiepie_hw_handle handle);

/**
 *       \defgroup tiepie_hw_devicelist_combined Combined devices
 *       \{
 *         \brief Functions to retrieve information from the individual devices in combined devices.
 *
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the serial numbers of the individual devices contained in a combined device.
 *
 * \param[in] handle A handle identifying the object.
 * \param[out] buffer A pointer to a buffer for the serial numbers.
 * \param[in] length The length of the buffer, in bytes.
 * \return The number of devices in the combined device, or zero if the device isn't a combined device.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>              <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>              <td>The indicated device is not a combined device.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                    <td></td></tr>
 *   </table>
 *
 * \par Example
 * \code{c}
 * uint32_t length = tiepie_hw_devicelistitem_get_contained_serial_numbers(handle, NULL, 0);
 * uint32_t* serial_numbers = malloc(sizeof(uint32_t) * length);
 * Length = tiepie_hw_devicelistitem_get_contained_serial_numbers(handle, serial_numbers, length);
 *
 * for(i = 0 ; i < Length ; i++)
 * {
 *   printf("%u\n", Serial_numbers[ i ]);
 * }
 *
 * free(p_serial_numbers);
 * \endcode
 *
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_devicelistitem_get_contained_serial_numbers(tiepie_hw_handle handle, uint32_t* buffer, uint32_t length);

/**
 * \brief Get the product id of a device contained in a combined device.
 *
 * \param[in] handle A handle identifying the object.
 * \param[in] contained_device_serial_number The serial number identifying the \b contained device inside the combined device.
 * \return The #tiepie_hw_productid "product id" of the contained device.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>                        <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>                        <td>The indicated device is not a combined device or the contained device does not support reading a product id.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CONTAINED_DEVICE_SERIALNUMBER</td><td>There is no contained device with the requested serial number in the combined device.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>              <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                              <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_productid tiepie_hw_devicelistitemcombined_get_product_id(tiepie_hw_handle handle, uint32_t contained_device_serial_number);

/**
 * \brief Get the full name of a device contained in a combined device.
 *
 * E.g. <tt>Handyscope HS5-530XMS</tt>
 *
 * \param[in] handle A handle identifying the object.
 * \param[in] contained_device_serial_number The serial number identifying the \b contained device inside the combined device.
 * \param[out] buffer A pointer to a buffer for the name.
 * \param[in] length The length of the buffer, in bytes.
 * \return The length of the name in bytes, excluding terminating zero.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>                        <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>                        <td>The indicated device is not a combined device or the contained device does not support reading a name.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CONTAINED_DEVICE_SERIALNUMBER</td><td>There is no contained device with the requested serial number in the combined device.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>              <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                              <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_devicelistitemcombined_get_name(tiepie_hw_handle handle, uint32_t contained_device_serial_number, char* buffer, uint32_t length);

/**
 * \brief Get the short name of a device contained in a combined device.
 *
 * E.g. <tt>HS5-530XMS</tt>
 *
 * \param[in] handle A handle identifying the object.
 * \param[in] contained_device_serial_number The serial number identifying the \b contained device inside the combined device.
 * \param[out] buffer A pointer to a buffer for the name.
 * \param[in] length The length of the buffer, in bytes.
 * \return The length of the name in bytes, excluding terminating zero.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>                        <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>                        <td>The indicated device is not a combined device or the contained device does not support reading a name.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CONTAINED_DEVICE_SERIALNUMBER</td><td>There is no contained device with the requested serial number in the combined device.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>              <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                              <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_devicelistitemcombined_get_name_short(tiepie_hw_handle handle, uint32_t contained_device_serial_number, char* buffer, uint32_t length);

/**
 * \brief Get the short name without model postfix of a device contained in a combined device.
 *
 * E.g. <tt>HS5</tt>
 *
 * \param[in] handle A handle identifying the object.
 * \param[in] contained_device_serial_number The serial number identifying the \b contained device inside the combined device.
 * \param[out] buffer A pointer to a buffer for the name.
 * \param[in] length The length of the buffer, in bytes.
 * \return The length of the name in bytes, excluding terminating zero.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>                        <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>                        <td>The indicated device is not a combined device or the contained device does not support reading a name.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CONTAINED_DEVICE_SERIALNUMBER</td><td>There is no contained device with the requested serial number in the combined device.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>              <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                              <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_devicelistitemcombined_get_name_shortest(tiepie_hw_handle handle, uint32_t contained_device_serial_number, char* buffer, uint32_t length);

/**
 * \brief Get the calibration date of a device contained in a combined device.
 *
 * \param[in] handle A handle identifying the object.
 * \param[in] contained_device_serial_number The serial number identifying the \b contained device inside the combined device.
 * \return The calibration \ref #tiepie_hw_date " date" of the contained device, or zero if no calibration date is available.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>                        <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>                        <td>The indicated device is not a combined device or the contained device does not have a calibration date.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CONTAINED_DEVICE_SERIALNUMBER</td><td>There is no contained device with the requested serial number in the combined device.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>              <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                              <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_date tiepie_hw_devicelistitemcombined_get_calibration_date(tiepie_hw_handle handle, uint32_t contained_device_serial_number);

/**
 * \brief Get the channel count of an oscilloscope contained in a combined oscilloscope.
 *
 * \param[in] handle A handle identifying the object.
 * \param[in] contained_device_serial_number The serial number identifying the \b contained oscilloscope inside the combined oscilloscope.
 * \return The channel count of the contained oscilloscope.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>                        <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>                        <td>The indicated device is not a combined oscilloscope.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CONTAINED_DEVICE_SERIALNUMBER</td><td>There is no contained device with the requested serial number in the combined device.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>              <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                              <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint16_t tiepie_hw_devicelistitemcombined_get_oscilloscope_channel_count(tiepie_hw_handle handle, uint32_t contained_device_serial_number);

/**
 *       \}
 *     \}
 *     \defgroup tiepie_hw_devicelist_callbacks Callbacks
 *     \{
 *       \brief Functions to set callbacks that are triggered when the device list is changed.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Set a callback function which is called when a device is added to the device list.
 *
 * \param[in] callback A pointer to the \ref tiepie_hw_devicelist_callback "callback" function. Use \c NULL to disable.
 * \param[in] data Optional user data.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS                </td><td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_devicelist_set_callback_device_added(tiepie_hw_devicelist_callback callback, void* data);

/**
 * \brief Set a callback function which is called when a device is removed from the device list.
 *
 * \param[in] callback A pointer to the \ref tiepie_hw_devicelist_callback "callback" function. Use \c NULL to disable.
 * \param[in] data Optional user data.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS                </td><td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_devicelist_set_callback_device_removed(tiepie_hw_devicelist_callback callback, void* data);

/**
 * \brief Set a callback function which is called when the device can open property changes.
 *
 * \param[in] callback A pointer to the \ref tiepie_hw_devicelist_callback "callback" function. Use \c NULL to disable.
 * \param[in] data Optional user data.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS                </td><td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_devicelist_set_callback_device_can_open_changed(tiepie_hw_devicelist_callback callback, void* data);

/**
 *     \}
 *   \}
 *   \defgroup net Network
 *   \{
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether automatically detecting network instruments and instrument servers is enabled.
 *
 * \return #TIEPIE_HW_BOOL_TRUE if enabled, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \see tiepie_hw_network_set_auto_detect_enabled
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_network_get_auto_detect_enabled(void);

/**
 * \brief Enable or disable automatic detection of network instruments and instrument servers.
 *
 * \param[in] value #TIEPIE_HW_BOOL_TRUE or #TIEPIE_HW_BOOL_FALSE.
 * \return #TIEPIE_HW_BOOL_TRUE if enabled, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \see tiepie_hw_network_get_auto_detect_enabled
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_network_set_auto_detect_enabled(tiepie_hw_bool value);

/**
 *     \defgroup net_srv Servers
 *     \{
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Add a server to the list of servers.
 *
 * \param[in] url Pointer to URL character buffer.
 * \param[in] length Length of URL buffer or #TIEPIE_HW_STRING_LENGTH_NULL_TERMINATED.
 * \param[out] handle The handle to the added server or \c NULL.
 * \return #TIEPIE_HW_BOOL_TRUE if added successfully, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_network_servers_add(const char* url, uint32_t length, tiepie_hw_handle* handle);

/**
 * \brief Remove a server from the list of servers.
 *
 * \param[in] url Pointer to URL character buffer.
 * \param[in] length Length of URL buffer or #TIEPIE_HW_STRING_LENGTH_NULL_TERMINATED.
 * \param[in] force If #TIEPIE_HW_BOOL_TRUE all open devices are closed, if #TIEPIE_HW_BOOL_FALSE remove only succeeds if no devices are open.
 * \return #TIEPIE_HW_BOOL_TRUE if removed successfully, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_network_servers_remove(const char* url, uint32_t length, tiepie_hw_bool force);

/**
 * \brief Get the number of servers available.
 *
 * \return The number of servers available.
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_network_servers_get_count(void);

/**
 * \brief Get the handle of a server, based on its index in the list of servers.
 *
 * \param[in] index A server index, \c 0 .. tiepie_hw_network_servers_get_count() - 1.
 * \return The handle to the requested server or \c NULL.
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_handle tiepie_hw_network_servers_get_by_index(uint32_t index);

/**
 * \brief Get the handle of a server, based on its URL.
 *
 * \param[in] url Pointer to URL character buffer.
 * \param[in] length Length of URL buffer or #TIEPIE_HW_STRING_LENGTH_NULL_TERMINATED.
 * \return The handle to the requested server or \c NULL.
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_handle tiepie_hw_network_servers_get_by_url(const char* url, uint32_t length);

/**
 *       \defgroup net_srv_callbacks Callbacks
 *       \{
 *         \brief Functions to set callbacks that are triggered when the server list is changed.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Set a callback function which is called when a server is added to the server list.
 *
 * \param[in] callback A pointer to the \ref tiepie_hw_handle_callback "callback" function. Use \c NULL to disable.
 * \param[in] data Optional user data.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS                </td><td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_network_servers_set_callback_added(tiepie_hw_handle_callback callback, void* data);

/**
 *       \}
 *     \}
 *   \}
 *   \defgroup obj Object
 *   \{
 *     \brief Functions to control devices.
 *
 * Before a device can be controlled or information can be retrieved from it, the device must be \ref Open_dev "opened" and a handle to it must be obtained.
 * This handle is then used in the functions to access the device.
 *
 * Devices can be \ref scp "oscilloscopes" or \ref gen "generators".
 * They have device specific functions which are listed in the dedicated sections and \ref obj "common" functions which are available to all devices.
 *
 *     \defgroup obj_common Common
 *     \{
 *       \brief Functions common to all objects.
 *
 * These functions can be called with any handle.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Close a object.
 *
 * When closing a object, its handle becomes invalid and must not be used again.
 *
 * \param[in] handle A handle identifying the object.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_devicelistitem_open_device
 * \see tiepie_hw_devicelistitem_open_oscilloscope
 * \see tiepie_hw_devicelistitem_open_generator
 * \see tiepie_hw_devicelistitem_get_server
 * \see tiepie_hw_network_servers_get_by_index
 * \see tiepie_hw_network_servers_get_by_url
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_object_close(tiepie_hw_handle handle);

/**
 * \brief Check whether an object is removed.
 *
 * \param[in] handle A handle identifying the object.
 * \return #TIEPIE_HW_BOOL_TRUE if removed, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_object_is_removed(tiepie_hw_handle handle);

/**
 * \brief Check which interfaces are supported by the specified object.
 *
 * \param[in] handle A handle identifying the object.
 * \return Set of OR-ed, \ref TIEPIE_HW_INTERFACE "interface flags".
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_object_get_interfaces(tiepie_hw_handle handle);

/**
 *       \}
 *       \defgroup obj_callbacks Callbacks
 *       \{
 *         \brief Callbacks that indicate an object change.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Set a callback function which is called when an event occurs.
 *
 * \param[in] handle A handle identifying the object.
 * \param[in] callback A pointer to the \ref tiepie_hw_event_callback "callback" function. Use \c NULL to disable.
 * \param[in] data Optional user data.
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_object_set_event_callback(tiepie_hw_handle handle, tiepie_hw_event_callback callback, void* data);

/**
 *       \}
 *     \}
 *     \defgroup dev Device
 *     \{
 *       \brief Functions common to all devices, to setup and control devices.
 *
 * These functions can be called with any device handles.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 *       \defgroup dev_info Info
 *       \{
 *         \brief Functions to retrieve information from a device.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the calibration date of the device.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \return The \ref tiepie_hw_date "calibration date" of the device, or zero if no calibration date is available.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated device does not have a calibration date.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \par Example
 * \code{.c}
 * tiepie_hw_date date = tiepie_hw_device_get_calibration_date(h_device);
 *
 * printf("tiepie_hw_device_get_calibration_date = %u-%u-%u\n", date.year, date.month, date.day);
 * \endcode
 *
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_date tiepie_hw_device_get_calibration_date(tiepie_hw_handle handle);

/**
 * \brief Get the serial number of the device.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \return The serial number of the device.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated device does not have a serial number.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_device_get_serial_number(tiepie_hw_handle handle);

/**
 * \brief Get the IP address of the device.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[out] buffer A pointer to a buffer for the IP address.
 * \param[in] length The length of the buffer, in bytes.
 * \return The length of the name in bytes, excluding terminating zero.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>              <td>The indicated device is not a network device.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>              <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                    <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_device_get_ip_address(tiepie_hw_handle handle, char* buffer, uint32_t length);

/**
 * \brief Get the IP port number of the device.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \return The IP port number of the device, or zero if no IP port number is available.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>              <td>The indicated device is not a network device.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>              <td>The value of Id_kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                    <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint16_t tiepie_hw_device_get_ip_port(tiepie_hw_handle handle);

/**
 * \brief Get the product id of the device.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \return The #tiepie_hw_productid "product id" of the device.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated device does not support reading a product id.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_productid tiepie_hw_device_get_product_id(tiepie_hw_handle handle);

/**
 * \brief Get the device type.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \return The \ref TIEPIE_HW_DEVICETYPE "device type".
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_device_get_type(tiepie_hw_handle handle);

/**
 * \brief Get the full name of the device.
 *
 * E.g. <tt>Handyscope HS5-530XMS</tt>
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[out] buffer A pointer to a buffer for the name.
 * \param[in] length The length of the buffer, in bytes.
 * \return The length of the name in bytes, excluding terminating zero.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated device does not support reading a name.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_get_name_short
 * \see tiepie_hw_device_get_name_shortest
 *
 * \par Example
 * \code{.c}
 * uint32_t length = tiepie_hw_device_get_name(h_device, NULL, 0) + 1; // Add one for the terminating zero
 * char* name = malloc(sizeof(char) * length);
 * length = tiepie_hw_device_get_name(h_device, name, length);
 *
 * printf("tiepie_hw_device_get_name = %s\n", name);
 *
 * free(name);
 * \endcode
 *
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_device_get_name(tiepie_hw_handle handle, char* buffer, uint32_t length);

/**
 * \brief Get the short name of the device.
 *
 * E.g. <tt>HS5-530XMS</tt>
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[out] buffer A pointer to a buffer for the name.
 * \param[in] length The length of the buffer, in bytes.
 * \return The length of the short name in bytes, excluding terminating zero.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated device does not support reading a name.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_get_name
 * \see tiepie_hw_device_get_name_shortest
 *
 * \par Example
 * \code{.c}
 * uint32_t length = tiepie_hw_device_get_name_short(h_device, NULL, 0) + 1; // Add one for the terminating zero
 * char* name = malloc(sizeof(char) * length);
 * length = tiepie_hw_device_get_name_short(h_device, name, length);
 *
 * printf("tiepie_hw_device_get_name_short = %s\n", name);
 *
 * free(name);
 * \endcode
 *
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_device_get_name_short(tiepie_hw_handle handle, char* buffer, uint32_t length);

/**
 * \brief Get the short name of the device without model postfix.
 *
 * E.g. <tt>HS5</tt>
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[out] buffer A pointer to a buffer for the name.
 * \param[in] length The length of the buffer, in bytes.
 * \return The length of the short name in bytes, excluding terminating zero.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated device does not support reading a name.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_get_name
 * \see tiepie_hw_device_get_name_short
 *
 * \par Example
 * \code{.c}
 * uint32_t length = tiepie_hw_device_get_name_shortest(h_device, NULL, 0) + 1; // Add one for the terminating zero
 * char* s_name_shortest = malloc(sizeof(char) * length);
 * Length = tiepie_hw_device_get_name_shortest(h_device, s_name_shortest, length);
 *
 * printf("tiepie_hw_device_get_name_shortest = %s\n", s_name_shortest);
 *
 * free(s_name_shortest);
 * \endcode
 *
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_device_get_name_shortest(tiepie_hw_handle handle, char* buffer, uint32_t length);

/**
 * \brief Check whether the device has a wireless trigger module
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \return #TIEPIE_HW_BOOL_TRUE if the device has a wireless trigger module, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.1
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_device_has_wireless_trigger_module(tiepie_hw_handle handle);

/**
 *       \}
 *       \defgroup dev_battery Battery
 *       \{
 *         \brief Device battery related functions
 */

/**
 * \brief Check whether the device has a battery
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \return #TIEPIE_HW_BOOL_TRUE if the device has a battery, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_device_has_battery(tiepie_hw_handle handle);

/**
 * \brief Get the battery charge state of the device's battery in percent.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \return Battery charge in percent if succesful, \c -1 otherwise.
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated device does not support reading the battery charge or doesn't have a battery.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_has_battery
 * \see tiepie_hw_device_get_battery_time_to_empty
 * \see tiepie_hw_device_get_battery_time_to_full
 * \since 1.0
 */
TIEPIE_HW_API int8_t tiepie_hw_device_get_battery_charge(tiepie_hw_handle handle);

/**
 * \brief Get the expected time in minutes until the battery will be empty.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \return When successful, the expected time until the battery will be empty in minutes, else \c -1
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated device does not support reading the battery time to empty or doesn't have a battery.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_has_battery
 * \see tiepie_hw_device_get_battery_charge
 * \see tiepie_hw_device_get_battery_time_to_full
 * \since 1.0
 */
TIEPIE_HW_API int32_t tiepie_hw_device_get_battery_time_to_empty(tiepie_hw_handle handle);

/**
 * \brief Get the expected time in minutes until the battery will be fully charged.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \return When successful, the expected time until the battery will be fully charged in minutes, else \c -1
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated device does not support reading the battery time to full or doesn't have a battery.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_has_battery
 * \see tiepie_hw_device_get_battery_charge
 * \see tiepie_hw_device_is_battery_charging
 * \since 1.0
 */
TIEPIE_HW_API int32_t tiepie_hw_device_get_battery_time_to_full(tiepie_hw_handle handle);

/**
 * \brief Check whether a charger is connected to the device.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \return #TIEPIE_HW_BOOL_TRUE if the device is connected to a charger, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated device does not have a battery.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_has_battery
 * \see tiepie_hw_device_is_battery_charging
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_device_is_battery_charger_connected(tiepie_hw_handle handle);

/**
 * \brief Check whether the device's battery is being charged.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \return #TIEPIE_HW_BOOL_TRUE if the device's battery is being charged, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated device does not have a battery.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_has_battery
 * \see tiepie_hw_device_get_battery_charge
 * \see tiepie_hw_device_get_battery_time_to_empty
 * \see tiepie_hw_device_get_battery_time_to_full
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_device_is_battery_charging(tiepie_hw_handle handle);

/**
 * \brief Check whether the device's battery is defective.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \return #TIEPIE_HW_BOOL_TRUE if the device's battery is defective, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated device does not have a battery.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_has_battery
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_device_is_battery_broken(tiepie_hw_handle handle);

/**
 *       \}
 *       \defgroup dev_trigger Trigger
 *       \{
 *         \brief device trigger related functions.
 *
 *         \defgroup dev_trigger_input Input(s)
 *         \{
 *           \brief A device can have one or more device trigger inputs, usually available as pins on an extension connector on the instrument.
 *
 * Use the function tiepie_hw_device_trigger_get_input_count() to determine the amount of available device trigger inputs.
 * To use a device trigger input as trigger source, use the function tiepie_hw_device_trigger_input_set_enabled() to enable it.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the number of trigger inputs.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \return The number of trigger inputs.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger inputs.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint16_t tiepie_hw_device_trigger_get_input_count(tiepie_hw_handle handle);

/**
 * \brief Get the index of a trigger input identified by its ID.
 *
 * The index is used in the other trigger input functions to identify the trigger input.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[in] id The trigger input ID, a \ref TIEPIE_HW_TIID_ "TIEPIE_HW_TIID_*" value, identifying the trigger input.
 * \return The trigger input index or #TIEPIE_HW_TRIGGERIO_INDEX_INVALID.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger inputs.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested ID is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_trigger_input_get_id
 * \since 1.0
 */
TIEPIE_HW_API uint16_t tiepie_hw_device_trigger_get_input_index_by_id(tiepie_hw_handle handle, uint32_t id);

/**
 *           \defgroup dev_trigger_input_status Status
 *           \{
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether the trigger input caused a trigger.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] input The trigger input index identifying the trigger input, \c 0 to <tt>Dev_trIn_get_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if the trigger input caused a trigger, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \see tiepie_hw_oscilloscope_is_triggered
 * \see tiepie_hw_oscilloscope_is_timeout_triggered
 * \see tiepie_hw_oscilloscope_is_force_triggered
 * \see tiepie_hw_oscilloscope_channel_trigger_is_triggered
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_trigger_input_is_triggered(tiepie_hw_handle handle, uint16_t input);

/**
 *           \}
 *           \defgroup dev_trigger_input_enabled Enabled
 *           \{
 *             \brief The enabled state of a device trigger input determines whether an input is selected as trigger source.
 *
 * By default, all device trigger inputs are disabled (#TIEPIE_HW_BOOL_FALSE).
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether a device trigger input is enabled.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[in] input The trigger input index identifying the trigger input, \c 0 to <tt>Dev_trIn_get_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if enabled, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_INPUT</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_AVAILABLE</td>          <td>With the current settings, the trigger input is not available.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger inputs.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_trigger_input_set_enabled
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_device_trigger_input_get_enabled(tiepie_hw_handle handle, uint16_t input);

/**
 * \brief To select a device trigger input as trigger source, set trigger input enabled.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[in] input The trigger input index identifying the trigger input, \c 0 to <tt>Dev_trIn_get_count() - 1</tt>.
 * \param[in] value #TIEPIE_HW_BOOL_TRUE or #TIEPIE_HW_BOOL_FALSE.
 * \return #TIEPIE_HW_BOOL_TRUE if enabled, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_INPUT</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_AVAILABLE</td>          <td>With the current settings, the trigger input is not available.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger inputs.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_trigger_input_get_enabled
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_device_trigger_input_set_enabled(tiepie_hw_handle handle, uint16_t input, tiepie_hw_bool value);

/**
 *           \}
 *           \defgroup dev_trigger_input_kind Kind
 *           \{
 *             \brief The device trigger kind determines how the device trigger responds to the device trigger input signal.
 *
 * Use tiepie_hw_device_trigger_input_get_kinds() to find out which trigger kinds are supported by the device trigger input.
 * Read more on \ref triggering_devin_kind "device trigger kind".
 *
 * Default value: #TIEPIE_HW_TK_RISINGEDGE if supported, else #TIEPIE_HW_TK_FALLINGEDGE.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the supported trigger kinds for a specified device trigger input.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[in] input The trigger input index identifying the trigger input, \c 0 to <tt>Dev_trIn_get_count() - 1</tt>.
 * \return Supported trigger input kinds, a set of OR-ed \ref TIEPIE_HW_TK_ "TIEPIE_HW_TK_*" values.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_INPUT</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_AVAILABLE</td>          <td>With the current settings, the trigger input is not available.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger inputs.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_trigger_input_get_kind
 * \see tiepie_hw_device_trigger_input_set_kind
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_device_trigger_input_get_kinds(tiepie_hw_handle handle, uint16_t input);

//! \cond EXTENDED_API

/**
 * \brief Get the supported trigger kinds for a specified oscilloscope trigger input and measure mode.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[in] input The trigger input index identifying the trigger input, \c 0 to <tt>Dev_trIn_get_count() - 1</tt>.
 * \param[in] measure_mode Measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \return Supported trigger input kinds, a set of OR-ed \ref TIEPIE_HW_TK_ "TIEPIE_HW_TK_*" values.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_INPUT</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_AVAILABLE</td>          <td>With the current settings, the trigger input is not available.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested measure mode is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger inputs.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_trigger_input_get_kind
 * \see tiepie_hw_device_trigger_input_set_kind
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_trigger_input_get_kinds_ex(tiepie_hw_handle handle, uint16_t input, uint32_t measure_mode);

//! \endcond

/**
 * \brief Get the currently selected trigger kind for a specified device trigger input.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[in] input The trigger input index identifying the trigger input, \c 0 to <tt>Dev_trIn_get_count() - 1</tt>.
 * \return The current trigger kind, a \ref TIEPIE_HW_TK_ "TIEPIE_HW_TK_*" value.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_INPUT</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_AVAILABLE</td>          <td>With the current settings, the trigger input is not available.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger inputs.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_trigger_input_get_kinds
 * \see tiepie_hw_device_trigger_input_set_kind
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_device_trigger_input_get_kind(tiepie_hw_handle handle, uint16_t input);

/**
 * \brief Set the required trigger kind for a specified device trigger input.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[in] input The trigger input index identifying the trigger input, \c 0 to <tt>Dev_trIn_get_count() - 1</tt>.
 * \param[in] value The required trigger kind, a \ref TIEPIE_HW_TK_ "TIEPIE_HW_TK_*" value.
 * \return The actually set trigger kind, a \ref TIEPIE_HW_TK_ "TIEPIE_HW_TK_*" value.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_INPUT</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_AVAILABLE</td>          <td>With the current settings, the trigger input is not available.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested trigger kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger inputs.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_trigger_input_get_kinds
 * \see tiepie_hw_device_trigger_input_get_kind
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_device_trigger_input_set_kind(tiepie_hw_handle handle, uint16_t input, uint64_t value);

/**
 *           \}
 *           \defgroup dev_trigger_input_info Info
 *           \{
 *             \brief Obtain information of a device trigger input.
 *
 * The following information of a device trigger input is available:
 * - \ref tiepie_hw_device_trigger_input_is_available "Availability"
 * - \ref tiepie_hw_device_trigger_input_get_id "ID"
 * - \ref tiepie_hw_device_trigger_input_get_name "Name"
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether a device trigger input is available.
 *
 * Depending on other settings of a device, a device trigger input may be not available.
 * E.g. when the \ref scp_measurements_mode "measure mode" of an oscilloscope is set to \ref TIEPIE_HW_MM_STREAM "streaming",
 * device trigger inputs are not available.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[in] input The trigger input index identifying the trigger input, \c 0 to <tt>Dev_trIn_get_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if available, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_INPUT</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger inputs.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_device_trigger_input_is_available(tiepie_hw_handle handle, uint16_t input);

//! \cond EXTENDED_API

/**
 * \brief Check whether a device trigger input is available, for a specific \ref scp_measurements_mode "measure mode".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[in] input The trigger input index identifying the trigger input, \c 0 to <tt>Dev_trIn_get_count() - 1</tt>.
 * \param[in] measure_mode Measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \return #TIEPIE_HW_BOOL_TRUE if available, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_trigger_input_is_available_ex(tiepie_hw_handle handle, uint16_t input, uint32_t measure_mode);

//! \endcond

/**
 * \brief Get the id of a specified device trigger input.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[in] input The trigger input index identifying the trigger input, \c 0 to <tt>Dev_trIn_get_count() - 1</tt>.
 * \return The trigger input id, a \ref TIEPIE_HW_TIID_ "TIEPIE_HW_TIID_*" value.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_INPUT</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger inputs.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_trigger_get_input_index_by_id
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_device_trigger_input_get_id(tiepie_hw_handle handle, uint16_t input);

/**
 * \brief Get the name of a specified device trigger input.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[in] input The trigger input index identifying the trigger input, \c 0 to <tt>Dev_trIn_get_count() - 1</tt>.
 * \param[out] buffer A pointer to a buffer for the name.
 * \param[in] length The length of the buffer, in bytes.
 * \return The length of the name in bytes, excluding terminating zero.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_INPUT</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger inputs.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_device_trigger_input_get_name(tiepie_hw_handle handle, uint16_t input, char* buffer, uint32_t length);

/**
 *           \}
 *         \}
 *         \defgroup dev_trigger_output Output(s)
 *         \{
 *           \brief  A device can have one or more device trigger outputs, usually available as pins on an extension connector on the instrument.
 *
 * The trigger outputs are controlled by events that occur in the instrument.
 *
 * Use the function tiepie_hw_device_trigger_get_output_count() to determine the amount of available device trigger outputs.
 * To use a device trigger output, use the function tiepie_hw_device_trigger_output_set_enabled() to enable it.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the number of trigger outputs.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \return The number of trigger outputs.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger outputs.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint16_t tiepie_hw_device_trigger_get_output_count(tiepie_hw_handle handle);

/**
 * \brief Get the index of trigger output identified by its ID.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[in] id The trigger output ID, a \ref TIEPIE_HW_TOID_ "TIEPIE_HW_TOID_*" value, identifying the trigger output.
 * \return The trigger output index or #TIEPIE_HW_TRIGGERIO_INDEX_INVALID.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger outputs.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested ID is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_trigger_output_get_id()
 * \since 1.0
 */
TIEPIE_HW_API uint16_t tiepie_hw_device_trigger_get_output_index_by_id(tiepie_hw_handle handle, uint32_t id);

/**
 *           \defgroup dev_trigger_output_enabled Enabled
 *           \{
 *             \brief The enabled state of a device trigger output determines whether an output is used.
 *
 * By default, all trigger outputs are disabled.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether a trigger output is enabled.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[in] output The trigger output index identifying the trigger output, \c 0 to <tt>Dev_trOut_get_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if enabled, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_OUTPUT</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger outputs.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_trigger_output_set_enabled
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_device_trigger_output_get_enabled(tiepie_hw_handle handle, uint16_t output);

/**
 * \brief Set trigger output enable.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[in] output The trigger output index identifying the trigger output, \c 0 to <tt>Dev_trOut_get_count() - 1</tt>.
 * \param[in] value #TIEPIE_HW_BOOL_TRUE or #TIEPIE_HW_BOOL_FALSE.
 * \return #TIEPIE_HW_BOOL_TRUE if enabled, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_OUTPUT</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger outputs.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_trigger_output_get_enabled
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_device_trigger_output_set_enabled(tiepie_hw_handle handle, uint16_t output, tiepie_hw_bool value);

/**
 *           \}
 *           \defgroup dev_trigger_output_event Event
 *           \{
 *             \brief Select the event that controls the trigger output.
 *
 * Supported events are:
 * - \ref TIEPIE_HW_TOE_GENERATOR_START "Generator start"
 * - \ref TIEPIE_HW_TOE_GENERATOR_STOP "Generator stop"
 * - \ref TIEPIE_HW_TOE_GENERATOR_NEWPERIOD "Generator new period"
 *
 * Only one event at a time can be set for a trigger output.
 *
 * By default, the event is set to #TIEPIE_HW_TOE_GENERATOR_START.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the supported trigger output events for a specified device trigger output.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[in] output The trigger output index identifying the trigger output, \c 0 to <tt>Dev_trOut_get_count() - 1</tt>.
 * \return The supported trigger output events, a set of OR-ed \ref TIEPIE_HW_TOE_ "TIEPIE_HW_TOE_*" values.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_OUTPUT</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger outputs.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_trigger_output_get_event
 * \see tiepie_hw_device_trigger_output_set_event
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_device_trigger_output_get_events(tiepie_hw_handle handle, uint16_t output);

/**
 * \brief Get the currently selected trigger output event for a specified device trigger output.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[in] output The trigger output index identifying the trigger output, \c 0 to <tt>Dev_trOut_get_count() - 1</tt>.
 * \return The currently selected trigger output event, a \ref TIEPIE_HW_TOE_ "TIEPIE_HW_TOE_*" value.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_OUTPUT</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger outputs.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_trigger_output_get_events
 * \see tiepie_hw_device_trigger_output_set_event
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_device_trigger_output_get_event(tiepie_hw_handle handle, uint16_t output);

/**
 * \brief Set the trigger output event for a specified device trigger output.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[in] output The trigger output index identifying the trigger output, \c 0 to <tt>Dev_trOut_get_count() - 1</tt>.
 * \param[in] value Trigger output event, a \ref TIEPIE_HW_TOE_ "TIEPIE_HW_TOE_*" value.
 * \return Trigger output event, a \ref TIEPIE_HW_TOE_ "TIEPIE_HW_TOE_*" value.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_OUTPUT</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested event value is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger outputs.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_trigger_output_get_events
 * \see tiepie_hw_device_trigger_output_get_event
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_device_trigger_output_set_event(tiepie_hw_handle handle, uint16_t output, uint64_t value);

/**
 *           \}
 *           \defgroup dev_trigger_output_info Info
 *           \{
 *             \brief Obtain information of a device trigger output.
 *
 * The following information of a device trigger output is available:
 * - \ref tiepie_hw_device_trigger_output_get_id "ID"
 * - \ref tiepie_hw_device_trigger_output_get_name "Name"
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the id of a specified device trigger output.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[in] output The trigger output index identifying the trigger output, \c 0 to <tt>Dev_trOut_get_count() - 1</tt>.
 * \return The trigger output id, a \ref TIEPIE_HW_TOID_ "TIEPIE_HW_TOID_*" value.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_OUTPUT</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger outputs.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_device_trigger_get_output_index_byId()
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_device_trigger_output_get_id(tiepie_hw_handle handle, uint16_t output);

/**
 * \brief Get the name of a specified device trigger output.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[in] output The trigger output index identifying the trigger output, \c 0 to <tt>Dev_trOut_get_count() - 1</tt>.
 * \param[out] buffer A pointer to a buffer for the name.
 * \param[in] length The length of the buffer, in bytes.
 * \return The length of the name in bytes, excluding terminating zero.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_OUTPUT</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger outputs.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_device_trigger_output_get_name(tiepie_hw_handle handle, uint16_t output, char* buffer, uint32_t length);

/**
 * \brief Trigger the specified device trigger output.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the device.
 * \param[in] output The trigger output index identifying the trigger output, \c 0 to <tt>Dev_trOut_get_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if successful, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_OUTPUT</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The device has no trigger outputs or the trigger output doesn't support manual triggering.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_device_trigger_output_trigger(tiepie_hw_handle handle, uint16_t output);

/**
 *           \}
 *         \}
 *       \}
 *     \}
 *     \defgroup scp Oscilloscope
 *     \{
 *       \brief Functions to setup and control oscilloscopes.
 *
 * All oscilloscope related functions require an \ref tiepie_hw_handle "oscilloscope handle" to identify the oscilloscope,
 * see \ref Open_dev "opening a device".
 *
 *       \defgroup scp_channels Channels
 *       \{
 *         \brief Functions to setup and control oscilloscope channels.
 *
 * An oscilloscope will have one or more input channels.
 * Use tiepie_hw_oscilloscope_get_channel_count() to determine the amount of available channels.
 *
 * All oscilloscope channel related functions use a channel number parameter to identify the channel.
 * Channel numbers start at \c 0 for the first channel.
 *
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the number of channels.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The number of channels.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint16_t tiepie_hw_oscilloscope_get_channel_count(tiepie_hw_handle handle);

/**
 * \brief Check whether the channel is available.
 *
 * Depending on other settings, a channel may currently not be available.
 * It can still be \ref tiepie_hw_oscilloscope_channel_get_enabled "enabled", but that will affect other settings.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if available, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_is_available(tiepie_hw_handle handle, uint16_t ch);

//! \cond EXTENDED_API

/**
 * \brief Check whether the channel is available, for a specific configuration.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] measure_mode Measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \param[in] sample_rate Sample rate in Hz.
 * \param[in] resolution Resolution in bits.
 * \param[in] channel_enabled Pointer to buffer with channel enables.
 * \param[in] channel_count Number of items in \c channel_enabled
 * \return #TIEPIE_HW_BOOL_TRUE if available, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_is_available_ex(tiepie_hw_handle handle, uint16_t ch, uint32_t measure_mode, double sample_rate, uint8_t resolution, const tiepie_hw_bool* channel_enabled, uint16_t channel_count);

//! \endcond

/**
 *         \defgroup scp_ch_info Info
 *         \{
 *           \brief Functions to retrieve information from an oscilloscope channel.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the channel \ref TIEPIE_HW_CONNECTORTYPE "connector type".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return Channel \ref TIEPIE_HW_CONNECTORTYPE "connector type".
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The channel does not support reading the connector type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_channel_get_connector_type(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Check whether the channel has a differential input.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if differential, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_is_differential(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Check whether the channel has a galvanically isolated input.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if galvanically isolated, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_is_isolated(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Get the channel input impedance.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return Channel input impedance in Ohm.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The channel does not support reading the input impedance.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_get_impedance(tiepie_hw_handle handle, uint16_t ch);

/**
 *         \}
 *         \defgroup scp_ch_bandwidth Bandwidth
 *         \{
 *           \brief Functions to control the input bandwidth of an oscilloscope channel.
 *
 * By default the input bandwidth of a channel is set to the highest value available.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the supported input bandwidths for a specified channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[out] list A pointer to an array for the input bandwidths.
 * \param[in] length The number of elements in the array.
 * \return The total number of bandwidths.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_get_bandwidth
 * \see tiepie_hw_oscilloscope_channel_set_bandwidth
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_channel_get_bandwidths(tiepie_hw_handle handle, uint16_t ch, double* list, uint32_t length);

/**
 * \brief Get the current channel input bandwidth.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The current channel input bandwidth in Hz.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The channel does not support reading the input bandwidth.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_get_bandwidths
 * \see tiepie_hw_oscilloscope_channel_set_bandwidth
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_get_bandwidth(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Set the channel input bandwidth.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] bandwidth The requested input bandwidth in Hz.
 * \return The actually set channel input bandwidth in Hz.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The channel does not support changing the input bandwidth.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_get_bandwidths
 * \see tiepie_hw_oscilloscope_channel_get_bandwidth
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_set_bandwidth(tiepie_hw_handle handle, uint16_t ch, double bandwidth);

/**
 *         \}
 *         \defgroup scp_ch_coupling Coupling
 *         \{
 *           \brief Functions to control the input coupling of an oscilloscope channel.
 *
 * By default the input coupling of a channel is set to: Volt DC (#TIEPIE_HW_CK_DCV).
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the supported coupling kinds of a specified channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The supported coupling kinds, a set of OR-ed \ref TIEPIE_HW_CK_ "TIEPIE_HW_CK_*" values.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_get_coupling
 * \see tiepie_hw_oscilloscope_channel_set_coupling
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_channel_get_couplings(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Get the currently set coupling of a specified channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return Coupling, a \ref TIEPIE_HW_CK_ "TIEPIE_HW_CK_*" value.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_get_couplings
 * \see tiepie_hw_oscilloscope_channel_set_coupling
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_channel_get_coupling(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Set the coupling of a specified channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] coupling The required coupling, a \ref TIEPIE_HW_CK_ "TIEPIE_HW_CK_*" value.
 * \return The actually set coupling, a \ref TIEPIE_HW_CK_ "TIEPIE_HW_CK_*" value.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested coupling kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \remark Changing the input coupling can affect the \ref scp_ch_range "input range".
 *
 * \see tiepie_hw_oscilloscope_channel_get_couplings
 * \see tiepie_hw_oscilloscope_channel_get_coupling
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_channel_set_coupling(tiepie_hw_handle handle, uint16_t ch, uint64_t coupling);

/**
 *         \}
 *         \defgroup scp_ch_enabled Enabled
 *         \{
 *           \brief Functions to control the enabled state of an oscilloscope channel.
 *
 * The enabled state of a channel determines whether the channel is measured.
 *
 * By default all channels are enabled.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether a specified channel is currently enabled.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if enabled, #TIEPIE_HW_BOOL_FALSE if disabled.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_set_enabled
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_get_enabled(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Set channel enable.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] value #TIEPIE_HW_BOOL_TRUE or #TIEPIE_HW_BOOL_FALSE.
 * \return #TIEPIE_HW_BOOL_TRUE if enabled, #TIEPIE_HW_BOOL_FALSE if disabled.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_AVAILABLE</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \remark Changing the channel enable may affect the \ref scp_timebase_sample_rate "sample rate", \ref scp_timebase_record_length "record length" and/or \ref scp_ch_tr_enabled "channel trigger enabled".
 * \see tiepie_hw_oscilloscope_channel_get_enabled
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_set_enabled(tiepie_hw_handle handle, uint16_t ch, tiepie_hw_bool value);

/**
 *         \}
 *         \defgroup scp_ch_range Range
 *         \{
 *           \brief Functions to control the input range of an oscilloscope channel
 *
 * An oscilloscope channel will have one or more different input ranges.
 * The number of input ranges and which ranges are available depends on the selected \ref tiepie_hw_oscilloscope_channel_get_coupling "input coupling".
 * Use tiepie_hw_oscilloscope_channel_get_ranges() to determine how many and which ranges are available.
 * Changing the input couping may change the selected input range.
 *
 * An input channel supports auto ranging, where a suitable input range is selected based on the measured data of the
 * last performed measurement with the channel.
 * Manually setting a range will disable auto ranging.
 *
 * When auto ranging of a channel is enabled and \ref scp_ch_tr_level_mode "trigger level mode" is set to #TIEPIE_HW_TLM_ABSOLUTE,
 * the input range will not auto range to a range that is smaller than the selected trigger level.
 *
 * By default the highest available range is selected and auto ranging is enabled.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether auto ranging is enabled for a specified channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if enabled, #TIEPIE_HW_BOOL_FALSE if disabled.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_set_auto_ranging
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_get_auto_ranging(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Set auto ranging for a specified channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] value #TIEPIE_HW_BOOL_TRUE to enable or #TIEPIE_HW_BOOL_FALSE to disable.
 * \return #TIEPIE_HW_BOOL_TRUE if enabled, #TIEPIE_HW_BOOL_FALSE if disabled.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>With the current settings, auto ranging is not available.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_get_auto_ranging
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_set_auto_ranging(tiepie_hw_handle handle, uint16_t ch, tiepie_hw_bool value);

/**
 * \brief Get the supported input ranges for a specified channel, with the currently selected \ref tiepie_hw_oscilloscope_channel_get_coupling "coupling".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[out] list A pointer to an array for the input ranges.
 * \param[in] length The number of elements in the array.
 * \return The total number of ranges.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \cond EXTENDED_API
 * \see tiepie_hw_oscilloscope_channel_get_ranges_ex
 * \endcond
 *
 * \par Example
 * \code{.c}
 * uint32_t Range_count = tiepie_hw_oscilloscope_channel_get_ranges(h_device, Ch, NULL, 0);
 * double* Ranges = malloc(sizeof(double) * Range_count);
 * Range_count = tiepie_hw_oscilloscope_channel_get_ranges(h_device, Ch, Ranges, Range_count);
 *
 * printf("Scp_chGet_ranges (Ch%u):\n", Ch + 1);
 * for(i = 0 ; i < Range_count ; i++)
 *   printf("- %f\n", Ranges[ i ]);
 *
 * free(p_ranges);
 * \endcode
 *
 * \see tiepie_hw_oscilloscope_channel_get_range
 * \see tiepie_hw_oscilloscope_channel_set_range
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_channel_get_ranges(tiepie_hw_handle handle, uint16_t ch, double* list, uint32_t length);

//! \cond EXTENDED_API

/**
 * \brief Get the supported ranges by coupling.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] coupling Coupling: a \ref TIEPIE_HW_CK_ "TIEPIE_HW_CK_*" value.
 * \param[out] list Pointer to array.
 * \param[in] length Number of elements in array.
 * \return Total number of ranges.
 * \see tiepie_hw_oscilloscope_channel_get_ranges
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_channel_get_ranges_ex(tiepie_hw_handle handle, uint16_t ch, uint64_t coupling, double* list, uint32_t length);

//! \endcond

/**
 * \brief Get the currently selected input range for a specified channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The currently selected input range.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_get_ranges
 * \see tiepie_hw_oscilloscope_channel_set_range
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_get_range(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Set the input range for a specified channel.
 *
 * When a non existing input range value is tried to be set, the closest available larger input range is selected.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] range The requested input range, or maximum absolute value that must fit within the range.
 * \return The actually selected input range.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested input range is larger than the largest available range and clipped to that range.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested input range is within the valid range but not available. The closest larger valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested input range is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \remark Setting the range will disable auto ranging if enabled.
 * \remark Changing the input range may affect the \ref scp_ch_tr_level "trigger level(s)" if the \ref tiepie_hw_oscilloscope_channel_trigger_get_level_mode "trigger level mode" is #TIEPIE_HW_TLM_ABSOLUTE.
 *
 * \par Example
 * \code{.c}
 * double Range = 10;
 *
 * Range = tiepie_hw_oscilloscope_channel_set_range(h_device, Ch, Range);
 *
 * printf("Scp_chSet_range = %f", Range);
 * \endcode
 *
 * \see tiepie_hw_oscilloscope_channel_get_ranges
 * \see tiepie_hw_oscilloscope_channel_get_range
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_set_range(tiepie_hw_handle handle, uint16_t ch, double range);

/**
 *         \}
 *         \defgroup scp_ch_safeground SafeGround
 *         \{
 *           \brief Functions to control the SafeGround feature of an oscilloscope channel.
 *
 * SafeGround is a system that connects the negative side of an oscilloscope input to the oscilloscope's ground and
 * real time monitors the ground current of that input.
 * This turns a differential input into a single ended input.
 * When the ground current exceeds a selected threshold value, the ground connection of the input is immediately opened,
 * avoiding that the ground current becomes too large and causes damage.
 *
 * An event can be generated to inform that the ground was disconnected, #TIEPIE_HW_EVENT_OSCILLOSCOPE_SAFEGROUND_ERROR.
 * See also \ref obj_callbacks "Callbacks".
 *
 * SafeGround is not available for all instruments.
 * Use tiepie_hw_oscilloscope_channel_has_safeground() to check whether SafeGround is available for your instrument.
 *
 * By default SafeGround is disabled and the threshold current is set to 30 mA.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether the specified channel has SafeGround.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if SafeGround is available, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_has_safeground(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Check whether SafeGround is enabled for a specified channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if SafeGround is enabled, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not have SafeGround.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_has_safeground
 * \see tiepie_hw_oscilloscope_channel_set_safeground_enabled
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_get_safeground_enabled(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Enable or disable SafeGround for a specified channel.
 *
 * When SafeGround is enabled for a channel and a ground current larger than the selected current threshold starts flowing,
 * SafeGround is immediately disabled by the instrument. Remove the (wrong) ground connection before enabling SafeGround.
 *
 * SafeGround can only be enabled or disabled when the scope is not performing a measurement.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] value #TIEPIE_HW_BOOL_TRUE to enable SafeGround or #TIEPIE_HW_BOOL_FALSE to disable SafeGround.
 * \return #TIEPIE_HW_BOOL_TRUE if SafeGround is enabled, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td>A ground current larger than the selected threshold caused SafeGround to be disabled again, or the scope is measuring.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not have SafeGround.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_has_safeground
 * \see tiepie_hw_oscilloscope_channel_get_safeground_enabled
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_set_safeground_enabled(tiepie_hw_handle handle, uint16_t ch, tiepie_hw_bool value);

/**
 * \brief Get the minimum SafeGround threshold current for the specified channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return Minimum SafeGround threshold current, in Ampere.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not have SafeGround.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_has_safeground
 * \see tiepie_hw_oscilloscope_channel_get_safeground_threshold_max
 * \see tiepie_hw_oscilloscope_channel_get_safeground_threshold
 * \see tiepie_hw_oscilloscope_channel_set_safeground_threshold
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_get_safeground_threshold_min(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Get the maximum SafeGround threshold current for the specified channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return Maximum SafeGround threshold current, in Ampere.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not have SafeGround.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_has_safeground
 * \see tiepie_hw_oscilloscope_channel_get_safeground_threshold_min
 * \see tiepie_hw_oscilloscope_channel_get_safeground_threshold
 * \see tiepie_hw_oscilloscope_channel_set_safeground_threshold
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_get_safeground_threshold_max(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Get the actual SafeGround threshold current for the specified channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The currently set SafeGround threshold current, in Ampere.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not have SafeGround.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_has_safeground
 * \see tiepie_hw_oscilloscope_channel_get_safeground_threshold_min
 * \see tiepie_hw_oscilloscope_channel_get_safeground_threshold_max
 * \see tiepie_hw_oscilloscope_channel_set_safeground_threshold
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_get_safeground_threshold(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Set the SafeGround threshold current for the specified channel.
 *
 * The SafeGround threshold can only be set when the scope is not performing a measurement.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] threshold The required threshold current, in Ampere.
 * \return The actual set SafeGround threshold current, in Ampere.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested threshold current is within the valid range, but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested threshold current is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td>The scope is measuring.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not have SafeGround.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_has_safeground
 * \see tiepie_hw_oscilloscope_channel_get_safeground_threshold_min
 * \see tiepie_hw_oscilloscope_channel_get_safeground_threshold_max
 * \see tiepie_hw_oscilloscope_channel_get_safeground_threshold
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_set_safeground_threshold(tiepie_hw_handle handle, uint16_t ch, double threshold);

//! \cond EXTENDED_API

/**
 * \brief Verify if the required threshold current for a specified channel can be set.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] threshold The required threshold current, in Ampere.
 * \return The SafeGround threshold current that would be set.
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_verify_safeground_threshold(tiepie_hw_handle handle, uint16_t ch, double threshold);

//! \endcond

/**
 *         \}
 *         \defgroup scp_ch_tr Trigger
 *         \{
 *           \brief Functions to control the trigger settings of an oscilloscope channel.
 *
 * Depending on the settings of the oscilloscope, a channel trigger may not be supported or temporarily unavailable.
 * In streaming \ref scp_measurements_mode "measure mode", channel trigger is not supported,
 * use tiepie_hw_oscilloscope_channel_has_trigger() to check if triggering is supported in the currently set measure mode.
 * When channel trigger is supported, it can be temporarily unavailable due to other settings like e.g. sample rate,
 * resolution and/or the number of enabled channels, use tiepie_hw_oscilloscope_channel_trigger_is_available() to check if the trigger is available.
 *
 * To use a channel as trigger source, the channel must be \ref scp_ch_enabled "enabled".
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether the specified channel has trigger support with the currently selected \ref scp_measurements_mode "measure mode".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if the channel has trigger support, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_has_trigger(tiepie_hw_handle handle, uint16_t ch);

//! \cond EXTENDED_API

/**
 * \brief Check whether the specified channel has trigger support, for a specific configuration.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] measure_mode Measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \return #TIEPIE_HW_BOOL_TRUE if the channel has trigger support, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_has_trigger_ex(tiepie_hw_handle handle, uint16_t ch, uint32_t measure_mode);

//! \endcond

/**
 * \brief Check whether the channel trigger for the specified channel is available, with the current oscilloscope settings.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if available, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_trigger_is_available(tiepie_hw_handle handle, uint16_t ch);

//! \cond EXTENDED_API

/**
 * \brief Check whether the channel trigger is available, for a specific configuration.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] measure_mode Measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \param[in] sample_rate sample rate in Hz.
 * \param[in] resolution Resolution in bits.
 * \param[in] channel_enabled Pointer to buffer with channel enables.
 * \param[in] channel_trigger_enabled  Pointer to buffer with channel trigger enables.
 * \param[in] channel_count Number of items in \c channel_enabled and \c channel_trigger_enabled.
 * \return #TIEPIE_HW_BOOL_TRUE if available, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_trigger_is_available_ex(tiepie_hw_handle handle, uint16_t ch, uint32_t measure_mode, double sample_rate, uint8_t resolution, const tiepie_hw_bool* channel_enabled, const tiepie_hw_bool* channel_trigger_enabled, uint16_t channel_count);

//! \endcond

/**
 * \brief Check whether the channel trigger caused a trigger.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if the channel trigger caused a trigger, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \see tiepie_hw_oscilloscope_is_triggered
 * \see tiepie_hw_oscilloscope_is_timeout_triggered
 * \see tiepie_hw_oscilloscope_is_force_triggered
 * \see tiepie_hw_oscilloscope_trigger_input_is_triggered
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_trigger_is_triggered(tiepie_hw_handle handle, uint16_t ch);

/**
 *           \defgroup scp_ch_tr_enabled Enabled
 *           \{
 *             \brief The enabled state of a channel trigger determines whether a channel is selected as trigger source.
 *
 * Channel triggers of multiple channels can be enabled, in that case they will be OR'ed.
 *
 * The enabled state can be affected by changing the \ref scp_ch_enabled "channel enable", \ref scp_timebase_sample_rate "sample rate" and/or \ref scp_resolution "resolution".
 *
 * By default channel 1 is enabled, all other channels are disabled.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether channel trigger for a specified channel is enabled.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if enabled, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support trigger with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_trigger_set_enabled
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_trigger_get_enabled(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief To select a channel as trigger source, set channel trigger enable.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] value #TIEPIE_HW_BOOL_TRUE or #TIEPIE_HW_BOOL_FALSE.
 * \return #TIEPIE_HW_BOOL_TRUE if enabled, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_AVAILABLE</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support trigger with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \remark Enabling the channel trigger may change the \ref scp_ch_range "input range" if \ref tiepie_hw_oscilloscope_channel_trigger_get_level_mode "trigger level mode" is #TIEPIE_HW_TLM_ABSOLUTE and \ref tiepie_hw_oscilloscope_channel_get_auto_ranging "auto ranging" is enabled.
 * \see tiepie_hw_oscilloscope_channel_trigger_get_enabled
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_trigger_set_enabled(tiepie_hw_handle handle, uint16_t ch, tiepie_hw_bool value);

/**
 *           \}
 *           \defgroup scp_ch_tr_kind Kind
 *           \{
 *             \brief The channel trigger kind property is used to control how the channel trigger responds to the channel input signal.
 *
 * Use tiepie_hw_oscilloscope_channel_trigger_get_kinds() to find out which trigger kinds are supported by the channel.
 * Depending on the selected trigger kind, other properties like e.g. level(s) and hysteresis are available to configure the
 * channel trigger. Read more on \ref triggering_scpch_kind "trigger kind".
 *
 * By default kind is set to rising edge (#TIEPIE_HW_TK_RISINGEDGE).
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the supported channel trigger kinds for a specified channel with the currently selected \ref scp_measurements_mode "measure mode".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The supported trigger kinds, a set of OR-ed \ref TIEPIE_HW_TK_ "TIEPIE_HW_TK_*" values or #TIEPIE_HW_TKM_NONE if the channel has no trigger support.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support trigger with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_trigger_get_kind
 * \see tiepie_hw_oscilloscope_channel_trigger_set_kind
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_channel_trigger_get_kinds(tiepie_hw_handle handle, uint16_t ch);

//! \cond EXTENDED_API

/**
 * \brief Get the supported channel trigger kinds for a specified channel, for a specific \ref scp_measurements_mode "measure mode".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] measure_mode Measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \return Supported trigger kinds, a set of OR-ed \ref TIEPIE_HW_TK_ "TIEPIE_HW_TK_*" values.
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_channel_trigger_get_kinds_ex(tiepie_hw_handle handle, uint16_t ch, uint32_t measure_mode);

//! \endcond

/**
 * \brief Get the currently selected channel trigger kind for a specified channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The current trigger kind, a \ref TIEPIE_HW_TK_ "TIEPIE_HW_TK_*" value.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support trigger with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_trigger_get_kinds
 * \see tiepie_hw_oscilloscope_channel_trigger_set_kind
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_channel_trigger_get_kind(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Set the channel trigger kind for a specified channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] value The required trigger kind: a \ref TIEPIE_HW_TK_ "TIEPIE_HW_TK_*" value.
 * \return The actually set trigger kind, a \ref TIEPIE_HW_TK_ "TIEPIE_HW_TK_*" value.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested trigger kind is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support trigger with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \remark Changing the channel trigger kind may change the \ref scp_ch_range "input range" if the \ref tiepie_hw_oscilloscope_channel_trigger_get_enabled "channel trigger" is enabled, \ref tiepie_hw_oscilloscope_channel_trigger_get_level_mode "trigger level mode" is #TIEPIE_HW_TLM_ABSOLUTE and \ref tiepie_hw_oscilloscope_channel_get_auto_ranging "auto ranging" is enabled.
 * \see tiepie_hw_oscilloscope_channel_trigger_get_kinds
 * \see tiepie_hw_oscilloscope_channel_trigger_get_kind
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_channel_trigger_set_kind(tiepie_hw_handle handle, uint16_t ch, uint64_t value);

/**
 *           \}
 *           \defgroup scp_ch_tr_level_mode Level mode
 *           \{
 *             \brief Functions for controlling the trigger level mode.
 *
 * The trigger level can be set in two different ways, indicated by the trigger level mode:
 * - #TIEPIE_HW_TLM_RELATIVE, the trigger level is set as a floating point value between 0 and 1, corresponding to a percentage of the full scale \ref scp_ch_range "input range".
 * - #TIEPIE_HW_TLM_ABSOLUTE, the trigger level is set as a floating point value, clipped by the full scale \ref scp_ch_range "input range".
 *
 * When trigger level mode is set to #TIEPIE_HW_TLM_RELATIVE and \ref scp_ch_range "auto ranging" of the channel is enabled, the trigger level will remain at the same
 * percentage when the input range changes, resulting in a different absolute voltage.
 *
 * When trigger level mode is set to #TIEPIE_HW_TLM_ABSOLUTE and auto ranging of the channel is enabled, the trigger level will remain at the same
 * absolute voltage level when the input range changes. The input range will not auto range to a range that is smaller than the selected
 * trigger level.
 *
 * By default the trigger level mode is set to #TIEPIE_HW_TLM_RELATIVE.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the supported trigger level modes of a specified channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The supported trigger level modes, a set of OR-ed \ref TIEPIE_HW_TLM_ "TIEPIE_HW_TLM_*" values or #TIEPIE_HW_TLMM_NONE when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support trigger with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_channel_trigger_get_level_modes(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Get the current trigger level mode of a specified channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The curretly set trigger level mode, a \ref TIEPIE_HW_TLM_ "TIEPIE_HW_TLM_*" value, or #TIEPIE_HW_TLMM_NONE when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support trigger with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_channel_trigger_get_level_mode(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Set the trigger level mode of a specified channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] value The requested trigger level mode, a \ref TIEPIE_HW_TLM_ "TIEPIE_HW_TLM_*" value.
 * \return The actually set trigger level mode, a \ref TIEPIE_HW_TLM_ "TIEPIE_HW_TLM_*" value, or #TIEPIE_HW_TLMM_NONE when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support trigger with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested trigger level mode is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_channel_trigger_set_level_mode(tiepie_hw_handle handle, uint16_t ch, uint32_t value);

/**
 *           \}
 *           \defgroup scp_ch_tr_level Level
 *           \{
 *             \brief The channel trigger level property is used to control at which level(s) the channel trigger responds to the channel input signal.
 *
 * The number of available trigger levels depends on the currently set \ref #scp_ch_tr_kind "trigger kind".
 * Use tiepie_hw_oscilloscope_channel_trigger_get_level_count() to determine the number of trigger levels for the currently set trigger kind.
 *
 * If the \ref scp_ch_tr_level_mode "trigger level mode" is #TIEPIE_HW_TLM_RELATIVE, the trigger level is set as a floating point value between 0 and 1, corresponding to a percentage of the full scale \ref scp_ch_range "input range":
 * - 0.0 (0%) equals -full scale
 * - 0.5 (50%) equals mid level or 0 Volt
 * - 1.0 (100%) equals full scale.
 *
 * If the \ref scp_ch_tr_level_mode "trigger level mode" is #TIEPIE_HW_TLM_ABSOLUTE, the trigger level is set as a floating point value, clipped by the full scale \ref scp_ch_range "input range".
 *
 * By default the trigger level is set to 0.5 (50%) of the full-scale range.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the number of channel trigger levels for a specified channel with the currently selected \ref tiepie_hw_oscilloscope_channel_trigger_get_kind "trigger kind".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The number of available trigger levels for the currently set trigger kind.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support trigger with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_trigger_get_kind
 * \see tiepie_hw_oscilloscope_channel_trigger_get_level
 * \see tiepie_hw_oscilloscope_channel_trigger_set_level
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_channel_trigger_get_level_count(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Get the currently set channel trigger level value for a specified channel and trigger level.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] index The trigger level index, \c 0 to <tt>tiepie_hw_oscilloscope_channel_trigger_get_level_count() - 1</tt>.
 * \return The currently set trigger level value.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support trigger (level) with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_INDEX</td>          <td>The trigger level index is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_trigger_get_level_count
 * \see tiepie_hw_oscilloscope_channel_trigger_set_level
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_trigger_get_level(tiepie_hw_handle handle, uint16_t ch, uint32_t index);

/**
 * \brief Set the channel trigger level value for a specified channel and trigger level.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] index The trigger level index, \c 0 to <tt>tiepie_hw_oscilloscope_channel_trigger_get_level_count() - 1</tt>.
 * \param[in] value The required trigger level.
 * \return The actually set trigger level.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested trigger level is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support trigger (level) with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_INDEX</td>          <td>The trigger level index is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \remark Changing the channel trigger level may change the \ref scp_ch_range "input range" if the \ref tiepie_hw_oscilloscope_channel_trigger_get_enabled "channel trigger" is enabled, \ref tiepie_hw_oscilloscope_channel_trigger_get_level_mode "trigger level mode" is #TIEPIE_HW_TLM_ABSOLUTE and \ref tiepie_hw_oscilloscope_channel_get_auto_ranging "auto ranging" is enabled.
 * \see tiepie_hw_oscilloscope_channel_trigger_get_level_count
 * \see tiepie_hw_oscilloscope_channel_trigger_get_level
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_trigger_set_level(tiepie_hw_handle handle, uint16_t ch, uint32_t index, double value);

/**
 *           \}
 *           \defgroup scp_ch_tr_hysteresis Hysteresis
 *           \{
 *             \brief The channel trigger hysteresis property is used to control the sensitivity of the trigger system.
 *
 * The number of available trigger hystereses depends on the currently set \ref #scp_ch_tr_kind "trigger kind".
 * Use tiepie_hw_oscilloscope_channel_trigger_get_hysteresis_count() to determine the number of trigger hystereses for the currently set trigger kind.
 *
 * The trigger hysteresis is set as a floating point value between 0 and 1, corresponding to a percentage of the full scale \ref scp_ch_range "input range":
 * - 0.0 (0%) equals 0 Volt (no hysteresis)
 * - 0.5 (50%) equals full scale
 * - 1.0 (100%) equals 2 * full scale.
 *
 * By default the trigger hysteresis is set to 0.05 (5%) of the full-scale range.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the number of trigger hystereses for a specified channel with the currently selected \ref tiepie_hw_oscilloscope_channel_trigger_get_kind "trigger kind".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The number of available trigger hystereses for the currently set trigger kind.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support trigger with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_trigger_get_kind
 * \see tiepie_hw_oscilloscope_channel_trigger_get_hysteresis
 * \see tiepie_hw_oscilloscope_channel_trigger_set_hysteresis
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_channel_trigger_get_hysteresis_count(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Get the currently set channel trigger hysteresis value for a specified channel and trigger hysteresis.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] index The trigger hysteresis index, \c 0 to <tt>tiepie_hw_oscilloscope_channel_trigger_get_hysteresis_count() - 1</tt>.
 * \return The currently set trigger hysteresis value, a number between \c 0 and \c 1.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support trigger (hysteresis) with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_INDEX</td>          <td>The trigger hysteresis index is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_trigger_get_hysteresis_count
 * \see tiepie_hw_oscilloscope_channel_trigger_set_hysteresis
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_trigger_get_hysteresis(tiepie_hw_handle handle, uint16_t ch, uint32_t index);

/**
 * \brief Set the channel trigger hysteresis value for a specified channel and trigger hysteresis.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] index The trigger hysteresis index, \c 0 to <tt>tiepie_hw_oscilloscope_channel_trigger_get_hysteresis_count() - 1</tt>.
 * \param[in] value The required trigger hysteresis value, a number between \c 0 and \c 1.
 * \return The actually set trigger hysteresis value, a number between \c 0 and \c 1.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested trigger hysteresis is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support trigger (hysteresis) with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_INDEX</td>          <td>The trigger hysteresis index is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_trigger_get_hysteresis_count
 * \see tiepie_hw_oscilloscope_channel_trigger_get_hysteresis
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_trigger_set_hysteresis(tiepie_hw_handle handle, uint16_t ch, uint32_t index, double value);

/**
 *           \}
 *           \defgroup scp_ch_tr_condition Condition
 *           \{
 *             \brief Some trigger kinds require an additional condition to indicate how the channel trigger must respond to the input signal.
 *
 * The available trigger conditions depend on the currently set trigger kind.
 * Use tiepie_hw_oscilloscope_channel_trigger_get_conditions() to determine the available trigger conditions for the currently selected trigger kind.
 * Read more on \ref triggering_scpch_condition "trigger condition".
 *
 * By default the trigger condition is set to: larger than (#TIEPIE_HW_TC_LARGER).
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the supported trigger conditions for a specified channel with the currently selected \ref tiepie_hw_oscilloscope_channel_trigger_get_kind "trigger kind".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The supported trigger conditions for this channel and trigger kind, a set of OR-ed \ref TIEPIE_HW_TC_ "TIEPIE_HW_TC_*" values.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support trigger with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_trigger_get_kind
 * \see tiepie_hw_oscilloscope_channel_trigger_get_condition
 * \see tiepie_hw_oscilloscope_channel_trigger_set_condition
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_channel_trigger_get_conditions(tiepie_hw_handle handle, uint16_t ch);

//! \cond EXTENDED_API

/**
 * \brief Get the supported trigger conditions for a specified channel, for a specific \ref scp_measurements_mode "measure mode" and \ref scp_ch_tr_kind "trigger kind".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] measure_mode Measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \param[in] trigger_kind Trigger kind, a \ref TIEPIE_HW_TK_ "TIEPIE_HW_TK_*" value.
 * \return Supported trigger conditions for this channel, measure mode and trigger kind, a set of OR-ed \ref TIEPIE_HW_TC_ "TIEPIE_HW_TC_*" values.
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_channel_trigger_get_conditions_ex(tiepie_hw_handle handle, uint16_t ch, uint32_t measure_mode, uint64_t trigger_kind);

//! \endcond

/**
 * \brief Get the current selected trigger condition for a specified channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The current trigger condition, a \ref TIEPIE_HW_TC_ "TIEPIE_HW_TC_*" value.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support trigger (condition) with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_trigger_get_conditions
 * \see tiepie_hw_oscilloscope_channel_trigger_set_condition
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_channel_trigger_get_condition(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Set the trigger condition for a specified channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] value The required trigger condition, a \ref TIEPIE_HW_TC_ "TIEPIE_HW_TC_*" value.
 * \return The actually set trigger condition, a \ref TIEPIE_HW_TC_ "TIEPIE_HW_TC_*" value.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested trigger condition is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support trigger (condition) with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_trigger_get_conditions
 * \see tiepie_hw_oscilloscope_channel_trigger_get_condition
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_channel_trigger_set_condition(tiepie_hw_handle handle, uint16_t ch, uint32_t value);

/**
 *           \}
 *           \defgroup scp_ch_tr_time Time
 *           \{
 *             \brief The Time property determines how long a specific condition must last for the channel trigger to respond.
 *
 * The number of time properties depends on the currently selected trigger kind and currently selected trigger condition.
 * Use tiepie_hw_oscilloscope_channel_trigger_get_time_count() to determine the number of trigger time properties for the currently set trigger kind and condition.
 *
 * The trigger time can be affected by changing the \ref scp_timebase_sample_rate "sample rate".
 *
 * The trigger time is set as a value in seconds.
 * By default time[0] is set to 1 ms.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the number of trigger times for the current \ref tiepie_hw_oscilloscope_channel_trigger_get_kind "trigger kind" and \ref tiepie_hw_oscilloscope_channel_trigger_get_condition "trigger condition".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The number of available trigger times for the current trigger kind and condition.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support trigger with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_trigger_get_kind
 * \see tiepie_hw_oscilloscope_channel_trigger_get_condition
 * \see tiepie_hw_oscilloscope_channel_trigger_get_time
 * \see tiepie_hw_oscilloscope_channel_trigger_set_time
 * \cond EXTENDED_API
 * \see tiepie_hw_oscilloscope_channel_trigger_verify_time
 * \endcond
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_channel_trigger_get_time_count(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Get the current trigger time value for a specified channel and trigger type.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] index The trigger time index, \c 0 to <tt>tiepie_hw_oscilloscope_channel_trigger_get_time_count() - 1</tt>.
 * \return The currently set trigger time value, in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support trigger (time) with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_INDEX</td>          <td>The trigger time index is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_trigger_get_time_count
 * \see tiepie_hw_oscilloscope_channel_trigger_set_time
 * \cond EXTENDED_API
 * \see tiepie_hw_oscilloscope_channel_trigger_verify_time
 * \endcond
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_trigger_get_time(tiepie_hw_handle handle, uint16_t ch, uint32_t index);

/**
 * \brief Set the required trigger time value for a specified channel and trigger type.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] index The trigger time index, \c 0 to <tt>tiepie_hw_oscilloscope_channel_trigger_get_time_count() - 1</tt>.
 * \param[in] value The required trigger time value, in seconds.
 * \return The actually set trigger time value, in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested trigger time is within the valid range, but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested trigger time is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_INDEX</td>          <td>The trigger time index is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support trigger (time) with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_trigger_get_time_count
 * \see tiepie_hw_oscilloscope_channel_trigger_get_time
 * \cond EXTENDED_API
 * \see tiepie_hw_oscilloscope_channel_trigger_verify_time
 * \endcond
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_trigger_set_time(tiepie_hw_handle handle, uint16_t ch, uint32_t index, double value);

//! \cond EXTENDED_API

/**
 * \brief Verify if the required trigger time value for a specified channel and trigger type can be set.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] index The trigger time index, \c 0 to <tt>tiepie_hw_oscilloscope_channel_trigger_get_time_count() - 1</tt>.
 * \param[in] value The required trigger time value, in seconds.
 * \return The actually trigger time value that would have been set, in seconds.
 * \see tiepie_hw_oscilloscope_channel_trigger_get_time_count
 * \see tiepie_hw_oscilloscope_channel_trigger_get_time
 * \see tiepie_hw_oscilloscope_channel_trigger_set_time
 * \see tiepie_hw_oscilloscope_channel_trigger_verify_time_ex
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_trigger_verify_time(tiepie_hw_handle handle, uint16_t ch, uint32_t index, double value);

/**
 * \brief Verify if the required trigger time value for a specified channel, measure mode, sample rate, trigger type and trigger condition can be set.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] index The trigger time index, \c 0 to <tt>tiepie_hw_oscilloscope_channel_trigger_get_time_count() - 1</tt>.
 * \param[in] value The required trigger time value, in seconds.
 * \param[in] measure_mode The required measure mode.
 * \param[in] sample_rate Sample rate in Hz.
 * \param[in] trigger_kind The required trigger kind.
 * \param[in] trigger_condition The required trigger condition.
 * \return The actually trigger time value that would have been set, in seconds.
 * \see tiepie_hw_oscilloscope_channel_trigger_get_time_count
 * \see tiepie_hw_oscilloscope_channel_trigger_get_time
 * \see tiepie_hw_oscilloscope_channel_trigger_set_time
 * \see tiepie_hw_oscilloscope_channel_trigger_verify_time
 * \see tiepie_hw_oscilloscope_channel_trigger_verify_time_ex
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_trigger_verify_time_ex(tiepie_hw_handle handle, uint16_t ch, uint32_t index, double value, uint32_t measure_mode, double sample_rate, uint64_t trigger_kind, uint32_t trigger_condition);

//! \endcond

/**
 *           \}
 *         \}
 *         \defgroup scp_ch_demo Demo signals
 *         \{
 *            \brief Functions to control demo signals of a demo oscilloscope channel.
 *
 * A demo oscilloscope functions identical to a real instrument but it has the additional capability of simulating several different types of signals.
 * Many aspects of these signals can be adjusted.
 */

/**
 * \brief Check whether the specified oscilloscope is a demo oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return #TIEPIE_HW_BOOL_TRUE if the specified oscilloscope is a demo oscilloscope, #TIEPIE_HW_BOOL_FALSE if not.
 * \see tiepie_hw_devicelist_create_demo_device
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_is_demo(tiepie_hw_handle handle);

/**
 * \brief Get the currently selected demo signal type of a specified demo oscilloscope channel
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The currently selected signal type, #tiepie_hw_demosignal value.
 * \see tiepie_hw_oscilloscope_channel_demo_set_signal
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support getting the demo signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_demo_set_signal
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_demosignal tiepie_hw_oscilloscope_channel_demo_get_signal(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Set the demo signal type of a specified demo oscilloscope channel
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] value The requested demo signal type, a \ref #tiepie_hw_demosignal value.
 * \return The actually set demo signal type, a \ref #tiepie_hw_demosignal value.
 * \see tiepie_hw_oscilloscope_channel_demo_get_signal
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated channel does not support setting the demo signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is not valid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_demosignal
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_demosignal tiepie_hw_oscilloscope_channel_demo_set_signal(tiepie_hw_handle handle, uint16_t ch, tiepie_hw_demosignal value);

/**
 *           \defgroup scp_ch_demo_amplitude Amplitude
 *           \{
 *              \brief Functions to control the amplitude of a demo signal
 *
 * Several of the demo signal types support setting the signal amplitude, but others don't.
 * Use tiepie_hw_oscilloscope_channel_demo_has_amplitude() to find out whether the selected demo signal type supports setting the amplitude.
 */

/**
 * \brief Check whether the currently selected demo signal type supports setting the amplitude.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if setting the amplitude is supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_demo_get_amplitude
 * \see tiepie_hw_oscilloscope_channel_demo_set_amplitude
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_demo_has_amplitude(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Get the currently selected demo signal amplitude of a specified demo oscilloscope channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The currently set demo signal amplitude, in Volt.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The currently selected demo signal type does not support getting the demo signal amplitude.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_demo_has_amplitude
 * \see tiepie_hw_oscilloscope_channel_demo_set_amplitude
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_demo_get_amplitude(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Set the demo signal amplitude of a specified demo oscilloscope channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] value The requested demo signal amplitude, in Volt.
 * \return The actually set amplitude, in Volt.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The currently selected demo signal type does not support setting the demo signal amplitude.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal amplitude is not valid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_demo_has_amplitude
 * \see tiepie_hw_oscilloscope_channel_demo_get_amplitude
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_demo_set_amplitude(tiepie_hw_handle handle, uint16_t ch, double value);

/**
 *           \}
 *           \defgroup scp_ch_demo_frequency Frequency
 *           \{
 *              \brief Functions to control the frequency of a demo signal
 *
 * Several of the demo signal types support setting the signal frequency, but others don't.
 * Use tiepie_hw_oscilloscope_channel_demo_has_frequency() to find out whether the selected demo signal type supports setting the frequency.
 */

/**
 * \brief Check whether the currently selected demo signal type supports setting the frequency.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if setting the frequency is supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_demo_get_frequency
 * \see tiepie_hw_oscilloscope_channel_demo_set_frequency
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_demo_has_frequency(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Get the currently selected demo signal frequency of a specified demo oscilloscope channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The currently set demo signal frequency, in Hz.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The currently selected demo signal type does not support getting the demo signal frequency.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_demo_has_frequency
 * \see tiepie_hw_oscilloscope_channel_demo_set_frequency
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_demo_get_frequency(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Set the demo signal frequency of a specified demo oscilloscope channel, in Hz.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] value The requested demo signal frequency, in Hz.
 * \return The actually set frequency, in Hz.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The currently selected demo signal type does not support setting the demo signal frequency.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal frequency is not valid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_demo_has_frequency
 * \see tiepie_hw_oscilloscope_channel_demo_get_frequency
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_demo_set_frequency(tiepie_hw_handle handle, uint16_t ch, double value);

/**
 *           \}
 *           \defgroup scp_ch_demo_offset Offset
 *           \{
 *              \brief Functions to control the offset of a demo signal
 *
 * Several of the demo signal types support setting the signal offset, but others don't.
 * Use tiepie_hw_oscilloscope_channel_demo_has_offset() to find out whether the selected demo signal type supports setting the offset.
 *
 * By default the offset is set to: 0 Volt.
 */

/**
 * \brief Check whether the currently selected demo signal type supports setting the offset.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if setting the offset is supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_demo_get_offset
 * \see tiepie_hw_oscilloscope_channel_demo_set_offset
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_demo_has_offset(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Get the currently selected demo signal offset of a specified demo oscilloscope channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The currently set demo signal offset, in Volt.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The currently selected demo signal type does not support getting the demo signal offset.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_demo_has_offset
 * \see tiepie_hw_oscilloscope_channel_demo_set_offset
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_demo_get_offset(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Set the demo signal offset of a specified demo oscilloscope channel, in Volt.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] value The requested demo signal offset, in Volt.
 * \return The actually set offset, in Volt.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The currently selected demo signal type does not support setting the demo signal offset.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal offset is not valid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_demo_has_offset
 * \see tiepie_hw_oscilloscope_channel_demo_get_offset
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_demo_set_offset(tiepie_hw_handle handle, uint16_t ch, double value);

/**
 *           \}
 *           \defgroup scp_ch_demo_symmetry Symmetry
 *           \{
 *              \brief Functions to control the symmetry of a demo signal
 *
 * The symmetry of a signal defines the ratio between the length of positive part of a period and
 * the length of the negative part of a period of the generated signal.
 *
 * The symmetry is defined as a number between 0 and 1, where 0 defines a symmetry of 0% (no positive part) and 1 defines a symmetry of 100% (no negative part).
 *
 * Several of the demo signal types support setting the signal symmetry, but others don't.
 * Use tiepie_hw_oscilloscope_channel_demo_has_symmetry() to find out whether the selected demo signal type supports setting the symmetry.
 *
 * By default the symmetry is set to: 0.5 (50%).
 */

/**
 * \brief Check whether the currently selected demo signal type supports setting the symmetry.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if setting the symmetry is supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_demo_get_symmetry
 * \see tiepie_hw_oscilloscope_channel_demo_set_symmetry
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_demo_has_symmetry(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Get the currently selected demo signal symmetry of a specified demo oscilloscope channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The currently set demo signal symmetry, a number between \c 0 and \c 1.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The currently selected demo signal type does not support getting the demo signal symmetry.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_demo_has_symmetry
 * \see tiepie_hw_oscilloscope_channel_demo_set_symmetry
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_demo_get_symmetry(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Set the demo signal symmetry of a specified demo oscilloscope channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] value The requested demo signal symmetry, a number between \c 0 and \c 1.
 * \return The actually set symmetry.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The currently selected demo signal type does not support setting the demo signal symmetry.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal symmetry is not valid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_demo_has_symmetry
 * \see tiepie_hw_oscilloscope_channel_demo_get_symmetry
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_demo_set_symmetry(tiepie_hw_handle handle, uint16_t ch, double value);

/**
 *           \}
 *           \defgroup scp_ch_demo_phase Phase
 *           \{
 *             \brief Functions for controlling the phase of a demo signal.
 *
 * The phase defines the starting point in the period of the signal that is generated, as well as the ending point.
 *
 * The phase is defined as a number between \c 0 and \c 1, where \c 0 defines the beginning of the period (\c 0&deg;)
 * and \c 1 defines the end of the period (\c 360&deg;).
 *
 * Several of the demo signal types support setting the signal phase, but others don't.
 * Use tiepie_hw_oscilloscope_channel_demo_has_phase() to find out whether the selected demo signal type supports setting the phase.
 *
 * By default the phase is set to: \c 0.
 */

/**
 * \brief Check whether the currently selected demo signal type supports setting the phase.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if setting the phase is supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_demo_get_phase
 * \see tiepie_hw_oscilloscope_channel_demo_set_phase
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_demo_has_phase(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Get the currently selected demo signal phase of a specified demo oscilloscope channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The currently set demo signal phase, a number between \c 0 and \c 1.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The currently selected demo signal type does not support getting the demo signal phase.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_demo_has_phase
 * \see tiepie_hw_oscilloscope_channel_demo_set_phase
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_demo_get_phase(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Set the demo signal phase of a specified demo oscilloscope channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] value The requested demo signal phase, a number between \c 0 and \c 1.
 * \return The actually set phase.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The currently selected demo signal type does not support setting the demo signal phase.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal phase is not valid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_demo_has_phase
 * \see tiepie_hw_oscilloscope_channel_demo_get_phase
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_demo_set_phase(tiepie_hw_handle handle, uint16_t ch, double value);

/**
 *           \}
 *           \defgroup scp_ch_demo_noise_enabled NoiseEnabled
 *           \{
 *             \brief Functions for controlling the optional noise of a demo signal.
 *
 * Several of the demo signal types support injecting small noise in the base signal, but others don't.
 * Use tiepie_hw_oscilloscope_channel_demo_has_noise_enabled() to find out whether the selected demo signal type supports injecting small noise.
 */

/**
 * \brief Check whether the selected demo signal type supports injecting small noise.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if injecting small noise is supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_demo_get_noise_enabled
 * \see tiepie_hw_oscilloscope_channel_demo_set_noise_enabled
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_demo_has_noise_enabled(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Get the currently selected noise injection state of a specified demo oscilloscope channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if injecting small noise is enabled, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The currently selected demo signal type does not support noise injection.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_demo_has_noise_enabled
 * \see tiepie_hw_oscilloscope_channel_demo_set_noise_enabled
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_demo_get_noise_enabled(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Set the noise injection state of a specified demo oscilloscope channel.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[in] value #TIEPIE_HW_BOOL_TRUE to enable noise injection, #TIEPIE_HW_BOOL_FALSE to disable noise injection
 * \return The currently selected noise injection state, #TIEPIE_HW_BOOL_TRUE if enabled, \c flase is disabled
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The currently selected demo signal type does not support noise injection.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_demo_has_noise_enabled
 * \see tiepie_hw_oscilloscope_channel_demo_get_noise_enabled
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_demo_set_noise_enabled(tiepie_hw_handle handle, uint16_t ch, tiepie_hw_bool value);

/**
 *           \}
 *         \}
 *       \}
 *       \defgroup scp_data Data
 *       \{
 * \brief Functions to collect the measured data
 *
 * When a measurement is performed, the data is stored inside the instrument.
 * When no \ref scp_timebase_pre_samples "pre samples" are selected (pre sample ratio = 0), the trigger point is located at the start of the record and all samples are measured post samples.
 *
 * When pre samples are selected (pre sample ratio > 0), the trigger point is located at position (pre sample ratio * \ref scp_timebase_record_length "record length"),
 * dividing the record in pre samples and post samples.
 *
 * When after starting the measurement a trigger occurs before all pre samples are measured, not all pre samples will be valid.
 * Invalid pre samples are set to zero.
 * Use #tiepie_hw_oscilloscope_get_valid_pre_sample_count to determine the amount of valid pre samples.
 * See \ref scp_trigger_presamples_valid to force all pre samples to be measured.
 *
 * When retrieving the measured data, the full record can be get, including the invalid presamples.
 * The start index needs to be set to \c 0 then.
 * It is also possible to get only the valid samples.
 * In that case, the start index needs to be set to <tt>(record length - (number of post samples + number of valid pre samples)</tt>.
 *
 * Example:
 *
 * \code{.c}
 * uint64_t Post_samples = llround((1 - tiepie_hw_oscilloscope_get_pre_sample_ratio(h_scp)) * tiepie_hw_oscilloscope_get_record_length(h_scp));
 * uint64_t Valid_samples = Post_samples + tiepie_hw_oscilloscope_get_valid_pre_sample_count(h_scp);
 * uint64_t Start = tiepie_hw_oscilloscope_get_record_length(h_scp) - Valid_samples;
 *
 * uint64_t Samples_read = tiepie_hw_oscilloscope_get_data1Ch(h_scp, Data_ch1, Start, Valid_samples);
 * \endcode
 *
 * The data retrieval functions use buffers to store the measured data in.
 * The caller must assure that enough memory is allocated for the buffer, to contain all data.
 *
 * Several routines are available to get the measured data, one universal applicable routine and a number of dedicated routines,
 * to collect data from specific channels.
 * - #tiepie_hw_oscilloscope_get_data
 * - #tiepie_hw_oscilloscope_get_data_1ch
 * - #tiepie_hw_oscilloscope_get_data_2ch
 * - #tiepie_hw_oscilloscope_get_data_3ch
 * - #tiepie_hw_oscilloscope_get_data_4ch
 * - #tiepie_hw_oscilloscope_get_data_5ch
 * - #tiepie_hw_oscilloscope_get_data_6ch
 * - #tiepie_hw_oscilloscope_get_data_7ch
 * - #tiepie_hw_oscilloscope_get_data_8ch
 *
 * The data is returned directly in Volt, Ampere or Ohm, depending on the \ref scp_ch_coupling "input coupling".
 *
 * Additionally, routines are available to retrieve range information of the measured data.
 * Once a measurement is ready, the input range of a channel can be changed, e.g. by the auto ranging function or by the user.
 * The input range will then no longer match with the range of the measured data.
 * Use these routines to determine the actual range of the measured data.
 * - #tiepie_hw_oscilloscope_channel_get_data_value_range
 * - #tiepie_hw_oscilloscope_channel_get_data_value_min
 * - #tiepie_hw_oscilloscope_channel_get_data_value_max
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the measurement data for specified channels.
 *
 * This routine is used to retrieve measured data from specific channels.
 * It uses an array of pointers to data buffers to indicate from which channels the data must be retrieved.
 * \c NULL pointers can be used to indicate that no data needs to be retrieved for a specific channel.
 *
 * To retrieve data from channels 1 and 2 of the oscilloscope, create a pointer array with two pointers:
 * <tt>{ Data_ch1, Data_ch2 }</tt> and set Channel_count to \c 2.
 *
 * To retrieve data from channels 2 and 4 of the oscilloscope, create a pointer array with four pointers:
 * <tt>{ NULL, Data_ch2, NULL, Data_ch4 }</tt> and set Channel_count to \c 4.
 *
 * The buffers contain data directly in Volt, Ampere or Ohm, depending on the \ref scp_ch_coupling "input coupling".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[out] buffers A pointer to a buffer with pointers to buffers for channel data, the pointer buffer may contain \c NULL pointers.
 * \param[in] channel_count The number of pointers in the pointer buffer.
 * \param[in] start_index The position in the record to start reading.
 * \param[in] sample_count The number of samples to read.
 * \return The number of samples actually read.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>Retrieved less samples than indicated by sample_count.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see hlp_ptrar for programming languages that don't support pointers to pointers, e.g. Matlab or Python.
 * \see tiepie_hw_oscilloscope_get_data1Ch, tiepie_hw_oscilloscope_get_data2Ch, tiepie_hw_oscilloscope_get_data3Ch, tiepie_hw_oscilloscope_get_data4Ch
 *
 * \par Example
 * \code{.c}
 * uint64_t Post_samples = llround((1 - tiepie_hw_oscilloscope_get_pre_sample_ratio(h_scp)) * tiepie_hw_oscilloscope_get_record_length(h_scp));
 * uint64_t Valid_samples = Post_samples + tiepie_hw_oscilloscope_get_valid_pre_sample_count(h_scp);
 * uint64_t Start = tiepie_hw_oscilloscope_get_record_length(h_scp) - Valid_samples;
 *
 * // Allocate memory for active channels:
 * float** pp_channel_data = malloc(sizeof(float*) * Channel_count);
 * for(w_ch = 0 ; Ch < Channel_count ; Ch++)
 *   if(Scp_chGet_enabled(h_scp, Ch))
 *     pp_channel_data[ Ch ] = malloc(sizeof(float) * Valid_samples);
 *   else
 *     pp_channel_data[ Ch ] = NULL;
 *
 * // Get data:
 * uint64_t Samples_read = tiepie_hw_oscilloscope_get_data(h_scp, pp_channel_data, Channel_count, Start, Valid_samples);
 *
 * // do something with the data.
 *
 * // Free memory:
 * for(w_ch = 0 ; Ch < Channel_count ; Ch++)
 *   free(pp_channel_data[ Ch ]);
 * free(pp_channel_data);
 * \endcode
 *
 * \since 1.0
 */
#ifdef INCLUDED_BY_MATLAB
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_data(tiepie_hw_handle handle, void** buffers, uint16_t channel_count, uint64_t start_index, uint64_t sample_count);
#else
# ifdef LIBTIEPIE_HW_DYNAMIC
typedef uint64_t(*tiepie_hw_oscilloscope_get_data_t)(tiepie_hw_handle handle, float** buffers, uint16_t channel_count, uint64_t start_index, uint64_t sample_count);
# else
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_data(tiepie_hw_handle handle, float** buffers, uint16_t channel_count, uint64_t start_index, uint64_t sample_count);
# endif
#endif

/**
 * \brief Get the measurement data for the first channel.
 *
 * The buffers contain data directly in Volt, Ampere or Ohm, depending on the \ref scp_ch_coupling "input coupling".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[out] buffer_ch1 A pointer to the buffer for channel 1 data or \c NULL.
 * \param[in] start_index The psition in the record to start reading.
 * \param[in] sample_count The number of samples to read.
 * \return The number of samples actually read.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>Retrieved less samples than indicated by sample_count.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_data
 * \see tiepie_hw_oscilloscope_get_data_2ch
 * \see tiepie_hw_oscilloscope_get_data_3ch
 * \see tiepie_hw_oscilloscope_get_data_4ch
 * \see tiepie_hw_oscilloscope_get_data_5ch
 * \see tiepie_hw_oscilloscope_get_data_6ch
 * \see tiepie_hw_oscilloscope_get_data_7ch
 * \see tiepie_hw_oscilloscope_get_data_8ch
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_data_1ch(tiepie_hw_handle handle, float* buffer_ch1, uint64_t start_index, uint64_t sample_count);

/**
 * \brief Get the measurement data for the first two channels.
 *
 * The buffers contain data directly in Volt, Ampere or Ohm, depending on the \ref scp_ch_coupling "input coupling".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[out] buffer_ch1 A pointer to the buffer for channel 1 data or \c NULL.
 * \param[out] buffer_ch2 A pointer to the buffer for channel 2 data or \c NULL.
 * \param[in] start_index The position in the record to start reading.
 * \param[in] sample_count The number of samples to read.
 * \return The number of samples actually read.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>Retrieved less samples than indicated by sample_count.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_data
 * \see tiepie_hw_oscilloscope_get_data_1ch
 * \see tiepie_hw_oscilloscope_get_data_3ch
 * \see tiepie_hw_oscilloscope_get_data_4ch
 * \see tiepie_hw_oscilloscope_get_data_5ch
 * \see tiepie_hw_oscilloscope_get_data_6ch
 * \see tiepie_hw_oscilloscope_get_data_7ch
 * \see tiepie_hw_oscilloscope_get_data_8ch
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_data_2ch(tiepie_hw_handle handle, float* buffer_ch1, float* buffer_ch2, uint64_t start_index, uint64_t sample_count);

/**
 * \brief Get the measurement data for the first three channels.
 *
 * The buffers contain data directly in Volt, Ampere or Ohm, depending on the \ref scp_ch_coupling "input coupling".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[out] buffer_ch1 A pointer to the buffer for channel 1 data or \c NULL.
 * \param[out] buffer_ch2 A pointer to the buffer for channel 2 data or \c NULL.
 * \param[out] buffer_ch3 A pointer to the buffer for channel 3 data or \c NULL.
 * \param[in] start_index The position in the record to start reading.
 * \param[in] sample_count The number of samples to read.
 * \return The number of samples actually read.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>Retrieved less samples than indicated by sample_count.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_data
 * \see tiepie_hw_oscilloscope_get_data_1ch
 * \see tiepie_hw_oscilloscope_get_data_2ch
 * \see tiepie_hw_oscilloscope_get_data_4ch
 * \see tiepie_hw_oscilloscope_get_data_5ch
 * \see tiepie_hw_oscilloscope_get_data_6ch
 * \see tiepie_hw_oscilloscope_get_data_7ch
 * \see tiepie_hw_oscilloscope_get_data_8ch
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_data_3ch(tiepie_hw_handle handle, float* buffer_ch1, float* buffer_ch2, float* buffer_ch3, uint64_t start_index, uint64_t sample_count);

/**
 * \brief Get the measurement data for the first four channels.
 *
 * The buffers contain data directly in Volt, Ampere or Ohm, depending on the \ref scp_ch_coupling "input coupling".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[out] buffer_ch1 A pointer to the buffer for channel 1 data or \c NULL.
 * \param[out] buffer_ch2 A pointer to the buffer for channel 2 data or \c NULL.
 * \param[out] buffer_ch3 A pointer to the buffer for channel 3 data or \c NULL.
 * \param[out] buffer_ch4 A pointer to the buffer for channel 4 data or \c NULL.
 * \param[in] start_index The position in the record to start reading.
 * \param[in] sample_count The number of samples to read.
 * \return The number of samples actually read.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>Retrieved less samples than indicated by sample_count.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_data
 * \see tiepie_hw_oscilloscope_get_data_1ch
 * \see tiepie_hw_oscilloscope_get_data_2ch
 * \see tiepie_hw_oscilloscope_get_data_3ch
 * \see tiepie_hw_oscilloscope_get_data_5ch
 * \see tiepie_hw_oscilloscope_get_data_6ch
 * \see tiepie_hw_oscilloscope_get_data_7ch
 * \see tiepie_hw_oscilloscope_get_data_8ch
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_data_4ch(tiepie_hw_handle handle, float* buffer_ch1, float* buffer_ch2, float* buffer_ch3, float* buffer_ch4, uint64_t start_index, uint64_t sample_count);

/**
 * \brief Get the measurement data for the first five channels.
 *
 * The buffers contain data directly in Volt, Ampere or Ohm, depending on the \ref scp_ch_coupling "input coupling".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[out] buffer_ch1 A pointer to the buffer for channel 1 data or \c NULL.
 * \param[out] buffer_ch2 A pointer to the buffer for channel 2 data or \c NULL.
 * \param[out] buffer_ch3 A pointer to the buffer for channel 3 data or \c NULL.
 * \param[out] buffer_ch4 A pointer to the buffer for channel 4 data or \c NULL.
 * \param[out] buffer_ch5 A pointer to the buffer for channel 5 data or \c NULL.
 * \param[in] start_index The position in the record to start reading.
 * \param[in] sample_count The number of samples to read.
 * \return The number of samples actually read.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>Retrieved less samples than indicated by sample_count.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_data
 * \see tiepie_hw_oscilloscope_get_data_1ch
 * \see tiepie_hw_oscilloscope_get_data_2ch
 * \see tiepie_hw_oscilloscope_get_data_3ch
 * \see tiepie_hw_oscilloscope_get_data_4ch
 * \see tiepie_hw_oscilloscope_get_data_6ch
 * \see tiepie_hw_oscilloscope_get_data_7ch
 * \see tiepie_hw_oscilloscope_get_data_8ch
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_data_5ch(tiepie_hw_handle handle, float* buffer_ch1, float* buffer_ch2, float* buffer_ch3, float* buffer_ch4, float* buffer_ch5, uint64_t start_index, uint64_t sample_count);

/**
 * \brief Get the measurement data for the first six channels.
 *
 * The buffers contain data directly in Volt, Ampere or Ohm, depending on the \ref scp_ch_coupling "input coupling".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[out] buffer_ch1 A pointer to the buffer for channel 1 data or \c NULL.
 * \param[out] buffer_ch2 A pointer to the buffer for channel 2 data or \c NULL.
 * \param[out] buffer_ch3 A pointer to the buffer for channel 3 data or \c NULL.
 * \param[out] buffer_ch4 A pointer to the buffer for channel 4 data or \c NULL.
 * \param[out] buffer_ch5 A pointer to the buffer for channel 5 data or \c NULL.
 * \param[out] buffer_ch6 A pointer to the buffer for channel 6 data or \c NULL.
 * \param[in] start_index The position in the record to start reading.
 * \param[in] sample_count The number of samples to read.
 * \return The number of samples actually read.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>Retrieved less samples than indicated by sample_count.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_data
 * \see tiepie_hw_oscilloscope_get_data_1ch
 * \see tiepie_hw_oscilloscope_get_data_2ch
 * \see tiepie_hw_oscilloscope_get_data_3ch
 * \see tiepie_hw_oscilloscope_get_data_4ch
 * \see tiepie_hw_oscilloscope_get_data_5ch
 * \see tiepie_hw_oscilloscope_get_data_7ch
 * \see tiepie_hw_oscilloscope_get_data_8ch
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_data_6ch(tiepie_hw_handle handle, float* buffer_ch1, float* buffer_ch2, float* buffer_ch3, float* buffer_ch4, float* buffer_ch5, float* buffer_ch6, uint64_t start_index, uint64_t sample_count);

/**
 * \brief Get the measurement data for the first seven channels.
 *
 * The buffers contain data directly in Volt, Ampere or Ohm, depending on the \ref scp_ch_coupling "input coupling".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[out] buffer_ch1 A pointer to the buffer for channel 1 data or \c NULL.
 * \param[out] buffer_ch2 A pointer to the buffer for channel 2 data or \c NULL.
 * \param[out] buffer_ch3 A pointer to the buffer for channel 3 data or \c NULL.
 * \param[out] buffer_ch4 A pointer to the buffer for channel 4 data or \c NULL.
 * \param[out] buffer_ch5 A pointer to the buffer for channel 5 data or \c NULL.
 * \param[out] buffer_ch6 A pointer to the buffer for channel 6 data or \c NULL.
 * \param[out] buffer_ch7 A pointer to the buffer for channel 7 data or \c NULL.
 * \param[in] start_index The position in the record to start reading.
 * \param[in] sample_count The number of samples to read.
 * \return The number of samples actually read.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>Retrieved less samples than indicated by sample_count.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_data
 * \see tiepie_hw_oscilloscope_get_data_1ch
 * \see tiepie_hw_oscilloscope_get_data_2ch
 * \see tiepie_hw_oscilloscope_get_data_3ch
 * \see tiepie_hw_oscilloscope_get_data_4ch
 * \see tiepie_hw_oscilloscope_get_data_5ch
 * \see tiepie_hw_oscilloscope_get_data_6ch
 * \see tiepie_hw_oscilloscope_get_data_8ch
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_data_7ch(tiepie_hw_handle handle, float* buffer_ch1, float* buffer_ch2, float* buffer_ch3, float* buffer_ch4, float* buffer_ch5, float* buffer_ch6, float* buffer_ch7, uint64_t start_index, uint64_t sample_count);

/**
 * \brief Get the measurement data for the first eight channels.
 *
 * The buffers contain data directly in Volt, Ampere or Ohm, depending on the \ref scp_ch_coupling "input coupling".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[out] buffer_ch1 A pointer to the buffer for channel 1 data or \c NULL.
 * \param[out] buffer_ch2 A pointer to the buffer for channel 2 data or \c NULL.
 * \param[out] buffer_ch3 A pointer to the buffer for channel 3 data or \c NULL.
 * \param[out] buffer_ch4 A pointer to the buffer for channel 4 data or \c NULL.
 * \param[out] buffer_ch5 A pointer to the buffer for channel 5 data or \c NULL.
 * \param[out] buffer_ch6 A pointer to the buffer for channel 6 data or \c NULL.
 * \param[out] buffer_ch7 A pointer to the buffer for channel 7 data or \c NULL.
 * \param[out] buffer_ch8 A pointer to the buffer for channel 8 data or \c NULL.
 * \param[in] start_index The position in the record to start reading.
 * \param[in] sample_count The number of samples to read.
 * \return The number of samples actually read.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>Retrieved less samples than indicated by sample_count.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_data
 * \see tiepie_hw_oscilloscope_get_data_1ch
 * \see tiepie_hw_oscilloscope_get_data_2ch
 * \see tiepie_hw_oscilloscope_get_data_3ch
 * \see tiepie_hw_oscilloscope_get_data_4ch
 * \see tiepie_hw_oscilloscope_get_data_5ch
 * \see tiepie_hw_oscilloscope_get_data_6ch
 * \see tiepie_hw_oscilloscope_get_data_7ch
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_data_8ch(tiepie_hw_handle handle, float* buffer_ch1, float* buffer_ch2, float* buffer_ch3, float* buffer_ch4, float* buffer_ch5, float* buffer_ch6, float* buffer_ch7, float* buffer_ch8, uint64_t start_index, uint64_t sample_count);

/**
 * \brief Get the number of valid pre samples in the measurement.
 *
 * When pre samples are selected (pre sample ratio > 0), the trigger point is located at position (pre sample ratio * \ref scp_timebase_record_length "record length"),
 * dividing the record in pre samples and post samples.
 *
 * When after starting the measurement a trigger occurs before all presamples are measured, not all pre samples will be valid.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The number of valid pre samples.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_valid_pre_sample_count(tiepie_hw_handle handle);

/**
 * \brief Get the minimum and maximum values of the input range the current data was measured with.
 *
 * The buffers contain the minimum and maximum values of the input range directly in Volt, Ampere or Ohm, depending on the \ref scp_ch_coupling "input coupling".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[out] min A pointer to a buffer for the minimum value of the range or \c NULL.
 * \param[out] max A pointer to a buffer for the maximum value of the range or \c NULL.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_get_data_value_min
 * \see tiepie_hw_oscilloscope_channel_get_data_value_max
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_oscilloscope_channel_get_data_value_range(tiepie_hw_handle handle, uint16_t ch, double* min, double* max);

/**
 * \brief Get the minimum value of the input range the current data was measured with.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The minimum value of the input range the current data was measured with, in Volt, Ampere or Ohm, depending on the \ref scp_ch_coupling "input coupling".
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_get_data_value_max
 * \see tiepie_hw_oscilloscope_channel_get_data_value_range
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_get_data_value_min(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Get the maximum value of the input range the current data was measured with.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch The channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return The maximum value of the input range the current data was measured with, in Volt, Ampere or Ohm, depending on the \ref scp_ch_coupling "input coupling".
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_get_data_value_min
 * \see tiepie_hw_oscilloscope_channel_get_data_value_range
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_channel_get_data_value_max(tiepie_hw_handle handle, uint16_t ch);

/**
 *         \cond EXTENDED_API
 *         \defgroup scp_data_raw Raw
 *         \{
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get raw measurement data.
 *
 * \param[in] handle A \ref Open_dev "device handle".
 * \param[out] buffers Pointer to buffer with pointers to buffer for channel data, pointer buffer may contain \c NULL pointers.
 * \param[in] channel_count Number of pointers in pointer buffer.
 * \param[in] start_index Position in record to start reading.
 * \param[in] sample_count Number of samples to read.
 * \return Number of samples read.
 * \see hlp_ptrar
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_data_raw(tiepie_hw_handle handle, void** buffers, uint16_t channel_count, uint64_t start_index, uint64_t sample_count);

/**
 * \brief Get raw measurement data.
 *
 * \param[in] handle A \ref Open_dev "device handle".
 * \param[out] buffer_ch1 Pointer to buffer for channel 1 data or \c NULL.
 * \param[in] start_index Position in record to start reading.
 * \param[in] sample_count Number of samples to read.
 * \return Number of samples read.
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_data_raw_1ch(tiepie_hw_handle handle, void* buffer_ch1, uint64_t start_index, uint64_t sample_count);

/**
 * \brief Get raw measurement data.
 *
 * \param[in] handle A \ref Open_dev "device handle".
 * \param[out] buffer_ch1 Pointer to buffer for channel 1 data or \c NULL.
 * \param[out] buffer_ch2 Pointer to buffer for channel 2 data or \c NULL.
 * \param[in] start_index Position in record to start reading.
 * \param[in] sample_count Number of samples to read.
 * \return Number of samples read.
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_data_raw_2ch(tiepie_hw_handle handle, void* buffer_ch1, void* buffer_ch2, uint64_t start_index, uint64_t sample_count);

/**
 * \brief Get raw measurement data.
 *
 * \param[in] handle A \ref Open_dev "device handle".
 * \param[out] buffer_ch1 Pointer to buffer for channel 1 data or \c NULL.
 * \param[out] buffer_ch2 Pointer to buffer for channel 2 data or \c NULL.
 * \param[out] buffer_ch3 Pointer to buffer for channel 3 data or \c NULL.
 * \param[in] start_index Position in record to start reading.
 * \param[in] sample_count Number of samples to read.
 * \return Number of samples read.
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_data_raw_3ch(tiepie_hw_handle handle, void* buffer_ch1, void* buffer_ch2, void* buffer_ch3, uint64_t start_index, uint64_t sample_count);

/**
 * \brief Get raw measurement data.
 *
 * \param[in] handle A \ref Open_dev "device handle".
 * \param[out] buffer_ch1 Pointer to buffer for channel 1 data or \c NULL.
 * \param[out] buffer_ch2 Pointer to buffer for channel 2 data or \c NULL.
 * \param[out] buffer_ch3 Pointer to buffer for channel 3 data or \c NULL.
 * \param[out] buffer_ch4 Pointer to buffer for channel 4 data or \c NULL.
 * \param[in] start_index Position in record to start reading.
 * \param[in] sample_count Number of samples to read.
 * \return Number of samples read.
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_data_raw_4ch(tiepie_hw_handle handle, void* buffer_ch1, void* buffer_ch2, void* buffer_ch3, void* buffer_ch4, uint64_t start_index, uint64_t sample_count);

/**
 * \brief Get raw measurement data.
 *
 * \param[in] handle A \ref Open_dev "device handle".
 * \param[out] buffer_ch1 Pointer to buffer for channel 1 data or \c NULL.
 * \param[out] buffer_ch2 Pointer to buffer for channel 2 data or \c NULL.
 * \param[out] buffer_ch3 Pointer to buffer for channel 3 data or \c NULL.
 * \param[out] buffer_ch4 Pointer to buffer for channel 4 data or \c NULL.
 * \param[out] buffer_ch5 Pointer to buffer for channel 5 data or \c NULL.
 * \param[in] start_index Position in record to start reading.
 * \param[in] sample_count Number of samples to read.
 * \return Number of samples read.
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_data_raw_5ch(tiepie_hw_handle handle, void* buffer_ch1, void* buffer_ch2, void* buffer_ch3, void* buffer_ch4, void* buffer_ch5, uint64_t start_index, uint64_t sample_count);

/**
 * \brief Get raw measurement data.
 *
 * \param[in] handle A \ref Open_dev "device handle".
 * \param[out] buffer_ch1 Pointer to buffer for channel 1 data or \c NULL.
 * \param[out] buffer_ch2 Pointer to buffer for channel 2 data or \c NULL.
 * \param[out] buffer_ch3 Pointer to buffer for channel 3 data or \c NULL.
 * \param[out] buffer_ch4 Pointer to buffer for channel 4 data or \c NULL.
 * \param[out] buffer_ch5 Pointer to buffer for channel 5 data or \c NULL.
 * \param[out] buffer_ch6 Pointer to buffer for channel 6 data or \c NULL.
 * \param[in] start_index Position in record to start reading.
 * \param[in] sample_count Number of samples to read.
 * \return Number of samples read.
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_data_raw_6ch(tiepie_hw_handle handle, void* buffer_ch1, void* buffer_ch2, void* buffer_ch3, void* buffer_ch4, void* buffer_ch5, void* buffer_ch6, uint64_t start_index, uint64_t sample_count);

/**
 * \brief Get raw measurement data.
 *
 * \param[in] handle A \ref Open_dev "device handle".
 * \param[out] buffer_ch1 Pointer to buffer for channel 1 data or \c NULL.
 * \param[out] buffer_ch2 Pointer to buffer for channel 2 data or \c NULL.
 * \param[out] buffer_ch3 Pointer to buffer for channel 3 data or \c NULL.
 * \param[out] buffer_ch4 Pointer to buffer for channel 4 data or \c NULL.
 * \param[out] buffer_ch5 Pointer to buffer for channel 5 data or \c NULL.
 * \param[out] buffer_ch6 Pointer to buffer for channel 6 data or \c NULL.
 * \param[out] buffer_ch7 Pointer to buffer for channel 7 data or \c NULL.
 * \param[in] start_index Position in record to start reading.
 * \param[in] sample_count Number of samples to read.
 * \return Number of samples read.
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_data_raw_7ch(tiepie_hw_handle handle, void* buffer_ch1, void* buffer_ch2, void* buffer_ch3, void* buffer_ch4, void* buffer_ch5, void* buffer_ch6, void* buffer_ch7, uint64_t start_index, uint64_t sample_count);

/**
 * \brief Get raw measurement data.
 *
 * \param[in] handle A \ref Open_dev "device handle".
 * \param[out] buffer_ch1 Pointer to buffer for channel 1 data or \c NULL.
 * \param[out] buffer_ch2 Pointer to buffer for channel 2 data or \c NULL.
 * \param[out] buffer_ch3 Pointer to buffer for channel 3 data or \c NULL.
 * \param[out] buffer_ch4 Pointer to buffer for channel 4 data or \c NULL.
 * \param[out] buffer_ch5 Pointer to buffer for channel 5 data or \c NULL.
 * \param[out] buffer_ch6 Pointer to buffer for channel 6 data or \c NULL.
 * \param[out] buffer_ch7 Pointer to buffer for channel 7 data or \c NULL.
 * \param[out] buffer_ch8 Pointer to buffer for channel 8 data or \c NULL.
 * \param[in] start_index Position in record to start reading.
 * \param[in] sample_count Number of samples to read.
 * \return Number of samples read.
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_data_raw_8ch(tiepie_hw_handle handle, void* buffer_ch1, void* buffer_ch2, void* buffer_ch3, void* buffer_ch4, void* buffer_ch5, void* buffer_ch6, void* buffer_ch7, void* buffer_ch8, uint64_t start_index, uint64_t sample_count);

/**
 * \brief Get raw data type.
 *
 * \param[in] handle A \ref Open_dev "device handle".
 * \param[in] ch Channel number, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return \ref DATARAWTYPE_ "Raw data type".
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_channel_get_data_raw_type(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Get possible raw data minimum, equal to zero and maximum values.
 *
 * \param[in] handle A \ref Open_dev "device handle".
 * \param[in] ch Channel number, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \param[out] min Pointer to buffer for possible minimum raw data value, or \c NULL.
 * \param[out] Zero Pointer to buffer for equal to zero raw data value, or \c NULL.
 * \param[out] max Pointer to buffer for possible maximum raw data value, or \c NULL.
 * \see tiepie_hw_oscilloscope_channel_get_data_raw_value_min
 * \see tiepie_hw_oscilloscope_channel_get_data_raw_value_zero
 * \see tiepie_hw_oscilloscope_channel_get_data_raw_value_max
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_oscilloscope_channel_get_data_raw_value_range(tiepie_hw_handle handle, uint16_t ch, int64_t* min, int64_t* zero, int64_t* max);

/**
 * \brief Get possible raw data minimum value.
 *
 * \param[in] handle A \ref Open_dev "device handle".
 * \param[in] ch Channel number, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return Possible raw data minimum value.
 * \see tiepie_hw_oscilloscope_channel_get_data_raw_value_zero
 * \see tiepie_hw_oscilloscope_channel_get_data_raw_value_max
 * \see tiepie_hw_oscilloscope_channel_get_data_raw_value_range
 * \since 1.0
 */
TIEPIE_HW_API int64_t tiepie_hw_oscilloscope_channel_get_data_raw_value_min(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Get raw data value which equals zero.
 *
 * \param[in] handle A \ref Open_dev "device handle".
 * \param[in] ch Channel number, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return Raw data value which equals zero.
 * \see tiepie_hw_oscilloscope_channel_get_data_raw_value_min
 * \see tiepie_hw_oscilloscope_channel_get_data_raw_value_max
 * \see tiepie_hw_oscilloscope_channel_get_data_raw_value_range
 * \since 1.0
 */
TIEPIE_HW_API int64_t tiepie_hw_oscilloscope_channel_get_data_raw_value_zero(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Get possible raw data maximum value.
 *
 * \param[in] handle A \ref Open_dev "device handle".
 * \param[in] ch Channel number, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return Possible raw data maximum value.
 * \see tiepie_hw_oscilloscope_channel_get_data_raw_value_min
 * \see tiepie_hw_oscilloscope_channel_get_data_raw_value_zero
 * \see tiepie_hw_oscilloscope_channel_get_data_raw_value_range
 * \since 1.0
 */
TIEPIE_HW_API int64_t tiepie_hw_oscilloscope_channel_get_data_raw_value_max(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Check whether the ranges maximum is reachable.
 *
 * \param[in] handle A \ref Open_dev "device handle".
 * \param[in] ch Channel number, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if reachable, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_is_range_max_reachable(tiepie_hw_handle handle, uint16_t ch);

/**
 *         \}
 *         \endcond
 *       \}
 *       \defgroup scp_measurements Measurements
 *       \{
 *         \brief Functions to perform measurements.
 *
 * Oscilloscopes can measure in block mode or in streaming mode. This is determined by the \ref scp_measurements_mode "measure mode".
 *
 * Several \ref scp_measurements_status "polling routines" and \ref obj_callbacks "callbacks" are available to determine the measurement status.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Start a single measurement.
 *
 * Use the measurement status \ref scp_measurements_status "functions" or \ref obj_callbacks "callbacks" to determine the status of a running measurement.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return #TIEPIE_HW_BOOL_TRUE if the measurement is started, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td>The measurement could not be started.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_MEASUREMENT_RUNNING</td>    <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_start(tiepie_hw_handle handle);

/**
 * \brief Stop a running measurement.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return #TIEPIE_HW_BOOL_TRUE if the measurement is aborted, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td>The measurement could not be stopped.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_stop(tiepie_hw_handle handle);

/**
 * \brief Force a trigger.
 *
 * If the trigger conditions are set in such a way that the input signal(s) will never meet the trigger settings,
 * the instrument will wait forever.
 * Use this function to force a trigger, independent from the input signal(s).
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return #TIEPIE_HW_BOOL_TRUE if succeeded, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td>The trigger could not be forced.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The oscilloscope does not support force trigger.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \return #TIEPIE_HW_BOOL_TRUE if succeeded, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_force_trigger(tiepie_hw_handle handle);

/**
 *         \defgroup scp_measurements_mode Mode
 *         \{
 *           \brief Functions for controlling the measure mode.
 *
 * Oscilloscopes measure in block mode or in streaming mode.
 * This is determined by the \ref scp_measurements_mode "measure mode".
 *
 * \section tiepie_hw_oscilloscope_measurements_block Block mode
 *
 * When measuring in <b>block mode</b> (#TIEPIE_HW_MM_BLOCK), the oscilloscope uses its internal memory to store the measured data.
 * Once the pre defined number of samples is measured, measuring stops and the computer is notified that the measurement is ready.
 * The computer can collect the data and can then start a new measurement. There will be gaps between consecutive measurements.
 *
 * Advantage of block mode: Fast measurements using a high \ref scp_timebase_sample_rate "sample rate" are possible.
 * Disadvantage of block mode: \ref scp_timebase_record_length "Record length" is limited by the instrument's memory size.
 *
 * \section tiepie_hw_oscilloscope_measurements_streaming Streaming mode
 *
 * When measuring in <b>streaming mode</b> (#TIEPIE_HW_MM_STREAM), the measured data is transferred continuously to the computer and collected in a buffer,
 * while the instrument remains measuring.
 * When a pre defined number of samples has been collected in the buffer, libtiepie-hw will notify the calling application that a new chunk of data
 * is available to be collected.
 * The calling application can then get that chunk of data and add it to previously collected data.
 * This makes it possible to perform long continuous measurements without gaps.
 *
 * Advantage of streaming mode: very long measurements are posible.
 * Disadvantage of streaming mode: the maximum sample rate is limited by number of \ref scp_ch_enabled "enabled channels",
 * the selected \ref scp_resolution "resolution", the data transfer rate to computer and the computer speed.
 *
 * The size of the chunks is set using tiepie_hw_oscilloscope_set_record_length().
 * The combination of chunk size and \ref scp_timebase_sample_rate "sample rate" determines the duration of a chunk and also the rate
 * at wich chunks are measured and need to be transferred.
 * When the computer can not keep up with the chunk rate and chunks are measured faster than the computer can process them,
 * the running measurement will be stopped and tiepie_hw_oscilloscope_is_data_overflow() will return #TIEPIE_HW_BOOL_TRUE and \ref obj_callbacks "event callback" will be triggered.
 *
 * By default the measure mode is set to: Block mode (#TIEPIE_HW_MM_BLOCK).
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the supported measure modes for a specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The supported measure modes, a set of OR-ed \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" values.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_measure_mode
 * \see tiepie_hw_oscilloscope_set_measure_mode
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_get_measure_modes(tiepie_hw_handle handle);

/**
 * \brief Get the current measure mode.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The currently selected measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_measure_modes
 * \see tiepie_hw_oscilloscope_set_measure_mode
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_get_measure_mode(tiepie_hw_handle handle);

/**
 * \brief Set the measure mode.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] value The required measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \return The actually set measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \remark Changing the measure mode may affect the \ref scp_timebase_sample_rate "sample rate" and/or \ref scp_timebase_record_length "record length".
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested measure mode is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_measure_modes
 * \see tiepie_hw_oscilloscope_get_measure_mode
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_set_measure_mode(tiepie_hw_handle handle, uint32_t value);

/**
 *         \}
 *         \defgroup scp_measurements_status Status
 *         \{
 *           \brief Functions to check the measurement status.
 *
 * These are all functions to poll the measurement status.
 * For some statuses also \ref obj_callbacks "callbacks" are available.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether the oscilloscope is currently measuring.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return #TIEPIE_HW_BOOL_TRUE if oscilloscope is measuring, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_is_running(tiepie_hw_handle handle);

/**
 * \brief Check whether the oscilloscope has triggered.
 *
 * Once a measurement is ready, the triggered status can be checked to determine whether the oscilloscope was triggered.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return #TIEPIE_HW_BOOL_TRUE if oscilloscope has triggered, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_is_timeout_triggered
 * \see tiepie_hw_oscilloscope_is_force_triggered
 * \see tiepie_hw_oscilloscope_channel_trigger_is_triggered
 * \see tiepie_hw_oscilloscope_trigger_input_is_triggered
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_is_triggered(tiepie_hw_handle handle);

/**
 * \brief  Check whether the trigger was caused by the trigger time out.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return #TIEPIE_HW_BOOL_TRUE if the trigger was caused by the \ref scp_trigger_time_out "trigger time out", #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_is_triggered
 * \see tiepie_hw_oscilloscope_is_force_triggered
 * \see tiepie_hw_oscilloscope_channel_trigger_is_triggered
 * \see tiepie_hw_oscilloscope_trigger_input_is_triggered
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_is_timeout_triggered(tiepie_hw_handle handle);

/**
 * \brief Check whether the trigger was caused by tiepie_hw_oscilloscope_force_trigger.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return #TIEPIE_HW_BOOL_TRUE if the trigger was caused by tiepie_hw_oscilloscope_force_trigger, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_is_triggered
 * \see tiepie_hw_oscilloscope_is_timeout_triggered
 * \see tiepie_hw_oscilloscope_channel_trigger_is_triggered
 * \see tiepie_hw_oscilloscope_trigger_input_is_triggered
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_is_force_triggered(tiepie_hw_handle handle);

/**
 * \brief Check whether new, unread measured data is available.
 *
 * When measuring in \ref tiepie_hw_oscilloscope_measurements_block "block mode", the data ready status is set when the measurement is ready and the measured data is
 * available.
 *
 * When measuring in \ref tiepie_hw_oscilloscope_measurements_streaming "streaming mode", the data ready status is set when one or more new chunks of data are available.
 *
 * The status is cleared by getting the data, using one of the \ref scp_data "Scp_get_data*" routines.
 * If more than one chunk of unread data is available, multiple calls to tiepie_hw_oscilloscope_get_data* are required to clear the status.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return #TIEPIE_HW_BOOL_TRUE if new measured data is available, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see notification scp_callbacks_data_ready
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_is_data_ready(tiepie_hw_handle handle);

/**
 * \brief Check whether a data overflow has occurred.
 *
 * During measuring in \ref tiepie_hw_oscilloscope_measurements_streaming "streaming mode", new chunks of measured data will become available.
 * When these chunks are not read fast enough, the number of available chunks will increase.
 * When the available buffer space for these chunks is full, the streaming measurement will be aborted and the data overflow status will be set.
 * The chunks of data that were already buffered, remain available to be read.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return #TIEPIE_HW_BOOL_TRUE if overflow occurred, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see notification scp_callbacks_data_overflow
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_is_data_overflow(tiepie_hw_handle handle);

/**
 *         \}
 *       \}
 *       \defgroup scp_resolution Resolution
 *       \{
 *         \brief Functions to control the oscilloscope resolution.
 *
 * The resolution determines how accurate the amplitude of a signal can be measured.
 * The higher the resolution, the more accurate the input signal can be reconstructed.
 *
 * devices can support multiple resolutions, use tiepie_hw_oscilloscope_get_resolutions() to determine the available resolutions for a device.
 *
 * Besides native hardware resolutions, also enhanced resolutions can be available for a device.
 * Use tiepie_hw_oscilloscope_is_resolution_enhanced() to determine whether the current resolution is a native hardware resolution or an enhanced resolution.
 *
 * The resolution can be set manually, but can also be set automatically, when \ref scp_resolution_mode "auto resolution mode" is enabled.
 *
 *         \defgroup scp_resolution_mode Auto resolution mode
 *         \{
 *           \brief Functions to control the auto resolution mode.
 *
 * The resolution can be set manually, but can also be set automatically, based on the selected \ref scp_timebase_sample_rate
 * "sample rate".
 * Use tiepie_hw_oscilloscope_get_auto_resolution_modes() to determine the available auto resolution modes.
 * Possible auto resolution modes are:
 * - #TIEPIE_HW_ARM_DISABLED : Resolution does not automatically change.
 * - #TIEPIE_HW_ARM_NATIVEONLY : Highest possible native resolution for the current sample rate is used.
 * - #TIEPIE_HW_ARM_ALL : Highest possible native or enhanced resolution for the current sample rate is used.
 *
 * When auto resolution mode is set to #TIEPIE_HW_ARM_DISABLED, the selected resolution will determine the maximum available sample rate
 * of the oscilloscope.
 * When auto resolution mode is enabled, the selected sample rate will determine the resolution of the oscilloscope.
 *
 * Changing the sample rate may change the resolution if auto resolution mode is #TIEPIE_HW_ARM_NATIVEONLY or #TIEPIE_HW_ARM_ALL.
 *
 * Manually setting a resolution will set auto resolution mode to #TIEPIE_HW_ARM_DISABLED.
 *
 * By default the auto resolution mode is set to #TIEPIE_HW_ARM_DISABLED for the Handyprobe HP3 and to #TIEPIE_HW_ARM_NATIVEONLY for all other supported
 * instruments.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the supported auto resolution modes of the specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The supported auto resolution modes, a set of OR-ed \ref TIEPIE_HW_ARM_ "TIEPIE_HW_ARM_*" values, #TIEPIE_HW_ARM_DISABLED when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_auto_resolution_mode
 * \see tiepie_hw_oscilloscope_set_auto_resolution_mode
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_get_auto_resolution_modes(tiepie_hw_handle handle);

/**
 * \brief Get the current auto resolution mode of the specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The currently selected auto resolution mode, a \ref TIEPIE_HW_ARM_ "TIEPIE_HW_ARM_*" value, #TIEPIE_HW_ARM_UNKNOWN when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>Auto resolution is not supported by the hardware.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_auto_resolution_modes
 * \see tiepie_hw_oscilloscope_set_auto_resolution_mode
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_get_auto_resolution_mode(tiepie_hw_handle handle);

/**
 * \brief Set the auto resolution mode of the specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] value The required auto resolution mode, a \ref TIEPIE_HW_ARM_ "TIEPIE_HW_ARM_*" value.
 * \return The actually set auto resolution mode, a \ref TIEPIE_HW_ARM_ "TIEPIE_HW_ARM_*" value, #TIEPIE_HW_ARM_UNKNOWN when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>Auto resolution is not supported by the hardware.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_auto_resolution_modes
 * \see tiepie_hw_oscilloscope_get_auto_resolution_mode
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_set_auto_resolution_mode(tiepie_hw_handle handle, uint32_t value);

/**
 *         \}
 */

/**
 * \brief Get an array with the supported resolutions of the specified oscilloscope.
 *
 * The caller must assure that the array is available and that enough memory is allocated.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[out] list A pointer to an array to contain the supported resolutions, or \c NULL.
 * \param[in] length The number of elements in the array.
 * \return Total number of supported resolutions, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 *
 * \par Example
 * \code{.c}
 * uint8_t Resolution_count = tiepie_hw_oscilloscope_get_resolutions(h_device, NULL, 0);
 * uint8_t* Resolutions = malloc(sizeof(uint8_t) * Resolution_count);
 * Resolution_count = tiepie_hw_oscilloscope_get_resolutions(h_device, Resolutions, Resolution_count);
 *
 * printf("Scp_get_resolutions:\n");
 * for(i = 0 ; i < Resolution_count ; i++)
 *   printf("- %u bits\n", Resolutions[ i ]);
 *
 * free(p_resolutions);
 * \endcode
 * \see tiepie_hw_oscilloscope_get_resolution
 * \see tiepie_hw_oscilloscope_set_resolution
 *
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_get_resolutions(tiepie_hw_handle handle, uint8_t* list, uint32_t length);

/**
 * \brief Get the current resolution of the specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The current resolution in bits, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_resolutions
 * \see tiepie_hw_oscilloscope_set_resolution
 * \since 1.0
 */
TIEPIE_HW_API uint8_t tiepie_hw_oscilloscope_get_resolution(tiepie_hw_handle handle);

/**
 * \brief Set the resolution of the specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] value The required resolution in bits.
 * \return The actually set resolution in bits, or \c 0 when unsuccessful.
 * \remark Changing the resolution may affect the \ref scp_timebase_sample_rate "sample rate", \ref scp_timebase_record_length "record length" and/or \ref scp_ch_tr_enabled "channel trigger enabled".
 * \remark Setting the resolution will set auto resolution mode to #TIEPIE_HW_ARM_DISABLED.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_resolutions
 * \see tiepie_hw_oscilloscope_get_resolution
 * \since 1.0
 */
TIEPIE_HW_API uint8_t tiepie_hw_oscilloscope_set_resolution(tiepie_hw_handle handle, uint8_t value);

/**
 * \brief Check whether the currently selected resolution is enhanced or a native resolution of the hardware.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return #TIEPIE_HW_BOOL_TRUE if the current resolution is enhanced, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_is_resolution_enhanced(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Check whether resolution is enhanced.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] value Resolution in bits.
 * \return #TIEPIE_HW_BOOL_TRUE if resolution is enhanced, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_is_resolution_enhanced_ex(tiepie_hw_handle handle, uint8_t value);

//! \endcond

/**
 *       \}
 *       \defgroup scp_clock Clock
 *       \{
 *         \brief Functions to control the clock of the oscilloscope.
 *
 *         \defgroup scp_clock_source Source
 *         \{
 *           \brief Functions to control the clock source of the oscilloscope.
 *
 * Oscilloscopes can support multiple clock sources, use tiepie_hw_oscilloscope_get_clock_sources() to determine the available clock sources
 * for an oscilloscope.
 *
 * When an oscilloscope supports selecting an external clock source, refer to the instrument manual for the location of the
 * external clock input and the specifications of the required external clock signal.
 *
 * Depending on the instrument, an external clock input can support multiple input frequencies.
 * Use tiepie_hw_oscilloscope_get_clock_source_frequencies() to determine which frequencies are supported.
 *
 * By default the clock source is set to: Internal (#TIEPIE_HW_CS_INTERNAL).
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the supported clock sources of the specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The supported clock sources, a set of OR-ed \ref TIEPIE_HW_CS_ "TIEPIE_HW_CS_*" values, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_clock_source
 * \see tiepie_hw_oscilloscope_set_clock_source
 * \see tiepie_hw_oscilloscope_get_clock_source_frequencies
 * \see tiepie_hw_oscilloscope_get_clock_source_frequency
 * \see tiepie_hw_oscilloscope_set_clock_source_frequency
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_get_clock_sources(tiepie_hw_handle handle);

/**
 * \brief Get the currently selected clock source of the specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The current clock source, a \ref TIEPIE_HW_CS_ "TIEPIE_HW_CS_*" value, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_clock_sources
 * \see tiepie_hw_oscilloscope_set_clock_source
 * \see tiepie_hw_oscilloscope_get_clock_source_frequencies
 * \see tiepie_hw_oscilloscope_get_clock_source_frequency
 * \see tiepie_hw_oscilloscope_set_clock_source_frequency
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_get_clock_source(tiepie_hw_handle handle);

/**
 * \brief Set the clock source of the specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] value The requested clock source, a \ref TIEPIE_HW_CS_ "TIEPIE_HW_CS_*" value.
 * \return The actually set clock source, a \ref TIEPIE_HW_CS_ "TIEPIE_HW_CS_*" value, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_clock_sources
 * \see tiepie_hw_oscilloscope_get_clock_source
 * \see tiepie_hw_oscilloscope_get_clock_source_frequencies
 * \see tiepie_hw_oscilloscope_get_clock_source_frequency
 * \see tiepie_hw_oscilloscope_set_clock_source_frequency
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_set_clock_source(tiepie_hw_handle handle, uint32_t value);

/**
 * \brief Get an array with the supported clock source frequencies of the specified oscilloscope.
 *
 * The caller must assure that enough memory is allocated.
 * This function is only available when the clock source is set to #TIEPIE_HW_CS_EXTERNAL.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[out] list A pointer to an array for the clock source frequencies, or \c NULL.
 * \param[in] length The number of elements in the array.
 * \return Total number of supported clock source frequencies, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The oscilloscope does not support external clock or the clock source is not set to #TIEPIE_HW_CS_EXTERNAL.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \par Example
 * \code{c}
 * uint32_t length = tiepie_hw_oscilloscope_get_clock_source_frequencies(h_device, NULL, 0);
 * double* Frequencies = malloc(sizeof(double) * Length);
 * Length = tiepie_hw_oscilloscope_get_clock_source_frequencies(h_device, Frequencies, Length);
 *
 * for(i = 0 ; i < Length ; i++)
 * {
 *   printf("%f\n", Frequencies[ i ]);
 * }
 *
 * free(p_frequencies);
 * \endcode
 * \see tiepie_hw_oscilloscope_get_clock_sources
 * \see tiepie_hw_oscilloscope_get_clock_source
 * \see tiepie_hw_oscilloscope_set_clock_source
 * \see tiepie_hw_oscilloscope_get_clock_source_frequency
 * \see tiepie_hw_oscilloscope_set_clock_source_frequency
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_get_clock_source_frequencies(tiepie_hw_handle handle, double* list, uint32_t length);

//! \cond EXTENDED_API

/**
 * \brief Get an array with the supported clock source frequencies of the specified oscilloscope for the specified clock source.
 *
 * The caller must assure that enough memory is allocated.
 * This function is only available when the clock source is set to #TIEPIE_HW_CS_EXTERNAL.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] value The requested clock source, a \ref TIEPIE_HW_CS_ "TIEPIE_HW_CS_*" value.
 * \param[out] list A pointer to an array for the clock source frequencies, or \c NULL.
 * \param[in] length The number of elements in the array.
 * \return Total number of supported clock source frequencies, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested clock source is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The oscilloscope does not support external clock or the clock source is not set to #TIEPIE_HW_CS_EXTERNAL.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_clock_sources
 * \see tiepie_hw_oscilloscope_get_clock_source
 * \see tiepie_hw_oscilloscope_set_clock_source
 * \see tiepie_hw_oscilloscope_get_clock_source_frequencies
 * \see tiepie_hw_oscilloscope_get_clock_source_frequency
 * \see tiepie_hw_oscilloscope_set_clock_source_frequency
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_get_clock_source_frequencies_ex(tiepie_hw_handle handle, uint32_t value, double* list, uint32_t length);

//!\endcond

/**
 * \brief Get the current clock source frequency of the specified oscilloscope.
 *
 * This function is only available when the clock source is set to #TIEPIE_HW_CS_EXTERNAL.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The current clock source frequency in Hz, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The oscilloscope does not support external clock or the clock source is not set to #TIEPIE_HW_CS_EXTERNAL.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_clock_sources
 * \see tiepie_hw_oscilloscope_get_clock_source
 * \see tiepie_hw_oscilloscope_set_clock_source
 * \see tiepie_hw_oscilloscope_get_clock_source_frequencies
 * \see tiepie_hw_oscilloscope_set_clock_source_frequency
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_get_clock_source_frequency(tiepie_hw_handle handle);

/**
 * \brief Set the clock source frequency of the specified oscilloscope.
 *
 * This function is only available when the clock source is set to #TIEPIE_HW_CS_EXTERNAL.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] value The required clock source frequency in Hz.
 * \return The actually set clock source frequency in Hz, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested clock source frequency is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested clock source frequency is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The oscilloscope does not support external clock or the clock source is not set to #TIEPIE_HW_CS_EXTERNAL.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_clock_sources
 * \see tiepie_hw_oscilloscope_get_clock_source
 * \see tiepie_hw_oscilloscope_set_clock_source
 * \see tiepie_hw_oscilloscope_get_clock_source_frequencies
 * \see tiepie_hw_oscilloscope_get_clock_source_frequency
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_set_clock_source_frequency(tiepie_hw_handle handle, double value);

/**
 *         \}
 *         \defgroup scp_clock_output Output
 *         \{
 *           \brief Functions to control the clock output type.
 *
 * Oscilloscopes can support supplying a clock output signal, use tiepie_hw_oscilloscope_get_clock_outputs() to determine the available
 * clock outputs for an oscilloscope.
 *
 * When an oscilloscope supports selecting a clock output signal, refer to the instrument manual for the location of the
 * clock output and the specifications of the clock output signal.
 *
 * Depending on the instrument, a clock output can support multiple output frequencies.
 * Use tiepie_hw_oscilloscope_get_clock_source_frequencies() to determine which frequencies are supported.
 *
 * By default the clock output is disabled (#TIEPIE_HW_CO_DISABLED).
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the supported clock outputs of the specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The supported clock outputs, a set of OR-ed \ref TIEPIE_HW_CO_ "TIEPIE_HW_CO_*" values, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_clock_output
 * \see tiepie_hw_oscilloscope_set_clock_output
 * \see tiepie_hw_oscilloscope_get_clock_output_frequencies
 * \see tiepie_hw_oscilloscope_get_clock_output_frequency
 * \see tiepie_hw_oscilloscope_set_clock_output_frequency
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_get_clock_outputs(tiepie_hw_handle handle);

/**
 * \brief Get the currently selected clock output of the specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The current clock output, a \ref TIEPIE_HW_CO_ "TIEPIE_HW_CO_*" value, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_clock_outputs
 * \see tiepie_hw_oscilloscope_set_clock_output
 * \see tiepie_hw_oscilloscope_get_clock_output_frequencies
 * \see tiepie_hw_oscilloscope_get_clock_output_frequency
 * \see tiepie_hw_oscilloscope_set_clock_output_frequency
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_get_clock_output(tiepie_hw_handle handle);

/**
 * \brief Set the clock output of the specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] value The requested clock output, a \ref TIEPIE_HW_CO_ "TIEPIE_HW_CO_*" value.
 * \return The actually set clock output, a \ref TIEPIE_HW_CO_ "TIEPIE_HW_CO_*" value, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_clock_outputs
 * \see tiepie_hw_oscilloscope_get_clock_output
 * \see tiepie_hw_oscilloscope_get_clock_output_frequencies
 * \see tiepie_hw_oscilloscope_get_clock_output_frequency
 * \see tiepie_hw_oscilloscope_set_clock_output_frequency
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_set_clock_output(tiepie_hw_handle handle, uint32_t value);

/**
 * \brief Get an array with the supported clock output frequencies of the specified oscilloscope.
 *
 * The caller must assure that enough memory is allocated.
 * This function is only available when the clock output is set to #TIEPIE_HW_CO_FIXED.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[out] list A pointer to an array for the clock output frequencies, or \c NULL.
 * \param[in] length The number of elements in the array.
 * \return Total number of supported clock output frequencies, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The oscilloscope does not support clock output or the clock output is not set to #TIEPIE_HW_CO_FIXED.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \par Example
 * \code{c}
 * uint32_t length = tiepie_hw_oscilloscope_get_clock_output_frequencies(h_device, NULL, 0);
 * double* Frequencies = malloc(sizeof(double) * Length);
 * Length = tiepie_hw_oscilloscope_get_clock_output_frequencies(h_device, Frequencies, Length);
 *
 * for(i = 0 ; i < Length ; i++)
 * {
 *   printf("%f\n", Frequencies[ i ]);
 * }
 *
 * free(p_frequencies);
 * \endcode
 * \see tiepie_hw_oscilloscope_get_clock_outputs
 * \see tiepie_hw_oscilloscope_get_clock_output
 * \see tiepie_hw_oscilloscope_set_clock_output
 * \see tiepie_hw_oscilloscope_get_clock_output_frequency
 * \see tiepie_hw_oscilloscope_set_clock_output_frequency
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_get_clock_output_frequencies(tiepie_hw_handle handle, double* list, uint32_t length);

//! \cond EXTENDED_API

/**
 * \brief Get an array with the supported clock output frequencies of the specified oscilloscope for the specified clock output.
 *
 * The caller must assure that enough memory is allocated.
 * This function is only available when the clock output is set to #TIEPIE_HW_CO_FIXED.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] clock_output The requested clock output, a \ref TIEPIE_HW_CS_ "TIEPIE_HW_CS_*" value.
 * \param[out] list A pointer to an array for the clock output frequencies, or \c NULL.
 * \param[in] length The number of elements in the array.
 * \return Total number of supported clock output frequencies, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested clock output is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The oscilloscope does not support clock output or the clock output is not set to #TIEPIE_HW_CO_FIXED.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_clock_outputs
 * \see tiepie_hw_oscilloscope_get_clock_output
 * \see tiepie_hw_oscilloscope_set_clock_output
 * \see tiepie_hw_oscilloscope_get_clock_output_frequencies
 * \see tiepie_hw_oscilloscope_get_clock_output_frequency
 * \see tiepie_hw_oscilloscope_set_clock_output_frequency
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_get_clock_output_frequencies_ex(tiepie_hw_handle handle, uint32_t clock_output, double* list, uint32_t length);

//!\endcond

/**
 * \brief Get the current clock output frequency of the specified oscilloscope.
 *
 * This function is only available when the clock output is set to #TIEPIE_HW_CO_FIXED.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The current clock output frequency in Hz, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The oscilloscope does not support clock output or the clock output is not set to #TIEPIE_HW_CO_FIXED.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_clock_outputs
 * \see tiepie_hw_oscilloscope_get_clock_output
 * \see tiepie_hw_oscilloscope_set_clock_output
 * \see tiepie_hw_oscilloscope_get_clock_output_frequencies
 * \see tiepie_hw_oscilloscope_set_clock_output_frequency
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_get_clock_output_frequency(tiepie_hw_handle handle);

/**
 * \brief Set the clock output frequency of the specified oscilloscope.
 *
 * This function is only available when the clock output is set to #TIEPIE_HW_CO_FIXED.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] value The required clock output frequency in Hz.
 * \return The actually set clock output frequency in Hz, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested clock output frequency is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested clock output frequency is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The oscilloscope does not support clock output or the clock output is not set to #TIEPIE_HW_CO_FIXED.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_clock_outputs
 * \see tiepie_hw_oscilloscope_get_clock_output
 * \see tiepie_hw_oscilloscope_set_clock_output
 * \see tiepie_hw_oscilloscope_get_clock_output_frequencies
 * \see tiepie_hw_oscilloscope_get_clock_output_frequency
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_set_clock_output_frequency(tiepie_hw_handle handle, double value);

/**
 *         \}
 *       \}
 *       \defgroup scp_timebase Timebase
 *       \{
 *         \brief Functions to control the time base of the oscilloscope.
 *
 *         \defgroup scp_timebase_sample_rate Sample rate
 *         \{
 *           \brief Functions to control the sample rate of the oscilloscope.
 *
 * The rate at which samples are taken by the oscilloscope is called the sample rate, the number of samples per second.
 * A higher sample rate corresponds to a shorter interval between the samples.
 * With a higher sample rate, the original signal can be reconstructed much better from the measured samples.
 *
 * The maximum supported sample rate depends on the used instrument and its configuration.
 * Use #tiepie_hw_oscilloscope_get_sample_rate_max to determine the maximum supported sample rate of a oscilloscope.
 *
 * The sample rate can be affected by changing the \ref scp_ch_enabled "channel enable", \ref scp_resolution "resolution" and/or \ref scp_measurements_mode "measure mode".
 *
 * By default the sample rate is set to the highest value available.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the maximum supported sample rate of a specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The maximum supported sample rate in Hz, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_sample_rate
 * \see tiepie_hw_oscilloscope_set_sample_rate
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_get_sample_rate_max(tiepie_hw_handle handle);

/**
 * \brief Get the currently selected sample rate of a specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The currently selected sample rate in Hz, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_sample_rate_max
 * \see tiepie_hw_oscilloscope_set_sample_rate
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_get_sample_rate(tiepie_hw_handle handle);

/**
 * \brief Set the sample rate of a specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] value The required sample rate in Hz.
 * \return The actually selected sample rate in Hz, or \c 0 when unsuccessful.
 * \remark Changing the sample rate may affect the \ref scp_timebase_record_length "record length", \ref scp_trigger_time_out "trigger time out", \ref scp_trigger_delay "trigger delay", \ref scp_ch_tr_enabled "channel trigger enabled" and/or \ref scp_ch_tr_time "channel trigger time(s)" value(s).
 * \remark Changing the sample rate may change the \ref scp_resolution "resolution" if auto resolution mode is #TIEPIE_HW_ARM_NATIVEONLY or #TIEPIE_HW_ARM_ALL.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested sample rate is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested sample rate is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_sample_rate_max
 * \see tiepie_hw_oscilloscope_get_sample_rate
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_set_sample_rate(tiepie_hw_handle handle, double value);

//! \cond EXTENDED_API

/**
 * \brief Verify if a required sample rate can be set, for the specified device, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] value The required sample rate, in Hz.
 * \return The sample rate that would have been set, if tiepie_hw_oscilloscope_set_sample_rate() was used.
 * \see tiepie_hw_oscilloscope_get_sample_rate_max
 * \see tiepie_hw_oscilloscope_get_sample_rate
 * \see tiepie_hw_oscilloscope_set_sample_rate
 * \see tiepie_hw_oscilloscope_verify_sample_rate_ex
 * \see tiepie_hw_oscilloscope_verify_sample_rates_ex
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_verify_sample_rate(tiepie_hw_handle handle, double value);

/**
 * \brief Verify sample rate by measure mode, resolution and active channels.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] value The required sample rate, in Hz.
 * \param[in] measure_mode Measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \param[in] resolution Resolution in bits.
 * \param[in] channel_enabled Pointer to buffer with channel enables.
 * \param[in] channel_count Number of items in \c channel_enabled.
 * \return Sample rate in Hz when set.
 * \see tiepie_hw_oscilloscope_get_sample_rate_max
 * \see tiepie_hw_oscilloscope_get_sample_rate
 * \see tiepie_hw_oscilloscope_set_sample_rate
 * \see tiepie_hw_oscilloscope_verify_sample_rate
 * \see tiepie_hw_oscilloscope_verify_sample_rates_ex
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_verify_sample_rate_ex(tiepie_hw_handle handle, double value, uint32_t measure_mode, uint8_t resolution, const tiepie_hw_bool* channel_enabled, uint16_t channel_count);

/**
 * \brief Verify sample rates by measure mode, resolution mode, resolution and active channels.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in,out] values Pointer to buffer with sample frequencies.
 * \param[in] count Number of items in \c values.
 * \param[in] measure_mode Measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \param[in] auto_resolution_mode Auto resolution mode, a \ref TIEPIE_HW_ARM_ "TIEPIE_HW_ARM_*" value.
 * \param[in] resolution Resolution in bits.
 * \param[in] channel_enabled Pointer to buffer with channel enables.
 * \param[in] channel_count Number of items in \c channel_enabled.
 * \see tiepie_hw_oscilloscope_get_sample_rate_max
 * \see tiepie_hw_oscilloscope_get_sample_rate
 * \see tiepie_hw_oscilloscope_set_sample_rate
 * \see tiepie_hw_oscilloscope_verify_sample_rate
 * \see tiepie_hw_oscilloscope_verify_sample_rate_ex
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_oscilloscope_verify_sample_rates_ex(tiepie_hw_handle handle, double* values, uint32_t count, uint32_t measure_mode, uint32_t auto_resolution_mode, uint8_t resolution, const tiepie_hw_bool* channel_enabled, uint16_t channel_count);

//! \endcond

/**
 *         \}
 *         \defgroup scp_timebase_record_length Record length
 *         \{
 *           \brief Functions to control the record length of the oscilloscope.
 *
 * The record length defines the number of samples in a measurement.
 * With a given \ref scp_timebase_sample_rate "sample rate", the record length determines the duration of the measurement.
 * Increasing the record length, will increase the total measuring time. The result is that more of the measured signal is visible.
 *
 * The maximum supported record length depends on the used instrument and its configuration.
 * Use #tiepie_hw_oscilloscope_get_record_length_max to determine the maximum supported record length of a oscilloscope.
 *
 * The record length can be affected by changing the \ref scp_ch_enabled "channel enable", \ref scp_resolution "resolution", \ref scp_measurements_mode "measure mode" and/or \ref scp_timebase_sample_rate "sample rate".
 *
 * By default the record length is set to: 5000 samples.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the maximum supported record length of a specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The maximum supported record length, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_record_length
 * \see tiepie_hw_oscilloscope_set_record_length
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_record_length_max(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Get maximum record length for a specified measure mode and resolution.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] measure_mode Measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \param[in] resolution Resolution in bits.
 * \return _max_imum record length.
 * \see tiepie_hw_oscilloscope_get_record_length_max
 * \see tiepie_hw_oscilloscope_get_record_length
 * \see tiepie_hw_oscilloscope_set_record_length
 * \see tiepie_hw_oscilloscope_verify_record_length
 * \see tiepie_hw_oscilloscope_verify_record_lengthex
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_record_length_max_ex(tiepie_hw_handle handle, uint32_t measure_mode, uint8_t resolution);

//! \endcond

/**
 * \brief Get the currently selected record length of a specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The currently selected record length in samples, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_record_length_max
 * \see tiepie_hw_oscilloscope_set_record_length
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_get_record_length(tiepie_hw_handle handle);

/**
 * \brief Set the record length of a specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] record_length The required record length in samples.
 * \return The actually set record length in samples, or \c 0 when unsuccessful.
 * \remark Changing the record length may affect the \ref scp_timebase_segment_count "segment count".
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested record length is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested record length is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_record_length_max
 * \see tiepie_hw_oscilloscope_get_record_length
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_set_record_length(tiepie_hw_handle handle, uint64_t record_length);

//! \cond EXTENDED_API

/**
 * \brief Verify if a required record length can be set, for the specified oscilloscope, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] record_length The required record length, in samples.
 * \return The record length that would have been set, if tiepie_hw_oscilloscope_set_record_length() was used.
 * \see tiepie_hw_oscilloscope_get_record_length_max
 * \see tiepie_hw_oscilloscope_get_record_length_max_ex
 * \see tiepie_hw_oscilloscope_get_record_length
 * \see tiepie_hw_oscilloscope_set_record_length
 * \see tiepie_hw_oscilloscope_verify_record_length_ex
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_verify_record_length(tiepie_hw_handle handle, uint64_t record_length);

/**
 * \brief Verify record length by measure mode, resolution and active channels.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] record_length Record length.
 * \param[in] measure_mode Measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \param[in] resolution Resolution in bits.
 * \param[in] channel_enabled Pointer to buffer with channel enables.
 * \param[in] channel_count Number of items in \c channel_enabled.
 * \return Record length.
 * \see tiepie_hw_oscilloscope_get_record_length_max
 * \see tiepie_hw_oscilloscope_get_record_length_max_ex
 * \see tiepie_hw_oscilloscope_get_record_length
 * \see tiepie_hw_oscilloscope_set_record_length
 * \see tiepie_hw_oscilloscope_verify_record_length
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_oscilloscope_verify_record_length_ex(tiepie_hw_handle handle, uint64_t record_length, uint32_t measure_mode, uint8_t resolution, const tiepie_hw_bool* channel_enabled, uint16_t channel_count);

//! \endcond

/**
 *         \}
 *         \defgroup scp_timebase_pre_samples Pre samples
 *         \{
 *           \brief Functions to control pre samples.
 *
 * When pre samples are selected (pre sample ratio > 0), the trigger point is located at position
 * (pre sample ratio * \ref scp_timebase_record_length "record length"), dividing the record in pre samples and post samples.
 * This way it is possible to "look back in time" since the pre samples were captured before the trigger moment.
 *
 * Pre sample ratio is set as a number between 0 and 1, representing the percentage of the total record length:
 * - 0 equals a trigger point at the start of the record, 0% pre samples and 100% post samples
 * - 0.5 equals a trigger point half way the record, 50% pre samples and 50% post samples
 * - 1  equals a trigger point at the end of the record, 100% pre samples and 0% post samples
 *
 * By default the pre sample ratio is: 0 (no pre samples).
 *
 * The pre sample buffer is not completely filled by default.
 * When a trigger occurs before the pre sample buffer is filled, part of the pre samples will be invalid.
 * Use tiepie_hw_oscilloscope_get_valid_pre_sample_count() before collecting the data to determine the amount of valid pre samples.
 * To ensure the pre samples buffer will be completely filled, set \ref scp_trigger_presamples_valid to true.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the current pre sample ratio of a specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The currently selected pre sample ratio, a value between \c 0 and \c 1.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated oscilloscope does not support pre samples with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_set_pre_sample_ratio
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_get_pre_sample_ratio(tiepie_hw_handle handle);

/**
 * \brief Set the pre sample ratio of a specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] value The required pre sample ratio, a number between \c 0 and \c 1.
 * \return The actually set pre sample ratio, a number between \c 0 and \c 1.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The indicated oscilloscope does not support pre samples with the current settings.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_pre_sample_ratio
 * \see tiepie_hw_oscilloscope_get_valid_pre_sample_count
 * \see scp_trigger_presamples_valid
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_set_pre_sample_ratio(tiepie_hw_handle handle, double value);

/**
 *         \}
 *         \defgroup scp_timebase_segment_count Segment count
 *         \{
 *           \brief Functions to control the segment count.
 *
 * The segment count can be affected by changing the \ref scp_timebase_record_length "record length".
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the maximum supported number of segments of a specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The maximum supported number of segments, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>Segment count is not supported by the hardware.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_segment_count
 * \see tiepie_hw_oscilloscope_set_segment_count
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_get_segment_count_max(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Get the maximum supported number of segments for a specified measure mode of a specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] measure_mode Measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \return The maximum supported number of segments, or \c 0 when unsuccessful.
 * \see tiepie_hw_oscilloscope_get_segment_count_max
 * \see tiepie_hw_oscilloscope_get_segment_count
 * \see tiepie_hw_oscilloscope_set_segment_count
 * \see tiepie_hw_oscilloscope_verify_segment_count
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_get_segment_count_max_ex(tiepie_hw_handle handle, uint32_t measure_mode);

//! \endcond

/**
 * \brief Get the currently selected number of segments of a specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The currently selected number of segments, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>Segment count is not supported by the hardware.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_segment_count_max
 * \see tiepie_hw_oscilloscope_set_segment_count
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_get_segment_count(tiepie_hw_handle handle);

/**
 * \brief Set the number of segments of a specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] value The required number of segments.
 * \return The actually set number of segments, or \c 0 when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested segment count is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested segment count is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>Segment count is not supported by the hardware.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_get_segment_count_max
 * \see tiepie_hw_oscilloscope_get_segment_count
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_set_segment_count(tiepie_hw_handle handle, uint32_t value);

//! \cond EXTENDED_API

/**
 * \brief Verify if a required number of segments can be set, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] value The required number of segments.
 * \return The actually number of segments that would have been set, if tiepie_hw_oscilloscope_set_segment_count() was used.
 * \see tiepie_hw_oscilloscope_get_segment_count_max
 * \see tiepie_hw_oscilloscope_get_segment_count_max_ex
 * \see tiepie_hw_oscilloscope_get_segment_count
 * \see tiepie_hw_oscilloscope_set_segment_count
 * \see tiepie_hw_oscilloscope_verify_segment_count_ex
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_verify_segment_count(tiepie_hw_handle handle, uint32_t value);

/**
 * \brief Verify number of segments by measure mode, record length and enabled channels.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] value The required number of segments.
 * \param[in] measure_mode Measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \param[in] record_length Record length in samples.
 * \param[in] channel_enabled Pointer to buffer with channel enables.
 * \param[in] channel_count Number of items in \c channel_enabled.
 * \return The actually number of segments that would have been set.
 * \see tiepie_hw_oscilloscope_get_segment_count_max
 * \see tiepie_hw_oscilloscope_get_segment_count_max_ex
 * \see tiepie_hw_oscilloscope_get_segment_count
 * \see tiepie_hw_oscilloscope_set_segment_count
 * \see tiepie_hw_oscilloscope_verify_segment_count
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_oscilloscope_verify_segment_count_ex(tiepie_hw_handle handle, uint32_t value, uint32_t measure_mode, uint64_t record_length, const tiepie_hw_bool* channel_enabled, uint16_t channel_count);

//! \endcond

/**
 *         \}
 *       \}
 *       \defgroup scp_trigger Trigger
 *       \{
 *         \brief Functions to control the oscilloscope trigger.
 *
 * See also the \ref TriggerSystem "Trigger system" page.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether the oscilloscope has trigger support with the currently selected \ref scp_measurements_mode "measure mode".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return #TIEPIE_HW_BOOL_TRUE if the oscilloscope has trigger support, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_has_trigger(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Check whether the oscilloscope has trigger support for a specified measure mode.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] measure_mode Measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \return #TIEPIE_HW_BOOL_TRUE if the oscilloscope has trigger support, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_has_trigger
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_has_trigger_ex(tiepie_hw_handle handle, uint32_t measure_mode);

//! \endcond

/**
 *         \defgroup scp_trigger_time_out Time out
 *         \{
 *           \brief Functions to control the oscilloscope trigger time out.
 *
 * Trigger time out defines the time that the system will wait for a trigger before a trigger is forced.
 *
 * If the trigger conditions are set in such a way that the input signal(s) will never meet the trigger settings,
 * the instrument will wait forever. When no measurement is performed, no signals will be displayed.
 * To avoid that the system will wait infinitely, a trigger time out is added to the trigger system.
 * When after a user defined amount of time after starting the measurement still no trigger has occurred,
 * the trigger time out will force a trigger.
 * This will ensure a minimum number of measurements per second.
 *
 * The trigger time out is entered as a number, representing the delay in seconds.
 * There are two special values for the trigger time out setting:
 * - <b>trigger time out = 0</b> Immediately after starting a measurement a trigger is forced. Basically this bypasses the trigger system and the instrument always measures immediately. No pre samples are recorded. The instrument is free-running, just like when no trigger source is selected.
 * - <b>trigger time out = infinite</b> (#TIEPIE_HW_TO_INFINITY) The system will wait infinitely for a trigger. The software will never force a trigger, only when the trigger conditions are met, a trigger will occur and a measurement will take place. This setting is particularly useful for single shot measurements. On conventional desktop oscilloscopes, this is called Trigger mode NORM.
 *
 * The trigger time out can be affected by changing the \ref scp_timebase_sample_rate "sample rate".
 *
 * By default the trigger time out is set to: 0.1 s (100 ms).
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the currently selected trigger time out in seconds, for a specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return Trigger time out in seconds, or #TIEPIE_HW_TO_INFINITY.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The oscilloscope does not support trigger.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_trigger_set_timeout
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_trigger_get_timeout(tiepie_hw_handle handle);

/**
 * \brief Set the trigger time out in seconds, for a specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] value The required trigger time out in seconds, or #TIEPIE_HW_TO_INFINITY.
 * \return The actually set trigger time out in seconds, or #TIEPIE_HW_TO_INFINITY.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested trigger time out is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The oscilloscope does not support trigger.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_trigger_get_timeout
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_trigger_set_timeout(tiepie_hw_handle handle, double value);

//! \cond EXTENDED_API

/**
 * \brief Verify if a required trigger time out can be set, for the specified device, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle".
 * \param[in] value The required trigger time out in seconds, or #TIEPIE_HW_TO_INFINITY.
 * \return The trigger time out that would have been set, if tiepie_hw_oscilloscope_trigger_set_timeout() was used.
 * \see tiepie_hw_oscilloscope_trigger_get_timeout
 * \see tiepie_hw_oscilloscope_trigger_set_timeout
 * \see tiepie_hw_oscilloscope_trigger_verify_timeout_ex
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_trigger_verify_timeout(tiepie_hw_handle handle, double value);

/**
 * \brief Verify if a required trigger time out can be set, for the specified device, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle".
 * \param[in] value The required trigger time out in seconds, or #TIEPIE_HW_TO_INFINITY.
 * \param[in] measure_mode Measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \param[in] sample_rate Sample rate in Hz.
 * \return The trigger time out that would have been set, if tiepie_hw_oscilloscope_trigger_set_timeout() was used.
 * \see tiepie_hw_oscilloscope_trigger_get_timeout
 * \see tiepie_hw_oscilloscope_trigger_set_timeout
 * \see tiepie_hw_oscilloscope_trigger_verify_timeout
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_trigger_verify_timeout_ex(tiepie_hw_handle handle, double value, uint32_t measure_mode, double sample_rate);

//! \endcond

/**
 *         \}
 *         \defgroup scp_trigger_delay Delay
 *         \{
 *           \brief Functions to control the trigger delay of an oscilloscope.
 *
 * Trigger delay allows to start measuring a specified time after the trigger occurred.
 * This allows to capture events that are more than one full record length past the trigger moment.
 *
 * Trigger delay is not available for all instruments and only available in \ref scp_measurements_mode "measure mode" Block.
 * Use tiepie_hw_oscilloscope_trigger_has_delay() to check whether trigger delay is available for your instrument and in the currently set measure mode.
 *
 * The trigger delay can be affected by changing the \ref scp_timebase_sample_rate "sample rate".
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether the oscilloscope has trigger delay support with the currently selected \ref scp_measurements_mode "measure mode".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return #TIEPIE_HW_BOOL_TRUE if the oscilloscope has trigger delay support, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_trigger_has_delay(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Check whether the oscilloscope has trigger delay support for a specified measure mode.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] measure_mode Measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \return #TIEPIE_HW_BOOL_TRUE if the oscilloscope has trigger delay support, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_trigger_has_delay
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_trigger_has_delay_ex(tiepie_hw_handle handle, uint32_t measure_mode);

//! \endcond

/**
 * \brief Get the maximum trigger delay in seconds, for the currently selected \ref scp_measurements_mode "measure mode" and \ref scp_timebase_sample_rate "sample rate".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The maximum trigger delay in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The oscilloscope does not support trigger delay.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_trigger_has_delay
 * \see tiepie_hw_oscilloscope_trigger_get_delay
 * \see tiepie_hw_oscilloscope_trigger_set_delay
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_trigger_get_delay_max(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief  Get the maximum trigger delay in seconds, for a specified measure mode and sample rate.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] measure_mode Measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \param[in] sample_rate Sample rate in Hz.
 * \return The maximum trigger delay in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_trigger_has_delay
 * \see tiepie_hw_oscilloscope_trigger_has_delay_ex
 * \see tiepie_hw_oscilloscope_trigger_get_delay_max
 * \see tiepie_hw_oscilloscope_trigger_get_delay
 * \see tiepie_hw_oscilloscope_trigger_set_delay
 * \see tiepie_hw_oscilloscope_trigger_verify_delay
 * \see tiepie_hw_oscilloscope_trigger_verify_delay_ex
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_trigger_get_delay_max_ex(tiepie_hw_handle handle, uint32_t measure_mode, double sample_rate);

//! \endcond

/**
 * \brief Get the currently selected trigger delay in seconds, for a specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return The currently set trigger delay in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The oscilloscope does not support trigger delay.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_trigger_has_delay
 * \see tiepie_hw_oscilloscope_trigger_get_delay_max
 * \see tiepie_hw_oscilloscope_trigger_set_delay
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_trigger_get_delay(tiepie_hw_handle handle);

/**
 * \brief Set trigger delay in seconds, for a specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] value The required trigger delay in seconds.
 * \return The actually set trigger delay in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested trigger delay is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The oscilloscope does not support trigger delay.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_trigger_has_delay
 * \see tiepie_hw_oscilloscope_trigger_get_delay_max
 * \see tiepie_hw_oscilloscope_trigger_get_delay
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_trigger_set_delay(tiepie_hw_handle handle, double value);

//! \cond EXTENDED_API

/**
 * \brief Verify if a required trigger delay can be set, for the specified device, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle".
 * \param[in] value The required trigger delay in seconds.
 * \return The trigger delay that would have been set, if tiepie_hw_oscilloscope_trigger_set_delay() was used.
 * \see tiepie_hw_oscilloscope_trigger_has_delay
 * \see tiepie_hw_oscilloscope_trigger_has_delay_ex
 * \see tiepie_hw_oscilloscope_trigger_get_delay_max
 * \see tiepie_hw_oscilloscope_trigger_get_delay
 * \see tiepie_hw_oscilloscope_trigger_set_delay
 * \see tiepie_hw_oscilloscope_trigger_verify_delay_ex
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_trigger_verify_delay(tiepie_hw_handle handle, double value);

/**
 * \brief Verify if a required trigger delay can be set, for the specified device, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle".
 * \param[in] value The required trigger delay in seconds.
 * \param[in] measure_mode Measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \param[in] sample_rate Sample rate in Hz.
 * \return The trigger delay that would have been set, if tiepie_hw_oscilloscope_trigger_set_delay() was used.
 * \see tiepie_hw_oscilloscope_trigger_has_delay
 * \see tiepie_hw_oscilloscope_trigger_has_delay_ex
 * \see tiepie_hw_oscilloscope_trigger_get_delay_max
 * \see tiepie_hw_oscilloscope_trigger_get_delay
 * \see tiepie_hw_oscilloscope_trigger_set_delay
 * \see tiepie_hw_oscilloscope_trigger_verify_delay
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_oscilloscope_trigger_verify_delay_ex(tiepie_hw_handle handle, double value, uint32_t measure_mode, double sample_rate);

//! \endcond

/**
 *         \}
 *         \defgroup scp_trigger_presamples_valid Presamples valid
 *         \{
 *           \brief Functions to control the trigger presamples valid of an oscilloscope.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether the oscilloscope has presamples valid support with the currently selected \ref scp_measurements_mode "measure mode".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return #TIEPIE_HW_BOOL_TRUE if the oscilloscope has presamples valid support, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_has_presamples_valid(tiepie_hw_handle handle);

/**
 * \brief Check whether the oscilloscope has presamples valid support for a specific \ref scp_measurements_mode "measure mode".
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] measure_mode Measure mode, a \ref TIEPIE_HW_MM_ "TIEPIE_HW_MM_*" value.
 * \return #TIEPIE_HW_BOOL_TRUE if the oscilloscope has presamples valid support, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0.1
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_has_presamples_valid_ex(tiepie_hw_handle handle, uint32_t measure_mode);

/**
 * \brief Get presamples valid for a specified measure mode, for a specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return #TIEPIE_HW_BOOL_TRUE if presamples valid is enabled, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The oscilloscope does not support presamples valid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_has_presamples_valid
 * \see tiepie_hw_oscilloscope_set_presamples_valid
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_get_presamples_valid(tiepie_hw_handle handle);

/**
 * \brief Set presamples valid, for a specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] value #TIEPIE_HW_BOOL_TRUE to enable presamples valid, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \return The actually set value.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The oscilloscope does not support presamples valid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_has_presamples_valid
 * \see tiepie_hw_oscilloscope_get_presamples_valid
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_set_presamples_valid(tiepie_hw_handle handle, tiepie_hw_bool value);

/**
 *         \}
 *       \}
 *       \defgroup scp_ct SureConnect connection test
 *       \{
 *         \brief Functions to perform a SureConnect connection test.
 *
 * To check whether the measurement probe on a channel is electrically connected to the device under test,
 * a connection test can be performed on instruments with <a class="External"
 * href="http://www.tiepie.com/articles/sureconnect">SureConnect</a>.
 * To find out whether the connection test is ready, tiepie_hw_oscilloscope_is_sureconnect_completed() can be polled, or
 * a \ref tiepie_hw_object_set_event_callback "notification" can be used.
 * When the connection test is ready, connection test data indicating the connection status of the input(s)
 * can be collected using tiepie_hw_oscilloscope_get_sureconnect_data().
 *
 * SureConnect connection test is not available for all instruments.
 * Use tiepie_hw_oscilloscope_has_sureconnect() to check whether connection test is available for your instrument.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether the specified oscilloscope supports SureConnect connection testing.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return #TIEPIE_HW_BOOL_TRUE when at least one channel supports connection testing, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_channel_has_sureconnect
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_has_sureconnect(tiepie_hw_handle handle);

/**
 * \brief Check whether a specified channel of a specified oscilloscope supports SureConnect connection testing.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] ch A channel number identifying the channel, \c 0 to <tt>tiepie_hw_oscilloscope_get_channel_count() - 1</tt>.
 * \return #TIEPIE_HW_BOOL_TRUE if the channel supports connection test, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_has_sureconnect
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_channel_has_sureconnect(tiepie_hw_handle handle, uint16_t ch);

/**
 * \brief Perform a SureConnect connection test on all enabled channels of a specified oscilloscope.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return #TIEPIE_HW_BOOL_TRUE if started successfully, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td>No channels are enabled or a measurement is busy.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The oscilloscope does not support SureConnect connection test.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_has_sureconnect
 * \see tiepie_hw_oscilloscope_channel_has_sureconnect
 * \see tiepie_hw_oscilloscope_is_sureconnect_completed
 * \see tiepie_hw_oscilloscope_get_sureconnect_data
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_start_sureconnect(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Perform a SureConnect connection test on all channels of a specified oscilloscope.
 *
 * The enabled status of the channels on entry is buffered in an array pointed to by \c channel_enabled.
 * During the test, all channels will be enabled.
 * On exit, the original enabled status of the channels will be reset.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[in] channel_enabled A pointer to a buffer with channel enables.
 * \param[in] channel_count The number of items in \c channel_enabled.
 * \return #TIEPIE_HW_BOOL_TRUE if started successfully, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_CHANNEL</td>        <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td>No channels are enabled or a measurement is busy.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The oscilloscope does not support SureConnect connection test.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_has_sureconnect
 * \see tiepie_hw_oscilloscope_channel_has_sureconnect
 * \see tiepie_hw_oscilloscope_start_sureconnect
 * \see tiepie_hw_oscilloscope_is_sureconnect_completed
 * \see tiepie_hw_oscilloscope_get_sureconnect_data
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_start_sureconnect_ex(tiepie_hw_handle handle, const tiepie_hw_bool* channel_enabled, uint16_t channel_count);

//! \endcond

/**
 * \brief Check whether the SureConnect connection test on a specified oscilloscope is completed.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \return #TIEPIE_HW_BOOL_TRUE if completed, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The oscilloscope does not support SureConnect connection test.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_oscilloscope_has_sureconnect
 * \see tiepie_hw_oscilloscope_channel_has_sureconnect
 * \see tiepie_hw_oscilloscope_start_sureconnect
 * \see notification scp_callbacks_sureconnect_completed
 * \see tiepie_hw_oscilloscope_get_sureconnect_data
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_oscilloscope_is_sureconnect_completed(tiepie_hw_handle handle);

/**
 * \brief Get the SureConnect connection test result data for a specified oscilloscope.
 *
 * The test result data is presented in an array \c Buffer with an element for each channel.
 * Each element contains the connection test status for a channel:
 * - #TIEPIE_HW_TRISTATE_UNDEFINED this channel is not enabled or does not support SureConnect connection test.
 * - #TIEPIE_HW_TRISTATE_FALSE this channel has no connection
 * - #TIEPIE_HW_TRISTATE_TRUE this channel has connection
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the oscilloscope.
 * \param[out] buffer A pointer to a #tiepie_hw_tristate array.
 * \param[in] channel_count The length of the #tiepie_hw_tristate array.
 * \return The number of elements written in the tiepie_hw_tristate array.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The oscilloscope does not support SureConnect connection test.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The pointer \c Buffer was \c NULL or \c Channel_count was \c 0.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td>No connection test result data available.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid oscilloscope handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \par Example
 * \code{.c}
 * uint16_t channel_count = tiepie_hw_oscilloscope_get_channel_count(h_device);
 * tiepie_hw_tristate* Connections = malloc(sizeof(tiepie_hw_tristate) * Channel_count);
 * tiepie_hw_oscilloscope_get_sureconnect_data(h_device, Connections, Channel_count);
 *
 * printf("scp_get_sureconnect_data ():\n");
 * for(uint16_t i = 0 ; i < Channel_count ; i++)
 *   switch(p_connections)
 *   {
 *     case TIEPIE_HW_TRISTATE_UNDEFINED:
 *       printf("- Ch%u Undefined\n", i + 1);
 *       break;
 *
 *     case TIEPIE_HW_TRISTATE_FALSE:
 *       printf("- Ch%u Not connected\n", i + 1);
 *       break;
 *
 *     case TIEPIE_HW_TRISTATE_TRUE:
 *       printf("- Ch%u Connected\n", i + 1);
 *       break;
 *
 *     default:
 *       printf("- Ch%u Invalid value\n", i + 1);
 *       break;
 *   }
 *
 * free(p_connections);
 * \endcode
 * \see tiepie_hw_oscilloscope_has_sureconnect
 * \see tiepie_hw_oscilloscope_channel_has_sureconnect
 * \see tiepie_hw_oscilloscope_start_sureconnect
 * \see tiepie_hw_oscilloscope_is_sureconnect_completed
 * \since 1.0
 */
TIEPIE_HW_API uint16_t tiepie_hw_oscilloscope_get_sureconnect_data(tiepie_hw_handle handle, tiepie_hw_tristate* buffer, uint16_t channel_count);

/**
 *       \}
 *     \}
 *     \defgroup gen Generator
 *     \{
 *       \brief Functions to setup and control generators.
 *
 * All generator related functions require a \ref tiepie_hw_handle "generator handle" to identify the generator,
 * see \ref Open_dev "opening a device".
 *
 * In certain conditions, like when performing a streaming measurement with the oscilloscope, the generator cannot be controlled.
 * Use tiepie_hw_generator_is_controllable() to check if the generator can be controlled.
 *
 *       \defgroup gen_info Info
 *       \{
 *         \brief Functions that provide information of a generator.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the output \ref TIEPIE_HW_CONNECTORTYPE "connector type" for a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The output \ref TIEPIE_HW_CONNECTORTYPE "connector type", #TIEPIE_HW_CONNECTORTYPE_UNKNOWN when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support getting the connector type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_generator_get_connector_type(tiepie_hw_handle handle);

/**
 * \brief Check whether the output of a specified generator is differential.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return #TIEPIE_HW_BOOL_TRUE when the output is differential, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_is_differential(tiepie_hw_handle handle);

/**
 * \brief Get the output impedance of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The output impedance in Ohm.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support getting the output impedance.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_impedance(tiepie_hw_handle handle);

/**
 * \brief Get the DAC resolution of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The resolution in bits.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support getting the resolution.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint8_t tiepie_hw_generator_get_resolution(tiepie_hw_handle handle);

/**
 * \brief Get the minimum output value of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The minimum output value in Volt.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_output_value_max
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_output_value_min(tiepie_hw_handle handle);

/**
 * \brief Get the maximum output value of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The maximum output value in Volt.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_output_value_min
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_output_value_max(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Get the minimum and/or maximum output value of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[out] min A pointer to a memory location for the minimum value, or \c NULL.
 * \param[out] max A pointer to a memory location for the maximum value, or \c NULL.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_generator_get_output_value_min_max(tiepie_hw_handle handle, double* min, double* max);

//! \endcond

/**
 *       \}
 *       \defgroup gen_control Control
 *       \{
 *         \brief Functions for starting and stopping the generator and checking its status.
 *
 * In certain conditions, like when performing a streaming measurement with the oscilloscope, the generator cannot be controlled.
 * Use tiepie_hw_generator_is_controllable() to poll if the generator can be controlled or use a \ref tiepie_hw_object_set_event_callback "notification".
 *
 * Use tiepie_hw_generator_get_status() to check the signal generation status.
 *
 * Before a generator can be used, the hardware must be switched on (enabled) using tiepie_hw_generator_set_output_enable().
 * When enabled, the generator signal properties can be set.
 * When the generator hardware is enabled, but the generator is not started, the output will be at the currently set \ref gen_signal_offset.
 * When the generator hardware is disabled, the hardware is switched off, resulting in the instrument using less power.
 *
 * Output invert is not available for all instruments.
 * Use tiepie_hw_generator_has_output_invert() to check whether output invert is available for your instrument.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether a specified generator can be controlled.
 *
 * In certain conditions like when performing a streaming measurement with the oscilloscope, the generator cannot be controlled.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return #TIEPIE_HW_BOOL_TRUE if the generator is controllable, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see Notification gen_callbacks_controllable_changed.
 * \see \ref scp_measurements_mode "Measure mode".
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_is_controllable(tiepie_hw_handle handle);

/**
 * \brief Check whether the generator is running.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return #TIEPIE_HW_BOOL_TRUE if running, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_is_running(tiepie_hw_handle handle);

/**
 * \brief Get the current signal generation status of a specified generator
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The current signal generation status, a \ref TIEPIE_HW_GS_ "TIEPIE_HW_GS_*" value or #TIEPIE_HW_GSM_NONE when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support getting the status.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_CONTROLLABLE</td>       <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_generator_get_status(tiepie_hw_handle handle);

/**
 * \brief Check whether a specified generator is enabled
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return #TIEPIE_HW_BOOL_TRUE if the generator hardware is currently enabled, #TIEPIE_HW_BOOL_FALSE if the generator hardware is disabled.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_set_output_enable
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_get_output_enable(tiepie_hw_handle handle);

/**
 * \brief Enable or disable the hardware of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested hardware state, #TIEPIE_HW_BOOL_TRUE to enable the hardware, #TIEPIE_HW_BOOL_FALSE to disable the hardware.
 * \return The actually set hardware state, #TIEPIE_HW_BOOL_TRUE if the hardware is enabled, #TIEPIE_HW_BOOL_FALSE if the hardware is disabled.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_CONTROLLABLE</td>       <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_output_enable
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_set_output_enable(tiepie_hw_handle handle, tiepie_hw_bool value);

/**
 * \brief Check whether the output of a specified generator can be inverted
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return #TIEPIE_HW_BOOL_TRUE if the output can be inverted, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_output_invert
 * \see tiepie_hw_generator_set_output_invert
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_has_output_invert(tiepie_hw_handle handle);

/**
 * \brief Check whether the output of a specified generator is inverted
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return #TIEPIE_HW_BOOL_TRUE if the output is currently inverted, #TIEPIE_HW_BOOL_FALSE if the output is normal.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_has_output_invert
 * \see tiepie_hw_generator_set_output_invert
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_get_output_invert(tiepie_hw_handle handle);

/**
 * \brief Enable or disable the output invert of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested output state, #TIEPIE_HW_BOOL_TRUE to invert the output, #TIEPIE_HW_BOOL_FALSE to disable the output invert.
 * \return The actually set output state, #TIEPIE_HW_BOOL_TRUE if the output is inverted, #TIEPIE_HW_BOOL_FALSE if the output is normal.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_CONTROLLABLE</td>       <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_has_output_invert
 * \see tiepie_hw_generator_get_output_invert
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_set_output_invert(tiepie_hw_handle handle, tiepie_hw_bool value);

/**
 * \brief Start the signal generation of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return #TIEPIE_HW_BOOL_TRUE if succesful, #TIEPIE_HW_BOOL_FALSE if failed.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NO_TRIGGER_ENABLED</td>     <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_CONTROLLABLE</td>       <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_stop
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_start(tiepie_hw_handle handle);

/**
 * \brief Stop the signal generation of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return #TIEPIE_HW_BOOL_TRUE if succesful, #TIEPIE_HW_BOOL_FALSE if failed.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_CONTROLLABLE</td>       <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_start
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_stop(tiepie_hw_handle handle);

/**
 *       \}
 *       \defgroup gen_signal Signal
 *       \{
 *         \brief Functions to control the signal properties of a generator.
 *
 * The generator supports several standard signal types.
 * Depending on the signal type that is set, other properties of the generator are available:
 *
 * <table>
 *   <tr>                    <th>\ref gen_signal_type</th><th>\ref gen_signal_amplitude</th><th>\ref gen_signal_offset</th><th>\ref gen_signal_frequency</th><th>\ref gen_signal_phase</th><th>\ref gen_signal_symmetry</th><th>\ref gen_signal_width</th><th>\ref gen_signal_edge_time</th><th>\ref gen_signal_data "Data"</th></tr>
 *   <tr class="signal_types"><th>Sine               </th><td>yes                     </td><td>yes                  </td><td>yes                     </td><td>yes                 </td><td>yes                    </td><td>-                   </td><td>-                      </td><td>-                         </td></tr>
 *   <tr class="signal_types"><th>Triangle           </th><td>yes                     </td><td>yes                  </td><td>yes                     </td><td>yes                 </td><td>yes                    </td><td>-                   </td><td>-                      </td><td>-                         </td></tr>
 *   <tr class="signal_types"><th>Square             </th><td>yes                     </td><td>yes                  </td><td>yes                     </td><td>yes                 </td><td>yes                    </td><td>-                   </td><td>-                      </td><td>-                         </td></tr>
 *   <tr class="signal_types"><th>Pulse              </th><td>yes                     </td><td>yes                  </td><td>yes                     </td><td>yes                 </td><td>-                      </td><td>yes                 </td><td>yes                    </td><td>-                         </td></tr>
 *   <tr class="signal_types"><th>DC                 </th><td>-                       </td><td>yes                  </td><td>-                       </td><td>-                   </td><td>-                      </td><td>-                   </td><td>-                      </td><td>-                         </td></tr>
 *   <tr class="signal_types"><th>Noise              </th><td>yes                     </td><td>yes                  </td><td>yes                     </td><td>-                   </td><td>-                      </td><td>-                   </td><td>-                      </td><td>-                         </td></tr>
 *   <tr class="signal_types"><th>Arbitrary          </th><td>yes                     </td><td>yes                  </td><td>yes                     </td><td>yes                 </td><td>-                      </td><td>-                   </td><td>-                      </td><td>yes                       </td></tr>
 * </table>
 *
 *         \defgroup gen_signal_type Signal type
 *         \{
 *           \brief Functions for controlling the signal type of a generator.
 *
 * The generator supports several standard signal types.
 * Use tiepie_hw_generator_get_signal_types() to find the supported signal types.
 *
 * By default signal type is set to: Sine (#TIEPIE_HW_ST_SINE).
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the supported signal types of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The supported signal types, a set of \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" values, #TIEPIE_HW_STM_NONE when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_signal_type
 * \see tiepie_hw_generator_set_signal_type
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_generator_get_signal_types(tiepie_hw_handle handle);

/**
 * \brief Get the currently selected signal type of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The currently set signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value, #TIEPIE_HW_ST_UNKNOWN when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_signal_types
 * \see tiepie_hw_generator_set_signal_type
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_generator_get_signal_type(tiepie_hw_handle handle);

/**
 * \brief Set the signal type of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \return The actually set signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value, #TIEPIE_HW_ST_UNKNOWN when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_CONTROLLABLE</td>       <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \remark When the generator is active, changing the signal type may shortly interrupt the output signal.
 * \remark Changing the signal type can affect the \ref tiepie_hw_generator_set_frequency_mode "frequency mode", \ref tiepie_hw_generator_set_mode "generator mode" and/or \ref gen_signal_offset "offset".
 * \remark Setting certain signal types will make other generator properties unavailable.
 * \see tiepie_hw_generator_get_signal_types
 * \see tiepie_hw_generator_get_signal_type
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_generator_set_signal_type(tiepie_hw_handle handle, uint32_t value);

/**
 *         \}
 *         \defgroup gen_signal_amplitude Amplitude
 *         \{
 *           \brief Functions for controlling the amplitude and amplitude range of a generator.
 *
 * The amplitude of a generator can be set between a minimum and a maximum value.
 * Use tiepie_hw_generator_get_amplitude_min() and tiepie_hw_generator_get_amplitude_max() to get the amplitude limits.
 *
 * Amplitude and \ref gen_signal_offset combined cannot exceed the \ref tiepie_hw_generator_get_output_value_min "minimum" and
 * \ref tiepie_hw_generator_get_output_value_max "maximum" output value of the generator.
 * Setting a larger amplitude will clip the amplitude to a valid value.
 *
 * A generator has one or more output ranges, use tiepie_hw_generator_set_amplitude_range() to set the required range or \ref tiepie_hw_generator_set_amplitude_auto_ranging
 * to enable amplitude auto ranging.
 *
 * By default the amplitude is set to: 1 V and auto ranging is enabled.
 *
 * When \ref gen_signal_type "signal type" DC is active, amplitude is not available.
 * Use tiepie_hw_generator_has_amplitude() to check whether amplitude is available for the currently set signal type.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether the current signal type of a specified generator supports controlling the signal amplitude.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return #TIEPIE_HW_BOOL_TRUE if supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_amplitude_min
 * \see tiepie_hw_generator_get_amplitude_max
 * \see tiepie_hw_generator_get_amplitude
 * \see tiepie_hw_generator_set_amplitude
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_has_amplitude(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Check whether the specified generator supports controlling the signal amplitude for a specified signal type.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \return #TIEPIE_HW_BOOL_TRUE if supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_has_amplitude_ex(tiepie_hw_handle handle, uint32_t signal_type);

//! \endcond

/**
 * \brief Get the minimum signal amplitude for the current signal type of a specified generator.
 *
 *  When \ref tiepie_hw_generator_set_amplitude_auto_ranging "amplitude auto ranging" is enabled, the minimum value of all amplitude ranges is returned.
 *  When amplitude auto ranging is disabled, the minimum value for the currently set amplitude range is returned.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The minimum signal amplitude in Volt.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The current signal type does not support signal amplitude.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_amplitude_max
 * \see tiepie_hw_generator_get_amplitude
 * \see tiepie_hw_generator_set_amplitude
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_amplitude_min(tiepie_hw_handle handle);

/**
 * \brief Get the maximum signal amplitude for the current signal type of a specified generator.
 *
 *  When \ref tiepie_hw_generator_set_amplitude_auto_ranging "amplitude auto ranging" is enabled, the maximum value for the highest amplitude range is returned.
 *  When amplitude auto ranging is disabled, the maximum value for the currently set amplitude range is returned.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The maximum signal amplitude in Volt.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The current signal type does not support signal amplitude.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_amplitude_min
 * \see tiepie_hw_generator_get_amplitude
 * \see tiepie_hw_generator_set_amplitude
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_amplitude_max(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Get the minimum and/or maximum amplitude for a specified signal type, of a specified generator.
 *
 *  When \ref tiepie_hw_generator_set_amplitude_auto_ranging "amplitude auto ranging" is enabled, the minimum and maximum values for the highest amplitude range
 *  are returned.
 *  When amplitude auto ranging is disabled, the minimum and maximum values for the currently set amplitude range
 *  are returned.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \param[out] min A pointer to a memory location for the minimum amplitude in Volt, or \c NULL.
 * \param[out] max A pointer to a memory location for the maximum amplitude in Volt, or \c NULL.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The requested signal type does not support signal amplitude.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_amplitude_max
 * \see tiepie_hw_generator_get_amplitude
 * \see tiepie_hw_generator_set_amplitude
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_generator_get_amplitude_min_max_ex(tiepie_hw_handle handle, uint32_t signal_type, double* min, double* max);

//! \endcond

/**
 * \brief Get the currently set signal amplitude of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The currently set signal amplitude in Volt.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The current signal type does not support signal amplitude.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_amplitude_min
 * \see tiepie_hw_generator_get_amplitude_max
 * \see tiepie_hw_generator_set_amplitude
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_amplitude(tiepie_hw_handle handle);

/**
 * \brief Set the signal amplitude of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] amplitude The requested signal amplitude.
 * \return The actually set signal amplitude.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested amplitude is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested amplitude is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested amplitude is &lt; \c 0.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The current signal type does not support signal amplitude.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_CONTROLLABLE</td>       <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \remark Setting the amplitude may change the amplitude range when \ref tiepie_hw_generator_set_amplitude_auto_ranging "amplitude auto ranging" is enabled.
 * \remark Setting the amplitude may cause a new waveform pattern to be uploaded when \ref gen_signal_type "signal type" Square wave is active, shortly interrupting the output signal.
 * \see tiepie_hw_generator_get_amplitude_min
 * \see tiepie_hw_generator_get_amplitude_max
 * \see tiepie_hw_generator_get_amplitude
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_set_amplitude(tiepie_hw_handle handle, double amplitude);

//! \cond EXTENDED_API

/**
 * \brief Verify if a signal amplitude can be set, of a specified generator, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] amplitude The requested signal amplitude.
 * \return The signal amplitude that would have been set, in Volt.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested amplitude is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested amplitude is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested amplitude is &lt; \c 0.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The current signal type does not support signal amplitude.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_CONTROLLABLE</td>       <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_amplitude_min
 * \see tiepie_hw_generator_get_amplitude_max
 * \see tiepie_hw_generator_get_amplitude_min_max_ex
 * \see tiepie_hw_generator_get_amplitude
 * \see tiepie_hw_generator_set_amplitude
 * \see tiepie_hw_generator_verify_amplitude_ex
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_verify_amplitude(tiepie_hw_handle handle, double amplitude);

/**
 * \brief Verify if a signal amplitude can be set for a specified signal type, amplitude range and offset, of a specified generator, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] amplitude The requested signal amplitude.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \param[in] amplitude_range_index The requested output range index or \ref TIEPIE_HW_RANGEINDEX_AUTO.
 * \param[in] offset The requested signal offset.
 * \param[in] output_invert The requested signal outputInvert.
 * \return The signal amplitude that would have been set, in Volt.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested amplitude is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested amplitude is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested amplitude is &lt; \c 0.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The current signal type does not support signal amplitude.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_amplitude_min
 * \see tiepie_hw_generator_get_amplitude_max
 * \see tiepie_hw_generator_get_amplitude_min_max_ex
 * \see tiepie_hw_generator_get_amplitude
 * \see tiepie_hw_generator_set_amplitude
 * \see tiepie_hw_generator_verify_amplitude
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_verify_amplitude_ex(tiepie_hw_handle handle, double amplitude, uint32_t signal_type, uint32_t amplitude_range_index, double offset, tiepie_hw_bool output_invert);

//! \endcond

/**
 *           \defgroup gen_signal_amplitude_range Amplitude range
 *           \{
 *             \brief Functions for controlling the amplitude range of a generator.
 *
 * A generator has one or more output ranges, use tiepie_hw_generator_get_amplitude_ranges() to get the available ranges.
 * Within each range, the amplitude can be set in a fixed number of steps.
 * When \ref tiepie_hw_generator_set_amplitude_auto_ranging "amplitude auto ranging" is disabled, the amplitude can only be set within the selected amplitude range.
 * When amplitude auto ranging is enabled, selecting a certain amplitude may change the amplitude range to the most appropriate value.
 *
 * By default the amplitude auto ranging is enabled.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the supported amplitude ranges for a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[out] list A pointer to an array to hold the amplitude range values.
 * \param[in] length The number of elements in the array.
 * \return The number of amplitude ranges.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The current signal type does not support signal amplitude (range).</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \par Example
 * \code{.c}
 * uint32_t Range_count = tiepie_hw_generator_get_amplitude_ranges(h_device, NULL, 0);
 * double* Ranges = malloc(sizeof(double) * Range_count);
 * Range_count = tiepie_hw_generator_get_amplitude_ranges(h_device, Ranges, Range_count);
 *
 * printf("Gen_get_amplitude_ranges:\n");
 *
 * for(uint32_t i = 0 ; i < Range_count ; i++)
 *   printf("- %f\n", Ranges[ i ]);
 *
 * free(p_ranges);
 * \endcode
 *
 * \see tiepie_hw_generator_get_amplitude_range
 * \see tiepie_hw_generator_set_amplitude_range
 * \see tiepie_hw_generator_get_amplitude_auto_ranging
 * \see tiepie_hw_generator_set_amplitude_auto_ranging
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_generator_get_amplitude_ranges(tiepie_hw_handle handle, double* list, uint32_t length);

/**
 * \brief Get the currently set amplitude range for a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The currently set amplitude range.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The current signal type does not support signal amplitude (range).</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_amplitude_ranges
 * \see tiepie_hw_generator_set_amplitude_range
 * \see tiepie_hw_generator_get_amplitude_auto_ranging
 * \see tiepie_hw_generator_set_amplitude_auto_ranging
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_amplitude_range(tiepie_hw_handle handle);

/**
 * \brief Set the amplitude range for a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The maximum value that must fit within the requested amplitude range.
 * \return The actually set amplitude range.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested amplitude range is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested amplitude range is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested amplitude range is &lt; \c 0.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_CONTROLLABLE</td>       <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The current signal type does not support signal amplitude (range).</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \remark Setting the amplitude range will disable \ref tiepie_hw_generator_set_amplitude_auto_ranging "amplitude auto ranging" when enabled.
 * \remark Setting the amplitude range may affect the amplitude.
 *
 * \par Example
 * \code{.c}
 * double Range = 10;
 *
 * Range = tiepie_hw_generator_set_amplitude_range(h_device, Range);
 *
 * printf("Gen_set_amplitude_range = %f", Range);
 * \endcode
 *
 * \see tiepie_hw_generator_get_amplitude_ranges
 * \see tiepie_hw_generator_get_amplitude_range
 * \see tiepie_hw_generator_get_amplitude_auto_ranging
 * \see tiepie_hw_generator_set_amplitude_auto_ranging
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_set_amplitude_range(tiepie_hw_handle handle, double value);

/**
 * \brief Get the amplitude auto ranging setting for a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The currently set amplitude auto ranging setting: #TIEPIE_HW_BOOL_TRUE if enabled, #TIEPIE_HW_BOOL_FALSE if disabled.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The current signal type does not support signal amplitude (range).</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_amplitude_ranges
 * \see tiepie_hw_generator_get_amplitude_range
 * \see tiepie_hw_generator_set_amplitude_range
 * \see tiepie_hw_generator_set_amplitude_auto_ranging
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_get_amplitude_auto_ranging(tiepie_hw_handle handle);

/**
 * \brief Set the amplitude auto ranging setting for a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The required amplitude auto ranging setting: #TIEPIE_HW_BOOL_TRUE to enable or #TIEPIE_HW_BOOL_FALSE to disable.
 * \return The actually set amplitude auto ranging setting: #TIEPIE_HW_BOOL_TRUE if enabled, #TIEPIE_HW_BOOL_FALSE if disabled.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_CONTROLLABLE</td>       <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The current signal type does not support signal amplitude (range).</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \remark Setting amplitude auto ranging may affect the amplitude range.
 * \see tiepie_hw_generator_get_amplitude_ranges
 * \see tiepie_hw_generator_get_amplitude_range
 * \see tiepie_hw_generator_set_amplitude_range
 * \see tiepie_hw_generator_get_amplitude_auto_ranging
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_set_amplitude_auto_ranging(tiepie_hw_handle handle, tiepie_hw_bool value);

/**
 *           \}
 *         \}
 *         \defgroup gen_signal_offset Offset
 *         \{
 *           \brief Functions for controlling the offset of a generator.
 *
 * The offset of a generator can be set between a minimum and a maximum value.
 * Use tiepie_hw_generator_get_offset_min() and tiepie_hw_generator_get_offset_max() to get the offset limits.
 *
 * \ref gen_signal_amplitude and Offset combined cannot exceed the \ref tiepie_hw_generator_get_output_value_min "minimum" and
 * \ref tiepie_hw_generator_get_output_value_max "maximum" output value of the generator.
 * Setting a larger offset will clip the offset to a valid value.
 *
 * When the \ref tiepie_hw_generator_get_output_enable "generator ouput" is switched on but signal generation is \ref tiepie_hw_generator_stop "stopped",
 * the generator output will be at the currently set offset level.
 *
 * By default the offset is set to: 0 V.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether the current signal type of a specified generator supports controlling the signal offset.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return #TIEPIE_HW_BOOL_TRUE if supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_offset_min
 * \see tiepie_hw_generator_get_offset_max
 * \see tiepie_hw_generator_get_offset
 * \see tiepie_hw_generator_set_offset
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_has_offset(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Check whether the specified generator supports controlling the signal offset for a specified signal type.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \return #TIEPIE_HW_BOOL_TRUE if supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_has_offset_ex(tiepie_hw_handle handle, uint32_t signal_type);

//! \endcond

/**
 * \brief Get the minimum offset for the current signal type, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The minimum signal offset in Volt.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The requested signal type does not support signal offset.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_offset_max
 * \see tiepie_hw_generator_get_offset
 * \see tiepie_hw_generator_set_offset
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_offset_min(tiepie_hw_handle handle);

/**
 * \brief Get the maximum offset for the current signal type, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The maximum signal offset in Volt.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The requested signal type does not support signal offset.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_offset_min
 * \see tiepie_hw_generator_get_offset
 * \see tiepie_hw_generator_set_offset
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_offset_max(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Get the minimum and maximum offset for a specified signal type, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \param[out] min A pointer to a memory location for the minimum offset in Volt, or \c NULL.
 * \param[out] max A pointer to a memory location for the maximum offset in Volt, or \c NULL.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The requested signal type does not support signal offset.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_offset_min
 * \see tiepie_hw_generator_get_offset_max
 * \see tiepie_hw_generator_get_offset
 * \see tiepie_hw_generator_set_offset
 * \see tiepie_hw_generator_verify_offset
 * \see tiepie_hw_generator_verify_offset_ex
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_generator_get_offset_min_max_ex(tiepie_hw_handle handle, uint32_t signal_type, double* min, double* max);

//! \endcond

/**
 * \brief Get the current signal offset of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The currently set signal offset in Volt.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The requested signal type does not support signal offset.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_offset_min
 * \see tiepie_hw_generator_get_offset_max
 * \see tiepie_hw_generator_set_offset
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_offset(tiepie_hw_handle handle);

/**
 * \brief Set the signal offset of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested signal offset in Volt.
 * \return The actually set signal offset in Volt.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested offset is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested offset is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The current signal type does not support signal offset.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_CONTROLLABLE</td>       <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_offset_min
 * \see tiepie_hw_generator_get_offset_max
 * \see tiepie_hw_generator_get_offset
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_set_offset(tiepie_hw_handle handle, double value);

//! \cond EXTENDED_API

/**
 * \brief Verify if a signal offset can be set, of a specified generator, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested signal offset, in Volt.
 * \return The signal offset that would have been set, in Volt.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested offset is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested offset is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The current signal type does not support signal offset.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_offset_min
 * \see tiepie_hw_generator_get_offset_max
 * \see tiepie_hw_generator_get_offset_min_max_ex
 * \see tiepie_hw_generator_get_offset
 * \see tiepie_hw_generator_set_offset
 * \see tiepie_hw_generator_verify_offset_ex
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_verify_offset(tiepie_hw_handle handle, double value);

/**
 * \brief Verify if a signal offset can be set for a specified signal type and amplitude, of a specified generator, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested signal offset.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \param[in] amplitude The requested signal amplitude, ignored for #TIEPIE_HW_ST_dC.
 * \param[in] output_invert The requested output_invert.
 * \return The signal offset that would have been set, in Volt.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested offset is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested offset is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The current signal type does not support signal offset.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_offset_min
 * \see tiepie_hw_generator_get_offset_max
 * \see tiepie_hw_generator_get_offset_min_max_ex
 * \see tiepie_hw_generator_get_offset
 * \see tiepie_hw_generator_set_offset
 * \see tiepie_hw_generator_verify_offset
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_verify_offset_ex(tiepie_hw_handle handle, double value, uint32_t signal_type, double amplitude, tiepie_hw_bool output_invert);

//! \endcond

/**
 *         \}
 *         \defgroup gen_signal_frequency Frequency
 *         \{
 *           \brief Functions for controlling signal frequency, sample rate and frequency mode of a generator.
 *
 * The frequency of a generator can be set between a minimum and a maximum value.
 * Use tiepie_hw_generator_get_frequency_min() and tiepie_hw_generator_get_frequency_max() to get the frequency limits.
 *
 * The frequency setting can either set the signal frequency or the sample rate of the generator,
 * depending on the selected \ref gen_signal_frequency_mode.
 *
 * When \ref gen_signal_type "signal type" DC is active, frequency is not available.
 * Use tiepie_hw_generator_has_frequency() to check whether frequency is available for the currently set signal type.
 *
 * By default the frequency mode is set to signal frequency (#TIEPIE_HW_FM_SIGNALFREQUENCY) and the frequency is set to 1 k_hz.
 *
 *           \defgroup gen_signal_frequency_mode Frequency mode
 *           \{
 *             \brief Functions to control the generator frequency mode.
 *
 *  When signal type arbitrary is selected, the frequency mode of the Arbitrary waveform generator can be set.
 *  The following frequency modes are supported:
 *  - <b>Signal frequency</b> : the \ref tiepie_hw_generator_set_frequency "frequency property" sets the signal frequency, the frequency at which the selected signal will be repeated.
 *  - <b>Sample rate</b> : The \ref tiepie_hw_generator_set_frequency "frequency property" sets the sample rate at which the individual samples of the selected signal will be generated.
 *
 *  With signal types sine, triangle, square and DC, the frequency mode is fixed to signal frequency.
 *  With signal type noise the frequency mode is fixed to sample rate.
 *
 *  The frequency mode can be affected by changing the \ref gen_signal_type "signal type".
 *
 *  By default the frequency mode is set to signal frequency (#TIEPIE_HW_FM_SIGNALFREQUENCY)
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the supported generator frequency modes of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The supported generator frequency modes, a set of OR-ed \ref TIEPIE_HW_FM_ "TIEPIE_HW_FM_*" values, or #TIEPIE_HW_FMM_NONE.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support frequency mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_frequency_mode
 * \see tiepie_hw_generator_set_frequency_mode
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_generator_get_frequency_modes(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Get the supported generator frequency modes for a specified signal type, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \return The supported generator frequency modes for th especified signal type, a set of OR-ed \ref TIEPIE_HW_FM_ "TIEPIE_HW_FM_*" values, or #TIEPIE_HW_FMM_NONE.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support frequency mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_frequency_modes
 * \see tiepie_hw_generator_get_frequency_mode
 * \see tiepie_hw_generator_set_frequency_mode
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_generator_get_frequency_modes_ex(tiepie_hw_handle handle, uint32_t signal_type);

//! \endcond

/**
 * \brief Get the current generator frequency mode of a specified generator
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The currently set generator frequency mode, a \ref TIEPIE_HW_FM_ "TIEPIE_HW_FM_*" value, #TIEPIE_HW_FM_UNKNOWN when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support frequency mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_frequency_modes
 * \see tiepie_hw_generator_set_frequency_mode
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_generator_get_frequency_mode(tiepie_hw_handle handle);

/**
 * \brief Set the generator frequency mode of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested generator frequency mode, a \ref TIEPIE_HW_FM_ "TIEPIE_HW_FM_*" value.
 * \return The actually set generator frequency mode, a \ref TIEPIE_HW_FM_ "TIEPIE_HW_FM_*" value, #TIEPIE_HW_FM_UNKNOWN when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested frequency mode is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support generator mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_CONTROLLABLE</td>       <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \remark Setting frequency mode is only available when \ref gen_signal_type "signal type" Arbitrary is active.
 * \remark When \ref gen_signal_type "signal type" Sine, Triangle or Square is active, frequency mode is fixed at signal frequency.
 * \remark When \ref gen_signal_type "signal type" Noise is active, frequency mode is fixed at sample frequency.
 * \remark Changing the frequency mode can affect the \ref tiepie_hw_generator_set_mode "generator mode".
 * \see tiepie_hw_generator_get_frequency_modes
 * \see tiepie_hw_generator_get_frequency_mode
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_generator_set_frequency_mode(tiepie_hw_handle handle, uint32_t value);

/**
 *           \}
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether the current signal type and frequency mode of a specified generator support controlling the signal/sample frequency.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return #TIEPIE_HW_BOOL_TRUE if supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_frequency_min
 * \see tiepie_hw_generator_get_frequency_max
 * \see tiepie_hw_generator_get_frequency
 * \see tiepie_hw_generator_set_frequency
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_has_frequency(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Check whether the specified generator supports controlling the signal/sample frequency for the specified frequency mode and signal type.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] frequency_mode The requested generator frequency mode, a \ref TIEPIE_HW_FM_ "TIEPIE_HW_FM_*" value.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \return #TIEPIE_HW_BOOL_TRUE if supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_has_frequency_ex(tiepie_hw_handle handle, uint32_t frequency_mode, uint32_t signal_type);

//! \endcond

/**
 * \brief Get the minimum signal/sample frequency with the current frequency mode, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The minimum signal/sample frequency, in Hz.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support frequency for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_frequency_max
 * \see tiepie_hw_generator_get_frequency
 * \see tiepie_hw_generator_set_frequency
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_frequency_min(tiepie_hw_handle handle);

/**
 * \brief Get the maximum signal/sample frequency with the current frequency mode and signal type, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The maximum signal/sample frequency, in Hz.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support frequency for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_frequency_min
 * \see tiepie_hw_generator_get_frequency
 * \see tiepie_hw_generator_set_frequency
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_frequency_max(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Get the minimum and maximum signal/sample frequency for a specified frequency mode and the current signal type, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] frequency_mode The requested generator frequency mode, a \ref TIEPIE_HW_FM_ "TIEPIE_HW_FM_*" value.
 * \param[out] min A pointer to a memory location for the minimum frequency, or \c NULL.
 * \param[out] max A pointer to a memory location for the maximum frequency, or \c NULL.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested frequency mode is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support frequency for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_frequency_min
 * \see tiepie_hw_generator_get_frequency_max
 * \see tiepie_hw_generator_get_frequency_min_max_ex
 * \see tiepie_hw_generator_get_frequency
 * \see tiepie_hw_generator_set_frequency
 * \see tiepie_hw_generator_verify_frequency
 * \see tiepie_hw_generator_verify_frequency_ex
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_generator_get_frequency_min_max(tiepie_hw_handle handle, uint32_t frequency_mode, double* min, double* max);

/**
 * \brief Get the minimum and maximum signal/sample frequency for a specified frequency mode and signal type, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] frequency_mode The requested generator frequency mode, a \ref TIEPIE_HW_FM_ "TIEPIE_HW_FM_*" value.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \param[out] min A pointer to a memory location for the minimum frequency, or \c NULL.
 * \param[out] max A pointer to a memory location for the maximum frequency, or \c NULL.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested frequency mode and/or signal type is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support frequency for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_frequency_min
 * \see tiepie_hw_generator_get_frequency_max
 * \see tiepie_hw_generator_get_frequency_min_max
 * \see tiepie_hw_generator_get_frequency
 * \see tiepie_hw_generator_set_frequency
 * \see tiepie_hw_generator_verify_frequency
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_generator_get_frequency_min_max_ex(tiepie_hw_handle handle, uint32_t frequency_mode, uint32_t signal_type, double* min, double* max);

//! \endcond

/**
 * \brief Get the current signal/sample frequency, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The currently set signal/sample frequency, in Hz.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support frequency for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_frequency_min
 * \see tiepie_hw_generator_get_frequency_max
 * \see tiepie_hw_generator_set_frequency
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_frequency(tiepie_hw_handle handle);

/**
 * \brief Set signal/sample frequency, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested signal/sample frequency, in Hz.
 * \return The actually set signal/sample frequency, in Hz.
 * \remark When the generator is active, changing the signal/sample frequency will shortly interrupt the output signal.
 * \remark When \ref gen_signal_type "signal type" DC is active, setting signal/sample frequency is not available.
 * \remark Changing the frequency may affect the \ref gen_signal_width "pulse width" and/or \ref gen_signal_edge_time "leading and trailing edge time" value(s) when signal type \ref TIEPIE_HW_ST_PULSE "pulse" is active.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested frequency is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested frequency is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support frequency for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_CONTROLLABLE</td>       <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_frequency_min
 * \see tiepie_hw_generator_get_frequency_max
 * \see tiepie_hw_generator_get_frequency
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_set_frequency(tiepie_hw_handle handle, double value);

//! \cond EXTENDED_API

/**
 * \brief Verify if a signal/sample frequency can be set, of a specified generator, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested signal/sample rate, in Hz.
 * \return The signal/sample rate that would have been set, in Hz.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested frequency is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested frequency is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support frequency for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_frequency_min
 * \see tiepie_hw_generator_get_frequency_max
 * \see tiepie_hw_generator_get_frequency_min_max
 * \see tiepie_hw_generator_get_frequency_min_max_ex
 * \see tiepie_hw_generator_get_frequency
 * \see tiepie_hw_generator_verify_frequency_ex
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_verify_frequency(tiepie_hw_handle handle, double value);

/**
 * \brief  Verify if a signal/sample frequency can be set for a specified frequency mode, signal type and arbitrary waveform pattern length, of a specified generator, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested signal/sample frequency, in Hz.
 * \param[in] frequency_mode The requested generator frequency mode, a \ref TIEPIE_HW_FM_ "TIEPIE_HW_FM_*" value.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \param[in] data_length The requested Arbitrary waveform pattern length.
 * \param[in] width Pulse width in seconds, only for #TIEPIE_HW_ST_PULSE.
 * \return The signal/sample frequency that would have been set, in Hz.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested frequency is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested frequency is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested frequency mode, signal type, pattern length and/or width is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support frequency for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_frequency_min
 * \see tiepie_hw_generator_get_frequency_max
 * \see tiepie_hw_generator_get_frequency_min_max
 * \see tiepie_hw_generator_get_frequency_min_max_ex
 * \see tiepie_hw_generator_get_frequency
 * \see tiepie_hw_generator_verify_frequency
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_verify_frequency_ex(tiepie_hw_handle handle, double value, uint32_t frequency_mode, uint32_t signal_type, uint64_t data_length, double width);

//! \endcond


/**
 *         \}
 *         \defgroup gen_signal_phase Phase
 *         \{
 *           \brief Functions for controlling the phase of a generator.
 *
 * The phase defines the starting point in the period of the signal that is generated, as well as the ending point.
 * The phase of a generator can be set between a minimum and a maximum value.
 * Use tiepie_hw_generator_get_phase_min() and tiepie_hw_generator_get_phase_max() to get the phase limits.
 *
 * The phase is defined as a number between \c 0 and \c 1, where \c 0 defines the beginning of the period (\c 0&deg;)
 * and \c 1 defines the end of the period (\c 360&deg;).
 *
 * Phase is not available on all instruments and all signal types.
 * Use tiepie_hw_generator_has_phase() to check whether phase is available for your instrument and for the currently set signal type.
 *
 * By default the phase is set to: \c 0.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether the specified generator and the current signal type of the specified generator support controlling the signal phase.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return #TIEPIE_HW_BOOL_TRUE if supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_phase_min
 * \see tiepie_hw_generator_get_phase_max
 * \see tiepie_hw_generator_get_phase
 * \see tiepie_hw_generator_set_phase
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_has_phase(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Check whether the specified generator supports controlling the signal phase for a specified signal type.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \return #TIEPIE_HW_BOOL_TRUE if supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_has_phase_ex(tiepie_hw_handle handle, uint32_t signal_type);

//! \endcond

/**
 * \brief Get the minimum signal phase of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The minimum signal phase, a number between \c 0 and \c 1.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support phase for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_has_phase
 * \see tiepie_hw_generator_get_phase_max
 * \see tiepie_hw_generator_get_phase
 * \see tiepie_hw_generator_set_phase
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_phase_min(tiepie_hw_handle handle);

/**
 * \brief Get the maximum signal phase of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The maximum signal phase, a number between \c 0 and \c 1.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support phase for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_has_phase
 * \see tiepie_hw_generator_get_phase_min
 * \see tiepie_hw_generator_get_phase
 * \see tiepie_hw_generator_set_phase
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_phase_max(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Get the minimum and maximum phase for a specified signal type, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \param[out] min A pointer to a memory location for the minimum phase, or \c NULL.
 * \param[out] max A pointer to a memory location for the maximum phase, or \c NULL.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support phase for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_phase_min
 * \see tiepie_hw_generator_get_phase_max
 * \see tiepie_hw_generator_get_phase
 * \see tiepie_hw_generator_set_phase
 * \see tiepie_hw_generator_verify_phase
 * \see tiepie_hw_generator_verify_phase_ex
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_generator_get_phase_min_max_ex(tiepie_hw_handle handle, uint32_t signal_type, double* min, double* max);

//! \endcond

/**
 * \brief Get the current signal phase of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The currently set signal phase, a number between \c 0 and \c 1.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support phase for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_has_phase
 * \see tiepie_hw_generator_get_phase_min
 * \see tiepie_hw_generator_get_phase_max
 * \see tiepie_hw_generator_set_phase
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_phase(tiepie_hw_handle handle);

/**
 * \brief Set the signal phase of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested signal phase, a number between \c 0 and \c 1.
 * \return The actually set signal phase, a number between \c 0 and \c 1.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested phase is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested phase is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support phase for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_CONTROLLABLE</td>       <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \remark When the generator is active, changing the phase will shortly interrupt the output signal.
 * \remark When \ref gen_signal_type "signal type" DC or Noise is active, setting phase is not available.
 * \see tiepie_hw_generator_has_phase
 * \see tiepie_hw_generator_get_phase_min
 * \see tiepie_hw_generator_get_phase_max
 * \see tiepie_hw_generator_get_phase
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_set_phase(tiepie_hw_handle handle, double value);

//! \cond EXTENDED_API

/**
 * \brief Verify if a phase can be set, of a specified generator, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested signal phase, a number between \c 0 and \c 1.
 * \return The signal phase that would have been set, a number between \c 0 and \c 1.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested phase is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested phase is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support phase for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_phase_min
 * \see tiepie_hw_generator_get_phase_max
 * \see tiepie_hw_generator_get_phase_min_max_ex
 * \see tiepie_hw_generator_get_phase
 * \see tiepie_hw_generator_set_phase
 * \see tiepie_hw_generator_verify_phase_ex
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_verify_phase(tiepie_hw_handle handle, double value);

/**
 * \brief Verify if a phase can be set for a specific signal type, of a specified generator, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested signal phase, a number between \c 0 and \c 1.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \return The signal phase that would have been set, a number between \c 0 and \c 1.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested phase is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested phase is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support phase for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_phase_min
 * \see tiepie_hw_generator_get_phase_max
 * \see tiepie_hw_generator_get_phase_min_max_ex
 * \see tiepie_hw_generator_get_phase
 * \see tiepie_hw_generator_set_phase
 * \see tiepie_hw_generator_verify_phase
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_verify_phase_ex(tiepie_hw_handle handle, double value, uint32_t signal_type);

//! \endcond

/**
 *         \}
 *         \defgroup gen_signal_symmetry Symmetry
 *         \{
 *           \brief Functions for controlling the signal symmetry of a generator.
 *
 * The symmetry of a signal defines the ratio between the length of positive part of a period and the length of the negative part
 * of a period of the generated signal.
 * The symmetry of a generator can be set between a minimum and a maximum value.
 * Use tiepie_hw_generator_get_symmetry_min() and tiepie_hw_generator_get_symmetry_max() to get the symmetry limits.
 *
 * The symmetry is defined as a number between \c 0 and \c 1, where \c 0 defines a symmetry of 0% (no positive part)
 * and \c 1 defines a symmetry of 100% (no negative part).
 *
 * When \ref gen_signal_type "signal type" Pulse, DC, Noise or Arbitrary is active, setting symmetry is not available.
 * Use tiepie_hw_generator_has_symmetry() to check whether symmetry is available for the currently set signal type.
 *
 * By default the symmetry is set to: 0.5 (50%).
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether the current signal type of a specified generator supports controlling the signal symmetry.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return #TIEPIE_HW_BOOL_TRUE if supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_symmetry_min
 * \see tiepie_hw_generator_get_symmetry_max
 * \see tiepie_hw_generator_get_symmetry
 * \see tiepie_hw_generator_set_symmetry
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_has_symmetry(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Check whether the specified generator supports controlling the signal symmetry for a specified signal type.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \return #TIEPIE_HW_BOOL_TRUE if supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_has_symmetry_ex(tiepie_hw_handle handle, uint32_t signal_type);

//! \endcond

/**
 * \brief Get the minimum signal symmetry of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The minimum signal symmetry, a number between \c 0 and \c 1.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support symmetry for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_symmetry_max
 * \see tiepie_hw_generator_get_symmetry
 * \see tiepie_hw_generator_set_symmetry
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_symmetry_min(tiepie_hw_handle handle);

/**
 * \brief Get the maximum signal symmetry of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The maximum signal symmetry, a number between \c 0 and \c 1.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support symmetry for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_symmetry_min
 * \see tiepie_hw_generator_get_symmetry
 * \see tiepie_hw_generator_set_symmetry
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_symmetry_max(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Get the minimum and maximum symmetry for a specified signal type, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \param[out] min A pointer to a memory location for the minimum symmetry, or \c NULL.
 * \param[out] max A pointer to a memory location for the maximum symmetry, or \c NULL.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support symmetry for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_symmetry_min
 * \see tiepie_hw_generator_get_symmetry_max
 * \see tiepie_hw_generator_get_symmetry
 * \see tiepie_hw_generator_set_symmetry
 * \see tiepie_hw_generator_verify_symmetry
 * \see tiepie_hw_generator_verify_symmetry_ex
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_generator_get_symmetry_min_max_ex(tiepie_hw_handle handle, uint32_t signal_type, double* min, double* max);

//! \endcond

/**
 * \brief Get the current signal symmetry of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The currently set signal symmetry, a number between \c 0 and \c 1.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support symmetry for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_symmetry_min
 * \see tiepie_hw_generator_get_symmetry_max
 * \see tiepie_hw_generator_set_symmetry
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_symmetry(tiepie_hw_handle handle);

/**
 * \brief Set the signal symmetry of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested signal symmetry, a number between \c 0 and \c 1.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested symmetry is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested symmetry is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support symmetry for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_CONTROLLABLE</td>       <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \return The actually set signal symmetry, a number between \c 0 and \c 1.
 * \remark When the generator is active, changing the symmetry will shortly interrupt the output signal.
 * \see tiepie_hw_generator_get_symmetry_min
 * \see tiepie_hw_generator_get_symmetry_max
 * \see tiepie_hw_generator_get_symmetry
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_set_symmetry(tiepie_hw_handle handle, double value);

//! \cond EXTENDED_API

/**
 * \brief Verify if a symmetry can be set, of a specified generator, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested signal symmetry, a number between \c 0 and \c 1.
 * \return The signal symmetry that would have been set, a number between \c 0 and \c 1.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested symmetry is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested symmetry is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support symmetry for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_symmetry_min
 * \see tiepie_hw_generator_get_symmetry_max
 * \see tiepie_hw_generator_get_symmetry_min_max_ex
 * \see tiepie_hw_generator_get_symmetry
 * \see tiepie_hw_generator_set_symmetry
 * \see tiepie_hw_generator_verify_symmetry_ex
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_verify_symmetry(tiepie_hw_handle handle, double value);

/**
 * \brief Verify if a symmetry can be set for a specific signal type, of a specified generator, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested signal symmetry, a number between \c 0 and \c 1.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \return The signal symmetry that would have been set, a number between \c 0 and \c 1.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested symmetry is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested symmetry is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support symmetry for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_symmetry_min
 * \see tiepie_hw_generator_get_symmetry_max
 * \see tiepie_hw_generator_get_symmetry_min_max_ex
 * \see tiepie_hw_generator_get_symmetry
 * \see tiepie_hw_generator_set_symmetry
 * \see tiepie_hw_generator_verify_symmetry
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_verify_symmetry_ex(tiepie_hw_handle handle, double value, uint32_t signal_type);

//! \endcond

/**
 *         \}
 *         \defgroup gen_signal_width Pulse width
 *         \{
 *           \brief Functions for controlling the pulse width of a generator.
 *
 * The pulse width defines the width of the pulse when \ref gen_signal_type "signal type" is set to #TIEPIE_HW_ST_PULSE, without affecting the
 * \ref gen_signal_frequency "signal frequency".
 * \image html PulseDefinition.png
 * The pulse width is defined as the time between 50% of the leading edge of the pulse and 50% of the trailing edge of the pulse,
 * in seconds. See also \ref gen_signal_edge_time "pulse edge times".
 *
 * The pulse width of a generator can be set between a minimum and a maximum value.
 * Use tiepie_hw_generator_get_width_min() and tiepie_hw_generator_get_width_max() to get the pulse width limits.
 *
 * The pulse width can be affected by changing the \ref gen_signal_frequency "signal frequency".
 *
 * The pulse width is not available on all instruments and only available for \ref gen_signal_type "signal type" Pulse.
 * Use tiepie_hw_generator_has_width() to check whether pulse width is available for your instrument and the currently set signal type.
 *
 * By default the pulse width is set to: 1 us.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether the current signal type of a specified generator supports controlling the signal pulse width.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return #TIEPIE_HW_BOOL_TRUE if supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_width_min
 * \see tiepie_hw_generator_get_width_max
 * \see tiepie_hw_generator_get_width
 * \see tiepie_hw_generator_set_width
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_has_width(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Check whether the specified generator supports controlling the signal pulse width for a specified signal type.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \return #TIEPIE_HW_BOOL_TRUE if supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_has_width_ex(tiepie_hw_handle handle, uint32_t signal_type);

//! \endcond

/**
 * \brief Get the minimum pulse width with the current signal frequency, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The minimum pulse width in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support pulse width for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_width_max
 * \see tiepie_hw_generator_get_width
 * \see tiepie_hw_generator_set_width
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_width_min(tiepie_hw_handle handle);

/**
 * \brief Get the maximum pulse width with the current signal frequency, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The maximum pulse width in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support pulse width for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_width_min
 * \see tiepie_hw_generator_get_width
 * \see tiepie_hw_generator_set_width
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_width_max(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Get the minimum and maximum pulse width for a specified signal type and signal frequency, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \param[in] signal_frequency The requested signal frequency in Hz.
 * \param[out] min A pointer to a memory location for the minimum pulse width, or \c NULL.
 * \param[out] max A pointer to a memory location for the maximum pulse width, or \c NULL.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type and/or signal frequency is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support pulse width for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_width_min
 * \see tiepie_hw_generator_get_width_max
 * \see tiepie_hw_generator_get_width
 * \see tiepie_hw_generator_set_width
 * \see tiepie_hw_generator_verify_width
 * \see tiepie_hw_generator_verify_width_ex
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_generator_get_width_min_max_ex(tiepie_hw_handle handle, uint32_t signal_type, double signal_frequency, double* min, double* max);

//! \endcond

/**
 * \brief Get the current pulse width, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The currently set pulse width in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support pulse width for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_width_min
 * \see tiepie_hw_generator_get_width_max
 * \see tiepie_hw_generator_set_width
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_width(tiepie_hw_handle handle);

/**
 * \brief Set the pulse width, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested pulse width in seconds.
 * \return The actually set pulse width in seconds
 * \remark When the generator is active, changing the pulse width will shortly interrupt the output signal.
 * \remark Changing the pulse width may affect the \ref gen_signal_edge_time "leading and trailing edge time" value(s).
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested pulse width is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested pulse width is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support pulse width for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_CONTROLLABLE</td>       <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_width_min
 * \see tiepie_hw_generator_get_width_max
 * \see tiepie_hw_generator_get_width
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_set_width(tiepie_hw_handle handle, double value);

//! \cond EXTENDED_API

/**
 * \brief Verify if a pulse width can be set, of a specified generator, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested pulse width in seconds.
 * \return The pulse width that would have been set, in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested pulse width is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested pulse width is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support pulse width for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_width_min
 * \see tiepie_hw_generator_get_width_max
 * \see tiepie_hw_generator_get_width_min_max_ex
 * \see tiepie_hw_generator_get_width
 * \see tiepie_hw_generator_set_width
 * \see tiepie_hw_generator_verify_width_ex
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_verify_width(tiepie_hw_handle handle, double value);

/**
 * \brief Verify if a pulse width can be set for a specific signal type and signal frequency, of a specified generator, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested pulse width in seconds.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \param[in] signal_frequency The requested signal frequency in Hz.
 * \return pulse width in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested pulse width is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested pulse width is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type and/or signal frequency is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support pulse width for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_width_min
 * \see tiepie_hw_generator_get_width_max
 * \see tiepie_hw_generator_get_width_min_max_ex
 * \see tiepie_hw_generator_get_width
 * \see tiepie_hw_generator_set_width
 * \see tiepie_hw_generator_verify_width
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_verify_width_ex(tiepie_hw_handle handle, double value, uint32_t signal_type, double signal_frequency);

//! \endcond

/**
 *         \}
 *         \defgroup gen_signal_edge_time Pulse edge time
 *         \{
 *           \brief Functions for controlling the signal edge times of a generator.
 *
 * A pulse signal has a leading edge and a trailing edge.
 * The duration of these edges can be set individually between a minimum and a maximum value.
 * \image html PulseDefinition.png
 * For a positive pulse, the leading edge time is defined as the time it takes for the signal to go from 10% of the pulse height
 * to 90% of the pulse height.
 * And the trailing edge time is defined as the time it takes for the signal to go from 90% of the pulse height
 * to 10% of the pulse height.
 *
 * For a negative pulse, the leading edge time is defined as the time it takes for the signal to go from 90% of the pulse height
 * to 10% of the pulse height.
 * And the trailing edge time is defined as the time it takes for the signal to go from 10% of the pulse height
 * to 90% of the pulse height.
 *
 * Controlling the edge times is not available on all instruments and only available for \ref gen_signal_type "signal type" Pulse.
 * Use tiepie_hw_generator_has_edge_time() to check whether your instrument and the current signal type of a specified generator support controlling the edge times.
 * Use tiepie_hw_generator_get_leading_edge_time_min(), tiepie_hw_generator_get_leading_edge_time_max(), tiepie_hw_generator_get_trailing_edge_time_min() and tiepie_hw_generator_get_trailing_edge_time_max() to get the edge time limits.
 * The minimum and maximum edge times depend on the currently set \ref gen_signal_width "pulse width" and \ref gen_signal_frequency "signal frequency" (period).
 *
 * The edge times are defined in seconds.
 *
 * The leading edge time and trailing edge time can be affected by changing the \ref gen_signal_frequency "signal frequency" or \ref gen_signal_width "pulse width".
 *
 * By default the edge times are set to: 8 ns.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether the current signal type of a specified generator supports controlling the edge times.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return #TIEPIE_HW_BOOL_TRUE if supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_leading_edge_time_min
 * \see tiepie_hw_generator_get_leading_edge_time_max
 * \see tiepie_hw_generator_get_leading_edge_time
 * \see tiepie_hw_generator_set_leading_edge_time
 * \see tiepie_hw_generator_get_trailing_edge_time_min
 * \see tiepie_hw_generator_get_trailing_edge_time_max
 * \see tiepie_hw_generator_get_trailing_edge_time
 * \see tiepie_hw_generator_set_trailing_edge_time
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_has_edge_time(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Check whether the specified generator supports controlling the edge times for a specified signal type.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \return #TIEPIE_HW_BOOL_TRUE if supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_has_edge_time
 * \see tiepie_hw_generator_get_leading_edge_time_min
 * \see tiepie_hw_generator_get_leading_edge_time_max
 * \see tiepie_hw_generator_get_leading_edge_time_min_max_ex
 * \see tiepie_hw_generator_get_leading_edge_time
 * \see tiepie_hw_generator_set_leading_edge_time
 * \see tiepie_hw_generator_verify_leading_edge_time
 * \see tiepie_hw_generator_verify_leading_edge_time_ex
 * \see tiepie_hw_generator_get_trailing_edge_time_min
 * \see tiepie_hw_generator_get_trailing_edge_time_max
 * \see tiepie_hw_generator_get_trailing_edge_time_min_max_ex
 * \see tiepie_hw_generator_get_trailing_edge_time
 * \see tiepie_hw_generator_set_trailing_edge_time
 * \see tiepie_hw_generator_verify_trailing_edge_time
 * \see tiepie_hw_generator_verify_trailing_edge_time_ex
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_has_edge_time_ex(tiepie_hw_handle handle, uint32_t signal_type);

//! \endcond

/**
 * \brief Get the minimum leading edge time with the current pulse width and signal frequency, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The minimum leading edge time in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support edge times for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_has_edge_time
 * \see tiepie_hw_generator_get_leading_edge_time_max
 * \see tiepie_hw_generator_get_leading_edge_time
 * \see tiepie_hw_generator_set_leading_edge_time
 * \see tiepie_hw_generator_get_trailing_edge_time_min
 * \see tiepie_hw_generator_get_trailing_edge_time_max
 * \see tiepie_hw_generator_get_trailing_edge_time
 * \see tiepie_hw_generator_set_trailing_edge_time
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_leading_edge_time_min(tiepie_hw_handle handle);

/**
 * \brief Get the maximum leading edge time with the current pulse width and signal frequency, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The maximum leading edge time in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support edge times for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_has_edge_time
 * \see tiepie_hw_generator_get_leading_edge_time_min
 * \see tiepie_hw_generator_get_leading_edge_time
 * \see tiepie_hw_generator_set_leading_edge_time
 * \see tiepie_hw_generator_get_trailing_edge_time_min
 * \see tiepie_hw_generator_get_trailing_edge_time_max
 * \see tiepie_hw_generator_get_trailing_edge_time
 * \see tiepie_hw_generator_set_trailing_edge_time
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_leading_edge_time_max(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Get the minimum and maximum leading edge time of a specified generator with the requested signal type, frequency, symmetry, pulse width and trailing edge time.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \param[in] signal_frequency The requested signal frequency in Hz.
 * \param[in] symmetry The requested signal symmetry, a number between \c 0 and \c 1.
 * \param[in] width The requested pulse width in seconds.
 * \param[in] trailing_edge_time The requested trailing edge time in seconds.
 * \param[out] min A pointer to a memory location for the minimum leading edge time, or \c NULL.
 * \param[out] max A pointer to a memory location for the maximum leading edge time, or \c NULL.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type frequency, symmetry, pulse width and/or trailing edge time is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_has_edge_time
 * \see tiepie_hw_generator_has_edge_time_ex
 * \see tiepie_hw_generator_get_leading_edge_time_min
 * \see tiepie_hw_generator_get_leading_edge_time_max
 * \see tiepie_hw_generator_get_leading_edge_time
 * \see tiepie_hw_generator_set_leading_edge_time
 * \see tiepie_hw_generator_verify_leading_edge_time
 * \see tiepie_hw_generator_verify_leading_edge_time_ex
 * \see tiepie_hw_generator_get_trailing_edge_time_min
 * \see tiepie_hw_generator_get_trailing_edge_time_max
 * \see tiepie_hw_generator_get_trailing_edge_time_min_max_ex
 * \see tiepie_hw_generator_get_trailing_edge_time
 * \see tiepie_hw_generator_set_trailing_edge_time
 * \see tiepie_hw_generator_verify_trailing_edge_time
 * \see tiepie_hw_generator_verify_trailing_edge_time_ex
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_generator_get_leading_edge_time_min_max_ex(tiepie_hw_handle handle, uint32_t signal_type, double signal_frequency, double symmetry, double width, double trailing_edge_time, double* min, double* max);

//! \endcond

/**
 * \brief Get the current leading edge time with the current pulse width and signal frequency, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The currently set leading edge time in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support edge times for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_has_edge_time
 * \see tiepie_hw_generator_get_leading_edge_time_min
 * \see tiepie_hw_generator_get_leading_edge_time_max
 * \see tiepie_hw_generator_set_leading_edge_time
 * \see tiepie_hw_generator_get_trailing_edge_time_min
 * \see tiepie_hw_generator_get_trailing_edge_time_max
 * \see tiepie_hw_generator_get_trailing_edge_time
 * \see tiepie_hw_generator_set_trailing_edge_time
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_leading_edge_time(tiepie_hw_handle handle);

/**
 * \brief Set the leading edge time, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] leading_edge_time The requested leading edge time in seconds.
 * \return The actually set leading edge time in seconds.
 * \remark When the generator is active, changing the leading edge time will shortly interrupt the output signal.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested edge time is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested edge time is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support edge times for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_CONTROLLABLE</td>       <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_has_edge_time
 * \see tiepie_hw_generator_get_leading_edge_time_min
 * \see tiepie_hw_generator_get_leading_edge_time_max
 * \see tiepie_hw_generator_get_leading_edge_time
 * \see tiepie_hw_generator_get_trailing_edge_time_min
 * \see tiepie_hw_generator_get_trailing_edge_time_max
 * \see tiepie_hw_generator_get_trailing_edge_time
 * \see tiepie_hw_generator_set_trailing_edge_time
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_set_leading_edge_time(tiepie_hw_handle handle, double leading_edge_time);

//! \cond EXTENDED_API

/**
 * \brief Verify if a leading edge time can be set for the current signal type and signal frequency, of a specified generator, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] leading_edge_time The requested leading edge time in seconds.
 * \return The leading edge time that would have been set, in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested edge time is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested edge time is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support edge times for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_has_edge_time
 * \see tiepie_hw_generator_has_edge_time_ex
 * \see tiepie_hw_generator_get_leading_edge_time_min
 * \see tiepie_hw_generator_get_leading_edge_time_max
 * \see tiepie_hw_generator_get_leading_edge_time_min_max_ex
 * \see tiepie_hw_generator_get_leading_edge_time
 * \see tiepie_hw_generator_set_leading_edge_time
 * \see tiepie_hw_generator_verify_leading_edge_time_ex
 * \see tiepie_hw_generator_get_trailing_edge_time_min
 * \see tiepie_hw_generator_get_trailing_edge_time_max
 * \see tiepie_hw_generator_get_trailing_edge_time_min_max_ex
 * \see tiepie_hw_generator_get_trailing_edge_time
 * \see tiepie_hw_generator_set_trailing_edge_time
 * \see tiepie_hw_generator_verify_trailing_edge_time
 * \see tiepie_hw_generator_verify_trailing_edge_time_ex
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_verify_leading_edge_time(tiepie_hw_handle handle, double leading_edge_time);

/**
 * \brief Verify if a leading edge time can be set for a specified generator, with the specified signal type, frequency, symmetrym pulse width and trailing edge time, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] leading_edge_time The requested leading edge time in seconds.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \param[in] signal_frequency The requested signal frequency in Hz.
 * \param[in] symmetry The requested signal symmetry, a number between \c 0 and \c 1.
 * \param[in] width The requested pulse width in seconds.
 * \param[in] trailing_edge_time The requested trailing edge time in seconds.
 * \return The leading edge time that would have been set, in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested edge time is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested edge time is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support edge times for the requested signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_has_edge_time
 * \see tiepie_hw_generator_has_edge_time_ex
 * \see tiepie_hw_generator_get_leading_edge_time_min
 * \see tiepie_hw_generator_get_leading_edge_time_max
 * \see tiepie_hw_generator_get_leading_edge_time_min_max_ex
 * \see tiepie_hw_generator_get_leading_edge_time
 * \see tiepie_hw_generator_set_leading_edge_time
 * \see tiepie_hw_generator_verify_leading_edge_time
 * \see tiepie_hw_generator_get_trailing_edge_time_min
 * \see tiepie_hw_generator_get_trailing_edge_time_max
 * \see tiepie_hw_generator_get_trailing_edge_time_min_max_ex
 * \see tiepie_hw_generator_get_trailing_edge_time
 * \see tiepie_hw_generator_set_trailing_edge_time
 * \see tiepie_hw_generator_verify_trailing_edge_time
 * \see tiepie_hw_generator_verify_trailing_edge_time_ex
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_verify_leading_edge_time_ex(tiepie_hw_handle handle, double leading_edge_time, uint32_t signal_type, double signal_frequency, double symmetry, double width, double trailing_edge_time);

//! \endcond

/**
 * \brief Get the minimum trailing edge time with the current pulse width and signal frequency, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The minimum trailing edge time in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support edge times for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_has_edge_time
 * \see tiepie_hw_generator_get_leading_edge_time_min
 * \see tiepie_hw_generator_get_leading_edge_time_max
 * \see tiepie_hw_generator_get_leading_edge_time
 * \see tiepie_hw_generator_set_leading_edge_time
 * \see tiepie_hw_generator_get_trailing_edge_time_max
 * \see tiepie_hw_generator_get_trailing_edge_time
 * \see tiepie_hw_generator_set_trailing_edge_time
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_trailing_edge_time_min(tiepie_hw_handle handle);

/**
 * \brief Get the maximum trailing edge time with the current pulse width and signal frequency, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The maximum trailing edge time in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support edge times for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_has_edge_time
 * \see tiepie_hw_generator_get_leading_edge_time_min
 * \see tiepie_hw_generator_get_leading_edge_time_max
 * \see tiepie_hw_generator_get_leading_edge_time
 * \see tiepie_hw_generator_set_leading_edge_time
 * \see tiepie_hw_generator_get_trailing_edge_time_min
 * \see tiepie_hw_generator_get_trailing_edge_time
 * \see tiepie_hw_generator_set_trailing_edge_time
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_trailing_edge_time_max(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Get the minimum and maximum trailing edge time of a specified generator with the requested signal type, frequency, symmetry, pulse width and leading edge time.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \param[in] signal_frequency The requested signal frequency in Hz.
 * \param[in] symmetry The requested signal symmetry, a number between \c 0 and \c 1.
 * \param[in] width The requested pulse width in seconds.
 * \param[in] leading_edge_time The requested trailing edge time in seconds.
 * \param[out] min A pointer to a memory location for the minimum trailing edge time, or \c NULL.
 * \param[out] max A pointer to a memory location for the maximum trailing edge time, or \c NULL.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type frequency, symmetry, pulse width and/or leading edge time is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_has_edge_time
 * \see tiepie_hw_generator_has_edge_time_ex
 * \see tiepie_hw_generator_get_leading_edge_time_min
 * \see tiepie_hw_generator_get_leading_edge_time_max
 * \see tiepie_hw_generator_get_leading_edge_time_min_max_ex
 * \see tiepie_hw_generator_get_leading_edge_time
 * \see tiepie_hw_generator_set_leading_edge_time
 * \see tiepie_hw_generator_verify_leading_edge_time
 * \see tiepie_hw_generator_verify_leading_edge_time_ex
 * \see tiepie_hw_generator_get_trailing_edge_time_min
 * \see tiepie_hw_generator_get_trailing_edge_time_max
 * \see tiepie_hw_generator_get_trailing_edge_time
 * \see tiepie_hw_generator_set_trailing_edge_time
 * \see tiepie_hw_generator_verify_trailing_edge_time
 * \see tiepie_hw_generator_verify_trailing_edge_time_ex
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_generator_get_trailing_edge_time_min_max_ex(tiepie_hw_handle handle, uint32_t signal_type, double signal_frequency, double symmetry, double width, double leading_edge_time, double* min, double* max);

//! \endcond

/**
 * \brief Get the current trailing edge time with the current pulse width and signal frequency, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The currently set trailing edge time in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support edge times for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_has_edge_time
 * \see tiepie_hw_generator_get_leading_edge_time_min
 * \see tiepie_hw_generator_get_leading_edge_time_max
 * \see tiepie_hw_generator_get_leading_edge_time
 * \see tiepie_hw_generator_set_leading_edge_time
 * \see tiepie_hw_generator_get_trailing_edge_time_min
 * \see tiepie_hw_generator_get_trailing_edge_time_max
 * \see tiepie_hw_generator_set_trailing_edge_time
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_get_trailing_edge_time(tiepie_hw_handle handle);

/**
 * \brief Set the trailing edge time, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested trailing edge time in seconds.
 * \return The actually set trailing edge time in seconds.
 * \remark When the generator is active, changing the trailing edge time will shortly interrupt the output signal.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested edge time is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested edge time is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support edge times for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_CONTROLLABLE</td>       <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_has_edge_time
 * \see tiepie_hw_generator_get_leading_edge_time_min
 * \see tiepie_hw_generator_get_leading_edge_time_max
 * \see tiepie_hw_generator_get_leading_edge_time
 * \see tiepie_hw_generator_set_leading_edge_time
 * \see tiepie_hw_generator_get_trailing_edge_time_min
 * \see tiepie_hw_generator_get_trailing_edge_time_max
 * \see tiepie_hw_generator_get_trailing_edge_time
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_set_trailing_edge_time(tiepie_hw_handle handle, double value);

//! \cond EXTENDED_API

/**
 * \brief Verify if a trailing edge time can be set for the current signal type and signal frequency, of a specified generator, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested trailing edge time in seconds.
 * \return The trailing edge time that would have been set, in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested edge time is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested edge time is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support edge times for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_has_edge_time
 * \see tiepie_hw_generator_has_edge_time_ex
 * \see tiepie_hw_generator_get_leading_edge_time_min
 * \see tiepie_hw_generator_get_leading_edge_time_max
 * \see tiepie_hw_generator_get_leading_edge_time_min_max_ex
 * \see tiepie_hw_generator_get_leading_edge_time
 * \see tiepie_hw_generator_set_leading_edge_time
 * \see tiepie_hw_generator_verify_leading_edge_time
 * \see tiepie_hw_generator_verify_leading_edge_time_ex
 * \see tiepie_hw_generator_get_trailing_edge_time_min
 * \see tiepie_hw_generator_get_trailing_edge_time_max
 * \see tiepie_hw_generator_get_trailing_edge_time
 * \see tiepie_hw_generator_set_trailing_edge_time
 * \see tiepie_hw_generator_verify_trailing_edge_time_ex
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_verify_trailing_edge_time(tiepie_hw_handle handle, double value);

/**
 * \brief Verify if a trailing edge time can be set for a specified generator, with the specified signal type, frequency, symmetrym pulse width and trailing edge time, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] trailing_edge_time The requested trailing edge time in seconds.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \param[in] signal_frequency The requested signal frequency in Hz.
 * \param[in] symmetry The requested signal symmetry, a number between \c 0 and \c 1.
 * \param[in] width The requested pulse width in seconds.
 * \param[in] leading_edge_time The requested leading edge time in seconds.
 * \return The trailing edge time that would have been set, in seconds.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested edge time is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested edge time is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support edge times for the requested signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_has_edge_time
 * \see tiepie_hw_generator_has_edge_time_ex
 * \see tiepie_hw_generator_get_leading_edge_time_min
 * \see tiepie_hw_generator_get_leading_edge_time_max
 * \see tiepie_hw_generator_get_leading_edge_time_min_max_ex
 * \see tiepie_hw_generator_get_leading_edge_time
 * \see tiepie_hw_generator_set_leading_edge_time
 * \see tiepie_hw_generator_verify_leading_edge_time
 * \see tiepie_hw_generator_verify_leading_edge_time_ex
 * \see tiepie_hw_generator_get_trailing_edge_time_min
 * \see tiepie_hw_generator_get_trailing_edge_time_max
 * \see tiepie_hw_generator_get_trailing_edge_time
 * \see tiepie_hw_generator_set_trailing_edge_time
 * \see tiepie_hw_generator_verify_trailing_edge_time
 * \since 1.0
 */
TIEPIE_HW_API double tiepie_hw_generator_verify_trailing_edge_time_ex(tiepie_hw_handle handle, double trailing_edge_time, uint32_t signal_type, double signal_frequency, double symmetry, double width, double leading_edge_time);

//! \endcond

/**
 *         \}
 *         \defgroup gen_signal_data Arbitrary waveform buffer
 *         \{
 *           \brief Functions for controlling the arbitrary waveform buffer of a generator.
 *
 * A generator has a buffer in which arbitrary waveform patterns can be loaded, after which the loaded pattern can be generated,
 * when the \ref gen_signal_type "signal type" is set to #TIEPIE_HW_ST_ARBITRARY.
 * Waveform patterns must have a length in samples between a minimum and maximum value.
 * Use tiepie_hw_generator_get_data_length_min() and tiepie_hw_generator_get_data_length_max() to get the buffer length limits in samples.
 *
 * When the \ref gen_signal_frequency_mode "frequency mode" is set to "signal frequency", the loaded pattern is treated as one period
 * of the signal to generate.
 * When the \ref gen_signal_frequency_mode "frequency mode" is set to "sample rate", the samples of the loaded pattern are generated
 * at the set sample rate.
 *
 * The samples in the waveform pattern buffer represent the voltage values of the signal to generate.
 * These sample values are unitless floating point values.
 * Positive values represent the positive part of the signal.
 * Negative values represent the negative part of the signal.
 * When loading the buffer, the values in the buffer are normalized:
 * - a value \c 0 (zero) will equal the set \ref gen_signal_offset "offset" value.
 * - the highest absolute value will equal the set \ref gen_signal_amplitude "amplitude" value.
 *
 * <b>Example pattern:</b>
 *
 * <table>
 *   <tr>                    <th>Sample number</th><th>Buffer value</th><th>Generated voltage<br><small>Amplitude = 7 V<br>Offset = 0 V</small></th><th>Generated voltage<br><small>Amplitude = 4V<br>Offset = -1 V</small></th></tr>
 *   <tr class="signal_types"><td>            0</td><td> 0.0        </td><td> 0.0 V                                                             </td><td>-1.0 V           </td></tr>
 *   <tr class="signal_types"><td>            1</td><td> 0.5        </td><td> 3.5 V                                                             </td><td> 1.0 V           </td></tr>
 *   <tr class="signal_types"><td>            2</td><td> 1.0        </td><td> 7.0 V                                                             </td><td> 3.0 V           </td></tr>
 *   <tr class="signal_types"><td>            3</td><td> 0.5        </td><td> 3.5 V                                                             </td><td> 1.0 V           </td></tr>
 *   <tr class="signal_types"><td>            4</td><td> 0.0        </td><td> 0.0 V                                                             </td><td>-1.0 V           </td></tr>
 *   <tr class="signal_types"><td>            5</td><td>-0.5        </td><td>-3.5 V                                                             </td><td>-3.0 V           </td></tr>
 *   <tr class="signal_types"><td>            6</td><td>-1.0        </td><td>-7.0 V                                                             </td><td>-5.0 V           </td></tr>
 *   <tr class="signal_types"><td>            7</td><td>-0.5        </td><td>-3.5 V                                                             </td><td>-3.0 V           </td></tr>
 * </table>
 *
 * There are a few limitations with the arbitrary waveform pattern length:
 *
 * <b>Handyscope HS5</b> / <b>WiFiScope WS5</b>: for pattern lengths larger than 128 Ki_samples (131072 samples),
 * the pattern length must be a multiple of 4 samples. When the length is not a multiple of 4, the data will be resampled to the
 * closest smaller multiple of 4 samples.
 * For pattern lengths smaller than 128 Ki_samples, there are no length limitations.
 *
 * <b>Handyscope HS3</b>: patterns must have a length that is a "power of 2" samples long, e.g. 1024, 2048, 4096,  etc..
 * When the length is not a power of 2, the data will be resampled (stretched) to the closest larger power of 2 samples.
 *
 * When uploading patterns that get resampled, tiepie_hw_generator_set_data() will set status #TIEPIE_HW_STATUS_VALUE_MODIFIED.
 * Use tiepie_hw_generator_get_data_length() to determine the actually used length.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether the current signal type of a specified generator supports controlling the Arbitrary waveform buffer.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return #TIEPIE_HW_BOOL_TRUE if supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_set_data
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_has_data(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Check whether the specified generator supports controlling the Arbitrary waveform buffer for a specified signal type.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \return #TIEPIE_HW_BOOL_TRUE if supported, #TIEPIE_HW_BOOL_FALSE if not.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_has_data_ex(tiepie_hw_handle handle, uint32_t signal_type);

//! \endcond

/**
 * \brief Get the minimum length of the waveform buffer of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The minimum waveform buffer length in samples.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support getting the data length for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_data_length_max
 * \see tiepie_hw_generator_get_data_length
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_get_data_length_min(tiepie_hw_handle handle);

/**
 * \brief Get the maximum length of the waveform buffer of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The maximum waveform buffer length in samples.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support getting the data length for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_data_length_min
 * \see tiepie_hw_generator_get_data_length
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_get_data_length_max(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Get the minimum and maximum length of the waveform buffer for a specified signal type, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \param[out] min A pointer to a memory location for the minimum data length, or \c NULL.
 * \param[out] max A pointer to a memory location for the maximum data length, or \c NULL.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support getting the data length for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_data_length_min
 * \see tiepie_hw_generator_get_data_length_max
 * \see tiepie_hw_generator_get_data_length
 * \see tiepie_hw_generator_verify_data_length
 * \see tiepie_hw_generator_verify_data_length_ex
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_generator_get_data_length_min_max_ex(tiepie_hw_handle handle, uint32_t signal_type, uint64_t* min, uint64_t* max);

//! \endcond

/**
 * \brief Get the length of the currently loaded waveform pattern of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The currently set waveform pattern length in samples.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support getting the data length for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_data_length_min
 * \see tiepie_hw_generator_get_data_length_max
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_get_data_length(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Verify if a specified length of the waveform buffer for the current signal type of a specified generator can be set, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested waveform buffer length in samples.
 * \return The waveform buffer length that would have been set, in samples.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested buffer length is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested buffer length is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested waveform pattern length is \c 0.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support verifying the data length for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_data_length_min
 * \see tiepie_hw_generator_get_data_length_max
 * \see tiepie_hw_generator_get_data_length_min_max_ex
 * \see tiepie_hw_generator_get_data_length
 * \see tiepie_hw_generator_verify_data_length_ex
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_verify_data_length(tiepie_hw_handle handle, uint64_t value);

/**
 * \brief Verify if a specified length of the waveform buffer for a specified signal type of a specified generator can be set, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested waveform buffer length in samples.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \return Waveform buffer length in samples.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested buffer length is outside the valid range and clipped to the closest limit.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested buffer length is within the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is invalid or the requested waveform pattern length is \c 0.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support verifying the data length for the requested signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_data_length_min
 * \see tiepie_hw_generator_get_data_length_max
 * \see tiepie_hw_generator_get_data_length_min_max_ex
 * \see tiepie_hw_generator_get_data_length
 * \see tiepie_hw_generator_verify_data_length
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_verify_data_length_ex(tiepie_hw_handle handle, uint64_t value, uint32_t signal_type);

//! \endcond

/**
 * \brief Load a waveform pattern into the waveform buffer of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] buffer A pointer to a buffer with the waveform data.
 * \param[in] sample_count The number of samples in the pattern.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested data length is not available. The data is resampled to the closest valid length.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The buffer pointer is \c NULL \b or the requested waveform pattern length is \c 0.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support uploading pattern data for the current signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_CONTROLLABLE</td>       <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \remark \ref gen_signal_type "Signal type" must be set to arbitrary mode to load a waveform pattern into the waveform buffer.
 * \remark To clear and reset the waveform buffer, call tiepie_hw_generator_set_data with Buffer = \c NULL \b and sample_count = \c 0.
 * \remark When the generator is active, uploading new a waveform pattern will shortly interrupt the output signal.
 * \remark Changing the data may change the \ref tiepie_hw_generator_set_burst_segment_count "burst segment count" if generator mode is #TIEPIE_HW_GM_BURST_SEGMENT_COUNT or #TIEPIE_HW_GM_BURST_SEGMENT_COUNT_OUTPUT.
 * \see tiepie_hw_generator_get_data_length_min
 * \see tiepie_hw_generator_get_data_length_max
 * \see tiepie_hw_generator_get_data_length
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_generator_set_data(tiepie_hw_handle handle, const float* buffer, uint64_t sample_count);

//! \cond EXTENDED_API

/**
 * \brief Load a waveform pattern for a specified signal type into the waveform buffer of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] buffer A pointer to a buffer with waveform data.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \param[in] sample_count The number of samples in the buffer.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested data length is not available. The data is resampled to the closest valid length.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support uploading pattern data for the requested signal type.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type is invalid or the requested waveform pattern length is \c 0.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>           <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_CONTROLLABLE</td>       <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \remark Changing the data may change the \ref tiepie_hw_generator_set_burst_segment_count "burst segment count" if generator mode is #TIEPIE_HW_GM_BURST_SEGMENT_COUNT or #TIEPIE_HW_GM_BURST_SEGMENT_COUNT_OUTPUT.
 * \see tiepie_hw_generator_get_data_length_min
 * \see tiepie_hw_generator_get_data_length_max
 * \see tiepie_hw_generator_get_data_length
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_generator_set_data_ex(tiepie_hw_handle handle, const float* buffer, uint64_t sample_count, uint32_t signal_type);

/**
 *           \defgroup gen_signaldata_raw Raw data
 *           \{
 *             \brief Functions for raw data.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the raw data type of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The supported raw data type, a \ref DATARAWTYPE_ "DATARAWTYPE_*" value.
 * \see tiepie_hw_generator_set_data_raw
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_generator_get_data_raw_type(tiepie_hw_handle handle);

/**
 * \brief Get raw data minimum, equal to zero and maximum values.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[out] min Pointer to buffer for possible minimum raw data value, or \c NULL.
 * \param[out] zero Pointer to buffer for equal to zero raw data value, or \c NULL.
 * \param[out] max Pointer to buffer for possible maximum raw data value, or \c NULL.
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_generator_get_data_raw_value_range(tiepie_hw_handle handle, int64_t* min, int64_t* zero, int64_t* max);

/**
 * \brief Get maximum raw data value.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return Raw data value that equals \ref gen_signal_offset "offset" - \ref gen_signal_amplitude "amplitude".
 * \since 1.0
 */
TIEPIE_HW_API int64_t tiepie_hw_generator_get_data_raw_value_min(tiepie_hw_handle handle);

/**
 * \brief Get raw data value that equals zero.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return Raw data value that equals \ref gen_signal_offset "offset".
 * \since 1.0
 */
TIEPIE_HW_API int64_t tiepie_hw_generator_get_data_raw_value_zero(tiepie_hw_handle handle);

/**
 * \brief Get minimum raw data value.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return Raw data value that equals \ref gen_signal_offset "offset" + \ref gen_signal_amplitude "amplitude".
 * \since 1.0
 */
TIEPIE_HW_API int64_t tiepie_hw_generator_get_data_raw_value_max(tiepie_hw_handle handle);

/**
 * \brief Load a waveform pattern into the waveform buffer of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] buffer Pointer to buffer with waveform data.
 * \param[in] sample_count Number of samples in buffer.
 * \remark Changing the data may change the \ref tiepie_hw_generator_set_burst_segment_count "burst segment count" if generator mode is #TIEPIE_HW_GM_BURST_SEGMENT_COUNT or #TIEPIE_HW_GM_BURST_SEGMENT_COUNT_OUTPUT.
 * \see tiepie_hw_generator_get_data_raw_type
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_generator_set_data_raw(tiepie_hw_handle handle, const void* buffer, uint64_t sample_count);

/**
 * \brief Load a waveform pattern into the waveform buffer of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] buffer Pointer to buffer with waveform data.
 * \param[in] sample_count Number of samples in buffer.
 * \param[in] signal_type Signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \remark Changing the data may change the \ref tiepie_hw_generator_set_burst_segment_count "burst segment count" if generator mode is #TIEPIE_HW_GM_BURST_SEGMENT_COUNT or #TIEPIE_HW_GM_BURST_SEGMENT_COUNT_OUTPUT.
 * \see tiepie_hw_generator_get_data_raw_type
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_generator_set_data_raw_ex(tiepie_hw_handle handle, const void* buffer, uint64_t sample_count, uint32_t signal_type);

/**
 *           \}
 */

//! \endcond

/**
 *         \}
 *
 *       \}
 *       \defgroup gen_mode Mode
 *       \{
 *         \brief Functions for controlling the generator mode.
 *
 * A generator can operate in various different modes: \ref gen_continuous, \ref gen_burst or \ref gen_gated.
 * In \ref gen_continuous mode, the generator continuously generates the selected signal, until the generator is \ref tiepie_hw_generator_stop "stopped".
 * In \ref gen_burst mode, the generator generates a specified number of periods of the selected signal or a specified number of
 * samples from the waveform buffer and then stops automatically.
 * In \ref gen_gated mode, the generator generates (a part of) the selected signal based on a the precence of an external signal on
 * a selected external input of the generator.
 *
 * Which generator modes are available, depends on the selected \ref gen_signal_type "signal type" and \ref tiepie_hw_generator_set_frequency_mode "frequency mode".
 * Use tiepie_hw_generator_get_modes() to find out which generator modes are supported for the current settings.
 * Use tiepie_hw_generator_get_modes_native() to find out which generator modes are supported, regardless of the current settings.
 *
 * By default generator mode is set to continuous (#TIEPIE_HW_GM_CONTINUOUS).
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Get the supported generator modes for the current signal type and frequency mode of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The supported generator modes, a set of OR-ed \ref TIEPIE_HW_GM_ "TIEPIE_HW_GM_*" values or #TIEPIE_HW_GMM_NONE when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_modes_native
 * \see tiepie_hw_generator_get_mode
 * \see tiepie_hw_generator_set_mode
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_get_modes(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Get the supported generator modes for a specified \ref gen_signal_type "signal type" and \ref tiepie_hw_generator_set_frequency_mode "frequency mode" of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \param[in] frequency_mode The requested generator frequency mode, a \ref TIEPIE_HW_FM_ "TIEPIE_HW_FM_*" value. (Ignored for #TIEPIE_HW_ST_dC)
 * \return The supported generator modes, a set of OR-ed \ref TIEPIE_HW_GM_ "TIEPIE_HW_GM_*" values or #TIEPIE_HW_GMM_NONE when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested signal type or frequency mode is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_get_modes_ex(tiepie_hw_handle handle, uint32_t signal_type, uint32_t frequency_mode);

//! \endcond

/**
 * \brief Get all supported generator modes of a specified generator, regardless of the signal type and frequency mode.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The supported generator modes, a set of OR-ed \ref TIEPIE_HW_GM_ "TIEPIE_HW_GM_*" values or #TIEPIE_HW_GMM_NONE when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_modes
 * \see tiepie_hw_generator_get_mode
 * \see tiepie_hw_generator_set_mode
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_get_modes_native(tiepie_hw_handle handle);

/**
 * \brief Get the current generator mode of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The currently set generator mode, a \ref TIEPIE_HW_GM_ "TIEPIE_HW_GM_*" value, or #TIEPIE_HW_GMM_NONE when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_modes
 * \see tiepie_hw_generator_get_modes_native
 * \see tiepie_hw_generator_set_mode
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_get_mode(tiepie_hw_handle handle);

/**
 * \brief Set the generator mode of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested generator mode, a \ref TIEPIE_HW_GM_ "TIEPIE_HW_GM_*" value.
 * \return The actually set generator mode, a \ref TIEPIE_HW_GM_ "TIEPIE_HW_GM_*" value, or #TIEPIE_HW_GMM_NONE when unsuccessful.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support setting the generator mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested generator mode is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \remark The new value becomes active after a call to tiepie_hw_generator_start().
 * \see tiepie_hw_generator_get_modes
 * \see tiepie_hw_generator_get_modes_native
 * \see tiepie_hw_generator_get_mode
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_set_mode(tiepie_hw_handle handle, uint64_t value);

/**
 *         \defgroup gen_continuous Continuous
 *         \{
 *           \brief Information on continuous mode.
 *
 * In continuous mode, the generator continuously generates the selected signal until the generator is stopped.
 *
 * Starting the generator is done using tiepie_hw_generator_start() or via an external trigger signal on a selected generator
 * \ref dev_trigger_input "trigger input".
 *
 * Stopping the generator is done using tiepie_hw_generator_stop().
 * The current period of the signal that is being generated is not finished,
 * the output will go immediately to the selected \ref gen_signal_offset.
 *
 *         \}
 *         \defgroup gen_burst Burst
 *         \{
 *           \brief Functions for controlling burst mode.
 *
 * In burst mode, the generator generates a specified number of periods of the selected signal,
 * a specified number of samples from the waveform buffer or a segement from the waveform buffer and then stops automatically.
 *
 * Starting the generator is done using tiepie_hw_generator_start() and via an external trigger signal on a selected generator
 * \ref dev_trigger_input "trigger input".
 * For all burst modes except #TIEPIE_HW_GM_BURST_COUNT a generator \ref dev_trigger_input "trigger input" must be enabled.
 *
 * The following burst modes are supported:
 *
 * - #TIEPIE_HW_GM_BURST_COUNT :
 *   When the generator is started, or when an external trigger is enabled and the external signal becomes active, the generator generates a
 *   specified number of periods of the selected signal.
 *   When the required number of periods is reached, the generator stops automatically and the output will go to the selected \ref gen_signal_offset.
 *   When the burst is started again, the requested amount of periods is generated again.
 * - #TIEPIE_HW_GM_BURST_SAMPLE_COUNT :
 *   When the generator is started and the external signal becomes active, the generator generates a specified number of samples from the
 *   waveform buffer.
 *   When the required number of samples is reached, the generator automatically stops and the output will go to the selected \ref gen_signal_offset.
 *   When the burst is started again, the next requested amount of samples from the waveform buffer are generated.
 * - #TIEPIE_HW_GM_BURST_SAMPLE_COUNT_OUTPUT :
 *   When the generator is started and the external signal becomes active, the generator generates a specified number of samples from the
 *   waveform buffer.
 *   When the required number of samples is reached, the generator automatically stops and the output will remain at the level of the last generated sample.
 *   When the burst is started again, the next requested amount of samples from the waveform buffer are generated.
 * - #TIEPIE_HW_GM_BURST_SEGMENT_COUNT :
 *   The signal pattern buffer is divided in a specified number of segments.
 *   When the generator is started, each time the external signal becomes active, the generator generates the next segment,
 *   after which the generator automatically stops and the output will go to the selected \ref gen_signal_offset.
 *   When all sements have been generated, the generator will start on the first segment again, on the next activation of the external signal.
 * - #TIEPIE_HW_GM_BURST_SEGMENT_COUNT_OUTPUT :
 *   When the generator is started, each time the external signal becomes active, the generator generates the next segment,
 *   after which the generator automatically stops and the output will remain at the level of the last generated sample.
 *   When all sements have been generated, the generator will start on the first segment again, on the next activation of the external signal.
 *
 * By default burst count, burst sample count and burst segment count are set to their minimum values.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Check whether a burst is active, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return #TIEPIE_HW_BOOL_TRUE if a burst is active, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The current generator mode does not support getting the burst status.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see Notification gen_callbacks_burst_completed.
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_generator_is_burst_active(tiepie_hw_handle handle);

/**
 * \brief Get the minimum burst count for the current generator mode of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The minimum burst count.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support burst count in the current generator mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_burst_count_max
 * \see tiepie_hw_generator_get_burst_count
 * \see tiepie_hw_generator_set_burst_count
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_get_burst_count_min(tiepie_hw_handle handle);

/**
 * \brief Get the maximum burst count for the current generator mode of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The maximum burst count.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support burst count in the current generator mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_burst_count_min
 * \see tiepie_hw_generator_get_burst_count
 * \see tiepie_hw_generator_set_burst_count
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_get_burst_count_max(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Get the minimum and maximum burst count for a specified generator mode, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] generator_mode The requested generator mode, a \ref TIEPIE_HW_GM_ "TIEPIE_HW_GM_*" value.
 * \param[out] min A pointer to a memory location for the minimum or \c NULL.
 * \param[out] max A pointer to a memory location for the maximum or \c NULL.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support burst count in the requested generator mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested generator mode is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_burst_count_max
 * \see tiepie_hw_generator_get_burst_count_min
 * \see tiepie_hw_generator_get_burst_count
 * \see tiepie_hw_generator_set_burst_count
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_generator_get_burst_count_min_max_ex(tiepie_hw_handle handle, uint64_t generator_mode, uint64_t* min, uint64_t* max);

//! \endcond

/**
 * \brief Get the current burst count for the current generator mode of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The currently set burst count.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support burst count in the current generator mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_burst_count_max
 * \see tiepie_hw_generator_get_burst_count_min
 * \see tiepie_hw_generator_set_burst_count
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_get_burst_count(tiepie_hw_handle handle);

/**
 * \brief Set the burst count for the current generator mode of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested burst count, <tt>Gen_get_burst_count_min()</tt> to <tt>Gen_get_burst_count_max()</tt>.
 * \return The actually set burst count.
 * \remark The new value becomes active after a call to tiepie_hw_generator_start().
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested burst count is outside the valid range and clipped to that range.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested burst count is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support burst count in the current generator mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_burst_count_max
 * \see tiepie_hw_generator_get_burst_count_min
 * \see tiepie_hw_generator_get_burst_count
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_set_burst_count(tiepie_hw_handle handle, uint64_t value);

/**
 * \brief Get the minimum burst sample count for the current generator mode of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The minimum burst sample count.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support burst sample count in the current generator mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_burst_sample_count_max
 * \see tiepie_hw_generator_get_burst_sample_count
 * \see tiepie_hw_generator_set_burst_sample_count
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_get_burst_sample_count_min(tiepie_hw_handle handle);

/**
 * \brief Get the maximum burst sample count for the current generator mode of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The maximum burst sample count.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support burst sample count in the current generator mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_burst_sample_count_min
 * \see tiepie_hw_generator_get_burst_sample_count
 * \see tiepie_hw_generator_set_burst_sample_count
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_get_burst_sample_count_max(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Get the minimum and maximum burst sample count for a specified generator mode, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] generator_mode The requested generator mode, a \ref TIEPIE_HW_GM_ "TIEPIE_HW_GM_*" value.
 * \param[out] min A pointer to a memory location for the minimum or \c NULL.
 * \param[out] max A pointer to a memory location for the maximum or \c NULL.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support burst sample count in the specified generator mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested generator mode is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_burst_sample_count_min
 * \see tiepie_hw_generator_get_burst_sample_count_max
 * \see tiepie_hw_generator_get_burst_sample_count
 * \see tiepie_hw_generator_set_burst_sample_count
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_generator_get_burst_sample_count_min_max_ex(tiepie_hw_handle handle, uint64_t generator_mode, uint64_t* min, uint64_t* max);

//! \endcond

/**
 * \brief Get the current burst sample count for the current generator mode of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The currently set burst sample count.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support burst sample count in the current generator mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_burst_sample_count_min
 * \see tiepie_hw_generator_get_burst_sample_count_max
 * \see tiepie_hw_generator_set_burst_sample_count
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_get_burst_sample_count(tiepie_hw_handle handle);

/**
 * \brief Set the burst sample count for the current generator mode of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested burst sample count, <tt>Gen_getburst_sample_count_min()</tt> to <tt>Gen_getburst_sample_count_max()</tt>.
 * \return The actually set burst sample count.
 * \remark The new value becomes active after a call to tiepie_hw_generator_start().
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested burst sample count is outside the valid range and clipped to that range.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested burst sample count is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support burst sample count in the current generator mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_burst_sample_count_min
 * \see tiepie_hw_generator_get_burst_sample_count_max
 * \see tiepie_hw_generator_get_burst_sample_count
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_set_burst_sample_count(tiepie_hw_handle handle, uint64_t value);

/**
 * \brief Get the minimum burst segment count for the current settings of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The minimum burst segment count.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support burst segment count in the current generator mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_burst_segment_count_max
 * \see tiepie_hw_generator_get_burst_segment_count
 * \see tiepie_hw_generator_set_burst_segment_count
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_get_burst_segment_count_min(tiepie_hw_handle handle);

/**
 * \brief Get the maximum burst segment count for the current settings of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The maximum burst segment count.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support burst segment count in the current generator mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_burst_segment_count_min
 * \see tiepie_hw_generator_get_burst_segment_count
 * \see tiepie_hw_generator_set_burst_segment_count
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_get_burst_segment_count_max(tiepie_hw_handle handle);

//! \cond EXTENDED_API

/**
 * \brief Get the minimum and maximum burst segment count for a specified generator mode, signal type, frequency mode, frequency and data length, of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] generator_mode The requested generator mode, a \ref TIEPIE_HW_GM_ "TIEPIE_HW_GM_*" value.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \param[in] frequency_mode The requested frequency mode, a \ref TIEPIE_HW_FM_ "TIEPIE_HW_FM_*" value. (Ignored for #TIEPIE_HW_ST_dC)
 * \param[in] frequency The requested frequency in Hz.
 * \param[in] data_length The requested data length in samples, only for #TIEPIE_HW_ST_ARBITRARY.
 * \param[out] min A pointer to a memory location for the minimum or \c NULL.
 * \param[out] max A pointer to a memory location for the maximum or \c NULL.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support burst segment count in the current generator mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested generator mode, signal type, frequency mode, frequency or data length is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_burst_segment_count_min
 * \see tiepie_hw_generator_get_burst_segment_count_max
 * \see tiepie_hw_generator_get_burst_segment_count
 * \see tiepie_hw_generator_set_burst_segment_count
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_generator_get_burst_segment_count_min_max_ex(tiepie_hw_handle handle, uint64_t generator_mode, uint32_t signal_type, uint32_t frequency_mode, double frequency, uint64_t data_length, uint64_t* min, uint64_t* max);

//! \endcond

/**
 * \brief Get the current burst segment count of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \return The currently set burst segment count.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support burst segment count in the current generator mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_burst_segment_count_min
 * \see tiepie_hw_generator_get_burst_segment_count_max
 * \see tiepie_hw_generator_set_burst_segment_count
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_get_burst_segment_count(tiepie_hw_handle handle);

/**
 * \brief Set the burst segment count of a specified generator.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested burst segment count, <tt>tiepie_hw_generator_get_burst_segment_count_min()</tt> to <tt>tiepie_hw_generator_get_burst_segment_count_max()</tt>.
 * \return The actually set burst segment count.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested burst segment count is outside the valid range and clipped to that range.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested burst sample count is inside the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested burst segment count is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support burst segment count in the current generator mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_burst_segment_count_min
 * \see tiepie_hw_generator_get_burst_segment_count_max
 * \see tiepie_hw_generator_get_burst_segment_count
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_set_burst_segment_count(tiepie_hw_handle handle, uint64_t value);

//! \cond EXTENDED_API

/**
 * \brief Verify if a burst segment count of a specified generator can be set, without actually setting the hardware itself.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested burst segment count.
 * \return The burst segment count that would have been set.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested burst segment count is outside the valid range and clipped to that range.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested burst sample count is inside the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support burst segment count in the current generator mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_burst_segment_count_min
 * \see tiepie_hw_generator_get_burst_segment_count_max
 * \see tiepie_hw_generator_get_burst_segment_count
 * \see tiepie_hw_generator_set_burst_segment_count
 * \see tiepie_hw_generator_verify_burst_segment_count_ex
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_verify_burst_segment_count(tiepie_hw_handle handle, uint64_t value);

/**
 * \brief Verify if a burst segment count for the specified generator mode, signal type, frequency mode, frequency and data length of a specified generator can be set, without actually setting the hardware.
 *
 * \param[in] handle A \ref Open_dev "device handle" identifying the generator.
 * \param[in] value The requested burst segment count.
 * \param[in] generator_mode The requested generator mode, a \ref TIEPIE_HW_GM_ "TIEPIE_HW_GM_*" value.
 * \param[in] signal_type The requested signal type, a \ref TIEPIE_HW_ST_ "TIEPIE_HW_ST_*" value.
 * \param[in] frequency_mode The requested frequency mode, a \ref TIEPIE_HW_FM_ "TIEPIE_HW_FM_*" value. (Ignored for #TIEPIE_HW_ST_dC)
 * \param[in] frequency The requested frequency in Hz.
 * \param[in] data_length The requested data length in samples, only for #TIEPIE_HW_ST_ARBITRARY.
 * \return The burst segment count that would have been set.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_CLIPPED</td>          <td>The requested burst segment count is outside the valid range and clipped to that range.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_VALUE_MODIFIED</td>         <td>The requested burst sample count is inside the valid range but not available. The closest valid value is set.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td>          <td>The requested burst segment count, generator mode, signal type, frequency mode, frequency or data length is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_NOT_SUPPORTED</td>          <td>The generator does not support burst segment count in the current generator mode.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_HANDLE</td>         <td>The handle is not a valid generator handle.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_OBJECT_GONE</td>            <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED</td><td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>                <td></td></tr>
 *   </table>
 * \see tiepie_hw_generator_get_burst_segment_count_min
 * \see tiepie_hw_generator_get_burst_segment_count_max
 * \see tiepie_hw_generator_get_burst_segment_count
 * \see tiepie_hw_generator_set_burst_segment_count
 * \see tiepie_hw_generator_verify_burst_segment_count
 * \since 1.0
 */
TIEPIE_HW_API uint64_t tiepie_hw_generator_verify_burst_segment_count_ex(tiepie_hw_handle handle, uint64_t value, uint64_t generator_mode, uint32_t signal_type, uint32_t frequency_mode, double frequency, uint64_t data_length);

//! \endcond

/**
 *         \}
 *         \defgroup gen_gated Gated
 *         \{
 *           \brief Information on gated mode.
 *
 * In gated mode, the generator generates (a part of) the selected signal based on the presence of an external signal on a selected
 * \ref dev_trigger_input "trigger input" of the generator.
 *
 * Starting the generator is done using tiepie_hw_generator_start().

 * A generator \ref dev_trigger_input "trigger input" must be enabled.
 *
 * The following gated modes are supported:
 *
 * - #TIEPIE_HW_GM_GATED :
 *   When the generator is started, signal generation is started, but the output remains at the selected
 *   \ref gen_signal_offset "offset level" until the selected external input signal becomes active.
 *   When the external input signal becomes inactive again, the output goes to the selected offset level again.
 * - #TIEPIE_HW_GM_GATED_PERIODS :
 *   After the generator is started, signal generation is started at a new period when the selected external input signal becomes active.
 *   When the external input signal becomes inactive again, the current period is finalized, signal generation stops and the output goes to the
 *   selected \ref gen_signal_offset.
 * - #TIEPIE_HW_GM_GATED_PERIOD_START :
 *   After  the generator is started, signal generation is started at a new period when selected external input signal becomes active.
 *   When the external input signal becomes inactive again, signal generation immediately stops and the output goes to the selected \ref gen_signal_offset.
 * - #TIEPIE_HW_GM_GATED_PERIOD_FINISH :
 *   When the generator is started, signal generation is started, but the output remains at the selected
 *   \ref gen_signal_offset "offset level" until the selected external input signal becomes active.
 *   When the external input signal becomes inactive again, the current period is finalized and then the generator stops and the output goes to the
 *   selected \ref gen_signal_offset.
 * - #TIEPIE_HW_GM_GATED_RUN :
 *   After the generator is started, signal generation is started at a new period when the selected external input signal becomes active.
 *   When the external input signal becomes inactive again, signal generation is paused and the output goes to the selected \ref gen_signal_offset.
 * - #TIEPIE_HW_GM_GATED_RUN_OUTPUT :
 *   After the generator is started, signal generation is started at a new period when the selected external input signal becomes active.
 *   When the external input signal becomes inactive again, signal generation is paused and the output will remain at the level of the last generated sample.
 *
 *         \}
 *       \}
 *     \}
 *     \defgroup tiepie_hw_server_ Server
 *     \{
 *         \brief Functions to communicate with TPISS Instrument Sharing servers.
 */

// Workaround: Without this line Doxygen adds the documentation below to the group above.

/**
 * \brief Connect to a specified Instrument Sharing Server.
 *        This gives access to the instruments connected to and shared by that server.
 *
 * \param[in] handle A server handle identifying the server.
 * \param[in] asynchronous Connect asynchronously.
 * \return #TIEPIE_HW_BOOL_TRUE if successful, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_server_connect(tiepie_hw_handle handle, tiepie_hw_bool asynchronous);

/**
 * \brief Disconnect from a specified Instrument Sharing Server.
 *        This will close all opened instruments shared by that server.
 *
 * \param[in] handle A server handle identifying the server.
 * \param[in] force If #TIEPIE_HW_BOOL_TRUE all open devices are closed, if #TIEPIE_HW_BOOL_FALSE remove only succeeds if no devices are open.
 * \return #TIEPIE_HW_BOOL_TRUE if successful, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_server_disconnect(tiepie_hw_handle handle, tiepie_hw_bool force);

/**
 * \brief Remove a specified Instrument Sharing Server from the list of servers.
 *
 * \param[in] handle A server handle identifying the server.
 * \param[in] force If #TIEPIE_HW_BOOL_TRUE all open devices are closed, if #TIEPIE_HW_BOOL_FALSE remove only succeeds if no devices are open.
 * \return #TIEPIE_HW_BOOL_TRUE if successful, #TIEPIE_HW_BOOL_FALSE otherwise.
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_bool tiepie_hw_server_remove(tiepie_hw_handle handle, tiepie_hw_bool force);

/**
 * \brief Retrieve the status of a specified Instrument Sharing Server
 *
 * \param[in] handle A server handle identifying the server.
 * \return The status of the specified Instrument Sharing Server, see TIEPIE_HW_SERVER_STATUS
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_server_get_status(tiepie_hw_handle handle);

/**
 * \brief Get the last error from a specified Instrument Sharing Server
 *
 * \param[in] handle A server handle identifying the server.
 * \return The last error given by the specified server, see TIEPIE_HW_SERVER_ERROR
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_server_get_last_error(tiepie_hw_handle handle);

/**
 * \brief Get the URL of the specified Instrument Sharing Server.
 *
 * \param[in] handle A server handle identifying the server.
 * \param[out] buffer A pointer to a buffer for the URL.
 * \param[in] length The length of the buffer, in bytes.
 * \return The length of the URL in bytes, excluding terminating zero.
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_server_get_url(tiepie_hw_handle handle, char* buffer, uint32_t length);

/**
 * \brief Get the id of the specified Instrument Sharing Server.
 *
 * \param[in] handle A server handle identifying the server.
 * \param[out] buffer A pointer to a buffer for the id.
 * \param[in] length The length of the buffer, in bytes.
 * \return The length of the id in bytes, excluding terminating zero.
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_server_get_id(tiepie_hw_handle handle, char* buffer, uint32_t length);

/**
 * \brief Get the IP address of the specified Instrument Sharing Server.
 *
 * \param[in] handle A server handle identifying the server.
 * \param[out] buffer A pointer to a buffer for the IP address.
 * \param[in] length The length of the buffer, in bytes.
 * \return The length of the URL in bytes, excluding terminating zero.
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_server_get_ip_address(tiepie_hw_handle handle, char* buffer, uint32_t length);

/**
 * \brief Get the IP port number of the specified Instrument Sharing Server.
 *
 * \param[in] handle A server handle identifying the server.
 * \return The IP port number of the specified server.
 * \since 1.0
 */
TIEPIE_HW_API uint16_t tiepie_hw_server_get_ip_port(tiepie_hw_handle handle);

/**
 * \brief Get the name of the specified Instrument Sharing Server.
 *
 * \param[in] handle A server handle identifying the server.
 * \param[out] buffer A pointer to a buffer for the name.
 * \param[in] length The length of the buffer, in bytes.
 * \return The length of the name in bytes, excluding terminating zero.
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_server_get_name(tiepie_hw_handle handle, char* buffer, uint32_t length);

/**
 * \brief Get the description of the specified Instrument Sharing Server.
 *
 * \param[in] handle A server handle identifying the server.
 * \param[out] buffer A pointer to a buffer for the description.
 * \param[in] length The length of the buffer, in bytes.
 * \return The length of the description in bytes, excluding terminating zero.
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_server_get_description(tiepie_hw_handle handle, char* buffer, uint32_t length);

/**
 * \brief Get the software version number of the specified Instrument Sharing Server.
 *
 * \param[in] handle A server handle identifying the server.
 * \param[out] buffer A pointer to a buffer for the description.
 * \param[in] length The length of the buffer, in bytes.
 * \return The length of the server version in bytes, excluding terminating zero.
 * \return The software version number of the server, or zero if no software version is available.
 * \par Example
 * \code{.c}
 * uint32_t length = tiepie_hw_server_get_version(handle, NULL, 0) + 1; // Add one for the terminating zero
 * char* version = malloc(sizeof(char) * length);
 * length = tiepie_hw_server_get_version(handle, version, length);
 *
 * printf("tiepie_hw_server_get_version = %s\n", version);
 *
 * free(version);
 * \endcode
 *
 * \since 1.0
 */
TIEPIE_HW_API uint32_t tiepie_hw_server_get_version(tiepie_hw_handle handle, char* buffer, uint32_t length);

/**
 *   \}
 *   \defgroup hlp Helper functions
 *   \{
 *     \brief Functions to bypass certain limitations of programming/scripting languages.
 *
 *     \defgroup hlp_ptrar Pointer array
 *     \{
 *       \brief Functions for handling arrays of pointers.
 *
 * The function tiepie_hw_oscilloscope_get_data() uses a pointer to a buffer with pointers to buffers for the channel data.
 * Not all programming/scripting languages can handle pointers to pointers properly.
 * These functions can then be used to work around that issue.
 *
 * \par Example
 * In pseudocode:
 * \code
 * buffers = empty list/array
 * pointer_array = tiepie_hw_pointerarray_new(channel_count)
 *
 * for i = 0 to channel_count - 1
 *   if tiepie_hw_oscilloscope_channel_get_enabled(handle, i)
 *     buffers[ i ] = allocate buffer/array
 *     tiepie_hw_pointerarray_set(pointer_array, i, pointer of buffers[ i ])
 *   end
 * end
 *
 * tiepie_hw_oscilloscope_get_data(handle, pointer_array, channel_count, ...)
 *
 * tiepie_hw_pointerarray_delete(pointer_array)
 * \endcode
 * The data is now available in \c buffers.
 *
 * \see tiepie_hw_oscilloscope_get_data
 */

/**
 * \brief Create a new pointer array.
 *
 * The pointer array is initialized with \c NULL pointers.
 *
 * \param[in] length The requested length of the pointer array, \c 1 .. \c #TIEPIE_HW_POINTER_ARRAY_MAX_LENGTH.
 * \return A pointer to the pointer array.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_INVALID_VALUE</td> <td>The requested length is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td>  <td></td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>       <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API tiepie_hw_pointerarray tiepie_hw_pointerarray_new(uint32_t length);

/**
 * \brief Set a pointer at a specified index in a specified pointer array.
 *
 * \param[in] ptr A pointer identifying the pointer array.
 * \param[in] index The requested array index.
 * \param[in] value The pointer value to set.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_UNSUCCESSFUL</td> <td>The pointer to the array is invalid.</td></tr>
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td>      <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_pointerarray_set(tiepie_hw_pointerarray ptr, uint32_t index, void* value);

/**
 * \brief Delete an existing pointer array.
 *
 * \param[in] ptr A pointer identifying the pointer array.
 * \par Status values
 *   <table class="params">
 *   <tr><td>#TIEPIE_HW_STATUS_SUCCESS</td> <td></td></tr>
 *   </table>
 * \since 1.0
 */
TIEPIE_HW_API void tiepie_hw_pointerarray_delete(tiepie_hw_pointerarray ptr);

/**
 *     \}
 *   \}
 * \}
 */

#ifdef __cplusplus
}
#endif

#endif
