#include "ramsim.h"

namespace dramsim3
{

    uint64_t rdata;
    uint64_t return_raddr;
    bool rvalid;
    bool wvalid;
    using std::map;
    using std::pair;
    using std::vector;
    map<uint64_t, uint64_t> ram;

    queue<uint64_t> write_addr_return_queue;
    queue<uint64_t> read_addr_return_queue;
    queue<uint64_t> read_value_return_queue;

    void RAM_module::ReadCallBack(uint64_t addr)
    {
        read_addr_return_queue.push(addr);
        read_value_return_queue.push(ram[addr]);
        // 每次读取完成往队列中push一次
    }

    void RAM_module::WriteCallBack(uint64_t addr)
    {
        write_addr_return_queue.push(addr); // 每次写完成往队列中push一次
    }

    void RAM_module::ClockTick()
    {

        printf("clk = %3ld\t", clk_);
        memory_system_.ClockTick();
        isReadFinish();
        isWriteFinish();
        clk_++;
        return;
    }

    bool RAM_module::isReadReady(uint64_t addr)
    {
        return memory_system_.WillAcceptTransaction(addr, false);
    }

    void RAM_module::readValid(uint64_t addr)
    {
        if (isReadReady(addr))
            memory_system_.AddTransaction(addr, false);
        printf("\tread request , addr=%ld\t", addr);
        return;
    }

    bool RAM_module::isWriteReady(uint64_t addr)
    {
        return memory_system_.WillAcceptTransaction(addr, true);
    }

    void RAM_module::writeValid(uint64_t addr, uint64_t wdata)
    {
        if (isWriteReady(addr))
            memory_system_.AddTransaction(addr, true);
        ram[addr] = wdata; // 往数组中存放读取结果
        printf("\twrite request , addr=%ld, wdata=%ld\t", addr, wdata);
        // ram.insert(pair<uint64_t, uint64_t>(addr, wdata));
        return;
    }

    bool RAM_module::isReadFinish()
    {
        if (!read_addr_return_queue.empty())
        {
            return_raddr = read_addr_return_queue.front();
            read_addr_return_queue.pop();
            rvalid = true;
            rdata = read_value_return_queue.front();
            read_value_return_queue.pop();
            printf("read finish addr:%ld data:%ld", return_raddr, rdata);
            return true;
        }
        else
        {
            rvalid = false;
            return_raddr = 0;
            return false;
        }
    }

    bool RAM_module::isWriteFinish()
    {
        if (!write_addr_return_queue.empty())
        {
            uint64_t return_waddr;
            wvalid = true;
            return_waddr = write_addr_return_queue.front();
            write_addr_return_queue.pop();
            printf("write finish addr:%ld data:%ld", return_waddr, rdata);
            return true;
        }
        else
        {
            wvalid = false;
            return false;
        }
    }
} // namespace dramsim3