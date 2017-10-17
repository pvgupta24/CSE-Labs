/*
------------------------------------------------------
            Praveen Kumar Gupta  -  16CO235
            Durvesh Bhalekar     -  16CO210
------------------------------------------------------
                Testbench for Half Adder
------------------------------------------------------

*/
`timescale 1ns/100ps
module half();
    wire S,C;
    reg a,b;
    ha myAdder(S,C,a,b);
    initial 
    begin
        $dumpfile("half.vcd");
        $dumpvars(0,half);
        $display("A B | S C\n---------");        
        
        a=1'b0;
        b=1'b0;

        #10;
        a=1'b0;
        b=1'b1;

        #10;
        a=1'b1;
        b=1'b0;

        #10;
        a=1'b1;
        b=1'b1;
        #10;
        $finish;
    end

    initial
        begin
            $monitor("%b %b | %b %b",a,b,S,C);
        end
endmodule