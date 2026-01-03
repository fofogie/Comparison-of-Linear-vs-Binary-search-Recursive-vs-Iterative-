#include "searchAlgorithm.h"
#include <vector>

using namespace std;

bool linearIterative(const std::vector<long long>& a, long long t) {
    for (int i = 0; i < a.size(); i++){
        if (a[i] == t) {
            return true; 
        }
    } 
    return false; 
}

bool linearRecursive(const vector<long long>& a, long long t, int i) {
    if (i >= a.size())
        return false;

    if (a[i] == t)
        return true;

    return linearRecursive(a, t, i + 1);
}

bool binaryIterative(const std::vector<long long>& a, long long t, int left, int right){
    while (left <= right){
        int mid = left + (right - left) / 2;

        if (a[mid] == t){
            return true; 
        }else if (a[mid] < t){
            left = mid + 1; 
        }else {
            right = mid - 1; 
        }
    }
    return false; 
}

bool binaryRecursive(const vector<long long>& a, long long t, int left, int right) {
    if (left > right)
        return false;

    int m = left + (right - left) / 2;
    if (a[m] == t)
        return true;

    if (a[m] < t)
        return binaryRecursive(a, t, m + 1, right);
    else
        return binaryRecursive(a, t, left, m - 1);
}
