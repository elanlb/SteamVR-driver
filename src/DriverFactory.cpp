#include "driverFactory.h"

HMD_DLL_EXPORT void *HmdDriverFactory (const char *pInterfaceName, int *pReturnCode)
{
    if (0 == strcmp(IServerTrackedDeviceProvider_Version, pInterfaceName))
    {
        // success message!
        system("osascript -e 'tell app \"iTerm2\" to display dialog \"Hello\"'");
        
        // this was generated in driverFactory.h
        return &serverDriver;
    }
    if (0 == strcmp(IVRWatchdogProvider_Version, pInterfaceName))
    {
        return 0;
        //return &g_watchdogDriverNull;
    }
    
    if (pReturnCode)
    {
        // errored
        *pReturnCode = VRInitError_Init_InterfaceNotFound;
    }
    
    // if there is an error in the request, return null
    return NULL;
}