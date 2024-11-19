#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node * createNode(int val){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = val;
	newNode->next = NULL;
	return newNode;
}

struct node* insertatlast(struct node* head, int val){
     struct node* newNode = createNode(val);
     struct node* ptr = head;

     if(head == NULL){
       head = newNode;
       return head;
       }
     while(ptr->next != NULL){
      ptr = ptr->next;
     }
     ptr->next = newNode;

     return head;
}

void printList(struct node * head){
	struct node* ptr = head;
	while(ptr->next != NULL){
		printf(" %d --> ", ptr->data);
		ptr = ptr->next;
	}
	printf("%d" , ptr->data);

}

struct node* insertBetween(struct node* result, struct node*head){
	  struct node *newNode =head;
	  struct node *ptr = result;
	  if( result == NULL){
	     result = newNode;
	     newNode->next = NULL;
	     return result;
	  }
	  if(ptr->data > newNode->data){
	     newNode->next =ptr;
	     result = newNode;
	     return result;
	  }
	  while(ptr->next->data <= newNode->data && ptr->next !=NULL){
	       ptr = ptr->next;
	  }
	  if(ptr->next == NULL){
	    ptr->next = newNode;
	    newNode->next = NULL;
	    return result;
	  }
	  newNode->next = ptr->next;
	  ptr->next = newNode;

	  return result;
}
struct node* selectionSort(struct node*head){
	struct node* NewList =NULL;
	struct node*ptr = head;

	while( head != 	NULL){
		ptr = head->next;
		NewList = insertBetween(NewList , head);
		head = ptr;
	     }
	return NewList;
}

int main(){
	int i;
	int flag = 1;
	int opt;
	int val;
	struct node * head =NULL;


	while(flag){
		printf("\n Menu :- \n");
		printf("1- print list\n");
		printf("2- insert node\n");
		printf("3- sort link list\n");
		printf("6- exit\n");
		printf("Please choose a option : ");
		scanf("%d" , &opt);

		switch(opt){
			case 1: printList(head);
				break;
			case 2: printf("Please enter data to insert : ");
				scanf("%d" , &val);
				head =insertatlast(head , val);
				break;
			case 3: head = selectionSort(head);
				break;
		      case 6: printf("exiting.....");
				flag = 0;
				break;
		      default: printf("please enter valid choice");
		}

	}
 getch();
 clrscr();
 return 0;
}