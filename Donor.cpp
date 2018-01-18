#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include "Donor.h"

using namespace std;


void Donor::logged_in_donor(){
    string input;
    cout << "Choose from [\"Manage\" \"Passwd\" \"View\" \"Donate\" \"Total\" \"Logout\"]" << endl << ": ";
    cin >> input;
    if(input == "Manage" || input == "manage"){
        manage();
    } else if(input == "Passwd" || input == "passwd"){
        passwd();
    } else if(input == "View" || input == "view"){
        view();
    } else if(input == "Donate" || input == "donate"){
        donate();
    } else if(input == "Total" || input == "total"){
        total();
    } else if(input == "Logout" || input == "logout"){
        cout << "Logging out..." << endl;
        return;
    } else {
        cerr << "Command not recognized. Please try again." << endl;
     }
     cout << " " << endl;
     logged_in_donor();
}

void Donor::set_username(string str){
    username = str;
}

void Donor::set_amnt_donated(){
    amnt_donated = 0.00;
}

void Donor::reset_password(string str){
    password = str;
}

void Donor::reset_first_name(string str){
    first_name = str;
}

void Donor::reset_last_name(string str){
    last_name = str;
}

void Donor::reset_age(string str){
    age = 50;
}

void Donor::reset_street_number(string str){
    street_number = 50;
}

void Donor::reset_street_name(string str){
    street_name = str;
}

void Donor::reset_town(string str){
    town = str;
}

void Donor::reset_state(string str){
    state = str;
}

void Donor::reset_zip(string str){
    zip_code = str;
}

void Donor::reset_amnt_donated(string str){
    amnt_donated = 50.00;
}

void Donor::set_password(){
    string tempPassword;
    cout << "Password: ";
    cin >> tempPassword;
    const size_t noSpecialChar = tempPassword.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");    
    if(tempPassword.length() < 6){
        cout << "Error. Password must be greater than 6 characters. Please try again." << endl;
        set_password();
    }else if(noSpecialChar == std::string::npos){
        cout << "Error. Password must contain one special character. Please try again." << endl;
        set_password();
    }else if(!std::any_of(std::begin(tempPassword), std::end(tempPassword), ::isdigit)){
        cout << "Error. Password must contain one digit. Please try again." << endl;
        set_password();
    }else{
        password = tempPassword;
        cout << password << endl;    
    }
}

void Donor::set_first_name(){
    string tempFirstName;
    cout << "First Name: ";
    cin.ignore();
    getline(cin,tempFirstName);
    const size_t temp = tempFirstName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ");        
    if(temp != std::string::npos){
        cout << "Error. First name can only contain letters. Please try again." << endl;
        set_first_name();
    }else{
        first_name = tempFirstName;
    }
}

void Donor::set_last_name(){
    string tempLastName;
    cout << "Last Name: ";
    cin.ignore();
    getline(cin,tempLastName);
    const size_t temp = tempLastName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ");        
    if(temp != std::string::npos){
        cout << "Error. Last name can only contain letters. Please try again." << endl;
        set_last_name();
    }else{
        last_name = tempLastName;
    }
}

void Donor::set_age(){
    string tempAge;
    cout << "Age: ";
    cin >> tempAge;
    const size_t temp = tempAge.find_first_not_of("1234567890");        
    if(temp != std::string::npos){
        cout << "Error. Age can only contain digits. Please try again." << endl;
        set_age();
    }else{
        age = stoi(tempAge);
    }
}

void Donor::set_street_number(){
    string tempNumber;
    cout << "Street Number: ";
    cin >> tempNumber;
    const size_t temp = tempNumber.find_first_not_of("1234567890");        
    if(temp != std::string::npos){
        cout << "Error. Street number can only contain digits. Please try again." << endl;
        set_street_number();
    }else if(stoi(tempNumber) < 0){
        cout << "Error. Street number can only contain digits. Please try again." << endl;
        set_street_number();
    }else{
        street_number = stoi(tempNumber);
    }
}

void Donor::set_street_name(){
    string tempName;
    cout << "Street Name: ";
    cin.ignore();
    getline(cin,tempName);
    const size_t temp = tempName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ");        
    if(temp != std::string::npos){
        cout << "Error. Street name can only contain letters. Please try again." << endl;
        set_street_number();
    }else{
        street_name = tempName;
    }
}

void Donor::set_town(){
    string tempTown;
    cout << "Town: ";
    cin.ignore();
    getline(cin,tempTown);
    const size_t temp = tempTown.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ");        
    if(temp != std::string::npos){
        cout << "Error. Town can only contain letters. Please try again." << endl;
        set_town();
    }else{
        town = tempTown;
    }
}

void Donor::set_state(){
    string tempState;
    cout << "State: ";
    cin >> tempState;
    string states[8] = { "NY", "PA", "RI", "NH", "VT", "MA", "CT", "ME" };
    bool tempBool = false;
    for(int i = 0; i < 8; i++){
        if(states[i] == tempState){
            tempBool = true;
        }
    }
    if(!tempBool){
        cout << "Error. Invlaid state. Please try again." << endl;
        set_state();
    }else{
        state = tempState;
    }
}

void Donor::set_zip(){
    string tempZip;
    cout << "Zip: ";
    cin >> tempZip;
    const size_t temp = tempZip.find_first_not_of("0123456789");        
    if(temp != std::string::npos){
        cout << "Error. Zip Code can only contain digits. Please try again." << endl;
        set_zip();
    }else if(tempZip.length() > 5){
        cout << "Error. Zip Code can only be 5 digits long. Please try again." << endl;
        set_zip();
    }else{    
        zip_code = tempZip;
    }
}

string Donor::get_username(){
    return username;
}

string Donor::get_password(){
    return password;
}

string Donor::get_last_name(){
    return last_name;
}

string Donor::get_first_name(){
    return last_name;
}

int Donor::get_age(){
    return age;
}

int Donor::get_street_number(){
    return street_number;
}

string Donor::get_street_name(){
    return street_name;
}

string Donor::get_town(){
    return town;
}

string Donor::get_state(){
    return street_name;
}

string Donor::get_zip(){
    return zip_code;
}

float Donor::get_amount_donated(){
    return amnt_donated;
}

void Donor::manage(){
    string input;
    cout << "Choose from: " << endl;
    cout << "- First Name" << endl;
    cout << "- Last Name" << endl;
    cout << "- Age" << endl;
    cout << "- Street Number" << endl;
    cout << "- Street Name" << endl;
    cout << "- Town" << endl;
    cout << "- State" << endl;
    cout << "- Zip" << endl;
    cout << ": ";
    cin >> input;
    if(input == "First Name" || input == "first name"){
        set_first_name();
    } else if(input == "Last Name" || input == "last_name"){
        set_last_name();
    } else if(input == "Age" || input == "age"){
        set_age();
    } else if(input == "Street Number" || input == "street number"){
        set_street_number();
    } else if(input == "Street Name" || input == "street name"){
        set_street_name();
    } else if(input == "Town" || input == "town"){
        set_town();
    } else if(input == "State" || input == "state"){
        set_state();
    } else if(input == "Zip" || input == "zip"){
        set_zip();
     } else {
        cerr << "Command not recognized. Please try again." << endl;
        manage();
    }
}

void Donor::view(){
    cout << "Donor Info:" << endl;
    cout << first_name << " " << last_name << ": Age " << age << endl;
    cout << street_number << " " + street_name << " " + town + " " + state + " " << zip_code << endl;
    cout << "Current Amount Donated: $" << amnt_donated << endl;
}

void Donor::donate(){
    float additional_amount;
    cout << "Enter Amount to Donate: ";        
    cin >> additional_amount;
    cout << fixed << setprecision(2);    
    cout << "$" << additional_amount << " donated" << endl;       
    amnt_donated = amnt_donated + additional_amount;
}

void Donor::total(){
    cout << fixed << setprecision(2);
    cout << last_name + " $" << amnt_donated << endl;
}

void Donor::passwd(){
    string tempPassword;
    bool canChangePassword;
    int attemptCounter = 0;
    while(attemptCounter < 2 || canChangePassword){
        cout << "Enter your current password: ";
        cin >> tempPassword;
        if(tempPassword == password){
            cout << "Again, enter your current password: ";
            cin >> tempPassword;
            if(tempPassword == password){
                canChangePassword = true;
                cout << "New Password: ";
                string tempPass;
                cin >> tempPass;
                password = tempPass;
                return;
            }else{
                cout << "Incorrect password." << endl;
                attemptCounter++;
            }
        }else{
            cout << "Incorrect password." << endl;
            attemptCounter++;
        }    
    }
    if(!canChangePassword){
        cout << "Incorrect password. Logging out." << endl;
        return;
    }
}