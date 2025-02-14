@echo off
setlocal

:: 设置编译器路径（如果需要）
:: set PATH=C:\MinGW\bin;%PATH%

:: 设置输出文件名
set OUTPUT_FILE=leetcode_random_picker.exe

:: 设置源文件列表
set SOURCE_FILES=main.cpp question_database.cpp utils.cpp

:: 设置编译选项
set INCLUDE_PATH=-I.
set COMPILE_FLAGS=-std=c++17 -O2

:: 编译项目
g++ %SOURCE_FILES% -o %OUTPUT_FILE% %INCLUDE_PATH% %COMPILE_FLAGS%

endlocal
pause