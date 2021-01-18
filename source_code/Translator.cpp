/** 
*   @brief      Translator class implementation.
*   @details    Translates the Output string to a given language.
*   @author     Hanna Dodd
*   @author     Bennett McDonald
*/
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Translator.h"
#include "Output.h"

using namespace std;

/**
*   @brief      Constructor.   
*   @details    Creates a translator object.
*   @param      Langto - language to translate to.
*	@param 		Langfrom - language to translate from.
*/
Translator::Translator(string langto, string langfrom) {

	this->langto = langto;
    this->langfrom = langfrom;

}

/**
*	@brief		Language to getter.
*	@details	Gets the language to translate to.
*	@returns	The language.
*/

string Translator::getlangto() {

	return this->langto;

}

/**
*	@brief		Language from getter.
*	@details	Gets the language to translate from.
*	@returns	The language code.
*/

string Translator::getlangfrom() {

	return this->langfrom;

}

/**
*	@brief		Translator.
*	@details	Translates the string from the Output object to the given language.
*	@param 		output - the object containing the string to be translated.
*	@param 		langto - the language to translate the string to.
*	@returns	The translated Output object.
*/
Output Translator::translate(Output output, string langto) {

	string input = output.getText();

	string translatedInput;
	string commandString;

	// command to interact with the API and translate the input
	commandString = "curl -X POST 'https://api.cognitive.microsofttranslator.com/translate?api-version=3.0&to=" + langto + "' \
     -H 'Ocp-Apim-Subscription-Key:b8153476d67c4a439fc258360d11670e' \
     -H 'Ocp-Apim-Subscription-Region:eastus' \
     -H 'Content-Type: application/json' \
     -d '[{\"Text\":\"" + input + "\"}]'";

	cout << "Beginning Translation..." << endl;

	// execute command
	system((commandString + " > temp.txt").c_str());

	// input command line output to a temporary txt file
	ifstream inp("temp.txt");
	getline(inp, translatedInput);
	inp.close();

	// parse input to only be the translated text
	string end = translatedInput.substr(76);
	int count = 0;

	// loop through string until end of translated text
	for(char c : end) {

		if (c == '"') {
			break;
		}

		count += 1;

	}

	string newtext = end.substr(0, count);

	Output translated(newtext, langto);

	return translated;

}