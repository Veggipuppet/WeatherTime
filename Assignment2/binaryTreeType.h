#ifndef BINARYTREETYPE_H_INCLUDED
#define BINARYTREETYPE_H_INCLUDED

#include <iostream>

    /**
	 * @struct nodetype
	 * @brief  The structure for the nodes within the binary tree
	 *
	 *
	 * @author Liam Goerke
	 * @version 01
	 * @date 3/06/2017 Liam Goerke
	 */
template <class T>
        struct nodetype
        {
            T info;
            nodetype<T> *lLink;
            nodetype<T> *rLink;
        };


    /**
	 * @class binaryTreeType
	 * @brief  Creates a dynamic storage structure in the form of a binary tree to store any kind of data.
	 *
	 *
	 * @author Liam Goerke
	 * @version 01
	 * @date 3/06/2017 Liam Goerke
	 */
template <class T>
class binaryTreeType
{
    public:

        /**
		 * @brief  Overload assignment operator
		 *
		 *
		 * @param const binaryTreeType<T>&
		 * @return void
        */
        const binaryTreeType<T>& operator= (const binaryTreeType<T>&);

        /**
		 * @brief  checks to see if the binary search tree is empty
		 *
		 * If tree is empty returns true else returns false
		 * @return bool
        */
        bool isEmpty() const;

        /**
		 * @brief  Function to carry out an inorder traversal of the tree
		 *
		 * The data in each node is dealt with in accordance to the function pointer
		 * @param void(*visit) (T& item)
		 * @return void
        */
        void inorderTraversal(void(*visit) (T& item)) const;

        /**
		 * @brief  Function to carry out an inorder traversal of the tree
		 *
		 * The data in each node is printed out in order
		 *
		 * @return void
        */
        void inorderTraversal() const;

        /**
		 * @brief  Function to carry out an preorder traversal of the tree
		 *
		 * The data in each node is printed out pre order
		 *
		 * @return void
        */
        void preorderTraversal() const;

        /**
		 * @brief  Function to carry out an postorder traversal of the tree
		 *
		 * The data in each node is dealt with in accordance to the function pointer
		 * @param void(*visit) (T& item)
		 * @return void
        */
        void postorderTraversal(void (*visit) (T& item)) const;

        /**
		 * @brief  Function to carry out an postorder traversal of the tree
		 *
		 * The data in each node is printed out
		 *
		 * @return void
        */
        void postorderTraversal() const;

        /**
		 * @brief  Function to destroy the binary tree
		 *
		 * Memory space occupied by each node is deallocated
		 *
		 * @return void
        */
        void destroyTree() ;

        /**
		 * @brief  Function to determine if the search item exists in the tree
		 *
		 * Returns true if the item is within the tree else returns false
		 *
		 * @return bool
        */
        bool search(const T& searchItem) const;

        /**
		 * @brief  Function to insert data into the tree
		 *
		 * The insertItem is entered into the tree based on an order
		 * @param const T& insertItem
		 * @return void
        */
        void insert(const T& insertItem);

        //virtual void deleteNode(const T& deleteItem);

        /**
		 * @brief  Copy constructor
		 *
		 * copies the tree into another tree
		 * @param const binaryTreeType<T>& otherTree, the other tree
		 * @return
        */
        binaryTreeType(const binaryTreeType<T>& otherTree);

        /**
		 * @brief  Default constructor
		 *
		 * sets the root to NULL
		 *
		 * @return
        */
        binaryTreeType();

        /**
		 * @brief  Destructor
		 *
		 * passes the root to the destroy function
		 *
		 * @return
        */
        ~binaryTreeType();

    private:

        nodetype<T> *root;

        /**
		 * @brief  Function to copy the tree
		 *
		 * creates a copy of the tree and points the copiedTreeRoot to it
		 * @param nodetype<T>* &copiedTreeRoot,nodetype<T>* otherTreeRoot, the two tree roots
		 * @return void
        */
        void copyTree(nodetype<T>* &copiedTreeRoot,nodetype<T>* otherTreeRoot);

        /**
		 * @brief  Function to destroy the tree to which p points
		 *
		 * the memory space is deallocated from the nodes in the tree
		 * @param nodetype<T>* &p, the pointer of the root of a tree to destroy
		 * @return void
        */
        void destroy(nodetype<T>* &p);

        /**
		 * @brief  Carries out an inorder traversal of the tree
		 *
		 * The data in each node is dealt with in accordance to the function pointer
		 * @param void(*visit) (T& item)
		 * @return void
        */
        void inorder(nodetype<T> *p, void (*visit) (T& item)) const;

        /**
		 * @brief  Carries out an inorder traversal of the tree
		 *
		 * The data in each node is printed out in order
		 * @param void(*visit) (T& item)
		 * @return void
        */
        void inorder(nodetype<T> *p) const;

        /**
		 * @brief  Carries out an preorder traversal of the tree
		 *
		 * The data in each node is printed out pre order
		 *
		 * @return void
        */
        void preorder(nodetype<T> *p) const;

        /**
		 * @brief  Carries out an postorder traversal of the tree
		 *
		 * The data in each node is dealt with in accordance to the function pointer
		 * @param void(*visit) (T& item)
		 * @return void
        */
        void postorder(nodetype<T> *p, void (*visit) (T& item)) const;

        /**
		 * @brief  Carries out an postorder traversal of the tree
		 *
		 * The data in each node is printed out post order
		 *
		 * @return void
        */
        void postorder(nodetype<T> *p) const;

        /**
		 * @brief  Inserts a node into the tree
		 *
		 * Data inserted based on which node data is greater, duplicates not inserted
		 * @param nodetype<T> *p, nodetype<T> *rootp, the node to insert and the root node
		 * @return void
        */
        void insertData(nodetype<T> *p, nodetype<T> *rootp);
};

template <class T>
void binaryTreeType<T>::insert(const T& insertItem)
{
    nodetype<T> *newNode;

    newNode = new nodetype<T>;
    newNode->info = insertItem;
    newNode->lLink = NULL;
    newNode->rLink = NULL;

    if(root==NULL)
    {
        root = newNode;
    }
    else
    {
        insertData(newNode,root);
    }

}

template <class T>
void binaryTreeType<T>::insertData(nodetype<T> *p, nodetype<T> *parent)
{
    if(p->info<parent->info)
    {
        if(parent->lLink == NULL)
        {
            parent->lLink = p;
        }
        else
        {
            insertData(p,parent->lLink);
        }
    }
    if(p->info>parent->info)
    {
        if(parent->rLink == NULL)
        {
            parent->rLink = p;
        }
        else
        {
            insertData(p,parent->rLink);
        }
    }
}

template <class T>
bool binaryTreeType<T>::isEmpty() const
{
    return(root == NULL);
}

template <class T>
void binaryTreeType<T>::inorderTraversal(void (*visit) (T& item)) const
{
    inorder(root, *visit);
}
template <class T>
void binaryTreeType<T>::inorderTraversal() const
{
    inorder(root);
}

template <class T>
void binaryTreeType<T>::preorderTraversal() const
{
    preorder(root);
}

template <class T>
void binaryTreeType<T>::postorderTraversal(void (*visit) (T& item)) const
{
    postorder(root, *visit);
}
template <class T>
void binaryTreeType<T>::postorderTraversal() const
{
    postorder(root);
}

template <class T>
void binaryTreeType<T>::inorder(nodetype<T> *p, void (*visit) (T& item)) const
{
    if(p != NULL)
    {
        inorder(p->lLink, *visit);
        //std::cout<< p->info << " ";
        (*visit)(p->info);
        inorder(p->rLink, *visit);
    }
}
template <class T>
void binaryTreeType<T>::inorder(nodetype<T> *p) const
{
    if(p != NULL)
    {
        inorder(p->lLink);
        std::cout<< p->info << " ";
        inorder(p->rLink);
    }
}

template <class T>
void binaryTreeType<T>::preorder(nodetype<T> *p) const
{
    if(p != NULL)
    {
        std::cout << p->info<< " ";
        preorder(p->lLink);
        preorder(p->rLink);
    }
}

template <class T>
void binaryTreeType<T>::postorder(nodetype<T> *p,void (*visit) (T& item)) const
{
    if(p != NULL)
    {
        postorder(p->lLink);
        postorder(p->rLink);
        //std::cout << p->info<< " ";
        (*visit)(p->info);
    }
}
template <class T>
void binaryTreeType<T>::postorder(nodetype<T> *p) const
{
    if(p != NULL)
    {
        postorder(p->lLink);
        postorder(p->rLink);
        std::cout << p->info<< " ";
    }
}

template <class T>
void binaryTreeType<T>::copyTree(nodetype<T>* &copiedTreeRoot,nodetype<T>* otherTreeRoot)
{
    if (otherTreeRoot == NULL) copiedTreeRoot = NULL;
    else
    {
        copiedTreeRoot = new nodetype<T>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
        copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
    }
} //end copyTree

template <class T>
void binaryTreeType<T>::destroy(nodetype<T>* &p)
{
    if(p != NULL)
    {
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = NULL;
    }

}

template <class T>
void binaryTreeType<T>::destroyTree()
{
    destroy(root);
}

template <class T>
bool binaryTreeType<T>::search(const T& searchItem) const
{
    nodetype<T> *current;
    bool found = false;

    if(root==NULL) return false;
    else
    {
        current = root;

        while(current != NULL && !found)
        {
            if(current->info == searchItem)
            {
                found = true;
            }
            else if(current->info > searchItem)
            {
                current = current->lLink;
            }
            else
            {
                current = current->rLink;
            }
        }
    }
    return found;
}

///copy constructor
template <class T>
binaryTreeType<T>::binaryTreeType(const binaryTreeType<T>& otherTree)
{
    if(otherTree.root == NULL)
    {
        root = NULL;
    }
    else
    {
        copyTree(root, otherTree.root);
    }
}
///constructor
template <class T>
binaryTreeType<T>::binaryTreeType()
{
    root = NULL;
}
///destructor
template <class T>
binaryTreeType<T>::~binaryTreeType()
{
    destroy(root);
}
///overload assignment operator
template <class T>
const binaryTreeType<T>& binaryTreeType<T>::operator=(const binaryTreeType<T>& otherTree)
{
    if(this != &otherTree)
    {
        if(root != NULL)
        {
            destroy(root);
        }
        if(otherTree.root == NULL)
        {
            root = NULL;
        }
        else
        {
            copyTree(root, otherTree.root);
        }
    }

    return *this;
}


#endif // BINARYTREETYPE_H_INCLUDED
