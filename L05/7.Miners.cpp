#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    vector<string> resourceNames;
    unordered_map<string, int> resources;
    string currResource;
    int currNum;
    while(cin >> currResource){
        if(currResource == "stop")break;
        cin >> currNum;
        if(resources.find(currResource) != resources.end() && currResource != "stop"){
            resources[currResource] += currNum;
        }else if(resources.find(currResource) == resources.end() && currResource != "stop"){
            resources[currResource] = currNum;
            resourceNames.push_back(currResource);
        }
    }
    for(int i = 0;i<resourceNames.size();i++){
        cout << resourceNames[i] << " -> " << resources[resourceNames[i]]<<endl;
    }
    return 0;
}
