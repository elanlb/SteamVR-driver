#pragma once

#include <OpenVR/openvr_driver.h>
using namespace vr;

class ServerDriver : public IServerTrackedDeviceProvider
{
public:
    ServerDriver();
    
    ~ServerDriver();
    
    EVRInitError Init(IVRDriverContext *pDriverContext) override;

    void Cleanup() override;

    const char * const *GetInterfaceVersions() override;

    void RunFrame() override;

    bool ShouldBlockStandbyMode() override;

    void EnterStandby() override;

    void LeaveStandby() override;

private:
    static const char* const interfaces_[];
};