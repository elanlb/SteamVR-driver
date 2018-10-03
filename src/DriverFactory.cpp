#include "driverFactory.h"

HMD_DLL_EXPORT void *HmdDriverFactory (const char *pInterfaceName, int *pReturnCode)
{
    if (0 == strcmp(IServerTrackedDeviceProvider_Version, pInterfaceName))
    {
        // this was generated in driverFactory.h
        return &serverDriver;
    }
    if (0 == strcmp(IVRWatchdogProvider_Version, pInterfaceName))
    {
        // also generated in driverFactory.h
        return &watchdogDriver;
    }
    
    if (pReturnCode)
    {
        // errored
        *pReturnCode = VRInitError_Init_InterfaceNotFound;
    }
    
    // if there is an error in the request, return null
    return NULL;
}