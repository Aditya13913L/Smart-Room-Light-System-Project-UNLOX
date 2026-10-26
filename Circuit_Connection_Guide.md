# Circuit Connection Guide

This guide lists the intended pin mapping used by the included code. The uploaded screenshot has overlapping wires, so confirm each connection in Tinkercad.

LDR divider - Junction between LDR and fixed resistor - A0
LDR divider - One end of divider - 5V
LDR divider - Other end of fixed resistor - GND
PIR module - VCC - 5V
PIR module - OUT - D2
PIR module - GND - GND
LED - Anode - D9 through 220–330 Ω resistor
LED - Cathode - GND
Buzzer - Positive - D8
Buzzer − Negative - GND
TMP36 - Left pin when flat face faces you - 5V
TMP36 - Middle pin - A1
TMP36 - Right pin when flat face faces you - GND

## LDR calibration
Open Serial Monitor at 9600 baud and record `LDR reading` in bright and dark conditions.
If dark readings are higher, leave `DARK_READING_IS_HIGH = true`, if dark readings are lower, change it to `false`. 
Set `LIGHT_THRESHOLD` between the typical bright and dark readings.
