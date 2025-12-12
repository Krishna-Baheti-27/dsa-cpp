#include<bits/stdc++.h>
using namespace std;

// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

// and by partition we mean that their union is the entire array and intersection is nothing

////////////////////////////////////////////////////////////////////////////////////////////

// so if we divide an array into two partitions then s1 + s2 = sum of array elements where s1 is sum of partition 1 and similarly for s2, but the question states if s1 == s2 then s1 == s2 == s / 2, so if we can find any subset having the target sum == s/2 where s is sum of array then we return true that such partition exists 

// so same as last question but target == s / 2

// but there is a problem, if s is odd then s / 2 is a decimal value but how can be sum of integers be a decimal/floating value and hence if s % 2 != 0 then we return false else we check if s / 2 is present as a target sum if yes then return true else return false



int main() {
    
    return 0;
}