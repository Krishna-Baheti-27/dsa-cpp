#include<bits/stdc++.h>
using namespace std;

// we are given an array of n books and arr[i] represents the number of pages in the ith book and we have to allocate all the n books to m students in a way that :

// Each student must get atleast one book, same book cannot be alloted to two students and book allocation should be in contiguous manner (from book 1 to book n and to student 1 to student m) 

// And after all possible configurations thus obtained you first have to calculate the max number of pages alloted to single student in a particular config and then we to find the min of all such max pages of each config, if allocation is not possible return -1

/////////////////////////////////////////////////////////////////////////////////////////

// so when is allocation, not possible, if number of students > number of books then allocation is not possible hence, return -1, thats the only case else everyone will get atleast one book and the above allocation criteria will be satisfied

// so now we have to find the range of possible answer, that is the min value of max pages assigned will be max element of array (give only one book to make it min but give the book with max number of pages so thats why max element) and the max value of max pages assigned will be sum of all array elements since if you have only one student then you will give all the books to him/her and thus number of pages = sum of array elements (sum of pages of each book)

// now that we know the range of our answer we can easily write a linear search solution in which we start from miPages to maxPages each time and if we can allocate n books to m students then return that as our answer since we want min value of max pages assigned

// lets go and write brute force linear search approach

int bookALlocBrute(vector<int> &arr, int m) {

    if(m > arr.size()) return -1; // more students then available books

    int minPages = *max_element(arr.begin(), arr.end());
    int maxPages = reduce(arr.begin(), arr.end(), 0); // to find sum of array elements

    for(int pages = minPages; pages <= maxPages; pages++) {

        // now what we have to do is maintain the fact that we cannot allocate more than 'pages' pages to any student since thats our condition, and in this way we try to allocate from start and if exceed 'pages' pages then we move to next student and thus count all the students

        // if we are able to allocate to m students then pages is our answer and we return it

        // this allocation logic is a bit trick to please understand it carefully

        int studentNo = 1, studentPages = 0; // intially student 1 is holding 0 pages

        for(int i = 0; i < arr.size(); i++) {

            // can still give to current student without violating our condition of max pages to be assigned equal to 'pages'

            if(studentPages + arr[i] <= pages) {
                studentPages += arr[i]; 
            } else {
                studentNo++; // move to next student
                studentPages = arr[i]; // and give him the new pages
            }

            // here when giving pages to new student we dont have to check if arr[i] <= pages since the value of pages starts from max_element so we can allocate a single book to any student without any checks, but when allocating more than one book then we have to check if the value of pages exceeds 'pages' or not
        }

        // now check if number of students allocated == m

        if(studentNo == m) return pages;
    }
     
    return -1; // it would never hit since we already dealt with case of book allocation not possible

} // O((sum - max + 1) * n) time

//////////////////////////////////////////////////////////////////////////////////////

// since we now have the range of answer we can use binary search

// its pretty easy to write the binary search code, only tricky bit is finding whether allocation is possible or not and we do that here in a separate function

bool isPossible(vector<int> &arr, int m, int mid) {

    int studentCount = 1, studentPages = 0;

    for(int i = 0; i < arr.size(); i++) {

        if(studentPages + arr[i] <= mid) {
            studentPages += arr[i];
        } else {
            studentCount++;
            studentPages = arr[i];
        }
    }

    return studentCount <= m; // since we want an even smaller value

    // you can also simply return studentCount and used the if-else to determine like we do in binary search
}

int bookAllocOptimal(vector<int> &arr, int m) {

    if(m > arr.size()) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = reduce(arr.begin(), arr.end(), 0); // to find sum of array
    int ans = high;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        // now check for mid number of pages, if it satisfies or not

        if(isPossible(arr, m, mid)) {
            ans = mid; // take it as a possible answer
            high = mid - 1; // but look for smaller answer
        } else {
            low = mid + 1; // try to reach the answer
        }
    }

    return ans;

} // O(log(sum - max) * n) time 

int main() {
    
    return 0;
}