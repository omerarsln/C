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
		printf("%d->", r->x);
		r = r->next;
	}
}

int main()
{

	ilk = (liste *)malloc(sizeof(liste));
	ilk->x = 10;

	ilk->next = (liste *)malloc(sizeof(liste));
	ilk->next->x = 20;

	ilk->next->next = (liste *)malloc(sizeof(liste));
	ilk->next->next->x = 30;

	iter = ilk;

	ilk->next->next->next = NULL;

	int i = 0;

	while (iter->next != NULL)
	{

		i++;
		printf("%d.eleman: %d\n", i, iter->x);
		iter = iter->next;
	}
	for (int j = 1; j < 5; j++)
	{
		iter->next = (liste *)malloc(sizeof(liste));
		iter = iter->next;
		iter->x = j;
		iter->next = NULL;
	}

	bastir(ilk);

	printf("\n\n%d\n", ilk->x);

	system("pause");
	return 0;
}
