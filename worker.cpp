#include "worker.h"

void Worker::printHeader()
{
    std::cout << "Worker data \n";
    std::cout << std::setw(4)  << "ID"    << std::setw(12) << "Surname"    <<
                 std::setw(12) << "Name"  << std::setw(12) << "Patronymic" <<
                 std::setw(12) << "Post"  << std::setw(8)  << "h/pay"      <<
                 std::setw(6)  << "Hours" << std::setw(10) << "Salary" << "\n";
    for (int iii{0}; iii<77; ++iii) std::cout << "-";
    std::cout << "\n";
}

void Worker::printLine(const data& elem)
{
    std::cout << std::fixed    << std::setprecision(2);
    std::cout << std::setw(4)  << elem.id                    <<
                 std::setw(12) << getString(elem.surname)    <<
                 std::setw(12) << getString(elem.name)       <<
                 std::setw(12) << getString(elem.patronymic) <<
                 std::setw(12) << getString(elem.post)       <<
                 std::setw(8)  << elem.hrPay                 <<
                 std::setw(6)  << elem.hours                 <<
                 std::setw(11) << elem.hrPay*elem.hours << "\n";
}


Worker::Worker()
{
     do
     {
         menu();
     }
     while (m_choice != 'Q');
}

void Worker::menu()
{
    std::cout << "Select an action: \n";
    std::cout << "N New worker.\n";
    std::cout << "E Edit data.\n";
    std::cout << "F Find worker.\n";
    std::cout << "D Delete data.\n";
    std::cout << "S Save to file.\n";
    std::cout << "R Load from file.\n";
    std::cout << "V Show all workers.\n";
    std::cout << "C Sort data.\n";
    std::cout << "Q Quit.\n";

    std::cin >> m_choice;
    m_choice = toupper(m_choice);
    std::cout << "\n";
    switch (m_choice)
    {
        case 'N': newWorker(); break;
        case 'R': loadFromFile(); break;
        case 'Q': quit(); return;
        default:  break;
    }

    if (m_personal.empty())
    {
        std::cout << "No employees found! Please, enter data.\n\n";
        return;
    }

    switch (m_choice)
    {
        case 'E': editData(); break;
        case 'F': findWorker(); break;
        case 'D': deleteData(); break;
        case 'S': saveToFile(); break;
        case 'V': showAll(); break;
        case 'C': sortData(); break;
        default:  break;
    }
}

void Worker::newWorker()
{
    std::cout << "Enter data:\n";
    setNumber("id", m_data.id);
    std::cout << "Surname: ";
    std::cin  >> m_data.surname;
    std::cout << "Name: ";
    std::cin  >> m_data.name;
    std::cout << "Patronymic: ";
    std::cin  >> m_data.patronymic;
    std::cout << "Post: ";
    std::cin  >> m_data.post;
    setNumber("Hr. pay", m_data.hrPay);
    setNumber("Hours", m_data.hours);
    std::cout << "\n";
    m_personal.push_back(m_data);
    std::cout << "New worker added!\n";
}

template <typename T>
void Worker::setNumber(std::string str, T& num)
{
    while(1)
    {
        std::cout << str << ": ";
        std::cin  >> num;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout << "Please, enter the number.\n";
        }
        else
        {
            std::cin.ignore(32767,'\n');
            break;
        }
    }
}

std::string Worker::getString(const std::string& str)
{
    std::string temp{str};
    if (str.length()>11)
    {
        temp = str.substr(0, 10);
        temp += ".";
    }
    return temp;

}

void Worker::editData()
{
    std::cout << "Please, enter the ID line to editing: ";
    int num;
    std::cin >> num;
    bool flag{0};
    for (auto& elem : m_personal)
    {
        if (num == elem.id)
        {
            flag = 1;
            char temp;
            while (1)
            {
                printHeader();
                printLine(elem);
                std::cout << "\n";
                std::cout << "    - Press 1 to edit ID \n"         <<
                             "    - Press 2 to edit Surname \n"    <<
                             "    - Press 3 to edit Name \n"       <<
                             "    - Press 4 to edit Patronymic \n" <<
                             "    - Press 5 to edit Post \n"       <<
                             "    - Press 6 to edit Hr. pay \n"    <<
                             "    - Press 7 to edit Hours \n"      <<
                             "    - Press q to Quit \n";


                std::cin >> temp;
                switch(temp)
                {
                    case '1':
                        std::cout << "ID is " << elem.id <<
                                     "\nEnter a new ID: ";
                        std::cin >> elem.id;
                        break;
                    case '2':
                        std::cout << "Surname is " << elem.surname <<
                                     "\nEnter a new Surname: ";
                        std::cin >> elem.surname;
                        break;
                    case '3':
                        std::cout << "Name is " << elem.name <<
                                     "\nEnter a new Name: ";
                        std::cin >> elem.name;
                        break;
                    case '4':
                        std::cout << "Patronymic is " << elem.patronymic <<
                                     "\nEnter a new Patronymic: ";
                        std::cin >> elem.patronymic;
                        break;
                    case '5':
                        std::cout << "Post is " << elem.post <<
                                     "\nEnter a new Post: ";
                        std::cin >> elem.post;
                        break;
                    case '6':
                        std::cout << "Hr. pay is " << elem.hrPay <<
                                     "\nEnter a new Hr. pay: ";
                        std::cin >> elem.hrPay;
                        break;
                    case '7':
                        std::cout << "Hours is " << elem.hours <<
                                     "\nEnter a new Hours: ";
                        std::cin >> elem.hours;
                        break;
                    default : break;
                }
                if (temp == 'Q' || temp == 'q') break;
            }
            std::cout << "Do you want to continue the search? (Y/N)";
            char key;
            std::cin >> key;
            if (key == 'N' || key == 'n') break;
            flag = 0;
        }
    }
    if (!flag) std::cout << "ID is not found.\n\n";
}

void Worker::findWorker()
{
    std::cout << "Please, enter data for search: ";
    std::string keyword;
    std::cin >> keyword;
    bool flag{1};
    for (const auto& elem : m_personal)
    {
        if ( keyword == std::to_string(elem.id) ||
             keyword == elem.surname ||
             keyword == elem.name ||
             keyword == elem.patronymic ||
             keyword == elem.post ||
             keyword == std::to_string(static_cast<int>(elem.hrPay)) ||
             keyword == std::to_string(elem.hours) ||
             keyword == std::to_string(static_cast<int>(elem.hrPay*elem.hours))
           )
        {
            if (flag) printHeader();
            printLine(elem);
            flag = 0;
        }
    }
    if (flag) std::cout << "No matches found.\n";
    std::cout << "\n";
}

void Worker::deleteData()
{
    std::cout << "Please, enter \"-1\" to delete all data or enter the ID line to delete: ";
    int num;
    std::cin >> num;
    if (num==-1)
    {
        std::cout << "Are you sure you want to delete ALL the data? (Y/N)";
        char key;
        std::cin >> key;
        if (key == 'Y' || key == 'y')
        {
            m_personal.clear();
            std::cout << "All data is deleted\n\n";
        }
        return;
    }
    bool flag{0};
    for (unsigned int iii{0}; iii<m_personal.size(); )
    {
        if (num == m_personal.at(iii).id)
        {
            flag = 1;
            m_personal.erase(m_personal.begin()+iii);
            std::cout << "Data deleted\n";
            std::cout << "Do you want to continue the search? (Y/N)";
            char key;
            std::cin >> key;
            if (key == 'N' || key == 'n') break;
            flag = 0;
            continue;
        }
        ++iii;
    }
    if (!flag) std::cout << "ID is not found.\n\n";
}

void Worker::showAll()
{
    //std::cout << "\n";
    printHeader();
    for (const auto& w : m_personal)
        printLine(w);
    std::cout << "\n";
}

void Worker::saveToFile()
{
    std::cout << "Please, enter the filename for save data: ";
    std::string filename;
    std::cin >> filename;
    std::ofstream out;

    char choice;
    while (1)
    {
        std::cout << "If you want \n" <<
                 "   -add file - press 1\n" <<
                 "   -overwrite the file " <<
                      "(!this will erase all old data!) - press 2\n" <<
                 "   - For exit press Q\n";

        std::cin >> choice;

        switch (choice)
        {
            case 'q': return;
            case 'Q': return;
            case '1': out.open(filename, std::ios::app);
                      break;
            case '2': out.open(filename);
                      break;
            default : break;
        }
        if (choice == '1' || choice == '2') break;
    }

    if (out.is_open())
    {
      if (choice == '2')
      {
            out << "Worker data \n";
            out << std::setw(4)  << "ID"    << std::setw(12) << "Surname"    <<
                         std::setw(10) << "Name"  << std::setw(12) << "Patronymic" <<
                         std::setw(14) << "Post"  << std::setw(8)  << "h/pay"      <<
                         std::setw(6)  << "Hours" << std::setw(10) << "Salary" << "\n";
            for (int iii{0}; iii<77; ++iii) out << "-";
            out << "\n";
      }
      for (const auto& w : m_personal)
        out << "  " << w.id    << "  " << w.surname       <<
               "  " << w.name  << "  " << w.patronymic    <<
               "  " << w.post  << "  " << w.hrPay         <<
               "  " << w.hours << "  " << w.hrPay*w.hours << "\n";

    }
    out.close();
    std::cout << "The save was completed successfully.\n\n";
}

void Worker::loadFromFile()
{
    std::ifstream in;
    std::string filename;
    while (1)
    {
        std::cout << "Please, enter the filename for load: ";
        std::cin >> filename;
        in.open(filename);
        if (!in.is_open())
        {
            std::cout << "File is '" << filename << "' is not found!\n";
            in.close();
        }
        else
        {
            std::string temp;
            std::getline(in, temp);
            if (temp != "Worker data " )
            {
                std::cout << "The file can not be read. " <<
                             "Please select the data file for this programm.\n";
                in.close();
            } else break;
        }
    }

    std::string line;
    int count{0};

    while (std::getline(in, line))
    {
        int         id;
        std::string surname;
        std::string name;
        std::string patronymic;
        std::string post{"none"};
        double      hrPay;
        int         hours;

        if (count>0)
        {
            in >> id >> surname >> name >> patronymic >>
                  post >> hrPay >> hours;
            if (post != "none")
            {
                    m_personal.push_back(m_data = {id,   surname, name, patronymic,
                                         post, hrPay,   hours});
            }
        }
        ++count;
    }
    in.close();
    std::cout << "\n";
    std::cout << "The load was completed successfully.\n\n";
}

void Worker::quit()
{
    if (!m_personal.empty())
    {
        while (1)
        {
            std::cout << "Do you want save from exit? Y/N\n";
            char choice;
            std::cin >> choice;
            if(toupper(choice)=='Y')
            {
                saveToFile();
                return;
            }
            else if(toupper(choice)=='N') return;
        }
    }
}

char Worker::m_sort_choice = '0';
