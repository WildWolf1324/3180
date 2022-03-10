// For the BST class provided, implement the findRangeSum() method that returns the sum of keys of all nodes from low to high (inclusive of low and high)
// Use an additional STLs and private methods as needed.
// Assume input keys exist in the BST

#include <iostream>


using namespace std;

/********** BST Class declaration **************/
class Node
{
private:
   int key;
   Node* left;
   Node* right;
   friend class BinarySearchTree;   
};   

class BinarySearchTree
{
public:  
		BinarySearchTree();
		void insert(int key); // Recursive
		int findRangeSum(int low, int high) const; // Returns the sum of keys of all nodes from low to high (inclusive of low and high)
private:
        Node* root;
        void insertHelper(Node* parent, Node* new_node);
        int findRangeSumHelper(Node* root, int low, int high) const;
    
};


/*********** BST Class implemenation *********/
BinarySearchTree::BinarySearchTree()
{  
   root = nullptr;
}
   
void BinarySearchTree::insert(int key) 
{  
   Node* new_node = new Node;
   new_node->key = key;
   new_node->left = nullptr;
   new_node->right = nullptr;
   if (root == nullptr) { 
      root = new_node; 
   } else { 
      insertHelper(root, new_node); 
   }
}

void BinarySearchTree::insertHelper(Node* parent, Node* new_node) 
{  
   if (new_node->key < parent->key) {  
      if (parent->left == nullptr) { 
         parent->left = new_node; 
      }
      else { 
         insertHelper(parent->left, new_node); }
   }
   else if (new_node->key > parent->key) {  
      if (parent->right == nullptr) {
         parent->right = new_node; 
      }
      else { 
         insertHelper(parent->right, new_node);
      }
   }
}


int BinarySearchTree::findRangeSum(int low, int high) const{
// Your code here. Feel free to add additional private methods to the BinarySearchTree class
    int sum = 0;
    sum = findRangeSumHelper(root, low, high);
    return sum;
    

}
int BinarySearchTree::findRangeSumHelper(Node* root, int low, int high) const{
    int sum = 0;
    if(root == nullptr){                            //check if empty
        return 0;
    }
    if(root->key >= low && root->key <= high){      //check for within bounds
        sum = root->key;
    }
    return sum + findRangeSumHelper(root->left,low,high) + findRangeSumHelper(root->right,low,high); //recursive to go through entire BST
}


/******************** Test **************/
int main()
{  
	BinarySearchTree t;
	t.insert(5);
	t.insert(3);
	t.insert(7);
	t.insert(2);
	t.insert(4);
	t.insert(6);
	t.insert(8);
   	t.insert(9);

	cout << "The sum of key keyues is " << t.findRangeSum(4,7) << endl;	// Should print 22
	
    return 0;
}



  
