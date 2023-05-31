#!/bin/bash

while read -r run	chip	matrix	hv	backbias	vcasn2	vclip	vpl	vph	input	stepsize	nbstep	vcasnLSB	vcasnMV

do

	iterator=0

	echo "Analysing run: $run";

	maxrange=$((${stepsize}*${nbstep}-${stepsize}))
	
	mkdir -p ./outputData/run_${run}

	for (( pulseHeight=0; pulseHeight<=$maxrange; pulseHeight=pulseHeight+$stepsize ))
	#for pulseHeight in {0..$maxrange..$stepsize}}
		do
			
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
		
			echo "_in_file_path:			../inputData/run_${run}/data" 	>> config_file.cfg
			
			echo "" >> config_file.cfg
			echo "${pulseHeight} --- ${iterator}"
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
			echo "_param_3_value:			${vcasnLSB}"					>> config_file.cfg
	  
			./mimosis1reader
	  			
			iterator=$((${iterator}+1))
			echo "iterator: ${iterator}"
		done
	
	

done < $1
