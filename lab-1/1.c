// Program to implement DFA for language of string over {0,1} in which each string ends with '11'
#include <stdio.h>
#include <stdlib.h>

char transition(int state, char input)
{
    int tMatrix[][3] = {
        //{'STATE', 'INPUT-0', 'INPUT-1'}
        {0, 0, 1},
        {1, 0, 2},
        {2, 0, 2},
    };
    if (input == '0')
        return tMatrix[state][1];
    else if (input == '1')
        return tMatrix[state][2];
    exit(1);
}

void main()
{
    char str[100];
    const int finalState = 2;
    int currentState = 0;
    int i;
    printf("Enter any string of alphabet {0,1}\n");
    scanf("%s", str);
    for (i = 0; str[i] != '\0'; i++)
        currentState = transition(currentState, str[i]);
    if (currentState == finalState)
        printf("Accepted\n");
    else
        printf("Rejected\n");
}