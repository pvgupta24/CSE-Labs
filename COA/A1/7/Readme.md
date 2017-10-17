## Single bit Sequential Memory Element. 

To implement a 1 bit sequential memory cell (a D-Flip Flop),

d and clk are the two inputs & q is given out as two output.

q=d at positive edge of clk

the Dflipflop is active at the positive edge of the clock cycle.

Compile the files from the root folder         
                `iverilog -o a.vvp <verilog code file name.v> <testbenchfilename.v>`

Run the compiled file as                  
                `vvp a.vvp`

Get the simulation wave as
                `gtkwave <dumpfilename.vcd>`