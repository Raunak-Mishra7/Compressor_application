#include <iostream>      // Input/output (cout, cin)
#include <fstream>       // File handling (opening, reading, writing)
#include <string>        // String operations
#include <vector>        // Dynamic arrays for triples
#include <algorithm>     // max(), min() functions
#include <iomanip>       // For formatting output
#include <climits>       // INT_MAX, etc.
using namespace std;
const int WINDOW_SIZE = 4096;      // 4KB sliding window
const int LOOKAHEAD_SIZE = 256;    // 256-byte lookahead
const int OFFSET_BITS = 12;        // 12 bits for offset (4096 positions)
const int LENGTH_BITS = 8;         // 8 bits for length (256 max)
bool even(int n){
    if(n%2==0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    
int n;
cout<<"Enter a number:"<<endl;
cin>>n;
even(n);



    return 0;
}