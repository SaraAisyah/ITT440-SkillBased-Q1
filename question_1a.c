#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>

int main(){

int socket_desc, new_socket, number;
struct sockaddr_in server_address, client_address;
char recvBuffer[1024];
int m;
int addrlen = sizeof(client_address);

//Create socket
socket_desc = socket(AF_INET, SOCK_STREAM, 0);

server_address.sin_family = AF_INET;
server_address.sin_addr.s_addr = INADDR_ANY;
server_address.sin_port = htons(8080);


//Bind
if(bind(socket_desc,(struct sockaddr *)&server_address, sizeof(server_address)) < 0)
  printf("Bind failed");

//Listen
listen(socket_desc, 5);


new_socket = accept(socket_desc, (struct sockaddr*)&client_address,(socklen_t*)&addrlen);
if (new_socket < 0)
    printf("Accept Failed");

//Generate random number
srand( time(NULL) );
number = (rand() % 900) + 100;

sprintf(recvBuffer, "%d", number);

m = write(new_socket, recvBuffer, sizeof(recvBuffer));

if(m < 0)
   printf("Writing Error");

close(new_socket);
close(socket_desc);

return 0;
}

