cmake_minimum_required(VERSION 3.10)

# Name your project
project(MCU_Project)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create ONE executable from all the source files combined
add_executable(mcu_app 
    main.cpp 
    mcu.cpp 
    mcu_walker.cpp 
    mcu_cam_controller.cpp
)