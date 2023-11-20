#!/bin/bash

if [ -n "$1" ] && [ -n "$2" ]; then
	rm -r ./build
fi

# generate the build folder if it does not exists
if [ ! -d "./build" ]; then 
	mkdir build
fi

cd build

# passing line arguments to cmake
if [ -n "$1" ] && [ -n "$2" ]; then
	cmake .. -DTARGET=$1 -DPATH=$2
else
	cmake .. -DTARGET="main" -DPATH="."
fi


make

# check result of make
if [ $? -eq 0 ]; then
	./project_med
else
	echo "Build failed..."
fi

cd ..

if [ -n "$1" ] && [ -n "$2" ]; then
	rm -r ./build
fi