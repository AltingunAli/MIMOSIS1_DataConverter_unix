/*! @file DataConverter.cpp
 *  @brief The source file for DataConverter.h.
 */



#include "DataConverter.h"

//-------------------------------------------------------------------------------------------------

std::ostream &operator<<(std::ostream &os, const DataConverter &dataconverter) 
{
	os << std::setw(30) << " Data Converter is run with: " 	<< std::endl;
	os << std::setw(30) << "_run: " 					<< dataconverter._run					<< std::endl;
	os << std::setw(30) << "_in_file_path: " 			<< dataconverter._in_file_path			<< std::endl;
	os << std::setw(30) << "_in_file_name: " 			<< dataconverter._in_file_name			<< std::endl;
	os << std::setw(30) << "_out_tree_file_path: " 		<< dataconverter._out_tree_file_path	<< std::endl;
	os << std::setw(30) << "_out_tree_file_name: " 		<< dataconverter._out_tree_file_name	<< std::endl;
	os << std::setw(30) << "_out_prefix: " 				<< dataconverter._out_prefix 			<< std::endl;
	os << std::setw(30) << "_out_name: " 				<< dataconverter._out_name 				<< std::endl;
	os << std::setw(30) << "_out_tree_name: " 			<< dataconverter._out_tree_name 		<< std::endl;
	os << std::setw(30) << "_is_noise: " 				<< dataconverter._is_noise 				<< std::endl;
	os << std::setw(30) << "_param_1: "  				<< dataconverter._param_1 				<< std::endl;
	os << std::setw(30) << "_param_2: " 				<< dataconverter._param_2				<< std::endl;
	os << std::setw(30) << "_param_3: " 				<< dataconverter._param_3				<< std::endl;
	os << std::setw(30) << "_param_1_value: "			<< dataconverter._param_1_value			<< std::endl;
	os << std::setw(30) << "_param_2_value: "			<< dataconverter._param_2_value			<< std::endl;
	os << std::setw(30) << "_param_3_value: "			<< dataconverter._param_3_value			<< std::endl;
	os << std::setw(30) << "_input_data_format: " 		<< dataconverter._input_data_format 	<< std::endl;
	os << std::setw(30) << "_is_uint16_t: " 			<< dataconverter._is_uint16_t		 	<< std::endl;
	os << std::setw(30) << "_output_data_format: " 		<< dataconverter._output_data_format 	<< std::endl;
	os << std::setw(30) << "_nb_of_rows: " 				<< dataconverter._nb_of_rows 			<< std::endl;
	os << std::setw(30) << "_nb_of_columns: " 			<< dataconverter._nb_of_columns 		<< std::endl;
	os << std::setw(30) << "_row_start : " 				<< dataconverter._row_start				<< std::endl;
	os << std::setw(30) << "_row_end : "  				<< dataconverter._row_end				<< std::endl;
	os << std::setw(30) << "_column_start : "    		<< dataconverter._column_start     		<< std::endl;
	os << std::setw(30) << "_column_end : "    			<< dataconverter._column_end     		<< std::endl;							
	return os;                          
}

//-------------------------------------------------------------------------------------------------

void DataConverter::init()
{
	MSG(DEB, "init() --> starts" );

	
	
	if(config.ReadFile("config_file.cfg", kEnvUser) < 0)
	{ 	
			MSG(ERR, "Could not read configuration file in DataConverter - exit")
			exit(0);
	}
	
	_run				=	config.GetValue("_run",999999);
	_chipNo				=	config.GetValue("_chipNo",0);

	_in_file_path		=	config.GetValue("_in_file_path","");
	_in_file_name		=	config.GetValue("_in_file_name","");
	_out_tree_file_path	= 	config.GetValue("_out_tree_file_path","");
	_out_tree_file_name	=	config.GetValue("_out_tree_file_name","test_tree");
	_out_prefix			=	config.GetValue("_out_prefix","");

	_out_tree_name		=	config.GetValue("_out_tree_name","tree_fired_mimosis1");
	
	_is_noise		= 	config.GetValue("_is_noise", 1);
	
	_param_1 		=	config.GetValue("_param_1", "");
	_param_2 		=   config.GetValue("_param_2", "");
	_param_3 		=   config.GetValue("_param_3", "");
	                    
	_param_1_value	=   config.GetValue("_param_1_value", 0);
	_param_2_value	=   config.GetValue("_param_2_value", 0);
	_param_3_value	=   config.GetValue("_param_3_value", 0);

	_input_data_format	= config.GetValue("_input_data_format", 3);
	_is_uint16_t		= config.GetValue("_is_uint16_t", 0);
	_output_data_format	= config.GetValue("_output_data_format", 1);
	
	_nb_of_rows 	= 	config.GetValue("_nb_of_rows", 0);
	_nb_of_columns	= 	config.GetValue("_nb_of_columns", 0);
	_nb_of_frames	=	config.GetValue("_nb_of_frames", -1);
	_row_start		=	config.GetValue("_row_start", 0);
	_row_end		=	config.GetValue("_row_end", 0);
	_column_start	=	config.GetValue("_column_start", 0);
	_column_end		=	config.GetValue("_column_end", 0);
	
	_param = 	_param_1 + "_" + std::to_string(_param_1_value) + "_" + 
				_param_2 + "_" + std::to_string(_param_2_value) + "_" + 
				_param_3 + "_" + std::to_string(_param_3_value);
				
	MSG(CNTR, "The _params are: " + _param);


	//Setting the output tree name
	if(_is_noise)
	{
		_out_name = _out_tree_file_path + "/" +
					_out_tree_file_name + "_" +
					"_run" + std::to_string(_run) + "_" +
					"NOISE" +
					_out_prefix ;						
	}
	else 
	{ 
		_out_name = _out_tree_file_path + "/" +
					_out_tree_file_name + "_" + 
					"run" + std::to_string(_run) + "_" +
					_param + 
					_out_prefix ;
	}
}

// -------------------------------------------------------------------------------------------------

void DataConverter::open_tree() 
{	

	MSG(DEB, "open_tree() --> starts " );
	const int nb_of_bins_x  {(_column_end-_column_start)+1};
	const int nb_of_bins_y  {(_row_end-_row_start)+1};
					
	//Create output file
	_output_data_file = TFile::Open( _out_name + ".root","RECREATE");
	
	if (!_output_data_file) 
	{ 	
		MSG(ERR, "Could not open output ROOT tree - exit")
		exit(0); 
	}
	else
	{ 
		MSG(INFO, "ROOT tree location and name: " 	<< _out_name + ".root");
		MSG(INFO, "Tree name: " 					<< _out_tree_name )
	
		// Create a TTree
		_output_data_file->cd();
		_mimosis_tree = new TTree(_out_tree_name, _out_tree_name);

		TString histo_name;
		if(_is_noise) 	histo_name = "noise";
		else 			histo_name = _param;
	
		MSG(CNTR, "The core to histo name is: " + histo_name);

	
		//Add TTree members  
		h2_integrated_frame_matrix = new TH2D("h2_integrated_frame_matrix", 
		"Integrated frame (N=" + (TString)std::to_string(_nb_of_frames)+ ") for: " + histo_name + " - entire matrix; colum; row", _nb_of_columns, 0, _nb_of_columns, _nb_of_rows, 0, _nb_of_rows); 
		
		h2_integrated_frame_part = new TH2D("h2_integrated_frame_part", "Integrated frame (N=" + (TString)std::to_string(_nb_of_frames)+ ") for: " + histo_name + "; column ; row", nb_of_bins_x, _column_start, _column_end+1, nb_of_bins_y, _row_start, _row_end+1);
		
		h2_pixels_fired_over_nbframes = new TH2D("h2_pixels_fired_over_nbframes", "Pixels fired over number of frames (N=" + (TString)std::to_string(_nb_of_frames)+ ") for: " + histo_name + "; column ; row", _nb_of_columns, 0, _nb_of_columns, _nb_of_rows, 0, _nb_of_rows);

		h_hitrate = new TH1D("h_hitrate","Hit rate -- integrated over " + (TString)std::to_string(_nb_of_frames) + " frames;hit rate; #", 2*_nb_of_frames+1, 0, 2*_nb_of_frames);
		  
		h_hitrate_matA = new TH1D("h_hitrate_matA","Hit rate -- integrated over " + (TString)std::to_string(_nb_of_frames) + " frames;hit rate; #", 2*_nb_of_frames+1, 0, 2*_nb_of_frames);
		h_hitrate_matB = new TH1D("h_hitrate_matB","Hit rate -- integrated over " + (TString)std::to_string(_nb_of_frames) + " frames;hit rate; #", 2*_nb_of_frames+1, 0, 2*_nb_of_frames);

	}
	
}

// -------------------------------------------------------------------------------------------------

void DataConverter::close_tree() 
{	
	MSG(DEB, "close_tree() --> starts" );

	_output_data_file  ->  Write(); 
	_output_data_file  ->  Close();
	
}

// -------------------------------------------------------------------------------------------------

int DataConverter::get_file_size() 
{
	MSG(DEB, "get_file_size() --> starts" );
	
	in_file.seekg (0, in_file.end);
    int length = in_file.tellg();
    in_file.seekg (0, in_file.beg);
    
    return length;
}

// -------------------------------------------------------------------------------------------------

std::string DataConverter::print_hex(std::string s, bool upper_case) 
{
	MSG(DEB, "print_hex() --> starts" );

	std::ostringstream ret;
	int z {0};
	
	//String::size_type i -- 8 bits
	for (std::string::size_type i = 0; i < s.length(); ++i)
    {
        z = s[i]&0xff;
        ret << std::hex << std::setfill('0') << std::setw(2) << (upper_case ? std::uppercase : std::nouppercase) << z << " ";
	}

    return ret.str();
}

// -------------------------------------------------------------------------------------------------


void DataConverter::open_file() 
{
	//Open file

	in_file.open(_in_file_path+"/"+_in_file_name, std::ios::out | std::ios::in | std::ios::binary); 

	in_file.seekg(0, std::ios::beg);
	_input_file_size = get_file_size();
	
	if(!in_file.is_open()) 	
	{ 	
		MSG(ERR, "There is no input file:" << _in_file_path+"/"+_in_file_name << " -- exit");
		exit(0);
	}
	else { 
		MSG(INFO, "Input file loaded: " << _in_file_path <<"/"<< _in_file_name );
		MSG(INFO, "Input file length: " << _input_file_size );
	}

}

// -------------------------------------------------------------------------------------------------
void DataConverter::fill_tree(int input_data_format){
	
	switch(input_data_format) 
	{
		case 1: { fill_tree_raw(); 		break; }
		case 2: { fill_tree_dec(); 		break; }
		case 3: { fill_tree_fired(); 	break; }
		default: {	
					MSG(WARN, "Input data format not provided. Fired-DAQ format will be launched." );
					fill_tree_fired(); break; 
				 } 
	}
}
// -------------------------------------------------------------------------------------------------

void DataConverter::fill_tree_raw()
{
	MSG(INFO, "Input data format: RAW-DAQ." );
}

// -------------------------------------------------------------------------------------------------

void DataConverter::fill_tree_dec()
{
	MSG(INFO, "Input data format: DEC-DAQ." );
}

// -------------------------------------------------------------------------------------------------
void DataConverter::fill_tree_fired()
{
	MSG(INFO, "Input data format: fired-DAQ format." );
	std::cout << sizeof(int) << std::endl;

	Integrated_Frame<uint16_t> 	input;
	long int					current_position {in_file.tellg()};
	unsigned int				how_many_hits {0};			 

	while( !in_file.eof() ) 
	{	
		//Avoids additional entry when the file over but not -1 yet
		if(current_position == _input_file_size) break;
		
			
		// Read array of integrated frame 
		in_file.read((char*) &input, sizeof(input) );
	}
	
	//std::cout << print_hex( std::string( (char*) &input, sizeof(input)), true) << std::endl;;

	MSG(CNTR, "Input array is: " + std::to_string(input.integrated_frame.size()) + " per " + std::to_string((&input.integrated_frame[0])->size()) );
	
	std::ofstream myfile;
	if(_column_end==127) { myfile.open ("../MIMOSIS1_PhysicsAnalysis_unix/masked/masked_pixels_no"+std::to_string(_chipNo)+"_A_"+std::to_string(_param_3_value)+"_"+std::to_string(_param_1_value)+".txt", std::ofstream::app); }
	else if(_column_end==511) { myfile.open ("../MIMOSIS1_PhysicsAnalysis_unix/masked/masked_pixels_no"+std::to_string(_chipNo)+"_B_"+std::to_string(_param_3_value)+"_"+std::to_string(_param_1_value)+".txt", std::ofstream::app); }
	else if(_column_end==895) { myfile.open ("../MIMOSIS1_PhysicsAnalysis_unix/masked/masked_pixels_no"+std::to_string(_chipNo)+"_C_"+std::to_string(_param_3_value)+"_"+std::to_string(_param_1_value)+".txt", std::ofstream::app); }
	else { myfile.open ("../MIMOSIS1_PhysicsAnalysis_unix/masked/masked_pixels_no"+std::to_string(_chipNo)+"_D_"+std::to_string(_param_3_value)+"_"+std::to_string(_param_1_value)+".txt", std::ofstream::app); }

	for(long unsigned int col_it = 0; col_it < input.integrated_frame.size() ; col_it++) 
	{	
		for(long unsigned int row_it = 0; row_it < (&input.integrated_frame[0])->size() ; row_it++) 
		{
			how_many_hits = input.integrated_frame[col_it][row_it];

			if(static_cast<int>(how_many_hits) > _nb_of_frames) 
			{
				MSG(WARN, "\t\t For pixel: [" << col_it << ", " << row_it << "] nb of hits largen than nb of frames: " << how_many_hits );
				h2_pixels_fired_over_nbframes -> Fill(col_it, row_it, how_many_hits);	
			}
			
			if( static_cast<int>(how_many_hits)  > 1.05*_nb_of_frames) 
			{
				myfile << col_it << "\t" << row_it << std::endl;
			}
			
			if((_param_2_value == 0) && (static_cast<int>(how_many_hits)  > 10))
			{
				myfile << col_it << "\t" << row_it << std::endl;
				//std::cout << "Non zero at first file " <<   col_it << "\t" << row_it << std::endl;
			}
			
			
			
			if(how_many_hits==0) 
			{
				continue;
			}
			
			MSG(DEB, "\t\tFired pixel: " + std::to_string(col_it) + " " + std::to_string(row_it) + " --> " + std::to_string(how_many_hits) );

			h2_integrated_frame_matrix 	-> Fill(col_it, row_it, how_many_hits);	
			h2_integrated_frame_part 	-> Fill(col_it, row_it, how_many_hits);
				
			h_hitrate	-> Fill(how_many_hits);
			if((col_it <= 127)) {h_hitrate_matA-> Fill(how_many_hits) ;}
			if((col_it >= 128 ) && (col_it <= 511)) {h_hitrate_matB-> Fill(how_many_hits) ;}

		}
	}
	
	myfile.close();

}

void DataConverter::save_png()
{	
	TCanvas *c = new TCanvas();
	gStyle->SetOptStat(0);
	c->Update();
	
	c->Clear();
	c->cd();
	h2_integrated_frame_matrix->Draw("COLZ");
	h2_integrated_frame_matrix->SetMaximum(_nb_of_frames);
	c->Print(_out_name+"_h2_integrated_frame_matrix.pdf");

	c->Clear();
	c->cd();
	h2_integrated_frame_part->Draw("COLZ");
	h2_integrated_frame_part->SetMaximum(_nb_of_frames);
	c->Print(_out_name+"_h2_integrated_frame_part.pdf");
	
	c->cd();
	c->SetLogy();
	//h_fired_pixels_int_frame->GetXaxis()->SetRangeUser(400, 2*_nb_of_frames);
	h_hitrate->Draw();
	c->Print(_out_name+"_h_hitrate.pdf");
	
	c->Clear();
	c->cd();  gPad->SetFrameFillColor(kBlack);
	h2_pixels_fired_over_nbframes->SetMinimum(_nb_of_frames);
	//h2_pixels_fired_over_nbframes->SetFillColor(1);
	//h2_pixels_fired_over_nbframes->GetXaxis()->SetRangeUser(0, 128);
	gStyle->SetPalette(kDarkRainBow);
	h2_pixels_fired_over_nbframes->Draw("COLZ");
	c->Print(_out_name+"_h2_pixels_fired_over_nbframes.pdf");
	
	

}
