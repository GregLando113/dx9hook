#pragma once

#include "..\dx9hook.hpp"

class GWDeviceFetcher : public dx9hook::DeviceFetcher {
public:

  virtual IDirect3DDevice9* GetDevice() override {

  struct d3ddev_ptr_chain {
		  struct sub2 {
			 BYTE pad[0x90];
			 IDirect3DDevice9* device;
		  }**dx_array; // Index
		DWORD sub2_size_alloc;
		DWORD sub2_size;
	} *base = nullptr;


	const BYTE dxdevicebasecode[] = { 0x89,0x45,0xF4,0x8B,0x45,0xFC,0x33,0xF6 };

	for (BYTE* i = (BYTE*)0x401000; i < (BYTE*)0x900000; ++i)
	{
		if (!memcmp(i, dxdevicebasecode, sizeof(dxdevicebasecode)))
		{
			base = *(d3ddev_ptr_chain**)(i - 0xE);
			break;
		}
	}

      if (!base) return nullptr;
        return base->dx_array[1]->device;
    }

};
