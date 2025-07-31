 #include<stdio.h>
 void main() {
    int rt[10],bt[10],wt[10],tat[10],n,tq;
    int i,count=0,sum_wt=0,sum_tat=0,temp,sq=0;
    float awt,atat;
    printf("enter the number of processes:\n");
    scanf("%d",&n);
    printf("\nenter the burst time of each process:\n");
    for(i=0;i<n;i++) {
        printf("\nP%d:",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    printf("\nenter the time quantum:");
    scanf("%d",&tq);
    while(1){
        for(i=0,count=0;i<n;i++){
            temp=tq;
            if(rt[i]==0) {
                count++;
                continue;
            }
            if(rt[i]>tq)
                rt[i]=rt[i]-tq;
            else
                if(rt[i]>=0) {
                    temp=rt[i];
                    rt[i]=0;
                }
            sq=sq+temp;
            tat[i]=sq;
        }
        if(n==count)
        break;
    }
    for(i=0;i<n;i++) {
        wt[i]=tat[i]-bt[i];
        sum_wt+=wt[i];
        sum_tat+=tat[i];
    }
    awt=(float)sum_wt/n;
    atat=(float)sum_tat/n;
    printf("\n P_ID\tBT\t WT\t TAT\n");
    for(i=0;i<n;i++)
        printf("\n%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
    printf("\nAverage Waiting Time = %f",awt);
    printf("\nAverage Turn Around Time = %f",atat);
}
