#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

int list_length = 1000;

string current_line;

void parse() {
    printf("printf fucks\n");
    return;
}

int main()
{
    parse();
    std::cout << "hello!\n";
    while (getline(cin, current_line)){
        printf("%s\n", current_line.c_str());
    }
    return 0;
}
