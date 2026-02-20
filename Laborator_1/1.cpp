#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

int atoi(char* t)
{
    int nr = 0, c;
    for (int i = 0; i < strlen(t); i++)
    {
        if (t[i] >= '0' && t[i] <= '9')
        {
            c = t[i] - '0';
            nr = nr * 10 + c;
        }
    }
    return nr;
}

int main()
{
    int sum = 0, nr;

    char line[256];
    FILE* infile = fopen("in.txt", "r");
    if (infile == NULL)
    {
        printf("Error");
        return 1;
    }

    while (fgets(line, sizeof(line), infile))
    {
        nr = atoi(line);
        sum = sum + nr;
    }
    fclose;
    printf("%d", sum);
    return 0;
}

