#ifndef ENUM_H
#define ENUM_H

struct EnumInfo
{
    const char* fullname{};
    const char* shortname{};
};

template<typename DERIVED>
class EnumBase
{
    int value;

public:
    EnumBase();
};

#endif // ENUM_H
