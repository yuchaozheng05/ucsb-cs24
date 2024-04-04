#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        cout<<"USAGE: censor [length]"<<endl;
        exit(1);
    }

    string text;
    vector<string>words;
    //cin>>text;
    unsigned int len = atoi(argv[1]);
    while(cin >> text)
    {
        if(text.size() != len)
        {
            words.push_back(text);
        }
        //cin>>text;
    }
    for(unsigned int i = 0; i< words.size()-1; i++)
    {
        cout<<words.at(i)<<" ";
    }
    int s = words.size();
    cout<<words.at(s-1);
    cout<<endl;

}