#pragma once
#include <cstdint>

namespace rage {
	struct RGBA {
		RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {
		}
		RGBA(uint8_t r, uint8_t g, uint8_t b) : RGBA(r, g, b, 255) {
		}
		RGBA() = default;
		uint8_t r, g, b, a;
	};
	class Color32 {
	public:
		Color32() {
			Set(255, 255, 255, 255);
		}
		explicit Color32(uint32_t color) : m_Color(color) {
		}
		Color32(int r, int g, int b, int a = 255) {
			Set(r, g, b, a);
		}
		Color32(uint32_t r, uint32_t g, uint32_t b, uint32_t a = 255) {
			Set(r, g, b, a);
		}
		Color32(float r, float g, float b, float a = 1.f) {
			Setf(r, g, b, a);
		}
		void Set(uint32_t color) {
			m_Color = color;
		}
		void Set(int r, int g, int b, int a = 255) {
			SetBytes(r, g, b, a);
		}
		void Setf(float r, float g, float b, float a = 1.f) {
			Set(int(r * 255.0f), int(g * 255.0f), int(b * 255.0f), int(a * 255.0f));
		}
		void SetBytes(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) {
			m_Color = (r << s_ChannelShiftR) | (g << s_ChannelShiftG) | (b << s_ChannelShiftB) | (a << s_ChannelShiftA);
		}
		void SetRed(int r) {
			m_Color = (m_Color & ~s_ChannelMaskR) | (uint8_t(r) << s_ChannelShiftR);
		}
		void SetGreen(int g) {
			m_Color = (m_Color & ~s_ChannelMaskG) | (uint8_t(g) << s_ChannelShiftG);
		}
		void SetBlue(int b) {
			m_Color = (m_Color & ~s_ChannelMaskB) | (uint8_t(b) << s_ChannelShiftB);
		}
		void SetAlpha(int a) {
			m_Color = (m_Color & ~s_ChannelMaskA) | (uint8_t(a) << s_ChannelShiftA);
		}
		uint8_t GetRed() const {
			return uint8_t(m_Color >> s_ChannelShiftR);
		}
		uint8_t GetGreen() const {
			return uint8_t(m_Color >> s_ChannelShiftG);
		}
		uint8_t GetBlue() const {
			return uint8_t(m_Color >> s_ChannelShiftB);
		}
		uint8_t GetAlpha() const {
			return uint8_t(m_Color >> s_ChannelShiftA);
		}
		float GetRedf() const {
			return GetRed() * (1.0f / 255.0f);
		}
		float GetGreenf() const {
			return GetGreen() * (1.0f / 255.0f);
		}
		float GetBluef() const {
			return GetBlue() * (1.0f / 255.0f);
		}
		float GetAlphaf() const {
			return GetAlpha() * (1.0f / 255.0f);
		}
		uint32_t GetColor() const {
			return m_Color;
		}
		uint32_t GetDeviceColor() const {
			return (GetRed()) | (GetGreen() << 8) | (GetBlue() << 16) | (GetAlpha() << 24);
		}
		void SetFromDeviceColor(uint32_t colorDC) {
			Set((colorDC & s_ChannelMaskB), (colorDC & s_ChannelMaskG) >> s_ChannelShiftG, (colorDC & s_ChannelMaskR) >> s_ChannelShiftR, (colorDC & s_ChannelMaskA) >> s_ChannelShiftA);
		}
		Color32 operator*(const Color32& c) const {
			return Color32((GetRed() * c.GetRed()) / 255, (GetGreen() * c.GetGreen()) / 255, (GetBlue() * c.GetBlue()) / 255, (GetAlpha() * c.GetAlpha()) / 255);
		}
		void operator+=(const Color32& c) {
			Set(GetRed() + c.GetRed(), GetGreen() + c.GetGreen(), GetBlue() + c.GetBlue(), GetAlpha() + c.GetAlpha());
		}
		bool operator==(const Color32& c) const {
			return m_Color == c.m_Color;
		}
		bool operator!=(const Color32& c) const {
			return m_Color != c.m_Color;
		}
		static constexpr int s_ChannelShiftA = 24;
		static constexpr int s_ChannelShiftR = 16;
		static constexpr int s_ChannelShiftG = 8;
		static constexpr int s_ChannelShiftB = 0;
		static constexpr uint32_t s_ChannelMaskA  = 0xFF000000;
		static constexpr uint32_t s_ChannelMaskR  = 0x00FF0000;
		static constexpr uint32_t s_ChannelMaskG  = 0x0000FF00;
		static constexpr uint32_t s_ChannelMaskB  = 0x000000FF;
		static constexpr uint32_t s_ChannelMaskRGB = s_ChannelMaskR | s_ChannelMaskG | s_ChannelMaskB;

	private:
		uint32_t m_Color;
	};
}