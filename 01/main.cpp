#include <iostream>
#include "allocator.hpp"


using namespace MyAllocator;


void NotPositiveSizeAlloc(Allocator test){
    test.makeAllocator(20);

    char* negative=test.alloc(-1);
    if (negative==nullptr) 
        std::cout<<"[SUCCESS] negative is nullptr "<<std::endl;
    else 
        std::cout<<"[FAILURE]"<<std::endl;
    
    char* zero=test.alloc(0);
    if (zero==nullptr) 
        std::cout<<"[SUCCESS] zero is nullptr "<<std::endl;
    else 
        std::cout<<"[FAILURE]"<<std::endl;

    char* positive=test.alloc(1);
    if (positive==nullptr) 
        std::cout<<"[FAILURE] positive is nullptr "<<std::endl;
    else 
        std::cout<<"[SUCCESS]"<<std::endl;
    test.reset();
}

void SizeTooBigAlloc(Allocator test){
    
    test.makeAllocator(40);

    char* enoughSpace=test.alloc(5);
    if (enoughSpace==nullptr) 
        std::cout<<"[FAILURE] enoughSpace is nullptr "<<std::endl;
    else 
        std::cout<<"[SUCCESS]"<<std::endl;

    char* notenoughSpace=test.alloc(36);
    if (notenoughSpace==nullptr) 
        std::cout<<"[SUCCESS] notenoughSpace is nullptr "<<std::endl;
    else 
        std::cout<<"[FAILURE]"<<std::endl;

    test.reset();
}

void NoMemoryAllocated(Allocator test){
    

    char* noMemory=test.alloc(36);
    if (noMemory==nullptr) 
        std::cout<<"[SUCCESS] noMemory is nullptr "<<std::endl;
    else 
        std::cout<<"[FAILURE]"<<std::endl;
}
int main(){
    try{
        Allocator test;
        NotPositiveSizeAlloc(test);
        SizeTooBigAlloc(test);
        NoMemoryAllocated(test);

        std::cout << "Everthing is good success!\n";
    }

    catch(int a){
        switch(a){
            case 1:
                std::cout<<"[expected error, FAILURE] Error 1:   memory leak, double makeAllocator"<<std::endl;
                break;   
            case 4:
                std::cout<<"[expected error, FAILURE] Error 4:   size is not pisitive (in MakeAllocator)"<<std::endl;
                break;  
            case 5:
                std::cout<<"[expected error, FAILURE] Error 5:   no memory allocated (in reset)"<<std::endl;
                break;       
        }
    

    }
    catch(...){
        std::cout<<"[unexpected error, FAILURE]"<<std::endl;
    }
    return 0;
}