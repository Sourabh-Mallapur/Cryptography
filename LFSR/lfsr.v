`timescale 1ns/1ps

module lfsr(input wire clk, reset,
            input wire [4:0] rounds,
            output reg [21:0] bitstream
            );
         
reg r1, r2, r3, r4;
wire y1, y2, y3, y4;
reg [3:0] seed;
wire y5;
reg [4:0] counter;

always @(posedge clk)   begin
    if (reset)  begin
        seed = 4'b1110;
        r1 <= seed[3];
        r2 <= seed[2];
        r3 <= seed[1];
        r4 <= seed[0];
        counter <= rounds;
        bitstream <= 0;
    end
    if (~counter) begin
        r1 <= y5;
        r2 <= y1;
        r3 <= y2;
        r4 <= y3;
        counter = counter - 1'b1;
    bitstream = {bitstream[21:1],r4};
    bitstream = bitstream << 1;
    end
end
  

assign y1 = r1;
assign y2 = r2;
assign y3 = r3;
assign y4 = r4;
assign y5 = r1 ^ r2 ^ r4;
    
endmodule