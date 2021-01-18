/** 
*   @brief      Email class implementation.
*   @details    Allows emails to be sent to and from the application.
*   @author     Connor Ciavarella
*/
#include "email.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "mailio/smtp.hpp"
#include <mailio/message.hpp>
#include <mailio/imap.hpp>
#include <vector>

// namespaces used
using namespace std;
using mailio::message;
using mailio::mail_address;
using mailio::smtps;
using mailio::imaps;
using mailio::smtp_error;
using mailio::dialog_error;
using mailio::imap_error;
using mailio::codec;

/**
*   @brief      Constructor.   
*   @details    Creates an email object.
*   @param      Address - email address of the user.
*	@param 		Password - password of the email address.
*	@param		Username - name of the user.
*/
email::email(string address, string password, string username) {
	addr = address;
	psswd = password;
	name = username;
	
	// determines the email provider that is used
	stringstream ss(addr);
	
	getline(ss, provider, '@');
	getline(ss, provider, '@');
	
}

/**
*   @brief      Default Destructor.   
*   @details    Destroys a file object.
*/
email::~email() {
	
}

/**
*   @brief      Connects to SMTP server.   
*   @details    Returns the correct SMTP server based on the given provider.
*	@returns	The correct SMTP server.
*/
string email::smtpServer() {

	if (provider == "gmail.com") {

		return "smtp.gmail.com";
			
	} else if (provider == "outlook.com") {

		return "smtp.office365.com";
		
	} else {

		// if the provider isnt gmail.com, outlook.com, or yahoo.com its not supported but will attempt with smtp.provider
		cout << "Attempting with unsupported provider. Supported providers are gmail.com, and outlook.com.";
		return "smtp." + provider;
				
	}

}

/**
*   @brief      Sends mail containing an attachment.   
*   @details    Send an email from the given user containing an attachment of the converted file.
*	@param		Recv - the receiving user's name
*	@param		Recvaddr - the receiving email address
*	@param		File name - the name of the file to attach
*	@returns	Returns 0 if successful, and 1 if an error occured.
*/
int email::sendmail(string recv, string recvaddr, string filename) {

	// try so that if there is an issue connecting it doesnt crash the program and it can just be said to have failed
	try {

		message msg;
		
		// sets the from, to, and subject for the message
		msg.from(mail_address(name, addr));
		msg.add_recipient(mail_address(recv, recvaddr));
		
		msg.subject("Piwriting output file");
		
		// adds the file to the message
		ifstream file(filename);
		msg.attach(file, filename, message::media_type_t::TEXT, "plain");
		
		msg.content("Here is your file");
        
        // gets the server address based on the email provider
        string serveraddr = smtpServer();
		
		// connects to the server and authenticates then sends the message
		smtps connect(serveraddr, 587);
        
        connect.authenticate(addr, psswd, smtps::auth_method_t::START_TLS);
        connect.submit(msg);
        
    }
    
    // catches any errors and prints them and returns 1
	catch (smtp_error& exc) {
		cout << exc.what() << endl;
		return 1;
		
	}
	
	catch (dialog_error& exc) {
		cout << exc.what() << endl;
		return 1;
	
	}
	
	catch (...) {
		return 1;
	}
	
	// returns 0 if successful
	return 0;

}

/**
*   @brief      Connects to IMAP server.   
*   @details    Returns the correct IMAP server based on the given provider.
*	@returns	The correct IMAP server.
*/
string email::imapServer() {

	if (provider == "gmail.com") {

		return "imap.gmail.com";
			
	} else if (provider == "outlook.com") {

		return "imap-mail.outlook.com";
		
	} else {

		// if the provider isnt gmail.com, outlook.com, or yahoo.com its not supported but will attempt with imap.provider
		cout << "Attempting with unsupported provider. Supported providers are gmail.com, and outlook.com.";
		return "imap." + provider;
				
	}

}

/**
*   @brief      Gets mail from the current objects account.   
*   @details    Gets the most recent mail from the current inbox and downloads the attachments in it.
*	@returns	A vector containing all of the attachment names from the most current email.
*/
vector<string> email::getmail() {

	// sets the filenames vector which will store all the files in the email
	vector<string> filenames;
	
	// try so that if there is an issue connecting it doesnt crash the program and it can just be said to have failed
	try {

		// gets the imap server address based on the email provider and connects
		string imapaddr = imapServer();
		
		imaps connect(imapaddr, 993);
		
		message msg;
		int numattached;
		
		// sets the line policy to allow reading long obejcts
		msg.line_policy(codec::line_len_policy_t::RECOMMENDED, codec::line_len_policy_t::MANDATORY);
		
		connect.authenticate(addr, psswd, imaps::auth_method_t::LOGIN);
		
		// deteremines the number of messages in the inbox so that it grabs the most recent one
		imaps::mailbox_stat_t stat = connect.statistics("inbox");
		
		int nummsg = stat.messages_no;
		
		// gets the most recent message
		connect.fetch("inbox", nummsg, msg);
		
		// gets the number of attachments
		numattached = msg.attachments_size();
		
		// downloads each attachment and adds its name to filenames
		for (int i = 0; i < numattached; i++) {

			size_t index = i + 1;
			string attachmentname = msg.attachment_name(index);
			
			ofstream attachment(attachmentname);
			
			msg.attachment(i + 1, attachment, attachmentname);
			
			filenames.push_back(attachmentname);
			
		}
		
		return filenames;
		
	}
	
	// catches any errors and returns filenames with only a "1" in it as the error code
	catch (imap_error& exc) {
		cout << exc.what() << endl;
		filenames.clear();
		
		filenames.push_back("1");
		
		return filenames;
		
	}
	
	catch (dialog_error& exc) {
		cout << exc.what() << endl;
		filenames.clear();
		
		filenames.push_back("1");
		
		return filenames;
	
	}
	
	catch (...) {
		filenames.clear();
		
		filenames.push_back("1");
		
		return filenames;
		
	}
}

