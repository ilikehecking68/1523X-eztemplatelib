#pragma once

#include "main.h"

namespace opcontrol_config {
    constexpr double linear_speed = 1;
    constexpr double angular_speed = 0.8;
    
    typedef pros::controller_analog_e_t analog_joystick;
    typedef pros::controller_digital_e_t digital_button;

    constexpr analog_joystick linear_trigger = ANALOG_LEFT_Y;
    constexpr analog_joystick angular_trigger = ANALOG_RIGHT_X;

    constexpr int linear_trigger_deadzone = 6;
    constexpr int angular_trigger_deadzone = 6;
    
    #define opcontrol_config_linear_drive_curve(input) input
    #define opcontrol_config_angular_drive_curve(input) input

    constexpr double hood_speed = 1;
    constexpr double conv_speed = 1;

    constexpr digital_button high_out_trigger = DIGITAL_R1;
    constexpr digital_button high_in_trigger = DIGITAL_R2;
    constexpr digital_button store_trigger = DIGITAL_L1;

    constexpr digital_button wing_trigger = DIGITAL_DOWN;
    constexpr digital_button match_loader_trigger = DIGITAL_X;

    #define opcontrol_config_auton_test_trigger(controller) controller.get_digital_new_press(DIGITAL_UP) && controller.get_digital_new_press(DIGITAL_DOWN) && controller.get_digital_new_press(DIGITAL_LEFT) && controller.get_digital_new_press(DIGITAL_RIGHT)
}