#include <stdio.h>
#include <stdlib.h>

typedef struct n
{

	int x;
	struct n *next;
} node;

void ekle(node *r, int a)
{

	while (r->next != NULL)
		r = r->next;

	r->next = (node *)malloc(sizeof(node));
	r->next->x = a;
	r->next->next = NULL;
}

void yazdir(node *r)
{

	while (r != NULL)
	{

		printf("%d -> ", r->x);
		r = r->next;
	}
	if (r == NULL)
		printf("NULL\n");
}

void swap(node *a, node *b)
{
	int temp = a->x;
	a->x = b->x;
	b->x = temp;
}

void bubbleSort(node *r)
{

	if (r == NULL || r->next == NULL)
		return;

	while (r != NULL)
	{

		node *iter = r->next;

		while (iter != NULL)
		{

			if (r->x > iter->x)
				swap(r, iter);

			iter = iter->next;
		}

		r = r->next;
	}
}

int main()
{

	node *root = NULL;
	int input;
	scanf("%d", &input);
	root = (node *)malloc(sizeof(node));
	root->x = input;
	root->next = NULL;

	while (input != 0)
	{

		scanf("%d", &input);

		if (input != 0)
			ekle(root, input);
	}

	yazdir(root);
	bubbleSort(root);

	printf("Listenin Siralanmis Hali : \n");
	yazdir(root);

	int dizi[10];
	int boyut = sizeof(dizi) / sizeof(dizi[0]);
	printf("%d\n%d\n", boyut, dizi[0]);
	system("pause");
	return 0;
}
