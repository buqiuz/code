module digital(
  input clk,
  input rstn,
  input [3:0]data0,
  input [3:0]data1,
  input [3:0]data2,
  input [3:0]data3,
  input [3:0]data4,
  input [3:0]data5,
  output reg[7:0]seg,
  output reg[3:0]sel,
  output reg[2:0]hours1,
  output reg[2:0]hours2
);
reg[15:0]cnl;
reg clk1k;
always@(posedge clk or negedge rstn)
  begin
    if(!rstn)
    begin
      cnl<=0;
      clk1k<=0;
    end
    else if(cnl>=24999)
    begin
      clk1k<=!clk1k;
      cnl<=0;
    end
    else cnl<=cnl+1;
  end
reg [3:0]tub;
reg [2:0]state;
always@(posedge clk1k or negedge rstn)
  begin
    if(!rstn)
    begin
      tub<=0;
      state<=0;
      sel<=0;
      hours1<=0;
      hours2<=0;
    end
    else
    begin
      case(state)
        0:begin hours1<=data0;sel<=4'b1111;state<=1;end
        1:begin hours2<=data1;sel<=4'b1111;state<=2;end
        2:begin tub<=data2;sel<=4'b0111;state<=3;end
        3:begin tub<=data3;sel<=4'b1011;state<=4;end
        4:begin tub<=data4;sel<=4'b1101;state<=5;end
        5:begin tub<=data5;sel<=4'b1110;state<=0;end
        default:state<=0;
      endcase
    end
  end
always@(*)
  if(!rstn)
    seg<=8'b1100_0000;
  else
    case(tub)
      0:seg<=8'b1100_0000;
      1:seg<=8'b1111_1001;
      2:seg<=8'b1010_0100;
      3:seg<=8'b1011_0000;
      4:seg<=8'b1001_1001;
      5:seg<=8'b1001_0010;
      6:seg<=8'b1000_0010;
      7:seg<=8'b1111_1000;
      8:seg<=8'b1000_0000;
      9:seg<=8'b1001_0000;
      default:seg<=8'b1100_0000;
    endcase
endmodule