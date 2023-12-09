#define TEST
#include "pq.cpp"
bool testInsert(AbstractPriorityQueue *pq, vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        pq->insert(v[i]);
    }
    return pq->getSize() == v.size();
}
bool testRemoveMin(AbstractPriorityQueue *pq, vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        if(pq->removeMin() != v[i]){
            return false;
        }
    }
    return true;
}

int main(){

    vector<int> v = {1, 2, 3, 4, 5};
    AbstractPriorityQueue *pq = new UnsortedPriorityQueue();
    int score = testInsert(pq, v);
    cout<<"Test Insert Unsorted: "<<score<<endl;
    score += testRemoveMin(pq, v);
    cout<<"Test RemoveMin Unsorted: "<<score<<endl;
    
    AbstractPriorityQueue *pq2 = new SortedPriorityQueue();
    score += testInsert(pq2, v);
    cout<<"Test Insert Sorted: "<<score<<endl;
    score += testRemoveMin(pq2, v);
    cout<<"Test RemoveMin Sorted: "<<score<<endl;

    AbstractPriorityQueue *pq3 = new PriorityQueueHeap();
    score += testInsert(pq3, v);
    cout<<"Test Insert Heap: "<<score<<endl;
    score += testRemoveMin(pq3, v);
    cout<<"Test RemoveMin Heap: "<<score<<endl;

    cout<<"Score : " << score << "/6"<< endl;
    return 0;

}



