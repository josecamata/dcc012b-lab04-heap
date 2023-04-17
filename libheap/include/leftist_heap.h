#ifndef LEFTIST_HEAP_H
#define LEFTIST_HEAP_H

#include <iostream>
#include <string>

#include "leftist_heap_node.h"



template<typename T>
class LeftistHeap {
    public:

        // Constroi uma nova heap esquerdista vazia.
        LeftistHeap();

        // Cria uma heap com unico nó contendo key
        LeftistHeap(T key);

        void Insert(T);              // Insere chave na heap
        T&   FindMax();              // Seleciona o maior elemento da heap
        T    RemoveMax();            // Remove o maior elemento da heap
        void Merge(LeftistHeap<T>&); // Intercala duas heaps esquerdistas
        void Print();                // Imprime a heap
        bool isEmpty();              // Verifica se a heap está vazia
        bool isLeftistHeap();        // Verifica se a heap é uma heap esquerdista
        ~LeftistHeap();
    private:

        // Funções Auxiliares
        // troca os filhos do nó
        void SwapChildren(LeftistHeapNode<T>* node); 

        // libera memoria alocada 
        void DeallocateMemory(LeftistHeapNode<T>*);  

        // auxilio para a impressão.
        void Auxiliary_Print(LeftistHeapNode<T>* node, const std::string& prefix, bool isLeft, std::ostream& out);
        
        // calcula o caminho minimo de um nó para a raiz.
        int  ComputeDist(LeftistHeapNode<T>*);

        // realiza o merge dados duas arvores esquerdistas.
        LeftistHeapNode<T>* Auxiliary_Merge(LeftistHeapNode<T>* left, LeftistHeapNode<T>* right);    
        
        // auxiliar na 
        bool CheckLeftistHeap(LeftistHeapNode<T>* node);
        

        // Atributos
        // Ponteiro para a raiz da heap
        LeftistHeapNode<T>* root;
};


template<typename T>
void LeftistHeap<T>::SwapChildren(LeftistHeapNode<T>* node)
{
    LeftistHeapNode<T>* temp = node->getLeftChild();
    node->setLeftChild(node->getRightChild());
    node->setRightChild(temp);
}

template<typename T>
int LeftistHeap<T>::ComputeDist(LeftistHeapNode<T>* node)
{
    if (node == nullptr)
        return 0;
    else
        return 1 + std::min(ComputeDist(node->getLeftChild()), ComputeDist(node->getRightChild()));
}

template<typename T>
LeftistHeapNode<T>* LeftistHeap<T>::Auxiliary_Merge(LeftistHeapNode<T>* A, LeftistHeapNode<T>* B)
{
    //TODO: IMPLEMENTAR MERGE
    // Etapas:
    // 1. Se A ou B é nulo, retorne o outro
    // 2. Se A->data < B->data, troque A com B
    // 3. A->right = Merge(A->right, B)
    // 4. Se A->left->dist < A->right->dist, troque A->left com A->right
    // 5. Se A->right é nulo, A->dist = 1, senão A->dist = A->right->dist + 1
    // 6. Retorne A

}

template <typename T>
bool LeftistHeap<T>::CheckLeftistHeap(LeftistHeapNode<T>* node)
{

    if (node == nullptr)
        return true;

    int distL = ComputeDist(node->getLeftChild());
    int distR = ComputeDist(node->getRightChild());
    T parent_data = node->getData();
    if(node->getLeftChild() != nullptr)
        if(parent_data < node->getLeftChild()->getData())
            return false;
    if(node->getRightChild() != nullptr)
        if(parent_data < node->getRightChild()->getData())
            return false;
    
    if( distL >= distR)
        return true;
        
    return CheckLeftistHeap(node->getLeftChild()) && CheckLeftistHeap(node->getRightChild());

}

template<typename T>
LeftistHeap<T>::LeftistHeap() : root(nullptr) {
}

template<typename T>
LeftistHeap<T>::LeftistHeap(T key) : root(new LeftistHeapNode<T>(key)) {
}


template<typename T>
void LeftistHeap<T>::Insert(T key) 
{
    //TODO: IMPLEMENTAR INSERÇÃO
    // Etapas:
    //  1. Criar uma heap com um nó com a chave key
    //  2. Realizar o merge da heap criada com a heap atual

}

template<typename T>
T LeftistHeap<T>::RemoveMax()
{
    //TODO: IMPLEMENTAR REMOÇÃO
    // Etapas:
    //  1. Salvar a chave do nó raiz
    //  2. Realizar o merge dos filhos da raiz
    //  3. Liberar a memória do nó raiz
    //  4. Retornar a chave salva no passo 1

}

template<typename T>
T& LeftistHeap<T>::FindMax()
{
   //TODO: IMPLEMENTAR SELEÇÃO
   // Etapas:
   //  1. Retornar a chave do nó raiz

}

template<typename T>
void LeftistHeap<T>::Merge(LeftistHeap<T>& other)
{
    // Implementação do merge
    // Etapas:
    //  1. Realizar o merge das duas heaps
    //  2. Zerar a heap other

}

template<typename T>
LeftistHeap<T>::~LeftistHeap()
{
    DeallocateMemory(root);
}

template<typename T>
void LeftistHeap<T>::DeallocateMemory(LeftistHeapNode<T>* node)
{
    if(node == nullptr)
        return;
    DeallocateMemory(node->getLeftChild());
    DeallocateMemory(node->getRightChild());
    delete node;
}

template<typename T>
void LeftistHeap<T>::Auxiliary_Print(LeftistHeapNode<T>* node, const std::string& prefix, bool isLeft, std::ostream& out)
{
    if(node == nullptr)
        return;
    
    out << prefix;
    out << (isLeft ? "├──" : "└──" );

    // print the value of the node
    out <<"["<<node->getData()<<","<<node->GetDist()<<"]" << std::endl;

    Auxiliary_Print(node->getLeftChild() , prefix + (isLeft ? "│   " : "    "), true, out);
    Auxiliary_Print(node->getRightChild(), prefix + (isLeft ? "│   " : "    "), false, out);
}

template<typename T>
void LeftistHeap<T>::Print()
{
    Auxiliary_Print(root, "", false,  std::cout);
    std::cout << std::endl;
}

template<typename T>
bool LeftistHeap<T>::isEmpty()
{
    return root == nullptr;
}


template<typename T>
bool LeftistHeap<T>::isLeftistHeap()
{
    return CheckLeftistHeap(root);
}

#endif
