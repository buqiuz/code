module digit (
    input clk,
    output wire[7:0] segs
    
);  
    reg [3:0]an=4'b1111;
    reg [3:0]digit=4'b0000;
    wire [6:0] seg;
    wire en;
    reg[15:0] s=16'b1000_0100_0010_0001;
    reg [16:0] count=17'b0000_0000_0000_0000_0;
    wire reset;
    reg [20:0]  counter=0;

  
    hexseg_0 h(digit,an,en,seg);
    assign segs={seg,1'b0};

    always @(posedge ms_4_clk,posedge reset) begin
        if (reset) begin
            count=0;    
        end else begin
            count=count+1;
        end

    end

    always @(posedge clk) begin
        case (count[1:0])
            0: begin
                an=4'b1110;
                digit=s[3:0];
            end
            1: begin
                an=4'b1101;
                digit=s[7:4];
            end
            2: begin
                an=4'b1011;
                digit=s[11:8];
            end
            3: begin
                an=4'b0111;
                digit=s[15:12];
            end

            default: begin
                an=4'b1111;
                digit=4'b0000;
            end
        endcase
    end
endmodule









