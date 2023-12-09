#define TEST
#include <iostream>
#include "graph.cpp"
using namespace std;

int testDijkstra(){
    Graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(1,2,5);
    g.addEdge(2,3,7);
    g.addEdge(3,4,3);
    g.addEdge(1,4,2);
    g.addEdge(0,3,5);
    int* arr = g.dijkstra();
    g.print();
    cout<< "Dijkshtra"<<endl;
    vector<int> v = {0, 1, 6, 5, 3};
    for(int i=0; i<5; i++){
        cout << arr[i] << ", ";
        if(arr[i] != v[i]){
            cout << "Failed" << endl;
            return 0;
        }
    }
    cout<<endl;
    return 1;
}

int main(){
    int out = testDijkstra();
    cout<<"Dijkstra passing: "<<out;
    return 0;
}