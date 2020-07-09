call config-debug-mingw.bat && call build-static.sh.bat || exit /b
cd ./test/boost || exit /b
call config-debug-mingw.bat && call build-static.sh.bat && call run.sh.bat
cd ../..
