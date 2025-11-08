#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(char* s)
{
    if (!s) return 0;

    int count = 0;
    size_t pos = 0;
    char* t;

    while (t = strchr(s + pos, 'n'))
    {
        if (*(t + 1) == 'o')
            count++;
        pos = (t - s) + 1;
    }

    pos = 0;
    while (t = strchr(s + pos, 'o'))
    {
        if (*(t + 1) == 'n')
            count++;
        pos = (t - s) + 1;
    }

    return count;
}

char* Replace(char* s)
{
    if (!s) return nullptr;

    size_t len = strlen(s);
    char* t = new char[3 * len + 1];
    t[0] = '\0';

    char* p = s;
    while (*p)
    {
        if ((*p == 'n' && *(p + 1) == 'o') ||
            (*p == 'o' && *(p + 1) == 'n'))
        {
            strcat(t, "***");
            p += 2;
        }
        else
        {
            strncat(t, p, 1);
            p++;
        }
    }

    strcpy(s, t);
    return t;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int pairs = Count(str);
    if (pairs > 0)
    {
        cout << "String contained " << pairs << " groups of 'no' or 'on'" << endl;

        char* dest = new char[3 * strlen(str) + 1];
        dest = Replace(str);

        cout << "Modified string (param) : " << str << endl;
        cout << "Modified string (result): " << dest << endl;

        delete[] dest;
    }
    else
    {
        cout << "No 'no' or 'on' found" << endl;
    }

    return 0;
}
