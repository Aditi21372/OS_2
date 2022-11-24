#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define SYS_matrix_copy 451

int main(int argc,char **argv)
{	int ele=0;
	int opa=0;
    	float matA[2][2] = {{8.5,3.5},{2.5,4.0}};
    	float matB[2][2];
    long res = syscall(SYS_matrix_copy,matA,matB);
    printf("returned: %ld \n",res);
    perror("output: ");
    printf("MatrixB (after syscall)\n");
    for(ele =0;ele<2;ele++)
    {
        for(opa = 0; opa<2;opa++)
        {
            printf("%f ",matB[ele][opa]);
        }
        printf("\n");
    }
    return res;
}
