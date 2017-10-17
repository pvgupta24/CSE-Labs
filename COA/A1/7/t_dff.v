/*
------------------------------------------------------
            Praveen Kumar Gupta  -  16CO235
            Durvesh Bhalekar     -  16CO210
------------------------------------------------------
    Testbench 32-bit Register using D Flip Flops
------------------------------------------------------

*/
`timescale 1ns/100ps

module dff;

    reg clk,d;
    wire q;

    DFF flipKaroKhushRaho(d,clk,q);

    initial 
    begin
        $dumpfile("dff.vcd");
        $dumpvars(0,dff);
        clk=1'b0;
        repeat(30)
            #3 clk = ~clk;
    end

    initial
    begin
        d = 1'b0;
        repeat(18)
            #5 d = ~d;
    end

    initial 
        begin 
            $monitor("Compiled. Check the wave.");
        end
endmodule