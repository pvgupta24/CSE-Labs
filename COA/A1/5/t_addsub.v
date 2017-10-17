/*
------------------------------------------------------
            Praveen Kumar Gupta  -  16CO235
            Durvesh Bhalekar     -  16CO210
------------------------------------------------------
Testbench for n-bit Adder/Subtractor using Full Adders
------------------------------------------------------

*/
`timescale 1ns/100ps
module adderSubtractor();
    parameter n=4;  
    wire [n:0]C;
    wire[n-1:0] S;
    reg[n-1:0] A,B;
    reg cin;
    //reg CD;
    
    addSub myAddSub  (S,C,A,B,cin);

    initial 
    begin
        $dumpfile("addsub.vcd");
        $dumpvars(0,adderSubtractor);
        $display("Cin   A  | B | C  S/D\n---------------------");     

        A=4'b0010;
        B=4'b0110;

        cin=1'b1;//0->add, 1->sub
        repeat(4)
            #10 A=A+1'b1;   
        cin=1'b0;
        A=4'b0110;
        B=4'b1000;
        repeat(4)
            #10 A=A+1'b1;
        #10;
        $finish;
    end

    initial
        begin
            $monitor(" %b |%b|%b| %b %b",cin,A,B,C[n],S);
        end
endmodule