#ifndef __RAMSIMDPI_H
#define __RAMSIMDPI_H
#include <svdpi.h>
#include <iostream>
#include "ramsim.h"
extern "C" svBit isReadReady(long int raddr);

extern "C" svBit isWriteReady(long int raddr);

extern "C" void initial_RAM();

extern "C" void ClockTick();

extern "C" void readValid(long int raddr);

extern "C" void writeValid(long int waddr, long int wdata);

extern "C" long int readData();

extern "C" svBit isReadFinish();

extern "C" svBit isWriteFinish();

#endif