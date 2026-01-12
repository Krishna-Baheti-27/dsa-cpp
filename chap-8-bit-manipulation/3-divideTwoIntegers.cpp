#include<bits/stdc++.h>
using namespace std;

// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

// The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

// Return the quotient after dividing dividend by divisor.

// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

//////////////////////////////////////////////////////////////////////////////////////

 // we have to divide without using * , / or % so basically we can use +,- since we know division is nothing but repeated subtraction

int divideBrute(int dividend, int divisor) {
   
    int count = 0, num = 0;

    while(num + divisor <= dividend) {
        count++;
        num += divisor;
    }
 
    return count;

} // O(dividend) time since if we are given divisor = 1 and dividend = INT_MAX, so loop will run for 2^31 - 1 times

/////////////////////////////////////////////////////////////////////////////////////////

// for 22 / 3 we have 7 which can be written as 2^2 + 2^1 + 2^0 so this is what we do in each step still possible and if not then number - 1 is what is added in our quotient

int divideOptimalImcorrect(int dividend, int divisor) {

    if(dividend == divisor) {
        return 1;
    }

    // This is the only case in integer division which can lead to overflow

    if(dividend == INT_MIN && divisor == -1) {
        return INT_MAX; 
    }

    // when we compute abs(INT_MIN) it would overflow for an integer resulting in an error and hence first typecast into long long then compute INT_MIN

    long long longDivisor = abs((long long)divisor);
    long long longDividend = abs((long long)dividend);

    // concise way to check if the sign is negative or not

    int sign = ((dividend < 0) ^ (divisor < 0) ? -1 : 1); 
    
    long long ans = 0;

    while(longDividend >= longDivisor) {

        long long mul = 1;

        while(longDivisor * mul <= longDividend) {
            mul = mul << 1;
        }

        mul = mul >> 1;
        ans += mul;
        longDividend -= longDivisor * mul;
    }

    // automatically converts back to int even though ans is long long since that is what function returns, so implicit conversion

    return ans * sign;

} // O((logn) ^ 2) time and O(1) space

//////////////////////////////////////////////////////////////////////////////////////

// this is our core logic but we are using multiplication operators so we prevent that by using left and right shifts instead

// here is the correct code

int divideOptimal(int dividend, int divisor) {

    if(dividend == divisor) {
        return 1;
    }
    
    // Handle overflow edge case

    if(dividend == INT_MIN && divisor == -1) {
        return INT_MAX; 
    }

    long long longDivisor = abs((long long)divisor);
    long long longDividend = abs((long long)dividend);
    
    int sign = ((dividend < 0) ^ (divisor < 0) ? -1 : 1); 

    long long ans = 0;

    while(longDividend >= longDivisor) {
        
        long long tempDivisor = longDivisor;
        long long mul = 1;

        // Instead of (divisor * mul), we shift the divisor itself
        // checking (tempDivisor << 1) is like checking (tempDivisor * 2)

        while (longDividend >= (tempDivisor << 1)) {
            tempDivisor = tempDivisor << 1; // Double the divisor
            mul = mul << 1;                 // Double the multiplier
        }

        // We found the largest chunk (tempDivisor) that fits into longDividend

        ans += mul;
        longDividend -= tempDivisor;
    }

    return sign == -1 ? -ans : ans;

} // O((logn) ^ 2) time and O(1) space

int main() {
    
    return 0;
} 