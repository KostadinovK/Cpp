#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){

    int i,n,trainTime;
    do{
        cin >> n;
    }while(n < 1 || n > 20);
    int times[n];
    for(i=0;i<n;i++){
        cin >> times[i];
    }
    cin >> trainTime;

    for(i=0;i<n;i++){
       if(times[i] / 1000 < 0){
            times[i] = times[i] % 1000;
       }
       int minutesIntoHours = (times[i] / 100) * 60;
       int minutes = times[i] % 100;
       times[i] = minutesIntoHours + minutes;
    }

    if(trainTime / 1000 < 0){
        trainTime = trainTime % 1000;
    }
    int trainMinutes = ((trainTime / 100)*60) + trainTime%100;

    int waitingTime[n];

    for(i=0;i<n;i++){
        waitingTime[i] = abs(trainMinutes - times[i]);
    }
    int min = INT_MAX;
    for(i=0;i<n;i++){
        if(waitingTime[i] < min)min = waitingTime[i];
    }

    cout << min << endl;



    return 0;
}
