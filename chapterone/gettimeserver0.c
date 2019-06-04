#include "../include/upn.h"

int main(int argc, char **argv)
{
	int sockfd, acceptfd;
	char buff[MAXLINE + 1] = {0};
	struct sockaddr_in servaddr;
	time_t ticks;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		printf("socket error\n");
		exit(-1);
	}
	
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(6666);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
	{
		printf("bind error %s (errno %d)\n",strerror(errno),errno);
		exit(-1);
	}

	if(listen(sockfd, 10) < 0)
	{
		printf("listen error\n");
		exit(-1);
	}

	while(1)
	{
		if((acceptfd = accept(sockfd, (struct sockaddr *)NULL, NULL)) < 0)
		{
			continue;
		}
		
		ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        write(acceptfd, buff, strlen(buff));

		close(acceptfd);
	}
	exit(0);
}
