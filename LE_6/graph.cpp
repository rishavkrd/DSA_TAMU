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
            n = size;
            l = new list<pair<int,int>>[n];

        }
        void addEdge(int x, int y, int w){
            l[x].push_back({y,w});
            l[y].push_back({x,w});
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
            int *dist = new int[n];
            for(int i = 0; i < n; i++){
                dist[i] = INT_MAX;
            }
            dist[0] = 0;
            PriorityQueue <pair<int,int>> pq;
            pq.pq_insert({0,0});

            while(!pq.isPqEmpty()){
                int currentNode = pq.pq_top().second;
                int currentDist = pq.pq_top().first;
                pq.pq_delete();
                for(pair<int,int> i : l[currentNode]){
                    if(currentDist + i.second < dist[i.first]){
                        dist[i.first] = currentDist + i.second;
                        pq.pq_insert({dist[i.first], i.first});
                    }
                }
            }
            return dist;
        }
};



void testDijkstra(){
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
    for(int i=0; i<5; i++){
        cout << arr[i] << ", ";
    }
    cout<<endl;
}

int main(){
    testDijkstra();
    return 0;
}