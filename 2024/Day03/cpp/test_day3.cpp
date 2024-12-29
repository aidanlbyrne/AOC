#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

/*

    for (int i = 0; i < input.size(); i++) {
        char c = input[i];
        printf("%c\n", c);
        if (c == 'm') {
            printf("found one! starting logic loop\n");
        }
    }
*/

bool checkInt(int& pos, string& line) {
    if ()
}

void getProducts(string& line) {
    string mul = "mul(";
    size_t pos = line.find(mul);
    while (pos != string::npos) {
        cout << "pos: " << pos << endl;
        cout << "pos: " << pos+4 << endl;
        cout << "char: " << line[pos+4] << endl;
                
        pos = line.find(mul, pos+1);
    }
    return;
}

int main(int argc, char** argv) {
    
    string input;

    getline(cin, input);

    getProducts(input);

    return 0;
}
