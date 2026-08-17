/*
Day 2
Write a program using a while loop that repeatedly asks the user
to enter the password and stops only when the correct password is entered.
Finally, display "Login successful!".
*/

#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    const char correctPassword[] = "12345";

    while (1) {
        printf("Enter password: ");
        scanf("%99s", password);

        if (strcmp(password, correctPassword) == 0) {
            printf("Login successful!\n");
            break;
        }

        printf("Incorrect password. Try again.\n");
    }

    return 0;
}
