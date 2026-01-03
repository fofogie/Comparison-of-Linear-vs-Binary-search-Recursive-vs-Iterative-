#ifndef SEARCHALGORITHMS_H
#define SEARCHALGORITHMS_H

#include <vector>

bool linearIterative(const std::vector<long long>& a, long long t);
bool linearRecursive(const std::vector<long long>& a, long long t, int i);
bool binaryIterative(const std::vector<long long>& a, long long t, int left, int right);
bool binaryRecursive(const std::vector<long long>& a, long long t, int left, int right);

#endif
