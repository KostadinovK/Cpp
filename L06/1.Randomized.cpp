#include <iostream>
#include <list>
#include <sstream>
#include <algorithm>
#include "RandomWordsList.h"
using namespace std;

class RandomWordsList{
public:
    list<string> words;

    RandomWordsList(){

    }
    RandomWordsList(string text){
        string currentWord;
        istringstream sIn(text);
        while(sIn >> currentWord){
            this->words.push_back(currentWord);
        }
    }

    string toString(){
        ostringstream info;
        for(auto i = this->words.begin();i!=this->words.end();i++){
            info << *i<<" ";
        }
        return info.str();
    }
    void getRandomized(){
        vector<string> wordsVec;
        for(auto i = this->words.begin();i!=this->words.end();i++){
            wordsVec.push_back(*i);
        }
        random_shuffle(wordsVec.begin(),wordsVec.end());
        int j=0;
        for(auto i = this->words.begin();i!=this ->words.end();i++){
            *i = wordsVec[j];
            j++;
        }
    }
};

int main(){
    string text;
    getline(cin,text);
    RandomWordsList n{text};
    n.getRandomized();
    for(auto i = n.words.begin();i != n.words.end();i++){
        cout << *i <<endl;
    }

    return 0;
}
