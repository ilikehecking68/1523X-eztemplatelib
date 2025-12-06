#pragma once

#include "config/robot.hpp"

extern void score_high();
extern void store();
extern void score_mid();
extern void outake();
#define score_low outake
extern void stop_intake();