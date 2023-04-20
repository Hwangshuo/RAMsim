#include "test.h"
using namespace dramsim3;
int main() {
    uint64_t cycles = 100;
    std::string config_file = "configs/DDR3_1Gb_x8_1333.ini";
    std::string output_dir = ".";

    CPU* cpu;
    cpu = new CPU(config_file, output_dir);
    std::mt19937_64 gen;
    uint64_t addr_a_ = gen();//生成随机地址
    uint64_t addr_b_ = gen();//生成随机地址
    uint64_t addr_c_ = gen();//生成随机地址

    for (uint64_t i = 0; i < cycles; i++) {
        cpu->ClockTick();  // 每个时钟周期TICK一次

        if (cpu->isReadFinish()) printf("rdata=%ld", rdata); //使用全局变量rdata,打印读取结果

        if (cpu->isWriteReady(addr_a_+i*8)&&i<20) {
            cpu->writeValid(addr_a_+i*8,i*8);  // 发送读请求 参数为读地址
        }

        if (cpu->isReadReady(addr_a_+(i-40)*8)&&i>=40&&i<=60) {
            cpu->readValid(addr_a_+(i-40)*8);  // 发送读请求 参数为读地址
        }

        printf("\n");
    }

    cpu->PrintStats();
    delete cpu;
    return 0;
}
