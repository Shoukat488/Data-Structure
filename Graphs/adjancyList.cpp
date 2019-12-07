#include<iostream>
#include<vector>

using namespace std;
void addEdge(vector<int> adj[] , int u , int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void printList(vector<int> adj[] , int size)
{
    for(int i = 1 ; i < size ; i ++)
    {
        cout<<"Edges at vertex "<<i<<endl;
        cout<<i;
        while(!adj[i].empty())
        {
            cout<<" -> ";
            cout<<adj[i].back();
            adj[i].pop_back();
        }
        cout<<endl;
    }
}

int main()
{
    vector<int> list[11];
    addEdge(list , 1 , 2);
    addEdge(list , 1 , 4);
    addEdge(list , 4 , 3);
    addEdge(list , 3 , 2);
    addEdge(list , 3 , 9);
    addEdge(list , 3 , 10);
    addEdge(list , 2 , 7);
    addEdge(list , 2 , 8);
    addEdge(list , 2 , 5);
    addEdge(list , 5 , 6);

    printList(list , 11);
}