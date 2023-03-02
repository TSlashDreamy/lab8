#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <Math.h>
#include <Windows.h>

using namespace std;


class Solution
{
private:
    vector<int> customArray = { -5, 10, 2, 20, 1, 30, 23, 46, 5, -20 };
    vector<int> :: iterator position, minElement, minPos;

public:
    int minimalElement()
    {
        minElement = min_element(customArray.begin(), customArray.end());

        return *minElement;
    }
    auto minimalElementNumber()
    {
        minPos = find(customArray.begin(), customArray.end(), minimalElement());

        return (minPos - customArray.begin() + 1);
    }

    int summOfVectorElements()
    {
        bool pushing = false;
        vector<int> tempArray;

        for (position = customArray.begin(); position != customArray.end(); ++position)
        {
            if (*position < 0) pushing = !pushing;
            if (*position >= 0 && pushing) {
                tempArray.push_back(*position);
            }
        }

        int summOfElements = accumulate(tempArray.begin(), tempArray.end(), 0);

        return summOfElements;
    }

    bool checkInArray(int valueToCheck, vector<int> tempArr)
    {
        for (position = tempArr.begin(); position != tempArr.end(); ++position)
        {
            if (valueToCheck == *position) return true;
        }

        return false;
    }

    void transformArray()
    {
        vector<int> tempArray;

        for (position = customArray.begin(); position != customArray.end(); ++position)
        {
            if (abs(*position) <= 1)
            {
                tempArray.push_back(*position);
            }
        }

        for (int i = 0; i != customArray.size(); i++)
        {
            int temp = customArray[i];
            if (!checkInArray(temp, tempArray))
            {
                tempArray.push_back(temp);
            }
        }

        customArray.erase(customArray.begin(), customArray.end());

        cout << "Changed array: ";
        for (position = tempArray.begin(); position != tempArray.end(); ++position)
        {
            cout << *position << ", ";
            customArray.push_back(*position);
        }
    }

};

int main()
{
    Solution solutionObj;

    cout << "Min element: " << solutionObj.minimalElement() << endl;
    cout << "Position of min element: " << solutionObj.minimalElementNumber() << endl;
    cout << "Summ of vector elements between two negative numbers: " << solutionObj.summOfVectorElements() << endl;
    solutionObj.transformArray();
}
