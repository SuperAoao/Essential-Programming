#include <iostream>
#include <list>

struct singleList
{
	int val;
	singleList* next;
};

struct singleListHead
{
	singleList* head;
};

bool isEmpty(struct singleListHead* head)
{
	if (head)
	{
		return head->head == nullptr;
	}
	else
	{
		return nullptr;
	}
}

void dump(struct singleListHead* head)
{
	if (!head)
	{
		return;
	}
	singleList* tmp = head->head;
	int idx = 0;
	while (tmp)
	{
		printf("[%02d]: %08d\n", idx++, tmp->val);
		tmp = tmp->next;
	}
}

void insert(singleList** prev, singleList* elem)
{
	if (!prev)
	{
		return;
	}
	elem->next = *prev;
	*prev = elem;	//	注意singleList** prev隐含信息, 它其实是前驱节点的next指针
}

void insertHead(singleListHead* head, singleList* elem)
{
	if (head)
	{
		insert(&head->head, elem);
	}
}

singleList* del(singleList** prev)
{
	if (!prev)
	{
		return nullptr;
	}

	singleList* toBeDeleted = (*prev);
	if (toBeDeleted)
	{
		*prev = toBeDeleted->next;
		toBeDeleted->next = nullptr;
	}
	else
	{
		return nullptr;
	}
}

singleList* deleteHead(singleListHead* head)
{
	if (head)
	{
		return del(&head->head);
	}
	else
	{
		return nullptr;
	}
}

void reverse(singleListHead* head)
{
	if (head)
	{
		struct singleListHead tmp = { nullptr };
		struct singleList* elem;

		while (!isEmpty(head)) {
			elem = deleteHead(head);
			insertHead(&tmp, elem);
		}

		head->head = tmp.head;
	}
	else
	{
		return;
	}
}

int main()
{
	singleListHead head = { nullptr };
	singleList list[10];
	singleList** prev = nullptr;
	int idx = 0;
	for (int i = 0; i < 10; i++)
	{
		list[i].val = idx++;
		list[i].next = nullptr;
	}
	insertHead(&head, &list[6]);
	insertHead(&head, &list[5]);
	insertHead(&head, &list[4]);
	insertHead(&head, &list[3]);
	insertHead(&head, &list[2]);
	insertHead(&head, &list[1]);
	insertHead(&head, &list[0]);
	printf_s("insert 0,1,2,3,4,5,6\n");
	dump(&head);

	reverse(&head);
	printf_s("after reverse\n");
	dump(&head);

	return 0;
}