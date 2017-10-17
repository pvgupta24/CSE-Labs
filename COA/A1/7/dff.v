/*
------------------------------------------------------
            Praveen Kumar Gupta  -  16CO235
            Durvesh Bhalekar     -  16CO210
------------------------------------------------------
                      D FlipFlop
------------------------------------------------------

*/
module DFF(d,clk,q);
    output reg q;
    input d,clk;
    
    initial 
      q = 1'b0;//Initialises once
    
    always @ (posedge clk)
        q <= d;

endmodule