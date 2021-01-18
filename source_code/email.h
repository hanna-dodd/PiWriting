/** 
*   @brief      Email class.
*   @details    Allows emails to be sent to and from the application.
*   @author     Connor Ciavarella
*/
#ifndef EMAIL_H
#define EMAIL_H
#include <string>
#include <vector>
#include <mailio/message.hpp>

class email {

	private:

		std::string addr, psswd, name, provider;
		
	public:

		/// Constructor.
		email(std::string, std::string, std::string);

		/// Destructor.
		~email();
		
		/// Connects to SMTP.
		std::string smtpServer();

		/// Connects to IMAP.
		std::string imapServer();
		
		/// Sends mail from current email address.
		int sendmail(std::string, std::string, std::string);
		
		/// Get mail from current email address.
		std::vector<std::string> getmail();
		
};

#endif
