/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include "FactGroup.h"
#include "QGCMAVLink.h"

class VehicleServoFactGroup : public FactGroup
{
    Q_OBJECT

public:
    static const int cMaxServoPackets = 16;

    VehicleServoFactGroup(QObject* parent = nullptr);

    Q_PROPERTY(Fact* dayLight   READ dayLight   CONSTANT)
    Q_PROPERTY(Fact* nightLight READ nightLight CONSTANT)
    Q_PROPERTY(Fact* reb READ reb CONSTANT)
    Q_PROPERTY(Fact* universal READ universal CONSTANT)

    Fact* dayLight         () { return &_dayLightFact; }
    Fact* nightLight       () { return &_nightLightFact; }
    Fact* reb              () { return &_rebFact; }
    Fact* universal        () { return &_universalFact; }

    // Overrides from FactGroup
    virtual void handleMessage(Vehicle* vehicle, mavlink_message_t& message) override;

    static const char* _dayLightFactName;
    static const char* _nightLightFactName;
    static const char* _rebFactName;
    static const char* _universalFactName;

protected:
    void _handleServoOutputRaw(mavlink_message_t& message);

    Fact _dayLightFact;
    Fact _nightLightFact;
    Fact _rebFact;
    Fact _universalFact;
};
