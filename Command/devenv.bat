@echo off

REM 设置 Visual Studio 安装路径
set "VS_PATH=C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\"

REM 设置要修改的路径
set "NEW_DEV_ENV=C:\Qt\Qt5.9.3\5.9.3\msvc2015_64\bin;D:\Dev\ht5\install\3rdpartyX64_VS15\bin;D:\Dev\ht5\install\FxGISSDK\bin;;D:\Dev\ht5\install\osg\bin;D:\Dev\ht5\install\osgearth\bin"

REM 设置新的环境变量 DEV_ENV
setx  DEV_ENV "%NEW_DEV_ENV%" -m

REM 检查是否已经包含要添加的路径
echo %PATH% | findstr /c:"%DEV_ENV%" >nul 2>&1
if %errorlevel% equ 0 (
  echo Path already exists in PATH variable.
) else (
  REM 获取当前的 PATH 环境变量值，并将新路径追加到末尾
  setx  PATH "%PATH%;%%DEV_ENV%%" -m
  echo %%DEV_ENV%% added to PATH variable.
)



REM 启动 Visual Studio 解决方案
start "" "%VS_PATH%\devenv.exe" "D:\Dev\ht5\Build\buildSSS\SpaceSimSystem.sln"

timeout /t -1

