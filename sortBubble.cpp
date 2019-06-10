#include "worker.h"

void Worker::sortBubble()
{
    std::vector<data> &arr = m_personal;

    for (unsigned int iii = 0; iii < arr.size() - 1; iii++) {
        for (unsigned int jjj = 0; jjj < arr.size() - iii - 1; jjj++) {
            if (comp(arr.at(jjj+1), arr.at(jjj)))
                std::swap(arr.at(jjj), arr.at(jjj+1));
        }
    }
}
