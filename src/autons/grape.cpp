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

#define drive(dist, speed, ...) do { \
    chassis.pid_drive_set((dist), (speed), __VA_ARGS__); \
    chassis.pid_wait(); \
} while (false);

#define turn(target_heading, speed, ...) do { \
    chassis.pid_drive_set((target_heading), (speed), __VA_ARGS__); \
    chassis.pid_wait(); \
} while (false);

void autonomous() {
    set_pid_constants();
    chassis.pid_targets_reset();                // Resets PID targets to 0
    chassis.drive_imu_reset();                  // Reset gyro position to 0
    chassis.drive_sensor_reset();               // Reset drive sensors to 0
    chassis.odom_xyt_set(0_in, 0_in, 0_deg);    // Set the current position, you can start at a specific position with this
    chassis.drive_brake_set(MOTOR_BRAKE_COAST);  // Set motors to hold.  This helps autonomous consistency
    chassis.pid_turn_behavior_set(ez::shortest); // ADDED TURN OPTIMIZATION HERE
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
