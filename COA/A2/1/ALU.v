/*
------------------------------------------------------
            Praveen Kumar Gupta  -  16CO235
            Durvesh Bhalekar     -  16CO210
------------------------------------------------------
           				1-bit ALU
------------------------------------------------------

*/
module multiplexer1(A,B,Y,invert);
	input A,B;
	input invert;
	output Y;
	
	not(invert_bar,invert);
	and(Y1,A,invert_bar);
	and(Y2,B,invert);
	or(Y,Y1,Y2);
	
endmodule

//half-adder

module full_adder(S,C,X,Y,Z);
	input X,Y,Z;
	output S,C;
	
	xor(S,X,Y,Z);
	and(C1,X,Y);
	and(C2,Y,Z);
	and(C3,X,Z);
	or(C,C1,C2,C3);
	
endmodule

//Multiplexer2 --> 4:1 MUX

module multiplexer2(A,B,C,D,op,result);
	input A,B,C,D;
	input [0:1]op;
	output result;
	
	not(op0_bar,op[0]);
	not(op1_bar,op[1]);
	
	and(result1,A,op0_bar,op1_bar);
	and(result2,B,op0_bar,op[1]);
	and(result3,C,op[0],op1_bar);
	and(result4,D,op[0],op[1]);
	or(result,result1,result2,result3,result4);
	
endmodule

//Main ALU code
//flag2 to check whether the first input (A) is greater than second (B)
//flag2 will be 1 if first input (A) is greater than second input (B)

module ALU(A,B,Less,A_invert,B_invert,carry_in,result,carry,op,flag1,flag2);
	input A,B,Less,A_invert,B_invert,carry_in;
	input [0:1]op;
	output result,carry,flag2,flag1;
	
	not(A_bar,A);
	not(B_bar,B);
	multiplexer1 M1(.A(A),.B(A_bar),.Y(R1),.invert(A_invert));
	multiplexer1 M2(.A(B),.B(B_bar),.Y(R2),.invert(B_invert));
	and(In1,R1,R2);
	or(In2,R1,R2);
	full_adder F1(.S(R3),.C(carry),.X(carry_in),.Y(R1),.Z(R2));
    multiplexer2 M3(.A(In1),.B(In2),.C(R3),.D(Less),.op(op),.result(result));
	not(B_bar,B);
	not(flag1,result);
    and(flag2,B_bar,A);
	
endmodule



