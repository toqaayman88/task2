#include <stdio.h>
#include <string.h>

typedef struct User {
    char username[20];
    char password[20];
};
union ActivityFlag {
    int activeFlag;
    char flagChar[4];
};

void registerUser(struct User newUser[], union ActivityFlag *flag, int *numUsers) {
    printf("Enter username: ");
    scanf("%s", newUser[*numUsers].username);
    printf("Enter password: ");
    scanf("%s", newUser[*numUsers].password);
    printf("Enter activity flag (true/1 or false/0): ");
    scanf("%d", &flag->activeFlag);
      (*numUsers)++;

    printf("Registration is done successfully\n");
}

int loginUser(struct User newUser[], union ActivityFlag flag, int numUsers, char username[], char password[]) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(newUser[i].username, username) == 0 && strcmp(newUser[i].password, password) == 0) {
            if (flag.activeFlag == 1) {
                return 1; // Active user, login successful
            } else {
                printf("User is not active. Please contact the administrator.\n");
                return 0; // Inactive user, login failed
            }
        }
    }
            return -1; // Invalid username or password, login failed
}

int main() {
     struct User newUser[100];
     union ActivityFlag flag;
    int numUsers = 0;
    int choice;
    char username[20];
    char password[20];
    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                 registerUser(newUser, &flag, &numUsers);
                break;
            case 2:
               printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                int loginStatus = loginUser(newUser, flag, numUsers, username, password);
                if (loginStatus == 1) {
                    printf("Login successful!\n");
                } else if (loginStatus == 0) {
                    printf("Login failed. User is not active.\n");
                } else {
                    printf("Login failed. Invalid username or password.\n");
                }
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}