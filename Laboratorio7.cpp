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

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }

};

Node* createNode(int data){
    Node* newNode = new Node(data);
    return newNode;
}

Node* insertNode(Node* root, int value){
    
    if (root == nullptr){
        return createNode(value);
    }

    if (value <= root->data){
        root->left = insertNode(root->left, value);
    }
    if (value > root->data){
        root->right = insertNode(root->right, value);
    }

    return root;
}

void printNode(Node* root) {
    if (root)
    {
        printNode(root->left);
        cout << root->data << " ";
        printNode(root->right);
    }
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
    if (root == nullptr){
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
    if (root == nullptr){
        cout << "Tree is empty!" << endl;
        return -1337;
    }

    while (root->left != nullptr){
        root = root->left;
    }

    return root->data;
}

int findHighestValue(Node* root)
{
    if (root == nullptr){
        cout << "Tree is empty!" << endl;
        return -1337;
    }

    while (root->right != nullptr){
        root = root->right;
    }

    return root->data;
}

/*
Ejercicio número 4
Cree un la función de eliminar un nodo del árbol.
*/

void deleteNode(Node* root, int value) //Not really sure if this really works
{
    if (root == nullptr){
        return;
    }

    if (root->data == value){
        root = nullptr;        
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
/*
Node* createTree(int value){
    Node* root = new Node;
    root->data = value;
    root->left = NULL;
    root->right = NULL;
    return root;
}
*/

Node* insertTree(){
    //???
}

Node* printTree(){
    //???
}

/*
Debe entregar además
Cree un menú para acceder a las distintas funciones desarrolladas en el presente
laboratorio. Debe considerar una correcta validación para no tener errores al
momento de ingresar información por parte del usuario.
*/

int main(){
    int input, res;
    bool loop=true;

    Node* root = createNode(50);
    cout << " -- root generated -- " << endl;

    do
    {
        cout << "\n\n1: Print from root" << endl;
        cout << "2: Insert value as node" << endl;
        cout << "3: Find a value" << endl;
        cout << "4: Find lowest value" << endl;
        cout << "5: Find highest value" << endl;
        cout << "9: Quit" << endl;
        cout << "\n\n Input: ";
        cin >> input;

        switch (input)
        {
        case 1:
            printNode(root);
            cout << "\n" << endl;
            break;
        
        case 2:
            userInsertNode(root);
            break;

        case 3:
            cout << "Enter a value to search: ";
            cin >> input;
            if (findValue(root, input)){
                cout << "Found " << input << " within the tree!" << endl;
            }else{
                cout << "Couldn't find " << input << "..." << endl;
            }
            break;

        case 4:
            res = findLowestValue(root);
            if (res != -1337){
                cout << "Lowest value is " << res << "!" << endl;
            };
            break;

        case 5:
            res = findHighestValue(root);
            if (res != -1337){
                cout << "Highest value is " << res << "!" << endl;
            };
            break;

        case 9:
            loop = false;
            break;
        
        default:
        cout << "ye";
            break;
        }
    } while (loop);
    
    return 0;
}