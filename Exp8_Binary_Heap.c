/*Write a program to implement max / min priority queue ADT using binary heap 
and analyze the performance of all the operations.
1. Insert
2. Remove Max
3. Get Max
4. Get Size
5. Check If Empty
6. Decrease Key
7. Increase Key
8. Change Key
9. Remove
10. Del Random
11. Print Random
12. Print Heap*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int key, value;
};

struct node H[50];
int size = -1;

int parent(int i)
{
    return (i - 1) / 2;
}

int isEmpty()
{
    if (size == -1)
        return 0;
    else
        return 1;
}

void swap(struct node *a, struct node *b)
{
    struct node temp = *a;
    *a = *b;
    *b = temp;
}

void shiftUp(int i)
{
    while (i > 0 && H[parent(i)].key < H[i].key)
    {
        swap(&H[parent(i)], &H[i]);
        i = parent(i);
    }
}

void shiftDown(int v)
{
    int w=2*v+1;
    while(w<size+1){
        if(w+1<size+1)
            if(H[w+1].key>H[w].key) w++;
        if(H[v].key>=H[w].key)
            return;
        swap(&H[v],&H[w]);
        v=w;
        w=2*v+1;
    }
}

void insert(int key, int value)
{

    H[++size].key = key;
    H[size].value = value;
    shiftUp(size);
}

struct node extractMax()
{
    struct node result = H[0];
    H[0] = H[size--];
    shiftDown(0);
    return result;
}

void changekey(int i, int p)
{
    int oldp = H[i].key;
    H[i].key = p;

    if (p > oldp)
    {
        shiftUp(i);
    }
    else
    {
        shiftDown(i);
    }
}

void decreasekey(int i)
{
    H[i].key--;
    shiftDown(i);
}

void increasekey(int i)
{
    H[i].key++;
    shiftUp(i);
}

struct node getMax()
{
    return H[0];
}

void remove_ele(int i)
{
    printf("The element removed is : %d with key %d",H[i].value,H[i].key);
    H[i].key = getMax().key + 1;
    shiftUp(i);
    extractMax();
}

int height(int n)
{
    return floor(log2(n));
}

int _size()
{
    return size;
}

int main()
{
    int n, k, v, c, run = 1;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &k, &v);
        insert(k, v);
    }

    printf("Heap: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", H[i].key, H[i].value);
    }
    while (run)
    {
        printf("Press 1 to insert\n");
        printf("Press 2 to removeMax\n");
        printf("Press 3 to getMax\n");
        printf("Press 4 to get size\n");
        printf("Press 5 to check if empty\n");
        printf("Press 6 to decreaseKey\n");
        printf("Press 7 to increaseKey\n");
        printf("Press 8 to changeKey\n");
        printf("Press 9 to remove\n");
        printf("Press 10 to delRandom\n");
        printf("Press 11 to print random element \n");
        printf("Press 12 to print heap \n");
        printf("Press 13 to quit\n");
        printf("Enter choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
        {
            int key, value;
            printf("Enter key and value to insert: ");
            scanf("%d %d", &key, &value);
            insert(key, value);
            break;
        }
        case 2:
        {
            struct node max = extractMax();
            printf("The removed max is key = %d, value = %d\n\n", max.key, max.value);
            break;
        }
        case 3:
        {
            struct node max = getMax();
            printf("The current max is key = %d, value = %d\n\n", max.key, max.value);
            break;
        }
        case 4:
        {
            printf("The size of the heap is %d\n\n", _size()+1);
            break;
        }
        case 5:
        {
            if (isEmpty())
                printf("The heap is not empty\n\n");
            else
                printf("The heap is empty\n\n");
            break;
        }
        case 6:
        {
            int index;
            printf("Enter the index whose key should be decreased: ");
            scanf("%d", &index);
            decreasekey(index);
            break;
        }
        case 7:
        {
            int index;
            printf("Enter the index whose key should be increased: ");
            scanf("%d", &index);
            increasekey(index);
            break;
        }
        case 8:
        {
            int index, newkey;
            printf("Enter the index and new key: ");
            scanf("%d %d", &index, &newkey);
            changekey(index, newkey);
            break;
        }
        case 9:
        {
            int index;
            printf("Enter the index of the key you want to remove: ");
            scanf("%d", &index);
            remove_ele(index);
            printf("\n");
            break;
        }
        case 10:
        {
            srand(time(0));
            int random = rand() % (size + 1);
            remove_ele(random);
            printf("\n");
            break;
        }
        case 11:
        {
            srand(time(0));
            int random = rand() % (size + 1);
            printf("Random key=%d, value=%d", H[random].key, H[random].value);
            break;
        }
        case 12:
        {
            printf("Heap: \n");
            for (int i = 0; i <= size; i++)
            {
                printf("%d %d\n", H[i].key, H[i].value);
            }
            break;
        }
        case 13:
        {
            run = 0;
            break;
        }
        default:
            printf("Invalid input\n\n");
            break;
        }
    }
    return 0;
}
