#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

//DONE...

using namespace std;

const int N = 10;

int n, T;
int Q[N][N];
int M[N][N];
int scan[N * N];
long double D[N][N];
int W[N][N];

void PrintOut(int a[][10])
{
    for (int i = 1; i <= 8; i ++ )
    {
        for (int j = 1; j <= 8; j ++ )
            cout << a[i][j] << ' ';
        cout << endl;
    }
}

void PrintOutD(long double a[][10])
{
    for (int i = 1; i <= 8; i ++ )
    {
        for (int j = 1; j <= 8; j ++ )
            cout << a[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
}

void FillIn(int a[], int M[][10])
{
    M[1][1] = a[1];
    int tmp[16] = {0, 0, 1, 3, 6, 10, 15, 21, 28, 36, 43, 49, 54, 58, 61, 63};

    for (int i = 1; i <= 8; i ++ )
        for (int j = 1; j <= 8; j ++ )
        {
            int k = i + j - 1;
            if (k >= 1 && k <= 8)
            {
                if (k % 2 == 1)
                {
                    int num = tmp[k];
                    if (a[num + j]) M[i][j] = a[num + j];
                }
                else
                {
                    int num = tmp[k];
                    if (a[num + i]) M[i][j] = a[num + i];
                }
            }
            else
            {
                if (k % 2 == 1)
                {
                    int num = tmp[k];
                    int cf = k - 8;
                    if (a[num + j - cf]) M[i][j] = a[num + j - cf];
                }
                else
                {
                    int num = tmp[k];
                    int cf = k - 8;
                    if (a[num + i - cf]) M[i][j] = a[num + i - cf];
                }
            }
        }
}

void Quntify(int Q[][10], int M[][10])
{
    for (int i = 1; i <= 8; i ++ )
        for (int j = 1; j <= 8; j ++ )
            M[i][j] *= Q[i][j];
}

void DisCreetCos(int M[][10], long double D[][10])
{
    for (int i = 1; i <= 8; i ++ )
        for (int j = 1; j <= 8; j ++ )
        {
            long double sum = 0;
            for (int u = 1; u <= 8; u ++ )
                for (int v = 1; v <= 8; v ++ )
                {
                    long double au = 1, av = 1;
                    if (u == 1) au = sqrt(0.5);
                    if (v == 1) av = sqrt(0.5);

                    long double pi = acos(-1);
                    long double Cos1 = cos(pi * 1.0 / 8 * ((i - 1) + 0.5) * (u - 1));
                    long double Cos2 = cos(pi * 1.0 / 8 * ((j - 1) + 0.5) * (v - 1));
                    sum += M[u][v] * au * av * Cos1 * Cos2;
                }
            D[i][j] += sum / 4;
        }
}

void FinalExec(int W[][10], long double D[][10])
{
    for (int i = 1; i <= 8; i ++ )
        for (int j = 1; j <= 8; j ++ )
        {
            int Res = min((int)(D[i][j] + 128 + 0.5), 255);
            Res = max(Res, 0);
            W[i][j] = Res;
        }
}

int main()
{
    for (int i = 1; i <= 8; i ++ )
        for (int j = 1; j <= 8; j ++ )
            cin >> Q[i][j];

    cin >> n >> T;

    for (int i = 1; i <= n; i ++ ) cin >> scan[i];
    FillIn(scan, M);
    if (T == 0) PrintOut(M);

    Quntify(Q, M);
    if (T == 1) PrintOut(M);

    DisCreetCos(M, D); 
    // PrintOutD(D);
    
    FinalExec(W, D);
    if (T == 2) PrintOut(W);

    return 0;
}