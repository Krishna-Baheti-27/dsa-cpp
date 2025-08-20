// segmentation fault occurs when there is something wrong with the memory like stack overflow

#include <iostream>
#include<string.h>
using namespace std;

int count = 0;

void print() {
    if(count == 3) return;
    cout << count << '\n';
    count++;
    print();
}

void printName(string name, int n) {
    if(n == 0) return;
    cout << name << '\n';
    printName(name, n - 1);
}

void print1ToN(int i, int n) {
    if(i > n) return;
    cout << i << '\n';
    print1ToN(i+1,n);
}

void printNTo1(int n) {
    if(n == 0) return;
    cout << n << '\n';
    printNTo1(n-1);
}

void print1TONBacktrack(int n) {
    // basically print statement should be after the recursive call or function should print while returning not while calling, that is backtracking
    if(n == 0) return;
    print1TONBacktrack(n-1);
    cout << n << '\n'; // print after recursive call
}

void printNTo1Backtrack(int i,int n) {
    // print statement after recursive call
    if(i > n) return;
    printNTo1Backtrack(i + 1, n);
    cout << i << '\n';
}

int sum1ToN(int n) {
    if(n == 0) return 0;
    else return n + sum1ToN(n - 1);
}

// here is the parameterised version
int sum1ToNParam(int i, int n ) {
    if(i == n) return n;
    else return i + sum1ToNParam(i+1, n);
}

int fact(int n) {
    if(n == 0) return 1;
    else return n * fact(n-1);
}

void reverseArray(int arr[], int i, int j) {
    // i  = 0 initially and  j = n - 1 initially
    // swapping first and last element and then moving the pointers ahead 
    if( i > j) return; // if i crossed j means entire thing has been traversed and reversed
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    reverseArray(arr, i + 1, j - 1); // each time increment i with 1 nad decrement j with 1
}

bool isPalindrome(const string &s, int i, int j) {
    // we send string by reference because in cpp unlike arrays, strings are not passed by ref, so we do that here to avoid creation of unnecessary copies
    if(i >= j) return true; // this should be checked before just because i and j should be valid indices for string
    if(s[i] != s[j]) return false;
    return isPalindrome(s, i + 1, j - 1);
}

int fib(int n) {
    if(n == 1) return 0;
    if(n == 2) return 1;
    return fib(n-1) + fib(n-2);
}

int fibUsingLoop(int n) {
    // 0 1 1 2 3 5 so on
    if(n == 1) return 0;
    if(n == 2) return 1;
    int first = 1, second = 2;
    for(int i = 0; i < n - 3; i++) {
        // we run for loop exactly that many times that we reach our desired location
        int temp = second; 
        second = second + first;
        first = temp;
    }
    return first;
}

int main() {
    // printName("John", 5);
    // print1ToN(1,10);
    // printNTo1(10); 
    // print1TONBacktrack(10);
    // printNTo1Backtrack(1,10);
    // cout << sum1ToN(10) << '\n';
//     cout << sum1ToNParam(1,100) << '\n';
//     cout << fact(5) << '\n';
    // int arr[] = {1,2,3,4,5,6};
    // int n  = sizeof(arr) / sizeof(arr[0]);
    // for(int num : arr) cout << num << ' ';
    // cout << endl;
    // reverseArray(arr,0,n-1);
    // for(int num : arr) cout << num << ' ';
    // // cout << endl;
    // string str = "madam";
    // cout << isPalindrome(str,0,4) << '\n';
    // string str1 = "krishna";
    // cout << isPalindrome(str1,0,6) << '\n';

    cout << fibUsingLoop(4) << '\n';
    cout << fib(5) << '\n';
}