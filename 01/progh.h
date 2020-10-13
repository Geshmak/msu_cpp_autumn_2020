#include <iostream>
class Allocator{
    private:
        size_t offset;
        size_t msize;
        char* meme;
        int leakcheck;
    public:
        Allocator(){
            leakcheck = 1;
            offset = 0;
            meme = nullptr;
            msize = 0;
        }
        void makeAllocator(size_t maxSize);
        char* alloc(size_t size);
        void reset();
        ~Allocator(){
            if (meme != nullptr) delete[] meme;
        }
};