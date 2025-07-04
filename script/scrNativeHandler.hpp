#pragma once
#include "rage/scrValue.hpp"
#include "rage/vector.hpp"

#include <cstddef>
#include <cstdint>
#include <utility>

namespace rage {
	class scrNativeCallContext {
	public:
		constexpr void reset() {
			m_arg_count  = 0;
			m_data_count = 0;
		}

		template<typename T>
		constexpr void push_arg(T&& value) {
			static_assert(sizeof(T) <= sizeof(std::uint64_t));
			*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(reinterpret_cast<std::uint64_t*>(m_args) + (m_arg_count++)) = std::forward<T>(value);
		}

		template<typename T>
		constexpr T& get_arg(std::size_t index) {
			static_assert(sizeof(T) <= sizeof(std::uint64_t));
			return *reinterpret_cast<T*>(reinterpret_cast<std::uint64_t*>(m_args) + index);
		}

		template<typename T>
		constexpr void set_arg(std::size_t index, T&& value) {
			static_assert(sizeof(T) <= sizeof(std::uint64_t));
			*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(reinterpret_cast<std::uint64_t*>(m_args) + index) = std::forward<T>(value);
		}

		template<typename T>
		constexpr T* get_return_value() {
			return reinterpret_cast<T*>(m_return_value);
		}

		template<typename T>
		constexpr void set_return_value(T&& value) {
			*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(m_return_value) = std::forward<T>(value);
		}

		void* m_return_value;
		std::uint32_t m_arg_count;
		void* m_args;
		std::int32_t m_data_count;
		rage::scrValue* m_orig [ 4 ];
		rage::fvector4 m_buffer [ 4 ];
	};
	static_assert(sizeof(scrNativeCallContext) == 0x80);

	using scrNativeHash    = std::uint64_t;
	using scrNativePair    = std::pair<scrNativeHash, scrNativeHash>;
	using scrNativeHandler = void (*)(scrNativeCallContext*);
}
