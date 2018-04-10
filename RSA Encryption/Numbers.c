#include<stdio.h>
#include<stdlib.h>
int M,n,e,d,C,phi,FLAG;
int check()
{
int i;
for(i=3;e%i==0&&phi%i==0;i+2)
{
FLAG=1;
return;
}
FLAG=0;
}
void encrypt()
{
int i;
for(i=0;i<e;i++)
C=C*M%n;
C=C%n;
printf("encrypted keyword:%d",C);
}
void decrypt()
{
int i;
for(i=0;i<d;i++)
M=M*C%n;
M=M%n;
printf("decrypted keyword:%d",M);
}
int main()
{
int p,q,s;
printf("enter two primes p and q:");
scanf("%d%d",&p,&q);
n=p*q;
phi=(p-1)*(q-1);
do
{
printf("enter a relative prime number e less than phi");
scanf("%d",&e);
check();
}while(FLAG==1);
d=1;
do
{
s=(e*d)%phi;
d=d+1;
}while(s!=1);
d=d-1;
printf("\n public key : { %d,%d}",e,n);
printf("\n private key : {%d,%d}",d,n);
printf("\n enter plain text :");
scanf("%d",&M);
encrypt();
printf("\n enter ciphered text :");
scanf("%d",&C);
decrypt();
return 0;
}
