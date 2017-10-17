## Encoders and Decoders
Implement a combinational 4-to-16 decoder and a 16-to-4 encoder.

### 4 x 16 Decoder
4 input variables are taken and assigned to [15:0]out vector of 1 bit each by using nor, and gates.

### 16 x 4 encoder
[15:0]inp is taken and encode to 4 output variables if Enable pin is 1

Compile the files from the root folder         
                `iverilog -o a.vvp <verilog code file name.v> <testbenchfilename.v>`

Run the compiled file as                  
                `vvp a.vvp`

Get the simulation wave as
                `gtkwave <dumpfilename.vcd>`