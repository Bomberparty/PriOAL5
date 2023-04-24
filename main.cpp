#include "function.h"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>

int main(int argc,const char** argv) {
    if (argc != 3) {
        std::cerr << "Использование: " << argv[0] << " <число> <последовательность>\n";
        return 1;
    }
    

    for (int i = 1; i <= 2; ++i) { 
        for (const char* p = argv[i]; *p != '\0'; ++p) {
            if (!std::isdigit(*p)) {
                std::cerr << "Агрумент " << i << " должен быть целым числом!\n";
                return 1;
            }
        }
    }

    int num = std::atoi(argv[1]); 
    int sequence = std::atoi(argv[2]);

    if (num <= 0 || sequence <= 0) { 
        std::cerr << "число и последовательность должны быть положительными!\n";
        return 1;
    }
    if (sequence > num) { 
        std::cerr << "Последовательность должна быть меньше или равна числу!\n";
        return 1;
    }
    bool result = check_bit_sequence(num, sequence);
    if (result) {
        std::cout << "Битовая последовательность " << sequence << " присутствует в числе " << num << std::endl;
    } else {
        std::cout << "Битовая последовательность " << sequence << " отсутствует в числе " << num << std::endl;
    }
    return 0;
}