#include "CSmtp.h"
#include <iostream>

int main()
{
	bool bError = false;

	try
	{
		CSmtp mail;

#define test_163_ssl

#if defined(test_gmail_tls)
		mail.SetSMTPServer("smtp.gmail.com",587);
		mail.SetSecurityType(USE_TLS);
#elif defined(test_gmail_ssl)
		mail.SetSMTPServer("smtp.gmail.com",465);
		mail.SetSecurityType(USE_SSL);
#elif defined(test_hotmail_TLS)
		mail.SetSMTPServer("smtp.live.com",25);
		mail.SetSecurityType(USE_TLS);
#elif defined(test_aol_tls)
		mail.SetSMTPServer("smtp.aol.com",587);
		mail.SetSecurityType(USE_TLS);
#elif defined(test_yahoo_ssl)
		mail.SetSMTPServer("plus.smtp.mail.yahoo.com",465);
		mail.SetSecurityType(USE_SSL);
#elif defined(test_163_ssl)
		mail.SetSMTPServer("smtp.163.com",465);
		mail.SetSecurityType(USE_SSL);
#endif

		mail.SetLogin("sxmobi_1");
		mail.SetPassword("het123457");
  		mail.SetSenderName("sxmobi_1@163.com");
  		mail.SetSenderMail("sxmobi_1@163.com");
  		mail.SetReplyTo("sxmobi_1@163.com");
  		mail.SetSubject("The message");
  		mail.AddRecipient("263996097@qq.com");
  		mail.SetXPriority(XPRIORITY_NORMAL);
  		mail.SetXMailer("The Bat! (v3.02) Professional");
  		mail.AddMsgLine("Hello,ccccccccccccccccccccccc");
		mail.AddMsgLine("");
		mail.AddMsgLine("...");
		mail.AddMsgLine("How are you today?");
		mail.AddMsgLine("");
		mail.AddMsgLine("Regards");
		mail.ModMsgLine(5,"regards");
		mail.DelMsgLine(2);
		mail.AddMsgLine("User");

  		//mail.AddAttachment("../test1.jpg");
  		//mail.AddAttachment("c:\\test2.exe");
		//mail.AddAttachment("c:\\test3.txt");
		mail.Send();
	}
	catch(ECSmtp e)
	{
		std::cout << "Error: " << e.GetErrorText().c_str() << ".\n";
		bError = true;
	}
	if(!bError)
		std::cout << "Mail was send successfully.\n";
	return 0;
}
