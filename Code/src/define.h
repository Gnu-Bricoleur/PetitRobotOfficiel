#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED



// definition des pins de la Mega


#define MoteurDroit 3
#define MoteurGauche 2
#define In1MoteurDroit 32
#define In2MoteurDroit 34
#define In3MoteurGauche 28
#define In4MoteurGauche 30
#define LassoPin 42
#define FunnyActionPin 40
#define GpioTirette 22
#define GpioJaune 24
#define GpioBleu 26
#define DetectAvant A8
#define DetectArriere A9

//definition des constantes

#define PWMMax 200
#define FrequenceEchantillonnage 50
#define NbTickPeriodique 100



//definition des variables globales
//Pour l'assert en vitesse
#define PD 1.2 //:-)
#define ID 0.001 //;-)
#define DD 0.5  //;-))

#define PG 1.5
#define IG 0.001
#define DG 0.5

#define PA 0.01
#define IA 0.001
#define DA 0.005

#define Separateur ';'

#define MaxI 100
#define NombreValeursI 25
int ListeIDroit[NombreValeursI];
int ListeIGauche[NombreValeursI];

#define CoefMagique 1.5

int ConsigneAngle;
int TimerId;
int CodeuseDroit;
int CodeuseGauche;
int AncienneCodeuseDroit;
int AncienneCodeuseGauche;
unsigned long Temps;
unsigned long DateAssert;
int ErreurDroit;
int SommeErreurDroit;
int DeltaErreurDroit;
int ErreurGauche;
int SommeErreurGauche;
int DeltaErreurGauche;
int AncienneErreur;
int ConsigneVitesse;
int AncienneErreurDroit;
int AncienneErreurGauche;
int PWMDroit;
int PWMGauche;
int PrecisionDroit;
int Parcouru;
int PrecisionAssert;
bool FinDroit;
bool FinGauche;
int Consigne;
int IndexTableau;


int ErreurAngulaire;
int ListeIAngulaire[NombreValeursI];
int SommeErreurAngulaire;
int DeltaErreurAngulaire;
int AncienneErreurAngulaire;
int PWMAngulaire;

int CorrectionEnAngle;

//Pour verifier Frequence assert
unsigned long DateDernierPassage;


//POur tester du codeuse
bool BetaCode;

// Pour Activer la DetectionActive
bool PriseEnCompteDetection;


//Pour la machine d'état
int EtatCourant;
char Actions[100];
//A => Avancer; R=> reculer; W => wait; F => funny action; L=> Leve pince : B => baisse pince ; T => tourne
long Param[100];
int Vitesse[100];
bool EtatComplete;


// Pour l'init et la Tirette
 bool Bleu;
 bool Tirette;
 unsigned long TempsDebut;


//pour la fonction d'attente
bool DebutAttente;
unsigned long TempsDebutAttente;



// pour la DetectionActive
bool DetectionActive;



#endif // DEFINE_H_INCLUDED
