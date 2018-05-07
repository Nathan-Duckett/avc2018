#include "header.h"

/**
 * This file is for storing the network code required to open
 * the inital gate on the course with a network request.
 */

void open_gate () {
    
}

//Code found on last year's github
# include <stdio.h>
# include <time.h>

int init(int d_lev);
int connect_to_server( char server_addr[15],int port);
int send_to_server(char message[24]);
int receive_from_server(char message[24]);

int main (){
   // This sets up the RPi hardware and ensures
   // everything is working correctly
   init(1);
   //connects to server with the ip address 192.168.1.2
   connect_to_server("192.168.1.2", 1024); //error converting string to char
   //sends a message to the connected server
   send_to_server("Hello server"); //error converting string to char
   //receives message from the connected server
   char message[24];
   receive_from_server(message); //this may be buggy!
   printf("%s", message);

return 0;}
