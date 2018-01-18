#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "Donor.h"

using namespace std;

class DonorDatabase {
    public: 
        DonorDatabase(int);
        DonorDatabase(int, string);        
        void login_prompt(string);
        void login();
        void set_username(Donor &);
        void add();
        void save();
        void load();
        void load_in_donors(string);
        void report();
        void add_donor(Donor);
        bool contains_donor(string);
        bool endProgram;        
    private:
        Donor *donors; 
        string *fileNames;  
        int donorCapacity;        
        int donorCounter;
        int fileCounter;
        float totalAmountDonated;
             
        
};