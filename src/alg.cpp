// Copyright 2025 UNN-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
    if (value <= 1) return false;
    if (value <= 3) return true;
    
    // Проверка через 6k ± 1
    if (value % 2 == 0 || value % 3 == 0) return false;
    
    for (uint64_t i = 5; i * i <= value; i += 6) {
        if (value % i == 0 || value % (i + 2) == 0) return false;
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 0) return 0;
    
    uint64_t found = 0;
    uint64_t candidate = 1;
    
    while (found < n) {
        candidate++;
        if (checkPrime(candidate)) {
            found++;
        }
    }
    return candidate;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t search = value;
    do {
        search++;
    } while (!checkPrime(search));
    return search;
}

uint64_t sumPrime(uint64_t hbound) {
    if (hbound <= 2) return 0;
    
    uint64_t total = 0;
    for (uint64_t current = 2; current < hbound; current++) {
        if (checkPrime(current)) {
            total += current;
        }
    }
    return total;
}