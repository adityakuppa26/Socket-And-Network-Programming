#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define MAX 200;
int main(int argc,char* argv[])
{
int ssfd,b,l,newsfd,len,n,i;
char buff[MAX+1];
struct sockaddr_in sa,client;
ssfd=socket(AF_INET,SOCK_STREAM,0);
if(sa<0)
{
printf("socket error");
exit(1);
}
sa.sin_family=AF_INET;
sa.sin_port=htons(atoi(argv[1]));
sa.sin_addr.s_addr=inet_addr("172.20.0.9");
b=bind(ssfd,(struct sockaddr*)&sa,sizeof(sa));
if(b<0)
{
printf("bind error");
exit(-1);
}
l=listen(ssfd,5);
if(l<0)
{
printf("listen error");
exit(-1);
}
printf("server is ready...");
newsfd=accept(ssfd,(struct sockaddr*)&client,&len);
if(newsfd<0)
{
printf("accept error");
exit(-1);
}
printf("client connected ... ");
n=recv(newsfd,&buff,MAX,0);
buff[n]='\0';
printf("message from client : %s ",buff);
for(i=0;buff[i]!='\0';i++)
{
buff[i]=toupper(buff[i]);
}
send(newsfd,&buff,n,0);
close(sfd);
close(newsfd);
return 0;
}
