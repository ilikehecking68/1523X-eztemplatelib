#pragma once

#include "main.h"

namespace robot {
    namespace chassis {
        #define dt_left -20, 9, -8
        #define dt_right 12, 1, -2
        inline pros::MotorGroup left({dt_left}, pros::MotorGearset::blue, pros::MotorEncoderUnits::degrees);
        inline pros::MotorGroup right({dt_right}, pros::MotorGearset::blue, pros::MotorEncoderUnits::degrees);
        constexpr int8_t imu_port = 19;
        inline pros::Rotation horiz(18);
        inline pros::Distance goal_align1(1);
        inline pros::Distance goal_align2(2);
    }

    namespace intake {
        inline pros::Motor hood(-10);
        inline pros::Motor conv(11);
    }

    namespace three_wire {
        inline pros::ADIDigitalOut match_loader('G');
        inline pros::ADIDigitalOut hood('A');
        inline pros::ADIDigitalOut wing('F');
        inline pros::ADIDigitalOut odom('D');
    }
}