#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
 using namespace std;
int main()
{
    ifstream fin("C:/Users/admin/Documents/Programming/CPP/Practice/Team _11/files/data- (1).txt");
    if (!fin.is_open())
    {
        cerr << "Unable to open file\n";
        return(1);
    }
    vector <vector <double>> points;
    int const col = 8; // кол-во столбцов в файле
    vector <double> vtmp(col); //вектор из векторов
    for (int i = 0; i < 1; ++i) // отбрасываем первую строку файла
    {
        fin.ignore(numeric_limits <streamsize>::max(), '\n');
    }
    
    while (true)
    {
        for (auto& val : vtmp)
        {
            fin >> val;
        }
        if (!fin)
        {
            break;
        }
        points.push_back(vtmp);
    }
 
    for (auto const& vct : points)
    {
        for (auto const& val : vct)
        {
            cout << val << "  ";
        }
        cout << endl;
    }
 
 
    //fin.close();
}











// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
