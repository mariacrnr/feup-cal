#include "../../include/Utils/Files.h"

int checkIntInput(){
    string holder;

    getline(cin, holder);

    if (cin.fail() || cin.eof() || holder.find_first_not_of("0123456789") != string::npos){
        cout << "You must input a valid number." << endl;

        if( holder.find_first_not_of("0123456789") == string::npos)
            clearInput("");

        return -1;
    }

    if(holder.empty()) return -1;

    return stoi(holder);
}

void clearInput(string message){
    cout << message;
    cin.clear();
    cin.ignore(1000,'\n');
}

int readInput(int low, int high, string message, string invalid){
    int input;
    while(true) {
        cout << message;
        if ((input = checkIntInput()) != -1){ // checks if a int was submitted

            if (input >= low && input <= high) break;
            else cout << invalid;
        }
    }
    return input;
}