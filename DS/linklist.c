#include <stdlib.h>
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
	return head;
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
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = NULL;
	}
	return head;
}

linklistp deletenode(linklistp head, int data)
{
	linklistp temp = head;
	if(temp == NULL)
	{
		return NULL;
	}
	if(temp->data == data)
	{
		head = temp->next;
		free(temp);
		return head;
	}
	linklistp pre = head;
	temp = head->next;
	while(temp != NULL && temp->data != data)
	{
		pre = temp;
		temp = temp->next;
	}
	if(temp == NULL)
	{
		return NULL;
	}
	pre->next = temp->next;
	free(temp);
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
	free(temp);
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
	int data;
	scanf("%d", &data);
	linklistp temp = deletenode(head, data);
	if(temp == NULL)
	{
		printf("no data!");
	}
	else
	{
		output(temp);
	}
	return 0;
}
