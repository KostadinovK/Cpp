#include <iostream>

using namespace std;

int main(){
    float first,second,third,neg_nums=0;;
    cin >> first;
    if(first < 0)neg_nums=neg_nums+1;
    cin >> second;
    if(second < 0)neg_nums=neg_nums+1;
    cin >> third;
    if(third < 0)neg_nums=neg_nums+1;
    if(neg_nums == 1 || neg_nums==3)cout << "-" <<endl;
    else cout << "+" <<endl;
    return 0;
}
