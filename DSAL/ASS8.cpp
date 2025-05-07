// Implement the Heap Sort algorithm demonstrating the Heap / Shell data structure with modularity of programming language.

#include<bits/stdc++.h>
using namespace std;

// class heap{
//     public:
//     int size;
//     vector<int> heap_v;

//     heap(){
//         int size = 0;
//         heap_v.push_back(-1);
//     }

//     void insert(int val){
//     size+=1;
//     int index = size;
//     heap_v.push_back(val);
    
//     while(index>1){
//         cout<<heap_v[index]<<" "<<index<<endl;
//         int parent = index/2;
//         if(heap_v[index]>heap_v[parent]){
//             cout<<"hii"<<endl;
//             swap(heap_v[index], heap_v[parent]);
//         }
//         index = index/2;
//     }
    
//     }
//     void print1(){
//         for(int i=1; i < size-1; i++){
//             cout<<heap_v[i]<<" ";
//         }cout<<endl;
//     }
// };



// int main(){
//     heap a;
//     a.insert(50);
//     a.insert(55);
//     a.insert(53);
//     a.insert(52);
//     a.insert(54);
//     a.insert(70);
//     a.print1();
//     return 0; 
// }


class heap{
    int size = 0 ;
    int heap_[100];
    public:
    heap(){
        size =0;
    }
    void insert(int val){
        size += 1;
        int index = size;
        heap_[index] = val;

        while(index>1){
            int parent = index/2;
            if(heap_[index]>heap_[parent]){
                swap(heap_[index], heap_[parent]);
            }
            else{
                return;
            }
            index = index/2;
        }
    }
    void print(){
        for(int i = 1; i <= size ; i++){
            cout<<heap_[i]<<" ";
        }cout<<endl;
    }
    void delete1(){
        swap(heap_[1], heap_[size]);
        size-=1;
        // this.heap_->heapify();
    //     int i = 1;
    //     while(i<=size){
    //         int left = i*2;
    //         int right = i*2 + 1;
    //         if(left<size && heap_[left]>heap_[i]){
    //             swap(heap_[i], heap_[left]);
    //             i = left;
    //         }
            
    //         else if(right<size && heap_[right]>heap_[i]){
    //             swap(heap_[i], heap_[right]);
    //             i = right;
    //         }
             
    //         else {
    //             return;
    //         }
    // }
    // int ind2 = size;
    // while(ind2>1){
    //     ind3 = ind2;
    //     while(ind2>1){
    //         int parent = ind3/2;
    //         if(heap_[parent]<heap_[ind3]){
    //             swap()
    //         }
    //     }
    // }
}
};
void heapify(int heap_[], int size, int index){

        int largest = index;
        
            int left = largest*2;
            int right = largest*2 +1;
            // cout << largest<<" "<< left <<" "<< right << " " << heap_[largest] <<" "<<heap_[left]<<" "<<heap_[right];
            if(left<=size && heap_[largest]<heap_[left]){
                largest = left;
            }
            if(right<=size && heap_[largest]<heap_[right]){
                largest = right;
            }

            if(largest != index){
                swap(heap_[index], heap_[largest]);
                heapify(heap_, size, largest);
            }

}
int main(){
    // heap a;
    // a.insert(50);
    // a.insert(51);
    // a.insert(49);
    // a.insert(56);
    // a.insert(434);
    // a.insert(45);
    // a.insert(78);
    // a.insert(90);
    // a.insert(41);
    // a.insert(81);
    // a.insert(8);
    // a.print();
    // a.delete1();
    // a.heapify();
    // a.print();
    int arr[] = {-1,50,51,49,56,434,45,78,90,41,81,8};
    for(int i = 5; i >= 1; i--){
        heapify(arr, 11, i);
    }
    for(int i = 1; i <= 11; i++){
        cout<<arr[i]<<" ";
    }
    
}