#!/bin/bash
#Sean Brace
#Builds a c++ program and runs it. If the program reads from a file, this script should run the program using all input files, output each
# execution to a new output file (input file = 01.dat, output file = 01.out), then use diff on the example output file provided.


declare -i outputFiles
# echo "$#"
# echo "$1"
(( outputFiles = 1 ))
if [[ $# == 2 ]]; then
   # build='g++ -Wall $1 $2 -o zelt'
   build="g++ -Wall $1 $2 -o zelt"
else
   # build='g++ -Wall $1 -o zelt'
   build="g++ -Wall $1 -o zelt"
fi

inputFiles=(`find ./ -maxdepth 1 -name "*.dat"`)
if [[ ${#inputFiles[@]} -gt 0 ]]; then
   if [[ -f differences.out ]]; then
      rm differences.out
   fi
   if ${build}; then
      echo " * Compilation succeeded."
      for files in "$inputFiles[@]"; do
         if [[ $outputFiles -ge 10 ]]; then
            ./zelt ${inputFiles[@]} > "${outputFiles}.out"
            diff sample${outputFiles}.out ${outputFiles}.out >> differences.out
         else
            ./zelt ${inputFiles[@]} > "0${outputFiles}.out"
            diff sample${outputFiles}.out "0${outputFiles}.out" >> differences.out
         fi
         (( outputFiles++ ))
      done
      cat differences.out
   else
      echo " * Compilation failed."
   fi
fi
   