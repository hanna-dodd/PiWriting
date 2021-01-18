/** 
*   @brief      Translator class implementation.
*   @details    Translates the Output string to a given language.
*   @author     Hanna Dodd
*   @author     Bennett McDonald
*/
#ifndef Translate_h
#define Translate_h
#include "Output.h"

class Translator {

	private:

		/// Language to translate to.
		std::string langto;

		/// Language to translate from.
		std::string langfrom;

	public:

		/// Constructor.
		Translator(std::string, std::string);

		/// Destructor.
		~Translator() { }

		/// Language to Getter.
		std::string getlangto();

		/// Language from Getter
		std::string getlangfrom();

		/// Translator.
		Output translate(Output, std::string);

};

#endif

