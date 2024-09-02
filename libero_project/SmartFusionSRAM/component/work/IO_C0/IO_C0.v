//////////////////////////////////////////////////////////////////////
// Created by SmartDesign Mon Sep  2 17:04:46 2024
// Version: 2024.1 2024.1.0.3
//////////////////////////////////////////////////////////////////////

`timescale 1ns / 100ps

//////////////////////////////////////////////////////////////////////
// Component Description (Tcl) 
//////////////////////////////////////////////////////////////////////
/*
# Exporting Component Description of IO_C0 to TCL
# Family: SmartFusion2
# Part Number: M2S005-TQ144
# Create and Configure the core component IO_C0
create_and_configure_core -core_vlnv {Actel:SgCore:IO:1.0.101} -component_name {IO_C0} -params {\
"DIFF_IOSTD_OK:false"  \
"IO_TYPE:BIBUF"  \
"IOSTD:LVCMOS25"  \
"SINGLE_IOSTD_OK:true"  \
"VARIATION:SINGLE"  \
"WIDTH:16"   }
# Exporting Component Description of IO_C0 to TCL done
*/

// IO_C0
module IO_C0(
    // Inputs
    D,
    E,
    // Outputs
    Y,
    // Inouts
    PAD_BI
);

//--------------------------------------------------------------------
// Input
//--------------------------------------------------------------------
input  [15:0] D;
input  [15:0] E;
//--------------------------------------------------------------------
// Output
//--------------------------------------------------------------------
output [15:0] Y;
//--------------------------------------------------------------------
// Inout
//--------------------------------------------------------------------
inout  [15:0] PAD_BI;
//--------------------------------------------------------------------
// Nets
//--------------------------------------------------------------------
wire   [15:0] D;
wire   [15:0] E;
wire   [15:0] PAD_BI;
wire   [15:0] Y_net_0;
wire   [15:0] Y_net_1;
//--------------------------------------------------------------------
// TiedOff Nets
//--------------------------------------------------------------------
wire   [15:0] PAD_IN_const_net_0;
wire   [15:0] PADP_IN_const_net_0;
wire   [15:0] PADP_BI_const_net_0;
wire   [15:0] PADN_IN_const_net_0;
wire   [15:0] PADN_BI_const_net_0;
//--------------------------------------------------------------------
// Constant assignments
//--------------------------------------------------------------------
assign PAD_IN_const_net_0  = 16'h0000;
assign PADP_IN_const_net_0 = 16'h0000;
assign PADP_BI_const_net_0 = 16'h0000;
assign PADN_IN_const_net_0 = 16'h0000;
assign PADN_BI_const_net_0 = 16'h0000;
//--------------------------------------------------------------------
// Top level output port assignments
//--------------------------------------------------------------------
assign Y_net_1 = Y_net_0;
assign Y[15:0] = Y_net_1;
//--------------------------------------------------------------------
// Component instances
//--------------------------------------------------------------------
//--------IO_C0_IO_C0_0_IO   -   Actel:SgCore:IO:1.0.101
IO_C0_IO_C0_0_IO IO_C0_0(
        // Inputs
        .D      ( D ),
        .E      ( E ),
        // Outputs
        .Y      ( Y_net_0 ),
        // Inouts
        .PAD_BI ( PAD_BI ) 
        );


endmodule
