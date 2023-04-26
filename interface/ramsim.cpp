#include "ramsim.h"

namespace dramsim3
{

    uint64_t rdata;
    using std::map;
    using std::pair;

    map<uint64_t, uint64_t> ram;

    queue<uint64_t> write_addr_return_queue;

    void RAM_module::ReadCallBack(uint64_t addr)
    {
        uint64_t index = read_request_queue.find(addr);

        if (index != MAX_SIZE + 1) //
        {
            read_request_queue.replace(index, ram[addr]);
        }
        else
        {
            printf("queue error at when ReadCallBack");
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

#ifdef RAM_debug
        printf("clk = %3ld\t", clk_);

#endif
        memory_system_.ClockTick();
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
#ifdef RAM_debug
        printf("\tread request , addr=%ld\t", addr);
#endif
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
#ifdef RAM_debug
        printf("\twrite request , addr=%ld, wdata=%ld\t", addr, wdata);
#endif
        // ram.insert(pair<uint64_t, uint64_t>(addr, wdata));
        return;
    }

    bool RAM_module::isReadFinish()
    {

        // printf("queue sieze: %ld",read_request_queue.size());

        if (read_request_queue.isReady()) // 队首元素是否准备好
        {
            rdata = read_request_queue.getHeadValue();
#ifdef RAM_debug
            printf("read finish addr:%ld data:%ld", read_request_queue.front(), read_request_queue.getHeadValue());
#endif

            read_request_queue.pop();
            return true;
        }
        else
        {

            return false;
        }
    }

    bool RAM_module::isWriteFinish()
    {
        if (!write_addr_return_queue.empty())
        {

            write_addr_return_queue.pop();
#ifdef RAM_debug
            uint64_t return_waddr;
            return_waddr = write_addr_return_queue.front();
            printf("write finish addr:%ld data:%ld", return_waddr, ram[return_waddr]);
#endif
            return true;
        }
        else
        {

            return false;
        }
    }
    uint64_t Queue::size()
    {

        return (rear + MAX_SIZE - head) % MAX_SIZE;
    }
    uint64_t Queue::getHeadValue()
    {
        if (empty())
        {

            return 0;
        }
        return data[head][2];
    }

    bool Queue::isReady()
    {
        if (empty())
        {

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
#ifdef RAM_debug
            std::cout << "Queue is full." << std::endl;
#endif
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
#ifdef RAM_debug
            std::cout << "Queue is empty." << std::endl;
#endif
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
        return MAX_SIZE + 1;
    }
    uint64_t Queue::front()
    {
        if (empty())
        {
#ifdef RAM_debug
            std::cout << "Queue is empty." << std::endl;
#endif
            return -1;
        }
        return data[head][0];
    }
    uint64_t Queue::back()
    {
        if (empty())
        {
#ifdef RAM_debug
            std::cout << "Queue is empty." << std::endl;
#endif
            return -1;
        }
        return data[(rear - 1 + MAX_SIZE) % MAX_SIZE][0];
    }

} // namespace dramsim3