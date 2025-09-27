#include <iostream>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<double> linear(double a, double b, double t_curr, double u_curr, int steps)
{
    vector<double> ans(steps);
    ans[0] = t_curr;
    for (int i = 1; i < steps; i++)
    {
        ans[i] = a * ans[i - 1] + b * u_curr;
    }
    return ans;
}

vector<double> nonlinear(double a, double b, double c, double d, double t_curr, double t_prev, double u_curr, double u_prev, int steps)
{
    vector<double> ans(steps);
    ans[0] = t_prev;
    ans[1] = t_curr;
    for (int i = 2; i < steps; i++)
    {
        ans[i] = a * ans[i - 1] - b * pow(ans[i - 2], 2) + c * u_curr + d * sin(u_prev);
    }
    return ans;
}

int main()
{
    int steps;
    double a, b, c, d, t_curr, t_prev, u_curr, u_prev;
    cin >> a >> b >> c >> d >> t_curr >> t_prev >> u_curr >> u_prev >> steps;
    vector<double> temp(steps);
    temp = linear(a, b, t_curr, u_curr, steps);
    cout << "Linear::\n";
    for (auto i : temp)
    {
        cout << i << endl;
    }
    temp = nonlinear(a, b, c, d, t_curr, t_prev, u_curr, u_prev, steps);
    cout << "Nonlinear::\n";
    for (auto i : temp)
    {
        cout << i << endl;
    }
}