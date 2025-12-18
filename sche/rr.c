#include <stdio.h>

int main(){
    int n,qt;
    int at[10],bt[10];
    int ct[10],tat[10],wt[10],rt[10];
    int p[10];
    int i,j,temp;
    int count=0,time=0;

    printf("ENter the quantum time:");
    scanf("%d",&qt);

    printf("Enter the no of processes:");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        p[i]=i+1;
        printf("Enter arrival time and burst time of process %d -->\n",p[i]);
        scanf("%d%d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    while(count<n){
        int executed=0;

        for(i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0){
                executed=1;

                if(rt[i]>qt){
                    rt[i]=rt[i]-qt;
                    time=time+qt;
                } else {
                    time = time+rt[i];
                    rt[i]=0;
                    ct[i]=time;
                    count++;

                }
            }
        }
        if(executed==0)time++;
    }

    // ct[0]=at[0]+bt[0];
    // for(i=1;i<n;i++){
    //     if(at[i]>ct[i-i]){
    //         ct[i]=at[i]+bt[i];
    //     } else {
    //         ct[i]=ct[i-1]+bt[i];
    //     }
    // }
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