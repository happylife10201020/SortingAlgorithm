/* 알고리즘
 * 지도교수 : 강윤석
 *
 * 소프트웨어학부 2022041069 이인수
 * generated in 09.19.25 in cLion
 * */


#include <iostream>
#include <fstream>
#include <vector>
using namespace std ;

#define DEBUG 0
#define MERGE_INSERTION_NUM 15

class SortArray {
public:
    void InsertionSort(std::vector<int> &arr);

    void MergeSort(std::vector<int> &arr, int left, int right);

    void Merge_InsertionSort(std::vector<int> &arr, int left, int right);
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
            } else {
                cout << "ERROR : not enough elements" << endl;
                exit(0);
            }
        }
        if (DEBUG) {
            cout << "DEBUG : input file :" << endl ;
            for (int i = 0; i < arr.size(); i++) {
                cout << arr[i] << " " ;
            }
            cout << endl << endl ;
        }
    } else {
        cout << "Unable to open file" << endl;
        cout << "please check your input file" << endl;
        exit(0);
    }
    file.close();
    return arr;
}

void writeData(const vector<int> &arr) {
    static int num = 0 ;
    static ofstream file("output.txt");
    if (file.is_open()) {
        file << arr[0] ;
        for (int i = 1; i < arr.size(); i++) {
            file << " " << arr[i] ;
        }
    }else {
        cout << "Unable to open file" << endl;
    }

    if (num < 2) {
        file << endl ;
    }else {
        file.close() ;
    }
    num++ ;
}

int main() {
    SortArray sorter;

    vector<int> Array = readData("input.txt");

    vector<int> ArrayforInsertion, ArrayforMerge, ArrayforMerge_Insertion;

    ArrayforInsertion = Array;
    ArrayforMerge = Array;
    ArrayforMerge_Insertion = Array;


    sorter.InsertionSort(ArrayforInsertion);
    if (DEBUG) {
        cout << "DEBUG: Insertion Sort >> " << endl  ;
        for (int i = 0; i < ArrayforInsertion.size(); i++) {
            cout << ArrayforInsertion[i] << " ";
        }
        cout << endl;
    }
    writeData(ArrayforInsertion);

    sorter.MergeSort(ArrayforMerge, 0, ArrayforMerge.size() - 1);
    if (DEBUG) {
        cout << endl << "DEBUG: Merge Sort >> " << endl;

        for (int i = 0; i < ArrayforMerge.size(); i++) {
            cout << ArrayforMerge[i] << " ";
        }
        cout << endl;
    }
    writeData(ArrayforMerge);

    sorter.Merge_InsertionSort(ArrayforMerge_Insertion, 0, ArrayforMerge_Insertion.size() - 1);
    if (DEBUG) {
        cout << endl << "DEBUG: Merge_Insertion Sort >> " << endl ;
        for (int i = 0; i < ArrayforMerge_Insertion.size(); i++) {
            cout << ArrayforMerge_Insertion[i] << " ";
        }
    }
    writeData(ArrayforMerge_Insertion);
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
    if (left >= right) return;

    int mid = (left + right) / 2 + 1;
    MergeSort(arr, left, mid - 1);
    MergeSort(arr, mid , right);

    vector<int> temp;
    int leftNum = 0, rightNum = 0;
    temp = arr;

    leftNum = 0;
    rightNum = 0;
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
        cout << "DEBUG >> left : " << left << " right : " << right << " " << "mid : " << mid << endl;
        for (int i = left; i <= right; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void SortArray::Merge_InsertionSort(vector<int> &arr, int left, int right) {
    if (right - left <= MERGE_INSERTION_NUM) {
        int key;
        for (int i = left; i <= right; i++) {
            key = arr[i];
            for (int j = i - 1; j >= left; j--) {
                if (arr[j] > key) {
                    arr[j + 1] = arr[j];
                    if (j == left) {
                        arr[left] = key;
                    }
                } else {
                    arr[j + 1] = key;
                    break;
                }
            }
        }
        if (DEBUG) {
            cout << "DEBUG >> ";
            for (int i = left; i <= right; i++) {
                cout << "left : " << left << " right : " << right << " : " << arr[i] << endl;
            }
        }

        return;
    };

    int mid = (left + right) / 2 + 1;
    Merge_InsertionSort(arr, left, mid - 1);
    Merge_InsertionSort(arr, mid, right);

    vector<int> temp;
    int leftNum = 0, rightNum = 0;
    temp = arr;

    leftNum = 0;
    rightNum = 0;
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
        cout << "DEBUG >> left : " << left << " right : " << right << " " << "mid : " << mid << endl;
        for (int i = left; i <= right; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
