// Copyright 2025 UNN-CS

#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

// --- checkPrime ---

TEST(checkPrimeTest, small_prime) {
    EXPECT_TRUE(checkPrime(2));
}

TEST(checkPrimeTest, another_prime) {
    EXPECT_TRUE(checkPrime(13));
}

TEST(checkPrimeTest, not_prime_one) {
    EXPECT_FALSE(checkPrime(1));
}

TEST(checkPrimeTest, not_prime_composite) {
    EXPECT_FALSE(checkPrime(9));
}

TEST(checkPrimeTest, zero_is_not_prime) {
    EXPECT_FALSE(checkPrime(0));
}

// --- nPrime ---

TEST(nPrimeTest, first_prime) {
    EXPECT_EQ(2u, nPrime(1));
}

TEST(nPrimeTest, third_prime) {
    // 2, 3, 5 — третье простое равно 5
    EXPECT_EQ(5u, nPrime(3));
}

TEST(nPrimeTest, tenth_prime) {
    // десятое простое число — 29
    EXPECT_EQ(29u, nPrime(10));
}

// --- nextPrime ---

TEST(nextPrimeTest, after_even) {
    // после 4 следующее простое — 5
    EXPECT_EQ(5u, nextPrime(4));
}

TEST(nextPrimeTest, after_prime_itself) {
    // само 11 не учитывается, следующее — 13
    EXPECT_EQ(13u, nextPrime(11));
}

TEST(nextPrimeTest, after_two) {
    EXPECT_EQ(3u, nextPrime(2));
}

// --- sumPrime ---

TEST(sumPrimeTest, up_to_10) {
    // 2+3+5+7 = 17
    EXPECT_EQ(17u, sumPrime(10));
}

TEST(sumPrimeTest, up_to_2000000) {
    EXPECT_EQ(142913828922u, sumPrime(2000000));
}

TEST(sumPrimeTest, up_to_2_returns_zero) {
    // нет простых чисел меньше 2
    EXPECT_EQ(0u, sumPrime(2));
}

TEST(sumPrimeTest, up_to_3_returns_2) {
    EXPECT_EQ(2u, sumPrime(3));
}
