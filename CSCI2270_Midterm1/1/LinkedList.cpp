#include "LinkedList.hpp"

using namespace std;

LinkedList::LinkedList(){
        head = NULL;
    }

LinkedList::~LinkedList(){
	Node* crawler;
	while(head!=nullptr){
		crawler = head->next;
		delete head;
		head = crawler;
	}
}

// Add a new Node to the list
void LinkedList::insert(Node* prev, int newKey){

    //Check if head is Null i.e list is empty
    if(head == NULL){
        head = new Node;
        head->key = newKey;
        head->next = NULL;
    }

        // if list is not empty, look for prev and append our Node there
    else if(prev == NULL)
    {
        Node* newNode = new Node;
        newNode->key = newKey;
        newNode->next = head;
        head = newNode;
    }

    else{

        Node* newNode = new Node;
        newNode->key = newKey;
        newNode->next = prev->next;
        prev->next = newNode;

    }
}



// Building list
void LinkedList::loadList(int* keys , int length) {

    insert(NULL, keys[0]);

    Node* prev = head;

    for(int i = 1; i < length; i++)
    {
        insert(prev, keys[i]);
        prev = prev->next;
    }

}

// Print the keys in your list
void LinkedList::printList(){
    Node* temp = head;

    while(temp->next != NULL){
        cout<< temp->key <<" -> ";
        temp = temp->next;
    }

    cout<<temp->key<<" -> NULL"<<endl;
}

///////////////////////////////////////////////////////////////
// TODO : Complete the following function
void LinkedList::removeNthFromEnd(int n)
{
    Node* fast = head; //moves first to set buffer distance of n
    Node* slow = head; //slow pointer will point to nth node when fast node gets to end
    Node* temp = head; //node to find length and to be deleted
    int count = 1;
    if (head != NULL) //check list exists
    {
        while (temp->next != NULL) //loop to count length of list, specifically for edge case of first node
        {
            temp = temp->next;
            count++;
        }
        if (n == count) //if deleting first node, take this case to delete head
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        else //else take this case
        {    
            for (int i = 0; i < n; i++) //move fast pointer forward n times
            {
                fast = fast->next;
            }
            while (fast->next != NULL) //after fast is n ahead of slow, move both until reaching the end of list
            {
                slow = slow->next;
                fast = fast->next;
            } //when falling out of this loop, slow->next is the node to be deleted
            temp = slow->next; //set node to be deleted
            slow->next = slow->next->next; //set slow next to the node after the node to be deleted
            delete temp;
        }
    }
}

