#include<stdio.h>
#include<conio.h>
void main()
{
 int at[30],pr[10],bt[10],tc[30],tat[30],wt[30],i,j,t2,c,c1,n,temp2;
 int temp1[10],temp[10],smallest, count = 0, time,time1,count1=0;
 int x,total=0;
 double wait_time = 0, turnaround_time = 0, end;
 double wait_time1 = 0, turnaround_time1 = 0;
 float t_wt,t_tat,avg_wt,avg_tat;
 float t_wt1,t_tat1,avg_wt1,avg_tat1,avg_wt2,avg_tat2,avg_wt3,avg_tat3;
 clrscr();
 scheduling:
 printf("\n Enter 1)FCFS 2)SJF 3)RR 4)PRIORITY");
 printf("\nEnter your choice:");
 scanf("%d",&c);
 switch(c)
 {
 case 1:
 printf("Enter the number of processes:");
 scanf("%d",&n);
 printf("\nEnter Details of %d Processes\n",n);
      for(i = 0; i < n; i++)
      {
	    printf("\nEnter Arrival Time:\t");
	    scanf("%d", &at[i]);
	    printf("Enter Burst Time:\t");
	    scanf("%d", &bt[i]);
      }
 tc[0]=bt[0]-at[0];
 for(i=1;i<n;i++)
    tc[i]=bt[i]+tc[i-1];
 for(i=0;i<n;i++)
    tat[i]=tc[i]-at[i];
 for(i=0;i<n;i++)
    wt[i]=tat[i]-bt[i];
 for(i=0;i<n;i++)
 {
  t_wt=t_wt+wt[i];
  t_tat=t_tat+tat[i];
  }
 avg_wt=t_wt/n;
 avg_tat=t_tat/n;
 printf("\nAverage Waiting Time:%f ms",avg_wt);
 printf("\nAverage TurnAround Time:%f ms",avg_tat);
 break;;
 case 2:
      printf("\nEnter the Total Number of Processes:\t");
      scanf("%d", &n);
      printf("\nEnter Details of %d Processes\n",n);
      for(i = 0; i < n; i++)
      {
	    printf("\nEnter Arrival Time:\t");
	    scanf("%d", &at[i]);
	    printf("Enter Burst Time:\t");
	    scanf("%d", &bt[i]);
	    temp[i] = bt[i];
      }
      bt[9] = 9999;
      for(time = 0; count != n; time++)
      {
	    smallest = 9;
	    for(i = 0; i < n; i++)
	    {
		  if(at[i] <= time && bt[i] < bt[smallest] && bt[i] > 0)
		  {
			smallest = i;
		  }
	    }
	    bt[smallest]--;
	    if(bt[smallest] == 0)
	    {
		  count++;
		  end = time + 1;
		  wait_time = wait_time + end - at[smallest] - temp[smallest];
		  turnaround_time = turnaround_time + end - at[smallest];
	    }
      }
      avg_wt1 = wait_time / n;
      avg_tat1= turnaround_time / n;
      printf("\n\nAverage Waiting Time:\t%lf\n", avg_wt1);
      printf("Average Turnaround Time:\t%lf\n", avg_tat1);
      break;;
  case 3:
      printf("\nEnter Total Number of Processes:\t");
      scanf("%d", &n);
      x = n;
      for(i = 0; i < n; i++)
	{
	    printf("\nEnter Arrival Time:");
	    scanf("%d", &at[i]);
	    printf("Enter Burst Time:");
	    scanf("%d", &bt[i]);
	    temp1[i] = bt[i];
      }
      printf("\nEnter Time Quantum:\t");
      scanf("%d", &time1);
      for(total = 0, i = 0; x != 0;)
      {
	    if(temp1[i] <= time1&& temp1[i] > 0)
	    {
		  total = total + temp1[i];
		  temp1[i] = 0;
		  count1 = 1;
	    }
	    else if(temp1[i] > 0)
	    {
		  temp1[i] = temp1[i] - time1;
		  total = total + time1;
	    }
	    if(temp1[i] == 0 && count1 == 1)
	    {
		  x--;
		  wait_time1 = wait_time1 + total - at[i] - bt[i];
		  turnaround_time1 = turnaround_time1 + total - at[i];
		  count1 = 0;
	    }
	    if(i == n - 1)
	    {
		  i = 0;
	    }
	    else if(at[i + 1] <= total)
	    {
		  i++;
	    }
	    else
	    {
		  i = 0;
	    }
      }
      avg_wt2 = wait_time1 * 1.0 / n;
      avg_tat2 = turnaround_time1 * 1.0 / n;
      printf("\n\nAverage Waiting Time:\t%f", avg_wt2);
      printf("\nAvg Turnaround Time:\t%f\n", avg_tat2);
      break;;
  case 4: printf("Enter the number of processes:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
    printf("\n Enter the burst time:");
    scanf("%d",&bt[i]);
    printf("Enter the priority:");
    scanf("%d",&pr[i]);
    }
 for(i=0;i<n-1;i++)
 {
  for(j=0;j<n-i-1;j++)
  {
   if(pr[j]>pr[j+1])
   {
   temp2=pr[j];
   pr[j]=pr[j+1];
   pr[j+1]=temp2;
   t2=bt[j];
   bt[j]=bt[j+1];
   bt[j+1]=t2;
   }
   }
   }
  wt[0]=0;
 for(i=1;i<n;i++)
    wt[i]=wt[i-1]+bt[i-1];
 for(i=0;i<n;i++)
    tat[i]=bt[i]+wt[i];
 for(i=0;i<n;i++)
 {
  t_wt1=t_wt1+wt[i];
  t_tat1=t_tat1+tat[i];
  }
 avg_wt3=t_wt1/n;
 avg_tat3=t_tat1/n;
 printf("\nAverage Waiting Time:%f ms",avg_wt3);
 printf("\nAverage TurnAround Time:%f ms",avg_tat3);
 break;;
  default:printf("Invalid Choice");
  break;;
  }
  printf("\nEnter 1)To Continue 2)To stop");
  scanf("%d",&c1);
  if(c1==1)
     goto scheduling;
  else
     printf("Thank You");
  getch();
}
