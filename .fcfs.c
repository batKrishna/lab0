#include<stdio.h>
 
 struct process{
 int at, pid  ,bt , ct , tat , wt ;
 };
 void main(){
struct process p[20],k;
int i,j,n,sum=0;
float tot_tat=0,tot_wt=0;
printf("enter no.of processes:\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{

printf("enter id at bt of process %d ",i+1 );
scanf("%d%d%d",&p[i].pid,&p[i].at,&p[i].bt);
}
for(i=0;i<n;i++)
{
for(j=0;j<n-1-i;j++)
{
if(p[j].at>p[j+1].at)
{
k=p[j];
p[j]=p[j+1];
p[j+1]=k;
}
}
}
printf("\n ");
printf("\ngantt chart\n");
printf("\n ");
printf("\n--------------------------------------------------");
printf("\n ");
for(i=0;i<n;i++)
{if(sum<p[i].at)
{
sum=p[i].at;
printf("\t|");
i--;
}
else
{
sum=sum+p[i].bt;
p[i].ct=sum;
printf("\tp%d| ",p[i].pid);
}
}
printf("\n");
printf("0");
if(p[0].at!=0)
{
printf("\t%d ",p[0].at);
}
for(i=0;i<n;i++)
{
printf("\t%d ",p[i].ct);
}
printf("\n--------------------------------------------------");
for(i=0;i<n;i++)
{
printf("\n");
}
for(i=0;i<n;i++)
{
p[i].tat=p[i].ct-p[i].at;
p[i].wt=p[i].tat-p[i].bt;
}
printf("pid\tat\tbt\tct\ttat\twt\n");
for(i=0;i<n;i++)
{
tot_tat=tot_tat+p[i].tat;
tot_wt=tot_wt+p[i].wt;
printf("\nP%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
}
printf("\ntotal tat= %f",tot_tat);
printf("\ntotal wt= %f",tot_wt);
printf("\naverage tat= %f",tot_tat/n);
printf("\naverage wt= %f",tot_wt/n);
}
