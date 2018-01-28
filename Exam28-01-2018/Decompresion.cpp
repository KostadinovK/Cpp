#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int main(){
    string line;
    getline(cin,line);
    stack<int> numbers;
    ostringstream deComp;
    for(int i = 0;i<line.size();i++){
        if(isdigit(line[i])){
            int num = line[i] - '0';
            if(numbers.empty()){
                numbers.push(num);
            }else{
                int oldNum = numbers.top();
                numbers.pop();
                ostringstream reNumber;
                reNumber << oldNum << num;
                istringstream toInt(reNumber.str());
                int number;
                toInt >> number;
                numbers.push(number);
            }
        }else{
            if(numbers.empty()){
                deComp << line[i];
            }else{
                int num = numbers.top();
                numbers.pop();
                for(int j = 0;j < num;j++){
                    deComp << line[i];
                }
            }

        }
    }
    cout << deComp.str()<<endl;
    return 0;
}
