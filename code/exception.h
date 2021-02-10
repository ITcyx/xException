#pragma once
#include <string>

namespace x
{
	// �쳣�������
	class exception_error
	{
	private:
		std::string msg;

	public:
		// ���캯�����������캯������������
		exception_error() noexcept;
		explicit exception_error(const std::string& message) noexcept;
		exception_error(const exception_error& other_exception_error) noexcept;
		virtual ~exception_error() noexcept;

		// ���ܺ���
		virtual const std::string& get_message() const noexcept;

		// ���������
		exception_error& operator=(const exception_error& other_exception_error) noexcept;
	};

	class argument_error :public exception_error
	{
	// ��������
	private:
		int id;
	public:
		// ���캯�����������캯������������
		argument_error() noexcept;
		argument_error(const argument_error& other_argument_error) noexcept;
		explicit argument_error(const int& argument_error_id) noexcept;
		explicit argument_error(const std::string& message, const int& argument_error_id = -1) noexcept;

		~argument_error() noexcept;
		int get_argument_error_id() noexcept;  // ��û��ָ���ĸ���������ʱ������-1


	};

	class operation_error :public exception_error
	{
	public:
		const std::string& get_message() const noexcept;
	};

	class file_error :public exception_error
	{
		const std::string& get_message() const noexcept;
	};
}