#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace Version3 {
	class Error
	{
	public:
		virtual void what() {};
	};


	class IndexError : public Error
	{
	protected:
		string msg;
	public:
		IndexError() { msg = "Index Error\n"; }
		virtual void what() { cout << msg << endl; }
	};


	class InvalidArgumentError : public Error
	{
	protected:
		string msg;
	public:
		InvalidArgumentError() { msg = "Invalid argument: n must be >= 0\n"; }
		virtual void what() { cout << msg << endl; }
	};


	class SizeError : public Error
	{
	protected:
		string msg;
	public:
		SizeError() { msg = "SizeError\n"; }
		virtual void what() { cout << msg << endl; }
	};


	class MaxSizeError : public SizeError
	{
	protected:
		string msg_;
	public:
		MaxSizeError() : SizeError() { msg_ = "size > max size\n"; }
		virtual void what() { cout << msg << msg_ << endl; }
	};


	class SizeMismatchError : SizeError
	{
	protected:
		string msg_;
	public:
		SizeMismatchError() : SizeError()
		{
			msg_ = "Size mismatch: cannot remove more elements than current size\n";
		}
		virtual void what() { cout << msg << msg_ << endl; }
	};


	class IndexError1 : IndexError
	{
	protected:
		string msg_;
	public:
		IndexError1() : IndexError() { msg_ = "index < 0\n"; }
		virtual void what() { cout << msg << msg_ << endl; }
	};


	class IndexError2 : IndexError
	{
	protected:
		string msg_;
	public:
		IndexError2() : IndexError() { msg_ = "index > size\n"; }
		virtual void what() { cout << msg << msg_ << endl; }
	};
}