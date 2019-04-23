/*references:
no skipping white spaces.
http://stackoverflow.com/questions/10946771/effect-of-noskipws-on-cin
*/
#include <iostream>
#include <fstream>
#include <vector>

//change to file location
const std::string earlyFile = "\Users\Byron\Documents\CS_OSU\CS162\Assignments\Lab 7\Sorting\early";
const std::string middleFile = "\Users\Byron\Documents\CS_OSU\CS162\Assignments\Lab 7\Sorting\middle";
const std::string endFile = "\Users\Byron\Documents\CS_OSU\CS162\Assignments\Lab 7\Sorting\end";
const std::string withoutZeroFile = "\Users\Byron\Documents\CS_OSU\CS162\Assignments\Lab 7\Sorting\without";


const std::string earlyFileSorted = "\Users\Byron\Documents\CS_OSU\CS162\Assignments\Lab 7\Sorting\early_sorted";
const std::string middleFileSorted = "\Users\Byron\Documents\CS_OSU\CS162\Assignments\Lab 7\Sorting/middle_sorted";
const std::string endFileSorted = "\Users\Byron\Documents\CS_OSU\CS162\Assignments\Lab 7\Sorting\end_sorted";
const std::string withoutZeroFileSorted = "\Users\Byron\Documents\CS_OSU\CS162\Assignments\Lab 7\Sorting\without_sorted";

// Search
bool linearSearch(int key)
{
    std::vector<std::string> files;

    files.push_back(earlyFile);
    files.push_back(middleFile);
    files.push_back(endFile);
    files.push_back(withoutZeroFile);

    char ch;
    int current = 0;

    int i = 0;

    while (i < 4)
    {
        std::fstream fin(files[i], std::fstream::in);

        while (fin >> std::noskipws >> ch)
        {
            if (ch > '0' && ch < '9')
            {
                current = current * 10 + (ch - '0');
            }
            else if (current == key)
            {
                return true;
            }
            else
            {
                current = 0;
            }
        }
        ++i;
            if (current == key)
            {
                return true;
            }
    }

    return current == key;
}

// Sort
void sortArrayAndWriteToFile(std::vector<int> array, const std::string& fileName)
{
    for (int startIndex = 0; startIndex < array.size(); ++startIndex)
        {
        // smallestIndex is the index of the smallest element
        int smallestIndex = startIndex;

        // Look for smallest element remaining in the array (starting at startIndex+1)
        for (int currentIndex = startIndex + 1; currentIndex < array.size(); ++currentIndex)
            {
            // If the current element is smaller than our previously found smallest
            if (array[currentIndex] < array[smallestIndex])
                // New smallest number for this iteration
                smallestIndex = currentIndex;
            }

        // Swap our start element with our smallest element
        std::swap(array[startIndex], array[smallestIndex]);
        }

    std::fstream fout(fileName, std::fstream::out);

    for(int i = 0; i < array.size(); ++i)
        {
        fout << array[i];
        if (i != array.size() - 1)
        {
            fout << ',';
        }
    }

}

//use this
void selectionSort()
{
    std::vector<std::string> files;
    std::vector<std::string> sortedFiles;


    files.push_back(earlyFile);
    files.push_back(middleFile);
    files.push_back(endFile);
    files.push_back(withoutZeroFile);

    sortedFiles.push_back(earlyFileSorted);
    sortedFiles.push_back(middleFileSorted);
    sortedFiles.push_back(endFileSorted);
    sortedFiles.push_back(withoutZeroFileSorted);


    char ch;
    int i = 0;
    while (i < 4)
        {
        int current = 0;
        std::fstream fin(files[i], std::fstream::in);

        std::vector<int> arrayToSort;

        while (fin >> std::noskipws >> ch)
        {
            if (ch >= '0' && ch <= '9')
            {
                current = current * 10 + (ch - '0');
            }
            else
            {
                arrayToSort.push_back(current);
                current = 0;
            }
        }
        arrayToSort.push_back(current);

        sortArrayAndWriteToFile(arrayToSort, sortedFiles[i]);
        ++i;

    }

}

//Binary Search
bool doBinarySearchInArray(const std::vector<int>& array, int key) {
    int start = 0;
    int end = (int)array.size();
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (key == array[mid])
        {
            return true;
        }
        else if (key < array[mid])
        {
            end = mid - 1;
        }
        else start = mid + 1;
    }
    return false;
}

bool binarySearch(int key)
{
    std::vector<std::string> sortedFiles;

    sortedFiles.push_back(earlyFileSorted);
    sortedFiles.push_back(middleFileSorted);
    sortedFiles.push_back(endFileSorted);
    sortedFiles.push_back(withoutZeroFileSorted);

    char ch;
    int i = 0;
    while (i < 4)
    {
        int current = 0;
        std::fstream fin(sortedFiles[i], std::fstream::in);

        std::vector<int> arrayToSearch;

        while (fin >> std::noskipws >> ch)
        {
            if (ch >= '0' && ch <= '9')
            {
                current = current * 10 + (ch - '0');
            }
            else
            {
                arrayToSearch.push_back(current);
                current = 0;
            }
        }
        arrayToSearch.push_back(current);

        if(doBinarySearchInArray(arrayToSearch, key))
        {
            return true;
        }
        ++i;

    }

    return false;
}

int main(int argc, const char * argv[])
{

    std::cout << linearSearch(0) << std::endl;

    selectionSort();

    std::cout << binarySearch(0) << std::endl;

    return 0;
}
