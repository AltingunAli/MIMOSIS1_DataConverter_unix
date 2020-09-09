/*! @file input_data_formats.h
 *  @brief input_data_formats.h -- defines input data structure
 *
 * 	C-style structure, containing format of input data from MIMOSIS1 DAQ.
 *  MIMOSIS 1 provides theree input data formats:
 * 	- RAW
 *  - DEC
 *  - FIRED: two dimensional array, corresponding to pixel matrix, with the number of fired pixel in N frames. FIRED format might be given as uint32_t (default) or uint16_t elements, what might be set in config_file.cfg.
 * 	
 */

#include  <cstdint>
#include  <array>

/*! \brief Number of rows in the martix
*/
#define ROWS     504

/*! \brief Number of columns in the martix
*/
#define COLS     1024


// -----------------  FIRED FORMAT --------------------------

/*! \brief Structure holding MIMOSIS1 FIRED input data format (for uint32_t).
 *  \details It is built of 2-dimensional array (STL containter) of <b>uint32_t</b> elements.
 *   The size of the array is defined by COLS x ROWS macros. After changing these values program needs to be recompiled.  
 * 	\todo Should be on option for 16b unsigned interger also !
 */

struct Integrated_Frame 
{
	//uint32_t int_frame[1024][504];
	std::array<  std::array<uint32_t, ROWS> , COLS> integrated_frame;
			
};
