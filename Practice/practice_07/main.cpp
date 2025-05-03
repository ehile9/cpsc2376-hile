
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <iomanip>

class Employee
{
protected:
    std::string name_;
    int id_;
public:
    Employee(std::string name, int id)
        : name_(std::move(name)), id_(id) {}
    virtual ~Employee() = default;

    virtual double calculateSalary() const = 0;
    virtual void displayInfo() const
    {
        std::cout << "ID: " << id_
            << ", Name: " << name_;
    }
};

class SalariedEmployee : public Employee
{
    double monthlySalary_;
public:
    SalariedEmployee(std::string name, int id, double m)
        : Employee(std::move(name), id), monthlySalary_(m) {}
    double calculateSalary() const override
    {
        return monthlySalary_;
    }
    void displayInfo() const override
    {
        Employee::displayInfo();
        std::cout << ", Type: Salaried"
            << ", Monthly Salary: $"
            << std::fixed << std::setprecision(2)
            << monthlySalary_;
    }
};

class HourlyEmployee : public Employee
{
    double hourlyRate_;
    int hoursWorked_;
public:
    HourlyEmployee(std::string name, int id, double rate, int hrs)
        : Employee(std::move(name), id)
        , hourlyRate_(rate)
        , hoursWorked_(hrs) {}
    double calculateSalary() const override
    {
        return hourlyRate_ * hoursWorked_;
    }
    void displayInfo() const override
    {
        Employee::displayInfo();
        std::cout << ", Type: Hourly"
            << ", Hours Worked: " << hoursWorked_
            << ", Hourly Rate: $" << std::fixed << std::setprecision(2)
            << hourlyRate_;
    }
};

class CommissionEmployee : public Employee
{
    double baseSalary_;
    double salesAmount_;
    double commissionRate_;
public:
    CommissionEmployee(std::string name, int id,
        double base, double sales, double rate)
        : Employee(std::move(name), id)
        , baseSalary_(base)
        , salesAmount_(sales)
        , commissionRate_(rate) {}
    double calculateSalary() const override
    {
        return baseSalary_ + (salesAmount_ * commissionRate_);
    }
    void displayInfo() const override
    {
        Employee::displayInfo();
        std::cout << ", Type: Commission"
            << ", Base Salary: $" << std::fixed << std::setprecision(2)
            << baseSalary_
            << ", Sales: $" << salesAmount_
            << ", Commission Rate: " << (commissionRate_ * 100) << "%";
    }
};

int main()
{
    std::ifstream infile("employees.txt");
    if (!infile)
    {
        std::cerr << "Failed to open employees.txt\n";
        return 1;
    }

    std::vector<std::unique_ptr<Employee>> staff;
    std::string type;
    while (infile >> type)
    {
        int id;
        std::string name;
        infile >> id >> name;
        if (type == "Salaried")
        {
            double m;
            infile >> m;
            staff.push_back(std::make_unique<SalariedEmployee>(name, id, m));
        }
        else if (type == "Hourly")
        {
            double rate;
            int hrs;
            infile >> rate >> hrs;
            staff.push_back(std::make_unique<HourlyEmployee>(name, id, rate, hrs));
        }
        else if (type == "Commission")
        {
            double base, sales, rate;
            infile >> base >> sales >> rate;
            staff.push_back(std::make_unique<CommissionEmployee>(name, id, base, sales, rate));
        }
        else
        {
            std::cerr << "Unknown type: " << type << "\n";
            // skip rest of line
            std::string skip;
            std::getline(infile, skip);
        }
    }

    for (const auto& emp : staff)
    {
        emp->displayInfo();
        std::cout << ", Salary: $" << std::fixed << std::setprecision(2)
            << emp->calculateSalary()
            << "\n";
    }

    return 0;
}
