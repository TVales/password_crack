/*
Password Cracking Algorithm 

Password Type: Alpha numeric 
               numeric (*)
               All characters 
               Words concatenated

Password Length: 4 - iphone number pad (*)
                 5 - test how much adding 1 increases password crack time
                 10 - medium strength password 
                 15 - strong password strength

Algorithms: Brute Force 
            Multithreading?  
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int generate_num_pw(int length);

int main() {

    srand(time(NULL));

    for(int i = 0; i < 50; i++) {
        cout << generate_num_pw(10000) << endl;
    }
}

//generate password using random number generator
//all numbers, length 4 
int generate_num_pw(int length) {
    return rand()%length + 1000;
}

//brute force algorithm 