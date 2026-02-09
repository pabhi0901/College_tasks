#include<iostream>
#include<string>
using namespace std;

int main(){


    string line;
    cout<<"Enter a line: "; 
    getline(cin, line);
    if ((line.substr(0, 2) == "//") || (line.substr(0, 2) == "/*" && line.substr(line.size() - 2) == "*/")) {
        cout << "The line is a comment." << endl;
    } else {
        cout << "The line is not a comment." << endl;
    }


    return 0;
}