# Soft Worm

## Summary

My thesis project to get the my professional title as mechanical engineer, back in 2016-2017. You can read more about it at 
[Research Gate](https://www.researchgate.net/publication/332063464_An_earthworm-inspired_soft_robot_with_perceptive_artificial_skin) and watch a short video
in [Youtube](https://www.youtube.com/watch?v=FZ2wraRIhEo).

It is basically a bio inspired pneumatic soft robot composed by 3 modules mostly made of silicone, which moves through cavities using a peristaltic movement gait. The cool things about it is that it can crawl through irregular cavities, as the body is soft and it will adapt.
The movement algorithm requires that the robot anchors itself to the inner walls of the cavities, which is sensed using a strain/pressure sensor also made of silicone with micro channels filled with liquid metal. 

I am making this repository for storage, and also, to improve my coding skills with Arduino, which really sucked
when i did this. Maybe i will add improvements on the part files and electronics to build the robot.

## Files

- I am using the objects to program the robot. There are four classes here: the worm itself, a virtual soft muscle class, a time controlled muscle and a sensor controlled muscle, both inherits from the soft muscle class, in this way the robot program does not change, only the attached actuators.

- The example in src is a time controlled worm moving forward.

## Further work

- To implement a sensor controlled worm moving forward.
- To redesign and upload the silicone injection molds in grabcad.
- To document the electronics involved. 