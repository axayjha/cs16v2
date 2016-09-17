#!/bin/bash

##===========================================================
## Shell script to compile and/or run or interpret source
## codes of some popular programming languages including
##   1. C
##   2. C++
##   3. Java
##   4. Python
##   5. Assembly
##   6. Ruby
##
## Last edited: 08/09/16
## (C) 2016 AkshayJha
## github.com/axayjha

## Under GNU LGPL v3.0 License.
## Free to use, modify and distribute! 
##============================================================


programname="run"
bold=$(tput bold)
normal=$(tput sgr0)

function usage {
    echo -e "${bold}NAME${normal}
        run - script to invoke different compilers, assemblers, 
        interpreters, executables. Can operate on multiple files
        at once. \n"
    echo -e "${bold}SYNOPSIS${normal} 
        run [-options] file ... \n"    
    echo "${bold}DESCRIPTION${normal}
        When you invoke run, it normally does preprocessing, compilation,
        assembly and linking using a GNU compiler (for C/C++/ASM) or the most
        commonly used compilers/interpreters available for linux by default
        for other langauges (Python, Java, Ruby).
        The \"overall options\" allow you to stop this process at an 
        intermediate stage.  For example, the -r option says not
        to run the compiler and just the executable if avaible.
        The output consists of object files output by the assembler.
    "
    echo "${bold}OPTIONS ${normal}"
    echo "        run [${bold}-c${normal}] [@file] ...         compiles files"
    echo "            [${bold}-r${normal}] [@file] ...         runs output files"
    echo "            [${bold}-cr| -rc${normal}] [@file] ...   compiles and runs both"
    echo "            [${bold}-h| --help${normal}]             display help information"
    echo "            [${bold}-v| --version${normal}]          display version"    
    echo "  "
    echo -e "${bold}COPYRIGHT${normal}
        Copyright © 2016 Free Software Foundation, Inc. License GPLv3+: 
        GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.
        This is free software: you are free to change and redistribute it. 
        There is NO WARRANTY, to the extent permitted by law. \n"${bold}
    echo "${bold}AUTHOR${normal}
        Akshay Jha
        For bug reporting please see:
        <http://www.github.com/axayjha>."
    exit 1
}

function version {
  echo "RUN version 1.01"
  echo "Copyright (C) 2016 AkshayJha"
}


function compile {
  ## C
  if [[ "$1" == *.c ]] ;
  then
    echo gcc $1 -lm -o "${1//.c}".out
    gcc $1 -lm -o "${1//.c}".out        
  ## Python3
  elif [[ "$1" == *.py ]];
  then
    echo -e "$programname: No need of compilation of $1. Just use -r option to run.\n"
    continue    
  ## C++
  elif [[ "$1" == *.cpp ]];
  then
    echo g++ $1 -lm -o "${1//.c}".out
    g++ $1 -lm -o "${1//.c}".out
  ## Java
  elif [[ "$1" == *.java ]];
  then
    echo javac $1
    javac $1
  ## ASM
  elif [[ "$1" == *.s ]];
  then
    echo gcc -c $1 -o "${1//.s}".o
    gcc -c $1 -o "${1//.s}".o
  ## Ruby
  elif [[ "$1" == *.rb ]];
  then
    echo -e "$programname: No need of compilation of $1. Just use -r option to run.\n"
    continue    
  else
    echo -e "$programname: file extension not known.\n"
     
  fi

}

function run {
  ## C
  if [[ "$1" == *.c ]];
  then
    echo running "${1//.c}".out
    ./"${1//.c}".out
  ## Python3
  elif [[ "$1" == *.py ]];
  then
    echo running $1
    python3 $1   
  ## C++
  elif [[ "$1" == *.cpp ]];
  then
    echo running "${1//.c}".out
    ./"${1//.c}".out
  ## Java
  elif [[ "$1" == *.java ]];
  then
    echo running "${1//.java}"
    java "${1//.java}"
  ## ASM
  elif [[ "$1" == *.s ]];
  then
    echo running "${1//.s}"
    ./"${1//.s}"
  ## Ruby
  elif [[ "$1" == *.rb ]];
  then
    echo running $1
    ruby $1
  else
    echo -e "$programname: file extension not known \n"    
  fi
}


Compile="fasle"
Run="fasle"

if [[ "$#" == 0 ]]
  then
  usage
fi

case "$1" in 
  -c) Compile="true"; shift ;;
  -r) Run="true"; shift ;;
  -h| --help) usage; exit 1;;
  -v| --version) version; exit 1;;
  -cr| -rc) Compile="true";  Run="true"; shift;;
  -*) echo invalid option;  exit 1 ;;
  *) Compile="true";  Run="true" ;;
esac


for var in "$@"
do
    if [[ "$Compile" == "true" ]] ;
      then
      if ! [[ -f "$var" ]];
      then
         echo -e "$programname: file $var not found! \n"
         continue
      fi
      echo compile $var
      compile $var
      echo "done."
      echo ""
      if [[ "$Run" == "true" ]];
        then
        run $var
        echo ""
      fi
    
    elif [[ "$Compile" == "fasle" ]] && [[ "$Run" == "true" ]];
      then
      if ! [[ -f "$var" ]];
      then
         echo -e "$programname: file $var not found!\n"
         continue
      fi      
      run $var
      echo ""
    else
      exit 1
    fi
done
