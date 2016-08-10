#include "..\dx9hook.hpp"

dx9hook::HookHandler::HookHandler(DeviceFetcher* fetcher)
{
  DWORD oldprot;

  device_ = fetcher->GetDevice();
  if(!device_) throw D3D_DEVICE_NULL;

  vft_ = new void*[0x200];
  VirtualProtect(vft_,0x200 * sizeof(void*),PAGE_EXECUTE_READWRITE,&oldprot);

  vft_original_ = *(void***)device_;

  VirtualProtect(vft_original_,0x200 * sizeof(void*),PAGE_EXECUTE_READWRITE,&oldprot);
  memcpy(vft_,vft_original_,0x200 * sizeof(void*));
  VirtualProtect(vft_original_,0x200 * sizeof(void*),oldprot,&oldprot);

  VirtualProtect(vft_original_,sizeof(void*),PAGE_EXECUTE_READWRITE,&oldprot);
  InterlockedExchangePointer((void**)device_,(void*)vft_);
  VirtualProtect(vft_original_,sizeof(void*),oldprot,&oldprot);
}

void dx9hook::HookHandler::Release()
{
  DWORD oldprot;
  VirtualProtect(vft_original_,sizeof(void*),PAGE_EXECUTE_READWRITE,&oldprot);
  InterlockedExchangePointer((void**)device_,(void*)vft_original_);
  VirtualProtect(vft_original_,sizeof(void*),oldprot,&oldprot);
}
