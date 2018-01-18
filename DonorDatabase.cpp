#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <fstream>
#include "DonorDatabase.h"

using namespace std;

DonorDatabase::DonorDatabase(int i){
    donorCapacity = i;
    donors = new Donor[donorCapacity];
    fileNames = new string[fileCounter];  
}

DonorDatabase::DonorDatabase(int i, string fileName){
    donorCapacity = i;
    donors = new Donor[donorCapacity];
    fileNames = new string[fileCounter];
    cout << fileName << endl;
    load_in_donors(fileName);
}

void DonorDatabase::login_prompt(string input){
    if(input == "Login" || input == "login"){
        login();
    } else if(input == "Add" || input == "add"){
        add();
    } else if(input == "Save" || input == "save"){
        save();
    } else if(input == "Load" || input == "load"){
        load();
    } else if(input == "Report" | input == "report"){
        report();
    } else if(input == "Quit" || input == "quit"){
        delete [] donors;
        cout << "Thanks for using the Donor Database. Exiting program..." << endl;
        endProgram = true;
    } else {
        cerr << "Command not recognized. Please try again." << endl;
    }
    cout << " " << endl;
}

void DonorDatabase::login(){
    string tempUsername;
    cout << "Username: ";
    cin >> tempUsername;
    if(!contains_donor(tempUsername)){
        cout << "Error. User is not in system. Try again or use \"Add\"." << endl;
        return;
    } else{
        int donorIndex;                
        for(int i = 0; i < donorCounter; i++){
            if(donors[i].get_username() == tempUsername){
                donorIndex = i;
            }
        }
        string tempPassword;
        cout << "Password: ";
        cin >> tempPassword;
        if(donors[donorIndex].get_password() == tempPassword){
            donors[donorIndex].logged_in_donor();
        } else{
            cout << "Error. Invalid password. Please try again." << endl;
            login();
        }
    }
}

void DonorDatabase::add(){
    if(donorCapacity == 0 || donorCapacity == donorCounter){
        cout << "The Donor Database is full. Please try again in the future." << endl;
    }else{
        Donor newDonor;
        set_username(newDonor);
        newDonor.set_password();
        newDonor.set_first_name();
        newDonor.set_last_name();
        newDonor.set_age();
        newDonor.set_street_number();
        newDonor.set_street_name();
        newDonor.set_town();
        newDonor.set_state();
        newDonor.set_zip();
        newDonor.set_amnt_donated();
        add_donor(newDonor);
        cout << "Donor added." << endl;
    }
}

void DonorDatabase::set_username(Donor &newDonor){
    string tempUsername;
    cout << "Username: ";
    cin >> tempUsername;
    const size_t temp = tempUsername.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
    if(temp != std::string::npos){
        cout << "Error. Password can only contain letters or numbers. Please try again." << endl;
        set_username(newDonor);
    } else if(tempUsername.length() < 5 || tempUsername.length() > 10){
        cout << "Error. Password must be between 5-10 characters. Please try again." << endl;
        set_username(newDonor);
    } else if(contains_donor(tempUsername)){
        cout << "Error. User already exists. Please try again." << endl;
        set_username(newDonor);
    } else{
        newDonor.set_username(tempUsername);
    }
}

void DonorDatabase::save(){
    string fileName;
    bool fileExists;
    cout << "Name the file you want to save to: " << endl << ": ";
    cin >> fileName;
    for(int i = 0;i < fileCounter; i++){
        if(fileNames[i] == fileName){
            fileExists = true;
        }
    }
    if(fileExists){
        cout << "The file you named already exists. Choose another name (please include \".txt\": " << endl << ": ";
        save();
    }else{
        ofstream file;
        file.open (fileName);
        file << donorCounter << endl;
        for(int i = 0; i < donorCounter; i++){
            file << donors[i].get_username() << endl;
            file << donors[i].get_password() << endl;
            file << donors[i].get_first_name() << endl;
            file << donors[i].get_last_name() << endl;
            file << donors[i].get_age() << endl;
            file << donors[i].get_street_number() << endl;
            file << donors[i].get_street_name() << endl;
            file << donors[i].get_town() << endl;
            file << donors[i].get_state() << endl;
            file << donors[i].get_zip() << endl;
            file << donors[i].get_amount_donated() << endl;
        }
        file.close();
        fileCounter ++;    
        fileNames[fileCounter] = fileName;   
        cout << "File successfully generated. " << endl;        
    }
}

void DonorDatabase::load(){
    string fileName;
    bool fileExists;
    cout << "Name the file you want to load: " << endl << ": ";
    cin >> fileName;
    if(!ifstream(fileName)){
        cout << "The file you named does not exist. Try again: " << endl;
        load();
    }else{
        delete [] donors;
        donorCapacity = 0;
        donors = new Donor[donorCapacity];
        load_in_donors(fileName);
        cout << "File successfully loaded into Donor Database. " << endl;        
    }
}

void DonorDatabase::load_in_donors(string fileName){
    string firstLine;
    int numOfDonors;
    ifstream infile;
    infile.open(fileName);
    getline(infile, firstLine);
    numOfDonors = stoi(firstLine);
    for(int i = 0; i < numOfDonors; i++){
        Donor newDonor;
        string tempUsername;
        string tempPassword;
        string tempFirstName;
        string tempLastName;
        string tempAge;
        string tempStreetNumber;
        string tempStreetName;
        string tempTown;
        string tempState;
        string tempZip;
        string tempAmount;
        getline(infile, tempUsername);
        getline(infile, tempPassword);
        getline(infile, tempFirstName);
        getline(infile, tempLastName);
        getline(infile, tempAge);
        getline(infile, tempStreetNumber);
        getline(infile, tempStreetName);
        getline(infile, tempTown);
        getline(infile, tempState);
        getline(infile, tempZip);
        getline(infile, tempAmount);
        newDonor.set_username(tempUsername);
        newDonor.reset_password(tempPassword);
        newDonor.reset_first_name(tempFirstName);
        newDonor.reset_last_name(tempLastName);
        newDonor.reset_age(tempAge);
        newDonor.reset_street_number(tempStreetNumber);
        newDonor.reset_street_name(tempStreetName);
        newDonor.reset_town(tempTown);
        newDonor.reset_state(tempState);
        newDonor.reset_zip(tempZip);
        newDonor.reset_amnt_donated(tempAmount);        
        donors[donorCounter] = newDonor;        
        donorCounter++;            
    }        
    infile.close();
}

void DonorDatabase::report(){
    for(int i = 0; i < (donorCounter+1); i++){
        totalAmountDonated += donors[i].get_amount_donated();
    }
    if(donorCounter == 1){
        cout << "There is 1 donor in the database." << endl;        
    }else{
        cout << "There are " << donorCounter << " donors in the database." << endl;
    }
    cout << "$" << totalAmountDonated <<  " total has been donated." << endl;         
}

void DonorDatabase::add_donor(Donor donor){
    donors[donorCounter] = donor;
    donorCounter ++; 
}

bool DonorDatabase::contains_donor(string username){
    bool returnValue = false;
    for(int i = 0; i < donorCounter; i++){
        if(donors[i].get_username() == username){
            returnValue = true;
        }
    }
    return returnValue;
}