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
	if (this == &other_exception_error)
		return *this;
	msg = other_exception_error.msg;
	return *this;
}










x::argument_error::argument_error() noexcept :exception_error("Argument Error!"), id(-1)
{}

x::argument_error::argument_error(const int& argument_id) noexcept :exception_error("Argument Error!"), id(argument_id)
{}

x::argument_error::argument_error(const std::string& message, const int& argument_id) noexcept :exception_error(message), id(argument_id)
{}

x::argument_error::argument_error(const argument_error& other_argument_error) noexcept :exception_error(other_argument_error.msg), id(other_argument_error.id)
{}

x::argument_error::~argument_error() noexcept
{
	if (msg != "")
		msg = "";
	id = -1;
}

int x::argument_error::get_argument_id() const noexcept
{
	return id;
}

x::argument_error& x::argument_error::operator=(const argument_error& other_argument_error) noexcept
{
	if (this == &other_argument_error)
		return *this;
	msg = other_argument_error.msg;
	id = other_argument_error.id;
	return *this;
}










x::operation_error::operation_error() noexcept :exception_error("Operation Error!")
{}

x::operation_error::operation_error(const std::string& message) noexcept :exception_error(message)
{}










x::file_error::file_error() noexcept :exception_error("File Error!"), fn("")
{}

x::file_error::file_error(int, const std::string& file_name) noexcept :exception_error("File Error!"), fn(file_name)
{}

x::file_error::file_error(const std::string& message, const std::string& file_name) noexcept :exception_error(message), fn(file_name)
{}

x::file_error::file_error(const file_error& other_file_error) noexcept :exception_error(other_file_error.msg), fn(other_file_error.fn)
{}

x::file_error::~file_error() noexcept
{
	if (fn != "")
		fn = "";
	if (msg != "")
		msg = "";
}

const std::string& x::file_error::get_file_name() const noexcept
{
	return fn;
}

x::file_error& x::file_error::operator=(const file_error& other_file_error) noexcept
{
	if (this == &other_file_error)
		return *this;
	msg = other_file_error.msg;
	fn = other_file_error.fn;
	return *this;
}










x::file_open_error::file_open_error() noexcept :file_error("File Opern Error!")
{}

x::file_open_error::file_open_error(int, const std::string& file_name) noexcept :file_error("File Open Error!", file_name)
{}

x::file_open_error::file_open_error(const std::string& message, const std::string& file_name) noexcept :file_error(message, file_name)
{}










x::file_read_error::file_read_error() noexcept :file_error("File Read Error!")
{}

x::file_read_error::file_read_error(int, const std::string& file_name) noexcept :file_error("File Read Error!", file_name)
{}

x::file_read_error::file_read_error(const std::string& message, const std::string& file_name) noexcept :file_error(message, file_name)
{}










x::file_write_error::file_write_error() noexcept :file_error("File Write Error!")
{}

x::file_write_error::file_write_error(int, const std::string& file_name) noexcept :file_error("File Write Error!", file_name)
{}

x::file_write_error::file_write_error(const std::string& message, const std::string& file_name) noexcept :file_error(message, file_name)
{}