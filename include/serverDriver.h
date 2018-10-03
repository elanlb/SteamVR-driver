#pragma once

#include <math.h>
#include <chrono>
#include <openvr_driver.h>
using namespace std::chrono;

#include "remoteDevice.h"

class ServerDriver : public IServerTrackedDeviceProvider
{
public:
    ServerDriver();
    ~ServerDriver();
    
    vr::EVRInitError Init(vr::IVRDriverContext *pDriverContext) override;

    void Cleanup() override;

    const char* const *GetInterfaceVersions() override;

    void RunFrame() override;

    bool ShouldBlockStandbyMode() override;
    void EnterStandby() override;
    void LeaveStandby() override;

private:
    static const char* const interfaces_[];

    RemoteDevice hmd;
};