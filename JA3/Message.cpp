#include <iostream>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

int main(){

    string message;
    getline(cin,message);
    istringstream sIn(message);
    string currentWord;
    vector<string> words;
    while(sIn >> currentWord){
        if(currentWord != "."){
            words.push_back(currentWord);
        }
    }
    int queryNumber;
    cin >> queryNumber;

    vector< pair<int,int> > wordsLocations;
    for(int i = 0;i<queryNumber;i++){
        pair<int,int> currentWordLocation;
        cin >> currentWordLocation.first >> currentWordLocation.second;
        wordsLocations.push_back(currentWordLocation);
    }
    set<string> uniqueWords;
    for(int i = 0;i<words.size();i++){
        uniqueWords.insert(words[i]);
    }
    vector< pair<string,int> > wordsCount;

    for(auto i = uniqueWords.begin();i != uniqueWords.end();i++){
        pair <string,int> currentWordsCount;
        currentWordsCount.first = *i;
        int count = 0;
        for(int j = 0;j<words.size();j++){
            if(*i == words[j]){
                count++;
            }
        }
        currentWordsCount.second = count;
        wordsCount.push_back(currentWordsCount);
    }
    int find = 0;
    for(int i = 0;i<wordsLocations.size();i++){
            int pos = 0;
        for(int j = 0;j<wordsCount.size();j++){
            if(wordsLocations[i].first == wordsCount[j].second){
                find = 1;
                if(pos == wordsLocations[i].second){
                    cout << wordsCount[j].first<<endl;
                    break;
                }
                pos++;
            }else{
                find = 0;
            }
        }
        if(find == 0)cout << "."<<endl;
    }

    return 0;
}
