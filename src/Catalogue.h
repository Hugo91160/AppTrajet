/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H


//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "ListeChainee.h"
#include <string>
//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//Implémente une collection ordonnée de trajets (simples ou composés)
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    //

    ListeChainee * GetListeTrajets();
    //Mode d'emploi : 
    //Permet de renvoyer la liste chainee contenant tous les trajets 
    //Contrat: 
    //

    void Ecriture ( std::string nomFichier, std::string villeDepart = "", std::string villeArrivee = "" );
    //Mode d'emploi : 
    //Permet d'écrire dans un fihcier des trajets qui sont stockés dans le catalogue : 
    //sans critère de sélection -> on écrit tous les trajets dans le fichier (c'est pour cela que la ville de départ et d'arrivée sont des pramètres optionnels)
    //avec critère de sélection : selon le type de trajet ou selon la ville de départ et/ou d'arrivée

    void Ecriture ( std::string nomFichier, char typeTrajet );
    //Mode d'emploi :
    //Permet d'écrire dans une fichier des trajets qui sont dans le catalogue :
    //sans critère de sélection -> on écrit tous les trajets dans le fichier
    //avec critère de sélection : selon le type de trajet ou selon la ville de départ et/ou d'arrivée
    //Contrat  : 
    //


    void Lecture(std::string nomFichier, char typeTrajet);
    //Mode d'emploi : 
    //Permet la  lecturre depuis un fichier dans un catalogue à partir d'un type de trajet 
    //Contrat : 
    //on suppose ici que l'utilisateur veut un type de trajet en particulier 

    void Lecture(std::string nomFichier, std::string villeDepart = "", std::string villeArrivee = "");
    //Mode d'emploi : 
    //Permet la lecture depuis un fichier dans une catalogue en fonction des données de l'utilisateur.
    //L'utilisateur peut décicider choisir la ville de départ et/ou d'arrivée ou peut décider de prendre tous les trajets

    void RechercheAvancee(const char * Depart, const char * Arrivee) const;
    //Mode d'emploi : 
    //Permet de renvoyer la liste de tous les trajets possibles correspondant au départ et à a destination voulue par l'utilisateur
    //Contrat :
    //

    void DFS(ListeChainee * listeChemins, const char * dest, const char * noeudAct) const ;
    // Mode d'emploi : 
    //Effectue une recherche récursive permettant de trouver toutes les combinaisons possibles entre un départ et une arrivée
    // Contrat : 
    //Ne peut être appelée que depuis la fonction RechercheAvancee, qui lance une recherche récursive grâce à la méthode DFS. 
    //Cette méthode n'a pas à être appelée indépendamment de la méthode RechercheAvancee()

    void RechercheTrajet(const char * vd, const char * va) const;
    //Mode d'emploi : 
    // Renvoie les trajets qui sont dans le catalogue et qui correspondent au départ et à l'arrivée entrée par l'utilisateur


    void AfficheCatalogue() const;
    //Mode d'emploi : 
    //Permet d'afficher tous les trajets du catalogue (indépendamment du type trajet)

    
    void AjouteTrajet(Trajet * unTrajet);
    // Mode d'emploi : 
    //Permet d'ajoute un tajet (peu importe son type) au catalogue
    // Contrat : 
    //L'allocation mémoire de l objet pointé par unTrajet doit être faite au préalable

//-------------------------------------------- Constructeur - Destructeur
    Catalogue ();
    // Mode d'emploi :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	ListeChainee * listeTrajets;
//----------------------------------------------------- Attributs protégés

};

#endif // CATALOGUE_H


