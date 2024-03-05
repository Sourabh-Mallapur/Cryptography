`timescale 1ns/1ps
module lfsr_tb;

  //Ports
  reg clk, reset;
  reg [4:0] rounds;
  wire [21:0] bitstream;

  lfsr  lfsr_inst (
    .clk(clk),
    .reset(reset),
    .rounds(rounds),
    .bitstream(bitstream)
  );

    always #5  clk = ! clk ;
    initial begin  
    $dumpfile("dump.vcd");
    $dumpvars(0,lfsr_tb);
    rounds = 20;
    reset = 1; clk = 0;
    #7 reset = 0;
    #250
    $finish;
end
endmodule