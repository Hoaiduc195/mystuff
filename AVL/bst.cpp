#include <iostream>
using namespace std;


struct Node{
    int key;
    Node* left, *right;
};

Node* createNode(int x){
    Node* p = new Node;
    p->key = x;
    p->left = p->right = nullptr;
    return p;
}

class BST{
    private:
        Node* root = nullptr;

        Node* search(Node* root, int x){
            if(!root) return nullptr;

            if(root->key==x) return root;
            if(x>root->key) return search(root->right,x);

            return search(root->left,x);
        }

        Node* insert(Node* root, int x){
            if(!root) return createNode(x);
            // if(root->key==x) return root;

            if(root->key>x){
                root->left = insert(root->left,x);
            }else if(root->key<x){
                root->right = insert(root->right,x);
            }
            return root;
        }

        Node* getSuccessor(Node* node){
            Node* cur =node->right;
            while(cur && cur->left) cur = cur->left;

            return cur;
        }

        Node* remove(Node* root, int x){
            if(!root) return nullptr;

            if(root->key<x){
                root->right = remove(root->right,x);
            }else if(root->key>x){
                root->left = remove(root->left,x);
            }else{
                if(!root->left){
                    Node* tmp = root->right;
                    delete root; root = tmp;
                    return root;
                }
                if(!root->right){
                    Node* tmp = root->left;
                    delete root; root = tmp;
                    return root;
                }

                Node* tmp = getSuccessor(root);
                root->key = tmp->key;
                root->right = remove(root->right, root->key);
            }
            return root;
        }

        string strdb(Node* root){
            if(!root) return "";

            string ans = to_string(root->key);

            if(root->left) ans+="("+strdb(root->left)+")";
            if(root->right){
                if(!root->left) ans+="()";
                ans+="("+strdb(root->right)+")";
            }
            return ans;
        }
    public:
        bool search(int x){
            return search(root, x)!= nullptr;
        }

        void insert(int x){
            root = insert(root, x);
        }

        void remove(int x){
            root = remove(root,x);
        }

        void clear(){
            while(root){
                root = remove(root, root->key);
            }
        }

        void strbst(){
            cout<<strdb(root)<<endl;
        }
};


//driver func
int main(){
    BST tree;
    string cmd ="";
    while(cmd!="exit"){
        cout<<">> "; cin>>cmd;
        if(cmd == "ins"){
            int x; cin>>x;
            tree.insert(x);
        }
        if(cmd == "rm"){
            int x; cin>>x;
            tree.remove(x);
        }

        if(cmd == "s"){
            int x; cin>>x;
            if(tree.search(x)){
                cout<<"yes"<<endl;
            }else cout<<"no"<<endl;
        }
        if(cmd =="str"){
            tree.strbst();
        }
        if(cmd =="cls"){system("clear");}
    }

    tree.clear();
    return 0;
}