/*! @file RunControler.cpp
 *  @brief main() 
 */

#include "DataConverter.h"

int main() 
{
	std::cout << "\n\n >>>>>>> Running data conversion for MIMOSIS1 <<<<<<<< \n\n" << std::endl;
	
	DataConverter*reader = new DataConverter();
			reader 		->	init();
			std::cout	<<	*reader;
			reader		->	open_tree();
			reader		->	open_file();
			reader		->	fill_tree(3);
			reader		->	close_tree();
	return 0;
}
