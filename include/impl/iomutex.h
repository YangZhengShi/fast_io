#pragma once
#include<mutex>

namespace fast_io
{

template<stream T>
class basic_iomutex
{
	std::unique_ptr<std::mutex> mtx;
	T handler;
public:
	using native_handle_type = T;
	using char_type = typename native_handle_type::char_type;
	template<typename ...Args>
	basic_iomutex(Args&& ...args):mtx(std::make_unique<std::mutex>()),handler(std::forward<Args>(args)...){}
	native_handle_type& native_handle()
	{
		return handler;
	}
	std::mutex& mutex()
	{
		return *mtx;
	}
	template<typename ...Args>
	void write(Args&& ...args) requires output_stream<native_handle_type>
	{
		std::lock_guard lg(mutex());
		handler.write(std::forward<Args>(args)...);
	}
	void put(char_type ch) requires standard_output_stream<native_handle_type>
	{
		std::lock_guard lg(mutex());
		handler.put(ch);
	}
	void flush() requires output_stream<native_handle_type>
	{
		std::lock_guard lg(mutex());
		handler.flush();
	}
	template<typename Contiguous_iterator>
	Contiguous_iterator read(Contiguous_iterator begin,Contiguous_iterator end)
		requires input_stream<native_handle_type>
	{
		std::lock_guard<std::mutex> lg(mutex());
		return handler.read(begin,end);
	}
	auto get() requires standard_input_stream<native_handle_type>
	{
		std::lock_guard<std::mutex> lg(mutex());
		return handler.get();
	}
	auto try_get() requires standard_input_stream<native_handle_type>
	{
		std::lock_guard<std::mutex> lg(mutex());
		return handler.try_get();
	}
	template<typename... Args>
	void seek(Args&& ...args) requires random_access_stream<native_handle_type>
	{
		std::lock_guard<std::mutex> lg(mutex());
		handler.seek(std::forward<Args>(args)...);
	}
};



template<mutex_input_stream input,typename ...Args>
inline constexpr void scan(input &in,Args&& ...args)
{
	std::lock_guard lg{in.mutex()};
	scan(in.native_handle(),std::forward<Args>(args)...);
}
template<mutex_input_stream input,typename ...Args>
inline constexpr void read(input &in,Args&& ...args)
{
	std::lock_guard lg{in.mutex()};
	read(in.native_handle(),std::forward<Args>(args)...);
}

template<mutex_output_stream output,typename ...Args>
inline constexpr void print(output &out,Args&& ...args)
{
	std::lock_guard lg{out.mutex()};
	print(out.native_handle(),std::forward<Args>(args)...);
}

template<mutex_output_stream output,typename ...Args>
inline constexpr void println(output &out,Args&& ...args)
{
	std::lock_guard lg{out.mutex()};
	println(out.native_handle(),std::forward<Args>(args)...);
}

template<mutex_output_stream output,typename ...Args>
inline constexpr void fprint(output &out,Args&& ...args)
{
	std::lock_guard lg{out.mutex()};
	fprint(out.native_handle(),std::forward<Args>(args)...);
}

template<mutex_output_stream output,typename ...Args>
inline constexpr void print_flush(output &out,Args&& ...args)
{
	std::lock_guard lg{out.mutex()};
	print_flush(out.native_handle(),std::forward<Args>(args)...);
}

template<mutex_output_stream output,typename ...Args>
inline constexpr void println_flush(output &out,Args&& ...args)
{
	std::lock_guard lg{out.mutex()};
	println_flush(out.native_handle(),std::forward<Args>(args)...);
}

template<mutex_output_stream output,typename ...Args>
inline constexpr void fprint_flush(output &out,Args&& ...args)
{
	std::lock_guard lg{out.mutex()};
	fprint_flush(out.native_handle(),std::forward<Args>(args)...);
}

template<mutex_output_stream output,typename ...Args>
inline constexpr void write_flush(output& out,Args&& ...args)
{
	std::lock_guard lg(out.mutex());
	write_flush(out.native_handle(),std::forward<Args>(args)...);
}

}