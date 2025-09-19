#include <iostream>
#include <fstream>
#include <vector>
using namespace std ;

int main() {
    ifstream inputFile("input.txt") ;

    int length ; vector<int> arr ;

    if (inputFile.is_open()) {
        inputFile >> length ;
        for (int i = 0; i < length; i++) {
            int data ;
            if (inputFile >> data) {
                arr.push_back(data) ; cout << arr[i] << " " ;
            } else {
                cout << "ERROR : not enough elements" << endl ;
                exit(0) ;
            }
        }
    }else {
        cout << "Unable to open file" << endl ;
        cout << "please check your input.txt" << endl ;
        exit(0) ;
    }


}