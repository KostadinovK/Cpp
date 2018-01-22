
#include<iostream>
#include<iomanip>

using namespace std;

int toDecimal(char c) {
    if (c >= 'a') {
        return 10 + (c - 'a');
    } else {
        return c - '0';
    }
}

int main() {
    char line[5];
    int xorred = 0,num,i;
    while (cin >> line[0]) {
        if (line[0] == '.') {
            break;
        }
        cin >> line[1] >> line[2] >> line[3] >> line[4];

        num = 0;
        for (i = 0; i < 5; i++) {
            num = num * 16;
            num = num + toDecimal(line[i]);
        }

        xorred = xorred ^ num;
    }

    cout << hex << setfill('0') << setw(5) << xorred << endl;
}

