#include <iostream>
using namespace std;
struct Node
{
    int info;
    Node *lt, *rt;
 
    Node(int info)
    {
        this->info = info;
        this->lt = this->rt = NULL;
    }
};
bool isCompBT(Node* root, int m, int n)
{
    if (root == NULL) 
    {
        return true;
    }
    if (m > n) 
    {
        return false;
    }
    if ((root->lt && root->lt->info <= root->info) || (root->rt && root->rt->info <= root->info)) 
    {
        return false;
    }
    return isCompBT(root->lt, 2*m + 1, n) && isCompBT(root->rt, 2*m + 2, n);
}
int totalNodes(Node* root)
{
    if (root == NULL) 
    {
        return 0;
    }
 
    return 1 + totalNodes(root->lt) + totalNodes(root->rt);
}
bool isminHeap(Node* root)
{
    int m = 0;
    return isCompBT(root, m, totalNodes(root));
}
int main()
{
    Node* root = new Node(1);
    root->lt = new Node(3);
    root->rt = new Node(4);
    root->lt->lt = new Node(5);
    root->lt->rt = new Node(6);
    root->rt->lt = new Node(8);
    root->rt->rt = new Node(10);
    root->lt->lt->lt = new Node(7);
    root->lt->lt->rt = new Node(9); 
    root->rt->lt->lt = new Node(12);
    root->rt->lt->rt = new Node(13);
    root->rt->rt->lt = new Node(17);
    root->rt->rt->lt = new Node(19); 

    if (isminHeap(root)) 
    {
        cout << "The given binary tree is a Binary min-heap";
    }
    else {
        cout << "The given binary tree is not a Binary min-heap";
    }
    return 0;
}