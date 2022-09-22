#pragma comment(lib, "Strmiids.lib")
#include <stdio.h>
#include <conio.h>
#include <dshow.h>
#include <iostream>
#include "Controle.h"


using namespace std;


void main(void)
{
    IGraphBuilder* pGraph = NULL;
    IMediaControl* pControl = NULL;
    IMediaEvent* pEvent = NULL;
    IMediaSeeking* pSeeking = NULL;


    // Initialize the COM library.
    HRESULT hr = CoInitialize(NULL);
    if (FAILED(hr))
    {
        printf("ERROR - Could not initialize COM library");
        return;
    }

    // Create the filter graph manager and query for interfaces.
    hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER,
        IID_IGraphBuilder, (void**)&pGraph);
    if (FAILED(hr))
    {
        printf("ERROR - Could not create the Filter Graph Manager.");
        return;
    }

    hr = pGraph->QueryInterface(IID_IMediaControl, (void**)&pControl);
    hr = pGraph->QueryInterface(IID_IMediaEvent, (void**)&pEvent);
    hr = pGraph->QueryInterface(IID_IMediaSeeking, (void**)&pSeeking);

    // Build the graph. IMPORTANT: Change this string to a file on your system.
    hr = pGraph->RenderFile(L"Example.avi", NULL);
    Controle* newControl = new Controle;

    if (SUCCEEDED(hr))
    {
        // Run the graph.
        pControl->Run();
        pControl->Pause();

        if (SUCCEEDED(hr)) // vraiment necessaire ?
        {
            newControl->controle(pControl, pSeeking, pGraph);
        }
    }

    pControl->Release();
    pEvent->Release();
    pGraph->Release();
    CoUninitialize();

}