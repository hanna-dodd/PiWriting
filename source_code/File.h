/** 
*   @brief      File class.
*   @details    Contains the filename and type of file.
*   @author     Hanna Dodd
*/
#ifndef File_h
#define File_h

#include <string>
#include <iostream>

class File {

	private:
		
		/// File name.
		std::string filename;

		/// File type.
		std::string filetype;

	public:

		///	Constructor.
		File(std::string, std::string);

		///	Destructor.
		~File() {}

		/// File name getter.
		std::string getname();

		///	File type getter.
		std::string gettype();

};

#endif