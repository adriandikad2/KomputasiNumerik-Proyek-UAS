#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STEP 0.1           // Define the step size for x values
#define MAX_X 100.0        // Define the maximum x value for plotting
#define TOLERANCE 1e-2       // Define a tolerance value (not used in this code)

// Function to calculate revenue
double revenue(double x, double a, double b) {
    return a * x - b * pow(x, 3); // Revenue = a*x - b*x^3
}

// Function to calculate cost
double cost(double x, double c, double d, double e) {
    return c * pow(x, 2) + d * exp(0.01 * x) + e; // Cost = c*x^2 + d*e^(0.01x) + e
}

// Function to calculate profit
double profit(double x, double a, double b, double c, double d, double e) {
    return revenue(x, a, b) - cost(x, c, d, e); // Profit = Revenue - Cost
}

// Function to generate data for plotting
void generatePlotData(double a, double b, double c, double d, double e, int index) {
    char filename[32];
    snprintf(filename, sizeof(filename), "dataset_%d.dat", index); // Create filename

    FILE *out = fopen(filename, "w"); // Open file for writing
    if (!out) {
        perror("Failed to open output file"); // Print error message if file opening fails
        return;
    }

    fprintf(out, "# x\tRevenue\tCost\tProfit\n"); // Write header to the file

    double x = 0.0;
    while (x <= MAX_X) { // Loop from x = 0 to MAX_X
        double r = revenue(x, a, b);       // Calculate revenue
        double cst = cost(x, c, d, e);      // Calculate cost
        double p = r - cst;              // Calculate profit
        fprintf(out, "%.2f\t%.2f\t%.2f\t%.2f\n", x, r, cst, p); // Write data to file
        x += STEP;                         // Increment x by STEP
    }

    fclose(out); // Close the output file
    printf("  -> Data written to %s\n", filename); // Print message to console
}

// Main function
int main() {
    FILE *fp = fopen("dataset.txt", "r"); // Open the dataset file for reading
    if (!fp) {
        perror("Failed to open dataset.txt"); // Print error message if file opening fails
        return 1;
    }

    double a, b, c, d, e;
    int datasetIndex = 1;

    // Read parameters from the dataset file
    while (fscanf(fp, "%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e) == 5) {
        printf("Dataset %d:\n", datasetIndex);
        printf("R(x) = %.2fx - %.4fx^3\n", a, b);       // Print revenue function
        printf("C(x) = %.2fx^2 + %.2fe^(0.01x) + %.2f\n", c, d, e); // Print cost function
        generatePlotData(a, b, c, d, e, datasetIndex); // Generate plot data
        datasetIndex++;                                  // Increment dataset index
    }

    fclose(fp); // Close the dataset file
    return 0;    // Return 0 to indicate successful execution
}
