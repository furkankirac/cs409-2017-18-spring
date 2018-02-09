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

    pData->age = 40;

    pData->name = (char*)malloc(10);

    pData->name[0] = 'f';
    pData->name[1] = 'u';
    pData->name[2] = 'r';
    pData->name[3] = 'k';
    pData->name[4] = 'a';
    pData->name[5] = 'n';
    pData->name[6] = '\0';

    printf("The string I created is %s.\n", pData->name);

    free(pData->name);
    free(pData);
    return 0;
}
