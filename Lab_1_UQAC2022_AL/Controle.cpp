#include "Controle.h"
#pragma comment(lib, "Strmiids.lib")
#include <stdio.h>
#include <conio.h>
#include <dshow.h>
#include <iostream>

Controle::Controle()
{
}

Controle::~Controle()
{
}

HRESULT Controle::controle(IMediaControl* pControl, IMediaSeeking *pSeeking, IGraphBuilder *pGraph)
{
    char selectionControle = 'a';
    m_state = ETAT_PAUSE;
    LONGLONG posDebut;
    LONGLONG posEnd;
    pSeeking->GetPositions(&posDebut, &posEnd);
    cout << posDebut << endl;
    cout << posEnd;

    while (selectionControle != 'q' && selectionControle != 'Q') {

        selectionControle = _getch();
        switch (selectionControle) {

        case 'A':
        case 'a':

            double rate;
   
            pSeeking->GetRate(&rate);
            if (rate == 1.5) {
                cout << "already done at 1.5";
            }else{
                cout << "set at 1.5";
                pSeeking->SetRate(1.5);
            }
           
            break;

        case 'P':
        case 'p':

            if(m_state != ETAT_ARRET) {

                if(m_state == ETAT_ENCOURS) {
                   cout << "Pause \n";
                   pControl->Pause();
                   m_state = ETAT_PAUSE;
                }else if (m_state == ETAT_PAUSE) {
                   cout << "Play \n"; 
                   pControl->Run();
                   m_state = ETAT_ENCOURS;
                }

            }
            
            break;
        case 'R':
        case 'r':
           pControl->Stop();
           pGraph->RenderFile(L"Example.avi", NULL);
           pControl->Run();

           // LONGLONG begining;
           // LONGLONG posCourant;
           // LONGLONG posEnd;
           // begining = 0;
           // pSeeking->GetPositions(&posCourant, &posEnd);
           // cout << posCourant;
           // if (posCourant != 0) {
           //     cout << "pasAuDebut";
           //     pSeeking->SetPositions(&begining, AM_SEEKING_NoPositioning, &posEnd, AM_SEEKING_NoPositioning);
           //     pSeeking->GetPositions(&posCourant, &posEnd);
           //     cout << posCourant;
           //     cout << posEnd;
           // }
           // else {
           //     cout << "estAuDébut";
           //     pSeeking->SetRate(1.5);
           // }
           // 
            break;
        default:
            break;
        }
    } 
    
    return E_NOTIMPL;    
}

void Controle::Play()
{
}

void Controle::Pause()
{
}

void Controle::AvanceRapide()
{
}

void Controle::RetourOrigine()
{
}
