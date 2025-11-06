#include "main.h"
#include "opcontrol_config_wrappers.hpp"
#include "config/robot.hpp"
#include <cmath>

constexpr uint32_t loop_delay = 10;

static void test_auton_trigger(pros::Controller& controller){
    if (!(opcontrol_config_auton_test_trigger((controller))) || pros::competition::is_connected()){
        return;
    }

}

static void drive_train_trigger(pros::Controller& controller){
    int linear = opcontrol_config::wrappers::opcontrol_config_linear_drive_curve_scaled(controller.get_analog(opcontrol_config::linear_trigger)) * opcontrol_config::linear_speed;
    int angular = opcontrol_config::wrappers::opcontrol_config_angular_drive_curve_scaled(controller.get_analog(opcontrol_config::angular_trigger)) * opcontrol_config::angular_speed;

    if (std::abs(linear) < opcontrol_config::linear_trigger_deadzone){
        linear = 0;
    }

    if (std::abs(angular) < opcontrol_config::angular_trigger_deadzone){
        angular = 0;
    }

    robot::chassis::left.move(linear + angular);
    robot::chassis::right.move(linear - angular);
}

static void intake_trigger(pros::Controller& controller){
    if (controller.get_digital(opcontrol_config::high_out_trigger)){
        robot::intake::conv.move(127 * opcontrol_config::conv_speed);
        robot::intake::hood.move(127 * opcontrol_config::hood_speed);
        robot::three_wire::hood.set_value(false);
        return;
    }

    robot::three_wire::hood.set_value(true);

    if (controller.get_digital(opcontrol_config::high_in_trigger) || controller.get_digital(DIGITAL_L2)){
        robot::intake::conv.move(-127 * opcontrol_config::conv_speed);
        robot::intake::hood.move(-127 * opcontrol_config::hood_speed);
        return;
    }

    if (controller.get_digital(opcontrol_config::store_trigger)){
        robot::intake::conv.move(127 * opcontrol_config::conv_speed);
        robot::intake::hood.move(-20);
        return;
    }

    robot::intake::conv.move(0);
    robot::intake::hood.move(0);
}

static bool wing_status = false;
static void wing_trigger(pros::Controller& controller){
    if (!controller.get_digital_new_press(opcontrol_config::wing_trigger)){
        return;
    }

    wing_status = !wing_status;
    robot::three_wire::wing.set_value(wing_status);
}

static bool match_loader_status = false;
static void match_loader_trigger(pros::Controller& controller){
    if (!controller.get_digital_new_press(opcontrol_config::match_loader_trigger)){
        return;
    }

    match_loader_status = !match_loader_status;
    robot::three_wire::match_loader.set_value(match_loader_status);
}

void opcontrol(){
    robot::three_wire::odom.set_value(false);

    pros::Controller controller(pros::E_CONTROLLER_MASTER);

    while (true){
        test_auton_trigger(controller);
        drive_train_trigger(controller);
        intake_trigger(controller);
        match_loader_trigger(controller);
        wing_trigger(controller);
        pros::delay(loop_delay);
    }
}