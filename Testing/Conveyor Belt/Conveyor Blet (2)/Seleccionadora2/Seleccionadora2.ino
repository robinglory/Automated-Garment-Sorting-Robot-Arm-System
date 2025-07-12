#include <Servo.h>

// CODIGO BANDA TRANSPORTADORA CON SELECCION DE ALTURA  //


int s1=2;  // sensor 1
int s2=3;  // sensor 2
int m1=5;  // terminal de motor 1
int m2=6;  // terminal de motor 2


int c=0;  // iniciar conteo de sensores en cero

int contador=0; //iniciar contador de elecmentos a cero

int cantidad=10; // *** AQUI INTRODUCE EL NUMERO DE ELEMENTOS QUE DEBE DETECTAR LA BANDA PARA QUE AL FINAL SE DETENGA *** (por defaul 10)

Servo selector;  // sevomotor compuerta selectora

void setup() {
 pinMode(s1, INPUT);  // decara sensor uno como entrada
 pinMode(s2, INPUT);  // decara sensor uno como entrada
 pinMode(m1, OUTPUT);  // decara sensor uno como salida
 pinMode(m2, OUTPUT);  // decara sensor uno como salida
 Serial.begin(9600);  
 selector.attach(9);  // declara donde esta conectado el servo

 selector.write(90); // empieza el servo a 90 grados hasta que se cumpla una condicion


}

void loop() {

  if(contador>=cantidad)  // si la cantidad de conteo el mayor o igual a la cantidad programada
  {
    delay(8000);
  digitalWrite(m1, LOW);  // la banda se detiene
  digitalWrite(m2, LOW);
  }
  else  // si no llega aun no llega al limite de conteo
  {
  digitalWrite(m1, HIGH);  // la banda empieza a funcionar con su respectiva velocidad
  digitalWrite(m2, LOW);
  }
  
  
  if (digitalRead (s1)==LOW) // Si detecta sensor 1 espera un tiempo para que no se active el servo hasta confirmar que si hay un objeto
{
  c=0;    
  c++;  // c suma uno, ahora c es igual a 1 a esta condicion
  contador++;
  Serial.print("# DE PIEZAS: ");
  Serial.println(contador);
  delay(2500);   // Iiempo que tarda en mandar la señal al sensor 2, (puedes modificar para ajustar la respuesta del servo)
  
}

if (digitalRead (s2)==LOW)  // Si el sensor 2 detecta y si paso previamente por el sensor uno, solo asi sumara una a esta condicion
{
if (c==1)
{
  c=c+1; // c ahora es igual a 2
}
if(c==2)  // Si c es igual a 2 entonces mueve el servo a 45 grados
{
  selector.write(45);
  delay(500);
}
}

if(c==1) // Si c sigue como igual a 1 entonces el servo se mueve a 135
{
  

selector.write(135);
delay(500);
}



}



/*while(digitalRead(s1)==LOW) // mientras permanesca el senso1 s1 activo no cuenta inecesariamente hasta que no detecte y vuelva a detectar
{ delay(10);}

while(digitalRead(s2)==LOW) // mientras permanesca el senso1 s1 activo no cuenta inecesariamente hasta que no detecte y vuelva a detectar
{ delay(10);}*/




