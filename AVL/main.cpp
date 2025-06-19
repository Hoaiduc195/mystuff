#include <bits/stdc++.h>
using namespace std;


class Node{
public:
    int val;
    Node *left, *right;
    int height;
};

Node* createNode(int x){
    Node* p = new Node;
    p->val = x;
    p->left = p->right = nullptr;
    p->height = 1;
    return p;
}

int getHeight(Node* x){
    return x?x->height:0;
}

int getBalanceFactor(Node* x){
    return x?(getHeight(x->left) - getHeight(x->right)):0;
}

class AVL{
private:
    Node* root = nullptr;

    Node* search(Node* root, int x){
        if(!root) return nullptr;

        if(root->val == x) return root;
        if(root->val>x) return search(root->left,x);
        return search(root->right, x);
    }

    Node* rotateLeft(Node* x){
        Node* y = x->right;
        Node* T = y->left;

        y->left = x;
        x->right = T;

        x->height = max(getHeight(x->left),getHeight(x->right))+1;
        y->height = max(getHeight(y->left),getHeight(y->right))+1;

        return y;
    }

    Node* rotateRight(Node* x){
        Node* y = x->left;
        Node* T = y->right;

        y->right = x;
        x->left = T;

        x->height = max(getHeight(x->left),getHeight(x->right))+1;
        y->height = max(getHeight(y->left),getHeight(y->right))+1;

        return y;
    }

    Node* insert(Node* root, int x){
        if(!root) return createNode(x);

        if(root->val >x){
            root->left = insert(root->left,x);
        }else if(root->val<x) root->right = insert(root->right, x);


        root->height = max(getHeight(root->left),getHeight(root->right))+1;

        int balanceFactor = getBalanceFactor(root);

        if(balanceFactor > 1 && x<root->left->val){
            return rotateRight(root);
        }
        if(balanceFactor < -1 && x>root->right->val){
            return  rotateLeft(root);
        }

        if(balanceFactor > 1 && x>root->left->val){
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        if(balanceFactor < -1 && x<root->right->val){
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    Node* getSuccessor(Node* node){
        Node* cur = node->right;
        while(cur && cur->left) cur = cur->left;
        return cur;
    }

    Node* remove(Node* root, int x){
        if(!root) return nullptr;

        if(x>root->val){
            root->right = remove(root->right,x);
        }else if(x<root->val){
            root->left = remove(root->left,x);
        }else{
            if(!root->right){
                Node* tmp = root->left;
                delete root;
                root = tmp;
            }else if(!root->left){
                Node* tmp = root->right;
                delete root;
                root = tmp;
            }else if(root->right && root->left){
                Node* tmp = getSuccessor(root);
                root->val = tmp->val;
                root->right = remove(root->right, root->val);
            }
        }

        if(!root) return root;

        root->height = 1+max(getHeight(root->left),getHeight(root->right));

        int bf = getBalanceFactor(root);

        if(bf > 1 && getBalanceFactor(root->left) >=0){
            return rotateRight(root);
        }
        if(bf>1 && getBalanceFactor(root->left) <0){
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
        if(bf<-1 && getBalanceFactor(root->right) <0){
            return rotateLeft(root);
        }

        if(bf<-1 && getBalanceFactor(root->right) >=0){
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    void inorder(Node* root){
        if(!root) return;

        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }

    void bfs(Node* root){
        if(!root) return;
        queue<Node*> q;
        q.push(root);

        while(q.size()){
            int size = q.size();
            while(size--){
                Node* v = q.front(); q.pop();
                
                cout<<v->val<<" ";
                if(v->left) q.push(v->left);
                if(v->right) q.push(v->right);    
                cout<<"  ";
            }
            cout<<endl;
        }
    }
    void clearTree(Node* &root) {
        if (!root) return;
        clearTree(root->left);
        clearTree(root->right);
        delete root;
        root = nullptr;
    }

    string treeStr(Node* root){
        if(!root) return "";
        string ans = to_string(root->val);
        if(root->left) ans+="("+treeStr(root->left)+")";
        if(root->right){
            if(!root->left) ans+="()";
            ans+="("+treeStr(root->right)+")";
        }

        return ans;
    }

public:
    ~AVL(){
        clearTree(root);
    }
    void insert(int x){
        root = insert(root,x);
    }

    bool search(int x){
        return search(root, x)!=nullptr;
    }

    void remove(int x){
        root = remove(root,x);
    }

    void print()
    {
        inorder(root);
    }

    void print3d(){
        bfs(root);
    }

    string treeStr(){
        return treeStr(root);
    }
};

int main() {


    // #ifndef MYIO
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif    

    AVL tree;

    string command = "";
    while(command != "exit"){
        cout<<">> ";
        cin>>command;
        if(command == "ins"){
            int x; cin>>x;
            tree.insert(x);
        }
        if(command == "f"){
            int x; cin>>x;
            if(tree.search(x)) cout<<"Exist"<<endl;
            else cout<<"None"<<endl;
        }
        if(command == "rm"){
            int x; cin>>x;
            tree.remove(x);
        }

        if(command == "print"){
            tree.print();
            cout<<endl;
        }
        if(command == "print3d"){
            tree.print3d();
            cout<<endl;
        }
        if(command == "str"){
            cout<<tree.treeStr();
            cout<<endl;
        }

        cout<<endl;
    }


    return 0;
}
