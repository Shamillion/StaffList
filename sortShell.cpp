#include "worker.h"

void Worker::sortShell()
{
    auto &arr{m_personal};
    int n{static_cast<int>(arr.size())};
    int d = n / 2;                        //Длина промежутков между элементами

    while (d > 0)
    {
        for (int iii{0}; iii < n - d; ++iii)
        {
            int jjj{iii};
            while (jjj >= 0 && comp(arr.at(jjj+d), arr.at(jjj)))
            {
                 data temp = arr.at(jjj);
                 arr.at(jjj) = arr.at(jjj + d);
                 arr.at(jjj + d) = temp;

                 --jjj;
            }
        }
        d = d/2;
    }
}
