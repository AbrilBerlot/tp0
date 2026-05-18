#include <stdio.h>
#include <stdbool.h>

const char FUNDADOR_SPRINGFIELD = 'J';
const char FUNDADOR_ALIENS = 'A';
const char FUNDADOR_MAGIOS = 'S';
const char FUNDADOR_BURNS = 'B';
const int RESPUESTA_CORRECTA = 100;
const int RESPUESTA_INCORRECTA = -20;
const int CANT_INTENTOS_MAX = 3;

const char GUARDA_SECRETO = 'S';
const char NO_GUARDA_SECRETO = 'N';
const int PUNTOS_GUARDA_SECRETO = 50;
const int PUNTOS_NO_GUARDA_SECRETO = -300;

const int ANIO_INVALIDO = -1;
const int ANIO_MAX = 2026;
const int ANIO_MIN_LIMITE = 1926;
const int MES_INVALIDO = -1;
const int MES_MIN = 1;
const int MES_MAX = 12;
const int MES_LIMITE_ANIO = 3;
const int MES_LIMITE_EDAD = 9;
const int EDAD_MIN = 18;
const int DUPLICAR_PUNTAJE_EDAD = 2;

const int MAX_NUM_DONAS = 12;
const int MIN_NUM_DONAS = 0;
const int DONAS_RANGO_INICAL_MIN = 1;
const int DONAS_RANGO_INICAL_MAX = 3;
const int DONAS_RANGO_MEDIO_MIN = 4;
const int DONAS_RANGO_MEDIO_MAX = 6;
const int DONAS_RANGO_INTERMEDIO_MIN = 7;
const int DONAS_RANGO_INTERMEDIO_MAX = 9;
const int DONAS_RANGO_SUPREMO_MIN = 10;
const int DONAS_RANGO_SUPREMO_MAX = 12;
const int PUNTOS_DONAS_MIN = -100;
const int PUNTOS_DONAS_INICIAL = 10;
const int PUNTOS_DONAS_MEDIO = 40;
const int PUNTOS_DONAS_INTERMEDIO = 70;
const int PUNTOS_DONAS_SUPREMO = 120;

const int RECHAZADO = 0;
const int ASPIRANTE_MAX = 150;
const int MAGIO_NOVATO_MIN = 151;
const int MAGIO_NOVATO_MAX = 250;
const int MAGIO_MIN = 251;
const int MAGIO_MAX = 349;
const int LIDER_SUPREMO = 350;



//pre:respuesta_fundador debe ser un carácter (J,A,S,B)
//pos:devuelve true si la respuesta_fundador es 'J','A','S' o 'B'. False caso contrario
bool es_opcion_fundador_valida (char respuesta_fundador){
    return (respuesta_fundador == FUNDADOR_SPRINGFIELD || respuesta_fundador == FUNDADOR_ALIENS || respuesta_fundador == FUNDADOR_MAGIOS || respuesta_fundador == FUNDADOR_BURNS);
}


//pre:letra_ingresada debe ser un carácter(J,A,S,B)
//pos:guarda en respuesta_fundador el caracter ingresado por el usuario
void preguntar_fundador_springfield(char* respuesta_fundador){
    printf("Bienvenido a la prueba de los magios, antes de adentrarse le pediremos unos datos. ¿Quién es el fundador de Springfield? Su respuesta debe ser [J]ebediah Springfield, los [A]liens, [S] los magios ó Sr.[B]urns. Por favor seleccione J,A,S,B y presione enter. \n");
    scanf(" %c", respuesta_fundador);
    while (!es_opcion_fundador_valida(*respuesta_fundador)){
        printf("Ingreso incorrecto. Seleccione (Jebediah Springfield) = J, (Los aliens) = A, (Los magios) = S, (Sr.Burns) = B. Luego presione enter.\n");
        scanf(" %c", respuesta_fundador);
    }
}

//pre:almacena la respuesta ingresada (J,A,S,B), un puntero con puntos_fundador, un puntero si es_fundador_acertado
//pos:actualiza el puntaje y su estado de acierto
void evaluar_intento_fundador(char respusta_fundador, int* puntos_fundador, bool* es_fundador_acertado){
    if(respusta_fundador == FUNDADOR_SPRINGFIELD){
        *es_fundador_acertado = true;
        *puntos_fundador += RESPUESTA_CORRECTA;
    } else {
        *puntos_fundador += RESPUESTA_INCORRECTA;
    }
}

//pre:los punteros deben estar inicializados en 0 y false
//pos:gestiona el bucle de intentos(máx 3) y lo comunica con el usuario
void procesar_pregunta_fundador(int* puntos_fundador, bool* es_fundador_acertado){
    char respuesta_fundador;
    int intentos_fallidos = 0;
    while (intentos_fallidos < CANT_INTENTOS_MAX && !(*es_fundador_acertado)){
        preguntar_fundador_springfield(&respuesta_fundador);
        evaluar_intento_fundador(respuesta_fundador, puntos_fundador, es_fundador_acertado);
        if(!(*es_fundador_acertado)){
            intentos_fallidos++;
            printf("Respuesta incorrecta, llevas %i intento/s fallido/s.\n",intentos_fallidos);
        }
    }
}

//pre:-
//pos:devuelve true si letra_ingresada es S,N. False, caso contrario
bool es_caracter_valido(char letra_ingresada){
    return (letra_ingresada == GUARDA_SECRETO || letra_ingresada == NO_GUARDA_SECRETO);
}

// pre:almacena en la respuesta_secreto en un tipo de dato bool
//pos:guarda en letra_ingresada la respuesta dada ingresada por el usuario y chequea que la misma guarde el secreto o no
void guardar_secreto (bool* respuesta_secreto){
    char letra_ingresada;
    printf("¿Promete mantener en secreto la existencia de los magios? Sí [S] o No [N], seleccione únicamente S o N y luego presione enter...\n");
    scanf(" %c", &letra_ingresada);
    while (!es_caracter_valido(letra_ingresada)){
        printf("Ha escrito mal el caracter, por favor si quiere seleccione S(Sí), de lo contrario N(No)\n");
        scanf(" %c", &letra_ingresada);
   }
   *respuesta_secreto = (letra_ingresada == GUARDA_SECRETO); 
}

//pre:respuesta_secreto tiene que ser un  valor bool y puntos_secreto un numero entero 
//pos:gestiona la respuesta_secreto ingresada y en base a ella sus puntos_secreto
void contar_puntaje_secreto (bool respuesta_secreto, int* puntos_secreto){
    if (respuesta_secreto){
        *puntos_secreto += PUNTOS_GUARDA_SECRETO;
    } else {
        *puntos_secreto += PUNTOS_NO_GUARDA_SECRETO;
    }
}

//pre:anio (1926-2026) y mes (1-12) deben ser enteros
//post:devuelve true si anio_valido, mes_valido, anio y mes estan entre 1926/03 y 2026. False caso contrario 
bool es_fecha_nac_valida(int anio, int anio_min, int anio_max, int mes, int mes_min, int mes_max){
   bool anio_valido = (anio >= anio_min && anio <= anio_max && anio != ANIO_INVALIDO);
   bool mes_valido = (mes >= mes_min && mes <= mes_max && mes != MES_INVALIDO);
   if(!anio_valido || !mes_valido){
    return false;
   }
   if (anio <= ANIO_MIN_LIMITE && mes < MES_LIMITE_ANIO){
    return false;
   }
   return true;
}

//pre:-
//pos:guarda en anio y mes la respuesta con formato brindada por el usuario
void preguntar_fecha_nacimiento(int* anio, int* mes){
    printf("¿Cuál es su año de nacimiento?(formato yyyy/mm, ejemplo 1973/03). Luego presione enter: ");
    scanf("%i/%i", anio, mes);
    while(!es_fecha_nac_valida(*anio, ANIO_MIN_LIMITE, ANIO_MAX, *mes, MES_MIN,MES_MAX)){
        printf("Fecha de nacimiento inválida, ingrese correctamente la fecha (Ejemplo: 2002/07) y luego presione enter\n");
        scanf("%i/%i", anio, mes);
    }   
}

//pre: se le pasa por parametros anio (1926 a 2026) y mes (1 al 12) que son numeros enteros
//pos:devuelve el cálculo de la edad_persona
int calculo_edad_persona(int anio, int mes){
    int edad_persona = ANIO_MAX - anio;
    if(mes >= MES_LIMITE_EDAD){
        edad_persona--;
    }
    return edad_persona;
}

//pre: almacena como puntero un anio y mes válido
//pos: true si es mayor de edad. False caso contrario
bool es_mayor_de_edad(int* anio, int* mes){
    return (calculo_edad_persona(*anio, *mes) >= EDAD_MIN);
}
//pre:respuesta_donas tiene que ser un num entero
//pos: devuelve true si la cantidad de donas esta entre 0 y 12. False caso contrario
bool es_cantidad_donas_valida(int respuesta_donas){
    return (respuesta_donas >= MIN_NUM_DONAS && respuesta_donas <= MAX_NUM_DONAS);
}

//pre:-
//pos:almacena la cantidad de donas que está dispuesto a sacrificar
void sacrificar_donas(int* respuesta_donas){
    printf("¿Cuántas donas estaría dispuesto a sacrificar? Ingrese un número de 0 a 12 inclusive: \n");
    scanf(" %i", respuesta_donas);
    while (!es_cantidad_donas_valida(*respuesta_donas)){
        printf("Ingreso incorrecto. Dígame un numero del 0 al 12 luego presione enter.\n");
        scanf(" %i", respuesta_donas);
    }
}

//pre:respuesta_donas debe ser un entero entre 0 y 12
//pos:devuelve el puntaje correspondiente a la cantidad de donas sacrificadas
int devolviendo_puntaje_donas(int respuesta_donas){
    int puntos_por_dona = 0;
    if(respuesta_donas == MIN_NUM_DONAS){
        puntos_por_dona += PUNTOS_DONAS_MIN;
    } 
    if (respuesta_donas >= DONAS_RANGO_INICAL_MIN && respuesta_donas <= DONAS_RANGO_INICAL_MAX) {
        puntos_por_dona += PUNTOS_DONAS_INICIAL;
    } 
    if (respuesta_donas >= DONAS_RANGO_MEDIO_MIN && respuesta_donas <= DONAS_RANGO_MEDIO_MAX){
        puntos_por_dona += PUNTOS_DONAS_MEDIO;
    }
    if (respuesta_donas >= DONAS_RANGO_INTERMEDIO_MIN && respuesta_donas <= DONAS_RANGO_INTERMEDIO_MAX){
        puntos_por_dona += PUNTOS_DONAS_INTERMEDIO;
    } 
    if (respuesta_donas >= DONAS_RANGO_SUPREMO_MIN && respuesta_donas <= DONAS_RANGO_SUPREMO_MAX){
        puntos_por_dona += PUNTOS_DONAS_SUPREMO;
    } 
    return puntos_por_dona;
} 

//pre: se le pasa por parámetros los puntos obtenidos por cada pregunta y el puntero calculo_tot debe ser un numero positivo
//pos:calcula el total de puntos acumulados
void calcular_total_puntos(int puntos_fundador, int puntos_secreto, int puntos_edad, int puntos_donas, int* calculo_tot){
    *calculo_tot = puntos_fundador + puntos_secreto + puntos_edad + puntos_donas;   
}

//pre:calcular_total debe ser un numero >=0
//pos:evalúa el resultado obtenido en calcular_total y en base a eso, indica su posición (RECHAZADO, ASPIRANTE, MAGIO NOVATO, MAGIO O LIDER SUPREMO)
void evaluar_resultado(int calcular_total){
    if (calcular_total < RECHAZADO) {
        printf("Con tus respuestas brindadas tu resultado es: -RECHAZADO- ");
    } else if (calcular_total >= RECHAZADO && calcular_total <= ASPIRANTE_MAX){
        printf("Con tus respuestas brindadas tu resultado es: -ASPIRANTE- ");
    } else if (calcular_total >= MAGIO_NOVATO_MIN && calcular_total <= MAGIO_NOVATO_MAX){
        printf("Con tus respuestas brindadas tu resultado es: -MAGIO NOVATO- ");
    } else if (calcular_total >= MAGIO_MIN && calcular_total <= MAGIO_MAX){
        printf("Con tus respuestas brindadas tu resultado es: -MAGIO- ");
    } else {
        printf("Con tus respuestas brindadas tu resultado es: -LIDER SUPREMO- ");
    }
    
}

int main(){
    int anio = 0;
    int mes = 0;
    int cantidad_donas = 0;
    int puntos_fundador = 0;
    int puntos_secreto = 0;
    int puntos_edad = 0; 
    int puntos_donas = 0; 
    int resultado_total = 0;
    bool es_fundador_acertado = false;
    bool respuesta_secreto = false;
    
    procesar_pregunta_fundador(&puntos_fundador, &es_fundador_acertado);
    
    if(es_fundador_acertado){
        guardar_secreto(&respuesta_secreto);
        contar_puntaje_secreto(respuesta_secreto, &puntos_secreto);
        
        preguntar_fecha_nacimiento(&anio, &mes);
        
        if (es_mayor_de_edad(&anio, &mes)){
            puntos_edad = (calculo_edad_persona(anio, mes) * DUPLICAR_PUNTAJE_EDAD);
            
            sacrificar_donas(&cantidad_donas);
            puntos_donas = devolviendo_puntaje_donas(cantidad_donas);
            
            calcular_total_puntos(puntos_fundador, puntos_secreto, puntos_edad, puntos_donas, &resultado_total);
            evaluar_resultado(resultado_total);
        } else {
            printf("¡-RECHAZADO-! Sos menor de edad, sólo apto para mayores de 18 años.\n");
        }
        
    } else {
        printf("-RECHAZADO-");
    }
    return 0;
}