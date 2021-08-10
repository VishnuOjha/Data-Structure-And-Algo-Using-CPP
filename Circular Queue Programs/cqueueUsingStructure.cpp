#include <iostream>
using namespace std;

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q)
{

    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
        cout << "Queue is Full" << endl;
    }

    else
    {
        return 0;
        cout << "Queue is Not full" << endl;
    }
}

int isEmpty(struct queue *q)
{

    if (q->f == q->r)
    {
        return 1;
        cout << "Queue is Not empty" << endl;
    }
    else
    {
        return 0;
        cout << "Queue is Not empty" << endl;
    }
}

void enqueue(struct queue *q, int val)
{

    if (isFull(q))
    {

        cout << "Queue is full" << endl;
    }
    else
    {

        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        cout << "Enqueue the element : " << val << endl;
    }
}

int dequeue(struct queue *q)
{

    int a = -1;
    if (isEmpty(q))
    {
        cout << "Queue is empty" << endl;
        return 1;
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
        cout << "dequeue element " << a << endl;
    }
    return a;
}

void travarsal(struct queue *q)
{

    for (int i = 0; i < q->size; i++)
    {
        cout << "" << q->arr[i] << endl;
    }
}

int main()
{

    struct queue q;
    q.size = 8;
    q.f = 0;
    q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    //enqueue elemenets
    enqueue(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 18);
    enqueue(&q, 19);
    // travarsal(&q);
    cout << endl;
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q, 11);
    enqueue(&q, 12);
    enqueue(&q, 13);
    

        return 0;
}