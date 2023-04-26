#ifndef __RAMSIM_H
#define __RAMSIM_H
#include <fstream>
#include <functional>

#include <random>
#include <string>
#include "memory_system.h"
#include <map>
#include <queue>
#include <utility>

namespace dramsim3
{
    extern uint64_t rdata;
    extern bool rvalid;
    extern bool wvalid;

    using std::map;
    extern map<uint64_t, uint64_t> ram;
    using std::queue;
    extern queue<uint64_t> write_addr_return_queue;

    const uint64_t MAX_SIZE = 100;

    class Queue
    {
    private:
        uint64_t data[MAX_SIZE][3];
        uint64_t head, rear;

    public:
        Queue()
        {
            head = rear = 1;
        };
        void push(uint64_t);
        uint64_t pop();
        uint64_t front();
        uint64_t back();
        bool empty();
        bool full();
        uint64_t find(uint64_t);
        void replace(uint64_t, uint64_t);
        bool isReady();
        uint64_t getHeadValue();
        uint64_t size();
    };

    class RAM_module
    {
    public:
        RAM_module(const std::string &config_file, const std::string &output_dir)
            : memory_system_(
                  config_file, output_dir,
                  std::bind(&RAM_module::ReadCallBack, this, std::placeholders::_1),
                  std::bind(&RAM_module::WriteCallBack, this, std::placeholders::_1)),
              clk_(0) {rdata=0;}
        void ClockTick();
        void ReadCallBack(uint64_t addr);
        void WriteCallBack(uint64_t addr);
        void PrintStats() { memory_system_.PrintStats(); }
        bool isReadReady(uint64_t addr);     // 能否接收读请求
        void readValid(uint64_t);            // 发送读请求
        void writeValid(uint64_t, uint64_t); // 发送写请求
        bool isWriteReady(uint64_t addr);    // 能否接收写请求
        bool isReadFinish();                 // 读是否完成
        bool isWriteFinish();                // 写是否完成 

    protected:
        MemorySystem memory_system_;
        uint64_t clk_;
        Queue read_request_queue;
    };

} // namespace dramsim3
#endif
