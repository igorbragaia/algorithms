/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id)
    {
        sort(employees.begin(), employees.end(), criteria);
        this->employees = employees;
        return sum(find(id));
    }

private:
    vector<Employee*> employees;
    int sum(Employee* employee)
    {
        int response = employee->importance;
        for (int i = 0; i < employee->subordinates.size(); i++)
            response += sum(find(employee->subordinates[i]));
        return response;
    }

    static bool criteria(Employee*& a, Employee*& b)
    {
        return a->id < b->id;
    }

    Employee* find(int id)
    {
        int begin = 0, end = this->employees.size() - 1, middle;
        Employee* mid;
        while (begin <= end) {
            middle = (begin + end) / 2;
            mid = this->employees[middle];
            if (mid->id == id)
                return mid;
            if (mid->id < id)
                begin = middle + 1;
            else
                end = middle - 1;
        }
    }
};
