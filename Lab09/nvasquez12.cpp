#include <iostream>
#include <list>
#include <climits>
#include <string>
#define COUNT 10
struct node {
    node *left;
    node *right;
    int freq;
    char letter;
    node(char letter, int freq) {
        left = NULL;
        right = NULL;
        this->freq = freq;
        this->letter = letter;
    }
   
};
//node *extractMin(std::list<node*>& q);
void printTree(node *root, int space);
void getCodes(node *root, std::string *codes, std::string temp);

int main(int argc, char** argv) {
    std::list<node*> q;
    struct node* z;
    std::string *codes = new std::string[6];
    int val;
    
    for (int i = 0; i < 6; i++)
        codes[i] = "";
    
    for (int i = 0; i < 6; i++) {
        std::cin >> val;
        q.push_back(new node(i + 65,val));
    }
    
    for(int i = 0; i < 5; i++) {
        
        z = new node('$', -1);
        q.sort([](node * first, node * second) {return first->freq < second->freq;});
//        used to check order of q
//        for (std::list<node*>::iterator it = q.begin(); it != q.end(); ++it) {
//            std::cout << (*it)->freq << " ";
//        }
        z->left = *(q.begin());
        q.erase(q.begin());
        z->right = *(q.begin());
        q.erase(q.begin());
        z->freq = z->right->freq + z->left->freq;
        q.push_back(z);

    }
//    std::cout << std::endl;
    
//    print2DUtil(*(q.begin()), 0);
    
    getCodes(*(q.begin()), codes, "");
    for(int i = 0; i < 6; i++) {
        std::cout << char(65 + i) << ':' << codes[i] << std::endl;
    }
    return 0;
}

void getCodes(node *root, std::string *codes, std::string temp) {
    if(root == NULL)
        return;
    
    if(root->letter != '$') {
        codes[root->letter - 65] = temp;
    }
    
    getCodes(root->right, codes, temp + "1");
    getCodes(root->left, codes, temp + "0");
    
}
//  for some reason the smallest value of the list would not get chosen and it would throw off my tree.
//node *extractMin(std::list<node*>& q) {
//    node *m;
//    std::list<node*>::iterator it = q.begin();
//    int smallest = INT_MAX;
//    for(; it != q.end(); ++it) {
//        if((*it)->freq < smallest) {
//            smallest = (*it)->freq;
//        }
//    }
//    it--;
//    std::cout << "smallest: " << smallest << std::endl;
//    m = new node('$', (*it)->freq);
//    m->left = (*it)->left;
//    m->right = (*it)->right;
//    m->letter = (*it)->letter;
//    q.erase(it);
//    return m;
//}

//  used to see what the tree looked like
//void printTree(node *root, int space)
//{
//    if (root == NULL){
//        return;
//    }
//    space += COUNT;
//    print2DUtil(root->right, space);
//    std::cout<<std::endl;
//    for (int i = COUNT; i < space; i++)
//        std::cout<<" ";
//    std::cout << root->letter << ":" << root->freq << "\n";
//    print2DUtil(root->left, space);
//}
