#include<stdio.h>
#include<stdlib.>
int main(){
    int n,head,total=0;
    printf("Enter number of requests:");
    scanf("%d",&n);
    int req[n],vis[n];
    printf("Enter requests");
    for(int i=0;i<n;i++){
        scanf("%d",&req[i]);
        vis[i]=0;
    }
    printf("initial head");
    scanf("%d",&head);
    for(int i=0;i<n;i++){
        int min=1000, index;
        for(int j=0;j<n;j++){
         if(!vis[j]){
            int d=abs(head-req[j]);
            if(d<min){
                min=d;
                index=j;}
            }
        }
        visited[index]=1;
        total+=min;
        head=req[index];
    }
    printf("total movement",total)
    return 0;
}