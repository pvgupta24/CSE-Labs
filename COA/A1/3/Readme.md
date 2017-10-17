## Half Adder 
Implement a combinational half adder (HA)

Two input bits x, y are taken and and sum and carry outputs are generated as

> sum=x(xor)y
> carry=x.y

Compile the files from the root folder         
                `iverilog -o a.vvp <verilog code file name.v> <testbenchfilename.v>`

Run the compiled file as                  
                `vvp a.vvp`

Get the simulation wave as
                `gtkwave <dumpfilename.vcd>`