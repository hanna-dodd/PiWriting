/** 
*   @brief      Output class.
*   @details    Contains the converted text and language.
*   @author     Hanna Dodd
*/
#ifndef Output_H
#define Output_H
#include <string>

class Output {

    private:

        /// Output text.
        std::string text;

        /// Language of the text.
        std::string language;

    public:

        /// Default constructor.
        Output() {}

        /// Constructor.
        Output(std::string, std::string);

        /// Destructor.
        ~Output() { }

        /// Text getter.
        std::string getText();

        /// Language getter.
        std::string getLanguage();

        /// Text setter.
        void setString(std::string temp);

};

#endif
