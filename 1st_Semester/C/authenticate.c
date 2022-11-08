#include <stdio.h>
#include <string.h>

int main()
{
    char username[15];
    char password[12];

    printf("Enter your username: ");
    scanf("%s", &username);

    printf("Enter your password: ");
    scanf("%s", &password);

    if (strcmp(username, "abc") == 0)
    {
        if (strcmp(password, "123") == 0)
        {
            printf("Login Success!");
        }
        else
        {
            printf("Invalid Password");
        }
    }
    else
    {
        printf("Invalid Username");
    }

    return 0;
}
