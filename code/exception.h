#pragma once

namespace x
{
	class exception_error
	{
	// “Ï≥£¥ÌŒÛª˘¿‡
	public:
		exception_error() noexcept;
		exception_error(const char* const message) noexcept;
		exception_error(const exception_error& other_exception_error) noexcept;
		exception_error& operator=(const exception_error& other_exception_error) noexcept;
		virtual ~exception_error() noexcept;
		virtual char const* MSG() noexcept;
	private:
		char const* msg;
	};

	class argument_error :public exception_error
	{

	};
}