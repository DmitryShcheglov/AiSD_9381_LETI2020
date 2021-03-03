#include<iostream>
#include<fstream>
#include<list>
#include<algorithm>
#include<stdlib.h>
#include<locale>

using namespace std;

template <typename T>
void print_list(list<T> started_list) // ������� ��� ������ ���� ��������� ������
{
    cout << "{ ";
    for (auto start_pos = started_list.begin(); start_pos != started_list.end(); start_pos++)
        cout << *start_pos << ", ";
    cout << '}';
}

template <typename T>
list<T> strandSort(list<T> lst) // ���������� ����������
{  
    
    cout << "������ ����������\n";
    
    list<T> result_list;    // ��������������� ������ 
    list<T> sorted_list;       // ������������� ���������

    while (!lst.empty())
    {
        { // ���������� ����������
            cout << "����� ��������:\n ����������� ������ = ";
            print_list(lst);
            cout << "\n �������� \'" << *(lst.begin()) << "\' � ������������� ���������\n";
        }

        sorted_list.push_back(lst.front()); // ���������� ������ ������� �� ���������� ������
        lst.pop_front();                   // ������� ������ ������� �� ���������� ������

        {  // ���������� ����������
            cout << " ������������� ��������� = ";
            print_list(sorted_list);
            cout << "\n";
        }

        for (typename list<T>::iterator iter = lst.begin(); iter != lst.end(); )
        {
            if (sorted_list.back() <= *iter)  // ���� ��������� ����������� ������� ������ ��� 
            {                              // ����� �������� �� ������� ��������� ��������
                { // �������
                    cout << " \'" << *iter << "\' >= \'" << sorted_list.back() << "\' ������� ����������" << " '"<<*iter <<"' " << "� ������������� ���������" << endl;
                }
                sorted_list.push_back(*iter); // ��������� ���� ������� � �����
                iter = lst.erase(iter);        // � ������� ��� �� ���������� �������

                {  // �������
                    cout << " ������������� ��������� = ";
                    print_list(sorted_list);
                    cout << "\n" ;
                }
            }
            else
                iter++;                 // �� �������� ��������� ��������
        }
        result_list.merge(sorted_list); // ���������� ��� ��������������� ������ � ����
        //�������
        { 
            cout << "����� ��������\n\n ��������� ������:\n �������� ������ ";
            print_list(result_list);
            cout << "\n\n";
        }
    }
    cout << "����� ����������\n" << endl;
    return result_list;
}

int main()
{
    setlocale(LC_ALL, "rus");
    list<int> start_list;
    int elem = 0;
    int count_of_elem = 0;
    bool flag = true;

    cout << "������� ���������� ��������� ������:" << endl;
    while (flag == true) { //��������� ���������� ��������� ������
        cin >> count_of_elem;
        if (count_of_elem > 30 || count_of_elem < 1 )
        {
            cout << "������� ���������� ���������� ��������� ������!" << endl;
            continue;
        }
        flag = false;
    }
        
    for (int i = 0; i < count_of_elem; i++) // ��������� �������� ������
    {
        if (i == 0)
            cout << "����� ������ ������� ��� �������� ������:\n";
        cin >> elem;    // ��������� �����
        start_list.push_back(elem);
    }

    cout <<"\n";
    list<int> strand_sorted_list = strandSort(start_list);
    cout << "������ �� ����������:\n";
    print_list(start_list);
    cout << "\n\n";
    cout << "C����� ����� ����������:\n";
    print_list(strand_sorted_list);
    return 0;
}