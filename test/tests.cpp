// Copyright 2025 UNN-CS
#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

// Тест 1: проверка простых чисел
TEST(PrimeTest, CheckPrimeTrue) {
    EXPECT_TRUE(checkPrime(2));
    EXPECT_TRUE(checkPrime(3));
    EXPECT_TRUE(checkPrime(5));
    EXPECT_TRUE(checkPrime(7));
    EXPECT_TRUE(checkPrime(11));
    EXPECT_TRUE(checkPrime(13));
    EXPECT_TRUE(checkPrime(17));
    EXPECT_TRUE(checkPrime(19));
}

// Тест 2: проверка составных чисел
TEST(PrimeTest, CheckPrimeFalse) {
    EXPECT_FALSE(checkPrime(0));
    EXPECT_FALSE(checkPrime(1));
    EXPECT_FALSE(checkPrime(4));
    EXPECT_FALSE(checkPrime(6));
    EXPECT_FALSE(checkPrime(8));
    EXPECT_FALSE(checkPrime(9));
    EXPECT_FALSE(checkPrime(10));
    EXPECT_FALSE(checkPrime(15));
}

// Тест 3: проверка nPrime для малых значений
TEST(PrimeTest, NPrimeSmall) {
    EXPECT_EQ(2, nPrime(1));
    EXPECT_EQ(3, nPrime(2));
    EXPECT_EQ(5, nPrime(3));
    EXPECT_EQ(7, nPrime(4));
    EXPECT_EQ(11, nPrime(5));
    EXPECT_EQ(13, nPrime(6));
}

// Тест 4: проверка nPrime для средних значений
TEST(PrimeTest, NPrimeMedium) {
    EXPECT_EQ(17, nPrime(7));
    EXPECT_EQ(19, nPrime(8));
    EXPECT_EQ(23, nPrime(9));
    EXPECT_EQ(29, nPrime(10));
    EXPECT_EQ(31, nPrime(11));
}

// Тест 5: проверка nextPrime для простых чисел
TEST(PrimeTest, NextPrimeFromPrime) {
    EXPECT_EQ(3, nextPrime(2));
    EXPECT_EQ(5, nextPrime(3));
    EXPECT_EQ(7, nextPrime(5));
    EXPECT_EQ(11, nextPrime(7));
    EXPECT_EQ(13, nextPrime(11));
}

// Тест 6: проверка nextPrime для составных чисел
TEST(PrimeTest, NextPrimeFromComposite) {
    EXPECT_EQ(5, nextPrime(4));
    EXPECT_EQ(7, nextPrime(6));
    EXPECT_EQ(11, nextPrime(8));
    EXPECT_EQ(11, nextPrime(9));
    EXPECT_EQ(11, nextPrime(10));
    EXPECT_EQ(13, nextPrime(12));
}

// Тест 7: проверка sumPrime для малых границ
TEST(PrimeTest, SumPrimeSmall) {
    EXPECT_EQ(0, sumPrime(0));
    EXPECT_EQ(0, sumPrime(1));
    EXPECT_EQ(0, sumPrime(2));
    EXPECT_EQ(2, sumPrime(3));
    EXPECT_EQ(5, sumPrime(4));
}

// Тест 8: проверка sumPrime для средних границ
TEST(PrimeTest, SumPrimeMedium) {
    EXPECT_EQ(17, sumPrime(10));   // 2+3+5+7=17
    EXPECT_EQ(28, sumPrime(12));   // 2+3+5+7+11=28
    EXPECT_EQ(41, sumPrime(14));   // 2+3+5+7+11+13=41
    EXPECT_EQ(77, sumPrime(20));   // сумма до 19
}

// Тест 9: комплексная проверка согласованности функций
TEST(PrimeTest, ConsistencyCheck) {
    // n-ое простое число должно быть следующим после (n-1)-го
    uint64_t prime5 = nPrime(5);  // 11
    uint64_t prime4 = nPrime(4);  // 7
    EXPECT_EQ(prime5, nextPrime(prime4));
    
    // сумма простых до 20 должна включать 19
    uint64_t sum = sumPrime(20);
    EXPECT_TRUE(checkPrime(19));
    EXPECT_GT(sum, 19);
}

// Тест 10: граничные значения и крайние случаи
TEST(PrimeTest, EdgeCases) {
    EXPECT_EQ(2, nextPrime(0));
    EXPECT_EQ(2, nextPrime(1));
    EXPECT_EQ(3, nextPrime(2));
    EXPECT_EQ(0, nPrime(0));
    EXPECT_FALSE(checkPrime(1000000)); // большое составное
    EXPECT_TRUE(checkPrime(999983));   // простое число
}