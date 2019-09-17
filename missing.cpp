/*
 Developer: Hamed Mirlohi
 Date: 09/11/2019
 
 In this problem, we are preseneted with two arrays of numbers.
 Child array has all the elements of mother array, however one item is missing.
 to Approach this problem, we are using Hash tables to solve the issue.
 we store all the childs missing item in hash table, then we check the hash-table
 against all mothers value, if one value was not detected in the hash table, then
 we will return the result.
 
 */


#include <iostream>
#include <map>

#define NOT_FOUND 0
#define TAKEN 't'

using std::cout;
using std::endl;

int find_missing(int* arr, int* missArr, const int motherSize, const int childrenSize)
{
    std::map<int, char> m;
    
    // populate hash table
    for(int i = 0; i < childrenSize ; ++i)
    {
        m.insert(std::pair<int, char>(missArr[i], TAKEN));
    }
    
    // check which value doesnt exist
    for(int i = 0; i < motherSize; ++i)
    {
        
        if(m[arr[i]] != TAKEN)
        {
            return arr[i];
        }
    }
    
    return NOT_FOUND;
}


int main(void)
{
    int missArr[] = {2,5,4,6};
    int arr[] = {2,3,4,5,6};
    
    int missing_number = find_missing(arr, missArr, sizeof(arr) / sizeof(int), sizeof(missArr) / sizeof(int));
    
    if(missing_number == NOT_FOUND)
        cout<< "No missing number found\n"<< endl;
    else
        cout<< "Missing number found: "<< missing_number << endl;
}
