# IPMMotorSim

[![Build status](../../actions/workflows/Build.yml/badge.svg)](../../actions/workflows/Build.yml)

This project is an IPM Motor simulator intended to be used with the Huebner inverter project, in particular the stm32-sine FOC firmware build. It is a fork of the original [IPM Motor Simulator](http://github.com/Pete9008/IPMMotorSim) made by Pete9008.

## Aims

The main aim of this project is to allow testing and development of the motor control sections of the inverter firmware in a safe reproducible environment.

The model is not intended to be perfect and is in the very early days of its development.  Hopefully it's good enough to be useful now and will develop into something more sophisticated over time.

## Binaries

Prebuilt binaries for Windows and Linux can be found on the most recent [Build](../../actions/workflows/Build.yml) run. The Linux binaries assume that Qt6 has been installed. The Windows binaries should just unzip and run.

## Compiling

Init the inverter source code by typing:

`git submodule update --init --recursive`

Build the software using CMake:

```text
mkdir build
cd build
cmake -S .. -G Ninja
cmake --build .
```

## Current Limitations

The simulator uses a number of new parameters not yet found in most builds of stm32-sin.  There is a replacement param_prj.h file in the project directory that will be used in place of the one in the subdirectory.  It is up to the user to ensure that the parameters contained in this replacement file are appropriate for whichever versions of the stn32-sine software is being used.

There is NO field validation on the GUI control fields, if you enter invalid values you will either get invalid simulation results or a program crash.

Not all GUI fields are supported by all versions of stm32-sine.

The simulator only exercises the main motor control sections of the stm32-sine software.  It does not fully simulate the lower level hardware peripherals of the processor (although it aims to accurately reflect their behaviour).  Nor does it exercise the higher level vehicle/charger control functions.

The model does not simulate drivetrain shunt (although it could be added relatively easily, see comments on source code).

Please note, as is says in the licence - This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE

For more information on this project please refer to <https://openinverter.org/forum/viewtopic.php?t=2611>
