`timescale 1ns/100ps

module PRINT(input wire clk);

    always @ (posedge clk)
        $monitor("%g ns --> Hello There !! ",$time);

endmodule

