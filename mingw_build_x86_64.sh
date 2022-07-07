#!/usr/bin/env sh
###
 # @Author: zhengminyan@tetras.ai
 # @Date: 2022-07-07 15:52:29
### 
if [ ! -d "./build/" ];then
    mkdir ./build
fi

if [ ! -d "./release/" ];then
    mkdir ./release
fi


cd build
echo "-- remove built files --"
rm -rf *

echo "-- start cmake"
cmake .. -G "MinGW Makefiles" -DCMAKE_SH="CMAKE_SH-NOTFOUND" -DCMAKE_BUILD_TYPE=Release
echo "-- end cmake"

echo "-- start make"
mingw32-make -j8 
echo "-- end make"
