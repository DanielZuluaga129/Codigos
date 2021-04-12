#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

//Funcion para convertir un String a un char
char convertir(string Cadena){
	char Valor;
	if(Cadena=="A"){Valor='A';}
	if(Cadena=="D"){Valor='D';}
	if(Cadena=="I"){Valor='I';}

return Valor;	
}
//Funcion para Gurdar el Resultado  en el TXT
void Guardar_Result(string D){
	
	ofstream file;
    file.open("ROBCOM2.txt");
    file << D;
    file.close();
}
//Funcion para Crear un delay o retraso en el programa y podamos observar como se va moviendo el robot
void delay(){
 for (int i=1 ;i<=10000;i++) { 
  for(int j=1;j<=10000;j++)  {  } 
                                }	
}

//Funcion Principal
int main() {
    //Declaramos todas la variables que se usaran 
    int m=0; //columnas
    int n=0; //filas
    int control=1;
    int o=0; 
    int valor; 
    int filas=1;
    int columnas=1;
    int  matriz[100][100];
    string ruta[40]; //instrucciones dadas por el usuario en el archivo txt.
    int long_ruta; //cantidad de instrucciones ingresadas por el usuario en el archivo txt.
    int i1;
    int j1;
    int i2;
    int j2;
    string R1="C"; //Resultado acertado del robot (llego correctamente a su destino)
    string R2="E"; //Resultado erroneo del robot (ha sido destruido por una mina)
    string orientacion; //orientacion que va a tomar el robot 
    // Obtenerel archivo TXT"
    string nombreArchivo = "ROBCOM.txt";
    ifstream archivo(nombreArchivo.c_str());
    string linea;
    cout<<"Verificar Trayectoria de  Robot"; cout<<endl;
    cout<<"Datos optenidos del Archivo TXT"; cout<<endl;cout<<endl;
	// Obtener línea de archivo, y almacenar contenido en "linea"
    while (getline(archivo, linea)) {
        // Lo vamos imprimiendo
       // cout << "Una línea: ";
       // cout << linea << endl;  
       string input=linea; 
       string numero;
	   string Valor_Matrix;
	   stringstream stream(input);
	    // obtener valores del tamaño de m y n que esta en la primera fila del Archivo TXT 
	    if(control==1 ){
       	while(getline(stream, numero, ' ')){	
	    	if(o==0){	
	    		valor=  atoi(numero.c_str());
	    		m=valor;
	    	}	 	
            if(o==1){
	    		valor=  atoi(numero.c_str());
				n=valor;
			}
            o++;
	    }
	       if(m>=1 && m<=100 && n>=1 && n<=100){
	        	cout<<"Tamano de la matriz: m="<<m<<" "<<"n="<<n;
	            cout<<endl;
		   }else{
		        cout<<"El tamaño dela matriz no cumple los requerimintos del sistema";
		        delay();
		        exit(0);
		   }
	      o=0;//Reiniciamos la Variable de control o para ser reutilizada
		}
	    //Obtenemos los Valores de la Matrix y llenamos esta con los valores del TXT
       if(control>=2 && control<= m+1){
        	while(getline(stream, Valor_Matrix, ' ')){ 
       		matriz[filas][columnas]=atoi(Valor_Matrix.c_str()); //llenamos la primera Fila de la Matrix
	    	columnas++;
		    }
	        filas++;
	        columnas=1;
	    }
	    //obtenemos la posicion de inicio
	    if(control==m+2 ){
       		while(getline(stream, numero, ' ')){
	    	    if(o==0){
	    		    i1=  atoi(numero.c_str());
	            }
                if(o==1){
	    	    j1=  atoi(numero.c_str());
	            }
                o++;
	        } 
	        o=0;
	        if(i1>=1 && i1<=m && j1>=1 && j1<=n){
	            cout<<"Posicion Inicial:"<<i1<<","<<j1;
	            cout<<endl;
		    }else{
		        cout<<"las cordenadas de inicio no cumplen los requerimientos del sistema";
		        delay();
		        exit(0);
		    }                                                                                                        
		}
		//obtenEmos el destino del Robot
	    if(control==m+3 ){
       	    while(getline(stream, numero, ' ')){
	            if(o==0){
	    			i2=  atoi(numero.c_str());
	            }
            	if(o==1){
	    		    j2=  atoi(numero.c_str());
	            }
                o++;
	        }
	        o=0;                                    
	        if(i2>=1 && i2<=m && j2>=1 && j2<=n){
	            cout<<"Posicion Final:"<<i2<<","<<j2;
	            cout<<endl;
		    }else{
		        cout<<"las coordenadas del punto final no cumplen los requerimientos del sistema";
		    	delay();
		        exit(0);
		    }                              
		}
	  //obtenemos la orientacion inicial
	    if(control==m+4 ){
			orientacion= linea;
            cout<<"Orientacion:"<<orientacion;
	        cout<<endl; 
	    }  
	  //Obtnemos el numero de Ordenes que ejecutara el robot  
	   if(control==m+5 ){
	        long_ruta= atoi(linea.c_str());           
	        if( long_ruta>=1 && long_ruta<=40){
                cout<<"Longitud de ordenes :"<<long_ruta;
	            cout<<endl;
		    }else{
		        cout<<"El numero de ordenes al Robot  superan las especificadas por el sistema";
		        delay();
		        exit(0);
		    }
        }  
	  //obtenemos las instruciones
	    if(control==m+6 ){cout<<"Ordenes :";
            while(getline(stream, numero, ' ')){
       			ruta[o]=numero;
            	o++;
  	        	cout<<numero;
	            cout<<" ";                                                              
	                                                            
	        }
			o=0;
			cout<<endl;  cout<<endl; 
		}
        control++;
    }// fin de obtencion de datos del Archivo TXT
   //Mostramos la matriz obtenida del TXT
    for (int i=1 ;i<=m;i++){ 
        for(int j=1;j<=n;j++){ 
    		cout<<matriz[i][j]; 
		} 
        cout<<endl;  
	} 
	getch();
	//Ejecutamos las ordenes que debe realizar el Robot
	for (int i=0 ;i<long_ruta;i++){ 
		char op=convertir(ruta[i]); // usamos la funcion que creamos para convertir a char  los valores de String guardados en Ruta, para ser usados en en SWITCH
		switch (op) {
        case 'D':// Esta opcion cambia la orientacion si la orden es un giro a la Derecha (D)
        	if(orientacion=="N"){orientacion="E";break;	}
			if(orientacion=="E"){orientacion="S";break;	}
			if(orientacion=="S"){orientacion="O";break;	}
			if(orientacion=="O"){orientacion="N";break;	}
            break;
        case 'I'://Esta opcion cambia la orientacion si la orden es un giro  la izquierda(I)
        	if(orientacion=="N"){orientacion="O";break;}
			if(orientacion=="O"){orientacion="S";break;}
			if(orientacion=="S"){orientacion="E";break;}
			if(orientacion=="E"){orientacion="N";break;}
            break;
        case 'A':// Esta opcion cambia la posiscion del Robot, avanzando una unidad hacia delante dependiendo la orientacion que tenga
        	
        	if(orientacion=="N"){  
			    system("cls");
                matriz[i1][j1]=0;
		        i1=i1-1;
		        if(matriz[i1][j1]==1){//verificamos que el robot no haya pisado una mina
		            cout <<"Has pisado una mina";
		            i=long_ruta;
		            Guardar_Result(R2);
					break;
				}
				if(i1==i2 && j1==j2){//verificamos que el robot ha llegado al destino
					cout<<"has llegado al destino";cout<<endl;
					Guardar_Result(R1);
				} 
        		matriz[i1][j1]=8;  
        		for (int i=1 ;i<=m;i++){ //dibujamos la matriz con la posicion del robot
                	cout<<"---------------------";cout<<endl;
                    for(int j=1;j<=n;j++){  
                        if(matriz[i][j]==1){cout<<"*"; cout<<"|";  }
                        if(matriz[i][j]==0){cout<<" "; cout<<"|"; }
                        if(matriz[i][j]==8){cout<<"^";cout<<"|"; } 
                	} 
                    cout<<endl;  
					if(i==m){cout<<"--------------------";cout<<endl; }
				}  
                delay();
        		
		    }
	    	if(orientacion=="O"){
			    system("cls");
		        matriz[i1][j1]=0;
			    j1=j1-1;
			    if(matriz[i1][j1]==1){//verificamos que el robot no haya pisado una mina
		            cout <<"Has pisado una mina";
		            i=long_ruta;
		            Guardar_Result(R2);
					break;
				}
				if(i1==i2 && j1==j2){//verificamos que el robot ha llegado al destino
					cout<<"Has llegado al destino";cout<<endl;
                    Guardar_Result(R1);
				} 
				matriz[i1][j1]=8;
        		for (int i=1 ;i<=m;i++) {  //dibujamos la matriz con la posicion del robot
                	cout<<"-------------------";cout<<endl;
                    for(int j=1;j<=n;j++){ 
                        if(matriz[i][j]==1){cout<<"*";  cout<<"|"; }
                    	if(matriz[i][j]==0){cout<<" "; cout<<"|"; }
                        if(matriz[i][j]==8){cout<<"<";cout<<"|"; } 
                    } 
                    cout<<endl;  
                    if(i==m){cout<<"---------------------";cout<<endl; }
				} 
                delay();
			}
			if(orientacion=="S"){
				system("cls");
			    matriz[i1][j1]=0;
			    i1=i1+1;
			    if(matriz[i1][j1]==1){//verificamos que el robot no haya pisado una mina
		            cout <<"Has pisado una mina";
		            i=long_ruta;
		            Guardar_Result(R2);
					break;
				}
				if(i1==i2 && j1==j2){//verificamos que el robot ha llegado al destino
					cout<<"Has llegado al destino";cout<<endl;
                    Guardar_Result(R1);
                } 
				matriz[i1][j1]=8;
        		for (int i=1 ;i<=m;i++){  //dibujamos la matris con la posicion del robot
                    cout<<"---------------------";cout<<endl;
                    for(int j=1;j<=n;j++){ 
                		if(matriz[i][j]==1){cout<<"*";  cout<<"|"; }
                    	if(matriz[i][j]==0){cout<<" "; cout<<"|"; }
                        if(matriz[i][j]==8){cout<<"v"; cout<<"|"; } 
                    } 
                    cout<<endl; 
					if(i==m){cout<<"--------------------";cout<<endl; } 
				} 
				delay();
			}
		 	if(orientacion=="E"){
			    system("cls");
		        matriz[i1][j1]=0;
				j1=j1+1;
				if(matriz[i1][j1]==1){//verificamos que el robot no haya pisado una mina
		        cout <<"Has pisado una mina";
		        i=long_ruta;
		        Guardar_Result(R2);
				break;
				}
				if(i1==i2 && j1==j2){//verificamos que el robot ha llegado al destino
					cout<<"Has llegado al destino";cout<<endl;
					Guardar_Result(R1);
				} 
				matriz[i1][j1]=8;
        		for (int i=1 ;i<=m;i++){  //dibujamos la matris con la posicion del robot
                	cout<<"-----------------------";cout<<endl;
                    for(int j=1;j<=n;j++){ 
                        if(matriz[i][j]==1){cout<<"*"; cout<<"|"; }
                        if(matriz[i][j]==0){cout<<" ";cout<<"|";  } 
                        if(matriz[i][j]==8){cout<<">";cout<<"|";  } 
                    } 
                    cout<<endl; 
					if(i==m){cout<<"---------------------";cout<<endl; }
				} 
			    delay();
			}
            break;
        	default:
            cout << "Esta orden no es permitida ";
            break;
        }//fin del switch
	}//fin del for
}//fin main



