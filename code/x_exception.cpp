# include "x_exception.h"


// ********** exception_error 实现 **********

// ---------- 构造、析构函数 ----------
x::exception_error::exception_error() noexcept :msg("Unknown Error!")
{}

x::exception_error::exception_error(exception_error const& other_exception_error) noexcept :msg(other_exception_error.msg)
{}

x::exception_error::exception_error(std::string const& message) noexcept :msg(message)
{}

x::exception_error::~exception_error() noexcept
{
	if (msg != "")
		msg = "";
}

// ---------- 功能函数 ----------
std::string const& x::exception_error::get_message() const noexcept
{
	return msg;
}

// ---------- 重载运算符 ----------
x::exception_error& x::exception_error::operator=(exception_error const& other_exception_error) noexcept
{
	if (this == &other_exception_error)
		return *this;
	msg = other_exception_error.msg;
	return *this;
}










// ********** argument_error **********

// ---------- 构造、析构函数 ----------
x::argument_error::argument_error() noexcept :exception_error("Argument Error!"), id(-1)
{}

x::argument_error::argument_error(argument_error const& other_argument_error) noexcept :exception_error(other_argument_error.msg), id(other_argument_error.id)
{}

x::argument_error::argument_error(int const& argument_id) noexcept :exception_error("Argument Error!"), id(argument_id)
{}

x::argument_error::argument_error(std::string const& message, int const& argument_id) noexcept :exception_error(message), id(argument_id)
{}

x::argument_error::~argument_error() noexcept
{
	if (msg != "")
		msg = "";
	id = -1;
}

// ---------- 功能性函数 ----------
int x::argument_error::get_argument_id() const noexcept
{
	return id;
}

// ---------- 重载运算符 ----------
x::argument_error& x::argument_error::operator=(argument_error const& other_argument_error) noexcept
{
	if (this == &other_argument_error)
		return *this;
	msg = other_argument_error.msg;
	id = other_argument_error.id;
	return *this;
}










// ********** operation_error **********

// ---------- 构造函数 ----------
x::operation_error::operation_error() noexcept :exception_error("Operation Error!")
{}

x::operation_error::operation_error(std::string const& message) noexcept :exception_error(message)
{}










// ********** index_error **********

// ---------- 构造函数 ----------
x::index_error::index_error() noexcept :exception_error("Index Error!")
{}

x::index_error::index_error(std::string const& message) noexcept :exception_error(message)
{}










// ********** file_error **********

// ---------- 构造、析构函数 ----------
x::file_error::file_error() noexcept :exception_error("File Error!"), fn("")
{}

x::file_error::file_error(file_error const& other_file_error) noexcept :exception_error(other_file_error.msg), fn(other_file_error.fn)
{}

x::file_error::file_error(int, std::string const& file_name) noexcept :exception_error("File Error!"), fn(file_name)
{}

x::file_error::file_error(std::string const& message, std::string const& file_name) noexcept :exception_error(message), fn(file_name)
{}

x::file_error::~file_error() noexcept
{
	if (fn != "")
		fn = "";
	if (msg != "")
		msg = "";
}

// ---------- 功能性函数 ----------
std::string const& x::file_error::get_file_name() const noexcept
{
	return fn;
}

// ---------- 重载运算符 ----------
x::file_error& x::file_error::operator=(file_error const& other_file_error) noexcept
{
	if (this == &other_file_error)
		return *this;
	msg = other_file_error.msg;
	fn = other_file_error.fn;
	return *this;
}










// ********** file_open_error **********

// ---------- 构造、析构函数 ----------
x::file_open_error::file_open_error() noexcept :file_error("File Opern Error!")
{}

x::file_open_error::file_open_error(int, std::string const& file_name) noexcept :file_error("File Open Error!", file_name)
{}

x::file_open_error::file_open_error(std::string const& message, std::string const& file_name) noexcept :file_error(message, file_name)
{}









// ********** file_read_error **********

// ---------- 构造函数 ----------
x::file_read_error::file_read_error() noexcept :file_error("File Read Error!")
{}

x::file_read_error::file_read_error(int, std::string const& file_name) noexcept :file_error("File Read Error!", file_name)
{}

x::file_read_error::file_read_error(std::string const& message, std::string const& file_name) noexcept :file_error(message, file_name)
{}










// ********** file_write_error **********

// ---------- 构造函数 ----------
x::file_write_error::file_write_error() noexcept :file_error("File Write Error!")
{}

x::file_write_error::file_write_error(int, std::string const& file_name) noexcept :file_error("File Write Error!", file_name)
{}

x::file_write_error::file_write_error(std::string const& message, std::string const& file_name) noexcept :file_error(message, file_name)
{}