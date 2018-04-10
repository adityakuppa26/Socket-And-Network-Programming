#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
struct IPmac{
char mac[100];
char ip[100];
};
int main()
{
int sfd,i,len;
char ip[30],mac[30],temp[30];
struct sockaddr_in sa;
struct IPmac in[3]={{"172.20.0.8","44:dd:22:55:11"},{"172.20.0.3","33:ee:22:44:11"},{"123.23.12.32","33:fe:23:32:22"}};
sfd=socket(AF_INET,SOCK_DGRAM,0);
if(sfd<0)
{
printf("socket error");
exit(-1);
}
sa.sin_family=AF_INET;
sa.sin_port=htons(9999);
sa.sin_addr.s_addr=INADDR_ANY;
bind(sfd,(struct sockaddr*)&sa,sizeof(sa));
len=sizeof(sa);
recvfrom(sfd,ip,sizeof(ip),0,(struct sockaddr*)&sa,&len);
for(i=0;i<strlen(ip)-1;i++)
{
temp[i]=ip[i];
}
temp[i]='\0';
printf("ip address received : %s",temp);
for(i=0;i<3;i++)
{
if(strcmp(ip,in[i].ip)==0)
{
strcpy(mac,in[i].mac);
break;
}
}
printf("the mac addr is : %s",mac);
sendto(sfd,mac,sizeof(mac),0,(struct sockaddr*)&sa,len);

// rarp simulation

recvfrom(sfd,mac,sizeof(mac),0,(struct sockaddr*)&sa,&len);
printf("received mac addr : %s",mac);
for(i=0;i<strlen(mac)-1;i++)
{
temp[i]=mac[i];
}
for(i=0;i<3;i++)
{
if(strcmp(temp,in[i].mac)==0)
{
strcpy(ip,in[i].ip);
break;
}
}
printf("ip address is : %s",ip);
sendto(sfd,ip,sizeof(ip),0,(struct sockaddr*)&sa,len);
return 0;
}
