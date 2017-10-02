module lcSub (res, cout, a, b, cin);
	//Output var
	output [3:0] res;
	output cout;
	//Declaring output as reg for assigning values in always.
	reg [3:0] res;
	reg cout;	
	//Input var by default wire
	input [3:0] a,b;
	input cin;	
	//Temp var
	reg [3:0] gen,pro,B,lc;

	//Run Block if any "input" in changed
	always @ (a or b or cin) 
	begin	
			lc[0] = cin;
			//b' or b based on cin
			B = cin ? ~b : b;
			//Assigning generate and propogate 			
			gen = a & B;
			pro = a ^ B;			
			// look ahead carry
			lc[1] = ( gen[0] | (pro[0] & lc[0]) );
			lc[2] = ( gen[1] | (pro[1] & gen[0]) | (pro[1] & pro[0] & lc[0]) );
			lc[3] = ( gen[2] | (pro[2] & gen[1]) | (pro[2] & pro[1] & gen[0]) | (pro[2] & pro[1] & pro[0] & lc[0]) );			
			// adder or subtractor
			res = pro ^ lc;			
			// last carry 
			cout = ( gen[3] | (pro[3] & gen[2]) | (pro[3] & pro[2] & gen[1]) |
			(pro[3] & pro[2] & pro[1] & gen[0]) |(pro[3] & pro[2] & pro[1] & pro[0] & lc[0]) );

			cout = cout ^ cin;
    end
    
endmodule



