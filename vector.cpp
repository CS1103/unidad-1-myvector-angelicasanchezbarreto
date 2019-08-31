//
// Created by lica-pc on 8/27/19.
//

#include "vector.h"
using namespace std;

UTEC::vector::vector() : myvector{nullptr}, nelementos(0) {
}

UTEC::vector::vector(int n) : nelementos(n) {
    myvector = new int[nelementos];
}


int UTEC::vector::size() {
    return nelementos;
}


void UTEC::vector::push_back(int nuevoE){
    // 1. Crear temporal
    int *temp = new int[nelementos + 1];

    // 2. Transferir los datos a temp
    for(int i = 0; i < nelementos; ++i)
        temp[i] = myvector[i];

    // 3. Borrar memoria anterior
    delete [] myvector;

    // 4. Apuntando a memoria actual
    myvector = temp;

    // 5. Actualizando valor
    myvector[nelementos] = nuevoE;

    // 6. Actualizando valor
    nelementos++;
}


void UTEC::vector::pop_back() {
    int *temp = new int[nelementos - 1];

    for(int i = 0; i < nelementos; ++i)
        temp[i] = myvector[i];

    delete [] myvector;

    myvector = temp;

    nelementos--;
}



void UTEC::vector::insert(int nuevoE, int pos) {
    try {
        if (pos>nelementos)
            throw logic_error("Fuera del limite");
    }
    catch(std::exception& e){
        cout << e.what();
    }

    int *temp = new int[nelementos+1];

    for(int i = 0; i < nelementos; i++)
        temp[i] = myvector[i];

    nelementos++;

    for(int i = 0; i<nelementos ; i++ ){
        if(i<pos){
            temp[i] = myvector[i] ;
        }
        else if(i==pos){
            temp[i] = nuevoE;
        }
        else if(i>pos){
            temp[i] = myvector[i-1]  ;
        }
    }

    delete [] myvector;

    myvector = temp;

    }



void UTEC::vector::erase(int pos) {
    try {
        if (pos>nelementos)
            throw logic_error("Fuera del limite");
    }
    catch(std::exception& e){
        cout << e.what();
    }

    int *temp = new int[nelementos-1];

    nelementos--;

    for(int i = 0; i<nelementos; i++ ){
        if(i<pos){
            temp[i] = myvector[i];
        }
        else if(i>=pos){
            temp[i] = myvector[i+1];
        }
    }

    delete [] myvector;

    myvector = temp;

}


int UTEC::vector::operator[](int i) {
    try {
        if(i<nelementos)
            myvector[i];
        else
            throw logic_error("HOli");
    }
    catch(std::exception& e){
        cout << e.what();
    }
    return myvector[i];
}


UTEC::vector UTEC::vector::operator+(const UTEC::vector & M1) {
    vector temp(M1);
    for(int i = 0; i < M1.nelementos;i++){
        temp.myvector[i] += this->myvector[i];
    }

    return temp;
}

UTEC::vector &UTEC::vector::operator=(const UTEC::vector & M1) {
    if(this->nelementos!=0){
        delete[] this->myvector;
    }
    this->nelementos = M1.nelementos;
    this->myvector = new int[this->nelementos];
    for(int i = 0; i < this->nelementos; i++){
        this->myvector[i] = M1.myvector[i];
    }
    return *this;
}


UTEC::vector::~vector() {
    delete [] myvector;
}

