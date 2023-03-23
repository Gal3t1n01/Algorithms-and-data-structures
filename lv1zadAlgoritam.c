#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void gen_arr(int V[], int n, int dg, int gg){

    for(int i=0;i<n;i++){
        V[i] = rand() % 50;
    }
}

int sekv_pret(int V[], int n, int x){
    int i,pron = 0;

    printf("Trazeni broj sekv_pret: ");
    scanf("%d", &x);

    for(i=0;i<n;i++){
        if(x == V[n])
            pron = 1;
    }

    if(pron == 1)
        printf("\nBroj postoji u listi: ", V[x]);
    else
        printf("\nBroj ne postoji u listi: ", -1);
}

void sort(int V[], int n){

    for(int s = 0; s < n-1;s++){
        for(int i = 0; i < n - s - 1;i++){

            if(V[i] > V[i+1]){
                int temp = V[i];
                V[i] = V[i+1];
                V[i+1] = temp;
            }
        }
    }

    for(int i = 0; i < n;i++){
        printf("%d  ", V[i]);
    }
    
    printf("\n");
}

int bin_pret(int V[], int n, int x){
    int low, high = 0;
    while(low <= high){
        int mid = low + (high - low) / 2;

        if(V[mid] == x)
            return mid;
        
        if(V[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main(){

    int n = 0;
    int x = 0;
    int V[1000];

    time_t t1, t2,t3;
    t1=clock();

    printf("Broj clanova polja n");
    scanf("%d", &n);

    gen_arr(V, n, 0, 200);
    sekv_pret(V,n,x);
    sort(V, n);
    bin_pret(V, n, x);
 
    t2=clock();

    printf("Vrijeme potrebno za cijeli program: %d", t2-t1);
}