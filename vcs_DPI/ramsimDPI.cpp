
#include "ramsimDPI.h"
// Define the DPI function
// The function takes two 32-bit integers as input and returns a 32-bit integer

std::string config_file = "DRAMsim3/configs/DDR3_1Gb_x8_1333.ini";
std::string output_dir = ".";
bool rst = false;
using dramsim3::RAM_module;
RAM_module *ram;

svBit isReadReady(long int raddr)
{

    return ram->isReadReady(raddr);
}

svBit isWriteReady(long int raddr)
{

    return ram->isWriteReady(raddr);
}

void initial_RAM()
{
    if (rst == false)
    {
        ram = new RAM_module(config_file, output_dir);

#ifdef RAM_debug
        printf("initial success!\n");
#endif
        rst = true;
    }
}

void ClockTick()
{
    if (rst == 1)
        ram->ClockTick();
    else
    {
#ifdef RAM_debug
        printf("clocktick should behind rst");
#endif
    }
}

void readValid(long int raddr)
{
    ram->readValid(raddr);
}

void writeValid(long int waddr, long int wdata)
{
    ram->writeValid(waddr, wdata);
}

long int readData()
{
    return dramsim3::rdata;
}

svBit isReadFinish()
{

    return ram->isReadFinish();
}

svBit isWriteFinish()
{

    return ram->isWriteFinish();
}
