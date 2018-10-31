# NodeMCU32S meets mruby/c

This is sample implementation of embedding mruby/c into NodeMCU-32S

## Our goals

* Trace latest mruby/c implementation and evaluate new feature.
* Provide full feature OLED control from mruby/c.
* Provide full feature sensor control from mruby/c. We target to manipulate for SunFounder basic sensor kit.
* Aim for useful deviceis for research and educational.

## Installation

This project is created by PlatformIO. so first, you need install PlatformIO environment.
  
1. Install PlatformIO

[Platform IO install manual](https://docs.platformio.org/en/latest/installation.html)

2. Create new project

```
mkdir nodemcu32s-meets-mrubyc
cd nodemcu32s-meets-mrubyc
platformio init --board nodemcu-32s
```

3. Clone, and copy this code

```
git clone https://github.com/kirikak2/nodemcu32s-meets-mrubyc
```

4. Install libraries 

Currentry, you need to install follow libraries.

```
platformio lib install "SSD_13xx"  // To use LCD display module
platformio lib install 18 // To use DHT11 module
platformio lib install 19 // To use DHT11 module
platformio lib install 31 // To use DHT11 module
```

5. Create data directory and write Wifi credencials

Currentry, you need to write wifi.txt with WiFi credential.

```
<first line, you write SSID name>
<second line, you write Wifi password>
```

5. Build and Upload firmware

```
 platformio run --target upload   
```

6. Finally, you can use mruby/c via rmirb

[rmirb](https://github.com/kishima/mruby/tree/rmirb)

```
rmirb -I<IP address on your device>
> You can write mruby code in here.
```

You can get your ip address from serial console.

## Supported(confirmed) devices

LCD display
* SSD_1331 - 96 x 64 full colored OLED display

Sunfounder Basic sensor kit
* Passiver buzzer
* Push button
* Humiture Sensor
* RGB LED

# Samples

TBD