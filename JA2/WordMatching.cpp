#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
bool areMatching(string,string,double);
int main(){

    string text;
    getline(cin,text);
    for(int i = 0;i<text.size();i++){
        if(text[i] == ',' || text[i] == ';' || text[i] == '.' || text[i] == '!' || text[i] == '?'){
            text[i] = 32;
        }
    }
    istringstream sIn(text);
    string currentWord;
    vector <string> words;
    while(sIn >> currentWord){
        words.push_back(currentWord);
    }
    string match;
    cin >> match;
    double p;
    cin >> p;
    int count = 0;
    for(int i = 0;i<words.size();i++){
        bool areM = areMatching(words[i],match,p);
        if(areM){
            count++;
        }
    }
    cout << count <<endl;
    return 0;
}

bool areMatching(string word1,string word2,double p){
    double count = 0;
    double pOfMatchingLetters;
    if(word1.size() != word2.size())return false;
    if(word1[0] != word2[0])return false;
    for(int i = 0;i<word1.size();i++){
        if(word1[i] == word2[i]){
            count++;
        }
    }

    pOfMatchingLetters = count/word1.size() * 100;
    if(pOfMatchingLetters < p)return false;
    else return true;

}
