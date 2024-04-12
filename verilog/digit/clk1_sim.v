module ClockGenerator_sim(

    );
    reg clk=0;
    wire sec_clk,ms_1_clk;
    ClockGenerator c(clk,sec_clk,ms_1_clk);
    always 
        #5 clk=~clk;
endmodule

