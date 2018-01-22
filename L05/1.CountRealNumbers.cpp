#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    double currentNumber;
    vector <double> numbers;
    int count = 0;
    while(cin >> currentNumber){
        numbers.push_back(currentNumber);
        if(cin.get() == '\n')break;

    }
    set<double> res;
    for(int i = 0;i < numbers.size();i++){
        res.insert(numbers[i]);

    }
    for(auto i = res.begin();i != res.end();i++){
        for(int j = 0;j < numbers.size();j++){
            if (*i == numbers[j])count += 1;
        }
        cout << *i<< " -> "<<count<<endl;
        count = 0;

    }
    return 0;
}
