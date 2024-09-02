`timescale 1 ns/100 ps
// Version: 2024.1 2024.1.0.3


module IO_C0_IO_C0_0_IO(
       PAD_BI,
       D,
       E,
       Y
    );
inout  [15:0] PAD_BI;
input  [15:0] D;
input  [15:0] E;
output [15:0] Y;

    
    BIBUF #( .IOSTD("LVCMOS25") )  U0_5 (.PAD(PAD_BI[5]), .D(D[5]), .E(
        E[5]), .Y(Y[5]));
    BIBUF #( .IOSTD("LVCMOS25") )  U0_11 (.PAD(PAD_BI[11]), .D(D[11]), 
        .E(E[11]), .Y(Y[11]));
    BIBUF #( .IOSTD("LVCMOS25") )  U0_7 (.PAD(PAD_BI[7]), .D(D[7]), .E(
        E[7]), .Y(Y[7]));
    BIBUF #( .IOSTD("LVCMOS25") )  U0_13 (.PAD(PAD_BI[13]), .D(D[13]), 
        .E(E[13]), .Y(Y[13]));
    BIBUF #( .IOSTD("LVCMOS25") )  U0_10 (.PAD(PAD_BI[10]), .D(D[10]), 
        .E(E[10]), .Y(Y[10]));
    BIBUF #( .IOSTD("LVCMOS25") )  U0_2 (.PAD(PAD_BI[2]), .D(D[2]), .E(
        E[2]), .Y(Y[2]));
    BIBUF #( .IOSTD("LVCMOS25") )  U0_12 (.PAD(PAD_BI[12]), .D(D[12]), 
        .E(E[12]), .Y(Y[12]));
    BIBUF #( .IOSTD("LVCMOS25") )  U0_9 (.PAD(PAD_BI[9]), .D(D[9]), .E(
        E[9]), .Y(Y[9]));
    BIBUF #( .IOSTD("LVCMOS25") )  U0_1 (.PAD(PAD_BI[1]), .D(D[1]), .E(
        E[1]), .Y(Y[1]));
    BIBUF #( .IOSTD("LVCMOS25") )  U0_8 (.PAD(PAD_BI[8]), .D(D[8]), .E(
        E[8]), .Y(Y[8]));
    BIBUF #( .IOSTD("LVCMOS25") )  U0_3 (.PAD(PAD_BI[3]), .D(D[3]), .E(
        E[3]), .Y(Y[3]));
    BIBUF #( .IOSTD("LVCMOS25") )  U0_15 (.PAD(PAD_BI[15]), .D(D[15]), 
        .E(E[15]), .Y(Y[15]));
    BIBUF #( .IOSTD("LVCMOS25") )  U0_4 (.PAD(PAD_BI[4]), .D(D[4]), .E(
        E[4]), .Y(Y[4]));
    BIBUF #( .IOSTD("LVCMOS25") )  U0_14 (.PAD(PAD_BI[14]), .D(D[14]), 
        .E(E[14]), .Y(Y[14]));
    BIBUF #( .IOSTD("LVCMOS25") )  U0_0 (.PAD(PAD_BI[0]), .D(D[0]), .E(
        E[0]), .Y(Y[0]));
    BIBUF #( .IOSTD("LVCMOS25") )  U0_6 (.PAD(PAD_BI[6]), .D(D[6]), .E(
        E[6]), .Y(Y[6]));
    
endmodule
