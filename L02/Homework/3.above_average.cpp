#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> above_average;
    int i,n;
    float average = 0;
    do{
        cin >> n;
    }while(n < 1);
    int nums[n];
    for(i=0;i<n;i++){
        cin >> nums[i];
        average = average + nums[i];
    }
    average = average / n;

    for(i=0;i<n;i++){
        if(nums[i] >= average){
            above_average.push_back(nums[i]);
        }
    }

    for(i=0;i<above_average.size();i++){
        cout << above_average[i]<<" ";

    }
    return 0;
}
