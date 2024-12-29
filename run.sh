#/bin/bash


set -e
cd build
cmake ../
make
./8051emu