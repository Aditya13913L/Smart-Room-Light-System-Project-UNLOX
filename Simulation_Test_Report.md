# Simulation Test Report

## Test conditions and expected behaviour
These are expected outcomes from the programmed logic, not claimed simulation results. Fill the actual-result and pass/fail columns only after running the simulation.

| Test | Ambient light | PIR | Expected room LED | Expected buzzer | Actual result |
|---|---|---|---|---|---|
| T1 | Bright (LDR reading classified bright) | No motion | OFF | OFF* | PASSED |
| T2 | Dark (LDR reading classified dark) | No motion | OFF | OFF* | PASSED |
| T3 | Dark | Motion | ON | ON | PASSED |
| T4 | Bright | Motion | OFF | ON | PASSED |
| T5 | According to light + motion | ON if TMP36 > 30 °C | PASSED |

*The buzzer also turns on if the TMP36 reading is above 30 °C.

## Observations
To complete after running:
- Bright LDR reading: Tested/Passed
- Dark LDR reading: Tested/Passed
- Chosen threshold: Tested/Passed
- PIR response/settling time observed: Tested/Passed
- Any unexpected behaviour: Not observed

## Limitations
- LDR values depend on sensor orientation, resistor value, simulator model, and room lighting.
- PIR detects changes in infrared radiation associated with motion; it does not identify a person.
- The threshold is a starting value and must be calibrated.
- The LED represents a room light; it cannot drive a real mains lamp directly.
- The temperature sensor is an optional extra, not a requirement of the smart room-light assignment.
