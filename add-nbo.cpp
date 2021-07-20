#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char *argv[]){

    uint32_t num_1;
    uint32_t num_2;
    uint32_t result;

    FILE* fp1 = fopen(argv[1],"rb");
    fread(&num_1,sizeof(num_1),1,fp1);
    num_1 = htonl(num_1);
    fclose(fp1);

    FILE* fp2 = fopen(argv[2], "rb");
    fread(&num_2, sizeof(num_2),1,fp2);
    num_2 = htonl(num_2);
    result = num_1 + num_2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", num_1, num_1,num_2,num_2,result,result);



    fclose(fp2);
    return 0;

}
