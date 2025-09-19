#include <iostream>
#include <fstream>
#include <vector>
using namespace std ;

#define DEBUG 1

class SortArray {
public:
    void InsertionSort(std::vector<int> &arr);

    void MergeSort(std::vector<int> &arr);

    void Merge_InsertionSort(std::vector<int> &arr);
};


vector<int> readData(const string& filename) {
    vector<int> arr;
    ifstream file(filename);
    if (file.is_open()) {
        int length;
        file >> length ;
        for (int i = 0; i < length; i++) {
            int data ;
            if (file >> data) {
                arr.push_back(data) ;
                if (DEBUG)
                    cout << arr[i] << " " ;
            } else {
                cout << "ERROR : not enough elements" << endl ;
                exit(0) ;
            }
        }
    }else {
        cout << "Unable to open file" << endl ;
        cout << "please check your input file" << endl ;
        exit(0) ;
    }

    return arr ;
}

int main() {
    SortArray sorter ;

    vector<int> Array = readData("input.txt") ;

    vector<int> ArrayforInsertion, ArrayforMerge, Array3 ;
    ArrayforInsertion = Array ;
    ArrayforMerge = Array ;
    Array3 = Array ;

    sorter.InsertionSort(ArrayforInsertion) ;
    cout << endl ;
    for (int i = 0; i < ArrayforInsertion.size(); i++) {
        cout << ArrayforInsertion[i] << " " ;
    }
    cout << endl ;
    sorter.MergeSort(ArrayforMerge) ;
    for (int i = 0; i < ArrayforMerge.size(); i++) {
        cout << ArrayforMerge[i] << " " ;
    }
}


void SortArray::InsertionSort(vector<int>& arr){
    int key ;
    for(int i = 0 ; i < arr.size() ; i++){
        key = arr[i] ;
        for(int j = i-1 ; j >= 0 ; j--){
            if(arr[j] > key){
                arr[j+1] = arr[j] ;
                if (j == 0) {
                    arr[0] = key ;
                }
            }else{
                arr[j+1] = key ;
                break;
            }
        }
    }
}

void SortArray::MergeSort(vector<int>& arr) {

}
void SortArray::Merge_InsertionSort(vector<int>& arr) {
    cout << "" ;
}
