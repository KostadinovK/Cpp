#include <iostream>

using namespace std;

int main(){
    int i,j,n,m,k=0,sum=0,currentWeight;
    do{
        cin >> n;
    }while(n < 1 || n > 100);
    do{
        cin >> m;
    }while(m < 1 || m > 100);

    int matrix[n][m];
    int res[m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            do{
                cin >> matrix[i][j];
            }while(matrix[i][j] < -100 || matrix[i][j] > 100);
        }
    }
    int weights[n];
    for(i=0;i<n;i++){
        do{
            cin >> weights[i];
        }while(weights[i] < -10 || weights[i] > 10);
    }

    for(j=0;j<m;j++){
        for(i=0;i<n;i++){
            sum = sum + matrix[i][j] * weights[i];
        }
        res[k] = sum;
        k++;
        sum = 0;
    }

    for(i=0;i<m;i++){
        cout << res[i] << " ";
    }
    return 0;
}
