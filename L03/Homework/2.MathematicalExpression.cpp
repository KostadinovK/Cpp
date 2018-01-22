#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    string expression;
    char c;
    getline(cin,expression);
    vector <char> v;
    istringstream sIn(expression);
    int openb=0,closeb=0;
    while(sIn >> c){
        v.push_back(c);
    }

    for(int i = 0;i<v.size();i++){
        if(v[i] == '('){
            openb++;
        }
        if(v[i] == ')'){
            closeb++;
        }
    }
    if(openb != closeb){
        cout << "incorrect"<<endl;
    }else{
        cout << "correct"<<endl;
    }
    return 0;
}
