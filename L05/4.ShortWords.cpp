#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

int main(){
    string text;
    getline(cin, text);
    istringstream sIn(text);
    vector<string> words;
    string currentWord;
    while(sIn >> currentWord){
        words.push_back(currentWord);
    }
    for(int i = 0;i<words.size();i++){
        for(int j = 0;j<words[i].size();j++){
            if(words[i][j] >= 'A' && words[i][j] <= 'Z'){
                words[i][j] = tolower(words[i][j]);
            }
        }
    }
    set<string>shortWords;
    int letters;
    for(int i = 0;i<words.size();i++){

        if(words[i].size() < 5){
            shortWords.insert(words[i]);
        }
    }
    auto firstShortWord = shortWords.begin();
    cout << *firstShortWord;
    auto secondShortWord = shortWords.begin();
    secondShortWord++;
    for(auto i = secondShortWord;i != shortWords.end();i++){
        cout <<", "<< *i;

    }
    return 0;
}
