

module seq(X,clk,p1,p2,r1,r2,q1,q2,y);
    input X,clk,p1,p2,r1,r2;
    output q1,q2;
    reg d1,d2;
    output reg y;

    DFF REG1(d1,clk,r1,p1,q1);
    DFF REG2(d2,clk,r2,p2,q2);
    always @(X)
        begin
          d1=(q1|q2)&X;
          d2= ~q1 & ~q2 & X;
          y=q2;
        end

endmodule

module DFF(d,clk,reset,preset,q);
    output reg q;
    input d,clk,preset,reset;
    always @ (posedge clk)
        begin
            if(reset)
                q <= 1'b0;
            else if(preset)
                q <= 1'b1;
            else
                q = d;
        end
endmodule