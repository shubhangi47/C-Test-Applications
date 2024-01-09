#include <iostream>
#include <iomanip>

int main()
{
#if ONE
    /* Point Array Duality */
    int arr[] = {
        1,
        2,
        3,
        5,
    };

    int *ptr = arr; // base of array as pointer

    std::cout << "arr[0] " << *ptr << std::endl;
    std::cout << "arr[1] " << *++ptr << std::endl;
    std::cout << "arr[2] " << *(ptr + 1) << std::endl;

    ptr = &arr[2]; // pointer to a location in array.
    *ptr = 88;
    std::cout << "arr[2] " << *ptr << std::endl;

    free(ptr);

    /*g++ Pointers_Test.cpp -o result -D ONE
    output  arr[0] 1
            arr[1] 2
            arr[2] 3
            arr[2] 88 */

#elif TWO
    /* Dynamically allocated arrays*/
    int *ptr = (int *)malloc(sizeof(int) * 3);

    ptr[0] = 1;
    ptr[1] = 2;
    ptr[2] = 3;

    std::cout << "ptr[0] " << *ptr++ << std::endl;
    std::cout << "ptr[1] " << *ptr++ << std::endl;
    std::cout << "ptr[2] " << *ptr++ << std::endl;

    /* g++ Pointers_Test.cpp -o result -D TWO
    ptr[0] 1
    ptr[1] 2
    ptr[2] 3 */

#elif THREE
    /* Pointer to a structure */

    typedef struct Data
    {
        int a;
        double b;
    } data_;

    data_ mydata;
    mydata.a = 1;
    mydata.b = 2.2;

    data_ *dataptr = &mydata; // pointer to a struct
    (*dataptr).a = 5;
    dataptr->b = 6.6;

    std::cout << mydata.a << "\n"
              << mydata.b << std::endl;
    /*g++ Pointers_Test.cpp -o result -D THREE
     output 5
            6.6 */          

#endif

    return 0;
}