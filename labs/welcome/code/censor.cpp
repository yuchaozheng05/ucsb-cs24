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
    while(cin >> text)
    {
        words.push_back(text);
        //cin>>text;
    }
    unsigned int len = atoi(argv[1]);
    for(unsigned int i = 0; i< words.size(); i++)
    {
        if((words.at(i)).size() != len)
        {
            cout<<words.at(i)<<" ";
        }
    }

    

}