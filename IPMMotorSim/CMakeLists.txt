cmake_minimum_required(VERSION 3.19)

project(IPMMotorSim LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Charts)
qt_standard_project_setup()

set(CMAKE_CXX_STANDARD
    20
    CACHE INTERNAL "")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

qt_add_executable(
    IPMMotorSim
    WIN32 # Needed to avoid a stray console window on Windows
    main.cpp
    mainwindow.ui
    mainwindow.cpp
    chart.cpp
    chartview.cpp
    datagraph.cpp
    motormodel.cpp
    stm32-sine/libopeninv/src/params.cpp
    stm32-sine/libopeninv/src/picontroller.cpp
    stm32-sine/libopeninv/src/sine_core.cpp
    stm32-sine/src/pwmgeneration-foc.cpp
    stm32-sine/libopeninv/src/my_string.c
    stm32-sine/libopeninv/src/errormessage.cpp
    stm32-sine/libopeninv/src/foc.cpp
    teststubs.c
    cpp_teststubs.cpp
    stm32-sine/src/pwmgeneration.cpp
    idiqgraph.cpp
    terminal_stubs.cpp
)

target_include_directories(
    IPMMotorSim
    PRIVATE
    stm32-sine/include
    stm32-sine/libopencm3/include
    stm32-sine/libopeninv/include
)

target_compile_definitions(
    IPMMotorSim
    PRIVATE
    "CTRL_FOC=1"
    "CTRL_SINE=0"
    "CONTROL=CTRL_FOC"
    "STM32F1"
    "QT_DEPRECATED_WARNINGS")

target_compile_options(
    IPMMotorSim
    PRIVATE
    -Werror
    -Wall
    -Wextra # reasonable and standard

    -Wcast-align # warn for potential performance problem casts
    -Wunused # warn on anything being unused
    -Wpedantic # warn if non-standard C++ is used

    -Wnull-dereference # warn if a null dereference is detected
    -Wformat=2 # warn on security issues around functions that format output (ie printf)
    -Wimplicit-fallthrough # warn on statements that fallthrough without an explicit annotation

    $<$<COMPILE_LANGUAGE:CXX>:
    -Woverloaded-virtual # warn if you overload (not override) a virtual function
    >
)

target_link_libraries(
    IPMMotorSim
    PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Charts)
