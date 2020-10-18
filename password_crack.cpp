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

int *generate_num_pw(int length);

int main() {

    srand(time(NULL));

    int *new_password = generate_num_pw(4); //generate_num_pw returns pointer to array created in function
    int val;

    for(int i = 0; i < 4; i++){
        val = new_password[i];
        cout << val << endl;
    }


    //this only works with 4 length passwords
    if(val > 9999){
        val /= 10;
    } 
    else if (val < 1000) {
        val *= 10;
    }

    cout << val << endl;
    
    return 0;
}

//all numbers, length 4 
//given a length, return array pointer with random values created by rand
int *generate_num_pw(int length) {
    int* pw_arr = new int[length]; //create pointer within function so that you can return it. If used normal array instantiation, it is destroyed after fn because of scope. 

    for(int i = 0; i < length; i++){
        pw_arr[i] = rand()%length;
    }

    return pw_arr;
}

//is valid password
//given array and length, return bool if password is valid length

//brute force algorithm 