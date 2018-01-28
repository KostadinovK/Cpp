#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;
typedef map<char,char> encryption;
const string original {"abcdefghijklmnopqrstuvwxyz"};

encryption makeEncryption(string);
bool isRightEncrypted(string,encryption,string);
string encryptOtherWords(string,encryption);

int main(){
    string keyWord;
    getline(cin,keyWord);
    //message insertion
    string message;
    getline(cin,message);
    vector<string> messages;
    while(message != "[encryptions]"){
        messages.push_back(message);
        getline(cin,message);
    }
    string table;
    getline(cin,table);
    vector<string> tables;//only string of the tables
    vector<encryption> enTables;//maps of the tables
    //tables insertion
    while(table != "[end]"){
        encryption enTable = makeEncryption(table);
        enTables.push_back(enTable);
        tables.push_back(table);
        getline(cin,table);
    }
    map<string,vector<string>> messagesByTables;
    //encrypt the firsts word of messages
    //if the first word is true encrypt other words of the message
    for(int i = 0;i < messages.size();i++){
        string currentMessage = messages[i];
        string firstWord;
        for(int j = 0;j < keyWord.size();j++){
            firstWord += currentMessage[j];
        }
        //cout << firstWord<<endl;
        for(int j = 0;j < enTables.size();j++){
            if(isRightEncrypted(firstWord,enTables[j],keyWord)){
                string encryptedMessage = encryptOtherWords(messages[i],enTables[j]);
                messagesByTables[tables[j]].push_back(encryptedMessage);
                //cout << encryptedMessage<<endl;
                break;
            }
        }

    }
    int maxNum = -1;
    for(auto i = messagesByTables.begin();i != messagesByTables.end();i++){
            int mesSize = (i->second).size();
        if(mesSize > maxNum){
            maxNum = mesSize;
            //cout << "size = " << (i->second).size()<<endl;
        }
    }
    for(auto i = messagesByTables.begin(); i != messagesByTables.end();i++){
        if((i->second).size() == maxNum){
            for(int j = 0;j < (i->second).size();j++){
                cout << i->second[j]<<endl;
            }
        }

    }
     /**for(auto i = messagesByTables.begin(); i != messagesByTables.end();i++){
        for(int j = 0;j < (i->second).size();j++){
            cout << i->second[j]<<endl;
        }
    }**/
    return 0;
}
encryption makeEncryption(string table){
    encryption res;
    for(int i = 0;i < table.size();i++){
        res[table[i]] = original[i];
    }
    return res;
}
bool isRightEncrypted(string word,encryption table,string keyWord){
    ostringstream encryptedWord;
    for(int i = 0;i < word.size();i++){
        char c = word[i];
        if(c != ' '){
            char enC = table[c];
            encryptedWord << enC;
        }else{
            encryptedWord << c;
        }
    }
    if(encryptedWord.str() == keyWord){
        return true;
    }else{
        return false;
    }
}
string encryptOtherWords(string message,encryption table){
    ostringstream result;
    for(int i = 0;i < message.size();i++){
        char letter = message[i];
        if(letter != ' '){
            char enLetter = table[letter];
            result << enLetter;
        }else{
            result << letter;
        }
    }

    return result.str();
}
