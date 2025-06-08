#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STEP 0.1
#define MAX_X 100.0  // For plotting
#define TOLERANCE 1e-2

double revenue(double x, double a, double b) {
    return a * x - b * pow(x, 3);
}

double cost(double x, double c, double d, double e) {
    return c * pow(x, 2) + d * exp(0.01 * x) + e;
}

double profit(double x, double a, double b, double c, double d, double e) {
    return revenue(x, a, b) - cost(x, c, d, e);
}

void generatePlotData(double a, double b, double c, double d, double e, int index) {
    char filename[32];
    snprintf(filename, sizeof(filename), "dataset_%d.dat", index);

    FILE *out = fopen(filename, "w");
    if (!out) {
        perror("Failed to open output file");
        return;
    }

    fprintf(out, "# x\tRevenue\tCost\tProfit\n");

    double x = 0.0;
    while (x <= MAX_X) {
        double r = revenue(x, a, b);
        double cst = cost(x, c, d, e);
        double p = r - cst;
        fprintf(out, "%.2f\t%.2f\t%.2f\t%.2f\n", x, r, cst, p);
        x += STEP;
    }

    fclose(out);
    printf("  -> Data written to %s\n", filename);
}

int main() {
    FILE *fp = fopen("dataset.txt", "r");
    if (!fp) {
        perror("Failed to open dataset.txt");
        return 1;
    }

    double a, b, c, d, e;
    int datasetIndex = 1;

    while (fscanf(fp, "%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e) == 5) {
        printf("Dataset %d:\n", datasetIndex);
        printf("R(x) = %.2fx - %.4fx^3\n", a, b);
        printf("C(x) = %.2fx^2 + %.2fe^(0.01x) + %.2f\n", c, d, e);
        generatePlotData(a, b, c, d, e, datasetIndex);
        datasetIndex++;
    }

    fclose(fp);
    return 0;
}
