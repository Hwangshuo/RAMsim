#include <verilated.h>
// Include model header, generated from Verilating "top.v"
#include "Vtop.h"
#include "ramsim.h"
int main(int argc, char **argv)
{
    // See a similar example walkthrough in the verilator manpage.
    // This is intended to be a minimal example. Before copying this to start a
    // real project, it is better to start with a more complete example,
    // e.g. examples/c_tracing.
    // Construct a VerilatedContext to hold simulation time, etc.
    VerilatedContext *contextp = new VerilatedContext;
    // Pass arguments so Verilated code can see them, e.g. $value$plusargs
    // This needs to be called before you create any model
    contextp->commandArgs(argc, argv);
    // Construct the Verilated model, from Vtop.h generated from Verilating "top.v"
    Vtop *top = new Vtop{contextp};
    printf("creta_success");
    
    uint64_t cycles = 100;
    std::string config_file = "../DRAMsim3/configs/DDR3_1Gb_x8_1333.ini";
    std::string output_dir = ".";
    using dramsim3::RAM_module;
    
    RAM_module *ram;
    ram = new RAM_module(config_file, output_dir);

    // std::mt19937_64 gen;
    // uint64_t addr_a_ = gen();//生成随机地址
    // uint64_t addr_b_ = gen();//生成随机地址
    // uint64_t addr_c_ = gen();//生成随机地址
    for (uint64_t i = 0; i < cycles; i++)
    {
        ram->ClockTick(); // 每个时钟周期TICK一次

        // if (ram->isWriteReady(i)&&i<20) {
        //     ram->writeValid(i,i*1000);  // 发送读请求 参数为读地址
        // }

        if (ram->isReadReady(0) && i >= 40 && i <= 60)
        {
            ram->readValid(0); // 发送读请求 参数为读地址
        }
        printf("\n");
    }
    while (!contextp->gotFinish())
    {
        // Evaluate model
        top->eval();
    }
    // Final model cleanup
    top->final();
    // Destroy model
    ram->PrintStats();
    delete ram;
    // Return good completion status
    return 0;
}
