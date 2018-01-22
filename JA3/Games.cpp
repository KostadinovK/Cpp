#include <iostream>
#include <vector>
#include <sstream>
#include <set>
using namespace std;

class Team{
private:
    string name;
    int playersNumber;
    vector<string> players;
public:
    Team(){

    }
    Team(string name,int playersNumber,vector<string> players){
        this->name = name;
        this->playersNumber = playersNumber;
        this->players = players;
    }

    void changeName(string name){
        this->name = name;
    }
    void changePlayers(vector<string> players){
        this->players = players;
    }
    void changePlayersNumber(int playersNumber){
        this->playersNumber = playersNumber;
    }
    string getName(){
        return this->name;
    }
    int getPlayersNumber(){
        return this->playersNumber;
    }
    vector<string> getPlayers(){
        return this->players;
    }
    string getInfo(){
        ostringstream info;
        info << this->name <<" "<< this->playersNumber << " ";
        for(int i = 0;i<this->playersNumber;i++){
            info << players[i] << " ";
        }
        return info.str();
    }
};
int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int teamsNumber;
    cin >> teamsNumber;
    vector<Team> teams;
    set<string> pNames;
    for(int i = 0;i<teamsNumber;i++){
        Team currentTeam;
        string teamName,playerName;
        int playersNumber;
        vector<string> players;
        cin >> teamName >> playersNumber;
        for(int j = 0;j < playersNumber;j++){
            cin >> playerName;
            pNames.insert(playerName);
            players.push_back(playerName);
        }
        currentTeam.changeName(teamName);
        currentTeam.changePlayersNumber(playersNumber);
        currentTeam.changePlayers(players);
        teams.push_back(currentTeam);
    }
    vector<string> winners;
    int gamesNumber;
    cin >> gamesNumber;
    for(int i = 0;i < gamesNumber;i++){
        string currentWinner;
        cin >> currentWinner;
        winners.push_back(currentWinner);
    }
    vector< pair<string,int> > nameAndScore;
    for(auto i = pNames.begin();i != pNames.end();i++){
        string name = *i;
        pair<string,int> paired;
        paired.first = name;
        nameAndScore.push_back(paired);
    }

    vector<string> namesOfWinners;
    for(int i = 0;i<gamesNumber;i++){
        for(int j = 0;j<teamsNumber;j++){
            if(winners[i] == teams[j].getName()){
                   vector<string> players = teams[j].getPlayers();
                   for(int i = 0;i<players.size();i++){
                        namesOfWinners.push_back(players[i]);
                   }
            }
        }
    }
    for(int i = 0;i<nameAndScore.size();i++){
            int score=0;
        for(int j = 0;j<namesOfWinners.size();j++){
            if(nameAndScore[i].first == namesOfWinners[j]){
                score++;
                nameAndScore[i].second = score;
            }
        }
    }
    for(int i = 0;i<nameAndScore.size();i++){
        cout <<nameAndScore[i].second<<" ";
    }
    return 0;
}

