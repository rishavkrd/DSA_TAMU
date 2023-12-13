#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include "priority_queue.cpp"
using namespace std;

class Graph{
    private:
        int n;
        list<pair<int,int>> *l;
    public:
        Graph(int size = 2){

        }
        void addEdge(int x, int y, int w){
        }
        void print(){
            for(int i = 0; i < n; i++){
                cout << "Node " << i << " is connected to: ";
                for(pair<int,int> j : l[i]){
                    if(j.first != -1){
                        cout << j.first << " : "<< j.second<<", ";
                    }
                }
                cout << endl;
            }
        }

        int* dijkstra(){
            int *distances = new int[n];
            
            return distances;
        }
};


#ifndef TEST
int main(){
    return 0;
}
#endif