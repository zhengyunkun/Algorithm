#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int a[110], q[110];
int date[110];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i ++ ) cin >> q[i]; //依赖关系
    for (int i = 1; i <= m; i ++ ) cin >> a[i]; //每项任务所需的时间

    int maxx = 0;
    for (int i = 1; i <= m; i ++ )
    {
        if (q[i] == 0) date[i] = 1; //如果无依赖关系
        else date[i] = date[q[i]] + a[q[i]]; //存在依赖关系
        maxx = max(maxx, date[i] + a[i] - 1);
    }

    for (int i = 1; i <= m; i ++ ) cout << date[i] << ' ';
    cout << endl;

    if (maxx > n) return 0;

    memset(date, 0x3f, sizeof date);

    for (int i = m; i >= 1; i -- )
    {
        if (date[i] == 0x3f3f3f3f) date[i] = n + 1 - a[i];
        if (q[i] != 0) date[q[i]] = min(date[q[i]], date[i] - a[q[i]]);
    }

    for (int i = 1; i <= m; i ++ ) cout << date[i] << ' ';
    cout << endl;

    return 0;
}