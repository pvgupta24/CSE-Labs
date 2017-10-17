`timescale 1ns/100ps

module register;
    reg clk;
    reg[31:0]d;
    wire [31:0]q;

    REG myReg(d,clk,q);

    initial 
    begin
        $dumpfile("register.vcd");
        $dumpvars(0,register);
        clk=1'b0;
        repeat(30)
            #3 clk = ~clk;
    end

    initial
    begin
        d = 0;
        repeat(18)
            #5 d = d+6;
    end

    initial 
        begin 
            $monitor("Compiled. Check the wave.");
        end
endmodule