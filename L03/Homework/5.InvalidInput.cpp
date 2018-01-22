#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    string line;
    getline(cin,line);
    istringstream sIn(line);
    vector<string> words;
    vector<int> nums;
    vector<string> invalidWords;
    string currentWord;
    int sum=0;
    while(sIn >> currentWord){
        words.push_back(currentWord);
    }
    for(int i = 0;i<words.size();i++){
        if((words[i][0] >= '0' && words[i][0] <= '9') || words[i][0] == '-'){
            istringstream input(words[i]);
            int num=0;
            input >> num;
            nums.push_back(num);
        }else{
            invalidWords.push_back(words[i]);
        }
    }
    for(int i = 0;i<nums.size();i++){
        sum = sum + nums[i];
    }
    cout << sum<<endl;
    for(int i = 0;i<invalidWords.size();i++){
        cout << invalidWords[i]<<" ";
    }

    return 0;
}
