#include "ramsim.h"

namespace dramsim3 {

// bool StreamCPU::isReadReady()  // 能否
// {
//     return true;
// }

// bool StreamCPU::isWriteReady()  // 能否
// {
//     return true;
// }
// bool StreamCPU::isReadFinish()  // 能否
// {
//     return true;
// }
// bool StreamCPU::isWriteFinish()  // 能否
// {
//     return true;
// }
void CPU::ClockTick() {
    printf("clk = %3ld\t", clk_);
    memory_system_.ClockTick();
    clk_++;
    return;
}

uint64_t rdata;
using std::map;
using std::pair;
map<uint64_t, uint64_t> ram;

bool CPU::isReadReady(uint64_t addr) {
    return memory_system_.WillAcceptTransaction(addr, false);
}

void CPU::readValid(uint64_t addr) {
    if(isReadReady(addr))
    memory_system_.AddTransaction(addr, false);
    printf("\tread request , addr=%p\t", addr);
    return;
}

void CPU::writeValid(uint64_t addr, uint64_t wdata) {
    if(isWriteReady(addr))
    memory_system_.AddTransaction(addr, true);
    ram[addr] = wdata;
    printf("\twrite request , addr=%p, wdata=%ld\t", addr, wdata);
    // ram.insert(pair<uint64_t, uint64_t>(addr, wdata));
    return;
}

bool CPU::isWriteReady(uint64_t addr) {
    return memory_system_.WillAcceptTransaction(addr, true);
}

bool CPU::isReadFinish() {
    rdata = ram[read_addr];
    return read_fin;
}

bool CPU::isWriteFinish() { return write_fin; }

}  // namespace dramsim3