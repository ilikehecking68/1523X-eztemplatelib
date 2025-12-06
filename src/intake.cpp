#include "config/robot.hpp"

void score_high() {
    robot::three_wire::hood.set_value(false);

    robot::intake::low.move(127);
    robot::intake::mid.move(127);
    robot::intake::high.move(127);
}

void store() {
    robot::three_wire::hood.set_value(true);

    robot::intake::low.move(127);
    robot::intake::mid.move(127);
    robot::intake::high.move(127);
}

void score_mid() {
    robot::three_wire::hood.set_value(true);

    robot::intake::low.move(70);
    robot::intake::mid.move(-70);
    robot::intake::high.move(127);
}

void outake() {
    robot::intake::low.move(-127);
    robot::intake::mid.move(-127);
    robot::intake::high.move(-127);
}

void stop_intake() {
    robot::intake::low.move(0);
    robot::intake::mid.move(0);
    robot::intake::high.move(0);
}