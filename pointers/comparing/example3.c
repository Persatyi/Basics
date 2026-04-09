// Практичний приклад порівняння вказівників на функції
#include <stdio.h>

// Функції для роботи з інвентарем
void sortParts() {
    printf("Sorting parts ...\n");
}

void calcSum() {
    printf("Calculating sum...\n");
}

void displayArray() {
    printf("Displaying array...\n");
}

void logOperation() { 
    printf("Logging operation...\n"); 
}

void findExpensive() { 
    printf("Finding most expensive...\n"); 
}

void findCheapest() {
     printf("Finding cheapest...\n"); 
}

typedef void (*Operation)();

// Операція 1: сортувати, підрахувати, вивести
Operation workflow1[] = {
    sortParts,
    calcSum,
    logOperation, // логування
    displayArray,
    NULL // кінець масиву
};

// Операція 2: вивести, знайти найдорожче/найдешевше
Operation workflow2[] = {
    displayArray,
    logOperation,  // логування (теж присутнє!)
    findExpensive,
    findCheapest,
    NULL
};

// Функція для видалення певної операції з робочого процесу
void removeOperation(Operation *workflow, Operation toRemove) {
    int i = 0, j = 0;
    while(workflow[i] != NULL) {
        if(workflow[i] != toRemove) { // ОСЬ ТУТ ПОРІВНЮЄМО!
            workflow[j++] = workflow[i];
        }
        i++;
    }
    workflow[j] = NULL;
}

// Виконати всі операції
void executeWorkflow(Operation *workflow) {
    for (int i = 0; workflow[i] != NULL; i++) {
        workflow[i]();
    }
}

int main() {
    printf("=== Workflow 1 (з логуванням) ===\n");
    executeWorkflow(workflow1);
    
    printf("\n=== Видаляємо логування ===\n");
    removeOperation(workflow1, logOperation);
    
    printf("\n=== Workflow 1 (без логування) ===\n");
    executeWorkflow(workflow1);
    
    return 0;
}