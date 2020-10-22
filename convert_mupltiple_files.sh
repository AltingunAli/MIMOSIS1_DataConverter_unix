#!/bin/bash

iterator=0

for run in 13
do
	iterator=0

	for backbias in 0
	do 
		for pulseHeight in {0..245..5}
		do

			for vthreshold in 67
			do
			
			rm 		config_file.cfg
			touch 	config_file.cfg
		
			echo "_run:		${run}" >> config_file.cfg
		
			echo "_input_data_format:		3" >> config_file.cfg	
			echo "_output_data_format:		1" >> config_file.cfg
		
			echo "" >> config_file.cfg
		
			echo "_nb_of_rows: 				504" 	>> config_file.cfg
			echo "_nb_of_columns:			1024" 	>> config_file.cfg
			echo "_nb_of_frames:			520" 	>> config_file.cfg
			echo "_row_start:				0" 	>> config_file.cfg
			echo "_row_end:					98" 	>> config_file.cfg
			echo "_column_start:			0" 		>> config_file.cfg
			echo "_column_end:				127" 	>> config_file.cfg
		
			echo "" >> config_file.cfg
		
			echo "_is_noise:				0" 		>> config_file.cfg
			
			echo "" >> config_file.cfg
		
			echo "_in_file_path:			./inputData/run_${run}/data" 	>> config_file.cfg
		
			echo "" >> config_file.cfg
		
			echo "_in_file_name:			run_${run}_${iterator}_step.bin" 	>> config_file.cfg
		
			echo "" >> config_file.cfg
				
			echo "_out_tree_file_path:		./outputData/20_10_2020" 		>> config_file.cfg
		
			echo "" >> config_file.cfg
			
			echo "_out_tree_file_name:		mimosis1" 						>> config_file.cfg
			
			echo "" >> config_file.cfg
						
			echo "_out_prefix:				_noPLL" 							>> config_file.cfg
					
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
	  
			mv ./outputData/20_10_2020/*.pdf ./outputData/20_10_2020/png
			
			iterator=`expr $iterator + 1`

			done
		done
	done
done
