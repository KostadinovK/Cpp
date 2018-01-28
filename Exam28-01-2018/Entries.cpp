#include <iostream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;
typedef map<string,string> lineInData;
lineInData writeInData(string line,vector<string>keys){
    istringstream write(line);
    lineInData result;
    int i = 0;
    while(write.good()){
        string key,value;
        key = keys[i];
        i++;
        write >> value;
        result[key] = value;
    }
    return result;
}
int main(){
    vector<lineInData> database;
    string line;
    getline(cin,line);
    vector<string> keys;
    istringstream sIn(line);
    string currentKey;
    while(sIn >> currentKey){
        keys.push_back(currentKey);
    }
    string entry;
    getline(cin,entry);
    while(entry != "end"){
        database.push_back(writeInData(entry,keys));
        getline(cin,entry);
    }
    string searchBy;
    getline(cin,searchBy);
    map<string,int> ocurrences;
    for(int i = 0; i<database.size();i++){
        auto currentFind = database[i].find(searchBy);
        //cout << currentFind->second<<endl;
        ocurrences[currentFind->second]++;
    }
    /**for(int i = 0; i<database.size();i++){
        for(auto j = database[i].begin(); j != database[i].end();j++){
            cout << "key = " << j->first << " value = " << j->second<<endl;
        }
    }**/
    int maxNum = -999999;
    for(auto i = ocurrences.begin();i != ocurrences.end();i++){
        //cout << i->first << "-" << i->second<<endl;
        if(i->second > maxNum)maxNum = i->second;
    }
    for(auto i = ocurrences.begin();i != ocurrences.end();i++){
        if(i->second == maxNum){
            cout << i->first <<" "<<i->second<<endl;
        }
    }
    return 0;
}
