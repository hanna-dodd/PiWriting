/** 	
*   @brief      Converter class.
*   @details    Converts image file to string output in english.
*   @author     Maximilian Smosarski
*/
#ifndef Converter_H
#define Converter_H
#include <string>
#include "File.h"
#include "Output.h"

class Converter {

        public:

                ///	Constructor.
                Converter() { }

                ///	Destructor.
                ~Converter() { }

                ///	Image to string.
                Output imagetostring(File);

};

#endif