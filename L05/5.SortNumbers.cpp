#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> nums;
    int currentNum;
    while(cin >> currentNum){
        nums.push_back(currentNum);
        if(cin.get() == '\n')break;
    }
    nums.sort();
    cout << *(nums.begin());
    auto secondNum = nums.begin();
    secondNum++;
    for(auto i = secondNum;i != nums.end();i++){
        cout <<" <= "<< *i;
    }
    return 0;
}

