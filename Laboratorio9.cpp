#include <iostream>
using namespace std;

/*
Ejercicio número 1
Crear una estructura que permita trabajar con este tipo de árbol y crear las instrucciones
que permitan incorporar la información al árbol en el orden señalado en la imagen de
referencia.
*/

class Node{
    public:
        char data;
        Node* left;
        Node* right;

        Node(char input){
            data = input;
            left = nullptr;
            right = nullptr;
        }
};

Node copyRef(){
    Node refroot = Node('M');

    refroot.left = new Node('C');
    refroot.right = new Node('Z');

    refroot.left->left = new Node('X');
    refroot.left->right = new Node('O');

    refroot.right->left = new Node('T');
    refroot.right->right = new Node('F');

    refroot.right->left->left = new Node('W');

    return refroot;
}

/*
Ejercicio número 2
Crear las funciones para recorrer el árbol en pre-order, in-order y postorden.
*/

void printPreOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
    
}

void printInOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

void printPostOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
    
}

/*
Ejercicio número 3
Considere el arreglo entregado en este ejercicio para; implementar la funcionalidad para la
creación del árbol binario y la selección del recorrido para que la impresión sea en orden.
Arreglo: 21, 18, 6, 9, 10, 7, 19, 15, 12, 5.
*/

/*
Ejercicio número 4
Crear una función que implemente la búsqueda por profundidad. Aquí se puede
considerar la recursividad para realizar la implementación o la utilización de un stack.
*/

/*
Ejercicio número 5
Crear una función que implemente la búsqueda por amplitud. Aquí debe utilizar una cola o
queue para realizar la implementación.
*/

int main(){
    Node root = copyRef();

    cout << "printPreOrder: ";
    printPreOrder(&root);
    cout << endl;

    cout << "inOrder: ";
    printInOrder(&root);
    cout << endl;
    
    cout << "printPostOrder: ";
    printPostOrder(&root);
    cout << endl;
    
    return 0;
}