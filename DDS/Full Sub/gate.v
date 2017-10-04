
module sub(diff,borr,in,din);

    output diff,borr;
    input [2:0] in;
    input din;

    wire a,b,c,d,e;
    wire [2:0] in_not;

    //Generates not of input
    not (in_not[0],in[0]),
        (in_not[1],in[1]),
        (in_not[2],in[2]);

    //Temp var
    and (a,din,in_not[2],in_not[1],in[0]),//001
        (b,din,in_not[2],in[1],in_not[0]),//010
        (c,din,in[2],in_not[1],in_not[0]),//100
        (d,din,in[2],in[1],in[0]),        //111
        (e,din,in_not[2],in[1],in[0]);//011
        
    //Final result
    or  (diff,a,b,c,d),
        (borr,a,b,d,e);

endmodule
