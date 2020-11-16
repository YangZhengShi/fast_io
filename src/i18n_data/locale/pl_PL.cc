#include"../localedef.h"

namespace fast_io_i18n
{
namespace
{

inline constexpr std::size_t numeric_grouping_storage[]{3};

inline constexpr lc_all lc_all_global{.identification={.title=tsc("Polish locale for Poland"),.source=tsc("RAP\t\t;\t\tfast_io"),.address=tsc("Sankt Jo/rgens Alle 8, DK-1615 Ko/benhavn V, Danmark\t\t;\t\thttps://github.com/expnkx/fast_io"),.contact=tsc("fast_io"),.email=tsc("bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(""),.fax=tsc(""),.language=tsc("Polish"),.territory=tsc("Poland"),.revision=tsc("1.0"),.date=tsc("2000-06-29")},.monetary={.int_curr_symbol=tsc("PLN "),.currency_symbol=tsc("zł"),.mon_decimal_point=tsc(","),.mon_thousands_sep=tsc(" "),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(""),.negative_sign=tsc("-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=0,.p_sep_by_space=1,.n_cs_precedes=0,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(","),.thousands_sep=tsc(" "),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc("nie"),tsc("pon"),tsc("wto"),tsc("śro"),tsc("czw"),tsc("pią"),tsc("sob")},.day={tsc("niedziela"),tsc("poniedziałek"),tsc("wtorek"),tsc("środa"),tsc("czwartek"),tsc("piątek"),tsc("sobota")},.abmon={tsc("sty"),tsc("lut"),tsc("mar"),tsc("kwi"),tsc("maj"),tsc("cze"),tsc("lip"),tsc("sie"),tsc("wrz"),tsc("paź"),tsc("lis"),tsc("gru")},.mon={tsc("stycznia"),tsc("lutego"),tsc("marca"),tsc("kwietnia"),tsc("maja"),tsc("czerwca"),tsc("lipca"),tsc("sierpnia"),tsc("września"),tsc("października"),tsc("listopada"),tsc("grudnia")},.d_t_fmt=tsc("%a, %-d %b %Y, %T"),.d_fmt=tsc("%d.%m.%Y"),.t_fmt=tsc("%T"),.t_fmt_ampm=tsc(""),.date_fmt=tsc("%a, %-d %b %Y, %T %Z"),.am_pm={tsc(""),tsc("")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc("^[+1TtYy]"),.noexpr=tsc("^[-0nN]"),.yesstr=tsc("tak"),.nostr=tsc("nie")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc("+%c %a %l"),.int_select=tsc("00"),.int_prefix=tsc("48")},.name={.name_fmt=tsc("%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc("%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc("Polska"),.country_ab2=tsc("PL"),.country_ab3=tsc("POL"),.country_num=616,.country_car=tsc("PL"),.lang_name=tsc("polski"),.lang_ab=tsc("pl"),.lang_term=tsc("pol"),.lang_lib=tsc("pol")},.measurement={.measurement=1}};

inline constexpr wlc_all wlc_all_global{.identification={.title=tsc(L"Polish locale for Poland"),.source=tsc(L"RAP\t\t;\t\tfast_io"),.address=tsc(L"Sankt Jo/rgens Alle 8, DK-1615 Ko/benhavn V, Danmark\t\t;\t\thttps://github.com/expnkx/fast_io"),.contact=tsc(L"fast_io"),.email=tsc(L"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(L""),.fax=tsc(L""),.language=tsc(L"Polish"),.territory=tsc(L"Poland"),.revision=tsc(L"1.0"),.date=tsc(L"2000-06-29")},.monetary={.int_curr_symbol=tsc(L"PLN "),.currency_symbol=tsc(L"zł"),.mon_decimal_point=tsc(L","),.mon_thousands_sep=tsc(L" "),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(L""),.negative_sign=tsc(L"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=0,.p_sep_by_space=1,.n_cs_precedes=0,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(L","),.thousands_sep=tsc(L" "),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(L"nie"),tsc(L"pon"),tsc(L"wto"),tsc(L"śro"),tsc(L"czw"),tsc(L"pią"),tsc(L"sob")},.day={tsc(L"niedziela"),tsc(L"poniedziałek"),tsc(L"wtorek"),tsc(L"środa"),tsc(L"czwartek"),tsc(L"piątek"),tsc(L"sobota")},.abmon={tsc(L"sty"),tsc(L"lut"),tsc(L"mar"),tsc(L"kwi"),tsc(L"maj"),tsc(L"cze"),tsc(L"lip"),tsc(L"sie"),tsc(L"wrz"),tsc(L"paź"),tsc(L"lis"),tsc(L"gru")},.mon={tsc(L"stycznia"),tsc(L"lutego"),tsc(L"marca"),tsc(L"kwietnia"),tsc(L"maja"),tsc(L"czerwca"),tsc(L"lipca"),tsc(L"sierpnia"),tsc(L"września"),tsc(L"października"),tsc(L"listopada"),tsc(L"grudnia")},.d_t_fmt=tsc(L"%a, %-d %b %Y, %T"),.d_fmt=tsc(L"%d.%m.%Y"),.t_fmt=tsc(L"%T"),.t_fmt_ampm=tsc(L""),.date_fmt=tsc(L"%a, %-d %b %Y, %T %Z"),.am_pm={tsc(L""),tsc(L"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(L"^[+1TtYy]"),.noexpr=tsc(L"^[-0nN]"),.yesstr=tsc(L"tak"),.nostr=tsc(L"nie")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(L"+%c %a %l"),.int_select=tsc(L"00"),.int_prefix=tsc(L"48")},.name={.name_fmt=tsc(L"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(L"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(L"Polska"),.country_ab2=tsc(L"PL"),.country_ab3=tsc(L"POL"),.country_num=616,.country_car=tsc(L"PL"),.lang_name=tsc(L"polski"),.lang_ab=tsc(L"pl"),.lang_term=tsc(L"pol"),.lang_lib=tsc(L"pol")},.measurement={.measurement=1}};

inline constexpr u8lc_all u8lc_all_global{.identification={.title=tsc(u8"Polish locale for Poland"),.source=tsc(u8"RAP\t\t;\t\tfast_io"),.address=tsc(u8"Sankt Jo/rgens Alle 8, DK-1615 Ko/benhavn V, Danmark\t\t;\t\thttps://github.com/expnkx/fast_io"),.contact=tsc(u8"fast_io"),.email=tsc(u8"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(u8""),.fax=tsc(u8""),.language=tsc(u8"Polish"),.territory=tsc(u8"Poland"),.revision=tsc(u8"1.0"),.date=tsc(u8"2000-06-29")},.monetary={.int_curr_symbol=tsc(u8"PLN "),.currency_symbol=tsc(u8"zł"),.mon_decimal_point=tsc(u8","),.mon_thousands_sep=tsc(u8" "),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u8""),.negative_sign=tsc(u8"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=0,.p_sep_by_space=1,.n_cs_precedes=0,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u8","),.thousands_sep=tsc(u8" "),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u8"nie"),tsc(u8"pon"),tsc(u8"wto"),tsc(u8"śro"),tsc(u8"czw"),tsc(u8"pią"),tsc(u8"sob")},.day={tsc(u8"niedziela"),tsc(u8"poniedziałek"),tsc(u8"wtorek"),tsc(u8"środa"),tsc(u8"czwartek"),tsc(u8"piątek"),tsc(u8"sobota")},.abmon={tsc(u8"sty"),tsc(u8"lut"),tsc(u8"mar"),tsc(u8"kwi"),tsc(u8"maj"),tsc(u8"cze"),tsc(u8"lip"),tsc(u8"sie"),tsc(u8"wrz"),tsc(u8"paź"),tsc(u8"lis"),tsc(u8"gru")},.mon={tsc(u8"stycznia"),tsc(u8"lutego"),tsc(u8"marca"),tsc(u8"kwietnia"),tsc(u8"maja"),tsc(u8"czerwca"),tsc(u8"lipca"),tsc(u8"sierpnia"),tsc(u8"września"),tsc(u8"października"),tsc(u8"listopada"),tsc(u8"grudnia")},.d_t_fmt=tsc(u8"%a, %-d %b %Y, %T"),.d_fmt=tsc(u8"%d.%m.%Y"),.t_fmt=tsc(u8"%T"),.t_fmt_ampm=tsc(u8""),.date_fmt=tsc(u8"%a, %-d %b %Y, %T %Z"),.am_pm={tsc(u8""),tsc(u8"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(u8"^[+1TtYy]"),.noexpr=tsc(u8"^[-0nN]"),.yesstr=tsc(u8"tak"),.nostr=tsc(u8"nie")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u8"+%c %a %l"),.int_select=tsc(u8"00"),.int_prefix=tsc(u8"48")},.name={.name_fmt=tsc(u8"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(u8"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(u8"Polska"),.country_ab2=tsc(u8"PL"),.country_ab3=tsc(u8"POL"),.country_num=616,.country_car=tsc(u8"PL"),.lang_name=tsc(u8"polski"),.lang_ab=tsc(u8"pl"),.lang_term=tsc(u8"pol"),.lang_lib=tsc(u8"pol")},.measurement={.measurement=1}};

inline constexpr u16lc_all u16lc_all_global{.identification={.title=tsc(u"Polish locale for Poland"),.source=tsc(u"RAP\t\t;\t\tfast_io"),.address=tsc(u"Sankt Jo/rgens Alle 8, DK-1615 Ko/benhavn V, Danmark\t\t;\t\thttps://github.com/expnkx/fast_io"),.contact=tsc(u"fast_io"),.email=tsc(u"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(u""),.fax=tsc(u""),.language=tsc(u"Polish"),.territory=tsc(u"Poland"),.revision=tsc(u"1.0"),.date=tsc(u"2000-06-29")},.monetary={.int_curr_symbol=tsc(u"PLN "),.currency_symbol=tsc(u"zł"),.mon_decimal_point=tsc(u","),.mon_thousands_sep=tsc(u" "),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(u""),.negative_sign=tsc(u"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=0,.p_sep_by_space=1,.n_cs_precedes=0,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(u","),.thousands_sep=tsc(u" "),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(u"nie"),tsc(u"pon"),tsc(u"wto"),tsc(u"śro"),tsc(u"czw"),tsc(u"pią"),tsc(u"sob")},.day={tsc(u"niedziela"),tsc(u"poniedziałek"),tsc(u"wtorek"),tsc(u"środa"),tsc(u"czwartek"),tsc(u"piątek"),tsc(u"sobota")},.abmon={tsc(u"sty"),tsc(u"lut"),tsc(u"mar"),tsc(u"kwi"),tsc(u"maj"),tsc(u"cze"),tsc(u"lip"),tsc(u"sie"),tsc(u"wrz"),tsc(u"paź"),tsc(u"lis"),tsc(u"gru")},.mon={tsc(u"stycznia"),tsc(u"lutego"),tsc(u"marca"),tsc(u"kwietnia"),tsc(u"maja"),tsc(u"czerwca"),tsc(u"lipca"),tsc(u"sierpnia"),tsc(u"września"),tsc(u"października"),tsc(u"listopada"),tsc(u"grudnia")},.d_t_fmt=tsc(u"%a, %-d %b %Y, %T"),.d_fmt=tsc(u"%d.%m.%Y"),.t_fmt=tsc(u"%T"),.t_fmt_ampm=tsc(u""),.date_fmt=tsc(u"%a, %-d %b %Y, %T %Z"),.am_pm={tsc(u""),tsc(u"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(u"^[+1TtYy]"),.noexpr=tsc(u"^[-0nN]"),.yesstr=tsc(u"tak"),.nostr=tsc(u"nie")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(u"+%c %a %l"),.int_select=tsc(u"00"),.int_prefix=tsc(u"48")},.name={.name_fmt=tsc(u"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(u"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(u"Polska"),.country_ab2=tsc(u"PL"),.country_ab3=tsc(u"POL"),.country_num=616,.country_car=tsc(u"PL"),.lang_name=tsc(u"polski"),.lang_ab=tsc(u"pl"),.lang_term=tsc(u"pol"),.lang_lib=tsc(u"pol")},.measurement={.measurement=1}};

inline constexpr u32lc_all u32lc_all_global{.identification={.title=tsc(U"Polish locale for Poland"),.source=tsc(U"RAP\t\t;\t\tfast_io"),.address=tsc(U"Sankt Jo/rgens Alle 8, DK-1615 Ko/benhavn V, Danmark\t\t;\t\thttps://github.com/expnkx/fast_io"),.contact=tsc(U"fast_io"),.email=tsc(U"bug-glibc-locales@gnu.org;euloanty@live.com"),.tel=tsc(U""),.fax=tsc(U""),.language=tsc(U"Polish"),.territory=tsc(U"Poland"),.revision=tsc(U"1.0"),.date=tsc(U"2000-06-29")},.monetary={.int_curr_symbol=tsc(U"PLN "),.currency_symbol=tsc(U"zł"),.mon_decimal_point=tsc(U","),.mon_thousands_sep=tsc(U" "),.mon_grouping={numeric_grouping_storage,1},.positive_sign=tsc(U""),.negative_sign=tsc(U"-"),.int_frac_digits=2,.frac_digits=2,.p_cs_precedes=0,.p_sep_by_space=1,.n_cs_precedes=0,.n_sep_by_space=1,.p_sign_posn=1,.n_sign_posn=1},.numeric={.decimal_point=tsc(U","),.thousands_sep=tsc(U" "),.grouping={numeric_grouping_storage,1}},.time={.abday={tsc(U"nie"),tsc(U"pon"),tsc(U"wto"),tsc(U"śro"),tsc(U"czw"),tsc(U"pią"),tsc(U"sob")},.day={tsc(U"niedziela"),tsc(U"poniedziałek"),tsc(U"wtorek"),tsc(U"środa"),tsc(U"czwartek"),tsc(U"piątek"),tsc(U"sobota")},.abmon={tsc(U"sty"),tsc(U"lut"),tsc(U"mar"),tsc(U"kwi"),tsc(U"maj"),tsc(U"cze"),tsc(U"lip"),tsc(U"sie"),tsc(U"wrz"),tsc(U"paź"),tsc(U"lis"),tsc(U"gru")},.mon={tsc(U"stycznia"),tsc(U"lutego"),tsc(U"marca"),tsc(U"kwietnia"),tsc(U"maja"),tsc(U"czerwca"),tsc(U"lipca"),tsc(U"sierpnia"),tsc(U"września"),tsc(U"października"),tsc(U"listopada"),tsc(U"grudnia")},.d_t_fmt=tsc(U"%a, %-d %b %Y, %T"),.d_fmt=tsc(U"%d.%m.%Y"),.t_fmt=tsc(U"%T"),.t_fmt_ampm=tsc(U""),.date_fmt=tsc(U"%a, %-d %b %Y, %T %Z"),.am_pm={tsc(U""),tsc(U"")},.week={7,19971130,4},.first_weekday=2},.messages={.yesexpr=tsc(U"^[+1TtYy]"),.noexpr=tsc(U"^[-0nN]"),.yesstr=tsc(U"tak"),.nostr=tsc(U"nie")},.paper={.width=210,.height=297},.telephone={.tel_int_fmt=tsc(U"+%c %a %l"),.int_select=tsc(U"00"),.int_prefix=tsc(U"48")},.name={.name_fmt=tsc(U"%d%t%g%t%m%t%f")},.address={.postal_fmt=tsc(U"%f%N%a%N%d%N%b%N%s %h %e %r%N%z %T%N%c%N"),.country_name=tsc(U"Polska"),.country_ab2=tsc(U"PL"),.country_ab3=tsc(U"POL"),.country_num=616,.country_car=tsc(U"PL"),.lang_name=tsc(U"polski"),.lang_ab=tsc(U"pl"),.lang_term=tsc(U"pol"),.lang_lib=tsc(U"pol")},.measurement={.measurement=1}};


}
}

#include"../main.h"