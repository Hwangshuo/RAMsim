#include <verilated.h>
// Include model header, generated from Verilating "top.v"
#include "Vtop.h"
#include <memory>

double sc_time_stamp() { return 0; }
int main(int argc, char **argv)
{
    if (false && argc && argv)
    {
    }
    Verilated::mkdir("logs");
    const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
    contextp->debug(0);
    contextp->randReset(2);
    contextp->commandArgs(argc, argv);
    const std::unique_ptr<Vtop> top{new Vtop{contextp.get(), "TOP"}};
    top->rst_n = 0;
    top->clk = 0;
    top->rvalid = 0;
    top->wvalid = 0;
    top->raddr = 0;
    top->waddr = 0;
    top->wdata = 0;
    top->readfin = 0;
    top->writefin = 0;
    top->readReady = 0;
    top->writeReady = 0;
    top->rdata = 0;
    int i = 0;
    while (!contextp->gotFinish())
    {
        contextp->timeInc(1);
        top->clk = !top->clk;
        if (!top->clk)
        {
            if (contextp->time() > 1 && contextp->time() < 10)
            {
                top->rst_n = 0; // Assert reset
            }
            else
            {
                top->rst_n = 1; // Deassert reset
            }

            if (contextp->time() > 30 && contextp->time() < 40)
            {
                top->wvalid = 1; // Assert reset
                top->waddr = i - 30;
                top->wdata = (i - 30) * 1000;
            }
            else
            {
                top->wvalid = 0; // Assert reset
                top->waddr = 0;
                top->wdata = 0;
            }

            if (contextp->time() > 60 && contextp->time() < 70)
            {
                top->rvalid = 1; // Assert reset
                top->raddr = i - 60;
            }
            else
            {
                top->rvalid = 0; // Assert reset
                top->raddr = 0;
            }

            if (contextp->time() > 100)
                break;
        }
        i++;
        top->eval();
        VL_PRINTF("[%3" PRId64 "] clk=%3x rst_n=%x rvalid=%x wvalid = %x raddr = %6" PRId64 " waddr = %6" PRId64 " wdata = %6" PRId64 "  readfin = %x writefin = %x readReady = %x writeReady = %x rdata = %6" PRId64 "\n",
                  contextp->time(),
                  top->clk, top->rst_n, top->rvalid,
                  top->wvalid,
                  top->raddr,
                  top->waddr,
                  top->wdata,
                  top->readfin,
                  top->writefin,
                  top->readReady,
                  top->writeReady,
                  top->rdata);
        // VL_PRINTF("\n[%" PRId64 "]\n",
        //           contextp->time());
    }
    top->final();
    return 0;
}