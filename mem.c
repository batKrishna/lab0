#include<stdio.h>
void firstFit(int bsize[], int m, int psize[], int n)
{
    int i, j;
    int allocation[n],blocksize[100];
    for(i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
      for(int i = 0; i < m; i++){
     blocksize[i] = bsize[i];
    }
    for (i = 0; i < n; i++)        
    {
        for (j = 0; j < m; j++)        
        {
            if (blocksize[j] >= psize[i])
            {
               
                allocation[i] =j;
                blocksize[j] -=psize[i];
                break;    
            }
        }
    }
    printf("\nProcess No.\tProcess Size\t\t\t\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %i\t\t\t", i+1);
        printf("%i\t\t\t\t", psize[i]);
        if (allocation[i] != -1)
            printf("%i", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}

void BestFit(int bsize[], int blocks, int psize[], int proccesses)
{
    int allocation[proccesses];
    int occupied[blocks];
    for(int i = 0; i < proccesses; i++){
        allocation[i] = -1;
    }
   
    for(int i = 0; i < blocks; i++){
        occupied[i] = 0;
    }
    for (int i = 0; i < proccesses; i++)
    {
       
        int indexPlaced = -1;
        for (int j = 0; j < blocks; j++) {
            if (bsize[j] >= psize[i] && !occupied[j])
            {
               
                if (indexPlaced == -1)
                    indexPlaced = j;
                else if (bsize[j] < bsize[indexPlaced])
                    indexPlaced = j;
            }
        }
        if (indexPlaced != -1)
        {
            allocation[i] = indexPlaced;
            occupied[indexPlaced] = 1;
        }
    }
 
    printf("\nProcess No.\tProcess Size\t\t\t\tBlock no.\n");
    for (int i = 0; i < proccesses; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, psize[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}


void WorstFit(int bsize[], int blocks, int psize[], int processes)
{
   
    int allocation[processes];
    int occupied[blocks];
    for(int i = 0; i < processes; i++){
        allocation[i] = -1;
    }
   
    for(int i = 0; i < blocks; i++){
        occupied[i] = 0;
    }
    for (int i=0; i < processes; i++)
    {
int indexPlaced = -1;
for(int j = 0; j < blocks; j++)
{
   if(bsize[j] >= psize[i] && !occupied[j])
            {
                if (indexPlaced == -1)
                    indexPlaced = j;
                else if (bsize[indexPlaced] < bsize[j])
                    indexPlaced = j;
            }
        }
 
       
        if (indexPlaced != -1)
        {
           
            allocation[i] = indexPlaced;
            occupied[indexPlaced] = 1;
            bsize[indexPlaced] -= psize[i];
        }
    }
 
    printf("\nProcess No.\tProcess Size\t\t\t\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, psize[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
void main()
{
    int m,n,i,ch=0;    
      int bsize[100], psize[100] ;
  printf("Enter the number of blocks:");
  scanf("%d",&m);
  printf("Enter the number of processes:");
  scanf("%d",&n);

  for(i=0;i<m;i++)
  {  printf("Enter the size of blocks %d :",i+1);
  scanf("%d",&bsize[i]);
  }
  
  for(i=0;i<n;i++)
  {printf("Enter the size of processes %d :",i+1);
  scanf("%d",&psize[i]);
  }
  while(ch<=3)
  { printf("\n"); 
   printf("chose an option ");
    printf("\n1.Firstfit\t\t2.bestfit\t\t3.worstfit\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1: firstFit(bsize, m, psize, n);
    break;
    case 2: BestFit(bsize, m, psize, n);
    break;
    case 3: WorstFit(bsize, m, psize, n);
    break;
    }
   }
 
}
