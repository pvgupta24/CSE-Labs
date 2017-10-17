## BASIC INTERCONNECTION NETWORK 

Implement a 2 node point to point interconnection network. 
Implement two versions of the system.

### Version 1:

Both X and Y send messages to each other,periodically.
The recieved message along with the timestamp is printed by each of them at the output.

There are two modules: X and Y with 
* 4 bit input register 'in' 
* 4 bit output register 'out'.
* 'clock' is taken as input and is complemented every 5ns

The module runs for 200ns.
In the testbench, we pass the output of module X as the input to module Y and vice versa.
A random 4 bit number generator is used to generate messages sent by X and Y to each other.
The messages recieved along with the timestamp is displayed.

### Version 2:

X sends one message to Y at random intervals of time. Y  send  4 replies.
X prints sent and received messages at the output.
There are two  two modules: X and Y with 
* 4 bit input register 'in' 
* 4 bit output register 'out'.
* 'clock' is taken as input and is complemented every 5ns.

The module runs for  1000ns.
In th testbench we pass output of module X as input to module Y.
Whenever module  gets an input, it responds with four 4 bit outputs. This is achieved by random number generator.
The messages recieved along with the timestamp is displayed.

In module X, display function is used to display the message sent from X to Y, and the four responses of B along with the timestamp.

Compile the files from the root folder         
                `iverilog -o a.vvp <verilog code file name.v>`

Run the compiled file as                  
                `vvp a.vvp`

Get the simulation wave as
                `gtkwave <dumpfilename.vcd>`