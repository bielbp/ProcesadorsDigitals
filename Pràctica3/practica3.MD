# PRACTICA 2 : WIFI  y BLUETOOTH  

El objetivo de la practica es comprender el funcionamiento de WIFI Y BT.

Para lo cual realizaremos una practica  donde  generaremos un web server desde utilizando 
nuestra ESP32  y tambien  una comunicacion  serie con una aplicacion de un movil con BT .



## Introducción teórica  

Si bien el objetivo de esta asignatura es el manejo de los microcontroladores  y microprocesadores .
Es muy complicado que podamos explicar el uso de periféricos  especializados WIFI o Bluetooth sin tener idea de 
cual es  el fundamento en que se basan . Por lo que daremos algunas referencias básicas  que les servirán para
 entender  los conceptos de la practica  ; si bien su comprensión la realizaran en otras asignaturas de redes.


Con respecto a la WIFI

 Por una parte recomendamos la lectura  de  protocolos TCP/IP  UDP   

https://www.tlm.unavarra.es/~daniel/docencia/lir/lir05_06/slides/1-Conceptosbasicos.pdf

Por otra parte   wifi

http://www.radiocomunicaciones.net/pdf/curso-iniciacion-wifi.pdf


Por otro  la API REST 

https://aprendiendoarduino.wordpress.com/2019/10/27/api-rest/


Y  por ultimo MQTT

https://ricveal.com/blog/primeros-pasos-mqtt


Con respecto a Bluetooth 

https://randomnerdtutorials.com/esp32-bluetooth-classic-arduino-ide/






## Practica A generación de una pagina web  

No se requiere montaje  

Ejemplo de código :


 ```

/*
  ESP32 Web Server - STA Mode
  modified on 25 MAy 2019
  by Mohammadreza Akbari @ Electropeak
  https://electropeak.com/learn
*/

#include <WiFi.h>
#include <WebServer.h>

// SSID & Password
const char* ssid = "*****";  // Enter your SSID here
const char* password = "*****";  //Enter your Password here

WebServer server(80);  // Object of WebServer(HTTP port, 80 is defult)

void setup() {
  Serial.begin(115200);
  Serial.println("Try Connecting to ");
  Serial.println(ssid);

  // Connect to your wi-fi modem
  WiFi.begin(ssid, password);

  // Check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected successfully");
  Serial.print("Got IP: ");
  Serial.println(WiFi.localIP());  //Show ESP32 IP on serial

  server.on("/", handle_root);

  server.begin();
  Serial.println("HTTP server started");
  delay(100); 
}

void loop() {
  server.handleClient();
}

// HTML & CSS contents which display on web server
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1>My Primera Pagina con ESP32 - Station Mode &#128522;</h1>\
</body>\
</html>";

// Handle root url (/)
void handle_root() {
  server.send(200, "text/html", HTML);
}
```


### informe
  
  1. Realizar el informe de funcionamiento  asi como la salida por el terminal  y la  visualización de la conexión a la pagina web con un navegador

  ### Introducció
  El programa connecta la esp32-S3 a la xarxa i la utilitza com a servidor per crear una pagina web. 
  ### Capçalera
  A l acapçalera s'introdueixen les llibreries <WiFi.h> i <WebServer.h> necessaries per generar el server a la esp32-S3. També s'introdueixen les variables que contenen les dades necessaries perquè el microcontrolador es connecti a la xarxa.

  ### Setup
  S'estableix la velocitat de comunicació a 115200 i les funcions necessaries per la conexió.

  ### Loop
  Només s'escriu la funció server.handleClient() per rebre les peticions del servidor.

  2. Modificar la pagina web generando un fichero HTML con  el editor Mark down e incluirlo en el codigo . Incluir un fichero adicional que solo incluya la pagina html 

  ### Codigo web
  String HTML ="<!DOCTYPE html>"
"<html lang=\"es\">"
"<head>"
"    <meta charset=\"UTF-8\">"
"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
"    <title>Pingüinos - Página Web</title>"
"    <style>"
"        body {"
"            font-family: Arial, sans-serif;"
"            margin: 0;"
"            padding: 0;"
"            background-color: #f0f0f0;"
"        }"
"        header {"
"            background-color: #007bff;"
"            color: white;"
"            padding: 20px;"
"            text-align: center;"
"        }"
"        nav {"
"            background-color: #333;"
"            color: white;"
"            padding: 10px;"
"            text-align: center;"
"        }"
"        nav a {"
"            color: white;"
"            text-decoration: none;"
"            padding: 10px;"
"        }"
"        nav a:hover {"
"            background-color: #555;"
"        }"
"        section {"
"            padding: 20px;"
"        }"
"        footer {"
"            background-color: #007bff;"
"            color: white;"
"            text-align: center;"
"            padding: 10px;"
"            position: fixed;"
"            bottom: 0;"
"            width: 100%;"
"        }"
"    </style>"
"</head>"
"<body>"
"    <header>"
"        <h1>Pingüinos</h1>"
"    </header>"
"    <nav>"
"        <a href=\"#informacion\">Información General</a>"
"        <a href=\"#especies\">Especies</a>"
"        <a href=\"#habitat\">Hábitat</a>"
"        <a href=\"#alimentacion\">Alimentación</a>"
"    </nav>"
"    <section id=\"informacion\">"
"        <h2>Información General</h2>"
"        <p>Los pingüinos son aves marinas no voladoras que habitan en el hemisferio sur. Son conocidos por su plumaje negro y blanco, y su habilidad para nadar y bucear.</p>"
"    </section>"
"    <section id=\"especies\">"
"        <h2>Especies de Pingüinos</h2>"
"        <ul>"
"            <li>Pingüino Emperador</li>"
"            <li>Pingüino Adelaida</li>"
"            <li>Pingüino de Magallanes</li>"
"            <li>Pingüino de Humboldt</li>"
"            <li>Pingüino de Galápagos</li>"
"        </ul>"
"    </section>"
"    <section id=\"habitat\">"
"        <h2>Hábitat</h2>"
"        <p>Los pingüinos habitan principalmente en regiones frías, como la Antártida y algunas islas cercanas al continente sudamericano.</p>"
"    </section>"
"    <section id=\"alimentacion\">"
"        <h2>Alimentación</h2>"
"        <p>La dieta de los pingüinos varía según la especie, pero generalmente consiste en peces, calamares y crustáceos.</p>"
"    </section>"
"    <footer>"
"        <p>&copy; 2024 Pingüinos Web - Todos los derechos reservados</p>"
"    </footer>"
"</body>"
"</html>";

  3. Generar informe  y codigo  en Github

### Codi sencer
#include <Arduino.h>

#include <WiFi.h>
#include <WebServer.h>
// SSID & Password
const char* ssid = "practicas "; // Enter your SSID here
const char* password = ""; //Enter your Password here
WebServer server(80); // Object of WebServer(HTTP port, 80 is defult)
String HTML ="<!DOCTYPE html>"
"<html lang=\"es\">"
"<head>"
"    <meta charset=\"UTF-8\">"
"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
"    <title>Pingüinos - Página Web</title>"
"    <style>"
"        body {"
"            font-family: Arial, sans-serif;"
"            margin: 0;"
"            padding: 0;"
"            background-color: #f0f0f0;"
"        }"
"        header {"
"            background-color: #007bff;"
"            color: white;"
"            padding: 20px;"
"            text-align: center;"
"        }"
"        nav {"
"            background-color: #333;"
"            color: white;"
"            padding: 10px;"
"            text-align: center;"
"        }"
"        nav a {"
"            color: white;"
"            text-decoration: none;"
"            padding: 10px;"
"        }"
"        nav a:hover {"
"            background-color: #555;"
"        }"
"        section {"
"            padding: 20px;"
"        }"
"        footer {"
"            background-color: #007bff;"
"            color: white;"
"            text-align: center;"
"            padding: 10px;"
"            position: fixed;"
"            bottom: 0;"
"            width: 100%;"
"        }"
"    </style>"
"</head>"
"<body>"
"    <header>"
"        <h1>Pingüinos</h1>"
"    </header>"
"    <nav>"
"        <a href=\"#informacion\">Información General</a>"
"        <a href=\"#especies\">Especies</a>"
"        <a href=\"#habitat\">Hábitat</a>"
"        <a href=\"#alimentacion\">Alimentación</a>"
"    </nav>"
"    <section id=\"informacion\">"
"        <h2>Información General</h2>"
"        <p>Los pingüinos son aves marinas no voladoras que habitan en el hemisferio sur. Son conocidos por su plumaje negro y blanco, y su habilidad para nadar y bucear.</p>"
"    </section>"
"    <section id=\"especies\">"
"        <h2>Especies de Pingüinos</h2>"
"        <ul>"
"            <li>Pingüino Emperador</li>"
"            <li>Pingüino Adelaida</li>"
"            <li>Pingüino de Magallanes</li>"
"            <li>Pingüino de Humboldt</li>"
"            <li>Pingüino de Galápagos</li>"
"        </ul>"
"    </section>"
"    <section id=\"habitat\">"
"        <h2>Hábitat</h2>"
"        <p>Los pingüinos habitan principalmente en regiones frías, como la Antártida y algunas islas cercanas al continente sudamericano.</p>"
"    </section>"
"    <section id=\"alimentacion\">"
"        <h2>Alimentación</h2>"
"        <p>La dieta de los pingüinos varía según la especie, pero generalmente consiste en peces, calamares y crustáceos.</p>"
"    </section>"
"    <footer>"
"        <p>&copy; 2024 Pingüinos Web - Todos los derechos reservados</p>"
"    </footer>"
"</body>"
"</html>";

;
// Handle root url (/)
void handle_root() {
server.send(200, "text/html", HTML);
}
void setup() {
Serial.begin(115200);
Serial.println("Try Connecting to ");
Serial.println(ssid);
// Connect to your wi-fi modem
WiFi.begin(ssid, password);
// Check wi-fi is connected to wi-fi network
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected successfully");
Serial.print("Got IP: ");
Serial.println(WiFi.localIP()); //Show ESP32 IP on serial
server.on("/", handle_root);
server.begin();
Serial.println("HTTP server started");
delay(100);
}
void loop() {
server.handleClient();
}


## Practica B  comunicación bluetooth con el movil 

El código de la practica es el siguiente


```
//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
}


```

Utilizar  la siguiente aplicación para realizar la comunicación serie 

![](https://i2.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/05/Bluetooth_Serial_app.png?w=500&quality=100&strip=all&ssl=1)



### Informe
  

  ### Introducció
  El programa connecta la esp32-S3 a un telèfon movil a trabés d'una conexió bluetooth. És necessaria una aplicació movil per la conexió. 
  ### Capçalera
  A l acapçalera s'introdueixen les llibreries necessaries per crear la conexió i s'utilitza una funció "if" per verificar que el bluetooth funciona correctament.

  ### Setup
  S'estableix la velocitat de comunicació a 115200, el nom del dispositiu i s'escriu per el serial monitor si la conexió ha estat correcte.

  ### Loop
  Comprova dos cops que el bluetooth està disponible avans de escriure i llegir la informació. Cada cop es repeteix amv un delay de 20ms.

### Codi sencer
#include<Arduino.h>
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); 
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
}