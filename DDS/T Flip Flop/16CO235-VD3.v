module TFF(t,clk,q);

    output q;
    input t, clk;
   
    wire temp;
    assign temp = q^t;    
    DFF flipItBro(temp, clk, q);

endmodule


module DFF(d,clk,q);
    initial 
      q = 1'b0;

    output reg q;
    input d, clk;
    always@ (posedge clk)
         q = d;
endmodule