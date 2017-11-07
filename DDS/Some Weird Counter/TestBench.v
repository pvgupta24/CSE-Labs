/*==================================================================
    Author - Praveen Kumar Gupta
             16CO235

    Title  - Some Random Counter
==================================================================*/
//Timnescale declaration
`timescale 1ns/100ps

//==================================================================

module t_16CO235V();
reg p1,r1,p2,r2,p3,r3,clk;
wire a,b,c,anot,bnot,cnot;
//==================================================================

//Instantiate counter module
counter WeirdCounter(p1,r1,p2,r2,p3,r3,clk,a,b,c,anot,bnot,cnot);
//==================================================================

initial
    begin
        $dumpfile("16CO235-V.vcd");
        $dumpvars(0,t_16CO235V);
        $display("Weird Counter");
        $display("Time\tA\tB\tC\n=========================");
    end

//==================================================================
// Clock Cycles
initial
    forever
       #5 clk=~clk;
//==================================================================

// Custom inout i.e Set ABC to 001 initially then start counting
initial
    begin
        #0;
        clk=1'b0;
        r1=1;
        p1=0;
        r2=1;
        p2=0;
        r3=0;
        p3=1;

        #5;
        r1=0;
        r2=0;
        p3=0;

        #100;       
        $finish;
    end
//==================================================================

initial
    $monitor("%gns\t%b\t%b\t%b",$time,a,b,c);

endmodule
//==================================================================
