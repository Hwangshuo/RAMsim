all:
	export LD_LIBRARY_PATH=./
	cp  DRAMsim3/libdramsim3.so .
	verilator -cc --exe --build -j top.v sim_main.cpp  -LDFLAGS "-L../ -ldramsim3"
	obj_dir/Vtop
clean:
	rm -rf libdramsim3.so
	rm -rf obj_dir