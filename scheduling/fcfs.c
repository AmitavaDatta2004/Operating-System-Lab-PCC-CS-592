#include<stdio.h>

int main(){
    int n,i,j;
    printf("Enter the no of process:");
    scanf("%d",&n);
    int pid[n],at[n],bt[n],ct[n],tat[n],wt[n];

    for(i=0;i<n;i++){
        pid[i]=i+1;
        printf("Enter the arrival time of process %d :",pid[i]);
        scanf("%d",&at[i]);
        printf("Enter the burst time of process %d :",pid[i]);
        scanf("%d",&bt[i]);
    }

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(at[i]>at[j]){
                int temp=at[i];at[i]=at[j];at[j]=temp;
                temp=bt[i];bt[i]=bt[j];bt[j]=temp;
                temp=pid[i];pid[i]=pid[j];pid[j]=temp;
            }
        }
    }

    ct[0]=at[0]+bt[0];
    for(i=1;i<n;i++){
        if(at[i]>ct[i-1]){
            ct[i]=at[i]+bt[i];
        } else {
            ct[i]=ct[i-1]+bt[i];
        }
    }

    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    
    int sumWt=0;
    int sumTat=0;
    for(i=0;i<n;i++){
        sumTat += tat[i];
        sumWt += wt[i];
    }
    float avgWt=sumWt/n;
    float avgTat=sumTat/n;

    printf("Average WT=%f\nAverage TAT=%f\n",avgWt,avgTat);
    return 0;
}