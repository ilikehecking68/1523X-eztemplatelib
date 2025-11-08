#include "main.h"
#include "config/ez.hpp"

void set_pid_constants() {
  // chassis.pid_heading_constants_set(11, 0, 20);
  // chassis.pid_drive_constants_set(20, 0, 100);
  // chassis.pid_turn_constants_set(3, 0.05, 20, 15);
  // chassis.pid_swing_constants_set(6, 0, 65);
  chassis.pid_heading_constants_set(11, 0, 20);
  chassis.pid_drive_constants_set(17, 0, 85);
  chassis.pid_turn_constants_set(3, 0.05, 20, 15);
  chassis.pid_swing_constants_set(6, 0, 65);

  // chassis.pid_turn_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  // chassis.pid_swing_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  // chassis.pid_drive_exit_condition_set(80_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  chassis.pid_turn_exit_condition_set(25_ms, 4_deg, 150_ms, 6_deg, 300_ms, 300_ms);
  chassis.pid_swing_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(25_ms, 2_in, 150_ms, 4_in, 300_ms, 300_ms);

  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(5_in);

  chassis.slew_drive_constants_set(7_in, 80);
}
static void Safe_Low(){
    robot::intake::conv.move(127);
    robot::intake::hood.move(-50);
    chassis.pid_turn_set(15_deg, 127);
    chassis.pid_wait();
    chassis.pid_drive_set(12_in, 127);
    chassis.pid_wait();
    chassis.pid_drive_set(25_in, 40);
    pros::delay(325);
    robot::three_wire::match_loader.set_value(true);
    chassis.pid_wait();
    pros::delay(1000);
    chassis.pid_drive_set(-5_in, 127);
    chassis.pid_wait();
    chassis.pid_turn_set(-45_deg, 127);
    chassis.pid_wait();
    robot::three_wire::match_loader.set_value(false);
    chassis.pid_drive_set(17_in, 40);
    chassis.pid_wait();
    robot::intake::conv.move(-127);
    pros::delay(1500);
    robot::intake::conv.move(127);
    chassis.pid_drive_set(-49_in, 100);
    chassis.pid_wait();
    chassis.pid_turn_set(180_deg, 127);
    chassis.pid_wait();
    robot::three_wire::match_loader.set_value(true);
    chassis.pid_drive_set(25_in, 50);
    chassis.pid_wait();
    pros::delay(500);
    chassis.pid_drive_set(-38_in, 127);
    chassis.pid_wait();
    robot::intake::hood.move(127);
}

static void safe_mid(){

}

static void elim_longgoal_right(){
    robot::intake::conv.move(127);
    robot::intake::hood.move(-50);
    chassis.pid_turn_set(15_deg, 127);
    chassis.pid_wait();
    chassis.pid_drive_set(12_in, 127);
    chassis.pid_wait();
    chassis.pid_drive_set(25_in, 40);
    pros::delay(325);
    robot::three_wire::match_loader.set_value(true);
    chassis.pid_wait();
    pros::delay(500);
    chassis.pid_drive_set(-5_in, 127);
    robot::three_wire::match_loader.set_value(false);
    chassis.pid_turn_set(65_deg, 127);
    chassis.pid_drive_set(25_in, 127);
    chassis.pid_wait();
    chassis.pid_drive_set(12_in, 40);
    chassis.pid_wait();
    pros::delay(250);
    chassis.pid_drive_set(-30_in, 127);
    chassis.pid_wait();
    chassis.pid_turn_set(-45_deg, 127);
    chassis.pid_wait();
    chassis.pid_drive_set(-41_in, 100);
    chassis.pid_wait();
    chassis.pid_turn_set(180_deg, 127);
    chassis.pid_wait();
    chassis.pid_drive_set(-30_in, 100);
    chassis.pid_wait();
    robot::intake::hood.move(127);
    pros::delay(1400);
    robot::intake::hood.move(-50);
    robot::three_wire::match_loader.set_value(true);
    chassis.pid_drive_set(33_in, 127);
    chassis.pid_wait();
    robot::intake::hood.move(-50);
    chassis.pid_turn_set(180_deg, 127);
    chassis.pid_wait();
    chassis.pid_drive_set(8_in, 50);
    chassis.pid_wait();
    pros::delay(500);
    chassis.pid_drive_set(-39_in, 127);
    chassis.pid_wait();
    robot::intake::hood.move(127);


    





}

static void elim_longgoal_left(){

}

static void sawp() {
    chassis.pid_heading_constants_set(8, 0, 20);
    chassis.pid_drive_constants_set(10, 0, 85);
    chassis.pid_turn_constants_set(3, 0.05, 20, 15);
    chassis.pid_swing_constants_set(6, 0, 65);
    
    robot::intake::conv.move(127);
    robot::intake::hood.move(-50);

    // Go to First Matchloader
    chassis.pid_drive_set(37_in, 127);
    chassis.pid_wait();
    chassis.pid_turn_set(90_deg, 127);
    robot::three_wire::match_loader.set_value(true);
    chassis.pid_wait();
    chassis.pid_drive_set(23.5_in, 127);
    chassis.pid_wait();
    pros::delay(50);
    //Line Up With Long Goal
    chassis.pid_drive_set(-39.5_in, 127);
    chassis.pid_wait();
    
    //Score
    robot::intake::hood.move(127);
    robot::three_wire::match_loader.set_value(false);
    pros::delay(1000);
    robot::intake::hood.move(-50);
    //Get 3 Balls
    chassis.pid_drive_set(16.5_in, 127);
    chassis.pid_wait();
    chassis.pid_turn_set(-145_deg, 127);
    chassis.pid_wait();
    chassis.pid_drive_set(37_in, 127);
    chassis.pid_wait();
    chassis.pid_turn_set(-135_deg, 127);
    chassis.pid_wait();
    chassis.pid_drive_set(22_in, 127);
    chassis.pid_wait();
    //Score on low Goal
    robot::intake::conv.move(-127);
    robot::intake::hood.move(-127);
    pros::delay(1000);
    robot::intake::conv.move(127);
    robot::intake::hood.move(-50);
    chassis.pid_drive_set(-12_in, 127);
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(180_deg, 127);
    chassis.pid_wait();
    chassis.pid_drive_set(52_in, 127);
    chassis.pid_wait_quick_chain();
    robot::three_wire::match_loader.set_value(true);
    chassis.pid_turn_set(135_deg, 127);
    chassis.pid_wait();
    chassis.pid_drive_set(38_in, 127);
    chassis.pid_wait_quick_chain();
    chassis.pid_turn_set(90_deg, 127);
    chassis.pid_wait();
    chassis.pid_drive_set(28_in, 127);
    chassis.pid_wait_quick_chain();
    chassis.pid_drive_set(5.5_in, 50);
    chassis.pid_wait_quick_chain();
    pros::delay(50);
    chassis.pid_drive_set(-39_in, 127);
    chassis.pid_wait_quick_chain();
    robot::intake::hood.move(-127);

}

void autonomous() {
    set_pid_constants();
    chassis.odom_tracker_back_set(&horiz);
    chassis.pid_targets_reset();                // Resets PID targets to 0
    chassis.drive_imu_reset();                  // Reset gyro position to 0
    chassis.drive_sensor_reset();               // Reset drive sensors to 0
    chassis.odom_xyt_set(0_in, 0_in, 0_deg);    // Set the current position, you can start at a specific position with this
    chassis.drive_brake_set(MOTOR_BRAKE_COAST);  // Set motors to hold.  This helps autonomous consistency
    chassis.pid_turn_behavior_set(ez::shortest); // ADDED TURN OPTIMIZATION HERE
    sawp();
    
  /*
  Odometry and Pure Pursuit are not magic

  It is possible to get perfectly consistent results without tracking wheels,
  but it is also possible to have extremely inconsistent results without tracking wheels.
  When you don't use tracking wheels, you need to:
   - avoid wheel slip
   - avoid wheelies
   - avoid throwing momentum around (super harsh turns, like in the example below)
  You can do cool curved motions, but you have to give your robot the best chance
  to be consistent
  */

}