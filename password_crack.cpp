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
#include <stdlib.h> //srand and rand
#include <time.h> //seed for rng
#include <chrono> //timing brute force algorithm

using namespace std;
using namespace std::chrono;

int *generate_num_pw(int length);

int main() {

    srand(time(NULL));

    int *new_password_arr = generate_num_pw(4); //generate_num_pw returns pointer to array created in function
    stringstream int_to_string; 
    int result;
    auto start = high_resolution_clock::now();

    for(int i = 0; i < 4; i++){
        int_to_string << new_password_arr[i]; //int_to_string takes in ints from ayya and converts to string 
    }

    int_to_string >> result; //int_to_string converted to int to check value of array 

    auto end = high_resolution_clock::now();

    cout << result << endl;  

    auto duration = duration_cast<microseconds>(end - start);

    cout << duration.count() << endl;
    
    return 0;
}

//all numbers, length 4 
//given a length, return array pointer with random int_to_stringues created by rand
int *generate_num_pw(int length) {
    int* pw_arr = new int[length]; //create pointer to array within function so that you can return it. If used normal array instantiation, it is destroyed after fn because of scope. 

    for(int i = 0; i < length; i++){
        pw_arr[i] = rand() % 9;
    }

    return pw_arr;
}

//brute force algorithm 
//given pw array, return time taken to crack pw 
int *brute_force(int *pw_arr_bf) {
    //iterate through every possible four integer permutation to find matching value in array
    int *result = new int[4];
    
    for(int i = 0; i < 10; i++) {
        if(i == pw_arr_bf[0]) {
            result[0] = i;
        } else if(i == pw_arr_bf[1]) {
            result[1] = i;
        }
        else if(i == pw_arr_bf[2]) {
            result[2] = i;
        }
        else if(i == pw_arr_bf[3]) {
            result[3] = i;
        }
    }

    return result;
}