module add32_4(
    input [31:0] a, //输入两个操作数
    input [31:0] b, 
    input rst, //归零
    input clk, //时钟
    input stop, //停止
    input cin, //进位标志
    output wire cout, //溢出标志
    output wire [31:0] sum //和
    );
    
    reg cout1,cout2,cout3,cout4; //存储溢出位
    //存储对应每级累加后的结果
    reg [7:0] sum1;
    reg [15:0] sum2;
    reg [23:0] sum3;
    reg [31:0] sum4;
    //存储每次加8位后剩余的数据
    reg [23:0] temp_a1,temp_b1;
    reg [15:0] temp_a2,temp_b2;
    reg [7:0] temp_a3,temp_b3;
    
    //第一级
    always@(posedge clk)
    begin
        if(rst)
        begin
            cout1<=0;
            sum1<=0;
            temp_a1<=0;
            temp_b1<=0;
        end
        else if(stop)
        begin
            cout1<=cout1;
            sum1<=sum1;
            temp_a1<=temp_a1;
            temp_b1<=temp_b1;
        end
        else
        begin
            {cout1,sum1} = {1'b0,a[7:0]} + {1'b0,b[7:0]} + {7'b0000_000,cin};
            temp_a1<=a[31:8];
            temp_b1<=b[31:8];
        end
    end
    
    //第二级
    always@(posedge clk)
    begin
        if(rst)
        begin
            cout2<=0;
            sum2<=0;
            temp_a2<=0;
            temp_b2<=0;
        end
        else if(stop)
        begin
            cout2<=cout2;
            sum2<=sum2;
            temp_a2<=temp_a2;
            temp_b2<=temp_b2;
        end
        else
        begin
            {cout2,sum2[15:7]} = {1'b0,temp_a1[7:0]} + {1'b0,temp_b1[7:0]} + {7'b0000_000,cout1};
            sum2[7:0]<=sum1;
            temp_a2<=temp_a1[23:8];
            temp_b2<=temp_b1[23:8];
        end
    end
    
    //第三级
    always@(posedge clk)
    begin
        if(rst)
        begin
            cout3<=0;
            sum3<=0;
            temp_a3<=0;
            temp_b3<=0;
        end
        else if(stop)
        begin
            cout3<=cout3;
            sum3<=sum3;
            temp_a3<=temp_a3;
            temp_b3<=temp_b3;
        end
        else
        begin
            {cout3,sum3[23:16]} = {1'b0,temp_a2[7:0]} + {1'b0,temp_b2[7:0]} + {7'b0000_000,cout2};
            sum3[15:0]<=sum2;
            temp_a3<=temp_a2[15:8];
            temp_b3<=temp_b2[15:8];
        end
    end
    
    //第四级
    always@(posedge clk)
    begin
        if(rst)
        begin
            cout4<=0;
            sum4<=0;
        end
        else if(stop)
        begin
            cout4<=cout4;
            sum4<=sum4;
        end
        else
        begin
            {cout4,sum4[31:24]} = {1'b0,temp_a3[7:0]} + {1'b0,temp_b3[7:0]} + {7'b0000_000,cout3};
            sum4[23:0]<=sum3;
        end
    end     
    
    assign sum=sum4;
    assign cout=cout4;
    
endmodule
