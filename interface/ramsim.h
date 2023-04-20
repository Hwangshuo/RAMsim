#ifndef __RAMSIM_H
#define __RAMSIM_H
#include <fstream>
#include <functional>

#include <random>
#include <string>
#include "../DRAMsim3/src/memory_system.h"
#include <map>
#include <queue>
#include <utility>

namespace dramsim3
{

    extern uint64_t rdata;
    extern uint64_t return_raddr;
    extern bool rvalid;
    extern bool wvalid;

    using std::map;
    extern map<uint64_t, uint64_t> ram;
    using std::queue;
    extern queue<uint64_t> write_addr_return_queue;
    extern queue<uint64_t> read_addr_return_queue;
    extern queue<uint64_t> read_value_return_queue;
    class RAM_module
    {
    public:
        RAM_module(const std::string &config_file, const std::string &output_dir)
            : memory_system_(
                  config_file, output_dir,
                  std::bind(&RAM_module::ReadCallBack, this, std::placeholders::_1),
                  std::bind(&RAM_module::WriteCallBack, this, std::placeholders::_1)),
              clk_(0) {}
        void ClockTick();
        void ReadCallBack(uint64_t addr);
        void WriteCallBack(uint64_t addr);
        void PrintStats() { memory_system_.PrintStats(); }
        bool isReadReady(uint64_t addr);     // 能否接收读请求
        void readValid(uint64_t);            // 发送读请求
        void writeValid(uint64_t, uint64_t); // 发送写请求
        bool isWriteReady(uint64_t addr);    // 能否接收写请求
        bool isReadFinish();                 // 读是否完成
        bool isWriteFinish();                // 写是否完成 }

    protected:
        MemorySystem memory_system_;
        uint64_t clk_;
    };

} // namespace dramsim3
#endif
