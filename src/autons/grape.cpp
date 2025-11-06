#include "main.h"
#include "config/ez.hpp"

void set_pid_constants() {
  // chassis.pid_heading_constants_set(11, 0, 20);
  // chassis.pid_drive_constants_set(20, 0, 100);
  // chassis.pid_turn_constants_set(3, 0.05, 20, 15);
  // chassis.pid_swing_constants_set(6, 0, 65);
  chassis.pid_heading_constants_set(11, 0, 20);
  chassis.pid_drive_constants_set(20, 0, 105);
  chassis.pid_turn_constants_set(3, 0.05, 20, 15);
  chassis.pid_swing_constants_set(6, 0, 65);

  // chassis.pid_turn_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  // chassis.pid_swing_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  // chassis.pid_drive_exit_condition_set(80_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);
  chassis.pid_turn_exit_condition_set(1_ms, 4_deg, 500_ms, 7_deg, 750_ms, 750_ms);
  chassis.pid_swing_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(1_ms, 1_in, 500_ms, 3_in, 750_ms, 750_ms);

  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  chassis.slew_drive_constants_set(7_in, 80);
}

static void sawp() {
    chassis.drive_angle_set(15);
    robot::intake::conv.move(127);
    robot::intake::hood.move(-50);
    chassis.pid_drive_set(12_in, 127);
    chassis.pid_wait();
    chassis.pid_drive_set(20_in, 40);
    pros::delay(250);
    robot::three_wire::match_loader.set_value(true);
    chassis.pid_wait();
    pros::delay(1000);
    chassis.pid_turn_set(-47.5_deg, 127);
    chassis.pid_wait();
    robot::three_wire::match_loader.set_value(false);
    chassis.pid_drive_set(18_in, 40);
    chassis.pid_wait();
    robot::intake::conv.move(-127);
}

void autonomous() {
    set_pid_constants();
    chassis.pid_targets_reset();                // Resets PID targets to 0
    chassis.drive_imu_reset();                  // Reset gyro position to 0
    chassis.drive_sensor_reset();               // Reset drive sensors to 0
    chassis.odom_xyt_set(0_in, 0_in, 0_deg);    // Set the current position, you can start at a specific position with this
    chassis.drive_brake_set(MOTOR_BRAKE_COAST);  // Set motors to hold.  This helps autonomous consistency
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