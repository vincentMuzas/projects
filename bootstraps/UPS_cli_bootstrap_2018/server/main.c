#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */
#include <stdio.h>
#define closesocket(s) close(s)
 
int main()
{
    int socket_desc;
    struct sockaddr_in server = { 0 };
    char *message , server_reply[2000];
     
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
		return (1);
    }
	printf("socket_desc: %d\n", socket_desc);

	server.sin_family = AF_INET;
	server.sin_port = htons(4242);
	server.sin_addr.s_addr = htonl(INADDR_ANY);

	if (0 > bind(socket_desc, (struct sockaddr *) &server, sizeof(server))) {
		printf("that's not how bind work!\n");
		return (1);
	}
	printf("bind: ok\n");

	if (listen(socket_desc, 10) < 0) {
		printf("that's not how listen work!\n");
		return (1);
	}
	printf("listen: ok\n");

	int to_read = accept(socket_desc, (struct sockaddr *) &server, sizeof(server));
	printf("%d\n", to_read);
    return 0;
}