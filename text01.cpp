//
// Created by antonio on 18-1-9.
//

/*
题目1：BST树的建立及动态查找
生成50个在[200, 1000]之间互不相同的整数保存数组A中，以此数组元素作为关键字，设计实现以下操作的程序：
① 建立对应的BST树，按中序遍历算法输出所建立的BST树的结点；
② 在BST树上的查找指定的关键字（输入要查找的整数），给出操作的结论及相应的操作次数；
③ 在BST树上的删除指定的关键字（输入要删除的整数），给出操作的结论及相应的操作次数，按中序遍历算法输出所建立的BST树的结点；///////未完成
④ 主函数通过调用函数实现以上操作。
*/

#include <iostream>

using namespace std;

class BSTree;

typedef struct node {
    int key_value;
    node *left;
    node *right;
    int count ;
}Node;

class BSTree {
public:
    BSTree();

    ~BSTree();

    void insert(int key);

    Node *search(int key);

    void intraverse(Node *root);//中序遍历

    void start();

    void destroy_tree();

    void destory_node() ;

private:
    int num ;
    void destroy_tree(Node *leaf);

    Node *destroy_node(Node *node, int key) ;//删除key键对应的结点

    void insert(int key, Node *leaf);

    Node *search(int key, Node *leaf);

    void updateCount(Node *node) ;//计数

    Node *MinNode(Node *root) ;//寻找最小大于值

    Node *deleteMin(Node *root) ;//

    Node *root;
};


void BSTree::destory_node() {
    /*
     * 删除任意节点的时候有三种情况可以考虑：
     * 删除一个没有子节点的节点非常简单了，只要返回null即可
     * 删除一个只有一个子节点的节点需要返回它唯一的一个子节点
     * 最难的问题在于删除一个有两个子节点的节点。
     * 这时候就要将右子树中最小的节点分离出来，放在该节点原本的位置。这就是Hibbard删除法。
     */
    cout << "\n请输入要删除的数字" << endl ;
    int n ;
    cin >> n ;
    Node *p = destroy_node(root, n) ;
    if (p == NULL)
        cout << "没有找到" << endl;
    else
        cout << "找到了,你要删除的数字是: " << p->key_value << endl << "已删除" << endl;
}

Node *BSTree::destroy_node(Node *node, int key) {
    //定位到需要删除的点
    if (node == NULL) return NULL;//1

    int compare = key - node->key_value;

    if (compare < 0) {
        node->left = destroy_node(node->left, key);
        updateCount(node);
        return node;
    } else if (compare > 0) {
        node->right = destroy_node(node->right, key);
        updateCount(node);
        return node;
    }

    // 已定位到对应的节点，开始删除。以下是没有子节点或只有1个子节点的情况
    if(node->left == NULL) return node->right;
    if(node->right == NULL) return node->left;

    // 有两个子节点时，采用Hibbard删除法，取出右侧最小的节点取代被删除的节点
    Node *minNode = MinNode(node->right);
    node->right = deleteMin(node->right);

    minNode->left = node->left;
    minNode->right = node->right;
    updateCount(minNode);
    return node;
}

Node *BSTree::deleteMin(Node *root){//删除最小结点，并处理好最下结点的子树
    Node *p = MinNode(root) ;
    if (!p->right && !p->left )
        return NULL ;
    else if(p->left && p->right){
        p->right->left = p->left ;
        root->left = p->right ;
    }
    else if(p->left && !p->right){
        root->left = p->left ;
    }
    else if (p->right && !p->left){
        root->left = p->right ;
    }
    delete p ;
    return root ;
}

void BSTree::updateCount(Node *node) {
    node->count = 1+sizeof(node->left)+sizeof(node->right);
}

Node *BSTree::MinNode(Node *root) {
    if(root == NULL) return NULL;

    Node *node = root;
    while(node->left != NULL) {
        node = node->left;
    }
    return node;//zui xiao jie dian
}

BSTree::BSTree() {
    num = 0 ;
    root = nullptr;
}

BSTree::~BSTree() {
    destroy_tree();
}

void BSTree::start() {
    //内部开启
    int A[50];

    for (int i = 0; i < 50; i++) {
        A[i] = 200 + rand() % 800; // NOLINT
        int j = i;
        while (j--)//防止重复的随机数
        {
            if (A[i] == A[j]) {
                A[i] = 200 + rand() % 800;// NOLINT
                j = i;
            }
        }
    }
    //插入到BST
    for (int i = 0; i < 50; ++i) {
        insert(A[i]);
    }
    //中序遍历
    cout << "中序遍历" << endl ;
    intraverse(root) ;

    cout << "\n请输入要查找的数字" << endl ;
    int n1 ;
    cin >> n1 ;
    Node * p1 = search(n1) ;
    if (p1 == NULL)
        cout << "没有找到" << endl;
    else
        cout << "找到了,你要查找的数字是: " << p1->key_value << endl ;



    destory_node() ;

    num = 0 ;
    intraverse(root) ;

}

void BSTree::destroy_tree(Node *leaf) {
    if (leaf != nullptr) {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void BSTree::insert(int key, Node *leaf) {
    if (key < leaf->key_value) {
        if (leaf->left != nullptr) {
            insert(key, leaf->left);
        } else {
            leaf->left = new Node;
            leaf->left->key_value = key;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
        }
    } else if (key >= leaf->key_value) {
        if (leaf->right != nullptr) {
            insert(key, leaf->right);
        } else {
            leaf->right = new Node;
            leaf->right->key_value = key;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr;
        }
    }
}

Node *BSTree::search(int key, Node *leaf) {
    if (leaf != nullptr) {
        if (key == leaf->key_value) {
            return leaf;
        }
        if (key < leaf->key_value) {
            return search(key, leaf->left);
        } else {
            return search(key, leaf->right);
        }
    } else return nullptr;
}


void BSTree::insert(int key) {
    if (root != nullptr) {
        insert(key, root);
    } else {
        root = new Node;
        root->key_value = key;
        root->left = nullptr;
        root->right = nullptr;
    }
}

Node *BSTree::search(int key) {
    return search(key, root);
}

void BSTree::intraverse(Node *root) {
    //中序便利二叉排序树
    if (root == NULL)
        return;
    if (root->left != NULL)
        intraverse(root->left);
    cout << root->key_value << " ";
    num++ ;
    if (num == 15 || num == 30)
        cout << endl ;

    if (root->right != NULL)
        intraverse(root->right);
}


void BSTree::destroy_tree() {//删除整棵树
    destroy_tree(root);
}


int main01() {

    BSTree bsTree;
    bsTree.start();

    return 0;
}
