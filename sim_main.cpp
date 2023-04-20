#include <verilated.h>
// Include model header, generated from Verilating "top.v"
#include "Vtop.h"
#include "DRAMsim3/interface/ramsim.h"
int main(int argc, char** argv) {
// See a similar example walkthrough in the verilator manpage.
// This is intended to be a minimal example. Before copying this to start a
// real project, it is better to start with a more complete example,
// e.g. examples/c_tracing.
// Construct a VerilatedContext to hold simulation time, etc.
VerilatedContext* contextp = new VerilatedContext;
// Pass arguments so Verilated code can see them, e.g. $value$plusargs
// This needs to be called before you create any model
contextp->commandArgs(argc, argv);
// Construct the Verilated model, from Vtop.h generated from Verilating "top.v"
Vtop* top = new Vtop{contextp};
    printf("creta_success");
    std::string config_file = "../DRAMsim3/configs/DDR3_1Gb_x8_1333.ini";
    std::string output_dir = "../output.txt";
    using dramsim3::CPU;
    CPU* cpu;
    cpu = new CPU (config_file, output_dir);
    printf("creta_success");
    // cpu->clockTick();
    cpu->PrintStats();
    delete cpu;
// Simulate until $finish
while (!contextp->gotFinish()) {
// Evaluate model
top->eval();
}
// Final model cleanup
top->final();
// Destroy model
delete top;
// Return good completion status
return 0;
}
