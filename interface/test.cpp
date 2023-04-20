#include "test.h"
using namespace dramsim3;
int main() {
    uint64_t cycles = 100;
    std::string config_file = "configs/DDR3_1Gb_x8_1333.ini";
    std::string output_dir = ".";

    RAM_module* ram;
    ram = new RAM_module(config_file, output_dir);

    
    // std::mt19937_64 gen;
    // uint64_t addr_a_ = gen();//生成随机地址
    // uint64_t addr_b_ = gen();//生成随机地址
    // uint64_t addr_c_ = gen();//生成随机地址

    for (uint64_t i = 0; i < cycles; i++) {
        ram->ClockTick();  // 每个时钟周期TICK一次

        // if (ram->isWriteReady(i)&&i<20) {
        //     ram->writeValid(i,i*1000);  // 发送读请求 参数为读地址
        // }

        if (ram->isReadReady(0)&&i>=40&&i<=60) {
            ram->readValid(0);  // 发送读请求 参数为读地址
        }
        // if (cpu->isReadReady(i)&&i<=20) {
        //    cpu->readValid(i);  // 发送读请求 参数为读地址
        // }
        printf("\n");
    }

    ram->PrintStats();
    delete ram;
    return 0;
}
