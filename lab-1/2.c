// Program implementing DFA accepting the string over {a,b} such that each string does not end with ab
#include <stdio.h>
#include <stdlib.h>

int transition(int state, char input)
{
    int tMatrix[][3] = {
        //{'STATE', 'INPUT-a', 'INPUT-b'}
        {1, 0},
        {1, 2},
        {1, 0},
    };
    if (input == 'a')
        return tMatrix[state][0];
    else if (input == 'b')
        return tMatrix[state][1];
    exit(1);
}

int isAcceptable(int currentState)
{
    int finalStates[] = {0, 1};
    int length = sizeof(finalStates) / sizeof(int);
    for (int i = 0; i < length; i++)
        if (finalStates[i] == currentState)
            return 1;
    return 0;
}

void main()
{
    char str[100];
    int currentState = 0;
    printf("Enter any string of alphabet {a,b}\n");
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++)
        currentState = transition(currentState, str[i]);
    if (isAcceptable(currentState))
        printf("Accepted\n");
    else
        printf("Rejected\n");
}