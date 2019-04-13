# CHAT
  
  It is client-server program in which you can chat to your friend via terminal to terminal in same network.
  
  Design using TCP/IP socket programing in pure c.
  
# USER
  
  To run this program following command for server:
  
  make -f server.mk
  
  ./server PORTNUMBER
  
  
  for client
  
  make -f client.mk
  
  ./client IP PORTNUMBER
  
  This will create object file. Command to cleam object file
  
  at server side: make clean -f server.mk
  
  at client side: make clean -f client.mk
  
  
