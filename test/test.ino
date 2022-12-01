#include <Keypad.h>  

 
const byte LIGNES = 4; // 4 lignes
const byte COLONNES = 4; //4 colonnes

const int C4=2; //declaration constante de broche
const int C3=3; //declaration constante de broche
const int C2=4; //declaration constante de broche
const int C1=5; //declaration constante de broche

const int L4=17; //declaration constante de broche
const int L3=16; //declaration constante de broche
const int L2=15; //declaration constante de broche
const int L1=14; //declaration constante de broche

char touches[LIGNES][COLONNES] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// tableaux de lignes et colonnes
byte BrochesLignes[LIGNES] = {L1, L2, L3, L4}; //connexions utilisées pour les broches de lignes du clavier
byte BrochesColonnes[COLONNES] = {C1, C2, C3, C4}; //connexions utilisées pour les broches de colonnes du clavier

char touche; // variable de stockage valeur touche appuyée


// création d'un objet keypad = initialisation clavier
Keypad clavier = Keypad( makeKeymap(touches), BrochesLignes, BrochesColonnes, LIGNES, COLONNES );
// les broches de lignes sont automatiquement configurées en ENTREE avec pullup interne activé
// les broches de colonnes sont automatiquement configurées en SORTIE

const int MAXBUFFER = 20;
char message[MAXBUFFER];   // initialisé à '\0' par le compilateur
unsigned int messageIndex; 
    boolean saisieEnCours = true;

//**************** FONCTION SETUP = Code d'initialisation *****
// La fonction setup() est exécutée en premier et 1 seule fois, au démarrage du programme
void lireUneReponse()
{
  while (saisieEnCours) {
    touche = clavier.getKey();// lecture de la touche appuyée
    switch (touche) {
      case NO_KEY: // on ne fait rien, on n'a rien reçu
        break;
      case '*': // valider l'entrée
        saisieEnCours = false;
        Serial.write("*");

        break;   
      default:
        message[messageIndex++] = touche;
        message[messageIndex] = '\0';// pour toujours avoir un chaîne de caractère bien formée.
          if (messageIndex >= MAXBUFFER - 1) {
          saisieEnCours = false; // l'entrée est validée car trop de caractères
        }
                Serial.write(message);

       break;
  }
  }
    //Serial.print("le message est: ["); Serial.print(message); Serial.println("]");
  
}
void setup()   { // debut de la fonction setup()

// --- ici instructions à exécuter au démarrage ---
  Serial.begin(115200); // Mettre la console Arduino sur 115200!!
  lireUneReponse();
  
} 

//*************** FONCTION LOOP = Boucle sans fin = coeur du programme *************

void loop(){
  //lireUneReponse();
  
}  
