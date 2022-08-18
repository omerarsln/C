#include<stdio.h>
#include<cstdlib>

int main(){

    FILE *input_file = fopen("VERI.txt" , "r+");
    if(input_file == NULL){
        printf("VERI.txt bulunamadi");
        system("pause");
        return 0;
    }

    float x[10]={0} , y[10]={0} , a ,k=0,s=1,t=1;
    int veri_sayisi=0 , i , j;

    while(!feof(input_file)){

        fscanf(input_file,"%f",&x[veri_sayisi]);
        fscanf(input_file,"%f",&y[veri_sayisi]);
        veri_sayisi++;
    }

    printf("x ara degerini giriniz : ");
    scanf("%f",&a);
    
    for(i=0; i<veri_sayisi; i++){
        s=1;
        t=1;
        for(j=0; j<veri_sayisi; j++){
            
            if(j!=i){
                
                s=s*(a-x[j]);
                t=t*(x[i]-x[j]);
            }
        }
        k=k+((s/t)*y[i]);
    }
        
    printf("y(%.0f) = %f\n", a, k);

    fclose(input_file);
    system("pause");
    return 0;
}
