
# My Name is Mimi (The secret life of plants)

This was a final semester project for students in Industrial Design class for Installation Art.

This design uses 7 Arduinos and 7 ULN2003 boards and motors. One Arduino is the "master" and the other 6 are  slaves. The number of slaves is unlimited as long as the output of the master can drive the inputs of the slaves. Each motor consumes around 500mA. One external 9V/4A power supply powers all the hardware.

The slaves turn a stepper motor to the left or to the right at a certain speed and for a certain time. The direction is defined by the state of the input pin. The speed and time is defined in each of the slave's code. 

The master uses a ultrasonic ensor to measure the distance of an object (here a human) . This sensor is placed  in the front of the cabinet whih contains plants and 7 leaves which are controlled by the motors. 

Each leaf is connected with a wire to one of the motors. A custom made wheel  is attached to the spindle of the motor to enable the wire to be pulled in or losen, When the wire relaxes the leaf falls back into a rest position. 

The major challenges experienced during development were:

1. To reduce any friction to the wire. almost any friction causes the wire to be stuck when the leaf is falling back.

2. The instability of the ultrasonic sensor. A great deal of the master code is used to "debounce" incorrect values since the correct assessment of the distance between the object and the sensor is crucial for the stability of the design.
 
The distances defined are:

- Too far away    --- Mimi is very lonely
- Get closer      --- Mimi opens her leaves
- Too close       --- Mimi is shy and her leaves close 
- Just right      --- Mimi introduces herself

The MP3 player will play an MP3 file only ONCE upon detection of a change in one of these 4 distances.

The Arduino's, motors, ULN2003's, the sensor and MP3 player are powered by one 4A 9 power supply. The 9Vs connects connects to each of the Arduino's power connector.  The Arduino power regulator converts 9V to 5V and this 5V powers the motors, MP3 player and distance sensor.

** Material List **

* 7x [uno] - Arduino Uno 
* 1x [speaker] - 2W or more speaker (3W recommended)
* 1x [dfplayer] - DFplayer Mini
* 7x [motor and board] - 28BYJ-48 and ULN2003 stepper motor board
* 1x [sensor] - Ultrasonic Distance Sensor - HC-SR04
* 2x [resistor] - 1K resistor
* 7x [leaf] - Student's design
* 7x [wheel] - Student's design


A demonstration of the design in action in included in a video (watch the video in VLC media player)
The backgroumd music played is from the album "Stevie Wonder's Journey through the secret life of plants" 
by Stevie Wonder. 

[uno]:  https://www.arduino.cc/	
[speaker]: https://www.amazon.com/2w-speaker/s?k=2w+speaker
[usb]: https://www.molex.com/molex/products/datasheet.jsp?part=active/0670687041_IO_CONNECTORS.xml
[dfplayer]: https://www.dfrobot.com/product-1121.html
[motor and board]: https://hobbycomponents.com/motors-and-servos/813-stepper-motor-and-uln2003-driver-board
[sensor]: https://www.sparkfun.com/products/15569
[music]: https://www.discogs.com/Stevie-Wonder-Stevie-Wonders-Journey-Through-The-Secret-Life-Of-Plants/master/86450
[leaf]: https://github.com/symdeb/Arduino-My-Name-Is-MiMi/blob/master/Presentation.pdf
[wheel]: https://github.com/symdeb/Arduino-My-Name-Is-MiMi/blob/master/Presentation.pdf


Future changes that could be made

* Communicate via I2C between the master and slaves to create variable time and speed for each leaf's 	 
