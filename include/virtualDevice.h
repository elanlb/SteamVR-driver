#pragma once

#include <openvr_driver.h>
using namespace vr;

class RemoteDevice : public ITrackedDeviceServerDriver, public IVRVirtualDisplay
{
public:
    RemoteDevice();
    RemoteDevice(std::string serial, DriverPose_t initialPose);
    ~RemoteDevice();
    virtual void updateHMDPose(DriverPose_t newPose);
    virtual uint32_t getObjectID();

    // Inherited via ITrackedDeviceServerDriver
    virtual EVRInitError Activate(uint32_t unObjectId) override;
    virtual void Deactivate() override;
    virtual void EnterStandby() override;
    virtual void *GetComponent(const char *pchComponentNameAndVersion) override;
    virtual void DebugRequest(const char *pchRequest, char *pchResponseBuffer, uint32_t unResponseBufferSize) override;
    virtual DriverPose_t GetPose() override;

    // Inherited via IVRVirtualDisplay
    virtual void Present(const PresentInfo_t *pPresentInfo, uint32_t unPresentInfoSize) override;
    virtual void WaitForPresent() override;
    virtual bool GetTimeSinceLastVsync(float *pfSecondsSinceLastVsync, uint64_t *pulFrameCounter) override;

private:
    uint32_t object_id_;
    std::string serial_;

    int window_width_ = 1200;
    int window_height_ = 800;
    int window_x_ = 1080;
    int window_y_ = 0;
    int separation_ = 75;

    DriverPose_t hmd_pose_;
};