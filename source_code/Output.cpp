/** 
*   @brief      Output class implementation.
*   @details    Contains the converted text and language.
*   @author     Hanna Dodd
*/
#include "Output.h"

using namespace std;

/**
*   @brief      Constructor.   
*   @details    Creates a output object.
*   @param      Text - string of text that the output of the image was.
*	@param 		Language - language that the string is in.
*/
Output::Output(string text, string language) {

        this->text = text;
        this->language = language;

}

/**
*	@brief		Text getter.
*	@details	Gets the output text of the object.
*	@returns	The output text.
*/
string Output::getText() {

        return this->text;

}

/**
*	@brief		Language getter.
*	@details	Gets the language of the object.
*	@returns	The language.
*/
string Output::getLanguage() {

        return this->language;

}

/**
*	@brief		Text setter.
*	@details	Sets the text of the object.
*	@param		Temp - the text to set to the object.
*/
void Output::setString(string temp) {

        this->text = temp;

}
