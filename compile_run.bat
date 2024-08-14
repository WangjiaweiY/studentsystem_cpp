@echo off
REM 切换到包含cpp文件夹的目录
cd /d "C:\Users\86187\Desktop\CPPworkspace\studentsystem"

REM 运行g++编译命令
g++ cpp\*.cpp -o studentsystem.exe -Llib -lmysql -Iinclude -fexec-charset=GBK

REM 检查编译是否成功
if %ERRORLEVEL% NEQ 0 (
    echo Compilation failed
    exit /b %ERRORLEVEL%
)

REM 编译成功，启动一个新的命令行窗口运行studentsystem.exe
start cmd /k .\studentsystem.exe