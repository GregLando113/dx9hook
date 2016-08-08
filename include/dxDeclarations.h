#pragma once

#include "d3d9\d3d9.h"
#include "d3d9\d3dx9.h"

namespace dx9 {

		// IDirect3DDevice Index Enumerations

		enum e_DX9VtableIndex {
			kQueryInterface, kAddRef, kRelease, kTestCooperativeLevel, kGetAvailableTextureMem,
			kEvictManagedResources, kGetDirect3D, kGetDeviceCaps, kGetDisplayMode, kGetCreationParameters,
			kSetCursorProperties, kSetCursorPosition, kShowCursor, kCreateAdditionalSwapChain, kGetSwapChain,
			kGetNumberOfSwapChains, kReset, kPresent, kGetBackBuffer, kGetRasterStatus, kSetDialogBoxMode,
			kSetGammaRamp, kGetGammaRamp, kCreateTexture, kCreateVolumeTexture, kCreateCubeTexture,
			kCreateVertexBuffer, kCreateIndexBuffer, kCreateRenderTarget, kCreateDepthStencilSurface,
			kUpdateSurface, kUpdateTexture, kGetRenderTargetData, kGetFrontBufferData, kStretchRect,
			kColorFill, kCreateOffscreenPlainSurface, kSetRenderTarget, kGetRenderTarget, kSetDepthStencilSurface,
			kGetDepthStencilSurface, kBeginScene, kEndScene, kClear, kSetTransform, kGetTransform, kMultiplyTransform,
			kSetViewport, kGetViewport, kSetMaterial, kGetMaterial, kSetLight, kGetLight, kLightEnable, kGetLightEnable,
			kSetClipPlane, kGetClipPlane, kSetRenderState, kGetRenderState, kCreateStateBlock, kBeginStateBlock,
			kEndStateBlock, kSetClipStatus, kGetClipStatus, kGetTexture, kSetTexture, kGetTextureStageState,
			kSetTextureStageState, kGetSamplerState, kSetSamplerState, kValidateDevice, kSetPaletteEntries,
			kGetPaletteEntries, kSetCurrentTexturePalette, kGetCurrentTexturePalette, kSetScissorRect,
			kGetScissorRect, kSetSoftwareVertexProcessing, kGetSoftwareVertexProcessing, kSetNPatchMode,
			kGetNPatchMode, kDrawPrimitive, kDrawIndexedPrimitive, kDrawPrimitiveUP, kDrawIndexedPrimitiveUP,
			kProcessVertices, kCreateVertexDeclaration, kSetVertexDeclaration, kGetVertexDeclaration,
			kSetFVF, kGetFVF, kCreateVertexShader, kSetVertexShader, kGetVertexShader, kSetVertexShaderConstantF,
			kGetVertexShaderConstantF, kSetVertexShaderConstantI, kGetVertexShaderConstantI, kSetVertexShaderConstantB,
			kGetVertexShaderConstantB, kSetStreamSource, kGetStreamSource, kSetStreamSourceFreq, kGetStreamSourceFreq,
			kSetIndices, kGetIndices, kCreatePixelShader, kSetPixelShader, kGetPixelShader, kSetPixelShaderConstantF,
			kGetPixelShaderConstantF, kSetPixelShaderConstantI, kGetPixelShaderConstantI, kSetPixelShaderConstantB,
			kGetPixelShaderConstantB, kDrawRectPatch, kDrawTriPatch, kDeletePatch, kCreateQuery,

			kEnd = 0x200
		};

		// IDirect3DDevice Method declarations

		typedef HRESULT(WINAPI *TestCooperativeLevel_t)(IDirect3DDevice9* pDev);
		typedef UINT(WINAPI *GetAvailableTextureMem_t)(IDirect3DDevice9* pDev);
		typedef HRESULT(WINAPI *EvictManagedResources_t)(IDirect3DDevice9* pDev);
		typedef HRESULT(WINAPI **GetDirect3D_t)(IDirect3DDevice9* pDev, IDirect3D9** ppD3D9);
		typedef HRESULT(WINAPI *GetDeviceCaps_t)(IDirect3DDevice9* pDev, D3DCAPS9* pCaps);
		typedef HRESULT(WINAPI *GetDisplayMode_t)(IDirect3DDevice9* pDev, UINT iSwapChain, D3DDISPLAYMODE* pMode);
		typedef HRESULT(WINAPI *GetCreationParameters_t)(IDirect3DDevice9* pDev, D3DDEVICE_CREATION_PARAMETERS *pParameters);
		typedef HRESULT(WINAPI *SetCursorProperties_t)(IDirect3DDevice9* pDev, UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9* pCursorBitmap);
		typedef void (WINAPI *SetCursorPosition_t)(IDirect3DDevice9* pDev, int X, int Y, DWORD Flags);
		typedef BOOL(WINAPI *ShowCursor_t)(IDirect3DDevice9* pDev, BOOL bShow);
		typedef HRESULT(WINAPI *CreateAdditionalSwapChain_t)(IDirect3DDevice9* pDev, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DSwapChain9** pSwapChain);
		typedef HRESULT(WINAPI *GetSwapChain_t)(IDirect3DDevice9* pDev, UINT iSwapChain, IDirect3DSwapChain9** pSwapChain);
		typedef UINT(WINAPI *GetNumberOfSwapChains_t)(IDirect3DDevice9* pDev);
		typedef HRESULT(WINAPI *Reset_t)(IDirect3DDevice9* pDev, D3DPRESENT_PARAMETERS* pPresentationParameters);
		typedef HRESULT(WINAPI *Present_t)(IDirect3DDevice9* pDev, CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion);
		typedef HRESULT(WINAPI *GetBackBuffer_t)(IDirect3DDevice9* pDev, UINT iSwapChain, UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer);
		typedef HRESULT(WINAPI *GetRasterStatus_t)(IDirect3DDevice9* pDev, UINT iSwapChain, D3DRASTER_STATUS* pRasterStatus);
		typedef HRESULT(WINAPI *SetDialogBoxMode_t)(IDirect3DDevice9* pDev, BOOL bEnableDialogs);
		typedef void (WINAPI *SetGammaRamp_t)(IDirect3DDevice9* pDev, UINT iSwapChain, DWORD Flags, CONST D3DGAMMARAMP* pRamp);
		typedef void (WINAPI *GetGammaRamp_t)(IDirect3DDevice9* pDev, UINT iSwapChain, D3DGAMMARAMP* pRamp);
		typedef HRESULT(WINAPI *CreateTexture_t)(IDirect3DDevice9* pDev, UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle);
		typedef HRESULT(WINAPI *CreateVolumeTexture_t)(IDirect3DDevice9* pDev, UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle);
		typedef HRESULT(WINAPI *CreateCubeTexture_t)(IDirect3DDevice9* pDev, UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle);
		typedef HRESULT(WINAPI *CreateVertexBuffer_t)(IDirect3DDevice9* pDev, UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle);
		typedef HRESULT(WINAPI *CreateIndexBuffer_t)(IDirect3DDevice9* pDev, UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle);
		typedef HRESULT(WINAPI *CreateRenderTarget_t)(IDirect3DDevice9* pDev, UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle);
		typedef HRESULT(WINAPI *CreateDepthStencilSurface_t)(IDirect3DDevice9* pDev, UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle);
		typedef HRESULT(WINAPI *UpdateSurface_t)(IDirect3DDevice9* pDev, IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestinationSurface, CONST POINT* pDestPoint);
		typedef HRESULT(WINAPI *UpdateTexture_t)(IDirect3DDevice9* pDev, IDirect3DBaseTexture9* pSourceTexture, IDirect3DBaseTexture9* pDestinationTexture);
		typedef HRESULT(WINAPI *GetRenderTargetData_t)(IDirect3DDevice9* pDev, IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface);
		typedef HRESULT(WINAPI *GetFrontBufferData_t)(IDirect3DDevice9* pDev, UINT iSwapChain, IDirect3DSurface9* pDestSurface);
		typedef HRESULT(WINAPI *StretchRect_t)(IDirect3DDevice9* pDev, IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestSurface, CONST RECT* pDestRect, D3DTEXTUREFILTERTYPE Filter);
		typedef HRESULT(WINAPI *ColorFill_t)(IDirect3DDevice9* pDev, IDirect3DSurface9* pSurface, CONST RECT* pRect, D3DCOLOR color);
		typedef HRESULT(WINAPI *CreateOffscreenPlainSurface_t)(IDirect3DDevice9* pDev, UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle);
		typedef HRESULT(WINAPI *SetRenderTarget_t)(IDirect3DDevice9* pDev, DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget);
		typedef HRESULT(WINAPI *GetRenderTarget_t)(IDirect3DDevice9* pDev, DWORD RenderTargetIndex, IDirect3DSurface9** ppRenderTarget);
		typedef HRESULT(WINAPI *SetDepthStencilSurface_t)(IDirect3DDevice9* pDev, IDirect3DSurface9* pNewZStencil);
		typedef HRESULT(WINAPI *GetDepthStencilSurface_t)(IDirect3DDevice9* pDev, IDirect3DSurface9** ppZStencilSurface);
		typedef HRESULT(WINAPI *BeginScene_t)(IDirect3DDevice9* pDev);
		typedef HRESULT(WINAPI *EndScene_t)(IDirect3DDevice9* pDev);
		typedef HRESULT(WINAPI *Clear_t)(IDirect3DDevice9* pDev, DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil);
		typedef HRESULT(WINAPI *SetTransform_t)(IDirect3DDevice9* pDev, D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix);
		typedef HRESULT(WINAPI *GetTransform_t)(IDirect3DDevice9* pDev, D3DTRANSFORMSTATETYPE State, D3DMATRIX* pMatrix);
		typedef HRESULT(WINAPI *MultiplyTransform_t)(IDirect3DDevice9* pDev, D3DTRANSFORMSTATETYPE, CONST D3DMATRIX*);
		typedef HRESULT(WINAPI *SetViewport_t)(IDirect3DDevice9* pDev, CONST D3DVIEWPORT9* pViewport);
		typedef HRESULT(WINAPI *GetViewport_t)(IDirect3DDevice9* pDev, D3DVIEWPORT9* pViewport);
		typedef HRESULT(WINAPI *SetMaterial_t)(IDirect3DDevice9* pDev, CONST D3DMATERIAL9* pMaterial);
		typedef HRESULT(WINAPI *GetMaterial_t)(IDirect3DDevice9* pDev, D3DMATERIAL9* pMaterial);
		typedef HRESULT(WINAPI *SetLight_t)(IDirect3DDevice9* pDev, DWORD Index, CONST D3DLIGHT9*);
		typedef HRESULT(WINAPI *GetLight_t)(IDirect3DDevice9* pDev, DWORD Index, D3DLIGHT9*);
		typedef HRESULT(WINAPI *LightEnable_t)(IDirect3DDevice9* pDev, DWORD Index, BOOL Enable);
		typedef HRESULT(WINAPI *GetLightEnable_t)(IDirect3DDevice9* pDev, DWORD Index, BOOL* pEnable);
		typedef HRESULT(WINAPI *SetClipPlane_t)(IDirect3DDevice9* pDev, DWORD Index, CONST float* pPlane);
		typedef HRESULT(WINAPI *GetClipPlane_t)(IDirect3DDevice9* pDev, DWORD Index, float* pPlane);
		typedef HRESULT(WINAPI *SetRenderState_t)(IDirect3DDevice9* pDev, D3DRENDERSTATETYPE State, DWORD Value);
		typedef HRESULT(WINAPI *GetRenderState_t)(IDirect3DDevice9* pDev, D3DRENDERSTATETYPE State, DWORD* pValue);
		typedef HRESULT(WINAPI *CreateStateBlock_t)(IDirect3DDevice9* pDev, D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9** ppSB);
		typedef HRESULT(WINAPI *BeginStateBlock_t)(IDirect3DDevice9* pDev);
		typedef HRESULT(WINAPI *EndStateBlock_t)(IDirect3DDevice9* pDev, IDirect3DStateBlock9** ppSB);
		typedef HRESULT(WINAPI *SetClipStatus_t)(IDirect3DDevice9* pDev, CONST D3DCLIPSTATUS9* pClipStatus);
		typedef HRESULT(WINAPI *GetClipStatus_t)(IDirect3DDevice9* pDev, D3DCLIPSTATUS9* pClipStatus);
		typedef HRESULT(WINAPI *GetTexture_t)(IDirect3DDevice9* pDev, DWORD Stage, IDirect3DBaseTexture9** ppTexture);
		typedef HRESULT(WINAPI *SetTexture_t)(IDirect3DDevice9* pDev, DWORD Stage, IDirect3DBaseTexture9* pTexture);
		typedef HRESULT(WINAPI *GetTextureStageState_t)(IDirect3DDevice9* pDev, DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue);
		typedef HRESULT(WINAPI *SetTextureStageState_t)(IDirect3DDevice9* pDev, DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value);
		typedef HRESULT(WINAPI *GetSamplerState_t)(IDirect3DDevice9* pDev, DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD* pValue);
		typedef HRESULT(WINAPI *SetSamplerState_t)(IDirect3DDevice9* pDev, DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value);
		typedef HRESULT(WINAPI *ValidateDevice_t)(IDirect3DDevice9* pDev, DWORD* pNumPasses);
		typedef HRESULT(WINAPI *SetPaletteEntries_t)(IDirect3DDevice9* pDev, UINT PaletteNumber, CONST PALETTEENTRY* pEntries);
		typedef HRESULT(WINAPI *GetPaletteEntries_t)(IDirect3DDevice9* pDev, UINT PaletteNumber, PALETTEENTRY* pEntries);
		typedef HRESULT(WINAPI *SetCurrentTexturePalette_t)(IDirect3DDevice9* pDev, UINT PaletteNumber);
		typedef HRESULT(WINAPI *GetCurrentTexturePalette_t)(IDirect3DDevice9* pDev, UINT *PaletteNumber);
		typedef HRESULT(WINAPI *SetScissorRect_t)(IDirect3DDevice9* pDev, CONST RECT* pRect);
		typedef HRESULT(WINAPI *GetScissorRect_t)(IDirect3DDevice9* pDev, RECT* pRect);
		typedef HRESULT(WINAPI *SetSoftwareVertexProcessing_t)(IDirect3DDevice9* pDev, BOOL bSoftware);
		typedef BOOL(WINAPI *GetSoftwareVertexProcessing_t)(IDirect3DDevice9* pDev);
		typedef HRESULT(WINAPI *SetNPatchMode_t)(IDirect3DDevice9* pDev, float nSegments);
		typedef float (WINAPI *GetNPatchMode_t)(IDirect3DDevice9* pDev);
		typedef HRESULT(WINAPI *DrawPrimitive_t)(IDirect3DDevice9* pDev, D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount);
		typedef HRESULT(WINAPI *DrawIndexedPrimitive_t)(IDirect3DDevice9* pDev, D3DPRIMITIVETYPE, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount);
		typedef HRESULT(WINAPI *DrawPrimitiveUP_t)(IDirect3DDevice9* pDev, D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride);
		typedef HRESULT(WINAPI *DrawIndexedPrimitiveUP_t)(IDirect3DDevice9* pDev, D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, CONST void* pIndexData, D3DFORMAT IndexDataFormat, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride);
		typedef HRESULT(WINAPI *ProcessVertices_t)(IDirect3DDevice9* pDev, UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9* pDestBuffer, IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags);
		typedef HRESULT(WINAPI *CreateVertexDeclaration_t)(IDirect3DDevice9* pDev, CONST D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl);
		typedef HRESULT(WINAPI *SetVertexDeclaration_t)(IDirect3DDevice9* pDev, IDirect3DVertexDeclaration9* pDecl);
		typedef HRESULT(WINAPI *GetVertexDeclaration_t)(IDirect3DDevice9* pDev, IDirect3DVertexDeclaration9** ppDecl);
		typedef HRESULT(WINAPI *SetFVF_t)(IDirect3DDevice9* pDev, DWORD FVF);
		typedef HRESULT(WINAPI *GetFVF_t)(IDirect3DDevice9* pDev, DWORD* pFVF);
		typedef HRESULT(WINAPI *CreateVertexShader_t)(IDirect3DDevice9* pDev, CONST DWORD* pFunction, IDirect3DVertexShader9** ppShader);
		typedef HRESULT(WINAPI *SetVertexShader_t)(IDirect3DDevice9* pDev, IDirect3DVertexShader9* pShader);
		typedef HRESULT(WINAPI *GetVertexShader_t)(IDirect3DDevice9* pDev, IDirect3DVertexShader9** ppShader);
		typedef HRESULT(WINAPI *SetVertexShaderConstantF_t)(IDirect3DDevice9* pDev, UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount);
		typedef HRESULT(WINAPI *GetVertexShaderConstantF_t)(IDirect3DDevice9* pDev, UINT StartRegister, float* pConstantData, UINT Vector4fCount);
		typedef HRESULT(WINAPI *SetVertexShaderConstantI_t)(IDirect3DDevice9* pDev, UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount);
		typedef HRESULT(WINAPI *GetVertexShaderConstantI_t)(IDirect3DDevice9* pDev, UINT StartRegister, int* pConstantData, UINT Vector4iCount);
		typedef HRESULT(WINAPI *SetVertexShaderConstantB_t)(IDirect3DDevice9* pDev, UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount);
		typedef HRESULT(WINAPI *GetVertexShaderConstantB_t)(IDirect3DDevice9* pDev, UINT StartRegister, BOOL* pConstantData, UINT BoolCount);
		typedef HRESULT(WINAPI *SetStreamSource_t)(IDirect3DDevice9* pDev, UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride);
		typedef HRESULT(WINAPI *GetStreamSource_t)(IDirect3DDevice9* pDev, UINT StreamNumber, IDirect3DVertexBuffer9** ppStreamData, UINT* pOffsetInBytes, UINT* pStride);
		typedef HRESULT(WINAPI *SetStreamSourceFreq_t)(IDirect3DDevice9* pDev, UINT StreamNumber, UINT Setting);
		typedef HRESULT(WINAPI *GetStreamSourceFreq_t)(IDirect3DDevice9* pDev, UINT StreamNumber, UINT* pSetting);
		typedef HRESULT(WINAPI *SetIndices_t)(IDirect3DDevice9* pDev, IDirect3DIndexBuffer9* pIndexData);
		typedef HRESULT(WINAPI *GetIndices_t)(IDirect3DDevice9* pDev, IDirect3DIndexBuffer9** ppIndexData);
		typedef HRESULT(WINAPI *CreatePixelShader_t)(IDirect3DDevice9* pDev, CONST DWORD* pFunction, IDirect3DPixelShader9** ppShader);
		typedef HRESULT(WINAPI *SetPixelShader_t)(IDirect3DDevice9* pDev, IDirect3DPixelShader9* pShader);
		typedef HRESULT(WINAPI *GetPixelShader_t)(IDirect3DDevice9* pDev, IDirect3DPixelShader9** ppShader);
		typedef HRESULT(WINAPI *SetPixelShaderConstantF_t)(IDirect3DDevice9* pDev, UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount);
		typedef HRESULT(WINAPI *GetPixelShaderConstantF_t)(IDirect3DDevice9* pDev, UINT StartRegister, float* pConstantData, UINT Vector4fCount);
		typedef HRESULT(WINAPI *SetPixelShaderConstantI_t)(IDirect3DDevice9* pDev, UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount);
		typedef HRESULT(WINAPI *GetPixelShaderConstantI_t)(IDirect3DDevice9* pDev, UINT StartRegister, int* pConstantData, UINT Vector4iCount);
		typedef HRESULT(WINAPI *SetPixelShaderConstantB_t)(IDirect3DDevice9* pDev, UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount);
		typedef HRESULT(WINAPI *GetPixelShaderConstantB_t)(IDirect3DDevice9* pDev, UINT StartRegister, BOOL* pConstantData, UINT BoolCount);
		typedef HRESULT(WINAPI *DrawRectPatch_t)(IDirect3DDevice9* pDev, UINT Handle, CONST float* pNumSegs, CONST D3DRECTPATCH_INFO* pRectPatchInfo);
		typedef HRESULT(WINAPI *DrawTriPatch_t)(IDirect3DDevice9* pDev, UINT Handle, CONST float* pNumSegs, CONST D3DTRIPATCH_INFO* pTriPatchInfo);
		typedef HRESULT(WINAPI *DeletePatch_t)(IDirect3DDevice9* pDev, UINT Handle);
		typedef HRESULT(WINAPI *CreateQuery_t)(IDirect3DDevice9* pDev, D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery);

}
