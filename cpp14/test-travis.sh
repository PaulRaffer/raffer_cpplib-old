sh config-debug-travis.sh && sh build-static.sh.bat || exit
cd ./test/boost || exit
sh config-debug-travis.sh && sh build-static.sh.bat && sh run.sh.bat
cd ../..
