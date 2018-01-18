#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "DonorDatabase.h"

using namespace std;


int main(int argc, char **argv) {
    string secondParam(argv[1]);
    int donorCapacity = stoi(secondParam);
    DonorDatabase donorDb(donorCapacity);            
    if(argc == 3){
        string fileName = argv[2];
        donorDb.load_in_donors(fileName);                
    }
    bool endBool;
    cout << endl << "Welcome to the Donor Database!" << endl;
    while(!donorDb.endProgram){
        string input;
        cout << "Choose from [\"Login\" \"Add\" \"Save\" \"Load\" \"Report\" \"Quit\"]" << endl << ": ";
        cin >> input;
        donorDb.login_prompt(input); 
    }
    return 0;
}