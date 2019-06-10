#include "worker.h"

void Worker::sortData()
{
    std::string myChoice;
    do
    {
        std::cout << "Sort by:\n";
        std::cout << "    - ID.         Press 1 \n" <<
                     "    - Surname.    Press 2 \n" <<
                     "    - Name.       Press 3 \n" <<
                     "    - Patronymic. Press 4 \n" <<
                     "    - Post.       Press 5 \n" <<
                     "    - Hr. pay.    Press 6 \n" <<
                     "    - Hours.      Press 7 \n" <<
                     "    - Salary.     Press 8 \n" <<
                     "    - Press q to Quit     \n"  ;

        std::cin >> m_sort_choice;
        std::cout << "\n";
        switch (m_sort_choice)
        {
            case '1': myChoice = "ID";         break;
            case '2': myChoice = "Surname";    break;
            case '3': myChoice = "Name";       break;
            case '4': myChoice = "Patronymic"; break;
            case '5': myChoice = "Post";       break;
            case '6': myChoice = "Hr. pay";    break;
            case '7': myChoice = "Hours";      break;
            case '8': myChoice = "Salary";     break;
            case 'q': return;
            case 'Q': return;
            default: m_sort_choice = 'w';             break;
        }
    } while (m_sort_choice == 'w');

    char method;
    do
    {
        std::cout << "Choose method by sort:  \n"  <<
                     "    - Press 1 to Quick  \n"  <<
                     "    - Press 2 to Shell  \n"  <<
                     "    - Press 3 to Bubble \n"  <<
                     "    - Press Q to quit   \n"   ;

        std::cin >> method;
        std::cout << "\n";
        switch (method)
        {
            case '1': std::cout << "Sort by " << myChoice <<
                                   ", Method: Quick. \n";
                                   std::sort (m_personal.begin(), m_personal.end(), comp);;
                                   break;
            case '2': std::cout << "Sort by " << myChoice <<
                                   ", Method: Shell. \n";
                                   sortShell();
                                   break;
            case '3': std::cout << "Sort by " << myChoice <<
                                   ", Method: Bubble. \n";
                                   sortBubble();
                                   break;
            case 'q': return;
            case 'Q': return;
            default: method = 'w';                        break;
        }
        std::cout << "\n";
        showAll();

    } while (method == 'w');
}
