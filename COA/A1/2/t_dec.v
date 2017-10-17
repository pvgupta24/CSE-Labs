/*
------------------------------------------------------
            Praveen Kumar Gupta  -  16CO235
            Durvesh Bhalekar     -  16CO210
------------------------------------------------------
              Testbench for 4 x 16 Decoder
------------------------------------------------------

*/

`timescale 1ns/100ps
module dec();
    wire [15:0]out;
    reg [3:0]inp;
    DEC myDec(inp[3],inp[2],inp[1],inp[0],out);
    initial 
    begin
        $dumpfile("dec.vcd");
        $dumpvars(0,dec);
        $display("A B C D |\tOutput\n-------------------------");     

        inp=4'b0000;
        repeat(15)
            #10 inp=inp+1'b1;   
        #10;
        $finish;
    end

    initial
        begin
            $monitor("%b %b %b %b| %b ",inp[3],inp[2],inp[1],inp[0],out);
        end
endmodule