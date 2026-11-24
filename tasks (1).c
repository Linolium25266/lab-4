#include "tasks.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define EPSILON 1e-8
#define MAX_STEPS 100

void task2() {
  int n = 0;
  printf("enter for value n: ");
  scanf_s("%d", &n);

  if (n < 1) {
    puts("n must be a natural number");
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      printf("%d\n", i);
    }
  }
}

void task51() {
  int n = 0;
  printf("enter for value n: ");
  scanf_s("%d", &n);

  if (n < 1) {
    puts("n must be a natural number");
    return;
  }

  long long sum = 0;

  for (int i = n; i <= 2 * n; i++) {
    sum += (long long)i * i;
  }

  printf("Result: %lld\n", sum);
}

void task58() {
  double x = 2;
  double sum = 0;
  double power = x;

  for (int i = 1; i <= 11; i += 2) {
    sum += power / i;
    power *= x * x;
  }

  printf("Result: %.3lf\n", sum);
}

void task77() {
  double length = 4.5;
  double distance = 3;
  double step = 0.2;

  puts("shift      angle (degrees)");

  for (int i = 0; distance + i * step <= length + EPSILON; i++) {
    double shift = i * step;
    double ratio = (distance + shift) / length;

    if (ratio > 1) {
      ratio = 1;
    }

    printf("%.1lf      %.3lf\n", shift, acos(ratio) * 180 / 3.14159265358979);
  }

  puts("the ladder falls");
}

void task113() {
  int k = 0;
  printf("enter for value k: ");
  scanf_s("%d", &k);

  if (k < 3) {
    puts("k must be greater than 2");
    return;
  }

  puts("m      n      a      b      c");

  for (int m = 2; m < k; m++) {
    for (int n = 2; n < m; n++) {
      int a = m * m - n * n;
      int b = 2 * m * n;
      int c = m * m + n * n;
      printf("%-6d %-6d %-6d %-6d %-6d\n", m, n, a, b, c);
    }
  }
}

void task114() {
  int c = 0;
  printf("enter for value C: ");
  scanf_s("%d", &c);

  if (c < 1) {
    puts("C must be a natural number");
    return;
  }

  int coupons[] = {10000, 1000, 500, 100, 50, 10, 5, 1};

  puts("coupon      count");

  for (int i = 0; i < 8; i++) {
    int count = c / coupons[i];
    c %= coupons[i];

    if (count > 0) {
      printf("%d      %d\n", coupons[i], count);
    }
  }
}

void task175() {
  long long product = 1;
  int a = 0;

  puts("enter the sequence of positive integers, finish with 0");

  while (true) {
    scanf_s("%d", &a);

    if (a < 0) {
      puts("the numbers must be positive");
      return;
    }

    if (a == 0) {
      printf("0\n");
      break;
    }

    product *= a;
    printf("%lld\n", product);
  }
}

void task210() {
  double epsilon = 0;
  printf("enter for value epsilon: ");
  scanf_s("%lf", &epsilon);

  if (epsilon <= 0) {
    puts("epsilon must be positive");
    return;
  }

  double previous = 0;
  int n = 1;

  printf("a%d = %.6lf\n", n, previous);

  while (n < MAX_STEPS) {
    double current = atan(previous) + 1;
    n++;
    printf("a%d = %.6lf\n", n, current);

    if (fabs(current - previous) < epsilon) {
      printf("the smallest number: %d\n", n);
      return;
    }

    previous = current;
  }

  puts("the condition isn't met within the step limit");
}

void task219() {
  double x = 0;
  double epsilon = 0;
  printf("enter for value x: ");
  scanf_s("%lf", &x);
  printf("enter for value epsilon: ");
  scanf_s("%lf", &epsilon);

  if (fabs(x) < EPSILON) {
    puts("x must not be zero");
    return;
  }
  if (epsilon <= 0) {
    puts("epsilon must be positive");
    return;
  }

  double previous = x;
  int n = 1;

  printf("a%d = %.6lf\n", n, previous);

  while (n < MAX_STEPS) {
    double current = x / (2 * previous * previous);

    if (!isfinite(current)) {
      puts("the sequence doesn't converge");
      return;
    }

    n++;
    printf("a%d = %.6lf\n", n, current);

    if (fabs(current - previous) < epsilon) {
      printf("the smallest number: %d\n", n);
      return;
    }

    previous = current;
  }

  puts("the condition isn't met within the step limit");
}

void task266() {
  int number = 0;
  printf("enter for value number: ");
  scanf_s("%d", &number);

  if (number < 1) {
    puts("the number must be natural");
    return;
  }

  int first = number;
  while (first >= 10) {
    first /= 10;
  }

  int count = 0;
  int rest = number;

  while (rest > 0) {
    if (rest % 10 == first) {
      count++;
    }
    rest /= 10;
  }

  printf("the first digit is %d, it occurs %d time(s)\n", first, count);
}
