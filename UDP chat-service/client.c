#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define MAX 200;
int main(int argc,char* argv[])
{
int sfd,b,n;
char buff[MAX+1];
struct sockaddr_in sa,ca;
sfd=socket(AF_INET,SOCK_DGRAM,0); // SOCK_DGRAM is used for UDP protocol
if(sfd<0)
{
printf("socket error");
exit(1);
}
sa.sin_family=AF_INET;
sa.sin_port=htons(atoi(argv[1]));
sa.sin_addr.s_addr=inet_addr("172.20.0.9");
memset(sa.sin_zero,'\0',sizeof(sa.sin_zero));
ca.sin_family=AF_INET;
ca.sin_port=0; // port number is automatically assigned
ca.sin_addr.s_addr=htonl(INADDR_ANY);
memset(ca.sin_zero,'\0',sizeof(ca.sin_zero));
b=bind(sfd,(struct sockaddr*)&ca,sizeof(ca));
if(b<0)
{
printf("bind error");
exit(1);
}
inr addr_len=sizeof(sa);
while(1)
{
write(1,"enter client message:",25);
fgets(buff,1024,stdin);
sendto(sfd,&buff,1024,0,(struct sockaddr*)&sa,addr_len);
n=recvfrom(sfd,&buff,MAX,0,(struct sockaddr*)&sa,&addr_len);
buff[n]='\0';
printf("received from server : %s",buff);
}
close(sfd);
return 0;
}
