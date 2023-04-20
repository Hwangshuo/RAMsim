#ifndef __RAMSIM_H
#define __RAMSIM_H
#include <fstream>
#include <functional>

#include <random>
#include <string>
#include "../src/memory_system.h"
#include <map>

namespace dramsim3 {

extern uint64_t rdata;
using std::map;
extern map<uint64_t,uint64_t>ram;

class CPU {
   public:
    CPU(const std::string& config_file, const std::string& output_dir)
        : memory_system_(
              config_file, output_dir,
              std::bind(&CPU::ReadCallBack, this, std::placeholders::_1),
              std::bind(&CPU::WriteCallBack, this, std::placeholders::_1)),
          clk_(0) {}
    void ClockTick();
    void ReadCallBack(uint64_t addr) { return; }
    void WriteCallBack(uint64_t addr) { return; }
    void PrintStats() { memory_system_.PrintStats();}
    bool isReadReady(uint64_t addr);  //能否接收读请求
    void readValid(uint64_t );  //发送读请求
    void writeValid(uint64_t ,uint64_t );  //发送写请求
    bool isWriteReady(uint64_t addr);  // 能否接收写请求
    bool isReadFinish();  // 读是否完成
    bool isWriteFinish();  // 写是否完成 }


   protected:
    MemorySystem memory_system_;
    uint64_t clk_;
};


// class CPU {
//    public:
//     CPU(const std::string& config_file, const std::string& output_dir)
//         : memory_system_(
//               config_file, output_dir,
//               std::bind(&CPU::ReadCallBack, this, std::placeholders::_1),
//               std::bind(&CPU::WriteCallBack, this, std::placeholders::_1)),
//           clk_(0) {}
//     virtual void ClockTick() = 0;
//     void ReadCallBack(uint64_t addr) { return; }
//     void WriteCallBack(uint64_t addr) { return; }
//     void PrintStats() { memory_system_.PrintStats();}
//     void clockTick();
//     bool isReadReady();  // 能否
//     bool isWrtieReady();  // 能否
//     bool isReadFinish();  // 能否
//     bool isWriteFinish();  // 能否 }


//    protected:
//     MemorySystem memory_system_;
//     uint64_t clk_;
// };

// class StreamCPU : public CPU {
//    public:
//     using CPU::CPU; //继承构造函数
//     void ClockTick() override;


//    private:
//     uint64_t addr_a_, addr_b_, addr_c_, offset_ = 0;
//     std::mt19937_64 gen;
//     bool inserted_a_ = false;
//     bool inserted_b_ = false;
//     bool inserted_c_ = false;
//     const uint64_t array_size_ = 2 << 20;  // elements in array
//     const int stride_ = 64;                // stride in bytes
// };

}  // namespace dramsim3
#endif
