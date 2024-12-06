@echo off

if not exist build mkdir build

pushd build

cl ../main.cpp

popd build