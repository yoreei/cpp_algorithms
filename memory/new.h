#include<iostream>

namespace memory_new
{
    void start()
    {
        int* set = new int[100];
        //use set[]
        delete [] set;
        {
            std::unique_ptr<int[]> arr(new int[10]);
        }
    }

} // memory