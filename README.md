[![Build Status](https://dev.azure.com/OxfordRSE/SlideSight/_apis/build/status/OxfordRSE.SlideSight?branchName=master)](https://dev.azure.com/OxfordRSE/SlideSight/_build/latest?definitionId=1&branchName=master)

# SlideSight

## Pre-requisites

The development Qt (https://www.qt.io/) libraries are required to build the GUI for this project.

### Ubuntu

```bash
$ sudo apt install qt5-default
```

## Build instructions

```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

### Build library only

To build just the library and not the GUI, which does not require `qt5`, run `cmake` with the following definition:

```
$ cmake .. -DSlideSight_BUILD_GUI:BOOL=OFF
```
