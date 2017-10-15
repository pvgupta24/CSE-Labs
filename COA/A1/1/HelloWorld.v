`timescale 1ns/100ps
module hello;

    initial 
    begin
        $dumpfile("hello.vcd");
        $dumpvars(0,hello);
        repeat(100)
           begin
                #10;
                $monitor("%g ns --> Hello There !! ",$time);
           end
        $finish;   
    end

endmodule