module lcSub (res, cout, a, b, cin);
	//Output var
	output [3:0] res;
	output cout;
	
	//Input var
	input [3:0] a, b;
	input cin;

	// temp var
	wire [3:0] gen, pro, lc,B;
	//b' or b based on cin
	assign B = cin ? ~b : b;
	// Assign generate and propogate 
	assign lc[0] = cin;
	assign gen = a & B;
	assign pro = a ^ B;
	
	// look ahead carry
    assign lc[1] = ( gen[0] | (pro[0] & lc[0]) );
    assign lc[2] = ( gen[1] | (pro[1] & gen[0]) | (pro[1] & pro[0] & lc[0]) );
    assign lc[3] = ( gen[2] | (pro[2] & gen[1]) | (pro[2] & pro[1] & gen[0]) |
	(pro[2] & pro[1] & pro[0] & lc[0]) );
    
    // Sum/Difference
    assign res = pro ^ lc;
    
    // Last carry 
    assign cout = ( gen[3] | (pro[3] & gen[2]) | (pro[3] & pro[2] & gen[1]) |
	(pro[3] & pro[2] & pro[1] & gen[0]) |(pro[3] & pro[2] & pro[1] & pro[0] & lc[0]) );
    
endmodule
