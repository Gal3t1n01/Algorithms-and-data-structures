#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0
#define MAX 100

void gen_arr(float V[], int n, float dg, float gg);
int sekv_pret(float V[], int n, float x);
void sort(float V[], int n);
int bin_pret(float V[], int n, float x);

int main() {
    srand(time(NULL));
    int n, i, x, pronadjen_sekv, pronadjen_bin;
    float *V;
    printf("Unesite velicinu polja: ");
    scanf("%d", &n);
    V = malloc(n * sizeof(float));
    if (V == NULL) {
        printf("Greska pri alociranju memorije.\n");
        return 1;
    }
    gen_arr(V, n, MIN, MAX);
    printf("Ispis polja:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f ", V[i]);
    }
    printf("\n");
    printf("Unesite broj koji zelite pronaci: ");
    scanf("%d", &x);
    pronadjen_sekv = sekv_pret(V, n, x);
    sort(V, n);
    pronadjen_bin = bin_pret(V, n, x);
    if (pronadjen_sekv == -1) {
        printf("Trazeni broj %d se ne nalazi u polju (sekvencijalno pretrazivanje).\n", x);
    }
    else {
        printf("Trazeni broj %d se nalazi na indeksu %d (sekvencijalno pretrazivanje).\n", x, pronadjen_sekv);
    }
    if (pronadjen_bin == -1) {
        printf("Trazeni broj %d se ne nalazi u polju (binarno pretrazivanje).\n", x);
    }
    else {
        printf("Trazeni broj %d se nalazi na indeksu %d (binarno pretrazivanje).\n", x, pronadjen_bin);
    }
    free(V);
    return 0;
}

void gen_arr(float V[], int n, float dg, float gg) {
    int i;
    for (i = 0; i < n; i++) {
        V[i] = dg + (float) rand() / RAND_MAX * (gg - dg);
    }
}

int sekv_pret(float V[], int n, float x) {
    int i;
    for (i = 0; i < n; i++) {
        if (V[i] == x) {
            return i;
        }
    }
    return -1;
}

void sort(float V[], int n) {
    int i, j;
    float temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (V[i] > V[j]) {
                temp = V[i];
                V[i] = V[j];
                V[j] = temp;
            }
        }
    }
}
int bin_pret(float V[], int n, float x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (V[m] == x) {
            return m;
        }
        else if (V[m] < x) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return -1;
}
