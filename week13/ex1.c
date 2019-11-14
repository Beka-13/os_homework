//
//  ex1.c
//  
//
//  Created by Bekzhan Talgat on 14.11.2019.
//

#include "ex1.h"

int main(){
    int ok = false;  // set ok true if you want to read input_ok
                    // set ok false if you want to read input_dl
    FILE *in;
    FILE *out;
    
    if(ok == true){
        in = fopen("input_ok.txt", "r");
        out = fopen("output_ok.txt", "w");
    }
    else{
        in = fopen("input_dl.txt", "r");
        out = fopen("output_dl.txt", "w");
    }

    int resource, process;

    fscanf(in, "%d\n", &process);
    fscanf(in, "%d\n", &resource);

    int E[resource];
    int A[resource];
    int C[process][resource];
    int R[process][resource];

    int done[process];
    
    for (int i = 0; i < resource; i++)
        fscanf(in, "%d", &E[i]);
    
    for (int i = 0; i < resource; i++)
        fscanf(in, "%d", &A[i]);
    
    for (int i = 0; i < process; i++)
        for (int j = 0; j < resource; j++)
            fscanf(in, "%d", &C[i][j]);
        
    for (int i = 0; i < process; i++)
        for (int j = 0; j < resource; j++)
            fscanf(in, "%d", &R[i][j]);
        
    int proceeded = true;
    while (proceeded){
        
        proceeded = false;
        for (int i = 0; i < process; i++) {
            
            if (done[i] == false) {
                int trap = true;
                
                for (int j = 0; j < resource; j++)
                    if (A[j] < R[i][j]) trap = false;
            
                if (trap) {
                    
                    for (int j = 0; j < resource; j++) {
                        A[j] += C[i][j];
                        R[i][j] = false;
                        done[i] = true;
                        proceeded = true;
                    }
                    
                    i = process;
                }
                
            }
        }
            
    }


    int broke = true;
    for (int i = 0; i < process; i++) {
        if (done[i] == false) {
            broke = false;
            fprintf(out, "Process %d is deadlocked\n", i);
        }
    }

    if (broke)  fprintf(out, "All processes are done\n");

    fclose(in);
    fclose(out);
  return 0;
}
