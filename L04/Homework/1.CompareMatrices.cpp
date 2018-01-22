#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;
bool areEqual(vector< vector<int> >,vector< vector<int> >);
int main(){
    int Matrix1Rows;
    int Matrix2Rows;
    cin >> Matrix1Rows;
    vector < vector<int> > matrix1;
    vector < vector<int> > matrix2;
    for(int i = 0;i<Matrix1Rows;i++){
        int num;
        vector<int> row;
        while(cin >> num){
            row.push_back(num);
            if(cin.get() == '\n')break;
        }
        matrix1.push_back(row);
    }
    cin >> Matrix2Rows;
    for(int i = 0;i<Matrix2Rows;i++){
        int num;
        vector<int> row;
        while(cin >> num){
            row.push_back(num);
            if(cin.get() == '\n')break;
        }
        matrix2.push_back(row);
    }
    bool equal = areEqual(matrix1,matrix2);
    if(equal == 1){
        cout << "equal" <<endl;
    }else{
        cout << "not equal" << endl;
    }
    return 0;
}

bool areEqual(vector< vector<int> > matrix1,vector< vector<int> > matrix2){
    if((matrix1.size() != matrix2.size()) || (matrix1[0].size() != matrix2[0].size())){
        return false;
    }

    for(int row = 0; row<matrix1.size();row++){
        for(int col = 0;col<matrix1[row].size();col++){
            if(matrix1[row][col] != matrix2[row][col]){
                return false;
            }
        }
    }
    return true;
}




