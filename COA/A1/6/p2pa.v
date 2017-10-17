/*
------------------------------------------------------
            Praveen Kumar Gupta  -  16CO235
            Durvesh Bhalekar     -  16CO210
------------------------------------------------------
       Point to Point Interconnection Network - A
------------------------------------------------------

*/
`timescale 1ns/100ps

module A(output reg[3:0] outMsg,input[3:0] inMsg,input clk);
    reg[9:0] currCycle = 0;
    reg temp;
    parameter MaxPeriod = 2;
    always@(posedge clk) begin
        currCycle = currCycle + 1;
        if(inMsg!==4'bzzzz) begin
            $display("A recieved %b at %g ns",inMsg,$time);
        end
        if(currCycle == MaxPeriod) begin
            currCycle = 0;
            outMsg <= {$random}%16;
        end
    end
endmodule

module B(output reg[3:0] outMsg,input[3:0] inMsg,input clk);
    reg [9:0]currCycle = 1;
    reg temp;
    parameter MaxPeriod = 2;
    initial begin
        currCycle = 1;
    end
    always @(posedge clk) begin
        currCycle = currCycle + 1;
        if(inMsg!==4'bzzzz ) begin
            $display("B recieved %b at %g ns\n",inMsg,$time);
        end
        if(currCycle == MaxPeriod) begin
            currCycle = 0;
            outMsg <= {$random}%16;
        end
    end
endmodule

module p2pa;
    reg clk=0;
    wire[3:0] aOut;
    wire[3:0] bOut;
    wire w1,w2;
    
    A m1(aOut,bOut,clk);
    B m2(bOut,aOut,~clk);

    initial begin
        $dumpfile("p2pa.vcd");
        $dumpvars(0,p2pa); 
        repeat(40)
            #5 clk = ~clk;
        $finish;
    end
endmodule