module ha( S,C, a,b);    
    output reg S,C;
    input wire a,b;
    always @ (a or b)
        begin
            S=a^b;
            C=a&b;
        end
endmodule