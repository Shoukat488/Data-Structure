#include<iostream>
using namespace std;

template<class T>
class Heap{

    private:
    T *data;
    int current;
    int size;

    public:
    Heap(int size);
    void insert(T value);
    T Ext_max();
    void upHeap();
    void DownHeap();
};
template<class T>
Heap<T>::Heap(int size)
{
    this->size = size;
    data = new T[size];
    current = -1;
}
template<class T>
void Heap<T>::insert(T value)
{
	if(current == size -1)
	{
		cout<<"Heap is full"<<endl;
		return;
	}
    data[++current] = value;
    upHeap();
}
template<class T>
void Heap<T>::upHeap()
{   
    int tempCurr = current;
    bool flag = false;
    int i = (current-1)/2;
    while(i >= 0 && current > 0 && i != tempCurr)
    {
        if(data[i] < data[tempCurr])
        {
            T temp = data[i];
            data[i] = data[tempCurr];
            data[tempCurr] = temp;
            flag = true;
        }
        if(flag == false)
        break;
        i = (i-1)/2;
        tempCurr = (tempCurr-1)/2;
    }
}
template<class T>
void Heap<T>::DownHeap()
{
    int tempCurr = 0;
    
    int swapElem = 0;
    int swapIndex = 0;
    while (tempCurr < current)
    {
        int left = tempCurr*2 + 1 ;
        int right = tempCurr*2 + 2 ;
        if(left <= current && right <= current)
        {

            if(data[left] > data[right])
            swapIndex = left;
            else
            swapIndex = right;

            if(data[tempCurr] < data[swapIndex])
            {
                T temp = data[tempCurr];
                data[tempCurr] = data[swapIndex];
                data[swapIndex] = temp;
            }
            else
            break;
        }
        else
        break;
        tempCurr = swapIndex;
    }
    
}
template<class T>
T Heap<T>::Ext_max()
{
	if(current == -1)
	{
		cout<<"Heap is empty"<<endl;
		return 0;
	}
    T temp = data[0];
    data[0] = data[current--];
    DownHeap();
    return temp;
}
int main()
{
    Heap<int> *h = new  Heap<int>(10);
    h->insert(4);
    h->insert(1);
    h->insert(10);
    h->insert(45);
    h->insert(32);
    cout<<h->Ext_max()<<endl;
    cout<<h->Ext_max()<<endl;
    cout<<h->Ext_max()<<endl;
    cout<<h->Ext_max()<<endl;
    cout<<h->Ext_max()<<endl;
    cout<<h->Ext_max()<<endl;

}
