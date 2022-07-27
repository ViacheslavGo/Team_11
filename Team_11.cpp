#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <cmath>
 using namespace std;
int main()
{
    ifstream fin("C:/Users/admin/Documents/Programming/CPP/Practice/Team _11/files/data- (1) little.txt");
    if (!fin.is_open())
    {
        cerr << "Unable to open file\n";
        return(1);
    }
    vector <vector <double>> points;    //вектор из векторов
    int const col = 8;  // кол-во столбцов в файле
    vector <double> vtmp(col);
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
 
    /*for (auto const& vct : points) //вывод матрицы
        {
            for (auto const& val : vct)
            {
                cout << val << "  ";
            }
            cout <<"\n";
        } */

    double Dmax, Dmin;  //ввод Dmax и Dmin
    cin >> Dmax >> Dmin;

    auto it = points.begin();   //поиск и удаление неподходящих элементов (подпункт b)
    while (it != points.end())
    {
        if (((*it)[1] >= (((Dmax+Dmin)/2)*((Dmax+Dmin)/2))/8) || (*it)[5] >= 2) points.erase(it);
        ++it;             
    }

    //                                                     (построение матрицы связей) подпункт c
    
    int const M = points.size();  // M - размер матрицы

    vector <vector <double>> matr_d;    //вектор из векторов
    int const matr_col = points.size();  // кол-во столбцов в матрице
    vector <double> matr_vtmp(matr_col);
    
    auto it1 = points.begin();
    it = points.begin();
    int i = 0;
    double d = 0;

    while (true)
    {
        for (auto val : matr_vtmp)
        {
            d = ((*it)[2]-(*it1)[2])*((*it1)[2]-(*it)[2]) + ((*it)[3]-(*it1)[3])*((*it1)[3]-(*it)[3]);
            if (d > Dmax || d < Dmin) val = 1.0;
            i++;
        }
        if (i > points.size()*points.size())
        {
            break;
        }
        matr_d.push_back(matr_vtmp);
        it1++;
        it++;
    }


    
    






    for (auto const& vct : matr_d) //вывод матрицы
        {
            for (auto const& val : vct)
            {
                cout << val << "  ";
            }
            cout <<"\n";
        }
    cout<<M;
}











// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
