#include <stdio.h>

struct Salary {
    float basic, bonus, deduction;
};

struct Employee {
    int id;
    char name[50];
    struct Salary sal;
};

float calcNetSalary(struct Salary s) {
    return s.basic + s.bonus - s.deduction;
}

void display(struct Employee e) {
    printf("\n-----------------------------------\n");
    printf("Employee ID: %d\n", e.id);
    printf("Name: %s\n", e.name);
    printf("Basic Pay: %.2f\nBonus: %.2f\nDeduction: %.2f\n", 
           e.sal.basic, e.sal.bonus, e.sal.deduction);
    printf("Net Salary: %.2f\n", calcNetSalary(e.sal));
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Basic Pay: ");
        scanf("%f", &emp[i].sal.basic);
        printf("Bonus: ");
        scanf("%f",&emp[i].sal.bonus);
        printf("Deduction: ");
        scanf("%f",&emp[i].sal.deduction);
    }

    printf("\n===== Employee Salary Details =====\n");
    for (int i = 0; i < n; i++)
        display(emp[i]);

    return 0;
}

