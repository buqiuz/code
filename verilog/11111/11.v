`timescale 1ns / 1ps

module Elevator(
clk, rst,Floor_call_state,current_floor,Floor_call_state_output,stop
    );
      	input             clk;
        input              rst;
        input 	 [4:0]   Floor_call_state;        
        output reg [4:0]   current_floor;
        output reg [4:0]   Floor_call_state_output; 
        output reg stop;
        
        integer k;
        reg [30:0] cnt=30'b0;
        parameter M=100000000;             
        reg clk_out=0;
        
        initial begin
             stop=1;
             Floor_call_state_output=5'b00001;
             current_floor=5'b00001;
        end
        
       
        always @(posedge clk)                
            begin
                if(rst)
                    begin
                        clk_out=0;
                    end
               
                if (cnt==M-1)                   
                    begin
                        clk_out=~clk_out;
                        cnt=0;
                    end
                else 
                    begin
                        clk_out=0;             
                        cnt=cnt+1'd1;
                    end
            end
            
 
       always @(*)    
            begin
                 if(rst)
                     begin
                         Floor_call_state_output=5'b00001;
                     end
                 else
                     begin
                         Floor_call_state_output=Floor_call_state;
                     end
            end
              
        
       always @(posedge clk_out or posedge rst)
           begin
               if(rst)
                   begin
                       stop=1;
                       current_floor=5'b00001;
                   end
               else if(Floor_call_state_output!=5'b00000)
                   begin
                       stop=0;
                       if(current_floor<Floor_call_state_output)               
                           current_floor={current_floor[3:0],current_floor[4]};
                       else if(current_floor>Floor_call_state_output)         
                           current_floor={current_floor[0],current_floor[4:1]};
                       else
                           stop=1;
                   end
               else
                   begin
                       stop=1;
                   end
           end
           
endmodule
