#include <stdio.h>

int main() {
    int n, i, j, temp;
    int arrival[100], burst[100], id[100];
    int waiting[100], turnaround[100], completion[100];
    float avg_waiting = 0, avg_turnaround = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d - Arrival: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Process %d - Burst: ", i + 1);
        scanf("%d", &burst[i]);
        id[i] = i + 1;
    }

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arrival[j] > arrival[j + 1]) {

                temp = arrival[j];
                arrival[j] = arrival[j + 1];
                arrival[j + 1] = temp;

                temp = burst[j];
                burst[j] = burst[j + 1];
                burst[j + 1] = temp;

                temp = id[j];
                id[j] = id[j + 1];
                id[j + 1] = temp;
            }
        }
    }

    completion[0] = arrival[0] + burst[0];
    turnaround[0] = completion[0] - arrival[0];
    waiting[0] = turnaround[0] - burst[0];

    for(i = 1; i < n; i++) {
        if(completion[i - 1] < arrival[i]) {
            completion[i] = arrival[i] + burst[i];
        } else {
            completion[i] = completion[i - 1] + burst[i];
        }

        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];
    }

    printf("\nFCFS Scheduling:\n");
    printf("ID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
            id[i], arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);

        avg_waiting += waiting[i];
        avg_turnaround += turnaround[i];
    }

    printf("\nAverage Waiting Time: %.2f", avg_waiting / n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround / n);

    return 0;
}
