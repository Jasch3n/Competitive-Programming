#include <vector>
#include <iostream>
using namespace std;


class EmployeeNode{
    public:
        int id;
        vector<int> underlings;
};

int recur(int id, EmployeeNode* employees)
{
    int ans = 0;
    if (employees[id].underlings.empty())
    {
        return 0;
    }
    else
    {
        for (auto &employee : employees[id].underlings) {
            int temp = 1 + recur(employee, employees);
            if (temp > ans) ans = temp;
        }
    }
    return ans;
}


int main(){
    int n; cin >> n;
    EmployeeNode* employees = (EmployeeNode*)malloc(n*sizeof(EmployeeNode));
    vector<int> superiors;

    for (int i = 0; i < n; i ++)
    {
        EmployeeNode newEmployee;
        employees[i] = newEmployee; employees[i].id=i;
    }
    for (int i = 0; i < n; i ++)
    {
        cout << "what";
        int superior = 0; 
        cin >> superior;
        if (superior > 0)
            employees[superior - 1].underlings.push_back(i);
        else
            superiors.push_back(i);
    }
    
    // int ans = 0;
    // for (auto&superior : superiors)
    // {
    //     int temp = recur(superior, employees);
    //     if (temp > ans) ans = temp;
    // }
    // cout << ans + 1;
}