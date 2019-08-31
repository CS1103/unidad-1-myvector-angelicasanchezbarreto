//
// Created by lica-pc on 8/27/19.
//

#ifndef MYVECTOR_VECTOR_H
#define MYVECTOR_VECTOR_H

namespace UTEC{

    class vector {
    private:
        int* myvector;
        int nelementos;

    public:
        vector();

        vector(int *myvector, int nelementos);

        vector(int nelementos);

        vector(int *myvector);

        int size();

        void push_back(int);

        void insert(int,int);

        void pop_back();

        void erase(int);

        int operator[](int);

        vector operator+(const vector&);

        vector& operator=(const vector&);

        virtual ~vector();

    };

}

#endif //MYVECTOR_VECTOR_H
