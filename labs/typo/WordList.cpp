#include "WordList.h"

WordList::WordList(std::istream& stream)
{
    std::string word;
    while(stream >> word)
    {
        bool is_lower = true;
        for(char char_:word)
        {
            if(!islower(char_))
            {
                is_lower = false;
                break;
            }
        }
        if(is_lower)
        {
            mWords.push_back(word);
        }
    }
}

Heap WordList::correct(const std::vector<Point>& points, size_t maxcount, float cutoff) const
{
   return 0; 
}