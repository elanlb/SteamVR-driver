#include "serverDriver.h"

const char* const ServerDriver::interfaces_[] = {
    IServerTrackedDeviceProvider_Version,
    IVRWatchdogProvider_Version
};

ServerDriver::ServerDriver ()
{
}

ServerDriver::~ServerDriver ()
{
}

EVRInitError ServerDriver::Init (IVRDriverContext *pDriverContext)
{
    VR_INIT_SERVER_DRIVER_CONTEXT(pDriverContext);

    DriverPose_t testPose = {0};
    testPose.deviceIsConnected = true;
    testPose.poseIsValid = true;
    testPose.willDriftInYaw = false;
    testPose.shouldApplyHeadModel = false;
    testPose.poseTimeOffset = 0;
    testPose.result = ETrackingResult::TrackingResult_Running_OK;
    testPose.qDriverFromHeadRotation = {1, 0, 0, 0};
    testPose.qWorldFromDriverRotation = {1, 0, 0, 0};

    VRControllerState_t testState;
    testState.ulButtonPressed = 0;

    hmd = DummyHMD("dummyHmd", testPose);
    VRServerDriverHost() -> TrackedDeviceAdded("dummyHmd", TrackedDeviceClass_HMD, &hmd);

    return EVRInitError::VRInitError_None;
}

void ServerDriver::Cleanup ()
{
    // TODO
}

const char * const *ServerDriver::GetInterfaceVersions ()
{
    return k_InterfaceVersions;
}

void ServerDriver::RunFrame ()
{
    static double angle = 0;
    angle += 0.01;

    static milliseconds lastMillis = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    milliseconds deltaTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()) - lastMillis;
    lastMillis = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

    DriverPose_t hmdPose = hmd.GetPose();
    DriverPose_t hmdPrevious = hmdPose;
    hmdPose.vecPosition[1] = 0.5 * - sin(angle);
    hmdPose.vecVelocity[1] = (hmdPose.vecPosition[1] - hmdPrevious.vecPosition[1]) * 1000 / std::max((int)deltaTime.count(), 1);
    hmd.updateHMDPose(hmdPose);
    VRServerDriverHost() -> TrackedDevicePoseUpdated(hmd.getObjectID(), hmd.GetPose(), sizeof(DriverPose_t));
}

bool ServerDriver::ShouldBlockStandbyMode ()
{
    return false;
}

void ServerDriver::EnterStandby ()
{
}

void ServerDriver::LeaveStandby ()
{
}