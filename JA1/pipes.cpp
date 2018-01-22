#include <iostream>

using namespace std;

int main(){
    int i,n;
    do{
        cin >> n;
    }while(n > 500 || n < 1);
    int lastYearChecks[n];
    int thisYearChecks[n];
    int years[n];
    for(i=0;i<n;i++){
        do{
            cin >> lastYearChecks[i];
        }while(lastYearChecks[i] > 1000000000 || lastYearChecks[i] < 1);

    }
    for(i=0;i<n;i++){
        do{
            cin >> thisYearChecks[i];
        }while(thisYearChecks[i] < 0 || thisYearChecks[i] > lastYearChecks[i]);
    }

    for(i=0;i<n;i++){
        int difference = lastYearChecks[i] - thisYearChecks[i];
        if(difference > thisYearChecks[i]){
            years[i] = 0;
        }else if(difference == thisYearChecks[i]){
            years[i] = 1;
        }else{
            years[i] = thisYearChecks[i] / difference;
        }
    }

    for(i=0;i<n;i++){
        cout << years[i] << " ";
    }
    return 0;
}
