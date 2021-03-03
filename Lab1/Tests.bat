@echo off

REM way for the test program is going by first arg of cmd
SET MyProgram="%~1"

REM Defent of start without argument
if %MyProgram%=="" (
	echo Please specify file path to the program
)

REM Copy empty file
%MyProgram% Empty.txt "%TEMP%\output.txt" || goto err
fc Empty.txt "%TEMP%\output.txt" || goto err
echo Test 1 passed

REM Copy non empty file
%MyProgram% NonEmpty.txt "%TEMP%\output.txt" || goto err
fc NonEmpty.txt "%TEMP%\output.txt" || goto err
echo Test 2 passed

REM Copy missing file should fail
%MyProgram% MissingFile.txt "%TEMP%\output.txt" && goto err
fc NonEmpty.txt "%TEMP%\output.txt" || goto err
echo Test 3 passed

REM If output file is not specified, program must fail
%MyProgram% MissingFile.txt && goto err
echo Test 4 passed

REM If input and output file are not specified, program must fail 
%MyProgram% && goto err
echo Test 5 passed

REM Tests are successful
echo All tests passed successfuly
exit /B 0

REM We are there in case of error
:err
echo Test failed
exit /B 1