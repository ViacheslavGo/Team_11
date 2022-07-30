#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <cmath>
using namespace std;

int main()
{
    double Dmax, Dmin;  //ввод Dmax и Dmin
    cin >> Dmin >> Dmax;

    int number_files = 2;
    string base_file_name = "files/data- (#).txt";
    for (int i = 1; i <= number_files; ++i)
    {
        string file_name = base_file_name;
        file_name.replace(13, 1, to_string(i));

        ifstream fin (file_name);
        

        if (!fin.is_open())
        {
             cerr << "Unable to open file\n";
             return(1);
        } 
        

        vector <vector <double>> all_points;    //матрица из файла
        int const col = 8;  // кол-во столбцов в файле
        vector <double> vtmp(col);
         
        fin.ignore(numeric_limits <streamsize>::max(), '\n'); // отбрасываем первую строку файла
    
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
            all_points.push_back(vtmp);
        }
        //                                                      создание новой матрицы только с подходщими значениями

        vector <vector <double>> points;    // новая матрица

        for (int i = 0; i < all_points.size(); i++)
            if (all_points[i][1] < ((Dmax-Dmin)*(Dmax-Dmin))/2 && all_points[i][5] < 2) points.push_back(all_points[i]);

        //                                                     (построение матрицы расстояний) подпункт c
    
        int const M = points.size();  // M - размер матрицы

        double** matr_d = new double*[M];
        matr_d[0] = new double [M * M];
        for (int i = 1; i < M; ++i)
            matr_d[i] = matr_d[i - 1] + M;

        double** matr_sv = new double*[M];
        matr_sv[0] = new double [M * M];
        for (int i = 1; i < M; ++i)
            matr_sv[i] = matr_sv[i - 1] + M;

        for (int i = 0; i < M; ++i)
            for (int j = i; j < M; ++j)
                { 
                    double dist = sqrt( pow ((points[i][2]-points[j][2]), 2) + pow((points[i][3]-points[j][3]), 2) );
                    matr_d[i][j] = dist;
                    matr_d[j][i] = dist;
                    if (dist < Dmax && dist > Dmin)
                    {
                        matr_sv[i][j] = 1;
                        matr_sv[j][i] = 1;
                    }
                    else 
                    {
                        matr_sv[i][j] = 0;
                        matr_sv[j][i] = 0;
                    }
                }

        //                      вывод матрицы расстояний
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                cout<<matr_d[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        //                      вывод матрицы связей
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                cout<<matr_sv[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n\n\n";
    }
}