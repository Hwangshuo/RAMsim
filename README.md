# RAM Simulation using Verilator and DRAMsim3

**本方案将DRAMsim3模拟器与Verilator集成，实现了快速且灵活的RAM模拟方案。**<br>
>通过对DRAMsim3模拟器进行最小化的源码修改，新增了相关函数并暴露了读写握手信号与读数据等，支持单通道存储器的读写操作。同时，使用Verilator编译DRAMsim3提供的库文件，并提供了示例代码，使得本方案可以支持HBM、DDR4等多种存储器类型。未来还可增加AXI接口，将存储器接入AXI总线。<br><br>This solution integrates the DRAMsim3 simulator with Verilator, achieving a fast and flexible RAM simulation approach. By making minimal modifications to the DRAMsim3 simulator source code, new functions have been added and handshake signals for read/write and read data have been exposed, supporting single-channel memory read/write operations. Additionally, Verilator is used to compile the library files provided by DRAMsim3 and sample code is provided, enabling this solution to support various memory types including HBM and DDR4. In the future, an AXI interface can be added to connect the memory to the AXI bus

### 该分支支持verilator的DPI，能够在verilog中直接调用RAM模型