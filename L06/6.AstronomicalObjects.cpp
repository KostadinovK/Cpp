#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

enum  AstroType{star, rockyPlanet, gasGiant, unknown};
class AstroObj{

private:
    string solarSystem;
    int pos;
    size_t massKg;
    size_t radius;
    AstroType type;
    string nickname;

    string getTypeString(AstroType type){
        switch(type){
        case 0:
            return "star";break;
        case 1:
            return "rocky planet";break;
        case 2:
            return "gas giant";break;
        case 3:
            return "unknown";break;
        default:
            return "error";break;
        }
    }
public:
    AstroObj(){
        this->nickname = "-";
        this->type = unknown;
    }
    AstroObj(string solarSystem,int pos,int massKg,int radius,AstroType type,string nickname){
        this->solarSystem = solarSystem;
        this->pos = pos;
        this->massKg = massKg;
        this->radius = radius;
        this->type = type;
        this->nickname = nickname;
    }
    AstroObj(string solarSystem,int pos,int massKg,int radius,AstroType type){
        this->solarSystem = solarSystem;
        this->pos = pos;
        this->massKg = massKg;
        this->radius = radius;
        this->type = type;
        this->nickname = "-";

    }
    void setSolarSystem(string name){
        this->solarSystem = name;
    }
    void setNickname(string name){
        this->nickname = name;
    }
    void setPos(int pos){
        if(this->type != star){
            this->pos = pos;
        }
    }
    void setMass(size_t mass){
        this->massKg = mass;
    }
    void setRadius(size_t radius){
        this->radius = radius;
    }
    void changeType(AstroType type){

        if(this->type == unknown && type != unknown){
            this->type = type;
        }
        if(this->type == star){
            this->pos = 1;
        }
    }
    string getSolarSystem(){
        return this->solarSystem;
    }
    string getNickname(){
        return this->nickname;
    }
    int getPos(){
        return this->pos;
    }
    size_t getMass(){
        return this->massKg;
    }
    size_t getRadius(){
        return this->radius;
    }
    string getType(){
        if(this->type == star)return "star";
        else if(this->type == unknown)return "unknown";
        else if(this->type == rockyPlanet)return "rockyPlanet";
        else return "gasGiant";

    }
    string getInfo(){
        ostringstream info;
        string typeStr = getTypeString(this->type);
        info << "solar system: " << this->solarSystem<<endl
        <<"position: " << this->pos<<endl
        <<"massKg: " << this->massKg<<endl
        <<"radius: " << this->radius<<endl
        <<"type: " <<typeStr <<endl
        <<"nickname: " << this->nickname<<endl;
        return info.str();
    }
};
AstroType stringToEnum(string typestr);
void writeDataFile(string);
vector <AstroObj> readFromDataFile(string);
int main(){
    cout << "1.Write data"<<endl
    <<"2.Read Data"<<endl;
    int choice;
    cout << "choice: ";
    cin >> choice;
    if(choice == 1){
        string fileName;
        cout <<"Enter name of datafile that you want to write(universe.txt): ";
        cin >> fileName;
        writeDataFile(fileName);
    }else{
        string fileName;
        cout <<"Enter name of datafile that you want to read(universe.txt): ";
        cin >> fileName;
        vector<AstroObj> objects = readFromDataFile(fileName);

        cout <<"1.Search all planets by solar system"<<endl
        <<"2.Search all planets by nicknames and positions"<<endl
        <<"3.Read all"<<endl;
        int choice2;
        cin >> choice2;
        if(choice2 == 1){
            string solarName;
            cout <<"solar system name: ";
            cin >> solarName;
            for(int i = 0;i<objects.size();i++){
                if(objects[i].getSolarSystem() == solarName){
                    if(objects[i].getNickname() != "-"){
                       cout <<objects[i].getSolarSystem() <<"-"<<objects[i].getPos() <<" (" << objects[i].getNickname() << ") " << "{" << "mass: " <<
                       objects[i].getMass() <<", radius: "<< objects[i].getRadius() <<"}";
                    }else{
                       cout <<objects[i].getSolarSystem() <<"-"<<objects[i].getPos() <<" {" << "mass: " <<
                       objects[i].getMass() <<", radius: "<< objects[i].getRadius() <<"}";
                    }

                }
                cout << endl;
            }

        }else if(choice2 == 2){
            string nickName;
            int pos;
            cout << "Enter nickname and position of the planet(for a planet without a nick, enter - at nickname): ";
            cin >> nickName >> pos;
            for(int i = 0;i<objects.size();i++){
                if(objects[i].getNickname() == nickName && objects[i].getPos() == pos){
                    if(objects[i].getNickname() != "-"){
                       cout <<objects[i].getSolarSystem() <<"-"<<objects[i].getPos() <<" (" << objects[i].getNickname() << ") " << "{" << "mass: " <<
                       objects[i].getMass() <<", radius: "<< objects[i].getRadius() <<"}";
                    }else{
                       cout <<objects[i].getSolarSystem() <<"-"<<objects[i].getPos() <<" {" << "mass: " <<
                       objects[i].getMass() <<", radius: "<< objects[i].getRadius() <<"}";
                    }
                }
                cout <<endl;
            }

        }else{
            for(int i = 0;i<objects.size();i++){
                if(objects[i].getNickname() != "-"){
                       cout <<objects[i].getSolarSystem() <<"-"<<objects[i].getPos() <<" (" << objects[i].getNickname() << ") " << "{" << "mass: " <<
                       objects[i].getMass() <<", radius: "<< objects[i].getRadius() <<"}";
                    }else{
                       cout <<objects[i].getSolarSystem() <<"-"<<objects[i].getPos() <<" {" << "mass: " <<
                       objects[i].getMass() <<", radius: "<< objects[i].getRadius() <<"}";
                    }
                cout <<endl;
            }


        }
    }



    return 0;
}
AstroType stringToEnum(string typestr){
    AstroType type;
    if(typestr == "star")type = star;
    else if(typestr == "rockyPlanet")type = rockyPlanet;
    else if(typestr == "gasGiant")type = gasGiant;
    else if(typestr == "unknown")type = unknown;

    return type;

}
void writeDataFile(string fileName){
    ofstream write(fileName,std::ios::app);
    int objCount;
    cin >> objCount;
    vector <AstroObj> objects;
    for(int i = 0;i<objCount;i++){
        AstroObj obj;
        string solarName,nickname;
        int pos;
        size_t mass,rad;
        string typestr;
        cin >> solarName >> pos >> mass >> rad >> typestr >> nickname;

        obj.setSolarSystem(solarName);
        obj.setPos(pos);
        obj.setMass(mass);
        obj.setRadius(rad);
        AstroType type = stringToEnum(typestr);
        obj.changeType(type);
        obj.setNickname(nickname);
        objects.push_back(obj);
    }
    for(int i = 0;i<objects.size();i++){
        write << objects[i].getSolarSystem()<<endl<< objects[i].getPos()<<endl<< objects[i].getMass() <<endl<< objects[i].getRadius()
        <<endl<< objects[i].getType() <<endl<< objects[i].getNickname()<<endl;
    }
    write.close();
}
vector<AstroObj> readFromDataFile(string fileName){
    ifstream read(fileName);
    vector <AstroObj> objects;
    string solarName,nickname;
    int pos;
    size_t mass,rad;
    string typestr;
    while(read >> solarName >> pos >> mass >> rad >> typestr >> nickname){
    AstroObj obj;
    obj.setSolarSystem(solarName);
    obj.setPos(pos);
    obj.setMass(mass);
    obj.setRadius(rad);
    AstroType type = stringToEnum(typestr);
    obj.changeType(type);
    obj.setNickname(nickname);
    objects.push_back(obj);
    }
    read.close();
    return objects;
    //for(int i = 0;i<objects.size();i++){
        //cout << objects[i].getInfo()<<endl;
    //}
}
