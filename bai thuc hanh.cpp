#include <stdio.h>
 
int main()
{
    int n, i;
    char name[255];                         // khai bao bien ten
    FILE *fi = fopen("input.txt", "r");     // mo file de doc
    FILE *fo = fopen("output.txt", "w");    // mo file de ghi
 
    fscanf(fi, "%d", &n);   
	fgetc(fi);                // doc so n tu file fi
 
    fgets(name, 255, fi);                   // loai bo dau xuong dong sau khi doc so n
 
    for(i = 0; i < n; i++) 
    {                   
        fgets(name, 255, fi);               // doc chuoi gom 255 ky tu tu file fi
        fprintf(fo, "%d.%s", (i+1), name);  // ghi chuoi ra file fo
    }
 
    fclose(fi);     // dong file fi
    fclose(fo);     // dong file fo
 
    return 0;
}
