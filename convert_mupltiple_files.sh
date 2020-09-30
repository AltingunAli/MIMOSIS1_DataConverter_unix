#!/bin/bash

iterator=0

for backbias in 0
do 
	for pulseHeight in {0..150..10}
	do

		for vthreshold in 70
		do
	
	rm 		config_file.cfg
	touch 	config_file.cfg

	echo "_input_data_format:		3" >> config_file.cfg	
	echo "_output_data_format:		1" >> config_file.cfg

	echo "" >> config_file.cfg

	echo "_nb_of_rows: 				504" 	>> config_file.cfg
	echo "_nb_of_columns:			1024" 	>> config_file.cfg
	echo "_nb_of_frames:			1000" 	>> config_file.cfg
	echo "_row_start:				10" 	>> config_file.cfg
	echo "_row_end:					10" 	>> config_file.cfg
	echo "_column_start:			0" 		>> config_file.cfg
	echo "_column_end:				126" 	>> config_file.cfg

	echo "" >> config_file.cfg

	echo "_is_noise:				0" 		>> config_file.cfg
	
	echo "" >> config_file.cfg

	echo "_in_file_path:			./inputData/29_09_2020/data" 	>> config_file.cfg

	echo "" >> config_file.cfg

	echo "_in_file_name:			run_0_${iterator}_cum.bin" 	>> config_file.cfg

	echo "" >> config_file.cfg
		
	echo "_out_tree_file_path:		./outputData/29_09_2020" 		>> config_file.cfg

	echo "" >> config_file.cfg
		
	echo "_out_tree_file_name:		mimosis1" 						>> config_file.cfg
	
	echo "" >> config_file.cfg
				
	echo "_out_prefix:				noPLL" 							>> config_file.cfg
			
	echo "" >> config_file.cfg
				
	echo "_out_tree_name:			mimosis1_raw_tree" 				>> config_file.cfg
		
	echo "" >> config_file.cfg	
			
	echo "_param_1:					VBB" 							>> config_file.cfg
	echo "_param_2:					VPH" 							>> config_file.cfg
	echo "_param_3:					VTH" 							>> config_file.cfg

	echo "" >> config_file.cfg

	echo "_param_1_value:			${backbias}"					>> config_file.cfg
	echo "_param_2_value:		    ${pulseHeight}"					>> config_file.cfg
	echo "_param_3_value:			${vthreshold}"					>> config_file.cfg
  
  ./mimosis1reader
  
  iterator=`expr $iterator + 1`

		done
	done
done
