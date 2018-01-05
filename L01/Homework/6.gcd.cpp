#include <iostream>
using namespace std;

int main(){
    int a,b,min,i;
    cin >> a >> b;
    if(a >= b) min = b;
    else min = a;
    for(i=min;i>=0;i--){
        if(a % i == 0 && b % i == 0){
            cout << i << endl;
            break;
        }
    }
    return 0;
}
