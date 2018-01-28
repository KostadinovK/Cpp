#include <iostream>
#include <string>

using namespace std;

int main(){
    const string alphabet{"abcdefghijklmnopqrstuvwxyz"};
    string line;
    getline(cin,line);
    int isIn=0;
    string unused;
    for(int i = 0;i < alphabet.size();i++){
        for(int j = 0;j < line.size();j++){
            if(line[j] == alphabet[i]){
                isIn = 1;
                break;
            }
        }
        if(isIn == 0){
            unused += alphabet[i];
            isIn;
        }
        isIn = 0;
    }
    cout << unused<<endl;
    return 0;
}
