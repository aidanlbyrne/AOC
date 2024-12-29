#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
/*
    General idea of part 1:
    look for 'm'
    once 'm' is found, enter logic loop looking for 'mul('
*/

// parse the file into a stream

// check for mul(

//  bool func to check for 1 to 3 ints: keep checking until delimiter of ','

bool checkInt(int& i, string& line) {

}

void parse(vector<string>& lines) {

    string line;

    while (getline(cin, line)) {
        lines.push_back(line);
    }
}

void getProducts(vector<int>& products, vector<string>& lines) {
    string mul = "mul(";
    for (auto line : lines) {
        size_t pos = line.find(mul);
        while (pos != string::npos) {
            cout << "pos: " << pos << endl;
            pos = line.find(mul, pos+1);
        }
    }
}

int main(int argc, char** argv) {

    vector<string> lines;
    vector<int> products;

    parse(lines);

    return 0;
}
