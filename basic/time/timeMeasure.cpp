#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    auto start_time = chrono::steady_clock::now();

    auto end_time = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end_time - start_time;
    cout << "--- " << elapsed_seconds.count() << " seconds ---" << endl;

    return 0;
}