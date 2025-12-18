#include <stdio.h>

int main(){
    int n;
    int at[10],bt[10];
    int ct[10],tat[10],wt[10];
    int p[10];
    int i,j,temp;

    printf("Enter the no of processes:");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        p[i]=i+1;
        printf("Enter arrival time and burst time of process %d -->\n",p[i]);
        scanf("%d%d",&at[i],&bt[i]);
    }

    for(i=0;i<n-1;i++){
        for(j=1;j<n;j++){
            if(bt[i]>bt[j]){
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;

                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }

    ct[0]=at[0]+bt[0];
    for(i=1;i<n;i++){
        if(at[i]>ct[i-i]){
            ct[i]=at[i]+bt[i];
        } else {
            ct[i]=ct[i-1]+bt[i];
        }
    }
    int total_tat=0,total_wt=0;
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        total_tat=total_tat+tat[i];
        total_wt=total_wt+wt[i];
    }

    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("Avg tat = %d\n",total_tat/n);
    printf("Avg bt = %d\n",total_wt/n);

}