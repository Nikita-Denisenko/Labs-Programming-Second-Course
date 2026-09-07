#include <cstdio>
#include <cstring>
#include <stdlib.h>

#define SIZE 100

int myStrcmp(const char* s1, const char* s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] < s2[i])
        {
            return -1;
        }

        if (s1[i] > s2[i])
        {
            return 1;
        }

        i++;
    }

    if (s1[i] == '\0' && s2[i] == '\0')
    {
        return 0;
    }

    if (s1[i] == '\0')
    {
        return -1;
    }

    return 1;
}

int main()
{
    char s1[SIZE];
    char s2[SIZE];

    printf("Enter first string: ");
    scanf_s("%99s", s1, (unsigned)_countof(s1));

    printf("Enter second string: ");
    scanf_s("%99s", s2, (unsigned)_countof(s2));

    int standardResult = strcmp(s1, s2);
    int customResult = myStrcmp(s1, s2);

    // Приводим результат стандартной strcmp к -1, 0 или 1
    if (standardResult < 0)
    {
        standardResult = -1;
    }
    else if (standardResult > 0)
    {
        standardResult = 1;
    }

    printf("\nStandard strcmp result: %d\n", standardResult);
    printf("My strcmp result: %d\n", customResult);

    return 0;
}
