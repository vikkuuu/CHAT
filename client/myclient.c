#include "mylib.h"

int main(int argc,char **argv)
{
	int sock,PORT,n=0;
	char buffer[MAXLINE+1];
	struct sockaddr_in svraddr;

	if(argc<3)
	{
		printf("plz provide <IP Address> and <PORT Number>");
		exit(1);
	}

	bzero(&svraddr,sizeof(svraddr));

	sock=Socket(AF_INET,SOCK_STREAM,0);

	PORT=atoi(argv[2]);

	svraddr.sin_family=AF_INET;
	svraddr.sin_port=htons(PORT);

	Inet_pton(AF_INET,argv[1],&svraddr.sin_addr);

	Connect(sock,(SA *)&svraddr,sizeof(svraddr));


	pid_t F=fork();
	
	if(F==0)
	{
		while(1)
		{
			bzero(buffer,MAXLINE);

			fgets(buffer,MAXLINE,stdin);

			Write(sock,buffer,strlen(buffer));
		}
	}
	else
	{
		while(1)
		{
			bzero(buffer,MAXLINE);

			n=Recv(sock,buffer,MAXLINE,0);
			
			if(n>1)
				printf("SERVER: %s",buffer);

			n=0;
		}
	}

	Close(sock);

return 0;
}