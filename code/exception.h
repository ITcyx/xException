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

	class argument_error :public exception_error
	{
	// 参数错误
	private:
		int id;

	public:
		// 构造函数，拷贝构造函数，析构函数
		argument_error() noexcept;
		argument_error(const argument_error& other_argument_error) noexcept;
		explicit argument_error(const int& argument_error_id) noexcept;
		explicit argument_error(const std::string& message, const int& argument_error_id = -1) noexcept;
		~argument_error() noexcept;

		// 功能性函数
		int get_argument_error_id() noexcept;  // 当没有指定哪个参数错误时，返回-1

		// 重载运算符
		argument_error& operator=(const argument_error& other_argument_error) noexcept;

	};

	class operation_error :public exception_error
	{
	public:
		// 构造函数
		operation_error() noexcept;
	};

	class file_error :public exception_error
	{
	public:
		// 构造函数
		file_error() noexcept;
	};
}