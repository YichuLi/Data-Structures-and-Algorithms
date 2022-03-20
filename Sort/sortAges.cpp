/*
* This sort method: sorting range from 0 to 99
* Time complexity: O(n)
* Space: an array of 100 integers
*/

#include <iostream>
#include <stdexcept>
using namespace std;

void sortAges(int ages[], int length)
{
    if(ages == nullptr || length <= 0){
        return;
    }
    const int oldestAge = 99;
    int timesOfAge[oldestAge+1];    // age range: 0-99

    for(int i = 0; i <= oldestAge; i++){
        timesOfAge[i] = 0;  // init time
    }

    for(int i = 0; i < length; i++){
        int age = ages[i];  // ages is an array for sorting
        if(age < 0 || age > oldestAge){
            throw logic_error("age out of range.");
        }
        ++timesOfAge[age];
    }

    int index = 0;
    for(int i = 0; i <= oldestAge; i++){    // for each age from 0-99
        for(int j = 0; j < timesOfAge[i]; j++){ // times of this age
            ages[index] = i;
            index++;    // index range: 0 to length-1
        }
    }
}

int main()
{
    int ages[] = {1, 3, 44, 34, 22};
    sortAges(ages, 5);
    for(int i = 0; i < 5; i++){
        cout << ages[i] << endl;
    }
    return 0;
}