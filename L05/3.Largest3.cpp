#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(){

    vector<double>numbers;
    double currentNum;
    while(cin >> currentNum){
        numbers.push_back(currentNum);
        if(cin.get() == '\n')break;
    }
    sort(numbers.begin(),numbers.end());

    if(numbers.size() >= 3){
        for(int i = numbers.size()-1;i>=numbers.size()-3;i--){
            cout << numbers[i] << " ";
        }
    }else{
        for(int i = numbers.size()-1;i>=0;i--){
            cout << numbers[i] << " ";
        }
    }

    return 0;
}
