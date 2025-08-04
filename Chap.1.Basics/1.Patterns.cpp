#include<iostream>
using namespace std;

void print1(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "*";
        }
        cout << '\n';
    }
}

void print2(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << '\n';
    }
};

void print3(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << '\n';
    }
}

void print4(int n) {
    for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			cout << i << ' ';
		}
		cout << endl;
	}
}

void print5(int n) {
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            // it can also be thought as we are printing (n - i + 1) times where i is the row number i.e. 1,2,3...
            cout << "*";
        }
        cout << '\n';
    }
}

void print6(int n) {
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            cout << j << ' ';
        }
        cout << endl;
    }
}

void print7(int n) {
    for(int i = 1; i <= n; i++) {
        // outer loop runs n times
        // printing n - i spaces
        for(int j = 1; j <= n - i; j++) {
            cout << ' ';
        }
        // printing stars 2*i- 1 times
        for(int k = 1; k <= 2*i-1; k++) {
            cout << "*";
        }
        // no need to print spaces again since printing nothing is equivalent to printing spaces
        // basically its your choice, you can again print n - i spaces
        cout << '\n'; // end
    }
}

void print8(int n) {
    for(int i = 1; i <= n; i++) {
        // outer loop runs n times
        // printing i - 1 spaces
        for(int j = 1; j <= i - 1; j++) {
            cout << ' ';
        }
        // printing 2*(n-i) + 1 stars where i is from 1,2,3..
        for(int k = 1; k <= 2*(n-i) + 1; k++) {
            cout << "*";
        }
        cout << '\n'; // end
    }
}

void print9(int n) {
    // you can simply print pattern 7 and then pattern 8
    print7(n);
    print8(n);
    // or you can write its own code, but reusing already written code more preferable
}

void print10(int n) {
    // REVISE THIS FUNCTION AND CODE ONCE AGAIN
    // outer loop runs 2*n - 1 times since thats the number of rows
    for(int i = 1; i <= 2*n - 1; i++) {
        int stars = i; // number of stars = row number
        if(i > n) {
            stars = 2*n - i;  // these are the number of stars after we have surpassed  i = n
        }
        for(int j = 1; j <= stars; j++) {
            cout << "*";
        }
        cout << '\n';
    }
}

void print11(int n) {
    // outer loop runs n times
    for(int i = 1; i <= n; i++) {
        int toPrint;
        if(i % 2 == 0) toPrint = 0;  // for even row numbers, the first digit to be printed is 0
        else toPrint = 1;  // for odd row numbers, the first digit to be printed is 1
        for(int j = 1; j <= i; j++) {
            cout << toPrint << ' '; // we print the digit
            // the below two lines switch the digit
            if(toPrint == 0) toPrint = 1;  // if digit = 0 then make it 1
            else toPrint = 0; // if digit = 1 then make it 0

            // you can also switch the digit using
            // toPrint = 1 - toPrint
        }
        cout << '\n';
    }
}

void print12(int n) {
    // outer loop runs n times
    for(int i = 1; i <= n; i++) {
        // we have to print numbers,spaces,numbers
        // printing  i numbers
        for(int j = 1; j <= i; j++) {
            cout << j;
        }
        // priting 2 * (n - i) spaces
        for(int k = 1; k <= 2*(n-i); k++) {
            cout << ' ';
        }
        // printing i numbers, but in reversed fashion
        for(int l = i; l >= 1; l--) {
            cout << l;
        }
        cout << '\n'; // end
    }
} 

void print13(int n) {
    // outer loop runs n times
    int a = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << a << ' ';
            a++;
        }
        cout << '\n';
    }
}

void print14(int n) {
    // outer loop runs n times
    for(int i = 1; i <= n; i++) {
        for(char j  = 'A'; j <= 'A' + i - 1; j++) {
            // we can do arithmetic operations with characters in the same way as we do with integers
            cout << j;
        }
        cout << '\n';
    }
}

void print15(int n) {
    // outer loop runs n times but in reverse fashion
    for(int i = n; i >= 1; i--) {
        for(char j = 'A'; j <= 'A' + i - 1; j++) {
            cout << j;
        }
        cout << '\n';
    }
}

void print16(int n) {
    // outer loop runs n times
    for(int i = 1; i <= n; i++) {
        char ch = 'A' + i - 1;  // using dummy variable
        for(int j = 1; j <= i; j++) {
            // running inner loop i times and printing dummy variable
            cout << ch;
        }
        cout << '\n';
    }
}

void print17(int n) {
    // REVISE EXCELLENT CODE
    // outer loop runs n times
    for(int i = 1; i <= n; i++) {
        // we have to print spaces, characters and again characters
        // printing n - i spaces
        for(int j = 1; j <= n - i; j++) {
            cout << ' ';
        }  
        // priting i characters
        for(char j = 'A'; j <= 'A' + i - 1; j++) {
            cout << j;
        }
        // printing i - 1 charcters in reverse fashionn
        for(char j = 'A' + i - 2; j >= 'A'; j--) {
            // just dry run this for loop for better clarity
            cout << j;
        }
        cout << '\n';
    }
}

void print18(int n) {
    // outer loop runs n times
    char mainChar = 'A' + n - 1;  // our main character
    for(int i = 1; i <= n; i++) {
        char auxilary = mainChar - i + 1; // corresponding to that row
        // intially auxilary character is equal to mainChar for first row or i = 1
        for(char ch = auxilary; ch <= mainChar; ch++) {
            // print starting from auxilary to mainChar
            cout << ch << ' ';
        }
        cout << '\n';
    }
}

void print19(int n) {
    for(int i = 1; i <= 2*n; i++) {
        // outer loop runs 2*n times
        if(i <= n) {
            // printing nmubers
            for(int j = 1; j <= n - i + 1; j++) {
                // for 5, 4, 3 respectively stars
                cout << "*";
            }
            // printing spaces
            for(int k = 1; k <= 2*(i - 1); k++) {
                cout << ' ';
            }
            // printing numbers
            for(int j = 1; j <= n - i + 1; j++) {
                // for 5, 4, 3 respectively stars
                cout << "*";
            }
        } else {
            // printing numbers
            for(int j = 1; j <= i - n; j++) {
                cout << "*";
            }
            // printing spaces (most important and difficult to find relation)
            for(int j = 1; j <= 2*(2*n - i); j++) {
                cout << ' '; 
            }
            // printing numbers
            for(int j = 1; j <= i - n; j++) {
                cout << "*";
            }
        }
        cout << endl;
    }
}

void print20(int n) {
    for(int i = 1; i <= 2*n - 1; i++) {
        // outer loop runs 2*n - 1 times
        if(i <= n) {
            // printing numbers
            for(int j = 1; j <= i; j++) {
                cout << "*";
            }
            // printing spaces
            for(int k = 1; k <= 2*(n - i); k++) {
                cout << ' ';
            }
            // printing numbers
            for(int j = 1; j <= i; j++) {
                cout << "*";
            }
        } else {
            // priting numbers
            for(int j = 1; j <= 2*n - i; j++) {
                cout << "*";
            }
            // printing spaces
            for(int k = 1; k <= 2*(i - n); k++) {
                cout << ' ';
            }
            // priting numbers
            for(int j = 1; j <= 2*n - i; j++) {
                cout << "*";
            }
        }
        cout << endl;
    }
}

void print21(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1 || i == n || j == 1 || j == n) cout << '*';
            else cout << ' ';
        }
        cout << endl;
    }
}

void print22(int n) {
    // PATTERN 22 IS REMAINING
    for(int i = 1; i <= 2*n - 1; i++) {
        // outer loop runs 2*n - 1 times
        int mainNum = n - i + 1; 
        // in each line we are basically printing till our mainNum
        int auxNum = n; // this is our number which will try to reach to mainNum
        // if it reaches then simply repeatedly print auxNum/mainNum since they are equal or else do auxNum-- in each iteration to reach till mainNum
        int timesToPrintauxNum = 2*n - 1 - 2*(i - 1);
        int count = 1;
        for(int j = 1; j <= 2*n - 1; j++) {
            // also there 2*n - 1 columns
            cout << auxNum << ' ';
            if(auxNum == mainNum) {
                if(count <= timesToPrintauxNum) {
                    count++;
                    continue;
                }
            }
            else if(count <= timesToPrintauxNum) auxNum--;
            else if(count > timesToPrintauxNum) auxNum++;
        }
        cout << endl;
    }
}

int main() {
    // you can also pass test cases by taking input of number of test cases and then running the for loop that many time and inside the for loop, take input of n and call the function to print
    int n = 5;
    print22(n);
    return 0;
}