#include "SortedCollection.h"
#include <string>
#include <array>
using namespace std;
/**TODO: override any methods necessary
 * to keep this collection of doubles in
 * sorted order.  Hint - Whenever you
 * add an item add it in the "correct"
 * spot to maintain sorted order.
 */
void SortedCollection::sort() {
    int temp = size_;
    while(array_[temp - 1] < array_[temp - 2] && temp > 1){
        double newTemp = array_[temp - 1];
        array_[temp - 1] = array_[temp - 2];
        array_[temp - 2] = newTemp;
        temp--;
    }
}

void SortedCollection::add(double num) {
    //just add from collection and then sort
    Collection::add(num);
    sort();
}