# How to run 

## General desciption 
__MIMOSIS1_DataConverter__

The software is dedicated for converting the data file .bin from MIMOSIS1 DAQ to ROOT Tree format (.root). Using ROOT TTree the data might be loaded into __MIMOSIS1_Lab_Analyser__ to plot S-Curves and performe basic noise analysis. 

For that moment (07.09.2020) the software is working with __FIRED DAQ__ data type, so the data format containing 2-DIM array with multiplicity of fired pixels per N frames. This format is futher called __integrated frame__ .

## GitHub
Repository can be cloned from:

__https://github.com/RomaBugiel/MIMOSIS1_DataConverter_unix.git__

## Software
* C++14, ROOT 

### Needed packages 
The software was tested on:

* ROOT 6.22/00 
* Unix: Ubuntu 20 (there is also Windows version but without documentation. This one can be used since the naming and functionality is the same)
* Doxygen: 1.8.17
* g++: 9.3.0 

## Compilation and run

### Software
> __make__ <br/>
> ./mimosis1reader

#### Configuration file

For configuration parameters list on HTLM documentation please go: Releated Pages --> config_file.cfg

#### Output
> In general the path for saving the root trees is provided via config_file.cfg.
> If not changed, one can find the outputs in: ./outputData

### Documentation

> * in main directory run: __make docs__ 
> 	* for Latex go to /doc/latex: __make__ and open __refman.pdf__
> 	* for HTLM: go to /doc/html and open __index.html__

## Scirpits

__NOT FINISHED__

The bash script __convert_multiple_files.sh__ is provided for running data conversion of serveral files. 
The bash script is generating only config_file.cfg which is loaded in runtime, so after changing configuration file no complitation is needed. 

There are three analysis parameters for which script is able to run automatic conversion (simply execute program for multiple files). These analysis parameters are: VPULSE, VTHRESHOLD and VBACKBIAS. One can also use script for running only one file. In such a case only one number (without {}) should be placed in for-loops inside bashscript. 
