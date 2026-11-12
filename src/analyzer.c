#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "analyzer.h"
#include <math.h>

//checks if it has repetitions
bool has_repetition(const char *password, int limit){
    int length = strlen(password);
    int count = 0;
    for(int i = 0; i<length; i++){
        if(password[i] == password[i+1]){
            count++;
            if(count >= limit - 1){
                return true;
            }
        }
        else{
            count = 0;
        }
    }
    return false;
}

//checks if it has sequences f.x abc or 123
bool has_sequence(const char *password, int limit){
    int count = 0;
    for(int i = 0; password[i] != '\0' && password[i + 1] != '\0'; i++){
        if(password[i]+1 == password[i+1]){
            count++;
            if(count >= limit - 1){
                return true;
            }
        }
        else{
            count = 0;
        }
    }
    return false;
}

//checks if the password is a common one
bool is_common(const char *password){
    FILE *file = fopen("data/common_passwords.txt", "r");
    if(file==NULL){
        printf("Error: Could not open password list!\n");
        return false;
    }
    char example[256];
    while(fgets(example,sizeof(example),file)){    //reads the text until it reaches \n
        example[strcspn(example, "\r\n")] = '\0';  //deleteing the \n of every example in common_passwords.txt
        if(strcmp(example,password) == 0){
            fclose(file);
            return true;
        }
    }
    fclose(file);
    return false;
}

//calculates the password entropy in bits based on length and character pool size
double calculate_entropy(const PasswordAnalysis *password){

    //amount of possible outcomes per character
    int pool_size = 0;

    if(password->lowercase > 0){
        pool_size += 26;
    }
    if(password->uppercase > 0){
        pool_size += 26;
    }
    if(password->digits > 0){
        pool_size += 10;
    }
    if(password->special > 0){
        pool_size += 32;
    }
    if (pool_size == 0 || password->length == 0){
        return 0.0;
    }
    
    return (double)password->length * log2(pool_size);
}

// Estimates brute-force cracking time in seconds
double estimate_crack_in_seconds(const double entropyBits){

    //lets say 10 billion guesses per second
    double guesses_per_seconds = 10000000000.0;

    double total_combinations = pow(2.0, entropyBits);
    double average_guesses = total_combinations / 2.0;

    return average_guesses / guesses_per_seconds;
}

void print_readable_time(double seconds) {
    printf("  Crack Time              : ");

    if (!isfinite(seconds)) {
        printf("Beyond calculation range\n");
    } else if (seconds < 1.0) {
        printf("Less than 1 second\n");
    } else if (seconds < 60.0) {
        printf("Approx. %.1f seconds\n", seconds);
    } else if (seconds < 3600.0) {
        printf("Approx. %.1f minutes\n", seconds / 60.0);
    } else if (seconds < 86400.0) {
        printf("Approx. %.1f hours\n", seconds / 3600.0);
    } else if (seconds < 31536000.0) {
        printf("Approx. %.1f days\n", seconds / 86400.0);
    } else if (seconds < 31536000.0 * 1000000.0) {
        printf("Approx. %.1f years\n", seconds / 31536000.0);
    } else {
        printf("Approx. %.2e years\n", seconds / 31536000.0);
    }
}

//gives the row analysis of the password
PasswordAnalysis passwordAnalysis(const char *password){
    PasswordAnalysis pw = {0};
    size_t length = strlen(password);
    pw.length = length;
    for(size_t i = 0; i<length; i++){
        char c = password[i];
        if(islower((unsigned char)c)){
            pw.lowercase++;
        }
        else if(isupper((unsigned char)c)){
            pw.uppercase++;
        }
        else if(isdigit((unsigned char)c)){
            pw.digits++;
        }
        else if(ispunct((unsigned char)c)){
            pw.special++;
        }
    }
    pw.has_sequence = has_sequence(password,3);
    pw.has_repetition = has_repetition(password,3);
    pw.is_common = is_common(password);

    return pw;
}

//checks if the password is valid or not
bool is_valid(const PasswordAnalysis *analysis){
    return analysis->length >= 9 && analysis->lowercase > 0 && analysis->uppercase > 0 && analysis->digits > 0 && analysis->special > 0;
}