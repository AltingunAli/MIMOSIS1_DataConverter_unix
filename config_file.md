# config_file.cfg
## Configuration parameter list

This file contains all the needed variables for running the software, such as files paths, scan parameters value, etc.<br/>
Changes in __does not need__ the program to be __recompiled__. <br/>
For the documentation the markdown format file is created, but in the DataConverter class the config_file.cfg is loaded. .md and .cfg are not created automatically. If some adds any parameter to .cfg a proper entry in .md should be done. <br/>

The convention is that the names of variables in .cfg are the same as used in classes/structures/etc. <br/>


| Name                | Value (example)        | Info                                   | Description                                                                                       |
|---------------------|------------------------|----------------------------------------|---------------------------------------------------------------------------------------------------|
| _input_data_format  | 3                      | __int__, options: 1, 2                 | Input file data format (1 - RAW, 2 - DEC, 3 - FIRED).                                             |
| _is_uint16_t		  | 0                      | __int__, options: 1	                | NOT DONE; When FIRED format is provided as uint16_t instead of default uint16_t                             |
| _output_data_format | 1                      | __int__                                | IGNORE; prepared for outputs for TAF and ROOT separetly.                                          |
| _nb_of_rows         | 504                    | __int__, arbitrary, > 0                | Number of rows in matrix for global histogram.                                                    |
| _nb_of_columns      | 1024                   | __int__, arbitrary, > 0                | Number of columns in matrix for global histogram.                                                 |
| _nb_of_frames       | 1000                   | __int__, arbitraty, > 0                | Number of frames aquired                                                                        	|
| _row_start          | 0                      | __int__, >=0                           | For plotting part of the matrix. Min pixel in X. Pixels numbered from 0.                          |
| _row_end            | 503                    | __int__, >= 0 && <= (_nb_of_rows-1)    | For plotting part of the matrix. Max pixel in X.                                                  |
| _column_start       | 0                      | __int__, >=0                           | For plotting part of the matrix. Min pixel in X. Pixels numbered from 0.                          |
| _column_end         | 1023                   | __int__, >= 0 && <= (_nb_of_columns-1) | For plotting part of the matrix. Max pixel in Y.                                                  |
| _is_noise           | 0                      | __int__, 1                             | If 1, output file has no parameter values in the name but only _noise + _out_prefix.              |
| _in_file_path       | ./inputData            | __std::string__                        | Path to directory with input .bin files.                                                          |
| _in_file_name       | name.bin 			   | __std::string__, *.bin                 | Name of input binary file.                                                                        |
| _out_tree_file_path | ./outputData           | __TString__                            | Path to output directory where the .root trees are saved.                                         |
| _out_tree_file_name | mimosis1               | __TString__                            | Name of the output file (TFile).                                                                  |
| _out_prefix         | _1                     | __TString__                            | User may add arbitrary postfix to output name file.                                               |
| _out_tree_name      | mimosis1_raw_tree      | __TString__                            | Name of the output tree (TTree).                                                                  |
| _param_1            | VBB                    | __std::string__                        | Name of first scan parameter. Added in total output file name. Corresponds to back bias voltage.  |
| _param_2            | VPH                    | __std::string__                        | Name of first scan parameter. Added in total output file name. Corresponds to pulse high voltage. |
| _param_3            | VTH                    | __std::string__                        | Name of first scan parameter. Added in total output file name. Corresponds to threshold voltage.  |
| _param_1_value      | 0                      | __int__                                | Value of the _param_1. Added in the output file name.                                             |
| _param_2_value      | 0                      | __int__                                | Value of the _param_2. Added in the output file name.                                             |
| _param_3_value      | 0                      | __int__                                | Value of the _param_3. Added in the output file name.     






