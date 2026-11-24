#include <stdbool.h>
#include <stdio.h>

#include "tasks.h"

void menu() {
  int choice;

  while (true) {
    puts("Select a task:");
    puts("1. Task 2");
    puts("2. Task 51");
    puts("3. Task 58");
    puts("4. Task 77");
    puts("5. Task 113");
    puts("6. Task 114");
    puts("7. Task 175");
    puts("8. Task 210");
    puts("9. Task 219");
    puts("10. Task 266");
    puts("11. Exit");
    printf("Enter choice: ");

    scanf_s("%d", &choice);

    printf("\n");

    switch (choice) {
    case 1:
      task2();
      break;
    case 2:
      task51();
      break;
    case 3:
      task58();
      break;
    case 4:
      task77();
      break;
    case 5:
      task113();
      break;
    case 6:
      task114();
      break;
    case 7:
      task175();
      break;
    case 8:
      task210();
      break;
    case 9:
      task219();
      break;
    case 10:
      task266();
      break;
    case 11:
      return;
    default:
      puts("Invalid choice, please try again.");
    }

    printf("\nPress Enter to continue...");
    getchar();
    getchar();
    printf("\n");
  }
}

int main(void) {
  menu();
  return 0;
}
