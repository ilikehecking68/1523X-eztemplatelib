#include "opcontrol_config_wrappers.hpp"

int opcontrol_config::wrappers::opcontrol_config_linear_drive_curve_scaled(int value){
    return 127 / (opcontrol_config_linear_drive_curve((127))) * (opcontrol_config_linear_drive_curve((value)));
}

int opcontrol_config::wrappers::opcontrol_config_angular_drive_curve_scaled(int value){
    return 127 / (opcontrol_config_angular_drive_curve((127))) * (opcontrol_config_angular_drive_curve((value)));
}