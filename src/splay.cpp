//
// Created by lyh on 2025/1/7.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include "cstring"
using namespace std;

typedef struct SplayTreeNode * SplayTree;
typedef struct SplayTreeNode
{
    int data;
    SplayTreeNode *lchild,*rchild;
} SplayTreeNode;

void BuildSplayTree(SplayTree *T)
{
    int item;
    cin>>item;
    if(item==-1)
    {
        *T = NULL;
    }
    else {
        *T = new SplayTreeNode;
        (*T)->data = item;
        BuildSplayTree(&((*T)->lchild));
        BuildSplayTree(&((*T)->rchild));
    }
}

SplayTree SingleRotateWithLeft(SplayTree x)
{
    /* x has left child y */
    SplayTree y;
    y = x->lchild;
    x->lchild = y->rchild;
    y->rchild = x;
    return y;
}

SplayTree SingleRotateWithRight(SplayTree x)
{
    /* x has right child y */
    SplayTree y;
    y = x->rchild;
    x->rchild = y->lchild;
    y->lchild = x;
    return y;
}

SplayTree DoubleRotateWithLeft(SplayTree x)
{
    /* x has left child x->lchild  and also
    x->lchild has a  right child x->lchild->right*/
    x->lchild = SingleRotateWithRight(x->lchild);
    return SingleRotateWithLeft(x);
}

SplayTree DoubleRotateWithRight(SplayTree x)
{
    /* x has right child x->rchild  and also
    x->rchild has a  left child x->rchild->lchild*/
    x->rchild = SingleRotateWithLeft(x->rchild);
    return SingleRotateWithRight(x);
}

SplayTree Splay(int key,SplayTree X)
{
    /* simple top down  splay, not requiring key in the tree X
    what it does is as described below                      */
    SplayTreeNode N;
    SplayTree left,right;

    if (X == NULL)
        return X;

    N.lchild = N.rchild = NULL;

    left = right = &N;

    while (key != X->data) {
        if (key < X->data)
        {
            if (X->lchild == NULL)
                break;
            if( key < X->lchild->data) {
                /*小于左支路上连续的两个结点*/
                X = SingleRotateWithLeft(X);
            }
            /*旋转之后看停止条件是否满足*/
            if (X->lchild == NULL)
                break;
            right->lchild = X;
            right = X;
            X = X->lchild;
        }
        else {
            if ( X->rchild == NULL)
                break;
            if ( key > X->rchild->data) {
                /*大于右支路上连续的两个结点*/
                X = SingleRotateWithRight(X);
            }
            /*旋转后看是否满足停止条件*/
            if (X->rchild == NULL)
                break;
            left->rchild = X;
            left = X;
            X = X->rchild;

        }
    }
    left->rchild = X->lchild;
    right->lchild = X->rchild;
    X->lchild = N.rchild;
    X->rchild = N.lchild;
    return X;
}

bool SplaySearch(int key, SplayTree *T)
{
    SplayTree t = *T;
    while (t != NULL) {
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else {
            *T = Splay(key,*T);
            return true;
        }
    }
    return false;
}

SplayTree SplayInsert(int key,SplayTree T)
{
    SplayTree t;
    t = new SplayTreeNode;
    t->data = key;
    t->lchild = t->rchild = NULL;
    if (T == NULL) {
        T = t;
    }
    else {
        T = Splay(key,T);
        if (key < T->data) {
            t->lchild = T->lchild;
            t->rchild = T;
            T->lchild = NULL;
            T = t;
        }
        else {
            if (T->data <key) {
                t->rchild = T->rchild;
                t->lchild = T;
                T->rchild = NULL;
                T = t;
            }
            else {
                delete t;
            }
        }
    }
    return T;

}

SplayTree SplayDelete(int key, SplayTree T)
{
    SplayTree t;
    if (T != NULL) {

        T = Splay(key, T);

        if (key == T->data) {
            if (T->lchild == NULL)
                t = T->rchild;
            else {
                t = T->lchild;
                t = Splay(key,t);
                t->rchild = T->rchild;
            }
            delete T;
            T = t;
        }
    }
    return T;
}

inline int max(int a,int b)
{
    return a>b?a:b;
}
int Height(SplayTree T)
{
    if (T == NULL)
        return 0;
    else
        return 1 + max(Height(T->lchild), Height(T->rchild));
}
void MakeMat(SplayTree T,int root_x,int root_y,int step,int **m)
{
    int lChildPos,rChildPos;
    lChildPos = root_x - step;
    rChildPos = root_x + step;
    if (T == NULL)
        return;
    else
    {
        m[root_y][root_x] = 1;
        MakeMat(T->lchild,lChildPos,root_y+1,step>>1,m);
        MakeMat(T->rchild,rChildPos,root_y+1,step>>1,m);
    }
}

void SplayTreeDisplay(SplayTree T)
{
    if(T == NULL)
        return;
    /* init placehold flags m[h][len] */
    int h = Height(T);
    int len = (1<<h) - 1;
    int row = h;
    int **m = new int*[row];
    for(int i= 0;i<row;i++){
        m[i] = new int[len];
        memset(m[i],0,len*sizeof(int));
    }
    /* get level order traversal sequence */
    vector<SplayTree> v;
    queue<SplayTree> q;
    queue<SplayTree> qt;
    q.push(T);
    SplayTree pt;
    while(!q.empty())
    {
        pt = q.front();
        if (pt->lchild != NULL)
            q.push(pt->lchild);
        if(pt->rchild != NULL)
            q.push(pt->rchild);
        v.push_back(pt);
        q.pop();
    }
    /* generate output matrix  plus '/' and '\\' m[2*h-1][len] */
    MakeMat(T,len>>1,0,len+1>>2,m);
    /* generate output */
    int cnt = 0;
    int width = 1;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(m[i][j])
            {
//				if (i & 1)
//					cout<<setw(width)<<char(m[i][j]);
//				else
//					cout<<setw(width)<<char(m[i][j]);
//					cout<<setw(width)<<m[i][j];
                cout<<(v[cnt])->data;
                cnt++;
            }
            else
                cout<<setw(width)<<' ';
        }
        cout<<endl;
    }

}

int main()
{
    SplayTree T = NULL;
    int i;
    //BuildSplayTree(&T);
    //SplayTreeDisplay(T);
    int a[] = {4,5,6,8,10,12};
    for(i = 0; i < 6; i++) {
        cout<<"Key = "<<a[i]<<" inserting: "<<endl;
        T = SplayInsert(a[i],T);
        SplayTreeDisplay(T);
        cout<<"--------------------------------------------"
              "--------------------"<<endl;
    }

    for(i = 0; i < 6; i++) {
        cout<<"Key = "<<a[i]<<" searching: "<<endl;
        SplaySearch(a[i],&T);
        SplayTreeDisplay(T);
        cout<<"--------------------------------------------"
              "--------------------"<<endl;
    }
    for(i = 0; i < 6; i++) {
        cout<<"Key = "<<a[i]<<" deleting: "<<endl;
        T = SplayDelete(a[i],T);
        SplayTreeDisplay(T);
        cout<<"--------------------------------------------"
              "--------------------"<<endl;
    }

    cout<<"Key = "<<19<<" deleting: "<<endl;
    T = SplayDelete(19,T);
    SplayTreeDisplay(T);
    cout<<"--------------------------------------------"
          "--------------------"<<endl;
}