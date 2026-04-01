#include <stdio.h>

int main() {
    int n = 5;
    char pid[5][3] = {"P0", "P1", "P2", "P3", "P4"};
    int at[5] = {0, 0, 0, 0, 0};
    int bt[5] = {5, 7, 6, 8, 5};
    int iot[5] = {2, 2, 3, 1, 2};
    int ct[5], tat[5], wt[5];
    int total_tat = 0, total_wt = 0;
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (time < at[i]) {
            time = at[i];
        }

        // First CPU burst
        time += bt[i];
        ct[i] = time;

        // I/O time if applicable
        if (iot[i] > 0) {
            time += iot[i];
            // Second CPU burst (assuming remaining burst time is same as original for simplicity)
            time += bt[i];
            ct[i] = time;
        }

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("Process\tAT\tBT\tIOT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], iot[i], ct[i], tat[i], wt[i]);
    }

    printf("Average Turnaround Time = %.2f\n", (float)total_tat / n);
    printf("Average Waiting Time = %.2f\n", (float)total_wt / n);

    return 0;
}