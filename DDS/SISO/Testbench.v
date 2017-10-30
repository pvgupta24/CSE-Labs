`timescale 1ns/100ps

module t_16CO235V5;
reg reset,preset,clear,clk,ip;
wire op,t1,t2,t3;

SISO zaraZaraShiftMeShiftMeShiftMe(preset,reset,clk,ip,op,t1,t2,t3);

initial
    begin
        $dumpfile("16CO235-V5.vcd");
        $dumpvars(0,t_16CO235V5);
        $display("Shift Register");
        $display("Time\tIn      Temp\tOut\n===========================");
        clk=1'b0;
    end

initial
    forever
       #5 clk=~clk;

initial
    begin//fork
        #0;
        reset=1'b1;
        preset=1'b0;
        ip=1'b0;
        //op=1'b0;
        #2;
        reset=1'b0;
        /*
        #12;
        ip=1;
        #17;
        ip=0;
        #27;
        ip=1;*/

        repeat(25)
            begin
              #10 ip = $random % 2;
            end
        $finish;
    end//join
initial
    //$monitor("%gns\t%b\t%b%b%b\t%b",$time,ip,t1,t2,t3,op);
    #1 repeat(100)
        #5 $display("%gns\t%b\t%b%b%b\t%b",$time,ip,t1,t2,t3,op);

endmodule
