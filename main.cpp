#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
#ifdef _WIN32
const std::string python = "python";
#else
const std::string python = "python3";
#endif

using namespace std;

string getInput(string prompt);

int main() {
    string fileName;
    string choice;
    int timesPlayed = 0;
    bool cont;

    choice = getInput("Would you like to play a game? (Y/N): ");
    while (choice != "y" && choice != "n") {
        choice = getInput("Would you like to play a game? (Y/N): ");
    }
    if (choice == "y") {
        cont = true;
    } else {
        cont = false;
    }
    while (cont) {
        cout << "Enter a minimum number: ";
        int min;
        int max;
        cin >> min;
        while (min < 0) {
            cout << "enter a positive value: ";
            cin >> min;
        }
        cout << "Enter a maximum number: ";
        cin >> max;
        while (max < min) {
            cout << "Enter a maximum that is greater than the minimum: ";
            cin >> max;
        }
        string command = python + " ../info.py " + to_string(min) + " " + to_string(max);
        system(command.c_str());
        timesPlayed++;

        string secondchoice;
        // this calls twice and I can't even begin to understand why.. I've tried an abundance of fixes
        // in debugger mode it calls the function once, but on the first pass doesn't print the prompt
        // or wait for user input.. I just don't know
        while(secondchoice != "y" && secondchoice != "n"){
            secondchoice = getInput("Would you like to play a game? (Y/N): ");
        }
        if (secondchoice == "n"){
            cont = false;
        }
    }
    if (timesPlayed == 0) {
        cout << "Then why'd you even start me?" << endl;
    } else {
        cout << "You played " + to_string(timesPlayed) + " times" << endl;
        cout << "Thanks for playing, even though I always won." << endl;
    }
}

string getInput(string prompt){
    string input;
    string lowString;
    cout << prompt;
    getline(cin, input);
    for (int i =0; i < input.size(); ++i){
        lowString.push_back(tolower(input[i]));
    }
    return lowString;
}