## n-bit adder/subtractor

Cin is given as 0 for Add and 1 for Subtract.

n bit inputs A,b are given. If cin is 1, b's bits are inverted

n Full Adders are used in series where Carry from one stage is used as input in next FA.

Carry of Final FA is taken as the Final Carry

Compile the files from the root folder         
                `iverilog -o a.vvp <verilog code file name.v> <testbenchfilename.v>`

Run the compiled file as                  
                `vvp a.vvp`

Get the simulation wave as
                `gtkwave <dumpfilename.vcd>`
