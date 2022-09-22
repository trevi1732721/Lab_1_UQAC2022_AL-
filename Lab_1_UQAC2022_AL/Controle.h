#pragma once
#include <dshow.h>
#include <new>
#include <Windows.h>

using namespace std;

enum EtatDeFonction
{
    ETAT_NO_GRAPH,
    ETAT_ENCOURS,
    ETAT_PAUSE,
    ETAT_ARRET,
    ETAT_QUITTER,
    ETAT_ATTENTE,
};

class Controle
{
public:

    Controle();
    ~Controle();
    HRESULT controle(IMediaControl *pControl, IMediaSeeking *pSeeking, IGraphBuilder *pGraph);

private:
    
    void Play();
    void Pause();
    void AvanceRapide();
    void RetourOrigine();
    EtatDeFonction m_state;

};