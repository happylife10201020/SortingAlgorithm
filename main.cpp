#include <iostream>
#include <fstream>
#include <vector>
using namespace std ;

#define DEBUG 1

class SortArray {
public:
    void InsertionSort(std::vector<int> &arr);

    void MergeSort(std::vector<int> &arr, int left, int right);

    void Merge_InsertionSort(std::vector<int> &arr);
};


vector<int> readData(const string &filename) {
    vector<int> arr;
    ifstream file(filename);
    if (file.is_open()) {
        int length;
        file >> length;
        for (int i = 0; i < length; i++) {
            int data;
            if (file >> data) {
                arr.push_back(data);
                if (DEBUG)
                    cout << arr[i] << " ";
            } else {
                cout << "ERROR : not enough elements" << endl;
                exit(0);
            }
        }
    } else {
        cout << "Unable to open file" << endl;
        cout << "please check your input file" << endl;
        exit(0);
    }

    return arr;
}

int main() {
    SortArray sorter;

    vector<int> Array = readData("input.txt");

    vector<int> ArrayforInsertion, ArrayforMerge, ArrayforMerge_Insertion;

    ArrayforInsertion = Array;
    ArrayforMerge = Array;
    ArrayforMerge_Insertion = Array;


    sorter.InsertionSort(ArrayforInsertion);
    if (DEBUG)
        cout << endl;
    for (int i = 0; i < ArrayforInsertion.size(); i++) {
        cout << ArrayforInsertion[i] << " ";
    }
    cout << endl;

    if (DEBUG) {
        cout << "DEBUG ArrayforMerge >> ";
        for (int i = 0; i < ArrayforMerge.size(); i++) {
            cout << ArrayforMerge[i] << " ";
        }
        cout << endl;
    }
    sorter.MergeSort(ArrayforMerge, 0, ArrayforMerge_Insertion.size() - 1);
    for (int i = 0; i < ArrayforMerge.size(); i++) {
        cout << ArrayforMerge[i] << " ";
    }
    cout << endl;

    sorter.Merge_InsertionSort(ArrayforMerge_Insertion);
    for (int i = 0; i < ArrayforMerge_Insertion.size(); i++) {
        cout << ArrayforMerge_Insertion[i] << " ";
    }
}


void SortArray::InsertionSort(vector<int> &arr) {
    int key;
    for (int i = 0; i < arr.size(); i++) {
        key = arr[i];
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                if (j == 0) {
                    arr[0] = key;
                }
            } else {
                arr[j + 1] = key;
                break;
            }
        }
    }
}

void SortArray::MergeSort(vector<int> &arr, int left, int right) {
    if (left >= right) return ;

    int mid = (left + right) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);

    vector<int> temp;
    int leftNum = 0, rightNum = 0;
    temp = arr;

    leftNum = 0; rightNum = 0;
    for (int i = left; i <= right; i++) {
        if (temp[left + leftNum] < temp[mid + rightNum] && left + leftNum < mid || mid + rightNum > right) {
            arr[left + leftNum + rightNum] = temp[left + leftNum];
            leftNum++;
        } else {
            arr[left + leftNum + rightNum] = temp[mid + rightNum];
            rightNum++;
        }
    }
    if (DEBUG) {
        cout<< "DEBUG >> left : " << left << " right : " << right << " " << "mid : " << mid << endl ;
        for (int i = left; i <= right; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void SortArray::Merge_InsertionSort(vector<int> &arr) {
    cout << "";
}
