#include <stdio.h>
#include <stdlib.h>
#include <string>

class Data
{
    int         m_age;
    std::string m_name;

public:
    Data(int age, const std::string& name) :
        m_age(age),
        m_name(name)
    {
    }

    ~Data()
    {
    }

    const std::string& name()
    {
        return m_name;
    }
};

class DataEx : public Data
{
    short m_height;

public:
    DataEx(int age, const std::string& name, short height) :
        Data(age, name),
        m_height(height)
    {
    }

    ~DataEx()
    {}

};


int main(int argc, char* argv[])
{
    printf("I'm gonna allocate %ld bytes.\n", sizeof(Data));

    DataEx* pData = new DataEx(40, "furkan", 178);
    printf("I did it\n");

    printf("The string I created is %s.\n", pData->name().c_str());

    delete pData;
    return 0;
}
