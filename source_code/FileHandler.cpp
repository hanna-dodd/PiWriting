/** 
*   @brief      FileHandler class implementation.
*   @details    Converts File objects from one type to another.
*   @author     Maximilian Smosarski
*   @author     Connor Ciavarella
*   @author     Bennett McDonald
*   @author     Jerrie Berrafati
*/
#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "FileHandler.h"
#include "File.h"
#include "Output.h"

using namespace std;

/** 	
*   @brief      Converts Output to a .txt file.
*	@details    Saves a .txt file to the current directory containing the string output.
*   @author     Maximilian Smosarski
* 	@param      Output - the Output object converted from the image.
* 	@returns    File object containing the file name and type of the converted file.
*/
File FileHandler::writetotxt(Output output) {

    string input = output.getText();

    ofstream MyFile;
    MyFile.open("export.txt");

    // Check that the file is open
    if (!MyFile.is_open()) {
        cerr << "Failed to create file.\n";
        exit(1);

    }

    MyFile << input;
    MyFile.close();

    File txt("export.txt", "txt");

    return txt;

}

/**     
*   @brief      Converts Output to a .docx file.
*   @details    Saves a .docx file to the current directory containing the string output.
*   @author     Connor Ciavarella
*   @author     Bennett McDonald
*   @param      Output - the Output object converted from the image.
*   @returns    File object containing the file name and type of the converted file.
*/
File FileHandler::writetodoc(Output output) {

    string filetext = output.getText();

    if (filetext.length() == 0) {
        File docx("error", "error");
        return docx;

    }

    ofstream outputfile;
    string newfile = "export.docx";
    outputfile.open(newfile);

    // Check that the file is open
    if (!outputfile.is_open()) {
        cerr << "Failed to create file.\n";
        exit(1);

    }

    outputfile << filetext;
    outputfile.close();

    File docx("export.docx", "docx");

    return docx;

}

/**     
*   @brief      Converts Output to a .wav file.
*   @details    Saves a .wav file to the current directory containing the string output.
*   @author     Jerrie Berrafati
*   @param      Output - the Output object converted from the image.
*   @returns    File object containing the file name and type of the converted file.
*/
File FileHandler::writetoaudio(Output output){

    string text = output.getText();

    // The command executed to save the string as an audio file.
    string commandString1 = "espeak -p 40 '" + text + "' -s 115 -w export.wav";

    // Creating the terminal command for espeak to work
    const char *command1 = commandString1.c_str();
    cout << "Saving the file..." << endl;

    // Executes the espeak command
    system(command1);

    File wav("export.wav", "wav");

    return wav;

}

/**     
*   @brief      Plays the Output string out loud.
*   @details    Speaks the string out loud through the Pi using espeak.
*   @author     Jerrie Berrafati
*   @param      Output - the Output object converted from the image.
*/
void FileHandler::playaudio(Output output) {

    string text = output.getText();

    // -p adjusts the pitch of the voice
    // -s adjusts the speed of the voice
    // stdout | aplay plays the voice
    string commandString = "espeak -p 40 '" + text + "' -s 115 --stdout | aplay";

    // Creating the terminal command for espeak to work
    const char *command = commandString.c_str();

    cout << "Converting to audio..." << endl;
    // Executes the espeak command
    system(command);

}












