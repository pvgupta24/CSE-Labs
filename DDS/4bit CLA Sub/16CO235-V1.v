`timescale 1ns/100ps

module t_16CO235V1;

	wire [3:0] res;
	wire cout;
	
	reg [3:0] a,b;
	reg cin;
	
	lcSub inst (res, cout, a, b, cin);	
	initial begin 		
		$dumpfile("16CO235-V1.vcd");
		$dumpvars(0, t_16CO235V1);

		// 1 for subtract , 0 for add
		cin = 1;

		// Custom inputs with 10ns delay
		a = 4'b1000; 
		b = 4'b0101;
		#10;
		a = 4'b1111; 
		b = 4'b0001;
		#10;
		a = 4'b1011; 
		b = 4'b1001;
		#10;
		a = 4'b1111; 
		b = 4'b1000;
		#10;
		a = 4'b0011; 
		b = 4'b100;
		#10;
		a = 4'b1011; 
		b = 4'b0001;
		#10;
		a = 4'b0101; 
		b = 4'b1011;
		#10;
		a = 4'b1011; 
		b = 4'b0011;
		#10;
		a = 4'b1111; 
		b = 4'b1111;
		#10;
		
		$finish;
	end		
	
	initial begin
		 $monitor("t=%3t: a = %b, b = %b, cout = %d, res = %b \n",$time,a, b,  cout, res);
	end

endmodule
