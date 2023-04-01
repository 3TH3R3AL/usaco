#!/bin/bash

echo "Created Challenge $1"

cd challenges
mkdir "$1"
cd "$1"
touch "$1.in"
touch "$1.out"
sed -e "s;%CHNAME%;$1;g" ../../notes_template.md> notes.md
sed -e "s;%CHNAME%;$1;g" ../../template.cpp > solution.cpp
nvim notes.md solution.cpp ../../notes.md


