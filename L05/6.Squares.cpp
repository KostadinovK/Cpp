#include <iostream>
#include <list>
#include <algorithm>

using namespace std;
int main(){

    list<int> numbers;
    int currentNum;
    while(cin >> currentNum){
        numbers.push_back(currentNum);
        if(cin.get() == '\n')break;
    }
    numbers.sort(greater<int>());
    for(auto i = numbers.begin();i != numbers.end();i++){

        for(int j = 0;j<=*i;j++){
            if(j*j == *i){
                cout << *i <<" ";
            }
        }
    }
    return 0;
}
