export QUARTUS_ROOTDIR=/home/kif/intelFPGA/18.0/quartus

$QUARTUS_ROOTDIR/sopc_builder/bin/qsys-generate sopc_top.qsys --output-directory=sopc_top -syn 
$QUARTUS_ROOTDIR/../nios2eds/nios2_command_shell.sh nios2-bsp-generate-files --settings=software/stest_bsp/settings.bsp --bsp-dir=software/stest_bsp
cd software/stest/
$QUARTUS_ROOTDIR/../nios2eds/nios2_command_shell.sh make mem_init_generate 
cd ..
cd ..
$QUARTUS_ROOTDIR/bin/quartus_sh --flow compile  C10_BAIKAL
$QUARTUS_ROOTDIR/bin/quartus_cpf -c output_file.cof

