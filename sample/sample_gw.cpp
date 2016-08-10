#include <Windows.h>
#include "..\premades\dxhook_gw.hpp"

using namespace dx9hook;

HookHandler* dx_hooker = nullptr;
dx9::EndScene_t endscene_og;
HMODULE module;


struct Vert{
  float x,y,z;
  float rhw;
  DWORD color;
};


HRESULT WINAPI sample_EndScene(IDirect3DDevice9* device){

  Vert v[] = {
      {100.0f,100.0f,0.0f,0.0f,0xFF00FF00},
      {200.0f,100.0f,0.0f,0.0f,0xFF00FF00},
      {200.0f,200.0f,0.0f,0.0f,0xFF00FF00},
      {100.0f,200.0f,0.0f,0.0f,0xFF00FF00},
  };

  IDirect3DStateBlock9* stateBlock = NULL;
  device->CreateStateBlock(D3DSBT_ALL, &stateBlock); // Stateblock saves all the rendersettings, as we are going to modify them in order to draw our stuff

  device->SetRenderState(D3DRS_ALPHABLENDENABLE,1);
  device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
  device->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
  device->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);

  device->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,2,v,sizeof(Vert));

  stateBlock->Apply();
  stateBlock->Release();

  return endscene_og(device);
}



BOOL WINAPI DllMain(HMODULE hMod,DWORD dwReason,LPVOID){
  if(dwReason == DLL_PROCESS_ATTACH){
    dx_hooker = HookHandler::Create<GWDeviceFetcher>();

    endscene_og = dx_hooker->original<dx9::EndScene_t>(dx9::kEndScene);
    dx_hooker->AddHook(dx9::kEndScene,sample_EndScene);

  }
  else if (dwReason == DLL_PROCESS_DETACH){
  }
  return TRUE;
}
