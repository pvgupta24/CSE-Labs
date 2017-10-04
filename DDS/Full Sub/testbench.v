`timescale 1ns/100ps
module t_16CO235;
    reg din;
    wire diff,borr;
    reg [2:0] in;    
    sub sub(diff,borr,in,din);
    
    initial 
    begin
        $dumpfile("16CO235-V2.vcd");
        $dumpvars(0,t_16CO235);
        $display("\nABC\tD\tB\t\n-----------------"); 

        din=1;
        in = 3'b000;
        //Generates input 000 to 111
        repeat(7)
            begin
                #10;
                in = in + 1'b1;
            end
            #10;
            
    end

    initial 
        begin 
            //Printing Block
            $monitor("%b\t%b\t%b\t",in,diff,borr);
        end
endmodule
