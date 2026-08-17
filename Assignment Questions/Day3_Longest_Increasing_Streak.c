/*
Day 3
Given an array of daily temperatures, find the length of the
longest consecutive strictly increasing streak.

Input:  [10, 12, 15, 14, 16, 18, 20]
Output: 4

Explanation:
14, 16, 18, 20 is the longest increasing streak.
*/

#include <stdio.h>

int main() {
    int n;

    printf("Enter number of temperatures: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Longest increasing streak: 0\n");
        return 0;
    }

    int arr[n];

    printf("Enter temperatures:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int current = 1;
    int longest = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            current++;

            if (current > longest)
                longest = current;
        } else {
            current = 1;
        }
    }

    printf("Longest increasing streak: %d\n", longest);

    return 0;
}
