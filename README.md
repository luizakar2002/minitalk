# minitalk
Summary: The purpose of this project is to code a small data exchange program using
UNIX signals.

• A communication program in the form of a client and server.
• The server must be launched first, and after being launched it must display its PID.
• The client will take as parameters:
◦ The server PID.
◦ The string that should be sent.
• The client communicates the string passed as a parameter to the server. Once
the string has been received, the server displays it.
• Communication between programs is ONLY done using UNIX signals.
• The server is able to display the string pretty quickly.
• Server is able to receive strings from several clients in a row, without
needing to be restarted.
• Only used these two signals: SIGUSR1 and SIGUSR2.
