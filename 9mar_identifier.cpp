#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isKeyword(string s)
{
    string keywords[] = {
        "int","float","double","char","if","else","while","for",
        "return","class","struct","break","continue","void","switch"
    };

    for(int i = 0; i < 15; i++)
    {
        if(s == keywords[i])
        return true;
    }

    return false;
}

int main()
{
    string id;
    cout << "Enter identifier: ";
    cin >> id;

    if(isKeyword(id))
    {
        cout << "Invalid Identifier (Keyword)";
        return 0;
    }

    if(!(isalpha(id[0]) || id[0] == '_'))
    {
        cout << "Invalid Identifier";
        return 0;
    }

    for(int i = 1; i < id.length(); i++)
    {
        if(!(isalnum(id[i]) || id[i] == '_'))
        {
            cout << "Invalid Identifier";
            return 0;
        }
    }

    cout << "Valid Identifier";
}