`timescale 1ns / 1ns


module top ();
  reg clk;
  reg rst_n;
  reg rvalid;
  reg wvalid;
  reg [63:0] raddr;
  reg [63:0] waddr;
  reg [63:0] wdata;
  wire readfin;
  wire writefin;
  wire readReady;
  wire writeReady;
  wire [63:0] rdata;
  initial begin
    clk   = 0;
    rst_n = 0;
    #20 @(posedge clk) rst_n = 1;
    @(posedge clk) raddr = 13;
    rvalid = 1;

    #10 @(posedge clk) raddr = 0;
    rvalid = 0;

    #100
    $finish();
  end



  always #5 clk = ~clk;


  RAMsim_DPI inst0 (
      clk,
      rst_n,
      rvalid,
      wvalid,
      raddr,
      waddr,
      wdata,
      readfin,
      writefin,
      readReady,
      writeReady,
      rdata
  );

  initial begin
    $fsdbDumpfile("./rtl.fsdb");
    $fsdbDumpvars("+all");
  end

endmodule
