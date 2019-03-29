#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
template <class D, class K>
class AVL;
template <class D, class K>
class Node{
private:
  K key;
  D dato;
  int height;
public:
  Node(const D & d,const K & k,int h=0);
  ~Node();
  friend class AVL<D,K>;
};

template <class D, class K>
Node<D,K>::Node(const D & d,const K & k,int h){
  dato=d;
  key=k;
  height=h;
}
template <class D, class K>
Node<D,K>::~Node(){
  dato=0;
}
template <class D, class K>
class AVL{
private:
  Node<D,K>* root;
  Node<D,K>*p_child[2];
public:
  AVL();
  ~AVL();
  void insert(const D & d);
};
template <class D, class K>
AVL<D,K>::AVL(){
  root=NULL;
  p_child[0]=NULL;
  p_child[1]=NULL;
}
template <class D, class K>
AVL<D,K>::~AVL(){
  root=0;
  p_child[0]=0;
  p_child[1]=0;
}
template <class D, class K>
void AVL<D,K>::insert(const D & d){
  if(root==NULL)root=new Node<D,K>(d,root);
  Node<D,K> *tmp=root;
  if(d<tmp)p_child[0]=new Node<D,K>(d,p_child[0]);tmp=tmp->p_child[0];
  if(d>tmp)p_child[1]=new Node<D,K>(d,p_child[1]);tmp=tmp->p_child[1];
}
int main(){
  AVL<int,int> tree;
  tree.insert(2);
}
