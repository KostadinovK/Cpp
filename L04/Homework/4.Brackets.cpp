#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main(){

    string Brackets;
    getline(cin,Brackets);
    int valid = 1;
    for(int i = 0;i<Brackets.size();i++){
        if(Brackets[i] == '{'){
            if(Brackets[i+1] == ']' || Brackets[i+1] == ')'){
                cout << "invalid"<<endl;
                valid = 0;
                break;
            }
        }else if(Brackets[i] == '['){
            if(Brackets[i+1] == '}' || Brackets[i+1] == ')' || Brackets[i+1] == '{'){
                cout <<"invalid"<<endl;
                valid = 0;
                break;
            }
        }else if(Brackets[i] == '('){
            if(Brackets[i+1] == '[' || Brackets[i+1] == '{' || Brackets[i+1] == ']' || Brackets[i+1] == '}'){
                cout << "invalid"<<endl;
                valid = 0;
                break;
            }
        }else if(Brackets[i] == '}'){
            if(Brackets[i+1] == ']' || Brackets[i+1] == ')'){
                cout << "invalid" << endl;
                valid = 0;
                break;
            }
        }else if(Brackets[i] == ']'){
            if(Brackets[i+1] == ')'){
                cout << "invalid"<<endl;
                valid = 0;
                break;
            }
        }
    }
        if(valid == 1){
            cout << "valid"<<endl;
        }
    return 0;
}
