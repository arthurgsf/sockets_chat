#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char buffer[200];
    int soc;
    struct sockaddr_in serverAddr;

    bzero(&serverAddr, sizeof(serverAddr));       //zera o endereço
    serverAddr.sin_family = AF_INET;              //tipo de endereço
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //endereço ip
    serverAddr.sin_port = htons(3490); //porta

    soc = socket(AF_INET, SOCK_STREAM, 0);
    printf("insira seu nickname : ");
    fgets(buffer, sizeof(char)*200, stdin);
    buffer[strlen(buffer)-1] = '\0';
    if (connect(soc, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == 0){
        printf("conexão estabelecida!\n");
        send(soc, buffer, sizeof(buffer), 0);
        shutdown(soc, 2);
        close(soc);
    }
    return 0;
}
