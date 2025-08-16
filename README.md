# Move-by-Counts DC Motor with Quadrature Encoder (Arduino Mega)
Motor position control is a fundamental technique in robotics and automation, enabling precise movement and repeatability. 
This project demonstrates how to control the position of a DC motor using an Arduino Mega and a quadrature encoder. Through serial commands, you can command the motor to move a specific amount (given in encoder "counts"), and the system ensures the motion is smooth, accurate, and bidirectional.

Components Overview
1)Arduino Mega — microcontroller for logic and serial communication.
2)DC Motor — actuated via a standard motor driver.
3)Motor Driver — accepts PWM for speed and a direction pin for motor rotation direction.
4)Quadrature Encoder — gives feedback for position (two out-of-phase PWM signals).
5)Serial Interface — allows user to input desired movement counts, positive or negative.

Control Logic
When a target position (in encoder counts) is received:
The Arduino reads the input value.
Sets motor direction (based on the sign).
Moves the motor until the encoder counts reach the desired value.
Ensures smooth motion (using gradual ramp up/down of PWM ).

components required:
Arduino Mega, Motor Driver (model), DC Motor, Encoder (PPR/CPR), Power supply, Wires.


Wiring:
 Component          - Arduino Mega Pin 

 Motor Driver PWM   - D5 (PWM)       
 Motor Driver DIR   - D6               
 Encoder A          - D18 (INT5)       
 Encoder B          - D19 (INT4)     
 Encoder VCC        - 5 V              
 Encoder GND        - GND              
 Driver VCC (logic) - 5 V           
 Driver VM (motor)  - +12 V           
 Driver GND         - GND             
 Motor terminals    - A01, A02    

code:




How to Run:
Open src/motor_move_by_counts.ino.
Select Arduino Mega 2560, correct COM port.
Upload.
Open Serial Monitor @ 115200, line endings = Newline.
Type a number between -255 to 255 and press Enter.

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

