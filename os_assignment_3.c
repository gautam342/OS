#include <stdio.h>

int main() {
    int n = 5;
    
    int process[] = {0, 1, 2, 3, 4};
    int arrival[] = {0, 1, 2, 3, 4};
    int burst[] = {5, 7, 6, 2, 4};
    
    int completion[5];
    int turnaround[5];
    int waiting[5];
    
    float totalTAT = 0, totalWT = 0;

    // First process
    completion[0] = arrival[0] + burst[0];

    // Calculate completion time
    for(int i = 1; i < n; i++) {
        if(completion[i-1] > arrival[i])
            completion[i] = completion[i-1] + burst[i];
        else
            completion[i] = arrival[i] + burst[i];
    }

    // Calculate Turnaround Time and Waiting Time
    for(int i = 0; i < n; i++) {
        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];

        totalTAT += turnaround[i];
        totalWT += waiting[i];
    }

    // Display results
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               process[i], arrival[i], burst[i],
               completion[i], turnaround[i], waiting[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", totalTAT / n);
    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);

    return 0;
}