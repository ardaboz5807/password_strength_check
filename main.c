#include <stdio.h>
#include <string.h>
#include "analyzer.h"

int main(){
    
    char password[100] = "HalloWelt!)(";
    
    if(is_valid(password)){
        printf("%s is valid\n", password);
    }
    else{
        printf("%s is not valid\n", password);
    }

    PasswordAnalysis analysis = passwordAnalysis(password);

    printf("------------------------------------------\n");
    printf("Length of password: %zu\n", analysis.length);
    printf("Amount of uppercase: %d\n", analysis.uppercase);
    printf("Amount of lowercase: %d\n", analysis.lowercase);
    printf("Amount of digits: %d\n", analysis.digits);
    printf("Amount of special signs: %d\n", analysis.special);

    return 0;
}