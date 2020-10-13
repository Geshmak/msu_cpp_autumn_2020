#ifndef ALLOCATOR_H
#define ALLOCATOR_H

namespace MyAllocator{
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
}

#endif