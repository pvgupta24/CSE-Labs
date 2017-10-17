`timescale 1ns/100ps
module enc();
    reg [15:0]in;
    wire [3:0]out;

    ENC myEnc(in,out,1);
    initial 
    begin
        $dumpfile("enc.vcd");
        $dumpvars(0,enc);
        $display("\t Input\t | ABCD\n-----------------------");     

        in=1;
        repeat(15)
            #10 in=in*2;   
        #10;
        $finish;
    end

    initial
        begin
            $monitor("%b | %b ",in,out);
        end
endmodule