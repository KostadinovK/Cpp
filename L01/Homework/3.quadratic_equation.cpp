#include <iostream>
#include <cmath>
using namespace std;
int main(){
    float a,b,c,D;
    cin >> a >> b>>c;
    D = b*b - 4*a*c;
    if(D < 0)cout << "no roots" << endl;
    else if(D == 0)cout << -b/(2*a)<<endl;
    else cout << (-b + sqrt(D))/(2*a) <<" "<< (-b - sqrt(D))/(2*a)<<endl;
    return 0;
}
