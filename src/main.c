#include <stdio.h>
#include <string.h>
#include "analyzer.h"

int main(void) {
    char password[102];

    printf("\n========================================================\n");
    printf("                    PASSCHECK-C  v1.0\n");
    printf("                    Password Analyzer\n");
    printf("========================================================\n\n");

    printf("Enter password: ");

    if (fgets(password, sizeof(password), stdin) == NULL) {
        fprintf(stderr, "Error: Could not read password.\n");
        return 1;
    }

    //remove a possible line ending
    password[strcspn(password, "\r\n")] = '\0';

    //check if password is too long
    if (strlen(password) > 99) {
        printf("Error: Password is too long!\n");
        return 1;
    }

    if (password[0] == '\0') {
        fprintf(stderr, "Error: Password cannot be empty.\n");
        return 1;
    }

    //if the wordlist is unavailable a negative common-password check is unreliable
    FILE *file = fopen("data/common_passwords.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open data/common_passwords.txt.\n");
        fprintf(stderr, "Please run the program from its project directory.\n");
        return 1;
    }
    fclose(file);

    PasswordAnalysis analysis = passwordAnalysis(password);
    double entropyBits = calculate_entropy(&analysis);
    double estimateCrack = estimate_crack_in_seconds(entropyBits);

    printf("\n------------------- CHARACTER ANALYSIS -------------------\n");
    printf("  Length                  : %zu\n", analysis.length);
    printf("  Uppercase letters       : %d\n", analysis.uppercase);
    printf("  Lowercase letters       : %d\n", analysis.lowercase);
    printf("  Digits                  : %d\n", analysis.digits);
    printf("  Special characters      : %d\n", analysis.special);

    printf("\n-------------------- SECURITY CHECKS ---------------------\n");
    printf("  Repeated characters     : %s\n", analysis.has_repetition ? "YES" : "NO");
    printf("  Ascending sequences     : %s\n", analysis.has_sequence ? "YES" : "NO");
    printf("  Common password list    : %s\n", analysis.is_common ? "FOUND" : "NOT FOUND");
    printf("  Basic requirements      : %s\n", is_valid(&analysis) ? "PASSED" : "NOT MET");

    printf("\n------------------- CRACK TIME MODEL ---------------------\n");
    printf("  Theoretical entropy     : %.1f bits\n", entropyBits);
    printf("  Assumed attack speed    : 10 billion guesses/second\n");

    if (analysis.is_common) {
        printf("  Crack Time              : NOT MEANINGFUL (common password)\n");
        printf("\n  WARNING: Found in the common-password list.\n");
        printf("  A random brute-force estimate is misleading here;\n");
        printf("  attackers may try known passwords first.\n");
    } else {
        print_readable_time(estimateCrack);
        printf("\n  Note: This is only a uniform-random brute-force model,\n");
        printf("  not a prediction of real-world password security.\n");
    }

    printf("\n------------------------- RESULT -------------------------\n");
    if (analysis.is_common) {
        printf("  COMMON PASSWORD - AVOID USING IT\n");
    } else if (is_valid(&analysis)) {
        printf("  BASIC REQUIREMENTS MET (not a security guarantee)\n");
    } else {
        printf("  BASIC REQUIREMENTS NOT MET\n");
    }
    printf("==========================================================\n\n");

    return 0;
}
