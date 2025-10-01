#include<bits/stdc++.h>
using namespace std;

int divideBrute(int dividend, int divisor) {
    // we have to divide without using * , / or % so basically we can use +,- since we know division is nothing but repeated subtraction
    int count = 0, num = 0;
    while(num + divisor <= dividend) {
        count++;
        num += divisor;
    }
    // here num > dividend so our answer is count
    return count;
} // O(dividend) time since if we are given divisor = 1 and dividend = INT_MAX, so loop will run for 2^31 - 1 times

// int divideOptimal(int dividend, int divisor) {
//     if(dividend == divisor) return 1;
//     int sign = 1;
//     if(dividend >= 0 && divisor < 0) sign = -1;
//     else if(dividend <= 0 && divisor > 0) sign = -1;
//     // if dividend == INT_MIN, then its absolute will over flow so check that
//     int divden = dividend == INT_MIN ? INT_MAX : abs(dividend);
//     int divis = abs(divisor);
//     int ans = 0;
//     while(divis <= divden) {
//         int mul = 1;
//         while(divis * mul <= divden) {
//             mul *= 2;
//         }
//         mul /= 2;
//         ans += mul;
//         divden -= divis * mul;
//     } 
//     return ans * sign;
// }
// This shows use long long for computation and it will never result in overflow and handle the only overflow case in integer division separately

int divideOptimal1(int dividend, int divisor) {
    if(dividend == divisor) return 1;
    // This is the only case in integer division which can lead to overflow
    if(dividend == INT_MIN && divisor == -1) return INT_MAX; 

    // when we compute abs(INT_MIN) it would overflow for an integer resulting in an error and hence first typecast into long long then compute INT_MIN
    long long longDivisor = abs((long long)divisor);
    long long longDividend = abs((long long)dividend);

    int sign = ((dividend < 0) ^ (divisor < 0) ? -1 : 1); // concise way to check if the sign is negative or not
    // it works on 1 ^ 0 and 0 ^ 1 both give 1 that is negative sign else positive sign

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
    return ans * sign; // automatically converts back to int even though ans is long long since that is what function returns, so implicit conversion
} // O((logn) ^ 2) time and O(1) space


// This is more dangerous and not at all robust code for implementing this solution

// int divideOptimal2(int dividend, int divisor) {
//     if(dividend == divisor) return 1;
//     int sign = ((dividend < 0) ^ (divisor < 0) ? -1 : 1);

//     long long ldivisor = abs((long long)divisor);
//     long long ldividend = abs((long long)dividend);
//     long long ans = 0;

//     while(ldividend >= ldivisor) {
//         int count = 0;
//         while(ldividend >= ldivisor << (count + 1)) { // since dividend >= divisor * 2^(count + 1)
//             count++;
//         }
//         ans += (1 << count); // ans += 2^(count), (one lesse than count, since that was more)
//         ldividend -= (ldivisor << count); // decrease the dividend
//     }
//     if(ans > INT_MAX) {
//         if(sign == 1) return INT_MAX;
//         return INT_MIN;
//     }
//     return ans * sign;
// } // O((logn) ^ 2) time and O(1) space

int main() {
    
    return 0;
} 