#include "virtualDevice.h"

RemoteDevice::RemoteDevice ()
{
}

RemoteDevice::RemoteDevice (std::string serial, DriverPose_t initialPose):
    serial_(serial),
    hmd_pose_(initialPose)
{
}

RemoteDevice::~RemoteDevice ()
{
}

void RemoteDevice::updateHMDPose (DriverPose_t newPose)
{
    hmd_pose_ = newPose;
}

uint32_t RemoteDevice::getObjectID () {
    return object_id_;
}

EVRInitError RemoteDevice::Activate (uint32_t unObjectId)
{
    object_id_ = unObjectId;
    PropertyContainerHandle_t propHandle = VRProperties() ->
        TrackedDeviceToPropertyContainer(object_id_);
    VRProperties() -> SetFloatProperty(propHandle, Prop_UserIpdMeters_Float, 0.065f);
    VRProperties() -> SetFloatProperty(propHandle, Prop_UserHeadToEyeDepthMeters_Float, 0.0f);
    VRProperties() -> SetFloatProperty(propHandle, Prop_DisplayFrequency_Float, 90.0f);
    VRProperties() -> SetFloatProperty(propHandle, Prop_SecondsFromVsyncToPhotons_Float, 0.1f);
    VRProperties() -> SetUint64Property(propHandle, Prop_CurrentUniverseId_Uint64, 2);

    // Properties related to virtual display
    VRProperties() -> SetFloatProperty(propHandle, Prop_SecondsFromVsyncToPhotons_Float, 0.0f);

    hmd_pose_.poseIsValid = true;
    hmd_pose_.result = TrackingResult_Running_OK;
    hmd_pose_.deviceIsConnected = true;

    hmd_pose_.qWorldFromDriverRotation = { 1, 0, 0, 0 };
    hmd_pose_.qDriverFromHeadRotation = { 1, 0, 0, 0 };

    return EVRInitError::VRInitError_None;
}

void RemoteDevice::Deactivate ()
{
}

void RemoteDevice::EnterStandby ()
{
}

void *RemoteDevice::GetComponent (const char *pchComponentNameAndVersion)
{
    if (!strcasecmp(pchComponentNameAndVersion, IVRVirtualDisplay_Version))
    {
        return static_cast< IVRVirtualDisplay* >(this);
    }

    return NULL;
}

void RemoteDevice::DebugRequest (const char *pchRequest, char *pchResponseBuffer, uint32_t unResponseBufferSize)
{
    if (unResponseBufferSize >= 1)
    {
        pchResponseBuffer[0] = 0;
    }
}

DriverPose_t RemoteDevice::GetPose ()
{
    return hmd_pose_;   
}

void RemoteDevice::Present (const PresentInfo_t *pPresentInfo, uint32_t unPresentInfoSize)
{
    /*
    // Do stuff
    std::string infoType = typeid(pPresentInfo).name();
    std::string message = "osascript -e 'tell app \"iTerm2\" to display dialog \""
    + infoType + "\"'";

    char output[message.length() + 1];
    strcpy(output, message.c_str());

    std::system(output); */

    std::system("osascript -e 'tell app \"iTerm2\" to display dialog \"Present called\"'");
}

void RemoteDevice::WaitForPresent ()
{
    // Do stuff
}

bool RemoteDevice::GetTimeSinceLastVsync (float *pfSecondsSinceLastVsync, uint64_t *pulFrameCounter)
{
    // Update stuff
    return true;
}