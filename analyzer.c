#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "analyzer.h"

bool is_special_char(char c){
    return ispunct((unsigned char)c) != 0;
}

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
    //pw.has_sequence = has_sequence(const char *password)
    //pw.has_repetition = has_repetition(const char *password)
    //pw.is_common = has_repetition(const char *password)

    return pw;
}

bool is_valid(const char *password){
    int length = strlen(password);
    if(length <= 8){
        return false;
    }

    bool has_lower = false;
    bool has_upper = false;
    bool has_special = false;
    bool has_digit = false;

    for(int i = 0; i<length; i++){
        char c = password[i];
        if(islower(c)){
            has_lower = true;
        }
        else if(isupper(c)){
            has_upper = true;
        }
        else if(is_special_char(c)){
            has_special = true;
        }
        else if(isdigit(c)){
            has_digit = true;
        }
    }

    if(has_lower && has_upper && has_special && has_digit){
        return true;
    }
    return false;
}