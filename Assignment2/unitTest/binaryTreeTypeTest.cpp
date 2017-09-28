/*#include <iostream>
#include <map>
#include "binaryTreeType.h"

using namespace std;

int maxvar = 0;

void print(int& x)
{
    cout << x << " ";
}

void maxx(int& x)
{
    if(maxvar< x)
    {
        maxvar = x;
        cout << x << " ";
    }
}

int main()
{
    binaryTreeType<map<int,int> > treemap;
    map<int, int> intmap[20];
    intmap[0][10]=5;

    treemap.insert(intmap[0]);
    if(treemap.search(intmap[0]))
    {
        cout << " found map" << endl;
    }




    binaryTreeType<int> intTree;
    cout <<"is the tree empty?" <<intTree.isEmpty() << endl;

    intTree.insert(10);
    intTree.insert(20);
    intTree.insert(12);
    intTree.insert(5);
    intTree.insert(7);

    cout <<"is the tree empty?" <<intTree.isEmpty() << endl;

    cout << "Inorder with function pointers: ";
    intTree.inorderTraversal(print);
    cout << endl;
    cout << "Inorder without function pointers: ";
    intTree.inorderTraversal();
    cout << endl;

    cout << "Postorder with function pointers: ";
    intTree.postorderTraversal(print);
    cout << endl;
    cout << "Postorder without function pointers: ";
    intTree.postorderTraversal();
    cout << endl;

    cout << "Preorder traversal: ";
    intTree.preorderTraversal();
    cout << endl;

    cout << "max is:" << endl;
    intTree.inorderTraversal(maxx);

    cout << endl;

    intTree.destroyTree();
    cout <<"is the tree empty: " <<intTree.isEmpty() << endl;

}

*/
