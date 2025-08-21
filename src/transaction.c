#include <stdint.h>

typedef struct {
    uint32_t id;
    char description[100];
    int32_t value_in_cents;
    char category[30];
    uint32_t date;
    uint8_t type;

} Transaction;


