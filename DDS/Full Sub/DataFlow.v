
module sub(diff,borr,in,din);

output diff,borr;
input [2:0] in;
input din;

assign diff = (din & ~in[2] & ~in[1] & in[0])  | (din & ~in[2] & in[1] & ~in[0])  |  
              (din & in[2] & ~in[1] & ~in[0])  | (din & in[2] & in[1] & in[0]);

assign borr = (din & ~in[2] & ~in[1] & in[0])  | (din & ~in[2] & in[1] & ~in[0])  |
              (din & ~in[2] & in[1] & in[0])  | (din & in[2] & in[1] & in[0]);

endmodule
