#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
int main()
{
int csfd,len;
char ip[100],mac[100];
struct sockaddr_in ca;
csfd=socket(AF_INET,SOCK_DGRAM,0);
if(csfd<0)
{
printf("socket error");
exit(-1);
}
ca.sin_family=AF_INET;
ca.sin_port=htons(9999);
ca.sin_addr.s_addr=INADDR_ANY;

// arp simulation

printf("enter ip address :");
fgets(ip,sizeof(ip),stdin);
len=sizeof(ca);
sendto(csfd,ip,sizeof(ip),0,(struct sockaddr*)&ca,len);
recvfrom(csfd,mac,sizeof(mac),0,(struct sockaddr*)&ca,&len);
printf("received mac addr : %s",mac);

// RARP simulation

printf("enter mac address:");
fgets(mac,sizeof(mac),stdin);
sendto(csfd,mac,sizeof(mac),0,(struct sockaddr*)&ca,len);
recvfrom(csfd,ip,sizeof(ip),0,(struct sockaddr*)&ca,&len);
printf("received ip address : %s",ip);
close(csfd);
return 0;
}
