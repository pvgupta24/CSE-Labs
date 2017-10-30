/*
------------------------------------------------------
            Praveen Kumar Gupta  -  16CO235
            Durvesh Bhalekar     -  16CO210
------------------------------------------------------
Testbench for 32-bit Register FILE using D Flip Flops
------------------------------------------------------

*/

`timescale 1ns/100ps

module t_reg;

reg clk,write;
reg [4:0] reg1,reg2,writereg;
reg [31:0] data;
wire [31:0] read1,read2;

RF registerFile(clk,reg1,reg2,writereg,write,data,read1,read2);

initial
begin
    $dumpfile("regWave.vcd");
    $dumpvars(0,t_reg);
    $display("Time\twrite\twritereg\tdata\treg1\treg2\t\tread1\t\tread2\n=======================================================================================");
end
initial
    begin
        #2;
        clk=1'b0;
        repeat(100)
            begin
                #5;
                write = $random % 2;
                data = $urandom % 1000;
                writereg = $random % 5;
                reg1 = $random % 5;
                reg2 = $random % 5;
            end

        $finish;
        
    end

initial
    forever
        #5 clk = ~clk;

initial
    $monitor("%g ns\t%b\t%d\t%d\t%d\t%d\t%d\t%d",$time,write,writereg,data,reg1,reg2,read1,read2);
endmodule