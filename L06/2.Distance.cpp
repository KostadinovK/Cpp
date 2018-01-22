#include <iostream>
#include <cmath>

using namespace std;
class Point{
public:
    int x;
    int y;

    Point(){

    }
    Point(int x,int y){
        this->x = x;
        this->y = y;
    }

    double distanceTo(Point p){
        return(sqrt(pow((p.x - this->x),2) + pow((p.y - this->y),2)));
    }
};
int main(){

    Point p1,p2;
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    double distance = p1.distanceTo(p2);
    cout << distance << setprecision(3)<<endl;
    return 0;
}
