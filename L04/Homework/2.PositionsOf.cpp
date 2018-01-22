#include <iostream>
#include<vector>

using namespace std;

int main(){
    int rows,cols;
    cin >> rows;
    cin >> cols;
    int matrix[rows][cols];
    int num;
    int search_for, isInMatrix = 0;
    for(int i = 0;i < rows;i++){
        for(int j = 0;j<cols;j++){
            cin >> num;
            matrix[i][j] = num;
        }
    }
    cin >> search_for;

    for(int i = 0;i < rows;i++){
        for(int j = 0;j<cols;j++){
            if(matrix[i][j] == search_for){
                cout << i <<" "<<j<<endl;
                isInMatrix = 1;
            }
        }
    }
    if (isInMatrix == 0){
        cout << "not found"<<endl;
    }
    return 0;
}
