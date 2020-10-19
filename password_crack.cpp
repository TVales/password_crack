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

#include <iostream> //cout 
#include <sstream> //array to string 
#include <stdlib.h> 
#include <time.h> //seed for rng

using namespace std;

int *generate_num_pw(int length);

int main() {

    srand(time(NULL));

    int *new_password = generate_num_pw(4); //generate_num_pw returns pointer to array created in function
    stringstream val; 
    int result;

    for(int i = 0; i < 4; i++){
        val << new_password[i]; //val takes in ints from ayya and converts to string 
    }

    val >> result; //val converted to int

    //this only works with 4 length passwords
    if(result > 9999){
        result /= 10;
    } 
    else if (result < 1000) {
        result *= 10;
    } 

    cout << result << endl;
    
    return 0;
}

//all numbers, length 4 
//given a length, return array pointer with random values created by rand
int *generate_num_pw(int length) {
    int* pw_arr = new int[length]; //create pointer within function so that you can return it. If used normal array instantiation, it is destroyed after fn because of scope. 

    for(int i = 0; i < length; i++){
        pw_arr[i] = rand() % 10 + 1;
    }

    return pw_arr;
}

//is valid password
//given array and length, return bool if password is valid length

//brute force algorithm 
//given pw array, return time taken to crack pw 