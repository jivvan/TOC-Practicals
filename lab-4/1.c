// Program to simulate a NFA that accepts string that ends with 10

#include <stdio.h>
#include <string.h>
#define NUMBER_OF_STATES 3
#define CARDINALITY 2

// 0 means epsilon, or no transition
int transition_table[NUMBER_OF_STATES][CARDINALITY][NUMBER_OF_STATES] = {
    {{1, 0, 0}, {1, 2, 0}},
    {{3, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}},
};

int final_states[] = {3};

void do_union(int current_states[NUMBER_OF_STATES], int transition_states[NUMBER_OF_STATES], int new_states[NUMBER_OF_STATES])
{
    for (int i = 0; i < NUMBER_OF_STATES; i++)
    {
        if (transition_states[i] != 0)
        {
            new_states[transition_states[i] - 1] = transition_states[i];
        }
    }
}

int contains_final_state(int *current_states)
{
    for (int i = 0; i < NUMBER_OF_STATES; i++)
    {
        for (int j = 0; j < sizeof(final_states) / sizeof(int); j++)
        {
            if (final_states[j] == current_states[i])
            {
                return 1;
            }
        }
    }
    return 0;
}

int evaluate(char *string)
{
    int current_states[NUMBER_OF_STATES] = {1};
    int new_states[NUMBER_OF_STATES] = {};

    for (int i = 0; i < strlen(string); i++)
    {
        char c = string[i];
        for (int j = 0; j < NUMBER_OF_STATES; j++)
        {
            if (current_states[j] != 0)
            {
                int current_state = current_states[j];
                int *transition_states = transition_table[current_state - 1][c == '0' ? 0 : 1];
                do_union(current_states, transition_states, new_states);
            }
        }
        memcpy(current_states, new_states, sizeof(int) * NUMBER_OF_STATES);
        memset(new_states, 0x00, sizeof(int) * NUMBER_OF_STATES);
    }
    return contains_final_state(current_states);
}

int main()
{
    char string[10];
    while (1)
    {
        printf("Enter string to evaluate: ");
        scanf("%s", &string);
        if (evaluate(string))
        {
            printf("%s is accepted!\n", string);
        }
        else
        {
            printf("%s is rejected!\n", string);
        }
    }
    return 1;
}