#include <iostream>
#include <string>
#include "JA3-Task-1-Big-Division_BigInt.h.h"
using namespace std;
bool isDivisibleBy45(string);
int main(){
    string n1,n2;
    getline(cin,n1);
    getline(cin,n2);
    BigInt number1 (n1);
    BigInt number2 (n2);
    BigInt i;
    string currentNumber;
    for(i = number1; i < number2;i+=1){
        currentNumber = i.getDigits();
        bool isDivisble = isDivisibleBy45(currentNumber);
        if(isDivisble){
            cout << i.getDigits()<<endl;
        }
    }
    return 0;
}
bool isDivisibleBy45(string number){
    int sum=0;
    if(number[number.size()-1] == '0' || number[number.size()-1] == '5'){
        for(int i =0;i<number.size();i++){
            sum += number[i] - '0';
        }
        if(sum % 9 == 0)return true;
        else return false;
    }
}
