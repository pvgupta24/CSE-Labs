
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
    output q;
    input d,clk,preset,reset;
    wire dn,pn,rn,cn;
    wire m1,m2,s1,s2;
    wire m1n,m2n,s1n,s2n;
    /*
        assign m1 = ~(d & clk);
        assign m1n = ~(~d & clk);

        assign m2 = ~(~preset & m1 & m2n);
        assign m2n = ~(~reset & m1n & m2);

        assign s1 = ~(~clk & m2);
        assign s1n = ~(~clk & m2n);

        assign s2 = ~(s2n & s1);
        assign s2n = ~(s2 & s1n);
        assign q=s2;    */
    nand (m1,d,clk);
    not (dn,d);
    nand (m1n,dn,clk);

    not (pn,preset);
    not (rn,reset);
    
    nand (m2,pn,m1,m2n);
    nand (m2n,rn,m1n,m2);
    not(cn,clk);

    nand (s1,cn,m2);
    nand (s1n,cn,m2n);

    nand (s2,s2n,s1);
    nand (s2n,s2,s1n);
    buf (q,s2);
   
endmodule
