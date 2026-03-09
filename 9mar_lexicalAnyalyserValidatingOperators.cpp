#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

bool isKeyword(string s)
{
    string keywords[] = {"int","float","double","char","if","else","while","for","return"};
    
    for(int i=0;i<9;i++)
        if(s==keywords[i])
        return true;

    return false;
}

bool isOperator(char c)
{
    char ops[] = {'+','-','*','/','=','<','>'};
    
    for(int i=0;i<7;i++)
        if(c==ops[i])
        return true;

    return false;
}

bool isNumber(string s)
{
    for(int i=0;i<s.length();i++)
        if(!isdigit(s[i]))
        return false;

    return true;
}

bool isIdentifier(string s)
{
    if(!(isalpha(s[0]) || s[0]=='_'))
    return false;

    for(int i=1;i<s.length();i++)
        if(!(isalnum(s[i]) || s[i]=='_'))
        return false;

    return true;
}

int main()
{
    string line, token;

    cout<<"Enter statement: ";
    getline(cin,line);

    stringstream ss(line);

    while(ss >> token)
    {
        if(isKeyword(token))
            cout<<token<<" : Keyword"<<endl;

        else if(isNumber(token))
            cout<<token<<" : Number"<<endl;

        else if(isIdentifier(token))
            cout<<token<<" : Identifier"<<endl;

        else
            cout<<token<<" : Unknown"<<endl;
    }

    for(char c : line)
    {
        if(isOperator(c))
        cout<<c<<" : Operator"<<endl;

        if(c==';' || c=='(' || c==')')
        cout<<c<<" : Separator"<<endl;
    }
}