// WAP to find prefixes, suffixes and substring from given string
#include <stdio.h>
#include <string.h>

void prefixes(char string[])
{
    for (int i = strlen(string); i >= 0; i--)
    {
        printf("- ");
        for (int j = 0; j < i; j++)
        {
            printf("%c", string[j]);
        }

        printf("\n");
    }
}

void suffixes(char string[])
{
    for (int i = 0; i <= strlen(string); i++)
    {
        printf("- ");
        for (int j = i; j < strlen(string); j++)
        {
            printf("%c", string[j]);
        }
        printf("\n");
    }
}

void substrings(char string[])
{
    for (int i = 0; i <= strlen(string); i++)
    {
        for (int j = strlen(string); j > i; j--)
        {
            printf("- ");
            for (int k = i; k < j; k++)
            {
                printf("%c", string[k]);
            }
            printf("\n");
        }
    }
    printf("- \n");
}

void main()
{
    char string[100];
    printf("Enter a string: ");
    scanf("%s", &string);
    printf("The prefixes are:\n");
    prefixes(string);
    printf("The suffixes are:\n");
    suffixes(string);
    printf("The substrings are:\n");
    substrings(string);
}