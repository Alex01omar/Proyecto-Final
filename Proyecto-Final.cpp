#include <stdio.h>
#include <string.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#define dim 22
#define dim2 10
#define dim3 3
#define dim4 4
#define dim6 6
#define dim10 10
#include <unordered_map>
#include <iostream>

using namespace std;



struct Alumno{

    long int cedula;

};

void ingresar_cedula(long int *a){
   char entrada[20];
    int valido = 0;

    while (!valido) {
        printf("\nIngrese el numero de cedula: ");
        scanf("%s", entrada);

        valido = 1;
        for (int i = 0; entrada[i] != '\0'; i++) {
            if (!isdigit(entrada[i])) {
                printf("Error: Ingrese solo números. Intentelo nuevamente.\n");
                valido = 0;
                break;
            }
        }
    }

    *a = atol(entrada);
}

int validar_cedula(long int x,int y[dim10] )
{
    long int coc;
    int mul,sumpar=0,sumimpar=0,sumtotal,res;
	//permita verificar si los digitos son 10
	    for(int i=9;i>=0;i--) {//coc!=0
			coc=x/10;
	        y[i]=x%10;
	        x=coc;
	    }
	        
	    for(int i=0;i<dim10;i+=2){	
	        mul=y[i]*2;
	        if(mul>9)
	            mul-=9;
	        sumpar+=mul;
		}
	    for(int i=1;i<dim10-2;i+=2)
	        sumimpar+=y[i];
	
	    sumtotal=sumimpar+sumpar;
	    res=10-(sumtotal%10);
	        
	    if(res==10)
	        res=0;
	    if(res==y[9]){
	       //printf("\nCedula valida\n");
	    
	        return(1);
	    }
	    else{
	       printf("\nCedula invalida, porfavor vuelva a ingresar");
	        return(0);
        }
    
}

int main(void)
{

	long int cedu; 

				int cedula[dim10],veri,prov;
    			int ddig;

    				do{
        				do{
            				ingresar_cedula(&cedu);
            				ddig=trunc(cedu/100000000);
            				if(cedu>3059999999||cedu<0100000000||ddig==25||ddig==26||ddig==27||ddig==28||ddig==29){
			
            				printf("\nCedula incorrecta porfavor ingresa nuevamente");
    						}
						}while(cedu>3059999999||cedu<0100000000||ddig==25||ddig==26||ddig==27||ddig==28||ddig==29);
	    				veri=validar_cedula(cedu,cedula);
    				}while(veri!=1);
    				
}
