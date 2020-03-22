/*Name : Palak Chawla
Section : SCC
ID : 118834175
ms5
email : pchawla5@myseneca.ca
07 April 2019*/

#ifndef SICT_SORT_H
#define SICT_SORT_H

namespace sict
{
    template <typename Type>
    void swap(Type* a, Type* b){
        Type temp = *a;
        *a = *b;
        *b = temp;
    }
    
    template <typename Type>
    void sort(Type arr[], int size)
    {
        for (int i = 0; i < (size - 1); i++)
            {
                for (int j = 0; j < size - i - 1; j++)
                    {
                        if (*arr[j] > *arr[j + 1])
                            {
                                swap(&arr[j], &arr[j + 1]);
                            }
                    }
            }
      }
}
#endif
