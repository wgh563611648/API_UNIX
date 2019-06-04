#include "../include/upn.h"

int main(int argc, char **argv)
{
	int sockfd,n;
	char recvline[MAXLINE + 1] = {0};
	struct sockaddr_in servaddr;
	
	if(argc < 2)
		printf("few\n");

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		printf("creat socket error\n");
		exit(-1);
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(6666);
	if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
	{
		printf("inet_pton error\n");
		exit(-1);
	}

	if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(struct sockaddr)))
	{
		printf("connect error\n");
		exit(-1);
	}

	while((n = read(sockfd, recvline, MAXLINE)) > 0)
	{
		recvline[n] = 0;
		printf("recvline=%s\n",recvline);
	}
	if(n < 0)
		printf("read error");
	close(sockfd);
	return 0;
}
