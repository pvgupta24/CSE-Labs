## Full Adder 
Using the Halfadder module from the previous question, Implement a combinational full adder.

In this question 3 input bits x,y,z are taken and carry,sum are is generated as

sum is the xor of the three inputs x,y,z.

    firstSum = a & b
    firstCarry = a ^ b
    S = firstSum & c
    C = firstSum ^ c

where firstSum and firstCarry are temporary variables

Compile the files from the root folder         
                `iverilog -o a.vvp <verilog code file name.v> <testbenchfilename.v>`

Run the compiled file as                  
                `vvp a.vvp`

Get the simulation wave as
                `gtkwave <dumpfilename.vcd>`
 


