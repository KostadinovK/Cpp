#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <sstream>
#include <vector>

using namespace std;

int sum(int,int);
int subtract(int,int);
int concat(int,int);


int main(){
    stack<int> numbers;
    vector<int> sortedNumbers;
    string currentComand;
    int number=1;
    while(cin >> currentComand){
        int num1,num2;

        if(currentComand == "sum"){
            num1 = numbers.top();
            numbers.pop();
            num2 = numbers.top();
            numbers.pop();
            int sumOfNums = sum(num1,num2);
            numbers.push(sumOfNums);
        }else if(currentComand == "subtract"){
            num1 = numbers.top();
            numbers.pop();
            num2 = numbers.top();
            numbers.pop();
            int subtractOfNums = subtract(num1,num2);
            numbers.push(subtractOfNums);
        }else if(currentComand == "concat"){
            num1 = numbers.top();
            numbers.pop();
            num2 = numbers.top();
            numbers.pop();
            int concatOfNums = concat(num1,num2);
            numbers.push(concatOfNums);
        }else if(currentComand == "discard"){
            numbers.pop();
        }else if(currentComand[0] >= '0' && currentComand[0] <= '9' || currentComand[0] == '-'){
            number = atoi(currentComand.c_str());
            numbers.push(number);
        }else if(currentComand == "end"){
            break;
        }else{
            cout << "This is not supported!"<<endl;
        }
    }
    while(!numbers.empty()){
        sortedNumbers.push_back(numbers.top());
        numbers.pop();

    }
    for(int i = sortedNumbers.size()-1;i>=0;i--){
        cout << sortedNumbers[i]<<" "<<endl;
    }

    return 0;
}

int sum(int num1,int num2){
    return num1+num2;
}
int subtract(int num1,int num2){
    return num1-num2;
}
int concat(int firstD, int secondD){
    if(secondD == 0){
        return firstD;
    }else{
        ostringstream stringed;
        stringed <<secondD<<firstD;
        istringstream sIn(stringed.str());
        int result;
        sIn >> result;
        return result;
    }
}
