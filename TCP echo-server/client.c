#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define MAX 200;
int main(int argc,char* argv[])
{
int sfd,c,inp,n;
char buffer[MAX+1];
struct sockaddr_in ca;
sfd=socket(AF_INET,SOCK_STREAM,0);  // AF_INET is used for the internet type of network and SOCK_STREAM for TCP protocol.
if(sfd<0)
{
printf("socket error");
exit(-1);
}
ca.sin_family=AF_INET;
ca.sin_port=htons(atoi(argv[1]));
ca.sin_addr.s_addr=inet_addr("172.20.0.9");
c=connect(sfd,(struct sockaddr*)&ca,sizeof(ca));
if(c<0)
{
printf("connect error");
exit(-1);
}
printf("enter choice : ");
scanf("%d",&inp);
while(inp!=0)
{
write(1,"enter message to be sent :",30);
n=read(0,&buffer,sizeof(buffer));
send(sfd,&buffer,n,0);
n=recv(sfd,&buffer,MAX,0);
buffer[n]='\0';
write(1,"received from server :",30);
write(0,&buffer,n);
}
close(sfd);
return 0;
}
