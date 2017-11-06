

//==================================================================

module counter(p1,r1,p2,r2,p3,r3,clk,a,b,c,anot,bnot,cnot);
    output a,b,c,anot,bnot,cnot;
    input p1,r1,p2,r2,p3,r3,clk;

    //Instantiate JK Flip Flops for A,B,C
    JK A(b,b,clk,r1,p1,a,anot);
    JK B(1,1,clk,r2,p2,b,bnot);
    JK C(1,anot,clk,r3,p3,c,cnot);

endmodule

//==================================================================

//Module for JK Flip Flop with preset and reset
module JK(j,k,clk,reset,preset,q,qb);
    //Port Declarations
    output reg q;
    output wire qb;
    input j,k,clk,preset,reset;

    //Positive edge trigger
    always @ (reset or preset or posedge clk)
        begin
            //Reset Q to 0
            if(reset)
                q <= 1'b0;
            //Set Q to 1
            else if(preset)
                q <= 1'b1;
            
            //J = 0, K = 0 => Q is same
            else if(j==0 && k==0)
                q <= q;

            //J = 0, K = 1 => Q is 0                
            else if(j==0 && k==1)
                q <= 0;

            //J = 1, K = 0 => Q is 1                                
            else if(j==1 && k==0)
                q <= 1;

            //J = 1, K = 1 => Q is toggled                            
            else if(j==1 && k==1)
                q <= ~q;
        end

    //Assign qnot = ~q
    assign qb = ~q;

endmodule

//==================================================================
