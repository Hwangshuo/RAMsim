#include "test.h"
using namespace dramsim3;
int main() {
    uint64_t cycles = 100;
    std::string config_file = "configs/DDR3_1Gb_x8_1333.ini";
    std::string output_dir = ".";

    CPU* cpu;
    cpu = new CPU(config_file, output_dir);
    std::mt19937_64 gen;
    uint64_t addr_a_ = gen();
    uint64_t addr_b_ = gen();
    uint64_t addr_c_ = gen();

    for (uint64_t i = 0; i < cycles; i++) {
        cpu->ClockTick();  // 每个时钟周期TICK一次

        if (cpu->isReadFinish()) printf("rdata=%ld", rdata);


        if (cpu->isReadReady(addr_a_+i*8)&&i<20) {
            cpu->readValid(addr_a_+i*8);  // 发送读请求 参数为读地址
        }
        // if (cpu->isWrtieReady(addr_a_) && (i==20)) {
        //     std::mt19937_64 gen;
        //     cpu->writeValid(addr_a_, uint64_t(100));  // 发送读请求 参数为读地址
        // }

        // if (cpu->isReadReady(addr_a_) && (i>=30&&i<=36 )) {
        //     cpu->readValid(addr_a_);  // 发送读请求 参数为读地址
        // }

        printf("\n");
    }

    cpu->PrintStats();
    delete cpu;
    return 0;
}
