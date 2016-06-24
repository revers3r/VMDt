#include "vbox-innotek.h"

bool Innotek::Innotek_chk() {
	HRESULT hr = CoInitialize(0);
	if (!SUCCEEDED(hr))	return FALSE;
	IDxDiagProvider* pProvider = NULL;

	hr = CoCreateInstance(CLSID_DxDiagProvider, 0,
		CLSCTX_INPROC_SERVER, IID_IDxDiagProvider, (void **)&pProvider);
	if (!SUCCEEDED(hr)) {
		CoUninitialize();
		return FALSE;
	}
	DXDIAG_INIT_PARAMS InitParams = { 0 };
	InitParams.dwSize = sizeof(DXDIAG_INIT_PARAMS);
	InitParams.dwDxDiagHeaderVersion = DXDIAG_DX9_SDK_VERSION;
	InitParams.bAllowWHQLChecks = false;

	hr = pProvider->Initialize(&InitParams);
	if (SUCCEEDED(hr)) {
		IDxDiagContainer* pDxDiagRoot = 0;
		IDxDiagContainer* pDxDiagSystemInfo = 0;

		hr = pProvider->GetRootContainer(&pDxDiagRoot);
		if (SUCCEEDED(hr)) {
			hr = pDxDiagRoot->GetChildContainer(L"DxDiag_SystemInfo", &pDxDiagSystemInfo);
			if (SUCCEEDED(hr)) {
				VARIANT varX;
				hr = pDxDiagSystemInfo->GetPropW(L"szSystemManufacturerEnglish", &varX);
				if (SUCCEEDED(hr) && varX.vt == VT_BSTR && SysStringLen(varX.bstrVal) != 0) {
					wchar_t* pMan = varX.bstrVal;
					if (!_wcsicmp(pMan, L"innotek GmbH")) {
						DETECT_START				"VirtualBox Detected"				DETECT_END
							QuitProcess(0);
					}
				}
				VariantClear(&varX);
				hr = pDxDiagSystemInfo->GetPropW(L"szSystemModelEnglish", &varX);
				if (SUCCEEDED(hr) && varX.vt == VT_BSTR && SysStringLen(varX.bstrVal) != 0) {
					wchar_t* pMan = varX.bstrVal;
					if (!_wcsicmp(pMan, L"VirtualBox")) {
						DETECT_START				"VirtualBox Detected"				DETECT_END
							QuitProcess(0);
					}
				}
				VariantClear(&varX);
				pDxDiagSystemInfo->Release();
			}
			pDxDiagRoot->Release();
		}
		pProvider->Release();
	}
	CoUninitialize();
	return TRUE;
}

// Source by pastebin.com