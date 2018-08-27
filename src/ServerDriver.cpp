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
    // TODO
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