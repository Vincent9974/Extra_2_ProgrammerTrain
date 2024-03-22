#include <iostream>
#include <queue>
#include <stack>
#include "Tree.h"
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
}Node;




Node* create()
{
    Node* head = new Node(); // 创建头节点
    head->next = NULL; // 初始化头节点的指针域为NULL

    Node* q = head; // 辅助指针指向头节点
    int x;
    cout << "Please input the data (end with 0):" << endl;
    while (cin >> x && x != 0) {
        Node* p = new Node(); // 创建新节点
        p->data = x;
        p->next = NULL;
        q->next = p; // 将新节点连接到链表尾部
        q = p; // 更新辅助指针指向新的尾节点
    }
    return head; // 返回头节点指针
}

int length(Node* head)
{
    int length = 0;
    Node* p = head->next;  

    while (p != NULL) 
    {
        ++length;
        p = p->next;
    }
    return length;
}

void print(Node* head)
{
    Node* p;
    int index = 0;
    if(head->next == nullptr)
    {
        cout << "Empty list" << endl;
        return;
    }
    p = head->next;
    while (p!= NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

Node* searchNode(Node* head, int pos)
{
    Node* p = head->next;
    if(pos < 0)
    {
        cout << "pos incorrect! " << endl;
        return NULL;
    }
    if(pos == 0)
    {
        return head;
    }
    if(p == NULL)
    {
        cout << "list is NULL" << endl;
        return NULL;
    }

    while(--pos)
    {
        p = p->next;
        if((p) == NULL)
        {
            cout << "incorrect postion to search node!\n";
            break;
        }
    }
    return p;
}

Node* insertNode(Node* head, int pos, int data)
{
    Node* item = NULL;
    Node* p = head->next;
    item = new Node;
    item->data = data;

    if(pos < 0)
    {
        cout << "incorrect pos!" << endl;
        return head;
    }
    if(pos == 0)
    {
        head->next = item;
        item->next = p;
        return head;
    }
    p = searchNode(head, pos);
    if(p != NULL)
    {
        item->next = p->next;
        p->next = item;
    }
    return head;
}

Node* deleteNode(Node* head, int pos)
{
    Node* p = head->next;
    Node* item = NULL;
    if(p == NULL)
    {
        cout << "Empty list" << endl;
        return NULL;
    }
    if(pos <= 0)
    {
        cout << "pos incorrect!" << endl;
        return NULL;
    }

    p = searchNode(head, pos - 1);
    if( p!=NULL && p->next!= NULL)
    {
        item = p->next;
        p->next = item->next;
        delete item;
    }
    return head;
}

Node* reverseList(Node* head)
{
    Node* start = head;
    Node* p =head->next;
    Node* pNext;
    Node* pNextNext;
    if(p == NULL)
    {
        cout << "Empty list" << endl;
        return head;
    }
    pNext = p->next;
    p->next = NULL;
    while(pNext != NULL)
    {
        pNextNext = pNext->next;
        pNext->next = p;
        p = pNext;
        pNext = pNextNext;
    }
    head->next = p;
    return head;
}

Node* findMid(Node* head)
{
    Node* current = head->next;
    Node* middle  = head->next;
    if(head->next == NULL)
    {
        return head;
    }
    while(current != NULL && current->next!=NULL)
    {
        current = current->next->next;
        middle  = middle->next;
    }
    return middle;
}

// 插入排序函数
Node* insertionSortList(Node* head) {
    if (!head || !head->next) return head; // 空链表或者只有一个节点，直接返回

    Node dummy = {0, nullptr}; // 创建哑节点作为新链表的头部
    Node* prev = &dummy; // prev指向已排序部分的最后一个节点

    while (head) {
        Node* cur = head; // cur指向当前需要插入的节点
        head = head->next; // head指向下一个待插入的节点

        if (cur->data < prev->data) {
            // 如果当前节点的值小于已排序部分的最后一个节点的值，则从头开始搜索插入位置
            prev = &dummy; // 重置prev为哑节点
        }

        // 在已排序部分中找到合适的位置插入当前节点
        while (prev->next && prev->next->data < cur->data) {
            prev = prev->next;
        }

        cur->next = prev->next; // 插入节点
        prev->next = cur;
    }

    return dummy.next; // 返回排序后的链表头部
}

bool isLoop(Node* head)
{
    Node* p1 = head->next;
    Node* p2 = head->next;

    if(head == NULL || head->next ==NULL)
    {
        return false;
    }

    do
    {
        p2 = p2->next->next;
        p1 = p1->next;
    }while(p2 && p2->next && p1 != p2);
    if(p1 == p2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Node* merge(Node* head1, Node* head2) {
    if (head1 == nullptr) {
        return head2;
    } else if (head2 == nullptr) {
        return head1;
    }

    Node* head = nullptr; // 合并后的头指针
    Node* tail = nullptr; // 合并后的尾指针
    Node* head1P = head1; // 链表1当前节点
    Node* head2P = head2; // 链表2当前节点

    // 确定合并后的头节点
    if (head1P->data < head2P->data) {
        head = head1P;
        head1P = head1P->next;
    } else {
        head = head2P;
        head2P = head2P->next;
    }
    tail = head;

    // 合并两个链表
    while (head1P != nullptr && head2P != nullptr) {
        if (head1P->data < head2P->data) {
            tail->next = head1P;
            head1P = head1P->next;
        } else {
            tail->next = head2P;
            head2P = head2P->next;
        }
        tail = tail->next;
    }

    // 处理剩余节点
    if (head1P != nullptr) {
        tail->next = head1P;
    } else if (head2P != nullptr) {
        tail->next = head2P;
    }

    return head;
}




void ex_1()
{
    Node* list = create();
    cout << "=" << endl;
    cout << length(list) << endl;
    cout << "==" << endl;
    print(list);
    cout << "==" << endl;
    Node* node =searchNode(list,2);
    cout << node->data << endl;
    cout <<  "==" << endl;
    list = insertNode(list, 4, 7);
    print(list);
    cout << "==" << endl;
    list = deleteNode(list,5);
    print(list);
    cout << "==" << endl;
    list = reverseList(list);
    print(list);
    cout << "==" << endl;
    Node* list1 = create();
    Node* Middle = findMid(list1);
    cout << Middle->data << endl;
    cout << "==" << endl;
    insertionSortList(list1);
    print(list1);
    cout << "==" << endl;
    cout << isLoop(list1) << endl;
}

void ex_11()
{
    Node* list1 = create();
    Node* list2 = create();
    Node* list3 = merge(list1, list2);
    cout << "==" << endl;
    print(list3);
}

// 定义链表节点结构
struct Node1 {
    int data;
    Node1* next;
    Node1(int val) : data(val), next(nullptr) {}
};

// 创建指定个数的循环链表
Node1* createCircleList(int n) {
    if (n <= 0) return nullptr;
    Node1* head = new Node1(1);
    Node1* prev = head;
    for (int i = 2; i <= n; ++i) {
        Node1* newNode = new Node1(i);
        prev->next = newNode;
        prev = newNode;
    }
    prev->next = head; // 将最后一个节点的 next 指向头节点，形成循环
    return head;
}

// 解决约瑟夫问题
int josephus(int n, int m) {
    Node1* head = createCircleList(n);
    Node1* prev = head;
    while (prev->next != prev) {
        // 找到第 m 个节点的前一个节点
        for (int i = 1; i < m; ++i) {
            prev = prev->next;
        }
        // 删除第 m 个节点
        Node1* temp = prev->next;
        prev->next = temp->next;
        cout << temp->data << " ";
        delete temp;
        // 重新从下一个节点开始数
        prev = prev->next;
    }
    int lastRemaining = prev->data;
    delete prev; // 释放最后一个节点的内存
    return lastRemaining;
}

void ex_12()
{
    int n, m;
    cout << "Enter the total number of people (n): ";
    cin >> n;
    cout << "Enter the counting interval (m): ";
    cin >> m;
    cout << "The last remaining person's position is: " << josephus(n, m) << endl;
}


typedef struct DbNode {
    int data;
    struct DbNode* left;
    struct DbNode* right;
} DbNode;

DbNode* CreateNode(int data) {
    DbNode* newNode = (DbNode*)malloc(sizeof(DbNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

DbNode* CreateList(int head) {
    DbNode* pNode = CreateNode(head);
    return pNode;
}

DbNode* AppendNode(DbNode* head, int data) {
    DbNode* node = CreateNode(data);
    DbNode* p = head;

    // 找到链表的尾节点
    while(p->right != NULL) {
        p = p->right;
    }
    
    // 将新节点插入到尾节点后面
    p->right = node;
    node->left = p;
    node->right = NULL; // 将新节点的右指针设置为 NULL

    return head;
}

void ex_13() {
    DbNode* head = CreateList(0);
    for(int i = 0; i < 10; ++i) {
        head = AppendNode(head, i);
    }
}

int GetLength(DbNode* head)
{
    int count = 1;
    DbNode* pnode = NULL;

    if(head == NULL)
    {
        return 0;
    }
    
    pnode = head->right;
    while(pnode != NULL)
    {
        pnode = pnode->right;
        count++;
    }
    return count;
}

void PrintList(DbNode*& head)
{
    DbNode* pnode = NULL;
    if(head == NULL)
    {
        return;
    }
    pnode = head;
    while(pnode != NULL)
    {
        cout << pnode->data << endl;
        pnode = pnode->right;
    }
}

void FreeList(DbNode* head) {
    DbNode* current = head;
    while (current != NULL) {
        DbNode* next = current->right;
        free(current);
        current = next;
    }
}

DbNode* FindNode(DbNode*& head, int data)
{
    DbNode* pnode = head;
    if(head == NULL)
    {
        return NULL;
    }
    while(pnode->right!= NULL && pnode->data != data)
    {
        pnode = pnode->right;
    }

    if(pnode == NULL)
    {
        return NULL;
    }
    
    return pnode;
}

void InsertNode(DbNode*& head, int data, int position)
{
    DbNode* newNode = new DbNode; // 创建新节点
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    // 如果链表为空，将新节点设为头节点
    if(head == NULL)
    {
        head = newNode;
        return;
    }

    // 在链表头插入节点
    if(position == 0)
    {
        newNode->right = head;
        head->left = newNode;
        head = newNode;
        return;
    }

    DbNode* current = head;
    int currentPosition = 0;
    // 找到插入位置
    while (currentPosition < position && current->right!=NULL)
    {
        current = current->right;
        currentPosition ++;
    }

    // 如果到达链表末尾，则将新节点插入到末尾
    if(current->right == NULL)
    {
        current->right = newNode;
        newNode->left = current;
        return;
    }
    
    // 在中间插入节点
    DbNode* next = current->right;
    newNode->left =  current;
    newNode->right = current->right;
    current->right->left = newNode;
    current->right = newNode;
}

DbNode* deleteNode(DbNode*& head, int data)
{
    DbNode* pnode = head;
    if(head == NULL)
    {
        return head;
    }

    // 如果要删除的节点是头节点
    if (head->data == data) 
    {
        DbNode* temp = head->right;
        if (temp != nullptr) {
            temp->left = nullptr;
        }
        delete head;
        return temp;
    }

    DbNode* current = head;
    while(current->right != NULL && current->data != data)
    {
        current = current->right;
    }
    if(current!=NULL)
    {
        if(current->left!=NULL)
        {
            current->left->right = current->right;
        }
        if(current->right != NULL)
        {
            current->right->left = current->left;
        }
        delete current;
    }
    return head;
}

void ex_16()
{
    DbNode* head = NULL;
    int data;
    while(1) {
        cout << "Input the data for the list: (until enter 0)" << endl;
        cin >> data;
        if(data == 0) {
            break;
        }
        if (head == NULL) {
            head = CreateList(data);
        } else {
            AppendNode(head, data);
        }
    }
    cout << "Length of the list: " << GetLength(head) << endl;
    cout << "List: " << endl;
    PrintList(head);
    cout << FindNode(head,3)->data << endl;
    cout << "Insert:" << endl;
    InsertNode(head, 6, 0);
    PrintList(head);
    cout << "Delete:" << endl;
    deleteNode(head, 1);
    PrintList(head);
}


// 在双向循环链表中插入节点
void InsertCircularNode(DbNode*& head, int newData) {
    DbNode* newNode = new DbNode; // 创建新节点
    newNode->data = newData;
    newNode->left = newNode;
    newNode->right = newNode;

    // 如果链表为空，将新节点设为头节点
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // 找到合适的插入位置
    DbNode* current = head;
    while (current->right != head && current->right->data < newData) {
        current = current->right;
    }

    // 插入节点
    newNode->right = current->right;
    current->right->left = newNode;
    current->right = newNode;
    newNode->left = current;

    // 如果新节点的数据小于头节点的数据，更新头节点
    if (newNode->data < head->data) {
        head = newNode;
    }
}

// 打印双向循环链表
void PrintCircularList(DbNode* head) {
    if (head == nullptr) {
        cout << "Empty List" << endl;
        return;
    }

    DbNode* current = head;
    do {
        cout << current->data << " ";
        current = current->right;
    } while (current != head);
    cout << endl;
}

void ex_19()
{
    DbNode* head = nullptr;

    // 在双向循环链表中插入节点
    InsertCircularNode(head, 10);
    InsertCircularNode(head, 20);
    InsertCircularNode(head, 15);
    InsertCircularNode(head, 5);

    // 打印链表
    PrintCircularList(head);
}

typedef struct _Node
{
    int data;
    struct _Node *next;
}node;

typedef struct _Queue
{
    node *front;
    node *rear;
}MyQueue;

MyQueue* CreateMyQueue()
{
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

//入队
MyQueue* enqueue(MyQueue* q, int data)
{
    node* newP = NULL;
    newP = (node*)malloc(sizeof(node));
    newP->data = data;
    newP->next = NULL;
    if(q->rear == NULL)
    {
        q->front = q->rear = newP;
    }
    else
    {
        //若队列不为空, 则新节点放到队尾,队尾指针指向新节点
        q->rear->next = newP;
        q->rear = newP;
    }
    return q;
}

//出队
MyQueue* dequeue(MyQueue* q)
{
    node* pnode = q->front;
    if(pnode == NULL)
    {
        cout << "Empty Queue!" << endl;
    }
    else
    {
        q->front = q->front->next;
        if(q->front == NULL)
        {
            q->rear = NULL;
        }
        free(pnode);
    }
    return q;
}

int getQueueLength(MyQueue* q)
{
    int len = 0;
    node* pnode = q->front;
    if(pnode == NULL)
    {
        return 0;
    }
    while(pnode != q->rear)
    {
        pnode = pnode->next;
        len++;
    }
    return len;
}

void printMyQueue(MyQueue *q)
{
    node* pnode = q->front;
    if(pnode == NULL)
    {
        cout << "Empty Queue!" << endl;
    }
    cout << "data:" << endl;
    while(pnode != q->rear)
    {
        cout << pnode->data << endl;
        pnode = pnode->next;
    }
    cout << pnode->data << endl;
}

void ex_21()
{
    int len = 0;
    MyQueue* hp = CreateMyQueue();
    enqueue(hp, 1);
    enqueue(hp, 2);
    enqueue(hp, 3);
    enqueue(hp, 4);

    len = getQueueLength(hp);
    cout << "len = " << len << endl;

    printMyQueue(hp);
    dequeue(hp);
    dequeue(hp);

    len = getQueueLength(hp);
    cout << "len = " << len << endl;
    printMyQueue(hp);
}

class StackUsingQueue {
private:
    queue<int> q1;
    queue<int> q2;

public:
    // 入栈操作
    void push(int data) {
        q1.push(data);
    }

    // 出栈操作
    int pop() {
        if (q1.empty())
            return -1; // 栈为空

        // 将q1中的元素移动到q2，留下最后一个元素
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // 获取最后一个元素
        int topElement = q1.front();
        q1.pop();

        // 交换q1和q2
        swap(q1, q2);

        return topElement;
    }

    // 返回栈顶元素
    int top() {
        if (q1.empty())
            return -1; // 栈为空

        // 将q1中的元素移动到q2，留下最后一个元素
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // 获取最后一个元素
        int topElement = q1.front();

        // 将最后一个元素入队到q2中
        q2.push(topElement);

        // 交换q1和q2
        swap(q1, q2);

        return topElement;
    }

    // 判断栈是否为空
    bool empty() {
        return q1.empty();
    }
};








int main()
{

    // ex_1();

    // ex_11();

    // ex_12();

    // ex_13();

    // ex_16();

    // ex_19();

    // ex_21();


    return 0;
}