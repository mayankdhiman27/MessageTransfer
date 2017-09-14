#include<netinet/in.h>
#include<sys/socket.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/types.h>
int main(int argc,char * argv[]){
	int s_fd;
	s_fd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_port=htonl(5001);
	socklen_t size_addr;
	addr.sin_addr.s_addr=inet_addr(argv[1]);
	bind(s_fd,(struct sockaddr *)&addr,size_addr);
	listen(s_fd,5);
	struct sockaddr_in caddr;
	socklen_t size_caddr;
	int c_fd;
	c_fd=accept(s_fd,(struct sockaddr *)&addr,&size_addr);
	char ch;
	char msg[100];
	int i=0,count=1;
	while(count){
		count=read(c_fd,&ch,1);
		msg[i]=ch;
		i++;

	}
	printf("%s\n",msg );
	close(s_fd);
	exit(0);
}
