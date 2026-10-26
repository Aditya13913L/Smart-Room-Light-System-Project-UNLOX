# Smart-Room-Light-System-Project-UNLOX
This is the 2nd minor project based on IOT &amp; Robotics @UNLOX based on Smart Room Light System Working

## Overview
An Arduino Uno prototype that combines an LDR (ambient light sensor) and a PIR motion sensor. The room-light LED turns on only when motion is detected **and** the room is classified as dark. A buzzer sounds when motion is detected. The screenshot also contains a TMP36 temperature sensor; its optional temperature alert is retained in the code.

## Files
- `Smart_Room_Light_System.ino` — Arduino source code.
- `Circuit_Connection_Guide.md` — Intended pin mapping and wiring notes.
- `Simulation_Test_Report.md` — Test matrix and evidence checklist.
- `test_results.csv` — Actual observed results during testing.
- `Smart_Room_Light_Report.pdf` — Project report.
- `circuit_diagram.png` — Simplified functional connection diagram.
- `evidence/circuit_screenshot.png` — Screenshot of the whole circuit.
- 'evidence/simulation video.mp4' - Simulation video of the project.

## Intended pin mapping (verify against the actual circuit)
| Part | Connection |
|---|---|
| LDR voltage-divider output | A0 |
| TMP36 output (optional extra) | A1 |
| PIR VCC / OUT / GND | 5V / D2 / GND |
| Room LED | D9 through 220–330 Ω resistor, then GND |
| Buzzer positive / negative | D8 / GND |
| Power | Arduino 5V and GND; all grounds common |

The uploaded screenshot is visually dense and wire junctions are not all unambiguous. Verify the intended mapping above in Tinkercad before relying on the code. The code is written for this mapping.

## Control logic
- `LIGHT_THRESHOLD = 500` is an initial value, not a universal calibrated value.
- With the default `DARK_READING_IS_HIGH = true`, an LDR reading greater than 500 means dark.
- LED ON = PIR motion detected AND dark condition.
- Buzzer ON = motion detected OR TMP36 temperature greater than 30 °C.
- If the assignment requires the buzzer only for motion, remove the temperature condition and temperature alert from the code.

## How to run
1. Open the circuit in Tinkercad Circuits and check the wiring.
2. Paste or upload the `.ino` code.
3. Start simulation and allow the PIR sensor to warm up.
4. Open Serial Monitor at 9600 baud.
5. Record readings and actual output behaviour in `test_results.csv` and `Simulation_Test_Report.md`.
6. Adjust `LIGHT_THRESHOLD` and, if needed, `DARK_READING_IS_HIGH` based on observed bright/dark readings.

## Important Links to access my Project
**Tinkercad Link** - https://www.tinkercad.com/things/bLWEdusoe8g-smart-room-light-system
**Github Link** - 

## Safety
Use only a small LED for this simulation. Do not connect mains-powered room lighting directly to Arduino. Higher-power loads need appropriately rated, isolated driver hardware and adult/supervised electrical safety practices.

## Evidence note
The included screenshot documents the circuit layout only. It does not prove the simulation passed the tests. Capture separate screenshots of Serial Monitor and output states after running each test.
