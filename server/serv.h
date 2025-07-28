#ifndef SERV_H
#define SERV_H

#include <arpa/inet.h>
#include "../utils/common.h"

#define PORT 9000
#define BUFFERSIZE 4096
#define BACKLOG 10
#define LINE_SIZE 512


class Serv {
public:
    Serv();//
    ~Serv();//

    int accept_cli();  //
    void run();        
    
    void send_msg(int cli_fd, MSG* msg);
    void recv_msg(int cli_fd, MSG* msg);

private:
    int serv_fd;
    int opt;
    struct sockaddr_in addr;
    socklen_t socklen;
};


#endif