/** 
*   @brief      Converter class implementation.
*   @details    Converts image file to string output in english.
*   @author     Maximilian Smosarski
*/
#include "Converter.h"
#include <fstream>
#include <algorithm>

using namespace std;

/**
*   @brief      Converts png or jpeg to string.   
*   @details    Uses Tesseract API to recognize characters from an image File object and format into
*               an Output object.
*   @param      Image - the image file object
*   @returns    Output object containing converted text and language.
*/
Output Converter::imagetostring(File image) {

    string imagename = image.getname();

    // Calling the Tesseract API command.
    string commandString = "tesseract " + imagename + " temp";
    const char *command1 = commandString.c_str();
    system(command1);

    // Removing all newline characters from output.
    ifstream in("temp.txt");
    string s((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    system("rm ./temp.txt");

    Output output(s, "en");

    return output;

}
