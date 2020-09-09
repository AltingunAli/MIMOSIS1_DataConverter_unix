#!/bin/bash


for backbias in 0
do 
	for pulseHeight in {106..130..1}
	do

		for vthreshold in 0
		do
	
	rm config_file.txt
	touch config_file.txt

	echo "file_path:		./inputData" >> config_file.txt
	echo "file_name:		row_matrix_VCASN_98_VPULSEHIGH_${pulseHeight}_0.bin_0.bin" >> config_file.txt
	echo "_tree_file_path:	./outputData" 	>> config_file.txt
	echo "_tree_file_name:	mimosis0_matrix_raw_VBB_${backbias}_VPH_${pulseHeight}_VTH_${vthreshold}" 	>> config_file.txt
	echo "_tree_name:		mimosis0_raw_tree" >> config_file.txt


  ./mimosis0reader
  
		done
	done
done
