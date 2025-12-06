#pragma once

#include "main.h"

namespace robot {
    namespace chassis {
        #define dt_left -11, 13, -14
        #define dt_right 17, -18, 19
        inline pros::MotorGroup left({dt_left}, pros::MotorGearset::blue, pros::MotorEncoderUnits::degrees);
        inline pros::MotorGroup right({dt_right}, pros::MotorGearset::blue, pros::MotorEncoderUnits::degrees);
        constexpr uint8_t imu_port = 15;
        constexpr uint8_t horiz_port = 18;
        inline pros::Distance goal_align1(4);
        inline pros::Distance goal_align2(16);
    }

    namespace intake {
        inline pros::Motor high(15);
        inline pros::Motor mid(-12);
        inline pros::Motor low(21);
    }

    namespace three_wire {
        inline pros::ADIDigitalOut match_loader('G');
        inline pros::ADIDigitalOut hood('A', true);
        inline pros::ADIDigitalOut wing('F', true);
        inline pros::ADIDigitalOut odom('D');
    }
}