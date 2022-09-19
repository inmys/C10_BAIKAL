rem set PATH=C:\intelFPGA\18.0\quartus\bin64\;%PATH%
%QUARTUS_ROOTDIR%\sopc_builder\bin\qsys-generate sopc_top.qsys --output-directory=sopc_top -syn
CALL %QUARTUS_ROOTDIR%\..\nios2eds\"Nios II Command Shell.bat" nios2-bsp-generate-files --settings=software/stest_bsp/settings.bsp --bsp-dir=software/stest_bsp
cd software\stest\ 
CALL %QUARTUS_ROOTDIR%\..\nios2eds\"Nios II Command Shell.bat" make mem_init_generate
cd ..
cd ..
%QUARTUS_ROOTDIR%\bin64\quartus_sh.exe --flow compile  C10_BAIKAL
%QUARTUS_ROOTDIR%\bin64\quartus_cpf -c output_file.cof



