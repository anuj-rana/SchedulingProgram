#include<stdio.h>  
  
int main()  
{  
    /* 
        n:      Total Number Of Processes 
        t:      Time 
        r:      Remaining 
        tq:     Time Quantum 
        wt:     Waiting Time 
        tat:    Turnaround Time 
        at:     Arriving Time 
        bt:     Burst Time 
        rt:     Running Time 
    */  
      
    int count, j, n, t, r;  
    int flag = 0, tq = 10, wt = 0, tat = 0, at[10], bt[10], rt[10];  
      
    printf("Enter the Total number of Process: ");  
    scanf("%d", &n);  
      
    r = n;  
      
    for(count = 0; count < n; count++){  
        printf("Enter Arrival Time and Burst Time for process number %d : ", count+1);  
        scanf("%d", &at[count]);  
        scanf("%d", &bt[count]);  
          
        rt[count] = bt[count];  
    }  
      
    printf("Enter Time Quantum: %d\n", tq);  
      
    printf("Process\t| Turnaround Time | Waiting Time\n");  
      
    for(t = 0, count = 0; r != 0; ){  
        if(rt[count] <= tq && rt[count] > 0){  
            t += rt[count];  
            rt[count] = 0;  
            flag = 1;  
        }  
        else if(rt[count] > 0){  
            rt[count] -= tq;  
            t += tq;  
        }  
          
        if(rt[count] == 0 && flag == 1){  
            r--;  
            printf("P[%d]\t|\t%d\t|\t%d\n", (count+1), (t - at[count]), (t - (at[count] - bt[count])));  
              
            wt += (t - at[count] - bt[count]);  
              
            tat += (t - at[count]);  
              
            flag = 0;  
              
            count++;  
        }  
          
        if(count == n-1){  
            count = 0;  
        }  
        else if(at[count+1] <= t){  
            count++;  
        }  
        else{  
            count = 0;  
        }  
    }  
      
    printf("Average Waiting Time= %f\n", (wt*1.0/n));  
      
    printf("Average Turnaround Time = %f", (tat*1.0/n));  
   
    return 0;  
