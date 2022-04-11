#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node
{

	char name[20];
	char author[30];
	char ISBN[20];
    char price[20];
}Node;


typedef struct Book
{
	Node data;
	struct Book* next;
}book;

//adding books
book* addBooks()
{
	book*head, *tail, *ptr;
	head=tail=(book*)malloc(sizeof(book));
	head->next = NULL;
	int n = 0;
	printf("Enter the number of books to be entered:");
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		ptr = (book*)malloc(sizeof(book));
		printf("Book Title:");
		scanf("%s",&ptr->data.name);
		printf("Author name:");
		scanf("%s",&ptr->data.author);
		printf("IBSN:");
		scanf("%s",&ptr->data.ISBN);
		printf("price:");
		scanf("%s",&ptr->data.price);
		ptr->next = NULL;
		tail->next = ptr; 
		tail = ptr;
	}
	return head;
}
void Insert(book*h)// inserting a book (insertion at head)
{
	    book *ptr;
		ptr = (book*)malloc(sizeof(book));
		printf("Book Title:");
		scanf("%s", &ptr->data.name);
		printf("Author name:");
		scanf("%s",&ptr->data.author);
		printf("IBSN:");
		scanf("%s", &ptr->data.ISBN);
		printf("price:");
		scanf("%s", &ptr->data.price);
		ptr->next = h->next;
		h->next = ptr;
	
}
void Search1(book*h)// Book title search
{
	char name[20];
	book*p = h->next;
	printf("Enter the title you want to find:");
	scanf("%s",&name);
	while (p!=NULL)
	{
		if (strcmp(p->data.name,name)!=0)
		{
			p = p->next;
		}
		else 
		{
			printf("Book Title\tAuthor name\tISBN\tPrice \n");
			printf("%s\t %s \t %s \t %s\n",p->data.name,p->data.author,p->data.ISBN,p->data.price);
			return;
		}
	}
	if (p == NULL)
	{
		printf("Not found! \n");
	}
}
void Search2(book*h)// ISBN search
{
	char ISBN[20];
	book*p = h->next;
	printf("Enter the ISBN to find:");
	scanf("%s", &ISBN);
	while (p != NULL)
	{
		if (strcmp(p->data.ISBN, ISBN)!=0)
		{
			p = p->next;
		}
		else
		{
			printf("Book Title\tAuthor name\tISBN\tPrice\n");
			printf("%s\t  %s  \t  %s  \t %s\n", p->data.name,p->data.author, p->data.ISBN, p->data.price);
			return;
		}
	}
	if (p == NULL)
	{
		printf("Not found! \n");
	}
}
void PrintLink(book*h)// displaying all the books
{
	book*p;
	printf("Book Title\tAuthor name\tISBN\tPrice \n");
	for (p = h->next; p != NULL; p = p->next)
	{
		printf("%s\t",p->data.name);
		printf("%s\t",p->data.author);
		printf("%s\t", p->data.ISBN);
		printf("%s\t", p->data.price);
		printf("\n");
	}

}
void delete(book*h)
{
	char ISBN[20];// Delete by ISBN because ISBN is unique
	book*p = h->next;
	book*tail = h;
	printf("Enter the ISBN of the book to be deleted:");
	scanf("%s", &ISBN);
	while (p != NULL)
	{
		if (strcmp(p->data.ISBN, ISBN)!=0)
		{
			p = p->next;
			tail = tail->next;
		}
		else
		{
			tail->next = p->next;
			free(p);
			return;
		}
	}
}

void choose(book*h)
{
	int j=0;
	while (j!=7)
	{
		printf("--------- Library Management System --------- \n");
		printf("************plzz enter 1 to add books*******\n");
		printf("************ 1. AddBooks ************** \n");
		printf("************ 2. Insert ************** \n");
		printf("************ 3. Search by title ****** \n");
		printf("***********  4. Search by ISBN ******* \n");
		printf("************ 5. Delete ************** \n");
		printf("************ 6. Display books ************** \n");
		printf("*************7. Exit   **************\n");
		scanf("%d",&j);
		switch (j)
		{
			case 1:
				h=addBooks();
				break;
			case 2:
				Insert(h);
				break;
			case 3:
				Search1(h);
				break;
			case 4:
				Search2(h);
				break;
			case 5:
				delete(h);
				break;
			case 6:
				PrintLink(h);
				break;
			case 7:
				exit(0);
			
			
		}
	}
}

int main()
{
	book*head = NULL;
	choose(head);
	return 0;
}
