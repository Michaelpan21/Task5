#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    int **Mass;
    int Lines;



    srand(time(0));


    cout << endl << " > Type variety of Lines and Columns: ";
    cin >> Lines;


    cout << endl << endl;

    Mass = new int *[Lines];

    for(int i = 0 ; i < Lines ; i++){ Mass[i] = new int[Lines]; }



    for(int i = 0 ; i < Lines ; i++){
         for(int j = 0 ; j < Lines ; j++){

            Mass[i][j] = rand() % 20;

         }
    }



    for(int i = 0 ; i < Lines ; i++){
         for(int j = 0 ; j < Lines ; j++){

            if(j == 0) cout << endl;

            printf(" %2d ", Mass[i][j]);

         }
    }

    ofstream fout("Pankov1623.txt");

    fout << " Basic Array : " << endl;

    for(int i = 0 ; i < Lines ; i++){
         for(int j = 0 ; j < Lines ; j++){

            if(j == 0) fout << endl;
            fout << setw(3) << Mass[i][j];

         }
    }

    fout.close();


    cout << endl << endl;

    int M = Lines - 1;
    int copy_1;

    int half_lines;

    if(Lines % 2 == 0) half_lines = Lines / 2;
    else half_lines = (Lines - 1) / 2;


    for(int i = 0, j = 0; i < half_lines ; i++,j++){



            copy_1 = Mass[i][j];

            Mass[i][j] = Mass[i][M];

            Mass[i][M] = Mass[M][M];

            Mass[M][M] = Mass[M][j];

            Mass[M][j] = copy_1;


         M--;
    }


    for(int i = 0 ; i < Lines ; i++){
         for(int j = 0 ; j < Lines ; j++){

            if(j == 0) cout << endl;

            printf(" %2d ", Mass[i][j]);
         }
    }



    fout.open("Pankov1623.txt", ios_base::app);

    fout << endl << endl << " New Array : " << endl;

    for(int i = 0 ; i < Lines ; i++){
         for(int j = 0 ; j < Lines ; j++){

            if(j == 0) fout << endl;
            fout << setw(3) << Mass[i][j];

         }
    }

    fout.close();


    return 0;
}

