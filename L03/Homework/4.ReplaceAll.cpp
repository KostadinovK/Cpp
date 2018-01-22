#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
void getString(char *,char *,int,int);
int main(){

    int match = 1,i,j;
    char line[200],searchFor[200],replaceWith[200];
    gets(line);

    gets(searchFor);
    gets(replaceWith);
    char l[200],r[200],change[200];

    for(i = 0;i < strlen(line);i++){
        if(searchFor[0] == line[i]){
            match = 1;
            for(j = 1;j<strlen(searchFor);j++){
                i++;
                if(line[i] != searchFor[j]){
                    match = 0;
                    break;
                }
            }
                if(match == 1){
                    getString(l,line,0,i-j);
                    getString(r,line,i+1,strlen(line)-1);
                    if(strlen(l) > 0){
                        strcpy(change,l);
                    }
                    strcat(change,replaceWith);
                    if(strlen(r) > 0){
                        strcat(change,r);
                    }
                    change[100] = '\0';
                    strcpy(line,change);
                }
            }
        }

    cout << line<<endl;
    return 0;
}
void getString(char *str1,char *str2,int j,int end){
    int i;
    for(i=0;j<=end;i++)
    {
        str1[i]=str2[j];
        j++;
    }
    str1[i]='\0';
}

