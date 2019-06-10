#include "worker.h"

bool Worker::comp (const data &a, const data &b)
{
    switch (m_sort_choice)
    {
        case '1': return a.id         < b.id;
        case '2': return a.surname    < b.surname;
        case '3': return a.name       < b.name;
        case '4': return a.patronymic < b.patronymic;
        case '5': return a.post       < b.post;
        case '6': return a.hrPay      < b.hrPay;
        case '7': return a.hours      < b.hours;
        case '8': return a.hours * a.hrPay < b.hours * b.hrPay;
        default:  break;
    }
    return 0;
}
