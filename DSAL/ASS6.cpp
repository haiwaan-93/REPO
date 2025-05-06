// Represent a given graph using adjacency matrix/list to perform DFS and using adjacency list to 
// perform BFS. Use the map of the area around the college as the graph. 
// Identify the prominent land marks as nodes and perform DFS and BFS on that.
// Functions to be implemented:
// 1. Read graph-----------------done
// 2. Display adjacency list-----done
// 3. DFS
// 4. BFS
// 5. indegree & outdegree-------done
// 6. isConnected

#include<bits/stdc++.h>
// #include<string.h>
using namespace std; 


class node{
    string name;
    node* next;
    node* down;
    public:
        node(string n = " "){
            name = n;
            next = down = nullptr;
        }
    friend class graph;
};

class graph{
    public:
    node* head = nullptr;
    graph(){
        head = nullptr;
    }
    void add(string src, string dest){
        node *temp;
        node *curr = head, *prev = nullptr;
        if(curr == nullptr){
            curr = new node(src);
            prev = new node(dest);
            curr->next = prev;
            curr->down = nullptr; 
            head = curr;
        }
        else{
            while(curr!=nullptr&& curr->name != src ){
                prev = curr;
                curr = curr->down;
            }
            if (curr == nullptr){
                temp = new node(dest);
                curr = new node(src);
                curr->next = temp; 
                prev->down = curr;
            }
            else if(curr->name == src){
                temp = new node(dest);
                while(curr->next!=nullptr){
                    curr = curr->next;
                } 
                curr->next = temp;
                
            }
        }
        curr = head, prev = nullptr;
        temp = nullptr; 
        while(curr!=nullptr&&curr->name != dest  ){
            prev = curr;
            curr = curr->down;
        }
        if (curr == nullptr){
            temp = new node(dest); 
            prev->down = temp;
        }
    }
    int outDegree(string node1){
        node* curr = head, *prev = nullptr , *temp = nullptr;
        if(curr==nullptr){
            curr = new node(node1);
            head = curr;
            return 0;
        }
        else{
            while(curr!=nullptr){
                if(curr->name == node1){
                    int ctr = 0; 
                    temp=curr;
                    while(temp->next != nullptr){
                        ctr++;
                        temp=temp->next;
                    }
                    return ctr;
                }
                prev = curr;
                curr = curr->down;
            }
        }
    }
    int inDegree(string node1){
        node* curr = head;
        int ctr = 0;
        while(curr!=nullptr){
            if(curr->name!=node1){
            node *crrr = curr;
            while(crrr!=nullptr){
                if(crrr->name == node1){
                    ctr += 1;
                    cout<<curr->name<<" "<<crrr->name<<endl;
                }
                crrr = crrr->next;
            }
        }
            curr = curr -> down;
        } 
        return ctr;
    }
    void display(){
        node* curr = head;
        while(curr != nullptr){
            cout << curr->name << " -> ";
            node* temp = curr->next;
            while(temp != nullptr){
                cout << temp->name << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
            curr = curr->down;
        }
    }
    node* return_node(string n){
        node* curr = head;
        while(curr!=nullptr){
            if(curr->name == n){
                return curr;
            }
            curr = curr->down;
        }
        return nullptr;
    }
    bool search1(string n, vector<node*> n1){
        for(int i = 0; i < n1.size ; i++){
            if(n1[i]==1){
                return true;
            }
        }
        return false;
    }  
    }
    void dfs(string node1){
        node* curr = head, *temp = nullptr;
        if(curr!= nullptr){
            while(curr->down!=nullptr){
            if(curr->name == node1){
                break;
            }
            curr= curr->down;
        }
        int n = 0;
        temp = head;
        while(temp!=nullptr){
            n++;
            temp = temp->down;
        }
        temp = nullptr;
        stack<node*> nodeptrs;
        vector<node*> visited;
        nodeptrs.push(curr);
        visited.push_back(curr);
        temp = curr;
        while(!nodeptrs.empty()){
            temp = temp->next;
            
            if(temp!=nullptr && !search1(temp->name, visited)){
            nodeptrs.push(temp);
            visited.push_back(temp);
            }
        }


    }
    }

    void bfs(){

    }

};


int main(){
    graph g;
    g.add("A1111","D1111");
    g.add("A1111","E1111");
    g.add("A1111","C1111");
    g.add("E1111","C1111");
    g.add("C1111","B1111");
    g.add("C1111","F1111");
    g.add("B1111","F1111");
    g.add("F1111","G1111");
    g.add("G1111","C1111");
    // string a = "C1111";
    g.display();
    cout<<g.inDegree("C1111");
}