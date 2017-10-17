//  n-bit Adder/Subtractor. Using the FA module from the previous question, build an n-bit Adder/Subtractor module.
//  Value of ‘n’ should be configurable. Possible n values are 4,8,. . .,256.
`timescale 1ns/100ps

module addSub(S,C,A,b,cin);
    input cin;
    parameter n=4;
    input [n-1:0] A,b;
    output[n-1:0] S;
    reg[n-1:0] B;
    output C;
    reg tempCarry;
    
    always @(cin)
        begin
            if(cin==1'b1)
                assign B = ~b;
            else
                assign B = b;
            assign tempCarry=cin;
        end
       
    
    genvar i;    
    generate
    for(i=0;i<n;i=i+1)
        begin : Ripple_Adder
          FA bitAdder(S[i],C,A[i],B[i],tempCarry);
          initial
            assign tempCarry = C;
        end
    endgenerate
    //assign C = tempCarry;    
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