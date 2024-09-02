set_component SFSRAM_sb_FABOSC_0_OSC
# Microchip Technology Inc.
# Date: 2024-Sep-02 17:36:18
#

create_clock -ignore_errors -period 20 [ get_pins { I_RCOSC_25_50MHZ/CLKOUT } ]
