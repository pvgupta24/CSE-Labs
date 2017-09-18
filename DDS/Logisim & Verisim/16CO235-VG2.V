

module t_16CO235-VD2(res, a, b, cin, cout);
    output [3:0] res, cout;   
    input [3:0] a;
    input [3:0] b;
    input cin;
    wire [3:0] G;
    wire [3:0] P;
    wire[3:0] C;  
    
    assign G = A & (~B);
    assign P = A ^ (~B); 
    assign C[0] = Cin;
    assign C[1] = G[0] | (P[0] & C[0]);
    assign C[2] = G[1] | (P[1] & G[0]) | (P[1] & P[0] & C[0]);
    assign C[3] = G[2] | (P[2] & G[1]) | (P[2] & P[1] & G[0]) | (P[2] & P[1] & P[0] & C[0]);
    assign res = P ^ C;

    assign cout = ~(G[3] | (P[3] & G[2]) | (P[3] & P[2] & G[1]) | (P[3] & P[2] & P[1] & G[0]) |(P[3] & P[2] & P[1] & P[0] & C[0]));


endmodule