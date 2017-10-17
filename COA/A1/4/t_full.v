`timescale 1ns/100ps
module full();
    wire S,C;
    reg[2:0] inp;
    FA myAdder(S,C,inp[2],inp[1],inp[0]);
    initial 
    begin
        $dumpfile("full.vcd");
        $dumpvars(0,full);
        $display("A B C | C S\n-----------");     

        inp=3'b000;
        repeat(8)
            #10 inp=inp+1'b1;   
        #10;
        $finish;
    end

    initial
        begin
            $monitor("%b %b %b | %b %b",inp[2],inp[1],inp[0],C,S);
        end
endmodule