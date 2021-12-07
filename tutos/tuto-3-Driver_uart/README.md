# Driver UART (liaison série)

Ce code permet d'envoyer des information depuis le RPi par une liaison série.
Il faut alors connecter un GPIO Ground du RPi au Ground de l'appareil récepteur.
Connexter le GPIO Trancemeteur (TX) du RPi (le GPIO 14) au Recepteur (RX) de l'appareil récepteur.
Connexter le GPIO Recepteur (RX) du RPi (le GPIO 14) au Recepteur (TX) de l'appareil récepteur.

Pour cela, il existe des USB to TTL sure le marché.
Personnelement, j'ai utilisé une carte Arduino UNO avec ce code:

```
void setup() {
  Serial.begin(115200);

}

void loop() {
  char c;  // important de passer par un "char" sinon "97" sera affiché à la place de "a" (table ascii)
  if(Serial.available()){
    c = Serial.read();
    Serial.print(c);
  }
}
```