
# Heap Esquerdistas

## Objetivos:

Implementar o tipo abstrado de dados heap esquerdistas e a operação de intercalação de de duas heaps.

## 📝 Head Esquerdistas

Heaps são conjuntos ou dicionários que permitem que tenhamos acessos a elementos arbitrários de maneira eficiente.
Algumas vezes, contudo, queremos ter acesso apenas ao elemento mínimo (ou máximo).
Heaps ou filas de prioridades são estruturas de dados especializadas neste tipo de tarefa.

Heaps são utilizados, por exemplo, para:

 - Ordenar um vetor (Heapsort);
 - Implementação de simuladores de eventos discretos (DES);
 - Cálculo de caminhos mínimos (Algoritmo de Djikstra);
 - Cálculo de árvores geradoras de custo mínimo (Algoritmos de Kruskal e Prim);
 - Compressão de arquivos (Algoritmo de Huffman por exemplo).

Existem diversas maneiras de se implementar um heap. Em geral, um heap deve permitir as seguintes operações (se possível eficientemente):
 - MakeHeap:  Cria e devolve um novo heap vazio
 - Insert: Insere um elemento no heap e devolve o novo heap
 - FindMax: Devolve o elemento maximo do heap
 - RemoveMax:  Remove o elemento máximo do heap

 Estamos interessados em **heaps intercaláveis** que além das operações anteriores também oferecem:
  - Merge(H1,H2): cria e devolve um novo heap que contém todos os elementos de H1 e H2

Árvores esquerdistas são árvores binárias nas quais vale a propriedade esquerdista :
 - Para todo no **x** da árvore vale:
  $$dist(Esq(x)) >= dist(Dir(x))$$
onde Esq(x) e Dir(x) são respectivamente, os filhos direito e esquerdo de **x**.

O *dist* de um nó *x* é o comprimento do caminho de *x* até o nó não nulo mais à direita.
 - Considera-se que o dist de um nó nulo é -1;

## O que deve ser feito? 

Uma estrutura básica para a implementação da heap esquerdistas já foi fornecida. 
 - [leftist_heap_node.h](siga/include/leftist_heap_node.h) implementa a estrutura de um nó de uma árvore esquerdista.
 - [leftist_heap.h](siga/include/leftist_heap.h) tem uma implementação incompleta de heap esquerdistas.

 Nessa atividade, vocês devem implementar as operações **merge**, **insert**, **FindMax** e **RemoveMax**.



## Compilação e execução

```
cmake -B build 
cd build 
ctest
...

```
O comando ctest irá executar o conjunto de testes unitaŕios para avaliar sua implementação.

Os testes [1](tests/test1.cc)  ao [2]()  criam heaps de inteiros para validar as funções implementadas. 


Veja no arquivo [CMakeLists.txt](CMakeLists.txt) o que os testes estão fazendo.

```
Test project /home/camata/git/dcc012/dcc012b-lab03-sorting/build
      Start  1: Setup
 1/10 Test  #1: Setup ............................   Passed    0.01 sec
      Start  2: TestImportacao1000
 2/10 Test  #2: TestImportacao1000 ...............   Passed    0.13 sec
      Start  3: TestMergeSort1000
 3/10 Test  #3: TestMergeSort1000 ................   Passed    0.01 sec
      Start  4: MergeSortCompare
 4/10 Test  #4: MergeSortCompare .................   Passed    0.02 sec
      Start  5: TestQuickSort1000
 5/10 Test  #5: TestQuickSort1000 ................   Passed    0.01 sec
      Start  6: QuickSortCompare
 6/10 Test  #6: QuickSortCompare .................   Passed    0.02 sec
      Start  7: Importe2000
 7/10 Test  #7: Importe2000 ......................   Passed    0.29 sec
      Start  8: OrdenaCursoENome
 8/10 Test  #8: OrdenaCursoENome .................   Passed    0.02 sec
      Start  9: OrdenaCursoENomeCompare
 9/10 Test  #9: OrdenaCursoENomeCompare ..........   Passed    0.01 sec
      Start 10: Compara
10/10 Test #10: Compara ..........................   Passed    0.98 sec

100% tests passed, 0 tests failed out of 10
```


## Como seu código será avaliado?

Seu código irá passar por um sistema de autocorreção onde algumas funcionalidades serão testadas.
Passar em todos testes é importante pois indica que você está no caminho certo. No entanto, outros aspectos podem afetar a sua nota, a saber:
 - código desorganizado e/ou sem documentação/comentários
 - detectação de vazamentos de memória
 - Implementação ineficiente

## Procure saber mais...
Tente saber com os testes unitários foram implementados no CMakeList. 


