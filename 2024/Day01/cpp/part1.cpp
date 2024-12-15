#include <algorithm>
#include<iostream>
#include<string>
#include<cstdio>
#include <unordered_map>
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

int part1(vector<int>& left, vector<int>& right) {

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    
    printf("sorted\n\n");

    for (int i = 0; i < left.size(); i++) {
        printf("%d   %d\n", left[i], right[i]);
    }

    int distance = 0;
    for (int i = 0; i < left.size(); i++) {
        int dis = abs(left[i] - right[i]);
        printf("dis: %d\n",dis);
        distance += abs(left[i] - right[i]);
        printf("dis: %d\n",distance);
    }

    return distance;
}

int part2(vector<int>& left, vector<int>& right) {
    unordered_map<int, int> countRight;
    int similarity;

    for (int num: left) {
        similarity += num * countRight[num];
    }
    return similarity;
}

int main(int argc, char **argv)
{
    vector<int> left, right;

    parseInput(left, right);



    if (*argv[1]== '1') { 
        printf("part 1: %d\n", part1(left, right));
    } else {
        printf("part 2: %d\n", part2(left, right));
    }

    return 0;
}
