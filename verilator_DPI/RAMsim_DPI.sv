`timescale 1ns / 1ns

import "DPI-C" context function bit isReadReady(longint raddr);  // sine function in C math library

import "DPI-C" context function bit isWriteReady(longint raddr);

import "DPI-C" context function void initial_RAM();  // sine function in C math library

import "DPI-C" context function void ClockTick();  // sine function in C math library

import "DPI-C" context function void readValid(longint raddr);

import "DPI-C" context function void writeValid(
  longint waddr,
  longint wdata
);

import "DPI-C" context function longint readData();

import "DPI-C" context function bit isReadFinish();

import "DPI-C" context function bit isWriteFinish();



module RAMsim_DPI (

    input clk,
    input rst_n,
    input rvalid,
    input wvalid,
    input [63:0] raddr,
    input [63:0] waddr,
    input [63:0] wdata,
    output reg readfin,
    output reg writefin,
    output reg readReady,
    output reg writeReady,
    output reg [63:0] rdata


);


  //检测到复位下降沿 即rst_n 1->0  即表示复位 

  always @(posedge clk or negedge rst_n) begin
    if (~rst_n) begin
      initial_RAM();
    end else begin
      ClockTick();

      readReady <= isReadReady(raddr);  // 能否接收读请求
      if (rvalid == 1 && readReady == 1) begin
        readValid(raddr);  //  发送读请求
      end

      writeReady <= isWriteReady(waddr);  // 能否接收写请求
      if (wvalid == 1 && writeReady == 1) begin
        writeValid(waddr, wdata);  //  发送读请求
      end

      readfin <= isReadFinish();  //读是否完成
      writefin <= isWriteFinish();  //写是否完成
      rdata <= readData();

    end
  end









endmodule
