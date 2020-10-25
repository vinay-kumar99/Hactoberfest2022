import smtplib
from email.message import EmailMessage

send_mail_to = ['test1@gmail.com','test2@gmail.com' ] # Mail Id's of persons to whom the mail is to be sent to
email_obj = EmailMessage()
email_obj['from'] = '{Senders Name/Username}'
email_obj['to'] = ', '.join(send_mail_to)
email['subject'] = input("Please enter the subject: ")

email.set_content(input("Please enter The content: \n\t"))

with smtplib.SMTP(host='smtp.gmail.com', port=587) as smtp:
    smtp.ehlo()
    smtp.starttls()
    while True:
        try:
            mail_id = 'test@gmail.com'
            email_password = input("Please enter the password for " + mail_id + ":- ")
            smtp.login(mail_id, email_password)
            smtp.send_message(email_obj)
            print("Done!!!")
            break
        except:
            print("There was a problem while login try again or check if this application is allowed to use the mail services in your mail settings")
            
