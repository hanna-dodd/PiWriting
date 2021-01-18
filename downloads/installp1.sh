#!/bin/bash
#install stuff

sudo mv install.sh /usr/local/bin
sudo mv message.cpp /usr/local/bin
sudo mv message.hpp /usr/local/bin

cd /usr/local/bin

sudo bash install.sh
