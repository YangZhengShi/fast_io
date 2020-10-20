#pragma once

namespace fast_io
{

namespace details
{
template<std::integral char_type,bool iobuf=false>
inline constexpr std::size_t cal_buffer_size()
{
#ifdef FAST_IO_BUFFER_SIZE
	static_assert(sizeof(char_type)<=FAST_IO_BUFFER_SIZE);
#endif
	if constexpr(iobuf)
	{
		return 
#ifdef FAST_IO_BUFFER_SIZE
		FAST_IO_BUFFER_SIZE
#else
#if defined(__WINNT__) || defined(_MSC_VER)
	1048576
#else
	65536
#endif
#endif
		/sizeof(char_type);
	}
	else
	{
	return 
#ifdef FAST_IO_BUFFER_SIZE
	FAST_IO_BUFFER_SIZE	//avoid BUFSIZ macro since it is a cancer and often set incorrectly
#else
#ifdef FAST_IO_TRANSMIT_ON_STACK
	4096
#else
#if defined(__WINNT__) || defined(_MSC_VER)
	1048576
#else
	65536
#endif
#endif
#endif
	/sizeof(char_type);
	}
}

template<output_stream output,input_stream input>
inline constexpr std::uintmax_t bufferred_transmit_impl(output& outp,input& inp)
{
	if constexpr(contiguous_output_stream<output>)
	{
		using input_char_type = typename std::remove_cvref_t<input>::char_type;
		using output_char_type = typename std::remove_cvref_t<output>::char_type;
		if constexpr(std::same_as<input_char_type,output_char_type>)
		{
			auto curr{obuffer_curr(outp)};
			auto ed{obuffer_end(outp)};
			for(auto ip{curr};;)
			{
				auto readed{read(inp,ip,ed)};
				obuffer_set_curr(outp,readed);
				if((readed==ip)|(readed==ed))
					return readed-curr;
				ip=readed;
			}
		}
		else
		{
			static_assert(std::same_as<output_char_type,char>,"only char allows punning");
			typedef input_char_type 
#ifndef _MSC_VER
			__attribute__((__may_alias__))
#endif
			alias_input_char_type;
			auto raw_curr{obuffer_curr(outp)};
			auto raw_end{obuffer_end(outp)};
			alias_input_char_type* curr{reinterpret_cast<alias_input_char_type*>(raw_curr)};
			alias_input_char_type* ed{curr+(raw_end-raw_curr)/sizeof(input_char_type)};
			for(auto ip{curr};;)
			{
				auto readed{read(inp,ip,ed)};
				obuffer_set_curr(outp,reinterpret_cast<char*>(readed));
				if((readed==ip)|(readed==ed))
					return readed-curr;
				ip=readed;
			}
		}
	}
	else if constexpr(buffer_input_stream<input>)
	{
		std::uintmax_t transmitted_chars{};
		do
		{
			auto b{ibuffer_curr(inp)};
			auto e{ibuffer_end(inp)};
			if(b!=e)[[likely]]
			{
				std::size_t transmitted_this_round(static_cast<std::size_t>(e-b));
				write(outp,b,e);
				transmitted_chars+=transmitted_this_round;
			}
		}
		while(underflow(inp));
		return transmitted_chars;
	}
	else
	{
		std::uintmax_t transmitted_chars{};
		using char_type = typename std::remove_cvref_t<input>::char_type;
		constexpr std::size_t buffer_size{cal_buffer_size<char_type>()};
#ifdef FAST_IO_TRANSMIT_ON_STACK
		std::array<char_type,buffer_size> array;
#else
		temp_unique_arr_ptr<char_type> ptr(buffer_size);
// we need to allocate it on the heap to avoid potential stack overflows
		std::span<char_type,buffer_size> array(ptr.data(),ptr.data()+buffer_size);
#endif
		conditional_secure_clear_guard<char_type,secure_clear_requirement_stream<std::remove_cvref_t<input>>> guard(array.data(),buffer_size);
		for(;;)
		{
			auto p(read(inp,array.data(),array.data()+array.size()));
			if(p==array.data())
				return transmitted_chars;
			std::size_t transmitted_this_round(p-array.data());
			transmitted_chars+=transmitted_this_round;
			write(outp,array.data(),p);
			if(!transmitted_this_round)
				return transmitted_chars;
		}
	}
}

template<output_stream output,input_stream input>
inline constexpr std::uintmax_t bufferred_transmit_impl(output& outp,input& inp,std::uintmax_t chars)
{
	if constexpr(contiguous_output_stream<output>)
	{
		using input_char_type = typename std::remove_cvref_t<input>::char_type;
		using output_char_type = typename std::remove_cvref_t<output>::char_type;
		if constexpr(std::same_as<input_char_type,output_char_type>)
		{
			auto curr{obuffer_curr(outp)};
			auto ed{obuffer_end(outp)};
			if(chars<ed-curr)
				ed=chars;
			for(auto ip{curr};;)
			{
				auto readed{read(inp,ip,ed)};
				obuffer_set_curr(outp,readed);
				if((readed==ip)|(readed==ed))
					return readed-curr;
				ip=readed;
			}
		}
		else
		{
			static_assert(std::same_as<output_char_type,char>,"only char allows punning");
			typedef input_char_type 
#ifndef _MSC_VER
			__attribute__((__may_alias__))
#endif
			alias_input_char_type;
			auto raw_curr{obuffer_curr(outp)};
			auto raw_end{obuffer_end(outp)};
			alias_input_char_type* curr{reinterpret_cast<alias_input_char_type*>(raw_curr)};
			alias_input_char_type* ed{curr+(raw_end-raw_curr)/sizeof(input_char_type)};
			if(chars<ed-curr)
				ed=chars;
			for(auto ip{curr};;)
			{
				auto readed{read(inp,ip,ed)};
				obuffer_set_curr(outp,reinterpret_cast<char*>(readed));
				if((readed==ip)|(readed==ed))
					return readed-curr;
				ip=readed;
			}
		}
	}
	else if constexpr(buffer_input_stream<input>)
	{
		std::uintmax_t transmitted_chars{};
		do
		{
			auto b(ibuffer_curr(inp));
			auto e(ibuffer_end(inp));
			if(b!=e)[[likely]]
			{
				std::size_t transmitted_this_round{e-b};
				if(chars<=transmitted_this_round)
				{
					write(outp,b,b+chars);
					return transmitted_chars+transmitted_this_round;
				}
				else
				{
					write(outp,b,e);
					transmitted_chars+=transmitted_this_round;
					chars-=transmitted_this_round;
				}
			}
		}
		while(underflow(inp));
		return transmitted_chars;
	}
	else
	{
		std::uintmax_t transmitted_chars{};
		using char_type = typename std::remove_cvref_t<input>::char_type;
		constexpr std::size_t buffer_size{cal_buffer_size<char_type>()};
#ifdef FAST_IO_TRANSMIT_ON_STACK
		std::array<char_type,buffer_size> array;
#else
		temp_unique_arr_ptr<char_type> ptr(buffer_size);
// we need to allocate it on the heap to avoid potential stack overflows
		std::span<char_type,buffer_size> array(ptr.data(),ptr.data()+buffer_size);
#endif
		conditional_secure_clear_guard<char_type,secure_clear_requirement_stream<std::remove_cvref_t<input>>> guard(array.data(),buffer_size);
		for(;chars;)
		{
			std::size_t b(array.size());
			if(chars<b)
				b=chars;
			auto p(read(inp,array.data(),array.data()+b));
			if(p==array.data())
				return transmitted_chars;
			std::size_t read_chars(p-array.data());
			write(outp,array.data(),p);
			transmitted_chars+=read_chars;
			if(read_chars!=b)
				return transmitted_chars;
			chars-=read_chars;
		}
		return transmitted_chars;
	}
}
#if defined(__linux__)
template<output_stream output,input_stream input>
inline constexpr std::uintmax_t zero_copy_transmit_impl(output& outp,input& inp)
{
	auto ret(zero_copy_transmit<false,true>(outp,inp,0));
	if(ret.second)
		return ret.first+bufferred_transmit_impl(outp,inp);
	return ret.first;
}

template<output_stream output,input_stream input>
inline constexpr std::uintmax_t zero_copy_transmit_impl(output& outp,input& inp,std::uintmax_t sz)
{
	auto ret(zero_copy_transmit<false,true>(outp,inp,sz,0)); 
	if(ret.second)
		return ret.first+bufferred_transmit_impl(outp,inp,sz-ret.first);
	return ret.first;
}
#endif

template<output_stream output,input_stream input,typename... Args>
inline constexpr auto transmit_impl(output& outp,input& inp,Args&& ...args)
{
	if constexpr(mutex_stream<input>)
	{
		details::lock_guard lg{inp};
		decltype(auto) uh{inp.unlocked_handle()};
		return transmit_impl(outp,uh,std::forward<Args>(args)...);
	}
	else
	{
#ifdef __cpp_lib_is_constant_evaluated
		if (std::is_constant_evaluated())
			return bufferred_transmit_impl(outp,inp,std::forward<Args>(args)...);
		else
		{
#endif
		if constexpr(zero_copy_output_stream<output>&&zero_copy_input_stream<input>)
		{
			if constexpr(buffer_input_stream<input>)
			{
				write(outp,ibuffer_curr(inp),ibuffer_end(inp));
				ibuffer_set_curr(inp,ibuffer_end(inp));
			}
			if constexpr(buffer_output_stream<output>)
				flush(outp);
#if defined(__linux__)
			return zero_copy_transmit_impl(outp,inp,std::forward<Args>(args)...);
#else
			return zero_copy_transmit<false>(outp,inp,0,std::forward<Args>(args)...);
#endif
		}
		else
			return bufferred_transmit_impl(outp,inp,std::forward<Args>(args)...);
#ifdef __cpp_lib_is_constant_evaluated
		}
#endif
	}
}
}
template<output_stream output,input_stream input,std::integral sz_type>
inline constexpr void print_define(output& outp,manip::transmission<input,sz_type> ref)
{
	ref.transmitted=static_cast<sz_type>(details::transmit_impl(outp,ref.reference));
}

template<output_stream output,input_stream input,std::integral sz_type>
inline constexpr void print_define(output& outp,manip::transmission_with_size<input,sz_type> ref)
{
	ref.transmitted=static_cast<sz_type>(details::transmit_impl(outp,ref.reference,ref.size));
}

template<output_stream output,input_stream input,std::integral sz_type>
inline constexpr sz_type transmit(output&& outp,input&& in,sz_type s)
{
	sz_type transmitted{};
	print_freestanding(std::forward<output>(outp),manip::transmission_with_size<input,sz_type>{transmitted,in,s});
	return transmitted;
}

template<output_stream output,input_stream input>
inline constexpr std::uintmax_t transmit(output&& outp,input&& in)
{
	std::uintmax_t transmitted{};
	print_freestanding(std::forward<output>(outp),manip::transmission<input,std::uintmax_t>{transmitted,in});
	return transmitted;
}

}
