#include <iostream>

using namespace std;
int main(){
    int i=0,n,count = 0;
    cin >> n;
    for(i=5; n/i >= 1;i *= 5){
        count = count + n/i;
    }
    cout << count<<endl;
    return 0;
}
