#!/bin/bash

# generate the build folder if it does not exists
if [ ! -d "./build" ]; then 
	mkdir build
fi

cd build

make

# check result of make
if [ $? -eq 0 ]; then
	./project_mid
else
	echo "Build failed..."
fi