#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

#define BUCKETS 10
void bucketSort(std::vector<float>& arr, float max, float min)
{
    std::vector<std::list<float>> result;
    result.resize(BUCKETS);
    float divider = (max + 1) / BUCKETS;
    int j = 0;
    for (int i = 0; i < arr.size(); i++) {
        j = floor(arr[i] / divider);
        result[j].push_back( arr[i]);
    }
    for (int i = 0; i < BUCKETS; i++)
        result[i].sort();
    int counter = 0;
    for (int i = 0; i < BUCKETS; i++){
        for (float n: result[i]) {
            arr[counter] = n;
            counter++;
        }
    }
}

int main() {
    char str[255];
    std::cin.getline(str, 255);
    int counter = 0;
    int NumSize = 0;
    float max = 0;
    float min = 100;
    std::vector<float> Numbers;
    std::string current = "";
    while (str[counter] != '\0') {
        if (str[counter] != ' ') {
            NumSize++; counter++;
        }
        else {
            for (int i = counter - NumSize; i < counter; i++) {
                current += str[i];
            }
            Numbers.push_back(std::stof(current));
            if (std::stof(current) > max)
            {
                max = std::stof(current);
            }
            if (std::stof(current) < min)
            {
                min = std::stof(current);
            }
            current = "";
            NumSize = 0;
            counter++;
        }
    }
    for (int i = counter - NumSize; i < counter; i++) {
        current += str[i];
    }
    Numbers.push_back(std::stoi(current));
    current = "";
    bucketSort(Numbers,max,min);
    for (int i = 0; i < Numbers.size(); i++)
        std::cout << Numbers[i] << " ";
    return 0;
}

