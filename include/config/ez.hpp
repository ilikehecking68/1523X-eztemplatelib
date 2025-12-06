#pragma once

#include "./robot.hpp"

// Chassis constructor
inline ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing!
    {dt_left},     // Left Chassis Ports (negative port will reverse it!)
    {dt_right},  // Right Chassis Ports (negative port will reverse it!)

    robot::chassis::imu_port,      // IMU Port
    3.25,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
    450   // Wheel RPM = cartridge * (motor gear / wheel gear)
);

inline ez::tracking_wheel horiz(robot::chassis::horiz_port, 2.125, 0);