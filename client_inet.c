#include<netinet/in.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/types.h>
int main(int argc,char *argv[])
{
	int c_fd;
	struct hostent *ptrh;
	c_fd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_port=htonl(5001);
	socklen_t size_addr;
	addr.sin_addr.s_addr=inet_addr(argv[1]);
	ptrh=gethostbyname("110.172.156.2");
	socklen_t size_addr;
	connect(c_fd,(struct sockaddr *)&addr,size_addr);
	char *msg="This is client";
	int len;
	len=strlen(msg);
	write(c_fd,msg,len+1);
	close(c_fd);
	exit(0);
}


