#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    int arr[30];
    int status;
    pid_t p1, p2;
    int final_sum_p1 = 0, final_sum_p2 = 0;

    srand(time(NULL));

    printf("Array initialized by Parent:\n");
    for (int i = 0; i < 30; i++) {
        arr[i] = rand() % 50 + 1;
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // -------- Child 1 --------
    p1 = fork();

    if (p1 == 0) {  // Child 1 process
        int sum = 0;
        for (int i = 0; i <= 14; i++) {
            if (arr[i] % 2 == 0)
                sum += arr[i];
        }
        printf("Child 1 (0-14) Even Sum = %d\n", sum);
        exit(sum);   // return sum to parent
    }

    // -------- Parent waits for Child 1 --------
    waitpid(p1, &status, 0);
    final_sum_p1 = WEXITSTATUS(status);

    // -------- Child 2 --------
    p2 = fork();

    if (p2 == 0) {  // Child 2 process
        int sum = 0;
        for (int i = 15; i < 30; i++) {
            if (arr[i] % 2 == 0)
                sum += arr[i];
        }
        printf("Child 2 (15-29) Even Sum = %d\n", sum);
        exit(sum);   // return sum to parent
    }

    // -------- Parent waits for Child 2 --------
    waitpid(p2, &status, 0);
    final_sum_p2 = WEXITSTATUS(status);

    // -------- Final Output --------
    printf("\nTotal Even Sum of left side and right side are: %d and %d\n",
           final_sum_p1, final_sum_p2);

    return 0;
}

