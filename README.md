# AggregatorTeensy

Pinout shown below

![alt text](https://www.pjrc.com/store/teensy41_card11a_rev3.png)

SoftPWM library [link](https://github.com/bhagman/SoftPWM)

## To actually program code to the Teensy 4.1 you need
- [Choice of several older arduino IDE versions, I used 1.8.13](https://www.arduino.cc/en/software)
- [Teensyduino to get the Teensy programmed](https://www.pjrc.com/teensy/teensyduino.html)
- The SoftPWM library, which you can install from the website or through the Arduino IDE library manager.

## To Do

I'd like to begin by seeing how this will interface with our ROS system on the UP^2 board.
There should be some sort of template out there to see what type of interaction our code will need to have/do with the ROS system.
- I'm wondering if we should create functions for forward, backward, and turning at a certain angle left or right as a beginning start to working with the teesny. 
- From there we can begin to create more of the complex action's such as moving the digger mechanism, unloading the hopper, etc.
