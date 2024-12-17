#include<stdio.h>
#include<stdlib.h>
struct process{
  int id,at,bt,ct,tat,wt,st,pt;
}p[20],temp;
void main(){
 int n,i=0,j=0,completed=0,currtime=0;
 float ttat=0,twt=0,avtat=0,avwt=0; 
 printf("Enter the no of process\n");
 scanf("%d",&n);
 for(i=0;i<n;i++){
  printf("Enter the arrival time,burst time and priority of process\n");
  scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].pt);
  p[i].id=i+1;
  p[i].st=0;
 }
 while(completed<n){
  int minprio=12345;
  int index=-1;
  for(i=0;i<n;i++){
  if(p[i].at<=currtime && p[i].st==0){
    if(minprio>p[i].pt){
      minprio=p[i].pt;
      index=i;
    }
  }}  
  if(index==-1){
  currtime++;
  }
  else{
    currtime=currtime+p[index].bt;
    p[index].ct=currtime;
    p[index].st=1;
    completed++;
  }
 }
 for(i=0;i<n;i++){
  p[i].tat=p[i].ct-p[i].at;
  p[i].wt=p[i].tat-p[i].bt;
  ttat+=p[i].tat;
  twt+=p[i].wt;
 }
 avtat=ttat/n;
 avwt=twt/n;

 printf("Process details are\n");
 printf("ID\tAT\tBT\tPT\tCT\tTAT\tWT\n");
 for(i=0;i<n;i++){
   printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].pt,p[i].ct,p[i].tat,p[i].wt);
 }
 for(i=0;i<n;i++){
  for(j=0;j<n-1-i;j++){
    if(p[j].ct>p[j+1].ct){
      temp=p[j];
      p[j]=p[j+1];
      p[j+1]=temp;
    }
  }
 } 
  printf("\n");
 printf("\n GANTT CHART\n");
  printf("\n --------------------------------------------------------\n");
 for(i=0;i<n;i++){
  printf("|p%d\t",p[i].id);
 }
 printf("|");
 printf("\n");
 printf("%d\t",p[0].at);
 for(i=0;i<n;i++){
  printf("%d\t",p[i].ct);
 }
   printf("\n --------------------------------------------------------\n");
 printf("\nTotat turnaround time is %f\n",ttat);
 printf("Average turnaround time is %f\n",avtat);
 printf("Totat waiting time is %f\n",twt);
 printf("Average waiting time is %f\n",avwt);
 
}
 
 
