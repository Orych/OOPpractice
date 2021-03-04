
#include <iostream>
#include <fstream>
#include <string>
#include <optional>
#include "CopyFile.h"

struct Args
{
    std::string inputFileName;
    std::string outputFileName;
};

std::optional <Args> ParseArgs(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: CopyFile.exe <input file name> <output file name>\n";
        return std::nullopt;
    }

    Args args;
    args.inputFileName = argv[1];
    args.outputFileName = argv[2];

    return args;
}

void CopyStreams(std::ifstream& input, std::ofstream& output)
{
    char ch;
    while (input.get(ch))
    {
        if (!output.put(ch))
        {
            break;
        }
    }
}

int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);

    if (!args)
    {
        return 1;
    }

    std::ifstream input;
    input.open(args->inputFileName);

    if (!input.is_open())
    {
        std::cout << "Failed to open '" << args->inputFileName << "' for reading\n";
        return 1;
    }

    std::ofstream output;
    output.open(args->outputFileName);

    if (!output.is_open())
    {
        std::cout << "Failed to open '" << args->outputFileName << "' for writing\n";
        return 1;
    }

    CopyStreams(input, output);

    if (input.bad())
    {
        std::cout << "Falied to read data from input file\n";
        return 1;
    }

    if (!output.flush())
    {
        std::cout << "Failed to write data to output file\n";
        return 1;
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
