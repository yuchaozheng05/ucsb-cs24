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
      for (const std::string& word : mWords) {
        if (word.length() == points.size()) {
            std::vector<Point> loc;
            for (char c : word) {
                loc.push_back(QWERTY[c - 'a']);
            }

            // Calculate score directly here
            float totalScore = 0.0;
            for (size_t i = 0; i < points.size(); i++) {
                float dx = points[i].x - loc[i].x;
                float dy = points[i].y - loc[i].y;
                float distance = std::sqrt(dx * dx + dy * dy);
                totalScore += 1.0 / (10.0 * distance * distance + 1.0);
            }
            float averageScore = totalScore / points.size();

            if (averageScore >= cutoff) {
                if (heap.count() < maxcount) {
                    heap.push(word, averageScore);
                } 
                else if (averageScore > heap.top().score) {
                    heap.pushpop(word, averageScore);
                }
            }
        }
    }
 
   return heap;
}