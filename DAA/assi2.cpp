//BFS and DFS
#include <iostream>
#include <string>
using namespace std;

class Node{
public:
int id;
string name;
Node* next;
friend class Graph;
};

class Graph{
public:

void create_adj_list();
void display();
Node* head[10];
void DFS();
void DFSrec(int v);
int n;
int visited[10];
};


void Graph :: create_adj_list(){
char ch;
cout<<"Enter number of vertices: ";
cin>>n;
Node* curr;
for(int i=0; i<n; i++){
head[i]=new Node();
cout<<"Enter name: ";
cin>> head[i]->name;
head[i]->id=i;
head[i]->next=NULL;
}
for(int i=0; i<n; i++){
Node* temp=head[i];
while(1){
cout<<"\nIs a vertex connected to "<<head[i]->id<<" (y/n):";
cin>>ch;
if(ch=='y'){
curr=new Node();
cout<<"Enter connected vertex id: ";
cin>>curr->id;
curr->name=head[curr->id]->name;
curr->next=NULL;
temp->next=curr;
temp=curr;
}
else{
break;
}
}
}
}

void Graph::DFS(){
for(int i=0; i<n;i++){
visited[i] = 0;

}
for(int i=0; i<n;i++){
if (visited[i]==0)
DFSrec(i);
}  
}

void Graph:: DFSrec(int v){
cout<< v<<" ";
visited[v] = 1;
cout<< head[v]->name<<" ";
Node*temp = head[v]->next;
while(temp !=nullptr){
if (visited[temp->id] ==0){
DFSrec(temp->id);
}
temp=temp->next;
}
}


void Graph :: display(){
for(int i=0; i<n; i++){
Node* temp=head[i]->next;
cout<<"User connections of user "<<head[i]->id<<" are"<<endl;
if(temp != NULL){
while(temp != NULL){
cout<<"User id: "<<temp->id<<endl<<"User name: "<<temp->name<<endl;
temp=temp->next;
}
}
else{
cout<<"User has no connections."<<endl;
}
}
}

int main(){
Graph g1;
cout<<"Creation of graph\n";
g1.create_adj_list();
cout<<endl;
cout<<"Display of graph\n";
g1.display();
cout<<endl;
cout<<"Finding user:";
g1.DFS();
return(0);
}
