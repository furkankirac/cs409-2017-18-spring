#include <stdio.h>
#include <stdlib.h>

struct Data
{
    int age;
    char* name;

    Data()
    {
        age = 40;

        name = (char*)malloc(10);
        name[0] = 'f';
        name[1] = 'u';
        name[2] = 'r';
        name[3] = 'k';
        name[4] = 'a';
        name[5] = 'n';
        name[6] = '\0';
    }

    ~Data()
    {
        free(name);
    }
};

int main(int argc, char* argv[])
{
    printf("I'm gonna allocate %ld bytes.\n", sizeof(Data));

    Data* pData = new Data();
    printf("I did it\n");

    printf("The string I created is %s.\n", pData->name);

    delete pData;
    return 0;
}
