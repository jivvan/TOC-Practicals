#include <stdio.h>
#include <string.h>

int isKeyword(char string[])
{
    char keyword[32][10] = {
        "auto", "double", "int", "struct", "break", "else", "long",
        "switch", "case", "enum", "register", "typedef", "char",
        "extern", "return", "union", "const", "float", "short",
        "unsigned", "continue", "for", "signed", "void", "default",
        "goto", "sizeof", "voltile", "do", "if", "static", "while"};
    for (int i = 0; i < 32; i++)
    {
        if (strcmp(string, keyword[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int isIdentifier(char string[])
{
    if (!((string[0] >= 'a' && string[0] <= 'z') || (string[0] >= 'A' && string[0] <= 'Z') || string[0] == '_'))
    {
        return 0;
    }
    for (int i = 1; i < strlen(string); i++)
    {
        if (!(string[i] >= 'a' && string[i] <= 'z' || string[0] >= 'A' && string[0] <= 'Z' || string[i] >= '0' && string[i] <= '9' || string[i] == '_'))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char string[50];
    while (1)
    {
        printf("Enter string to evaluate: ");
        scanf("%s", &string);
        if (isKeyword(string))
        {
            printf("%s is a keyword!\n", string);
        }
        else if (isIdentifier(string))
        {
            printf("%s is a valid identifier!\n", string);
        }
        else
        {
            printf("%s is neither a keyword nor a valid identifier!\n", string);
        }
    }
    return 0;
}