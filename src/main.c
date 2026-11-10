#include <stdio.h>
#include <string.h>
#include "analyzer.h"

int main(){
    
    char password[100] = "HallllloWelt!1234)(";

    PasswordAnalysis analysis = passwordAnalysis(password);

    printf("------------------------------------------\n");
    printf("Length of password: %zu\n", analysis.length);
    printf("Amount of uppercase: %d\n", analysis.uppercase);
    printf("Amount of lowercase: %d\n", analysis.lowercase);
    printf("Amount of digits: %d\n", analysis.digits);
    printf("Amount of special signs: %d\n", analysis.special);
    printf("Has repetitions: %d\n", analysis.has_repetition);  //1 = True   0 == False
    printf("Has sequences: %d\n", analysis.has_sequence);
    printf("Is a common one: %d\n", analysis.is_common);

    PasswordAnalysis *value = &analysis;

    if(is_valid(&analysis)){
        printf("%s is valid password\n", password);
    }
    else{
        printf("%s is not valid password\n", password);
    }

    return 0;
}