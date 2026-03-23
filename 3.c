#include <stdio.h>
 int main(){
    int n,m;
    printf("Enter processes and resources types");
    scanf("%d%d", &n,&m);
    int alloc[n][m], max[n][m],avail[m],need[n][m],finish[n],safe[n], ind=0;

    printf("enter allocation matrix:\n");
    for(int i=0;i<n;i++){
        finish[i]=0;
        for(int j=0;j<m;j++){
            scanf("&d",&alloc[i][j]);
        }
    }
    printf("Enter max resources\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("&d",&max[i][j]);
        }
    }
    printf("Enter available resources\n");
            for(int j=0;j<m;j++){
            scanf("&d",&avail[j]);
            }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int flag = 0;
                for (int j = 0; j < m; j++)
                    if (need[i][j] > avail[j]) { flag = 1; break; }
                if (flag == 0) {
                    safe[ind++] = i;
                    for (int y = 0; y < m; y++) avail[y] += alloc[i][y];
                    finish[i] = 1;
                }
            }
        }
    }
    printf("Safe Sequence: ");
    for (int i = 0; i < n; i++) printf("P%d ", safe[i]);
    return 0;
 }