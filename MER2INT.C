//Swapping Nodes in a Linked List without Swapping Data(Sorting)
#include<stdio.h>
#include<stdlib.h>

//Structure declaration
struct Node
{
    int data;
    struct Node* next;
};

//Function prototypes
struct Node* SortedMerge(struct Node* a, struct Node* b);
void FrontBackSplit(struct Node* source,struct Node** frontRef, struct Node** backRef);

// sorts the linked list by changing next pointers (not data)
void MergeSort(struct Node** headRef)
{
struct Node* head = *headRef;
struct Node* a;
struct Node* b;


if ((head == NULL) || (head->next == NULL))
{
    return;
}

// Split head into 'a' and 'b' sublists 
FrontBackSplit(head, &a, &b);

//Recursively sort the sublists 
MergeSort(&a);
MergeSort(&b);

//merge two sorted list together
*headRef = SortedMerge(a, b);
}


struct Node* SortedMerge(struct Node* a, struct Node* b)
{
struct Node* result = NULL;


if (a == NULL)
    return(b);
else if (b==NULL)
    return(a);

if (a->data <= b->data)
{
    result = a;
    result->next = SortedMerge(a->next, b);
}
else
{
    result = b;
    result->next = SortedMerge(a, b->next);
}
return(result);
}


// Splits the nodes of the given list into front and back halves
void FrontBackSplit(struct Node* source,struct Node** frontRef, struct Node** backRef)
{
    struct Node* fast;
    struct Node* slow;
    slow = source;
    fast = source->next;

    // Advance 'fast' two nodes, and advance 'slow' one node
    while (fast != NULL)
    {
    fast = fast->next;
    if (fast != NULL)
    {
	slow = slow->next;
	fast = fast->next;
    }
    }

    // 'slow' is before the midpoint in the list, so split it in two at that point. 
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// Function to print nodes in a given linked list 
void printList(struct Node *node)
{
while(node!=NULL)
{
printf("%d ", node->data);
node = node->next;
}
}

//inserting at the beginning
void push(struct Node** head_ref, int new_data)
{
// allocating node 
struct Node* new_node =
	    (struct Node*) malloc(sizeof(struct Node));


new_node->data = new_data;

new_node->next = (*head_ref);

//moving the head to point to the new node 
(*head_ref) = new_node;
}


int main()
{

struct Node* res = NULL;
struct Node* a = NULL;
int count,i,n;
clrscr();



printf("Enter length of the Linked List : \n");
scanf("%d",&count);
if(count==0)
{
	printf("List is empty\n");//Empty condition

}
else{
printf("Enter the members \n");
for(i=0;i<count;i++)
{       scanf("%d",&n);
		push(&a, n);
}
printf("Linked List is:\n");
printList(a);


MergeSort(&a);

printf("\nSorted Linked List is: \n");
printList(a);
}
getch();
return 0;
}