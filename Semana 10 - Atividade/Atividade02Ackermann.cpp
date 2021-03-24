#include <stdio.h>
#include <stdlib.h>

int ackermann(int m, int n) {
    
	if (m < 0 || n < 0) {
        return 0;
    }
    if (m == 0) {
        return n + 1;
        
    } else if (n == 0) {
        return ackermann(m - 1, 1); 
        
    } else {
        return ackermann(m - 1, ackermann(m, n - 1));
        
    }
}

int main(){
	
	int m = 2, n = 1;
	
	printf("A(%d,%d) = %d",m,n,ackermann(m,n));
	
	return 0;
}
