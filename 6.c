#include <stdio.h>
int main() {
    int f, n, frames[10], pages[30], time[10], faults = 0, counter = 0;
    printf("Frames and Pages: "); scanf("%d %d", &f, &n);
    printf("Reference string: ");
    for(int i=0; i<n; i++) scanf("%d", &pages[i]);
    for(int i=0; i<f; i++) frames[i] = -1;

    for(int i=0; i<n; i++) {
        int flag1 = 0, flag2 = 0;
        for(int j=0; j<f; j++) {
            if(frames[j] == pages[i]) { counter++; time[j] = counter; flag1 = flag2 = 1; break; }
        }
        if(flag1 == 0) {
            for(int j=0; j<f; j++) {
                if(frames[j] == -1) { counter++; faults++; frames[j] = pages[i]; time[j] = counter; flag2 = 1; break; }
            }
        }
        if(flag2 == 0) {
            int min = time[0], pos = 0;
            for(int j=1; j<f; j++) if(time[j] < min) { min = time[j]; pos = j; }
            counter++; faults++; frames[pos] = pages[i]; time[pos] = counter;
        }
    }
    printf("Total Page Faults: %d\n", faults);
    return 0;
}