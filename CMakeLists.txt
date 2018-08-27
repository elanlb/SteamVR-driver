cmake_minimum_required(VERSION 3.0.0)
project(example)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_library(OPENVR_LIBRARIES OpenVR
    HINTS ${PROJECT_SOURCE_DIR}/lib/openvr/bin/osx64
)
mark_as_advanced(OPENVR_LIBRARIES)


add_library(${PROJECT_NAME} SHARED
    src/DriverFactory.cpp
    src/ServerDriver.cpp
    src/WatchdogDriver.cpp
)

target_link_libraries(${PROJECT_NAME} ${OPENVR_LIBRARIES})

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/bin
)