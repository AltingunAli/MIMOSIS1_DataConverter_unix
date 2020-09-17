/*! @file DataConverter.h
 *  @brief Header file for DataConverter class.
 */


#ifndef _DATACONVERTER_H_        // include guard 
#define _DATACONVERTER_H_        

#include "input_data_formats.h"
#include "cout_msg.h"
#include "globals.h"


/*! \class 		DataConverter
 *  \brief 		opening file/tree, writing to tree and closing the file/tree.
 *  \author    	Roma Bugiel
 *  \date      	August 2020
 *  \pre       	ROOT installation
 *  \warning   	Exeception handling not added
 */

class DataConverter {
    
public:
	
	//-------------------------
	//----- Constructors ------ 
	//-------------------------
	
	//! Default constructor
	DataConverter(){};  

	//-------------------------
	//-------- Methods -------- 
	//-------------------------

	 /*! \brief Initializes the class memebers.
	 *   \details Checks if TEnv object is correctly read in (config_file.cfg). If not it exits. Otherwise it assigns values from config_file.cfg to class members. It also initializes _param string, used for output file naming. */
    void init();
    
    //-------------------------
	/*! \brief Calculates the file size that was assigned to ifstream in_file 
     *  \return Size of the input file in bits. */
    int get_file_size();
    
    //-------------------------
    /*! \brief Takes binary input and saves it in hex. 
	 *  \param[in] s input string in binary format
	 *  \param[in] upper_case true to get the output with A, B, C, D, E
     *  \return std::string corresponding to s in hex. */
    std::string print_hex(std::string s, bool upper_case=true);
	
	//-------------------------
	 /*!  Overloading stream insertion operator. 
	  *   Lists all class members and theris current values. */
	friend std::ostream &operator<<(std::ostream &os, const DataConverter &treereader);

    /*!  \brief Opens file: _in_file_path+"/"+_in_file_name and assigns it to ifstream in_file */
    void open_file() ;
    
    //-------------------------
    /*! \brief Fill tree accoriding to input data format.
	 *  \param[in] input_data_format 1 = RAW, 2 = DEC, 3 = FIRED (default). */
	void 	fill_tree(int input_data_format = 3);

	/*! \fn fill_tree_raw();  
	 * 	\brief Not defined yet. For reading RAW DAQ data format. 
	 *  \fn fill_tree_dec(); 
	 * 	\brief Not defined yet. For reading DEC DAQ data format. */
	void 	fill_tree_raw();
	void 	fill_tree_dec();
	
	/*! \brief Reads Integrated_Frame from input file and fills output histograms .
	 *  \details Fills:
	 *  h2_integrated_frame_matrix, h2_integrated_frame_part, h_fired_pixels_int_frame */
	
	void 	fill_tree_fired();
	
	//-------------------------
	/*! \brief Open output tree
	 *  \details The path and name of the output tree is: 
	 * 
	 * _out_tree_file_path/_out_tree_file_name + _ + _param + _ + _out_prefix + .root
	 * 
	 * or when _is_noise = 1:
	 * 
	 * _out_tree_file_path + / + _out_tree_file_name + _ + NOISE + _out_prefix + .root;	
	 */
    void 	open_tree();
    
    //-------------------------
    /*! \brief Writes data and closes TFile. */
    void 	close_tree();

	//Input files
	std::ifstream 	in_file; /*!< ifstream object holding a binary input file */
	long int 		_input_file_size {0}; 	/*!< size of the input file in bits */
	
	//! Default constructor
	~DataConverter();
	
private:
	
	#ifndef DOXYGEN_SHOULD_SKIP_THIS

	//Analysis flags
	int _is_noise;
	int	_is_uint16_t;
	
	//Output tree
	TString _out_prefix{""};
 	TString _out_tree_file_path {""};
	TString _out_tree_file_name {""};
	TString _out_tree_name {""};  
	TString _out_name;
	
	//Detector parameters
	int _nb_of_rows; 	
	int _nb_of_columns;
	int	_nb_of_frames;
	int _row_start;			
	int _row_end;			
	int _column_start;		
	int _column_end;

	//Data formats flags
	int _input_data_format;
	int _output_data_format;	

	//TTree definition
	TFile *_output_data_file;
	TTree *_mimosis_tree;

	std::string _param_1;
	std::string _param_2;
	std::string _param_3;
	
	int _param_1_value;
	int _param_2_value;
	int _param_3_value;
	
	TEnv config;

	#endif /* DOXYGEN_SHOULD_SKIP_THIS */
	/*! \brief string with the run params full info
	 *  \details _param = _param_1+_param_1_value+_param_2+_param_2_value+_param_3+_param_3_value
	 *
	 * so for example:  
	 * VBB_10_VPH_100_VH_10
	 * 
	 * It is used for output file name and histogram captions*/
	std::string _param {""};

	//Input file
	std::string _in_file_path; /*!< \brief Input file path */
	std::string _in_file_name; /*!< \brief Input file name */	
	
	
	//Histo definition
  	/*! \brief Integrated hit map of N frames plotted for full matrix.
	 *  \details The 2-dim histogram corresponding to the pixel matrix. 
	 *  Axes are defined for full matrix (0 - (_nb_of_rows-1) for Y axis and 0 - (_nb_of_rows-1) for X axis). 
	 *  Each pixel value corresponds to how many times pixel fired in N (=_nb_of_frames) frames. 
	 *  N is displayed in the histo caption and SHOULD be defined in the config_file.cfg */
	TH2D *h2_integrated_frame_matrix;
	
	/*! \brief Integrated hit map of N frames plotted for part of the matrix.
	 *  \details The 2-dim histogram corresponding to the part (or entire) pixel matrix. 
	 *  Axes might be defined for part of the matrix (_row_start, _row_end, _column_start, _column_end) in config_file.cfg.
	 *  Each pixel value corresponds to how many times pixel fired in N (=_nb_of_frames) frames. 
	 *  N is displayed in the histo caption and SHOULD be defined in the config_file.cfg */
	TH2D *h2_integrated_frame_part;
	
	/*! \brief Multiplicity of pixel firing in N frames. 
	 *  \details 1-dim histogram  of integrated hit map (h2_integrated_frame_matrix). Shows how many pixels fired how many times. */
	TH1D *h_fired_pixels_int_frame;
	
	

} ; 

#endif
