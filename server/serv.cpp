//syscall
#include <unistd.h>

//stdcall
#include <cstdio>
#include <cstdlib>

//include
#include "serv.h"
#include "../utils/utils.h"

Serv::Serv()
{
    //Creat socket
    serv_fd = socket(AF_INET, SOCK_STREAM, 0);

    opt = 1;
    setsockopt(serv_fd, 
                SOL_SOCKET, 
                SO_REUSEADDR | SO_REUSEPORT, 
                &opt,
                sizeof(opt)
    );

    //Bind
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    bind(serv_fd, (struct sockaddr*)&addr, sizeof(addr));

    //Listen
    listen(serv_fd, BACKLOG);
    printf("Listenning\n");
}

Serv::~Serv()
{
    close(serv_fd);
}

int Serv::accept_cli()
{
    //Accepting
    int cli_fd = accept(serv_fd, (struct sockaddr*)&addr, &socklen);
    printf("New client accepted\n");
    return cli_fd;
}

void send_msg(int cli_fd, MSG* msg)
{
        
}

void store_msg(int cli_fd, MSG* msg)
{
    //translate endian; check if file not exist, create the file; append msg
    
    char filepath[11];
    sprintf(filepath, "%u", msg->conv_id);

    FILE *file = fopen(filepath, "a");
    fprintf(file, msg->content);
}

void Serv::recv_msg(int cli_fd, MSG* msg)
{

    recv_bytes(cli_fd, &msg->conv_id, sizeof(msg->conv_id));
    msg->conv_id = htonl(msg->conv_id);   
    recv_bytes(cli_fd, msg->from, sizeof(msg->from));
    recv_bytes(cli_fd, msg->content, sizeof(msg->content));
}