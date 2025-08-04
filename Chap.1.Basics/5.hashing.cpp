#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string.h>
using namespace std;

// // note : if you are declaring an array of integers
// // in main -> the max size of array can be 10^6
// // but if you decalre it globally -> the max size of the array can be 10^7
// // hence global is better

// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     // getting the array,
//     // precompute
//     int hashh[100] = {0}; // assuming elements in the range 0-99 both inclusive
//     for(int i = 0; i < n; i++) {
//         hashh[arr[i]]++;
//     }
//     int q; // no of queries
//     cin >> q;
//     vector<int> res;
//     while(q--) {
//         // shortcut to do something q times
//         int number;
//         cin >> number;
//         // fetch
//         res.push_back(hashh[number]); // hashh[number] just fetches or returns the frequency of the number
//     // getting the array,
//     // precompute
//     int hashh[100] = {0}; // assuming elements in the range 0-99 both inclusive
//     for(int i = 0; i < n; i++) {
//         hashh[arr[i]]++;
//     }
//     int q; // no of queries
//     cin >> q;
//     vector<int> res;
//     while(q--) {
//         // shortcut to do something q times
//         int number;
//         cin >> number;
//         // fetch
//         res.push_back(hashh[number]); // hashh[number] just fetches or returns the frequency of the number
//     }
//     // printing result
//     }
//     // printing result
//     for(int result : res) cout << result << '\n'; 
//     return 0;
// }

// int main() {
//     string str;
//     cin >> str;
//     vector<int> res;
//     int hashh[26] = {0}; // to store the occurence of 26 lower case english alphabet letters
//     // precompute
//     for(int i = 0; str[i] != '\0'; i++) {
//         // a means 0, b means 1 and so on
//         // so ascii value of a is 97, so i want to store stuff by subtracting 97 from each char
//         hashh[str[i] - 97]++; // understand it fully or you could have also written str[i] - 'a'
//     }
//     int q;
//     cin >> q;
//     while(q--) {
//         char ch;
//         cin >> ch;
//         res.push_back(hashh[ch - 97]); // fetch
//     }
//     for(int result : res) cout << result << '\n';

//     // if you want to store and make a hashh array for 256 characters you can do that, and you store frequency of each character at the index = its ascii value
// }


// STORING THE FREQUENCY OF ELEEMENTS AS VALUES, AND THE ELEMENT ITSELF AS KEYS TO HANDLE LARGE DATA SETS WITHOUT SIZE CONSTRAINT
int main() {
    int n;
    cin >> n;
    int arr[n]; 
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        // by the way you can also precompute during taking input as well
    }
    // pre compute
    map<int,int> mpp;
    // for finding frequency of characters use
    map<char,int> mppChar; // char to store the key and int to store the freq. or value
    vector<int> res;
    for(int i = 0; i < n; i++) {
        mpp[arr[i]]++;
        // this will generate the key as the element itslef and ++ will increase its frequency from 0 to 1 and so on
    }
    // iterating the map
    // for(auto it : mpp) {
    //     cout << it.first << " -> " << it.second << '\n';
    // }
    int q;
    cin >> q;
    while(q--) {
        int number;
        cin >> number;
        // fetch
        res.push_back(mpp[number]); // mpp of number would the bring the value stored in key, number
    }
    for(int result : res) {
        cout << result << '\n';
    }
}

//  NOTE ALL OF THE ABOVE CODE WOULD STILL WORK IF YOU REPLACE THE MAP BY UNORDERED MAP and its better to use unordered_map since it stores and fectches in O(1) instead of map which takes O(logN) but in the worst case unordered_map might take O(n) due to collisions and your code may give TLE, in that case use map otherwise unordered_map more suitable and efficient

// basically internally unordered_map use various methods of hashing like division method and if collision happens such that all the entries go to the same key, then you would have to traverse a whole list to get to the last element hence worst time is O(n) but rarely happens

