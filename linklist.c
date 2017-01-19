#include<stdio.h>

typedef struct linklist
{
	int data;
	struct linklist *next;
}linknode, *linklistp;

linklistp inserthead(linklistp head, linklistp newnode)
{
	newnode->next = head;
	head = newnode;
}

linklistp inserttail(linklistp head, linklistp newnode)
{
	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		linklistp temp = head;
		while(head->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = NULL;
	}
	return head;
}

void output(linklistp head)
{
	linklistp temp = head;
	while(temp)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	linklistp head = NULL;
	srand(time(NULL));
	int i = 0;
	for(i = 0; i < 10; i++)
	{
		linklistp newnode = (linklistp)malloc(sizeof(linknode));
		newnode->data = rand()%100;
		newnode->next = NULL;
		head = inserttail(head, newnode);
		output(head);
	}
}
