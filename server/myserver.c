#include "mylib.h"

int main(int argc,char **argv)
{
	int sock1,sock2,PORT,n=0;
	char buffer[MAXLINE+1];
	struct sockaddr_in svraddr;

	if(argc<2)
	{
		printf("plz provide <PORT Number>");
		exit(1);
	}

	bzero(&svraddr,sizeof(svraddr));

	sock1=Socket(AF_INET,SOCK_STREAM,0);

	PORT=atoi(argv[1]);

	svraddr.sin_family=AF_INET;
	svraddr.sin_addr.s_addr=htonl(INADDR_ANY);
	svraddr.sin_port=htons(PORT);

	Bind(sock1,(SA *)&svraddr,sizeof(svraddr));

	Listen(sock1,5);

	sock2=Accept(sock1,(SA *)NULL,NULL);


	pid_t F=fork();

	if(F==0)
	{
		while(1)
		{
			bzero(buffer,MAXLINE);

			n=Read(sock2,buffer,MAXLINE);

			if(n>1)
			printf("CLIENT: %s",buffer);

			n=0;
		}
	}
	else
	{
		while(1)
		{

			bzero(buffer,MAXLINE);

			fgets(buffer,MAXLINE,stdin);

			Write(sock2,buffer,strlen(buffer));
		}
	}

	Close(sock1);
	Close(sock2);
	return 0;
}