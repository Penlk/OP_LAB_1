#include "AllStructs.h"
#include "../Functions.h"

void IsCommands::IndexToField(int i)
{
    args[i] = true;
    switch (i)
    {
    case 0:
        output = true;
        break;
    case 1:
        print = true;
        break;
    case 2:
        stats = true;
        break;
    case 3:
        window = true;
        break;
    case 4:
        from = true;
        break;
    case 5:
        to = true;
        break;
    }
}

void ValuesArgs::IndexToFieldValue(int i, long long value)
{
    switch (i)
    {
    case 2:
        statsN = value;
        break;
    case 3:
        windowT = value;
        break;
    case 4:
        fromT = value;
        break;
    case 5:
        toT = value;
        break;
    }
}

long long ValuesLog::LocalTimeToInt() //[localTime]
{
    if (localTimeRight - localTimeLeft + 1 < 23)
        return -1;
    
    int start = localTimeLeft + 1;
    int end = FindSymbol(str, localTimeLeft, '/');
    int day = StringToInt(str, start, end);

    start = end + 1;
    end = FindSymbol(str, start, '/');
    char* month = CopyString(str, start, end);

    start = end + 1;
    end = FindSymbol(str, start, ':');
    int year = StringToInt(str, start, end);

    start = end + 1;
    end = FindSymbol(str, start, ':');
    int hour = StringToInt(str, start, end);

    start = end + 1;
    end = FindSymbol(str, start, ':');
    int minute = StringToInt(str, start, end);

    start = end + 1;
    end = FindSymbol(str, start, ' ');
    int second = StringToInt(str, start, end);

    start = end + 1;
    bool minus = start == '-' ? -1: 1;
    hour += minus * StringToInt(str, start + 1, start + 3);
    minute += minus * StringToInt(str, start + 3, start + 5);

    if (end >= localTimeRight)
        return -1;

    return TranslateTime(day, month, year, hour, minute, second);
}

template<typename T>
void MyList<T>::Append(T str)
{
    length++;

    if (length == maxLength + 1)
    {
        T* newList = new T[maxLength * 2];
        for (int i = 0; i < maxLength; i++)
            newList[i] = list[i];
        delete [] list;
        list = newList;
        maxLength *= 2;
    }

    list[length - 1] = str;
}

template struct MyList<char*>;
template struct MyList<long*>;