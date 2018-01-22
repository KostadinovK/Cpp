#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int heximalToDecimal(char,char);
void printAverageColour(int,int,int);
void decimalToHeximal(int,char*,char*);
int main(){
    string c1,c2;
    cin >> c1 >> c2;
    int red1 = heximalToDecimal(c1[1],c1[2]);
    int red2 = heximalToDecimal(c2[1],c2[2]);
    int green1 = heximalToDecimal(c1[3],c1[4]);
    int green2 = heximalToDecimal(c2[3],c2[4]);
    int blue1 = heximalToDecimal(c1[5],c1[6]);
    int blue2 = heximalToDecimal(c2[5],c2[6]);
    int red3 = (red1+red2)/2;
    int green3 = (green1+green2)/2;
    int blue3 = (blue1+blue2)/2;
    printAverageColour(red3,green3,blue3);


    return 0;
}

int heximalToDecimal(char firstD,char secondD){
    int num;
    int digit1;
    int digit2;
    if(firstD == 'f'){
        digit1 = 15*(pow(16,1));
    }else if(firstD == 'e'){
        digit1 = 14*(pow(16,1));
    }else if(firstD == 'd'){
        digit1 = 13*(pow(16,1));
    }else if(firstD == 'c'){
        digit1 = 12*(pow(16,1));
    }else if(firstD == 'b'){
        digit1 = 11*(pow(16,1));
    }else if(firstD == 'a'){
        digit1 = 10*(pow(16,1));
    }else{
        digit1 = (firstD - '0')*(pow(16,1));
    }

    if(secondD == 'f'){
        digit2 = 15*(pow(16,0));
    }else if(secondD == 'e'){
        digit2 = 14*(pow(16,0));
    }else if(secondD == 'd'){
        digit2 = 13*(pow(16,0));
    }else if(secondD == 'c'){
        digit2 = 12*(pow(16,0));
    }else if(secondD == 'b'){
        digit2 = 11*(pow(16,0));
    }else if(secondD == 'a'){
        digit2 = 10*(pow(16,0));
    }else{
        digit2 = (secondD - '0')*(pow(16,0));
    }

    num = digit1 + digit2;
    return num;
}


void printAverageColour(int red,int green,int blue){
    char c1 = ' ',c2 = ' ';
    decimalToHeximal(red,&c1,&c2);

    cout <<"#"<<c1<<c2;
    decimalToHeximal(green,&c1,&c2);
    cout <<c1<<c2;
    decimalToHeximal(blue,&c1,&c2);
    cout <<c1<<c2<<endl;
}

void decimalToHeximal(int number,char *c1,char *c2){
    int digit1 = number / 16;
    int digit2 = number % 16;
    switch(digit1){
    case 15: *c1 = 'f';break;
    case 14: *c1 = 'e';break;
    case 13: *c1 = 'd';break;
    case 12: *c1 = 'c';break;
    case 11: *c1 = 'b';break;
    case 10: *c1 = 'a';break;
    default: *c1 = digit1 + '0';break;
    }
    switch(digit2){
    case 15: *c2 = 'f';break;
    case 14: *c2 = 'e';break;
    case 13: *c2 = 'd';break;
    case 12: *c2 = 'c';break;
    case 11: *c2 = 'b';break;
    case 10: *c2 = 'a';break;
    default: *c2 = digit2 + '0';break;
    }
}
