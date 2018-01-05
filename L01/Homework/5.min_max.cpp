#include <iostream>

using namespace std;

int main(){
    int n,num,counts=0,min=1000000,max=0;
    cin >> n;
    do{
        cin >> num;
        counts = counts+1;
        if(num > max)max = num;
        if(num < min)min = num;
    }while(counts != n);
    cout << min <<" "<< max<<endl;
    return 0;
}
