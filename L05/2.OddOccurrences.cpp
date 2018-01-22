#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector <string> words;
    string currentWord;
    while(cin >> currentWord){
        words.push_back(currentWord);
        if(cin.get() == '\n')break;

    }
    for(int i = 0;i < words.size();i++){
        for(int j = 0;j<words[i].size();j++){
            if(words[i][j] >= 'A' && words[i][j] <= 'Z'){
                words[i][j] = tolower(words[i][j]);
            }
        }

    }
    vector<string> res;
    int count = 0,ok=1;
    for(int i = 0;i<words.size();i++){

        for(int j = 0;j<words.size();j++){
            if (words[i] == words[j])count += 1;
        }
        if(count % 2 != 0){
            for(int k = 0;k<res.size();k++){
                if(words[i] == res[k])ok = 0;
            }
            if(ok == 1){
                res.push_back(words[i]);
            }

        }
        ok = 1;
        count = 0;
    }


    for(int i = 0;i<res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}
