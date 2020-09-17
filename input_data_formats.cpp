
#include "input_data_format.h"


template<typename T>

struct Integrated_Frame 
{
	std::array<  std::array<T, ROWS> , COLS> integrated_frame;		
};
