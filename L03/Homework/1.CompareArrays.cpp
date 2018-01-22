#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
bool areEquals(vector<int>,vector<int>);
int main(){
    vector<int> v1;
    vector<int> v2;
    int i,currentNum;
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    istringstream sIn1(s1);
    istringstream sIn2(s2);
    while(sIn1>>currentNum){
        v1.push_back(currentNum);
    }

    while(sIn2>>currentNum){
        v2.push_back(currentNum);
    }
    if(areEquals(v1,v2) == 1){
        cout << "equal"<<endl;
    }else{
        cout <<"not equal"<<endl;
    }
    return 0;
}
bool areEquals(vector<int> v1,vector<int> v2){
    int i;

    if(v1.size() != v2.size())return false;
    for(i=0;i<v1.size();i++){
        if(v1[i] != v2[i]){
            return false;
        }
    }
    return true;

}
