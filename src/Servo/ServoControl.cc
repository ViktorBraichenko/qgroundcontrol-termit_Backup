/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/


#include<iostream>
#include "Vehicle.h"
#include "ServoControl.h"

#define SERVO_PWM_ON  2000
#define SERVO_PWM_OFF 1000

#define DAY_LIGHT_SERVO   11
#define NIGHT_LIGHT_SERVO 3
#define REB_SERVO 10
#define UNIVERSAL_SERVO 7


ServoControl::ServoControl(QObject *parent, Vehicle *vehicle)
        : QObject(parent), _vehicle(vehicle)
{
}

void ServoControl::setDayLightEnabled(bool enabled, int _defaultComponentId) {
    if (!enabled) {
        dayLightDisable(_defaultComponentId);
    } else {
        dayLightEnable(_defaultComponentId);
    }
};

void ServoControl::setNightLightEnabled(bool enabled, int _defaultComponentId) {
    if (!enabled) {
        nightLightDisable(_defaultComponentId);
    } else {
        nightLightEnable(_defaultComponentId);
    }
};

void ServoControl::setRebEnabled(bool enabled, int _defaultComponentId) {
    if (!enabled) {
        rebDisable(_defaultComponentId);
    } else {
        rebEnable(_defaultComponentId);
    }
};

void ServoControl::setUniversalEnabled(bool enabled, int _defaultComponentId) {
    if (!enabled) {
        universalDisable(_defaultComponentId);
    } else {
        universalEnable(_defaultComponentId);
    }
};

// ----------------------------------------------------------------------------
void ServoControl::dayLightEnable(int _defaultComponentId) {
    // _defaultComponentId
    _vehicle->sendCommand(
        _defaultComponentId,
        MAV_CMD_DO_SET_SERVO,
        true,
        DAY_LIGHT_SERVO,
        SERVO_PWM_ON
    );                
};

// ----------------------------------------------------------------------------
void ServoControl::dayLightDisable(int _defaultComponentId) {
    // _defaultComponentId
    _vehicle->sendCommand(
        _defaultComponentId,
        MAV_CMD_DO_SET_SERVO,
        true,
        DAY_LIGHT_SERVO,
        SERVO_PWM_OFF
    );                
};

// ----------------------------------------------------------------------------
void ServoControl::nightLightEnable(int _defaultComponentId) {
    // _defaultComponentId
    _vehicle->sendCommand(
        _defaultComponentId,
        MAV_CMD_DO_SET_SERVO,
        true,
        NIGHT_LIGHT_SERVO,
        SERVO_PWM_ON
    );                
};

// ----------------------------------------------------------------------------
void ServoControl::nightLightDisable(int _defaultComponentId) {
    // _defaultComponentId
    _vehicle->sendCommand(
        _defaultComponentId,
        MAV_CMD_DO_SET_SERVO,
        true,
        NIGHT_LIGHT_SERVO,
        SERVO_PWM_OFF
    );                
};

// ----------------------------------------------------------------------------
void ServoControl::rebEnable(int _defaultComponentId) {
    // _defaultComponentId
    _vehicle->sendCommand(
        _defaultComponentId,
        MAV_CMD_DO_SET_SERVO,
        true,
        REB_SERVO,
        SERVO_PWM_ON
    );                
};

// ----------------------------------------------------------------------------
void ServoControl::rebDisable(int _defaultComponentId) {
    // _defaultComponentId
    _vehicle->sendCommand(
        _defaultComponentId,
        MAV_CMD_DO_SET_SERVO,
        true,
        REB_SERVO,
        SERVO_PWM_OFF
    );                
};

// ----------------------------------------------------------------------------
void ServoControl::universalEnable(int _defaultComponentId) {
    // _defaultComponentId
    _vehicle->sendCommand(
        _defaultComponentId,
        MAV_CMD_DO_SET_SERVO,
        true,
        UNIVERSAL_SERVO,
        SERVO_PWM_ON
    );                
};

// ----------------------------------------------------------------------------
void ServoControl::universalDisable(int _defaultComponentId) {
    // _defaultComponentId
    _vehicle->sendCommand(
        _defaultComponentId,
        MAV_CMD_DO_SET_SERVO,
        true,
        UNIVERSAL_SERVO,
        SERVO_PWM_OFF
    );                
};
