#!/bin/bash

	iterator=0
	i=0;
	
	run=44390
	chip=44
	matrix='B'
	
	backbias=1000
	#vthreshold=145

	#for run in {44319..44320..1}

	for vthreshold in {98..98..3}
	do 	

		run=`expr $i + $run`
		
		echo ""
		echo "--> RUN is: $run" 
		echo ""

		for pulseHeight in {0..245..5}
		do
			echo "run: ${run}"
			
			case ${matrix} in
				A)
				column_start=0
				column_end=127
				echo "--> matrix A analysed from ${column_start} to ${column_end}"
				;;
				B)
				column_start=128
				column_end=511
				echo "--> matrix B analysed from ${column_start} to ${column_end}"
				;;
				C)
				column_start=512
				column_end=895
				echo "--> matrix C analysed from ${column_start} to ${column_end}"
				;;
				D)
				column_start=896
				column_end=1023
				echo "--> matrix D analysed from ${column_start} to ${column_end}"
				;;
				*)
				column_start=0
				column_end=127
				echo "--> WRONG MATRIX INDEX PROVIDED, specify A, B, C or D. Default taken for column ranges: ${column_start} to ${column_end}"
				;;
			esac


			mkdir -p ./outputData/run_${run}
			
			rm 	config_file.cfg
			touch 	config_file.cfg
		
			echo "_run:			${run}" 		>> config_file.cfg
			echo "_chipNo:		${chip}" 		>> config_file.cfg

			echo "_input_data_format:		3" >> config_file.cfg	
			echo "_output_data_format:		1" >> config_file.cfg
		
			echo "" >> config_file.cfg
		
			echo "_nb_of_rows: 			504" 	>> config_file.cfg
			echo "_nb_of_columns:		1024" 	>> config_file.cfg
			echo "_nb_of_frames:		500" 	>> config_file.cfg
			echo "_row_start:			0"	>> config_file.cfg
			echo "_row_end:				503" 	>> config_file.cfg
			echo "_column_start:		${column_start}" 	>> config_file.cfg
			echo "_column_end:		${column_end}"	>> config_file.cfg

			echo "" >> config_file.cfg
		
			echo "_is_noise:				0" 		>> config_file.cfg
			
			echo "" >> config_file.cfg
		
			#echo "_in_file_path:			/iphc-work/cmos100/data/DATA_Laboratory/Mimosis_1/Chip21_bis/run_${run}/data" 	>> config_file.cfg
			echo "_in_file_path:			/iphc-work/cmos100/data/DATA_Laboratory/Mimosis_1/Chip${chip}/run_${run}/data" 	>> config_file.cfg
			#echo "_in_file_path:			./inputData/run_${run}/data" 	>> config_file.cfg
			
			echo "" >> config_file.cfg
		
			echo "_in_file_name:			run_${run}_${iterator}_step.bin" 	>> config_file.cfg
		
			echo "" >> config_file.cfg
				
			echo "_out_tree_file_path:		./outputData/run_${run}" 		>> config_file.cfg
		
			echo "" >> config_file.cfg
			
			echo "_out_tree_file_name:		mimosis1" 						>> config_file.cfg
			
			echo "" >> config_file.cfg
						
			echo "_out_prefix:			_noPLL" 						>> config_file.cfg
					
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
		i=1
		#i=`expr $i + 1`

	done

