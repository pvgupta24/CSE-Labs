/*
------------------------------------------------------
            Praveen Kumar Gupta  -  16CO235
            Durvesh Bhalekar     -  16CO210
------------------------------------------------------
           32-bit Register FILE using D Flip Flops
------------------------------------------------------

*/

// 32 32-bit registers in this module
module RF(clk,reg1,reg2,writereg,write,data,read1,read2,reset);
    input [4:0] reg1,reg2,writereg;
    input write,clk,reset;
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

// 32 bit register file using D FF's
module REG(input [31:0] data,input clk,output [31:0]out,input reset);
    genvar i;    
    generate
    for(i=0;i<32;i=i+1)
        begin : Register_Bits
          DFF flipBro(data[i],clk,out[i],reset);
        end
    endgenerate
endmodule

//D Flip Flops
module DFF(d,clk,q,reset);
    output reg q;
    input d,clk,reset;
    
   // initial 
    //  q = 1'b0;//Initialises once    
    always @ (posedge clk)
    begin
    if(reset)
        q=0;
    else
        q <= d;
    end

endmodule