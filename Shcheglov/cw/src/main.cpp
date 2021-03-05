#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <fstream>
#include <cstring>
#include <cmath>
#include <limits>
#include <cstring>


using namespace std;

class WeakHeap {

public:
    vector <int> wheap;
    int size_of_heap = 0;
    int* bit_array = NULL;
    int size_array;
    WeakHeap* InputHeap();
    void DisplayArray();
    void DisplayHeap();
    void WeakHeapMerge(int* bit_array, int i, int j);
    void WeakHeapSort();

    ~WeakHeap() {
        if (!wheap.empty())
            wheap.clear();
    }

};

double logarifm(int a, int b) //���������� ��������� b �� ��������� a
{
    return log(b) / log(a);
}

void WeakHeap::DisplayHeap() {

    vector <int> result_heap;
    result_heap.push_back(wheap[0]);
    result_heap.push_back(wheap[1]);
    for (int i = 0; i < size_array; i++) {//���������� �������� � ���� � �������, ������� ��� ������ �� �����
        result_heap.push_back(wheap[2 * i + bit_array[i]]);
        result_heap.push_back(wheap[2 * i + 1 - bit_array[i]]);

    }
    cout << wheap[0];
    cout << "\n";

    int depth = (int)logarifm(2, size_of_heap); //��������� ������� ������
    if (depth == 3)
        depth++;
    int k = 0;
    double idt = depth * 2;
    for (int i = 0; i < depth; i++) {

        for(int iter = 0; iter < idt; iter++)
            cout <<" ";
        idt = idt / 2;

        for (int j = 0; j < pow(2, i); j++) {
            cout << wheap[k+1]<< "  ";
            for (int it = 0; it < idt * 4 - 1; it++)
                cout << " ";
            k++;
        }
        cout << "\n";
    }

    for (int i = 0; i < 100; i++)
        cout << "_";
    cout << "\n";
}

void WeakHeap::WeakHeapMerge(int* bit_array, int i, int j) {


    if (wheap[i] < wheap[j]) { //��� ������� ��������������, ������� ��� ��������, ��� �����, � ��� ������
        bit_array[j>>3] ^= 1 << ((j) & 7);
        this->DisplayHeap();
        cout << "������������� " << wheap[i] << " ������ ������� " << wheap[j] << ", ������ �� �������\n";
        swap(wheap[i], wheap[j]);//������ �������� "�������������" � �������
        this->DisplayHeap();

    }
    else {
        this->DisplayHeap();
        for (int i = 0; i < 100; i++)
            cout << "_";
        cout << "\n";
    }
}

void WeakHeap::WeakHeapSort() {
    int n = size_of_heap;
    int lef;
    int per;
    if (n > 1){
    int i;
    int j;
    int x;
    int y;
    int GreatParent;
    size_array = (n + 7) / 8;
    bit_array = new int[size_array]; // ������ ��� ����������� ������ � ������� �������� ��������
    for (i = 0; i < n / 8; ++i)
            bit_array[i] = 0;
    cout << "���������� �������������� ������ ����\n";
            for (i = n - 1; i > 0; --i) { //���������� �������������� ������ ����
            j = i;
            //����������� �� ������� �������� �����,
            lef = (bit_array[(j >> 1) >> 3] >> ((j >> 1) & 7)) & 1;  //���� � �������� ������ ������� ��������
            while ((j & 1) == lef) {
                j = j >> 1;
                lef = (bit_array[(j >> 1) >> 3] >> ((j >> 1) & 7)) & 1;
            }
            GreatParent = j >> 1;//� ��� �� ���� ������� ����� ��� ������ ������� ��������
            WeakHeapMerge(bit_array, GreatParent, i); //������� ���������� ��������, � �������� ������ ����������� �� �������������
        }
        cout << "������ ���� ���������!!!\n"; //��������� �������� �� ����� � �����, ����� ������ ��������
        this->DisplayHeap();

        for (i = n - 1; i >= 2; --i) {
            cout << "��������� �������� �� �����, �������� ������ ��������\n";
            this->DisplayHeap();
            cout << "����������� ������ " << wheap[0] << " � ������� �� ����� ����������������� ����� " << wheap[i] << "\n";
            swap(wheap[0], wheap[i]);
            this->DisplayHeap();
            x = 1;
            lef = (bit_array[(j >> 1) >> 3] >> ((j >> 1) & 7)) & 1; //���������� ����� ���� �� ����� ������
            while ((y = 2 * x + lef) < i) {
                x = y;
                lef = (bit_array[(j >> 1) >> 3] >> ((j >> 1) & 7)) & 1;
            }

            while (x > 0) {   //����������� ������� ����� ������� �� ������ ������
                WeakHeapMerge(bit_array, 0, x);
                x >>= 1;
            }
        }
        this->DisplayHeap();
        cout << "������ ������� ������ " << wheap[0] << " � ��������� �� ��� ������� " << wheap[1] << "\n";
        swap(wheap[0], wheap[1]);
        this->DisplayHeap();
        delete[] bit_array;
    }
}
void WeakHeap::DisplayArray()
{
    for (int i = 0; i < size_of_heap; i++)
        cout << wheap[i] << " ";
    cout << "\n\n\n";
}

WeakHeap* WeakHeap::InputHeap() {
    int count;
    cin >> count;
    int elem;
    WeakHeap* wh = new WeakHeap();
    cout << "����� ������ ������� �������� �������:\n";
    while (wh->size_of_heap != count) {
        cin >> elem;
        wh->wheap.push_back(elem);
        wh->size_of_heap++;
    }
    return wh;
}

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "��������� ��� ������������ ���������� ������ �����.\n\n";
    cout << "�� ������� ������ ���������, ����� �������, ��� ���������� ���������� ������ �����.\n\n";
    WeakHeap* wh = NULL;
    cout << "������� ���������� ��������� �������:\n";
     wh = wh->InputHeap(); //������ �������� � ����
     wh->WeakHeapSort();
     cout << "\n� ���������� ���������� ������ ������ ���:\n";
     cout << "�������� ������: ";
     wh->DisplayArray();
     delete wh;
     return 0;
}
