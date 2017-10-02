module lcSub (res, cout, a, b, cin);
	// output var
	output [3:0] res;
	output cout;
	
	// input var
	input [3:0] a;
	input [3:0] b;
	input cin;
	
	// temp var
	wire [3:0] gen, pro, lc,B;
	wire temp [17:0];
	wire tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8, tmp9, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17;
	
	
	// fill generate and propogate
	buf (lc[0], cin); 
	
	xor (B[0], cin, b[0]),
		(B[1], cin, b[1]),
		(B[2], cin, b[2]),
		(B[3], cin, b[3]);

	and (gen[0], a[0], B[0]),
		(gen[1], a[1], B[1]),
		(gen[2], a[2], B[2]),
		(gen[3], a[3], B[3]);

	xor (pro[0], a[0], B[0]),
		(pro[1], a[1], B[1]),
		(pro[2], a[2], B[2]),
		(pro[3], a[3], B[3]);
	
	// look ahead carry
	and (tmp1, pro[0], lc[0]);
	or (lc[1], gen[0], tmp1);
	
	and (tmp3, pro[1], tmp1);
	and (tmp4, pro[1], gen[0]);
	or (tmp5, tmp3, tmp4);
	or (lc[2], gen[1], tmp5);
	
	and (tmp6, pro[2], tmp3);
	and (tmp7, pro[2], tmp4);
	and (tmp8, pro[2], gen[1]);
	or (tmp9, tmp7, tmp6);
	or (tmp10, tmp8, tmp9);
	or (lc[3], gen[2], tmp10);
    
    // adder
   xor  (res[0], pro[0], lc[0]),
		(res[1], pro[1], lc[1]),
		(res[2], pro[2], lc[2]),
		(res[3], pro[3], lc[3]);
    
    // last carry 
    and (tmp11, pro[3], tmp1);
	and (tmp12, pro[3], tmp7);
	and (tmp13, pro[3], tmp8);
	and (tmp14, pro[3], gen[2]);
	or (tmp15, tmp12, tmp11);
	or (tmp16, tmp14, tmp13);
	or (tmp17, tmp15, tmp16);
	or (cout, gen[3], tmp17);
    
    
    //assign cout = gen[3] | (pro[3] & gen[2]) | (pro[3] & pro[2] & gen[1]) | (pro[3] & pro[2] & pro[1] & gen[0]) |(pro[3] & pro[2] & pro[1] & pro[0] & lc[0]);
    
endmodule
