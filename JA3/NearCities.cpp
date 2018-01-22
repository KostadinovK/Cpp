#include <iostream>
#include "JA3-Task-2-Near-Cities_Vector2D.h.h"
#include <vector>
#include <sstream>
using namespace std;

int main(){
    vector< pair<string,Vector2D> > cities;
    vector<pair<string,Vector2D> > distances;
    int citiesNums;
    cin >> citiesNums;
    for(int i =0;i<citiesNums;i++){
        string cityName;
        double x,y;
        cin >> cityName >> x >> y;
        Vector2D vec(x,y);
        cities.push_back(pair<string,Vector2D>(cityName,vec));
    }

    double minDistance=999999999;
    string city1,city2;


    for(int i = 0;i < cities.size();i++){
        for(int j = i;j < cities.size();j++){
            ostringstream sOut;
            if(cities[i].first != cities[j].first){

                Vector2D distance = cities[i].second - cities[j].second;
                sOut << cities[i].first<<"-"<<cities[j].first;
                string route = sOut.str();
                distances.push_back(pair<string,Vector2D>(route,distance));
                if(distance.getLength() < minDistance){
                    minDistance = distance.getLength();

                }
            }
        }
    }
    for(int i = 0;i<distances.size();i++){
        if(minDistance == distances[i].second.getLength()){
            cout << distances[i].first <<endl;
            break;
        }

    }

    return 0;
}
