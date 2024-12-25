#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;


// int safe = 0;
// check if the report will be inc or dec (if report[0] > report[1]){!inc}
// if report[i] - report[i-1] <= 3 && > 0

void parse(vector<vector<int>>& reports) {

    string line;

    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> report;

        int num;
        while (iss >> num) {
            report.push_back(num);
        }
        reports.push_back(report);
    }
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
        int diff = (report[i]-report[i-1])*dir;
        //printf("diff: %d\n", diff);
        if (!(diff >= 1 && diff <= 3)) {
            return 0;
        }
    }
    return 1;
}


int checkSafe2(vector<int>& report) {
    
    /*
    printf("failed report:\n");
    for (int i = 0; i < report.size(); i++) {
        printf("%d  ", report[i]);
    }
    printf("\n");
    printf("dampened:\n");
    */
    for (int skipindex = 0; skipindex < report.size(); skipindex++) {
        vector<int> dampened;
        for (int i = 0; i < report.size(); i++) {
            if (i != skipindex) {
                dampened.push_back(report[i]);
                //printf("%d  ", dampened[i]);
            }
        }
        //printf("\n");
        if (checkSafe(checkDir(dampened), dampened)) {
            return 1;
        }
    }
    return 0;
}


int main(int argc, char *argv[]) {

    int passed1 = 0, passed2 = 0;
    vector<vector<int>> reports;

    parse(reports);

    for (auto report : reports) {

        passed1 += checkSafe(checkDir(report), report);

    }

    for (auto report : reports) {
        //passed2 += checkSafe(checkDir(report), report);
        if (checkSafe(checkDir(report), report)) {
            passed2++;
        } else {
            passed2 += checkSafe2(report);
        }
    }

    printf("Passed part1: %d\nPassed part2: %d\n", passed1, passed2);

    return 0;
}
