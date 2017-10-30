`timescale 1ns/100ps

module t_16CO235;

    reg clk,X,p1,r1,p2,r2;
    //inout d1,d2;
    wire q1,q2,y;
    
    seq solve(X,clk,p1,p2,r1,r2,q1,q2,y);
    initial     
    begin
        $dumpfile("16CO235-V4.vcd");
        $dumpvars(0,t_16CO235);
        $display("A(t+1)  B(t+1)  X\tY(t)");
        $display("===========================");
        clk=1'b0;
        p1=1'b1;
        p2=1'b1;
        
        r1=1'b0;
        r2=1'b0;        
        clk=~clk;
        #2;
        p1=~p1;
        p2=~p2;      
        X=1'b1;  
        clk=~clk;
        #10;
        repeat(30)
            #3 clk = ~clk;
    end
    initial
    begin
      repeat(10)
      #10 X=~X;
    end
    initial 
        begin 
            $monitor("%b\t%b\t%b\t%b",q1,q2,X,y);
        end
endmodule