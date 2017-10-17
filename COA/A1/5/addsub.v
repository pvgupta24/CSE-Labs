/*
------------------------------------------------------
            Praveen Kumar Gupta  -  16CO235
            Durvesh Bhalekar     -  16CO210
------------------------------------------------------
        n-bit Adder/Subtractor using Full Adders
------------------------------------------------------

*/
`timescale 1ns/100ps

module addSub(S,C,A,b,cin);
    parameter n=4;
    input cin;
    input [n-1:0] A,b;
    output[n-1:0] S;
    reg[n-1:0] B;
    output[n:0] C;
    assign C[0]=cin;
    
    always @(cin or b)
        begin
            if(cin==1'b1)
                assign B = ~b;
            else
                assign B = b;            
        end
       
    genvar i;    
    generate
    for(i=0;i<n;i=i+1)
        begin : Ripple_Adder
          FA bitAdder(S[i],C[i+1],A[i],B[i],C[i]);
        end
    endgenerate
endmodule

module FA(S,C,a,b,c);
    output wire S,C;
    input wire a,b,c;
    wire firstSum,firstCarry,secondcarry; 
    HA firstHalf(firstSum,firstCarry,a,b);
    HA secondHalf(S,secondcarry,firstSum,c);
    assign C = secondcarry|firstCarry;

endmodule

module HA(S,C,a,b);    
    output reg S,C;
    input wire a,b;
    always @ (a or b)
        begin
            S = a^b;
            C = a&b;
        end
endmodule