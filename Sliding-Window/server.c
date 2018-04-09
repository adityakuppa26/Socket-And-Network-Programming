#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define SIZE 4;
int main(int argc,char* argv[])
{
int sfd,b,l,nsfd,len,length,i,status,j;
char str[100],frame[100],ack[20],temp[100];
struct sockaddr_in sa,ca;
sfd=socket(AF_INET,SOCK_STREAM,0);
if(sfd<0)
{
perror("bind error");
exit(-1);
}
sa.sin_family=AF_INET;
sa.sin_port=htons(atoi(argv[1]));
sa.sin_addr.s_addr=htonl(INADDR_ANY);
b=bind(sfd,(struct sockaddr*)&sa,sizeof(sa));
if(b<0)
{
perror("bind error");
exit(1);
}
l=listen(sfd,5);
if(l<0)
{
perror("listen error");
exit(1);
}
len=sizeof(ca);
nsfd=accept(sfd,(struct sockaddr*)&ca,&len);
printf("enter string:");
scanf("%s",str);
i=0;
while(i<strlen(str))
{
memset(frame,0,100);
strncpy(frame,str+i,SIZE);
write(1,"transmitting frames",20);
length=strlen(frame);
for(j=0;j<length;j++)
{
printf("%d",i+j);
sprintf(temp,"%d",i+j);
strcat(frame,temp);
}
write(nsfd,&frame,sizeof(frame));
read(nsfd,ack,20);
sscanf(ack,"%d",&status);
if(status==-1)
printf("transmitted successfully...");
else
{
printf("\n received error in frame : %d",status);
printf("\n retransmitting frames \n");
for(j=0;;)
{
frame[j]=str[j+status];
printf("%d",j+status);
j++;
if((j+status)%4==0)
break;
}
frame[j]='\0';
length=strlen(frame);
for(j=0;j<length;j++)
{
sprintf(temp,"%d",j+status);
strcat(frame,temp);
}
write(nsfd,&frame,sizeof(frame));

}
i+=SIZE;
}
write(nsfd,"exit",sizeof("exit"));
printf("exiting...");
close(sfd);
close(nsfd);
return 0;
}
