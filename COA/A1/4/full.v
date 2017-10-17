/*
------------------------------------------------------
            Praveen Kumar Gupta  -  16CO235
            Durvesh Bhalekar     -  16CO210
------------------------------------------------------
              Full Adder using Half Adders
------------------------------------------------------

*/
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
            S=a^b;
            C=a&b;
        end
endmodule