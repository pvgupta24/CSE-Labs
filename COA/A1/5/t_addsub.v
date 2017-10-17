
`timescale 1ns/100ps
module adderSubtractor();
    parameter n=4;  
    wire C;
    wire[n-1:0] S;
    reg[n-1:0] A,B;
    reg cin;

    addSub myAddSub(S,C,A,B,cin);

    initial 
    begin
        $dumpfile("addsub.vcd");
        $dumpvars(0,adderSubtractor);
        $display(" A  | B  | C  S\n-----------------");     

        A=4'b0110;
        B=4'b0110;

        cin=1'b1;//0->add, 1->sub
        repeat(8)
            #10 A=A+1'b1;   
        #10;
        $finish;
    end

    initial
        begin
            $monitor("%b|%b| %b %b",A,B,C,S);
        end
endmodule