#include <iostream>
#include "progh.h"
void NotPositiveSizeAlloc(){
    Allocator one;
    one.makeAllocator(20);

    char* a=one.alloc(-1);
    if (a==nullptr) std::cout<<"a is nullptr"<<std::endl;
    
    char* b=one.alloc(0);
    if (b==nullptr) std::cout<<"b is nullptr"<<std::endl;
    
    char* c=one.alloc(1);
    if (c==nullptr) std::cout<<"c is nullptr"<<std::endl;

    one.reset();
}

void SizeTooBigAlloc(){
    Allocator two;
    two.makeAllocator(40);

    char* d=two.alloc(5);
    if (d==nullptr) std::cout<<"d is nullptr"<<std::endl;

    char* e=two.alloc(36);
    if (e==nullptr) std::cout<<"e is nullptr"<<std::endl;

    two.reset();
}

void NoMemoryAllocated(){
    Allocator three;

    char* f=three.alloc(36);
    if (f==nullptr) std::cout<<"f is nullptr"<<std::endl;
}
int main(){
    try{
        NotPositiveSizeAlloc();
        SizeTooBigAlloc();
        NoMemoryAllocated();

        std::cout << "Success!\n";
    }

    catch(int a){
        switch(a){
            case 1:
                std::cout<<"Error 1:   memory leak, double makeAllocator[expected error]"<<std::endl;
                break;   
            case 4:
                std::cout<<"Error 4:   size is not pisitive (in MakeAllocator)[expected error]"<<std::endl;
                break;  
            case 5:
                std::cout<<"Error 5:   no memory allocated (in reset)[expected error]"<<std::endl;
                break;       
        }
    

    }
    catch(...){
        std::cout<<"failure [unexpected error]"<<std::endl;
    }
    return 0;
}