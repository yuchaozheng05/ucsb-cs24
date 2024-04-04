#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int main(int argc, char * argv[])
{
    if(argc >2)
    {
        cout<<"USAGE: censor"<<argc<<endl;
        exit(1);
    }
    if(argc == 1)
    {
        cout<<"USAGE: censor"<<argc<<endl;
        exit(1);
    }
    string text;
    getline(cin, text);
    vector<string>words;
    stringstream ss(text);
    string word;
    while(ss>>word){
        words.push_back(word);
    }
    for(int i =0; i<words.size(); i++){
        if((words.at(i)).size() != atoi(argv[1])){
            cout<<words.at(i);
        }
    }
    cout<<endl;

}