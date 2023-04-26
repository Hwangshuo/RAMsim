`timescale 1ns / 1ns


module top (
    input clk,
    input rst_n,
    input rvalid,
    input wvalid,
    input [63:0] raddr,
    input [63:0] waddr,
    input [63:0] wdata,
    output readfin,
    output writefin,
    output readReady,
    output writeReady,
    output [63:0] rdata
);


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

endmodule
