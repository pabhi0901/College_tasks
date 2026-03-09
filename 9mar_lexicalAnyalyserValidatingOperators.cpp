#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isKeyword(string s)
{
    string keywords[]={"int","float","double","char","if","else","while","for","return"};
    
    for(int i=0;i<9;i++)
        if(s==keywords[i])
        return true;

    return false;
}

bool isOperator(char c)
{
    char ops[]={'+','-','*','/','=','<','>'};

    for(int i=0;i<7;i++)
        if(c==ops[i])
        return true;

    return false;
}

bool isSeparator(char c)
{
    char sep[]={';','(',')','{','}',','};

    for(int i=0;i<6;i++)
        if(c==sep[i])
        return true;

    return false;
}

int main()
{
    string line;

    cout<<"Enter statement: ";
    getline(cin,line);

    for(int i=0;i<line.length();)
    {
        if(isalpha(line[i]) || line[i]=='_')
        {
            string word="";

            while(i<line.length() && (isalnum(line[i]) || line[i]=='_'))
            {
                word+=line[i];
                i++;
            }

            if(isKeyword(word))
                cout<<word<<" : Keyword"<<endl;
            else
                cout<<word<<" : Identifier"<<endl;
        }

        else if(isdigit(line[i]))
        {
            string num="";

            while(i<line.length() && isdigit(line[i]))
            {
                num+=line[i];
                i++;
            }

            cout<<num<<" : Number"<<endl;
        }

        else if(isOperator(line[i]))
        {
            cout<<line[i]<<" : Operator"<<endl;
            i++;
        }

        else if(isSeparator(line[i]))
        {
            cout<<line[i]<<" : Separator"<<endl;
            i++;
        }

        else if(isspace(line[i]))
        {
            i++;
        }

        else
        {
            cout<<line[i]<<" : Invalid Symbol"<<endl;
            i++;
        }
    }
}
