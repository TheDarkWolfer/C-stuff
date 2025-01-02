#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

int getInt(char* prompt) {
    char buffer[128];
    char *endptr;
    int value;

    while (1) {
        fprintf(stdout, "%s", prompt);  // Corrected: Use stdout, not stdin

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            fprintf(stderr, "Error reading input, try again please.\n");
            continue;
        }

        // Remove carriage return character if present
        buffer[strcspn(buffer, "\n")] = '\0';

        // Attempt integer conversion
        value = strtol(buffer, &endptr, 10);

        // Check if the conversion was successful
        if (*endptr == '\0' && strlen(buffer) > 0) {
            return value;
        } else {
            fprintf(stderr, "Invalid input, try again please.\n");
        }
    }
}

int main() {
    // Chrono to see how fast it is
    struct timeval start, end;
    long seconds, micros;

    unsigned long long lastint = 0, currentint = 1, newint;
    unsigned long long iterations = getInt(
        "Please enter how many iterations of Fibonacci's sequence you wish to attempt:\n[o]> ");

    gettimeofday(&start, NULL);

    // Fibonacci sequence
    for (unsigned long long i = 0; i < iterations; i++) {
        fprintf(stdout, "%llu - Iteration %llu\n", lastint, i + 1);

        newint = lastint + currentint;
        lastint = currentint;
        currentint = newint;
    }

    gettimeofday(&end, NULL);

    // Calculate time taken
    seconds = end.tv_sec - start.tv_sec;
    micros = end.tv_usec - start.tv_usec;

    if (micros < 0) {
        seconds--;
        micros += 1000000;
    }

    fprintf(stdout,
            "Calculated %llu iterations of the Fibonacci sequence in %ld seconds and %ld microseconds.\n",
            iterations, seconds, micros);

    return 0;
}
