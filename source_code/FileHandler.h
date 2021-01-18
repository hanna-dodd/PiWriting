/** 
*   @brief      FileHandler class.
*   @details    Converts File objects from one type to another.
*   @author     Maximilian Smosarski
*   @author     Connor Ciavarella
*   @author     Bennett McDonald
*   @author     Jerrie Berrafati
*/
#ifndef FileHandler_H
#define FileHandler_H
#include <string>
#include "File.h"
#include "Output.h"

class FileHandler {

    public:

        /// Constructor.
        FileHandler() { }

        /// Destructor.
        ~FileHandler() { }

        /// Write to Text.
        File writetotxt(Output);

        /// Write to Doc.
        File writetodoc(Output);

        /// Write to Wav.
        File writetoaudio(Output);

        /// Play audio.
        void playaudio(Output);

};

#endif
