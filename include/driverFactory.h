#pragma once

#include <openvr_driver.h>
using namespace vr;

#include "serverDriver.h"
static ServerDriver serverDriver;

#include "watchdogDriver.h"
static WatchdogDriver watchdogDriver;

#define HMD_DLL_EXPORT extern "C" __attribute__((visibility("default")))
#define HMD_DLL_IMPORT extern "C"