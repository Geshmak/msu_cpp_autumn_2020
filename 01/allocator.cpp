#include <iostream>
class Allocator{
    private:
        size_t offset;
        size_t msize;
        char* pointer;
        int leakcheck;
    public:
        Allocator(){
            leakcheck = 1;
            offset = 0;
            pointer = nullptr;
            msize = 0;
        }
        void makeAllocator(size_t maxSize);
        char* alloc(size_t size);
        void reset();
        ~Allocator(){
            if (pointer != nullptr) delete[] pointer;
        }
};

void Allocator::makeAllocator(size_t maxSize){
    if (leakcheck){
        if (maxSize <=0) throw 4;
        pointer = new char[maxSize];
        msize = maxSize;
        leakcheck = 0;
    }
    else throw 1;
}
char* Allocator::alloc(size_t size){
    if (!leakcheck){
        if (size <= 0){
            return (nullptr);  
        } 
        if (msize >= size + offset){
            offset += size;
            return (pointer + offset - size);
        }
        else return (nullptr);
    }
    else return (nullptr);
}

void Allocator::reset(){
    if (!leakcheck)
        offset = 0;
    else throw 5; 
}