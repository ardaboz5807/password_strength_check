#include <stdbool.h>
#include <stddef.h>

typedef struct {
    size_t length;
    int uppercase;
    int lowercase;
    int digits;
    int special;
    bool has_sequence;
    bool has_repetition;
    bool is_common;
} PasswordAnalysis;

bool has_repetition(const char *password, int limit);
bool has_sequence(const char *password, int limit);
bool is_common(const char *password);
double calculate_entropy(const PasswordAnalysis *passwordAnalysis);
double estimate_crack_in_seconds(const double entropyBits);
void print_readable_time(double seconds);
PasswordAnalysis passwordAnalysis(const char *password);
bool is_valid(const PasswordAnalysis *password);