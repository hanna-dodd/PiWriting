/** 
*   @brief      File class implementation.
*   @details    Contains the filename and type of file.
*   @author     Hanna Dodd
*/
#include "File.h"

using namespace std;

/**
*   @brief      Constructor.   
*   @details    Creates a file object.
*   @param      Name - name of the file.
*	@param 		Type - file type (img, .txt, .docx, or .wav).
*/
File::File(string name, string type) {

    this->filename = name;
    this->filetype = type;

}

/**
*	@brief		File name getter.
*	@details	Gets the file name of the object.
*	@returns	The file name.
*/
string File::getname() {

    return this->filename;

}

/**
*	@brief		File type getter.
*	@details	Gets the file type of the object.
*	@returns	The file type.
*/
string File::gettype() {

    return this->filetype;

}
