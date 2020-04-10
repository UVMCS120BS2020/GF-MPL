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

vector<int> getColors();

int main(){
    string fileName;
    cout << "Enter the name of your text file (without the extension): ";
    getline(cin, fileName);
    string command = python + " ../info.py " + fileName;
    system(command.c_str());
    cout << "Processing some statistics...";
    vector<int> colorVec = getColors();
    int red = colorVec[0];
    int green = colorVec[1];
    int blue = colorVec[2];

    cout << "The RGB of your story is: " << red << ", " << green << ", " << blue << endl;
}



vector<int> getColors(){
    ifstream inFile;
    inFile.open ("colorfile.txt");
    string line;
    vector<int> intVec;
    vector<int> colorVec;
    while (getline(inFile, line)){
        for (int i = 0; i < line.size(); ++i){
            if (isdigit(line[i])){
                intVec.push_back(line[i]);
            }
        }
    }
    int addme = 0;
    int temp = 0;
    for(int q = 0; q < intVec.size(); q++){
        if (q == 0 || q == 1 || q == 2){
            if (q == 0){
                addme = intVec[q];
                addme = addme * 100;
            } else if (q == 1){
                temp = intVec[q];
                temp = temp * 10;
                addme = addme + temp;
            } else if (q == 2){
                temp = intVec[q];
                addme = addme + temp;
                colorVec.push_back(addme);
            }
        } else if (q == 3 || q == 4 || q == 5){
            if (q == 3){
                addme = intVec[q];
                addme = addme * 100;
            } else if (q == 4){
                temp = intVec[q];
                temp = temp * 10;
                addme = addme + temp;
            }else if (q == 5){
                temp = intVec[q];
                addme = addme + temp;
                colorVec.push_back(addme);
            }
        } else if (q == 6 || q == 7 || q == 8) {
            if (q == 6) {
                addme = intVec[q];
                addme = addme * 100;
            } else if (q == 7) {
                temp = intVec[q];
                temp = temp * 10;
                addme = addme + temp;
            } else if (q == 8) {
                temp = intVec[q];
                addme = addme + temp;
                colorVec.push_back(addme);
            }
        }else{
            cout << "not possible" << endl;
        }
    }
    inFile.close();
    return colorVec;
}