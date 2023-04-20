
FMT_LIB_DIR=../../DRAMsim3/ext/fmt/include
INI_LIB_DIR=../../DRAMsim3/ext/headers
JSON_LIB_DIR=../../DRAMsim3/ext/headers
ARGS_LIB_DIR=../../DRAMsim3/ext/headers

INC="-I../../interface/ -I../../DRAMsim3/src/ -I$(FMT_LIB_DIR) -I$(INI_LIB_DIR) -I$(ARGS_LIB_DIR) -I$(JSON_LIB_DIR)"


all:
	export LD_LIBRARY_PATH=./
	cp  ../DRAMsim3/libdramsim3.so .
	# verilator   -cc --exe --build -j $(INC) top.v sim_main.cpp -LDFLAGS "  -L../../lib -ldramsim3"
	verilator  -cc --exe  -j top.v sim_main.cpp -LDFLAGS "  -L../ -ldramsim3 "
	CXXFLAGS=$(INC) make -j -C obj_dir -f Vtop.mk Vtop 
	obj_dir/Vtop
clean:
	rm -rf libdramsim3.so
	rm -rf obj_dir