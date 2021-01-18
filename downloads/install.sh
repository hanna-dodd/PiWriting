#!/bin/bash
#install stuff

sudo apt-get install libssl-dev

sudo apt remove --purge --auto-remove cmake

sudo wget https://github.com/Kitware/CMake/releases/download/v3.19.1/cmake-3.19.1.tar.gz

sudo tar -zxvf cmake-3.19.1.tar.gz

cd cmake-3.19.1

sudo ./bootstrap

sudo make

sudo make install

cd ../

sudo wget https://dl.bintray.com/boostorg/release/1.73.0/source/boost_1_73_0.tar.bz2

sudo tar --bzip2 -xf boost_1_73_0.tar.bz2

cd boost_1_73_0

sudo ./bootstrap.sh

sudo ./b2 install

cd ../

sudo git clone https://github.com/karastojko/mailio

cd mailio

cd src

sudo rm message.cpp

cd ../

cd include

cd mailio

sudo rm message.hpp

cd ../
 
cd ../

cd ../

sudo mv message.cpp /usr/local/bin/mailio/src

sudo mv message.hpp /usr/local/bin/mailio/include/mailio

cd mailio

sudo mkdir build

cd build

sudo cmake ..

sudo make install

sudo ldconfig

cd ../../

sudo apt-get install tesseract-ocr
sudo apt install libtesseract-dev

sudo apt-get install espeak

sudo apt-get install qt5-default

