#include<stdio.h>
#include<limits.h>

struct process{
    int at, pid, bt, tat, wt, ct, rt;
};

int main(){
    int n,s=-1, min_rt=INT_MAX, completed=0,time=0;
    int gantt[100];

    printf("Enter number of processes");
    scanf("%d",&n);
    stuct process p[n];

    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("Enter at and bt of process %d:", i+1);
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].rt=p[i].bt;
    }
    while(completed!=n){
        s=-1;
        min_rt=int-max;
        for(int i=0;i<n;i++){
            if(p[i].at<=time && p[i].rt>0 && p[i].rt<min_rt){
                s=i;
                min_rt=p[i].rt;
            }
        }
        if(shortest==-1){
            gantt[time]=-1;
            time++;
            continue;
        }
        gantt[time]=p[s].pid;
        p[s].rt--;

        if(p[s].rt==0){
            completed++;
            p[s].ct=time+1;
            p[s].tat=p[s].ct-p[s].at;
            p[s].wt=p[s].tat-p[s].bt;
        }
        time++
    }
    printf("gantt chart");
    for(int i=0; i<time;i++){
        if(gantt[i]==-1){
            printf("idle |");
        }else{
            printf("p%d",gantt[i]);
        }
    }
    printf("/n0");
    for(int i=0;i<=time;i++){
        printf("   %d",i);
    }
    return 0;
}