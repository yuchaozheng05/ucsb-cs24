#include "WordList.h"
#include <cmath>
#include <cctype>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
WordList::WordList(std::istream& stream)
{
    std::string word;
    while(stream >> word)
    {
        bool is_lower = true;
        for(size_t i =0; i<word.size(); i++)
        {
            if(!islower(word[i]))
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
   Heap heap(maxcount);
   for(const std::string& word: mWords)
   {
    if(word.length() == points.size())
    {
        std::vector<Point> loc;
        for(char c:word)
        {
            loc.push_back(QWERTY[c-'a']);
        }
        float score = 0.0;
        for(size_t i =0; i<points.size();i++)
        {
            float x = points[i].x - loc[i].x;
            float y = points[i].y - loc[i].y;
            float distant = std::sqrt(x*x + y*y);
            score += 1.0 / (10.0 * distant * distant +1.0);
        }
        float score_ = (score/points.size());
        if(score_>=cutoff)
        {
            if(heap.count()<maxcount)
            {
                heap.push(word,score_);
            }
        }
    }
   }
   return heap;
}