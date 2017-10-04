
module sub(diff,borr,in,din);

    output reg diff,borr;
    input [2:0] in;
    input din;

    always @ (in or din)
        begin        
             diff = (din & ~in[2] & ~in[1] & in[0])  | (din & ~in[2] & in[1] & ~in[0])  |  
              (din & in[2] & ~in[1] & ~in[0])  | (din & in[2] & in[1] & in[0]);

             borr = (din & ~in[2] & ~in[1] & in[0])  | (din & ~in[2] & in[1] & ~in[0])  |
              (din & ~in[2] & in[1] & in[0])  | (din & in[2] & in[1] & in[0]);
        end

endmodule
