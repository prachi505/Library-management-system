#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct library
{
	char bk_name[30];
	char author[30];
	int pages;
	float price;
	int acc_num;
	int yr_publish;
};

int main()
{
	struct library l[100];
	char au_nm[30],bk_nm[30];
	int i,j, count;
	i=j=count = 0;

	while(j!=6)
	{
		printf("\n\n1. Add book information\n2. Display book information\n");
		printf("3. List all books of given author\n");
		printf("4. List the title of specified book\n");
		printf("5. List the count of books in the library\n");
		printf("6. Exit");

		printf ("\n\nEnter your choice : ");
		scanf("%d",&j);

		switch (j)
		{
		/* Adding a book */
			case 1:  

				printf ("Enter book name = ");
				scanf ("%s",l[i].bk_name);

				printf ("Enter author name = ");
				scanf ("%s",l[i].author);

				printf ("Enter pages = ");
				scanf ("%d",&l[i].pages);

				printf ("Enter price = ");
				scanf ("%f",&l[i].price);
			
				printf ("Enter accession number = ");
				scanf ("%d",&l[i].acc_num);
			
				printf ("Enter year of publish = ");
				scanf ("%d",&l[i].yr_publish);
				count++;

				break;
			case 2:
				printf("following books are present in the library\n");
				for(i=0; i<count; i++)
				{
					printf ("book name = %s",l[i].bk_name);

					printf ("\t author name = %s",l[i].author);

					printf ("\t  pages = %d",l[i].pages);

					printf ("\t  price = %f",l[i].price);
					
					printf("\t   accession number = %d",l[i].acc_num);
					
					printf("\t   year of publish = %d",l[i].yr_publish);
				}
				break;

			case 3:
				printf ("Enter the author name of the book you want to search: ");
				scanf ("%s",au_nm);
				for (i=0; i<count; i++)
				{
					if (strcmp(au_nm, l[i].author) == 0)
					{
						printf("author found \n");
						printf ("%s %s %d %f %d %d",l[i].bk_name,l[i].author,l[i].pages,l[i].price,l[i].acc_num,l[i].yr_publish);
					}
					else
						printf("author not found \n");
					
				}
				break;

			case 4:
				printf ("Enter book name : ");
				scanf ("%s",bk_nm);
				for (i=0; i<count; i++)
				{
					if (strcmp(bk_nm, l[i].bk_name) == 0)
					{
						printf("book found \n");
						printf ("%s \t %s \t %d \t %f \t %d \t %d",l[i].bk_name,l[i].author,l[i].pages,l[i].price,l[i].acc_num,l[i].yr_publish);
										
					}
					else
						printf("book not found \n");
				}
				break;

			case 5:
				printf("\n No of books in library : %d", count);
				break;
			case 6:
			exit (0); 

		}
	}
	return 0;
}

