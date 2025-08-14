# Move-by-Counts DC Motor with Quadrature Encoder (Arduino Mega)
components required:
Arduino Mega, Motor Driver (model), DC Motor, Encoder (PPR/CPR), Power supply, Wires.

Wiring:
Pin table + the docs/wiring_diagram.png.

How to Build/Run:
Open src/motor_move_by_counts.ino.
Select Arduino Mega 2560, correct COM port.
Upload.
Open Serial Monitor @ 115200, line endings = Newline.
Type a number between -255..255 and press Enter.

How it Works:
Encoder interrupts → position count.
State machine → IDLE / RUN.
Trapezoidal-ish PWM ramp (distance-based taper + acceleration limit).

Testing:
Commands tested, expected vs actual counts, notes on tolerance.
Tuning Notes
Constants and their effect.

Known Limitations:
No hard limits; gear backlash may introduce ±counts; needs adequate supply.

