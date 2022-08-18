#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int x;
	struct list *next;
} liste;

liste *ilk;
liste *iter;

void bastir(liste *r)
{

	while (r != NULL)
	{
		printf("%d ", r->x);
		r = r->next;
	}
}
void ekle(liste *r, int x)
{

	while (r->next != NULL)
	{
		r = r->next;
	}
	r->next = (liste *)malloc(sizeof(liste));
	r->next->x = x;
	r->next->next = NULL;
}

int main()
{
	ilk = (liste *)malloc(sizeof(liste));
	ilk->next = NULL;
	ilk->x = 500;

	for (int i = 0; i < 5; i++)
	{

		ekle(ilk, i * 10);
	}

	bastir(ilk);

	iter = ilk;
	for (int i = 0; i < 3; i++)
		iter = iter->next;

	liste *temp = (liste *)malloc(sizeof(liste));

	temp->next = iter->next;
	iter->next = temp;
	temp->x = 100;
	bastir(ilk);
	getchar();
}
