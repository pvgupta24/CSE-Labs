module TFF(t,clk,q);

    output reg q;
    input t,clk;
    
    initial 
      q = 1'b0;
    
    always @ (posedge clk)
        q <= q^t;

endmodule