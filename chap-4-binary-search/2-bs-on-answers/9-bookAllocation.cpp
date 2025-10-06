#include<bits/stdc++.h>
using namespace std;

// we have to allocate arr.legnth books to m students in such a way that their allocation criteria is fullfilled that is each student must get atleast one book, same book cannot be alloted to two students and book allocation should be in contiguous manner, and after all possible configurations thus obtainec you first have to calculate the max number of pages alloted to single student in a particular config and then we to find the min of all such max pages of each config, if allocation is not possible return -1

// so when is allocation, not possible, if number of students > number of books then allocation is not possible hence, return -1

// so now we have to find the range of possible answer
// the least possible value of ans = max_element(arr) since, we have to make sure that every student gets atleast one book, if lets say we start with a range lesser than max_element, then we know that the max_element would not be allocated to any student, and we have to allocate atleast one book to each student and what we are essentially doing is allocate a book student by checking if it lesser than max permissible value, if it is then we also try allocating next one to that student by checking if sum < max permissible value

// so our max permissible value starts from max_element(arr) and ends at sum of all array elements becuase in case of single student we have to allocate each to book to that single studnet only

// so what we are asked is to find the min value of all such max configs

// lets go and write brute force linear search approach

int bookALlocBrute(vector<int> &arr, int m) {
    if(m > arr.size()) return -1;
    int minPages = *max_element(arr.begin(), arr.end());
    int maxPages = reduce(arr.begin(), arr.end(), 0);
    for(int pages = minPages; pages <= maxPages; pages++) {
        // now we count the students when there are maximum "pages" pages and check if number of students == m, then return pages
        int studentNo = 1, studentPages = 0; // intially student 1 is holding 0 pages
        for(int i = 0; i < arr.size(); i++) {
            if(studentPages + arr[i] <= pages) {
                // we are still under our limit so need to move to next student
                studentPages += arr[i]; 
            } else {
                // when out of limit, move to next student and give him the current pages
                studentNo++;
                studentPages = arr[i];
            }
        }
        // now check if number of students allocated == m
        if(studentNo == m) return pages;
    }
    return -1;
} // O((sum - max + 1) * n) time

// since we now have the range of answer we can use binary search

int bookAllocOptimal(vector<int> &arr, int m) {
    if(m > arr.size()) return -1;
    int low = *max_element(arr.begin(), arr.end(), 0);
    int high = reduce(arr.begin(), arr.end(), 0); // to find sum of array
    while(low <= high) {
        int mid = low + (high - low) / 2;
        // now check for mid, if it satisfies or not
        int studentNo = 1, studentPages = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(studentPages + arr[i] <= mid) {
                studentPages += arr[i];
            } else {
                studentNo++;
                studentPages = arr[i];
            }
        }
        if(studentNo <= m) {
            high = mid - 1; // i will take it as an aswer but look for smaller one
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    
    return 0;
}