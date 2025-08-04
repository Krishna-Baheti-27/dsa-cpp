#include<bits/stdc++.h>
using namespace std;

// C++ STL consists of : 
// Algorithms
// Containers
// Functions
// Iterators

void explainPair() {
    // pair is simply a data type and p is the name of the variable of that pair data type
    pair<int,int> p = {1,3};
    cout << p.first << ' ' << p.second << '\n';
    pair<int,pair<int,int>> p2 = {2,{5,6}}; 
    // in a pair you can store 2 elements of any data type and that includes pair as well
    cout << p2.first << ' ' << p2.second.first << ' ' << p2.second.second << '\n';
    // declaring an array of pair data type
    pair<int,int> arr[3] = {{1,2}, {2,4}, {3,6}};  // this array has three elements of pair type
    // basically acts as a 2-d array
    // pairs are inside the utility library
    cout << arr[1].second << '\n'; // prints 4 
}

void explainVector() {
    // vectors internally maintains a dynamic array and thee pointers to first, last and end of memory block to ensure fast and random access
    vector<int> v;  // empty container or array {}
    v.push_back(10);  // {10}, for an empty container it will insert like queue or FIFO
    v.emplace_back(20); // {10,20}
    cout << v[0] << ' ' << v[1] << '\n';

    vector<pair<int,int>> vec; // vector can be of any data type like pair
    vec.push_back({1,2}); // passing the pair {1,2}  to the push_back function
    vec.emplace_back(3,4); // automatically assumes {3,4} to be a pair
    // so thats the main difference between push_back and emplace_back
    cout << vec[0].first << ' ' << vec[0].second << '\n';
    cout << vec[1].first << ' ' << vec[1].second << '\n';

    vector<int> vect(5); // creates a vector of size 5 having all elements as 0 or garbage
    // even after defining the size of vector here we can always increase it using push_back
    vector<int> vec2(4,10); // creates a vector of size 4 having all elements as 10
    for(int i = 0; i < 5; i++) cout << vect[i] << ' ';  // for this compiler all initialised to 0
    for(int i = 0; i < 4; i++) cout << vec2[i] << ' ';
    cout << '\n';

    // to create a deep copy of a vector
    vector<int> vec3(vec2);
    // now vec3 is a new vector having same elements as vec2 but a deep copy (stored in different memory locations)

    // iterators to access vector elements
    v.emplace_back(30);
    v.push_back(40);
    vector<int>::iterator it = v.begin(); // it points to memory location of first element of vector v
    // vector<int> here refers to the data type, we can have iterator for any data type and ::iterator is used to tell it is a iterator and 'it' is the name of that iterator
    cout << *it << '\n'; // use * operator to print the value at that memory location
    it++; // moves it to next location, similar to pointer
    cout << *it << '\n';

    vector<int>::iterator it2 = v.end(); // this points to the memory location after the last element,this was done so we can use for loop till it != v.end()
    it2--; // now points to the last element
    cout << *it2 << '\n'; // prints 40

    cout << v.at(0) << '\n'; // prints element at 0th index similar to v[0]
    cout << v.back() << '\n'; // prints the last element

    // we also have reverse iterators like v.rend() and v.rbegin() but never really used
    
    // how to loop the vector using iterators which does not require the knowledge of the size of vector
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) { // we stop we it reaches the location next to last element
        cout << *it << ' ';
    }
    cout << '\n';

    // shorthand of doing above
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << *it << ' ';
    }
    cout << '\n';
    // use of auto can be extended to other data types and not just iterators
    auto a = 5; // a is now of integer type

    // printing using for each loop, for each element in vector v, print element
    for(auto element : v) {
        cout << element << ' ';
    }
    cout << '\n';


    // deletion in a vector at a particular index
    vector<int> vec4 = {1,2,3,4,5,6};
    vec4.erase(vec4.begin() + 1); // erases 2 and vec4 is now : {1,3,4,5,6}
    for(auto i : vec4) cout << i << ' ';
    cout << '\n';
    
    vec4.erase(vec4.begin() + 1, vec4.begin() + 4); // deletes elements from 2nd to 4th position, as the second argumnet passed is the location before which we want to delete  -> [start,end)
    // end is not included or end is not inclusive in the interval
    // vector now is {1,6}
    for(auto i : vec4) cout << i << ' ';
    cout << '\n';

    // deletion of the last element
    vec4.pop_back(); // does not return the deleted element
    // BUTTTTTTTTTTTTT
    // Yes, the erase() function in C++ STL vectors returns an iterator to the element that follows the last element erased. If you erase the last element, the returned iterator will be equal to vector.end(). This allows you to safely continue iterating through the vector after erasure, especially useful when removing elements in a loop.

    // INSERT FUNCTION
    vector<int> vec5(2,100); // {100,100}
    vec5.insert(vec5.begin(),300); // {300,100,100}
    // this will insert 300 at the address passed, which in this case is v.begin() or location of first element
    vec5.insert(vec5.begin() + 1,400); // {300,400,100,100}
    // vec5.begin() + 1 is the location of second element

    // to insert multiple occurrences of the same element at a given location
    vec5.insert(vec5.begin(),3,99); // {99,99,99,300,400,100,100}  at the very first position, insert 3 occurrences of 99 
    for(auto el : vec5) cout << el << ' ';
    cout << '\n';
    vec5.insert(vec5.end(),4,0); // {99,99,99,300,400,100,100,0,0,0,0}
    // insert 4 zeroes at the memory location right next to last element
    for(auto el : vec5) cout << el << ' ';
    cout << '\n';


    // inserting one vector into another vector
    vector<int> copy = {1,4,5};
    vec5.insert(vec5.begin(),copy.begin(),copy.end()); // {1,4,5,99,99,99,300,400,100,100,0,0,0,0}
    // insert the vector copy from its first to last location at the location v.begin()
    for(auto el : vec5) cout << el << ' ';
    cout << '\n';


    // OTHER MISCELLANEOUS
    cout << vec5.size() << '\n'; // returns number of elements currently stored in the vector
    vec5.pop_back(); // {1,4,5,99,99,99,300,400,100,100,0,0,0}
    // deletes the last element
    for(auto el : vec5) cout << el << ' ';
    cout << '\n';

    copy.swap(vec5); // now both are swapped by memory location
    // now vec5 has become copy and copy has become vec5
    for(auto el : vec5) cout << el << ' ';
    cout << '\n';
    cout << vec5.size() << '\n';
    vec5.clear(); // erases the entire vector
    cout << vec5.size() << '\n';
    cout << vec5.empty() << '\n'; // returns true or 1 if vector is empty otherwise false or zero
}

void explainList() {
    // list internally uses a doubly linked list
    list<int> ls; // {}
    ls.push_back(10);  // {10}
    ls.emplace_back(20); // {10,20}
    ls.push_front(30); // {30,10,20} these are cheaper than insert in vectors as DLL is used 
    ls.emplace_front(5); // {5,30,10,20}
    for(auto el : ls) cout << el << ' ';
    cout << '\n';
    // rest functions are same as vectors
    // begin, end, rend, rbegin, clear, insert, size, empty
}

void explainDeque() { // double ended queue
    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(-1);
    dq.emplace_front(-2);
    for(auto el : dq) cout << el << ' ';
    cout << '\n';
    dq.pop_back();
    dq.pop_front();
    cout << dq.front() << ' ' << dq.back() << '\n';
    for(auto el : dq) cout << el << ' ';
    cout << '\n';

    // rest everything similar
}

void explainStack() {
    stack<int> st;
    st.push(1);  // {1}
    st.push(2);  // {2,1}
    st.emplace(3); // {3,2,1}
    cout << st.top() << '\n'; // 3
    st.pop(); // {2,1}
    cout << st.top() << '\n'; // 2
    // remember, st[0] or anything like that is not allowed inside a stack
    // rest same like swap, empty , clear, size
}

void explainQueue() {
    queue<int> q;
    q.push(1); // {1}
    q.emplace(2); // {1,2}
    q.push(3); // {1,2,3}
    q.pop(); // {2,3} FIFO
    q.back() += 5; // {2,8}
    cout << q.front() << ' ' << q.back() << '\n';  // 2 8
    q.pop(); // {8}
    cout << q.front() << '\n';  // 8
}

void explainPrioriyQueue() {
    // this not a linear data structure and inside it a tree is maintained
    priority_queue<int> pq;  // maximum priority queue or max heap
    pq.push(10);
    pq.push(21);
    pq.emplace(8); 
    // 21 would be at top since its a maximum priority queue
    cout << pq.top() << '\n'; // 21
    pq.pop(); // 21 gets deleted
    cout << pq.top() << '\n'; // 10


    // MINIMUM HEAP or minimum priority queue
    priority_queue<int,vector<int>,greater<int>> pqq;
    pqq.push(1);
    pqq.push(10);
    pqq.push(-1);
    cout << pqq.top() << '\n'; // -1 as its a min priority queue
    pqq.pop();
    cout << pqq.top() << '\n'; // 1
}

void explainSet() {
    set<int> st;
    // a set is a container which stores everything in a sorted order and stores only unique elements not duplicates
    st.insert(1); // {1}
    st.emplace(2); // {1,2} in sorted fashion
    st.insert(2); // {1,2}, does not store duplicates
    st.insert(4); // {1,2,4}
    st.insert(3); // {1,2,3,4} , sorted

    auto it = st.find(3); // returns an iterator which points to the memory location of 3
    auto it2 = st.find(5); // since 5 is not in the set, it returns st.end() which is nothing but the location right after the last element as in vector

    int cnt = st.count(2); // {1,2,3,4}
    // returns the number of occurrences of 2, but since its a set and doesn't have duplicates, it will simply return 1 if the element is present as there cannot be more than one occurrences and return 0 if the element is not present as there are 0 occurrences

    st.erase(3); // deletes 3 from set -> {1,2,4}
    st.erase(it2); // also works as we pass the memory location to erase

    // example let there be a set st2 -> {1,2,3,4,5}
    set<int> st2;
    auto it3 = st2.find(2); // the address from which you want to start deleting
    auto it4 = st2.find(5); // address before which you want to delete
    st2.erase(it3,it4); // erases everything from 2 to 4 -> {1,5} // same as in vector

    // understand lower_bound and upper_bound for vectors and sets, same for both
}

void explainMultiset() {
    multiset<int> ms;
    // stores everything in the sorted order but not unique, can store multiple occurrences
    ms.insert(1); // {1}
    ms.emplace(1); // {1,1}
    ms.insert(1); // {1,1,1}
    ms.insert(2); // {1,1,1,2}
    ms.erase(1); // {2} 
    // when we erase a element, it deletes all occurrences of that element
    // better way is to erase using a iterator
    ms.erase(ms.find(1)); // this will find the first occurrence of 1 and delete that memory location
    // to delete multiple occurrences, use a loop and iterate till ms.end() and delete the iterator each time and it automatically increments
    // EXAMPLE CODE
//     int count = 2;  // Number of occurrences to erase
// auto it = ms.find(1);
// while (it != ms.end() && count--) {
//     it = ms.erase(it);, // since erase returns the iterator pointing to memory just past the element which is deleted
// }
}

void explainUnorderedSet() {
    // same as set but stores only unique elements in random fashion and not sorted fashion
    // lower_bound() and upper_bound() functions do not work, since it is not sorted so not defined
    unordered_set<int> ust;
    // most operations take O(1) since implemented using hash table, unlike set or multiset which uses BST and hence logN, but in worst case having multiple collisions, time is O(N)
}

void explainMap() {
    // set of key-value of pairs
    // keys for a map are unique and stored in a sorted fashion<, used to access the value
    map<string,int> people = {{"John",20}, {"Chris",30}, {"krishna",10}};
    cout << "Age of john is : " << people["John"] << '\n';
    cout << "Age of krishna is : " << people.at("krishna") << '\n';
    people["krishna"] = 18; // can modify values
    cout << "Age of krishna is : " << people.at("krishna") << '\n';
    people["ramesh"] = 50; // can add new values

    // adding new values using insert
    people.insert({"bajaj",90}); // pass the key-value pair to the insert function

    // to delete
    people.erase("bajaj"); // deletes that key value pair
    cout << people.count("krishna") << '\n'; // returns 1 if the key exists, otheriwise 0


    // HOW TO ITERATE THROUGH A MAP
    // You should use the auto keyword (introduced in C++ version 11) inside the for loop. This allows the compiler to automatically determine the correct data type for each key-value pair.
    // Since map elements consist of both keys and values, you have to include .first to access the keys, and .second to access values in the loop.
    // Elements in the map are sorted automatically in ascending order by their keys:

    for(auto person : people) {
        cout << person.first << ' ' << person.second << '\n';
        // this will print the according to keys arranged in sorted fashion
    }

    auto it = people.find("krishna");
    cout << (*it).first << ' ' << (*it).second << '\n'; 
    // this way you can also access using a iterator

    // Iterating through the map using an iterator
    for (auto it = people.begin(); it != people.end(); ++it) {
    std::cout << it->first << " " << it->second << std::endl;
    }
    // since it is a pointer or iterator use -> , *it does not work since multiple values contained

//     Best Practice
// Use const auto& when you do not need to modify the elements and want to avoid the overhead of copying, especially for containers holding complex or large types.

// Use auto& if you need to modify the elements in place.

// Use auto (by value) only if you explicitly want a copy of each element.
// so simply using for(auto person : people) is inefficient as it creates unnecessary copies
}

void explainMultiMap() {
    // everything same but can store duplicate keys
    // mpp[key] cannot be used here
}

void explainUnorderedMap() {
    // unique keys but stored in random order, not sorted
    // same usually O(1) but worst case is O(N)
}

bool myWayComparator(pair<int,int> p1, pair<int,int> p2) {
    if(p2.second > p1.second) return true; // already sorted
    else if(p2.second < p1.second) return false;
    else {
        if(p1.first > p2.first) return true; // works
        return false; // does not work
    }

    // basically break the problem into comparison of two elements of array and write comaparator and rest will be taken care by sort
}

void explainAlgorithms() {
    int arr[10];
    int n = 10;
    sort(arr, arr + n); // to sort the array
    sort(arr, arr +n, greater<int>()); // to sort in reverse order 
    // use () because greater<int> is not a function in itself
    sort(arr + 2, arr + 4); // to sort from third to 4th element, basically arr+ 2 and arr + 3, 
    // arr + 4 is not included
    vector<int> vec;
    sort(vec.begin(), vec.end());  // to sort vector
    sort(vec.begin(), vec.begin() + 3); // to sort first three elements, from 0 to 2

    // SORT IT ACCORDING TO MY WAY
    pair<int,int> a[] = {{2,1}, {1,2}, {4,1}};
    // sort it according to second element but if both same then according to first 
    // but in decreasing order

    // To print all permutations of string
    string s = "123"; // should be sorted to print all else sort it sort(s.begin(), s.end())
    do {
        cout << s << endl;
    } while(next_permutation(s.begin(), s.end()));
    auto maxIterator = max_element(arr,arr + n);
    int maxElement = *maxIterator;
    // similarly min_element
}

int main() {
    explainMap();
    return 0;
}