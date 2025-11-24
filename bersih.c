#include <stdio.h>
#include <string.h>
#include <ctype.h>


void toLowercase(char *str) {
    if (str == NULL) return; 
    for (int i = 0; str[i] != '\0'; i++) {
        // tolower() dipanggil pada setiap karakter
        str[i] = tolower((unsigned char)str[i]);
    }
}

 int main(){
    typedef struct{ 
        char title[10000];
        char kalimat[100000];
      
    } tipe;

    tipe data;
    FILE *input_file, *hasil;
    input_file = fopen ("datamentah.txt", "r");
    if (input_file == NULL){
        printf("file gak bisa dibuka");
        return 1;
    }
    hasil = fopen ("hasil.txt", "w");
      if (hasil == NULL){
         printf("file gak bisa dibuka");
         return 1;
      }
    
    while (fscanf(input_file," <url>%*[^<]</url><title>%9999[^<]</title><body>%99999[^<]</body> ", data.title, data.kalimat) == 2){ 
        fprintf(hasil, "%s %s\n", data.title, data.kalimat); 
        hasil = tolower(hasil);
        toLowercase(data.title);
        toLowercase(data.kalimat);
    }

fclose(hasil);
fclose(input_file);

    return 0;
 }