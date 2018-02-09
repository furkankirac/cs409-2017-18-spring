#include <stdio.h>
#include <stdlib.h>
#include <string>

struct Data
{
private:
    int         m_age;
    std::string m_name;

public:
    Data()
    {
        m_age = 40;
        m_name = "furkan";
    }

    ~Data()
    {
    }

    std::string name()
    {
        return m_name;
    }

};

int main(int argc, char* argv[])
{
    printf("I'm gonna allocate %ld bytes.\n", sizeof(Data));

    Data* pData = new Data();
    printf("I did it\n");

    printf("The string I created is %s.\n", pData->name().c_str());

    delete pData;
    return 0;
}
