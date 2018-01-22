#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int i,j,n,min = INT_MAX;
    cin >> n;
    int nums[n];
    vector<int> differences;
    for(i=0;i<n;i++){
        cin >> nums[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i!=j){
                differences.push_back(abs(nums[i]-nums[j]));
            }
        }
    }
    for(i=0;i<differences.size();i++){
        if(differences[i] < min){
            min = differences[i];
        }
    }
    cout <<min<<endl;
    return 0;
}
