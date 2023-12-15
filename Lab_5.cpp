#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    std::vector<int> list1{ 1, 5, 7, 8, 10, 20 };

    std::vector<int> list2{ 2, 3, 4, 6, 9, 11, 12, 15 };

    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    std::vector<int> result;
    result.reserve(list1.size() + list2.size());
    result.insert(result.end(), list1.begin(), list1.end());
    result.insert(result.end(), list2.begin(), list2.end());

    std::sort(result.begin(), result.end());

    cout << "Merging list: ";

    for (int i : result) {
        std::cout << i << ' ';
    }
    cout << endl;

    int max_elem = *max_element(list1.begin(), list1.end());
    int min_elem = *min_element(list1.begin(), list1.end());

    auto max_idx = find(list1.cbegin(), list1.cend(), max_elem);
    auto min_idx = find(list1.cbegin(), list1.cend(), min_elem);

    swap(list1[max_idx - list1.cbegin()], list1[min_idx - list1.cbegin()]);

    cout << "The permutation: ";

    for (int i = 0; i < list1.size(); i++)
    {
        cout << list1[i] << " ";
    }

    return 0;

}