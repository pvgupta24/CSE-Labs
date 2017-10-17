/*
------------------------------------------------------
            Praveen Kumar Gupta  -  16CO235
            Durvesh Bhalekar     -  16CO210
------------------------------------------------------
                    16 x 4 Encoder
------------------------------------------------------

*/
module ENC(code,out,En);
    output reg[3:0] out;
    input[15:0] code;
    input En;
    always @(En or code)
        begin
        assign out = 0;
        if (En) begin
            case (code) 
            1 : assign out =     0; 
            2 : assign out =     1; 
            4 : assign out =     2; 
            8 : assign out =     3;
            16 : assign out =    4; 
            32 : assign out =    5; 
            64 : assign out =    6; 
            128 : assign out =   7;
            256 : assign out =   8;
            512 : assign out =   9; 
            1024 : assign out =  10; 
            2048 : assign out =  11; 
            4096 : assign out =  12; 
            8192 : assign out =  13; 
            16384 : assign out = 14;
            32768 : assign out = 15; 
             
            endcase
        end
    end
endmodule
