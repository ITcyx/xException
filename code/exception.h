#pragma once
#include <string>

namespace x
{
	// 异常错误基类
	class exception_error
	{
	protected:
		std::string msg;

	public:
		// 构造函数，拷贝构造函数，析构函数
		exception_error() noexcept;
		explicit exception_error(const std::string& message) noexcept;
		exception_error(const exception_error& other_exception_error) noexcept;
		virtual ~exception_error() noexcept;

		// 功能函数
		virtual const std::string& get_message() const noexcept;

		// 重载运算符
		exception_error& operator=(const exception_error& other_exception_error) noexcept;
	};










	// 参数异常错误类
	class argument_error :public exception_error
	{
	private:
		int id;

	public:
		// 构造函数，拷贝构造函数，析构函数
		argument_error() noexcept;
		explicit argument_error(const int& argument_id) noexcept;
		explicit argument_error(const std::string& message, const int& argument_id = -1) noexcept;
		argument_error(const argument_error& other_argument_error) noexcept;
		~argument_error() noexcept;

		// 功能性函数
		int get_argument_id() const noexcept;  // 当没有指定哪个参数错误时，返回-1。返回0指的是第一个参数，以此类推

		// 重载运算符
		argument_error& operator=(const argument_error& other_argument_error) noexcept;
	};










	// 操作常错误类
	class operation_error :public exception_error
	{
	public:
		// 构造函数、拷贝构造函数
		operation_error() noexcept;
		explicit operation_error(const std::string& message) noexcept;
	};










	// 文件异常错误类
	class file_error :public exception_error
	{
	protected:
		std::string fn;

	public:
		// 构造函数、拷贝构造函数
		file_error() noexcept;
		file_error(int, const std::string& file_name) noexcept;
		explicit file_error(const std::string& message, const std::string& file_name = "") noexcept;
		file_error(const file_error& other_file_error) noexcept;
		~file_error() noexcept;

		// 功能性函数
		const std::string& get_file_name() const noexcept;  // 当没有指定哪个文件错误时，返回空字符串""

		// 重载运算符
		file_error& operator=(const file_error& other_file_error) noexcept;
	};










	// 文件打开异常错误类
	class file_open_error :public file_error
	{
	public:
		// 构造函数、拷贝构造函数
		file_open_error() noexcept;
		file_open_error(int, const std::string& file_name) noexcept;
		explicit file_open_error(const std::string& message, const std::string& file_name) noexcept;
	};










	// 文件读取异常错误类
	class file_read_error :public file_error
	{
	public:
		// 构造函数、拷贝构造函数
		file_read_error() noexcept;
		file_read_error(int, const std::string& file_name) noexcept;
		explicit file_read_error(const std::string& message, const std::string& file_name) noexcept;
	};










	// 文件写入异常错误类
	class file_write_error :public file_error
	{
	public:
		// 构造函数、拷贝构造函数
		file_write_error() noexcept;
		file_write_error(int, const std::string& file_name) noexcept;
		explicit file_write_error(const std::string& message, const std::string& file_name) noexcept;
	};
}