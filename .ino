// Equipe 7: CESI de Rouen

String toString(double value);
int toInt(String text);
double toDouble(String text);
int cleAgent(String x);
int e, mp, c;
long m;
String x;
void mA1();
void mA2();
void mA3();
void mA4();
void mA5();
void setup() {
  // Initialisez ici vos broches et paramètres Arduino si nécessaire
  Serial.begin(9600); // Initialisation de la communication série
  randomSeed(analogRead(0));
  Serial.println("Identifiez-vous:");
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  // Code principal d'exécution du programme
  String z;
  Serial.println("Donnez le modele de la carte (M01, MO2, ..., MO8):");
  while (Serial.available() == 0) {} // Attente de l'entrée utilisateur
  z = Serial.readString();
  if (z == "MO1") {
    delay(2000); // Attente de 2 secondes
    Serial.println("Vous avez choisi le modele " +z);
    delay(2000); // Attente de 2 secondes
    nS1();
  } else if (z == "MO2") {
    delay(2000); // Attente de 2 secondes
    Serial.println("Vous avez choisi le modele " +z);
    delay(2000); // Attente de 2 secondes
    nS4();
  } else if (z == "MO3" || z == "MO4") {
    delay(2000); // Attente de 2 secondes
    Serial.println("Vous avez choisi le modele " +z);
    delay(2000); // Attente de 2 secondes
    nS2();
  } else if (z == "MO5" || z == "MO6") {
    delay(2000); // Attente de 2 secondes
    Serial.println("Vous avez choisi le modele " +z);
    delay(2000); // Attente de 2 secondes
    nS3();
  } else if (z == "MO8"|| z == "MO7") {
    delay(2000); // Attente de 2 secondes
    Serial.println("Vous avez choisi le modele " +z);
    delay(2000); // Attente de 2 secondes
    nS5();
  } else {
    Serial.println("Modele de carte non valide.");
  }
}

void mA1() {
  int reponses;
  Serial.println("Vous allez devoir repondre au QCM suivant:");
  delay(2000); // Attente de 2 secondes
  Serial.println("Quel agent devons-nous remplacer lors d'une mission prioritaire car il est malade?");
  delay(1000); // Attente de 1 secondes
  Serial.println("1. Agent M");
  Serial.println("2. Agent R");
  Serial.println("3. Arnold");
  while (Serial.available() == 0) {} // Attente de l'entrée utilisateur
  reponses = Serial.parseInt();
  if (reponses == 1) {
    delay(1000); // Attente de 1 secondes
    Serial.println("Bonne reponse.");
    delay(1000); // Attente de 1 secondes
    Serial.println("Qui avons-nous du remplacer lors de ses vacances?");
    delay(1000); // Attente de 1 secondes
    Serial.println("1. Arnold");
    Serial.println("2. Agent M");
    Serial.println("3. Arnold M");
    while (Serial.available() == 0) {} // Attente de l'entrée utilisateur
    reponses = Serial.parseInt();
    if (reponses == 2) {
      delay(1000); // Attente de 1 secondes
      Serial.println("Bonne reponse.");
      delay(1000); // Attente de 1 secondes
      Serial.println("A qui appartenait l'artefact?");
      delay(1000); // Attente de 1 secondes
      Serial.println("1. Arnold");
      Serial.println("2. Vincent");
      Serial.println("3. Agent M");
      while (Serial.available() == 0) {} // Attente de l'entrée utilisateur
      reponses = Serial.parseInt();
      if (reponses == 2) {
        // Autre action
      } else {
        delay(1000); // Attente de 1 secondes
        Serial.println("Erreur d'authentification, le systeme est bloque.");
        digitalWrite(3, HIGH);
        while (1) { // Boucle infinie pour arrêter complètement le code
        }
      }
    } else {
      delay(1000); // Attente de 1 secondes
      Serial.println("Erreur d'authentification, le systeme est bloque.");
      digitalWrite(3, HIGH);
      while (1) { // Boucle infinie pour arrêter complètement le code
        }
    }
  } else {
    delay(1000); // Attente de 1 secondes
    Serial.println("Erreur d'authentification, le systeme est bloque.");
    digitalWrite(3, HIGH);
      while (1) { // Boucle infinie pour arrêter complètement le code
      }
  }
}

void mA2() {
  Serial.println("Identifiez-vous:");
  
  while (Serial.available() == 0) {} // Attente que l'utilisateur entre une lettre
  
  if (Serial.available() > 0) {
    char x = Serial.read(); // Lire un seul caractère
    String xString = String(x); // Convertir le caractère en une chaîne de caractères
    xString.toUpperCase();
  
    if (xString >= "A" && xString <= "Q") {
      long m = random(2881L); // Utilisation de 'L' pour indiquer que 2881 est un long
      int e = cleAgent(xString);
      int c = chiffrer(m, e);
      
      Serial.print("message à dechiffrer : ");
      Serial.println(c);
      Serial.println("Attendez la saisie de Mp");
      
      while (Serial.available() == 0) {}
      int mp = Serial.parseInt();
      
      if (m == mp) {
      } else {
        Serial.println("Erreur d'authentification, le systeme est bloque.");
        digitalWrite(3, HIGH);
        while (1) { // Boucle infinie pour arrêter complètement le code
        }
      }
    } else {
      Serial.println("Caractère invalide. Entrez une lettre de A à Q.");
      Serial.println("Erreur d'authentification, le systeme est bloque.");
      digitalWrite(3, HIGH); 
      while (1) { // Boucle infinie pour arrêter complètement le code
      }
    }
  }
}

void mA3() {
  bool oeil;
  Serial.println("Placez votre oeil correctement (t ou f) :");
  while (Serial.available() == 0) {}
  oeil = Serial.read() == 't'; // Lit un caractère ('t' pour true, 'f' pour false)
  if (oeil == true) {
    // Autre action
  } else {
    Serial.println("L'oeil n'a pas ete reconnu, le systeme est bloque.");
    digitalWrite(3, HIGH);
    while (1) {}// Boucle infinie pour arrêter complètement le code
  }
}

void mA4() {
  bool empreinte;
  Serial.println("Placez votre doigt correctement sur le dispositif de scan (true ou false) :");
  while (Serial.available() == 0) {}
  empreinte = Serial.read() == 't'; // Lit un caractère ('t' pour true, 'f' pour false)
  if (empreinte == true) {
    // Autre action
  } else {
    Serial.println("Empreinte non reconnue, le systeme est bloque.");
    digitalWrite(3, HIGH);
    while (1) {}// Boucle infinie pour arrêter complètement le code
  }
}

void mA5() {
  String lettre[16];
  lettre[0] = "A";
  lettre[1] = "B";
  lettre[2] = "C";
  lettre[3] = "D";
  lettre[4] = "E";
  lettre[5] = "F";
  lettre[6] = "H";
  lettre[7] = "I";
  lettre[8] = "J";
  lettre[9] = "K";
  lettre[10] = "L";
  lettre[11] = "M";
  lettre[12] = "N";
  lettre[13] = "O";
  lettre[14] = "P";
  lettre[15] = "Q";
  int numeroCarte[16];
  numeroCarte[0] = 0;
  numeroCarte[1] = 1;
  numeroCarte[2] = 10;
  numeroCarte[3] = 11;
  numeroCarte[4] = 100;
  numeroCarte[5] = 101;
  numeroCarte[6] = 110;
  numeroCarte[7] = 111;
  numeroCarte[8] = 1000;
  numeroCarte[9] = 1001;
  numeroCarte[10] = 1010;
  numeroCarte[11] = 1011;
  numeroCarte[12] = 1100;
  numeroCarte[13] = 1101;
  numeroCarte[14] = 1110;
  numeroCarte[15] = 1111;
  String lettreAgent;
  int numeroAgent;
  Serial.println("Entrez votre lettre d'agent (A, B, C, ..., P, Q) :");
  while (Serial.available() == 0) {}
  lettreAgent = Serial.readString();
  if (lettreAgent == lettre[0]) {
    Serial.println("Entrez votre numero d'agent :");
    while (Serial.available() == 0) {}
    numeroAgent = Serial.parseInt();
    if (numeroAgent == numeroCarte[0]) {
      // Autre action
    } else {
      Serial.println("Attention : Tentative d'intrusion.");
    }
  } 
  else if (lettreAgent == lettre[1]) {
     Serial.println("Entrez votre numero d'agent :");
     while (Serial.available() == 0) {}
     numeroAgent = Serial.parseInt();
     if (numeroAgent == numeroCarte[1]) {
      // Autre action
    } else {
      Serial.println("Attention : Tentative d'intrusion.");
    }
  }
   else if (lettreAgent == lettre[2]) {
     Serial.println("Entrez votre numero d'agent :");
     while (Serial.available() == 0) {}
     numeroAgent = Serial.parseInt();
     if (numeroAgent == numeroCarte[2]) {
      // Autre action
    } else {
      Serial.println("Attention : Tentative d'intrusion.");
    }
   }
    else if (lettreAgent == lettre[3]) {
     Serial.println("Entrez votre numero d'agent :");
     while (Serial.available() == 0) {}
     numeroAgent = Serial.parseInt();
     if (numeroAgent == numeroCarte[3]) {
      // Autre action
    } else {
      Serial.println("Attention : Tentative d'intrusion.");
    }
    }
    else if (lettreAgent == lettre[4]) {
     Serial.println("Entrez votre numero d'agent :");
     while (Serial.available() == 0) {}
     numeroAgent = Serial.parseInt();
     if (numeroAgent == numeroCarte[4]) {
      // Autre action
    } else {
      Serial.println("Attention : Tentative d'intrusion.");
    }
    }
   else if (lettreAgent == lettre[5]) {
     Serial.println("Entrez votre numero d'agent (en binaire) :");
     while (Serial.available() == 0) {}
     numeroAgent = Serial.parseInt();
     if (numeroAgent == numeroCarte[5]) {
      // Autre action
    } else {
      Serial.println("Attention : Tentative d'intrusion.");
    }
   }
   else if (lettreAgent == lettre[6]) {
     Serial.println("Entrez votre numero d'agent (en binaire):");
     while (Serial.available() == 0) {}
     numeroAgent = Serial.parseInt();
     if (numeroAgent == numeroCarte[6]) {
      // Autre action
    } else {
      Serial.println("Attention : Tentative d'intrusion.");
    }
   }
   else if (lettreAgent == lettre[7]) {
     Serial.println("Entrez votre numero d'agent (en binaire):");
     while (Serial.available() == 0) {}
     numeroAgent = Serial.parseInt();
     if (numeroAgent == numeroCarte[7]) {
      // Autre action
    } else {
      Serial.println("Attention : Tentative d'intrusion.");
    }
   }
   else if (lettreAgent == lettre[8]) {
     Serial.println("Entrez votre numero d'agent (en binaire):");
     while (Serial.available() == 0) {}
     numeroAgent = Serial.parseInt();
     if (numeroAgent == numeroCarte[8]) {
      // Autre action
    } else {
      Serial.println("Attention : Tentative d'intrusion.");
    }
   }
   else if (lettreAgent == lettre[9]) {
     Serial.println("Entrez votre numero d'agent (en binaire):");
     while (Serial.available() == 0) {}
     numeroAgent = Serial.parseInt();
     if (numeroAgent == numeroCarte[9]) {
      // Autre action
    } else {
      Serial.println("Attention : Tentative d'intrusion.");
    }
   }
   else if (lettreAgent == lettre[10]) {
     Serial.println("Entrez votre numero d'agent (en binaire):");
     while (Serial.available() == 0) {}
     numeroAgent = Serial.parseInt();
     if (numeroAgent == numeroCarte[10]) {
      // Autre action
    } else {
      Serial.println("Attention : Tentative d'intrusion.");
    }
   }
   else if (lettreAgent == lettre[11]) {
     Serial.println("Entrez votre numero d'agent (en binaire):");
     while (Serial.available() == 0) {}
     numeroAgent = Serial.parseInt();
     if (numeroAgent == numeroCarte[11]) {
      // Autre action
    } else {
      Serial.println("Attention : Tentative d'intrusion.");
    }
   }
   else if (lettreAgent == lettre[12]) {
     Serial.println("Entrez votre numero d'agent (en binaire):");
     while (Serial.available() == 0) {}
     numeroAgent = Serial.parseInt();
     if (numeroAgent == numeroCarte[12]) {
      // Autre action
    } else {
      Serial.println("Attention : Tentative d'intrusion.");
    }
   }
   else if (lettreAgent == lettre[13]) {
     Serial.println("Entrez votre numero d'agent (en binaire):");
     while (Serial.available() == 0) {}
     numeroAgent = Serial.parseInt();
     if (numeroAgent == numeroCarte[13]) {
      // Autre action
    } else {
      Serial.println("Attention : Tentative d'intrusion.");
    }
   }
   else if (lettreAgent == lettre[14]) {
     Serial.println("Entrez votre numero d'agent (en binaire):");
     while (Serial.available() == 0) {}
     numeroAgent = Serial.parseInt();
     if (numeroAgent == numeroCarte[14]) {
      // Autre action
    } else {
      Serial.println("Attention : Tentative d'intrusion.");
    }
   }
   else if (lettreAgent == lettre[15]) {
     Serial.println("Entrez votre numero d'agent (en binaire):");
     while (Serial.available() == 0) {}
     numeroAgent = Serial.parseInt();
     if (numeroAgent == numeroCarte[15]) {
      // Autre action
    } else {
      Serial.println("Attention : Tentative d'intrusion.");
    }
 
  } 
  else {
    Serial.println("Lettre d'agent invalide.");
    digitalWrite(3, HIGH);
  }
}

void nS1() {
  mA1();
  delay(2000); // Attente de 2 secondes
  Serial.println("Bravo, vous avez passe la premiere securite du coffre.");
  delay(2000); // Attente de 2 secondes
  mA3();
  delay(2000); // Attente de 2 secondes
  Serial.println("Bonjour Agent.");
  digitalWrite(2, HIGH); // Allumer la LED connectée à la broche 2
  while (1) {}
}

void nS2() {
  mA1();
  delay(2000); // Attente de 2 secondes
  Serial.println("Bravo, vous avez passe la premiere securite du coffre.");
  delay(2000); // Attente de 2 secondes
  mA4();
  delay(2000); // Attente de 2 secondes
  Serial.println("Bonjour Agent.");
  digitalWrite(2, HIGH); // Allumer la LED connectée à la broche 2
  while (1) {}
}

void nS3() {
  mA5();
  delay(2000); // Attente de 2 secondes
  Serial.println("Bravo, vous avez passe la premiere securite du coffre.");
  delay(2000); // Attente de 2 secondes
  mA2();
  delay(2000); // Attente de 2 secondes
  Serial.println("Bonjour Agent.");
  digitalWrite(2, HIGH); // Allumer la LED connectée à la broche 2
  while (1) {}
}

void nS4() {
  mA2();
  delay(2000); // Attente de 2 secondes
  Serial.println("Bravo, vous avez passe la premiere securite du coffre.");
  delay(2000); // Attente de 2 secondes
  mA3();
  delay(2000); // Attente de 2 secondes
  Serial.println("Bravo, vous avez passe la deuxieme securite du coffre.");
  delay(2000); // Attente de 2 secondes
  mA4();
  delay(2000); // Attente de 2 secondes
  Serial.println("Bonjour Agent.");
  digitalWrite(2, HIGH); // Allumer la LED connectée à la broche 2
  while (1) {}
}

void nS5() {
  mA1();
  delay(2000); // Attente de 2 secondes
  Serial.println("Bravo, vous avez passe la premiere securite du coffre.");
  delay(2000); // Attente de 2 secondes
  mA2();
  delay(2000); // Attente de 2 secondes
  Serial.println("Bravo, vous avez passe la deuxieme securite du coffre.");
  delay(2000); // Attente de 2 secondes
  mA3();
  delay(2000); // Attente de 2 secondes
  Serial.println("Bravo, vous avez passe la troisieme securite du coffre.");
  delay(2000); // Attente de 2 secondes
  mA5();
  delay(2000); // Attente de 2 secondes
  Serial.println("Bonjour Agent.");
  digitalWrite(2, HIGH); // Allumer la LED connectée à la broche 2
  while (1) {}
}

int chiffrer(long m, int e) { // Modifié le type de m en long
  int n = 43 * 67;
  int c = modexp(m, e, n);
  return c;
}

int cleAgent(String x) {
  int e; // Gardé comme int

  if (x == "A") {
    e = 601;
  } else if (x == "B") {
    e = 619;
  } else if (x == "C") {
    e = 631;
  } else if (x == "D") {
    e = 641;
  } else if (x == "E") {
    e = 647;
  } else if (x == "F") {
    e = 653;
  } else if (x == "H") {
    e = 661;
  } else if (x == "I") {
    e = 673;
  } else if (x == "J") {
    e = 691;
  } else if (x == "K") {
    e = 701;
  } else if (x == "L") {
    e = 733;
  } else if (x == "M") {
    e = 739;
  } else if (x == "N") {
    e = 751;
  } else if (x == "O") {
    e = 797;
  } else if (x == "P") {
    e = 809;
  } else if (x == "Q") {
    e = 811;
  }

  return e;
}

int modexp(long a, int e, int n) { // Modifié le type de a en long
  int r;

  if (e < 0) {
    Serial.println("Cas non géré");
    exit(-1);
  }
  if (a == 0 || n == 1) {
    r = 0;
  } else {
    r = 1;
    while (e > 0) {
      r = (r * (a % n)) % n;
      e = e - 1;
    }
  }

  return r;
}
