/*
Day 1
Write a C program that accepts a positive integer containing digits
from 0 to 9. Exactly one digit is missing, while the remaining nine
digits appear exactly once.

Input: 854102967
Output: 3
*/

#include <stdio.h>

int main() {
    int n;
    int present[10] = {0};

    printf("Enter the positive integer: ");
    scanf("%d", &n);

    while (n > 0) {
        int digit = n % 10;
        present[digit] = 1;
        n /= 10;
    }

    for (int i = 0; i <= 9; i++) {
        if (present[i] == 0) {
            printf("Missing digit: %d\n", i);
            break;
        }
    }

    return 0;
}
