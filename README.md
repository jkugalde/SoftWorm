# Soft Worm

## Summary

My thesis project to get the my professional title as mechanical engineer, back in 2016-2017. You can read more about it at 
[Research Gate](https://www.researchgate.net/publication/332063464_An_earthworm-inspired_soft_robot_with_perceptive_artificial_skin) and watch a short video
in [Youtube](https://www.youtube.com/watch?v=FZ2wraRIhEo).

It is basically a bio inspired pneumatic soft robot composed by 3 modules mostly made of silicone, which moves through cavities using a peristaltic movement gait. The cool things about it is that it can crawl through irregular cavities, as the body is soft and it will adapt.
The movement algorithm requires that the robot anchors itself to the inner walls of the cavities, which is sensed using a strain/pressure sensor also made of silicone with micro channels filled with liquid metal. 

With the sensors, it is possible to detect the inner walls of the cavities as the derivative of the read values will increase as the pressure on the channels does so, even more considering that over the sensor surface there is a groove pattern. It is also possible to detect when the actuator fully deflates, as the derivative of the signal will be steady and near zero.

This is a better version of the original code, but it still needs to be tested on the hardware.

It may be a good idea to drop the axial actuator and only use a chain of radial actuators, as the axial deformation in them is not negligible. A pulse propagation would be interesting to study.

## Files

- I am using object oriented classes to program the robot. There are four classes here: the worm itself, a virtual soft muscle class, a time controlled muscle and a sensor controlled muscle, both inherits from the soft muscle class, in this way the robot program does not change, only the attached actuators.

- The examples in src folder is a time controlled worm moving forward, and a perceptive worm also moving forward.

## Further work

- To redesign and upload the silicone injection molds in grabcad.
- To document the electronics involved. 