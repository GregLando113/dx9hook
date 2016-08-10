#ifndef _DX9_HOOK
#define _DX9_HOOK

#include <Windows.h>

#include "include\d3d9\d3d9.h"
#include "include\d3d9\d3dx9.h"

#include "include\dxDeclarations.h"

namespace dx9hook
{

  class DeviceFetcher {
  public:
    virtual IDirect3DDevice9* GetDevice() = 0;
  };

  class HookHandler {
  public:

    enum Exception{
      D3D_DEVICE_NULL
    };

    template <typename _FuncType>
    inline _FuncType original(size_t index){
      return (_FuncType)vft_original_[index];
    }


    void AddHook(size_t index,void* function){
      vft_[index] = function;
    }


    template <typename _Fetcher>
    static HookHandler* Create() {
      return new HookHandler(new _Fetcher());
    }

    void Release();

  private:

    HookHandler(DeviceFetcher*);

    IDirect3DDevice9* device_;

    void** vft_;
    void** vft_original_;

  };



}

#endif /* end of include guard: _DX9_HOOK */
