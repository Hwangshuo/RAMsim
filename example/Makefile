
DRAMsim3_DIR:= ../DRAMsim3
DRAMsim3_FMT_LIB_DIR:=../../DRAMsim3/ext/fmt/include
DRAMsim3_INI_LIB_DIR:=../../DRAMsim3/ext/headers
DRAMsim3_JSON_LIB_DIR:=../../DRAMsim3/ext/headers
DRAMsim3_ARGS_LIB_DIR:=../../DRAMsim3/ext/headers
DRAMsim3_LIB_NAME:=libdramsim3.so
DRAMsim3_INTERFACE_DIR:=../../interface
DRAMsim3_MEMORY_SYSTEM_DIR:=../../DRAMsim3/src

EXE:=obj_dir/Vtop

INC:="-I$(DRAMsim3_INTERFACE_DIR) -I$(DRAMsim3_MEMORY_SYSTEM_DIR) -I$(DRAMsim3_FMT_LIB_DIR) -I$(DRAMsim3_INI_LIB_DIR) -I$(DRAMsim3_ARGS_LIB_DIR) -I$(DRAMsim3_JSON_LIB_DIR)"

ALL:$(EXE)

$(DRAMsim3_LIB_NAME):
	-@$(MAKE) -C ../DRAMsim3
	-@cp  $(DRAMsim3_DIR)/libdramsim3.so lib/

$(EXE):$(DRAMsim3_LIB_NAME)
	verilator  -cc --exe  -j top.v sim_main.cpp -LDFLAGS "  -L../lib -ldramsim3 -Wl,-rpath=lib"
	CXXFLAGS=$(INC) make -j -C obj_dir -f Vtop.mk Vtop 
	-@echo -e "\n[Vtop translation and  compilation successful , You can use \"make run\" to performance it] "

run:
	-obj_dir/Vtop

clean:
	-@rm -rf obj_dir
	-@rm -f lib/libdramsim3.so
	-@cd  $(DRAMsim3_DIR) && $(MAKE) clean

.PHONY: clean ALL