cmake_minimum_required(VERSION 3.0.0)
project(example)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(${PROJECT_NAME} SHARED
    src/DriverFactory.cpp
    src/ServerDriver.cpp
    src/WatchdogDriver.cpp
    src/RemoteDevice.cpp
)
# src/RemoteDevice.cpp

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

### OpenVR libraries ###
find_library(OPENVR_LIBRARIES OpenVR
    NAMES libopenvr_api.dylib
    HINTS ${PROJECT_SOURCE_DIR}/lib/openvr/bin/osx32
)
mark_as_advanced(OPENVR_LIBRARIES)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/lib/openvr/headers)
target_link_libraries(${PROJECT_NAME} ${OPENVR_LIBRARIES})


include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY
    DESTINATION ${PROJECT_SOURCE_DIR}/bin
)