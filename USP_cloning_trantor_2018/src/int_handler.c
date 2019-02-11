/*
** EPITECH PROJECT, 2018
** USP_cloning_trantor_2018
** File description:
** int_handler
*/

#include "trantor.h"

int keepRunning = 1;
int listen_port;

void intHandler(int dummy) {
    dummy = dummy;

    keepRunning = 0;
    int socket_desc;
    if ((socket_desc = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        return;
    struct sockaddr_in sin = {0};
    sin.sin_family = AF_INET;
    sin.sin_port = htons(listen_port);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    if ((connect(socket_desc,(const struct sockaddr*)&sin,sizeof(sin))== -1))
        return;
    close(socket_desc);
}