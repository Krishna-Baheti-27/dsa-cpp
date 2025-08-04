#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
using namespace std;

class Node {  // can also use struct but you miss all the OOP advantages
    public:
    int data;
    Node *next;
    Node(int data, Node *next) {
        this->data = data; // instead of this you can also use simply data = data1 (change the parameter name)
        this->next = next;
    }
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

Node* arrayToLL(vector<int> &arr) {
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for(int i = 1; i < arr.size(); i++) {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

int isLoopNaiveSolution(Node *head) {
    map<Node*,int> mp;
    Node *temp = head;
    while(temp) {
        if(mp.count(temp) == 1) return 1; // there is a loop
        mp[temp] = 1; // 1 marks that the node is visited
        temp = temp->next;
    }
    return 0; // no loop
}

int isLoopOptimised(Node *head) {
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return 1; // if slow and fast meet, means loop exists
        // in a loop they are guaranteed to meet because the distance between them will decrease by 1 in each iteration sinceslow moves 1 step and fast moves 2 steps (difference = 2 - 1 = 1) , so difference will always be 1 no matter what the intial distance maybe, it will always decrease by 1 and thus guaranteed it will become zero
    }
    return 0; // no loop exists
}

// Intuition:
// The slow pointer moves one step at a time.

// The fast pointer moves two steps at a time.

// Once both enter the loop, the fast pointer starts gaining on the slow pointer by 1 step per iteration (2 - 1 = 1).

// Since the loop is finite (say, C nodes in the loop), the fast pointer is guaranteed to catch up to the slow pointer in at most C steps — just like how two runners on a circular track will eventually meet if one is faster.

// CODE TO FIND THE STARTING POINT OF LOOP
Node* detectLoopStart(Node *head) {
    Node *slow = head, *fast = head;

    // Step 1: Detect if loop exists
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }

    // No loop
    if (slow != fast) return nullptr;

    // Step 2: Find the entry point
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // Start of the loop
}
// it is way easier to find starting node of loop in LL using hashing as the first node to have mp.count(temp) == 1 is the node from which loop will begin and all the nodes after that will have mp.count() == 1

int lengthOfLoopNaive(Node *head) {
    // we basically have to subtract the nodes not in the loop from total nodes
    int index = 0;
    map<Node*,int> mp;
    Node *temp = head;
    while(temp) {
        if(mp.count(temp) == 1) return index - mp[temp]; // as soon as loop is detected
        mp[temp] = index++; // mp[temp] helps us give number of nodes at that temp, for temp = head, mp[temp] = 0
        temp = temp->next;
    }
    return 0; // no loop
}

// int lengthOfLoopOptimised(Node *head) {
//     int len = 0; // basically count the number of nodes till the collision point
//     Node *slow = head, *fast = head;
//     while(fast && fast->next) {
//         len++;
//         slow = slow->next;
//         fast = fast->next->next;
//         if(slow == fast) return len;
//     }
//     return 0;
// } /// Not correct code : fails for 47 -> 11 -> 37 -> 8 -> 21 -> 41 -> 21

// int lengthOfLoopOptimised(Node *head) {
//     Node *slow = head, *fast = head;
//     int len = 0;
//     while(fast && fast->next) {
//         slow = slow->next;
//         fast = fast->next->next;
//         if(slow == fast) {
//             Node *temp = head;
//             while(temp != slow) {
//                 len++;
//                 slow = slow->next;
//                 temp = temp->next;
//             }
//             while(slow != fast) {
//                 slow = slow->next;
//                 len++;
//             }
//             return len;
//         }
//     }
//     return 0;
// } // this fails for cases like 17->37->17


// FINAL CORRECT CODE /////////////////
int lengthOfLoopOptimised(Node *head) {
    Node *slow = head, *fast = head;
    int len = 1;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        // its pretty easy, as soon as you encounter collision point, you just save one pointer and move other all the way around the loop by slow->next and increment length;
        if(slow == fast) {
            slow = slow->next;
            while(slow != fast) {
                slow = slow->next;
                len++;
            }
            return len;
        }
    }
    return 0;
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    Node *head = arrayToLL(arr);
    cout << lengthOfLoopNaive(head) << endl;
    return 0;
}