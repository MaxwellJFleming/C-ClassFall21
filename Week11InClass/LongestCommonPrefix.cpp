#include <iostream>
#include <vector>
#include <string>

int FindShortestString(const std::vector<std::string> *input)
{
    int ret = 0;
    for (int i = 0; i < input->size(); i++){
        if (input->at(i).length() > ret){
            ret = input->at(i).length();
        }
    }
    return ret;
}

std::string LongestCommonPrefix(const std::vector<std::string> *input)
{
    
    std::string *prefix;
    
    for(int i = 0; i < FindShortestString(input); i++)
    {
        for(std::size_t j = 1; j < input->size(); j++)
        {
            if (input->at(j)[i] != input->at(j-1)[i])
            {
                return prefix;
            }
        }
        prefix += input->at(0)[i];
    }

    return prefix;
}

int main(){

    std::vector<std::string> *test = new std::vector<std::string>{"dog", "doghouse", "dog park"};

    std::cout << LongestCommonPrefix(test) << std::endl;

    return 0;
}