/*
------------------------------------------------------
            Praveen Kumar Gupta  -  16CO235
            Durvesh Bhalekar     -  16CO210
------------------------------------------------------
           		Testbench for 1-bit ALU
------------------------------------------------------

*/
`timescale 1ns/10ps

module t_ALU;
	wire result,carry,flag2,flag1;
	reg  A,B,Less,A_invert,B_invert,carry_in;
	reg [0:1]op;
	
	ALU MM1(.A(A),.B(B),.Less(Less),.A_invert(A_invert),.B_invert(B_invert),.carry_in(carry_in),.result(result),.carry(carry),.op(op),.flag1(flag1),.flag2(flag2));
	
	initial
	begin
		$dumpfile("t_ALU.vcd");
		$dumpvars(0,t_ALU);
		
		//for AND and OR
		
		carry_in=1'b0;
		A_invert=1'b0;
		B_invert=1'b0;
		
		A=1'b0;
		B=1'b0;
		
		$display(" \ncarry_in = %b , A_invert = %b , B_invert = %b , A = %b , B = %b ,flag1 = %b , flag2 = %b",carry_in,A_invert,B_invert,A,B,flag1,flag2);
		#1;
		$display(" ------------------------------------------------------------------------------------------ ");
		#1
		
		op=2'b00;
		$display("AND result = %b , op = %b \n",result,op);
		#10;
		
		op=2'b01;
		$display("OR result = %b , op = %b \n",result,op);
		#10;
		
		op=2'b10;
		$display("ADDITION result = %b , op = %b \n",result,op);
		#10;
		
		A=1'b0;
		B=1'b1;
		
		$display(" \ncarry_in = %b , A_invert = %b , B_invert = %b , A = %b , B = %b ,flag1 = %b , flag2 = %b",carry_in,A_invert,B_invert,A,B,flag1,flag2);
		#1;
		$display("-------------------------------------------------------------------------------------------- ");
		#1
		
		op=2'b00;
		$display("AND result = %b , op = %b \n",result, op);
		#10;
		
		op=2'b01;
		$display("OR result = %b , op = %b \n",result,op);
		#10;
		
		op=2'b10;
		$display("ADDITION result = %b , op = %b \n",result,op);
		#10;
		
		A=1'b1;
		B=1'b0;
		
 		$display(" \ncarry_in = %b , A_invert = %b , B_invert = %b , A = %b , B = %b ,flag1 = %b , flag2 = %b",carry_in,A_invert,B_invert,A,B,flag1,flag2);
		#1;
		$display("----------------------------------------------------------------------------------------- ");
		#1
		
		op=2'b00;
		$display("AND result = %b , op = %b \n",result,op);
		#10;
		
		op=2'b01;
		$display("OR result = %b , op = %b \n",result,op);
		#10;
		
		op=2'b10;
		$display("ADDITION result = %b , op = %b\n",result,op);
		#10;
		
		A=1'b1;
		B=1'b1;
		
		$display(" \ncarry_in = %b , A_invert = %b , B_invert = %b , A = %b , B = %b ,flag1 = %b , flag2 = %b",carry_in,A_invert,B_invert,A,B,flag1,flag2);
		#1;
		$display("----------------------------------------------------------------------------------------------- ");
		#1
		
		op=2'b00;
		$display("AND result = %b , op = %b\n",result,op);
		#10;
		
		op=2'b01;
		$display("OR result = %b , op = %b\n",result,op);
		#10;
		
		op=2'b10;
		$display("ADDITION result = %b , op = %b\n",result,op);
		#10;
		
		//---------------------------------------------------------------------------------------------------------------------------------
		//For NOR and NAND
		
		carry_in=1'b1;
		A_invert=1'b1;
		B_invert=1'b1;
		
		A=1'b0;
		B=1'b0;
		
		$display(" \n carry_in = %b , A_invert = %b , B_invert = %b , A = %b , B = %b ,flag1 = %b , flag2 = %b",carry_in,A_invert,B_invert,A,B,flag1,flag2);
		#1;
		$display(" ----------------------------------------------------------------------------------------------- ");
		#1
		
		op=2'b00;
		$display("NOR result = %b , op = %b \n",result,op);
		#10;
		
		op=2'b01;
		$display("NAND result = %b , op = %b \n",result,op);
		#10;
		
		
		A=1'b0;
		B=1'b1;
		
		$display(" \n carry_in = %b , A_invert = %b , B_invert = %b , A = %b , B = %b ,flag1 = %b , flag2 = %b",carry_in,A_invert,B_invert,A,B,flag1,flag2);
		#1;
		$display(" --------------------------------------------------------------------------------------------- ");
		#1
		
		op=2'b00;
		$display("NOR result = %b , op = %b \n",result,op);
		#10;
		
		op=2'b01;
		$display("NAND result = %b , op = %b \n",result,op);
		#10;
		
		
		A=1'b1;
		B=1'b0;
		
		$display(" \n carry_in = %b , A_invert = %b , B_invert = %b , A = %b , B = %b ,flag1 = %b , flag2 = %b",carry_in,A_invert,B_invert,A,B,flag1,flag2);
		#1;
		$display(" ------------------------------------------------------------------------------------------- ");
		#1
		
		op=2'b00;
		$display("NOR result = %b , op = %b \n",result,op);
		#10;
		
		op=2'b01;
		$display("NAND result = %b , op = %b \n",result,op);
		#10;
		
		A=1'b1;
		B=1'b1;
		
		$display(" \n carry_in = %b , A_invert = %b , B_invert = %b , A = %b , B = %b ,flag1 = %b , flag2 = %b",carry_in,A_invert,B_invert,A,B,flag1,flag2);
		#1;
		$display(" ------------------------------------------------------------------------------------------- ");
		#1
		
		op=2'b00;
		$display("NOR result = %b , op =%b \n",result,op);
		#10;
		
		op=2'b01;
		$display("NAND result = %b , op = %b \n",result,op);
		#10;
		
		
		//--------------------------------------------------------------------------------------------------------------------------------
		
		A_invert=1'b0;
		op=2'b10;
		
		A=1'b0;
		B=1'b0;
		
		$display(" \n carry_in = %b , A_invert = %b , B_invert = %b , A = %b , B = %b ,flag1 = %b , flag2 = %b",carry_in,A_invert,B_invert,A,B,flag1,flag2);
		#1;
		$display("---------------------------------------------------------------------------------------------");
		#1
		
		$display("SUBTRACTION result = %b , op = %b \n",result,op);
		#10;
		
		A=1'b0;
		B=1'b1;
		
		$display(" \n carry_in = %b , A_invert = %b , B_invert = %b , A = %b , B = %b ,flag1 = %b , flag2 = %b",carry_in,A_invert,B_invert,A,B,flag1,flag2);
		#1;
		$display("---------------------------------------------------------------------------------------------");
		#1
		
		$display("SUBTRACTION result = %b , op = %b \n",result,op);
		#10;
		
		A=1'b1;
		B=1'b0;
		
		$display(" \n carry_in = %b , A_invert = %b , B_invert = %b , A = %b , B = %b ,flag1 = %b , flag2 = %b",carry_in,A_invert,B_invert,A,B,flag1,flag2);
		#1;
		$display("---------------------------------------------------------------------------------------------");
		#1
		
		$display("SUBTRACTION result = %b , op = %b \n",result,op);
		#10;
		
		A=1'b1;
		B=1'b1;
		
		$display(" \n carry_in = %b , A_invert = %b , B_invert = %b , A = %b , B = %b ,flag1 = %b , flag2 = %b",carry_in,A_invert,B_invert,A,B,flag1,flag2);
		#1;
		$display("---------------------------------------------------------------------------------------------");
		#1
		
		$display("SUBTRACTION result = %b , op = %b \n",result,op);
		
		
	end
	initial #1000 $finish;
endmodule