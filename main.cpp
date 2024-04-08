#include "main.h"

uint32_t read_uint32_from_file(FILE* file, char* filename) {
    uint32_t value;
    if (int filesize = fread(&value, sizeof(value), 1, file) < 1){
        fprintf(stderr, "[*] File[%s] size(%d) smaller than 4 bytes..\n", filename,filesize);
        exit(0);
    }
    return ntohl(value);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "[*] Usage: %s <file#1> <file#2>\n", argv[0]);
        return 1;
    }

    FILE* fp1 = fopen(argv[1], "rb");
    FILE* fp2 = fopen(argv[2], "rb");

    if (!fp1 || !fp2) {
        perror("[*] Error opening file");
        return 1;
    }

    uint32_t val1 = read_uint32_from_file(fp1,argv[1]);
    uint32_t val2 = read_uint32_from_file(fp2,argv[2]);

    fclose(fp1);
    fclose(fp2);

    uint32_t sum = val1 + val2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", val1, val1, val2, val2, sum, sum);

    return 0;
}
