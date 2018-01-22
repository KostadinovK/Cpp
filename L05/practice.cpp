#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    map<string,int> namedNumbers{
      {"one", 1},
      {"two", 2},
      {"three", 3},
      {"four",4}
    };

    string name;
    cin >> name;

    cout <<  namedNumbers[name]<<endl;

    for(auto i = namedNumbers.begin();i!=namedNumbers.end();i++){

            cout << i->first << " "<<i->second<<endl;

    }
    return 0;
}
