#include <iostream>
#include <stdlib.h>
#include <string>
//#include "DonorDatabase.h"

using namespace std;

class Donor {
    public: 
        // Donor();
        enum State { NY, PA, RI, NH, VT, MA, CT, ME };
        
        void reset_password(string);
        void reset_first_name(string);
        void reset_last_name(string);
        void reset_age(string);
        void reset_street_number(string);
        void reset_street_name(string);
        void reset_town(string);
        void reset_state(string);
        void reset_zip(string);
        void reset_amnt_donated(string);
        
        void set_username(string);
        void set_password();
        void set_first_name();      
        void set_last_name();
        void set_age();        
        void set_street_number();                        
        void set_street_name();                                        
        void set_town();
        void set_state();
        void set_zip();
        void set_amnt_donated();

        string get_username();
        string get_password();
        string get_first_name();
        string get_last_name();
        int get_age();
        int get_street_number();
        string get_street_name();
        string get_town();
        string get_state();
        string get_zip();
        float get_amount_donated();

        void logged_in_donor();
        void manage();
        void passwd();
        void view();
        void donate();
        void total();

    private:

        string username;        
        string password;
        string last_name;
        string first_name;
        int age;
        int street_number;
        string street_name;
        string town;
        string state;
        string zip_code;
        float amnt_donated;

};

