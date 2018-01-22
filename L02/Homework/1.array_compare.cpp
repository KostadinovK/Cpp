#include <iostream>

using namespace std;

bool areEqual(int[] ,int,int[],int);
 int main(){
    int i,lenght1,lenght2;
    bool res;
    cin >> lenght1;
    int arr1[lenght1];
    for(i = 0;i<lenght1;i++){
        cin >> arr1[i];
    }

    cin >> lenght2;
    int arr2[lenght2];
    for(i = 0;i<lenght2;i++){
        cin >> arr2[i];
    }

    res = areEqual(arr1,lenght1,arr2,lenght2);

    if(res == true)cout << "equal"<<endl;
    else cout <<"not equal"<<endl;
    return 0;
 }

 bool areEqual(int arr1[],int lenght1,int arr2[],int lenght2){
    int i;
    if (lenght1 != lenght2) return false;
    for(i=0;i<lenght1;i++){
        if(arr1[i] != arr2[i]){
            return false;

        }
    }
    return true;
 }
