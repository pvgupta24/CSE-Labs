
module SISO(preset,reset,clk,ip,op,t1,t2,t3);
input preset,reset,clk,ip;
output op;
output t1,t2,t3;

DFF FF1(ip,clk,reset,preset,t1);
DFF FF2(t1,clk,reset,preset,t2);
DFF FF3(t2,clk,reset,preset,t3);
DFF FF4(t3,clk,reset,preset,op);
endmodule


module DFF(d,clk,reset,preset,q);
    output reg q;
    input d,clk,preset,reset;
    always @ (reset or preset or posedge clk)
        begin
            if(reset)
                q <= 1'b0;
            else if(preset)
                q <= 1'b1;
            else
                q <= d;
        end
endmodule
