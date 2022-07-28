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

    int number_files = 303;
    string base_file_name = "files/data- (#) .txt";
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
        

        vector <vector <double>> points;    //матрица из файла
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
            points.push_back(vtmp);
        }

        auto it = points.begin();   //поиск и удаление неподходящих элементов (подпункт b)
        while (it != points.end())
        {
           if (((*it)[1] >= (((Dmax+Dmin)/2)*((Dmax+Dmin)/2))/8) || (*it)[5] >= 2) points.erase(it);
          ++it;             
        }

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
                    double dist = sqrt((points[i][2]-points[j][2])*(points[i][2]-points[j][2]) + (points[j][3]-points[i][3])*(points[i][3]-points[j][3]));
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
            
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                cout<<matr_d[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}