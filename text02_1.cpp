//////
////// Created by antonio on 18-1-9.
//////
////
//
//
///*题目2：HASH表的建立及查找
//生成50个在[200, 1000]之间互不相同的整数保存数组A中，以此数组元素作为关键字，设计实现以下操作的程序：
//① 建立对应的HASH表并输出所建立的HASH表：HASH函数为h(k)=key% p（p为20以内的某个素数），采用链地址法解决冲突；
//② 在所建立的HASH表中查找指定的关键字（输入要查找的整数），给出操作的结论及相应的操作次数；
//③ 在所建立的HASH表中删除指定的关键字（输入要删除的整数），给出操作的结论及相应的操作次数；
//④ 主函数通过调用函数实现以上操作。
// * */
//
//#include <iostream>
//#include <vector>
//#include <iterator>
//using namespace std;
//typedef int Key ;
//typedef int Value ;
//
//int main02_1() {
//    int A[50];
//
//    for (int i = 0; i < 50; i++) {
//        A[i] = 200 + rand() % 800; // NOLINT
//        int j = i;
//        while (j--) {
//            if (A[i] == A[j]) {
//                A[i] = 200 + rand() % 800;// NOLINT
//                j = i;
//            }
//        }
//        cout << A[i] << ' ';
//    }
//
//    return 0;
//}
//
//const int Prim = 7 ;//prim为20以内的某个素数
//
//class HashNode {
//public:
//    Key key;
//    Value value;
//    HashNode *next ;
//    HashNode(){
//        key = 0 ;
//        value = 0 ;
//        next = nullptr;
//    }
//
//    HashNode(int key, int value) {
//        this->key = key;
//        this->value = value;
//        this->next = nullptr ;
//    }
//};
//
//
//class HashMap {
//private:
//    vector<Key ,Value > Node ;//用容器存放键值对
//    vector<Node *> table ;//
//public:
//    HashMap() {
//    }
//
//
//    int HashFunc(int key) {
//        return key % Prim;//返回的是hash地址
//    }
//
//    void checkExpand() ;
//
//    int getNextPrime(int data) ;
//    //
//    void Insert(const Key &key, const Value &value) {
//        //涉及扩容，需要两个检验函数
//        checkExpand() ;
//        //头插
//        int index = HashFunc(key) ;
//        HashNode* temp = new HashNode(key, value) ;
//        //需要找到容器里下标是index的位置
//        if (table[index] == NULL)
//            table[index] = temp ;
//    }
//
//
//    int Search(int key) {
//        int hash = HashFunc(key);
//        while (table[hash] != nullptr && table[hash]->key != key) {
//            hash = HashFunc(hash + 1);
//        }
//        if (table[hash] == nullptr) {
//            return -1;
//        } else {
//            return table[hash]->value;
//        }
//    }
//
//    void Remove(int key) {
//        int hash = HashFunc(key);
//        while (table[hash] != nullptr) {
//            if (table[hash]->key == key) {
//                break;
//            }
//            hash = HashFunc(hash + 1);
//        }
//        if (table[hash] == nullptr) {
//            cout << "No Element found at key " << key << endl;
//            return;
//        } else {
//            delete table[hash];
//        }
//        cout << "Element Deleted" << endl;
//    }
//
//    ~HashMap() {
//        for (int i = 0; i < Prim; i++) {
//            if (table[i] != nullptr) {
//                delete table[i];
//            }
//            delete[] table;
//        }
//    }
//};
//
//
///*
//*哈希表 除留余数 拉链法
//*/
//#include<stdio.h>
//#include<stdlib.h>
//#include <cstring>
//
//#define TableSize 71
//
//typedef unsigned int Index;
//
//typedef struct ListNode
//{
//    char element[20];
//    struct ListNode *next;
//}*Position;
//
//typedef struct HashTbl
//{
//    int TblSize;
//    Position *TheLists;
//    //struct  HashTbl *next;
//}*HashTable;
//
//void InitializeTable(HashTable Tbl[])
//{
//    int i;
//    HashTable tmp;
//    for(i=0;i<TableSize;i++)
//    {
//        tmp=(HashTable)malloc(sizeof(struct HashTbl));
//        Tbl[i]=tmp;
//        Tbl[i]->TblSize=TableSize;
//        Tbl[i]->TheLists=NULL;
//    }
//}
//
//Index Hash(char Key[])
//{
//    int i=0;
//    int b=0;
//    while(Key[i]!='\0' )
//    {
//        b+=(((int)Key[i])*((int)Key[i]));
//        i++;
//    }//这段用于获取key值，可以根据自己要求修改
//    return b%TableSize;
//    //除留余数法。。。
//}
//
//void Insert(HashTable Tbl[])
//{
//    Position p,newnode;
//    newnode=(Position)malloc(sizeof(struct ListNode));
//    int i=0;
//    char k[20];
//    Index key;
//    scanf("%s",k);
//    key=Hash(k);
//    while(k[i]!='\0' )
//    {
//        newnode->element[i]=k[i];
//        i++;
//    }
//    newnode=NULL;
//
//    p=*Tbl[key]->TheLists;
//
//    if(!p)
//        Tbl[key]->TheLists=&newnode;
//    while(p)
//    {
//        //printf("%s\n",p->element);
//        if(p->next==NULL)
//        {
//            p->next=newnode;
//            //printf("OK!");
//            return ;
//        }
//        else
//            p=p->next;
//    }
//}
//
//void Print(HashTable Tbl[])
//{
//    int i,j,k,l,m;
//    k=0;
//    l=0;
//    m=0;
//    double n,o;
//    Position p;
//    for(i=0;i<TableSize;i++)
//    {
//        j=0;
//        p=*Tbl[i]->TheLists;
//        while(p)
//        {
//            printf("%d->%d->%-20s\t",i,j,p->element);
//            p=p->next;
//            k++;    //统计输出次数，既是数据记录集的总个数
//            j++;    //同一位置上的输出个数，当i＋1是要清零
//            m+=j;
//
//
//        }
//
//        if(!j)
//            printf("%d->%d->\t",i,j);
//        else
//            j--;
//        l+=j;       //计算冲突的记录
//
//        //printf("\t%d",j);
//        printf("\n");
//
//    }
//    n=(double)l/(double)k;  o=(double)m/(double)k;
//    //k为输入记录的总数， l为冲突的记录的总个数  m统计每一个记录的查找长度。
//    //n为冲突率， o为平均查找长度。
//    printf("**********\t%d\t%d\t%d\n",k,l,m);
//    printf("**********\tConflict:%lf\tASL:%lf\n",n,o);
//}
//
//void  Search(HashTable Tbl[])
//{
//    Position p;
//    char k[20];
//    Index key;
//    int j;
//
//    scanf("%s",k);
//    key=Hash(k);printf("%d\n",key);
//    p=*Tbl[key]->TheLists;
//    if(p)
//    {
//        while(strcmp(p->element,k))
//        {
//            p=p->next;
//            if(!p)
//            {
//                printf("No Item found!\n");
//                return ;
//            }
//            j++;
//        }
//        printf("%d->%d->%s\n",key,j,p->element);
//    }
//    else
//    {
//        printf("No Item found!\n");
//    }
//}
//
//void Destroy(HashTable Tbl[])
//{
//    int i;
//    Position p;
//    Position temp;
//
//    for(i=TableSize-1;i>=0;i--)
//    {
//        //printf("%d\n",i);
//        p=*Tbl[i]->TheLists;
//        while(p!=NULL)
//        {
//            temp=p->next;
//            free(p);
//            p=temp;
//        }
//        free(Tbl[i]);
//    }
//}
//
//int main02_1()
//{
//    HashTable T[TableSize];
//    InitializeTable(T);
//    int a,i;
//    while(true)
//    {
//
//        printf("*******1.Insert data**********\n");
//        printf("*******2.search data*********\n");
//        printf("*******3.show add ***********\n");
//        printf("*******4.exit*******************\n");
//        printf("switich action: ");
//        scanf("%d",&a);
//        switch(a)
//        {
//
//
//            case 1:
//                Insert(T);
//                break;
//
//            case 2:
//                Search(T);
//                break;
//
//            case 3:
//                Print(T);
//                break;
//
//            case 4:
//                Destroy(T);
//                break ;
//
//            default:
//                printf("Err! please check!\n");
//                break;
//        }
//
//
//
//    }
//    return 0;
//}


//
// Created by antonio on 18-1-9.
//



/*题目2：HASH表的建立及查找
生成50个在[200, 1000]之间互不相同的整数保存数组A中，以此数组元素作为关键字，设计实现以下操作的程序：
① 建立对应的HASH表并输出所建立的HASH表：HASH函数为h(k)=key% p（p为20以内的某个素数），采用链地址法解决冲突；
② 在所建立的HASH表中查找指定的关键字（输入要查找的整数），给出操作的结论及相应的操作次数；
③ 在所建立的HASH表中删除指定的关键字（输入要删除的整数），给出操作的结论及相应的操作次数；
④ 主函数通过调用函数实现以上操作。
 * */

#include <iostream>
#include <iomanip>

using namespace std;
typedef int Key ;
typedef int Value ;

const int Prim = 7 ;//p为20以内的某个素数
const int Size = 50 ;
const int Over = 10000 ;//表示查找失败

class HashNode {
public:
    Key key;
    Value value;

    HashNode *next ;

    HashNode(Key key, Value value) {
        this->key = key;
        this->value = value;
    }
};


class HashMap {
private:
    HashNode **table;//二级指针
    int sh ;
public:
    int A[Size];
    HashMap() {
        setRand();
        table = new HashNode *[Size];//指针数组
        for (int i = 0; i < Size; i++) {
            table[i] = nullptr;
        }

    }


    int HashFunc(int key) {//这里可能会越界
        sh = key / Size ;
        return key % Prim;
    }

    void setRand(){
        for (int i = 0; i < Size; i++) {
            A[i] = 200 + rand() % 800; // NOLINT
            int j = i;
            while (j--) {
                if (A[i] == A[j]) {
                    A[i] = 200 + rand() % 800;// NOLINT
                    j = i;
                }
            }
        }
    }

    void Insert(int key, int value) {
        int index = HashFunc(value);

        //头插法，不管该hash位置有没有其他结点，直接插入结点
        HashNode *p = new HashNode(index, value) ;
        if (p == NULL) return;

        p->next = table[index] ;
        table[index] = p ;

        return;
    }

    void displayHashTable()
    {//显示hash表元素（不包括空）
        HashNode *np;
        Value hashvalue;
        for(int i=0; i < Size; ++i) {
            if(table[i] != NULL) {
                np = table[i];

                printf("\nkey键: %d (", np->key);
                cout << "value值: " ;
                for(; np != NULL; np = np->next)
                    cout <<  np->value << "  ";
                printf(")\n");
            }
        }
    }

    void cleanUp()
    {//清空hash表
        HashNode *np,*tmp;
        for(int i=0;i < Size; ++i)
        {
            if(table[i] != NULL)
            {
                np = table[i];
                while(np != NULL)
                {
                    tmp = np->next;
                    free(np);
                    np = tmp;
                }
            }
        }
    }

    HashNode* lookup(Value value){

        Value hashvalue = HashFunc(value);

        HashNode *np = table[hashvalue];
        np->key = hashvalue ;//

        for( ; np != NULL; np = np->next) {
            //这里是链地址法解决的冲突,返回的是第一个链表结点
            if (np->value == value)//相等的时候才返回0
                return np;
        }
        return NULL;
    }

    Value search(Value value)
    {//对hash表查找特定元素
        HashNode* np = lookup(value);
        if(np == NULL){
            return Over;
        }
        else
            return np->key;
    }

    //删除value值对应的结点
    int  Remove(Value value) {
        int key ;
        HashNode *p = lookup(value);
        if (p){
            delete p ;
            return 1 ;
        }
        return Over ;

    }

    ~HashMap() {
        for (int i = 0; i < Prim; i++) {
            if (table[i] != nullptr) {
                delete table[i];
            }
            delete[] table;
        }
    }
};


int main02_1() {

    HashMap hashMap ;
    for (int i = 0; i < Size; ++i) {
        hashMap.Insert(i, hashMap.A[i]) ;
    }

    hashMap.displayHashTable() ;
    cout << "请输入要查找数据的value值" << endl ;
    int data ;
    cin >> data ;
    data = hashMap.search(data) ;
    if (data != Over){
        cout << "找到了, 你要查找数据的key是: " << data << endl ;
    } else{
        cout << "没有找到" << endl ;
    }
    int del ;
    cout << "请输入要删除的数据value值" << endl ;
    cin >> del ;
    del = hashMap.Remove(del) ;
    if (del != Over){
        cout << "已删除" << endl ;
        hashMap.displayHashTable() ;
    } else{
        cout << "没有找到" << endl ;
    }

    hashMap.cleanUp() ;

    return 0;
}
