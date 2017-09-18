`timescale 1ns/100ps

module 16CO235-VD2;
 wire [3:0] res;
 wire [3:0] cout;

 reg [3:0] a;
 wire [3:0] b;
 wire cin;
  
 adder v1 (res, a, b, cin, cout);
 initial
 begin

  $dumpfile("16CO233-V1.vcd");
  $dumpvars(0,16CO233-V1);


  a = 4'b0000;      b = 4'b0000;     cin=1'0; 
  #10 a=4'b0001;    b=4'b0000;  cin=1'b0;


      #10 a=4'b0100;b=4'b0011;
      cin=1'b0;
      #10 a=4'b1101;b=4'b1010;
      cin=1'b0;
      #10 a=4'b1110;b=4'b1001;
      cin=1'b0;
      #10 a=4'b1111;b=4'b1010;
      cin=1'b0; 


 end
 initial #100 $finish
 endmodule