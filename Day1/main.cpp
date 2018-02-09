#include <stdio.h>
#include <stdlib.h>

struct Data
{
    int age;
    char* name;
};

int main(int argc, char* argv[])
{
    printf("I'm gonna allocate %ld bytes.\n", sizeof(Data));
    Data* pData = (Data*)malloc(sizeof(Data));
    printf("I did it\n");

    free(pData);
    return 0;
}
