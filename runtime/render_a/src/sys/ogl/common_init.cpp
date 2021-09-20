#include "bdefs.h"

#include "render.h"


void rdll_OGlRenderSetup(RenderStruct *pStruct)
{

}

RMode* rdll_GetSupportedModes() // RKJ STUB for the openGL Renderer
{
    return nullptr;
}

void rdll_FreeModeList(RMode *pCur) // free the allocated RMode linked list
{
    RMode *pNext = nullptr;
    while (pCur)
    {
        pNext = pCur->m_pNext;
        delete pCur;
        pCur = pNext;
    }
}
