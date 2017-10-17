`timescale 1ns/100ps

module hello();
    reg clk;    
    PRINT print(clk);
    initial 
    begin
        $dumpfile("hello.vcd");
        $dumpvars(0,hello);
        clk=1'b0;
        repeat(100)
            #10 clk=~clk;
           /*begin
                #10;
                $monitor("%g ns --> Hello There !! ",$time);
           end*/
        $finish;   
    end

endmodule