#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        cout<<"USAGE: censor"<<argc<<endl;
        exit(1);
    }
    string text;
    getline(cin, text);

}