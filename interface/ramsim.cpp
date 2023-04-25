#include "ramsim.h"

namespace dramsim3
{

    uint64_t rdata;
    bool rvalid;
    bool wvalid;
    using std::map;
    using std::pair;

    map<uint64_t, uint64_t> ram;

    queue<uint64_t> write_addr_return_queue;

    void RAM_module::ReadCallBack(uint64_t addr)
    {
        uint64_t index = read_request_queue.find(addr);

        if (index != 101) //
        {
            read_request_queue.replace(index, ram[addr]);
        }
        else
        {
            std::cout << "error";
            exit(0);
        }
        return;
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
        {
            memory_system_.AddTransaction(addr, false);
            read_request_queue.push(addr); // 将读请求发送到读请求队列中
        }

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

        std::cout << read_request_queue.size();

        if (read_request_queue.isReady()) // 队首元素是否准备好
        {
            rvalid = true;
            rdata = read_request_queue.getHeadValue();
            printf("read finish addr:%ld data:%ld", read_request_queue.front(), read_request_queue.getHeadValue());
            read_request_queue.pop();
            return true;
        }
        else
        {
            rvalid = false;
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
    uint64_t Queue::size()
    {
        // printf("rear:%ld head:%ld", rear, head);
        return (rear + MAX_SIZE - head) % MAX_SIZE;
    }
    uint64_t Queue::getHeadValue()
    {
        if (empty())
        {
            // std::cout << "Queue is empty." << std::endl;
            return 0;
        }
        return data[head][2];
    }

    bool Queue::isReady()
    {
        if (empty())
        {
            // std::cout << "Queue is empty." << std::endl;
            return false;
        }
        return data[head][1];
    }
    void Queue::replace(uint64_t index, uint64_t rdata)
    {
        data[index][1] = 1;
        data[index][2] = rdata;
    }
    void Queue::push(uint64_t x)
    {
        if ((rear + 1) % MAX_SIZE == head)
        {
            std::cout << "Queue is full." << std::endl;
            return;
        }
        data[rear][0] = x;
        data[rear][1] = 0;
        data[rear][2] = 0;
        rear = (rear + 1) % MAX_SIZE;
    }
    uint64_t Queue::pop()
    {
        if (head == rear)
        {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }
        uint64_t x = data[head][0];
        head = (head + 1) % MAX_SIZE;
        return x;
    }
    bool Queue::empty()
    {
        return head == rear;
    }
    bool Queue::full()
    {
        return (rear + 1) % MAX_SIZE == head;
    }
    uint64_t Queue::find(uint64_t x)
    {
        uint64_t i = head;
        while (i != rear)
        {
            if (data[i][0] == x)
            {
                return i;
            }
            i = (i + 1) % MAX_SIZE;
        }
        return 101;
    }
    uint64_t Queue::front()
    {
        if (empty())
        {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }
        return data[head][0];
    }
    uint64_t Queue::back()
    {
        if (empty())
        {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }
        return data[(rear - 1 + MAX_SIZE) % MAX_SIZE][0];
    }

} // namespace dramsim3