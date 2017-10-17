/*
------------------------------------------------------
            Praveen Kumar Gupta  -  16CO235
            Durvesh Bhalekar     -  16CO210
------------------------------------------------------
            Testbench For Hello World
------------------------------------------------------

*/

`timescale 1ns/100ps
module hello();
    reg clk;    
    PRINT print(clk);
    initial 
    begin
        $dumpfile("hello.vcd");
        $dumpvars(0,hello);
        clk=1'b0;
        repeat(100)
            #10 clk=~clk;           
        $finish;   
    end
endmodule