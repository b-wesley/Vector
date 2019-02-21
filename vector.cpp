#include <iostream>
#include <stdlib.h>
using namespace std;

class Vector{
private:
    int length, capacity;
    double *v;
public:
    Vector(){
        length= 0;
        cout<<"Enter starting capacity of the array\n";
        cin>>capacity;
        v = new double[2];
    }

    ~Vector(){
        cout<<"Array deleted\n";
    }

    int getLength();
    int getCapacity();


    void grow(int);
    void append(double);
    void removeLast();
    void print();
    void insert(int, double);
};

int Vector::getLength(){
    return length;
}

int Vector::getCapacity(){
    return capacity;
}

//increases the capacity of the array by the given amount
void Vector::grow(int amount){
    capacity += amount;
    double *vNew = new double[capacity];

    for (int i = 0; i<length; i++){
        *(vNew + i) = *(v+i);
    }

    v = vNew;
    delete [] vNew;
}

//adds the given element to the end of the array
void Vector::append(double num){
    if (length == capacity){
        grow(1);
    }
    length++;
    *(v+ length-1) = num;
}

//removes last element of the array
void Vector::removeLast(){
    if (length == 0){
        cout<< "Error: No elements in vector\n";
    }
    else{
        *(v+length-1) = 0;
        length--;
    }
}

//prints all elements of the array
void Vector::print(){
    if (length == 0){
        cout<<"Array Empty";
    }
    else{
        for (int i = 0; i<length; i++){
            cout<<v[i]<<endl;
        }
    }
}

//inserts an element at the given index
void Vector::insert(int index, double num){
    if (index<0 || index>=length){
       cout<<"Error: Index out of range";
    }
    else{
        if(length==capacity){
            grow(1);
        }
        //shift all elements after index to the right
        else{
            for  (int i = length-1; i>=index; i--){
                v[i+1] = v[i];
            }
            v[index] = num;
            length++;
        }
    }
}

int main() {
    Vector vec1;

    int choice, s = 0;
    while(s ==0){
        std::cout<<"Main menu:\n\n1. Print the array\n2. Append element at the end\n3. Remove last element\n";
        std::cout<<"4. Insert one element\n5. Exit\n\nSelect an option:\n";
        std::cin>>choice;

        switch(choice){
            case 1: cout<<"You selected 'Print the array'"<<endl;
                vec1.print();
                break;
            case 2: cout<<"You selected 'Append element at the end'"<<endl;
                double entry;
                cout<<"Enter value to add\n";
                cin>>entry;
                vec1.append(entry);
                break;
            case 3: cout<<"You selected 'Remove last element'"<<endl;
                vec1.removeLast();
                break;
            case 4: cout<<"You selected 'Insert one element'"<<endl;
                int i;
                double val;
                cout<<"Enter index\n";
                cin>>i;
                cout<<"Enter value to append\n";
                cin>>val;
                vec1.insert(i, val);
                break;
            case 5: cout<<"You selected 'Exit'"<<endl;
                s = 1;
                break;
            default: cout<<"Error: Invalid entry"<<endl;
        }
    }
}
