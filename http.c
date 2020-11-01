#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h> 
#include <strings.h>
#include "utilities.hpp"

#ifdef WIN32
#include <winsock2.h>
#include <windows.h>
#else
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h> 
#endif

int8_t parseUrl(char* uri, char** host, char** path) {
    char* pos;

    //DEBUG_MSG_PRINT("In parseUrl()\n");

    pos = strstr(uri, "//");

    

    if(pos == 0) {
        return -1;
    }

    *host = pos + 2;
    //printf("host = %c\n", **host);

    pos = strchr(*host, '/');

    //DEBUG_MSG_PRINT("Here\n");
    if(pos == 0) {
        *path = NULL;
    } else {
        
        *path = pos + 1;
        //printf("path = %c\n", **path);
        pos = '\0';
    }

    return 1;
    

}
int main() {
    char* host;
    char* path;
    char url[100];
    strcpy( url, "https://www.google.com/unique");
    //printf("In main...\n");
    printf("Return value: %d\n", parseUrl(url, &host, &path));

}