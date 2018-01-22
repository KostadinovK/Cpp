#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;

int main(){
    string line;
    getline(cin,line);
    istringstream sIn(line);
    vector<string> words;
    string currentWord;

    while(sIn >> currentWord){
        words.push_back(currentWord);
    }

    for(int i=0;i<words.size();i++){
        words[i][0] = toupper(words[i][0]);
        if(words[i][words[i].size()-2] == ','){
            words[i][words[i].size()-1] = toupper(words[i][words[i].size()-1]);
        }
        cout << words[i]<<" ";
    }


    return 0;
}
