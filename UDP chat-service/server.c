#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define MAX 200;
int main(int argc,char* argv[])
{
int ssfd,b,len,n;
char buff[MAX+1];
struct sockaddr_in serv,client;
ssfd=socket(AF_INET,SOCK_DGRAM,0);
if(ssfd<0)
{
printf("socket error");
exit(1);
}
serv.sin_family=AF_INET;
serv.sin_port=htons(atoi(argv[1]));
serv.sin_addr.s_addr=inet_addr("172.20.0.9");
b=bind(ssfd,(struct sockaddr*)&serv,sizeof(serv));
if(b<0)
{
printf("bind error");
exit(-1);
}
len=sizeof(client);
while(1)
{
n=recvfrom(ssfd,&buff,MAX,0,(struct sockaddr*)&client,&len);
printf("message from client : %s ",buff);
printf("enter message to send :");
fgets(buff,1024,stdin);
sendto(ssfd,&buff,n,0,(struct sockaddr*)&client,len);
}
close(ssfd);
return 0;
}
