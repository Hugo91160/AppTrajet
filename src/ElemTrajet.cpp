/*************************************************************************
                           ElemTrajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ElemTrajet> (fichier ElemTrajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ElemTrajet.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
//
//
//

void ElemTrajet::AfficheTrajet() const
{
	traj -> AfficheTrajet();
}

void ElemTrajet::SetNext(ElemTrajet *ptrElemTrajet)
{
	trajSuivant = ptrElemTrajet; //on fait pointer le trajet suivant sur un trajet passé en paramètre
}

ElemTrajet* ElemTrajet::GetNext()
{
	return trajSuivant;
}

Trajet * ElemTrajet::GetTraj()
{
	return traj;
}
//------------------------------------------------- Surcharge d'opérateurs
/*
Xxx & Xxx::operator = ( const Xxx & unXxx )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
ElemTrajet::ElemTrajet ( const ElemTrajet & unElemTrajet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ElemTrajet>" << endl;
#endif

} //----- Fin de Xxx (constructeur de copie)


ElemTrajet::ElemTrajet (Trajet * unTrajet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ElemTrajet>" << endl;
#endif
    	
	trajSuivant = new ElemTrajet;
	trajSuivant = nullptr;
	traj = unTrajet;

} //----- Fin de ElemTrajet


ElemTrajet::~ElemTrajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ElemTrajet>" << endl;
#endif

	if (HasNext( ))
	{
		delete trajSuivant;
	}

} //----- Fin de ~Xxx


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

bool ElemTrajet::HasNext ( )
{
	if (trajSuivant == nullptr)
	{
		return false;
	}
	return true;
}

