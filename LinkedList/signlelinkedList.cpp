#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node * next;

	Node(){
		data=0;
		next=NULL;
	}

	Node(int data){
		this->data=data;
		this->next=NULL;
	}
};

class LinkedList{
	Node *head;
public:
	LinkedList(){head=NULL;}

	void insertNode(int);

	void printNode();

	void deleteNode(int);
};

void LinkedList::deleteNode(int el){
	Node *temp1=head,*temp2=head;

	while(temp1!=NULL){
		if(temp1->data==el) {
			break;
		}
		temp2=temp1;
		temp1=temp1->next;
	}
	if(temp1==NULL){ cout<<"NO data found.."<<endl;  return;}

        //handle if first element is deleted element
	if(temp1==temp2){

          head=temp1->next;
         delete(temp1);
         return;
	}

	temp2->next=temp1->next;
	delete(temp1);

}


void LinkedList:: printNode(){
	Node * temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

void LinkedList:: insertNode(int el){

	Node *newNode=new Node(el);

	if(head==NULL){
		head=newNode;
		return;
	}

	Node * temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}

	temp->next=newNode;
}

int main() 
{ 
    LinkedList list; 
  
    // Inserting nodes 
    list.insertNode(1); 
    list.insertNode(2); 
    list.insertNode(3); 
    list.insertNode(4); 
  
    cout << "Elements of the list are: "; 
  
    // Print the list 
    list.printNode(); 
    cout << endl; 
  
    // // Delete node at position 2. 
    list.deleteNode(7); 
  
    cout << "Elements of the list are: "; 
    list.printNode(); 
    // cout << endl; 
    return 0; 
}