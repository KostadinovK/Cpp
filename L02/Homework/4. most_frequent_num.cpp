#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> frequent;
    int i,j,n,digit,counter=1,max=0,swap;
    cin >> n;
    int nums[n];
    for(i = 0;i<n;i++){
        cin >> nums[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(nums[i] == nums[j]){
                counter = counter + 1;
                digit = nums[i];
            }
        }
        if(counter >= max)max = counter;
        if(counter == max)frequent.push_back(digit);
        counter = 1;
        digit = -1;
    }

    for(i=0;i<frequent.size()-1;i++){
        for(j=i;j<frequent.size()-i-1;j++){
            if(frequent[j] > frequent[j+1]){
                swap = frequent[j+1];
                frequent[j+1] = frequent[j];
                frequent[j] = swap;
            }
        }
    }

    for(i=0;i<frequent.size();i++){
        cout << frequent[i] << " ";
    }
    return 0;
}
