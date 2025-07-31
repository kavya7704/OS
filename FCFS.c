#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int BT[n], TAT[n], WT[n];
    
    printf("Enter the Burst time of each processor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &BT[i]);
    }

    // Initialize first Turn Around Time and Waiting Time
    TAT[0] = BT[0];
    WT[0] = 0;

    int sum_TAT = TAT[0];
    int sum_WT = WT[0];

    // Compute Turn Around Time and Waiting Time for rest
    for (int i = 1; i < n; i++) {
        TAT[i] = TAT[i - 1] + BT[i];
        WT[i] = TAT[i] - BT[i];
        sum_TAT += TAT[i];
        sum_WT += WT[i];
    }

    float avg_TAT = (float)sum_TAT / n;
    float avg_WT = (float)sum_WT / n;

    printf("The average turn around time is: %.2f\n", avg_TAT);
    printf("The average waiting time is: %.2f\n", avg_WT);

    return 0;
}
