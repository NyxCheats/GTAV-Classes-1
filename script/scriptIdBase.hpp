#pragma once
#include "../rage/joaat.hpp"

#include <cstdint>

#pragma pack(push, 1)
namespace rage {
	class datBitBuffer;
	class netLoggingInterface;
	class scrThread;

	class scriptIdBase {
	public:
		virtual ~scriptIdBase() = default; // 0 (0x00)

		// Assumes the script thread's identity.
		virtual void assume_thread_identity(scrThread*) {}; // 1 (0x08)

		// Returns whether the hash of the script id is valid.
		virtual bool is_valid() {
			return false;
		}; // 2 (0x10)

		// Gets the hash of the script id.
		virtual joaat_t* get_hash(joaat_t* out) {
			return 0;
		}; // 3 (0x18)

		// Gets an unknown value from the script id.
		virtual std::uint32_t* get_hash2(std::uint32_t* out) {
			return 0;
		}; // 4 (0x20)

		// Gets the name of the script id.
		virtual const char* get_name() {
			return nullptr;
		}; // 5 (0x28)

		// Serializes the script id from the buffer.
		virtual void deserialize(datBitBuffer* buffer) {}; // 6 (0x30)

		// Serializes the script id to the buffer.
		virtual void serialize(datBitBuffer* buffer) {}; // 7 (0x38)

		// Calculates some information with the position hash & instance id.
		virtual std::uint32_t _0x40() {
			return 0;
		}; // 8 (0x40)

		// Calls _0x40 and returns it's value added to another value.
		virtual std::uint32_t _0x48() {
			return 0;
		}; // 9 (0x48)

		// Logs some information about the script id.
		virtual void log_information(netLoggingInterface* logger) {}; // 10 (0x50)

		// Copies the information of other to this object.
		virtual void copy_data(scriptIdBase* other) {
		} // 11 (0x58)

		// Returns whether the other script id is equal.
		virtual bool operator==(scriptIdBase*) {
			return false;
		}; // 12 (0x60)

		virtual bool _0x68(void*) {
			return false;
		}; // 13 (0x68)
	};
}
#pragma pack(pop)