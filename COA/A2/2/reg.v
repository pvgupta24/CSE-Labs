/*
------------------------------------------------------
            Praveen Kumar Gupta  -  16CO235
            Durvesh Bhalekar     -  16CO210
------------------------------------------------------
           32-bit Register FILE using D Flip Flops
------------------------------------------------------

*/

module RF(clk,reg1,reg2,writereg,write,data,read1,read2);
    input [4:0] reg1,reg2,writereg;
    input write,clk;
    input [31:0] data;
    output reg [31:0] read1, read2;
    reg [31:0] REG [0:31];
    always @(posedge clk)
    begin
        if(write)
            begin
                REG[writereg]  <= data;
            end
        read1 <= REG[reg1];
        read2 <= REG[reg2];  
            
    end
    
endmodule


module REG(input [31:0] data,input clk,output [31:0]out);
    genvar i;    
    generate
    for(i=0;i<32;i=i+1)
        begin : Register_Bits
          DFF flipBro(data[i],clk,out[i]);
        end
    endgenerate
endmodule

module DFF(d,clk,q);
    output reg q;
    input d,clk;
    
    initial 
      q = 1'b0;//Initialises once    
    always @ (posedge clk)
        q <= d;

endmodule