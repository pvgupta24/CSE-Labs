#!/bin/bash

# If command line arg is empty
if [ -z $1 ]; then
    echo "Usage $0 <filename to run>"
else
    g++ $1 -lGL -lGLU -lglut -lm && ./a.out
fi