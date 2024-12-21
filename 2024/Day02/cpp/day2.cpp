#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;


// int safe = 0;
// check if the report will be inc or dec (if report[0] > report[1]){!inc}
// if report[i] - report[i-1] <= 3 && > 0

void parse(vector<vector<int>>& reports) {
        
}

int checkDir(vector<int>& report) {
    int last = report.size() - 1;
    if (report[0] > report[last]) {
        return -1;
    } else if (report[last] > report[0]) {
        return 1;
    } else {
        return 0;
    }
}

int checkSafe(int dir, vector<int>& report) {
    for (int i = 1; i < report.size(); i++) {
        int diff = (report[i-1]-report[i])*dir;
        if (!(diff >= 1 && diff <= 3)) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char **argv) {

    int passed = 0, failed = 0;
    vector<vector<int>> reports;

    parse(reports);

    for (auto report : reports) {
        if (checkDir(report)) {
            passed += checkSafe(checkDir(report), report);
        } else {
            failed ++;
        }
    }

    printf("Passed: %d\nFailed: %d\n", passed, failed);

    return 0;
}

