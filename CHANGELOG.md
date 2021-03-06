
## v0.4.3


### FEATURES
 - Half-duplex mode on Serial1 via `Serial1.halfdupliex()`. Thanks to @prices.

### ENHANCEMENTS
 - I2C methods now use `micros()` for timeouts rather than `millis()`, so I2C functions can be used in an interrupt handler. [#460](https://github.com/spark/firmware/issues/460)


### BUGFIXES

 - [Photon/TCPServer] - `TCPClient.connected()` was not returning `false` when the socket was asynchronously disconnected.
 - Fix time being reset on wakeup. (removed WICED RTC init code that resets to default preset time in platform_mcu_powersave_init() within photon-wiced repo.) [#440](https://github.com/spark/firmware/issues/440)
 - `TCPClient.connected()` was not returning `false` when the socket was disconnected from the other end.
 - `strdup()` was returning garbage [#457](https://github.com/spark/firmware/issues/457)
 - `attachInterrupt()` should work on all interrupt pins now except D0 & A5. Please note there are shared lines as per the following issue comment : [#443] (https://github.com/spark/firmware/issues/443#issuecomment-114389744)
 - Fix I2C bus lockup when no slave devices are present by issuing a STOP condition after sLave send address fails.


## v0.4.2

### FEATURES
 - EEPROM storage of custom data types via `EEPROM.put()` and `EEPROM.get()'
 - When the device is in safe mode, the LED breathes magenta
 - `attachSystemInterrupt()` allows hooking key system interrupts in user code.
 - [DMA-driven SPI master](https://github.com/spark/docs/pull/49)
 - `UDP.sendPacket()` method avoids buffering data when the user can supply the entire buffer at once.
 - [Photon] SoftAP setup can be done over HTTP
 - platform-neutral fast pin access [449](https://github.com/spark/firmware/pull/449)
 - [P1] Serial2 support

### ENHANCEMENTS

 - [Photon] The system firmware updates the bootloader to latest version
 - [Photon] The system write protects the bootloader region.
 - UDP uses dynamically allocated buffers
 - `PRODUCT_ID` and `PRODUCT_VERSION` place these details at a known place in the firmware image
 - DFU mode and serial firmware update can be triggered by setting the line rate.

### BUGFIXES

 - `Serial1.end()` [hangs the system](https://community.particle.io/t/changing-serial-baud-rate-inside-setup-code-causes-core-freezing-afterwards/10314/6)
 - Malformed CoAP acknowledgement message in cloud protocol.
 - `SPARK_WLAN_Loop()` was not linked. (Workaround was to use `Spark.process()`)
 - UDP doesn't send anything to the device until `UDP.write()` [#407](https://github.com/spark/firmware/issues/407)
 - Divide by zero now caught and causes a SOS.
 - Floating-point support for `sprintf()` reinstated
 - Fixed WICED DCT becoming unmodifiable
 - Fix UDP.parsePacket() not receiving any data on the Photon

## v0.4.1

### ENHANCEMENTS

- Signed Photon USB Driver for use with Windows 8.1


### BUGFIXES

 - `Spark.syncTime()` was not linked. [#426](https://github.com/spark/firmware/issues/426)
 - Wire.setSpeed(CLOCK_SPEED_100KHZ) was not linked. [#432](https://github.com/spark/firmware/issues/432)
 - WiFi.selectAntenna() was not linked.

## v0.4.0

### NEW PLATFORMS
- PHOTON!!!!


### ENHANCEMENTS

 - `loop()` iteration rate increased by 1000 times - from 200 Hz to over 200 kHz!
 - Compiler: Removed all warnings from the compile (and made warnings as errors) so compiler output is minimal.
 - Debugging: SWD Support, thanks to Elco Jacobs. [#337](https://github.com/spark/core-firmware/pull/337)
 - `Spark.publish()` returns a success value - [#388](https://github.com/spark/firmware/issues/388)
 - `Spark.process()` as the public API for running the system loop. [#347](https://github.com/spark/firmware/issues/347)
 - Sleep no longer resets (on the Photon) [#283](https://github.com/spark/firmware/issues/283)
 - Support for application code outside of the firmware repo. [#374](https://github.com/spark/firmware/issues/374)
 - MAC Address available in setup via 'm' key. [#352](https://github.com/spark/firmware/issues/352)
 - SoftAP setup on the Photon
 - `Spark.sleep()` changed to `System.sleep()` and similarly for `deviceID()` [#390](https://github.com/spark/firmware/issues/390)
 - Listening mode uses existing serial connection if already opened. [#384](https://github.com/spark/firmware/issues/384)
 - `Spark.publish("event", PRIVATE)` shorthand - [#376](https://github.com/spark/firmware/issues/376)
 - Improved integrity checks for firmware images
 - Added additional safe/recovery mode in bootloader (> 6.5 sec : restore factory code without clearing wifi credentials)
 - Enabled CRC verification in bootloader before restoring/copying the firmware image from factory reset, ota downloaded area etc.
 - Added 'program-serial' to build target to enter serial ymodem protocol for flashing user firmware (Testing pending...)
 - Cloud string variables can be re-defined [#241](https://github.com/spark/firmware/issues/241)
 - Removed hard-coded limit on number of functions and variables [#111](https://github.com/spark/firmware/issues/111)
 - Parameterized function callbacks, lambda support for functions [#311](https://github.com/spark/firmware/issues/313)
 - C++ STL headers supported
- Can duplicate the onboard RGB LED color in firmware. [#302](https://github.com/spark/firmware/issues/302)
- `WiFi.selectAntenna()` - select between internal (chip) and external (u.FL) antenna on Photon: [#394](https://github.com/spark/firmware/issues/394)
- `WiFi.resolve()` to look up an IP address from a domain name. [#91](https://github.com/spark/firmware/issues/91)
- `System.dfu()` to reboot the core in dfu mode, until next reset or next DFU update is received.


### BUGFIXES

- SOS calling `Spark.publish()` in `SEMI_AUTOMATIC`/`MANUAL` mode
- Subscriptions maintained when cloud disconnected. [#278](https://github.com/spark/firmware/issues/278)
- Fix for events with composite names. [#382](https://github.com/spark/firmware/issues/382)
- `WiFi.ready()` returning true after `WiFi.off()` in manual mode. [#378](https://github.com/spark/firmware/issues/378)
- `Serial.peek()` implemented. [#387](https://github.com/spark/firmware/issues/387)
- Mode button not working in semi-automatic or manual mode. [#343](https://github.com/spark/firmware/issues/343)
- `Time.timeStr()` had a newline at the end. [#336](https://github.com/spark/firmware/issues/336)
- `WiFi.RSSI()` caused panic in some cases. [#377](https://github.com/spark/firmware/issues/377)
- `Spark.publish()` caused SOS when cloud disconnected. [#322](https://github.com/spark/firmware/issues/332)
- `TCPClient.flush()` discards data in the socket layer also. [#416](https://github.com/spark/firmware/issues/416)


### UNDER THE HOOD

 - Platform: hardware dependencies are factored out from wiring into a hardware abstraction layer
 - Repo: all 3 spark repos (core-common-lib, core-communication-lib, core-firmware) are combined into this repo.
 - Modularization: factored common-lib into `platform`, `services` and `hal` modules.
 - Modularization: factored core-firmware into `wiring`, `system`, 'main' and `user` modules.
 - Modularization: user code compiled as a separate library in the 'user' module
 - Build system: fancy new build system - [build/readme.md](build/readme.md)
 - Modularization: modules folder containing dynamically linked modules for the Photon



## v0.3.4

### FEATURES

- Local Build: Specify custom toolchain with `GCC_PREFIX` environment variable ([firmware](https://github.com/spark/firmware/pull/328), [core-common-lib](https://github.com/spark/core-common-lib/pull/39), [core-communication-lib](https://github.com/spark/core-communication-lib/pull/29))

### ENHANCEMENTS

- Wiring: More efficient and reliable `print(String)` (fix issue [#281](https://github.com/spark/firmware/issues/281)) [#305](https://github.com/spark/firmware/pull/305)
- DFU: Add DFU suffix to .bin file [#323](https://github.com/spark/firmware/pull/323)

### BUGFIXES

- I2C: Use I2C polling mode by default [#322](https://github.com/spark/firmware/pull/322)
- Listening Mode: Fix hard fault when Wi-Fi is off [#320](https://github.com/spark/firmware/pull/320)
- LED Interaction: Fix breathing blue that should be blinking green [#315](https://github.com/spark/firmware/pull/315)


## v0.3.3

### FEATURES

 - Cloud: [Secure random seed](https://github.com/spark/core-communication-lib/pull/25). When the spark does a handshake with the cloud, it receives a random number that is set as a seed for `rand()`
 - Wiring: Arduino-compatible `random()` and `randomSeed()` functions. [#289](https://github.com/spark/core-firmware/pull/289)
 - Wiring: Arduino-compatible functions like `isAlpha()` and `toLowerCase()`. [#293](https://github.com/spark/core-firmware/pull/293)

### ENHANCEMENTS

 - Wire: added missing Slave mode using DMA/Interrupts and updated Master mode using DMA. New APIs `Wire.setSpeed()` and `Wire.strechClock()`. [#284](https://github.com/spark/core-firmware/issues/284)
 - Sleep: `Spark.sleep()` supports wakeup on pin change. [#265](https://github.com/spark/core-firmware/issues/265)

### BUGFIXES

 - RGB: calling `RGB.brightness()` doesn't change the LED brightness immediately [#261](https://github.com/spark/core-firmware/issues/261)
 - Wiring: `pinMode()` `INPUT` and `OUTPUT` constants had reversed values compared to Arduino. [#282](https://github.com/spark/core-firmware/issues/282)
 - Wiring: compiler error using `HEX` with `String`. [#210](https://github.com/spark/core-firmware/pull/210)
 - System Mode: MANUAL mode breaks OTA update [#294](https://github.com/spark/core-firmware/issues/294)

## pre v0.3.3 versions

See https://github.com/spark/core-firmware/releases
