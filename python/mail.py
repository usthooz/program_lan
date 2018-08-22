import smtplib
import email.mime.multipart
import email.mime.text

msg = email.mime.multipart.MIMEMultipart()
msgFrom = "swxctx@sina.com"
msgTo = "swxctx@sina.net"
smtpSever = "smtp.sina.com"
smtpPort = "465"
passWord = ""

# send text
def send_text(From,To,title,context_text):
    msg["from"] = From
    msg["to"] = To
    msg["subject"] = title
    content = context_text
    txt = email.mime.text.MIMEText(content)
    msg.attach(txt)

    try:
        smtp  = smtplib.SMTP_SSL("smtp.sina.com",465)
        smtp.login(msgFrom,password)
        smtp.sendmail(msgFrom,msgTo,str(msg))
        smtp.quit()
        print("Mail send success...")
    except Exception:
        print("Mail send failed...")

send_text(msgFrom,msgTo,"第一个","发送的第一份邮件")
