#include <fstream>
#include <iostream>
#include <iomanip>

double mapping(double value)
{
    if (value >= 1.0 && value <= 5.0)
    {
        return -1.0 + 3.0*((value-1.0)/4.0);
    }
    else {
        std::cerr << "Il valore non è compreso nell'intervallo [1,5]" << std::endl;
        return 2.0;
    }
}

int main()
{
    std::string fileName = "data.csv";
    std::ifstream ifstr(fileName);
    double value;

    if(ifstr.fail())
    {
        std::cerr << "File does not exist" << std::endl;
        return 1;
    }

    std::ofstream outFile("result.csv");
    outFile << "# N Mean" << std::endl;

    double sumValues = 0;
    unsigned int countVal = 0;
    double mean;

    while (ifstr >> value)
    {
        sumValues += mapping(value);
        countVal++;
        mean = sumValues/countVal;
        outFile << countVal << "  " << std::scientific << std::setprecision(16) << mean << std::endl;
    }

    ifstr.close();
    outFile.close();

    return 0;
}
