## Register

32 bit inp and out variables along with clk is given.
The register stores 32 bits till positive edge of clock cycle where a loop is used to set the output bits same as input bits.

Compile the files from the root folder         
                `iverilog -o a.vvp <verilog code file name.v> <testbenchfilename.v>`

Run the compiled file as                  
                `vvp a.vvp`

Get the simulation wave as
                `gtkwave <dumpfilename.vcd>`