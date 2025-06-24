#pragma once
#include <cstdint>
#include <d3d11.h>

namespace rage {
	typedef struct ID3D11Device grcDeviceHandle;
	typedef struct IDXGISwapChain grcSwapChain;
	typedef struct ID3D11DeviceContext grcContextHandle;
	typedef struct ID3D11CommandList grcContextCommandList;
	typedef ID3D11Buffer grcBuffer;
	typedef ID3D11ComputeShader grcComputeShader;
	typedef ID3D11DeviceChild grcShader;
	typedef ID3D11DomainShader grcDomainShader;
	typedef ID3D11GeometryShader grcGeometryShader;
	typedef ID3D11HullShader grcHullShader;
	typedef ID3D11PixelShader grcPixelShader;
	typedef ID3D11Resource grcDeviceTexture;
	typedef ID3D11Resource grcTextureObject;
	typedef ID3D11ShaderResourceView grcDeviceView;
	typedef ID3D11VertexShader grcVertexShader;
	typedef IUnknown grcDeviceSurface;
	typedef IUnknown grcResource;
	typedef IUnknown grcBlob;
	typedef void grcStreamOutputDeclaration;
	class grcDevice {
	public:
		enum MSAAModeEnum {
			MSAA_None        = 0,
			MSAA_NonMaskAble = 1,
			MSAA_2           = 2,
			MSAA_4           = 4,
			MSAA_8           = 8,
			// PS3
			MSAA_2xMS = 2, // using 2x multi-sampling with a Quincunx filter while downsampling
			MSAA_Centered4xMS = 4, // using 4x multi-sampling with a centered filter kernel and a Gauss filter while downsampling
			MSAA_Rotated4xMS = 8 // using 4x multi-sampling with a rotated filter kernel and a Gauss filter while downsampling
		};
		enum Stereo_t {
			MONO,
			STEREO,
			AUTO
		};
		class MSAAMode {
		public:
			inline MSAAMode() : m_Mode(MSAA_None) {
			}
			inline MSAAMode(MSAAModeEnum mode) : m_Mode(mode) {
			}
			inline MSAAMode(int mode) :
			    m_Mode(static_cast<MSAAModeEnum>(mode)) {
			}
			inline MSAAMode operator=(int value) {
				m_Mode = static_cast<MSAAModeEnum>(value);
				return *this;
			}
			inline bool operator==(MSAAMode mode) const {
				return m_Mode == mode.m_Mode;
			}
			inline bool operator==(MSAAModeEnum mode) const {
				return m_Mode == mode;
			}
			inline operator uint32_t() const {
				return static_cast<uint32_t>(m_Mode);
			}

		private:
			MSAAModeEnum m_Mode;
		};
	};
}