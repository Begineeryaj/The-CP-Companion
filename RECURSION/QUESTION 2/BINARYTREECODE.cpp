#include<iostream>
using namespace std;

class binaryTree
{
    public:
    class Node
    {
        public:
        int val;
        Node*left;
        Node*right;
        Node(int val)
        {
            this->val=val;
            left=nullptr;
            right=nullptr;
        
        }

    };
    private:
    Node *root=nullptr;
    Node *insert(Node *myNode,int idx,int value,string dir)
    {
        if(myNode==nullptr)
        {
            Node*basecase=new Node(value);
            return basecase;
        }
        if(idx==dir.length())
        {
            myNode->val=value;
            return myNode;
        }
        if(dir[idx]=='R')
        {
            myNode->right=insert(myNode->right,idx+1,value,dir);
        }
        else
        {
            myNode->left=insert(myNode->left,idx+1,value,dir);
        }
        return myNode;
    }
    public:
    void insert(int value, string dir)
    {
        this->root=insert(root,0,value,dir);
    }

    private:
    void display(Node*myNode)
    {
        if(myNode==nullptr)
        {
            return;
        }
        if(myNode->left!=nullptr)
        {
            cout<<myNode->left->val<<" -> ";
        }
        else{
            cout<<" -> ";
        }
        cout<<myNode->val;
        if(myNode->right!=nullptr)
        {
            cout<<" <- "<<myNode->right->val;
        }
        else
        {
            cout<<" <- ";
        }
        cout<<endl;
        display(myNode->left);
        display(myNode->right);
    }

    public:
    void display()
    {
        display(root);
    }
};

int main()
{
    binaryTree bt;
    int n=1;
    while(n!=3)
    {
        int h;
        cout<<"Press 1 to insert"<<endl;
        cout<<"Press 2 to display"<<endl;
        cout<<"press 3 to break"<<endl;
        cin>>h;
        if(h==1)
        {
            int x;string s;
            cout<<"Enter the position: ";
            cin>>s;
            cout<<"Enter the value: ";
            cin>>x;
            bt.insert(x,s);
        }
        else if(h==2)
        {
            bt.display();
        }
        else{
        break;}



    }
    



    }

// bt.insert(15,"");
    // bt.insert(25,"L");
    // bt.insert(35,"R");
    // bt.insert(45,"LL");
    // bt.insert(55,"LR");
    // bt.insert(65,"RL");
    // bt.insert(75,"RR");
    // bt.display();
    // return 0;





