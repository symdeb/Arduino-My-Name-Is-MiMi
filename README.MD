
# MY NAME IS MIMI

This was a final semester project for students in Industrial Design class for Installation Art.

This design uses 7 Arduinos and ULN2003 7 motors with motor control board. One of which is the "master" and the other slaves. The number of slaves is unlimited as long as the output of the master can drive the inputs of the slaves. Each motor consumes around 500mA. The power supply should be able to power the arduino's and the motors.

The slaves turn a stepper motor fully to the left or fully the right depending on the input pin.The speed is defined in the slaves code. 

The master uses a distance sensor to measure the distance of an object (here a human) in front of the
a cabinet full of plants and 7 leaves that are controlled by the motors. 

Each leaf is connected with a wire to one of the motors. when the wire is relaxes the leaf falls back into a rest position. The major challenge in this design was to reduce any friction to the wire. A too high friction causes the wire to be stuck when falling back.
 
The distances defined are:

- Too far away  
- Get closer
- Too close       --- Leafes closes 
- Just right      --- Leafes open (relax)

The MP3 player will play an MP3 file ONCE once a change in one of these 4 distances is detected.

The Arduino are powered by a 4A 9~12V power supply connected to the Arduni power connector.  The Arduni power regulator converts this to 5V and this 5V powers the motors , MP3 player and distance sensor.


** Material List **

* [uno] - Arduino Uno 
* [speaker] - 2W or more speaker (3W recommended)
* [dfplayer] - DFplayer Mini
* [motor] - 5V  Stepper motor
* [motor and board] - 28BYJ-48 and ULN2003 stepper motor board
* [resisstor] - 2 1K resistors


A demonstration of the design in action in included in a video (watch the video in VLC media player)
The backgroumd music played is from the album "Stevie Wonder's Journey through the secret life of plants" 
by Stevie Wonder. 

[uno]:  https://www.arduino.cc/	
[speaker]: https://www.amazon.com/2w-speaker/s?k=2w+speaker
[usb]: https://www.molex.com/molex/products/datasheet.jsp?part=active/0670687041_IO_CONNECTORS.xml
[dfplayer]: https://www.dfrobot.com/product-1121.html
[motor and board]: https://hobbycomponents.com/motors-and-servos/813-stepper-motor-and-uln2003-driver-board
[music]: https://www.discogs.com/Stevie-Wonder-Stevie-Wonders-Journey-Through-The-Secret-Life-Of-Plants/master/86450
	 
