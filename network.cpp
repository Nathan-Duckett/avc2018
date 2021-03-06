#include "header.h"

/**
 * This file is for storing the network code required to open
 * the inital gate on the course with a network request.
 */

int init(int d_lev);
int connect_to_server( char server_addr[15],int port);
int send_to_server(char message[24]);
int receive_from_server(char message[24]);

void open_gate () {
	char server_address[] = {'1','3','0','.','1','9','5','.','6','.','1','9','6'};
	char password[] = {'P','l','e','a','s','e'};
	//connects to server with the ip address 192.168.1.2
	connect_to_server(server_address, 1024); //error converting string to char
	//sends a message to the connected server
	send_to_server(password); //error converting string to char
	//receives message from the connected server
	char message[24];
	receive_from_server(message); //this may be buggy!
	printf("%s", message);
	send_to_server(message);
}

