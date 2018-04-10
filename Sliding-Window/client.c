#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main(int argc,char* argv[])
{
int sfd,c,n,choice;
char str[100],err[100];
struct sockaddr_in sa;
sfd=socket(AF_INET,SOCK_STREAM,0);
if(sfd<0)
{
perror("socket error");
exit(-1);
}
sa.sin_family=AF_INET;
sa.sin_port=htons(atoi(argv[1]));
sa.sin_addr.s_addr=htonl(INADDR_ANY);
c=connect(sfd,(struct sockaddr*)&sa,sizeof(sa));
if(c<0)
{
perror("connect error");
exit(-1);
}
for(;;)
{
n=recv(sfd,&str,100,0);
if(!strncmp(str,"exit",4))
{
printf("exiting.....");
break;
}
printf("received message is : %s , Are there any errors ? (1-yes , 0-no) : ",str);
scanf("%d",&choice);
if(!choice)
write(sfd,"-1",sizeof("-1"));
else
{
printf("enter the error frame's sequence number :");
scanf("%s",err);
write(sfd,&err,sizeof(err));
n=read(sfd,&str,100);
str[n]='\0';
printf("received the re-transmitted frames : %s \n\n" , str);
}
}
close(sfd);
return 0;
}
