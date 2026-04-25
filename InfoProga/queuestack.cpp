#include<iostream>
using namespace std;

struct queue
{
	int inf;
	queue* next;
};
void push(queue*& h, queue*& t, int x)
{
	queue* r = new queue;
	r->inf = x;
	r->next = NULL;
	if (!h && !t)
	{
		h = t = r;
	}
	else
	{
		t->next = r;
		t = r;
	}
}

int pop(queue*& h, queue*& t)
{
	queue* r = h;
	int i = h->inf;
	h = h->next;
	if (!h)
	{
		t = NULL;
	}
	delete r;
	return i;
}

void deletepovelem(queue*& h, queue*& t)
{
	if (!h || h == t)
	{
		return;
	}
	queue* cur = h;
	while (cur && cur->next)
	{
		if (cur->inf == cur->next->inf)
		{
			queue* pov = cur->next;
			cur->next = pov->next;
			if (pov == t)
			{
				t = cur;
			}
			delete pov;
		}
		else
		{
			cur = cur->next;
		}
	}
}

void coutqueue(queue* h)
{
	queue* f = h;
	while (f)
	{
		cout << f->inf << " ";
		f = f->next;
	}
	cout << endl;
}


int main()
{
	int N;
	cout << "Input kol of elements:";
	cin >> N;
	queue* head = NULL;
	queue* tail = NULL;
	cout << "Input" <<" "<<N <<" "<<"elements:";
	for (int i = 0; i < N; i += 1)
	{
		int X;
		cin >> X;
		push(head, tail, X);
	}

	deletepovelem(head, tail);
	coutqueue(head);

}


#include<iostream>
using namespace std;

struct stack
{
	int inf;
	stack* next;
};

void push(stack*& h, int x)
{
	stack* r = new stack;
	r->inf = x;
	r->next = h;
	h = r;
}

int pop(stack*& h)
{
	int i = h->inf;
	stack* r = h;
	h = h->next;
	delete r;
	return i;
}

void reverse(stack*& h)
{
	stack *head1 = NULL;
	while (h)
	{
		push(head1, pop(h));
	}
	h = head1;
}

int findmax(stack* h)
{
	if (!h)
	{
		return 0;
	}
	int max1 = h->inf;
	stack* p = h;
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

int findmin(stack* h)
{
	if (!h)
	{
		return 0;
	}
	int min1 = h->inf;
	stack* p = h;
	while (p)
	{
		if (p->inf < min1)
		{
			min1 = p->inf;
		}
		p = p->next;
	}
	return min1;
}

stack* insertminaftermax(stack*& h, int max1, int min1)
{   
	stack* res = NULL;  
	while (h) 
	{
		int X=pop(h);
		push(res,X);
	     
		if (X == max1)
		{
			push(res, min1);
		}
	}
	reverse(res);
	return res;
}
void coutstack(stack* h)
{
	stack* p = h;
	while (p)
	{
		cout << p->inf << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	int N;
	cout << "Input kol of elements:";
	cin >> N;
	stack* head = NULL;
	cout << "Input" << " " << N << " " << "elements:";
	for (int i = 0; i < N; i += 1)
	{
		int X;
		cin >> X;
		push(head, X);
	}
	int max1 = findmax(head);
	int min1 = findmin(head);
	reverse(head);
	stack* res = insertminaftermax(head, max1, min1);
	coutstack(res);
}

#include<iostream>
using namespace std;

struct stack
{
	int inf;
	stack* next;
};

void push(stack*& h, int x)
{
	stack* r = new stack;
	r->inf = x;
	r->next = h;
	h = r;
}

int pop(stack*& h)
{
	int i = h->inf;
	stack* r = h;
	h = h->next;
	delete r;
	return i;
}

void reverse(stack*& h)
{
	stack* head1 = NULL;
	while (h)
	{
		push(head1, pop(h));
	}
	h = head1;
}

void coutstack(stack* h)
{
	stack* p = h;
	while (p)
	{
		cout << p->inf << " ";
		p = p->next;
	}
	cout << endl;
}

stack* notdeltwodeltwo(stack*& h)
{
	stack* dontdeltwo = NULL;
	stack * deltwo = NULL;
	stack* res = NULL;
	reverse(h);
	while (h)
	{
		int X = pop(h);
		if (X % 2 != 0)
		{
			push(dontdeltwo, X);
		}
		else
		{
			push(deltwo, X);
		}
	}
	reverse(dontdeltwo);
	reverse(deltwo);

	while (dontdeltwo)
	{
		push(res, pop(dontdeltwo));
	}
	while (deltwo)
	{
		push(res, pop(deltwo));
	}
	reverse(res);
	return res;
}


int main()
{
	int N;
	cout << "Input kol of elements:";
	cin >> N;
	stack* head = NULL;
	cout << "Input" << " " << N << " " << "elements:";
	for (int i = 0; i < N; i += 1)
	{
		int X;
		cin >> X;
		push(head, X);
	}
	stack* res = notdeltwodeltwo(head);
	coutstack(res);
	while (res)
	{
		pop(res);
	}
}


#include<iostream>
using namespace std;

struct queue
{
	int inf;
	queue* next;
};

void push(queue*& h, queue*& t, int x)
{
	queue* r = new queue;
	r->inf = x;
	r->next = NULL;
	if (!h && !t)
	{
		h = t = r;
	}
	else
	{
		t->next = r;
		t = r;
	}
}

int pop(queue*& h, queue*& t)
{
	queue* r = h;
	int i = h->inf;
	h = h->next;
	if (!h)
	{
		t = NULL;
	}
	delete r;
	return i;
}

int findmin(queue *h)
{
	if (!h)
	{
		return 0;
	}
	int min1 = h->inf;
	queue* p = h;
	while (p)
	{
		if (p->inf < min1)
		{
			min1 = p->inf;
		}
		p = p->next;
	}
	return min1;
}

int findlastelem(queue* h)
{
	if (!h)
	{
		return 0;
	}
	int last = -1;
	queue* p = h;
	while (p)
	{
		if (p->inf % 2 == 0)
		{
			last = p->inf;
		}
		p = p->next;
	}
	return last;
}
void insertaftermin(queue*& h, queue*& t, int minVal, int insertel)
{
	queue* temp = NULL;      
	queue* tt = NULL;
	queue* resh = NULL;
	queue* rest = NULL;
	while (h)
	{
		int X = pop(h, t);
		push(temp,tt, X);
	}
	while (temp)
	{
		int X = pop(temp, tt);
		push(resh, rest, X);

		if (X == minVal)
		{
			push(resh, rest, insertel);
		}
	}
	h = resh;
	t = rest;
}

void coutqueue(queue* h)
{
	queue* f = h;
	while (f)
	{
		cout << f->inf << " ";
		f = f->next;
	}
	cout << endl;
}


int main()
{
	int N;
	cout << "Input kol of elements:";
	cin >> N;
	queue* head = NULL;
	queue* tail = NULL;
	cout << "Input" << " " << N << " " << "elements:";
	for (int i = 0; i < N; i += 1)
	{
		int X;
		cin >> X;
		push(head, tail, X);
	}
	int min1 = findmin(head);
	int last = findlastelem(head);
	insertaftermin(head, tail, min1, last);
	coutqueue(head);
}