cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME wigthfreq)

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here

    #FreeRTOS source files
    Drivers/FreeRTOS_f4/src/croutine.c
    Drivers/FreeRTOS_f4/src/event_groups.c
    Drivers/FreeRTOS_f4/src/list.c
    Drivers/FreeRTOS_f4/src/queue.c
    Drivers/FreeRTOS_f4/src/stream_buffer.c
    Drivers/FreeRTOS_f4/src/tasks.c
    Drivers/FreeRTOS_f4/src/timers.c

    Drivers/FreeRTOS_f4/port/MemMang/heap_4.c
    Drivers/FreeRTOS_f4/port/GCC/ARM_CM4F/port.c

    #self--HAL source files

    #self--HARDWARE source files
    self/HARDWARE/STM32H7xx/Src/self_gpio.c

    #self--DRIVER source files
    self/DRIVER/Src/relay.c
    self/DRIVER/Src/led.c

    #self--APP source files
    self/APP/Src/self_task.c
    self/APP/Src/led_task.c

)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths

    #FreeRTOS include paths
    Drivers/FreeRTOS_f4/include
    Drivers/FreeRTOS_f4/port/MemMang/
    Drivers/FreeRTOS_f4/port/GCC/ARM_CM4F

    #self--HAL include paths
    self/HAL/Inc

    #self--HARDWARE source files
    self/HARDWARE/STM32H7xx/Inc

    #self--DRIVER include paths
    self/DRIVER/Inc

    #self--APP include paths
    self/APP/Inc
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Remove wrong libob.a library dependency when using cpp files
list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx

    # Add user defined libraries
)
