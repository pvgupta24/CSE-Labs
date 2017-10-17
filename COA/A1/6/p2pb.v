/*
------------------------------------------------------
            Praveen Kumar Gupta  -  16CO235
            Durvesh Bhalekar     -  16CO210
------------------------------------------------------
       Point to Point Interconnection Network - B
------------------------------------------------------

*/
`timescale 1ns/100ps

module A(output reg[3:0] outMsg,input[3:0] inMsg,input clk);
    reg[3:0] rnd=3'b000;
    always@(posedge clk) begin
       // if(rnd==3'b000) begin
            rnd <= {$random}%16+1;
            outMsg <= {$random}%8;
            $display("A sent %b to B at %0t.",outMsg,$time);
            $display("B responded with %b\n",inMsg);
       // end
        //else begin
            //outMsg = 4'bzzzz;
        //    rnd <= rnd - 1;
       // end        
    end
endmodule

module B(output reg[3:0] outMsg,input[3:0] inMsg,input clk);
    always @(posedge clk) begin
        //if(inMsg !== 4'bzzzz) begin
            outMsg[0] <= {$random}%16;
            outMsg[1] <= {$random}%16;
            outMsg[2] <= {$random}%16;
            outMsg[3] <= {$random}%16;
        //end
    end
endmodule


module p2pb;
    reg clk=0;
    wire[3:0] m1_out;
    wire[3:0]  m2_out;
    wire w1,w2;
    
    A m1(m1_out,m2_out,clk);
    B m2(m2_out,m1_out,clk);
    
    initial
        repeat(200)
            #5 clk = ~clk;
    /*always begin
        #5 clk = ~clk;
    end
    initial begin
        $dumpfile("p2pb.vcd");
        $dumpvars(0,p2pb);
        #1000 $finish;
    end*/
endmodule