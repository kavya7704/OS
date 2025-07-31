#include <stdio.h> 
int main() { 
    // P1, P2, P3, P4,P5 are the Process names here 
 int n, m, i, j, k; 
     n = 5; // Number of processes 
     m = 3; // Number of resources 
     int allocated[5][3] = { {1, 1, 2}, // P1    // Allocation Matrix 
                           {2, 1, 2}, // P2 
                           {4, 0, 1}, // P3 
                           {0, 2, 0}, // P4 
                           {1, 1, 2} }; // P5 
  
     int max[5][3] = { {4, 3, 3}, // P1   // MAX Matrix 
                        {3, 2, 2}, // P2 
                        {9, 0, 2}, // P3 
                        {7, 5, 3}, // P4 
                        {1, 1, 2} }; // P5 
  
     int available[3] = {2, 1, 0}; // Available Resources 
  
     int finish[n], safe_sequence[n], ind = 0; 
     for (k = 0; k < n; k++) { // checking  the safety status of the process 
          f[k] = 0; 
     } 
     int remaining_need[n][m]; 
     for (i = 0; i < n; i++) { 
          for (j = 0; j < m; j++) 
               remaining_need[i][j] = max[i][j] - allocated[i][j]; 
     } 
     
     int y = 0; 
     for (k = 0; k < 5; k++) { 
          for (i = 0; i < n; i++) { 
               if (f[i] == 0) { 
                   int flag = 0; 
                   for (j = 0; j < m; j++) { 
                        if (remaining_need[i][j] > available[j]){ 
                            flag = 1; 
                             break; 
                       } 
                  } 
                  if (flag == 0) { 
                       safe_sequence[ind++] = i+1; 
                       for (y = 0; y < m; y++) 
                            available[y] += allocated[i][y]; 
                       finish [i] = 1; 
                  } 
              } 
         } 
    } 
    int flag = 1; 
    for(int i=0;i<n;i++) { 
      if(finish [i]==0) { 
          flag=0; 
           printf("The following system is not safe"); 
          break; 
       } 
    } 
    if(flag==1) { 
      printf("Following is the SAFE Sequence\n"); 
       for (i = 0; i < n - 1; i++) 
          printf(" P%d ->", safe_sequence[i]); 
       printf(" P%d", safe_sequence[n - 1]); 
    } 
    return (0); 
} 
