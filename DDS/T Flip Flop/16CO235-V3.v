`timescale 1ns/100ps

module t_16CO235;

    reg clk,t;
    wire q;

    TFF flipKaroKhushRaho(t,clk,q);

    initial 
    begin
        $dumpfile("16CO235-V3.vcd");
        $dumpvars(0,t_16CO235);
        clk=1'b0;
        repeat(30)
            #3 clk = ~clk;
    end

    initial
    begin
        t = 1'b0;
        repeat(18)
            #5 t = ~t;
    end

    initial 
        begin 
            $monitor("Compiled bro. Check the wave.");
        end
endmodule