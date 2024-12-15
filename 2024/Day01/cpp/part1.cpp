#include<iostream>
#include<string>
#include<cstdio>
#include <vector>

using namespace std;

string current_line;

void parseInput(vector<int>& left, vector<int>& right) {
    
    int intLeft, intRight;

    while(cin >> intLeft >> intRight) {
        left.push_back(intLeft);
        right.push_back(intRight);
    }
}

int main()
{
    vector<int> left, right;

    parseInput(left, right);

    for (int num : left) {
        printf("%d\n", num);
    }

    return 0;
}
