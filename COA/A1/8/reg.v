
module REG(input [31:0] data,input clk,output [31:0]out);
    //input[31:0] wire data;
    //input wire clk;
    //output[31:0] wire out;

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