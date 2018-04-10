#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define N 6;
#define IN 99;
int dijkstra(int cost[][N],int source,int target);
int main()
{
int cost[N][N],i,j,x,y,w,co,source,target;
for(i=1;i<N;i++)
{
for(j=1;j<N;j++)
cost[i][j]=IN;
}
}
for(x=1;x<N;x++)
{
for(y=x+1;y<N;y++)
{
printf("enter the cost of the edge from %d to %d ",x,y);
scanf("%d",&w);
cost[x][y]=w;
cost[y][x]=w;
}
}
printf("\n enter the source :");
scanf("%d",&source);
printf("\n enter the target:");
scanf("%d",&target);
co=dijkstra(cost,source,target);
printf(" the shortest path : %d ",co);
return 0;
}
int dijkstra(int cost[][N],int source,int target)
{
int prev[N],dist[N],selected[N]={0},m,min,i,start,j,d;
char path[N];
for(i=1;i<N;i++)
{
dist[i]=IN;
prev[i]=-1;
}
start = source;
selected[start]=1;
dist[start]=0;
while(selected[target]==0)
{
min=IN;
m=0;
for(i=1;i<N;i++)
{
d=dist[i]+cost[start][i];
if(d<dist[i] && selected[i]==0)
{
dist[i]=d;
prev[i]=start;
}
if(min>dist[i] && selected[i]==0)
{
min=dist[i];
m=i;
}
}
start=m;
selected[start]=1;
}
start=target;
j=0;
while(start != -1)
{
path[j++]=start+65;
start=prev[start];
}
path[j]='\0';
printf(" Shortest path : %s",strrev(path));
return dist[target];
}
