#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main(){
    int num,inA = 0;
    vector <int> A;
    vector <int> B;
    while(cin >> num){
        A.push_back(num);
        if(cin.get() == '\n')break;
    }
    while(cin >> num){
        B.push_back(num);
        if(cin.get() == '\n')break;
    }
    priority_queue<int> C;
    for(int i = 0;i<A.size();i++){
        C.push(A[i]);
    }
    for(int i = 0;i < B.size();i++){
        C.push(B[i]);
    }
    vector<int> mergeOutput;
    stack<char>mergeSequence;
    while(!C.empty()){
        for(auto i = A.begin();i != A.end();i++){
            if (C.top() == *i){
                inA = 1;
                mergeSequence.push('A');
                break;
            }
        }
        if (inA == 0){
            mergeSequence.push('B');
        }
        inA = 0;
        mergeOutput.push_back(C.top());
        C.pop();
    }
    while(!mergeSequence.empty()){
        cout << mergeSequence.top();
        mergeSequence.pop();
    }
    cout<<endl;
    for(int i = 0;i < mergeOutput.size();i++){
        cout << mergeOutput[i] << " ";
    }
    return 0;
}
