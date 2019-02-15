#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>

    int main(int argc, char const *argv[]){

    char buffer[200];
    int soc, con_soc;
    struct sockaddr_in serverAddr;

    bzero(&serverAddr, sizeof(serverAddr));//zera o endereço
    serverAddr.sin_family = AF_INET;//tipo de endereço
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //endereço ip
    serverAddr.sin_port = htons(3490); //porta

    /* tenta criar um socket */
    if (soc = socket(AF_INET, SOCK_STREAM, 0)){

        /* se der certo associa ele ao endereço definido */
        bind(soc, (struct sockaddr*)&serverAddr, sizeof(struct sockaddr));

        /* define o máximo de requisições pendentes */
        listen(soc, 5);
        printf("escutando na porta 3490...\n");

        while(1){
            con_soc = accept(soc, (struct sockaddr *)NULL, NULL);
            if (con_soc != -1){
                recv(con_soc, buffer, sizeof(char)*200, 0);
                printf("%s acabou de entrar!\n", buffer);
            }
        }
    }
    return 0;
}
