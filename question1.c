#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){
    int socket_desc, n;
    struct sockaddr_in server_address;
    char recvBuffer[1024];
    
    socket_desc = socket(F_INET, SOCK_STREAM, 0);
    
    server_address.sin_addr.s_addr = inet_addr("192.168.234.128");
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    
    if(connect(socket_desc, (struct sockaddr *)server_address, sizeof(server_address)) < 0)
       printf("\n Connection Failed \n");
       
    n = read(socket_desc, recvBuffer, sizeof(recvBuffer)-1);
    
    if(n < 0)
      print("Read Failed \n");  
      
    printf("Random number from server: %s\n", recvBuffer);
    
    close(socket_desc);
    
 return 0;
    
 }
    
