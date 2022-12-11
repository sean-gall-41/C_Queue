#!/usr/bin/bash

c_flags="-Wall -pedantic -ggdb"

g++ $c_flags -o queue queue.cpp # && ./queue
