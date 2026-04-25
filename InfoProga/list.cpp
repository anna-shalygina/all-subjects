#include <iostream>
using namespace std;
struct list
{
	int inf;
	list* next;
	list* prev;
};

void push(list*& h, list*& t, int x)
{
	list* r = new list;
	r->inf = x;
	r->next = NULL;
	if (!h && !t)
	{
		r->prev = NULL;
		h = r;
	}
	else
	{
		t->next = r;
		r->prev = t;
	}
	t = r;
}
void print(list* h)
{
	list* p = h;
	while (p)
	{
		cout << p->inf << " ";
		p = p->next;
	}
}
int findmax(list* h)
{
	if (!h)
	{
		return 0;
	}
	int max1 = h->inf;
	list* p = h->next;
	while (p)
	{
		if (p->inf > max1)
		{
			max1 = p->inf;
		}
		p = p->next;
	}
	return max1;
}
void insert_after(list*& h, list*& t, list* r, int x)
{
	list* p = new list;
	p->inf = x;
	if (r == t)
	{
		p->next = NULL;
		p->prev = t;
		t->next = p;
		t = p;
	}
	else
	{
		p->next = r->next;
		p->prev = r;
		r->next->prev = p;
		r ->next = p;
	}
}
int main()
{
	list* head = NULL;
	list* tail = NULL;
	int N;
	cout << "Input kol of elements:";
	cin >> N;
	cout << "Input elements:";
	for (int i = 0; i < N; i += 1)
	{
		int X;
		cin >>X;
		push(head, tail, X);
	}
	int firstel = head->inf;
	int max1 = findmax(head);
	list* p = head;
	while (p)
	{
		if (p->inf == firstel)
		{
			insert_after(head, tail, p, max1);
			p = p->next;
		}
		p = p->next;
	}
	print(head);
}

#include <iostream>
using namespace std;
struct list
{
	int inf;
	list* next;
	list* prev;
};

void push(list*& h, list*& t, int x)
{
	list* r = new list;
	r->inf = x;
	r->next = NULL;
	if (!h && !t)
	{
		r->prev = NULL;
		h = r;
	}
	else
	{
		t->next = r;
		r->prev = t;
	}
	t = r;
}
void print(list* h)
{
	list* p = h;
	while (p)
	{
		cout << p->inf << " ";
		p = p->next;
	}
}
void del_node(list*& h, list*& t, list* r)
{
	if (r == t && r == h)
	{
		h = t = NULL;
	}
	else if (r == h)
	{
		h = h->next;
		h->prev = NULL;
	}
	else if (r == t)
	{
		t = t->prev;
		t->next = NULL;
	}
	else
	{
		r->next->prev = r->prev;
		r->prev ->next = r->next;
	}
	delete r;
}
void deletedublicates(list*& h, list*& t)
{
	if (!h)
	{
		return;
	}
	list* p = h;
	while (p && p->next)
	{
		if (p->inf == p->next->inf)
		{
			list* dubl = p->next;
			p->next = dubl ->next;
			if (dubl->next)
			{
				dubl->next->prev = p;
			}
			else
			{
				t = p;
			}
			delete dubl;
		}
		else
		{
			p = p->next;
		}
	}
}
int main()
{
	list* head = NULL;
	list* tail = NULL;
	int N;
	cout << "Input kol of elements:";
	cin >> N;
	cout << "Input elements:";
	for (int i = 0; i < N; i += 1)
	{
		int X;
		cin >> X;
		push(head, tail, X);
	}
	deletedublicates(head, tail);
	print(head);
}


#include <iostream>
using namespace std;
struct list
{
	int inf;
	list* next;
	list* prev;
};

void push(list*& h, list*& t, int x)
{
	list* r = new list;
	r->inf = x;
	r->next = NULL;
	if (!h && !t)
	{
		r->prev = NULL;
		h = r;
	}
	else
	{
		t->next = r;
		r->prev = t;
	}
	t = r;
}
void print(list* h)
{
	list* p = h;
	while (p)
	{
		cout << p->inf << " ";
		p = p->next;
	}
}
void del_node(list*& h, list*& t, list* r)
{
	if (r == t && r == h)
	{
		h = t = NULL;
	}
	else if (r == h)
	{
		h = h->next;
		h->prev = NULL;
	}
	else if (r == t)
	{
		t = t->prev;
		t->next = NULL;
	}
	else
	{
		r->next->prev = r->prev;
		r->prev->next = r->next;
	}
	delete r;
}
void srdchage(list*& h, list*& t)
{
	if (!h)
	{
		return;
	}
	int k = 0;
	list* p = h;
	while (p)
	{
		k += 1;
		p = p->next;
	}
	p = h;
	int pos = 0;
	while (p)
	{
		int sum_after = 0;
		int kol_after = 0;
		list* q = p->next;
		while (q)
		{
			sum_after += q->inf;
			kol_after += 1;
			q = q->next;
		}
		if (kol_after > 0)
		{
			double srd = (double)sum_after /kol_after;
			if (p->inf > srd)
			{
				list* del = p;
				p = p->next;
				del_node(h, t, del);
				continue;
			}
		}
		p = p->next;
		pos += 1;
	}
}
int main()
{
	list* head = NULL;
	list* tail = NULL;
	int N;
	cout << "Input kol of elements:";
	cin >> N;
	cout << "Input elements:";
	for (int i = 0; i < N; i += 1)
	{
		int X;
		cin >> X;
		push(head, tail, X);
	}
	srdchage(head, tail);
	print(head);
}