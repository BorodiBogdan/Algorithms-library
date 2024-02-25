#include <iostream>
#include <fstream>
#define Nmax 1000001
using namespace std;

ifstream fin("heap.in");
ofstream fout("heap.out");

int heap[Nmax];

int n;//numerele adaugate in heap
int l = 0;

void Up_Heap(int pos){
    if(pos == 1)
        return;

    int dad = pos / 2;

    if(heap[dad] < heap[pos]){
        swap(heap[dad], heap[pos]);
        Up_Heap(dad);
    }
}

void Add_Heap(int element){
    heap[++l] = element;
    Up_Heap(l);
}

void Down_Heap(int pos){
    int left_son = pos * 2;
    int right_son = pos * 2 + 1;

    int largest = pos;

    if(left_son <= l && heap[left_son] > heap[largest])
        largest = left_son;

    if(right_son <= l && heap[right_son] > heap[largest])
        largest = right_son;

    if(largest == pos)
        return;

    swap(heap[largest], heap[pos]);

    Down_Heap(largest);
}

void Delete(){
    swap(heap[1], heap[l--]);

    Down_Heap(1);
}
void Top(int Heap[]){
    fout << Heap[1] << "\n";
}
int main(){
    fin >> n;

    int op, nr;

    for(int i = 1; i <= n; ++i){
        fin >> op;

        if(op == 1){
            fin >> nr;
            Add_Heap(nr);
        }
        else if(op == 2){
            Top(heap);
            Delete();
        }
    }
}
