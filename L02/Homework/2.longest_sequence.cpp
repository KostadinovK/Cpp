#include <iostream>
#include <vector>
using namespace std;
vector<int> longest_sequence(int[],int);
void print(vector<int>);
int main(){
    vector<int> sequence;
    int i,j,counter=1,n,max = 0,digit=0;
    cin >> n;
    int nums[n];
    for(i=0;i<n;i++){
        cin >> nums[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(nums[i] != nums[j]){
                if(counter >= max){
                    max = counter;
                    digit = nums[i];
                }
                counter = 1;
                digit = nums[i+1];
                break;
            }
            counter = counter+1;
        }
    }
    print(longest_sequence(nums,n));


    for(i=0;i<sequence.size();i++){
        cout << sequence[i]<<" ";

    }
    return 0;
}

void print(vector<int> nums){
    int i;
    for(i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;

}

vector<int> longest_sequence(int arr[], int size){
    int max = 0;
    int count = 1;
    int i,digit=0;
    vector<int> sequence;
    for(i = 1; i < size; i++){
        if(arr[i] == arr[i-1]){
            count++;
        }else{
            if(count > max){
                max = count;
                digit = arr[i-1];
            }

            count = 1;
        }
    }
    for(i=0;i<max;i++){
        sequence.push_back(digit);
    }
    return sequence;
}

