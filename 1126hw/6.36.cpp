#include <stdio.h>

void stringReverse(const char str[]);

int main(void)
{
    char str[100];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) != NULL)
    {
        int i = 0;
        while (str[i] != '\0')
        {
            if (str[i] == '\n')
            {
                str[i] = '\0';
                break;
            }
            i++;
        }
        stringReverse(str);
        printf("\n");
    }

    return 0;
}

void stringReverse(const char str[])
{
    if (str[0] == '\0')
    {
        return;
    }

    stringReverse(&str[1]);
    printf("%c", str[0]);
}
