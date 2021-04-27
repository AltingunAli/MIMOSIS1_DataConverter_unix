#!/bin/bash

	iterator=0
	i=0;

	for backbias in 2000
	do 
		for vthreshold in {120..130..10}
		do 
			run=26035
			run=`expr $i + $run`
			
			for pulseHeight in {0..195..5}
			do		
			
			echo "run: ${run}"
			
			mkdir -p ./outputData/run_${run}
			
			rm 	config_file.cfg
			touch 	config_file.cfg
		
			echo "_run:			${run}" 		>> config_file.cfg
			echo "_chipNo:		23" 		>> config_file.cfg

			echo "_input_data_format:		3" >> config_file.cfg	
			echo "_output_data_format:		1" >> config_file.cfg
		
			echo "" >> config_file.cfg
		
			echo "_nb_of_rows: 			504" 	>> config_file.cfg
			echo "_nb_of_columns:		1024" 	>> config_file.cfg
			echo "_nb_of_frames:		500" 	>> config_file.cfg
			echo "_row_start:			0"	>> config_file.cfg
			echo "_row_end:				503" 	>> config_file.cfg
			echo "_column_start:		0" 	>> config_file.cfg
			echo "_column_end:			127"	>> config_file.cfg

			echo "" >> config_file.cfg
		
			echo "_is_noise:				0" 		>> config_file.cfg
			
			echo "" >> config_file.cfg
		
			echo "_in_file_path:			./inputData/run_${run}/data" 	>> config_file.cfg
		
			echo "" >> config_file.cfg
		
			echo "_in_file_name:			run_${run}_${iterator}_step.bin" 	>> config_file.cfg
		
			echo "" >> config_file.cfg
				
			echo "_out_tree_file_path:		./outputData/run_${run}" 		>> config_file.cfg
		
			echo "" >> config_file.cfg
			
			echo "_out_tree_file_name:		mimosis1" 						>> config_file.cfg
			
			echo "" >> config_file.cfg
						
			echo "_out_prefix:				_noPLL" 						>> config_file.cfg
					
			echo "" >> config_file.cfg
						
			echo "_out_tree_name:			mimosis1_raw_tree" 				>> config_file.cfg
				
			echo "" >> config_file.cfg	
					
			echo "_param_1:					VBB" 							>> config_file.cfg
			echo "_param_2:					VPH_fine" 						>> config_file.cfg
			echo "_param_3:					VTH" 							>> config_file.cfg

			echo "" >> config_file.cfg
		
			echo "_param_1_value:			${backbias}"					>> config_file.cfg
			echo "_param_2_value:		    ${pulseHeight}"					>> config_file.cfg
			echo "_param_3_value:			${vthreshold}"					>> config_file.cfg
	  
			./mimosis1reader
	  
			#mv ./outputData/26_10_2020/*.pdf ./outputData/26_10_2020/png
			
			iterator=`expr $iterator + 1`

			done
			
			iterator=0
			i=`expr $i + 1`

		done
	done
#done
