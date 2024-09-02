set_device -family {SmartFusion2} -die {M2S005} -speed {STD}
read_verilog -mode system_verilog {C:\Users\Clara\STM32CubeIDE\workspace_1.16.0\nascerr\libero_project\SmartFusionSRAM\component\work\SFSRAM_sb\CCC_0\SFSRAM_sb_CCC_0_FCCC.v}
read_verilog -mode system_verilog {C:\Users\Clara\STM32CubeIDE\workspace_1.16.0\nascerr\libero_project\SmartFusionSRAM\component\work\SFSRAM_sb\FABOSC_0\SFSRAM_sb_FABOSC_0_OSC.v}
read_verilog -mode system_verilog {C:\Users\Clara\STM32CubeIDE\workspace_1.16.0\nascerr\libero_project\SmartFusionSRAM\component\work\SFSRAM_sb_MSS\SFSRAM_sb_MSS.v}
read_verilog -mode system_verilog {C:\Users\Clara\STM32CubeIDE\workspace_1.16.0\nascerr\libero_project\SmartFusionSRAM\component\Actel\DirectCore\CoreResetP\7.1.100\rtl\vlog\core\coreresetp_pcie_hotreset.v}
read_verilog -mode system_verilog {C:\Users\Clara\STM32CubeIDE\workspace_1.16.0\nascerr\libero_project\SmartFusionSRAM\component\Actel\DirectCore\CoreResetP\7.1.100\rtl\vlog\core\coreresetp.v}
read_verilog -mode system_verilog {C:\Users\Clara\STM32CubeIDE\workspace_1.16.0\nascerr\libero_project\SmartFusionSRAM\component\work\SFSRAM_sb\SFSRAM_sb.v}
read_verilog -mode system_verilog {C:\Users\Clara\STM32CubeIDE\workspace_1.16.0\nascerr\libero_project\SmartFusionSRAM\component\work\SFSRAM\SFSRAM.v}
set_top_level {SFSRAM}
map_netlist
check_constraints {C:\Users\Clara\STM32CubeIDE\workspace_1.16.0\nascerr\libero_project\SmartFusionSRAM\constraint\synthesis_sdc_errors.log}
write_fdc {C:\Users\Clara\STM32CubeIDE\workspace_1.16.0\nascerr\libero_project\SmartFusionSRAM\designer\SFSRAM\synthesis.fdc}
