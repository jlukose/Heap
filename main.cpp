//Heap - Joshua Lukose 11/2020
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <iomanip>
#include <fstream>

using namespace std;

void printheap();
void heapify(int array[], int sizeInp, int root);
void sortHeap(int array[], int sizeInp);
void displayPrint(int array[], int size);
void swapArray(int array[], int size);
void deleteHeap();

int heap[100];
int size;
int counter = 0;
int position;

int main(){
    int type;
    char input[1000];
    char fileName[10];
    cout << "Direct input(1) or file input(2)" << endl;
    cin >> type;
    cin.clear();
    cin.ignore(10000, '\n');    
    
    int i = 0;
    if (type == 1){//direct input
        cout << "Please input numbers sperated by spaces." << endl;
        cin.get(input, 1000);
        cin.clear();
        cin.ignore(10000, '\n');
        cout << input << endl;
    }
    
    if (type == 2){//file input
        cout << endl << "What is the name of the file?" << endl << ">> ";
        cin.get(fileName, 20);
        cin.clear();
        cin.ignore(1000000, '\n');
        streampos size;
        ifstream file(fileName, ios::in | ios::binary | ios::ate);
        if (file.is_open()){
            size = file.tellg();
            file.seekg(0, ios::beg);
            file.read(input, size);
            file.close();
        }
        cout << input;
    }
    
    //parsing
    char my_number [100];
    while (input[i] != '\0'){//If the input has a space then do nothing or "skip" it
        if (input[i] == ' '){
        }
        else{
            int z = 0;
            for (int j = counter; j <= sizeof(input); j++){
                if(input[j] == ' '){
                    counter++;
                    z++;
                    break;
                }
                else{
                    my_number[z] = input[j];
                    counter++;
                    z++;
                }
            }
            if(atoi(my_number) == 0){
            }
            else{
                heap[position] = atoi(my_number);
                position++;
                for (int z = 0; z < sizeof(my_number); z++){
                    my_number[z] = '\0';
                }
            }
        }
        i++;
    }
    sortHeap(heap, position);
    printheap();
    cout << "\n";
    swapArray(heap, position);
    printheap();
    displayPrint(heap, position);
    deleteHeap();
    return 0;
}

void heapify(int array[], int sizeInp, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    //If left child is greater
    if (left < sizeInp && array[left] > array[largest]){
        cout << array[left];
        largest = left;
    }
    //if the right child is the largest
    if (right < sizeInp && array[right] > array[largest]){
        largest = right;
    }
    //if the largest is not the root
    if (largest != i){
        swap(array[i], array[largest]);
        heapify(array, sizeInp, largest);
    }
}

void sortHeap(int array[], int sizeInp){
    //Build heap
    for (int i = sizeInp / 2 - 1; i >= 0; i--){
        heapify(array, sizeInp, i);
    }
    //iterate through heap
    for (int i = sizeInp - 1; i >= 0; i--){
        //move root to end
        swap(array[0], array[i]);
        
        //heapify the reduced heap
        heapify(array, i, 0);
    }
}

void printheap(){
    for (int i = 0; i < position; i++){
        cout << heap[i] << " ";
    }
}

void displayPrint(int array[], int size){//display print
    for(int i = 0; i <= size/2-1; i++){
        if(array[i] != 0){
            cout << "\n" << array[i] << "\n | ";
        }
        if (array[i*2 + 1] != 0){
            cout << "\n " << array[i*2 + 1] << "-";
        }
        if(array[i*2 + 2] != 0){
            cout << " " << array[i*2 + 2] << "\n";
        }
    }
}

void swapArray(int array[], int size){
    for(int i = 0; i <= size/2; i++){
        swap(array[i], array[size-i-1]);
    }
}

void deleteHeap(){//delete
    cout << "\n";
    for (int i = 0; i < position; i++){
        cout << heap[i] << " ";
        heap[i] = '\0';
    }
}
