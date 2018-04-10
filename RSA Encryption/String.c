#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long int m[100],n,e[100],d[100],p,q,t,flag,temp[100],en[100]i,j;
char msg[100];
long int prime(long int);
void ce();
void encrypt();
void decrypt();
long int cd(long int);
int main()
{
printf("enter the first prime number :");
scanf("%ld",&p);
flag=prime(p);
if(flag==0)
{
printf("\n wrong input \n ");
exit(1);
}
printf("\n enter second prime number:");
scanf("%ld",&q);
flag=prime(q);
if(flag==0||p==q)
{
printf("\n wrong input");
exit(-1);
}
printf("\n enter the message:");
scanf("%s",msg);
for(i=0;msg[i]!=NULL;i++)
{
m[i]=msg[i];
}
n=p*q;
t=(p-1)*(q-1);
ce();
printf("\n the possible values of e and d are :");
for(i=0;i<j-1;i++)
{
if((e[i]!=0) && (d[i]!=0))
printf("\n %ld,%ld ",e[i],d[i]);
}
encrypt();
decrypt();
return 0;
}

// prime()

long int prime(long int pr)
{
int i;
j=pr;
for(i=2;i<j;i++)
{
if(pr%i==0)
return 0;
}
return 1;
}

// ce()

void ce()
{
int k;
k=0;
for(i=2;i<t;i++)
{
if(t%i==0)
continue;
flag=prime(i);
if(flag==1 && i!=p && i!=q)
{
e[k]=i;
flag=cd(e[k]);
if(flag>0)
{
d[k]=flag;
k++;
}
if(k==99(
break;
}
}
}

// cd()

long int cd(long int x)
{
long int k;
k=1;
while(1)
{
k=k+t;
if(k%x==0)
return (k/x);
}
}

// encrypt()

void encrypt()
{
long int key=e[0],k,len,i;,pt,ct
i=0;
len=strlen(msg);
while(i!=len)
{
pt=m[i];
pt=pt-96;
k=1;
for(j=0;j<key;j++)
{
k=k*pt;
k=k%n;
}
temp[i]=k;
ct=k+96;
en[i]=ct;
i++;
}
en[i]=-1;
printf(" the encrypted string is:");
for(j=0;en[j]!=-1;j++)
{
printf("%c",en[j]);
}
}

// decrypt()

void decrypt()
{
long int ct,pt,key=d[0],k;
i=0;
while(en[i]!=-1)
{
ct=temp[i];
k=1;
for(j=0;j<key;j++)
{
k=k*ct;
k=k%n;
}
pt=k+96;
m[i]=pt;
i++;
}
m[i]=-1;
printf("the decrypted message is :);
for(i=0;m[i]!=-1;i++)
{
printf("%c",m[i]);
}
}
