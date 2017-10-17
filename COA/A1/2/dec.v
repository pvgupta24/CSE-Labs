
module DEC(a,b,c,d,out);
    input a,b,c,d;
    output reg [15:0] out;
    always @(a,b,c,d)
        begin
            assign out[0] = ~a & ~b & ~c & ~d;
            assign out[1] = ~a & ~b & ~c & d;
            assign out[2] = ~a & ~b & c & ~d;
            assign out[3] = ~a & ~b & c & d;
            assign out[4] = ~a & b & ~c & ~d;
            assign out[5] = ~a & b & ~c & d;
            assign out[6] = ~a & b & c & ~d;
            assign out[7] = ~a & b & c & d;
            assign out[8] = a & ~b & ~c & ~d;
            assign out[9] = a & ~b & ~c & d;
            assign out[10] = a & ~b & c & ~d;
            assign out[11] = a & ~b & c & d;
            assign out[12] = a & b & ~c & ~d;
            assign out[13] = a & b & ~c & d;
            assign out[14] = a & b & c & ~d;
            assign out[15] = a & b & c & d;            
        end
        /*begin
            if(c==1'b0 && d==1'b0)
                begin
                    assign out[3]=a&b;
                    assign out[2]=a&~b;
                    assign out[1]=~a&b;
                    assign out[0]=~a&~b;
                     
                end
            else if(c==1'b1 && d==1'b0)
                begin
                    assign out[7]=a&b;
                    assign out[6]=a&~b;
                    assign out[5]=~a&b;
                    assign out[4]=~a&~b;
                end
            else if(c==1'b0 && d==1'b1)
                begin
                    assign out[11]=a&b;
                    assign out[10]=a&~b;
                    assign out[9]=~a&b;
                    assign out[8]=~a&~b;
                end
            else if(c==1'b1 && d==1'b1)
                begin
                    assign out[15]=a&b;
                    assign out[14]=a&~b;
                    assign out[13]=~a&b;
                    assign out[12]=~a&~b;
                end
        end*/
endmodule
/*
module twoFour(input wire a,b,En,output reg[3:0] out);

    initial    
        if(En==1'b1)
            begin
                assign out[3]=a&b;
                assign out[2]=a&~b;
                assign out[1]=~a&b;
                assign out[0]=~a&~b;              
            end
endmodule
*/