#include <iostream>
using namespace std;

/*
Ejercicio número 1
Crear una estructura para implementar un árbol binario y las funciones de crear,
insertar e imprimir en orden nodos del árbol.
*/

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value){
    
    if (root == NULL){
        root = new Node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if (value < root->data){
        root->left = insertNode(root->left, value);
    }else{
        root->right = insertNode(root->right, value);
    }

    return root;
}

void printNode(Node* root) {
    if (root == NULL) {
        return;
    }
    printNode(root->left);
    cout << root->data << " ";
    printNode(root->right);
}

/*
Ejercicio número 2
Crear la funcionalidad que permite al usuario ingresar los números para ser
incorporados en el árbol.
*/

void userInsertNode(Node* root){
    int input;
    cout << "Enter a number: ";
    cin >> input;

    insertNode(root, input);
    cout << "Number inserted succesfully!";
}

/*
Ejercicio número 3
Crear las siguientes funciones de búsqueda en el árbol: buscar valor, buscar valor
mínimo y buscar valor máximo.
*/

bool findValue(Node* root, int value)
{
    if (root == NULL){
        return false;
    }

    if (root->data == value){
        return true;
    }

    if (value < root->data){
        return findValue(root->left, value);
    }else{
        return findValue(root->right, value);
    }
}

int findLowestValue(Node* root)
{
    if (root == NULL){
        cout << "Tree is empty!" << endl;
        return -1337;
    }

    while (root->left != NULL){
        root = root->left;
    }

    return root->data;
}

int findHighestValue(Node* root)
{
    if (root == NULL){
        cout << "Tree is empty!" << endl;
        return -1337;
    }

    while (root->right != NULL){
        root = root->right;
    }

    return root->data;
}

/*
Ejercicio número 4
Cree un la función de eliminar un nodo del árbol.
*/

void deleteNode(Node* root, int value)
{
    if (root == NULL){
        return;
    }

    if (root->data == value){
        root = NULL;        
        return;
    }

    if (value < root->data){
        return deleteNode(root->left, value);
    }else{
        return deleteNode(root->right, value);
    }
}

/*
Ejercicio número 5
Crear una estructura para implementar un árbol General y las funciones de crear,
insertar e imprimir el árbol.
*/

Node* createTree(){
    Node* root;
    root = insertNode(root, 50);

    return root;
}

Node* insertTree(){

}

Node* printTree(){

}



/*
Debe entregar además
Cree un menú para acceder a las distintas funciones desarrolladas en el presente
laboratorio. Debe considerar una correcta validación para no tener errores al
momento de ingresar información por parte del usuario.
*/



int main(){

}