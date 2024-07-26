#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TreeNode{
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* init(TreeNode* t){
    t->data='A';
    t->left=NULL;
    t->right=NULL;
    return t;
}

void pre(TreeNode* tree){
    if(tree){
        printf("%c",tree->data);
        pre(tree->left);
        pre(tree->right);
    }
}
void mid(TreeNode* tree){
    if(tree){
        mid(tree->left);
        printf("%c",tree->data);
        mid(tree->right);
    }
}
void post(TreeNode* tree){
    if(tree){
        post(tree->left);
        post(tree->right);
        printf("%c",tree->data);
    }
}

TreeNode* newnode(char c){
    TreeNode* tmp=(TreeNode*)malloc(sizeof(TreeNode));
    tmp->data=c;
    tmp->left=tmp->right=NULL;
    return tmp;
}

TreeNode* Find(TreeNode* root,char data){
    if(root==NULL) return NULL;
    if(root->data==data) return root;
    else{
        TreeNode* temp = Find(root->left, data);
        if (temp != NULL)
            return temp;
        return Find(root->right, data);
    }
}

void inserttree(TreeNode* root,char data,char left,char right){
    root->data=data;
    if(left!='.'){
        root->left=newnode(left);
    }
    if(right!='.'){
        root->right=newnode(right);
    }
}

int main(){
    int j=0,n;
    TreeNode* root=newnode('A');
    TreeNode* tmp=NULL;
    char data,ldata,rdata;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        scanf("%c %c %c",&data,&ldata,&rdata);
        getchar();
        tmp=Find(root,data);
        if(tmp!=NULL)
            inserttree(tmp,data,ldata,rdata);
        else inserttree(root,data,ldata,rdata);
    }
    
    pre(root);
    printf("\n");
    mid(root);
    printf("\n");
    post(root);
    
}
