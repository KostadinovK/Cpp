#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string line;
    getline(cin,line);
    vector<string> signalNoise;
    string currentSignalNoise;
    istringstream sIn(line);
    while(sIn >> currentSignalNoise){
        signalNoise.push_back(currentSignalNoise);
    }
    for(int i = 0;i<signalNoise.size();i++){
        for(int j = 0;j<signalNoise[i].size();j++){
            if(signalNoise[i][j] < '0' || signalNoise[i][j] > '9' ){
                signalNoise[i].erase(j,1);
                j--;
            }
        }
    }
    vector<int> nums;
    int num=0;
    for(int i = 0;i<signalNoise.size();i++){
        istringstream toNum(signalNoise[i]);
        toNum >> num;
        nums.push_back(num);
    }
    int max = INT_MIN;
    for(int i = 0;i<nums.size();i++){
        if(nums[i] > max)max = nums[i];
    }
    cout <<max<<endl;
    return 0;
}
