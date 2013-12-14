#!/bin/bash
# Tested on pandoc == 1.12.2.1 
filename=stan-reference.tex
pandoc  -f latex -t html -o ${filename%%.tex}.html -s --mathjax $filename
