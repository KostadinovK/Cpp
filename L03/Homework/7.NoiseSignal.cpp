#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    string line;
    getline(cin,line);
    istringstream sIn(line);
    vector<string> noise;
    string currentNoise;
    while(sIn >> currentNoise){
        for(int i = 0;i<currentNoise.size();i++){
                if(currentNoise[i] >= '0' && currentNoise[i] <= '9'){
                    currentNoise.erase(i,1);
                    i--;
                }
        }
        noise.push_back(currentNoise);
    }
    int maxSize = 0;
    for(int i = 0;i<noise.size();i++){
        if(noise[i].size() > maxSize){
            maxSize = noise[i].size();
        }
    }
    vector <string> maxNoise;
    if(maxSize == 0){
        cout << "no noise";
        return 0;
    }else{
        for(int i = 0;i<noise.size();i++){
        if(maxSize == noise[i].size()){
            maxNoise.push_back(noise[i]);
        }
    }
    }
    string res = maxNoise[0];
    for(int i=1;i<maxNoise.size();i++){
        if(maxNoise[i].compare(res) < 0){
            res = maxNoise[i];
        }
    }
    cout << res<<endl;
    return 0;
}
