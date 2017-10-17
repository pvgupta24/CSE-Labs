/*
------------------------------------------------------
            Praveen Kumar Gupta  -  16CO235
            Durvesh Bhalekar     -  16CO210
------------------------------------------------------
    Prints Hello World at positive edge of clock
------------------------------------------------------

*/

`timescale 1ns/100ps

module PRINT(input wire clk);
    always @ (posedge clk)
        $monitor("%g ns --> Hello There !! ",$time);
endmodule

