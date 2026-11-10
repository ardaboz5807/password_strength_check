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

bool is_special_char(char c);
bool is_valid(const PasswordAnalysis *password);
bool has_repetition(const char *password, int limit);
bool has_sequence(const char *password, int limit);
bool is_common(const char *password);
PasswordAnalysis passwordAnalysis(const char *password);