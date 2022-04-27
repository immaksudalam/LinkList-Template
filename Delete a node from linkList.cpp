#include<bits/stdc++.h>
using namespace std;
struct node{
	int val;
	node *next;
	node(int data){
		val = data;
		next = NULL;
	}
};

void insertAtTail(node* &head, int val){
	node *n = new node(val);
	if(head == NULL){
		head = n;
		return;
	}
	node *temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = n;
}
void insertAtHead(node* &head, int val){
	node *n = new node(val);
	n->next = head;
	head = n;
}
void insertAfterValue(node* &head, int target, int val){
	node *temp = head;
	node *n = new node(val);
	while(temp->val != target){
		temp = temp->next;
	}
	node *t = temp->next;
	temp->next = n;
	n->next = t;
}
bool search(node* head, int key){
	node *temp = head;
	while(temp != NULL){
		if(temp->val == key){
			return true;
		}
		temp = temp->next;
	}
	return false;
}
////////////////////////////////////////////////////////////////////////////////
void deletion(node* &head, int key){
	node* temp = head;
	if(head->val == key){
		head = head->next;
		return;
	}
	while(temp->next->val != key){
		temp = temp->next;
	}
	node *d = temp->next;
	temp->next = temp->next->next;
	delete d;
}
///////////////////////////////////////////////////////////////////////////////////
int main()
{
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	node *head = NULL;
	for(int i=0; i<n; i++){
		insertAtTail(head, v[i]);
	}
	insertAtTail(head, 6);
	insertAtHead(head, 10);
	insertAfterValue(head, 4, 20);
	cout<<search(head, 2)<<endl;
	deletion(head, 10);
	while(head){
		if(head->next)cout<<head->val<<"-> ";
		else cout<<head->val;
		head = head->next;
	}
}
