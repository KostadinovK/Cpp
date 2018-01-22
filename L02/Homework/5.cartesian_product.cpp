#include <iostream>
#include <vector>

using namespace std;

int main(){
    int i,j,k=0,n;
    cin >> n;
    int nums[n];
    int products[n*n];
    for(i=0;i<n;i++){
        cin >> nums[i];
    }
    if(n != 1){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                products[k] = nums[i]*nums[j];
                k++;
            }
        }


        for(i=0;i<k;i++){
            cout << products[i] << " ";
        }
    }else{
        cout << nums[0];
    }
    return 0;
}
