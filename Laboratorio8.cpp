#include <iostream>
#include <list>
using namespace std;

/*
Ejercicio número 1
Crear una clase llamada Rectangle, considerando dos atributos privados y los
métodos públicos. Incluir además un método para calcular el área.
*/

class Rectangle{
    private:
        double width, length;
    public:
        Rectangle(){
            width = 5;
            length = 5;
            cout << "Called default constructor" << endl;
            printData();
        };
        Rectangle(double inWidth, double inLength){
            width = inWidth;
            length = inLength;
            cout << "Called constructor with parameters" << endl;
            printData();
        };
        
        void printData(){
            cout << "Rectangle (width: " << width << ") (length: "<< length << ")" << endl;
        }

        double getWidth(){return width;}
        void setWidth(double newWidth){
            width = newWidth;
        }

        double getLength(){return length;}
        void setLength(double newLength){
            length = newLength;
        }

        void calculateArea(){
            cout << "Area: " << width * length << endl;
        }
};

/*
Ejercicio número 2
Crear una clase llamada Point, considerando dos atributos privados y los métodos
públicos para su definición y acceso. Implementar el uso de esta clase mediante la
definición de objetivos a través del constructor y utilizando los métodos.
*/

class Point{
    private:
        int X, Y;
    public:
        Point(){
            X = 0;
            Y = 0;
        }

        Point(int inX, int inY){
            X = inX;
            Y = inY;
        }

        int getX(){return X;}
        void setX(int inX){ X = inX;}

        int getY(){return Y;}
        void setY(int inY){ Y = inY;}
};

/*
Ejercicio número 3
Crear una clase llamada LinkedList, considerando que contenga un atributo privado
que apunte al primer nodo de la lista y los métodos públicos para insertar, buscar,
eliminar e imprimir. Implementar el uso de las clases y pruebas de todas las
funcionalidades.
*/

class Node{
    public:
        int data;
        Node* next;
        
        Node(int value){
            data = value;
            next = nullptr;
        }
};

class LinkedList{
    private:
        Node* first;
    public:
        LinkedList(){
            first = nullptr;
        }

        LinkedList(int input){
            first = new Node(input);
        }

        Node*& getFirstPtr(){return first;}
        
        void insertLL(Node*& n, int in){
            
            if (n == nullptr){
                //cout << "Inserted " << in << " in an empty, null node" << endl;
                n = new Node(in);
            }
            else if (n->next == nullptr){
                //cout << "Inserted " << in << " in next node (current is " << n->data << " and n.next is null)" << endl;
                n->next = new Node(in);
            }
            else {
                //cout << "Passing value to next node" << endl;
                insertLL(n->next, in);
            }
        }

        bool searchLL(Node* n, int in){
            if (n == nullptr){
                cout << in << " not found." << endl;
            }

            if (n->data == in){
                cout << "Found " << in << "." << endl;
            }

            return searchLL(n->next, in);
        }

        void deleteLL(){

        }

        void printLL(Node* n){
            if (n == nullptr){
                return;
            }

            cout << n->data;
            if (n->next != nullptr) {
                cout << " -> " << n->next->data;
            }
            else{
                cout << " -> end";
            }
            cout << endl;

            printLL(n->next);
        }
};

/*
Ejercicio número 4
Crear una clase llamada BinaryTree, considerando que contenga un atributo privado
que apunte a la raíz del árbol y los métodos públicos para insertar, buscar e imprimir.
Implementar el uso de las clases y pruebas de todas las funcionalidades.
*/

class BinaryNode{
    public:
        int data;
        BinaryNode* left; 
        BinaryNode* right;

        BinaryNode(){
            data = 50;
            left = nullptr;
            right = nullptr;
        }

        BinaryNode(int input){
            data = input;
            left = nullptr;
            right = nullptr;
        }
};

class BinaryTree{
    private: 
        BinaryNode* root;

        BinaryNode* insertRec(BinaryNode*& bn, int in){
            if (bn == nullptr) {
                return new BinaryNode(in);
            }

            if (in < bn->data) {
                bn->left = insertRec(bn->left, in);
            } 
            
            if (in > bn->data) {
                bn->right = insertRec(bn->right, in);
            }

            return bn;   
        }

        bool searchRec(BinaryNode* bn, int in){
            if (bn == nullptr) {
            return false;
            }

            if (bn->data == in) {
                return true;
            } else if (in < bn->data) {
                return searchRec(bn->left, in);
            } else {
                return searchRec(bn->right, in);
            }
        }
    
        void printRec(BinaryNode* bn) {
            if (bn != nullptr) {
                printRec(bn->left);
                cout << bn->data << endl;
                printRec(bn->right);
        }
    }
    
    public:
        BinaryTree(){
            root = new BinaryNode();
        }

        BinaryTree(int value){
            root = new BinaryNode(value);
        }

        void insertTree(int value) {
            root = insertRec(root, value);
        }

        bool searchTree(int value) {
            return searchRec(root, value);
        }

        void printTree() {
            printRec(root);
        }

};

/*
Ejercicio número 5
Crear una clase llamada GeneralTree, considerando que contenga un atributo
privado que apunte a la raíz del árbol y los métodos públicos para insertar, buscar e
imprimir. Implementar el uso de las clases y pruebas de todas las funcionalidades.
*/

class GeneralTree{

};


    

int main(){

    cout << "\n\n--- PROGRAM STARTED ---\n" << endl;

    cout << "-- E1 --" << endl;
    Rectangle sides = Rectangle(5,5);
    cout << "Created Rectangle using constructor with parameters (Rectangle(5,5))" << endl;
    sides.calculateArea();
    cout << "Changing Rectangle's width and length values to 8 and 4, respectively" << endl;
    sides.setWidth(8);
    sides.setLength(4);
    sides.calculateArea();

    cout << "-- E2 --" << endl;
    Point p = Point(2,8);
    cout << "Created point" << endl;
    cout << "Point: " << p.getX() << "," << p.getY() << endl;
    p.setX(5); 
    cout << "Changed point's X to " << p.getX() << endl;
    p.setY(1); 
    cout << "Changed point's Y to " << p.getY() << endl;
    cout << "Point: " << p.getX() << "," << p.getY() << endl;

    cout << "-- E3 --" << endl;
    LinkedList coollist = LinkedList(1);
    for (int c=0; c<5; c++){
        coollist.insertLL(coollist.getFirstPtr(), c);
        cout << "Inserted " << c << " into LinkedList" << endl;
    }

    cout << "Printing LinkedList: " << endl;
    coollist.printLL(coollist.getFirstPtr());

    cout << "-- E4 --" << endl;
    
    BinaryTree bitree = BinaryTree();
    cout << "Created an empty BiTree" << endl;
    
    for (int c=0; c<10; c++){
        bitree.insertTree(rand()%100);
    }
    cout << "Inserted 10 random numbers into the BiTree" << endl;

    cout << "Printing the BiTree" << endl;
    bitree.printTree();

    return 0;
}
