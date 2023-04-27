DRAMsim3_DIR:= ../DRAMsim3
DRAMsim3_FMT_LIB_DIR:=.././RAMsim/DRAMsim3/ext/fmt/include
DRAMsim3_INI_LIB_DIR:=..././RAMsim/DRAMsim3/ext/headers
DRAMsim3_JSON_LIB_DIR:=.././RAMsim/DRAMsim3/ext/headers
DRAMsim3_ARGS_LIB_DIR:=../DRAMsim3/ext/headers
DRAMsim3_LIB_NAME:=libdramsim3.so
DRAMsim3_INTERFACE_DIR:=../interface
DRAMsim3_MEMORY_SYSTEM_DIR:=../DRAMsim3/src

INC:="-I$(DRAMsim3_INTERFACE_DIR) -I$(DRAMsim3_MEMORY_SYSTEM_DIR) -I$(DRAMsim3_FMT_LIB_DIR) -I$(DRAMsim3_INI_LIB_DIR) -I$(DRAMsim3_ARGS_LIB_DIR) -I$(DRAMsim3_JSON_LIB_DIR)"

VCS = vcs -full64 -sverilog -timescale=1ns/1ns \
		+v2k \
		-sv_lib libdramsim3.so \
		-CFLAGS $(INC) \
		-debug_access+all -kdb -lca \
		-f file.f
comp:
	-@ cd DRAMsim3 && make -j64
	-@ cp DRAMsim3/$(DRAMsim3_LIB_NAME) .
	$(VCS) 

verdi:
	# verdi -ssf rtl.fsdb
	./simv -gui=verdi 

clean:
	-rm -rf csrc simv* *.lib *.lib++ nLint*
	-rm -rf *.log *.vpd *.fsdb* *.key *log 
	-rm -rf novas*
	-rm -rf verdiLog DVEfiles
	-rm -rf .synopsys_dve_rebuild.tcl
	-rm -rf temp
	-rm -rf .inter.fsdb* .vcs_chec* libdramsim3.so vc_hdrs.h dramsim3*
	-rm -rf interface/*.o
	-@ cd DRAMsim3 && make clean
