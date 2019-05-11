# How to Setup #

## download git repository
git clone --recursive https://github.com/transeos/hackerrank
## or update submodules (inside 'hackerrank' repository)
git submodule update --init --recursive

## build calculator
mkdir build
cd build
cmake ..
make

## Now you'll have hackerrank executable file.
