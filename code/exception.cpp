# include "exception.h"

x::exception_error::exception_error() noexcept :msg("Unknown Error!")
{}

x::exception_error::exception_error(const std::string& message) noexcept :msg(message)
{}

x::exception_error::exception_error(const exception_error& other_exception_error) noexcept :msg(other_exception_error.msg)
{}

x::exception_error::~exception_error() noexcept
{
	if (msg != "")
		msg = "";
}

const std::string& x::exception_error::get_message() const noexcept
{
	return msg;
}

x::exception_error& x::exception_error::operator=(const exception_error& other_exception_error) noexcept
{
	msg = other_exception_error.msg;
}










x::argument_error::argument_error() noexcept :exception_error("Argument Error"), id(-1)
{}

x::argument_error::argument_error(const argument_error& other_argument_error) noexcept :exception_error(other_argument_error.msg), id(other_argument_error.id)
{}

explicit x::argument_error::argument_error(const int& argument_error_id) noexcept :exception_error("Argument Error"), id(argument_error_id)
{}

explicit x::argument_error::argument_error(const std::string& message, const int& argument_error_id) noexcept :exception_error(message), id(argument_error_id)
{}

x::argument_error::~argument_error() noexcept
{
	msg = "";
	id = -1;
}

int x::argument_error::get_argument_error_id() noexcept
{
	return id;
}

x::argument_error& x::argument_error::operator=(const argument_error& other_argument_error) noexcept
{
	msg = other_argument_error.msg;
	id = other_argument_error.id;
}










x::operation_error::operation_error() noexcept :exception_error("Operation Error!")
{}










x::file_error::file_error() noexcept :exception_error("File Error!")
{}