#pragma once

namespace fast_io
{

template<buffer_output_stream output,std::integral char_type>
requires std::same_as<typename output::char_type,char_type>
inline constexpr void print_define(output bos,basic_lc_identification<char_type> const& identification)
{
	if constexpr(std::same_as<char_type,char>)
		print_freestanding(bos,"LC_IDENTIFICATION\n"
			"title\t\"",identification.title,"\"\n"
			"source\t\"",identification.source,"\"\n"
			"address\t\"",identification.address,"\"\n"
			"contact\t\"",identification.contact,"\"\n"
			"email\t\"",identification.email,"\"\n"
			"tel\t\"",identification.tel,"\"\n"
			"fax\t\"",identification.fax,"\"\n"
			"language\t\"",identification.language,"\"\n"
			"territory\t\"",identification.territory,"\"\n"
			"audience\t\"",identification.audience,"\"\n"
			"application\t\"",identification.application,"\"\n"
			"abbreviation\t\"",identification.abbreviation,"\"\n"
			"revision\t\"",identification.revision,"\"\n"
			"date\t\"",identification.date,"\"\n"
			"END LC_IDENTIFICATION");
	else if constexpr(std::same_as<char_type,wchar_t>)
		print_freestanding(bos,L"LC_IDENTIFICATION\n"
			L"title\t\"",identification.title,L"\"\n"
			L"source\t\"",identification.source,L"\"\n"
			L"address\t\"",identification.address,L"\"\n"
			L"contact\t\"",identification.contact,L"\"\n"
			L"email\t\"",identification.email,L"\"\n"
			L"tel\t\"",identification.tel,L"\"\n"
			L"fax\t\"",identification.fax,L"\"\n"
			L"language\t\"",identification.language,L"\"\n"
			L"territory\t\"",identification.territory,L"\"\n"
			L"audience\t\"",identification.audience,L"\"\n"
			L"application\t\"",identification.application,L"\"\n"
			L"abbreviation\t\"",identification.abbreviation,L"\"\n"
			L"revision\t\"",identification.revision,L"\"\n"
			L"date\t\"",identification.date,L"\"\n"
			L"END LC_IDENTIFICATION");
	else if constexpr(std::same_as<char_type,char16_t>)
		print_freestanding(bos,u"LC_IDENTIFICATION\n"
			u"title\t\"",identification.title,u"\"\n"
			u"source\t\"",identification.source,u"\"\n"
			u"address\t\"",identification.address,u"\"\n"
			u"contact\t\"",identification.contact,u"\"\n"
			u"email\t\"",identification.email,u"\"\n"
			u"tel\t\"",identification.tel,u"\"\n"
			u"fax\t\"",identification.fax,u"\"\n"
			u"language\t\"",identification.language,u"\"\n"
			u"territory\t\"",identification.territory,u"\"\n"
			u"audience\t\"",identification.audience,u"\"\n"
			u"application\t\"",identification.application,u"\"\n"
			u"abbreviation\t\"",identification.abbreviation,u"\"\n"
			u"revision\t\"",identification.revision,u"\"\n"
			u"date\t\"",identification.date,u"\"\n"
			u"END LC_IDENTIFICATION");
	else if constexpr(std::same_as<char_type,char32_t>)
		print_freestanding(bos,U"LC_IDENTIFICATION\n"
			U"title\t\"",identification.title,U"\"\n"
			U"source\t\"",identification.source,U"\"\n"
			U"address\t\"",identification.address,U"\"\n"
			U"contact\t\"",identification.contact,U"\"\n"
			U"email\t\"",identification.email,U"\"\n"
			U"tel\t\"",identification.tel,U"\"\n"
			U"fax\t\"",identification.fax,U"\"\n"
			U"language\t\"",identification.language,U"\"\n"
			U"territory\t\"",identification.territory,U"\"\n"
			U"audience\t\"",identification.audience,U"\"\n"
			U"application\t\"",identification.application,U"\"\n"
			U"abbreviation\t\"",identification.abbreviation,U"\"\n"
			U"revision\t\"",identification.revision,U"\"\n"
			U"date\t\"",identification.date,U"\"\n"
			U"END LC_IDENTIFICATION");
	else if constexpr(std::same_as<char_type,char8_t>)
		print_freestanding(bos,u8"LC_IDENTIFICATION\n"
			u8"title\t\"",identification.title,u8"\"\n"
			u8"source\t\"",identification.source,u8"\"\n"
			u8"address\t\"",identification.address,u8"\"\n"
			u8"contact\t\"",identification.contact,u8"\"\n"
			u8"email\t\"",identification.email,u8"\"\n"
			u8"tel\t\"",identification.tel,u8"\"\n"
			u8"fax\t\"",identification.fax,u8"\"\n"
			u8"language\t\"",identification.language,u8"\"\n"
			u8"territory\t\"",identification.territory,u8"\"\n"
			u8"audience\t\"",identification.audience,u8"\"\n"
			u8"application\t\"",identification.application,u8"\"\n"
			u8"abbreviation\t\"",identification.abbreviation,u8"\"\n"
			u8"revision\t\"",identification.revision,u8"\"\n"
			u8"date\t\"",identification.date,u8"\"\n"
			u8"END LC_IDENTIFICATION");
}

namespace details
{
template<buffer_output_stream output>
inline void print_grouping(output bos,basic_io_scatter_t<std::size_t> grouping)
{
	using char_type = typename output::char_type;
	for(std::size_t i{};i!=grouping.len;++i)
	{
		if(i)
		{
			if constexpr(std::same_as<char,char_type>)
				print_freestanding(bos,";");
			else if constexpr(std::same_as<wchar_t,char_type>)
				print_freestanding(bos,L";");
			else if constexpr(std::same_as<char16_t,char_type>)
				print_freestanding(bos,u";");
			else if constexpr(std::same_as<char32_t,char_type>)
				print_freestanding(bos,U";");
			else if constexpr(std::same_as<char8_t,char_type>)
				print_freestanding(bos,u8";");
		}
		if(grouping.base[i]==std::numeric_limits<std::size_t>::max())
		{
			if constexpr(std::same_as<char,char_type>)
				print_freestanding(bos,"-1");
			else if constexpr(std::same_as<wchar_t,char_type>)
				print_freestanding(bos,L"-1");
			else if constexpr(std::same_as<char16_t,char_type>)
				print_freestanding(bos,u"-1");
			else if constexpr(std::same_as<char32_t,char_type>)
				print_freestanding(bos,U"-1");
			else if constexpr(std::same_as<char8_t,char_type>)
				print_freestanding(bos,u8"-1");
		}
		else
			print_freestanding(bos,grouping.base[i]);
	}
}

}

template<buffer_output_stream output,std::integral char_type>
requires std::same_as<typename output::char_type,char_type>
inline constexpr void print_define(output bos,basic_lc_monetary<char_type> const& monetary)
{
	if constexpr(std::same_as<char_type,char>)
	{
		print_freestanding(bos,"LC_MONETARY\n"
			"int_curr_symbol\t\"",monetary.int_curr_symbol,"\"\n"
			"currency_symbol\t\"",monetary.currency_symbol,"\"\n"
			"mon_decimal_point\t\"",monetary.mon_decimal_point,"\"\n"
			"mon_thousands_sep\t\"",monetary.mon_thousands_sep,"\"\n"
			"mon_grouping\t");
		details::print_grouping(bos,monetary.mon_grouping);
		print_freestanding(bos,"\n"
			"positive_sign\t\"",monetary.positive_sign,"\"\n"
			"negative_sign\t\"",monetary.negative_sign,"\"\n"
			"int_frac_digits\t",monetary.int_frac_digits,"\n"
			"frac_digits\t",monetary.frac_digits,"\n"
			"p_cs_precedes\t",monetary.p_cs_precedes,"\n"
			"p_sep_by_space\t",monetary.p_sep_by_space,"\n"
			"n_cs_precedes\t",monetary.n_cs_precedes,"\n"
			"n_sep_by_space\t",monetary.n_sep_by_space,"\n"
			"int_p_cs_precedes\t",monetary.int_p_cs_precedes,"\n"
			"int_p_sep_by_space\t",monetary.int_p_sep_by_space,"\n"
			"int_n_cs_precedes\t",monetary.int_n_cs_precedes,"\n"
			"int_n_sep_by_space\t",monetary.int_n_sep_by_space,"\n"
			"p_sign_posn\t",monetary.p_sign_posn,"\n"
			"n_sign_posn\t",monetary.n_sign_posn,"\n"
			"int_p_sign_posn\t",monetary.int_p_sign_posn,"\n"
			"int_n_sign_posn\t",monetary.int_n_sign_posn,"\n"
			"END LC_MONETARY");
	}
	else if constexpr(std::same_as<char_type,wchar_t>)
	{
		print_freestanding(bos,L"LC_MONETARY\n"
			L"int_curr_symbol\t\"",monetary.int_curr_symbol,L"\"\n"
			L"currency_symbol\t\"",monetary.currency_symbol,L"\"\n"
			L"mon_decimal_point\t\"",monetary.mon_decimal_point,L"\"\n"
			L"mon_thousands_sep\t\"",monetary.mon_thousands_sep,L"\"\n"
			L"mon_grouping\t");
		details::print_grouping(bos,monetary.mon_grouping);
		print_freestanding(bos,L"\n"
			L"positive_sign\t\"",monetary.positive_sign,L"\"\n"
			L"negative_sign\t\"",monetary.negative_sign,L"\"\n"
			L"int_frac_digits\t",monetary.int_frac_digits,L"\n"
			L"frac_digits\t",monetary.frac_digits,L"\n"
			L"p_cs_precedes\t",monetary.p_cs_precedes,L"\n"
			L"p_sep_by_space\t",monetary.p_sep_by_space,L"\n"
			L"n_cs_precedes\t",monetary.n_cs_precedes,L"\n"
			L"n_sep_by_space\t",monetary.n_sep_by_space,L"\n"
			L"int_p_cs_precedes\t",monetary.int_p_cs_precedes,L"\n"
			L"int_p_sep_by_space\t",monetary.int_p_sep_by_space,L"\n"
			L"int_n_cs_precedes\t",monetary.int_n_cs_precedes,L"\n"
			L"int_n_sep_by_space\t",monetary.int_n_sep_by_space,L"\n"
			L"p_sign_posn\t",monetary.p_sign_posn,L"\n"
			L"n_sign_posn\t",monetary.n_sign_posn,L"\n"
			L"int_p_sign_posn\t",monetary.int_p_sign_posn,L"\n"
			L"int_n_sign_posn\t",monetary.int_n_sign_posn,L"\n"
			L"END LC_MONETARY");
	}
	else if constexpr(std::same_as<char_type,char16_t>)
	{
		print_freestanding(bos,u"LC_MONETARY\n"
			u"int_curr_symbol\t\"",monetary.int_curr_symbol,u"\"\n"
			u"currency_symbol\t\"",monetary.currency_symbol,u"\"\n"
			u"mon_decimal_point\t\"",monetary.mon_decimal_point,u"\"\n"
			u"mon_thousands_sep\t\"",monetary.mon_thousands_sep,u"\"\n"
			u"mon_grouping\t");
		details::print_grouping(bos,monetary.mon_grouping);
		print_freestanding(bos,u"\n"
			u"positive_sign\t\"",monetary.positive_sign,u"\"\n"
			u"negative_sign\t\"",monetary.negative_sign,u"\"\n"
			u"int_frac_digits\t",monetary.int_frac_digits,u"\n"
			u"frac_digits\t",monetary.frac_digits,u"\n"
			u"p_cs_precedes\t",monetary.p_cs_precedes,u"\n"
			u"p_sep_by_space\t",monetary.p_sep_by_space,u"\n"
			u"n_cs_precedes\t",monetary.n_cs_precedes,u"\n"
			u"n_sep_by_space\t",monetary.n_sep_by_space,u"\n"
			u"int_p_cs_precedes\t",monetary.int_p_cs_precedes,u"\n"
			u"int_p_sep_by_space\t",monetary.int_p_sep_by_space,u"\n"
			u"int_n_cs_precedes\t",monetary.int_n_cs_precedes,u"\n"
			u"int_n_sep_by_space\t",monetary.int_n_sep_by_space,u"\n"
			u"p_sign_posn\t",monetary.p_sign_posn,u"\n"
			u"n_sign_posn\t",monetary.n_sign_posn,u"\n"
			u"int_p_sign_posn\t",monetary.int_p_sign_posn,u"\n"
			u"int_n_sign_posn\t",monetary.int_n_sign_posn,u"\n"
			u"END LC_MONETARY");
	}
	else if constexpr(std::same_as<char_type,char32_t>)
	{
		print_freestanding(bos,U"LC_MONETARY\n"
			U"int_curr_symbol\t\"",monetary.int_curr_symbol,U"\"\n"
			U"currency_symbol\t\"",monetary.currency_symbol,U"\"\n"
			U"mon_decimal_point\t\"",monetary.mon_decimal_point,U"\"\n"
			U"mon_thousands_sep\t\"",monetary.mon_thousands_sep,U"\"\n"
			U"mon_grouping\t");
		details::print_grouping(bos,monetary.mon_grouping);
		print_freestanding(bos,U"\n"
			U"positive_sign\t\"",monetary.positive_sign,U"\"\n"
			U"negative_sign\t\"",monetary.negative_sign,U"\"\n"
			U"int_frac_digits\t",monetary.int_frac_digits,U"\n"
			U"frac_digits\t",monetary.frac_digits,U"\n"
			U"p_cs_precedes\t",monetary.p_cs_precedes,U"\n"
			U"p_sep_by_space\t",monetary.p_sep_by_space,U"\n"
			U"n_cs_precedes\t",monetary.n_cs_precedes,U"\n"
			U"n_sep_by_space\t",monetary.n_sep_by_space,U"\n"
			U"int_p_cs_precedes\t",monetary.int_p_cs_precedes,U"\n"
			U"int_p_sep_by_space\t",monetary.int_p_sep_by_space,U"\n"
			U"int_n_cs_precedes\t",monetary.int_n_cs_precedes,U"\n"
			U"int_n_sep_by_space\t",monetary.int_n_sep_by_space,U"\n"
			U"p_sign_posn\t",monetary.p_sign_posn,U"\n"
			U"n_sign_posn\t",monetary.n_sign_posn,U"\n"
			U"int_p_sign_posn\t",monetary.int_p_sign_posn,U"\n"
			U"int_n_sign_posn\t",monetary.int_n_sign_posn,U"\n"
			U"END LC_MONETARY");
	}
	else if constexpr(std::same_as<char_type,char8_t>)
	{
		print_freestanding(bos,u8"LC_MONETARY\n"
			u8"int_curr_symbol\t\"",monetary.int_curr_symbol,u8"\"\n"
			u8"currency_symbol\t\"",monetary.currency_symbol,u8"\"\n"
			u8"mon_decimal_point\t\"",monetary.mon_decimal_point,u8"\"\n"
			u8"mon_thousands_sep\t\"",monetary.mon_thousands_sep,u8"\"\n"
			u8"mon_grouping\t");
		details::print_grouping(bos,monetary.mon_grouping);
		print_freestanding(bos,u8"\n"
			u8"positive_sign\t\"",monetary.positive_sign,u8"\"\n"
			u8"negative_sign\t\"",monetary.negative_sign,u8"\"\n"
			u8"int_frac_digits\t",monetary.int_frac_digits,u8"\n"
			u8"frac_digits\t",monetary.frac_digits,u8"\n"
			u8"p_cs_precedes\t",monetary.p_cs_precedes,u8"\n"
			u8"p_sep_by_space\t",monetary.p_sep_by_space,u8"\n"
			u8"n_cs_precedes\t",monetary.n_cs_precedes,u8"\n"
			u8"n_sep_by_space\t",monetary.n_sep_by_space,u8"\n"
			u8"int_p_cs_precedes\t",monetary.int_p_cs_precedes,u8"\n"
			u8"int_p_sep_by_space\t",monetary.int_p_sep_by_space,u8"\n"
			u8"int_n_cs_precedes\t",monetary.int_n_cs_precedes,u8"\n"
			u8"int_n_sep_by_space\t",monetary.int_n_sep_by_space,u8"\n"
			u8"p_sign_posn\t",monetary.p_sign_posn,u8"\n"
			u8"n_sign_posn\t",monetary.n_sign_posn,u8"\n"
			u8"int_p_sign_posn\t",monetary.int_p_sign_posn,u8"\n"
			u8"int_n_sign_posn\t",monetary.int_n_sign_posn,u8"\n"
			u8"END LC_MONETARY");
	}
}


template<buffer_output_stream output,std::integral char_type>
requires std::same_as<typename output::char_type,char_type>
inline constexpr void print_define(output bos,basic_lc_numeric<char_type> const& numeric)
{
	if constexpr(std::same_as<char_type,char>)
	{
		print_freestanding(bos,"LC_NUMERIC\n"
			"decimal_point\t\"",numeric.decimal_point,"\"\n"
			"thousands_sep\t\"",numeric.thousands_sep,"\"\n"
			"grouping\t");
		details::print_grouping(bos,numeric.grouping);
		print_freestanding(bos,"\n"
			"END LC_NUMERIC");
	}
	else if constexpr(std::same_as<char_type,wchar_t>)
	{
		print_freestanding(bos,L"LC_NUMERIC\n"
			L"decimal_point\t\"",numeric.decimal_point,L"\"\n"
			L"thousands_sep\t\"",numeric.thousands_sep,L"\"\n"
			L"grouping\t");
		details::print_grouping(bos,numeric.grouping);
		print_freestanding(bos,L"\n"
			L"END LC_NUMERIC");
	}
	else if constexpr(std::same_as<char_type,char16_t>)
	{
		print_freestanding(bos,u"LC_NUMERIC\n"
			u"decimal_point\t\"",numeric.decimal_point,u"\"\n"
			u"thousands_sep\t\"",numeric.thousands_sep,u"\"\n"
			u"grouping\t");
		details::print_grouping(bos,numeric.grouping);
		print_freestanding(bos,u"\n"
			u"END LC_NUMERIC");
	}
	else if constexpr(std::same_as<char_type,char32_t>)
	{
		print_freestanding(bos,U"LC_NUMERIC\n"
			U"decimal_point\t\"",numeric.decimal_point,U"\"\n"
			U"thousands_sep\t\"",numeric.thousands_sep,U"\"\n"
			U"grouping\t");
		details::print_grouping(bos,numeric.grouping);
		print_freestanding(bos,U"\n"
			U"END LC_NUMERIC");
	}
	else if constexpr(std::same_as<char_type,char8_t>)
	{
		print_freestanding(bos,u8"LC_NUMERIC\n"
			u8"decimal_point\t\"",numeric.decimal_point,u8"\"\n"
			u8"thousands_sep\t\"",numeric.thousands_sep,u8"\"\n"
			u8"grouping\t");
		details::print_grouping(bos,numeric.grouping);
		print_freestanding(bos,u8"\n"
			u8"END LC_NUMERIC");
	}
}

template<buffer_output_stream output,std::integral char_type>
requires std::same_as<typename output::char_type,char_type>
inline constexpr void print_define(output bos,basic_lc_all<char_type> const& all)
{
	if constexpr(std::same_as<char_type,char>)
		print_freestanding(bos,all.identification,"\n\n",
			all.monetary,"\n\n",
			all.numeric);
}

template<buffer_output_stream output>
inline constexpr void print_define(output bos,lc_locale const& loc)
{
	if constexpr(std::same_as<typename output::char_type,char>)
		print_freestanding(bos,*loc.all);
	else if constexpr(std::same_as<typename output::char_type,wchar_t>)
		print_freestanding(bos,*loc.wall);
	else if constexpr(std::same_as<typename output::char_type,char8_t>)
		print_freestanding(bos,*loc.u8all);
	else if constexpr(std::same_as<typename output::char_type,char16_t>)
		print_freestanding(bos,*loc.u16all);
	else if constexpr(std::same_as<typename output::char_type,char16_t>)
		print_freestanding(bos,*loc.u32all);
}


}