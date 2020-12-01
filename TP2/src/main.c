#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int main(int argc, char *argv[]){
    if (argc != 2) {
        printf("Usage: %s %s\n", argv[0], "ftp://[<user>:<password>@]<host>/<url-path>");
        return -1;
    }

    struct urlArgs args;
    if(getArgsFromUrl(argv[1],&args) != 0){
        exit(1);
    }
    //printf("User: %s\n", args.user);
    //printf("Password: %s\n", args.password);
    //printf("Host name: %s\n", args.host);
    //printf("Path name: %s\n", args.path);
    //printf("File name: %s\n", args.filename);

    char IP[STR_LEN];
    if(getIP(args.host,IP)!=0){
       printf("failed retrieving IP\n");
       return -1;
    }
    //printf("IP: %s\n",IP);

    int sockfd;
    if(openSocket(IP,&sockfd) != 0){
        printf("failed opening socket\n");
       return -1;
    }


    return 0;
}