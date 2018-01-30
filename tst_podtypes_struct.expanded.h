

typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;

typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;

typedef long int __quad_t;
typedef unsigned long int __u_quad_t;

typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;

typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct {
  int __val[2];
} __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef int __key_t;

typedef int __clockid_t;

typedef void* __timer_t;

typedef long int __blksize_t;

typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;

typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;

typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;

typedef long int __fsword_t;

typedef long int __ssize_t;

typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;

typedef __off64_t __loff_t;
typedef __quad_t* __qaddr_t;
typedef char* __caddr_t;

typedef long int __intptr_t;

typedef unsigned int __socklen_t;

typedef int __sig_atomic_t;

typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;

typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;

typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;

typedef long int int_least64_t;

typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;

typedef unsigned long int uint_least64_t;
typedef signed char int_fast8_t;

typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;

typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef long int intptr_t;

typedef unsigned long int uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;

namespace std {
typedef long unsigned int size_t;
typedef long int ptrdiff_t;

typedef decltype(nullptr) nullptr_t;

}  // namespace std
namespace std {
inline namespace __cxx11 __attribute__((__abi_tag__("cxx11"))) {}
}  // namespace std
namespace __gnu_cxx {
inline namespace __cxx11 __attribute__((__abi_tag__("cxx11"))) {}
}  // namespace __gnu_cxx

namespace std {
typedef short unsigned int uint_least16_t;
typedef unsigned int uint_least32_t;
}  // namespace std

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Tp, _Tp __v>
  struct integral_constant {
    static constexpr _Tp value = __v;
    typedef _Tp value_type;
    typedef integral_constant<_Tp, __v> type;
    constexpr operator value_type() const { return value; }

    constexpr value_type operator()() const { return value; }
  };

  template <typename _Tp, _Tp __v>
  constexpr _Tp integral_constant<_Tp, __v>::value;

  typedef integral_constant<bool, true> true_type;

  typedef integral_constant<bool, false> false_type;

  template <bool __v>
  using __bool_constant = integral_constant<bool, __v>;
  template <bool, typename, typename>
  struct conditional;

  template <typename...>
  struct __or_;

  template <>
  struct __or_<> : public false_type {};

  template <typename _B1>
  struct __or_<_B1> : public _B1 {};

  template <typename _B1, typename _B2>
  struct __or_<_B1, _B2> : public conditional<_B1::value, _B1, _B2>::type {};

  template <typename _B1, typename _B2, typename _B3, typename... _Bn>
  struct __or_<_B1, _B2, _B3, _Bn...>
      : public conditional<_B1::value, _B1, __or_<_B2, _B3, _Bn...>>::type {};

  template <typename...>
  struct __and_;

  template <>
  struct __and_<> : public true_type {};

  template <typename _B1>
  struct __and_<_B1> : public _B1 {};

  template <typename _B1, typename _B2>
  struct __and_<_B1, _B2> : public conditional<_B1::value, _B2, _B1>::type {};

  template <typename _B1, typename _B2, typename _B3, typename... _Bn>
  struct __and_<_B1, _B2, _B3, _Bn...>
      : public conditional<_B1::value, __and_<_B2, _B3, _Bn...>, _B1>::type {};

  template <typename _Pp>
  struct __not_ : public integral_constant<bool, !_Pp::value> {};
  template <typename _Tp>
  struct __success_type {
    typedef _Tp type;
  };

  struct __failure_type {};

  template <typename>
  struct remove_cv;

  template <typename>
  struct __is_void_helper : public false_type {};

  template <>
  struct __is_void_helper<void> : public true_type {};

  template <typename _Tp>
  struct is_void
      : public __is_void_helper<typename remove_cv<_Tp>::type>::type {};

  template <typename>
  struct __is_integral_helper : public false_type {};

  template <>
  struct __is_integral_helper<bool> : public true_type {};

  template <>
  struct __is_integral_helper<char> : public true_type {};

  template <>
  struct __is_integral_helper<signed char> : public true_type {};

  template <>
  struct __is_integral_helper<unsigned char> : public true_type {};

  template <>
  struct __is_integral_helper<wchar_t> : public true_type {};

  template <>
  struct __is_integral_helper<char16_t> : public true_type {};

  template <>
  struct __is_integral_helper<char32_t> : public true_type {};

  template <>
  struct __is_integral_helper<short> : public true_type {};

  template <>
  struct __is_integral_helper<unsigned short> : public true_type {};

  template <>
  struct __is_integral_helper<int> : public true_type {};

  template <>
  struct __is_integral_helper<unsigned int> : public true_type {};

  template <>
  struct __is_integral_helper<long> : public true_type {};

  template <>
  struct __is_integral_helper<unsigned long> : public true_type {};

  template <>
  struct __is_integral_helper<long long> : public true_type {};

  template <>
  struct __is_integral_helper<unsigned long long> : public true_type {};

  template <>
  struct __is_integral_helper<__int128> : public true_type {};

  template <>
  struct __is_integral_helper<unsigned __int128> : public true_type {};
  template <typename _Tp>
  struct is_integral
      : public __is_integral_helper<typename remove_cv<_Tp>::type>::type {};

  template <typename>
  struct __is_floating_point_helper : public false_type {};

  template <>
  struct __is_floating_point_helper<float> : public true_type {};

  template <>
  struct __is_floating_point_helper<double> : public true_type {};

  template <>
  struct __is_floating_point_helper<long double> : public true_type {};

  template <>
  struct __is_floating_point_helper<__float128> : public true_type {};

  template <typename _Tp>
  struct is_floating_point
      : public __is_floating_point_helper<typename remove_cv<_Tp>::type>::type {
  };

  template <typename>
  struct is_array : public false_type {};

  template <typename _Tp, std::size_t _Size>
  struct is_array<_Tp[_Size]> : public true_type {};

  template <typename _Tp>
  struct is_array<_Tp[]> : public true_type {};

  template <typename>
  struct __is_pointer_helper : public false_type {};

  template <typename _Tp>
  struct __is_pointer_helper<_Tp*> : public true_type {};

  template <typename _Tp>
  struct is_pointer
      : public __is_pointer_helper<typename remove_cv<_Tp>::type>::type {};

  template <typename>
  struct is_lvalue_reference : public false_type {};

  template <typename _Tp>
  struct is_lvalue_reference<_Tp&> : public true_type {};

  template <typename>
  struct is_rvalue_reference : public false_type {};

  template <typename _Tp>
  struct is_rvalue_reference<_Tp&&> : public true_type {};

  template <typename>
  struct is_function;

  template <typename>
  struct __is_member_object_pointer_helper : public false_type {};

  template <typename _Tp, typename _Cp>
  struct __is_member_object_pointer_helper<_Tp _Cp::*>
      : public integral_constant<bool, !is_function<_Tp>::value> {};

  template <typename _Tp>
  struct is_member_object_pointer : public __is_member_object_pointer_helper<
                                        typename remove_cv<_Tp>::type>::type {};

  template <typename>
  struct __is_member_function_pointer_helper : public false_type {};

  template <typename _Tp, typename _Cp>
  struct __is_member_function_pointer_helper<_Tp _Cp::*>
      : public integral_constant<bool, is_function<_Tp>::value> {};

  template <typename _Tp>
  struct is_member_function_pointer
      : public __is_member_function_pointer_helper<
            typename remove_cv<_Tp>::type>::type {};

  template <typename _Tp>
  struct is_enum : public integral_constant<bool, __is_enum(_Tp)> {};

  template <typename _Tp>
  struct is_union : public integral_constant<bool, __is_union(_Tp)> {};

  template <typename _Tp>
  struct is_class : public integral_constant<bool, __is_class(_Tp)> {};

  template <typename>
  struct is_function : public false_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes...)> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes...)&> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes...) &&> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes......)> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes......)&> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes......) &&> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes...) const> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes...) const &> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes...) const &&> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes......) const> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes......) const &> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes......) const &&> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes...) volatile> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes...) volatile&> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes...) volatile&&> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes......) volatile> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes......) volatile&> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes......) volatile&&> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes...) const volatile> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes...) const volatile&> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes...) const volatile&&> : public true_type {};

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes......) const volatile> : public true_type {
  };

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes......) const volatile&> : public true_type {
  };

  template <typename _Res, typename... _ArgTypes>
  struct is_function<_Res(_ArgTypes......) const volatile&&>
      : public true_type {};

  template <typename>
  struct __is_null_pointer_helper : public false_type {};

  template <>
  struct __is_null_pointer_helper<std::nullptr_t> : public true_type {};

  template <typename _Tp>
  struct is_null_pointer
      : public __is_null_pointer_helper<typename remove_cv<_Tp>::type>::type {};

  template <typename _Tp>
  struct __is_nullptr_t : public is_null_pointer<_Tp> {};

  template <typename _Tp>
  struct is_reference
      : public __or_<is_lvalue_reference<_Tp>, is_rvalue_reference<_Tp>>::type {
  };

  template <typename _Tp>
  struct is_arithmetic
      : public __or_<is_integral<_Tp>, is_floating_point<_Tp>>::type {};

  template <typename _Tp>
  struct is_fundamental : public __or_<is_arithmetic<_Tp>, is_void<_Tp>,
                                       is_null_pointer<_Tp>>::type {};

  template <typename _Tp>
  struct is_object
      : public __not_<
            __or_<is_function<_Tp>, is_reference<_Tp>, is_void<_Tp>>>::type {};

  template <typename>
  struct is_member_pointer;

  template <typename _Tp>
  struct is_scalar
      : public __or_<is_arithmetic<_Tp>, is_enum<_Tp>, is_pointer<_Tp>,
                     is_member_pointer<_Tp>, is_null_pointer<_Tp>>::type {};

  template <typename _Tp>
  struct is_compound
      : public integral_constant<bool, !is_fundamental<_Tp>::value> {};

  template <typename _Tp>
  struct __is_member_pointer_helper : public false_type {};

  template <typename _Tp, typename _Cp>
  struct __is_member_pointer_helper<_Tp _Cp::*> : public true_type {};

  template <typename _Tp>
  struct is_member_pointer
      : public __is_member_pointer_helper<typename remove_cv<_Tp>::type>::type {
  };

  template <typename _Tp>
  struct __is_referenceable
      : public __or_<is_object<_Tp>, is_reference<_Tp>>::type {};

  template <typename _Res, typename... _Args>
  struct __is_referenceable<_Res(_Args...)> : public true_type {};

  template <typename _Res, typename... _Args>
  struct __is_referenceable<_Res(_Args......)> : public true_type {};

  template <typename>
  struct is_const : public false_type {};

  template <typename _Tp>
  struct is_const<_Tp const> : public true_type {};

  template <typename>
  struct is_volatile : public false_type {};

  template <typename _Tp>
  struct is_volatile<_Tp volatile> : public true_type {};

  template <typename _Tp>
  struct is_trivial : public integral_constant<bool, __is_trivial(_Tp)> {};

  template <typename _Tp>
  struct is_trivially_copyable
      : public integral_constant<bool, __is_trivially_copyable(_Tp)> {};

  template <typename _Tp>
  struct is_standard_layout
      : public integral_constant<bool, __is_standard_layout(_Tp)> {};

  template <typename _Tp>
  struct is_pod : public integral_constant<bool, __is_pod(_Tp)> {};

  template <typename _Tp>
  struct is_literal_type
      : public integral_constant<bool, __is_literal_type(_Tp)> {};

  template <typename _Tp>
  struct is_empty : public integral_constant<bool, __is_empty(_Tp)> {};

  template <typename _Tp>
  struct is_polymorphic
      : public integral_constant<bool, __is_polymorphic(_Tp)> {};

  template <typename _Tp>
  struct is_final : public integral_constant<bool, __is_final(_Tp)> {};

  template <typename _Tp>
  struct is_abstract : public integral_constant<bool, __is_abstract(_Tp)> {};

  template <typename _Tp, bool = is_arithmetic<_Tp>::value>
  struct __is_signed_helper : public false_type {};

  template <typename _Tp>
  struct __is_signed_helper<_Tp, true>
      : public integral_constant<bool, _Tp(-1) < _Tp(0)> {};

  template <typename _Tp>
  struct is_signed : public __is_signed_helper<_Tp>::type {};

  template <typename _Tp>
  struct is_unsigned
      : public __and_<is_arithmetic<_Tp>, __not_<is_signed<_Tp>>> {};

  template <typename>
  struct add_rvalue_reference;

  template <typename _Tp>
  typename add_rvalue_reference<_Tp>::type declval() noexcept;

  template <typename, unsigned = 0>
  struct extent;

  template <typename>
  struct remove_all_extents;

  template <typename _Tp>
  struct __is_array_known_bounds
      : public integral_constant<bool, (extent<_Tp>::value > 0)> {};

  template <typename _Tp>
  struct __is_array_unknown_bounds
      : public __and_<is_array<_Tp>, __not_<extent<_Tp>>> {};

  struct __do_is_destructible_impl {
    template <typename _Tp, typename = decltype(declval<_Tp&>().~_Tp())>
    static true_type __test(int);

    template <typename>
    static false_type __test(...);
  };

  template <typename _Tp>
  struct __is_destructible_impl : public __do_is_destructible_impl {
    typedef decltype(__test<_Tp>(0)) type;
  };

  template <typename _Tp,
            bool = __or_<is_void<_Tp>, __is_array_unknown_bounds<_Tp>,
                         is_function<_Tp>>::value,
            bool = __or_<is_reference<_Tp>, is_scalar<_Tp>>::value>
  struct __is_destructible_safe;

  template <typename _Tp>
  struct __is_destructible_safe<_Tp, false, false>
      : public __is_destructible_impl<
            typename remove_all_extents<_Tp>::type>::type {};

  template <typename _Tp>
  struct __is_destructible_safe<_Tp, true, false> : public false_type {};

  template <typename _Tp>
  struct __is_destructible_safe<_Tp, false, true> : public true_type {};

  template <typename _Tp>
  struct is_destructible : public __is_destructible_safe<_Tp>::type {};

  struct __do_is_nt_destructible_impl {
    template <typename _Tp>
    static integral_constant<bool, noexcept(declval<_Tp&>().~_Tp())> __test(
        int);

    template <typename>
    static false_type __test(...);
  };

  template <typename _Tp>
  struct __is_nt_destructible_impl : public __do_is_nt_destructible_impl {
    typedef decltype(__test<_Tp>(0)) type;
  };

  template <typename _Tp,
            bool = __or_<is_void<_Tp>, __is_array_unknown_bounds<_Tp>,
                         is_function<_Tp>>::value,
            bool = __or_<is_reference<_Tp>, is_scalar<_Tp>>::value>
  struct __is_nt_destructible_safe;

  template <typename _Tp>
  struct __is_nt_destructible_safe<_Tp, false, false>
      : public __is_nt_destructible_impl<
            typename remove_all_extents<_Tp>::type>::type {};

  template <typename _Tp>
  struct __is_nt_destructible_safe<_Tp, true, false> : public false_type {};

  template <typename _Tp>
  struct __is_nt_destructible_safe<_Tp, false, true> : public true_type {};

  template <typename _Tp>
  struct is_nothrow_destructible : public __is_nt_destructible_safe<_Tp>::type {
  };

  struct __do_is_default_constructible_impl {
    template <typename _Tp, typename = decltype(_Tp())>
    static true_type __test(int);

    template <typename>
    static false_type __test(...);
  };

  template <typename _Tp>
  struct __is_default_constructible_impl
      : public __do_is_default_constructible_impl {
    typedef decltype(__test<_Tp>(0)) type;
  };

  template <typename _Tp>
  struct __is_default_constructible_atom
      : public __and_<__not_<is_void<_Tp>>,
                      __is_default_constructible_impl<_Tp>> {};

  template <typename _Tp, bool = is_array<_Tp>::value>
  struct __is_default_constructible_safe;

  template <typename _Tp>
  struct __is_default_constructible_safe<_Tp, true>
      : public __and_<__is_array_known_bounds<_Tp>,
                      __is_default_constructible_atom<
                          typename remove_all_extents<_Tp>::type>> {};

  template <typename _Tp>
  struct __is_default_constructible_safe<_Tp, false>
      : public __is_default_constructible_atom<_Tp>::type {};

  template <typename _Tp>
  struct is_default_constructible
      : public __is_default_constructible_safe<_Tp>::type {};
  struct __do_is_static_castable_impl {
    template <typename _From,
              typename _To,
              typename = decltype(static_cast<_To>(declval<_From>()))>
    static true_type __test(int);

    template <typename, typename>
    static false_type __test(...);
  };

  template <typename _From, typename _To>
  struct __is_static_castable_impl : public __do_is_static_castable_impl {
    typedef decltype(__test<_From, _To>(0)) type;
  };

  template <typename _From, typename _To>
  struct __is_static_castable_safe
      : public __is_static_castable_impl<_From, _To>::type {};

  template <typename _From, typename _To>
  struct __is_static_castable
      : public integral_constant<
            bool, (__is_static_castable_safe<_From, _To>::value)> {};

  struct __do_is_direct_constructible_impl {
    template <typename _Tp,
              typename _Arg,
              typename = decltype(::new _Tp(declval<_Arg>()))>
    static true_type __test(int);

    template <typename, typename>
    static false_type __test(...);
  };

  template <typename _Tp, typename _Arg>
  struct __is_direct_constructible_impl
      : public __do_is_direct_constructible_impl {
    typedef decltype(__test<_Tp, _Arg>(0)) type;
  };

  template <typename _Tp, typename _Arg>
  struct __is_direct_constructible_new_safe
      : public __and_<is_destructible<_Tp>,
                      __is_direct_constructible_impl<_Tp, _Arg>> {};

  template <typename, typename>
  struct is_same;

  template <typename, typename>
  struct is_base_of;

  template <typename>
  struct remove_reference;

  template <typename _From, typename _To,
            bool = __not_<__or_<is_void<_From>, is_function<_From>>>::value>
  struct __is_base_to_derived_ref;

  template <typename _Tp, typename... _Args>
  struct is_constructible;

  template <typename _From, typename _To>
  struct __is_base_to_derived_ref<_From, _To, true> {
    typedef typename remove_cv<typename remove_reference<_From>::type>::type
        __src_t;
    typedef
        typename remove_cv<typename remove_reference<_To>::type>::type __dst_t;
    typedef __and_<__not_<is_same<__src_t, __dst_t>>,
                   is_base_of<__src_t, __dst_t>,
                   __not_<is_constructible<__dst_t, _From>>>
        type;
    static constexpr bool value = type::value;
  };

  template <typename _From, typename _To>
  struct __is_base_to_derived_ref<_From, _To, false> : public false_type {};

  template <typename _From, typename _To,
            bool = __and_<is_lvalue_reference<_From>,
                          is_rvalue_reference<_To>>::value>
  struct __is_lvalue_to_rvalue_ref;

  template <typename _From, typename _To>
  struct __is_lvalue_to_rvalue_ref<_From, _To, true> {
    typedef typename remove_cv<typename remove_reference<_From>::type>::type
        __src_t;
    typedef
        typename remove_cv<typename remove_reference<_To>::type>::type __dst_t;
    typedef __and_<
        __not_<is_function<__src_t>>,
        __or_<is_same<__src_t, __dst_t>, is_base_of<__dst_t, __src_t>>>
        type;
    static constexpr bool value = type::value;
  };

  template <typename _From, typename _To>
  struct __is_lvalue_to_rvalue_ref<_From, _To, false> : public false_type {};

  template <typename _Tp, typename _Arg>
  struct __is_direct_constructible_ref_cast
      : public __and_<__is_static_castable<_Arg, _Tp>,
                      __not_<__or_<__is_base_to_derived_ref<_Arg, _Tp>,
                                   __is_lvalue_to_rvalue_ref<_Arg, _Tp>>>> {};

  template <typename _Tp, typename _Arg>
  struct __is_direct_constructible_new
      : public conditional<
            is_reference<_Tp>::value,
            __is_direct_constructible_ref_cast<_Tp, _Arg>,
            __is_direct_constructible_new_safe<_Tp, _Arg>>::type {};

  template <typename _Tp, typename _Arg>
  struct __is_direct_constructible
      : public __is_direct_constructible_new<_Tp, _Arg>::type {};

  struct __do_is_nary_constructible_impl {
    template <typename _Tp,
              typename... _Args,
              typename = decltype(_Tp(declval<_Args>()...))>
    static true_type __test(int);

    template <typename, typename...>
    static false_type __test(...);
  };

  template <typename _Tp, typename... _Args>
  struct __is_nary_constructible_impl : public __do_is_nary_constructible_impl {
    typedef decltype(__test<_Tp, _Args...>(0)) type;
  };

  template <typename _Tp, typename... _Args>
  struct __is_nary_constructible
      : public __is_nary_constructible_impl<_Tp, _Args...>::type {
    static_assert(sizeof...(_Args) > 1, "Only useful for > 1 arguments");
  };

  template <typename _Tp, typename... _Args>
  struct __is_constructible_impl
      : public __is_nary_constructible<_Tp, _Args...> {};

  template <typename _Tp, typename _Arg>
  struct __is_constructible_impl<_Tp, _Arg>
      : public __is_direct_constructible<_Tp, _Arg> {};

  template <typename _Tp>
  struct __is_constructible_impl<_Tp> : public is_default_constructible<_Tp> {};

  template <typename _Tp, typename... _Args>
  struct is_constructible
      : public __is_constructible_impl<_Tp, _Args...>::type {};

  template <typename _Tp, bool = __is_referenceable<_Tp>::value>
  struct __is_copy_constructible_impl;

  template <typename _Tp>
  struct __is_copy_constructible_impl<_Tp, false> : public false_type {};

  template <typename _Tp>
  struct __is_copy_constructible_impl<_Tp, true>
      : public is_constructible<_Tp, const _Tp&> {};

  template <typename _Tp>
  struct is_copy_constructible : public __is_copy_constructible_impl<_Tp> {};

  template <typename _Tp, bool = __is_referenceable<_Tp>::value>
  struct __is_move_constructible_impl;

  template <typename _Tp>
  struct __is_move_constructible_impl<_Tp, false> : public false_type {};

  template <typename _Tp>
  struct __is_move_constructible_impl<_Tp, true>
      : public is_constructible<_Tp, _Tp&&> {};

  template <typename _Tp>
  struct is_move_constructible : public __is_move_constructible_impl<_Tp> {};

  template <typename _Tp>
  struct __is_nt_default_constructible_atom
      : public integral_constant<bool, noexcept(_Tp())> {};

  template <typename _Tp, bool = is_array<_Tp>::value>
  struct __is_nt_default_constructible_impl;

  template <typename _Tp>
  struct __is_nt_default_constructible_impl<_Tp, true>
      : public __and_<__is_array_known_bounds<_Tp>,
                      __is_nt_default_constructible_atom<
                          typename remove_all_extents<_Tp>::type>> {};

  template <typename _Tp>
  struct __is_nt_default_constructible_impl<_Tp, false>
      : public __is_nt_default_constructible_atom<_Tp> {};

  template <typename _Tp>
  struct is_nothrow_default_constructible
      : public __and_<is_default_constructible<_Tp>,
                      __is_nt_default_constructible_impl<_Tp>> {};

  template <typename _Tp, typename... _Args>
  struct __is_nt_constructible_impl
      : public integral_constant<bool, noexcept(_Tp(declval<_Args>()...))> {};

  template <typename _Tp, typename _Arg>
  struct __is_nt_constructible_impl<_Tp, _Arg>
      : public integral_constant<bool,
                                 noexcept(static_cast<_Tp>(declval<_Arg>()))> {
  };

  template <typename _Tp>
  struct __is_nt_constructible_impl<_Tp>
      : public is_nothrow_default_constructible<_Tp> {};

  template <typename _Tp, typename... _Args>
  struct is_nothrow_constructible
      : public __and_<is_constructible<_Tp, _Args...>,
                      __is_nt_constructible_impl<_Tp, _Args...>> {};

  template <typename _Tp, bool = __is_referenceable<_Tp>::value>
  struct __is_nothrow_copy_constructible_impl;

  template <typename _Tp>
  struct __is_nothrow_copy_constructible_impl<_Tp, false> : public false_type {
  };

  template <typename _Tp>
  struct __is_nothrow_copy_constructible_impl<_Tp, true>
      : public is_nothrow_constructible<_Tp, const _Tp&> {};

  template <typename _Tp>
  struct is_nothrow_copy_constructible
      : public __is_nothrow_copy_constructible_impl<_Tp> {};

  template <typename _Tp, bool = __is_referenceable<_Tp>::value>
  struct __is_nothrow_move_constructible_impl;

  template <typename _Tp>
  struct __is_nothrow_move_constructible_impl<_Tp, false> : public false_type {
  };

  template <typename _Tp>
  struct __is_nothrow_move_constructible_impl<_Tp, true>
      : public is_nothrow_constructible<_Tp, _Tp&&> {};

  template <typename _Tp>
  struct is_nothrow_move_constructible
      : public __is_nothrow_move_constructible_impl<_Tp> {};

  template <typename _Tp, typename _Up>
  class __is_assignable_helper {
    template <typename _Tp1,
              typename _Up1,
              typename = decltype(declval<_Tp1>() = declval<_Up1>())>
    static true_type __test(int);

    template <typename, typename>
    static false_type __test(...);

   public:
    typedef decltype(__test<_Tp, _Up>(0)) type;
  };

  template <typename _Tp, typename _Up>
  struct is_assignable : public __is_assignable_helper<_Tp, _Up>::type {};

  template <typename _Tp, bool = __is_referenceable<_Tp>::value>
  struct __is_copy_assignable_impl;

  template <typename _Tp>
  struct __is_copy_assignable_impl<_Tp, false> : public false_type {};

  template <typename _Tp>
  struct __is_copy_assignable_impl<_Tp, true>
      : public is_assignable<_Tp&, const _Tp&> {};

  template <typename _Tp>
  struct is_copy_assignable : public __is_copy_assignable_impl<_Tp> {};

  template <typename _Tp, bool = __is_referenceable<_Tp>::value>
  struct __is_move_assignable_impl;

  template <typename _Tp>
  struct __is_move_assignable_impl<_Tp, false> : public false_type {};

  template <typename _Tp>
  struct __is_move_assignable_impl<_Tp, true>
      : public is_assignable<_Tp&, _Tp&&> {};

  template <typename _Tp>
  struct is_move_assignable : public __is_move_assignable_impl<_Tp> {};

  template <typename _Tp, typename _Up>
  struct __is_nt_assignable_impl
      : public integral_constant<bool,
                                 noexcept(declval<_Tp>() = declval<_Up>())> {};

  template <typename _Tp, typename _Up>
  struct is_nothrow_assignable
      : public __and_<is_assignable<_Tp, _Up>,
                      __is_nt_assignable_impl<_Tp, _Up>> {};

  template <typename _Tp, bool = __is_referenceable<_Tp>::value>
  struct __is_nt_copy_assignable_impl;

  template <typename _Tp>
  struct __is_nt_copy_assignable_impl<_Tp, false> : public false_type {};

  template <typename _Tp>
  struct __is_nt_copy_assignable_impl<_Tp, true>
      : public is_nothrow_assignable<_Tp&, const _Tp&> {};

  template <typename _Tp>
  struct is_nothrow_copy_assignable : public __is_nt_copy_assignable_impl<_Tp> {
  };

  template <typename _Tp, bool = __is_referenceable<_Tp>::value>
  struct __is_nt_move_assignable_impl;

  template <typename _Tp>
  struct __is_nt_move_assignable_impl<_Tp, false> : public false_type {};

  template <typename _Tp>
  struct __is_nt_move_assignable_impl<_Tp, true>
      : public is_nothrow_assignable<_Tp&, _Tp&&> {};

  template <typename _Tp>
  struct is_nothrow_move_assignable : public __is_nt_move_assignable_impl<_Tp> {
  };

  template <typename _Tp, typename... _Args>
  struct is_trivially_constructible
      : public __and_<is_constructible<_Tp, _Args...>,
                      integral_constant<bool, __is_trivially_constructible(
                                                  _Tp, _Args...)>> {};

  template <typename _Tp>
  struct is_trivially_default_constructible
      : public is_trivially_constructible<_Tp>::type {};

  struct __do_is_implicitly_default_constructible_impl {
    template <typename _Tp>
    static void __helper(const _Tp&);

    template <typename _Tp>
    static true_type __test(const _Tp&,
                            decltype(__helper<const _Tp&>({})) * = 0);

    static false_type __test(...);
  };

  template <typename _Tp>
  struct __is_implicitly_default_constructible_impl
      : public __do_is_implicitly_default_constructible_impl {
    typedef decltype(__test(declval<_Tp>())) type;
  };

  template <typename _Tp>
  struct __is_implicitly_default_constructible_safe
      : public __is_implicitly_default_constructible_impl<_Tp>::type {};

  template <typename _Tp>
  struct __is_implicitly_default_constructible
      : public __and_<is_default_constructible<_Tp>,
                      __is_implicitly_default_constructible_safe<_Tp>> {};

  template <typename _Tp>
  struct is_trivially_copy_constructible
      : public __and_<is_copy_constructible<_Tp>,
                      integral_constant<bool, __is_trivially_constructible(
                                                  _Tp, const _Tp&)>> {};

  template <typename _Tp>
  struct is_trivially_move_constructible
      : public __and_<is_move_constructible<_Tp>,
                      integral_constant<bool, __is_trivially_constructible(
                                                  _Tp, _Tp &&)>> {};

  template <typename _Tp, typename _Up>
  struct is_trivially_assignable
      : public __and_<
            is_assignable<_Tp, _Up>,
            integral_constant<bool, __is_trivially_assignable(_Tp, _Up)>> {};

  template <typename _Tp>
  struct is_trivially_copy_assignable
      : public __and_<is_copy_assignable<_Tp>,
                      integral_constant<bool, __is_trivially_assignable(
                                                  _Tp&, const _Tp&)>> {};

  template <typename _Tp>
  struct is_trivially_move_assignable
      : public __and_<
            is_move_assignable<_Tp>,
            integral_constant<bool, __is_trivially_assignable(_Tp&, _Tp &&)>> {
  };

  template <typename _Tp>
  struct is_trivially_destructible
      : public __and_<is_destructible<_Tp>,
                      integral_constant<bool, __has_trivial_destructor(_Tp)>> {
  };

  template <typename _Tp>
  struct has_virtual_destructor
      : public integral_constant<bool, __has_virtual_destructor(_Tp)> {};

  template <typename _Tp>
  struct alignment_of
      : public integral_constant<std::size_t, __alignof__(_Tp)> {};

  template <typename>
  struct rank : public integral_constant<std::size_t, 0> {};

  template <typename _Tp, std::size_t _Size>
  struct rank<_Tp[_Size]>
      : public integral_constant<std::size_t, 1 + rank<_Tp>::value> {};

  template <typename _Tp>
  struct rank<_Tp[]>
      : public integral_constant<std::size_t, 1 + rank<_Tp>::value> {};

  template <typename, unsigned _Uint>
  struct extent : public integral_constant<std::size_t, 0> {};

  template <typename _Tp, unsigned _Uint, std::size_t _Size>
  struct extent<_Tp[_Size], _Uint>
      : public integral_constant<
            std::size_t, _Uint == 0 ? _Size : extent<_Tp, _Uint - 1>::value> {};

  template <typename _Tp, unsigned _Uint>
  struct extent<_Tp[], _Uint>
      : public integral_constant<
            std::size_t, _Uint == 0 ? 0 : extent<_Tp, _Uint - 1>::value> {};

  template <typename, typename>
  struct is_same : public false_type {};

  template <typename _Tp>
  struct is_same<_Tp, _Tp> : public true_type {};

  template <typename _Base, typename _Derived>
  struct is_base_of
      : public integral_constant<bool, __is_base_of(_Base, _Derived)> {};

  template <typename _From, typename _To,
            bool =
                __or_<is_void<_From>, is_function<_To>, is_array<_To>>::value>
  struct __is_convertible_helper {
    typedef typename is_void<_To>::type type;
  };

  template <typename _From, typename _To>
  class __is_convertible_helper<_From, _To, false> {
    template <typename _To1>
    static void __test_aux(_To1);

    template <typename _From1,
              typename _To1,
              typename = decltype(__test_aux<_To1>(std::declval<_From1>()))>
    static true_type __test(int);

    template <typename, typename>
    static false_type __test(...);

   public:
    typedef decltype(__test<_From, _To>(0)) type;
  };

  template <typename _From, typename _To>
  struct is_convertible : public __is_convertible_helper<_From, _To>::type {};

  template <typename _Tp>
  struct remove_const {
    typedef _Tp type;
  };

  template <typename _Tp>
  struct remove_const<_Tp const> {
    typedef _Tp type;
  };

  template <typename _Tp>
  struct remove_volatile {
    typedef _Tp type;
  };

  template <typename _Tp>
  struct remove_volatile<_Tp volatile> {
    typedef _Tp type;
  };

  template <typename _Tp>
  struct remove_cv {
    typedef
        typename remove_const<typename remove_volatile<_Tp>::type>::type type;
  };

  template <typename _Tp>
  struct add_const {
    typedef _Tp const type;
  };

  template <typename _Tp>
  struct add_volatile {
    typedef _Tp volatile type;
  };

  template <typename _Tp>
  struct add_cv {
    typedef typename add_const<typename add_volatile<_Tp>::type>::type type;
  };

  template <typename _Tp>
  using remove_const_t = typename remove_const<_Tp>::type;

  template <typename _Tp>
  using remove_volatile_t = typename remove_volatile<_Tp>::type;

  template <typename _Tp>
  using remove_cv_t = typename remove_cv<_Tp>::type;

  template <typename _Tp>
  using add_const_t = typename add_const<_Tp>::type;

  template <typename _Tp>
  using add_volatile_t = typename add_volatile<_Tp>::type;

  template <typename _Tp>
  using add_cv_t = typename add_cv<_Tp>::type;

  template <typename _Tp>
  struct remove_reference {
    typedef _Tp type;
  };

  template <typename _Tp>
  struct remove_reference<_Tp&> {
    typedef _Tp type;
  };

  template <typename _Tp>
  struct remove_reference<_Tp&&> {
    typedef _Tp type;
  };

  template <typename _Tp, bool = __is_referenceable<_Tp>::value>
  struct __add_lvalue_reference_helper {
    typedef _Tp type;
  };

  template <typename _Tp>
  struct __add_lvalue_reference_helper<_Tp, true> {
    typedef _Tp& type;
  };

  template <typename _Tp>
  struct add_lvalue_reference : public __add_lvalue_reference_helper<_Tp> {};

  template <typename _Tp, bool = __is_referenceable<_Tp>::value>
  struct __add_rvalue_reference_helper {
    typedef _Tp type;
  };

  template <typename _Tp>
  struct __add_rvalue_reference_helper<_Tp, true> {
    typedef _Tp&& type;
  };

  template <typename _Tp>
  struct add_rvalue_reference : public __add_rvalue_reference_helper<_Tp> {};

  template <typename _Tp>
  using remove_reference_t = typename remove_reference<_Tp>::type;

  template <typename _Tp>
  using add_lvalue_reference_t = typename add_lvalue_reference<_Tp>::type;

  template <typename _Tp>
  using add_rvalue_reference_t = typename add_rvalue_reference<_Tp>::type;

  template <typename _Unqualified, bool _IsConst, bool _IsVol>
  struct __cv_selector;

  template <typename _Unqualified>
  struct __cv_selector<_Unqualified, false, false> {
    typedef _Unqualified __type;
  };

  template <typename _Unqualified>
  struct __cv_selector<_Unqualified, false, true> {
    typedef volatile _Unqualified __type;
  };

  template <typename _Unqualified>
  struct __cv_selector<_Unqualified, true, false> {
    typedef const _Unqualified __type;
  };

  template <typename _Unqualified>
  struct __cv_selector<_Unqualified, true, true> {
    typedef const volatile _Unqualified __type;
  };

  template <typename _Qualified, typename _Unqualified,
            bool _IsConst = is_const<_Qualified>::value,
            bool _IsVol = is_volatile<_Qualified>::value>
  class __match_cv_qualifiers {
    typedef __cv_selector<_Unqualified, _IsConst, _IsVol> __match;

   public:
    typedef typename __match::__type __type;
  };

  template <typename _Tp>
  struct __make_unsigned {
    typedef _Tp __type;
  };

  template <>
  struct __make_unsigned<char> {
    typedef unsigned char __type;
  };

  template <>
  struct __make_unsigned<signed char> {
    typedef unsigned char __type;
  };

  template <>
  struct __make_unsigned<short> {
    typedef unsigned short __type;
  };

  template <>
  struct __make_unsigned<int> {
    typedef unsigned int __type;
  };

  template <>
  struct __make_unsigned<long> {
    typedef unsigned long __type;
  };

  template <>
  struct __make_unsigned<long long> {
    typedef unsigned long long __type;
  };

  template <>
  struct __make_unsigned<wchar_t> : __make_unsigned<int> {};

  template <>
  struct __make_unsigned<__int128> {
    typedef unsigned __int128 __type;
  };
  template <typename _Tp, bool _IsInt = is_integral<_Tp>::value,
            bool _IsEnum = is_enum<_Tp>::value>
  class __make_unsigned_selector;

  template <typename _Tp>
  class __make_unsigned_selector<_Tp, true, false> {
    typedef __make_unsigned<typename remove_cv<_Tp>::type> __unsignedt;
    typedef typename __unsignedt::__type __unsigned_type;
    typedef __match_cv_qualifiers<_Tp, __unsigned_type> __cv_unsigned;

   public:
    typedef typename __cv_unsigned::__type __type;
  };

  template <typename _Tp>
  class __make_unsigned_selector<_Tp, false, true> {
    typedef unsigned char __smallest;
    static const bool __b0 = sizeof(_Tp) <= sizeof(__smallest);
    static const bool __b1 = sizeof(_Tp) <= sizeof(unsigned short);
    static const bool __b2 = sizeof(_Tp) <= sizeof(unsigned int);
    static const bool __b3 = sizeof(_Tp) <= sizeof(unsigned long);
    typedef conditional<__b3, unsigned long, unsigned long long> __cond3;
    typedef typename __cond3::type __cond3_type;
    typedef conditional<__b2, unsigned int, __cond3_type> __cond2;
    typedef typename __cond2::type __cond2_type;
    typedef conditional<__b1, unsigned short, __cond2_type> __cond1;
    typedef typename __cond1::type __cond1_type;

    typedef typename conditional<__b0, __smallest, __cond1_type>::type
        __unsigned_type;
    typedef __match_cv_qualifiers<_Tp, __unsigned_type> __cv_unsigned;

   public:
    typedef typename __cv_unsigned::__type __type;
  };

  template <typename _Tp>
  struct make_unsigned {
    typedef typename __make_unsigned_selector<_Tp>::__type type;
  };

  template <>
  struct make_unsigned<bool>;

  template <typename _Tp>
  struct __make_signed {
    typedef _Tp __type;
  };

  template <>
  struct __make_signed<char> {
    typedef signed char __type;
  };

  template <>
  struct __make_signed<unsigned char> {
    typedef signed char __type;
  };

  template <>
  struct __make_signed<unsigned short> {
    typedef signed short __type;
  };

  template <>
  struct __make_signed<unsigned int> {
    typedef signed int __type;
  };

  template <>
  struct __make_signed<unsigned long> {
    typedef signed long __type;
  };

  template <>
  struct __make_signed<unsigned long long> {
    typedef signed long long __type;
  };
  template <>
  struct __make_signed<char16_t> : __make_signed<uint_least16_t> {};
  template <>
  struct __make_signed<char32_t> : __make_signed<uint_least32_t> {};

  template <>
  struct __make_signed<unsigned __int128> {
    typedef __int128 __type;
  };
  template <typename _Tp, bool _IsInt = is_integral<_Tp>::value,
            bool _IsEnum = is_enum<_Tp>::value>
  class __make_signed_selector;

  template <typename _Tp>
  class __make_signed_selector<_Tp, true, false> {
    typedef __make_signed<typename remove_cv<_Tp>::type> __signedt;
    typedef typename __signedt::__type __signed_type;
    typedef __match_cv_qualifiers<_Tp, __signed_type> __cv_signed;

   public:
    typedef typename __cv_signed::__type __type;
  };

  template <typename _Tp>
  class __make_signed_selector<_Tp, false, true> {
    typedef typename __make_unsigned_selector<_Tp>::__type __unsigned_type;

   public:
    typedef typename __make_signed_selector<__unsigned_type>::__type __type;
  };

  template <typename _Tp>
  struct make_signed {
    typedef typename __make_signed_selector<_Tp>::__type type;
  };

  template <>
  struct make_signed<bool>;

  template <typename _Tp>
  using make_signed_t = typename make_signed<_Tp>::type;

  template <typename _Tp>
  using make_unsigned_t = typename make_unsigned<_Tp>::type;

  template <typename _Tp>
  struct remove_extent {
    typedef _Tp type;
  };

  template <typename _Tp, std::size_t _Size>
  struct remove_extent<_Tp[_Size]> {
    typedef _Tp type;
  };

  template <typename _Tp>
  struct remove_extent<_Tp[]> {
    typedef _Tp type;
  };

  template <typename _Tp>
  struct remove_all_extents {
    typedef _Tp type;
  };

  template <typename _Tp, std::size_t _Size>
  struct remove_all_extents<_Tp[_Size]> {
    typedef typename remove_all_extents<_Tp>::type type;
  };

  template <typename _Tp>
  struct remove_all_extents<_Tp[]> {
    typedef typename remove_all_extents<_Tp>::type type;
  };

  template <typename _Tp>
  using remove_extent_t = typename remove_extent<_Tp>::type;

  template <typename _Tp>
  using remove_all_extents_t = typename remove_all_extents<_Tp>::type;

  template <typename _Tp, typename>
  struct __remove_pointer_helper {
    typedef _Tp type;
  };

  template <typename _Tp, typename _Up>
  struct __remove_pointer_helper<_Tp, _Up*> {
    typedef _Up type;
  };

  template <typename _Tp>
  struct remove_pointer
      : public __remove_pointer_helper<_Tp, typename remove_cv<_Tp>::type> {};

  template <typename _Tp,
            bool = __or_<__is_referenceable<_Tp>, is_void<_Tp>>::value>
  struct __add_pointer_helper {
    typedef _Tp type;
  };

  template <typename _Tp>
  struct __add_pointer_helper<_Tp, true> {
    typedef typename remove_reference<_Tp>::type* type;
  };

  template <typename _Tp>
  struct add_pointer : public __add_pointer_helper<_Tp> {};

  template <typename _Tp>
  using remove_pointer_t = typename remove_pointer<_Tp>::type;

  template <typename _Tp>
  using add_pointer_t = typename add_pointer<_Tp>::type;

  template <std::size_t _Len>
  struct __aligned_storage_msa {
    union __type {
      unsigned char __data[_Len];
      struct __attribute__((__aligned__)) {
      } __align;
    };
  };
  template <std::size_t _Len, std::size_t _Align = __alignof__(
                                  typename __aligned_storage_msa<_Len>::__type)>
  struct aligned_storage {
    union type {
      unsigned char __data[_Len];
      struct __attribute__((__aligned__((_Align)))) {
      } __align;
    };
  };

  template <typename... _Types>
  struct __strictest_alignment {
    static const size_t _S_alignment = 0;
    static const size_t _S_size = 0;
  };

  template <typename _Tp, typename... _Types>
  struct __strictest_alignment<_Tp, _Types...> {
    static const size_t _S_alignment =
        alignof(_Tp) > __strictest_alignment<_Types...>::_S_alignment
            ? alignof(_Tp)
            : __strictest_alignment<_Types...>::_S_alignment;
    static const size_t _S_size =
        sizeof(_Tp) > __strictest_alignment<_Types...>::_S_size
            ? sizeof(_Tp)
            : __strictest_alignment<_Types...>::_S_size;
  };
  template <size_t _Len, typename... _Types>
  struct aligned_union {
   private:
    static_assert(sizeof...(_Types) != 0, "At least one type is required");

    using __strictest = __strictest_alignment<_Types...>;
    static const size_t _S_len =
        _Len > __strictest::_S_size ? _Len : __strictest::_S_size;

   public:
    static const size_t alignment_value = __strictest::_S_alignment;

    typedef typename aligned_storage<_S_len, alignment_value>::type type;
  };

  template <size_t _Len, typename... _Types>
  const size_t aligned_union<_Len, _Types...>::alignment_value;

  template <typename _Up, bool _IsArray = is_array<_Up>::value,
            bool _IsFunction = is_function<_Up>::value>
  struct __decay_selector;

  template <typename _Up>
  struct __decay_selector<_Up, false, false> {
    typedef typename remove_cv<_Up>::type __type;
  };

  template <typename _Up>
  struct __decay_selector<_Up, true, false> {
    typedef typename remove_extent<_Up>::type* __type;
  };

  template <typename _Up>
  struct __decay_selector<_Up, false, true> {
    typedef typename add_pointer<_Up>::type __type;
  };

  template <typename _Tp>
  class decay {
    typedef typename remove_reference<_Tp>::type __remove_type;

   public:
    typedef typename __decay_selector<__remove_type>::__type type;
  };

  template <typename _Tp>
  class reference_wrapper;

  template <typename _Tp>
  struct __strip_reference_wrapper {
    typedef _Tp __type;
  };

  template <typename _Tp>
  struct __strip_reference_wrapper<reference_wrapper<_Tp>> {
    typedef _Tp& __type;
  };

  template <typename _Tp>
  struct __decay_and_strip {
    typedef
        typename __strip_reference_wrapper<typename decay<_Tp>::type>::__type
            __type;
  };

  template <bool, typename _Tp = void>
  struct enable_if {};

  template <typename _Tp>
  struct enable_if<true, _Tp> {
    typedef _Tp type;
  };

  template <typename... _Cond>
  using _Require = typename enable_if<__and_<_Cond...>::value>::type;

  template <bool _Cond, typename _Iftrue, typename _Iffalse>
  struct conditional {
    typedef _Iftrue type;
  };

  template <typename _Iftrue, typename _Iffalse>
  struct conditional<false, _Iftrue, _Iffalse> {
    typedef _Iffalse type;
  };

  template <typename... _Tp>
  struct common_type;

  struct __do_common_type_impl {
    template <typename _Tp, typename _Up>
    static __success_type<typename decay<
        decltype(true ? std::declval<_Tp>() : std::declval<_Up>())>::type>
    _S_test(int);

    template <typename, typename>
    static __failure_type _S_test(...);
  };

  template <typename _Tp, typename _Up>
  struct __common_type_impl : private __do_common_type_impl {
    typedef decltype(_S_test<_Tp, _Up>(0)) type;
  };

  struct __do_member_type_wrapper {
    template <typename _Tp>
    static __success_type<typename _Tp::type> _S_test(int);

    template <typename>
    static __failure_type _S_test(...);
  };

  template <typename _Tp>
  struct __member_type_wrapper : private __do_member_type_wrapper {
    typedef decltype(_S_test<_Tp>(0)) type;
  };

  template <typename _CTp, typename... _Args>
  struct __expanded_common_type_wrapper {
    typedef common_type<typename _CTp::type, _Args...> type;
  };

  template <typename... _Args>
  struct __expanded_common_type_wrapper<__failure_type, _Args...> {
    typedef __failure_type type;
  };

  template <typename _Tp>
  struct common_type<_Tp> {
    typedef typename decay<_Tp>::type type;
  };

  template <typename _Tp, typename _Up>
  struct common_type<_Tp, _Up> : public __common_type_impl<_Tp, _Up>::type {};

  template <typename _Tp, typename _Up, typename... _Vp>
  struct common_type<_Tp, _Up, _Vp...>
      : public __expanded_common_type_wrapper<
            typename __member_type_wrapper<common_type<_Tp, _Up>>::type,
            _Vp...>::type {};

  template <typename _Tp>
  struct underlying_type {
    typedef __underlying_type(_Tp) type;
  };

  template <typename _Tp>
  struct __declval_protector {
    static const bool __stop = false;
    static typename add_rvalue_reference<_Tp>::type __delegate();
  };

  template <typename _Tp>
  inline typename add_rvalue_reference<_Tp>::type declval() noexcept {
    static_assert(__declval_protector<_Tp>::__stop,
                  "declval() must not be used!");
    return __declval_protector<_Tp>::__delegate();
  }

  template <typename _Signature>
  class result_of;

  struct __invoke_memfun_ref {};
  struct __invoke_memfun_deref {};
  struct __invoke_memobj_ref {};
  struct __invoke_memobj_deref {};
  struct __invoke_other {};

  template <typename _Tp, typename _Tag>
  struct __result_of_success : __success_type<_Tp> {
    using __invoke_type = _Tag;
  };

  struct __result_of_memfun_ref_impl {
    template <typename _Fp, typename _Tp1, typename... _Args>
    static __result_of_success<
        decltype((std::declval<_Tp1>().*
                  std::declval<_Fp>())(std::declval<_Args>()...)),
        __invoke_memfun_ref>
    _S_test(int);

    template <typename...>
    static __failure_type _S_test(...);
  };

  template <typename _MemPtr, typename _Arg, typename... _Args>
  struct __result_of_memfun_ref : private __result_of_memfun_ref_impl {
    typedef decltype(_S_test<_MemPtr, _Arg, _Args...>(0)) type;
  };

  struct __result_of_memfun_deref_impl {
    template <typename _Fp, typename _Tp1, typename... _Args>
    static __result_of_success<
        decltype(((*std::declval<_Tp1>()).*
                  std::declval<_Fp>())(std::declval<_Args>()...)),
        __invoke_memfun_deref>
    _S_test(int);

    template <typename...>
    static __failure_type _S_test(...);
  };

  template <typename _MemPtr, typename _Arg, typename... _Args>
  struct __result_of_memfun_deref : private __result_of_memfun_deref_impl {
    typedef decltype(_S_test<_MemPtr, _Arg, _Args...>(0)) type;
  };

  struct __result_of_memobj_ref_impl {
    template <typename _Fp, typename _Tp1>
    static __result_of_success<decltype(std::declval<_Tp1>().*
                                        std::declval<_Fp>()),
                               __invoke_memobj_ref>
    _S_test(int);

    template <typename, typename>
    static __failure_type _S_test(...);
  };

  template <typename _MemPtr, typename _Arg>
  struct __result_of_memobj_ref : private __result_of_memobj_ref_impl {
    typedef decltype(_S_test<_MemPtr, _Arg>(0)) type;
  };

  struct __result_of_memobj_deref_impl {
    template <typename _Fp, typename _Tp1>
    static __result_of_success<decltype((*std::declval<_Tp1>()).*
                                        std::declval<_Fp>()),
                               __invoke_memobj_deref>
    _S_test(int);

    template <typename, typename>
    static __failure_type _S_test(...);
  };

  template <typename _MemPtr, typename _Arg>
  struct __result_of_memobj_deref : private __result_of_memobj_deref_impl {
    typedef decltype(_S_test<_MemPtr, _Arg>(0)) type;
  };

  template <typename _MemPtr, typename _Arg>
  struct __result_of_memobj;

  template <typename _Res, typename _Class, typename _Arg>
  struct __result_of_memobj<_Res _Class::*, _Arg> {
    typedef
        typename remove_cv<typename remove_reference<_Arg>::type>::type _Argval;
    typedef _Res _Class::*_MemPtr;
    typedef typename conditional<
        __or_<is_same<_Argval, _Class>, is_base_of<_Class, _Argval>>::value,
        __result_of_memobj_ref<_MemPtr, _Arg>,
        __result_of_memobj_deref<_MemPtr, _Arg>>::type::type type;
  };

  template <typename _MemPtr, typename _Arg, typename... _Args>
  struct __result_of_memfun;

  template <typename _Res, typename _Class, typename _Arg, typename... _Args>
  struct __result_of_memfun<_Res _Class::*, _Arg, _Args...> {
    typedef
        typename remove_cv<typename remove_reference<_Arg>::type>::type _Argval;
    typedef _Res _Class::*_MemPtr;
    typedef typename conditional<
        __or_<is_same<_Argval, _Class>, is_base_of<_Class, _Argval>>::value,
        __result_of_memfun_ref<_MemPtr, _Arg, _Args...>,
        __result_of_memfun_deref<_MemPtr, _Arg, _Args...>>::type::type type;
  };

  template <typename _Tp, typename _Up = typename decay<_Tp>::type>
  struct __inv_unwrap {
    using type = _Tp;
  };

  template <typename _Tp, typename _Up>
  struct __inv_unwrap<_Tp, reference_wrapper<_Up>> {
    using type = _Up&;
  };

  template <bool, bool, typename _Functor, typename... _ArgTypes>
  struct __result_of_impl {
    typedef __failure_type type;
  };

  template <typename _MemPtr, typename _Arg>
  struct __result_of_impl<true, false, _MemPtr, _Arg>
      : public __result_of_memobj<typename decay<_MemPtr>::type,
                                  typename __inv_unwrap<_Arg>::type> {};

  template <typename _MemPtr, typename _Arg, typename... _Args>
  struct __result_of_impl<false, true, _MemPtr, _Arg, _Args...>
      : public __result_of_memfun<typename decay<_MemPtr>::type,
                                  typename __inv_unwrap<_Arg>::type, _Args...> {
  };

  struct __result_of_other_impl {
    template <typename _Fn, typename... _Args>
    static __result_of_success<
        decltype(std::declval<_Fn>()(std::declval<_Args>()...)),
        __invoke_other>
    _S_test(int);

    template <typename...>
    static __failure_type _S_test(...);
  };

  template <typename _Functor, typename... _ArgTypes>
  struct __result_of_impl<false, false, _Functor, _ArgTypes...>
      : private __result_of_other_impl {
    typedef decltype(_S_test<_Functor, _ArgTypes...>(0)) type;
  };

  template <typename _Functor, typename... _ArgTypes>
  struct __invoke_result
      : public __result_of_impl<
            is_member_object_pointer<
                typename remove_reference<_Functor>::type>::value,
            is_member_function_pointer<
                typename remove_reference<_Functor>::type>::value,
            _Functor, _ArgTypes...>::type {};

  template <typename _Functor, typename... _ArgTypes>
  struct result_of<_Functor(_ArgTypes...)>
      : public __invoke_result<_Functor, _ArgTypes...> {};

  template <size_t _Len, size_t _Align = __alignof__(
                             typename __aligned_storage_msa<_Len>::__type)>
  using aligned_storage_t = typename aligned_storage<_Len, _Align>::type;

  template <size_t _Len, typename... _Types>
  using aligned_union_t = typename aligned_union<_Len, _Types...>::type;

  template <typename _Tp>
  using decay_t = typename decay<_Tp>::type;

  template <bool _Cond, typename _Tp = void>
  using enable_if_t = typename enable_if<_Cond, _Tp>::type;

  template <bool _Cond, typename _Iftrue, typename _Iffalse>
  using conditional_t = typename conditional<_Cond, _Iftrue, _Iffalse>::type;

  template <typename... _Tp>
  using common_type_t = typename common_type<_Tp...>::type;

  template <typename _Tp>
  using underlying_type_t = typename underlying_type<_Tp>::type;

  template <typename _Tp>
  using result_of_t = typename result_of<_Tp>::type;

  template <typename...>
  using __void_t = void;

  template <typename...>
  using void_t = void;

  template <typename _Default, typename _AlwaysVoid,
            template <typename...> class _Op, typename... _Args>
  struct __detector {
    using value_t = false_type;
    using type = _Default;
  };

  template <typename _Default, template <typename...> class _Op,
            typename... _Args>
  struct __detector<_Default, __void_t<_Op<_Args...>>, _Op, _Args...> {
    using value_t = true_type;
    using type = _Op<_Args...>;
  };

  template <typename _Default, template <typename...> class _Op,
            typename... _Args>
  using __detected_or = __detector<_Default, void, _Op, _Args...>;

  template <typename _Default, template <typename...> class _Op,
            typename... _Args>
  using __detected_or_t = typename __detected_or<_Default, _Op, _Args...>::type;
  template <typename _Tp>
  struct __is_swappable;

  template <typename _Tp>
  struct __is_nothrow_swappable;

  template <typename... _Elements>
  class tuple;

  template <typename>
  struct __is_tuple_like_impl : false_type {};

  template <typename... _Tps>
  struct __is_tuple_like_impl<tuple<_Tps...>> : true_type {};

  template <typename _Tp>
  struct __is_tuple_like
      : public __is_tuple_like_impl<typename remove_cv<
            typename remove_reference<_Tp>::type>::type>::type {};

  template <typename _Tp>
  inline typename enable_if<
      __and_<__not_<__is_tuple_like<_Tp>>, is_move_constructible<_Tp>,
             is_move_assignable<_Tp>>::value>::type
  swap(_Tp&, _Tp&) noexcept(__and_<is_nothrow_move_constructible<_Tp>,
                                   is_nothrow_move_assignable<_Tp>>::value);

  template <typename _Tp, size_t _Nm>
  inline typename enable_if<__is_swappable<_Tp>::value>::type swap(
      _Tp(&__a)[_Nm],
      _Tp(&__b)[_Nm]) noexcept(__is_nothrow_swappable<_Tp>::value);

  namespace __swappable_details {
  using std::swap;

  struct __do_is_swappable_impl {
    template <typename _Tp,
              typename = decltype(swap(std::declval<_Tp&>(),
                                       std::declval<_Tp&>()))>
    static true_type __test(int);

    template <typename>
    static false_type __test(...);
  };

  struct __do_is_nothrow_swappable_impl {
    template <typename _Tp>
    static __bool_constant<noexcept(swap(std::declval<_Tp&>(),
                                         std::declval<_Tp&>()))>
    __test(int);

    template <typename>
    static false_type __test(...);
  };

  }  // namespace __swappable_details

  template <typename _Tp>
  struct __is_swappable_impl
      : public __swappable_details::__do_is_swappable_impl {
    typedef decltype(__test<_Tp>(0)) type;
  };

  template <typename _Tp>
  struct __is_nothrow_swappable_impl
      : public __swappable_details::__do_is_nothrow_swappable_impl {
    typedef decltype(__test<_Tp>(0)) type;
  };

  template <typename _Tp>
  struct __is_swappable : public __is_swappable_impl<_Tp>::type {};

  template <typename _Tp>
  struct __is_nothrow_swappable
      : public __is_nothrow_swappable_impl<_Tp>::type {};

  template <typename _Tp>
  struct is_swappable : public __is_swappable_impl<_Tp>::type {};

  template <typename _Tp>
  struct is_nothrow_swappable : public __is_nothrow_swappable_impl<_Tp>::type {
  };

  template <typename _Tp>
  constexpr bool is_swappable_v = is_swappable<_Tp>::value;

  template <typename _Tp>
  constexpr bool is_nothrow_swappable_v = is_nothrow_swappable<_Tp>::value;

  namespace __swappable_with_details {
  using std::swap;

  struct __do_is_swappable_with_impl {
    template <
        typename _Tp,
        typename _Up,
        typename = decltype(swap(std::declval<_Tp>(), std::declval<_Up>())),
        typename = decltype(swap(std::declval<_Up>(), std::declval<_Tp>()))>
    static true_type __test(int);

    template <typename, typename>
    static false_type __test(...);
  };

  struct __do_is_nothrow_swappable_with_impl {
    template <typename _Tp, typename _Up>
    static __bool_constant<
        noexcept(swap(std::declval<_Tp>(), std::declval<_Up>())) &&
        noexcept(swap(std::declval<_Up>(), std::declval<_Tp>()))>
    __test(int);

    template <typename, typename>
    static false_type __test(...);
  };

  }  // namespace __swappable_with_details

  template <typename _Tp, typename _Up>
  struct __is_swappable_with_impl
      : public __swappable_with_details::__do_is_swappable_with_impl {
    typedef decltype(__test<_Tp, _Up>(0)) type;
  };

  template <typename _Tp>
  struct __is_swappable_with_impl<_Tp&, _Tp&>
      : public __swappable_details::__do_is_swappable_impl {
    typedef decltype(__test<_Tp&>(0)) type;
  };

  template <typename _Tp, typename _Up>
  struct __is_nothrow_swappable_with_impl
      : public __swappable_with_details::__do_is_nothrow_swappable_with_impl {
    typedef decltype(__test<_Tp, _Up>(0)) type;
  };

  template <typename _Tp>
  struct __is_nothrow_swappable_with_impl<_Tp&, _Tp&>
      : public __swappable_details::__do_is_nothrow_swappable_impl {
    typedef decltype(__test<_Tp&>(0)) type;
  };

  template <typename _Tp, typename _Up>
  struct is_swappable_with : public __is_swappable_with_impl<_Tp, _Up>::type {};

  template <typename _Tp, typename _Up>
  struct is_nothrow_swappable_with
      : public __is_nothrow_swappable_with_impl<_Tp, _Up>::type {};

  template <typename _Tp, typename _Up>
  constexpr bool is_swappable_with_v = is_swappable_with<_Tp, _Up>::value;

  template <typename _Tp, typename _Up>
  constexpr bool is_nothrow_swappable_with_v =
      is_nothrow_swappable_with<_Tp, _Up>::value;

  template <typename _Result, typename _Ret, typename = void>
  struct __is_invocable_impl : false_type {};

  template <typename _Result, typename _Ret>
  struct __is_invocable_impl<_Result, _Ret, __void_t<typename _Result::type>>
      : __or_<is_void<_Ret>,
              is_convertible<typename _Result::type, _Ret>>::type {};

  template <typename _Fn, typename... _ArgTypes>
  struct __is_invocable
      : __is_invocable_impl<__invoke_result<_Fn, _ArgTypes...>, void>::type {};

  template <typename _Fn, typename _Tp, typename... _Args>
  constexpr bool __call_is_nt(__invoke_memfun_ref) {
    using _Up = typename __inv_unwrap<_Tp>::type;
    return noexcept(
        (std::declval<_Up>().*std::declval<_Fn>())(std::declval<_Args>()...));
  }

  template <typename _Fn, typename _Tp, typename... _Args>
  constexpr bool __call_is_nt(__invoke_memfun_deref) {
    return noexcept(((*std::declval<_Tp>()).*
                     std::declval<_Fn>())(std::declval<_Args>()...));
  }

  template <typename _Fn, typename _Tp>
  constexpr bool __call_is_nt(__invoke_memobj_ref) {
    using _Up = typename __inv_unwrap<_Tp>::type;
    return noexcept(std::declval<_Up>().*std::declval<_Fn>());
  }

  template <typename _Fn, typename _Tp>
  constexpr bool __call_is_nt(__invoke_memobj_deref) {
    return noexcept((*std::declval<_Tp>()).*std::declval<_Fn>());
  }

  template <typename _Fn, typename... _Args>
  constexpr bool __call_is_nt(__invoke_other) {
    return noexcept(std::declval<_Fn>()(std::declval<_Args>()...));
  }

  template <typename _Result, typename _Fn, typename... _Args>
  struct __call_is_nothrow : __bool_constant<std::__call_is_nt<_Fn, _Args...>(
                                 typename _Result::__invoke_type{})> {};

  template <typename _Fn, typename... _Args>
  using __call_is_nothrow_ =
      __call_is_nothrow<__invoke_result<_Fn, _Args...>, _Fn, _Args...>;

  template <typename _Fn, typename... _Args>
  struct __is_nothrow_invocable
      : __and_<__is_invocable<_Fn, _Args...>,
               __call_is_nothrow_<_Fn, _Args...>>::type {};

  struct __nonesuch {
    __nonesuch() = delete;
    ~__nonesuch() = delete;
    __nonesuch(__nonesuch const&) = delete;
    void operator=(__nonesuch const&) = delete;
  };

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  struct input_iterator_tag {};

  struct output_iterator_tag {};

  struct forward_iterator_tag : public input_iterator_tag {};

  struct bidirectional_iterator_tag : public forward_iterator_tag {};

  struct random_access_iterator_tag : public bidirectional_iterator_tag {};
  template <typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
            typename _Pointer = _Tp*, typename _Reference = _Tp&>
  struct iterator {
    typedef _Category iterator_category;

    typedef _Tp value_type;

    typedef _Distance difference_type;

    typedef _Pointer pointer;

    typedef _Reference reference;
  };
  template <typename _Iterator, typename = __void_t<>>
  struct __iterator_traits {};

  template <typename _Iterator>
  struct __iterator_traits<
      _Iterator,
      __void_t<typename _Iterator::iterator_category,
               typename _Iterator::value_type,
               typename _Iterator::difference_type, typename _Iterator::pointer,
               typename _Iterator::reference>> {
    typedef typename _Iterator::iterator_category iterator_category;
    typedef typename _Iterator::value_type value_type;
    typedef typename _Iterator::difference_type difference_type;
    typedef typename _Iterator::pointer pointer;
    typedef typename _Iterator::reference reference;
  };

  template <typename _Iterator>
  struct iterator_traits : public __iterator_traits<_Iterator> {};
  template <typename _Tp>
  struct iterator_traits<_Tp*> {
    typedef random_access_iterator_tag iterator_category;
    typedef _Tp value_type;
    typedef ptrdiff_t difference_type;
    typedef _Tp* pointer;
    typedef _Tp& reference;
  };

  template <typename _Tp>
  struct iterator_traits<const _Tp*> {
    typedef random_access_iterator_tag iterator_category;
    typedef _Tp value_type;
    typedef ptrdiff_t difference_type;
    typedef const _Tp* pointer;
    typedef const _Tp& reference;
  };

  template <typename _Iter>
  inline typename iterator_traits<_Iter>::iterator_category __iterator_category(
      const _Iter&) {
    return typename iterator_traits<_Iter>::iterator_category();
  }
  template <typename _InIter>
  using _RequireInputIter = typename enable_if<
      is_convertible<typename iterator_traits<_InIter>::iterator_category,
                     input_iterator_tag>::value>::type;

}  // namespace std__attribute__((__visibility__("default")))

namespace std {
namespace __debug {}
}  // namespace std

namespace __gnu_debug {
using namespace std::__debug;
}
namespace std __attribute__((__visibility__("default"))) {

  template <typename _Tp>
  inline constexpr _Tp* __addressof(_Tp & __r) noexcept {
    return __builtin_addressof(__r);
  }

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Tp>
  constexpr _Tp&& forward(typename std::remove_reference<_Tp>::type &
                          __t) noexcept {
    return static_cast<_Tp&&>(__t);
  }

  template <typename _Tp>
  constexpr _Tp&& forward(typename std::remove_reference<_Tp>::type &&
                          __t) noexcept {
    static_assert(!std::is_lvalue_reference<_Tp>::value,
                  "template argument"
                  " substituting _Tp is an lvalue reference type");
    return static_cast<_Tp&&>(__t);
  }

  template <typename _Tp>
  constexpr typename std::remove_reference<_Tp>::type&& move(_Tp &&
                                                             __t) noexcept {
    return static_cast<typename std::remove_reference<_Tp>::type&&>(__t);
  }

  template <typename _Tp>
  struct __move_if_noexcept_cond
      : public __and_<__not_<is_nothrow_move_constructible<_Tp>>,
                      is_copy_constructible<_Tp>>::type {};
  template <typename _Tp>
  constexpr typename conditional<__move_if_noexcept_cond<_Tp>::value,
                                 const _Tp&, _Tp&&>::type
  move_if_noexcept(_Tp & __x) noexcept {
    return std::move(__x);
  }
  template <typename _Tp>
  inline _Tp* addressof(_Tp & __r) noexcept {
    return std::__addressof(__r);
  }

  template <typename _Tp>
  const _Tp* addressof(const _Tp&&) = delete;

  template <typename _Tp, typename _Up = _Tp>
  inline _Tp __exchange(_Tp & __obj, _Up && __new_val) {
    _Tp __old_val = std::move(__obj);
    __obj = std::forward<_Up>(__new_val);
    return __old_val;
  }

}  // namespace std__attribute__((__visibility__("default")))
namespace std __attribute__((__visibility__("default"))) {

  template <typename _Tp>
  inline

      typename enable_if<
          __and_<__not_<__is_tuple_like<_Tp>>, is_move_constructible<_Tp>,
                 is_move_assignable<_Tp>>::value>::type
      swap(_Tp & __a,
           _Tp & __b) noexcept(__and_<is_nothrow_move_constructible<_Tp>,
                                      is_nothrow_move_assignable<_Tp>>::value)

  {
    _Tp __tmp = std::move(__a);
    __a = std::move(__b);
    __b = std::move(__tmp);
  }

  template <typename _Tp, size_t _Nm>
  inline

      typename enable_if<__is_swappable<_Tp>::value>::type
      swap(_Tp(&__a)[_Nm],
           _Tp(&__b)[_Nm]) noexcept(__is_nothrow_swappable<_Tp>::value)

  {
    for (size_t __n = 0; __n < _Nm; ++__n)
      swap(__a[__n], __b[__n]);
  }

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <typename _ForwardIterator, typename _Tp>
  void iota(_ForwardIterator __first, _ForwardIterator __last, _Tp __value) {
    ;

    for (; __first != __last; ++__first) {
      *__first = __value;
      ++__value;
    }
  }

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <typename _InputIterator, typename _Tp>
  inline _Tp accumulate(_InputIterator __first, _InputIterator __last,
                        _Tp __init) {
    ;

    for (; __first != __last; ++__first)
      __init = __init + *__first;
    return __init;
  }
  template <typename _InputIterator, typename _Tp, typename _BinaryOperation>
  inline _Tp accumulate(_InputIterator __first, _InputIterator __last,
                        _Tp __init, _BinaryOperation __binary_op) {
    ;

    for (; __first != __last; ++__first)
      __init = __binary_op(__init, *__first);
    return __init;
  }
  template <typename _InputIterator1, typename _InputIterator2, typename _Tp>
  inline _Tp inner_product(_InputIterator1 __first1, _InputIterator1 __last1,
                           _InputIterator2 __first2, _Tp __init) {
    ;

    for (; __first1 != __last1; ++__first1, (void)++__first2)
      __init = __init + (*__first1 * *__first2);
    return __init;
  }
  template <typename _InputIterator1, typename _InputIterator2, typename _Tp,
            typename _BinaryOperation1, typename _BinaryOperation2>
  inline _Tp inner_product(_InputIterator1 __first1, _InputIterator1 __last1,
                           _InputIterator2 __first2, _Tp __init,
                           _BinaryOperation1 __binary_op1,
                           _BinaryOperation2 __binary_op2) {
    ;

    for (; __first1 != __last1; ++__first1, (void)++__first2)
      __init = __binary_op1(__init, __binary_op2(*__first1, *__first2));
    return __init;
  }
  template <typename _InputIterator, typename _OutputIterator>
  _OutputIterator partial_sum(_InputIterator __first, _InputIterator __last,
                              _OutputIterator __result) {
    typedef typename iterator_traits<_InputIterator>::value_type _ValueType;

    ;

    if (__first == __last)
      return __result;
    _ValueType __value = *__first;
    *__result = __value;
    while (++__first != __last) {
      __value = __value + *__first;
      *++__result = __value;
    }
    return ++__result;
  }
  template <typename _InputIterator, typename _OutputIterator,
            typename _BinaryOperation>
  _OutputIterator partial_sum(_InputIterator __first, _InputIterator __last,
                              _OutputIterator __result,
                              _BinaryOperation __binary_op) {
    typedef typename iterator_traits<_InputIterator>::value_type _ValueType;

    ;

    if (__first == __last)
      return __result;
    _ValueType __value = *__first;
    *__result = __value;
    while (++__first != __last) {
      __value = __binary_op(__value, *__first);
      *++__result = __value;
    }
    return ++__result;
  }
  template <typename _InputIterator, typename _OutputIterator>
  _OutputIterator adjacent_difference(
      _InputIterator __first, _InputIterator __last, _OutputIterator __result) {
    typedef typename iterator_traits<_InputIterator>::value_type _ValueType;

    ;

    if (__first == __last)
      return __result;
    _ValueType __value = *__first;
    *__result = __value;
    while (++__first != __last) {
      _ValueType __tmp = *__first;
      *++__result = __tmp - __value;
      __value = std::move(__tmp);
    }
    return ++__result;
  }
  template <typename _InputIterator, typename _OutputIterator,
            typename _BinaryOperation>
  _OutputIterator adjacent_difference(
      _InputIterator __first, _InputIterator __last, _OutputIterator __result,
      _BinaryOperation __binary_op) {
    typedef typename iterator_traits<_InputIterator>::value_type _ValueType;

    ;

    if (__first == __last)
      return __result;
    _ValueType __value = *__first;
    *__result = __value;
    while (++__first != __last) {
      _ValueType __tmp = *__first;
      *++__result = __binary_op(__tmp, __value);
      __value = std::move(__tmp);
    }
    return ++__result;
  }

}  // namespace std__attribute__((__visibility__("default")))
namespace std __attribute__((__visibility__("default"))) {
  namespace __detail {

  template <typename _Tp>
  constexpr enable_if_t<__and_<is_integral<_Tp>, is_signed<_Tp>>::value, _Tp>
  __abs_integral(_Tp __val) {
    return __val < 0 ? -__val : __val;
  }

  template <typename _Tp>
  constexpr enable_if_t<__and_<is_integral<_Tp>, is_unsigned<_Tp>>::value, _Tp>
  __abs_integral(_Tp __val) {
    return __val;
  }

  void __abs_integral(bool) = delete;

  template <typename _Mn, typename _Nn>
  constexpr common_type_t<_Mn, _Nn> __gcd(_Mn __m, _Nn __n) {
    return __m == 0 ? __detail::__abs_integral(__n)
                    : __n == 0 ? __detail::__abs_integral(__m)
                               : __detail::__gcd(__n, __m % __n);
  }

  template <typename _Mn, typename _Nn>
  constexpr common_type_t<_Mn, _Nn> __lcm(_Mn __m, _Nn __n) {
    return (__m != 0 && __n != 0)
               ? (__detail::__abs_integral(__m) / __detail::__gcd(__m, __n)) *
                     __detail::__abs_integral(__n)
               : 0;
  }

  }  // namespace __detail

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  void __throw_bad_exception(void) __attribute__((__noreturn__));

  void __throw_bad_alloc(void) __attribute__((__noreturn__));

  void __throw_bad_cast(void) __attribute__((__noreturn__));

  void __throw_bad_typeid(void) __attribute__((__noreturn__));

  void __throw_logic_error(const char*) __attribute__((__noreturn__));

  void __throw_domain_error(const char*) __attribute__((__noreturn__));

  void __throw_invalid_argument(const char*) __attribute__((__noreturn__));

  void __throw_length_error(const char*) __attribute__((__noreturn__));

  void __throw_out_of_range(const char*) __attribute__((__noreturn__));

  void __throw_out_of_range_fmt(const char*, ...) __attribute__((__noreturn__))
  __attribute__((__format__(__gnu_printf__, 1, 2)));

  void __throw_runtime_error(const char*) __attribute__((__noreturn__));

  void __throw_range_error(const char*) __attribute__((__noreturn__));

  void __throw_overflow_error(const char*) __attribute__((__noreturn__));

  void __throw_underflow_error(const char*) __attribute__((__noreturn__));

  void __throw_ios_failure(const char*) __attribute__((__noreturn__));

  void __throw_system_error(int) __attribute__((__noreturn__));

  void __throw_future_error(int) __attribute__((__noreturn__));

  void __throw_bad_function_call() __attribute__((__noreturn__));

}  // namespace std__attribute__((__visibility__("default")))

extern "C++" {

namespace std __attribute__((__visibility__("default"))) {

  struct __true_type {};
  struct __false_type {};

  template <bool>
  struct __truth_type {
    typedef __false_type __type;
  };

  template <>
  struct __truth_type<true> {
    typedef __true_type __type;
  };

  template <class _Sp, class _Tp>
  struct __traitor {
    enum { __value = bool(_Sp::__value) || bool(_Tp::__value) };
    typedef typename __truth_type<__value>::__type __type;
  };

  template <typename, typename>
  struct __are_same {
    enum { __value = 0 };
    typedef __false_type __type;
  };

  template <typename _Tp>
  struct __are_same<_Tp, _Tp> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <typename _Tp>
  struct __is_void {
    enum { __value = 0 };
    typedef __false_type __type;
  };

  template <>
  struct __is_void<void> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <typename _Tp>
  struct __is_integer {
    enum { __value = 0 };
    typedef __false_type __type;
  };

  template <>
  struct __is_integer<bool> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <>
  struct __is_integer<char> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <>
  struct __is_integer<signed char> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <>
  struct __is_integer<unsigned char> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <>
  struct __is_integer<wchar_t> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <>
  struct __is_integer<char16_t> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <>
  struct __is_integer<char32_t> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <>
  struct __is_integer<short> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <>
  struct __is_integer<unsigned short> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <>
  struct __is_integer<int> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <>
  struct __is_integer<unsigned int> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <>
  struct __is_integer<long> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <>
  struct __is_integer<unsigned long> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <>
  struct __is_integer<long long> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <>
  struct __is_integer<unsigned long long> {
    enum { __value = 1 };
    typedef __true_type __type;
  };
  template <>
  struct __is_integer<__int128> {
    enum { __value = 1 };
    typedef __true_type __type;
  };
  template <>
  struct __is_integer<unsigned __int128> {
    enum { __value = 1 };
    typedef __true_type __type;
  };
  template <typename _Tp>
  struct __is_floating {
    enum { __value = 0 };
    typedef __false_type __type;
  };

  template <>
  struct __is_floating<float> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <>
  struct __is_floating<double> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <>
  struct __is_floating<long double> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <typename _Tp>
  struct __is_pointer {
    enum { __value = 0 };
    typedef __false_type __type;
  };

  template <typename _Tp>
  struct __is_pointer<_Tp*> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <typename _Tp>
  struct __is_arithmetic
      : public __traitor<__is_integer<_Tp>, __is_floating<_Tp>>{};

  template <typename _Tp>
  struct __is_scalar
      : public __traitor<__is_arithmetic<_Tp>, __is_pointer<_Tp>>{};

  template <typename _Tp>
  struct __is_char {
    enum { __value = 0 };
    typedef __false_type __type;
  };

  template <>
  struct __is_char<char> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <>
  struct __is_char<wchar_t> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <typename _Tp>
  struct __is_byte {
    enum { __value = 0 };
    typedef __false_type __type;
  };

  template <>
  struct __is_byte<char> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <>
  struct __is_byte<signed char> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <>
  struct __is_byte<unsigned char> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <typename _Tp>
  struct __is_move_iterator {
    enum { __value = 0 };
    typedef __false_type __type;
  };

  template <typename _Iterator>
  inline _Iterator __miter_base(_Iterator __it) {
    return __it;
  }

}  // namespace std__attribute__((__visibility__("default")))
}

extern "C++" {

namespace __gnu_cxx __attribute__((__visibility__("default"))) {

  template <bool, typename>
  struct __enable_if {};

  template <typename _Tp>
  struct __enable_if<true, _Tp> {
    typedef _Tp __type;
  };

  template <bool _Cond, typename _Iftrue, typename _Iffalse>
  struct __conditional_type {
    typedef _Iftrue __type;
  };

  template <typename _Iftrue, typename _Iffalse>
  struct __conditional_type<false, _Iftrue, _Iffalse> {
    typedef _Iffalse __type;
  };

  template <typename _Tp>
  struct __add_unsigned {
   private:
    typedef __enable_if<std::__is_integer<_Tp>::__value, _Tp> __if_type;

   public:
    typedef typename __if_type::__type __type;
  };

  template <>
  struct __add_unsigned<char> {
    typedef unsigned char __type;
  };

  template <>
  struct __add_unsigned<signed char> {
    typedef unsigned char __type;
  };

  template <>
  struct __add_unsigned<short> {
    typedef unsigned short __type;
  };

  template <>
  struct __add_unsigned<int> {
    typedef unsigned int __type;
  };

  template <>
  struct __add_unsigned<long> {
    typedef unsigned long __type;
  };

  template <>
  struct __add_unsigned<long long> {
    typedef unsigned long long __type;
  };

  template <>
  struct __add_unsigned<bool>;

  template <>
  struct __add_unsigned<wchar_t>;

  template <typename _Tp>
  struct __remove_unsigned {
   private:
    typedef __enable_if<std::__is_integer<_Tp>::__value, _Tp> __if_type;

   public:
    typedef typename __if_type::__type __type;
  };

  template <>
  struct __remove_unsigned<char> {
    typedef signed char __type;
  };

  template <>
  struct __remove_unsigned<unsigned char> {
    typedef signed char __type;
  };

  template <>
  struct __remove_unsigned<unsigned short> {
    typedef short __type;
  };

  template <>
  struct __remove_unsigned<unsigned int> {
    typedef int __type;
  };

  template <>
  struct __remove_unsigned<unsigned long> {
    typedef long __type;
  };

  template <>
  struct __remove_unsigned<unsigned long long> {
    typedef long long __type;
  };

  template <>
  struct __remove_unsigned<bool>;

  template <>
  struct __remove_unsigned<wchar_t>;

  template <typename _Type>
  inline bool __is_null_pointer(_Type * __ptr) {
    return __ptr == 0;
  }

  template <typename _Type>
  inline bool __is_null_pointer(_Type) {
    return false;
  }

  inline bool __is_null_pointer(std::nullptr_t) { return true; }

  template <typename _Tp, bool = std::__is_integer<_Tp>::__value>
  struct __promote {
    typedef double __type;
  };

  template <typename _Tp>
  struct __promote<_Tp, false> {};

  template <>
  struct __promote<long double> {
    typedef long double __type;
  };

  template <>
  struct __promote<double> {
    typedef double __type;
  };

  template <>
  struct __promote<float> {
    typedef float __type;
  };

  template <typename _Tp, typename _Up,
            typename _Tp2 = typename __promote<_Tp>::__type,
            typename _Up2 = typename __promote<_Up>::__type>
  struct __promote_2 {
    typedef __typeof__(_Tp2() + _Up2()) __type;
  };

  template <typename _Tp, typename _Up, typename _Vp,
            typename _Tp2 = typename __promote<_Tp>::__type,
            typename _Up2 = typename __promote<_Up>::__type,
            typename _Vp2 = typename __promote<_Vp>::__type>
  struct __promote_3 {
    typedef __typeof__(_Tp2() + _Up2() + _Vp2()) __type;
  };

  template <typename _Tp, typename _Up, typename _Vp, typename _Wp,
            typename _Tp2 = typename __promote<_Tp>::__type,
            typename _Up2 = typename __promote<_Up>::__type,
            typename _Vp2 = typename __promote<_Vp>::__type,
            typename _Wp2 = typename __promote<_Wp>::__type>
  struct __promote_4 {
    typedef __typeof__(_Tp2() + _Up2() + _Vp2() + _Wp2()) __type;
  };

}  // namespace __gnu_cxx__attribute__((__visibility__("default")))
}

namespace __gnu_cxx __attribute__((__visibility__("default"))) {

  template <typename _Value>
  struct __numeric_traits_integer {
    static const _Value __min =
        (((_Value)(-1) < 0)
             ? (_Value)1 << (sizeof(_Value) * 8 - ((_Value)(-1) < 0))
             : (_Value)0);
    static const _Value __max =
        (((_Value)(-1) < 0)
             ? (((((_Value)1
                   << ((sizeof(_Value) * 8 - ((_Value)(-1) < 0)) - 1)) -
                  1)
                 << 1) +
                1)
             : ~(_Value)0);

    static const bool __is_signed = ((_Value)(-1) < 0);
    static const int __digits = (sizeof(_Value) * 8 - ((_Value)(-1) < 0));
  };

  template <typename _Value>
  const _Value __numeric_traits_integer<_Value>::__min;

  template <typename _Value>
  const _Value __numeric_traits_integer<_Value>::__max;

  template <typename _Value>
  const bool __numeric_traits_integer<_Value>::__is_signed;

  template <typename _Value>
  const int __numeric_traits_integer<_Value>::__digits;
  template <typename _Value>
  struct __numeric_traits_floating {
    static const int __max_digits10 =
        (2 + (std::__are_same<_Value, float>::__value
                  ? 24
                  : std::__are_same<_Value, double>::__value ? 53 : 64) *
                 643L / 2136);

    static const bool __is_signed = true;
    static const int __digits10 =
        (std::__are_same<_Value, float>::__value
             ? 6
             : std::__are_same<_Value, double>::__value ? 15 : 18);
    static const int __max_exponent10 =
        (std::__are_same<_Value, float>::__value
             ? 38
             : std::__are_same<_Value, double>::__value ? 308 : 4932);
  };

  template <typename _Value>
  const int __numeric_traits_floating<_Value>::__max_digits10;

  template <typename _Value>
  const bool __numeric_traits_floating<_Value>::__is_signed;

  template <typename _Value>
  const int __numeric_traits_floating<_Value>::__digits10;

  template <typename _Value>
  const int __numeric_traits_floating<_Value>::__max_exponent10;

  template <typename _Value>
  struct __numeric_traits
      : public __conditional_type<std::__is_integer<_Value>::__value,
                                  __numeric_traits_integer<_Value>,
                                  __numeric_traits_floating<_Value>>::__type {};

}  // namespace __gnu_cxx__attribute__((__visibility__("default")))
namespace std __attribute__((__visibility__("default"))) {

  struct piecewise_construct_t {
    explicit piecewise_construct_t() = default;
  };

  constexpr piecewise_construct_t piecewise_construct = piecewise_construct_t();

  template <typename...>
  class tuple;

  template <std::size_t...>
  struct _Index_tuple;

  template <bool, typename _T1, typename _T2>
  struct _PCC {
    template <typename _U1, typename _U2>
    static constexpr bool _ConstructiblePair() {
      return __and_<is_constructible<_T1, const _U1&>,
                    is_constructible<_T2, const _U2&>>::value;
    }

    template <typename _U1, typename _U2>
    static constexpr bool _ImplicitlyConvertiblePair() {
      return __and_<is_convertible<const _U1&, _T1>,
                    is_convertible<const _U2&, _T2>>::value;
    }

    template <typename _U1, typename _U2>
    static constexpr bool _MoveConstructiblePair() {
      return __and_<is_constructible<_T1, _U1&&>,
                    is_constructible<_T2, _U2&&>>::value;
    }

    template <typename _U1, typename _U2>
    static constexpr bool _ImplicitlyMoveConvertiblePair() {
      return __and_<is_convertible<_U1&&, _T1>,
                    is_convertible<_U2&&, _T2>>::value;
    }

    template <bool __implicit, typename _U1, typename _U2>
    static constexpr bool _CopyMovePair() {
      using __do_converts =
          __and_<is_convertible<const _U1&, _T1>, is_convertible<_U2&&, _T2>>;
      using __converts = typename conditional<__implicit, __do_converts,
                                              __not_<__do_converts>>::type;
      return __and_<is_constructible<_T1, const _U1&>,
                    is_constructible<_T2, _U2&&>, __converts>::value;
    }

    template <bool __implicit, typename _U1, typename _U2>
    static constexpr bool _MoveCopyPair() {
      using __do_converts =
          __and_<is_convertible<_U1&&, _T1>, is_convertible<const _U2&, _T2>>;
      using __converts = typename conditional<__implicit, __do_converts,
                                              __not_<__do_converts>>::type;
      return __and_<is_constructible<_T1, _U1&&>,
                    is_constructible<_T2, const _U2&&>, __converts>::value;
    }
  };

  template <typename _T1, typename _T2>
  struct _PCC<false, _T1, _T2> {
    template <typename _U1, typename _U2>
    static constexpr bool _ConstructiblePair() {
      return false;
    }

    template <typename _U1, typename _U2>
    static constexpr bool _ImplicitlyConvertiblePair() {
      return false;
    }

    template <typename _U1, typename _U2>
    static constexpr bool _MoveConstructiblePair() {
      return false;
    }

    template <typename _U1, typename _U2>
    static constexpr bool _ImplicitlyMoveConvertiblePair() {
      return false;
    }
  };

  struct __nonesuch_no_braces : std::__nonesuch {
    explicit __nonesuch_no_braces(const __nonesuch&) = delete;
  };
  template <typename _T1, typename _T2>
  struct pair {
    typedef _T1 first_type;
    typedef _T2 second_type;

    _T1 first;
    _T2 second;

    template <typename _U1 = _T1,
              typename _U2 = _T2,
              typename enable_if<
                  __and_<__is_implicitly_default_constructible<_U1>,
                         __is_implicitly_default_constructible<_U2>>::value,
                  bool>::type = true>

    constexpr pair() : first(), second() {}

    template <
        typename _U1 = _T1,
        typename _U2 = _T2,
        typename enable_if<
            __and_<is_default_constructible<_U1>,
                   is_default_constructible<_U2>,
                   __not_<__and_<__is_implicitly_default_constructible<_U1>,
                                 __is_implicitly_default_constructible<_U2>>>>::
                value,
            bool>::type = false>
    explicit constexpr pair() : first(), second() {}
    using _PCCP = _PCC<true, _T1, _T2>;

    template <typename _U1 = _T1,
              typename _U2 = _T2,
              typename enable_if<
                  _PCCP::template _ConstructiblePair<_U1, _U2>() &&
                      _PCCP::template _ImplicitlyConvertiblePair<_U1, _U2>(),
                  bool>::type = true>
    constexpr pair(const _T1& __a, const _T2& __b) : first(__a), second(__b) {}

    template <typename _U1 = _T1,
              typename _U2 = _T2,
              typename enable_if<
                  _PCCP::template _ConstructiblePair<_U1, _U2>() &&
                      !_PCCP::template _ImplicitlyConvertiblePair<_U1, _U2>(),
                  bool>::type = false>
    explicit constexpr pair(const _T1& __a, const _T2& __b)
        : first(__a), second(__b) {}
    template <typename _U1, typename _U2>
    using _PCCFP =
        _PCC<!is_same<_T1, _U1>::value || !is_same<_T2, _U2>::value, _T1, _T2>;

    template <typename _U1,
              typename _U2,
              typename enable_if<
                  _PCCFP<_U1, _U2>::template _ConstructiblePair<_U1, _U2>() &&
                      _PCCFP<_U1, _U2>::
                          template _ImplicitlyConvertiblePair<_U1, _U2>(),
                  bool>::type = true>
    constexpr pair(const pair<_U1, _U2>& __p)
        : first(__p.first), second(__p.second) {}

    template <typename _U1,
              typename _U2,
              typename enable_if<
                  _PCCFP<_U1, _U2>::template _ConstructiblePair<_U1, _U2>() &&
                      !_PCCFP<_U1, _U2>::
                          template _ImplicitlyConvertiblePair<_U1, _U2>(),
                  bool>::type = false>
    explicit constexpr pair(const pair<_U1, _U2>& __p)
        : first(__p.first), second(__p.second) {}

    constexpr pair(const pair&) = default;
    constexpr pair(pair&&) = default;

    template <
        typename _U1,
        typename enable_if<_PCCP::template _MoveCopyPair<true, _U1, _T2>(),
                           bool>::type = true>
    constexpr pair(_U1&& __x, const _T2& __y)
        : first(std::forward<_U1>(__x)), second(__y) {}

    template <
        typename _U1,
        typename enable_if<_PCCP::template _MoveCopyPair<false, _U1, _T2>(),
                           bool>::type = false>
    explicit constexpr pair(_U1&& __x, const _T2& __y)
        : first(std::forward<_U1>(__x)), second(__y) {}

    template <
        typename _U2,
        typename enable_if<_PCCP::template _CopyMovePair<true, _T1, _U2>(),
                           bool>::type = true>
    constexpr pair(const _T1& __x, _U2&& __y)
        : first(__x), second(std::forward<_U2>(__y)) {}

    template <
        typename _U2,
        typename enable_if<_PCCP::template _CopyMovePair<false, _T1, _U2>(),
                           bool>::type = false>
    explicit pair(const _T1& __x, _U2&& __y)
        : first(__x), second(std::forward<_U2>(__y)) {}

    template <
        typename _U1,
        typename _U2,
        typename enable_if<
            _PCCP::template _MoveConstructiblePair<_U1, _U2>() &&
                _PCCP::template _ImplicitlyMoveConvertiblePair<_U1, _U2>(),
            bool>::type = true>
    constexpr pair(_U1&& __x, _U2&& __y)
        : first(std::forward<_U1>(__x)), second(std::forward<_U2>(__y)) {}

    template <
        typename _U1,
        typename _U2,
        typename enable_if<
            _PCCP::template _MoveConstructiblePair<_U1, _U2>() &&
                !_PCCP::template _ImplicitlyMoveConvertiblePair<_U1, _U2>(),
            bool>::type = false>
    explicit constexpr pair(_U1&& __x, _U2&& __y)
        : first(std::forward<_U1>(__x)), second(std::forward<_U2>(__y)) {}

    template <
        typename _U1,
        typename _U2,
        typename enable_if<
            _PCCFP<_U1, _U2>::template _MoveConstructiblePair<_U1, _U2>() &&
                _PCCFP<_U1, _U2>::
                    template _ImplicitlyMoveConvertiblePair<_U1, _U2>(),
            bool>::type = true>
    constexpr pair(pair<_U1, _U2>&& __p)
        : first(std::forward<_U1>(__p.first)),
          second(std::forward<_U2>(__p.second)) {}

    template <
        typename _U1,
        typename _U2,
        typename enable_if<
            _PCCFP<_U1, _U2>::template _MoveConstructiblePair<_U1, _U2>() &&
                !_PCCFP<_U1, _U2>::
                    template _ImplicitlyMoveConvertiblePair<_U1, _U2>(),
            bool>::type = false>
    explicit constexpr pair(pair<_U1, _U2>&& __p)
        : first(std::forward<_U1>(__p.first)),
          second(std::forward<_U2>(__p.second)) {}

    template <typename... _Args1, typename... _Args2>
    pair(piecewise_construct_t, tuple<_Args1...>, tuple<_Args2...>);

    pair& operator=(
        typename conditional<
            __and_<is_copy_assignable<_T1>, is_copy_assignable<_T2>>::value,
            const pair&,
            const __nonesuch_no_braces&>::type __p) {
      first = __p.first;
      second = __p.second;
      return *this;
    }

    pair& operator=(
        typename conditional<__not_<__and_<is_copy_assignable<_T1>,
                                           is_copy_assignable<_T2>>>::value,
                             const pair&,
                             const __nonesuch_no_braces&>::type __p) = delete;

    pair& operator=(
        typename conditional<
            __and_<is_move_assignable<_T1>, is_move_assignable<_T2>>::value,
            pair&&,
            __nonesuch_no_braces&&>::type
            __p) noexcept(__and_<is_nothrow_move_assignable<_T1>,
                                 is_nothrow_move_assignable<_T2>>::value) {
      first = std::forward<first_type>(__p.first);
      second = std::forward<second_type>(__p.second);
      return *this;
    }

    template <typename _U1, typename _U2>
    typename enable_if<__and_<is_assignable<_T1&, const _U1&>,
                              is_assignable<_T2&, const _U2&>>::value,
                       pair&>::type
    operator=(const pair<_U1, _U2>& __p) {
      first = __p.first;
      second = __p.second;
      return *this;
    }

    template <typename _U1, typename _U2>
    typename enable_if<
        __and_<is_assignable<_T1&, _U1&&>, is_assignable<_T2&, _U2&&>>::value,
        pair&>::type
    operator=(pair<_U1, _U2>&& __p) {
      first = std::forward<_U1>(__p.first);
      second = std::forward<_U2>(__p.second);
      return *this;
    }

    void swap(pair& __p) noexcept(__and_<__is_nothrow_swappable<_T1>,
                                         __is_nothrow_swappable<_T2>>::value) {
      using std::swap;
      swap(first, __p.first);
      swap(second, __p.second);
    }

   private:
    template <typename... _Args1,
              std::size_t... _Indexes1,
              typename... _Args2,
              std::size_t... _Indexes2>
    pair(tuple<_Args1...>&,
         tuple<_Args2...>&,
         _Index_tuple<_Indexes1...>,
         _Index_tuple<_Indexes2...>);
  };

  template <typename _T1, typename _T2>
  inline constexpr bool operator==(const pair<_T1, _T2>& __x,
                                   const pair<_T1, _T2>& __y) {
    return __x.first == __y.first && __x.second == __y.second;
  }

  template <typename _T1, typename _T2>
  inline constexpr bool operator<(const pair<_T1, _T2>& __x,
                                  const pair<_T1, _T2>& __y) {
    return __x.first < __y.first ||
           (!(__y.first < __x.first) && __x.second < __y.second);
  }

  template <typename _T1, typename _T2>
  inline constexpr bool operator!=(const pair<_T1, _T2>& __x,
                                   const pair<_T1, _T2>& __y) {
    return !(__x == __y);
  }

  template <typename _T1, typename _T2>
  inline constexpr bool operator>(const pair<_T1, _T2>& __x,
                                  const pair<_T1, _T2>& __y) {
    return __y < __x;
  }

  template <typename _T1, typename _T2>
  inline constexpr bool operator<=(const pair<_T1, _T2>& __x,
                                   const pair<_T1, _T2>& __y) {
    return !(__y < __x);
  }

  template <typename _T1, typename _T2>
  inline constexpr bool operator>=(const pair<_T1, _T2>& __x,
                                   const pair<_T1, _T2>& __y) {
    return !(__x < __y);
  }

  template <typename _T1, typename _T2>
  inline

      typename enable_if<
          __and_<__is_swappable<_T1>, __is_swappable<_T2>>::value>::type

      swap(pair<_T1, _T2> & __x,
           pair<_T1, _T2> & __y) noexcept(noexcept(__x.swap(__y))) {
    __x.swap(__y);
  }

  template <typename _T1, typename _T2>
  typename enable_if<
      !__and_<__is_swappable<_T1>, __is_swappable<_T2>>::value>::type
  swap(pair<_T1, _T2>&, pair<_T1, _T2>&) = delete;
  template <typename _T1, typename _T2>
  constexpr pair<typename __decay_and_strip<_T1>::__type,
                 typename __decay_and_strip<_T2>::__type>
  make_pair(_T1 && __x, _T2 && __y) {
    typedef typename __decay_and_strip<_T1>::__type __ds_type1;
    typedef typename __decay_and_strip<_T2>::__type __ds_type2;
    typedef pair<__ds_type1, __ds_type2> __pair_type;
    return __pair_type(std::forward<_T1>(__x), std::forward<_T2>(__y));
  }

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <typename>
  struct _List_iterator;
  template <typename>
  struct _List_const_iterator;

  template <typename _InputIterator>
  inline constexpr typename iterator_traits<_InputIterator>::difference_type
  __distance(_InputIterator __first, _InputIterator __last,
             input_iterator_tag) {
    typename iterator_traits<_InputIterator>::difference_type __n = 0;
    while (__first != __last) {
      ++__first;
      ++__n;
    }
    return __n;
  }

  template <typename _RandomAccessIterator>
  inline constexpr
      typename iterator_traits<_RandomAccessIterator>::difference_type
      __distance(_RandomAccessIterator __first, _RandomAccessIterator __last,
                 random_access_iterator_tag) {
    return __last - __first;
  }

  template <typename _Tp>
  ptrdiff_t __distance(std::_List_iterator<_Tp>, std::_List_iterator<_Tp>,
                       input_iterator_tag);

  template <typename _Tp>
  ptrdiff_t __distance(std::_List_const_iterator<_Tp>,
                       std::_List_const_iterator<_Tp>, input_iterator_tag);
  template <typename _InputIterator>
  inline typename iterator_traits<_InputIterator>::difference_type distance(
      _InputIterator __first, _InputIterator __last) {
    return std::__distance(__first, __last, std::__iterator_category(__first));
  }

  template <typename _InputIterator, typename _Distance>
  inline constexpr void __advance(_InputIterator & __i, _Distance __n,
                                  input_iterator_tag) {
    ;
    while (__n--)
      ++__i;
  }

  template <typename _BidirectionalIterator, typename _Distance>
  inline constexpr void __advance(_BidirectionalIterator & __i, _Distance __n,
                                  bidirectional_iterator_tag) {
    if (__n > 0)
      while (__n--)
        ++__i;
    else
      while (__n++)
        --__i;
  }

  template <typename _RandomAccessIterator, typename _Distance>
  inline constexpr void __advance(_RandomAccessIterator & __i, _Distance __n,
                                  random_access_iterator_tag) {
    __i += __n;
  }
  template <typename _InputIterator, typename _Distance>
  inline void advance(_InputIterator & __i, _Distance __n) {
    typename iterator_traits<_InputIterator>::difference_type __d = __n;
    std::__advance(__i, __d, std::__iterator_category(__i));
  }

  template <typename _ForwardIterator>
  inline _ForwardIterator next(
      _ForwardIterator __x,
      typename iterator_traits<_ForwardIterator>::difference_type __n = 1) {
    std::advance(__x, __n);
    return __x;
  }

  template <typename _BidirectionalIterator>
  inline _BidirectionalIterator prev(
      _BidirectionalIterator __x,
      typename iterator_traits<_BidirectionalIterator>::difference_type __n =
          1) {
    std::advance(__x, -__n);
    return __x;
  }

}  // namespace std__attribute__((__visibility__("default")))
namespace std __attribute__((__visibility__("default"))) {

  class __undefined;

  template <typename _Tp>
  struct __get_first_arg {
    using type = __undefined;
  };

  template <template <typename, typename...> class _Template, typename _Tp,
            typename... _Types>
  struct __get_first_arg<_Template<_Tp, _Types...>> {
    using type = _Tp;
  };

  template <typename _Tp>
  using __get_first_arg_t = typename __get_first_arg<_Tp>::type;

  template <typename _Tp, typename _Up>
  struct __replace_first_arg {};

  template <template <typename, typename...> class _Template, typename _Up,
            typename _Tp, typename... _Types>
  struct __replace_first_arg<_Template<_Tp, _Types...>, _Up> {
    using type = _Template<_Up, _Types...>;
  };

  template <typename _Tp, typename _Up>
  using __replace_first_arg_t = typename __replace_first_arg<_Tp, _Up>::type;

  template <typename _Tp>
  using __make_not_void =
      typename conditional<is_void<_Tp>::value, __undefined, _Tp>::type;

  template <typename _Ptr>
  struct pointer_traits {
   private:
    template <typename _Tp>
    using __element_type = typename _Tp::element_type;

    template <typename _Tp>
    using __difference_type = typename _Tp::difference_type;

    template <typename _Tp, typename _Up, typename = void>
    struct __rebind : __replace_first_arg<_Tp, _Up> {};

    template <typename _Tp, typename _Up>
    struct __rebind<_Tp, _Up, __void_t<typename _Tp::template rebind<_Up>>> {
      using type = typename _Tp::template rebind<_Up>;
    };

   public:
    using pointer = _Ptr;

    using element_type =
        __detected_or_t<__get_first_arg_t<_Ptr>, __element_type, _Ptr>;

    using difference_type = __detected_or_t<ptrdiff_t, __difference_type, _Ptr>;

    template <typename _Up>
    using rebind = typename __rebind<_Ptr, _Up>::type;

    static _Ptr pointer_to(__make_not_void<element_type>& __e) {
      return _Ptr::pointer_to(__e);
    }

    static_assert(
        !is_same<element_type, __undefined>::value,
        "pointer type defines element_type or is like SomePointer<T, Args>");
  };

  template <typename _Tp>
  struct pointer_traits<_Tp*> {
    typedef _Tp* pointer;

    typedef _Tp element_type;

    typedef ptrdiff_t difference_type;

    template <typename _Up>
    using rebind = _Up*;

    static pointer pointer_to(__make_not_void<element_type>& __r) noexcept {
      return std::addressof(__r);
    }
  };

  template <typename _Ptr, typename _Tp>
  using __ptr_rebind = typename pointer_traits<_Ptr>::template rebind<_Tp>;

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Iterator>
  class reverse_iterator
      : public iterator<typename iterator_traits<_Iterator>::iterator_category,
                        typename iterator_traits<_Iterator>::value_type,
                        typename iterator_traits<_Iterator>::difference_type,
                        typename iterator_traits<_Iterator>::pointer,
                        typename iterator_traits<_Iterator>::reference> {
   protected:
    _Iterator current;

    typedef iterator_traits<_Iterator> __traits_type;

   public:
    typedef _Iterator iterator_type;
    typedef typename __traits_type::difference_type difference_type;
    typedef typename __traits_type::pointer pointer;
    typedef typename __traits_type::reference reference;

    reverse_iterator() : current() {}

    explicit reverse_iterator(iterator_type __x) : current(__x) {}

    reverse_iterator(const reverse_iterator& __x) : current(__x.current) {}

    template <typename _Iter>

    reverse_iterator(const reverse_iterator<_Iter>& __x)
        : current(__x.base()) {}

    iterator_type base() const { return current; }
    reference operator*() const {
      _Iterator __tmp = current;
      return *--__tmp;
    }

    pointer operator->() const { return &(operator*()); }

    reverse_iterator& operator++() {
      --current;
      return *this;
    }

    reverse_iterator operator++(int) {
      reverse_iterator __tmp = *this;
      --current;
      return __tmp;
    }

    reverse_iterator& operator--() {
      ++current;
      return *this;
    }

    reverse_iterator operator--(int) {
      reverse_iterator __tmp = *this;
      ++current;
      return __tmp;
    }

    reverse_iterator operator+(difference_type __n) const {
      return reverse_iterator(current - __n);
    }

    reverse_iterator& operator+=(difference_type __n) {
      current -= __n;
      return *this;
    }

    reverse_iterator operator-(difference_type __n) const {
      return reverse_iterator(current + __n);
    }

    reverse_iterator& operator-=(difference_type __n) {
      current += __n;
      return *this;
    }

    reference operator[](difference_type __n) const { return *(*this + __n); }
  };
  template <typename _Iterator>
  inline bool operator==(const reverse_iterator<_Iterator>& __x,
                         const reverse_iterator<_Iterator>& __y) {
    return __x.base() == __y.base();
  }

  template <typename _Iterator>
  inline bool operator<(const reverse_iterator<_Iterator>& __x,
                        const reverse_iterator<_Iterator>& __y) {
    return __y.base() < __x.base();
  }

  template <typename _Iterator>
  inline bool operator!=(const reverse_iterator<_Iterator>& __x,
                         const reverse_iterator<_Iterator>& __y) {
    return !(__x == __y);
  }

  template <typename _Iterator>
  inline bool operator>(const reverse_iterator<_Iterator>& __x,
                        const reverse_iterator<_Iterator>& __y) {
    return __y < __x;
  }

  template <typename _Iterator>
  inline bool operator<=(const reverse_iterator<_Iterator>& __x,
                         const reverse_iterator<_Iterator>& __y) {
    return !(__y < __x);
  }

  template <typename _Iterator>
  inline bool operator>=(const reverse_iterator<_Iterator>& __x,
                         const reverse_iterator<_Iterator>& __y) {
    return !(__x < __y);
  }

  template <typename _IteratorL, typename _IteratorR>
  inline bool operator==(const reverse_iterator<_IteratorL>& __x,
                         const reverse_iterator<_IteratorR>& __y) {
    return __x.base() == __y.base();
  }

  template <typename _IteratorL, typename _IteratorR>
  inline bool operator<(const reverse_iterator<_IteratorL>& __x,
                        const reverse_iterator<_IteratorR>& __y) {
    return __y.base() < __x.base();
  }

  template <typename _IteratorL, typename _IteratorR>
  inline bool operator!=(const reverse_iterator<_IteratorL>& __x,
                         const reverse_iterator<_IteratorR>& __y) {
    return !(__x == __y);
  }

  template <typename _IteratorL, typename _IteratorR>
  inline bool operator>(const reverse_iterator<_IteratorL>& __x,
                        const reverse_iterator<_IteratorR>& __y) {
    return __y < __x;
  }

  template <typename _IteratorL, typename _IteratorR>
  inline bool operator<=(const reverse_iterator<_IteratorL>& __x,
                         const reverse_iterator<_IteratorR>& __y) {
    return !(__y < __x);
  }

  template <typename _IteratorL, typename _IteratorR>
  inline bool operator>=(const reverse_iterator<_IteratorL>& __x,
                         const reverse_iterator<_IteratorR>& __y) {
    return !(__x < __y);
  }
  template <typename _IteratorL, typename _IteratorR>
  inline auto operator-(const reverse_iterator<_IteratorL>& __x,
                        const reverse_iterator<_IteratorR>& __y)
      ->decltype(__y.base() - __x.base()) {
    return __y.base() - __x.base();
  }

  template <typename _Iterator>
  inline reverse_iterator<_Iterator> operator+(
      typename reverse_iterator<_Iterator>::difference_type __n,
      const reverse_iterator<_Iterator>& __x) {
    return reverse_iterator<_Iterator>(__x.base() - __n);
  }

  template <typename _Iterator>
  inline reverse_iterator<_Iterator> __make_reverse_iterator(_Iterator __i) {
    return reverse_iterator<_Iterator>(__i);
  }

  template <typename _Iterator>
  inline reverse_iterator<_Iterator> make_reverse_iterator(_Iterator __i) {
    return reverse_iterator<_Iterator>(__i);
  }

  template <typename _Iterator>
  auto __niter_base(reverse_iterator<_Iterator> __it)
      ->decltype(__make_reverse_iterator(__niter_base(__it.base()))) {
    return __make_reverse_iterator(__niter_base(__it.base()));
  }

  template <typename _Iterator>
  struct __is_move_iterator<reverse_iterator<_Iterator>>
      : __is_move_iterator<_Iterator> {};

  template <typename _Iterator>
  auto __miter_base(reverse_iterator<_Iterator> __it)
      ->decltype(__make_reverse_iterator(__miter_base(__it.base()))) {
    return __make_reverse_iterator(__miter_base(__it.base()));
  }
  template <typename _Container>
  class back_insert_iterator
      : public iterator<output_iterator_tag, void, void, void, void> {
   protected:
    _Container* container;

   public:
    typedef _Container container_type;

    explicit back_insert_iterator(_Container& __x)
        : container(std::__addressof(__x)) {}
    back_insert_iterator& operator=(
        const typename _Container::value_type& __value) {
      container->push_back(__value);
      return *this;
    }

    back_insert_iterator& operator=(typename _Container::value_type&& __value) {
      container->push_back(std::move(__value));
      return *this;
    }

    back_insert_iterator& operator*() { return *this; }

    back_insert_iterator& operator++() { return *this; }

    back_insert_iterator operator++(int) { return *this; }
  };
  template <typename _Container>
  inline back_insert_iterator<_Container> back_inserter(_Container & __x) {
    return back_insert_iterator<_Container>(__x);
  }
  template <typename _Container>
  class front_insert_iterator
      : public iterator<output_iterator_tag, void, void, void, void> {
   protected:
    _Container* container;

   public:
    typedef _Container container_type;

    explicit front_insert_iterator(_Container& __x)
        : container(std::__addressof(__x)) {}
    front_insert_iterator& operator=(
        const typename _Container::value_type& __value) {
      container->push_front(__value);
      return *this;
    }

    front_insert_iterator& operator=(
        typename _Container::value_type&& __value) {
      container->push_front(std::move(__value));
      return *this;
    }

    front_insert_iterator& operator*() { return *this; }

    front_insert_iterator& operator++() { return *this; }

    front_insert_iterator operator++(int) { return *this; }
  };
  template <typename _Container>
  inline front_insert_iterator<_Container> front_inserter(_Container & __x) {
    return front_insert_iterator<_Container>(__x);
  }
  template <typename _Container>
  class insert_iterator
      : public iterator<output_iterator_tag, void, void, void, void> {
   protected:
    _Container* container;
    typename _Container::iterator iter;

   public:
    typedef _Container container_type;

    insert_iterator(_Container& __x, typename _Container::iterator __i)
        : container(std::__addressof(__x)), iter(__i) {}
    insert_iterator& operator=(const typename _Container::value_type& __value) {
      iter = container->insert(iter, __value);
      ++iter;
      return *this;
    }

    insert_iterator& operator=(typename _Container::value_type&& __value) {
      iter = container->insert(iter, std::move(__value));
      ++iter;
      return *this;
    }

    insert_iterator& operator*() { return *this; }

    insert_iterator& operator++() { return *this; }

    insert_iterator& operator++(int) { return *this; }
  };
  template <typename _Container, typename _Iterator>
  inline insert_iterator<_Container> inserter(_Container & __x, _Iterator __i) {
    return insert_iterator<_Container>(__x, typename _Container::iterator(__i));
  }

}  // namespace std__attribute__((__visibility__("default")))

namespace __gnu_cxx __attribute__((__visibility__("default"))) {

  using std::iterator;
  using std::iterator_traits;
  template <typename _Iterator, typename _Container>
  class __normal_iterator {
   protected:
    _Iterator _M_current;

    typedef iterator_traits<_Iterator> __traits_type;

   public:
    typedef _Iterator iterator_type;
    typedef typename __traits_type::iterator_category iterator_category;
    typedef typename __traits_type::value_type value_type;
    typedef typename __traits_type::difference_type difference_type;
    typedef typename __traits_type::reference reference;
    typedef typename __traits_type::pointer pointer;

    constexpr __normal_iterator() noexcept : _M_current(_Iterator()) {}

    explicit __normal_iterator(const _Iterator& __i) noexcept
        : _M_current(__i) {}

    template <typename _Iter>
    __normal_iterator(
        const __normal_iterator<
            _Iter,
            typename __enable_if<
                (std::__are_same<_Iter, typename _Container::pointer>::__value),
                _Container>::__type>& __i) noexcept
        : _M_current(__i.base()) {}

    reference operator*() const noexcept { return *_M_current; }

    pointer operator->() const noexcept { return _M_current; }

    __normal_iterator& operator++() noexcept {
      ++_M_current;
      return *this;
    }

    __normal_iterator operator++(int)noexcept {
      return __normal_iterator(_M_current++);
    }

    __normal_iterator& operator--() noexcept {
      --_M_current;
      return *this;
    }

    __normal_iterator operator--(int)noexcept {
      return __normal_iterator(_M_current--);
    }

    reference operator[](difference_type __n) const noexcept {
      return _M_current[__n];
    }

    __normal_iterator& operator+=(difference_type __n) noexcept {
      _M_current += __n;
      return *this;
    }

    __normal_iterator operator+(difference_type __n) const noexcept {
      return __normal_iterator(_M_current + __n);
    }

    __normal_iterator& operator-=(difference_type __n) noexcept {
      _M_current -= __n;
      return *this;
    }

    __normal_iterator operator-(difference_type __n) const noexcept {
      return __normal_iterator(_M_current - __n);
    }

    const _Iterator& base() const noexcept { return _M_current; }
  };
  template <typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool operator==(
      const __normal_iterator<_IteratorL, _Container>& __lhs,
      const __normal_iterator<_IteratorR, _Container>& __rhs) noexcept {
    return __lhs.base() == __rhs.base();
  }

  template <typename _Iterator, typename _Container>
  inline bool operator==(
      const __normal_iterator<_Iterator, _Container>& __lhs,
      const __normal_iterator<_Iterator, _Container>& __rhs) noexcept {
    return __lhs.base() == __rhs.base();
  }

  template <typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool operator!=(
      const __normal_iterator<_IteratorL, _Container>& __lhs,
      const __normal_iterator<_IteratorR, _Container>& __rhs) noexcept {
    return __lhs.base() != __rhs.base();
  }

  template <typename _Iterator, typename _Container>
  inline bool operator!=(
      const __normal_iterator<_Iterator, _Container>& __lhs,
      const __normal_iterator<_Iterator, _Container>& __rhs) noexcept {
    return __lhs.base() != __rhs.base();
  }

  template <typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool operator<(
      const __normal_iterator<_IteratorL, _Container>& __lhs,
      const __normal_iterator<_IteratorR, _Container>& __rhs) noexcept {
    return __lhs.base() < __rhs.base();
  }

  template <typename _Iterator, typename _Container>
  inline bool operator<(
      const __normal_iterator<_Iterator, _Container>& __lhs,
      const __normal_iterator<_Iterator, _Container>& __rhs) noexcept {
    return __lhs.base() < __rhs.base();
  }

  template <typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool operator>(
      const __normal_iterator<_IteratorL, _Container>& __lhs,
      const __normal_iterator<_IteratorR, _Container>& __rhs) noexcept {
    return __lhs.base() > __rhs.base();
  }

  template <typename _Iterator, typename _Container>
  inline bool operator>(
      const __normal_iterator<_Iterator, _Container>& __lhs,
      const __normal_iterator<_Iterator, _Container>& __rhs) noexcept {
    return __lhs.base() > __rhs.base();
  }

  template <typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool operator<=(
      const __normal_iterator<_IteratorL, _Container>& __lhs,
      const __normal_iterator<_IteratorR, _Container>& __rhs) noexcept {
    return __lhs.base() <= __rhs.base();
  }

  template <typename _Iterator, typename _Container>
  inline bool operator<=(
      const __normal_iterator<_Iterator, _Container>& __lhs,
      const __normal_iterator<_Iterator, _Container>& __rhs) noexcept {
    return __lhs.base() <= __rhs.base();
  }

  template <typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool operator>=(
      const __normal_iterator<_IteratorL, _Container>& __lhs,
      const __normal_iterator<_IteratorR, _Container>& __rhs) noexcept {
    return __lhs.base() >= __rhs.base();
  }

  template <typename _Iterator, typename _Container>
  inline bool operator>=(
      const __normal_iterator<_Iterator, _Container>& __lhs,
      const __normal_iterator<_Iterator, _Container>& __rhs) noexcept {
    return __lhs.base() >= __rhs.base();
  }

  template <typename _IteratorL, typename _IteratorR, typename _Container>

  inline auto operator-(
      const __normal_iterator<_IteratorL, _Container>& __lhs,
      const __normal_iterator<_IteratorR, _Container>& __rhs) noexcept
      ->decltype(__lhs.base() - __rhs.base())

  {
    return __lhs.base() - __rhs.base();
  }

  template <typename _Iterator, typename _Container>
  inline typename __normal_iterator<_Iterator, _Container>::difference_type
  operator-(const __normal_iterator<_Iterator, _Container>& __lhs,
            const __normal_iterator<_Iterator, _Container>& __rhs) noexcept {
    return __lhs.base() - __rhs.base();
  }

  template <typename _Iterator, typename _Container>
  inline __normal_iterator<_Iterator, _Container> operator+(
      typename __normal_iterator<_Iterator, _Container>::difference_type __n,
      const __normal_iterator<_Iterator, _Container>& __i) noexcept {
    return __normal_iterator<_Iterator, _Container>(__i.base() + __n);
  }

}  // namespace __gnu_cxx__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Iterator, typename _Container>
  _Iterator __niter_base(
      __gnu_cxx::__normal_iterator<_Iterator, _Container> __it) {
    return __it.base();
  }

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Iterator>
  class move_iterator {
   protected:
    _Iterator _M_current;

    typedef iterator_traits<_Iterator> __traits_type;
    typedef typename __traits_type::reference __base_ref;

   public:
    typedef _Iterator iterator_type;
    typedef typename __traits_type::iterator_category iterator_category;
    typedef typename __traits_type::value_type value_type;
    typedef typename __traits_type::difference_type difference_type;

    typedef _Iterator pointer;

    typedef typename conditional<is_reference<__base_ref>::value,
                                 typename remove_reference<__base_ref>::type&&,
                                 __base_ref>::type reference;

    move_iterator() : _M_current() {}

    explicit move_iterator(iterator_type __i) : _M_current(__i) {}

    template <typename _Iter>

    move_iterator(const move_iterator<_Iter>& __i) : _M_current(__i.base()) {}

    iterator_type base() const { return _M_current; }

    reference operator*() const { return static_cast<reference>(*_M_current); }

    pointer operator->() const { return _M_current; }

    move_iterator& operator++() {
      ++_M_current;
      return *this;
    }

    move_iterator operator++(int) {
      move_iterator __tmp = *this;
      ++_M_current;
      return __tmp;
    }

    move_iterator& operator--() {
      --_M_current;
      return *this;
    }

    move_iterator operator--(int) {
      move_iterator __tmp = *this;
      --_M_current;
      return __tmp;
    }

    move_iterator operator+(difference_type __n) const {
      return move_iterator(_M_current + __n);
    }

    move_iterator& operator+=(difference_type __n) {
      _M_current += __n;
      return *this;
    }

    move_iterator operator-(difference_type __n) const {
      return move_iterator(_M_current - __n);
    }

    move_iterator& operator-=(difference_type __n) {
      _M_current -= __n;
      return *this;
    }

    reference operator[](difference_type __n) const {
      return std::move(_M_current[__n]);
    }
  };

  template <typename _IteratorL, typename _IteratorR>
  inline bool operator==(const move_iterator<_IteratorL>& __x,
                         const move_iterator<_IteratorR>& __y) {
    return __x.base() == __y.base();
  }

  template <typename _Iterator>
  inline bool operator==(const move_iterator<_Iterator>& __x,
                         const move_iterator<_Iterator>& __y) {
    return __x.base() == __y.base();
  }

  template <typename _IteratorL, typename _IteratorR>
  inline bool operator!=(const move_iterator<_IteratorL>& __x,
                         const move_iterator<_IteratorR>& __y) {
    return !(__x == __y);
  }

  template <typename _Iterator>
  inline bool operator!=(const move_iterator<_Iterator>& __x,
                         const move_iterator<_Iterator>& __y) {
    return !(__x == __y);
  }

  template <typename _IteratorL, typename _IteratorR>
  inline bool operator<(const move_iterator<_IteratorL>& __x,
                        const move_iterator<_IteratorR>& __y) {
    return __x.base() < __y.base();
  }

  template <typename _Iterator>
  inline bool operator<(const move_iterator<_Iterator>& __x,
                        const move_iterator<_Iterator>& __y) {
    return __x.base() < __y.base();
  }

  template <typename _IteratorL, typename _IteratorR>
  inline bool operator<=(const move_iterator<_IteratorL>& __x,
                         const move_iterator<_IteratorR>& __y) {
    return !(__y < __x);
  }

  template <typename _Iterator>
  inline bool operator<=(const move_iterator<_Iterator>& __x,
                         const move_iterator<_Iterator>& __y) {
    return !(__y < __x);
  }

  template <typename _IteratorL, typename _IteratorR>
  inline bool operator>(const move_iterator<_IteratorL>& __x,
                        const move_iterator<_IteratorR>& __y) {
    return __y < __x;
  }

  template <typename _Iterator>
  inline bool operator>(const move_iterator<_Iterator>& __x,
                        const move_iterator<_Iterator>& __y) {
    return __y < __x;
  }

  template <typename _IteratorL, typename _IteratorR>
  inline bool operator>=(const move_iterator<_IteratorL>& __x,
                         const move_iterator<_IteratorR>& __y) {
    return !(__x < __y);
  }

  template <typename _Iterator>
  inline bool operator>=(const move_iterator<_Iterator>& __x,
                         const move_iterator<_Iterator>& __y) {
    return !(__x < __y);
  }

  template <typename _IteratorL, typename _IteratorR>
  inline auto operator-(const move_iterator<_IteratorL>& __x,
                        const move_iterator<_IteratorR>& __y)
      ->decltype(__x.base() - __y.base()) {
    return __x.base() - __y.base();
  }

  template <typename _Iterator>
  inline move_iterator<_Iterator> operator+(
      typename move_iterator<_Iterator>::difference_type __n,
      const move_iterator<_Iterator>& __x) {
    return __x + __n;
  }

  template <typename _Iterator>
  inline move_iterator<_Iterator> make_move_iterator(_Iterator __i) {
    return move_iterator<_Iterator>(__i);
  }

  template <typename _Iterator,
            typename _ReturnType = typename conditional<
                __move_if_noexcept_cond<
                    typename iterator_traits<_Iterator>::value_type>::value,
                _Iterator, move_iterator<_Iterator>>::type>
  inline _ReturnType __make_move_if_noexcept_iterator(_Iterator __i) {
    return _ReturnType(__i);
  }

  template <typename _Tp,
            typename _ReturnType =
                typename conditional<__move_if_noexcept_cond<_Tp>::value,
                                     const _Tp*, move_iterator<_Tp*>>::type>
  inline _ReturnType __make_move_if_noexcept_iterator(_Tp * __i) {
    return _ReturnType(__i);
  }

  template <typename _Iterator>
  auto __niter_base(move_iterator<_Iterator> __it)
      ->decltype(make_move_iterator(__niter_base(__it.base()))) {
    return make_move_iterator(__niter_base(__it.base()));
  }

  template <typename _Iterator>
  struct __is_move_iterator<move_iterator<_Iterator>> {
    enum { __value = 1 };
    typedef __true_type __type;
  };

  template <typename _Iterator>
  auto __miter_base(move_iterator<_Iterator> __it)
      ->decltype(__miter_base(__it.base())) {
    return __miter_base(__it.base());
  }

}  // namespace std__attribute__((__visibility__("default")))

namespace __gnu_cxx {
namespace __ops {
struct _Iter_less_iter {
  template <typename _Iterator1, typename _Iterator2>
  constexpr bool operator()(_Iterator1 __it1, _Iterator2 __it2) const {
    return *__it1 < *__it2;
  }
};

constexpr inline _Iter_less_iter __iter_less_iter() {
  return _Iter_less_iter();
}

struct _Iter_less_val {
  constexpr _Iter_less_val() = default;

  explicit _Iter_less_val(_Iter_less_iter) {}

  template <typename _Iterator, typename _Value>
  bool operator()(_Iterator __it, _Value& __val) const {
    return *__it < __val;
  }
};

inline _Iter_less_val __iter_less_val() {
  return _Iter_less_val();
}

inline _Iter_less_val __iter_comp_val(_Iter_less_iter) {
  return _Iter_less_val();
}

struct _Val_less_iter {
  constexpr _Val_less_iter() = default;

  explicit _Val_less_iter(_Iter_less_iter) {}

  template <typename _Value, typename _Iterator>
  bool operator()(_Value& __val, _Iterator __it) const {
    return __val < *__it;
  }
};

inline _Val_less_iter __val_less_iter() {
  return _Val_less_iter();
}

inline _Val_less_iter __val_comp_iter(_Iter_less_iter) {
  return _Val_less_iter();
}

struct _Iter_equal_to_iter {
  template <typename _Iterator1, typename _Iterator2>
  bool operator()(_Iterator1 __it1, _Iterator2 __it2) const {
    return *__it1 == *__it2;
  }
};

inline _Iter_equal_to_iter __iter_equal_to_iter() {
  return _Iter_equal_to_iter();
}

struct _Iter_equal_to_val {
  template <typename _Iterator, typename _Value>
  bool operator()(_Iterator __it, _Value& __val) const {
    return *__it == __val;
  }
};

inline _Iter_equal_to_val __iter_equal_to_val() {
  return _Iter_equal_to_val();
}

inline _Iter_equal_to_val __iter_comp_val(_Iter_equal_to_iter) {
  return _Iter_equal_to_val();
}

template <typename _Compare>
struct _Iter_comp_iter {
  _Compare _M_comp;

  explicit constexpr _Iter_comp_iter(_Compare __comp)
      : _M_comp(std::move(__comp)) {}

  template <typename _Iterator1, typename _Iterator2>
  constexpr bool operator()(_Iterator1 __it1, _Iterator2 __it2) {
    return bool(_M_comp(*__it1, *__it2));
  }
};

template <typename _Compare>
constexpr inline _Iter_comp_iter<_Compare> __iter_comp_iter(_Compare __comp) {
  return _Iter_comp_iter<_Compare>(std::move(__comp));
}

template <typename _Compare>
struct _Iter_comp_val {
  _Compare _M_comp;

  explicit _Iter_comp_val(_Compare __comp) : _M_comp(std::move(__comp)) {}

  explicit _Iter_comp_val(const _Iter_comp_iter<_Compare>& __comp)
      : _M_comp(__comp._M_comp) {}

  explicit _Iter_comp_val(_Iter_comp_iter<_Compare>&& __comp)
      : _M_comp(std::move(__comp._M_comp)) {}

  template <typename _Iterator, typename _Value>
  bool operator()(_Iterator __it, _Value& __val) {
    return bool(_M_comp(*__it, __val));
  }
};

template <typename _Compare>
inline _Iter_comp_val<_Compare> __iter_comp_val(_Compare __comp) {
  return _Iter_comp_val<_Compare>(std::move(__comp));
}

template <typename _Compare>
inline _Iter_comp_val<_Compare> __iter_comp_val(
    _Iter_comp_iter<_Compare> __comp) {
  return _Iter_comp_val<_Compare>(std::move(__comp));
}

template <typename _Compare>
struct _Val_comp_iter {
  _Compare _M_comp;

  explicit _Val_comp_iter(_Compare __comp) : _M_comp(std::move(__comp)) {}

  explicit _Val_comp_iter(const _Iter_comp_iter<_Compare>& __comp)
      : _M_comp(__comp._M_comp) {}

  explicit _Val_comp_iter(_Iter_comp_iter<_Compare>&& __comp)
      : _M_comp(std::move(__comp._M_comp)) {}

  template <typename _Value, typename _Iterator>
  bool operator()(_Value& __val, _Iterator __it) {
    return bool(_M_comp(__val, *__it));
  }
};

template <typename _Compare>
inline _Val_comp_iter<_Compare> __val_comp_iter(_Compare __comp) {
  return _Val_comp_iter<_Compare>(std::move(__comp));
}

template <typename _Compare>
inline _Val_comp_iter<_Compare> __val_comp_iter(
    _Iter_comp_iter<_Compare> __comp) {
  return _Val_comp_iter<_Compare>(std::move(__comp));
}

template <typename _Value>
struct _Iter_equals_val {
  _Value& _M_value;

  explicit _Iter_equals_val(_Value& __value) : _M_value(__value) {}

  template <typename _Iterator>
  bool operator()(_Iterator __it) {
    return *__it == _M_value;
  }
};

template <typename _Value>
inline _Iter_equals_val<_Value> __iter_equals_val(_Value& __val) {
  return _Iter_equals_val<_Value>(__val);
}

template <typename _Iterator1>
struct _Iter_equals_iter {
  _Iterator1 _M_it1;

  explicit _Iter_equals_iter(_Iterator1 __it1) : _M_it1(__it1) {}

  template <typename _Iterator2>
  bool operator()(_Iterator2 __it2) {
    return *__it2 == *_M_it1;
  }
};

template <typename _Iterator>
inline _Iter_equals_iter<_Iterator> __iter_comp_iter(_Iter_equal_to_iter,
                                                     _Iterator __it) {
  return _Iter_equals_iter<_Iterator>(__it);
}

template <typename _Predicate>
struct _Iter_pred {
  _Predicate _M_pred;

  explicit _Iter_pred(_Predicate __pred) : _M_pred(std::move(__pred)) {}

  template <typename _Iterator>
  bool operator()(_Iterator __it) {
    return bool(_M_pred(*__it));
  }
};

template <typename _Predicate>
inline _Iter_pred<_Predicate> __pred_iter(_Predicate __pred) {
  return _Iter_pred<_Predicate>(std::move(__pred));
}

template <typename _Compare, typename _Value>
struct _Iter_comp_to_val {
  _Compare _M_comp;
  _Value& _M_value;

  _Iter_comp_to_val(_Compare __comp, _Value& __value)
      : _M_comp(std::move(__comp)), _M_value(__value) {}

  template <typename _Iterator>
  bool operator()(_Iterator __it) {
    return bool(_M_comp(*__it, _M_value));
  }
};

template <typename _Compare, typename _Value>
_Iter_comp_to_val<_Compare, _Value> __iter_comp_val(_Compare __comp,
                                                    _Value& __val) {
  return _Iter_comp_to_val<_Compare, _Value>(std::move(__comp), __val);
}

template <typename _Compare, typename _Iterator1>
struct _Iter_comp_to_iter {
  _Compare _M_comp;
  _Iterator1 _M_it1;

  _Iter_comp_to_iter(_Compare __comp, _Iterator1 __it1)
      : _M_comp(std::move(__comp)), _M_it1(__it1) {}

  template <typename _Iterator2>
  bool operator()(_Iterator2 __it2) {
    return bool(_M_comp(*__it2, *_M_it1));
  }
};

template <typename _Compare, typename _Iterator>
inline _Iter_comp_to_iter<_Compare, _Iterator> __iter_comp_iter(
    _Iter_comp_iter<_Compare> __comp,
    _Iterator __it) {
  return _Iter_comp_to_iter<_Compare, _Iterator>(std::move(__comp._M_comp),
                                                 __it);
}

template <typename _Predicate>
struct _Iter_negate {
  _Predicate _M_pred;

  explicit _Iter_negate(_Predicate __pred) : _M_pred(std::move(__pred)) {}

  template <typename _Iterator>
  bool operator()(_Iterator __it) {
    return !bool(_M_pred(*__it));
  }
};

template <typename _Predicate>
inline _Iter_negate<_Predicate> __negate(_Iter_pred<_Predicate> __pred) {
  return _Iter_negate<_Predicate>(std::move(__pred._M_pred));
}

}  // namespace __ops
}  // namespace __gnu_cxx

namespace std __attribute__((__visibility__("default"))) {

  template <typename _ForwardIterator1, typename _ForwardIterator2>
  inline void iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b) {
    swap(*__a, *__b);
  }
  template <typename _ForwardIterator1, typename _ForwardIterator2>
  _ForwardIterator2 swap_ranges(_ForwardIterator1 __first1,
                                _ForwardIterator1 __last1,
                                _ForwardIterator2 __first2) {
    ;

    for (; __first1 != __last1; ++__first1, (void)++__first2)
      std::iter_swap(__first1, __first2);
    return __first2;
  }
  template <typename _Tp>
  constexpr inline const _Tp& min(const _Tp& __a, const _Tp& __b) {
    if (__b < __a)
      return __b;
    return __a;
  }
  template <typename _Tp>
  constexpr inline const _Tp& max(const _Tp& __a, const _Tp& __b) {
    if (__a < __b)
      return __b;
    return __a;
  }
  template <typename _Tp, typename _Compare>
  constexpr inline const _Tp& min(const _Tp& __a, const _Tp& __b,
                                  _Compare __comp) {
    if (__comp(__b, __a))
      return __b;
    return __a;
  }
  template <typename _Tp, typename _Compare>
  constexpr inline const _Tp& max(const _Tp& __a, const _Tp& __b,
                                  _Compare __comp) {
    if (__comp(__a, __b))
      return __b;
    return __a;
  }

  template <typename _Iterator>
  inline _Iterator __niter_base(_Iterator __it) {
    return __it;
  }

  template <bool, bool, typename>
  struct __copy_move {
    template <typename _II, typename _OI>
    static _OI __copy_m(_II __first, _II __last, _OI __result) {
      for (; __first != __last; ++__result, (void)++__first)
        *__result = *__first;
      return __result;
    }
  };

  template <typename _Category>
  struct __copy_move<true, false, _Category> {
    template <typename _II, typename _OI>
    static _OI __copy_m(_II __first, _II __last, _OI __result) {
      for (; __first != __last; ++__result, (void)++__first)
        *__result = std::move(*__first);
      return __result;
    }
  };

  template <>
  struct __copy_move<false, false, random_access_iterator_tag> {
    template <typename _II, typename _OI>
    static _OI __copy_m(_II __first, _II __last, _OI __result) {
      typedef typename iterator_traits<_II>::difference_type _Distance;
      for (_Distance __n = __last - __first; __n > 0; --__n) {
        *__result = *__first;
        ++__first;
        ++__result;
      }
      return __result;
    }
  };

  template <>
  struct __copy_move<true, false, random_access_iterator_tag> {
    template <typename _II, typename _OI>
    static _OI __copy_m(_II __first, _II __last, _OI __result) {
      typedef typename iterator_traits<_II>::difference_type _Distance;
      for (_Distance __n = __last - __first; __n > 0; --__n) {
        *__result = std::move(*__first);
        ++__first;
        ++__result;
      }
      return __result;
    }
  };

  template <bool _IsMove>
  struct __copy_move<_IsMove, true, random_access_iterator_tag> {
    template <typename _Tp>
    static _Tp* __copy_m(const _Tp* __first, const _Tp* __last, _Tp* __result) {
      using __assignable = conditional<_IsMove, is_move_assignable<_Tp>,
                                       is_copy_assignable<_Tp>>;

      static_assert(__assignable::type::value, "type is not assignable");

      const ptrdiff_t _Num = __last - __first;
      if (_Num)
        __builtin_memmove(__result, __first, sizeof(_Tp) * _Num);
      return __result + _Num;
    }
  };

  template <bool _IsMove, typename _II, typename _OI>
  inline _OI __copy_move_a(_II __first, _II __last, _OI __result) {
    typedef typename iterator_traits<_II>::value_type _ValueTypeI;
    typedef typename iterator_traits<_OI>::value_type _ValueTypeO;
    typedef typename iterator_traits<_II>::iterator_category _Category;
    const bool __simple =
        (__is_trivial(_ValueTypeI) && __is_pointer<_II>::__value &&
         __is_pointer<_OI>::__value &&
         __are_same<_ValueTypeI, _ValueTypeO>::__value);

    return std::__copy_move<_IsMove, __simple, _Category>::__copy_m(
        __first, __last, __result);
  }

  template <typename _CharT>
  struct char_traits;

  template <typename _CharT, typename _Traits>
  class istreambuf_iterator;

  template <typename _CharT, typename _Traits>
  class ostreambuf_iterator;

  template <bool _IsMove, typename _CharT>
  typename __gnu_cxx::__enable_if<
      __is_char<_CharT>::__value,
      ostreambuf_iterator<_CharT, char_traits<_CharT>>>::__type
  __copy_move_a2(_CharT*, _CharT*,
                 ostreambuf_iterator<_CharT, char_traits<_CharT>>);

  template <bool _IsMove, typename _CharT>
  typename __gnu_cxx::__enable_if<
      __is_char<_CharT>::__value,
      ostreambuf_iterator<_CharT, char_traits<_CharT>>>::__type
  __copy_move_a2(const _CharT*, const _CharT*,
                 ostreambuf_iterator<_CharT, char_traits<_CharT>>);

  template <bool _IsMove, typename _CharT>
  typename __gnu_cxx::__enable_if<__is_char<_CharT>::__value, _CharT*>::__type
  __copy_move_a2(istreambuf_iterator<_CharT, char_traits<_CharT>>,
                 istreambuf_iterator<_CharT, char_traits<_CharT>>, _CharT*);

  template <bool _IsMove, typename _II, typename _OI>
  inline _OI __copy_move_a2(_II __first, _II __last, _OI __result) {
    return _OI(std::__copy_move_a<_IsMove>(std::__niter_base(__first),
                                           std::__niter_base(__last),
                                           std::__niter_base(__result)));
  }
  template <typename _II, typename _OI>
  inline _OI copy(_II __first, _II __last, _OI __result) {
    ;

    return (std::__copy_move_a2<__is_move_iterator<_II>::__value>(
        std::__miter_base(__first), std::__miter_base(__last), __result));
  }
  template <typename _II, typename _OI>
  inline _OI move(_II __first, _II __last, _OI __result) {
    ;

    return std::__copy_move_a2<true>(std::__miter_base(__first),
                                     std::__miter_base(__last), __result);
  }

  template <bool, bool, typename>
  struct __copy_move_backward {
    template <typename _BI1, typename _BI2>
    static _BI2 __copy_move_b(_BI1 __first, _BI1 __last, _BI2 __result) {
      while (__first != __last)
        *--__result = *--__last;
      return __result;
    }
  };

  template <typename _Category>
  struct __copy_move_backward<true, false, _Category> {
    template <typename _BI1, typename _BI2>
    static _BI2 __copy_move_b(_BI1 __first, _BI1 __last, _BI2 __result) {
      while (__first != __last)
        *--__result = std::move(*--__last);
      return __result;
    }
  };

  template <>
  struct __copy_move_backward<false, false, random_access_iterator_tag> {
    template <typename _BI1, typename _BI2>
    static _BI2 __copy_move_b(_BI1 __first, _BI1 __last, _BI2 __result) {
      typename iterator_traits<_BI1>::difference_type __n;
      for (__n = __last - __first; __n > 0; --__n)
        *--__result = *--__last;
      return __result;
    }
  };

  template <>
  struct __copy_move_backward<true, false, random_access_iterator_tag> {
    template <typename _BI1, typename _BI2>
    static _BI2 __copy_move_b(_BI1 __first, _BI1 __last, _BI2 __result) {
      typename iterator_traits<_BI1>::difference_type __n;
      for (__n = __last - __first; __n > 0; --__n)
        *--__result = std::move(*--__last);
      return __result;
    }
  };

  template <bool _IsMove>
  struct __copy_move_backward<_IsMove, true, random_access_iterator_tag> {
    template <typename _Tp>
    static _Tp* __copy_move_b(const _Tp* __first,
                              const _Tp* __last,
                              _Tp* __result) {
      using __assignable = conditional<_IsMove, is_move_assignable<_Tp>,
                                       is_copy_assignable<_Tp>>;

      static_assert(__assignable::type::value, "type is not assignable");

      const ptrdiff_t _Num = __last - __first;
      if (_Num)
        __builtin_memmove(__result - _Num, __first, sizeof(_Tp) * _Num);
      return __result - _Num;
    }
  };

  template <bool _IsMove, typename _BI1, typename _BI2>
  inline _BI2 __copy_move_backward_a(_BI1 __first, _BI1 __last, _BI2 __result) {
    typedef typename iterator_traits<_BI1>::value_type _ValueType1;
    typedef typename iterator_traits<_BI2>::value_type _ValueType2;
    typedef typename iterator_traits<_BI1>::iterator_category _Category;
    const bool __simple =
        (__is_trivial(_ValueType1) && __is_pointer<_BI1>::__value &&
         __is_pointer<_BI2>::__value &&
         __are_same<_ValueType1, _ValueType2>::__value);

    return std::__copy_move_backward<_IsMove, __simple,
                                     _Category>::__copy_move_b(__first, __last,
                                                               __result);
  }

  template <bool _IsMove, typename _BI1, typename _BI2>
  inline _BI2 __copy_move_backward_a2(_BI1 __first, _BI1 __last,
                                      _BI2 __result) {
    return _BI2(std::__copy_move_backward_a<_IsMove>(
        std::__niter_base(__first), std::__niter_base(__last),
        std::__niter_base(__result)));
  }
  template <typename _BI1, typename _BI2>
  inline _BI2 copy_backward(_BI1 __first, _BI1 __last, _BI2 __result) {
    ;

    return (std::__copy_move_backward_a2<__is_move_iterator<_BI1>::__value>(
        std::__miter_base(__first), std::__miter_base(__last), __result));
  }
  template <typename _BI1, typename _BI2>
  inline _BI2 move_backward(_BI1 __first, _BI1 __last, _BI2 __result) {
    ;

    return std::__copy_move_backward_a2<true>(
        std::__miter_base(__first), std::__miter_base(__last), __result);
  }

  template <typename _ForwardIterator, typename _Tp>
  inline
      typename __gnu_cxx::__enable_if<!__is_scalar<_Tp>::__value, void>::__type
      __fill_a(_ForwardIterator __first, _ForwardIterator __last,
               const _Tp& __value) {
    for (; __first != __last; ++__first)
      *__first = __value;
  }

  template <typename _ForwardIterator, typename _Tp>
  inline
      typename __gnu_cxx::__enable_if<__is_scalar<_Tp>::__value, void>::__type
      __fill_a(_ForwardIterator __first, _ForwardIterator __last,
               const _Tp& __value) {
    const _Tp __tmp = __value;
    for (; __first != __last; ++__first)
      *__first = __tmp;
  }

  template <typename _Tp>
  inline typename __gnu_cxx::__enable_if<__is_byte<_Tp>::__value, void>::__type
  __fill_a(_Tp * __first, _Tp * __last, const _Tp& __c) {
    const _Tp __tmp = __c;
    if (const size_t __len = __last - __first)
      __builtin_memset(__first, static_cast<unsigned char>(__tmp), __len);
  }
  template <typename _ForwardIterator, typename _Tp>
  inline void fill(_ForwardIterator __first, _ForwardIterator __last,
                   const _Tp& __value) {
    ;

    std::__fill_a(std::__niter_base(__first), std::__niter_base(__last),
                  __value);
  }

  template <typename _OutputIterator, typename _Size, typename _Tp>
  inline typename __gnu_cxx::__enable_if<!__is_scalar<_Tp>::__value,
                                         _OutputIterator>::__type
  __fill_n_a(_OutputIterator __first, _Size __n, const _Tp& __value) {
    for (__decltype(__n + 0) __niter = __n; __niter > 0; --__niter, ++__first)
      *__first = __value;
    return __first;
  }

  template <typename _OutputIterator, typename _Size, typename _Tp>
  inline typename __gnu_cxx::__enable_if<__is_scalar<_Tp>::__value,
                                         _OutputIterator>::__type
  __fill_n_a(_OutputIterator __first, _Size __n, const _Tp& __value) {
    const _Tp __tmp = __value;
    for (__decltype(__n + 0) __niter = __n; __niter > 0; --__niter, ++__first)
      *__first = __tmp;
    return __first;
  }

  template <typename _Size, typename _Tp>
  inline typename __gnu_cxx::__enable_if<__is_byte<_Tp>::__value, _Tp*>::__type
  __fill_n_a(_Tp * __first, _Size __n, const _Tp& __c) {
    std::__fill_a(__first, __first + __n, __c);
    return __first + __n;
  }
  template <typename _OI, typename _Size, typename _Tp>
  inline _OI fill_n(_OI __first, _Size __n, const _Tp& __value) {
    return _OI(std::__fill_n_a(std::__niter_base(__first), __n, __value));
  }

  template <bool _BoolType>
  struct __equal {
    template <typename _II1, typename _II2>
    static bool equal(_II1 __first1, _II1 __last1, _II2 __first2) {
      for (; __first1 != __last1; ++__first1, (void)++__first2)
        if (!(*__first1 == *__first2))
          return false;
      return true;
    }
  };

  template <>
  struct __equal<true> {
    template <typename _Tp>
    static bool equal(const _Tp* __first1,
                      const _Tp* __last1,
                      const _Tp* __first2) {
      if (const size_t __len = (__last1 - __first1))
        return !__builtin_memcmp(__first1, __first2, sizeof(_Tp) * __len);
      return true;
    }
  };

  template <typename _II1, typename _II2>
  inline bool __equal_aux(_II1 __first1, _II1 __last1, _II2 __first2) {
    typedef typename iterator_traits<_II1>::value_type _ValueType1;
    typedef typename iterator_traits<_II2>::value_type _ValueType2;
    const bool __simple =
        ((__is_integer<_ValueType1>::__value ||
          __is_pointer<_ValueType1>::__value) &&
         __is_pointer<_II1>::__value && __is_pointer<_II2>::__value &&
         __are_same<_ValueType1, _ValueType2>::__value);

    return std::__equal<__simple>::equal(__first1, __last1, __first2);
  }

  template <typename, typename>
  struct __lc_rai {
    template <typename _II1, typename _II2>
    static _II1 __newlast1(_II1, _II1 __last1, _II2, _II2) {
      return __last1;
    }

    template <typename _II>
    static bool __cnd2(_II __first, _II __last) {
      return __first != __last;
    }
  };

  template <>
  struct __lc_rai<random_access_iterator_tag, random_access_iterator_tag> {
    template <typename _RAI1, typename _RAI2>
    static _RAI1 __newlast1(_RAI1 __first1,
                            _RAI1 __last1,
                            _RAI2 __first2,
                            _RAI2 __last2) {
      const typename iterator_traits<_RAI1>::difference_type __diff1 =
          __last1 - __first1;
      const typename iterator_traits<_RAI2>::difference_type __diff2 =
          __last2 - __first2;
      return __diff2 < __diff1 ? __first1 + __diff2 : __last1;
    }

    template <typename _RAI>
    static bool __cnd2(_RAI, _RAI) {
      return true;
    }
  };

  template <typename _II1, typename _II2, typename _Compare>
  bool __lexicographical_compare_impl(_II1 __first1, _II1 __last1,
                                      _II2 __first2, _II2 __last2,
                                      _Compare __comp) {
    typedef typename iterator_traits<_II1>::iterator_category _Category1;
    typedef typename iterator_traits<_II2>::iterator_category _Category2;
    typedef std::__lc_rai<_Category1, _Category2> __rai_type;

    __last1 = __rai_type::__newlast1(__first1, __last1, __first2, __last2);
    for (; __first1 != __last1 && __rai_type::__cnd2(__first2, __last2);
         ++__first1, (void)++__first2) {
      if (__comp(__first1, __first2))
        return true;
      if (__comp(__first2, __first1))
        return false;
    }
    return __first1 == __last1 && __first2 != __last2;
  }

  template <bool _BoolType>
  struct __lexicographical_compare {
    template <typename _II1, typename _II2>
    static bool __lc(_II1, _II1, _II2, _II2);
  };

  template <bool _BoolType>
  template <typename _II1, typename _II2>
  bool __lexicographical_compare<_BoolType>::__lc(_II1 __first1, _II1 __last1,
                                                  _II2 __first2, _II2 __last2) {
    return std::__lexicographical_compare_impl(
        __first1, __last1, __first2, __last2,
        __gnu_cxx::__ops::__iter_less_iter());
  }

  template <>
  struct __lexicographical_compare<true> {
    template <typename _Tp, typename _Up>
    static bool __lc(const _Tp* __first1,
                     const _Tp* __last1,
                     const _Up* __first2,
                     const _Up* __last2) {
      const size_t __len1 = __last1 - __first1;
      const size_t __len2 = __last2 - __first2;
      if (const size_t __len = std::min(__len1, __len2))
        if (int __result = __builtin_memcmp(__first1, __first2, __len))
          return __result < 0;
      return __len1 < __len2;
    }
  };

  template <typename _II1, typename _II2>
  inline bool __lexicographical_compare_aux(_II1 __first1, _II1 __last1,
                                            _II2 __first2, _II2 __last2) {
    typedef typename iterator_traits<_II1>::value_type _ValueType1;
    typedef typename iterator_traits<_II2>::value_type _ValueType2;
    const bool __simple =
        (__is_byte<_ValueType1>::__value && __is_byte<_ValueType2>::__value &&
         !__gnu_cxx::__numeric_traits<_ValueType1>::__is_signed &&
         !__gnu_cxx::__numeric_traits<_ValueType2>::__is_signed &&
         __is_pointer<_II1>::__value && __is_pointer<_II2>::__value);

    return std::__lexicographical_compare<__simple>::__lc(__first1, __last1,
                                                          __first2, __last2);
  }

  template <typename _ForwardIterator, typename _Tp, typename _Compare>
  _ForwardIterator __lower_bound(_ForwardIterator __first,
                                 _ForwardIterator __last, const _Tp& __val,
                                 _Compare __comp) {
    typedef typename iterator_traits<_ForwardIterator>::difference_type
        _DistanceType;

    _DistanceType __len = std::distance(__first, __last);

    while (__len > 0) {
      _DistanceType __half = __len >> 1;
      _ForwardIterator __middle = __first;
      std::advance(__middle, __half);
      if (__comp(__middle, __val)) {
        __first = __middle;
        ++__first;
        __len = __len - __half - 1;
      } else
        __len = __half;
    }
    return __first;
  }
  template <typename _ForwardIterator, typename _Tp>
  inline _ForwardIterator lower_bound(
      _ForwardIterator __first, _ForwardIterator __last, const _Tp& __val) {
    ;

    return std::__lower_bound(__first, __last, __val,
                              __gnu_cxx::__ops::__iter_less_val());
  }

  inline constexpr int __lg(int __n) {
    return sizeof(int) * 8 - 1 - __builtin_clz(__n);
  }

  inline constexpr unsigned __lg(unsigned __n) {
    return sizeof(int) * 8 - 1 - __builtin_clz(__n);
  }

  inline constexpr long __lg(long __n) {
    return sizeof(long) * 8 - 1 - __builtin_clzl(__n);
  }

  inline constexpr unsigned long __lg(unsigned long __n) {
    return sizeof(long) * 8 - 1 - __builtin_clzl(__n);
  }

  inline constexpr long long __lg(long long __n) {
    return sizeof(long long) * 8 - 1 - __builtin_clzll(__n);
  }

  inline constexpr unsigned long long __lg(unsigned long long __n) {
    return sizeof(long long) * 8 - 1 - __builtin_clzll(__n);
  }

  template <typename _II1, typename _II2>
  inline bool equal(_II1 __first1, _II1 __last1, _II2 __first2) {
    ;

    return std::__equal_aux(std::__niter_base(__first1),
                            std::__niter_base(__last1),
                            std::__niter_base(__first2));
  }
  template <typename _IIter1, typename _IIter2, typename _BinaryPredicate>
  inline bool equal(_IIter1 __first1, _IIter1 __last1, _IIter2 __first2,
                    _BinaryPredicate __binary_pred) {
    ;

    for (; __first1 != __last1; ++__first1, (void)++__first2)
      if (!bool(__binary_pred(*__first1, *__first2)))
        return false;
    return true;
  }
  template <typename _II1, typename _II2>
  inline bool equal(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2) {
    ;
    ;

    using _RATag = random_access_iterator_tag;
    using _Cat1 = typename iterator_traits<_II1>::iterator_category;
    using _Cat2 = typename iterator_traits<_II2>::iterator_category;
    using _RAIters = __and_<is_same<_Cat1, _RATag>, is_same<_Cat2, _RATag>>;
    if (_RAIters()) {
      auto __d1 = std::distance(__first1, __last1);
      auto __d2 = std::distance(__first2, __last2);
      if (__d1 != __d2)
        return false;
      return std::equal(__first1, __last1, __first2);
    }

    for (; __first1 != __last1 && __first2 != __last2;
         ++__first1, (void)++__first2)
      if (!(*__first1 == *__first2))
        return false;
    return __first1 == __last1 && __first2 == __last2;
  }
  template <typename _IIter1, typename _IIter2, typename _BinaryPredicate>
  inline bool equal(_IIter1 __first1, _IIter1 __last1, _IIter2 __first2,
                    _IIter2 __last2, _BinaryPredicate __binary_pred) {
    ;
    ;

    using _RATag = random_access_iterator_tag;
    using _Cat1 = typename iterator_traits<_IIter1>::iterator_category;
    using _Cat2 = typename iterator_traits<_IIter2>::iterator_category;
    using _RAIters = __and_<is_same<_Cat1, _RATag>, is_same<_Cat2, _RATag>>;
    if (_RAIters()) {
      auto __d1 = std::distance(__first1, __last1);
      auto __d2 = std::distance(__first2, __last2);
      if (__d1 != __d2)
        return false;
      return std::equal(__first1, __last1, __first2, __binary_pred);
    }

    for (; __first1 != __last1 && __first2 != __last2;
         ++__first1, (void)++__first2)
      if (!bool(__binary_pred(*__first1, *__first2)))
        return false;
    return __first1 == __last1 && __first2 == __last2;
  }
  template <typename _II1, typename _II2>
  inline bool lexicographical_compare(_II1 __first1, _II1 __last1,
                                      _II2 __first2, _II2 __last2) {
    ;
    ;

    return std::__lexicographical_compare_aux(
        std::__niter_base(__first1), std::__niter_base(__last1),
        std::__niter_base(__first2), std::__niter_base(__last2));
  }
  template <typename _II1, typename _II2, typename _Compare>
  inline bool lexicographical_compare(_II1 __first1, _II1 __last1,
                                      _II2 __first2, _II2 __last2,
                                      _Compare __comp) {
    ;
    ;

    return std::__lexicographical_compare_impl(
        __first1, __last1, __first2, __last2,
        __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }

  template <typename _InputIterator1, typename _InputIterator2,
            typename _BinaryPredicate>
  pair<_InputIterator1, _InputIterator2> __mismatch(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _BinaryPredicate __binary_pred) {
    while (__first1 != __last1 && __binary_pred(__first1, __first2)) {
      ++__first1;
      ++__first2;
    }
    return pair<_InputIterator1, _InputIterator2>(__first1, __first2);
  }
  template <typename _InputIterator1, typename _InputIterator2>
  inline pair<_InputIterator1, _InputIterator2> mismatch(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2) {
    ;

    return std::__mismatch(__first1, __last1, __first2,
                           __gnu_cxx::__ops::__iter_equal_to_iter());
  }
  template <typename _InputIterator1, typename _InputIterator2,
            typename _BinaryPredicate>
  inline pair<_InputIterator1, _InputIterator2> mismatch(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _BinaryPredicate __binary_pred) {
    ;

    return std::__mismatch(__first1, __last1, __first2,
                           __gnu_cxx::__ops::__iter_comp_iter(__binary_pred));
  }

  template <typename _InputIterator1, typename _InputIterator2,
            typename _BinaryPredicate>
  pair<_InputIterator1, _InputIterator2> __mismatch(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2,
      _BinaryPredicate __binary_pred) {
    while (__first1 != __last1 && __first2 != __last2 &&
           __binary_pred(__first1, __first2)) {
      ++__first1;
      ++__first2;
    }
    return pair<_InputIterator1, _InputIterator2>(__first1, __first2);
  }
  template <typename _InputIterator1, typename _InputIterator2>
  inline pair<_InputIterator1, _InputIterator2> mismatch(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2) {
    ;
    ;

    return std::__mismatch(__first1, __last1, __first2, __last2,
                           __gnu_cxx::__ops::__iter_equal_to_iter());
  }
  template <typename _InputIterator1, typename _InputIterator2,
            typename _BinaryPredicate>
  inline pair<_InputIterator1, _InputIterator2> mismatch(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2,
      _BinaryPredicate __binary_pred) {
    ;
    ;

    return std::__mismatch(__first1, __last1, __first2, __last2,
                           __gnu_cxx::__ops::__iter_comp_iter(__binary_pred));
  }

}  // namespace std__attribute__((__visibility__("default")))

#pragma GCC visibility push(default)

#pragma GCC visibility push(default)

extern "C++" {

namespace std {
class exception {
 public:
  exception() noexcept {}
  virtual ~exception() noexcept;

  virtual const char* what() const noexcept;
};

}  // namespace std
}

#pragma GCC visibility pop

extern "C++" {

namespace std {

class bad_exception : public exception {
 public:
  bad_exception() noexcept {}

  virtual ~bad_exception() noexcept;

  virtual const char* what() const noexcept;
};

typedef void (*terminate_handler)();

typedef void (*unexpected_handler)();

terminate_handler set_terminate(terminate_handler) noexcept;

terminate_handler get_terminate() noexcept;

void terminate() noexcept __attribute__((__noreturn__));

unexpected_handler set_unexpected(unexpected_handler) noexcept;

unexpected_handler get_unexpected() noexcept;

void unexpected() __attribute__((__noreturn__));
bool uncaught_exception() noexcept __attribute__((__pure__));

int uncaught_exceptions() noexcept __attribute__((__pure__));

}  // namespace std

namespace __gnu_cxx {

void __verbose_terminate_handler();
}
}

#pragma GCC visibility pop

#pragma GCC visibility push(default)

#pragma GCC visibility push(default)

typedef long int ptrdiff_t;
typedef long unsigned int size_t;
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld
      __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;

typedef decltype(nullptr) nullptr_t;
namespace std {
class type_info;
}

namespace __cxxabiv1 {
struct __cxa_refcounted_exception;

extern "C" {

void* __cxa_allocate_exception(size_t) noexcept;

__cxa_refcounted_exception* __cxa_init_primary_exception(
    void* object,
    std::type_info* tinfo,
    void (*dest)(void*)) noexcept;
}
}  // namespace __cxxabiv1

#pragma GCC visibility pop

namespace std {

size_t _Hash_bytes(const void* __ptr, size_t __len, size_t __seed);

size_t _Fnv_hash_bytes(const void* __ptr, size_t __len, size_t __seed);

}  // namespace std

#pragma GCC visibility push(default)

extern "C++" {

namespace __cxxabiv1 {
class __class_type_info;
}
namespace std {

class type_info {
 public:
  virtual ~type_info();

  const char* name() const noexcept {
    return __name[0] == '*' ? __name + 1 : __name;
  }
  bool before(const type_info& __arg) const noexcept {
    return (__name[0] == '*' && __arg.__name[0] == '*')
               ? __name < __arg.__name
               : __builtin_strcmp(__name, __arg.__name) < 0;
  }

  bool operator==(const type_info& __arg) const noexcept {
    return ((__name == __arg.__name) ||
            (__name[0] != '*' && __builtin_strcmp(__name, __arg.__name) == 0));
  }
  bool operator!=(const type_info& __arg) const noexcept {
    return !operator==(__arg);
  }

  size_t hash_code() const noexcept {
    return _Hash_bytes(name(), __builtin_strlen(name()),
                       static_cast<size_t>(0xc70f6907UL));
  }

  virtual bool __is_pointer_p() const;

  virtual bool __is_function_p() const;

  virtual bool __do_catch(const type_info* __thr_type,
                          void** __thr_obj,
                          unsigned __outer) const;

  virtual bool __do_upcast(const __cxxabiv1::__class_type_info* __target,
                           void** __obj_ptr) const;

 protected:
  const char* __name;

  explicit type_info(const char* __n) : __name(__n) {}

 private:
  type_info& operator=(const type_info&);
  type_info(const type_info&);
};

class bad_cast : public exception {
 public:
  bad_cast() noexcept {}

  virtual ~bad_cast() noexcept;

  virtual const char* what() const noexcept;
};

class bad_typeid : public exception {
 public:
  bad_typeid() noexcept {}

  virtual ~bad_typeid() noexcept;

  virtual const char* what() const noexcept;
};
}  // namespace std
}

#pragma GCC visibility pop

extern "C++" {

namespace std {
class type_info;

namespace __exception_ptr {
class exception_ptr;
}

using __exception_ptr::exception_ptr;

exception_ptr current_exception() noexcept;

template <typename _Ex>
exception_ptr make_exception_ptr(_Ex) noexcept;

void rethrow_exception(exception_ptr) __attribute__((__noreturn__));

namespace __exception_ptr {
using std::rethrow_exception;

class exception_ptr {
  void* _M_exception_object;

  explicit exception_ptr(void* __e) noexcept;

  void _M_addref() noexcept;
  void _M_release() noexcept;

  void* _M_get() const noexcept __attribute__((__pure__));

  friend exception_ptr std::current_exception() noexcept;
  friend void std::rethrow_exception(exception_ptr);
  template <typename _Ex>
  friend exception_ptr std::make_exception_ptr(_Ex) noexcept;

 public:
  exception_ptr() noexcept;

  exception_ptr(const exception_ptr&) noexcept;

  exception_ptr(nullptr_t) noexcept : _M_exception_object(0) {}

  exception_ptr(exception_ptr&& __o) noexcept
      : _M_exception_object(__o._M_exception_object) {
    __o._M_exception_object = 0;
  }
  exception_ptr& operator=(const exception_ptr&) noexcept;

  exception_ptr& operator=(exception_ptr&& __o) noexcept {
    exception_ptr(static_cast<exception_ptr&&>(__o)).swap(*this);
    return *this;
  }

  ~exception_ptr() noexcept;

  void swap(exception_ptr&) noexcept;
  explicit operator bool() const { return _M_exception_object; }

  friend bool operator==(const exception_ptr&, const exception_ptr&) noexcept
      __attribute__((__pure__));

  const class std::type_info* __cxa_exception_type() const noexcept
      __attribute__((__pure__));
};

bool operator==(const exception_ptr&, const exception_ptr&) noexcept
    __attribute__((__pure__));

bool operator!=(const exception_ptr&, const exception_ptr&) noexcept
    __attribute__((__pure__));

inline void swap(exception_ptr& __lhs, exception_ptr& __rhs) {
  __lhs.swap(__rhs);
}

template <typename _Ex>
inline void __dest_thunk(void* __x) {
  static_cast<_Ex*>(__x)->~_Ex();
}

}  // namespace __exception_ptr

template <typename _Ex>
exception_ptr make_exception_ptr(_Ex __ex) noexcept {
  try {
    void* __e = __cxxabiv1::__cxa_allocate_exception(sizeof(_Ex));
    (void)__cxxabiv1::__cxa_init_primary_exception(
        __e, const_cast<std::type_info*>(&typeid(__ex)),
        __exception_ptr::__dest_thunk<_Ex>);
    ::new (__e) _Ex(__ex);
    return exception_ptr(__e);

  } catch (...) {
    return current_exception();
  }
}

template <typename _Ex>
exception_ptr copy_exception(_Ex __ex) noexcept __attribute__((__deprecated__));

template <typename _Ex>
exception_ptr copy_exception(_Ex __ex) noexcept {
  return std::make_exception_ptr<_Ex>(__ex);
}

}  // namespace std
}

#pragma GCC visibility pop
#pragma GCC visibility push(default)
extern "C++" {

namespace std {

class nested_exception {
  exception_ptr _M_ptr;

 public:
  nested_exception() noexcept : _M_ptr(current_exception()) {}

  nested_exception(const nested_exception&) noexcept = default;

  nested_exception& operator=(const nested_exception&) noexcept = default;

  virtual ~nested_exception() noexcept;

  [[noreturn]] void rethrow_nested() const {
    if (_M_ptr)
      rethrow_exception(_M_ptr);
    std::terminate();
  }

  exception_ptr nested_ptr() const noexcept { return _M_ptr; }
};

template <typename _Except>
struct _Nested_exception : public _Except, public nested_exception {
  explicit _Nested_exception(const _Except& __ex) : _Except(__ex) {}

  explicit _Nested_exception(_Except&& __ex)
      : _Except(static_cast<_Except&&>(__ex)) {}
};

template <typename _Tp>
inline void __throw_with_nested_impl(_Tp&& __t, true_type) {
  using _Up = typename remove_reference<_Tp>::type;
  throw _Nested_exception<_Up>{std::forward<_Tp>(__t)};
}

template <typename _Tp>
inline void __throw_with_nested_impl(_Tp&& __t, false_type) {
  throw std::forward<_Tp>(__t);
}

template <typename _Tp>
[[noreturn]] inline void throw_with_nested(_Tp&& __t) {
  using _Up = typename decay<_Tp>::type;
  using _CopyConstructible =
      __and_<is_copy_constructible<_Up>, is_move_constructible<_Up>>;
  static_assert(_CopyConstructible::value,
                "throw_with_nested argument must be CopyConstructible");
  using __nest = __and_<is_class<_Up>, __bool_constant<!__is_final(_Up)>,
                        __not_<is_base_of<nested_exception, _Up>>>;
  std::__throw_with_nested_impl(std::forward<_Tp>(__t), __nest{});
}

template <typename _Tp>
using __rethrow_if_nested_cond = typename enable_if<
    __and_<is_polymorphic<_Tp>,
           __or_<__not_<is_base_of<nested_exception, _Tp>>,
                 is_convertible<_Tp*, nested_exception*>>>::value>::type;

template <typename _Ex>
inline __rethrow_if_nested_cond<_Ex> __rethrow_if_nested_impl(
    const _Ex* __ptr) {
  if (auto __ne_ptr = dynamic_cast<const nested_exception*>(__ptr))
    __ne_ptr->rethrow_nested();
}

inline void __rethrow_if_nested_impl(const void*) {}

template <typename _Ex>
inline void rethrow_if_nested(const _Ex& __ex) {
  std::__rethrow_if_nested_impl(std::__addressof(__ex));
}

}  // namespace std
}

#pragma GCC visibility pop

#pragma GCC visibility push(default)

extern "C++" {

namespace std {

class bad_alloc : public exception {
 public:
  bad_alloc() throw() {}

  virtual ~bad_alloc() throw();

  virtual const char* what() const throw();
};

class bad_array_new_length : public bad_alloc {
 public:
  bad_array_new_length() throw(){};

  virtual ~bad_array_new_length() throw();

  virtual const char* what() const throw();
};

struct nothrow_t {
  explicit nothrow_t() = default;
};

extern const nothrow_t nothrow;

typedef void (*new_handler)();

new_handler set_new_handler(new_handler) throw();

new_handler get_new_handler() noexcept;

}  // namespace std
void* operator new(std::size_t) __attribute__((__externally_visible__));
void* operator new[](std::size_t) __attribute__((__externally_visible__));
void operator delete(void*)noexcept __attribute__((__externally_visible__));
void operator delete[](void*) noexcept __attribute__((__externally_visible__));

void operator delete(void*, std::size_t) noexcept
    __attribute__((__externally_visible__));
void operator delete[](void*, std::size_t) noexcept
    __attribute__((__externally_visible__));

void* operator new(std::size_t, const std::nothrow_t&) noexcept
    __attribute__((__externally_visible__));
void* operator new[](std::size_t, const std::nothrow_t&) noexcept
    __attribute__((__externally_visible__));
void operator delete(void*, const std::nothrow_t&)noexcept
    __attribute__((__externally_visible__));
void operator delete[](void*, const std::nothrow_t&) noexcept
    __attribute__((__externally_visible__));
inline void* operator new(std::size_t, void* __p) noexcept {
  return __p;
}
inline void* operator new[](std::size_t, void* __p) noexcept {
  return __p;
}

inline void operator delete(void*, void*)noexcept {}
inline void operator delete[](void*, void*) noexcept {}
}
#pragma GCC visibility pop

namespace __gnu_cxx __attribute__((__visibility__("default"))) {

  using std::ptrdiff_t;
  using std::size_t;
  template <typename _Tp>
  class new_allocator {
   public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef _Tp* pointer;
    typedef const _Tp* const_pointer;
    typedef _Tp& reference;
    typedef const _Tp& const_reference;
    typedef _Tp value_type;

    template <typename _Tp1>
    struct rebind {
      typedef new_allocator<_Tp1> other;
    };

    typedef std::true_type propagate_on_container_move_assignment;

    new_allocator() noexcept {}

    new_allocator(const new_allocator&) noexcept {}

    template <typename _Tp1>
    new_allocator(const new_allocator<_Tp1>&) noexcept {}

    ~new_allocator() noexcept {}

    pointer address(reference __x) const noexcept {
      return std::__addressof(__x);
    }

    const_pointer address(const_reference __x) const noexcept {
      return std::__addressof(__x);
    }

    pointer allocate(size_type __n, const void* = 0) {
      if (__n > this->max_size())
        std::__throw_bad_alloc();
      return static_cast<_Tp*>(::operator new(__n * sizeof(_Tp)));
    }

    void deallocate(pointer __p, size_type) { ::operator delete(__p); }

    size_type max_size() const noexcept { return size_t(-1) / sizeof(_Tp); }

    template <typename _Up, typename... _Args>
    void construct(_Up* __p, _Args&&... __args) {
      ::new ((void*)__p) _Up(std::forward<_Args>(__args)...);
    }

    template <typename _Up>
    void destroy(_Up* __p) {
      __p->~_Up();
    }
  };

  template <typename _Tp>
  inline bool operator==(const new_allocator<_Tp>&, const new_allocator<_Tp>&) {
    return true;
  }

  template <typename _Tp>
  inline bool operator!=(const new_allocator<_Tp>&, const new_allocator<_Tp>&) {
    return false;
  }

}  // namespace __gnu_cxx__attribute__((__visibility__("default")))

namespace std {
template <typename _Tp>
using __allocator_base = __gnu_cxx::new_allocator<_Tp>;
}

namespace std __attribute__((__visibility__("default"))) {

  template <typename>
  class allocator;

  template <>
  class allocator<void>;

  template <typename, typename>
  struct uses_allocator;

}  // namespace std__attribute__((__visibility__("default")))
namespace std __attribute__((__visibility__("default"))) {

  template <>
  class allocator<void> {
   public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef void* pointer;
    typedef const void* const_pointer;
    typedef void value_type;

    template <typename _Tp1>
    struct rebind {
      typedef allocator<_Tp1> other;
    };

    typedef true_type propagate_on_container_move_assignment;

    typedef true_type is_always_equal;

    template <typename _Up, typename... _Args>
    void construct(_Up* __p, _Args&&... __args) {
      ::new ((void*)__p) _Up(std::forward<_Args>(__args)...);
    }

    template <typename _Up>
    void destroy(_Up* __p) {
      __p->~_Up();
    }
  };
  template <typename _Tp>
  class allocator : public __allocator_base<_Tp> {
   public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef _Tp* pointer;
    typedef const _Tp* const_pointer;
    typedef _Tp& reference;
    typedef const _Tp& const_reference;
    typedef _Tp value_type;

    template <typename _Tp1>
    struct rebind {
      typedef allocator<_Tp1> other;
    };

    typedef true_type propagate_on_container_move_assignment;

    typedef true_type is_always_equal;

    allocator() throw() {}

    allocator(const allocator& __a) throw() : __allocator_base<_Tp>(__a) {}

    template <typename _Tp1>
    allocator(const allocator<_Tp1>&) throw() {}

    ~allocator() throw() {}
  };

  template <typename _T1, typename _T2>
  inline bool operator==(const allocator<_T1>&,
                         const allocator<_T2>&) noexcept {
    return true;
  }

  template <typename _Tp>
  inline bool operator==(const allocator<_Tp>&,
                         const allocator<_Tp>&) noexcept {
    return true;
  }

  template <typename _T1, typename _T2>
  inline bool operator!=(const allocator<_T1>&,
                         const allocator<_T2>&) noexcept {
    return false;
  }

  template <typename _Tp>
  inline bool operator!=(const allocator<_Tp>&,
                         const allocator<_Tp>&) noexcept {
    return false;
  }

  extern template class allocator<char>;
  extern template class allocator<wchar_t>;

  template <typename _Alloc, bool = __is_empty(_Alloc)>
  struct __alloc_swap {
    static void _S_do_it(_Alloc&, _Alloc&) noexcept {}
  };

  template <typename _Alloc>
  struct __alloc_swap<_Alloc, false> {
    static void _S_do_it(_Alloc& __one, _Alloc& __two) noexcept {
      if (__one != __two)
        swap(__one, __two);
    }
  };

  template <typename _Alloc, bool = __is_empty(_Alloc)>
  struct __alloc_neq {
    static bool _S_do_it(const _Alloc&, const _Alloc&) { return false; }
  };

  template <typename _Alloc>
  struct __alloc_neq<_Alloc, false> {
    static bool _S_do_it(const _Alloc& __one, const _Alloc& __two) {
      return __one != __two;
    }
  };

  template <typename _Tp,
            bool = __or_<
                is_copy_constructible<typename _Tp::value_type>,
                is_nothrow_move_constructible<typename _Tp::value_type>>::value>
  struct __shrink_to_fit_aux {
    static bool _S_do_it(_Tp&) noexcept { return false; }
  };

  template <typename _Tp>
  struct __shrink_to_fit_aux<_Tp, true> {
    static bool _S_do_it(_Tp& __c) noexcept {
      try {
        _Tp(__make_move_if_noexcept_iterator(__c.begin()),
            __make_move_if_noexcept_iterator(__c.end()), __c.get_allocator())
            .swap(__c);
        return true;
      } catch (...) {
        return false;
      }
    }
  };

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  struct __allocator_traits_base {
    template <typename _Tp, typename _Up, typename = void>
    struct __rebind : __replace_first_arg<_Tp, _Up> {};

    template <typename _Tp, typename _Up>
    struct __rebind<_Tp,
                    _Up,
                    __void_t<typename _Tp::template rebind<_Up>::other>> {
      using type = typename _Tp::template rebind<_Up>::other;
    };

   protected:
    template <typename _Tp>
    using __pointer = typename _Tp::pointer;
    template <typename _Tp>
    using __c_pointer = typename _Tp::const_pointer;
    template <typename _Tp>
    using __v_pointer = typename _Tp::void_pointer;
    template <typename _Tp>
    using __cv_pointer = typename _Tp::const_void_pointer;
    template <typename _Tp>
    using __pocca = typename _Tp::propagate_on_container_copy_assignment;
    template <typename _Tp>
    using __pocma = typename _Tp::propagate_on_container_move_assignment;
    template <typename _Tp>
    using __pocs = typename _Tp::propagate_on_container_swap;
    template <typename _Tp>
    using __equal = typename _Tp::is_always_equal;
  };

  template <typename _Alloc, typename _Up>
  using __alloc_rebind =
      typename __allocator_traits_base::template __rebind<_Alloc, _Up>::type;

  template <typename _Alloc>
  struct allocator_traits : __allocator_traits_base {
    typedef _Alloc allocator_type;

    typedef typename _Alloc::value_type value_type;

    using pointer = __detected_or_t<value_type*, __pointer, _Alloc>;

   private:
    template <template <typename> class _Func, typename _Tp, typename = void>
    struct _Ptr {
      using type = typename pointer_traits<pointer>::template rebind<_Tp>;
    };

    template <template <typename> class _Func, typename _Tp>
    struct _Ptr<_Func, _Tp, __void_t<_Func<_Alloc>>> {
      using type = _Func<_Alloc>;
    };

    template <typename _A2, typename _PtrT, typename = void>
    struct _Diff {
      using type = typename pointer_traits<_PtrT>::difference_type;
    };

    template <typename _A2, typename _PtrT>
    struct _Diff<_A2, _PtrT, __void_t<typename _A2::difference_type>> {
      using type = typename _A2::difference_type;
    };

    template <typename _A2, typename _DiffT, typename = void>
    struct _Size : make_unsigned<_DiffT> {};

    template <typename _A2, typename _DiffT>
    struct _Size<_A2, _DiffT, __void_t<typename _A2::size_type>> {
      using type = typename _A2::size_type;
    };

   public:
    using const_pointer = typename _Ptr<__c_pointer, const value_type>::type;

    using void_pointer = typename _Ptr<__v_pointer, void>::type;

    using const_void_pointer = typename _Ptr<__cv_pointer, const void>::type;

    using difference_type = typename _Diff<_Alloc, pointer>::type;

    using size_type = typename _Size<_Alloc, difference_type>::type;

    using propagate_on_container_copy_assignment =
        __detected_or_t<false_type, __pocca, _Alloc>;

    using propagate_on_container_move_assignment =
        __detected_or_t<false_type, __pocma, _Alloc>;

    using propagate_on_container_swap =
        __detected_or_t<false_type, __pocs, _Alloc>;

    using is_always_equal =
        __detected_or_t<typename is_empty<_Alloc>::type, __equal, _Alloc>;

    template <typename _Tp>
    using rebind_alloc = __alloc_rebind<_Alloc, _Tp>;
    template <typename _Tp>
    using rebind_traits = allocator_traits<rebind_alloc<_Tp>>;

   private:
    template <typename _Alloc2>
    static auto _S_allocate(_Alloc2& __a,
                            size_type __n,
                            const_void_pointer __hint,
                            int) -> decltype(__a.allocate(__n, __hint)) {
      return __a.allocate(__n, __hint);
    }

    template <typename _Alloc2>
    static pointer _S_allocate(_Alloc2& __a,
                               size_type __n,
                               const_void_pointer,
                               ...) {
      return __a.allocate(__n);
    }

    template <typename _Tp, typename... _Args>
    struct __construct_helper {
      template <typename _Alloc2,
                typename = decltype(std::declval<_Alloc2*>()->construct(
                    std::declval<_Tp*>(),
                    std::declval<_Args>()...))>
      static true_type __test(int);

      template <typename>
      static false_type __test(...);

      using type = decltype(__test<_Alloc>(0));
    };

    template <typename _Tp, typename... _Args>
    using __has_construct = typename __construct_helper<_Tp, _Args...>::type;

    template <typename _Tp, typename... _Args>
    static _Require<__has_construct<_Tp, _Args...>>
    _S_construct(_Alloc& __a, _Tp* __p, _Args&&... __args) {
      __a.construct(__p, std::forward<_Args>(__args)...);
    }

    template <typename _Tp, typename... _Args>
    static _Require<__and_<__not_<__has_construct<_Tp, _Args...>>,
                           is_constructible<_Tp, _Args...>>>
    _S_construct(_Alloc&, _Tp* __p, _Args&&... __args) {
      ::new ((void*)__p) _Tp(std::forward<_Args>(__args)...);
    }

    template <typename _Alloc2, typename _Tp>
    static auto _S_destroy(_Alloc2& __a, _Tp* __p, int)
        -> decltype(__a.destroy(__p)) {
      __a.destroy(__p);
    }

    template <typename _Alloc2, typename _Tp>
    static void _S_destroy(_Alloc2&, _Tp* __p, ...) {
      __p->~_Tp();
    }

    template <typename _Alloc2>
    static auto _S_max_size(_Alloc2& __a, int) -> decltype(__a.max_size()) {
      return __a.max_size();
    }

    template <typename _Alloc2>
    static size_type _S_max_size(_Alloc2&, ...) {
      return __gnu_cxx::__numeric_traits<size_type>::__max / sizeof(value_type);
    }

    template <typename _Alloc2>
    static auto _S_select(_Alloc2& __a, int)
        -> decltype(__a.select_on_container_copy_construction()) {
      return __a.select_on_container_copy_construction();
    }

    template <typename _Alloc2>
    static _Alloc2 _S_select(_Alloc2& __a, ...) {
      return __a;
    }

   public:
    static pointer allocate(_Alloc& __a, size_type __n) {
      return __a.allocate(__n);
    }
    static pointer allocate(_Alloc& __a,
                            size_type __n,
                            const_void_pointer __hint) {
      return _S_allocate(__a, __n, __hint, 0);
    }
    static void deallocate(_Alloc& __a, pointer __p, size_type __n) {
      __a.deallocate(__p, __n);
    }
    template <typename _Tp, typename... _Args>
    static auto construct(_Alloc& __a, _Tp* __p, _Args&&... __args)
        -> decltype(_S_construct(__a, __p, std::forward<_Args>(__args)...)) {
      _S_construct(__a, __p, std::forward<_Args>(__args)...);
    }
    template <typename _Tp>
    static void destroy(_Alloc& __a, _Tp* __p) {
      _S_destroy(__a, __p, 0);
    }
    static size_type max_size(const _Alloc& __a) noexcept {
      return _S_max_size(__a, 0);
    }
    static _Alloc select_on_container_copy_construction(const _Alloc& __rhs) {
      return _S_select(__rhs, 0);
    }
  };

  template <typename _Tp>
  struct allocator_traits<allocator<_Tp>> {
    using allocator_type = allocator<_Tp>;

    using value_type = _Tp;

    using pointer = _Tp*;

    using const_pointer = const _Tp*;

    using void_pointer = void*;

    using const_void_pointer = const void*;

    using difference_type = std::ptrdiff_t;

    using size_type = std::size_t;

    using propagate_on_container_copy_assignment = false_type;

    using propagate_on_container_move_assignment = true_type;

    using propagate_on_container_swap = false_type;

    using is_always_equal = true_type;

    template <typename _Up>
    using rebind_alloc = allocator<_Up>;

    template <typename _Up>
    using rebind_traits = allocator_traits<allocator<_Up>>;
    static pointer allocate(allocator_type& __a, size_type __n) {
      return __a.allocate(__n);
    }
    static pointer allocate(allocator_type& __a,
                            size_type __n,
                            const_void_pointer __hint) {
      return __a.allocate(__n, __hint);
    }
    static void deallocate(allocator_type& __a, pointer __p, size_type __n) {
      __a.deallocate(__p, __n);
    }
    template <typename _Up, typename... _Args>
    static void construct(allocator_type& __a, _Up* __p, _Args&&... __args) {
      __a.construct(__p, std::forward<_Args>(__args)...);
    }
    template <typename _Up>
    static void destroy(allocator_type& __a, _Up* __p) {
      __a.destroy(__p);
    }

    static size_type max_size(const allocator_type& __a) noexcept {
      return __a.max_size();
    }

    static allocator_type select_on_container_copy_construction(
        const allocator_type& __rhs) {
      return __rhs;
    }
  };

  template <typename _Alloc>
  inline void __do_alloc_on_copy(_Alloc & __one, const _Alloc& __two,
                                 true_type) {
    __one = __two;
  }

  template <typename _Alloc>
  inline void __do_alloc_on_copy(_Alloc&, const _Alloc&, false_type) {}

  template <typename _Alloc>
  inline void __alloc_on_copy(_Alloc & __one, const _Alloc& __two) {
    typedef allocator_traits<_Alloc> __traits;
    typedef typename __traits::propagate_on_container_copy_assignment __pocca;
    __do_alloc_on_copy(__one, __two, __pocca());
  }

  template <typename _Alloc>
  inline _Alloc __alloc_on_copy(const _Alloc& __a) {
    typedef allocator_traits<_Alloc> __traits;
    return __traits::select_on_container_copy_construction(__a);
  }

  template <typename _Alloc>
  inline void __do_alloc_on_move(_Alloc & __one, _Alloc & __two, true_type) {
    __one = std::move(__two);
  }

  template <typename _Alloc>
  inline void __do_alloc_on_move(_Alloc&, _Alloc&, false_type) {}

  template <typename _Alloc>
  inline void __alloc_on_move(_Alloc & __one, _Alloc & __two) {
    typedef allocator_traits<_Alloc> __traits;
    typedef typename __traits::propagate_on_container_move_assignment __pocma;
    __do_alloc_on_move(__one, __two, __pocma());
  }

  template <typename _Alloc>
  inline void __do_alloc_on_swap(_Alloc & __one, _Alloc & __two, true_type) {
    using std::swap;
    swap(__one, __two);
  }

  template <typename _Alloc>
  inline void __do_alloc_on_swap(_Alloc&, _Alloc&, false_type) {}

  template <typename _Alloc>
  inline void __alloc_on_swap(_Alloc & __one, _Alloc & __two) {
    typedef allocator_traits<_Alloc> __traits;
    typedef typename __traits::propagate_on_container_swap __pocs;
    __do_alloc_on_swap(__one, __two, __pocs());
  }

  template <typename _Alloc>
  class __is_copy_insertable_impl {
    typedef allocator_traits<_Alloc> _Traits;

    template <
        typename _Up,
        typename = decltype(_Traits::construct(std::declval<_Alloc&>(),
                                               std::declval<_Up*>(),
                                               std::declval<const _Up&>()))>
    static true_type _M_select(int);

    template <typename _Up>
    static false_type _M_select(...);

   public:
    typedef decltype(_M_select<typename _Alloc::value_type>(0)) type;
  };

  template <typename _Alloc>
  struct __is_copy_insertable : __is_copy_insertable_impl<_Alloc>::type {};

  template <typename _Tp>
  struct __is_copy_insertable<allocator<_Tp>> : is_copy_constructible<_Tp> {};

}  // namespace std__attribute__((__visibility__("default")))

namespace __gnu_cxx __attribute__((__visibility__("default"))) {

  template <typename _Alloc>
  struct __alloc_traits

      : std::allocator_traits<_Alloc>

  {
    typedef _Alloc allocator_type;

    typedef std::allocator_traits<_Alloc> _Base_type;
    typedef typename _Base_type::value_type value_type;
    typedef typename _Base_type::pointer pointer;
    typedef typename _Base_type::const_pointer const_pointer;
    typedef typename _Base_type::size_type size_type;
    typedef typename _Base_type::difference_type difference_type;

    typedef value_type& reference;
    typedef const value_type& const_reference;
    using _Base_type::allocate;
    using _Base_type::construct;
    using _Base_type::deallocate;
    using _Base_type::destroy;
    using _Base_type::max_size;

   private:
    template <typename _Ptr>
    using __is_custom_pointer = std::__and_<std::is_same<pointer, _Ptr>,
                                            std::__not_<std::is_pointer<_Ptr>>>;

   public:
    template <typename _Ptr, typename... _Args>
    static typename std::enable_if<__is_custom_pointer<_Ptr>::value>::type
    construct(_Alloc& __a, _Ptr __p, _Args&&... __args) {
      _Base_type::construct(__a, std::addressof(*__p),
                            std::forward<_Args>(__args)...);
    }

    template <typename _Ptr>
    static typename std::enable_if<__is_custom_pointer<_Ptr>::value>::type
    destroy(_Alloc& __a, _Ptr __p) {
      _Base_type::destroy(__a, std::addressof(*__p));
    }

    static _Alloc _S_select_on_copy(const _Alloc& __a) {
      return _Base_type::select_on_container_copy_construction(__a);
    }

    static void _S_on_swap(_Alloc& __a, _Alloc& __b) {
      std::__alloc_on_swap(__a, __b);
    }

    static constexpr bool _S_propagate_on_copy_assign() {
      return _Base_type::propagate_on_container_copy_assignment::value;
    }

    static constexpr bool _S_propagate_on_move_assign() {
      return _Base_type::propagate_on_container_move_assignment::value;
    }

    static constexpr bool _S_propagate_on_swap() {
      return _Base_type::propagate_on_container_swap::value;
    }

    static constexpr bool _S_always_equal() {
      return _Base_type::is_always_equal::value;
    }

    static constexpr bool _S_nothrow_move() {
      return _S_propagate_on_move_assign() || _S_always_equal();
    }

    template <typename _Tp>
    struct rebind {
      typedef typename _Base_type::template rebind_alloc<_Tp> other;
    };
  };

}  // namespace __gnu_cxx__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <typename _T1, typename... _Args>
  inline void _Construct(_T1 * __p, _Args && ... __args) {
    ::new (static_cast<void*>(__p)) _T1(std::forward<_Args>(__args)...);
  }
  template <typename _T1>
  inline void _Construct_novalue(_T1 * __p) {
    ::new (static_cast<void*>(__p)) _T1;
  }

  template <typename _Tp>
  inline void _Destroy(_Tp * __pointer) {
    __pointer->~_Tp();
  }

  template <bool>
  struct _Destroy_aux {
    template <typename _ForwardIterator>
    static void __destroy(_ForwardIterator __first, _ForwardIterator __last) {
      for (; __first != __last; ++__first)
        std::_Destroy(std::__addressof(*__first));
    }
  };

  template <>
  struct _Destroy_aux<true> {
    template <typename _ForwardIterator>
    static void __destroy(_ForwardIterator, _ForwardIterator) {}
  };

  template <typename _ForwardIterator>
  inline void _Destroy(_ForwardIterator __first, _ForwardIterator __last) {
    typedef typename iterator_traits<_ForwardIterator>::value_type _Value_type;

    static_assert(is_destructible<_Value_type>::value,
                  "value type is destructible");

    std::_Destroy_aux<__has_trivial_destructor(_Value_type)>::__destroy(__first,
                                                                        __last);
  }

  template <bool>
  struct _Destroy_n_aux {
    template <typename _ForwardIterator, typename _Size>
    static _ForwardIterator __destroy_n(_ForwardIterator __first,
                                        _Size __count) {
      for (; __count > 0; (void)++__first, --__count)
        std::_Destroy(std::__addressof(*__first));
      return __first;
    }
  };

  template <>
  struct _Destroy_n_aux<true> {
    template <typename _ForwardIterator, typename _Size>
    static _ForwardIterator __destroy_n(_ForwardIterator __first,
                                        _Size __count) {
      std::advance(__first, __count);
      return __first;
    }
  };

  template <typename _ForwardIterator, typename _Size>
  inline _ForwardIterator _Destroy_n(_ForwardIterator __first, _Size __count) {
    typedef typename iterator_traits<_ForwardIterator>::value_type _Value_type;

    static_assert(is_destructible<_Value_type>::value,
                  "value type is destructible");

    return std::_Destroy_n_aux<__has_trivial_destructor(
        _Value_type)>::__destroy_n(__first, __count);
  }

  template <typename _ForwardIterator, typename _Allocator>
  void _Destroy(_ForwardIterator __first, _ForwardIterator __last,
                _Allocator & __alloc) {
    typedef __gnu_cxx::__alloc_traits<_Allocator> __traits;
    for (; __first != __last; ++__first)
      __traits::destroy(__alloc, std::__addressof(*__first));
  }

  template <typename _ForwardIterator, typename _Tp>
  inline void _Destroy(_ForwardIterator __first, _ForwardIterator __last,
                       allocator<_Tp>&) {
    _Destroy(__first, __last);
  }

}  // namespace std__attribute__((__visibility__("default")))
namespace std __attribute__((__visibility__("default"))) {

  template <bool _TrivialValueTypes>
  struct __uninitialized_copy {
    template <typename _InputIterator, typename _ForwardIterator>
    static _ForwardIterator __uninit_copy(_InputIterator __first,
                                          _InputIterator __last,
                                          _ForwardIterator __result) {
      _ForwardIterator __cur = __result;
      try {
        for (; __first != __last; ++__first, (void)++__cur)
          std::_Construct(std::__addressof(*__cur), *__first);
        return __cur;
      } catch (...) {
        std::_Destroy(__result, __cur);
        throw;
      }
    }
  };

  template <>
  struct __uninitialized_copy<true> {
    template <typename _InputIterator, typename _ForwardIterator>
    static _ForwardIterator __uninit_copy(_InputIterator __first,
                                          _InputIterator __last,
                                          _ForwardIterator __result) {
      return std::copy(__first, __last, __result);
    }
  };
  template <typename _InputIterator, typename _ForwardIterator>
  inline _ForwardIterator uninitialized_copy(_InputIterator __first,
                                             _InputIterator __last,
                                             _ForwardIterator __result) {
    typedef typename iterator_traits<_InputIterator>::value_type _ValueType1;
    typedef typename iterator_traits<_ForwardIterator>::value_type _ValueType2;

    typedef typename iterator_traits<_InputIterator>::reference _RefType1;
    typedef typename iterator_traits<_ForwardIterator>::reference _RefType2;
    const bool __assignable = is_assignable<_RefType2, _RefType1>::value;

    return std::__uninitialized_copy < __is_trivial(_ValueType1) &&
           __is_trivial(_ValueType2) &&
           __assignable > ::__uninit_copy(__first, __last, __result);
  }

  template <bool _TrivialValueType>
  struct __uninitialized_fill {
    template <typename _ForwardIterator, typename _Tp>
    static void __uninit_fill(_ForwardIterator __first,
                              _ForwardIterator __last,
                              const _Tp& __x) {
      _ForwardIterator __cur = __first;
      try {
        for (; __cur != __last; ++__cur)
          std::_Construct(std::__addressof(*__cur), __x);
      } catch (...) {
        std::_Destroy(__first, __cur);
        throw;
      }
    }
  };

  template <>
  struct __uninitialized_fill<true> {
    template <typename _ForwardIterator, typename _Tp>
    static void __uninit_fill(_ForwardIterator __first,
                              _ForwardIterator __last,
                              const _Tp& __x) {
      std::fill(__first, __last, __x);
    }
  };
  template <typename _ForwardIterator, typename _Tp>
  inline void uninitialized_fill(_ForwardIterator __first,
                                 _ForwardIterator __last, const _Tp& __x) {
    typedef typename iterator_traits<_ForwardIterator>::value_type _ValueType;

    const bool __assignable = is_copy_assignable<_ValueType>::value;

    std::__uninitialized_fill<__is_trivial(_ValueType) &&
                              __assignable>::__uninit_fill(__first, __last,
                                                           __x);
  }

  template <bool _TrivialValueType>
  struct __uninitialized_fill_n {
    template <typename _ForwardIterator, typename _Size, typename _Tp>
    static _ForwardIterator __uninit_fill_n(_ForwardIterator __first,
                                            _Size __n,
                                            const _Tp& __x) {
      _ForwardIterator __cur = __first;
      try {
        for (; __n > 0; --__n, ++__cur)
          std::_Construct(std::__addressof(*__cur), __x);
        return __cur;
      } catch (...) {
        std::_Destroy(__first, __cur);
        throw;
      }
    }
  };

  template <>
  struct __uninitialized_fill_n<true> {
    template <typename _ForwardIterator, typename _Size, typename _Tp>
    static _ForwardIterator __uninit_fill_n(_ForwardIterator __first,
                                            _Size __n,
                                            const _Tp& __x) {
      return std::fill_n(__first, __n, __x);
    }
  };
  template <typename _ForwardIterator, typename _Size, typename _Tp>
  inline _ForwardIterator uninitialized_fill_n(_ForwardIterator __first,
                                               _Size __n, const _Tp& __x) {
    typedef typename iterator_traits<_ForwardIterator>::value_type _ValueType;

    const bool __assignable = is_copy_assignable<_ValueType>::value;

    return __uninitialized_fill_n < __is_trivial(_ValueType) &&
           __assignable > ::__uninit_fill_n(__first, __n, __x);
  }

  template <typename _InputIterator, typename _ForwardIterator,
            typename _Allocator>
  _ForwardIterator __uninitialized_copy_a(
      _InputIterator __first, _InputIterator __last, _ForwardIterator __result,
      _Allocator & __alloc) {
    _ForwardIterator __cur = __result;
    try {
      typedef __gnu_cxx::__alloc_traits<_Allocator> __traits;
      for (; __first != __last; ++__first, (void)++__cur)
        __traits::construct(__alloc, std::__addressof(*__cur), *__first);
      return __cur;
    } catch (...) {
      std::_Destroy(__result, __cur, __alloc);
      throw;
    }
  }

  template <typename _InputIterator, typename _ForwardIterator, typename _Tp>
  inline _ForwardIterator __uninitialized_copy_a(
      _InputIterator __first, _InputIterator __last, _ForwardIterator __result,
      allocator<_Tp>&) {
    return std::uninitialized_copy(__first, __last, __result);
  }

  template <typename _InputIterator, typename _ForwardIterator,
            typename _Allocator>
  inline _ForwardIterator __uninitialized_move_a(
      _InputIterator __first, _InputIterator __last, _ForwardIterator __result,
      _Allocator & __alloc) {
    return std::__uninitialized_copy_a(std::make_move_iterator(__first),
                                       std::make_move_iterator(__last),
                                       __result, __alloc);
  }

  template <typename _InputIterator, typename _ForwardIterator,
            typename _Allocator>
  inline _ForwardIterator __uninitialized_move_if_noexcept_a(
      _InputIterator __first, _InputIterator __last, _ForwardIterator __result,
      _Allocator & __alloc) {
    return std::__uninitialized_copy_a(
        std::__make_move_if_noexcept_iterator(__first),
        std::__make_move_if_noexcept_iterator(__last), __result, __alloc);
  }

  template <typename _ForwardIterator, typename _Tp, typename _Allocator>
  void __uninitialized_fill_a(_ForwardIterator __first, _ForwardIterator __last,
                              const _Tp& __x, _Allocator& __alloc) {
    _ForwardIterator __cur = __first;
    try {
      typedef __gnu_cxx::__alloc_traits<_Allocator> __traits;
      for (; __cur != __last; ++__cur)
        __traits::construct(__alloc, std::__addressof(*__cur), __x);
    } catch (...) {
      std::_Destroy(__first, __cur, __alloc);
      throw;
    }
  }

  template <typename _ForwardIterator, typename _Tp, typename _Tp2>
  inline void __uninitialized_fill_a(_ForwardIterator __first,
                                     _ForwardIterator __last, const _Tp& __x,
                                     allocator<_Tp2>&) {
    std::uninitialized_fill(__first, __last, __x);
  }

  template <typename _ForwardIterator, typename _Size, typename _Tp,
            typename _Allocator>
  _ForwardIterator __uninitialized_fill_n_a(_ForwardIterator __first, _Size __n,
                                            const _Tp& __x,
                                            _Allocator& __alloc) {
    _ForwardIterator __cur = __first;
    try {
      typedef __gnu_cxx::__alloc_traits<_Allocator> __traits;
      for (; __n > 0; --__n, ++__cur)
        __traits::construct(__alloc, std::__addressof(*__cur), __x);
      return __cur;
    } catch (...) {
      std::_Destroy(__first, __cur, __alloc);
      throw;
    }
  }

  template <typename _ForwardIterator, typename _Size, typename _Tp,
            typename _Tp2>
  inline _ForwardIterator __uninitialized_fill_n_a(
      _ForwardIterator __first, _Size __n, const _Tp& __x, allocator<_Tp2>&) {
    return std::uninitialized_fill_n(__first, __n, __x);
  }
  template <typename _InputIterator1, typename _InputIterator2,
            typename _ForwardIterator, typename _Allocator>
  inline _ForwardIterator __uninitialized_copy_move(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2,
      _ForwardIterator __result, _Allocator & __alloc) {
    _ForwardIterator __mid =
        std::__uninitialized_copy_a(__first1, __last1, __result, __alloc);
    try {
      return std::__uninitialized_move_a(__first2, __last2, __mid, __alloc);
    } catch (...) {
      std::_Destroy(__result, __mid, __alloc);
      throw;
    }
  }

  template <typename _InputIterator1, typename _InputIterator2,
            typename _ForwardIterator, typename _Allocator>
  inline _ForwardIterator __uninitialized_move_copy(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2,
      _ForwardIterator __result, _Allocator & __alloc) {
    _ForwardIterator __mid =
        std::__uninitialized_move_a(__first1, __last1, __result, __alloc);
    try {
      return std::__uninitialized_copy_a(__first2, __last2, __mid, __alloc);
    } catch (...) {
      std::_Destroy(__result, __mid, __alloc);
      throw;
    }
  }

  template <typename _ForwardIterator, typename _Tp, typename _InputIterator,
            typename _Allocator>
  inline _ForwardIterator __uninitialized_fill_move(
      _ForwardIterator __result, _ForwardIterator __mid, const _Tp& __x,
      _InputIterator __first, _InputIterator __last, _Allocator& __alloc) {
    std::__uninitialized_fill_a(__result, __mid, __x, __alloc);
    try {
      return std::__uninitialized_move_a(__first, __last, __mid, __alloc);
    } catch (...) {
      std::_Destroy(__result, __mid, __alloc);
      throw;
    }
  }

  template <typename _InputIterator, typename _ForwardIterator, typename _Tp,
            typename _Allocator>
  inline void __uninitialized_move_fill(
      _InputIterator __first1, _InputIterator __last1,
      _ForwardIterator __first2, _ForwardIterator __last2, const _Tp& __x,
      _Allocator& __alloc) {
    _ForwardIterator __mid2 =
        std::__uninitialized_move_a(__first1, __last1, __first2, __alloc);
    try {
      std::__uninitialized_fill_a(__mid2, __last2, __x, __alloc);
    } catch (...) {
      std::_Destroy(__first2, __mid2, __alloc);
      throw;
    }
  }

  template <bool _TrivialValueType>
  struct __uninitialized_default_1 {
    template <typename _ForwardIterator>
    static void __uninit_default(_ForwardIterator __first,
                                 _ForwardIterator __last) {
      _ForwardIterator __cur = __first;
      try {
        for (; __cur != __last; ++__cur)
          std::_Construct(std::__addressof(*__cur));
      } catch (...) {
        std::_Destroy(__first, __cur);
        throw;
      }
    }
  };

  template <>
  struct __uninitialized_default_1<true> {
    template <typename _ForwardIterator>
    static void __uninit_default(_ForwardIterator __first,
                                 _ForwardIterator __last) {
      typedef typename iterator_traits<_ForwardIterator>::value_type _ValueType;

      std::fill(__first, __last, _ValueType());
    }
  };

  template <bool _TrivialValueType>
  struct __uninitialized_default_n_1 {
    template <typename _ForwardIterator, typename _Size>
    static _ForwardIterator __uninit_default_n(_ForwardIterator __first,
                                               _Size __n) {
      _ForwardIterator __cur = __first;
      try {
        for (; __n > 0; --__n, ++__cur)
          std::_Construct(std::__addressof(*__cur));
        return __cur;
      } catch (...) {
        std::_Destroy(__first, __cur);
        throw;
      }
    }
  };

  template <>
  struct __uninitialized_default_n_1<true> {
    template <typename _ForwardIterator, typename _Size>
    static _ForwardIterator __uninit_default_n(_ForwardIterator __first,
                                               _Size __n) {
      typedef typename iterator_traits<_ForwardIterator>::value_type _ValueType;

      return std::fill_n(__first, __n, _ValueType());
    }
  };

  template <typename _ForwardIterator>
  inline void __uninitialized_default(_ForwardIterator __first,
                                      _ForwardIterator __last) {
    typedef typename iterator_traits<_ForwardIterator>::value_type _ValueType;

    const bool __assignable = is_copy_assignable<_ValueType>::value;

    std::__uninitialized_default_1<__is_trivial(_ValueType) &&
                                   __assignable>::__uninit_default(__first,
                                                                   __last);
  }

  template <typename _ForwardIterator, typename _Size>
  inline _ForwardIterator __uninitialized_default_n(_ForwardIterator __first,
                                                    _Size __n) {
    typedef typename iterator_traits<_ForwardIterator>::value_type _ValueType;

    const bool __assignable = is_copy_assignable<_ValueType>::value;

    return __uninitialized_default_n_1 < __is_trivial(_ValueType) &&
           __assignable > ::__uninit_default_n(__first, __n);
  }

  template <typename _ForwardIterator, typename _Allocator>
  void __uninitialized_default_a(
      _ForwardIterator __first, _ForwardIterator __last, _Allocator & __alloc) {
    _ForwardIterator __cur = __first;
    try {
      typedef __gnu_cxx::__alloc_traits<_Allocator> __traits;
      for (; __cur != __last; ++__cur)
        __traits::construct(__alloc, std::__addressof(*__cur));
    } catch (...) {
      std::_Destroy(__first, __cur, __alloc);
      throw;
    }
  }

  template <typename _ForwardIterator, typename _Tp>
  inline void __uninitialized_default_a(
      _ForwardIterator __first, _ForwardIterator __last, allocator<_Tp>&) {
    std::__uninitialized_default(__first, __last);
  }

  template <typename _ForwardIterator, typename _Size, typename _Allocator>
  _ForwardIterator __uninitialized_default_n_a(
      _ForwardIterator __first, _Size __n, _Allocator & __alloc) {
    _ForwardIterator __cur = __first;
    try {
      typedef __gnu_cxx::__alloc_traits<_Allocator> __traits;
      for (; __n > 0; --__n, ++__cur)
        __traits::construct(__alloc, std::__addressof(*__cur));
      return __cur;
    } catch (...) {
      std::_Destroy(__first, __cur, __alloc);
      throw;
    }
  }

  template <typename _ForwardIterator, typename _Size, typename _Tp>
  inline _ForwardIterator __uninitialized_default_n_a(
      _ForwardIterator __first, _Size __n, allocator<_Tp>&) {
    return std::__uninitialized_default_n(__first, __n);
  }

  template <bool _TrivialValueType>
  struct __uninitialized_default_novalue_1 {
    template <typename _ForwardIterator>
    static void __uninit_default_novalue(_ForwardIterator __first,
                                         _ForwardIterator __last) {
      _ForwardIterator __cur = __first;
      try {
        for (; __cur != __last; ++__cur)
          std::_Construct_novalue(std::__addressof(*__cur));
      } catch (...) {
        std::_Destroy(__first, __cur);
        throw;
      }
    }
  };

  template <>
  struct __uninitialized_default_novalue_1<true> {
    template <typename _ForwardIterator>
    static void __uninit_default_novalue(_ForwardIterator __first,
                                         _ForwardIterator __last) {}
  };

  template <bool _TrivialValueType>
  struct __uninitialized_default_novalue_n_1 {
    template <typename _ForwardIterator, typename _Size>
    static _ForwardIterator __uninit_default_novalue_n(_ForwardIterator __first,
                                                       _Size __n) {
      _ForwardIterator __cur = __first;
      try {
        for (; __n > 0; --__n, ++__cur)
          std::_Construct_novalue(std::__addressof(*__cur));
        return __cur;
      } catch (...) {
        std::_Destroy(__first, __cur);
        throw;
      }
    }
  };

  template <>
  struct __uninitialized_default_novalue_n_1<true> {
    template <typename _ForwardIterator, typename _Size>
    static _ForwardIterator __uninit_default_novalue_n(_ForwardIterator __first,
                                                       _Size __n) {
      return std::next(__first, __n);
    }
  };

  template <typename _ForwardIterator>
  inline void __uninitialized_default_novalue(_ForwardIterator __first,
                                              _ForwardIterator __last) {
    typedef typename iterator_traits<_ForwardIterator>::value_type _ValueType;

    std::__uninitialized_default_novalue_1<is_trivially_default_constructible<
        _ValueType>::value>::__uninit_default_novalue(__first, __last);
  }

  template <typename _ForwardIterator, typename _Size>
  inline _ForwardIterator __uninitialized_default_novalue_n(
      _ForwardIterator __first, _Size __n) {
    typedef typename iterator_traits<_ForwardIterator>::value_type _ValueType;

    return __uninitialized_default_novalue_n_1<
        is_trivially_default_constructible<_ValueType>::value>::
        __uninit_default_novalue_n(__first, __n);
  }

  template <typename _InputIterator, typename _Size, typename _ForwardIterator>
  _ForwardIterator __uninitialized_copy_n(_InputIterator __first, _Size __n,
                                          _ForwardIterator __result,
                                          input_iterator_tag) {
    _ForwardIterator __cur = __result;
    try {
      for (; __n > 0; --__n, ++__first, ++__cur)
        std::_Construct(std::__addressof(*__cur), *__first);
      return __cur;
    } catch (...) {
      std::_Destroy(__result, __cur);
      throw;
    }
  }

  template <typename _RandomAccessIterator, typename _Size,
            typename _ForwardIterator>
  inline _ForwardIterator __uninitialized_copy_n(
      _RandomAccessIterator __first, _Size __n, _ForwardIterator __result,
      random_access_iterator_tag) {
    return std::uninitialized_copy(__first, __first + __n, __result);
  }

  template <typename _InputIterator, typename _Size, typename _ForwardIterator>
  pair<_InputIterator, _ForwardIterator> __uninitialized_copy_n_pair(
      _InputIterator __first, _Size __n, _ForwardIterator __result,
      input_iterator_tag) {
    _ForwardIterator __cur = __result;
    try {
      for (; __n > 0; --__n, ++__first, ++__cur)
        std::_Construct(std::__addressof(*__cur), *__first);
      return {__first, __cur};
    } catch (...) {
      std::_Destroy(__result, __cur);
      throw;
    }
  }

  template <typename _RandomAccessIterator, typename _Size,
            typename _ForwardIterator>
  inline pair<_RandomAccessIterator, _ForwardIterator>
  __uninitialized_copy_n_pair(_RandomAccessIterator __first, _Size __n,
                              _ForwardIterator __result,
                              random_access_iterator_tag) {
    auto __second_res = uninitialized_copy(__first, __first + __n, __result);
    auto __first_res = std::next(__first, __n);
    return {__first_res, __second_res};
  }
  template <typename _InputIterator, typename _Size, typename _ForwardIterator>
  inline _ForwardIterator uninitialized_copy_n(
      _InputIterator __first, _Size __n, _ForwardIterator __result) {
    return std::__uninitialized_copy_n(__first, __n, __result,
                                       std::__iterator_category(__first));
  }

  template <typename _InputIterator, typename _Size, typename _ForwardIterator>
  inline pair<_InputIterator, _ForwardIterator> __uninitialized_copy_n_pair(
      _InputIterator __first, _Size __n, _ForwardIterator __result) {
    return std::__uninitialized_copy_n_pair(__first, __n, __result,
                                            std::__iterator_category(__first));
  }

}  // namespace std__attribute__((__visibility__("default")))

#pragma GCC visibility push(default)

namespace std {

template <class _E>
class initializer_list {
 public:
  typedef _E value_type;
  typedef const _E& reference;
  typedef const _E& const_reference;
  typedef size_t size_type;
  typedef const _E* iterator;
  typedef const _E* const_iterator;

 private:
  iterator _M_array;
  size_type _M_len;

  constexpr initializer_list(const_iterator __a, size_type __l)
      : _M_array(__a), _M_len(__l) {}

 public:
  constexpr initializer_list() noexcept : _M_array(0), _M_len(0) {}

  constexpr size_type size() const noexcept { return _M_len; }

  constexpr const_iterator begin() const noexcept { return _M_array; }

  constexpr const_iterator end() const noexcept { return begin() + size(); }
};

template <class _Tp>
constexpr const _Tp* begin(initializer_list<_Tp> __ils) noexcept {
  return __ils.begin();
}

template <class _Tp>
constexpr const _Tp* end(initializer_list<_Tp> __ils) noexcept {
  return __ils.end();
}
}  // namespace std

#pragma GCC visibility pop

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Tp, typename _Alloc>
  struct _Vector_base {
    typedef
        typename __gnu_cxx::__alloc_traits<_Alloc>::template rebind<_Tp>::other
            _Tp_alloc_type;
    typedef typename __gnu_cxx::__alloc_traits<_Tp_alloc_type>::pointer pointer;

    struct _Vector_impl : public _Tp_alloc_type {
      pointer _M_start;
      pointer _M_finish;
      pointer _M_end_of_storage;

      _Vector_impl()
          : _Tp_alloc_type(), _M_start(), _M_finish(), _M_end_of_storage() {}

      _Vector_impl(_Tp_alloc_type const& __a) noexcept
          : _Tp_alloc_type(__a), _M_start(), _M_finish(), _M_end_of_storage() {}

      _Vector_impl(_Tp_alloc_type&& __a) noexcept
          : _Tp_alloc_type(std::move(__a)),
            _M_start(),
            _M_finish(),
            _M_end_of_storage() {}

      void _M_swap_data(_Vector_impl& __x) noexcept {
        std::swap(_M_start, __x._M_start);
        std::swap(_M_finish, __x._M_finish);
        std::swap(_M_end_of_storage, __x._M_end_of_storage);
      }
    };

   public:
    typedef _Alloc allocator_type;

    _Tp_alloc_type& _M_get_Tp_allocator() noexcept {
      return *static_cast<_Tp_alloc_type*>(&this->_M_impl);
    }

    const _Tp_alloc_type& _M_get_Tp_allocator() const noexcept {
      return *static_cast<const _Tp_alloc_type*>(&this->_M_impl);
    }

    allocator_type get_allocator() const noexcept {
      return allocator_type(_M_get_Tp_allocator());
    }

    _Vector_base() : _M_impl() {}

    _Vector_base(const allocator_type& __a) noexcept : _M_impl(__a) {}

    _Vector_base(size_t __n) : _M_impl() { _M_create_storage(__n); }

    _Vector_base(size_t __n, const allocator_type& __a) : _M_impl(__a) {
      _M_create_storage(__n);
    }

    _Vector_base(_Tp_alloc_type&& __a) noexcept : _M_impl(std::move(__a)) {}

    _Vector_base(_Vector_base&& __x) noexcept
        : _M_impl(std::move(__x._M_get_Tp_allocator())) {
      this->_M_impl._M_swap_data(__x._M_impl);
    }

    _Vector_base(_Vector_base&& __x, const allocator_type& __a) : _M_impl(__a) {
      if (__x.get_allocator() == __a)
        this->_M_impl._M_swap_data(__x._M_impl);
      else {
        size_t __n = __x._M_impl._M_finish - __x._M_impl._M_start;
        _M_create_storage(__n);
      }
    }

    ~_Vector_base() noexcept {
      _M_deallocate(this->_M_impl._M_start,
                    this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
    }

   public:
    _Vector_impl _M_impl;

    pointer _M_allocate(size_t __n) {
      typedef __gnu_cxx::__alloc_traits<_Tp_alloc_type> _Tr;
      return __n != 0 ? _Tr::allocate(_M_impl, __n) : pointer();
    }

    void _M_deallocate(pointer __p, size_t __n) {
      typedef __gnu_cxx::__alloc_traits<_Tp_alloc_type> _Tr;
      if (__p)
        _Tr::deallocate(_M_impl, __p, __n);
    }

   private:
    void _M_create_storage(size_t __n) {
      this->_M_impl._M_start = this->_M_allocate(__n);
      this->_M_impl._M_finish = this->_M_impl._M_start;
      this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
    }
  };
  template <typename _Tp, typename _Alloc = std::allocator<_Tp>>
  class vector : protected _Vector_base<_Tp, _Alloc> {
    typedef _Vector_base<_Tp, _Alloc> _Base;
    typedef typename _Base::_Tp_alloc_type _Tp_alloc_type;
    typedef __gnu_cxx::__alloc_traits<_Tp_alloc_type> _Alloc_traits;

   public:
    typedef _Tp value_type;
    typedef typename _Base::pointer pointer;
    typedef typename _Alloc_traits::const_pointer const_pointer;
    typedef typename _Alloc_traits::reference reference;
    typedef typename _Alloc_traits::const_reference const_reference;
    typedef __gnu_cxx::__normal_iterator<pointer, vector> iterator;
    typedef __gnu_cxx::__normal_iterator<const_pointer, vector> const_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef _Alloc allocator_type;

   protected:
    using _Base::_M_allocate;
    using _Base::_M_deallocate;
    using _Base::_M_get_Tp_allocator;
    using _Base::_M_impl;

   public:
    vector()

        noexcept(is_nothrow_default_constructible<_Alloc>::value)

        : _Base() {}

    explicit vector(const allocator_type& __a) noexcept : _Base(__a) {}
    explicit vector(size_type __n, const allocator_type& __a = allocator_type())
        : _Base(__n, __a) {
      _M_default_initialize(__n);
    }
    vector(size_type __n,
           const value_type& __value,
           const allocator_type& __a = allocator_type())
        : _Base(__n, __a) {
      _M_fill_initialize(__n, __value);
    }
    vector(const vector& __x)
        : _Base(__x.size(),
                _Alloc_traits::_S_select_on_copy(__x._M_get_Tp_allocator())) {
      this->_M_impl._M_finish = std::__uninitialized_copy_a(
          __x.begin(), __x.end(), this->_M_impl._M_start,
          _M_get_Tp_allocator());
    }
    vector(vector&& __x) noexcept : _Base(std::move(__x)) {}

    vector(const vector& __x, const allocator_type& __a)
        : _Base(__x.size(), __a) {
      this->_M_impl._M_finish = std::__uninitialized_copy_a(
          __x.begin(), __x.end(), this->_M_impl._M_start,
          _M_get_Tp_allocator());
    }

    vector(vector&& __rv,
           const allocator_type& __m) noexcept(_Alloc_traits::_S_always_equal())
        : _Base(std::move(__rv), __m) {
      if (__rv.get_allocator() != __m) {
        this->_M_impl._M_finish = std::__uninitialized_move_a(
            __rv.begin(), __rv.end(), this->_M_impl._M_start,
            _M_get_Tp_allocator());
        __rv.clear();
      }
    }
    vector(initializer_list<value_type> __l,
           const allocator_type& __a = allocator_type())
        : _Base(__a) {
      _M_range_initialize(__l.begin(), __l.end(), random_access_iterator_tag());
    }
    template <typename _InputIterator,
              typename = std::_RequireInputIter<_InputIterator>>
    vector(_InputIterator __first,
           _InputIterator __last,
           const allocator_type& __a = allocator_type())
        : _Base(__a) {
      _M_initialize_dispatch(__first, __last, __false_type());
    }
    ~vector() noexcept {
      std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
                    _M_get_Tp_allocator());
    }
    vector& operator=(const vector& __x);
    vector& operator=(vector&& __x) noexcept(_Alloc_traits::_S_nothrow_move()) {
      constexpr bool __move_storage =
          _Alloc_traits::_S_propagate_on_move_assign() ||
          _Alloc_traits::_S_always_equal();
      _M_move_assign(std::move(__x), __bool_constant<__move_storage>());
      return *this;
    }
    vector& operator=(initializer_list<value_type> __l) {
      this->_M_assign_aux(__l.begin(), __l.end(), random_access_iterator_tag());
      return *this;
    }
    void assign(size_type __n, const value_type& __val) {
      _M_fill_assign(__n, __val);
    }
    template <typename _InputIterator,
              typename = std::_RequireInputIter<_InputIterator>>
    void assign(_InputIterator __first, _InputIterator __last) {
      _M_assign_dispatch(__first, __last, __false_type());
    }
    void assign(initializer_list<value_type> __l) {
      this->_M_assign_aux(__l.begin(), __l.end(), random_access_iterator_tag());
    }

    using _Base::get_allocator;

    iterator begin() noexcept { return iterator(this->_M_impl._M_start); }

    const_iterator begin() const noexcept {
      return const_iterator(this->_M_impl._M_start);
    }

    iterator end() noexcept { return iterator(this->_M_impl._M_finish); }

    const_iterator end() const noexcept {
      return const_iterator(this->_M_impl._M_finish);
    }

    reverse_iterator rbegin() noexcept { return reverse_iterator(end()); }

    const_reverse_iterator rbegin() const noexcept {
      return const_reverse_iterator(end());
    }

    reverse_iterator rend() noexcept { return reverse_iterator(begin()); }

    const_reverse_iterator rend() const noexcept {
      return const_reverse_iterator(begin());
    }

    const_iterator cbegin() const noexcept {
      return const_iterator(this->_M_impl._M_start);
    }

    const_iterator cend() const noexcept {
      return const_iterator(this->_M_impl._M_finish);
    }

    const_reverse_iterator crbegin() const noexcept {
      return const_reverse_iterator(end());
    }

    const_reverse_iterator crend() const noexcept {
      return const_reverse_iterator(begin());
    }

    size_type size() const noexcept {
      return size_type(this->_M_impl._M_finish - this->_M_impl._M_start);
    }

    size_type max_size() const noexcept {
      return _Alloc_traits::max_size(_M_get_Tp_allocator());
    }
    void resize(size_type __new_size) {
      if (__new_size > size())
        _M_default_append(__new_size - size());
      else if (__new_size < size())
        _M_erase_at_end(this->_M_impl._M_start + __new_size);
    }
    void resize(size_type __new_size, const value_type& __x) {
      if (__new_size > size())
        _M_fill_insert(end(), __new_size - size(), __x);
      else if (__new_size < size())
        _M_erase_at_end(this->_M_impl._M_start + __new_size);
    }
    void shrink_to_fit() { _M_shrink_to_fit(); }

    size_type capacity() const noexcept {
      return size_type(this->_M_impl._M_end_of_storage -
                       this->_M_impl._M_start);
    }

    bool empty() const noexcept { return begin() == end(); }
    void reserve(size_type __n);
    reference operator[](size_type __n) noexcept {
      ;
      return *(this->_M_impl._M_start + __n);
    }
    const_reference operator[](size_type __n) const noexcept {
      ;
      return *(this->_M_impl._M_start + __n);
    }

   protected:
    void _M_range_check(size_type __n) const {
      if (__n >= this->size())
        __throw_out_of_range_fmt(("vector::_M_range_check: __n "
                                  "(which is %zu) >= this->size() "
                                  "(which is %zu)")

                                     ,
                                 __n, this->size());
    }

   public:
    reference at(size_type __n) {
      _M_range_check(__n);
      return (*this)[__n];
    }
    const_reference at(size_type __n) const {
      _M_range_check(__n);
      return (*this)[__n];
    }

    reference front() noexcept {
      ;
      return *begin();
    }

    const_reference front() const noexcept {
      ;
      return *begin();
    }

    reference back() noexcept {
      ;
      return *(end() - 1);
    }

    const_reference back() const noexcept {
      ;
      return *(end() - 1);
    }
    _Tp* data() noexcept { return _M_data_ptr(this->_M_impl._M_start); }

    const _Tp* data() const noexcept {
      return _M_data_ptr(this->_M_impl._M_start);
    }
    void push_back(const value_type& __x) {
      if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage) {
        _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish, __x);
        ++this->_M_impl._M_finish;
      } else
        _M_realloc_insert(end(), __x);
    }

    void push_back(value_type&& __x) { emplace_back(std::move(__x)); }

    template <typename... _Args>

    void

    emplace_back(_Args&&... __args);
    void pop_back() noexcept {
      ;
      --this->_M_impl._M_finish;
      _Alloc_traits::destroy(this->_M_impl, this->_M_impl._M_finish);
    }
    template <typename... _Args>
    iterator emplace(const_iterator __position, _Args&&... __args) {
      return _M_emplace_aux(__position, std::forward<_Args>(__args)...);
    }
    iterator insert(const_iterator __position, const value_type& __x);
    iterator insert(const_iterator __position, value_type&& __x) {
      return _M_insert_rval(__position, std::move(__x));
    }
    iterator insert(const_iterator __position,
                    initializer_list<value_type> __l) {
      auto __offset = __position - cbegin();
      _M_range_insert(begin() + __offset, __l.begin(), __l.end(),
                      std::random_access_iterator_tag());
      return begin() + __offset;
    }
    iterator insert(const_iterator __position,
                    size_type __n,
                    const value_type& __x) {
      difference_type __offset = __position - cbegin();
      _M_fill_insert(begin() + __offset, __n, __x);
      return begin() + __offset;
    }
    template <typename _InputIterator,
              typename = std::_RequireInputIter<_InputIterator>>
    iterator insert(const_iterator __position,
                    _InputIterator __first,
                    _InputIterator __last) {
      difference_type __offset = __position - cbegin();
      _M_insert_dispatch(begin() + __offset, __first, __last, __false_type());
      return begin() + __offset;
    }
    iterator

    erase(const_iterator __position) {
      return _M_erase(begin() + (__position - cbegin()));
    }
    iterator

    erase(const_iterator __first, const_iterator __last) {
      const auto __beg = begin();
      const auto __cbeg = cbegin();
      return _M_erase(__beg + (__first - __cbeg), __beg + (__last - __cbeg));
    }
    void swap(vector& __x) noexcept {
      ;

      this->_M_impl._M_swap_data(__x._M_impl);
      _Alloc_traits::_S_on_swap(_M_get_Tp_allocator(),
                                __x._M_get_Tp_allocator());
    }

    void clear() noexcept { _M_erase_at_end(this->_M_impl._M_start); }

   protected:
    template <typename _ForwardIterator>
    pointer _M_allocate_and_copy(size_type __n,
                                 _ForwardIterator __first,
                                 _ForwardIterator __last) {
      pointer __result = this->_M_allocate(__n);
      try {
        std::__uninitialized_copy_a(__first, __last, __result,
                                    _M_get_Tp_allocator());
        return __result;
      } catch (...) {
        _M_deallocate(__result, __n);
        throw;
      }
    }
    template <typename _Integer>
    void _M_initialize_dispatch(_Integer __n, _Integer __value, __true_type) {
      this->_M_impl._M_start = _M_allocate(static_cast<size_type>(__n));
      this->_M_impl._M_end_of_storage =
          this->_M_impl._M_start + static_cast<size_type>(__n);
      _M_fill_initialize(static_cast<size_type>(__n), __value);
    }

    template <typename _InputIterator>
    void _M_initialize_dispatch(_InputIterator __first,
                                _InputIterator __last,
                                __false_type) {
      typedef typename std::iterator_traits<_InputIterator>::iterator_category
          _IterCategory;
      _M_range_initialize(__first, __last, _IterCategory());
    }

    template <typename _InputIterator>
    void _M_range_initialize(_InputIterator __first,
                             _InputIterator __last,
                             std::input_iterator_tag) {
      for (; __first != __last; ++__first)

        emplace_back(*__first);
    }

    template <typename _ForwardIterator>
    void _M_range_initialize(_ForwardIterator __first,
                             _ForwardIterator __last,
                             std::forward_iterator_tag) {
      const size_type __n = std::distance(__first, __last);
      this->_M_impl._M_start = this->_M_allocate(__n);
      this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
      this->_M_impl._M_finish = std::__uninitialized_copy_a(
          __first, __last, this->_M_impl._M_start, _M_get_Tp_allocator());
    }

    void _M_fill_initialize(size_type __n, const value_type& __value) {
      this->_M_impl._M_finish = std::__uninitialized_fill_n_a(
          this->_M_impl._M_start, __n, __value, _M_get_Tp_allocator());
    }

    void _M_default_initialize(size_type __n) {
      this->_M_impl._M_finish = std::__uninitialized_default_n_a(
          this->_M_impl._M_start, __n, _M_get_Tp_allocator());
    }
    template <typename _Integer>
    void _M_assign_dispatch(_Integer __n, _Integer __val, __true_type) {
      _M_fill_assign(__n, __val);
    }

    template <typename _InputIterator>
    void _M_assign_dispatch(_InputIterator __first,
                            _InputIterator __last,
                            __false_type) {
      _M_assign_aux(__first, __last, std::__iterator_category(__first));
    }

    template <typename _InputIterator>
    void _M_assign_aux(_InputIterator __first,
                       _InputIterator __last,
                       std::input_iterator_tag);

    template <typename _ForwardIterator>
    void _M_assign_aux(_ForwardIterator __first,
                       _ForwardIterator __last,
                       std::forward_iterator_tag);

    void _M_fill_assign(size_type __n, const value_type& __val);

    template <typename _Integer>
    void _M_insert_dispatch(iterator __pos,
                            _Integer __n,
                            _Integer __val,
                            __true_type) {
      _M_fill_insert(__pos, __n, __val);
    }

    template <typename _InputIterator>
    void _M_insert_dispatch(iterator __pos,
                            _InputIterator __first,
                            _InputIterator __last,
                            __false_type) {
      _M_range_insert(__pos, __first, __last,
                      std::__iterator_category(__first));
    }

    template <typename _InputIterator>
    void _M_range_insert(iterator __pos,
                         _InputIterator __first,
                         _InputIterator __last,
                         std::input_iterator_tag);

    template <typename _ForwardIterator>
    void _M_range_insert(iterator __pos,
                         _ForwardIterator __first,
                         _ForwardIterator __last,
                         std::forward_iterator_tag);

    void _M_fill_insert(iterator __pos, size_type __n, const value_type& __x);

    void _M_default_append(size_type __n);

    bool _M_shrink_to_fit();
    struct _Temporary_value {
      template <typename... _Args>
      explicit _Temporary_value(vector* __vec, _Args&&... __args)
          : _M_this(__vec) {
        _Alloc_traits::construct(_M_this->_M_impl, _M_ptr(),
                                 std::forward<_Args>(__args)...);
      }

      ~_Temporary_value() {
        _Alloc_traits::destroy(_M_this->_M_impl, _M_ptr());
      }

      value_type& _M_val() { return *reinterpret_cast<_Tp*>(&__buf); }

     private:
      pointer _M_ptr() { return pointer_traits<pointer>::pointer_to(_M_val()); }

      vector* _M_this;
      typename aligned_storage<sizeof(_Tp), alignof(_Tp)>::type __buf;
    };

    template <typename _Arg>
    void _M_insert_aux(iterator __position, _Arg&& __arg);

    template <typename... _Args>
    void _M_realloc_insert(iterator __position, _Args&&... __args);

    iterator _M_insert_rval(const_iterator __position, value_type&& __v);

    template <typename... _Args>
    iterator _M_emplace_aux(const_iterator __position, _Args&&... __args);

    iterator _M_emplace_aux(const_iterator __position, value_type&& __v) {
      return _M_insert_rval(__position, std::move(__v));
    }

    size_type _M_check_len(size_type __n, const char* __s) const {
      if (max_size() - size() < __n)
        __throw_length_error((__s));

      const size_type __len = size() + std::max(size(), __n);
      return (__len < size() || __len > max_size()) ? max_size() : __len;
    }

    void _M_erase_at_end(pointer __pos) noexcept {
      std::_Destroy(__pos, this->_M_impl._M_finish, _M_get_Tp_allocator());
      this->_M_impl._M_finish = __pos;
    }

    iterator _M_erase(iterator __position);

    iterator _M_erase(iterator __first, iterator __last);

   private:
    void _M_move_assign(vector&& __x, std::true_type) noexcept {
      vector __tmp(get_allocator());
      this->_M_impl._M_swap_data(__tmp._M_impl);
      this->_M_impl._M_swap_data(__x._M_impl);
      std::__alloc_on_move(_M_get_Tp_allocator(), __x._M_get_Tp_allocator());
    }

    void _M_move_assign(vector&& __x, std::false_type) {
      if (__x._M_get_Tp_allocator() == this->_M_get_Tp_allocator())
        _M_move_assign(std::move(__x), std::true_type());
      else {
        this->assign(std::__make_move_if_noexcept_iterator(__x.begin()),
                     std::__make_move_if_noexcept_iterator(__x.end()));
        __x.clear();
      }
    }

    template <typename _Up>
    _Up* _M_data_ptr(_Up* __ptr) const noexcept {
      return __ptr;
    }

    template <typename _Ptr>
    typename std::pointer_traits<_Ptr>::element_type* _M_data_ptr(
        _Ptr __ptr) const {
      return empty() ? nullptr : std::__addressof(*__ptr);
    }
  };
  template <typename _Tp, typename _Alloc>
  inline bool operator==(const vector<_Tp, _Alloc>& __x,
                         const vector<_Tp, _Alloc>& __y) {
    return (__x.size() == __y.size() &&
            std::equal(__x.begin(), __x.end(), __y.begin()));
  }
  template <typename _Tp, typename _Alloc>
  inline bool operator<(const vector<_Tp, _Alloc>& __x,
                        const vector<_Tp, _Alloc>& __y) {
    return std::lexicographical_compare(__x.begin(), __x.end(), __y.begin(),
                                        __y.end());
  }

  template <typename _Tp, typename _Alloc>
  inline bool operator!=(const vector<_Tp, _Alloc>& __x,
                         const vector<_Tp, _Alloc>& __y) {
    return !(__x == __y);
  }

  template <typename _Tp, typename _Alloc>
  inline bool operator>(const vector<_Tp, _Alloc>& __x,
                        const vector<_Tp, _Alloc>& __y) {
    return __y < __x;
  }

  template <typename _Tp, typename _Alloc>
  inline bool operator<=(const vector<_Tp, _Alloc>& __x,
                         const vector<_Tp, _Alloc>& __y) {
    return !(__y < __x);
  }

  template <typename _Tp, typename _Alloc>
  inline bool operator>=(const vector<_Tp, _Alloc>& __x,
                         const vector<_Tp, _Alloc>& __y) {
    return !(__x < __y);
  }

  template <typename _Tp, typename _Alloc>
  inline void swap(
      vector<_Tp, _Alloc> & __x,
      vector<_Tp, _Alloc> & __y) noexcept(noexcept(__x.swap(__y))) {
    __x.swap(__y);
  }

}  // namespace std__attribute__((__visibility__("default")))
namespace std __attribute__((__visibility__("default"))) {

  typedef unsigned long _Bit_type;
  enum { _S_word_bit = int(8 * sizeof(_Bit_type)) };

  struct _Bit_reference {
    _Bit_type* _M_p;
    _Bit_type _M_mask;

    _Bit_reference(_Bit_type* __x, _Bit_type __y) : _M_p(__x), _M_mask(__y) {}

    _Bit_reference() noexcept : _M_p(0), _M_mask(0) {}

    operator bool() const noexcept { return !!(*_M_p & _M_mask); }

    _Bit_reference& operator=(bool __x) noexcept {
      if (__x)
        *_M_p |= _M_mask;
      else
        *_M_p &= ~_M_mask;
      return *this;
    }

    _Bit_reference& operator=(const _Bit_reference& __x) noexcept {
      return *this = bool(__x);
    }

    bool operator==(const _Bit_reference& __x) const {
      return bool(*this) == bool(__x);
    }

    bool operator<(const _Bit_reference& __x) const {
      return !bool(*this) && bool(__x);
    }

    void flip() noexcept { *_M_p ^= _M_mask; }
  };

  inline void swap(_Bit_reference __x, _Bit_reference __y) noexcept {
    bool __tmp = __x;
    __x = __y;
    __y = __tmp;
  }

  inline void swap(_Bit_reference __x, bool& __y) noexcept {
    bool __tmp = __x;
    __x = __y;
    __y = __tmp;
  }

  inline void swap(bool& __x, _Bit_reference __y) noexcept {
    bool __tmp = __x;
    __x = __y;
    __y = __tmp;
  }

  struct _Bit_iterator_base
      : public std::iterator<std::random_access_iterator_tag, bool> {
    _Bit_type* _M_p;
    unsigned int _M_offset;

    _Bit_iterator_base(_Bit_type* __x, unsigned int __y)
        : _M_p(__x), _M_offset(__y) {}

    void _M_bump_up() {
      if (_M_offset++ == int(_S_word_bit) - 1) {
        _M_offset = 0;
        ++_M_p;
      }
    }

    void _M_bump_down() {
      if (_M_offset-- == 0) {
        _M_offset = int(_S_word_bit) - 1;
        --_M_p;
      }
    }

    void _M_incr(ptrdiff_t __i) {
      difference_type __n = __i + _M_offset;
      _M_p += __n / int(_S_word_bit);
      __n = __n % int(_S_word_bit);
      if (__n < 0) {
        __n += int(_S_word_bit);
        --_M_p;
      }
      _M_offset = static_cast<unsigned int>(__n);
    }

    bool operator==(const _Bit_iterator_base& __i) const {
      return _M_p == __i._M_p && _M_offset == __i._M_offset;
    }

    bool operator<(const _Bit_iterator_base& __i) const {
      return _M_p < __i._M_p || (_M_p == __i._M_p && _M_offset < __i._M_offset);
    }

    bool operator!=(const _Bit_iterator_base& __i) const {
      return !(*this == __i);
    }

    bool operator>(const _Bit_iterator_base& __i) const { return __i < *this; }

    bool operator<=(const _Bit_iterator_base& __i) const {
      return !(__i < *this);
    }

    bool operator>=(const _Bit_iterator_base& __i) const {
      return !(*this < __i);
    }
  };

  inline ptrdiff_t operator-(const _Bit_iterator_base& __x,
                             const _Bit_iterator_base& __y) {
    return (int(_S_word_bit) * (__x._M_p - __y._M_p) + __x._M_offset -
            __y._M_offset);
  }

  struct _Bit_iterator : public _Bit_iterator_base {
    typedef _Bit_reference reference;
    typedef _Bit_reference* pointer;
    typedef _Bit_iterator iterator;

    _Bit_iterator() : _Bit_iterator_base(0, 0) {}

    _Bit_iterator(_Bit_type* __x, unsigned int __y)
        : _Bit_iterator_base(__x, __y) {}

    iterator _M_const_cast() const { return *this; }

    reference operator*() const { return reference(_M_p, 1UL << _M_offset); }

    iterator& operator++() {
      _M_bump_up();
      return *this;
    }

    iterator operator++(int) {
      iterator __tmp = *this;
      _M_bump_up();
      return __tmp;
    }

    iterator& operator--() {
      _M_bump_down();
      return *this;
    }

    iterator operator--(int) {
      iterator __tmp = *this;
      _M_bump_down();
      return __tmp;
    }

    iterator& operator+=(difference_type __i) {
      _M_incr(__i);
      return *this;
    }

    iterator& operator-=(difference_type __i) {
      *this += -__i;
      return *this;
    }

    iterator operator+(difference_type __i) const {
      iterator __tmp = *this;
      return __tmp += __i;
    }

    iterator operator-(difference_type __i) const {
      iterator __tmp = *this;
      return __tmp -= __i;
    }

    reference operator[](difference_type __i) const { return *(*this + __i); }
  };

  inline _Bit_iterator operator+(ptrdiff_t __n, const _Bit_iterator& __x) {
    return __x + __n;
  }

  struct _Bit_const_iterator : public _Bit_iterator_base {
    typedef bool reference;
    typedef bool const_reference;
    typedef const bool* pointer;
    typedef _Bit_const_iterator const_iterator;

    _Bit_const_iterator() : _Bit_iterator_base(0, 0) {}

    _Bit_const_iterator(_Bit_type* __x, unsigned int __y)
        : _Bit_iterator_base(__x, __y) {}

    _Bit_const_iterator(const _Bit_iterator& __x)
        : _Bit_iterator_base(__x._M_p, __x._M_offset) {}

    _Bit_iterator _M_const_cast() const {
      return _Bit_iterator(_M_p, _M_offset);
    }

    const_reference operator*() const {
      return _Bit_reference(_M_p, 1UL << _M_offset);
    }

    const_iterator& operator++() {
      _M_bump_up();
      return *this;
    }

    const_iterator operator++(int) {
      const_iterator __tmp = *this;
      _M_bump_up();
      return __tmp;
    }

    const_iterator& operator--() {
      _M_bump_down();
      return *this;
    }

    const_iterator operator--(int) {
      const_iterator __tmp = *this;
      _M_bump_down();
      return __tmp;
    }

    const_iterator& operator+=(difference_type __i) {
      _M_incr(__i);
      return *this;
    }

    const_iterator& operator-=(difference_type __i) {
      *this += -__i;
      return *this;
    }

    const_iterator operator+(difference_type __i) const {
      const_iterator __tmp = *this;
      return __tmp += __i;
    }

    const_iterator operator-(difference_type __i) const {
      const_iterator __tmp = *this;
      return __tmp -= __i;
    }

    const_reference operator[](difference_type __i) const {
      return *(*this + __i);
    }
  };

  inline _Bit_const_iterator operator+(ptrdiff_t __n,
                                       const _Bit_const_iterator& __x) {
    return __x + __n;
  }

  inline void __fill_bvector(_Bit_iterator __first, _Bit_iterator __last,
                             bool __x) {
    for (; __first != __last; ++__first)
      *__first = __x;
  }

  inline void fill(_Bit_iterator __first, _Bit_iterator __last,
                   const bool& __x) {
    if (__first._M_p != __last._M_p) {
      std::fill(__first._M_p + 1, __last._M_p, __x ? ~0 : 0);
      __fill_bvector(__first, _Bit_iterator(__first._M_p + 1, 0), __x);
      __fill_bvector(_Bit_iterator(__last._M_p, 0), __last, __x);
    } else
      __fill_bvector(__first, __last, __x);
  }

  template <typename _Alloc>
  struct _Bvector_base {
    typedef typename __gnu_cxx::__alloc_traits<_Alloc>::template rebind<
        _Bit_type>::other _Bit_alloc_type;
    typedef typename __gnu_cxx::__alloc_traits<_Bit_alloc_type>
        _Bit_alloc_traits;
    typedef typename _Bit_alloc_traits::pointer _Bit_pointer;

    struct _Bvector_impl : public _Bit_alloc_type {
      _Bit_iterator _M_start;
      _Bit_iterator _M_finish;
      _Bit_pointer _M_end_of_storage;

      _Bvector_impl()
          : _Bit_alloc_type(), _M_start(), _M_finish(), _M_end_of_storage() {}

      _Bvector_impl(const _Bit_alloc_type& __a)
          : _Bit_alloc_type(__a),
            _M_start(),
            _M_finish(),
            _M_end_of_storage() {}

      _Bvector_impl(_Bit_alloc_type&& __a)
          : _Bit_alloc_type(std::move(__a)),
            _M_start(),
            _M_finish(),
            _M_end_of_storage() {}

      _Bit_type* _M_end_addr() const noexcept {
        if (_M_end_of_storage)
          return std::__addressof(_M_end_of_storage[-1]) + 1;
        return 0;
      }
    };

   public:
    typedef _Alloc allocator_type;

    _Bit_alloc_type& _M_get_Bit_allocator() noexcept {
      return *static_cast<_Bit_alloc_type*>(&this->_M_impl);
    }

    const _Bit_alloc_type& _M_get_Bit_allocator() const noexcept {
      return *static_cast<const _Bit_alloc_type*>(&this->_M_impl);
    }

    allocator_type get_allocator() const noexcept {
      return allocator_type(_M_get_Bit_allocator());
    }

    _Bvector_base() : _M_impl() {}

    _Bvector_base(const allocator_type& __a) : _M_impl(__a) {}

    _Bvector_base(_Bvector_base&& __x) noexcept
        : _M_impl(std::move(__x._M_get_Bit_allocator())) {
      this->_M_impl._M_start = __x._M_impl._M_start;
      this->_M_impl._M_finish = __x._M_impl._M_finish;
      this->_M_impl._M_end_of_storage = __x._M_impl._M_end_of_storage;
      __x._M_impl._M_start = _Bit_iterator();
      __x._M_impl._M_finish = _Bit_iterator();
      __x._M_impl._M_end_of_storage = nullptr;
    }

    ~_Bvector_base() { this->_M_deallocate(); }

   protected:
    _Bvector_impl _M_impl;

    _Bit_pointer _M_allocate(size_t __n) {
      return _Bit_alloc_traits::allocate(_M_impl, _S_nword(__n));
    }

    void _M_deallocate() {
      if (_M_impl._M_start._M_p) {
        const size_t __n = _M_impl._M_end_addr() - _M_impl._M_start._M_p;
        _Bit_alloc_traits::deallocate(_M_impl, _M_impl._M_end_of_storage - __n,
                                      __n);
        _M_impl._M_start = _M_impl._M_finish = _Bit_iterator();
        _M_impl._M_end_of_storage = _Bit_pointer();
      }
    }

    static size_t _S_nword(size_t __n) {
      return (__n + int(_S_word_bit) - 1) / int(_S_word_bit);
    }
  };

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Alloc>
  class vector<bool, _Alloc> : protected _Bvector_base<_Alloc> {
    typedef _Bvector_base<_Alloc> _Base;
    typedef typename _Base::_Bit_pointer _Bit_pointer;
    typedef typename _Base::_Bit_alloc_traits _Bit_alloc_traits;

    template <typename>
    friend struct hash;

   public:
    typedef bool value_type;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef _Bit_reference reference;
    typedef bool const_reference;
    typedef _Bit_reference* pointer;
    typedef const bool* const_pointer;
    typedef _Bit_iterator iterator;
    typedef _Bit_const_iterator const_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef _Alloc allocator_type;

    allocator_type get_allocator() const { return _Base::get_allocator(); }

   protected:
    using _Base::_M_allocate;
    using _Base::_M_deallocate;
    using _Base::_M_get_Bit_allocator;
    using _Base::_S_nword;

   public:
    vector()

        noexcept(is_nothrow_default_constructible<allocator_type>::value)

        : _Base() {}

    explicit vector(const allocator_type& __a) : _Base(__a) {}

    explicit vector(size_type __n, const allocator_type& __a = allocator_type())
        : vector(__n, false, __a) {}

    vector(size_type __n,
           const bool& __value,
           const allocator_type& __a = allocator_type())
        : _Base(__a) {
      _M_initialize(__n);
      std::fill(this->_M_impl._M_start._M_p, this->_M_impl._M_end_addr(),
                __value ? ~0 : 0);
    }
    vector(const vector& __x)
        : _Base(_Bit_alloc_traits::_S_select_on_copy(
              __x._M_get_Bit_allocator())) {
      _M_initialize(__x.size());
      _M_copy_aligned(__x.begin(), __x.end(), this->_M_impl._M_start);
    }

    vector(vector&& __x) noexcept : _Base(std::move(__x)) {}

    vector(vector&& __x, const allocator_type& __a) noexcept(
        _Bit_alloc_traits::_S_always_equal())
        : _Base(__a) {
      if (__x.get_allocator() == __a) {
        this->_M_impl._M_start = __x._M_impl._M_start;
        this->_M_impl._M_finish = __x._M_impl._M_finish;
        this->_M_impl._M_end_of_storage = __x._M_impl._M_end_of_storage;
        __x._M_impl._M_start = _Bit_iterator();
        __x._M_impl._M_finish = _Bit_iterator();
        __x._M_impl._M_end_of_storage = nullptr;
      } else {
        _M_initialize(__x.size());
        _M_copy_aligned(__x.begin(), __x.end(), begin());
        __x.clear();
      }
    }

    vector(const vector& __x, const allocator_type& __a) : _Base(__a) {
      _M_initialize(__x.size());
      _M_copy_aligned(__x.begin(), __x.end(), this->_M_impl._M_start);
    }

    vector(initializer_list<bool> __l,
           const allocator_type& __a = allocator_type())
        : _Base(__a) {
      _M_initialize_range(__l.begin(), __l.end(), random_access_iterator_tag());
    }

    template <typename _InputIterator,
              typename = std::_RequireInputIter<_InputIterator>>
    vector(_InputIterator __first,
           _InputIterator __last,
           const allocator_type& __a = allocator_type())
        : _Base(__a) {
      _M_initialize_dispatch(__first, __last, __false_type());
    }
    ~vector() noexcept {}

    vector& operator=(const vector& __x) {
      if (&__x == this)
        return *this;

      if (_Bit_alloc_traits::_S_propagate_on_copy_assign()) {
        if (this->_M_get_Bit_allocator() != __x._M_get_Bit_allocator()) {
          this->_M_deallocate();
          std::__alloc_on_copy(_M_get_Bit_allocator(),
                               __x._M_get_Bit_allocator());
          _M_initialize(__x.size());
        } else
          std::__alloc_on_copy(_M_get_Bit_allocator(),
                               __x._M_get_Bit_allocator());
      }

      if (__x.size() > capacity()) {
        this->_M_deallocate();
        _M_initialize(__x.size());
      }
      this->_M_impl._M_finish =
          _M_copy_aligned(__x.begin(), __x.end(), begin());
      return *this;
    }

    vector& operator=(vector&& __x) noexcept(
        _Bit_alloc_traits::_S_nothrow_move()) {
      if (_Bit_alloc_traits::_S_propagate_on_move_assign() ||
          this->_M_get_Bit_allocator() == __x._M_get_Bit_allocator()) {
        this->_M_deallocate();
        this->_M_impl._M_start = __x._M_impl._M_start;
        this->_M_impl._M_finish = __x._M_impl._M_finish;
        this->_M_impl._M_end_of_storage = __x._M_impl._M_end_of_storage;
        __x._M_impl._M_start = _Bit_iterator();
        __x._M_impl._M_finish = _Bit_iterator();
        __x._M_impl._M_end_of_storage = nullptr;
        std::__alloc_on_move(_M_get_Bit_allocator(),
                             __x._M_get_Bit_allocator());
      } else {
        if (__x.size() > capacity()) {
          this->_M_deallocate();
          _M_initialize(__x.size());
        }
        this->_M_impl._M_finish =
            _M_copy_aligned(__x.begin(), __x.end(), begin());
        __x.clear();
      }
      return *this;
    }

    vector& operator=(initializer_list<bool> __l) {
      this->assign(__l.begin(), __l.end());
      return *this;
    }

    void assign(size_type __n, const bool& __x) { _M_fill_assign(__n, __x); }

    template <typename _InputIterator,
              typename = std::_RequireInputIter<_InputIterator>>
    void assign(_InputIterator __first, _InputIterator __last) {
      _M_assign_dispatch(__first, __last, __false_type());
    }
    void assign(initializer_list<bool> __l) {
      this->assign(__l.begin(), __l.end());
    }

    iterator begin() noexcept { return this->_M_impl._M_start; }

    const_iterator begin() const noexcept { return this->_M_impl._M_start; }

    iterator end() noexcept { return this->_M_impl._M_finish; }

    const_iterator end() const noexcept { return this->_M_impl._M_finish; }

    reverse_iterator rbegin() noexcept { return reverse_iterator(end()); }

    const_reverse_iterator rbegin() const noexcept {
      return const_reverse_iterator(end());
    }

    reverse_iterator rend() noexcept { return reverse_iterator(begin()); }

    const_reverse_iterator rend() const noexcept {
      return const_reverse_iterator(begin());
    }

    const_iterator cbegin() const noexcept { return this->_M_impl._M_start; }

    const_iterator cend() const noexcept { return this->_M_impl._M_finish; }

    const_reverse_iterator crbegin() const noexcept {
      return const_reverse_iterator(end());
    }

    const_reverse_iterator crend() const noexcept {
      return const_reverse_iterator(begin());
    }

    size_type size() const noexcept { return size_type(end() - begin()); }

    size_type max_size() const noexcept {
      const size_type __isize =
          __gnu_cxx::__numeric_traits<difference_type>::__max -
          int(_S_word_bit) + 1;
      const size_type __asize =
          _Bit_alloc_traits::max_size(_M_get_Bit_allocator());
      return (__asize <= __isize / int(_S_word_bit) ? __asize* int(_S_word_bit)
                                                    : __isize);
    }

    size_type capacity() const noexcept {
      return size_type(const_iterator(this->_M_impl._M_end_addr(), 0) -
                       begin());
    }

    bool empty() const noexcept { return begin() == end(); }

    reference operator[](size_type __n) {
      return *iterator(this->_M_impl._M_start._M_p + __n / int(_S_word_bit),
                       __n % int(_S_word_bit));
    }

    const_reference operator[](size_type __n) const {
      return *const_iterator(
          this->_M_impl._M_start._M_p + __n / int(_S_word_bit),
          __n % int(_S_word_bit));
    }

   protected:
    void _M_range_check(size_type __n) const {
      if (__n >= this->size())
        __throw_out_of_range_fmt(("vector<bool>::_M_range_check: __n "
                                  "(which is %zu) >= this->size() "
                                  "(which is %zu)")

                                     ,
                                 __n, this->size());
    }

   public:
    reference at(size_type __n) {
      _M_range_check(__n);
      return (*this)[__n];
    }

    const_reference at(size_type __n) const {
      _M_range_check(__n);
      return (*this)[__n];
    }

    void reserve(size_type __n) {
      if (__n > max_size())
        __throw_length_error(("vector::reserve"));
      if (capacity() < __n)
        _M_reallocate(__n);
    }

    reference front() { return *begin(); }

    const_reference front() const { return *begin(); }

    reference back() { return *(end() - 1); }

    const_reference back() const { return *(end() - 1); }

    void data() noexcept {}

    void push_back(bool __x) {
      if (this->_M_impl._M_finish._M_p != this->_M_impl._M_end_addr())
        *this->_M_impl._M_finish++ = __x;
      else
        _M_insert_aux(end(), __x);
    }

    void swap(vector& __x) noexcept {
      std::swap(this->_M_impl._M_start, __x._M_impl._M_start);
      std::swap(this->_M_impl._M_finish, __x._M_impl._M_finish);
      std::swap(this->_M_impl._M_end_of_storage, __x._M_impl._M_end_of_storage);
      _Bit_alloc_traits::_S_on_swap(_M_get_Bit_allocator(),
                                    __x._M_get_Bit_allocator());
    }

    static void swap(reference __x, reference __y) noexcept {
      bool __tmp = __x;
      __x = __y;
      __y = __tmp;
    }

    iterator

    insert(const_iterator __position, const bool& __x = bool())

    {
      const difference_type __n = __position - begin();
      if (this->_M_impl._M_finish._M_p != this->_M_impl._M_end_addr() &&
          __position == end())
        *this->_M_impl._M_finish++ = __x;
      else
        _M_insert_aux(__position._M_const_cast(), __x);
      return begin() + __n;
    }

    template <typename _InputIterator,
              typename = std::_RequireInputIter<_InputIterator>>
    iterator insert(const_iterator __position,
                    _InputIterator __first,
                    _InputIterator __last) {
      difference_type __offset = __position - cbegin();
      _M_insert_dispatch(__position._M_const_cast(), __first, __last,
                         __false_type());
      return begin() + __offset;
    }
    iterator insert(const_iterator __position, size_type __n, const bool& __x) {
      difference_type __offset = __position - cbegin();
      _M_fill_insert(__position._M_const_cast(), __n, __x);
      return begin() + __offset;
    }

    iterator insert(const_iterator __p, initializer_list<bool> __l) {
      return this->insert(__p, __l.begin(), __l.end());
    }

    void pop_back() { --this->_M_impl._M_finish; }

    iterator

    erase(const_iterator __position)

    {
      return _M_erase(__position._M_const_cast());
    }

    iterator

    erase(const_iterator __first, const_iterator __last)

    {
      return _M_erase(__first._M_const_cast(), __last._M_const_cast());
    }

    void resize(size_type __new_size, bool __x = bool()) {
      if (__new_size < size())
        _M_erase_at_end(begin() + difference_type(__new_size));
      else
        insert(end(), __new_size - size(), __x);
    }

    void shrink_to_fit() { _M_shrink_to_fit(); }

    void flip() noexcept {
      _Bit_type* const __end = this->_M_impl._M_end_addr();
      for (_Bit_type* __p = this->_M_impl._M_start._M_p; __p != __end; ++__p)
        *__p = ~*__p;
    }

    void clear() noexcept { _M_erase_at_end(begin()); }

    template <typename... _Args>

    void

    emplace_back(_Args&&... __args) {
      push_back(bool(__args...));
    }

    template <typename... _Args>
    iterator emplace(const_iterator __pos, _Args&&... __args) {
      return insert(__pos, bool(__args...));
    }

   protected:
    iterator _M_copy_aligned(const_iterator __first,
                             const_iterator __last,
                             iterator __result) {
      _Bit_type* __q = std::copy(__first._M_p, __last._M_p, __result._M_p);
      return std::copy(const_iterator(__last._M_p, 0), __last,
                       iterator(__q, 0));
    }

    void _M_initialize(size_type __n) {
      _Bit_pointer __q = this->_M_allocate(__n);
      this->_M_impl._M_end_of_storage = __q + _S_nword(__n);
      this->_M_impl._M_start = iterator(std::__addressof(*__q), 0);
      this->_M_impl._M_finish = this->_M_impl._M_start + difference_type(__n);
    }

    void _M_reallocate(size_type __n);

    bool _M_shrink_to_fit();

    template <typename _Integer>
    void _M_initialize_dispatch(_Integer __n, _Integer __x, __true_type) {
      _M_initialize(static_cast<size_type>(__n));
      std::fill(this->_M_impl._M_start._M_p, this->_M_impl._M_end_addr(),
                __x ? ~0 : 0);
    }

    template <typename _InputIterator>
    void _M_initialize_dispatch(_InputIterator __first,
                                _InputIterator __last,
                                __false_type) {
      _M_initialize_range(__first, __last, std::__iterator_category(__first));
    }

    template <typename _InputIterator>
    void _M_initialize_range(_InputIterator __first,
                             _InputIterator __last,
                             std::input_iterator_tag) {
      for (; __first != __last; ++__first)
        push_back(*__first);
    }

    template <typename _ForwardIterator>
    void _M_initialize_range(_ForwardIterator __first,
                             _ForwardIterator __last,
                             std::forward_iterator_tag) {
      const size_type __n = std::distance(__first, __last);
      _M_initialize(__n);
      std::copy(__first, __last, this->_M_impl._M_start);
    }

    template <typename _Integer>
    void _M_assign_dispatch(_Integer __n, _Integer __val, __true_type) {
      _M_fill_assign(__n, __val);
    }

    template <class _InputIterator>
    void _M_assign_dispatch(_InputIterator __first,
                            _InputIterator __last,
                            __false_type) {
      _M_assign_aux(__first, __last, std::__iterator_category(__first));
    }

    void _M_fill_assign(size_t __n, bool __x) {
      if (__n > size()) {
        std::fill(this->_M_impl._M_start._M_p, this->_M_impl._M_end_addr(),
                  __x ? ~0 : 0);
        insert(end(), __n - size(), __x);
      } else {
        _M_erase_at_end(begin() + __n);
        std::fill(this->_M_impl._M_start._M_p, this->_M_impl._M_end_addr(),
                  __x ? ~0 : 0);
      }
    }

    template <typename _InputIterator>
    void _M_assign_aux(_InputIterator __first,
                       _InputIterator __last,
                       std::input_iterator_tag) {
      iterator __cur = begin();
      for (; __first != __last && __cur != end(); ++__cur, ++__first)
        *__cur = *__first;
      if (__first == __last)
        _M_erase_at_end(__cur);
      else
        insert(end(), __first, __last);
    }

    template <typename _ForwardIterator>
    void _M_assign_aux(_ForwardIterator __first,
                       _ForwardIterator __last,
                       std::forward_iterator_tag) {
      const size_type __len = std::distance(__first, __last);
      if (__len < size())
        _M_erase_at_end(std::copy(__first, __last, begin()));
      else {
        _ForwardIterator __mid = __first;
        std::advance(__mid, size());
        std::copy(__first, __mid, begin());
        insert(end(), __mid, __last);
      }
    }

    template <typename _Integer>
    void _M_insert_dispatch(iterator __pos,
                            _Integer __n,
                            _Integer __x,
                            __true_type) {
      _M_fill_insert(__pos, __n, __x);
    }

    template <typename _InputIterator>
    void _M_insert_dispatch(iterator __pos,
                            _InputIterator __first,
                            _InputIterator __last,
                            __false_type) {
      _M_insert_range(__pos, __first, __last,
                      std::__iterator_category(__first));
    }

    void _M_fill_insert(iterator __position, size_type __n, bool __x);

    template <typename _InputIterator>
    void _M_insert_range(iterator __pos,
                         _InputIterator __first,
                         _InputIterator __last,
                         std::input_iterator_tag) {
      for (; __first != __last; ++__first) {
        __pos = insert(__pos, *__first);
        ++__pos;
      }
    }

    template <typename _ForwardIterator>
    void _M_insert_range(iterator __position,
                         _ForwardIterator __first,
                         _ForwardIterator __last,
                         std::forward_iterator_tag);

    void _M_insert_aux(iterator __position, bool __x);

    size_type _M_check_len(size_type __n, const char* __s) const {
      if (max_size() - size() < __n)
        __throw_length_error((__s));

      const size_type __len = size() + std::max(size(), __n);
      return (__len < size() || __len > max_size()) ? max_size() : __len;
    }

    void _M_erase_at_end(iterator __pos) { this->_M_impl._M_finish = __pos; }

    iterator _M_erase(iterator __pos);

    iterator _M_erase(iterator __first, iterator __last);
  };

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Result, typename _Arg>
  struct __hash_base {
    typedef _Result result_type;
    typedef _Arg argument_type;
  };

  template <typename _Tp>
  struct hash;

  template <typename _Tp, typename = void>
  struct __poison_hash {
    static constexpr bool __enable_hash_call = false;

   private:
    __poison_hash(__poison_hash&&);
    ~__poison_hash();
  };

  template <typename _Tp>
  struct __poison_hash<_Tp, __void_t<decltype(hash<_Tp>()(declval<_Tp>()))>> {
    static constexpr bool __enable_hash_call = true;
  };

  template <typename _Tp, bool = is_enum<_Tp>::value>
  struct __hash_enum {
   private:
    __hash_enum(__hash_enum&&);
    ~__hash_enum();
  };

  template <typename _Tp>
  struct __hash_enum<_Tp, true> : public __hash_base<size_t, _Tp> {
    size_t operator()(_Tp __val) const noexcept {
      using __type = typename underlying_type<_Tp>::type;
      return hash<__type>{}(static_cast<__type>(__val));
    }
  };

  template <typename _Tp>
  struct hash : __hash_enum<_Tp> {};

  template <typename _Tp>
  struct hash<_Tp*> : public __hash_base<size_t, _Tp*> {
    size_t operator()(_Tp* __p) const noexcept {
      return reinterpret_cast<size_t>(__p);
    }
  };
  template <>
  struct hash<bool> : public __hash_base<size_t, bool> {
    size_t operator()(bool __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<char> : public __hash_base<size_t, char> {
    size_t operator()(char __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<signed char> : public __hash_base<size_t, signed char> {
    size_t operator()(signed char __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<unsigned char> : public __hash_base<size_t, unsigned char> {
    size_t operator()(unsigned char __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<wchar_t> : public __hash_base<size_t, wchar_t> {
    size_t operator()(wchar_t __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<char16_t> : public __hash_base<size_t, char16_t> {
    size_t operator()(char16_t __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<char32_t> : public __hash_base<size_t, char32_t> {
    size_t operator()(char32_t __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<short> : public __hash_base<size_t, short> {
    size_t operator()(short __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<int> : public __hash_base<size_t, int> {
    size_t operator()(int __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<long> : public __hash_base<size_t, long> {
    size_t operator()(long __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<long long> : public __hash_base<size_t, long long> {
    size_t operator()(long long __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<unsigned short> : public __hash_base<size_t, unsigned short> {
    size_t operator()(unsigned short __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<unsigned int> : public __hash_base<size_t, unsigned int> {
    size_t operator()(unsigned int __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<unsigned long> : public __hash_base<size_t, unsigned long> {
    size_t operator()(unsigned long __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<unsigned long long>
      : public __hash_base<size_t, unsigned long long> {
    size_t operator()(unsigned long long __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };

  template <>
  struct hash<__int128> : public __hash_base<size_t, __int128> {
    size_t operator()(__int128 __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };
  template <>
  struct hash<__int128 unsigned>
      : public __hash_base<size_t, __int128 unsigned> {
    size_t operator()(__int128 unsigned __val) const noexcept {
      return static_cast<size_t>(__val);
    }
  };
  struct _Hash_impl {
    static size_t hash(const void* __ptr,
                       size_t __clength,
                       size_t __seed = static_cast<size_t>(0xc70f6907UL)) {
      return _Hash_bytes(__ptr, __clength, __seed);
    }

    template <typename _Tp>
    static size_t hash(const _Tp& __val) {
      return hash(&__val, sizeof(__val));
    }

    template <typename _Tp>
    static size_t __hash_combine(const _Tp& __val, size_t __hash) {
      return hash(&__val, sizeof(__val), __hash);
    }
  };

  struct _Fnv_hash_impl {
    static size_t hash(const void* __ptr,
                       size_t __clength,
                       size_t __seed = static_cast<size_t>(2166136261UL)) {
      return _Fnv_hash_bytes(__ptr, __clength, __seed);
    }

    template <typename _Tp>
    static size_t hash(const _Tp& __val) {
      return hash(&__val, sizeof(__val));
    }

    template <typename _Tp>
    static size_t __hash_combine(const _Tp& __val, size_t __hash) {
      return hash(&__val, sizeof(__val), __hash);
    }
  };

  template <>
  struct hash<float> : public __hash_base<size_t, float> {
    size_t operator()(float __val) const noexcept {
      return __val != 0.0f ? std::_Hash_impl::hash(__val) : 0;
    }
  };

  template <>
  struct hash<double> : public __hash_base<size_t, double> {
    size_t operator()(double __val) const noexcept {
      return __val != 0.0 ? std::_Hash_impl::hash(__val) : 0;
    }
  };

  template <>
  struct hash<long double> : public __hash_base<size_t, long double> {
    __attribute__((__pure__)) size_t operator()(long double __val) const
        noexcept;
  };

  template <typename _Hash>
  struct __is_fast_hash : public std::true_type {};

  template <>
  struct __is_fast_hash<hash<long double>> : public std::false_type {};

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Alloc>
  struct hash<std::vector<bool, _Alloc>>
      : public __hash_base<size_t, std::vector<bool, _Alloc>> {
    size_t operator()(const std::vector<bool, _Alloc>&) const noexcept;
  };

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Container>
  inline auto begin(_Container & __cont)->decltype(__cont.begin()) {
    return __cont.begin();
  }

  template <typename _Container>
  inline auto begin(const _Container& __cont)->decltype(__cont.begin()) {
    return __cont.begin();
  }

  template <typename _Container>
  inline auto end(_Container & __cont)->decltype(__cont.end()) {
    return __cont.end();
  }

  template <typename _Container>
  inline auto end(const _Container& __cont)->decltype(__cont.end()) {
    return __cont.end();
  }

  template <typename _Tp, size_t _Nm>
  inline constexpr _Tp* begin(_Tp(&__arr)[_Nm]) {
    return __arr;
  }

  template <typename _Tp, size_t _Nm>
  inline constexpr _Tp* end(_Tp(&__arr)[_Nm]) {
    return __arr + _Nm;
  }

  template <typename _Tp>
  class valarray;

  template <typename _Tp>
  _Tp* begin(valarray<_Tp>&);
  template <typename _Tp>
  const _Tp* begin(const valarray<_Tp>&);
  template <typename _Tp>
  _Tp* end(valarray<_Tp>&);
  template <typename _Tp>
  const _Tp* end(const valarray<_Tp>&);

  template <typename _Container>
  inline constexpr auto cbegin(const _Container& __cont) noexcept(
      noexcept(std::begin(__cont)))
      ->decltype(std::begin(__cont)) {
    return std::begin(__cont);
  }

  template <typename _Container>
  inline constexpr auto cend(const _Container& __cont) noexcept(
      noexcept(std::end(__cont)))
      ->decltype(std::end(__cont)) {
    return std::end(__cont);
  }

  template <typename _Container>
  inline auto rbegin(_Container & __cont)->decltype(__cont.rbegin()) {
    return __cont.rbegin();
  }

  template <typename _Container>
  inline auto rbegin(const _Container& __cont)->decltype(__cont.rbegin()) {
    return __cont.rbegin();
  }

  template <typename _Container>
  inline auto rend(_Container & __cont)->decltype(__cont.rend()) {
    return __cont.rend();
  }

  template <typename _Container>
  inline auto rend(const _Container& __cont)->decltype(__cont.rend()) {
    return __cont.rend();
  }

  template <typename _Tp, size_t _Nm>
  inline reverse_iterator<_Tp*> rbegin(_Tp(&__arr)[_Nm]) {
    return reverse_iterator<_Tp*>(__arr + _Nm);
  }

  template <typename _Tp, size_t _Nm>
  inline reverse_iterator<_Tp*> rend(_Tp(&__arr)[_Nm]) {
    return reverse_iterator<_Tp*>(__arr);
  }

  template <typename _Tp>
  inline reverse_iterator<const _Tp*> rbegin(initializer_list<_Tp> __il) {
    return reverse_iterator<const _Tp*>(__il.end());
  }

  template <typename _Tp>
  inline reverse_iterator<const _Tp*> rend(initializer_list<_Tp> __il) {
    return reverse_iterator<const _Tp*>(__il.begin());
  }

  template <typename _Container>
  inline auto crbegin(const _Container& __cont)->decltype(std::rbegin(__cont)) {
    return std::rbegin(__cont);
  }

  template <typename _Container>
  inline auto crend(const _Container& __cont)->decltype(std::rend(__cont)) {
    return std::rend(__cont);
  }

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Tp, typename _Alloc>
  void vector<_Tp, _Alloc>::reserve(size_type __n) {
    if (__n > this->max_size())
      __throw_length_error(("vector::reserve"));
    if (this->capacity() < __n) {
      const size_type __old_size = size();
      pointer __tmp = _M_allocate_and_copy(
          __n, std::__make_move_if_noexcept_iterator(this->_M_impl._M_start),
          std::__make_move_if_noexcept_iterator(this->_M_impl._M_finish));
      std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
                    _M_get_Tp_allocator());
      _M_deallocate(this->_M_impl._M_start,
                    this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
      this->_M_impl._M_start = __tmp;
      this->_M_impl._M_finish = __tmp + __old_size;
      this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
    }
  }

  template <typename _Tp, typename _Alloc>
  template <typename... _Args>

  void

  vector<_Tp, _Alloc>::emplace_back(_Args && ... __args) {
    if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage) {
      _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
                               std::forward<_Args>(__args)...);
      ++this->_M_impl._M_finish;
    } else
      _M_realloc_insert(end(), std::forward<_Args>(__args)...);
  }

  template <typename _Tp, typename _Alloc>
  typename vector<_Tp, _Alloc>::iterator vector<_Tp, _Alloc>::

      insert(const_iterator __position, const value_type& __x)

  {
    const size_type __n = __position - begin();
    if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
      if (__position == end()) {
        _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish, __x);
        ++this->_M_impl._M_finish;
      } else {
        const auto __pos = begin() + (__position - cbegin());

        _Temporary_value __x_copy(this, __x);
        _M_insert_aux(__pos, std::move(__x_copy._M_val()));
      }
    else

      _M_realloc_insert(begin() + (__position - cbegin()), __x);

    return iterator(this->_M_impl._M_start + __n);
  }

  template <typename _Tp, typename _Alloc>
  typename vector<_Tp, _Alloc>::iterator vector<_Tp, _Alloc>::_M_erase(
      iterator __position) {
    if (__position + 1 != end())
      std::move(__position + 1, end(), __position);
    --this->_M_impl._M_finish;
    _Alloc_traits::destroy(this->_M_impl, this->_M_impl._M_finish);
    return __position;
  }

  template <typename _Tp, typename _Alloc>
  typename vector<_Tp, _Alloc>::iterator vector<_Tp, _Alloc>::_M_erase(
      iterator __first, iterator __last) {
    if (__first != __last) {
      if (__last != end())
        std::move(__last, end(), __first);
      _M_erase_at_end(__first.base() + (end() - __last));
    }
    return __first;
  }

  template <typename _Tp, typename _Alloc>
  vector<_Tp, _Alloc>& vector<_Tp, _Alloc>::operator=(
      const vector<_Tp, _Alloc>& __x) {
    if (&__x != this) {
      if (_Alloc_traits::_S_propagate_on_copy_assign()) {
        if (!_Alloc_traits::_S_always_equal() &&
            _M_get_Tp_allocator() != __x._M_get_Tp_allocator()) {
          this->clear();
          _M_deallocate(
              this->_M_impl._M_start,
              this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
          this->_M_impl._M_start = nullptr;
          this->_M_impl._M_finish = nullptr;
          this->_M_impl._M_end_of_storage = nullptr;
        }
        std::__alloc_on_copy(_M_get_Tp_allocator(), __x._M_get_Tp_allocator());
      }

      const size_type __xlen = __x.size();
      if (__xlen > capacity()) {
        pointer __tmp = _M_allocate_and_copy(__xlen, __x.begin(), __x.end());
        std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
                      _M_get_Tp_allocator());
        _M_deallocate(this->_M_impl._M_start,
                      this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
        this->_M_impl._M_start = __tmp;
        this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __xlen;
      } else if (size() >= __xlen) {
        std::_Destroy(std::copy(__x.begin(), __x.end(), begin()), end(),
                      _M_get_Tp_allocator());
      } else {
        std::copy(__x._M_impl._M_start, __x._M_impl._M_start + size(),
                  this->_M_impl._M_start);
        std::__uninitialized_copy_a(
            __x._M_impl._M_start + size(), __x._M_impl._M_finish,
            this->_M_impl._M_finish, _M_get_Tp_allocator());
      }
      this->_M_impl._M_finish = this->_M_impl._M_start + __xlen;
    }
    return *this;
  }

  template <typename _Tp, typename _Alloc>
  void vector<_Tp, _Alloc>::_M_fill_assign(size_t __n,
                                           const value_type& __val) {
    if (__n > capacity()) {
      vector __tmp(__n, __val, _M_get_Tp_allocator());
      __tmp._M_impl._M_swap_data(this->_M_impl);
    } else if (__n > size()) {
      std::fill(begin(), end(), __val);
      this->_M_impl._M_finish = std::__uninitialized_fill_n_a(
          this->_M_impl._M_finish, __n - size(), __val, _M_get_Tp_allocator());
    } else
      _M_erase_at_end(std::fill_n(this->_M_impl._M_start, __n, __val));
  }

  template <typename _Tp, typename _Alloc>
  template <typename _InputIterator>
  void vector<_Tp, _Alloc>::_M_assign_aux(
      _InputIterator __first, _InputIterator __last, std::input_iterator_tag) {
    pointer __cur(this->_M_impl._M_start);
    for (; __first != __last && __cur != this->_M_impl._M_finish;
         ++__cur, ++__first)
      *__cur = *__first;
    if (__first == __last)
      _M_erase_at_end(__cur);
    else
      _M_range_insert(end(), __first, __last,
                      std::__iterator_category(__first));
  }

  template <typename _Tp, typename _Alloc>
  template <typename _ForwardIterator>
  void vector<_Tp, _Alloc>::_M_assign_aux(_ForwardIterator __first,
                                          _ForwardIterator __last,
                                          std::forward_iterator_tag) {
    const size_type __len = std::distance(__first, __last);

    if (__len > capacity()) {
      pointer __tmp(_M_allocate_and_copy(__len, __first, __last));
      std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
                    _M_get_Tp_allocator());
      _M_deallocate(this->_M_impl._M_start,
                    this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
      this->_M_impl._M_start = __tmp;
      this->_M_impl._M_finish = this->_M_impl._M_start + __len;
      this->_M_impl._M_end_of_storage = this->_M_impl._M_finish;
    } else if (size() >= __len)
      _M_erase_at_end(std::copy(__first, __last, this->_M_impl._M_start));
    else {
      _ForwardIterator __mid = __first;
      std::advance(__mid, size());
      std::copy(__first, __mid, this->_M_impl._M_start);
      this->_M_impl._M_finish = std::__uninitialized_copy_a(
          __mid, __last, this->_M_impl._M_finish, _M_get_Tp_allocator());
    }
  }

  template <typename _Tp, typename _Alloc>
  auto vector<_Tp, _Alloc>::_M_insert_rval(const_iterator __position,
                                           value_type && __v)
      ->iterator {
    const auto __n = __position - cbegin();
    if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
      if (__position == cend()) {
        _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
                                 std::move(__v));
        ++this->_M_impl._M_finish;
      } else
        _M_insert_aux(begin() + __n, std::move(__v));
    else
      _M_realloc_insert(begin() + __n, std::move(__v));

    return iterator(this->_M_impl._M_start + __n);
  }

  template <typename _Tp, typename _Alloc>
  template <typename... _Args>
  auto vector<_Tp, _Alloc>::_M_emplace_aux(const_iterator __position,
                                           _Args && ... __args)
      ->iterator {
    const auto __n = __position - cbegin();
    if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
      if (__position == cend()) {
        _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
                                 std::forward<_Args>(__args)...);
        ++this->_M_impl._M_finish;
      } else {
        _Temporary_value __tmp(this, std::forward<_Args>(__args)...);
        _M_insert_aux(begin() + __n, std::move(__tmp._M_val()));
      }
    else
      _M_realloc_insert(begin() + __n, std::forward<_Args>(__args)...);

    return iterator(this->_M_impl._M_start + __n);
  }

  template <typename _Tp, typename _Alloc>
  template <typename _Arg>
  void vector<_Tp, _Alloc>::_M_insert_aux(iterator __position, _Arg && __arg)

  {
    _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
                             std::move(*(this->_M_impl._M_finish - 1)));
    ++this->_M_impl._M_finish;

    std::move_backward(__position.base(), this->_M_impl._M_finish - 2,
                       this->_M_impl._M_finish - 1)

        ;

    *__position = std::forward<_Arg>(__arg);
  }

  template <typename _Tp, typename _Alloc>
  template <typename... _Args>
  void vector<_Tp, _Alloc>::_M_realloc_insert(iterator __position,
                                              _Args && ... __args)

  {
    const size_type __len =
        _M_check_len(size_type(1), "vector::_M_realloc_insert");
    const size_type __elems_before = __position - begin();
    pointer __new_start(this->_M_allocate(__len));
    pointer __new_finish(__new_start);
    try {
      _Alloc_traits::construct(this->_M_impl, __new_start + __elems_before,

                               std::forward<_Args>(__args)...);

      __new_finish = pointer();

      __new_finish = std::__uninitialized_move_if_noexcept_a(
          this->_M_impl._M_start, __position.base(), __new_start,
          _M_get_Tp_allocator());

      ++__new_finish;

      __new_finish = std::__uninitialized_move_if_noexcept_a(
          __position.base(), this->_M_impl._M_finish, __new_finish,
          _M_get_Tp_allocator());
    } catch (...) {
      if (!__new_finish)
        _Alloc_traits::destroy(this->_M_impl, __new_start + __elems_before);
      else
        std::_Destroy(__new_start, __new_finish, _M_get_Tp_allocator());
      _M_deallocate(__new_start, __len);
      throw;
    }
    std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
                  _M_get_Tp_allocator());
    _M_deallocate(this->_M_impl._M_start,
                  this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
    this->_M_impl._M_start = __new_start;
    this->_M_impl._M_finish = __new_finish;
    this->_M_impl._M_end_of_storage = __new_start + __len;
  }

  template <typename _Tp, typename _Alloc>
  void vector<_Tp, _Alloc>::_M_fill_insert(iterator __position, size_type __n,
                                           const value_type& __x) {
    if (__n != 0) {
      if (size_type(this->_M_impl._M_end_of_storage -
                    this->_M_impl._M_finish) >= __n) {
        _Temporary_value __tmp(this, __x);
        value_type& __x_copy = __tmp._M_val();

        const size_type __elems_after = end() - __position;
        pointer __old_finish(this->_M_impl._M_finish);
        if (__elems_after > __n) {
          std::__uninitialized_move_a(
              this->_M_impl._M_finish - __n, this->_M_impl._M_finish,
              this->_M_impl._M_finish, _M_get_Tp_allocator());
          this->_M_impl._M_finish += __n;
          std::move_backward(__position.base(), __old_finish - __n,
                             __old_finish);
          std::fill(__position.base(), __position.base() + __n, __x_copy);
        } else {
          this->_M_impl._M_finish = std::__uninitialized_fill_n_a(
              this->_M_impl._M_finish, __n - __elems_after, __x_copy,
              _M_get_Tp_allocator());
          std::__uninitialized_move_a(__position.base(), __old_finish,
                                      this->_M_impl._M_finish,
                                      _M_get_Tp_allocator());
          this->_M_impl._M_finish += __elems_after;
          std::fill(__position.base(), __old_finish, __x_copy);
        }
      } else {
        const size_type __len = _M_check_len(__n, "vector::_M_fill_insert");
        const size_type __elems_before = __position - begin();
        pointer __new_start(this->_M_allocate(__len));
        pointer __new_finish(__new_start);
        try {
          std::__uninitialized_fill_n_a(__new_start + __elems_before, __n, __x,
                                        _M_get_Tp_allocator());
          __new_finish = pointer();

          __new_finish = std::__uninitialized_move_if_noexcept_a(
              this->_M_impl._M_start, __position.base(), __new_start,
              _M_get_Tp_allocator());

          __new_finish += __n;

          __new_finish = std::__uninitialized_move_if_noexcept_a(
              __position.base(), this->_M_impl._M_finish, __new_finish,
              _M_get_Tp_allocator());
        } catch (...) {
          if (!__new_finish)
            std::_Destroy(__new_start + __elems_before,
                          __new_start + __elems_before + __n,
                          _M_get_Tp_allocator());
          else
            std::_Destroy(__new_start, __new_finish, _M_get_Tp_allocator());
          _M_deallocate(__new_start, __len);
          throw;
        }
        std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
                      _M_get_Tp_allocator());
        _M_deallocate(this->_M_impl._M_start,
                      this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
        this->_M_impl._M_start = __new_start;
        this->_M_impl._M_finish = __new_finish;
        this->_M_impl._M_end_of_storage = __new_start + __len;
      }
    }
  }

  template <typename _Tp, typename _Alloc>
  void vector<_Tp, _Alloc>::_M_default_append(size_type __n) {
    if (__n != 0) {
      if (size_type(this->_M_impl._M_end_of_storage -
                    this->_M_impl._M_finish) >= __n) {
        this->_M_impl._M_finish = std::__uninitialized_default_n_a(
            this->_M_impl._M_finish, __n, _M_get_Tp_allocator());
      } else {
        const size_type __len = _M_check_len(__n, "vector::_M_default_append");
        const size_type __old_size = this->size();
        pointer __new_start(this->_M_allocate(__len));
        pointer __new_finish(__new_start);
        try {
          __new_finish = std::__uninitialized_move_if_noexcept_a(
              this->_M_impl._M_start, this->_M_impl._M_finish, __new_start,
              _M_get_Tp_allocator());
          __new_finish = std::__uninitialized_default_n_a(
              __new_finish, __n, _M_get_Tp_allocator());
        } catch (...) {
          std::_Destroy(__new_start, __new_finish, _M_get_Tp_allocator());
          _M_deallocate(__new_start, __len);
          throw;
        }
        std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
                      _M_get_Tp_allocator());
        _M_deallocate(this->_M_impl._M_start,
                      this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
        this->_M_impl._M_start = __new_start;
        this->_M_impl._M_finish = __new_finish;
        this->_M_impl._M_end_of_storage = __new_start + __len;
      }
    }
  }

  template <typename _Tp, typename _Alloc>
  bool vector<_Tp, _Alloc>::_M_shrink_to_fit() {
    if (capacity() == size())
      return false;
    return std::__shrink_to_fit_aux<vector>::_S_do_it(*this);
  }

  template <typename _Tp, typename _Alloc>
  template <typename _InputIterator>
  void vector<_Tp, _Alloc>::_M_range_insert(
      iterator __pos, _InputIterator __first, _InputIterator __last,
      std::input_iterator_tag) {
    for (; __first != __last; ++__first) {
      __pos = insert(__pos, *__first);
      ++__pos;
    }
  }

  template <typename _Tp, typename _Alloc>
  template <typename _ForwardIterator>
  void vector<_Tp, _Alloc>::_M_range_insert(
      iterator __position, _ForwardIterator __first, _ForwardIterator __last,
      std::forward_iterator_tag) {
    if (__first != __last) {
      const size_type __n = std::distance(__first, __last);
      if (size_type(this->_M_impl._M_end_of_storage -
                    this->_M_impl._M_finish) >= __n) {
        const size_type __elems_after = end() - __position;
        pointer __old_finish(this->_M_impl._M_finish);
        if (__elems_after > __n) {
          std::__uninitialized_move_a(
              this->_M_impl._M_finish - __n, this->_M_impl._M_finish,
              this->_M_impl._M_finish, _M_get_Tp_allocator());
          this->_M_impl._M_finish += __n;
          std::move_backward(__position.base(), __old_finish - __n,
                             __old_finish);
          std::copy(__first, __last, __position);
        } else {
          _ForwardIterator __mid = __first;
          std::advance(__mid, __elems_after);
          std::__uninitialized_copy_a(__mid, __last, this->_M_impl._M_finish,
                                      _M_get_Tp_allocator());
          this->_M_impl._M_finish += __n - __elems_after;
          std::__uninitialized_move_a(__position.base(), __old_finish,
                                      this->_M_impl._M_finish,
                                      _M_get_Tp_allocator());
          this->_M_impl._M_finish += __elems_after;
          std::copy(__first, __mid, __position);
        }
      } else {
        const size_type __len = _M_check_len(__n, "vector::_M_range_insert");
        pointer __new_start(this->_M_allocate(__len));
        pointer __new_finish(__new_start);
        try {
          __new_finish = std::__uninitialized_move_if_noexcept_a(
              this->_M_impl._M_start, __position.base(), __new_start,
              _M_get_Tp_allocator());
          __new_finish = std::__uninitialized_copy_a(
              __first, __last, __new_finish, _M_get_Tp_allocator());
          __new_finish = std::__uninitialized_move_if_noexcept_a(
              __position.base(), this->_M_impl._M_finish, __new_finish,
              _M_get_Tp_allocator());
        } catch (...) {
          std::_Destroy(__new_start, __new_finish, _M_get_Tp_allocator());
          _M_deallocate(__new_start, __len);
          throw;
        }
        std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
                      _M_get_Tp_allocator());
        _M_deallocate(this->_M_impl._M_start,
                      this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
        this->_M_impl._M_start = __new_start;
        this->_M_impl._M_finish = __new_finish;
        this->_M_impl._M_end_of_storage = __new_start + __len;
      }
    }
  }

  template <typename _Alloc>
  void vector<bool, _Alloc>::_M_reallocate(size_type __n) {
    _Bit_pointer __q = this->_M_allocate(__n);
    iterator __start(std::__addressof(*__q), 0);
    iterator __finish(_M_copy_aligned(begin(), end(), __start));
    this->_M_deallocate();
    this->_M_impl._M_start = __start;
    this->_M_impl._M_finish = __finish;
    this->_M_impl._M_end_of_storage = __q + _S_nword(__n);
  }

  template <typename _Alloc>
  void vector<bool, _Alloc>::_M_fill_insert(iterator __position, size_type __n,
                                            bool __x) {
    if (__n == 0)
      return;
    if (capacity() - size() >= __n) {
      std::copy_backward(__position, end(),
                         this->_M_impl._M_finish + difference_type(__n));
      std::fill(__position, __position + difference_type(__n), __x);
      this->_M_impl._M_finish += difference_type(__n);
    } else {
      const size_type __len = _M_check_len(__n, "vector<bool>::_M_fill_insert");
      _Bit_pointer __q = this->_M_allocate(__len);
      iterator __start(std::__addressof(*__q), 0);
      iterator __i = _M_copy_aligned(begin(), __position, __start);
      std::fill(__i, __i + difference_type(__n), __x);
      iterator __finish =
          std::copy(__position, end(), __i + difference_type(__n));
      this->_M_deallocate();
      this->_M_impl._M_end_of_storage = __q + _S_nword(__len);
      this->_M_impl._M_start = __start;
      this->_M_impl._M_finish = __finish;
    }
  }

  template <typename _Alloc>
  template <typename _ForwardIterator>
  void vector<bool, _Alloc>::_M_insert_range(
      iterator __position, _ForwardIterator __first, _ForwardIterator __last,
      std::forward_iterator_tag) {
    if (__first != __last) {
      size_type __n = std::distance(__first, __last);
      if (capacity() - size() >= __n) {
        std::copy_backward(__position, end(),
                           this->_M_impl._M_finish + difference_type(__n));
        std::copy(__first, __last, __position);
        this->_M_impl._M_finish += difference_type(__n);
      } else {
        const size_type __len =
            _M_check_len(__n, "vector<bool>::_M_insert_range");
        _Bit_pointer __q = this->_M_allocate(__len);
        iterator __start(std::__addressof(*__q), 0);
        iterator __i = _M_copy_aligned(begin(), __position, __start);
        __i = std::copy(__first, __last, __i);
        iterator __finish = std::copy(__position, end(), __i);
        this->_M_deallocate();
        this->_M_impl._M_end_of_storage = __q + _S_nword(__len);
        this->_M_impl._M_start = __start;
        this->_M_impl._M_finish = __finish;
      }
    }
  }

  template <typename _Alloc>
  void vector<bool, _Alloc>::_M_insert_aux(iterator __position, bool __x) {
    if (this->_M_impl._M_finish._M_p != this->_M_impl._M_end_addr()) {
      std::copy_backward(__position, this->_M_impl._M_finish,
                         this->_M_impl._M_finish + 1);
      *__position = __x;
      ++this->_M_impl._M_finish;
    } else {
      const size_type __len =
          _M_check_len(size_type(1), "vector<bool>::_M_insert_aux");
      _Bit_pointer __q = this->_M_allocate(__len);
      iterator __start(std::__addressof(*__q), 0);
      iterator __i = _M_copy_aligned(begin(), __position, __start);
      *__i++ = __x;
      iterator __finish = std::copy(__position, end(), __i);
      this->_M_deallocate();
      this->_M_impl._M_end_of_storage = __q + _S_nword(__len);
      this->_M_impl._M_start = __start;
      this->_M_impl._M_finish = __finish;
    }
  }

  template <typename _Alloc>
  typename vector<bool, _Alloc>::iterator vector<bool, _Alloc>::_M_erase(
      iterator __position) {
    if (__position + 1 != end())
      std::copy(__position + 1, end(), __position);
    --this->_M_impl._M_finish;
    return __position;
  }

  template <typename _Alloc>
  typename vector<bool, _Alloc>::iterator vector<bool, _Alloc>::_M_erase(
      iterator __first, iterator __last) {
    if (__first != __last)
      _M_erase_at_end(std::copy(__last, end(), __first));
    return __first;
  }

  template <typename _Alloc>
  bool vector<bool, _Alloc>::_M_shrink_to_fit() {
    if (capacity() - size() < int(_S_word_bit))
      return false;
    try {
      _M_reallocate(size());
      return true;
    } catch (...) {
      return false;
    }
  }

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Alloc>
  size_t hash<std::vector<bool, _Alloc>>::operator()(
      const std::vector<bool, _Alloc>& __b) const noexcept {
    size_t __hash = 0;
    using std::_Bit_type;
    using std::_S_word_bit;

    const size_t __words = __b.size() / _S_word_bit;
    if (__words) {
      const size_t __clength = __words * sizeof(_Bit_type);
      __hash = std::_Hash_impl::hash(__b._M_impl._M_start._M_p, __clength);
    }

    const size_t __extrabits = __b.size() % _S_word_bit;
    if (__extrabits) {
      _Bit_type __hiword = *__b._M_impl._M_finish._M_p;
      __hiword &= ~((~static_cast<_Bit_type>(0)) << __extrabits);

      const size_t __clength = (__extrabits + 8 - 1) / 8;
      if (__words)
        __hash = std::_Hash_impl::hash(&__hiword, __clength, __hash);
      else
        __hash = std::_Hash_impl::hash(&__hiword, __clength);
    }

    return __hash;
  }

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <class _CharT>
  struct char_traits;

  template <>
  struct char_traits<char>;

  template <>
  struct char_traits<wchar_t>;

  template <>
  struct char_traits<char16_t>;
  template <>
  struct char_traits<char32_t>;

  namespace __cxx11 {

  template <typename _CharT,
            typename _Traits = char_traits<_CharT>,
            typename _Alloc = allocator<_CharT>>
  class basic_string;

  typedef basic_string<char> string;

  typedef basic_string<wchar_t> wstring;

  typedef basic_string<char16_t> u16string;

  typedef basic_string<char32_t> u32string;

  }  // namespace __cxx11

}  // namespace std__attribute__((__visibility__("default")))

typedef _Complex float __cfloat128 __attribute__((__mode__(__TC__)));
typedef __float128 _Float128;

typedef __builtin_va_list __gnuc_va_list;

typedef unsigned int wint_t;

typedef struct {
  int __count;
  union {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;

typedef __mbstate_t mbstate_t;

struct _IO_FILE;
typedef struct _IO_FILE __FILE;

struct _IO_FILE;

typedef struct _IO_FILE FILE;

struct __locale_struct {
  struct __locale_data* __locales[13];

  const unsigned short int* __ctype_b;
  const int* __ctype_tolower;
  const int* __ctype_toupper;

  const char* __names[13];
};

typedef struct __locale_struct* __locale_t;

typedef __locale_t locale_t;
extern "C" {

struct tm;

extern wchar_t* wcscpy(wchar_t* __restrict __dest,
                       const wchar_t* __restrict __src) throw()
    __attribute__((__nonnull__(1, 2)));

extern wchar_t* wcsncpy(wchar_t* __restrict __dest,
                        const wchar_t* __restrict __src,
                        size_t __n) throw() __attribute__((__nonnull__(1, 2)));

extern wchar_t* wcscat(wchar_t* __restrict __dest,
                       const wchar_t* __restrict __src) throw()
    __attribute__((__nonnull__(1, 2)));

extern wchar_t* wcsncat(wchar_t* __restrict __dest,
                        const wchar_t* __restrict __src,
                        size_t __n) throw() __attribute__((__nonnull__(1, 2)));

extern int wcscmp(const wchar_t* __s1, const wchar_t* __s2) throw()
    __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));

extern int wcsncmp(const wchar_t* __s1, const wchar_t* __s2, size_t __n) throw()
    __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));

extern int wcscasecmp(const wchar_t* __s1, const wchar_t* __s2) throw();

extern int wcsncasecmp(const wchar_t* __s1,
                       const wchar_t* __s2,
                       size_t __n) throw();

extern int wcscasecmp_l(const wchar_t* __s1,
                        const wchar_t* __s2,
                        locale_t __loc) throw();

extern int wcsncasecmp_l(const wchar_t* __s1,
                         const wchar_t* __s2,
                         size_t __n,
                         locale_t __loc) throw();

extern int wcscoll(const wchar_t* __s1, const wchar_t* __s2) throw();

extern size_t wcsxfrm(wchar_t* __restrict __s1,
                      const wchar_t* __restrict __s2,
                      size_t __n) throw();

extern int wcscoll_l(const wchar_t* __s1,
                     const wchar_t* __s2,
                     locale_t __loc) throw();

extern size_t wcsxfrm_l(wchar_t* __s1,
                        const wchar_t* __s2,
                        size_t __n,
                        locale_t __loc) throw();

extern wchar_t* wcsdup(const wchar_t* __s) throw() __attribute__((__malloc__));

extern "C++" wchar_t* wcschr(wchar_t* __wcs,
                             wchar_t __wc) throw() __asm("wcschr")
    __attribute__((__pure__));
extern "C++" const wchar_t* wcschr(const wchar_t* __wcs,
                                   wchar_t __wc) throw() __asm("wcschr")
    __attribute__((__pure__));

extern "C++" wchar_t* wcsrchr(wchar_t* __wcs,
                              wchar_t __wc) throw() __asm("wcsrchr")
    __attribute__((__pure__));
extern "C++" const wchar_t* wcsrchr(const wchar_t* __wcs,
                                    wchar_t __wc) throw() __asm("wcsrchr")
    __attribute__((__pure__));
extern wchar_t* wcschrnul(const wchar_t* __s, wchar_t __wc) throw()
    __attribute__((__pure__));

extern size_t wcscspn(const wchar_t* __wcs, const wchar_t* __reject) throw()
    __attribute__((__pure__));

extern size_t wcsspn(const wchar_t* __wcs, const wchar_t* __accept) throw()
    __attribute__((__pure__));

extern "C++" wchar_t* wcspbrk(wchar_t* __wcs,
                              const wchar_t* __accept) throw() __asm("wcspbrk")
    __attribute__((__pure__));
extern "C++" const wchar_t* wcspbrk(
    const wchar_t* __wcs,
    const wchar_t* __accept) throw() __asm("wcspbrk") __attribute__((__pure__));

extern "C++" wchar_t* wcsstr(wchar_t* __haystack,
                             const wchar_t* __needle) throw() __asm("wcsstr")
    __attribute__((__pure__));
extern "C++" const wchar_t* wcsstr(
    const wchar_t* __haystack,
    const wchar_t* __needle) throw() __asm("wcsstr") __attribute__((__pure__));

extern wchar_t* wcstok(wchar_t* __restrict __s,
                       const wchar_t* __restrict __delim,
                       wchar_t** __restrict __ptr) throw();

extern size_t wcslen(const wchar_t* __s) throw() __attribute__((__pure__));

extern "C++" wchar_t* wcswcs(wchar_t* __haystack,
                             const wchar_t* __needle) throw() __asm("wcswcs")
    __attribute__((__pure__));
extern "C++" const wchar_t* wcswcs(
    const wchar_t* __haystack,
    const wchar_t* __needle) throw() __asm("wcswcs") __attribute__((__pure__));
extern size_t wcsnlen(const wchar_t* __s, size_t __maxlen) throw()
    __attribute__((__pure__));

extern "C++" wchar_t* wmemchr(wchar_t* __s,
                              wchar_t __c,
                              size_t __n) throw() __asm("wmemchr")
    __attribute__((__pure__));
extern "C++" const wchar_t* wmemchr(const wchar_t* __s,
                                    wchar_t __c,
                                    size_t __n) throw() __asm("wmemchr")
    __attribute__((__pure__));

extern int wmemcmp(const wchar_t* __s1, const wchar_t* __s2, size_t __n) throw()
    __attribute__((__pure__));

extern wchar_t* wmemcpy(wchar_t* __restrict __s1,
                        const wchar_t* __restrict __s2,
                        size_t __n) throw();

extern wchar_t* wmemmove(wchar_t* __s1,
                         const wchar_t* __s2,
                         size_t __n) throw();

extern wchar_t* wmemset(wchar_t* __s, wchar_t __c, size_t __n) throw();

extern wchar_t* wmempcpy(wchar_t* __restrict __s1,
                         const wchar_t* __restrict __s2,
                         size_t __n) throw();

extern wint_t btowc(int __c) throw();

extern int wctob(wint_t __c) throw();

extern int mbsinit(const mbstate_t* __ps) throw() __attribute__((__pure__));

extern size_t mbrtowc(wchar_t* __restrict __pwc,
                      const char* __restrict __s,
                      size_t __n,
                      mbstate_t* __restrict __p) throw();

extern size_t wcrtomb(char* __restrict __s,
                      wchar_t __wc,
                      mbstate_t* __restrict __ps) throw();

extern size_t __mbrlen(const char* __restrict __s,
                       size_t __n,
                       mbstate_t* __restrict __ps) throw();
extern size_t mbrlen(const char* __restrict __s,
                     size_t __n,
                     mbstate_t* __restrict __ps) throw();
extern size_t mbsrtowcs(wchar_t* __restrict __dst,
                        const char** __restrict __src,
                        size_t __len,
                        mbstate_t* __restrict __ps) throw();

extern size_t wcsrtombs(char* __restrict __dst,
                        const wchar_t** __restrict __src,
                        size_t __len,
                        mbstate_t* __restrict __ps) throw();

extern size_t mbsnrtowcs(wchar_t* __restrict __dst,
                         const char** __restrict __src,
                         size_t __nmc,
                         size_t __len,
                         mbstate_t* __restrict __ps) throw();

extern size_t wcsnrtombs(char* __restrict __dst,
                         const wchar_t** __restrict __src,
                         size_t __nwc,
                         size_t __len,
                         mbstate_t* __restrict __ps) throw();

extern int wcwidth(wchar_t __c) throw();

extern int wcswidth(const wchar_t* __s, size_t __n) throw();

extern double wcstod(const wchar_t* __restrict __nptr,
                     wchar_t** __restrict __endptr) throw();

extern float wcstof(const wchar_t* __restrict __nptr,
                    wchar_t** __restrict __endptr) throw();
extern long double wcstold(const wchar_t* __restrict __nptr,
                           wchar_t** __restrict __endptr) throw();

extern _Float128 wcstof128(const wchar_t* __restrict __nptr,
                           wchar_t** __restrict __endptr) throw();

extern long int wcstol(const wchar_t* __restrict __nptr,
                       wchar_t** __restrict __endptr,
                       int __base) throw();

extern unsigned long int wcstoul(const wchar_t* __restrict __nptr,
                                 wchar_t** __restrict __endptr,
                                 int __base) throw();

__extension__ extern long long int wcstoll(const wchar_t* __restrict __nptr,
                                           wchar_t** __restrict __endptr,
                                           int __base) throw();

__extension__ extern unsigned long long int wcstoull(
    const wchar_t* __restrict __nptr,
    wchar_t** __restrict __endptr,
    int __base) throw();

__extension__ extern long long int wcstoq(const wchar_t* __restrict __nptr,
                                          wchar_t** __restrict __endptr,
                                          int __base) throw();

__extension__ extern unsigned long long int wcstouq(
    const wchar_t* __restrict __nptr,
    wchar_t** __restrict __endptr,
    int __base) throw();

extern long int wcstol_l(const wchar_t* __restrict __nptr,
                         wchar_t** __restrict __endptr,
                         int __base,
                         locale_t __loc) throw();

extern unsigned long int wcstoul_l(const wchar_t* __restrict __nptr,
                                   wchar_t** __restrict __endptr,
                                   int __base,
                                   locale_t __loc) throw();

__extension__ extern long long int wcstoll_l(const wchar_t* __restrict __nptr,
                                             wchar_t** __restrict __endptr,
                                             int __base,
                                             locale_t __loc) throw();

__extension__ extern unsigned long long int wcstoull_l(
    const wchar_t* __restrict __nptr,
    wchar_t** __restrict __endptr,
    int __base,
    locale_t __loc) throw();

extern double wcstod_l(const wchar_t* __restrict __nptr,
                       wchar_t** __restrict __endptr,
                       locale_t __loc) throw();

extern float wcstof_l(const wchar_t* __restrict __nptr,
                      wchar_t** __restrict __endptr,
                      locale_t __loc) throw();

extern long double wcstold_l(const wchar_t* __restrict __nptr,
                             wchar_t** __restrict __endptr,
                             locale_t __loc) throw();

extern _Float128 wcstof128_l(const wchar_t* __restrict __nptr,
                             wchar_t** __restrict __endptr,
                             locale_t __loc) throw();

extern wchar_t* wcpcpy(wchar_t* __restrict __dest,
                       const wchar_t* __restrict __src) throw();

extern wchar_t* wcpncpy(wchar_t* __restrict __dest,
                        const wchar_t* __restrict __src,
                        size_t __n) throw();
extern __FILE* open_wmemstream(wchar_t** __bufloc, size_t* __sizeloc) throw();

extern int fwide(__FILE* __fp, int __mode) throw();

extern int fwprintf(__FILE* __restrict __stream,
                    const wchar_t* __restrict __format,
                    ...);

extern int wprintf(const wchar_t* __restrict __format, ...);

extern int swprintf(wchar_t* __restrict __s,
                    size_t __n,
                    const wchar_t* __restrict __format,
                    ...) throw();

extern int vfwprintf(__FILE* __restrict __s,
                     const wchar_t* __restrict __format,
                     __gnuc_va_list __arg);

extern int vwprintf(const wchar_t* __restrict __format, __gnuc_va_list __arg);

extern int vswprintf(wchar_t* __restrict __s,
                     size_t __n,
                     const wchar_t* __restrict __format,
                     __gnuc_va_list __arg) throw();

extern int fwscanf(__FILE* __restrict __stream,
                   const wchar_t* __restrict __format,
                   ...);

extern int wscanf(const wchar_t* __restrict __format, ...);

extern int swscanf(const wchar_t* __restrict __s,
                   const wchar_t* __restrict __format,
                   ...) throw();
extern int vfwscanf(__FILE* __restrict __s,
                    const wchar_t* __restrict __format,
                    __gnuc_va_list __arg);

extern int vwscanf(const wchar_t* __restrict __format, __gnuc_va_list __arg);

extern int vswscanf(const wchar_t* __restrict __s,
                    const wchar_t* __restrict __format,
                    __gnuc_va_list __arg) throw();
extern wint_t fgetwc(__FILE* __stream);
extern wint_t getwc(__FILE* __stream);

extern wint_t getwchar(void);

extern wint_t fputwc(wchar_t __wc, __FILE* __stream);
extern wint_t putwc(wchar_t __wc, __FILE* __stream);

extern wint_t putwchar(wchar_t __wc);

extern wchar_t* fgetws(wchar_t* __restrict __ws,
                       int __n,
                       __FILE* __restrict __stream);

extern int fputws(const wchar_t* __restrict __ws, __FILE* __restrict __stream);

extern wint_t ungetwc(wint_t __wc, __FILE* __stream);
extern wint_t getwc_unlocked(__FILE* __stream);
extern wint_t getwchar_unlocked(void);

extern wint_t fgetwc_unlocked(__FILE* __stream);

extern wint_t fputwc_unlocked(wchar_t __wc, __FILE* __stream);
extern wint_t putwc_unlocked(wchar_t __wc, __FILE* __stream);
extern wint_t putwchar_unlocked(wchar_t __wc);
extern wchar_t* fgetws_unlocked(wchar_t* __restrict __ws,
                                int __n,
                                __FILE* __restrict __stream);

extern int fputws_unlocked(const wchar_t* __restrict __ws,
                           __FILE* __restrict __stream);

extern size_t wcsftime(wchar_t* __restrict __s,
                       size_t __maxsize,
                       const wchar_t* __restrict __format,
                       const struct tm* __restrict __tp) throw();

extern size_t wcsftime_l(wchar_t* __restrict __s,
                         size_t __maxsize,
                         const wchar_t* __restrict __format,
                         const struct tm* __restrict __tp,
                         locale_t __loc) throw();
}
namespace std {
using ::mbstate_t;
}
namespace std __attribute__((__visibility__("default"))) {

  using ::wint_t;

  using ::btowc;
  using ::fgetwc;
  using ::fgetws;
  using ::fputwc;
  using ::fputws;
  using ::fwide;
  using ::fwprintf;
  using ::fwscanf;
  using ::getwc;
  using ::getwchar;
  using ::mbrlen;
  using ::mbrtowc;
  using ::mbsinit;
  using ::mbsrtowcs;
  using ::putwc;
  using ::putwchar;

  using ::swprintf;

  using ::swscanf;
  using ::ungetwc;
  using ::vfwprintf;

  using ::vfwscanf;

  using ::vswprintf;

  using ::vswscanf;

  using ::vwprintf;

  using ::vwscanf;

  using ::wcrtomb;
  using ::wcscat;
  using ::wcscmp;
  using ::wcscoll;
  using ::wcscpy;
  using ::wcscspn;
  using ::wcsftime;
  using ::wcslen;
  using ::wcsncat;
  using ::wcsncmp;
  using ::wcsncpy;
  using ::wcsrtombs;
  using ::wcsspn;
  using ::wcstod;

  using ::wcstof;

  using ::wcschr;
  using ::wcspbrk;
  using ::wcsrchr;
  using ::wcsstr;
  using ::wcstok;
  using ::wcstol;
  using ::wcstoul;
  using ::wcsxfrm;
  using ::wctob;
  using ::wmemchr;
  using ::wmemcmp;
  using ::wmemcpy;
  using ::wmemmove;
  using ::wmemset;
  using ::wprintf;
  using ::wscanf;

}  // namespace std__attribute__((__visibility__("default")))

namespace __gnu_cxx {

using ::wcstold;
using ::wcstoll;
using ::wcstoull;

}  // namespace __gnu_cxx

namespace std {
using ::__gnu_cxx::wcstold;
using ::__gnu_cxx::wcstoll;
using ::__gnu_cxx::wcstoull;
}  // namespace std
namespace std {

using std::wcstof;

using std::vfwscanf;

using std::vswscanf;

using std::vwscanf;

using std::wcstold;
using std::wcstoll;
using std::wcstoull;

}  // namespace std
namespace std __attribute__((__visibility__("default"))) {

  typedef long streamoff;
  typedef ptrdiff_t streamsize;
  template <typename _StateT>
  class fpos {
   private:
    streamoff _M_off;
    _StateT _M_state;

   public:
    fpos() : _M_off(0), _M_state() {}
    fpos(streamoff __off) : _M_off(__off), _M_state() {}

    operator streamoff() const { return _M_off; }

    void state(_StateT __st) { _M_state = __st; }

    _StateT state() const { return _M_state; }

    fpos& operator+=(streamoff __off) {
      _M_off += __off;
      return *this;
    }

    fpos& operator-=(streamoff __off) {
      _M_off -= __off;
      return *this;
    }

    fpos operator+(streamoff __off) const {
      fpos __pos(*this);
      __pos += __off;
      return __pos;
    }

    fpos operator-(streamoff __off) const {
      fpos __pos(*this);
      __pos -= __off;
      return __pos;
    }

    streamoff operator-(const fpos& __other) const {
      return _M_off - __other._M_off;
    }
  };

  template <typename _StateT>
  inline bool operator==(const fpos<_StateT>& __lhs,
                         const fpos<_StateT>& __rhs) {
    return streamoff(__lhs) == streamoff(__rhs);
  }

  template <typename _StateT>
  inline bool operator!=(const fpos<_StateT>& __lhs,
                         const fpos<_StateT>& __rhs) {
    return streamoff(__lhs) != streamoff(__rhs);
  }

  typedef fpos<mbstate_t> streampos;

  typedef fpos<mbstate_t> wstreampos;

  typedef fpos<mbstate_t> u16streampos;

  typedef fpos<mbstate_t> u32streampos;

}  // namespace std__attribute__((__visibility__("default")))

namespace __gnu_cxx __attribute__((__visibility__("default"))) {

  template <typename _CharT>
  struct _Char_types {
    typedef unsigned long int_type;
    typedef std::streampos pos_type;
    typedef std::streamoff off_type;
    typedef std::mbstate_t state_type;
  };
  template <typename _CharT>
  struct char_traits {
    typedef _CharT char_type;
    typedef typename _Char_types<_CharT>::int_type int_type;
    typedef typename _Char_types<_CharT>::pos_type pos_type;
    typedef typename _Char_types<_CharT>::off_type off_type;
    typedef typename _Char_types<_CharT>::state_type state_type;

    static constexpr void assign(char_type& __c1, const char_type& __c2) {
      __c1 = __c2;
    }

    static constexpr bool eq(const char_type& __c1, const char_type& __c2) {
      return __c1 == __c2;
    }

    static constexpr bool lt(const char_type& __c1, const char_type& __c2) {
      return __c1 < __c2;
    }

    static constexpr int compare(const char_type* __s1,
                                 const char_type* __s2,
                                 std::size_t __n);

    static constexpr std::size_t length(const char_type* __s);

    static constexpr const char_type* find(const char_type* __s,
                                           std::size_t __n,
                                           const char_type& __a);

    static char_type* move(char_type* __s1,
                           const char_type* __s2,
                           std::size_t __n);

    static char_type* copy(char_type* __s1,
                           const char_type* __s2,
                           std::size_t __n);

    static char_type* assign(char_type* __s, std::size_t __n, char_type __a);

    static constexpr char_type to_char_type(const int_type& __c) {
      return static_cast<char_type>(__c);
    }

    static constexpr int_type to_int_type(const char_type& __c) {
      return static_cast<int_type>(__c);
    }

    static constexpr bool eq_int_type(const int_type& __c1,
                                      const int_type& __c2) {
      return __c1 == __c2;
    }

    static constexpr int_type eof() { return static_cast<int_type>(-1); }

    static constexpr int_type not_eof(const int_type& __c) {
      return !eq_int_type(__c, eof()) ? __c : to_int_type(char_type());
    }
  };

  template <typename _CharT>
  constexpr int char_traits<_CharT>::compare(
      const char_type* __s1, const char_type* __s2, std::size_t __n) {
    for (std::size_t __i = 0; __i < __n; ++__i)
      if (lt(__s1[__i], __s2[__i]))
        return -1;
      else if (lt(__s2[__i], __s1[__i]))
        return 1;
    return 0;
  }

  template <typename _CharT>
  constexpr std::size_t char_traits<_CharT>::length(const char_type* __p) {
    std::size_t __i = 0;
    while (!eq(__p[__i], char_type()))
      ++__i;
    return __i;
  }

  template <typename _CharT>
  constexpr const typename char_traits<_CharT>::char_type*
  char_traits<_CharT>::find(const char_type* __s, std::size_t __n,
                            const char_type& __a) {
    for (std::size_t __i = 0; __i < __n; ++__i)
      if (eq(__s[__i], __a))
        return __s + __i;
    return 0;
  }

  template <typename _CharT>
  typename char_traits<_CharT>::char_type* char_traits<_CharT>::move(
      char_type * __s1, const char_type* __s2, std::size_t __n) {
    return static_cast<_CharT*>(
        __builtin_memmove(__s1, __s2, __n * sizeof(char_type)));
  }

  template <typename _CharT>
  typename char_traits<_CharT>::char_type* char_traits<_CharT>::copy(
      char_type * __s1, const char_type* __s2, std::size_t __n) {
    std::copy(__s2, __s2 + __n, __s1);
    return __s1;
  }

  template <typename _CharT>
  typename char_traits<_CharT>::char_type* char_traits<_CharT>::assign(
      char_type * __s, std::size_t __n, char_type __a) {
    std::fill_n(__s, __n, __a);
    return __s;
  }

}  // namespace __gnu_cxx__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <class _CharT>
  struct char_traits : public __gnu_cxx::char_traits<_CharT> {};

  template <>
  struct char_traits<char> {
    typedef char char_type;
    typedef int int_type;
    typedef streampos pos_type;
    typedef streamoff off_type;
    typedef mbstate_t state_type;

    static void assign(char_type& __c1, const char_type& __c2) noexcept {
      __c1 = __c2;
    }

    static constexpr bool eq(const char_type& __c1,
                             const char_type& __c2) noexcept {
      return __c1 == __c2;
    }

    static constexpr bool lt(const char_type& __c1,
                             const char_type& __c2) noexcept {
      return (static_cast<unsigned char>(__c1) <
              static_cast<unsigned char>(__c2));
    }

    static int compare(const char_type* __s1,
                       const char_type* __s2,
                       size_t __n) {
      if (__n == 0)
        return 0;
      return __builtin_memcmp(__s1, __s2, __n);
    }

    static size_t length(const char_type* __s) { return __builtin_strlen(__s); }

    static const char_type* find(const char_type* __s,
                                 size_t __n,
                                 const char_type& __a) {
      if (__n == 0)
        return 0;
      return static_cast<const char_type*>(__builtin_memchr(__s, __a, __n));
    }

    static char_type* move(char_type* __s1, const char_type* __s2, size_t __n) {
      if (__n == 0)
        return __s1;
      return static_cast<char_type*>(__builtin_memmove(__s1, __s2, __n));
    }

    static char_type* copy(char_type* __s1, const char_type* __s2, size_t __n) {
      if (__n == 0)
        return __s1;
      return static_cast<char_type*>(__builtin_memcpy(__s1, __s2, __n));
    }

    static char_type* assign(char_type* __s, size_t __n, char_type __a) {
      if (__n == 0)
        return __s;
      return static_cast<char_type*>(__builtin_memset(__s, __a, __n));
    }

    static constexpr char_type to_char_type(const int_type& __c) noexcept {
      return static_cast<char_type>(__c);
    }

    static constexpr int_type to_int_type(const char_type& __c) noexcept {
      return static_cast<int_type>(static_cast<unsigned char>(__c));
    }

    static constexpr bool eq_int_type(const int_type& __c1,
                                      const int_type& __c2) noexcept {
      return __c1 == __c2;
    }

    static constexpr int_type eof() noexcept {
      return static_cast<int_type>(-1);
    }

    static constexpr int_type not_eof(const int_type& __c) noexcept {
      return (__c == eof()) ? 0 : __c;
    }
  };

  template <>
  struct char_traits<wchar_t> {
    typedef wchar_t char_type;
    typedef wint_t int_type;
    typedef streamoff off_type;
    typedef wstreampos pos_type;
    typedef mbstate_t state_type;

    static void assign(char_type& __c1, const char_type& __c2) noexcept {
      __c1 = __c2;
    }

    static constexpr bool eq(const char_type& __c1,
                             const char_type& __c2) noexcept {
      return __c1 == __c2;
    }

    static constexpr bool lt(const char_type& __c1,
                             const char_type& __c2) noexcept {
      return __c1 < __c2;
    }

    static int compare(const char_type* __s1,
                       const char_type* __s2,
                       size_t __n) {
      if (__n == 0)
        return 0;
      return wmemcmp(__s1, __s2, __n);
    }

    static size_t length(const char_type* __s) { return wcslen(__s); }

    static const char_type* find(const char_type* __s,
                                 size_t __n,
                                 const char_type& __a) {
      if (__n == 0)
        return 0;
      return wmemchr(__s, __a, __n);
    }

    static char_type* move(char_type* __s1, const char_type* __s2, size_t __n) {
      if (__n == 0)
        return __s1;
      return wmemmove(__s1, __s2, __n);
    }

    static char_type* copy(char_type* __s1, const char_type* __s2, size_t __n) {
      if (__n == 0)
        return __s1;
      return wmemcpy(__s1, __s2, __n);
    }

    static char_type* assign(char_type* __s, size_t __n, char_type __a) {
      if (__n == 0)
        return __s;
      return wmemset(__s, __a, __n);
    }

    static constexpr char_type to_char_type(const int_type& __c) noexcept {
      return char_type(__c);
    }

    static constexpr int_type to_int_type(const char_type& __c) noexcept {
      return int_type(__c);
    }

    static constexpr bool eq_int_type(const int_type& __c1,
                                      const int_type& __c2) noexcept {
      return __c1 == __c2;
    }

    static constexpr int_type eof() noexcept {
      return static_cast<int_type>((0xffffffffu));
    }

    static constexpr int_type not_eof(const int_type& __c) noexcept {
      return eq_int_type(__c, eof()) ? 0 : __c;
    }
  };

}  // namespace std__attribute__((__visibility__("default")))

namespace std {
using ::int16_t;
using ::int32_t;
using ::int64_t;
using ::int8_t;

using ::int_fast16_t;
using ::int_fast32_t;
using ::int_fast64_t;
using ::int_fast8_t;

using ::int_least16_t;
using ::int_least32_t;
using ::int_least64_t;
using ::int_least8_t;

using ::intmax_t;
using ::intptr_t;

using ::uint16_t;
using ::uint32_t;
using ::uint64_t;
using ::uint8_t;

using ::uint_fast16_t;
using ::uint_fast32_t;
using ::uint_fast64_t;
using ::uint_fast8_t;

using ::uint_least16_t;
using ::uint_least32_t;
using ::uint_least64_t;
using ::uint_least8_t;

using ::uintmax_t;
using ::uintptr_t;
}  // namespace std

namespace std __attribute__((__visibility__("default"))) {

  template <>
  struct char_traits<char16_t> {
    typedef char16_t char_type;
    typedef uint_least16_t int_type;
    typedef streamoff off_type;
    typedef u16streampos pos_type;
    typedef mbstate_t state_type;

    static void assign(char_type& __c1, const char_type& __c2) noexcept {
      __c1 = __c2;
    }

    static constexpr bool eq(const char_type& __c1,
                             const char_type& __c2) noexcept {
      return __c1 == __c2;
    }

    static constexpr bool lt(const char_type& __c1,
                             const char_type& __c2) noexcept {
      return __c1 < __c2;
    }

    static int compare(const char_type* __s1,
                       const char_type* __s2,
                       size_t __n) {
      for (size_t __i = 0; __i < __n; ++__i)
        if (lt(__s1[__i], __s2[__i]))
          return -1;
        else if (lt(__s2[__i], __s1[__i]))
          return 1;
      return 0;
    }

    static size_t length(const char_type* __s) {
      size_t __i = 0;
      while (!eq(__s[__i], char_type()))
        ++__i;
      return __i;
    }

    static const char_type* find(const char_type* __s,
                                 size_t __n,
                                 const char_type& __a) {
      for (size_t __i = 0; __i < __n; ++__i)
        if (eq(__s[__i], __a))
          return __s + __i;
      return 0;
    }

    static char_type* move(char_type* __s1, const char_type* __s2, size_t __n) {
      if (__n == 0)
        return __s1;
      return (static_cast<char_type*>(
          __builtin_memmove(__s1, __s2, __n * sizeof(char_type))));
    }

    static char_type* copy(char_type* __s1, const char_type* __s2, size_t __n) {
      if (__n == 0)
        return __s1;
      return (static_cast<char_type*>(
          __builtin_memcpy(__s1, __s2, __n * sizeof(char_type))));
    }

    static char_type* assign(char_type* __s, size_t __n, char_type __a) {
      for (size_t __i = 0; __i < __n; ++__i)
        assign(__s[__i], __a);
      return __s;
    }

    static constexpr char_type to_char_type(const int_type& __c) noexcept {
      return char_type(__c);
    }

    static constexpr int_type to_int_type(const char_type& __c) noexcept {
      return int_type(__c);
    }

    static constexpr bool eq_int_type(const int_type& __c1,
                                      const int_type& __c2) noexcept {
      return __c1 == __c2;
    }

    static constexpr int_type eof() noexcept {
      return static_cast<int_type>(-1);
    }

    static constexpr int_type not_eof(const int_type& __c) noexcept {
      return eq_int_type(__c, eof()) ? 0 : __c;
    }
  };

  template <>
  struct char_traits<char32_t> {
    typedef char32_t char_type;
    typedef uint_least32_t int_type;
    typedef streamoff off_type;
    typedef u32streampos pos_type;
    typedef mbstate_t state_type;

    static void assign(char_type& __c1, const char_type& __c2) noexcept {
      __c1 = __c2;
    }

    static constexpr bool eq(const char_type& __c1,
                             const char_type& __c2) noexcept {
      return __c1 == __c2;
    }

    static constexpr bool lt(const char_type& __c1,
                             const char_type& __c2) noexcept {
      return __c1 < __c2;
    }

    static int compare(const char_type* __s1,
                       const char_type* __s2,
                       size_t __n) {
      for (size_t __i = 0; __i < __n; ++__i)
        if (lt(__s1[__i], __s2[__i]))
          return -1;
        else if (lt(__s2[__i], __s1[__i]))
          return 1;
      return 0;
    }

    static size_t length(const char_type* __s) {
      size_t __i = 0;
      while (!eq(__s[__i], char_type()))
        ++__i;
      return __i;
    }

    static const char_type* find(const char_type* __s,
                                 size_t __n,
                                 const char_type& __a) {
      for (size_t __i = 0; __i < __n; ++__i)
        if (eq(__s[__i], __a))
          return __s + __i;
      return 0;
    }

    static char_type* move(char_type* __s1, const char_type* __s2, size_t __n) {
      if (__n == 0)
        return __s1;
      return (static_cast<char_type*>(
          __builtin_memmove(__s1, __s2, __n * sizeof(char_type))));
    }

    static char_type* copy(char_type* __s1, const char_type* __s2, size_t __n) {
      if (__n == 0)
        return __s1;
      return (static_cast<char_type*>(
          __builtin_memcpy(__s1, __s2, __n * sizeof(char_type))));
    }

    static char_type* assign(char_type* __s, size_t __n, char_type __a) {
      for (size_t __i = 0; __i < __n; ++__i)
        assign(__s[__i], __a);
      return __s;
    }

    static constexpr char_type to_char_type(const int_type& __c) noexcept {
      return char_type(__c);
    }

    static constexpr int_type to_int_type(const char_type& __c) noexcept {
      return int_type(__c);
    }

    static constexpr bool eq_int_type(const int_type& __c1,
                                      const int_type& __c2) noexcept {
      return __c1 == __c2;
    }

    static constexpr int_type eof() noexcept {
      return static_cast<int_type>(-1);
    }

    static constexpr int_type not_eof(const int_type& __c) noexcept {
      return eq_int_type(__c, eof()) ? 0 : __c;
    }
  };

}  // namespace std__attribute__((__visibility__("default")))

extern "C" {
struct lconv {
  char* decimal_point;
  char* thousands_sep;

  char* grouping;

  char* int_curr_symbol;
  char* currency_symbol;
  char* mon_decimal_point;
  char* mon_thousands_sep;
  char* mon_grouping;
  char* positive_sign;
  char* negative_sign;
  char int_frac_digits;
  char frac_digits;

  char p_cs_precedes;

  char p_sep_by_space;

  char n_cs_precedes;

  char n_sep_by_space;

  char p_sign_posn;
  char n_sign_posn;

  char int_p_cs_precedes;

  char int_p_sep_by_space;

  char int_n_cs_precedes;

  char int_n_sep_by_space;

  char int_p_sign_posn;
  char int_n_sign_posn;
};

extern char* setlocale(int __category, const char* __locale) throw();

extern struct lconv* localeconv(void) throw();
extern locale_t newlocale(int __category_mask,
                          const char* __locale,
                          locale_t __base) throw();
extern locale_t duplocale(locale_t __dataset) throw();

extern void freelocale(locale_t __dataset) throw();

extern locale_t uselocale(locale_t __dataset) throw();
}
namespace std {
using ::lconv;
using ::localeconv;
using ::setlocale;
}  // namespace std

namespace __gnu_cxx __attribute__((__visibility__("default"))) {

  extern "C" __typeof(uselocale) __uselocale;
}

namespace std __attribute__((__visibility__("default"))) {

  typedef __locale_t __c_locale;

  inline int __convert_from_v(
      const __c_locale& __cloc __attribute__((__unused__)), char* __out,
      const int __size __attribute__((__unused__)), const char* __fmt, ...) {
    __c_locale __old = __gnu_cxx::__uselocale(__cloc);
    __builtin_va_list __args;
    __builtin_va_start(__args, __fmt);

    const int __ret = __builtin_vsnprintf(__out, __size, __fmt, __args);

    __builtin_va_end(__args);

    __gnu_cxx::__uselocale(__old);

    return __ret;
  }

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  class ios_base;

  template <typename _CharT, typename _Traits = char_traits<_CharT>>
  class basic_ios;

  template <typename _CharT, typename _Traits = char_traits<_CharT>>
  class basic_streambuf;

  template <typename _CharT, typename _Traits = char_traits<_CharT>>
  class basic_istream;

  template <typename _CharT, typename _Traits = char_traits<_CharT>>
  class basic_ostream;

  template <typename _CharT, typename _Traits = char_traits<_CharT>>
  class basic_iostream;

  namespace __cxx11 {

  template <typename _CharT,
            typename _Traits = char_traits<_CharT>,
            typename _Alloc = allocator<_CharT>>
  class basic_stringbuf;

  template <typename _CharT,
            typename _Traits = char_traits<_CharT>,
            typename _Alloc = allocator<_CharT>>
  class basic_istringstream;

  template <typename _CharT,
            typename _Traits = char_traits<_CharT>,
            typename _Alloc = allocator<_CharT>>
  class basic_ostringstream;

  template <typename _CharT,
            typename _Traits = char_traits<_CharT>,
            typename _Alloc = allocator<_CharT>>
  class basic_stringstream;

  }  // namespace __cxx11

  template <typename _CharT, typename _Traits = char_traits<_CharT>>
  class basic_filebuf;

  template <typename _CharT, typename _Traits = char_traits<_CharT>>
  class basic_ifstream;

  template <typename _CharT, typename _Traits = char_traits<_CharT>>
  class basic_ofstream;

  template <typename _CharT, typename _Traits = char_traits<_CharT>>
  class basic_fstream;

  template <typename _CharT, typename _Traits = char_traits<_CharT>>
  class istreambuf_iterator;

  template <typename _CharT, typename _Traits = char_traits<_CharT>>
  class ostreambuf_iterator;

  typedef basic_ios<char> ios;

  typedef basic_streambuf<char> streambuf;

  typedef basic_istream<char> istream;

  typedef basic_ostream<char> ostream;

  typedef basic_iostream<char> iostream;

  typedef basic_stringbuf<char> stringbuf;

  typedef basic_istringstream<char> istringstream;

  typedef basic_ostringstream<char> ostringstream;

  typedef basic_stringstream<char> stringstream;

  typedef basic_filebuf<char> filebuf;

  typedef basic_ifstream<char> ifstream;

  typedef basic_ofstream<char> ofstream;

  typedef basic_fstream<char> fstream;

  typedef basic_ios<wchar_t> wios;

  typedef basic_streambuf<wchar_t> wstreambuf;

  typedef basic_istream<wchar_t> wistream;

  typedef basic_ostream<wchar_t> wostream;

  typedef basic_iostream<wchar_t> wiostream;

  typedef basic_stringbuf<wchar_t> wstringbuf;

  typedef basic_istringstream<wchar_t> wistringstream;

  typedef basic_ostringstream<wchar_t> wostringstream;

  typedef basic_stringstream<wchar_t> wstringstream;

  typedef basic_filebuf<wchar_t> wfilebuf;

  typedef basic_ifstream<wchar_t> wifstream;

  typedef basic_ofstream<wchar_t> wofstream;

  typedef basic_fstream<wchar_t> wfstream;

}  // namespace std__attribute__((__visibility__("default")))

extern "C" {

static __inline unsigned int __bswap_32(unsigned int __bsx) {
  return __builtin_bswap32(__bsx);
}
static __inline __uint64_t __bswap_64(__uint64_t __bsx) {
  return __builtin_bswap64(__bsx);
}
static __inline __uint16_t __uint16_identity(__uint16_t __x) {
  return __x;
}

static __inline __uint32_t __uint32_identity(__uint32_t __x) {
  return __x;
}

static __inline __uint64_t __uint64_identity(__uint64_t __x) {
  return __x;
}

enum {
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
extern const unsigned short int** __ctype_b_loc(void) throw()
    __attribute__((__const__));
extern const __int32_t** __ctype_tolower_loc(void) throw()
    __attribute__((__const__));
extern const __int32_t** __ctype_toupper_loc(void) throw()
    __attribute__((__const__));
extern int isalnum(int) throw();
extern int isalpha(int) throw();
extern int iscntrl(int) throw();
extern int isdigit(int) throw();
extern int islower(int) throw();
extern int isgraph(int) throw();
extern int isprint(int) throw();
extern int ispunct(int) throw();
extern int isspace(int) throw();
extern int isupper(int) throw();
extern int isxdigit(int) throw();

extern int tolower(int __c) throw();

extern int toupper(int __c) throw();

extern int isblank(int) throw();

extern int isctype(int __c, int __mask) throw();

extern int isascii(int __c) throw();

extern int toascii(int __c) throw();

extern int _toupper(int) throw();
extern int _tolower(int) throw();
extern int isalnum_l(int, locale_t) throw();
extern int isalpha_l(int, locale_t) throw();
extern int iscntrl_l(int, locale_t) throw();
extern int isdigit_l(int, locale_t) throw();
extern int islower_l(int, locale_t) throw();
extern int isgraph_l(int, locale_t) throw();
extern int isprint_l(int, locale_t) throw();
extern int ispunct_l(int, locale_t) throw();
extern int isspace_l(int, locale_t) throw();
extern int isupper_l(int, locale_t) throw();
extern int isxdigit_l(int, locale_t) throw();

extern int isblank_l(int, locale_t) throw();

extern int __tolower_l(int __c, locale_t __l) throw();
extern int tolower_l(int __c, locale_t __l) throw();

extern int __toupper_l(int __c, locale_t __l) throw();
extern int toupper_l(int __c, locale_t __l) throw();
}
namespace std {
using ::isalnum;
using ::isalpha;
using ::iscntrl;
using ::isdigit;
using ::isgraph;
using ::islower;
using ::isprint;
using ::ispunct;
using ::isspace;
using ::isupper;
using ::isxdigit;
using ::tolower;
using ::toupper;
}  // namespace std

namespace std {
using ::isblank;
}

namespace std __attribute__((__visibility__("default"))) {

  class locale;

  template <typename _Facet>
  bool has_facet(const locale&) throw();

  template <typename _Facet>
  const _Facet& use_facet(const locale&);

  template <typename _CharT>
  bool isspace(_CharT, const locale&);

  template <typename _CharT>
  bool isprint(_CharT, const locale&);

  template <typename _CharT>
  bool iscntrl(_CharT, const locale&);

  template <typename _CharT>
  bool isupper(_CharT, const locale&);

  template <typename _CharT>
  bool islower(_CharT, const locale&);

  template <typename _CharT>
  bool isalpha(_CharT, const locale&);

  template <typename _CharT>
  bool isdigit(_CharT, const locale&);

  template <typename _CharT>
  bool ispunct(_CharT, const locale&);

  template <typename _CharT>
  bool isxdigit(_CharT, const locale&);

  template <typename _CharT>
  bool isalnum(_CharT, const locale&);

  template <typename _CharT>
  bool isgraph(_CharT, const locale&);

  template <typename _CharT>
  bool isblank(_CharT, const locale&);

  template <typename _CharT>
  _CharT toupper(_CharT, const locale&);

  template <typename _CharT>
  _CharT tolower(_CharT, const locale&);

  class ctype_base;
  template <typename _CharT>
  class ctype;
  template <>
  class ctype<char>;

  template <>
  class ctype<wchar_t>;

  template <typename _CharT>
  class ctype_byname;

  class codecvt_base;
  template <typename _InternT, typename _ExternT, typename _StateT>
  class codecvt;
  template <>
  class codecvt<char, char, mbstate_t>;

  template <>
  class codecvt<wchar_t, char, mbstate_t>;

  template <typename _InternT, typename _ExternT, typename _StateT>
  class codecvt_byname;

  template <typename _CharT, typename _InIter = istreambuf_iterator<_CharT>>
  class num_get;
  template <typename _CharT, typename _OutIter = ostreambuf_iterator<_CharT>>
  class num_put;

  namespace __cxx11 {
  template <typename _CharT>
  class numpunct;
  template <typename _CharT>
  class numpunct_byname;
  }  // namespace __cxx11

  namespace __cxx11 {

  template <typename _CharT>
  class collate;
  template <typename _CharT>
  class collate_byname;
  }  // namespace __cxx11

  class time_base;
  namespace __cxx11 {
  template <typename _CharT, typename _InIter = istreambuf_iterator<_CharT>>
  class time_get;
  template <typename _CharT, typename _InIter = istreambuf_iterator<_CharT>>
  class time_get_byname;
  }  // namespace __cxx11
  template <typename _CharT, typename _OutIter = ostreambuf_iterator<_CharT>>
  class time_put;
  template <typename _CharT, typename _OutIter = ostreambuf_iterator<_CharT>>
  class time_put_byname;

  class money_base;
  namespace __cxx11 {
  template <typename _CharT, typename _InIter = istreambuf_iterator<_CharT>>
  class money_get;
  template <typename _CharT, typename _OutIter = ostreambuf_iterator<_CharT>>
  class money_put;
  }  // namespace __cxx11
  namespace __cxx11 {
  template <typename _CharT, bool _Intl = false>
  class moneypunct;
  template <typename _CharT, bool _Intl = false>
  class moneypunct_byname;
  }  // namespace __cxx11

  class messages_base;
  namespace __cxx11 {
  template <typename _CharT>
  class messages;
  template <typename _CharT>
  class messages_byname;
  }  // namespace __cxx11

}  // namespace std__attribute__((__visibility__("default")))

#pragma GCC visibility push(default)

namespace __cxxabiv1 {

class __forced_unwind {
  virtual ~__forced_unwind() throw();

  virtual void __pure_dummy() = 0;
};
}  // namespace __cxxabiv1

#pragma GCC visibility pop

namespace std __attribute__((__visibility__("default"))) {

  template <typename _CharT, typename _Traits>
  inline void __ostream_write(basic_ostream<_CharT, _Traits> & __out,
                              const _CharT* __s, streamsize __n) {
    typedef basic_ostream<_CharT, _Traits> __ostream_type;
    typedef typename __ostream_type::ios_base __ios_base;

    const streamsize __put = __out.rdbuf()->sputn(__s, __n);
    if (__put != __n)
      __out.setstate(__ios_base::badbit);
  }

  template <typename _CharT, typename _Traits>
  inline void __ostream_fill(basic_ostream<_CharT, _Traits> & __out,
                             streamsize __n) {
    typedef basic_ostream<_CharT, _Traits> __ostream_type;
    typedef typename __ostream_type::ios_base __ios_base;

    const _CharT __c = __out.fill();
    for (; __n > 0; --__n) {
      const typename _Traits::int_type __put = __out.rdbuf()->sputc(__c);
      if (_Traits::eq_int_type(__put, _Traits::eof())) {
        __out.setstate(__ios_base::badbit);
        break;
      }
    }
  }

  template <typename _CharT, typename _Traits>
  basic_ostream<_CharT, _Traits>& __ostream_insert(
      basic_ostream<_CharT, _Traits> & __out, const _CharT* __s,
      streamsize __n) {
    typedef basic_ostream<_CharT, _Traits> __ostream_type;
    typedef typename __ostream_type::ios_base __ios_base;

    typename __ostream_type::sentry __cerb(__out);
    if (__cerb) {
      try {
        const streamsize __w = __out.width();
        if (__w > __n) {
          const bool __left =
              ((__out.flags() & __ios_base::adjustfield) == __ios_base::left);
          if (!__left)
            __ostream_fill(__out, __w - __n);
          if (__out.good())
            __ostream_write(__out, __s, __n);
          if (__left && __out.good())
            __ostream_fill(__out, __w - __n);
        } else
          __ostream_write(__out, __s, __n);
        __out.width(0);
      } catch (__cxxabiv1::__forced_unwind&) {
        __out._M_setstate(__ios_base::badbit);
        throw;
      } catch (...) {
        __out._M_setstate(__ios_base::badbit);
      }
    }
    return __out;
  }

  extern template ostream& __ostream_insert(ostream&, const char*, streamsize);

  extern template wostream& __ostream_insert(wostream&, const wchar_t*,
                                             streamsize);

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Arg, typename _Result>
  struct unary_function {
    typedef _Arg argument_type;

    typedef _Result result_type;
  };

  template <typename _Arg1, typename _Arg2, typename _Result>
  struct binary_function {
    typedef _Arg1 first_argument_type;

    typedef _Arg2 second_argument_type;

    typedef _Result result_type;
  };
  struct __is_transparent;

  template <typename _Tp = void>
  struct plus;

  template <typename _Tp = void>
  struct minus;

  template <typename _Tp = void>
  struct multiplies;

  template <typename _Tp = void>
  struct divides;

  template <typename _Tp = void>
  struct modulus;

  template <typename _Tp = void>
  struct negate;

  template <typename _Tp>
  struct plus : public binary_function<_Tp, _Tp, _Tp> {
    constexpr _Tp operator()(const _Tp& __x, const _Tp& __y) const {
      return __x + __y;
    }
  };

  template <typename _Tp>
  struct minus : public binary_function<_Tp, _Tp, _Tp> {
    constexpr _Tp operator()(const _Tp& __x, const _Tp& __y) const {
      return __x - __y;
    }
  };

  template <typename _Tp>
  struct multiplies : public binary_function<_Tp, _Tp, _Tp> {
    constexpr _Tp operator()(const _Tp& __x, const _Tp& __y) const {
      return __x * __y;
    }
  };

  template <typename _Tp>
  struct divides : public binary_function<_Tp, _Tp, _Tp> {
    constexpr _Tp operator()(const _Tp& __x, const _Tp& __y) const {
      return __x / __y;
    }
  };

  template <typename _Tp>
  struct modulus : public binary_function<_Tp, _Tp, _Tp> {
    constexpr _Tp operator()(const _Tp& __x, const _Tp& __y) const {
      return __x % __y;
    }
  };

  template <typename _Tp>
  struct negate : public unary_function<_Tp, _Tp> {
    constexpr _Tp operator()(const _Tp& __x) const { return -__x; }
  };

  template <>
  struct plus<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp&& __t, _Up&& __u) const
        noexcept(noexcept(std::forward<_Tp>(__t) + std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) + std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) + std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <>
  struct minus<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp&& __t, _Up&& __u) const
        noexcept(noexcept(std::forward<_Tp>(__t) - std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) - std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) - std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <>
  struct multiplies<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp&& __t, _Up&& __u) const
        noexcept(noexcept(std::forward<_Tp>(__t) * std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) * std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) * std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <>
  struct divides<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp&& __t, _Up&& __u) const
        noexcept(noexcept(std::forward<_Tp>(__t) / std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) / std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) / std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <>
  struct modulus<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp&& __t, _Up&& __u) const
        noexcept(noexcept(std::forward<_Tp>(__t) % std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) % std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) % std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <>
  struct negate<void> {
    template <typename _Tp>
    constexpr auto operator()(_Tp&& __t) const
        noexcept(noexcept(-std::forward<_Tp>(__t)))
            -> decltype(-std::forward<_Tp>(__t)) {
      return -std::forward<_Tp>(__t);
    }

    typedef __is_transparent is_transparent;
  };
  template <typename _Tp = void>
  struct equal_to;

  template <typename _Tp = void>
  struct not_equal_to;

  template <typename _Tp = void>
  struct greater;

  template <typename _Tp = void>
  struct less;

  template <typename _Tp = void>
  struct greater_equal;

  template <typename _Tp = void>
  struct less_equal;

  template <typename _Tp>
  struct equal_to : public binary_function<_Tp, _Tp, bool> {
    constexpr bool operator()(const _Tp& __x, const _Tp& __y) const {
      return __x == __y;
    }
  };

  template <typename _Tp>
  struct not_equal_to : public binary_function<_Tp, _Tp, bool> {
    constexpr bool operator()(const _Tp& __x, const _Tp& __y) const {
      return __x != __y;
    }
  };

  template <typename _Tp>
  struct greater : public binary_function<_Tp, _Tp, bool> {
    constexpr bool operator()(const _Tp& __x, const _Tp& __y) const {
      return __x > __y;
    }
  };

  template <typename _Tp>
  struct less : public binary_function<_Tp, _Tp, bool> {
    constexpr bool operator()(const _Tp& __x, const _Tp& __y) const {
      return __x < __y;
    }
  };

  template <typename _Tp>
  struct greater_equal : public binary_function<_Tp, _Tp, bool> {
    constexpr bool operator()(const _Tp& __x, const _Tp& __y) const {
      return __x >= __y;
    }
  };

  template <typename _Tp>
  struct less_equal : public binary_function<_Tp, _Tp, bool> {
    constexpr bool operator()(const _Tp& __x, const _Tp& __y) const {
      return __x <= __y;
    }
  };

  template <>
  struct equal_to<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp&& __t, _Up&& __u) const
        noexcept(noexcept(std::forward<_Tp>(__t) == std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) == std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) == std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <>
  struct not_equal_to<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp&& __t, _Up&& __u) const
        noexcept(noexcept(std::forward<_Tp>(__t) != std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) != std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) != std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <>
  struct greater<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp&& __t, _Up&& __u) const
        noexcept(noexcept(std::forward<_Tp>(__t) > std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) > std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) > std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <>
  struct less<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp&& __t, _Up&& __u) const
        noexcept(noexcept(std::forward<_Tp>(__t) < std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) < std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) < std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <>
  struct greater_equal<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp&& __t, _Up&& __u) const
        noexcept(noexcept(std::forward<_Tp>(__t) >= std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) >= std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) >= std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <>
  struct less_equal<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp&& __t, _Up&& __u) const
        noexcept(noexcept(std::forward<_Tp>(__t) <= std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) <= std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) <= std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };
  template <typename _Tp = void>
  struct logical_and;

  template <typename _Tp = void>
  struct logical_or;

  template <typename _Tp = void>
  struct logical_not;

  template <typename _Tp>
  struct logical_and : public binary_function<_Tp, _Tp, bool> {
    constexpr bool operator()(const _Tp& __x, const _Tp& __y) const {
      return __x && __y;
    }
  };

  template <typename _Tp>
  struct logical_or : public binary_function<_Tp, _Tp, bool> {
    constexpr bool operator()(const _Tp& __x, const _Tp& __y) const {
      return __x || __y;
    }
  };

  template <typename _Tp>
  struct logical_not : public unary_function<_Tp, bool> {
    constexpr bool operator()(const _Tp& __x) const { return !__x; }
  };

  template <>
  struct logical_and<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp&& __t, _Up&& __u) const
        noexcept(noexcept(std::forward<_Tp>(__t) && std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) && std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) && std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <>
  struct logical_or<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp&& __t, _Up&& __u) const
        noexcept(noexcept(std::forward<_Tp>(__t) || std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) || std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) || std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <>
  struct logical_not<void> {
    template <typename _Tp>
    constexpr auto operator()(_Tp&& __t) const
        noexcept(noexcept(!std::forward<_Tp>(__t)))
            -> decltype(!std::forward<_Tp>(__t)) {
      return !std::forward<_Tp>(__t);
    }

    typedef __is_transparent is_transparent;
  };

  template <typename _Tp = void>
  struct bit_and;

  template <typename _Tp = void>
  struct bit_or;

  template <typename _Tp = void>
  struct bit_xor;

  template <typename _Tp = void>
  struct bit_not;

  template <typename _Tp>
  struct bit_and : public binary_function<_Tp, _Tp, _Tp> {
    constexpr _Tp operator()(const _Tp& __x, const _Tp& __y) const {
      return __x & __y;
    }
  };

  template <typename _Tp>
  struct bit_or : public binary_function<_Tp, _Tp, _Tp> {
    constexpr _Tp operator()(const _Tp& __x, const _Tp& __y) const {
      return __x | __y;
    }
  };

  template <typename _Tp>
  struct bit_xor : public binary_function<_Tp, _Tp, _Tp> {
    constexpr _Tp operator()(const _Tp& __x, const _Tp& __y) const {
      return __x ^ __y;
    }
  };

  template <typename _Tp>
  struct bit_not : public unary_function<_Tp, _Tp> {
    constexpr _Tp operator()(const _Tp& __x) const { return ~__x; }
  };

  template <>
  struct bit_and<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp&& __t, _Up&& __u) const
        noexcept(noexcept(std::forward<_Tp>(__t) & std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) & std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) & std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <>
  struct bit_or<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp&& __t, _Up&& __u) const
        noexcept(noexcept(std::forward<_Tp>(__t) | std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) | std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) | std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <>
  struct bit_xor<void> {
    template <typename _Tp, typename _Up>
    constexpr auto operator()(_Tp&& __t, _Up&& __u) const
        noexcept(noexcept(std::forward<_Tp>(__t) ^ std::forward<_Up>(__u)))
            -> decltype(std::forward<_Tp>(__t) ^ std::forward<_Up>(__u)) {
      return std::forward<_Tp>(__t) ^ std::forward<_Up>(__u);
    }

    typedef __is_transparent is_transparent;
  };

  template <>
  struct bit_not<void> {
    template <typename _Tp>
    constexpr auto operator()(_Tp&& __t) const
        noexcept(noexcept(~std::forward<_Tp>(__t)))
            -> decltype(~std::forward<_Tp>(__t)) {
      return ~std::forward<_Tp>(__t);
    }

    typedef __is_transparent is_transparent;
  };
  template <typename _Predicate>
  class unary_negate
      : public unary_function<typename _Predicate::argument_type, bool> {
   protected:
    _Predicate _M_pred;

   public:
    constexpr explicit unary_negate(const _Predicate& __x) : _M_pred(__x) {}

    constexpr bool operator()(
        const typename _Predicate::argument_type& __x) const {
      return !_M_pred(__x);
    }
  };

  template <typename _Predicate>
  constexpr inline unary_negate<_Predicate> not1(const _Predicate& __pred) {
    return unary_negate<_Predicate>(__pred);
  }

  template <typename _Predicate>
  class binary_negate
      : public binary_function<typename _Predicate::first_argument_type,
                               typename _Predicate::second_argument_type,
                               bool> {
   protected:
    _Predicate _M_pred;

   public:
    constexpr explicit binary_negate(const _Predicate& __x) : _M_pred(__x) {}

    constexpr bool operator()(
        const typename _Predicate::first_argument_type& __x,
        const typename _Predicate::second_argument_type& __y) const {
      return !_M_pred(__x, __y);
    }
  };

  template <typename _Predicate>
  constexpr inline binary_negate<_Predicate> not2(const _Predicate& __pred) {
    return binary_negate<_Predicate>(__pred);
  }
  template <typename _Arg, typename _Result>
  class pointer_to_unary_function : public unary_function<_Arg, _Result> {
   protected:
    _Result (*_M_ptr)(_Arg);

   public:
    pointer_to_unary_function() {}

    explicit pointer_to_unary_function(_Result (*__x)(_Arg)) : _M_ptr(__x) {}

    _Result operator()(_Arg __x) const { return _M_ptr(__x); }
  };

  template <typename _Arg, typename _Result>
  inline pointer_to_unary_function<_Arg, _Result> ptr_fun(_Result(*__x)(_Arg)) {
    return pointer_to_unary_function<_Arg, _Result>(__x);
  }

  template <typename _Arg1, typename _Arg2, typename _Result>
  class pointer_to_binary_function
      : public binary_function<_Arg1, _Arg2, _Result> {
   protected:
    _Result (*_M_ptr)(_Arg1, _Arg2);

   public:
    pointer_to_binary_function() {}

    explicit pointer_to_binary_function(_Result (*__x)(_Arg1, _Arg2))
        : _M_ptr(__x) {}

    _Result operator()(_Arg1 __x, _Arg2 __y) const { return _M_ptr(__x, __y); }
  };

  template <typename _Arg1, typename _Arg2, typename _Result>
  inline pointer_to_binary_function<_Arg1, _Arg2, _Result> ptr_fun(
      _Result(*__x)(_Arg1, _Arg2)) {
    return pointer_to_binary_function<_Arg1, _Arg2, _Result>(__x);
  }

  template <typename _Tp>
  struct _Identity : public unary_function<_Tp, _Tp> {
    _Tp& operator()(_Tp& __x) const { return __x; }

    const _Tp& operator()(const _Tp& __x) const { return __x; }
  };

  template <typename _Pair>
  struct _Select1st : public unary_function<_Pair, typename _Pair::first_type> {
    typename _Pair::first_type& operator()(_Pair& __x) const {
      return __x.first;
    }

    const typename _Pair::first_type& operator()(const _Pair& __x) const {
      return __x.first;
    }

    template <typename _Pair2>
    typename _Pair2::first_type& operator()(_Pair2& __x) const {
      return __x.first;
    }

    template <typename _Pair2>
    const typename _Pair2::first_type& operator()(const _Pair2& __x) const {
      return __x.first;
    }
  };

  template <typename _Pair>
  struct _Select2nd
      : public unary_function<_Pair, typename _Pair::second_type> {
    typename _Pair::second_type& operator()(_Pair& __x) const {
      return __x.second;
    }

    const typename _Pair::second_type& operator()(const _Pair& __x) const {
      return __x.second;
    }
  };
  template <typename _Ret, typename _Tp>
  class mem_fun_t : public unary_function<_Tp*, _Ret> {
   public:
    explicit mem_fun_t(_Ret (_Tp::*__pf)()) : _M_f(__pf) {}

    _Ret operator()(_Tp* __p) const { return (__p->*_M_f)(); }

   private:
    _Ret (_Tp::*_M_f)();
  };

  template <typename _Ret, typename _Tp>
  class const_mem_fun_t : public unary_function<const _Tp*, _Ret> {
   public:
    explicit const_mem_fun_t(_Ret (_Tp::*__pf)() const) : _M_f(__pf) {}

    _Ret operator()(const _Tp* __p) const { return (__p->*_M_f)(); }

   private:
    _Ret (_Tp::*_M_f)() const;
  };

  template <typename _Ret, typename _Tp>
  class mem_fun_ref_t : public unary_function<_Tp, _Ret> {
   public:
    explicit mem_fun_ref_t(_Ret (_Tp::*__pf)()) : _M_f(__pf) {}

    _Ret operator()(_Tp& __r) const { return (__r.*_M_f)(); }

   private:
    _Ret (_Tp::*_M_f)();
  };

  template <typename _Ret, typename _Tp>
  class const_mem_fun_ref_t : public unary_function<_Tp, _Ret> {
   public:
    explicit const_mem_fun_ref_t(_Ret (_Tp::*__pf)() const) : _M_f(__pf) {}

    _Ret operator()(const _Tp& __r) const { return (__r.*_M_f)(); }

   private:
    _Ret (_Tp::*_M_f)() const;
  };

  template <typename _Ret, typename _Tp, typename _Arg>
  class mem_fun1_t : public binary_function<_Tp*, _Arg, _Ret> {
   public:
    explicit mem_fun1_t(_Ret (_Tp::*__pf)(_Arg)) : _M_f(__pf) {}

    _Ret operator()(_Tp* __p, _Arg __x) const { return (__p->*_M_f)(__x); }

   private:
    _Ret (_Tp::*_M_f)(_Arg);
  };

  template <typename _Ret, typename _Tp, typename _Arg>
  class const_mem_fun1_t : public binary_function<const _Tp*, _Arg, _Ret> {
   public:
    explicit const_mem_fun1_t(_Ret (_Tp::*__pf)(_Arg) const) : _M_f(__pf) {}

    _Ret operator()(const _Tp* __p, _Arg __x) const {
      return (__p->*_M_f)(__x);
    }

   private:
    _Ret (_Tp::*_M_f)(_Arg) const;
  };

  template <typename _Ret, typename _Tp, typename _Arg>
  class mem_fun1_ref_t : public binary_function<_Tp, _Arg, _Ret> {
   public:
    explicit mem_fun1_ref_t(_Ret (_Tp::*__pf)(_Arg)) : _M_f(__pf) {}

    _Ret operator()(_Tp& __r, _Arg __x) const { return (__r.*_M_f)(__x); }

   private:
    _Ret (_Tp::*_M_f)(_Arg);
  };

  template <typename _Ret, typename _Tp, typename _Arg>
  class const_mem_fun1_ref_t : public binary_function<_Tp, _Arg, _Ret> {
   public:
    explicit const_mem_fun1_ref_t(_Ret (_Tp::*__pf)(_Arg) const) : _M_f(__pf) {}

    _Ret operator()(const _Tp& __r, _Arg __x) const { return (__r.*_M_f)(__x); }

   private:
    _Ret (_Tp::*_M_f)(_Arg) const;
  };

  template <typename _Ret, typename _Tp>
  inline mem_fun_t<_Ret, _Tp> mem_fun(_Ret(_Tp::*__f)()) {
    return mem_fun_t<_Ret, _Tp>(__f);
  }

  template <typename _Ret, typename _Tp>
  inline const_mem_fun_t<_Ret, _Tp> mem_fun(_Ret(_Tp::*__f)() const) {
    return const_mem_fun_t<_Ret, _Tp>(__f);
  }

  template <typename _Ret, typename _Tp>
  inline mem_fun_ref_t<_Ret, _Tp> mem_fun_ref(_Ret(_Tp::*__f)()) {
    return mem_fun_ref_t<_Ret, _Tp>(__f);
  }

  template <typename _Ret, typename _Tp>
  inline const_mem_fun_ref_t<_Ret, _Tp> mem_fun_ref(_Ret(_Tp::*__f)() const) {
    return const_mem_fun_ref_t<_Ret, _Tp>(__f);
  }

  template <typename _Ret, typename _Tp, typename _Arg>
  inline mem_fun1_t<_Ret, _Tp, _Arg> mem_fun(_Ret(_Tp::*__f)(_Arg)) {
    return mem_fun1_t<_Ret, _Tp, _Arg>(__f);
  }

  template <typename _Ret, typename _Tp, typename _Arg>
  inline const_mem_fun1_t<_Ret, _Tp, _Arg> mem_fun(_Ret(_Tp::*__f)(_Arg)
                                                       const) {
    return const_mem_fun1_t<_Ret, _Tp, _Arg>(__f);
  }

  template <typename _Ret, typename _Tp, typename _Arg>
  inline mem_fun1_ref_t<_Ret, _Tp, _Arg> mem_fun_ref(_Ret(_Tp::*__f)(_Arg)) {
    return mem_fun1_ref_t<_Ret, _Tp, _Arg>(__f);
  }

  template <typename _Ret, typename _Tp, typename _Arg>
  inline const_mem_fun1_ref_t<_Ret, _Tp, _Arg> mem_fun_ref(_Ret(_Tp::*__f)(_Arg)
                                                               const) {
    return const_mem_fun1_ref_t<_Ret, _Tp, _Arg>(__f);
  }

}  // namespace std__attribute__((__visibility__("default")))

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Operation>
  class binder1st
      : public unary_function<typename _Operation::second_argument_type,
                              typename _Operation::result_type> {
   protected:
    _Operation op;
    typename _Operation::first_argument_type value;

   public:
    binder1st(const _Operation& __x,
              const typename _Operation::first_argument_type& __y)
        : op(__x), value(__y) {}

    typename _Operation::result_type operator()(
        const typename _Operation::second_argument_type& __x) const {
      return op(value, __x);
    }

    typename _Operation::result_type operator()(
        typename _Operation::second_argument_type& __x) const {
      return op(value, __x);
    }
  } __attribute__((__deprecated__));

  template <typename _Operation, typename _Tp>
  inline binder1st<_Operation> bind1st(const _Operation& __fn, const _Tp& __x) {
    typedef typename _Operation::first_argument_type _Arg1_type;
    return binder1st<_Operation>(__fn, _Arg1_type(__x));
  }

  template <typename _Operation>
  class binder2nd
      : public unary_function<typename _Operation::first_argument_type,
                              typename _Operation::result_type> {
   protected:
    _Operation op;
    typename _Operation::second_argument_type value;

   public:
    binder2nd(const _Operation& __x,
              const typename _Operation::second_argument_type& __y)
        : op(__x), value(__y) {}

    typename _Operation::result_type operator()(
        const typename _Operation::first_argument_type& __x) const {
      return op(__x, value);
    }

    typename _Operation::result_type operator()(
        typename _Operation::first_argument_type& __x) const {
      return op(__x, value);
    }
  } __attribute__((__deprecated__));

  template <typename _Operation, typename _Tp>
  inline binder2nd<_Operation> bind2nd(const _Operation& __fn, const _Tp& __x) {
    typedef typename _Operation::second_argument_type _Arg2_type;
    return binder2nd<_Operation>(__fn, _Arg2_type(__x));
  }

}  // namespace std__attribute__((__visibility__("default")))

#pragma GCC diagnostic pop

#pragma GCC visibility push(default)

typedef __time_t time_t;

struct timespec {
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};

typedef __pid_t pid_t;

struct sched_param {
  int sched_priority;
};

extern "C" {

extern int clone(int (*__fn)(void* __arg),
                 void* __child_stack,
                 int __flags,
                 void* __arg,
                 ...) throw();

extern int unshare(int __flags) throw();

extern int sched_getcpu(void) throw();

extern int setns(int __fd, int __nstype) throw();
}
typedef unsigned long int __cpu_mask;

typedef struct {
  __cpu_mask __bits[1024 / (8 * sizeof(__cpu_mask))];
} cpu_set_t;
extern "C" {

extern int __sched_cpucount(size_t __setsize, const cpu_set_t* __setp) throw();
extern cpu_set_t* __sched_cpualloc(size_t __count) throw();
extern void __sched_cpufree(cpu_set_t* __set) throw();
}

extern "C" {

extern int sched_setparam(__pid_t __pid,
                          const struct sched_param* __param) throw();

extern int sched_getparam(__pid_t __pid, struct sched_param* __param) throw();

extern int sched_setscheduler(__pid_t __pid,
                              int __policy,
                              const struct sched_param* __param) throw();

extern int sched_getscheduler(__pid_t __pid) throw();

extern int sched_yield(void) throw();

extern int sched_get_priority_max(int __algorithm) throw();

extern int sched_get_priority_min(int __algorithm) throw();

extern int sched_rr_get_interval(__pid_t __pid, struct timespec* __t) throw();
extern int sched_setaffinity(__pid_t __pid,
                             size_t __cpusetsize,
                             const cpu_set_t* __cpuset) throw();

extern int sched_getaffinity(__pid_t __pid,
                             size_t __cpusetsize,
                             cpu_set_t* __cpuset) throw();
}

struct timeval {
  __time_t tv_sec;
  __suseconds_t tv_usec;
};

struct timex {
  unsigned int modes;
  __syscall_slong_t offset;
  __syscall_slong_t freq;
  __syscall_slong_t maxerror;
  __syscall_slong_t esterror;
  int status;
  __syscall_slong_t constant;
  __syscall_slong_t precision;
  __syscall_slong_t tolerance;
  struct timeval time;
  __syscall_slong_t tick;
  __syscall_slong_t ppsfreq;
  __syscall_slong_t jitter;
  int shift;
  __syscall_slong_t stabil;
  __syscall_slong_t jitcnt;
  __syscall_slong_t calcnt;
  __syscall_slong_t errcnt;
  __syscall_slong_t stbcnt;

  int tai;

  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
  int : 32;
};

extern "C" {

extern int clock_adjtime(__clockid_t __clock_id, struct timex* __utx) throw();
}

typedef __clock_t clock_t;

struct tm {
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;

  long int tm_gmtoff;
  const char* tm_zone;
};

typedef __clockid_t clockid_t;

typedef __timer_t timer_t;

struct itimerspec {
  struct timespec it_interval;
  struct timespec it_value;
};
struct sigevent;
extern "C" {

extern clock_t clock(void) throw();

extern time_t time(time_t* __timer) throw();

extern double difftime(time_t __time1, time_t __time0) throw()
    __attribute__((__const__));

extern time_t mktime(struct tm* __tp) throw();

extern size_t strftime(char* __restrict __s,
                       size_t __maxsize,
                       const char* __restrict __format,
                       const struct tm* __restrict __tp) throw();

extern char* strptime(const char* __restrict __s,
                      const char* __restrict __fmt,
                      struct tm* __tp) throw();

extern size_t strftime_l(char* __restrict __s,
                         size_t __maxsize,
                         const char* __restrict __format,
                         const struct tm* __restrict __tp,
                         locale_t __loc) throw();

extern char* strptime_l(const char* __restrict __s,
                        const char* __restrict __fmt,
                        struct tm* __tp,
                        locale_t __loc) throw();

extern struct tm* gmtime(const time_t* __timer) throw();

extern struct tm* localtime(const time_t* __timer) throw();

extern struct tm* gmtime_r(const time_t* __restrict __timer,
                           struct tm* __restrict __tp) throw();

extern struct tm* localtime_r(const time_t* __restrict __timer,
                              struct tm* __restrict __tp) throw();

extern char* asctime(const struct tm* __tp) throw();

extern char* ctime(const time_t* __timer) throw();

extern char* asctime_r(const struct tm* __restrict __tp,
                       char* __restrict __buf) throw();

extern char* ctime_r(const time_t* __restrict __timer,
                     char* __restrict __buf) throw();

extern char* __tzname[2];
extern int __daylight;
extern long int __timezone;

extern char* tzname[2];

extern void tzset(void) throw();

extern int daylight;
extern long int timezone;

extern int stime(const time_t* __when) throw();
extern time_t timegm(struct tm* __tp) throw();

extern time_t timelocal(struct tm* __tp) throw();

extern int dysize(int __year) throw() __attribute__((__const__));
extern int nanosleep(const struct timespec* __requested_time,
                     struct timespec* __remaining);

extern int clock_getres(clockid_t __clock_id, struct timespec* __res) throw();

extern int clock_gettime(clockid_t __clock_id, struct timespec* __tp) throw();

extern int clock_settime(clockid_t __clock_id,
                         const struct timespec* __tp) throw();

extern int clock_nanosleep(clockid_t __clock_id,
                           int __flags,
                           const struct timespec* __req,
                           struct timespec* __rem);

extern int clock_getcpuclockid(pid_t __pid, clockid_t* __clock_id) throw();

extern int timer_create(clockid_t __clock_id,
                        struct sigevent* __restrict __evp,
                        timer_t* __restrict __timerid) throw();

extern int timer_delete(timer_t __timerid) throw();

extern int timer_settime(timer_t __timerid,
                         int __flags,
                         const struct itimerspec* __restrict __value,
                         struct itimerspec* __restrict __ovalue) throw();

extern int timer_gettime(timer_t __timerid, struct itimerspec* __value) throw();

extern int timer_getoverrun(timer_t __timerid) throw();

extern int timespec_get(struct timespec* __ts, int __base) throw()
    __attribute__((__nonnull__(1)));
extern int getdate_err;
extern struct tm* getdate(const char* __string);
extern int getdate_r(const char* __restrict __string,
                     struct tm* __restrict __resbufp);
}

struct __pthread_rwlock_arch_t {
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;

  int __cur_writer;
  int __shared;
  signed char __rwelision;

  unsigned char __pad1[7];

  unsigned long int __pad2;

  unsigned int __flags;
};

typedef struct __pthread_internal_list {
  struct __pthread_internal_list* __prev;
  struct __pthread_internal_list* __next;
} __pthread_list_t;
struct __pthread_mutex_s {
  int __lock;
  unsigned int __count;
  int __owner;

  unsigned int __nusers;

  int __kind;

  short __spins;
  short __elision;
  __pthread_list_t __list;
};

struct __pthread_cond_s {
  __extension__ union {
    __extension__ unsigned long long int __wseq;
    struct {
      unsigned int __low;
      unsigned int __high;
    } __wseq32;
  };
  __extension__ union {
    __extension__ unsigned long long int __g1_start;
    struct {
      unsigned int __low;
      unsigned int __high;
    } __g1_start32;
  };
  unsigned int __g_refs[2];
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};

typedef unsigned long int pthread_t;

typedef union {
  char __size[4];
  int __align;
} pthread_mutexattr_t;

typedef union {
  char __size[4];
  int __align;
} pthread_condattr_t;

typedef unsigned int pthread_key_t;

typedef int pthread_once_t;

union pthread_attr_t {
  char __size[56];
  long int __align;
};

typedef union pthread_attr_t pthread_attr_t;

typedef union {
  struct __pthread_mutex_s __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;

typedef union {
  struct __pthread_cond_s __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;

typedef union {
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;

typedef union {
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;

typedef volatile int pthread_spinlock_t;

typedef union {
  char __size[32];
  long int __align;
} pthread_barrier_t;

typedef union {
  char __size[4];
  int __align;
} pthread_barrierattr_t;

typedef long int __jmp_buf[8];

enum {
  PTHREAD_CREATE_JOINABLE,

  PTHREAD_CREATE_DETACHED

};

enum {
  PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_ADAPTIVE_NP

  ,
  PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL

  ,
  PTHREAD_MUTEX_FAST_NP = PTHREAD_MUTEX_TIMED_NP

};

enum {
  PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_STALLED_NP = PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_ROBUST,
  PTHREAD_MUTEX_ROBUST_NP = PTHREAD_MUTEX_ROBUST
};

enum { PTHREAD_PRIO_NONE, PTHREAD_PRIO_INHERIT, PTHREAD_PRIO_PROTECT };
enum {
  PTHREAD_RWLOCK_PREFER_READER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP,
  PTHREAD_RWLOCK_DEFAULT_NP = PTHREAD_RWLOCK_PREFER_READER_NP
};
enum {
  PTHREAD_INHERIT_SCHED,

  PTHREAD_EXPLICIT_SCHED

};

enum {
  PTHREAD_SCOPE_SYSTEM,

  PTHREAD_SCOPE_PROCESS

};

enum {
  PTHREAD_PROCESS_PRIVATE,

  PTHREAD_PROCESS_SHARED

};
struct _pthread_cleanup_buffer {
  void (*__routine)(void*);
  void* __arg;
  int __canceltype;
  struct _pthread_cleanup_buffer* __prev;
};

enum {
  PTHREAD_CANCEL_ENABLE,

  PTHREAD_CANCEL_DISABLE

};
enum {
  PTHREAD_CANCEL_DEFERRED,

  PTHREAD_CANCEL_ASYNCHRONOUS

};
extern "C" {

extern int pthread_create(pthread_t* __restrict __newthread,
                          const pthread_attr_t* __restrict __attr,
                          void* (*__start_routine)(void*),
                          void* __restrict __arg) throw()
    __attribute__((__nonnull__(1, 3)));

extern void pthread_exit(void* __retval) __attribute__((__noreturn__));

extern int pthread_join(pthread_t __th, void** __thread_return);

extern int pthread_tryjoin_np(pthread_t __th, void** __thread_return) throw();

extern int pthread_timedjoin_np(pthread_t __th,
                                void** __thread_return,
                                const struct timespec* __abstime);

extern int pthread_detach(pthread_t __th) throw();

extern pthread_t pthread_self(void) throw() __attribute__((__const__));

extern int pthread_equal(pthread_t __thread1, pthread_t __thread2) throw()
    __attribute__((__const__));

extern int pthread_attr_init(pthread_attr_t* __attr) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_attr_destroy(pthread_attr_t* __attr) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_attr_getdetachstate(const pthread_attr_t* __attr,
                                       int* __detachstate) throw()
    __attribute__((__nonnull__(1, 2)));

extern int pthread_attr_setdetachstate(pthread_attr_t* __attr,
                                       int __detachstate) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_attr_getguardsize(const pthread_attr_t* __attr,
                                     size_t* __guardsize) throw()
    __attribute__((__nonnull__(1, 2)));

extern int pthread_attr_setguardsize(pthread_attr_t* __attr,
                                     size_t __guardsize) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_attr_getschedparam(
    const pthread_attr_t* __restrict __attr,
    struct sched_param* __restrict __param) throw()
    __attribute__((__nonnull__(1, 2)));

extern int pthread_attr_setschedparam(
    pthread_attr_t* __restrict __attr,
    const struct sched_param* __restrict __param) throw()
    __attribute__((__nonnull__(1, 2)));

extern int pthread_attr_getschedpolicy(const pthread_attr_t* __restrict __attr,
                                       int* __restrict __policy) throw()
    __attribute__((__nonnull__(1, 2)));

extern int pthread_attr_setschedpolicy(pthread_attr_t* __attr,
                                       int __policy) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_attr_getinheritsched(const pthread_attr_t* __restrict __attr,
                                        int* __restrict __inherit) throw()
    __attribute__((__nonnull__(1, 2)));

extern int pthread_attr_setinheritsched(pthread_attr_t* __attr,
                                        int __inherit) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_attr_getscope(const pthread_attr_t* __restrict __attr,
                                 int* __restrict __scope) throw()
    __attribute__((__nonnull__(1, 2)));

extern int pthread_attr_setscope(pthread_attr_t* __attr, int __scope) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_attr_getstackaddr(const pthread_attr_t* __restrict __attr,
                                     void** __restrict __stackaddr) throw()
    __attribute__((__nonnull__(1, 2))) __attribute__((__deprecated__));

extern int pthread_attr_setstackaddr(pthread_attr_t* __attr,
                                     void* __stackaddr) throw()
    __attribute__((__nonnull__(1))) __attribute__((__deprecated__));

extern int pthread_attr_getstacksize(const pthread_attr_t* __restrict __attr,
                                     size_t* __restrict __stacksize) throw()
    __attribute__((__nonnull__(1, 2)));

extern int pthread_attr_setstacksize(pthread_attr_t* __attr,
                                     size_t __stacksize) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_attr_getstack(const pthread_attr_t* __restrict __attr,
                                 void** __restrict __stackaddr,
                                 size_t* __restrict __stacksize) throw()
    __attribute__((__nonnull__(1, 2, 3)));

extern int pthread_attr_setstack(pthread_attr_t* __attr,
                                 void* __stackaddr,
                                 size_t __stacksize) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_attr_setaffinity_np(pthread_attr_t* __attr,
                                       size_t __cpusetsize,
                                       const cpu_set_t* __cpuset) throw()
    __attribute__((__nonnull__(1, 3)));

extern int pthread_attr_getaffinity_np(const pthread_attr_t* __attr,
                                       size_t __cpusetsize,
                                       cpu_set_t* __cpuset) throw()
    __attribute__((__nonnull__(1, 3)));

extern int pthread_getattr_default_np(pthread_attr_t* __attr) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_setattr_default_np(const pthread_attr_t* __attr) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_getattr_np(pthread_t __th, pthread_attr_t* __attr) throw()
    __attribute__((__nonnull__(2)));

extern int pthread_setschedparam(pthread_t __target_thread,
                                 int __policy,
                                 const struct sched_param* __param) throw()
    __attribute__((__nonnull__(3)));

extern int pthread_getschedparam(pthread_t __target_thread,
                                 int* __restrict __policy,
                                 struct sched_param* __restrict __param) throw()
    __attribute__((__nonnull__(2, 3)));

extern int pthread_setschedprio(pthread_t __target_thread, int __prio) throw();

extern int pthread_getname_np(pthread_t __target_thread,
                              char* __buf,
                              size_t __buflen) throw()
    __attribute__((__nonnull__(2)));

extern int pthread_setname_np(pthread_t __target_thread,
                              const char* __name) throw()
    __attribute__((__nonnull__(2)));

extern int pthread_getconcurrency(void) throw();

extern int pthread_setconcurrency(int __level) throw();

extern int pthread_yield(void) throw();

extern int pthread_setaffinity_np(pthread_t __th,
                                  size_t __cpusetsize,
                                  const cpu_set_t* __cpuset) throw()
    __attribute__((__nonnull__(3)));

extern int pthread_getaffinity_np(pthread_t __th,
                                  size_t __cpusetsize,
                                  cpu_set_t* __cpuset) throw()
    __attribute__((__nonnull__(3)));
extern int pthread_once(pthread_once_t* __once_control,
                        void (*__init_routine)(void))
    __attribute__((__nonnull__(1, 2)));
extern int pthread_setcancelstate(int __state, int* __oldstate);

extern int pthread_setcanceltype(int __type, int* __oldtype);

extern int pthread_cancel(pthread_t __th);

extern void pthread_testcancel(void);

typedef struct {
  struct {
    __jmp_buf __cancel_jmp_buf;
    int __mask_was_saved;
  } __cancel_jmp_buf[1];
  void* __pad[4];
} __pthread_unwind_buf_t __attribute__((__aligned__));
struct __pthread_cleanup_frame {
  void (*__cancel_routine)(void*);
  void* __cancel_arg;
  int __do_it;
  int __cancel_type;
};

class __pthread_cleanup_class {
  void (*__cancel_routine)(void*);
  void* __cancel_arg;
  int __do_it;
  int __cancel_type;

 public:
  __pthread_cleanup_class(void (*__fct)(void*), void* __arg)
      : __cancel_routine(__fct), __cancel_arg(__arg), __do_it(1) {}
  ~__pthread_cleanup_class() {
    if (__do_it)
      __cancel_routine(__cancel_arg);
  }
  void __setdoit(int __newval) { __do_it = __newval; }
  void __defer() {
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, &__cancel_type);
  }
  void __restore() const { pthread_setcanceltype(__cancel_type, 0); }
};
struct __jmp_buf_tag;
extern int __sigsetjmp(struct __jmp_buf_tag* __env, int __savemask) throw();

extern int pthread_mutex_init(pthread_mutex_t* __mutex,
                              const pthread_mutexattr_t* __mutexattr) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_mutex_destroy(pthread_mutex_t* __mutex) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_mutex_trylock(pthread_mutex_t* __mutex) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_mutex_lock(pthread_mutex_t* __mutex) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_mutex_timedlock(
    pthread_mutex_t* __restrict __mutex,
    const struct timespec* __restrict __abstime) throw()
    __attribute__((__nonnull__(1, 2)));

extern int pthread_mutex_unlock(pthread_mutex_t* __mutex) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_mutex_getprioceiling(
    const pthread_mutex_t* __restrict __mutex,
    int* __restrict __prioceiling) throw() __attribute__((__nonnull__(1, 2)));

extern int pthread_mutex_setprioceiling(pthread_mutex_t* __restrict __mutex,
                                        int __prioceiling,
                                        int* __restrict __old_ceiling) throw()
    __attribute__((__nonnull__(1, 3)));

extern int pthread_mutex_consistent(pthread_mutex_t* __mutex) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_mutex_consistent_np(pthread_mutex_t* __mutex) throw()
    __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_init(pthread_mutexattr_t* __attr) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_mutexattr_destroy(pthread_mutexattr_t* __attr) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_mutexattr_getpshared(
    const pthread_mutexattr_t* __restrict __attr,
    int* __restrict __pshared) throw() __attribute__((__nonnull__(1, 2)));

extern int pthread_mutexattr_setpshared(pthread_mutexattr_t* __attr,
                                        int __pshared) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_mutexattr_gettype(
    const pthread_mutexattr_t* __restrict __attr,
    int* __restrict __kind) throw() __attribute__((__nonnull__(1, 2)));

extern int pthread_mutexattr_settype(pthread_mutexattr_t* __attr,
                                     int __kind) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_mutexattr_getprotocol(
    const pthread_mutexattr_t* __restrict __attr,
    int* __restrict __protocol) throw() __attribute__((__nonnull__(1, 2)));

extern int pthread_mutexattr_setprotocol(pthread_mutexattr_t* __attr,
                                         int __protocol) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_mutexattr_getprioceiling(
    const pthread_mutexattr_t* __restrict __attr,
    int* __restrict __prioceiling) throw() __attribute__((__nonnull__(1, 2)));

extern int pthread_mutexattr_setprioceiling(pthread_mutexattr_t* __attr,
                                            int __prioceiling) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_mutexattr_getrobust(const pthread_mutexattr_t* __attr,
                                       int* __robustness) throw()
    __attribute__((__nonnull__(1, 2)));

extern int pthread_mutexattr_getrobust_np(const pthread_mutexattr_t* __attr,
                                          int* __robustness) throw()
    __attribute__((__nonnull__(1, 2)));

extern int pthread_mutexattr_setrobust(pthread_mutexattr_t* __attr,
                                       int __robustness) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_mutexattr_setrobust_np(pthread_mutexattr_t* __attr,
                                          int __robustness) throw()
    __attribute__((__nonnull__(1)));
extern int pthread_rwlock_init(
    pthread_rwlock_t* __restrict __rwlock,
    const pthread_rwlockattr_t* __restrict __attr) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_rwlock_destroy(pthread_rwlock_t* __rwlock) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_rwlock_rdlock(pthread_rwlock_t* __rwlock) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_rwlock_tryrdlock(pthread_rwlock_t* __rwlock) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_rwlock_timedrdlock(
    pthread_rwlock_t* __restrict __rwlock,
    const struct timespec* __restrict __abstime) throw()
    __attribute__((__nonnull__(1, 2)));

extern int pthread_rwlock_wrlock(pthread_rwlock_t* __rwlock) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_rwlock_trywrlock(pthread_rwlock_t* __rwlock) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_rwlock_timedwrlock(
    pthread_rwlock_t* __restrict __rwlock,
    const struct timespec* __restrict __abstime) throw()
    __attribute__((__nonnull__(1, 2)));

extern int pthread_rwlock_unlock(pthread_rwlock_t* __rwlock) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_rwlockattr_init(pthread_rwlockattr_t* __attr) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_rwlockattr_destroy(pthread_rwlockattr_t* __attr) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_rwlockattr_getpshared(
    const pthread_rwlockattr_t* __restrict __attr,
    int* __restrict __pshared) throw() __attribute__((__nonnull__(1, 2)));

extern int pthread_rwlockattr_setpshared(pthread_rwlockattr_t* __attr,
                                         int __pshared) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_rwlockattr_getkind_np(
    const pthread_rwlockattr_t* __restrict __attr,
    int* __restrict __pref) throw() __attribute__((__nonnull__(1, 2)));

extern int pthread_rwlockattr_setkind_np(pthread_rwlockattr_t* __attr,
                                         int __pref) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_cond_init(
    pthread_cond_t* __restrict __cond,
    const pthread_condattr_t* __restrict __cond_attr) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_cond_destroy(pthread_cond_t* __cond) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_cond_signal(pthread_cond_t* __cond) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_cond_broadcast(pthread_cond_t* __cond) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_cond_wait(pthread_cond_t* __restrict __cond,
                             pthread_mutex_t* __restrict __mutex)
    __attribute__((__nonnull__(1, 2)));
extern int pthread_cond_timedwait(pthread_cond_t* __restrict __cond,
                                  pthread_mutex_t* __restrict __mutex,
                                  const struct timespec* __restrict __abstime)
    __attribute__((__nonnull__(1, 2, 3)));

extern int pthread_condattr_init(pthread_condattr_t* __attr) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_condattr_destroy(pthread_condattr_t* __attr) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_condattr_getpshared(
    const pthread_condattr_t* __restrict __attr,
    int* __restrict __pshared) throw() __attribute__((__nonnull__(1, 2)));

extern int pthread_condattr_setpshared(pthread_condattr_t* __attr,
                                       int __pshared) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_condattr_getclock(
    const pthread_condattr_t* __restrict __attr,
    __clockid_t* __restrict __clock_id) throw()
    __attribute__((__nonnull__(1, 2)));

extern int pthread_condattr_setclock(pthread_condattr_t* __attr,
                                     __clockid_t __clock_id) throw()
    __attribute__((__nonnull__(1)));
extern int pthread_spin_init(pthread_spinlock_t* __lock, int __pshared) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_spin_destroy(pthread_spinlock_t* __lock) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_spin_lock(pthread_spinlock_t* __lock) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_spin_trylock(pthread_spinlock_t* __lock) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_spin_unlock(pthread_spinlock_t* __lock) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_barrier_init(pthread_barrier_t* __restrict __barrier,
                                const pthread_barrierattr_t* __restrict __attr,
                                unsigned int __count) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_barrier_destroy(pthread_barrier_t* __barrier) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_barrier_wait(pthread_barrier_t* __barrier) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_barrierattr_init(pthread_barrierattr_t* __attr) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_barrierattr_destroy(pthread_barrierattr_t* __attr) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_barrierattr_getpshared(
    const pthread_barrierattr_t* __restrict __attr,
    int* __restrict __pshared) throw() __attribute__((__nonnull__(1, 2)));

extern int pthread_barrierattr_setpshared(pthread_barrierattr_t* __attr,
                                          int __pshared) throw()
    __attribute__((__nonnull__(1)));
extern int pthread_key_create(pthread_key_t* __key,
                              void (*__destr_function)(void*)) throw()
    __attribute__((__nonnull__(1)));

extern int pthread_key_delete(pthread_key_t __key) throw();

extern void* pthread_getspecific(pthread_key_t __key) throw();

extern int pthread_setspecific(pthread_key_t __key,
                               const void* __pointer) throw();

extern int pthread_getcpuclockid(pthread_t __thread_id,
                                 __clockid_t* __clock_id) throw()
    __attribute__((__nonnull__(2)));
extern int pthread_atfork(void (*__prepare)(void),
                          void (*__parent)(void),
                          void (*__child)(void)) throw();
}
typedef pthread_t __gthread_t;
typedef pthread_key_t __gthread_key_t;
typedef pthread_once_t __gthread_once_t;
typedef pthread_mutex_t __gthread_mutex_t;
typedef pthread_mutex_t __gthread_recursive_mutex_t;
typedef pthread_cond_t __gthread_cond_t;
typedef struct timespec __gthread_time_t;
static __typeof(pthread_once) __gthrw_pthread_once
    __attribute__((__weakref__("pthread_once")));
static __typeof(pthread_getspecific) __gthrw_pthread_getspecific
    __attribute__((__weakref__("pthread_getspecific")));
static __typeof(pthread_setspecific) __gthrw_pthread_setspecific
    __attribute__((__weakref__("pthread_setspecific")));

static __typeof(pthread_create) __gthrw_pthread_create
    __attribute__((__weakref__("pthread_create")));
static __typeof(pthread_join) __gthrw_pthread_join
    __attribute__((__weakref__("pthread_join")));
static __typeof(pthread_equal) __gthrw_pthread_equal
    __attribute__((__weakref__("pthread_equal")));
static __typeof(pthread_self) __gthrw_pthread_self
    __attribute__((__weakref__("pthread_self")));
static __typeof(pthread_detach) __gthrw_pthread_detach
    __attribute__((__weakref__("pthread_detach")));

static __typeof(pthread_cancel) __gthrw_pthread_cancel
    __attribute__((__weakref__("pthread_cancel")));

static __typeof(sched_yield) __gthrw_sched_yield
    __attribute__((__weakref__("sched_yield")));

static __typeof(pthread_mutex_lock) __gthrw_pthread_mutex_lock
    __attribute__((__weakref__("pthread_mutex_lock")));
static __typeof(pthread_mutex_trylock) __gthrw_pthread_mutex_trylock
    __attribute__((__weakref__("pthread_mutex_trylock")));

static __typeof(pthread_mutex_timedlock) __gthrw_pthread_mutex_timedlock
    __attribute__((__weakref__("pthread_mutex_timedlock")));

static __typeof(pthread_mutex_unlock) __gthrw_pthread_mutex_unlock
    __attribute__((__weakref__("pthread_mutex_unlock")));
static __typeof(pthread_mutex_init) __gthrw_pthread_mutex_init
    __attribute__((__weakref__("pthread_mutex_init")));
static __typeof(pthread_mutex_destroy) __gthrw_pthread_mutex_destroy
    __attribute__((__weakref__("pthread_mutex_destroy")));

static __typeof(pthread_cond_init) __gthrw_pthread_cond_init
    __attribute__((__weakref__("pthread_cond_init")));
static __typeof(pthread_cond_broadcast) __gthrw_pthread_cond_broadcast
    __attribute__((__weakref__("pthread_cond_broadcast")));
static __typeof(pthread_cond_signal) __gthrw_pthread_cond_signal
    __attribute__((__weakref__("pthread_cond_signal")));
static __typeof(pthread_cond_wait) __gthrw_pthread_cond_wait
    __attribute__((__weakref__("pthread_cond_wait")));
static __typeof(pthread_cond_timedwait) __gthrw_pthread_cond_timedwait
    __attribute__((__weakref__("pthread_cond_timedwait")));
static __typeof(pthread_cond_destroy) __gthrw_pthread_cond_destroy
    __attribute__((__weakref__("pthread_cond_destroy")));

static __typeof(pthread_key_create) __gthrw_pthread_key_create
    __attribute__((__weakref__("pthread_key_create")));
static __typeof(pthread_key_delete) __gthrw_pthread_key_delete
    __attribute__((__weakref__("pthread_key_delete")));
static __typeof(pthread_mutexattr_init) __gthrw_pthread_mutexattr_init
    __attribute__((__weakref__("pthread_mutexattr_init")));
static __typeof(pthread_mutexattr_settype) __gthrw_pthread_mutexattr_settype
    __attribute__((__weakref__("pthread_mutexattr_settype")));
static __typeof(pthread_mutexattr_destroy) __gthrw_pthread_mutexattr_destroy
    __attribute__((__weakref__("pthread_mutexattr_destroy")));
static __typeof(pthread_key_create) __gthrw___pthread_key_create
    __attribute__((__weakref__("__pthread_key_create")));
static inline int __gthread_active_p(void) {
  static void* const __gthread_active_ptr =
      __extension__(void*) & __gthrw___pthread_key_create;
  return __gthread_active_ptr != 0;
}
static inline int __gthread_create(__gthread_t* __threadid,
                                   void* (*__func)(void*),
                                   void* __args) {
  return __gthrw_pthread_create(__threadid, __null, __func, __args);
}

static inline int __gthread_join(__gthread_t __threadid, void** __value_ptr) {
  return __gthrw_pthread_join(__threadid, __value_ptr);
}

static inline int __gthread_detach(__gthread_t __threadid) {
  return __gthrw_pthread_detach(__threadid);
}

static inline int __gthread_equal(__gthread_t __t1, __gthread_t __t2) {
  return __gthrw_pthread_equal(__t1, __t2);
}

static inline __gthread_t __gthread_self(void) {
  return __gthrw_pthread_self();
}

static inline int __gthread_yield(void) {
  return __gthrw_sched_yield();
}

static inline int __gthread_once(__gthread_once_t* __once,
                                 void (*__func)(void)) {
  if (__gthread_active_p())
    return __gthrw_pthread_once(__once, __func);
  else
    return -1;
}

static inline int __gthread_key_create(__gthread_key_t* __key,
                                       void (*__dtor)(void*)) {
  return __gthrw_pthread_key_create(__key, __dtor);
}

static inline int __gthread_key_delete(__gthread_key_t __key) {
  return __gthrw_pthread_key_delete(__key);
}

static inline void* __gthread_getspecific(__gthread_key_t __key) {
  return __gthrw_pthread_getspecific(__key);
}

static inline int __gthread_setspecific(__gthread_key_t __key,
                                        const void* __ptr) {
  return __gthrw_pthread_setspecific(__key, __ptr);
}

static inline void __gthread_mutex_init_function(__gthread_mutex_t* __mutex) {
  if (__gthread_active_p())
    __gthrw_pthread_mutex_init(__mutex, __null);
}

static inline int __gthread_mutex_destroy(__gthread_mutex_t* __mutex) {
  if (__gthread_active_p())
    return __gthrw_pthread_mutex_destroy(__mutex);
  else
    return 0;
}

static inline int __gthread_mutex_lock(__gthread_mutex_t* __mutex) {
  if (__gthread_active_p())
    return __gthrw_pthread_mutex_lock(__mutex);
  else
    return 0;
}

static inline int __gthread_mutex_trylock(__gthread_mutex_t* __mutex) {
  if (__gthread_active_p())
    return __gthrw_pthread_mutex_trylock(__mutex);
  else
    return 0;
}

static inline int __gthread_mutex_timedlock(
    __gthread_mutex_t* __mutex,
    const __gthread_time_t* __abs_timeout) {
  if (__gthread_active_p())
    return __gthrw_pthread_mutex_timedlock(__mutex, __abs_timeout);
  else
    return 0;
}

static inline int __gthread_mutex_unlock(__gthread_mutex_t* __mutex) {
  if (__gthread_active_p())
    return __gthrw_pthread_mutex_unlock(__mutex);
  else
    return 0;
}
static inline int __gthread_recursive_mutex_lock(
    __gthread_recursive_mutex_t* __mutex) {
  return __gthread_mutex_lock(__mutex);
}

static inline int __gthread_recursive_mutex_trylock(
    __gthread_recursive_mutex_t* __mutex) {
  return __gthread_mutex_trylock(__mutex);
}

static inline int __gthread_recursive_mutex_timedlock(
    __gthread_recursive_mutex_t* __mutex,
    const __gthread_time_t* __abs_timeout) {
  return __gthread_mutex_timedlock(__mutex, __abs_timeout);
}

static inline int __gthread_recursive_mutex_unlock(
    __gthread_recursive_mutex_t* __mutex) {
  return __gthread_mutex_unlock(__mutex);
}

static inline int __gthread_recursive_mutex_destroy(
    __gthread_recursive_mutex_t* __mutex) {
  return __gthread_mutex_destroy(__mutex);
}
static inline int __gthread_cond_broadcast(__gthread_cond_t* __cond) {
  return __gthrw_pthread_cond_broadcast(__cond);
}

static inline int __gthread_cond_signal(__gthread_cond_t* __cond) {
  return __gthrw_pthread_cond_signal(__cond);
}

static inline int __gthread_cond_wait(__gthread_cond_t* __cond,
                                      __gthread_mutex_t* __mutex) {
  return __gthrw_pthread_cond_wait(__cond, __mutex);
}

static inline int __gthread_cond_timedwait(
    __gthread_cond_t* __cond,
    __gthread_mutex_t* __mutex,
    const __gthread_time_t* __abs_timeout) {
  return __gthrw_pthread_cond_timedwait(__cond, __mutex, __abs_timeout);
}

static inline int __gthread_cond_wait_recursive(
    __gthread_cond_t* __cond,
    __gthread_recursive_mutex_t* __mutex) {
  return __gthread_cond_wait(__cond, __mutex);
}

static inline int __gthread_cond_destroy(__gthread_cond_t* __cond) {
  return __gthrw_pthread_cond_destroy(__cond);
}

#pragma GCC visibility pop
typedef int _Atomic_word;

namespace __gnu_cxx __attribute__((__visibility__("default"))) {

  static inline _Atomic_word __exchange_and_add(volatile _Atomic_word * __mem,
                                                int __val) {
    return __atomic_fetch_add(__mem, __val, 4);
  }

  static inline void __atomic_add(volatile _Atomic_word * __mem, int __val) {
    __atomic_fetch_add(__mem, __val, 4);
  }
  static inline _Atomic_word __exchange_and_add_single(_Atomic_word * __mem,
                                                       int __val) {
    _Atomic_word __result = *__mem;
    *__mem += __val;
    return __result;
  }

  static inline void __atomic_add_single(_Atomic_word * __mem, int __val) {
    *__mem += __val;
  }

  static inline _Atomic_word __attribute__((__unused__))
  __exchange_and_add_dispatch(_Atomic_word * __mem, int __val) {
    if (__gthread_active_p())
      return __exchange_and_add(__mem, __val);
    else
      return __exchange_and_add_single(__mem, __val);
  }

  static inline void __attribute__((__unused__))
  __atomic_add_dispatch(_Atomic_word * __mem, int __val) {
    if (__gthread_active_p())
      __atomic_add(__mem, __val);
    else
      __atomic_add_single(__mem, __val);
  }

}  // namespace __gnu_cxx__attribute__((__visibility__("default")))
namespace std __attribute__((__visibility__("default"))) {

  namespace __cxx11 {
  template <typename _CharT, typename _Traits, typename _Alloc>
  class basic_string {
    typedef typename __gnu_cxx::__alloc_traits<_Alloc>::template rebind<
        _CharT>::other _Char_alloc_type;
    typedef __gnu_cxx::__alloc_traits<_Char_alloc_type> _Alloc_traits;

   public:
    typedef _Traits traits_type;
    typedef typename _Traits::char_type value_type;
    typedef _Char_alloc_type allocator_type;
    typedef typename _Alloc_traits::size_type size_type;
    typedef typename _Alloc_traits::difference_type difference_type;
    typedef typename _Alloc_traits::reference reference;
    typedef typename _Alloc_traits::const_reference const_reference;
    typedef typename _Alloc_traits::pointer pointer;
    typedef typename _Alloc_traits::const_pointer const_pointer;
    typedef __gnu_cxx::__normal_iterator<pointer, basic_string> iterator;
    typedef __gnu_cxx::__normal_iterator<const_pointer, basic_string>
        const_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;

    static const size_type npos = static_cast<size_type>(-1);

   private:
    typedef const_iterator __const_iterator;
    struct _Alloc_hider : allocator_type {
      _Alloc_hider(pointer __dat, const _Alloc& __a)
          : allocator_type(__a), _M_p(__dat) {}

      _Alloc_hider(pointer __dat, _Alloc&& __a = _Alloc())
          : allocator_type(std::move(__a)), _M_p(__dat) {}

      pointer _M_p;
    };

    _Alloc_hider _M_dataplus;
    size_type _M_string_length;

    enum { _S_local_capacity = 15 / sizeof(_CharT) };

    union {
      _CharT _M_local_buf[_S_local_capacity + 1];
      size_type _M_allocated_capacity;
    };

    void _M_data(pointer __p) { _M_dataplus._M_p = __p; }

    void _M_length(size_type __length) { _M_string_length = __length; }

    pointer _M_data() const { return _M_dataplus._M_p; }

    pointer _M_local_data() {
      return std::pointer_traits<pointer>::pointer_to(*_M_local_buf);
    }

    const_pointer _M_local_data() const {
      return std::pointer_traits<const_pointer>::pointer_to(*_M_local_buf);
    }

    void _M_capacity(size_type __capacity) {
      _M_allocated_capacity = __capacity;
    }

    void _M_set_length(size_type __n) {
      _M_length(__n);
      traits_type::assign(_M_data()[__n], _CharT());
    }

    bool _M_is_local() const { return _M_data() == _M_local_data(); }

    pointer _M_create(size_type&, size_type);

    void _M_dispose() {
      if (!_M_is_local())
        _M_destroy(_M_allocated_capacity);
    }

    void _M_destroy(size_type __size) throw() {
      _Alloc_traits::deallocate(_M_get_allocator(), _M_data(), __size + 1);
    }

    template <typename _InIterator>
    void _M_construct_aux(_InIterator __beg,
                          _InIterator __end,
                          std::__false_type) {
      typedef typename iterator_traits<_InIterator>::iterator_category _Tag;
      _M_construct(__beg, __end, _Tag());
    }

    template <typename _Integer>
    void _M_construct_aux(_Integer __beg, _Integer __end, std::__true_type) {
      _M_construct_aux_2(static_cast<size_type>(__beg), __end);
    }

    void _M_construct_aux_2(size_type __req, _CharT __c) {
      _M_construct(__req, __c);
    }

    template <typename _InIterator>
    void _M_construct(_InIterator __beg, _InIterator __end) {
      typedef typename std::__is_integer<_InIterator>::__type _Integral;
      _M_construct_aux(__beg, __end, _Integral());
    }

    template <typename _InIterator>
    void _M_construct(_InIterator __beg,
                      _InIterator __end,
                      std::input_iterator_tag);

    template <typename _FwdIterator>
    void _M_construct(_FwdIterator __beg,
                      _FwdIterator __end,
                      std::forward_iterator_tag);

    void _M_construct(size_type __req, _CharT __c);

    allocator_type& _M_get_allocator() { return _M_dataplus; }

    const allocator_type& _M_get_allocator() const { return _M_dataplus; }

   private:
    size_type _M_check(size_type __pos, const char* __s) const {
      if (__pos > this->size())
        __throw_out_of_range_fmt(("%s: __pos (which is %zu) > "
                                  "this->size() (which is %zu)"),
                                 __s, __pos, this->size());
      return __pos;
    }

    void _M_check_length(size_type __n1,
                         size_type __n2,
                         const char* __s) const {
      if (this->max_size() - (this->size() - __n1) < __n2)
        __throw_length_error((__s));
    }

    size_type _M_limit(size_type __pos, size_type __off) const noexcept {
      const bool __testoff = __off < this->size() - __pos;
      return __testoff ? __off : this->size() - __pos;
    }

    bool _M_disjunct(const _CharT* __s) const noexcept {
      return (less<const _CharT*>()(__s, _M_data()) ||
              less<const _CharT*>()(_M_data() + this->size(), __s));
    }

    static void _S_copy(_CharT* __d, const _CharT* __s, size_type __n) {
      if (__n == 1)
        traits_type::assign(*__d, *__s);
      else
        traits_type::copy(__d, __s, __n);
    }

    static void _S_move(_CharT* __d, const _CharT* __s, size_type __n) {
      if (__n == 1)
        traits_type::assign(*__d, *__s);
      else
        traits_type::move(__d, __s, __n);
    }

    static void _S_assign(_CharT* __d, size_type __n, _CharT __c) {
      if (__n == 1)
        traits_type::assign(*__d, __c);
      else
        traits_type::assign(__d, __n, __c);
    }

    template <class _Iterator>
    static void _S_copy_chars(_CharT* __p, _Iterator __k1, _Iterator __k2) {
      for (; __k1 != __k2; ++__k1, (void)++__p)
        traits_type::assign(*__p, *__k1);
    }

    static void _S_copy_chars(_CharT* __p,
                              iterator __k1,
                              iterator __k2) noexcept {
      _S_copy_chars(__p, __k1.base(), __k2.base());
    }

    static void _S_copy_chars(_CharT* __p,
                              const_iterator __k1,
                              const_iterator __k2) noexcept {
      _S_copy_chars(__p, __k1.base(), __k2.base());
    }

    static void _S_copy_chars(_CharT* __p,
                              _CharT* __k1,
                              _CharT* __k2) noexcept {
      _S_copy(__p, __k1, __k2 - __k1);
    }

    static void _S_copy_chars(_CharT* __p,
                              const _CharT* __k1,
                              const _CharT* __k2) noexcept {
      _S_copy(__p, __k1, __k2 - __k1);
    }

    static int _S_compare(size_type __n1, size_type __n2) noexcept {
      const difference_type __d = difference_type(__n1 - __n2);

      if (__d > __gnu_cxx::__numeric_traits<int>::__max)
        return __gnu_cxx::__numeric_traits<int>::__max;
      else if (__d < __gnu_cxx::__numeric_traits<int>::__min)
        return __gnu_cxx::__numeric_traits<int>::__min;
      else
        return int(__d);
    }

    void _M_assign(const basic_string&);

    void _M_mutate(size_type __pos,
                   size_type __len1,
                   const _CharT* __s,
                   size_type __len2);

    void _M_erase(size_type __pos, size_type __n);

   public:
    basic_string() noexcept(is_nothrow_default_constructible<_Alloc>::value)
        : _M_dataplus(_M_local_data()) {
      _M_set_length(0);
    }

    explicit basic_string(const _Alloc& __a) noexcept
        : _M_dataplus(_M_local_data(), __a) {
      _M_set_length(0);
    }

    basic_string(const basic_string& __str)
        : _M_dataplus(
              _M_local_data(),
              _Alloc_traits::_S_select_on_copy(__str._M_get_allocator())) {
      _M_construct(__str._M_data(), __str._M_data() + __str.length());
    }
    basic_string(const basic_string& __str,
                 size_type __pos,
                 const _Alloc& __a = _Alloc())
        : _M_dataplus(_M_local_data(), __a) {
      const _CharT* __start =
          __str._M_data() + __str._M_check(__pos, "basic_string::basic_string");
      _M_construct(__start, __start + __str._M_limit(__pos, npos));
    }

    basic_string(const basic_string& __str, size_type __pos, size_type __n)
        : _M_dataplus(_M_local_data()) {
      const _CharT* __start =
          __str._M_data() + __str._M_check(__pos, "basic_string::basic_string");
      _M_construct(__start, __start + __str._M_limit(__pos, __n));
    }
    basic_string(const basic_string& __str,
                 size_type __pos,
                 size_type __n,
                 const _Alloc& __a)
        : _M_dataplus(_M_local_data(), __a) {
      const _CharT* __start =
          __str._M_data() + __str._M_check(__pos, "string::string");
      _M_construct(__start, __start + __str._M_limit(__pos, __n));
    }
    basic_string(const _CharT* __s, size_type __n, const _Alloc& __a = _Alloc())
        : _M_dataplus(_M_local_data(), __a) {
      _M_construct(__s, __s + __n);
    }

    basic_string(const _CharT* __s, const _Alloc& __a = _Alloc())
        : _M_dataplus(_M_local_data(), __a) {
      _M_construct(__s, __s ? __s + traits_type::length(__s) : __s + npos);
    }

    basic_string(size_type __n, _CharT __c, const _Alloc& __a = _Alloc())
        : _M_dataplus(_M_local_data(), __a) {
      _M_construct(__n, __c);
    }
    basic_string(basic_string&& __str) noexcept
        : _M_dataplus(_M_local_data(), std::move(__str._M_get_allocator())) {
      if (__str._M_is_local()) {
        traits_type::copy(_M_local_buf, __str._M_local_buf,
                          _S_local_capacity + 1);
      } else {
        _M_data(__str._M_data());
        _M_capacity(__str._M_allocated_capacity);
      }

      _M_length(__str.length());
      __str._M_data(__str._M_local_data());
      __str._M_set_length(0);
    }

    basic_string(initializer_list<_CharT> __l, const _Alloc& __a = _Alloc())
        : _M_dataplus(_M_local_data(), __a) {
      _M_construct(__l.begin(), __l.end());
    }

    basic_string(const basic_string& __str, const _Alloc& __a)
        : _M_dataplus(_M_local_data(), __a) {
      _M_construct(__str.begin(), __str.end());
    }

    basic_string(basic_string&& __str,
                 const _Alloc& __a) noexcept(_Alloc_traits::_S_always_equal())
        : _M_dataplus(_M_local_data(), __a) {
      if (__str._M_is_local()) {
        traits_type::copy(_M_local_buf, __str._M_local_buf,
                          _S_local_capacity + 1);
        _M_length(__str.length());
        __str._M_set_length(0);
      } else if (_Alloc_traits::_S_always_equal() ||
                 __str.get_allocator() == __a) {
        _M_data(__str._M_data());
        _M_length(__str.length());
        _M_capacity(__str._M_allocated_capacity);
        __str._M_data(__str._M_local_buf);
        __str._M_set_length(0);
      } else
        _M_construct(__str.begin(), __str.end());
    }
    template <typename _InputIterator,
              typename = std::_RequireInputIter<_InputIterator>>

    basic_string(_InputIterator __beg,
                 _InputIterator __end,
                 const _Alloc& __a = _Alloc())
        : _M_dataplus(_M_local_data(), __a) {
      _M_construct(__beg, __end);
    }
    ~basic_string() { _M_dispose(); }

    basic_string& operator=(const basic_string& __str) {
      if (_Alloc_traits::_S_propagate_on_copy_assign()) {
        if (!_Alloc_traits::_S_always_equal() && !_M_is_local() &&
            _M_get_allocator() != __str._M_get_allocator()) {
          if (__str.size() <= _S_local_capacity) {
            _M_destroy(_M_allocated_capacity);
            _M_data(_M_local_data());
            _M_set_length(0);
          } else {
            const auto __len = __str.size();
            auto __alloc = __str._M_get_allocator();

            auto __ptr = _Alloc_traits::allocate(__alloc, __len + 1);
            _M_destroy(_M_allocated_capacity);
            _M_data(__ptr);
            _M_capacity(__len);
            _M_set_length(__len);
          }
        }
        std::__alloc_on_copy(_M_get_allocator(), __str._M_get_allocator());
      }

      return this->assign(__str);
    }

    basic_string& operator=(const _CharT* __s) { return this->assign(__s); }
    basic_string& operator=(_CharT __c) {
      this->assign(1, __c);
      return *this;
    }
    basic_string& operator=(basic_string&& __str) noexcept(
        _Alloc_traits::_S_nothrow_move()) {
      if (!_M_is_local() && _Alloc_traits::_S_propagate_on_move_assign() &&
          !_Alloc_traits::_S_always_equal() &&
          _M_get_allocator() != __str._M_get_allocator()) {
        _M_destroy(_M_allocated_capacity);
        _M_data(_M_local_data());
        _M_set_length(0);
      }

      std::__alloc_on_move(_M_get_allocator(), __str._M_get_allocator());

      if (!__str._M_is_local() &&
          (_Alloc_traits::_S_propagate_on_move_assign() ||
           _Alloc_traits::_S_always_equal())) {
        pointer __data = nullptr;
        size_type __capacity;
        if (!_M_is_local()) {
          if (_Alloc_traits::_S_always_equal()) {
            __data = _M_data();
            __capacity = _M_allocated_capacity;
          } else
            _M_destroy(_M_allocated_capacity);
        }

        _M_data(__str._M_data());
        _M_length(__str.length());
        _M_capacity(__str._M_allocated_capacity);
        if (__data) {
          __str._M_data(__data);
          __str._M_capacity(__capacity);
        } else
          __str._M_data(__str._M_local_buf);
      } else
        assign(__str);
      __str.clear();
      return *this;
    }

    basic_string& operator=(initializer_list<_CharT> __l) {
      this->assign(__l.begin(), __l.size());
      return *this;
    }
    iterator begin() noexcept { return iterator(_M_data()); }

    const_iterator begin() const noexcept { return const_iterator(_M_data()); }

    iterator end() noexcept { return iterator(_M_data() + this->size()); }

    const_iterator end() const noexcept {
      return const_iterator(_M_data() + this->size());
    }

    reverse_iterator rbegin() noexcept { return reverse_iterator(this->end()); }

    const_reverse_iterator rbegin() const noexcept {
      return const_reverse_iterator(this->end());
    }

    reverse_iterator rend() noexcept { return reverse_iterator(this->begin()); }

    const_reverse_iterator rend() const noexcept {
      return const_reverse_iterator(this->begin());
    }

    const_iterator cbegin() const noexcept {
      return const_iterator(this->_M_data());
    }

    const_iterator cend() const noexcept {
      return const_iterator(this->_M_data() + this->size());
    }

    const_reverse_iterator crbegin() const noexcept {
      return const_reverse_iterator(this->end());
    }

    const_reverse_iterator crend() const noexcept {
      return const_reverse_iterator(this->begin());
    }

   public:
    size_type size() const noexcept { return _M_string_length; }

    size_type length() const noexcept { return _M_string_length; }

    size_type max_size() const noexcept {
      return (_Alloc_traits::max_size(_M_get_allocator()) - 1) / 2;
    }
    void resize(size_type __n, _CharT __c);
    void resize(size_type __n) { this->resize(__n, _CharT()); }

    void shrink_to_fit() noexcept {
      if (capacity() > size()) {
        try {
          reserve(0);
        } catch (...) {
        }
      }
    }

    size_type capacity() const noexcept {
      return _M_is_local() ? size_type(_S_local_capacity)
                           : _M_allocated_capacity;
    }
    void reserve(size_type __res_arg = 0);

    void clear() noexcept { _M_set_length(0); }

    bool empty() const noexcept { return this->size() == 0; }
    const_reference operator[](size_type __pos) const noexcept {
      ;
      return _M_data()[__pos];
    }
    reference operator[](size_type __pos) {
      ;

      ;
      return _M_data()[__pos];
    }
    const_reference at(size_type __n) const {
      if (__n >= this->size())
        __throw_out_of_range_fmt(("basic_string::at: __n "
                                  "(which is %zu) >= this->size() "
                                  "(which is %zu)")

                                     ,
                                 __n, this->size());
      return _M_data()[__n];
    }
    reference at(size_type __n) {
      if (__n >= size())
        __throw_out_of_range_fmt(("basic_string::at: __n "
                                  "(which is %zu) >= this->size() "
                                  "(which is %zu)")

                                     ,
                                 __n, this->size());
      return _M_data()[__n];
    }

    reference front() noexcept {
      ;
      return operator[](0);
    }

    const_reference front() const noexcept {
      ;
      return operator[](0);
    }

    reference back() noexcept {
      ;
      return operator[](this->size() - 1);
    }

    const_reference back() const noexcept {
      ;
      return operator[](this->size() - 1);
    }
    basic_string& operator+=(const basic_string& __str) {
      return this->append(__str);
    }

    basic_string& operator+=(const _CharT* __s) { return this->append(__s); }

    basic_string& operator+=(_CharT __c) {
      this->push_back(__c);
      return *this;
    }

    basic_string& operator+=(initializer_list<_CharT> __l) {
      return this->append(__l.begin(), __l.size());
    }
    basic_string& append(const basic_string& __str) {
      return _M_append(__str._M_data(), __str.size());
    }
    basic_string& append(const basic_string& __str,
                         size_type __pos,
                         size_type __n) {
      return _M_append(
          __str._M_data() + __str._M_check(__pos, "basic_string::append"),
          __str._M_limit(__pos, __n));
    }

    basic_string& append(const _CharT* __s, size_type __n) {
      ;
      _M_check_length(size_type(0), __n, "basic_string::append");
      return _M_append(__s, __n);
    }

    basic_string& append(const _CharT* __s) {
      ;
      const size_type __n = traits_type::length(__s);
      _M_check_length(size_type(0), __n, "basic_string::append");
      return _M_append(__s, __n);
    }
    basic_string& append(size_type __n, _CharT __c) {
      return _M_replace_aux(this->size(), size_type(0), __n, __c);
    }

    basic_string& append(initializer_list<_CharT> __l) {
      return this->append(__l.begin(), __l.size());
    }
    template <class _InputIterator,
              typename = std::_RequireInputIter<_InputIterator>>

    basic_string& append(_InputIterator __first, _InputIterator __last) {
      return this->replace(end(), end(), __first, __last);
    }
    void push_back(_CharT __c) {
      const size_type __size = this->size();
      if (__size + 1 > this->capacity())
        this->_M_mutate(__size, size_type(0), 0, size_type(1));
      traits_type::assign(this->_M_data()[__size], __c);
      this->_M_set_length(__size + 1);
    }

    basic_string& assign(const basic_string& __str) {
      this->_M_assign(__str);
      return *this;
    }
    basic_string& assign(basic_string&& __str) noexcept(
        _Alloc_traits::_S_nothrow_move()) {
      return *this = std::move(__str);
    }
    basic_string& assign(const basic_string& __str,
                         size_type __pos,
                         size_type __n) {
      return _M_replace(
          size_type(0), this->size(),
          __str._M_data() + __str._M_check(__pos, "basic_string::assign"),
          __str._M_limit(__pos, __n));
    }
    basic_string& assign(const _CharT* __s, size_type __n) {
      ;
      return _M_replace(size_type(0), this->size(), __s, __n);
    }
    basic_string& assign(const _CharT* __s) {
      ;
      return _M_replace(size_type(0), this->size(), __s,
                        traits_type::length(__s));
    }
    basic_string& assign(size_type __n, _CharT __c) {
      return _M_replace_aux(size_type(0), this->size(), __n, __c);
    }
    template <class _InputIterator,
              typename = std::_RequireInputIter<_InputIterator>>

    basic_string& assign(_InputIterator __first, _InputIterator __last) {
      return this->replace(begin(), end(), __first, __last);
    }

    basic_string& assign(initializer_list<_CharT> __l) {
      return this->assign(__l.begin(), __l.size());
    }
    iterator insert(const_iterator __p, size_type __n, _CharT __c) {
      ;
      const size_type __pos = __p - begin();
      this->replace(__p, __p, __n, __c);
      return iterator(this->_M_data() + __pos);
    }
    template <class _InputIterator,
              typename = std::_RequireInputIter<_InputIterator>>
    iterator insert(const_iterator __p,
                    _InputIterator __beg,
                    _InputIterator __end) {
      ;
      const size_type __pos = __p - begin();
      this->replace(__p, __p, __beg, __end);
      return iterator(this->_M_data() + __pos);
    }
    void insert(iterator __p, initializer_list<_CharT> __l) {
      ;
      this->insert(__p - begin(), __l.begin(), __l.size());
    }
    basic_string& insert(size_type __pos1, const basic_string& __str) {
      return this->replace(__pos1, size_type(0), __str._M_data(), __str.size());
    }
    basic_string& insert(size_type __pos1,
                         const basic_string& __str,
                         size_type __pos2,
                         size_type __n) {
      return this->replace(
          __pos1, size_type(0),
          __str._M_data() + __str._M_check(__pos2, "basic_string::insert"),
          __str._M_limit(__pos2, __n));
    }
    basic_string& insert(size_type __pos, const _CharT* __s, size_type __n) {
      return this->replace(__pos, size_type(0), __s, __n);
    }
    basic_string& insert(size_type __pos, const _CharT* __s) {
      ;
      return this->replace(__pos, size_type(0), __s, traits_type::length(__s));
    }
    basic_string& insert(size_type __pos, size_type __n, _CharT __c) {
      return _M_replace_aux(_M_check(__pos, "basic_string::insert"),
                            size_type(0), __n, __c);
    }
    iterator insert(__const_iterator __p, _CharT __c) {
      ;
      const size_type __pos = __p - begin();
      _M_replace_aux(__pos, size_type(0), size_type(1), __c);
      return iterator(_M_data() + __pos);
    }
    basic_string& erase(size_type __pos = 0, size_type __n = npos) {
      _M_check(__pos, "basic_string::erase");
      if (__n == npos)
        this->_M_set_length(__pos);
      else if (__n != 0)
        this->_M_erase(__pos, _M_limit(__pos, __n));
      return *this;
    }
    iterator erase(__const_iterator __position) {
      ;
      const size_type __pos = __position - begin();
      this->_M_erase(__pos, size_type(1));
      return iterator(_M_data() + __pos);
    }
    iterator erase(__const_iterator __first, __const_iterator __last) {
      ;
      const size_type __pos = __first - begin();
      if (__last == end())
        this->_M_set_length(__pos);
      else
        this->_M_erase(__pos, __last - __first);
      return iterator(this->_M_data() + __pos);
    }

    void pop_back() noexcept {
      ;
      _M_erase(size() - 1, 1);
    }
    basic_string& replace(size_type __pos,
                          size_type __n,
                          const basic_string& __str) {
      return this->replace(__pos, __n, __str._M_data(), __str.size());
    }
    basic_string& replace(size_type __pos1,
                          size_type __n1,
                          const basic_string& __str,
                          size_type __pos2,
                          size_type __n2) {
      return this->replace(
          __pos1, __n1,
          __str._M_data() + __str._M_check(__pos2, "basic_string::replace"),
          __str._M_limit(__pos2, __n2));
    }
    basic_string& replace(size_type __pos,
                          size_type __n1,
                          const _CharT* __s,
                          size_type __n2) {
      ;
      return _M_replace(_M_check(__pos, "basic_string::replace"),
                        _M_limit(__pos, __n1), __s, __n2);
    }
    basic_string& replace(size_type __pos, size_type __n1, const _CharT* __s) {
      ;
      return this->replace(__pos, __n1, __s, traits_type::length(__s));
    }
    basic_string& replace(size_type __pos,
                          size_type __n1,
                          size_type __n2,
                          _CharT __c) {
      return _M_replace_aux(_M_check(__pos, "basic_string::replace"),
                            _M_limit(__pos, __n1), __n2, __c);
    }
    basic_string& replace(__const_iterator __i1,
                          __const_iterator __i2,
                          const basic_string& __str) {
      return this->replace(__i1, __i2, __str._M_data(), __str.size());
    }
    basic_string& replace(__const_iterator __i1,
                          __const_iterator __i2,
                          const _CharT* __s,
                          size_type __n) {
      ;
      return this->replace(__i1 - begin(), __i2 - __i1, __s, __n);
    }
    basic_string& replace(__const_iterator __i1,
                          __const_iterator __i2,
                          const _CharT* __s) {
      ;
      return this->replace(__i1, __i2, __s, traits_type::length(__s));
    }
    basic_string& replace(__const_iterator __i1,
                          __const_iterator __i2,
                          size_type __n,
                          _CharT __c) {
      ;
      return _M_replace_aux(__i1 - begin(), __i2 - __i1, __n, __c);
    }
    template <class _InputIterator,
              typename = std::_RequireInputIter<_InputIterator>>
    basic_string& replace(const_iterator __i1,
                          const_iterator __i2,
                          _InputIterator __k1,
                          _InputIterator __k2) {
      ;
      ;
      return this->_M_replace_dispatch(__i1, __i2, __k1, __k2,
                                       std::__false_type());
    }
    basic_string& replace(__const_iterator __i1,
                          __const_iterator __i2,
                          _CharT* __k1,
                          _CharT* __k2) {
      ;
      ;
      return this->replace(__i1 - begin(), __i2 - __i1, __k1, __k2 - __k1);
    }

    basic_string& replace(__const_iterator __i1,
                          __const_iterator __i2,
                          const _CharT* __k1,
                          const _CharT* __k2) {
      ;
      ;
      return this->replace(__i1 - begin(), __i2 - __i1, __k1, __k2 - __k1);
    }

    basic_string& replace(__const_iterator __i1,
                          __const_iterator __i2,
                          iterator __k1,
                          iterator __k2) {
      ;
      ;
      return this->replace(__i1 - begin(), __i2 - __i1, __k1.base(),
                           __k2 - __k1);
    }

    basic_string& replace(__const_iterator __i1,
                          __const_iterator __i2,
                          const_iterator __k1,
                          const_iterator __k2) {
      ;
      ;
      return this->replace(__i1 - begin(), __i2 - __i1, __k1.base(),
                           __k2 - __k1);
    }
    basic_string& replace(const_iterator __i1,
                          const_iterator __i2,
                          initializer_list<_CharT> __l) {
      return this->replace(__i1, __i2, __l.begin(), __l.size());
    }

   private:
    template <class _Integer>
    basic_string& _M_replace_dispatch(const_iterator __i1,
                                      const_iterator __i2,
                                      _Integer __n,
                                      _Integer __val,
                                      __true_type) {
      return _M_replace_aux(__i1 - begin(), __i2 - __i1, __n, __val);
    }

    template <class _InputIterator>
    basic_string& _M_replace_dispatch(const_iterator __i1,
                                      const_iterator __i2,
                                      _InputIterator __k1,
                                      _InputIterator __k2,
                                      __false_type);

    basic_string& _M_replace_aux(size_type __pos1,
                                 size_type __n1,
                                 size_type __n2,
                                 _CharT __c);

    basic_string& _M_replace(size_type __pos,
                             size_type __len1,
                             const _CharT* __s,
                             const size_type __len2);

    basic_string& _M_append(const _CharT* __s, size_type __n);

   public:
    size_type copy(_CharT* __s, size_type __n, size_type __pos = 0) const;
    void swap(basic_string& __s) noexcept;
    const _CharT* c_str() const noexcept { return _M_data(); }
    const _CharT* data() const noexcept { return _M_data(); }
    allocator_type get_allocator() const noexcept { return _M_get_allocator(); }
    size_type find(const _CharT* __s, size_type __pos, size_type __n) const
        noexcept;
    size_type find(const basic_string& __str, size_type __pos = 0) const
        noexcept {
      return this->find(__str.data(), __pos, __str.size());
    }
    size_type find(const _CharT* __s, size_type __pos = 0) const noexcept {
      ;
      return this->find(__s, __pos, traits_type::length(__s));
    }
    size_type find(_CharT __c, size_type __pos = 0) const noexcept;
    size_type rfind(const basic_string& __str, size_type __pos = npos) const
        noexcept {
      return this->rfind(__str.data(), __pos, __str.size());
    }
    size_type rfind(const _CharT* __s, size_type __pos, size_type __n) const
        noexcept;
    size_type rfind(const _CharT* __s, size_type __pos = npos) const {
      ;
      return this->rfind(__s, __pos, traits_type::length(__s));
    }
    size_type rfind(_CharT __c, size_type __pos = npos) const noexcept;
    size_type find_first_of(const basic_string& __str,
                            size_type __pos = 0) const noexcept {
      return this->find_first_of(__str.data(), __pos, __str.size());
    }
    size_type find_first_of(const _CharT* __s,
                            size_type __pos,
                            size_type __n) const noexcept;
    size_type find_first_of(const _CharT* __s, size_type __pos = 0) const
        noexcept {
      ;
      return this->find_first_of(__s, __pos, traits_type::length(__s));
    }
    size_type find_first_of(_CharT __c, size_type __pos = 0) const noexcept {
      return this->find(__c, __pos);
    }
    size_type find_last_of(const basic_string& __str,
                           size_type __pos = npos) const noexcept {
      return this->find_last_of(__str.data(), __pos, __str.size());
    }
    size_type find_last_of(const _CharT* __s,
                           size_type __pos,
                           size_type __n) const noexcept;
    size_type find_last_of(const _CharT* __s, size_type __pos = npos) const
        noexcept {
      ;
      return this->find_last_of(__s, __pos, traits_type::length(__s));
    }
    size_type find_last_of(_CharT __c, size_type __pos = npos) const noexcept {
      return this->rfind(__c, __pos);
    }
    size_type find_first_not_of(const basic_string& __str,
                                size_type __pos = 0) const noexcept {
      return this->find_first_not_of(__str.data(), __pos, __str.size());
    }
    size_type find_first_not_of(const _CharT* __s,
                                size_type __pos,
                                size_type __n) const noexcept;
    size_type find_first_not_of(const _CharT* __s, size_type __pos = 0) const
        noexcept {
      ;
      return this->find_first_not_of(__s, __pos, traits_type::length(__s));
    }
    size_type find_first_not_of(_CharT __c, size_type __pos = 0) const noexcept;
    size_type find_last_not_of(const basic_string& __str,
                               size_type __pos = npos) const noexcept {
      return this->find_last_not_of(__str.data(), __pos, __str.size());
    }
    size_type find_last_not_of(const _CharT* __s,
                               size_type __pos,
                               size_type __n) const noexcept;
    size_type find_last_not_of(const _CharT* __s, size_type __pos = npos) const
        noexcept {
      ;
      return this->find_last_not_of(__s, __pos, traits_type::length(__s));
    }
    size_type find_last_not_of(_CharT __c, size_type __pos = npos) const
        noexcept;
    basic_string substr(size_type __pos = 0, size_type __n = npos) const {
      return basic_string(*this, _M_check(__pos, "basic_string::substr"), __n);
    }
    int compare(const basic_string& __str) const {
      const size_type __size = this->size();
      const size_type __osize = __str.size();
      const size_type __len = std::min(__size, __osize);

      int __r = traits_type::compare(_M_data(), __str.data(), __len);
      if (!__r)
        __r = _S_compare(__size, __osize);
      return __r;
    }
    int compare(size_type __pos,
                size_type __n,
                const basic_string& __str) const;
    int compare(size_type __pos1,
                size_type __n1,
                const basic_string& __str,
                size_type __pos2,
                size_type __n2) const;
    int compare(const _CharT* __s) const noexcept;
    int compare(size_type __pos, size_type __n1, const _CharT* __s) const;
    int compare(size_type __pos,
                size_type __n1,
                const _CharT* __s,
                size_type __n2) const;
  };
  }  // namespace __cxx11
  template <typename _CharT, typename _Traits, typename _Alloc>
  basic_string<_CharT, _Traits, _Alloc> operator+(
      const basic_string<_CharT, _Traits, _Alloc>& __lhs,
      const basic_string<_CharT, _Traits, _Alloc>& __rhs) {
    basic_string<_CharT, _Traits, _Alloc> __str(__lhs);
    __str.append(__rhs);
    return __str;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  basic_string<_CharT, _Traits, _Alloc> operator+(
      const _CharT* __lhs, const basic_string<_CharT, _Traits, _Alloc>& __rhs);

  template <typename _CharT, typename _Traits, typename _Alloc>
  basic_string<_CharT, _Traits, _Alloc> operator+(
      _CharT __lhs, const basic_string<_CharT, _Traits, _Alloc>& __rhs);

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline basic_string<_CharT, _Traits, _Alloc> operator+(
      const basic_string<_CharT, _Traits, _Alloc>& __lhs, const _CharT* __rhs) {
    basic_string<_CharT, _Traits, _Alloc> __str(__lhs);
    __str.append(__rhs);
    return __str;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline basic_string<_CharT, _Traits, _Alloc> operator+(
      const basic_string<_CharT, _Traits, _Alloc>& __lhs, _CharT __rhs) {
    typedef basic_string<_CharT, _Traits, _Alloc> __string_type;
    typedef typename __string_type::size_type __size_type;
    __string_type __str(__lhs);
    __str.append(__size_type(1), __rhs);
    return __str;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline basic_string<_CharT, _Traits, _Alloc> operator+(
      basic_string<_CharT, _Traits, _Alloc>&& __lhs,
      const basic_string<_CharT, _Traits, _Alloc>& __rhs) {
    return std::move(__lhs.append(__rhs));
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline basic_string<_CharT, _Traits, _Alloc> operator+(
      const basic_string<_CharT, _Traits, _Alloc>& __lhs,
      basic_string<_CharT, _Traits, _Alloc>&& __rhs) {
    return std::move(__rhs.insert(0, __lhs));
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline basic_string<_CharT, _Traits, _Alloc> operator+(
      basic_string<_CharT, _Traits, _Alloc>&& __lhs,
      basic_string<_CharT, _Traits, _Alloc>&& __rhs) {
    const auto __size = __lhs.size() + __rhs.size();
    const bool __cond =
        (__size > __lhs.capacity() && __size <= __rhs.capacity());
    return __cond ? std::move(__rhs.insert(0, __lhs))
                  : std::move(__lhs.append(__rhs));
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline basic_string<_CharT, _Traits, _Alloc> operator+(
      const _CharT* __lhs, basic_string<_CharT, _Traits, _Alloc>&& __rhs) {
    return std::move(__rhs.insert(0, __lhs));
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline basic_string<_CharT, _Traits, _Alloc> operator+(
      _CharT __lhs, basic_string<_CharT, _Traits, _Alloc>&& __rhs) {
    return std::move(__rhs.insert(0, 1, __lhs));
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline basic_string<_CharT, _Traits, _Alloc> operator+(
      basic_string<_CharT, _Traits, _Alloc>&& __lhs, const _CharT* __rhs) {
    return std::move(__lhs.append(__rhs));
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline basic_string<_CharT, _Traits, _Alloc> operator+(
      basic_string<_CharT, _Traits, _Alloc>&& __lhs, _CharT __rhs) {
    return std::move(__lhs.append(1, __rhs));
  }
  template <typename _CharT, typename _Traits, typename _Alloc>
  inline bool operator==(
      const basic_string<_CharT, _Traits, _Alloc>& __lhs,
      const basic_string<_CharT, _Traits, _Alloc>& __rhs) noexcept {
    return __lhs.compare(__rhs) == 0;
  }

  template <typename _CharT>
  inline
      typename __gnu_cxx::__enable_if<__is_char<_CharT>::__value, bool>::__type
      operator==(const basic_string<_CharT>& __lhs,
                 const basic_string<_CharT>& __rhs) noexcept {
    return (__lhs.size() == __rhs.size() &&
            !std::char_traits<_CharT>::compare(__lhs.data(), __rhs.data(),
                                               __lhs.size()));
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline bool operator==(const _CharT* __lhs,
                         const basic_string<_CharT, _Traits, _Alloc>& __rhs) {
    return __rhs.compare(__lhs) == 0;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline bool operator==(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
                         const _CharT* __rhs) {
    return __lhs.compare(__rhs) == 0;
  }
  template <typename _CharT, typename _Traits, typename _Alloc>
  inline bool operator!=(
      const basic_string<_CharT, _Traits, _Alloc>& __lhs,
      const basic_string<_CharT, _Traits, _Alloc>& __rhs) noexcept {
    return !(__lhs == __rhs);
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline bool operator!=(const _CharT* __lhs,
                         const basic_string<_CharT, _Traits, _Alloc>& __rhs) {
    return !(__lhs == __rhs);
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline bool operator!=(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
                         const _CharT* __rhs) {
    return !(__lhs == __rhs);
  }
  template <typename _CharT, typename _Traits, typename _Alloc>
  inline bool operator<(
      const basic_string<_CharT, _Traits, _Alloc>& __lhs,
      const basic_string<_CharT, _Traits, _Alloc>& __rhs) noexcept {
    return __lhs.compare(__rhs) < 0;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline bool operator<(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
                        const _CharT* __rhs) {
    return __lhs.compare(__rhs) < 0;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline bool operator<(const _CharT* __lhs,
                        const basic_string<_CharT, _Traits, _Alloc>& __rhs) {
    return __rhs.compare(__lhs) > 0;
  }
  template <typename _CharT, typename _Traits, typename _Alloc>
  inline bool operator>(
      const basic_string<_CharT, _Traits, _Alloc>& __lhs,
      const basic_string<_CharT, _Traits, _Alloc>& __rhs) noexcept {
    return __lhs.compare(__rhs) > 0;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline bool operator>(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
                        const _CharT* __rhs) {
    return __lhs.compare(__rhs) > 0;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline bool operator>(const _CharT* __lhs,
                        const basic_string<_CharT, _Traits, _Alloc>& __rhs) {
    return __rhs.compare(__lhs) < 0;
  }
  template <typename _CharT, typename _Traits, typename _Alloc>
  inline bool operator<=(
      const basic_string<_CharT, _Traits, _Alloc>& __lhs,
      const basic_string<_CharT, _Traits, _Alloc>& __rhs) noexcept {
    return __lhs.compare(__rhs) <= 0;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline bool operator<=(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
                         const _CharT* __rhs) {
    return __lhs.compare(__rhs) <= 0;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline bool operator<=(const _CharT* __lhs,
                         const basic_string<_CharT, _Traits, _Alloc>& __rhs) {
    return __rhs.compare(__lhs) >= 0;
  }
  template <typename _CharT, typename _Traits, typename _Alloc>
  inline bool operator>=(
      const basic_string<_CharT, _Traits, _Alloc>& __lhs,
      const basic_string<_CharT, _Traits, _Alloc>& __rhs) noexcept {
    return __lhs.compare(__rhs) >= 0;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline bool operator>=(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
                         const _CharT* __rhs) {
    return __lhs.compare(__rhs) >= 0;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline bool operator>=(const _CharT* __lhs,
                         const basic_string<_CharT, _Traits, _Alloc>& __rhs) {
    return __rhs.compare(__lhs) <= 0;
  }
  template <typename _CharT, typename _Traits, typename _Alloc>
  inline void swap(basic_string<_CharT, _Traits, _Alloc> & __lhs,
                   basic_string<_CharT, _Traits, _Alloc> &
                       __rhs) noexcept(noexcept(__lhs.swap(__rhs))) {
    __lhs.swap(__rhs);
  }
  template <typename _CharT, typename _Traits, typename _Alloc>
  basic_istream<_CharT, _Traits>& operator>>(
      basic_istream<_CharT, _Traits>& __is,
      basic_string<_CharT, _Traits, _Alloc>& __str);

  template <>
  basic_istream<char>& operator>>(basic_istream<char>& __is,
                                  basic_string<char>& __str);
  template <typename _CharT, typename _Traits, typename _Alloc>
  inline basic_ostream<_CharT, _Traits>& operator<<(
      basic_ostream<_CharT, _Traits>& __os,
      const basic_string<_CharT, _Traits, _Alloc>& __str) {
    return __ostream_insert(__os, __str.data(), __str.size());
  }
  template <typename _CharT, typename _Traits, typename _Alloc>
  basic_istream<_CharT, _Traits>& getline(
      basic_istream<_CharT, _Traits> & __is,
      basic_string<_CharT, _Traits, _Alloc> & __str, _CharT __delim);
  template <typename _CharT, typename _Traits, typename _Alloc>
  inline basic_istream<_CharT, _Traits>& getline(
      basic_istream<_CharT, _Traits> & __is,
      basic_string<_CharT, _Traits, _Alloc> & __str) {
    return std::getline(__is, __str, __is.widen('\n'));
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline basic_istream<_CharT, _Traits>& getline(
      basic_istream<_CharT, _Traits> && __is,
      basic_string<_CharT, _Traits, _Alloc> & __str, _CharT __delim) {
    return std::getline(__is, __str, __delim);
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  inline basic_istream<_CharT, _Traits>& getline(
      basic_istream<_CharT, _Traits> && __is,
      basic_string<_CharT, _Traits, _Alloc> & __str) {
    return std::getline(__is, __str);
  }

  template <>
  basic_istream<char>& getline(basic_istream<char> & __in,
                               basic_string<char> & __str, char __delim);

  template <>
  basic_istream<wchar_t>& getline(basic_istream<wchar_t> & __in,
                                  basic_string<wchar_t> & __str,
                                  wchar_t __delim);

}  // namespace std__attribute__((__visibility__("default")))

extern "C" {

typedef struct {
  int quot;
  int rem;
} div_t;

typedef struct {
  long int quot;
  long int rem;
} ldiv_t;

__extension__ typedef struct {
  long long int quot;
  long long int rem;
} lldiv_t;
extern size_t __ctype_get_mb_cur_max(void) throw();

extern double atof(const char* __nptr) throw() __attribute__((__pure__))
__attribute__((__nonnull__(1)));

extern int atoi(const char* __nptr) throw() __attribute__((__pure__))
__attribute__((__nonnull__(1)));

extern long int atol(const char* __nptr) throw() __attribute__((__pure__))
__attribute__((__nonnull__(1)));

__extension__ extern long long int atoll(const char* __nptr) throw()
    __attribute__((__pure__)) __attribute__((__nonnull__(1)));

extern double strtod(const char* __restrict __nptr,
                     char** __restrict __endptr) throw()
    __attribute__((__nonnull__(1)));

extern float strtof(const char* __restrict __nptr,
                    char** __restrict __endptr) throw()
    __attribute__((__nonnull__(1)));

extern long double strtold(const char* __restrict __nptr,
                           char** __restrict __endptr) throw()
    __attribute__((__nonnull__(1)));

extern _Float128 strtof128(const char* __restrict __nptr,
                           char** __restrict __endptr) throw()
    __attribute__((__nonnull__(1)));

extern long int strtol(const char* __restrict __nptr,
                       char** __restrict __endptr,
                       int __base) throw() __attribute__((__nonnull__(1)));

extern unsigned long int strtoul(const char* __restrict __nptr,
                                 char** __restrict __endptr,
                                 int __base) throw()
    __attribute__((__nonnull__(1)));

__extension__ extern long long int strtoq(const char* __restrict __nptr,
                                          char** __restrict __endptr,
                                          int __base) throw()
    __attribute__((__nonnull__(1)));

__extension__ extern unsigned long long int strtouq(
    const char* __restrict __nptr,
    char** __restrict __endptr,
    int __base) throw() __attribute__((__nonnull__(1)));

__extension__ extern long long int strtoll(const char* __restrict __nptr,
                                           char** __restrict __endptr,
                                           int __base) throw()
    __attribute__((__nonnull__(1)));

__extension__ extern unsigned long long int strtoull(
    const char* __restrict __nptr,
    char** __restrict __endptr,
    int __base) throw() __attribute__((__nonnull__(1)));

extern int strfromd(char* __dest,
                    size_t __size,
                    const char* __format,
                    double __f) throw() __attribute__((__nonnull__(3)));

extern int strfromf(char* __dest,
                    size_t __size,
                    const char* __format,
                    float __f) throw() __attribute__((__nonnull__(3)));

extern int strfroml(char* __dest,
                    size_t __size,
                    const char* __format,
                    long double __f) throw() __attribute__((__nonnull__(3)));

extern int strfromf128(char* __dest,
                       size_t __size,
                       const char* __format,
                       _Float128 __f) throw() __attribute__((__nonnull__(3)));
extern long int strtol_l(const char* __restrict __nptr,
                         char** __restrict __endptr,
                         int __base,
                         locale_t __loc) throw()
    __attribute__((__nonnull__(1, 4)));

extern unsigned long int strtoul_l(const char* __restrict __nptr,
                                   char** __restrict __endptr,
                                   int __base,
                                   locale_t __loc) throw()
    __attribute__((__nonnull__(1, 4)));

__extension__ extern long long int strtoll_l(const char* __restrict __nptr,
                                             char** __restrict __endptr,
                                             int __base,
                                             locale_t __loc) throw()
    __attribute__((__nonnull__(1, 4)));

__extension__ extern unsigned long long int strtoull_l(
    const char* __restrict __nptr,
    char** __restrict __endptr,
    int __base,
    locale_t __loc) throw() __attribute__((__nonnull__(1, 4)));

extern double strtod_l(const char* __restrict __nptr,
                       char** __restrict __endptr,
                       locale_t __loc) throw()
    __attribute__((__nonnull__(1, 3)));

extern float strtof_l(const char* __restrict __nptr,
                      char** __restrict __endptr,
                      locale_t __loc) throw()
    __attribute__((__nonnull__(1, 3)));

extern long double strtold_l(const char* __restrict __nptr,
                             char** __restrict __endptr,
                             locale_t __loc) throw()
    __attribute__((__nonnull__(1, 3)));

extern _Float128 strtof128_l(const char* __restrict __nptr,
                             char** __restrict __endptr,
                             locale_t __loc) throw()
    __attribute__((__nonnull__(1, 3)));
extern char* l64a(long int __n) throw();

extern long int a64l(const char* __s) throw() __attribute__((__pure__))
__attribute__((__nonnull__(1)));

extern "C" {

typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;

typedef __loff_t loff_t;

typedef __ino_t ino_t;

typedef __ino64_t ino64_t;

typedef __dev_t dev_t;

typedef __gid_t gid_t;

typedef __mode_t mode_t;

typedef __nlink_t nlink_t;

typedef __uid_t uid_t;

typedef __off_t off_t;

typedef __off64_t off64_t;
typedef __id_t id_t;

typedef __ssize_t ssize_t;

typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;

typedef __key_t key_t;
typedef __useconds_t useconds_t;

typedef __suseconds_t suseconds_t;

typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef unsigned int u_int8_t __attribute__((__mode__(__QI__)));
typedef unsigned int u_int16_t __attribute__((__mode__(__HI__)));
typedef unsigned int u_int32_t __attribute__((__mode__(__SI__)));
typedef unsigned int u_int64_t __attribute__((__mode__(__DI__)));

typedef int register_t __attribute__((__mode__(__word__)));

typedef struct {
  unsigned long int __val[(1024 / (8 * sizeof(unsigned long int)))];
} __sigset_t;

typedef __sigset_t sigset_t;
typedef long int __fd_mask;
typedef struct {
  __fd_mask fds_bits[1024 / (8 * (int)sizeof(__fd_mask))];

} fd_set;

typedef __fd_mask fd_mask;
extern "C" {
extern int select(int __nfds,
                  fd_set* __restrict __readfds,
                  fd_set* __restrict __writefds,
                  fd_set* __restrict __exceptfds,
                  struct timeval* __restrict __timeout);
extern int pselect(int __nfds,
                   fd_set* __restrict __readfds,
                   fd_set* __restrict __writefds,
                   fd_set* __restrict __exceptfds,
                   const struct timespec* __restrict __timeout,
                   const __sigset_t* __restrict __sigmask);
}

typedef __blksize_t blksize_t;

typedef __blkcnt_t blkcnt_t;

typedef __fsblkcnt_t fsblkcnt_t;

typedef __fsfilcnt_t fsfilcnt_t;
typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;
}

extern long int random(void) throw();

extern void srandom(unsigned int __seed) throw();

extern char* initstate(unsigned int __seed,
                       char* __statebuf,
                       size_t __statelen) throw()
    __attribute__((__nonnull__(2)));

extern char* setstate(char* __statebuf) throw() __attribute__((__nonnull__(1)));

struct random_data {
  int32_t* fptr;
  int32_t* rptr;
  int32_t* state;
  int rand_type;
  int rand_deg;
  int rand_sep;
  int32_t* end_ptr;
};

extern int random_r(struct random_data* __restrict __buf,
                    int32_t* __restrict __result) throw()
    __attribute__((__nonnull__(1, 2)));

extern int srandom_r(unsigned int __seed, struct random_data* __buf) throw()
    __attribute__((__nonnull__(2)));

extern int initstate_r(unsigned int __seed,
                       char* __restrict __statebuf,
                       size_t __statelen,
                       struct random_data* __restrict __buf) throw()
    __attribute__((__nonnull__(2, 4)));

extern int setstate_r(char* __restrict __statebuf,
                      struct random_data* __restrict __buf) throw()
    __attribute__((__nonnull__(1, 2)));

extern int rand(void) throw();

extern void srand(unsigned int __seed) throw();

extern int rand_r(unsigned int* __seed) throw();

extern double drand48(void) throw();
extern double erand48(unsigned short int __xsubi[3]) throw()
    __attribute__((__nonnull__(1)));

extern long int lrand48(void) throw();
extern long int nrand48(unsigned short int __xsubi[3]) throw()
    __attribute__((__nonnull__(1)));

extern long int mrand48(void) throw();
extern long int jrand48(unsigned short int __xsubi[3]) throw()
    __attribute__((__nonnull__(1)));

extern void srand48(long int __seedval) throw();
extern unsigned short int* seed48(unsigned short int __seed16v[3]) throw()
    __attribute__((__nonnull__(1)));
extern void lcong48(unsigned short int __param[7]) throw()
    __attribute__((__nonnull__(1)));

struct drand48_data {
  unsigned short int __x[3];
  unsigned short int __old_x[3];
  unsigned short int __c;
  unsigned short int __init;
  __extension__ unsigned long long int __a;
};

extern int drand48_r(struct drand48_data* __restrict __buffer,
                     double* __restrict __result) throw()
    __attribute__((__nonnull__(1, 2)));
extern int erand48_r(unsigned short int __xsubi[3],
                     struct drand48_data* __restrict __buffer,
                     double* __restrict __result) throw()
    __attribute__((__nonnull__(1, 2)));

extern int lrand48_r(struct drand48_data* __restrict __buffer,
                     long int* __restrict __result) throw()
    __attribute__((__nonnull__(1, 2)));
extern int nrand48_r(unsigned short int __xsubi[3],
                     struct drand48_data* __restrict __buffer,
                     long int* __restrict __result) throw()
    __attribute__((__nonnull__(1, 2)));

extern int mrand48_r(struct drand48_data* __restrict __buffer,
                     long int* __restrict __result) throw()
    __attribute__((__nonnull__(1, 2)));
extern int jrand48_r(unsigned short int __xsubi[3],
                     struct drand48_data* __restrict __buffer,
                     long int* __restrict __result) throw()
    __attribute__((__nonnull__(1, 2)));

extern int srand48_r(long int __seedval, struct drand48_data* __buffer) throw()
    __attribute__((__nonnull__(2)));

extern int seed48_r(unsigned short int __seed16v[3],
                    struct drand48_data* __buffer) throw()
    __attribute__((__nonnull__(1, 2)));

extern int lcong48_r(unsigned short int __param[7],
                     struct drand48_data* __buffer) throw()
    __attribute__((__nonnull__(1, 2)));

extern void* malloc(size_t __size) throw() __attribute__((__malloc__));

extern void* calloc(size_t __nmemb, size_t __size) throw()
    __attribute__((__malloc__));

extern void* realloc(void* __ptr, size_t __size) throw()
    __attribute__((__warn_unused_result__));

extern void* reallocarray(void* __ptr, size_t __nmemb, size_t __size) throw()
    __attribute__((__warn_unused_result__));

extern void free(void* __ptr) throw();

extern "C" {

extern void* alloca(size_t __size) throw();
}

extern void* valloc(size_t __size) throw() __attribute__((__malloc__));

extern int posix_memalign(void** __memptr,
                          size_t __alignment,
                          size_t __size) throw()
    __attribute__((__nonnull__(1)));

extern void* aligned_alloc(size_t __alignment, size_t __size) throw()
    __attribute__((__malloc__)) __attribute__((__alloc_size__(2)));

extern void abort(void) throw() __attribute__((__noreturn__));

extern int atexit(void (*__func)(void)) throw() __attribute__((__nonnull__(1)));

extern "C++" int at_quick_exit(void (*__func)(void)) throw() __asm(
    "at_quick_exit") __attribute__((__nonnull__(1)));
extern int on_exit(void (*__func)(int __status, void* __arg),
                   void* __arg) throw() __attribute__((__nonnull__(1)));

extern void exit(int __status) throw() __attribute__((__noreturn__));

extern void quick_exit(int __status) throw() __attribute__((__noreturn__));

extern void _Exit(int __status) throw() __attribute__((__noreturn__));

extern char* getenv(const char* __name) throw() __attribute__((__nonnull__(1)));

extern char* secure_getenv(const char* __name) throw()
    __attribute__((__nonnull__(1)));

extern int putenv(char* __string) throw() __attribute__((__nonnull__(1)));

extern int setenv(const char* __name,
                  const char* __value,
                  int __replace) throw() __attribute__((__nonnull__(2)));

extern int unsetenv(const char* __name) throw() __attribute__((__nonnull__(1)));

extern int clearenv(void) throw();
extern char* mktemp(char* __template) throw() __attribute__((__nonnull__(1)));
extern int mkstemp(char* __template) __attribute__((__nonnull__(1)));
extern int mkstemp64(char* __template) __attribute__((__nonnull__(1)));
extern int mkstemps(char* __template, int __suffixlen)
    __attribute__((__nonnull__(1)));
extern int mkstemps64(char* __template, int __suffixlen)
    __attribute__((__nonnull__(1)));
extern char* mkdtemp(char* __template) throw() __attribute__((__nonnull__(1)));
extern int mkostemp(char* __template, int __flags)
    __attribute__((__nonnull__(1)));
extern int mkostemp64(char* __template, int __flags)
    __attribute__((__nonnull__(1)));
extern int mkostemps(char* __template, int __suffixlen, int __flags)
    __attribute__((__nonnull__(1)));
extern int mkostemps64(char* __template, int __suffixlen, int __flags)
    __attribute__((__nonnull__(1)));
extern int system(const char* __command);

extern char* canonicalize_file_name(const char* __name) throw()
    __attribute__((__nonnull__(1)));
extern char* realpath(const char* __restrict __name,
                      char* __restrict __resolved) throw();

typedef int (*__compar_fn_t)(const void*, const void*);

typedef __compar_fn_t comparison_fn_t;

typedef int (*__compar_d_fn_t)(const void*, const void*, void*);

extern void* bsearch(const void* __key,
                     const void* __base,
                     size_t __nmemb,
                     size_t __size,
                     __compar_fn_t __compar)
    __attribute__((__nonnull__(1, 2, 5)));

extern void qsort(void* __base,
                  size_t __nmemb,
                  size_t __size,
                  __compar_fn_t __compar) __attribute__((__nonnull__(1, 4)));

extern void qsort_r(void* __base,
                    size_t __nmemb,
                    size_t __size,
                    __compar_d_fn_t __compar,
                    void* __arg) __attribute__((__nonnull__(1, 4)));

extern int abs(int __x) throw() __attribute__((__const__));
extern long int labs(long int __x) throw() __attribute__((__const__));

__extension__ extern long long int llabs(long long int __x) throw()
    __attribute__((__const__));

extern div_t div(int __numer, int __denom) throw() __attribute__((__const__));
extern ldiv_t ldiv(long int __numer, long int __denom) throw()
    __attribute__((__const__));

__extension__ extern lldiv_t lldiv(long long int __numer,
                                   long long int __denom) throw()
    __attribute__((__const__));
extern char* ecvt(double __value,
                  int __ndigit,
                  int* __restrict __decpt,
                  int* __restrict __sign) throw()
    __attribute__((__nonnull__(3, 4)));

extern char* fcvt(double __value,
                  int __ndigit,
                  int* __restrict __decpt,
                  int* __restrict __sign) throw()
    __attribute__((__nonnull__(3, 4)));

extern char* gcvt(double __value, int __ndigit, char* __buf) throw()
    __attribute__((__nonnull__(3)));

extern char* qecvt(long double __value,
                   int __ndigit,
                   int* __restrict __decpt,
                   int* __restrict __sign) throw()
    __attribute__((__nonnull__(3, 4)));
extern char* qfcvt(long double __value,
                   int __ndigit,
                   int* __restrict __decpt,
                   int* __restrict __sign) throw()
    __attribute__((__nonnull__(3, 4)));
extern char* qgcvt(long double __value, int __ndigit, char* __buf) throw()
    __attribute__((__nonnull__(3)));

extern int ecvt_r(double __value,
                  int __ndigit,
                  int* __restrict __decpt,
                  int* __restrict __sign,
                  char* __restrict __buf,
                  size_t __len) throw() __attribute__((__nonnull__(3, 4, 5)));
extern int fcvt_r(double __value,
                  int __ndigit,
                  int* __restrict __decpt,
                  int* __restrict __sign,
                  char* __restrict __buf,
                  size_t __len) throw() __attribute__((__nonnull__(3, 4, 5)));

extern int qecvt_r(long double __value,
                   int __ndigit,
                   int* __restrict __decpt,
                   int* __restrict __sign,
                   char* __restrict __buf,
                   size_t __len) throw() __attribute__((__nonnull__(3, 4, 5)));
extern int qfcvt_r(long double __value,
                   int __ndigit,
                   int* __restrict __decpt,
                   int* __restrict __sign,
                   char* __restrict __buf,
                   size_t __len) throw() __attribute__((__nonnull__(3, 4, 5)));

extern int mblen(const char* __s, size_t __n) throw();

extern int mbtowc(wchar_t* __restrict __pwc,
                  const char* __restrict __s,
                  size_t __n) throw();

extern int wctomb(char* __s, wchar_t __wchar) throw();

extern size_t mbstowcs(wchar_t* __restrict __pwcs,
                       const char* __restrict __s,
                       size_t __n) throw();

extern size_t wcstombs(char* __restrict __s,
                       const wchar_t* __restrict __pwcs,
                       size_t __n) throw();

extern int rpmatch(const char* __response) throw()
    __attribute__((__nonnull__(1)));
extern int getsubopt(char** __restrict __optionp,
                     char* const* __restrict __tokens,
                     char** __restrict __valuep) throw()
    __attribute__((__nonnull__(1, 2, 3)));

extern void setkey(const char* __key) throw() __attribute__((__nonnull__(1)));

extern int posix_openpt(int __oflag);

extern int grantpt(int __fd) throw();

extern int unlockpt(int __fd) throw();

extern char* ptsname(int __fd) throw();

extern int ptsname_r(int __fd, char* __buf, size_t __buflen) throw()
    __attribute__((__nonnull__(2)));

extern int getpt(void);

extern int getloadavg(double __loadavg[], int __nelem) throw()
    __attribute__((__nonnull__(1)));
}

extern "C++" {
namespace std __attribute__((__visibility__("default"))) {

  using ::abs;

  inline long abs(long __i) { return __builtin_labs(__i); }

  inline long long abs(long long __x) { return __builtin_llabs(__x); }

  inline constexpr double abs(double __x) { return __builtin_fabs(__x); }

  inline constexpr float abs(float __x) { return __builtin_fabsf(__x); }

  inline constexpr long double abs(long double __x) {
    return __builtin_fabsl(__x);
  }

  inline constexpr __int128 abs(__int128 __x) { return __x >= 0 ? __x : -__x; }
  inline constexpr __float128 abs(__float128 __x) {
    return __x < 0 ? -__x : __x;
  }

}  // namespace std__attribute__((__visibility__("default")))
}
extern "C++" {
namespace std __attribute__((__visibility__("default"))) {

  using ::div_t;
  using ::ldiv_t;

  using ::abort;
  using ::atexit;

  using ::at_quick_exit;

  using ::atof;
  using ::atoi;
  using ::atol;
  using ::bsearch;
  using ::calloc;
  using ::div;
  using ::exit;
  using ::free;
  using ::getenv;
  using ::labs;
  using ::ldiv;
  using ::malloc;

  using ::mblen;
  using ::mbstowcs;
  using ::mbtowc;

  using ::qsort;

  using ::quick_exit;

  using ::rand;
  using ::realloc;
  using ::srand;
  using ::strtod;
  using ::strtol;
  using ::strtoul;
  using ::system;

  using ::wcstombs;
  using ::wctomb;

  inline ldiv_t div(long __i, long __j) { return ldiv(__i, __j); }

}  // namespace std__attribute__((__visibility__("default")))
namespace __gnu_cxx __attribute__((__visibility__("default"))) {

  using ::lldiv_t;

  using ::_Exit;

  using ::llabs;

  inline lldiv_t div(long long __n, long long __d) {
    lldiv_t __q;
    __q.quot = __n / __d;
    __q.rem = __n % __d;
    return __q;
  }

  using ::atoll;
  using ::lldiv;
  using ::strtoll;
  using ::strtoull;

  using ::strtof;
  using ::strtold;

}  // namespace __gnu_cxx__attribute__((__visibility__("default")))

namespace std {

using ::__gnu_cxx::lldiv_t;

using ::__gnu_cxx::_Exit;

using ::__gnu_cxx::div;
using ::__gnu_cxx::llabs;
using ::__gnu_cxx::lldiv;

using ::__gnu_cxx::atoll;
using ::__gnu_cxx::strtof;
using ::__gnu_cxx::strtold;
using ::__gnu_cxx::strtoll;
using ::__gnu_cxx::strtoull;
}  // namespace std
}

extern "C" {

typedef struct {
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct {
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
struct _IO_jump_t;
struct _IO_FILE;

typedef void _IO_lock_t;

struct _IO_marker {
  struct _IO_marker* _next;
  struct _IO_FILE* _sbuf;

  int _pos;
};

enum __codecvt_result {
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
struct _IO_FILE {
  int _flags;

  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;

  char* _IO_save_base;
  char* _IO_backup_base;
  char* _IO_save_end;

  struct _IO_marker* _markers;

  struct _IO_FILE* _chain;

  int _fileno;

  int _flags2;

  __off_t _old_offset;

  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];

  _IO_lock_t* _lock;
  __off64_t _offset;

  void* __pad1;
  void* __pad2;
  void* __pad3;
  void* __pad4;

  size_t __pad5;
  int _mode;

  char _unused2[15 * sizeof(int) - 4 * sizeof(void*) - sizeof(size_t)];
};

struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
typedef __ssize_t __io_read_fn(void* __cookie, char* __buf, size_t __nbytes);

typedef __ssize_t __io_write_fn(void* __cookie, const char* __buf, size_t __n);

typedef int __io_seek_fn(void* __cookie, __off64_t* __pos, int __w);

typedef int __io_close_fn(void* __cookie);

typedef __io_read_fn cookie_read_function_t;
typedef __io_write_fn cookie_write_function_t;
typedef __io_seek_fn cookie_seek_function_t;
typedef __io_close_fn cookie_close_function_t;

typedef struct {
  __io_read_fn* read;
  __io_write_fn* write;
  __io_seek_fn* seek;
  __io_close_fn* close;
} _IO_cookie_io_functions_t;
typedef _IO_cookie_io_functions_t cookie_io_functions_t;

struct _IO_cookie_file;

extern void _IO_cookie_init(struct _IO_cookie_file* __cfile,
                            int __read_write,
                            void* __cookie,
                            _IO_cookie_io_functions_t __fns);

extern "C" {

extern int __underflow(_IO_FILE*);
extern int __uflow(_IO_FILE*);
extern int __overflow(_IO_FILE*, int);
extern int _IO_getc(_IO_FILE* __fp);
extern int _IO_putc(int __c, _IO_FILE* __fp);
extern int _IO_feof(_IO_FILE* __fp) throw();
extern int _IO_ferror(_IO_FILE* __fp) throw();

extern int _IO_peekc_locked(_IO_FILE* __fp);

extern void _IO_flockfile(_IO_FILE*) throw();
extern void _IO_funlockfile(_IO_FILE*) throw();
extern int _IO_ftrylockfile(_IO_FILE*) throw();
extern int _IO_vfscanf(_IO_FILE* __restrict,
                       const char* __restrict,
                       __gnuc_va_list,
                       int* __restrict);
extern int _IO_vfprintf(_IO_FILE* __restrict,
                        const char* __restrict,
                        __gnuc_va_list);
extern __ssize_t _IO_padn(_IO_FILE*, int, __ssize_t);
extern size_t _IO_sgetn(_IO_FILE*, void*, size_t);

extern __off64_t _IO_seekoff(_IO_FILE*, __off64_t, int, int);
extern __off64_t _IO_seekpos(_IO_FILE*, __off64_t, int);

extern void _IO_free_backup_area(_IO_FILE*) throw();
}

typedef __gnuc_va_list va_list;
typedef _G_fpos_t fpos_t;

typedef _G_fpos64_t fpos64_t;

extern struct _IO_FILE* stdin;
extern struct _IO_FILE* stdout;
extern struct _IO_FILE* stderr;

extern int remove(const char* __filename) throw();

extern int rename(const char* __old, const char* __new) throw();

extern int renameat(int __oldfd,
                    const char* __old,
                    int __newfd,
                    const char* __new) throw();

extern FILE* tmpfile(void);
extern FILE* tmpfile64(void);

extern char* tmpnam(char* __s) throw();

extern char* tmpnam_r(char* __s) throw();
extern char* tempnam(const char* __dir, const char* __pfx) throw()
    __attribute__((__malloc__));

extern int fclose(FILE* __stream);

extern int fflush(FILE* __stream);
extern int fflush_unlocked(FILE* __stream);
extern int fcloseall(void);
extern FILE* fopen(const char* __restrict __filename,
                   const char* __restrict __modes);

extern FILE* freopen(const char* __restrict __filename,
                     const char* __restrict __modes,
                     FILE* __restrict __stream);
extern FILE* fopen64(const char* __restrict __filename,
                     const char* __restrict __modes);
extern FILE* freopen64(const char* __restrict __filename,
                       const char* __restrict __modes,
                       FILE* __restrict __stream);

extern FILE* fdopen(int __fd, const char* __modes) throw();

extern FILE* fopencookie(void* __restrict __magic_cookie,
                         const char* __restrict __modes,
                         _IO_cookie_io_functions_t __io_funcs) throw();

extern FILE* fmemopen(void* __s, size_t __len, const char* __modes) throw();

extern FILE* open_memstream(char** __bufloc, size_t* __sizeloc) throw();

extern void setbuf(FILE* __restrict __stream, char* __restrict __buf) throw();

extern int setvbuf(FILE* __restrict __stream,
                   char* __restrict __buf,
                   int __modes,
                   size_t __n) throw();

extern void setbuffer(FILE* __restrict __stream,
                      char* __restrict __buf,
                      size_t __size) throw();

extern void setlinebuf(FILE* __stream) throw();

extern int fprintf(FILE* __restrict __stream,
                   const char* __restrict __format,
                   ...);

extern int printf(const char* __restrict __format, ...);

extern int sprintf(char* __restrict __s,
                   const char* __restrict __format,
                   ...) throw();

extern int vfprintf(FILE* __restrict __s,
                    const char* __restrict __format,
                    __gnuc_va_list __arg);

extern int vprintf(const char* __restrict __format, __gnuc_va_list __arg);

extern int vsprintf(char* __restrict __s,
                    const char* __restrict __format,
                    __gnuc_va_list __arg) throw();

extern int snprintf(char* __restrict __s,
                    size_t __maxlen,
                    const char* __restrict __format,
                    ...) throw() __attribute__((__format__(__printf__, 3, 4)));

extern int vsnprintf(char* __restrict __s,
                     size_t __maxlen,
                     const char* __restrict __format,
                     __gnuc_va_list __arg) throw()
    __attribute__((__format__(__printf__, 3, 0)));

extern int vasprintf(char** __restrict __ptr,
                     const char* __restrict __f,
                     __gnuc_va_list __arg) throw()
    __attribute__((__format__(__printf__, 2, 0)));
extern int __asprintf(char** __restrict __ptr,
                      const char* __restrict __fmt,
                      ...) throw()
    __attribute__((__format__(__printf__, 2, 3)));
extern int asprintf(char** __restrict __ptr,
                    const char* __restrict __fmt,
                    ...) throw() __attribute__((__format__(__printf__, 2, 3)));

extern int vdprintf(int __fd,
                    const char* __restrict __fmt,
                    __gnuc_va_list __arg)
    __attribute__((__format__(__printf__, 2, 0)));
extern int dprintf(int __fd, const char* __restrict __fmt, ...)
    __attribute__((__format__(__printf__, 2, 3)));

extern int fscanf(FILE* __restrict __stream,
                  const char* __restrict __format,
                  ...);

extern int scanf(const char* __restrict __format, ...);

extern int sscanf(const char* __restrict __s,
                  const char* __restrict __format,
                  ...) throw();
extern int vfscanf(FILE* __restrict __s,
                   const char* __restrict __format,
                   __gnuc_va_list __arg)
    __attribute__((__format__(__scanf__, 2, 0)));

extern int vscanf(const char* __restrict __format, __gnuc_va_list __arg)
    __attribute__((__format__(__scanf__, 1, 0)));

extern int vsscanf(const char* __restrict __s,
                   const char* __restrict __format,
                   __gnuc_va_list __arg) throw()
    __attribute__((__format__(__scanf__, 2, 0)));
extern int fgetc(FILE* __stream);
extern int getc(FILE* __stream);

extern int getchar(void);
extern int getc_unlocked(FILE* __stream);
extern int getchar_unlocked(void);
extern int fgetc_unlocked(FILE* __stream);
extern int fputc(int __c, FILE* __stream);
extern int putc(int __c, FILE* __stream);

extern int putchar(int __c);
extern int fputc_unlocked(int __c, FILE* __stream);

extern int putc_unlocked(int __c, FILE* __stream);
extern int putchar_unlocked(int __c);

extern int getw(FILE* __stream);

extern int putw(int __w, FILE* __stream);

extern char* fgets(char* __restrict __s, int __n, FILE* __restrict __stream);
extern char* fgets_unlocked(char* __restrict __s,
                            int __n,
                            FILE* __restrict __stream);
extern __ssize_t __getdelim(char** __restrict __lineptr,
                            size_t* __restrict __n,
                            int __delimiter,
                            FILE* __restrict __stream);
extern __ssize_t getdelim(char** __restrict __lineptr,
                          size_t* __restrict __n,
                          int __delimiter,
                          FILE* __restrict __stream);

extern __ssize_t getline(char** __restrict __lineptr,
                         size_t* __restrict __n,
                         FILE* __restrict __stream);

extern int fputs(const char* __restrict __s, FILE* __restrict __stream);

extern int puts(const char* __s);

extern int ungetc(int __c, FILE* __stream);

extern size_t fread(void* __restrict __ptr,
                    size_t __size,
                    size_t __n,
                    FILE* __restrict __stream);

extern size_t fwrite(const void* __restrict __ptr,
                     size_t __size,
                     size_t __n,
                     FILE* __restrict __s);
extern int fputs_unlocked(const char* __restrict __s,
                          FILE* __restrict __stream);
extern size_t fread_unlocked(void* __restrict __ptr,
                             size_t __size,
                             size_t __n,
                             FILE* __restrict __stream);
extern size_t fwrite_unlocked(const void* __restrict __ptr,
                              size_t __size,
                              size_t __n,
                              FILE* __restrict __stream);

extern int fseek(FILE* __stream, long int __off, int __whence);

extern long int ftell(FILE* __stream);

extern void rewind(FILE* __stream);
extern int fseeko(FILE* __stream, __off_t __off, int __whence);

extern __off_t ftello(FILE* __stream);
extern int fgetpos(FILE* __restrict __stream, fpos_t* __restrict __pos);

extern int fsetpos(FILE* __stream, const fpos_t* __pos);
extern int fseeko64(FILE* __stream, __off64_t __off, int __whence);
extern __off64_t ftello64(FILE* __stream);
extern int fgetpos64(FILE* __restrict __stream, fpos64_t* __restrict __pos);
extern int fsetpos64(FILE* __stream, const fpos64_t* __pos);

extern void clearerr(FILE* __stream) throw();

extern int feof(FILE* __stream) throw();

extern int ferror(FILE* __stream) throw();

extern void clearerr_unlocked(FILE* __stream) throw();
extern int feof_unlocked(FILE* __stream) throw();
extern int ferror_unlocked(FILE* __stream) throw();

extern void perror(const char* __s);

extern int sys_nerr;
extern const char* const sys_errlist[];

extern int _sys_nerr;
extern const char* const _sys_errlist[];

extern int fileno(FILE* __stream) throw();

extern int fileno_unlocked(FILE* __stream) throw();
extern FILE* popen(const char* __command, const char* __modes);

extern int pclose(FILE* __stream);

extern char* ctermid(char* __s) throw();

extern char* cuserid(char* __s);

struct obstack;

extern int obstack_printf(struct obstack* __restrict __obstack,
                          const char* __restrict __format,
                          ...) throw()
    __attribute__((__format__(__printf__, 2, 3)));
extern int obstack_vprintf(struct obstack* __restrict __obstack,
                           const char* __restrict __format,
                           __gnuc_va_list __args) throw()
    __attribute__((__format__(__printf__, 2, 0)));

extern void flockfile(FILE* __stream) throw();

extern int ftrylockfile(FILE* __stream) throw();

extern void funlockfile(FILE* __stream) throw();
}
namespace std {
using ::FILE;
using ::fpos_t;

using ::clearerr;
using ::fclose;
using ::feof;
using ::ferror;
using ::fflush;
using ::fgetc;
using ::fgetpos;
using ::fgets;
using ::fopen;
using ::fprintf;
using ::fputc;
using ::fputs;
using ::fread;
using ::freopen;
using ::fscanf;
using ::fseek;
using ::fsetpos;
using ::ftell;
using ::fwrite;
using ::getc;
using ::getchar;

using ::perror;
using ::printf;
using ::putc;
using ::putchar;
using ::puts;
using ::remove;
using ::rename;
using ::rewind;
using ::scanf;
using ::setbuf;
using ::setvbuf;
using ::sprintf;
using ::sscanf;
using ::tmpfile;

using ::tmpnam;

using ::ungetc;
using ::vfprintf;
using ::vprintf;
using ::vsprintf;
}  // namespace std
namespace __gnu_cxx {
using ::snprintf;
using ::vfscanf;
using ::vscanf;
using ::vsnprintf;
using ::vsscanf;

}  // namespace __gnu_cxx

namespace std {
using ::__gnu_cxx::snprintf;
using ::__gnu_cxx::vfscanf;
using ::__gnu_cxx::vscanf;
using ::__gnu_cxx::vsnprintf;
using ::__gnu_cxx::vsscanf;
}  // namespace std

extern "C" {

extern int* __errno_location(void) throw() __attribute__((__const__));

extern char* program_invocation_name;
extern char* program_invocation_short_name;

typedef int error_t;
}

namespace __gnu_cxx __attribute__((__visibility__("default"))) {

  template <typename _TRet, typename _Ret = _TRet, typename _CharT,
            typename... _Base>
  _Ret __stoa(_TRet(*__convf)(const _CharT*, _CharT**, _Base...),
              const char* __name, const _CharT* __str, std::size_t* __idx,
              _Base... __base) {
    _Ret __ret;

    _CharT* __endptr;

    struct _Save_errno {
      _Save_errno() : _M_errno((*__errno_location())) {
        (*__errno_location()) = 0;
      }
      ~_Save_errno() {
        if ((*__errno_location()) == 0)
          (*__errno_location()) = _M_errno;
      }
      int _M_errno;
    } const __save_errno;

    struct _Range_chk {
      static bool _S_chk(_TRet, std::false_type) { return false; }

      static bool _S_chk(_TRet __val, std::true_type) {
        return __val < _TRet(__numeric_traits<int>::__min) ||
               __val > _TRet(__numeric_traits<int>::__max);
      }
    };

    const _TRet __tmp = __convf(__str, &__endptr, __base...);

    if (__endptr == __str)
      std::__throw_invalid_argument(__name);
    else if ((*__errno_location()) == 34 ||
             _Range_chk::_S_chk(__tmp, std::is_same<_Ret, int>{}))
      std::__throw_out_of_range(__name);
    else
      __ret = __tmp;

    if (__idx)
      *__idx = __endptr - __str;

    return __ret;
  }

  template <typename _String, typename _CharT = typename _String::value_type>
  _String __to_xstring(
      int (*__convf)(_CharT*, std::size_t, const _CharT*, __builtin_va_list),
      std::size_t __n, const _CharT* __fmt, ...) {
    _CharT* __s = static_cast<_CharT*>(__builtin_alloca(sizeof(_CharT) * __n));

    __builtin_va_list __args;
    __builtin_va_start(__args, __fmt);

    const int __len = __convf(__s, __n, __fmt, __args);

    __builtin_va_end(__args);

    return _String(__s, __s + __len);
  }

}  // namespace __gnu_cxx__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  namespace __cxx11 {

  inline int stoi(const string& __str, size_t* __idx = 0, int __base = 10) {
    return __gnu_cxx::__stoa<long, int>(&std::strtol, "stoi", __str.c_str(),
                                        __idx, __base);
  }

  inline long stol(const string& __str, size_t* __idx = 0, int __base = 10) {
    return __gnu_cxx::__stoa(&std::strtol, "stol", __str.c_str(), __idx,
                             __base);
  }

  inline unsigned long stoul(const string& __str,
                             size_t* __idx = 0,
                             int __base = 10) {
    return __gnu_cxx::__stoa(&std::strtoul, "stoul", __str.c_str(), __idx,
                             __base);
  }

  inline long long stoll(const string& __str,
                         size_t* __idx = 0,
                         int __base = 10) {
    return __gnu_cxx::__stoa(&std::strtoll, "stoll", __str.c_str(), __idx,
                             __base);
  }

  inline unsigned long long stoull(const string& __str,
                                   size_t* __idx = 0,
                                   int __base = 10) {
    return __gnu_cxx::__stoa(&std::strtoull, "stoull", __str.c_str(), __idx,
                             __base);
  }

  inline float stof(const string& __str, size_t* __idx = 0) {
    return __gnu_cxx::__stoa(&std::strtof, "stof", __str.c_str(), __idx);
  }

  inline double stod(const string& __str, size_t* __idx = 0) {
    return __gnu_cxx::__stoa(&std::strtod, "stod", __str.c_str(), __idx);
  }

  inline long double stold(const string& __str, size_t* __idx = 0) {
    return __gnu_cxx::__stoa(&std::strtold, "stold", __str.c_str(), __idx);
  }

  inline string to_string(int __val) {
    return __gnu_cxx::__to_xstring<string>(&std::vsnprintf, 4 * sizeof(int),
                                           "%d", __val);
  }

  inline string to_string(unsigned __val) {
    return __gnu_cxx::__to_xstring<string>(&std::vsnprintf,
                                           4 * sizeof(unsigned), "%u", __val);
  }

  inline string to_string(long __val) {
    return __gnu_cxx::__to_xstring<string>(&std::vsnprintf, 4 * sizeof(long),
                                           "%ld", __val);
  }

  inline string to_string(unsigned long __val) {
    return __gnu_cxx::__to_xstring<string>(
        &std::vsnprintf, 4 * sizeof(unsigned long), "%lu", __val);
  }

  inline string to_string(long long __val) {
    return __gnu_cxx::__to_xstring<string>(
        &std::vsnprintf, 4 * sizeof(long long), "%lld", __val);
  }

  inline string to_string(unsigned long long __val) {
    return __gnu_cxx::__to_xstring<string>(
        &std::vsnprintf, 4 * sizeof(unsigned long long), "%llu", __val);
  }

  inline string to_string(float __val) {
    const int __n = __gnu_cxx::__numeric_traits<float>::__max_exponent10 + 20;
    return __gnu_cxx::__to_xstring<string>(&std::vsnprintf, __n, "%f", __val);
  }

  inline string to_string(double __val) {
    const int __n = __gnu_cxx::__numeric_traits<double>::__max_exponent10 + 20;
    return __gnu_cxx::__to_xstring<string>(&std::vsnprintf, __n, "%f", __val);
  }

  inline string to_string(long double __val) {
    const int __n =
        __gnu_cxx::__numeric_traits<long double>::__max_exponent10 + 20;
    return __gnu_cxx::__to_xstring<string>(&std::vsnprintf, __n, "%Lf", __val);
  }

  inline int stoi(const wstring& __str, size_t* __idx = 0, int __base = 10) {
    return __gnu_cxx::__stoa<long, int>(&std::wcstol, "stoi", __str.c_str(),
                                        __idx, __base);
  }

  inline long stol(const wstring& __str, size_t* __idx = 0, int __base = 10) {
    return __gnu_cxx::__stoa(&std::wcstol, "stol", __str.c_str(), __idx,
                             __base);
  }

  inline unsigned long stoul(const wstring& __str,
                             size_t* __idx = 0,
                             int __base = 10) {
    return __gnu_cxx::__stoa(&std::wcstoul, "stoul", __str.c_str(), __idx,
                             __base);
  }

  inline long long stoll(const wstring& __str,
                         size_t* __idx = 0,
                         int __base = 10) {
    return __gnu_cxx::__stoa(&std::wcstoll, "stoll", __str.c_str(), __idx,
                             __base);
  }

  inline unsigned long long stoull(const wstring& __str,
                                   size_t* __idx = 0,
                                   int __base = 10) {
    return __gnu_cxx::__stoa(&std::wcstoull, "stoull", __str.c_str(), __idx,
                             __base);
  }

  inline float stof(const wstring& __str, size_t* __idx = 0) {
    return __gnu_cxx::__stoa(&std::wcstof, "stof", __str.c_str(), __idx);
  }

  inline double stod(const wstring& __str, size_t* __idx = 0) {
    return __gnu_cxx::__stoa(&std::wcstod, "stod", __str.c_str(), __idx);
  }

  inline long double stold(const wstring& __str, size_t* __idx = 0) {
    return __gnu_cxx::__stoa(&std::wcstold, "stold", __str.c_str(), __idx);
  }

  inline wstring to_wstring(int __val) {
    return __gnu_cxx::__to_xstring<wstring>(&std::vswprintf, 4 * sizeof(int),
                                            L"%d", __val);
  }

  inline wstring to_wstring(unsigned __val) {
    return __gnu_cxx::__to_xstring<wstring>(&std::vswprintf,
                                            4 * sizeof(unsigned), L"%u", __val);
  }

  inline wstring to_wstring(long __val) {
    return __gnu_cxx::__to_xstring<wstring>(&std::vswprintf, 4 * sizeof(long),
                                            L"%ld", __val);
  }

  inline wstring to_wstring(unsigned long __val) {
    return __gnu_cxx::__to_xstring<wstring>(
        &std::vswprintf, 4 * sizeof(unsigned long), L"%lu", __val);
  }

  inline wstring to_wstring(long long __val) {
    return __gnu_cxx::__to_xstring<wstring>(
        &std::vswprintf, 4 * sizeof(long long), L"%lld", __val);
  }

  inline wstring to_wstring(unsigned long long __val) {
    return __gnu_cxx::__to_xstring<wstring>(
        &std::vswprintf, 4 * sizeof(unsigned long long), L"%llu", __val);
  }

  inline wstring to_wstring(float __val) {
    const int __n = __gnu_cxx::__numeric_traits<float>::__max_exponent10 + 20;
    return __gnu_cxx::__to_xstring<wstring>(&std::vswprintf, __n, L"%f", __val);
  }

  inline wstring to_wstring(double __val) {
    const int __n = __gnu_cxx::__numeric_traits<double>::__max_exponent10 + 20;
    return __gnu_cxx::__to_xstring<wstring>(&std::vswprintf, __n, L"%f", __val);
  }

  inline wstring to_wstring(long double __val) {
    const int __n =
        __gnu_cxx::__numeric_traits<long double>::__max_exponent10 + 20;
    return __gnu_cxx::__to_xstring<wstring>(&std::vswprintf, __n, L"%Lf",
                                            __val);
  }

  }  // namespace __cxx11

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <>
  struct hash<string> : public __hash_base<size_t, string> {
    size_t operator()(const string& __s) const noexcept {
      return std::_Hash_impl::hash(__s.data(), __s.length());
    }
  };

  template <>
  struct __is_fast_hash<hash<string>> : std::false_type {};

  template <>
  struct hash<wstring> : public __hash_base<size_t, wstring> {
    size_t operator()(const wstring& __s) const noexcept {
      return std::_Hash_impl::hash(__s.data(), __s.length() * sizeof(wchar_t));
    }
  };

  template <>
  struct __is_fast_hash<hash<wstring>> : std::false_type {};

  template <>
  struct hash<u16string> : public __hash_base<size_t, u16string> {
    size_t operator()(const u16string& __s) const noexcept {
      return std::_Hash_impl::hash(__s.data(), __s.length() * sizeof(char16_t));
    }
  };

  template <>
  struct __is_fast_hash<hash<u16string>> : std::false_type {};

  template <>
  struct hash<u32string> : public __hash_base<size_t, u32string> {
    size_t operator()(const u32string& __s) const noexcept {
      return std::_Hash_impl::hash(__s.data(), __s.length() * sizeof(char32_t));
    }
  };

  template <>
  struct __is_fast_hash<hash<u32string>> : std::false_type {};

  inline namespace literals {
  inline namespace string_literals {
  __attribute((__abi_tag__("cxx11"))) inline basic_string<char> operator""s(
      const char* __str,
      size_t __len) {
    return basic_string<char>{__str, __len};
  }

  __attribute((__abi_tag__("cxx11"))) inline basic_string<wchar_t> operator""s(
      const wchar_t* __str,
      size_t __len) {
    return basic_string<wchar_t>{__str, __len};
  }

  __attribute((__abi_tag__("cxx11"))) inline basic_string<char16_t> operator""s(
      const char16_t* __str,
      size_t __len) {
    return basic_string<char16_t>{__str, __len};
  }

  __attribute((__abi_tag__("cxx11"))) inline basic_string<char32_t> operator""s(
      const char32_t* __str,
      size_t __len) {
    return basic_string<char32_t>{__str, __len};
  }

  }  // namespace string_literals
  }  // namespace literals

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <typename _CharT, typename _Traits, typename _Alloc>
  const typename basic_string<_CharT, _Traits, _Alloc>::size_type
      basic_string<_CharT, _Traits, _Alloc>::npos;

  template <typename _CharT, typename _Traits, typename _Alloc>
  void basic_string<_CharT, _Traits, _Alloc>::swap(basic_string &
                                                   __s) noexcept {
    if (this == &__s)
      return;

    _Alloc_traits::_S_on_swap(_M_get_allocator(), __s._M_get_allocator());

    if (_M_is_local())
      if (__s._M_is_local()) {
        if (length() && __s.length()) {
          _CharT __tmp_data[_S_local_capacity + 1];
          traits_type::copy(__tmp_data, __s._M_local_buf,
                            _S_local_capacity + 1);
          traits_type::copy(__s._M_local_buf, _M_local_buf,
                            _S_local_capacity + 1);
          traits_type::copy(_M_local_buf, __tmp_data, _S_local_capacity + 1);
        } else if (__s.length()) {
          traits_type::copy(_M_local_buf, __s._M_local_buf,
                            _S_local_capacity + 1);
          _M_length(__s.length());
          __s._M_set_length(0);
          return;
        } else if (length()) {
          traits_type::copy(__s._M_local_buf, _M_local_buf,
                            _S_local_capacity + 1);
          __s._M_length(length());
          _M_set_length(0);
          return;
        }
      } else {
        const size_type __tmp_capacity = __s._M_allocated_capacity;
        traits_type::copy(__s._M_local_buf, _M_local_buf,
                          _S_local_capacity + 1);
        _M_data(__s._M_data());
        __s._M_data(__s._M_local_buf);
        _M_capacity(__tmp_capacity);
      }
    else {
      const size_type __tmp_capacity = _M_allocated_capacity;
      if (__s._M_is_local()) {
        traits_type::copy(_M_local_buf, __s._M_local_buf,
                          _S_local_capacity + 1);
        __s._M_data(_M_data());
        _M_data(_M_local_buf);
      } else {
        pointer __tmp_ptr = _M_data();
        _M_data(__s._M_data());
        __s._M_data(__tmp_ptr);
        _M_capacity(__s._M_allocated_capacity);
      }
      __s._M_capacity(__tmp_capacity);
    }

    const size_type __tmp_length = length();
    _M_length(__s.length());
    __s._M_length(__tmp_length);
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  typename basic_string<_CharT, _Traits, _Alloc>::pointer
  basic_string<_CharT, _Traits, _Alloc>::_M_create(size_type & __capacity,
                                                   size_type __old_capacity) {
    if (__capacity > max_size())
      std::__throw_length_error(("basic_string::_M_create"));

    if (__capacity > __old_capacity && __capacity < 2 * __old_capacity) {
      __capacity = 2 * __old_capacity;

      if (__capacity > max_size())
        __capacity = max_size();
    }

    return _Alloc_traits::allocate(_M_get_allocator(), __capacity + 1);
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  template <typename _InIterator>
  void basic_string<_CharT, _Traits, _Alloc>::_M_construct(
      _InIterator __beg, _InIterator __end, std::input_iterator_tag) {
    size_type __len = 0;
    size_type __capacity = size_type(_S_local_capacity);

    while (__beg != __end && __len < __capacity) {
      _M_data()[__len++] = *__beg;
      ++__beg;
    }

    try {
      while (__beg != __end) {
        if (__len == __capacity) {
          __capacity = __len + 1;
          pointer __another = _M_create(__capacity, __len);
          this->_S_copy(__another, _M_data(), __len);
          _M_dispose();
          _M_data(__another);
          _M_capacity(__capacity);
        }
        _M_data()[__len++] = *__beg;
        ++__beg;
      }
    } catch (...) {
      _M_dispose();
      throw;
    }

    _M_set_length(__len);
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  template <typename _InIterator>
  void basic_string<_CharT, _Traits, _Alloc>::_M_construct(
      _InIterator __beg, _InIterator __end, std::forward_iterator_tag) {
    if (__gnu_cxx::__is_null_pointer(__beg) && __beg != __end)
      std::__throw_logic_error(
          ("basic_string::"
           "_M_construct null not valid"));

    size_type __dnew = static_cast<size_type>(std::distance(__beg, __end));

    if (__dnew > size_type(_S_local_capacity)) {
      _M_data(_M_create(__dnew, size_type(0)));
      _M_capacity(__dnew);
    }

    try {
      this->_S_copy_chars(_M_data(), __beg, __end);
    } catch (...) {
      _M_dispose();
      throw;
    }

    _M_set_length(__dnew);
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  void basic_string<_CharT, _Traits, _Alloc>::_M_construct(size_type __n,
                                                           _CharT __c) {
    if (__n > size_type(_S_local_capacity)) {
      _M_data(_M_create(__n, size_type(0)));
      _M_capacity(__n);
    }

    if (__n)
      this->_S_assign(_M_data(), __n, __c);

    _M_set_length(__n);
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  void basic_string<_CharT, _Traits, _Alloc>::_M_assign(
      const basic_string& __str) {
    if (this != &__str) {
      const size_type __rsize = __str.length();
      const size_type __capacity = capacity();

      if (__rsize > __capacity) {
        size_type __new_capacity = __rsize;
        pointer __tmp = _M_create(__new_capacity, __capacity);
        _M_dispose();
        _M_data(__tmp);
        _M_capacity(__new_capacity);
      }

      if (__rsize)
        this->_S_copy(_M_data(), __str._M_data(), __rsize);

      _M_set_length(__rsize);
    }
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  void basic_string<_CharT, _Traits, _Alloc>::reserve(size_type __res) {
    if (__res < length())
      __res = length();

    const size_type __capacity = capacity();
    if (__res != __capacity) {
      if (__res > __capacity || __res > size_type(_S_local_capacity)) {
        pointer __tmp = _M_create(__res, __capacity);
        this->_S_copy(__tmp, _M_data(), length() + 1);
        _M_dispose();
        _M_data(__tmp);
        _M_capacity(__res);
      } else if (!_M_is_local()) {
        this->_S_copy(_M_local_data(), _M_data(), length() + 1);
        _M_destroy(__capacity);
        _M_data(_M_local_data());
      }
    }
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  void basic_string<_CharT, _Traits, _Alloc>::_M_mutate(
      size_type __pos, size_type __len1, const _CharT* __s, size_type __len2) {
    const size_type __how_much = length() - __pos - __len1;

    size_type __new_capacity = length() + __len2 - __len1;
    pointer __r = _M_create(__new_capacity, capacity());

    if (__pos)
      this->_S_copy(__r, _M_data(), __pos);
    if (__s && __len2)
      this->_S_copy(__r + __pos, __s, __len2);
    if (__how_much)
      this->_S_copy(__r + __pos + __len2, _M_data() + __pos + __len1,
                    __how_much);

    _M_dispose();
    _M_data(__r);
    _M_capacity(__new_capacity);
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  void basic_string<_CharT, _Traits, _Alloc>::_M_erase(size_type __pos,
                                                       size_type __n) {
    const size_type __how_much = length() - __pos - __n;

    if (__how_much && __n)
      this->_S_move(_M_data() + __pos, _M_data() + __pos + __n, __how_much);

    _M_set_length(length() - __n);
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  void basic_string<_CharT, _Traits, _Alloc>::resize(size_type __n,
                                                     _CharT __c) {
    const size_type __size = this->size();
    if (__size < __n)
      this->append(__n - __size, __c);
    else if (__n < __size)
      this->_M_set_length(__n);
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  basic_string<_CharT, _Traits, _Alloc>&
  basic_string<_CharT, _Traits, _Alloc>::_M_append(const _CharT* __s,
                                                   size_type __n) {
    const size_type __len = __n + this->size();

    if (__len <= this->capacity()) {
      if (__n)
        this->_S_copy(this->_M_data() + this->size(), __s, __n);
    } else
      this->_M_mutate(this->size(), size_type(0), __s, __n);

    this->_M_set_length(__len);
    return *this;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  template <typename _InputIterator>
  basic_string<_CharT, _Traits, _Alloc>&
  basic_string<_CharT, _Traits, _Alloc>::_M_replace_dispatch(
      const_iterator __i1, const_iterator __i2, _InputIterator __k1,
      _InputIterator __k2, std::__false_type) {
    const basic_string __s(__k1, __k2);
    const size_type __n1 = __i2 - __i1;
    return _M_replace(__i1 - begin(), __n1, __s._M_data(), __s.size());
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  basic_string<_CharT, _Traits, _Alloc>&
  basic_string<_CharT, _Traits, _Alloc>::_M_replace_aux(
      size_type __pos1, size_type __n1, size_type __n2, _CharT __c) {
    _M_check_length(__n1, __n2, "basic_string::_M_replace_aux");

    const size_type __old_size = this->size();
    const size_type __new_size = __old_size + __n2 - __n1;

    if (__new_size <= this->capacity()) {
      pointer __p = this->_M_data() + __pos1;

      const size_type __how_much = __old_size - __pos1 - __n1;
      if (__how_much && __n1 != __n2)
        this->_S_move(__p + __n2, __p + __n1, __how_much);
    } else
      this->_M_mutate(__pos1, __n1, 0, __n2);

    if (__n2)
      this->_S_assign(this->_M_data() + __pos1, __n2, __c);

    this->_M_set_length(__new_size);
    return *this;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  basic_string<_CharT, _Traits, _Alloc>&
  basic_string<_CharT, _Traits, _Alloc>::_M_replace(
      size_type __pos, size_type __len1, const _CharT* __s,
      const size_type __len2) {
    _M_check_length(__len1, __len2, "basic_string::_M_replace");

    const size_type __old_size = this->size();
    const size_type __new_size = __old_size + __len2 - __len1;

    if (__new_size <= this->capacity()) {
      pointer __p = this->_M_data() + __pos;

      const size_type __how_much = __old_size - __pos - __len1;
      if (_M_disjunct(__s)) {
        if (__how_much && __len1 != __len2)
          this->_S_move(__p + __len2, __p + __len1, __how_much);
        if (__len2)
          this->_S_copy(__p, __s, __len2);
      } else {
        if (__len2 && __len2 <= __len1)
          this->_S_move(__p, __s, __len2);
        if (__how_much && __len1 != __len2)
          this->_S_move(__p + __len2, __p + __len1, __how_much);
        if (__len2 > __len1) {
          if (__s + __len2 <= __p + __len1)
            this->_S_move(__p, __s, __len2);
          else if (__s >= __p + __len1)
            this->_S_copy(__p, __s + __len2 - __len1, __len2);
          else {
            const size_type __nleft = (__p + __len1) - __s;
            this->_S_move(__p, __s, __nleft);
            this->_S_copy(__p + __nleft, __p + __len2, __len2 - __nleft);
          }
        }
      }
    } else
      this->_M_mutate(__pos, __len1, __s, __len2);

    this->_M_set_length(__new_size);
    return *this;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  typename basic_string<_CharT, _Traits, _Alloc>::size_type
  basic_string<_CharT, _Traits, _Alloc>::copy(_CharT * __s, size_type __n,
                                              size_type __pos) const {
    _M_check(__pos, "basic_string::copy");
    __n = _M_limit(__pos, __n);
    ;
    if (__n)
      _S_copy(__s, _M_data() + __pos, __n);

    return __n;
  }
  template <typename _CharT, typename _Traits, typename _Alloc>
  basic_string<_CharT, _Traits, _Alloc> operator+(
      const _CharT* __lhs, const basic_string<_CharT, _Traits, _Alloc>& __rhs) {
    ;
    typedef basic_string<_CharT, _Traits, _Alloc> __string_type;
    typedef typename __string_type::size_type __size_type;
    const __size_type __len = _Traits::length(__lhs);
    __string_type __str;
    __str.reserve(__len + __rhs.size());
    __str.append(__lhs, __len);
    __str.append(__rhs);
    return __str;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  basic_string<_CharT, _Traits, _Alloc> operator+(
      _CharT __lhs, const basic_string<_CharT, _Traits, _Alloc>& __rhs) {
    typedef basic_string<_CharT, _Traits, _Alloc> __string_type;
    typedef typename __string_type::size_type __size_type;
    __string_type __str;
    const __size_type __len = __rhs.size();
    __str.reserve(__len + 1);
    __str.append(__size_type(1), __lhs);
    __str.append(__rhs);
    return __str;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  typename basic_string<_CharT, _Traits, _Alloc>::size_type
  basic_string<_CharT, _Traits, _Alloc>::find(
      const _CharT* __s, size_type __pos, size_type __n) const noexcept {
    ;
    const size_type __size = this->size();

    if (__n == 0)
      return __pos <= __size ? __pos : npos;
    if (__pos >= __size)
      return npos;

    const _CharT __elem0 = __s[0];
    const _CharT* const __data = data();
    const _CharT* __first = __data + __pos;
    const _CharT* const __last = __data + __size;
    size_type __len = __size - __pos;

    while (__len >= __n) {
      __first = traits_type::find(__first, __len - __n + 1, __elem0);
      if (!__first)
        return npos;

      if (traits_type::compare(__first, __s, __n) == 0)
        return __first - __data;
      __len = __last - ++__first;
    }
    return npos;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  typename basic_string<_CharT, _Traits, _Alloc>::size_type
  basic_string<_CharT, _Traits, _Alloc>::find(_CharT __c, size_type __pos)
      const noexcept {
    size_type __ret = npos;
    const size_type __size = this->size();
    if (__pos < __size) {
      const _CharT* __data = _M_data();
      const size_type __n = __size - __pos;
      const _CharT* __p = traits_type::find(__data + __pos, __n, __c);
      if (__p)
        __ret = __p - __data;
    }
    return __ret;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  typename basic_string<_CharT, _Traits, _Alloc>::size_type
  basic_string<_CharT, _Traits, _Alloc>::rfind(
      const _CharT* __s, size_type __pos, size_type __n) const noexcept {
    ;
    const size_type __size = this->size();
    if (__n <= __size) {
      __pos = std::min(size_type(__size - __n), __pos);
      const _CharT* __data = _M_data();
      do {
        if (traits_type::compare(__data + __pos, __s, __n) == 0)
          return __pos;
      } while (__pos-- > 0);
    }
    return npos;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  typename basic_string<_CharT, _Traits, _Alloc>::size_type
  basic_string<_CharT, _Traits, _Alloc>::rfind(_CharT __c, size_type __pos)
      const noexcept {
    size_type __size = this->size();
    if (__size) {
      if (--__size > __pos)
        __size = __pos;
      for (++__size; __size-- > 0;)
        if (traits_type::eq(_M_data()[__size], __c))
          return __size;
    }
    return npos;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  typename basic_string<_CharT, _Traits, _Alloc>::size_type
  basic_string<_CharT, _Traits, _Alloc>::find_first_of(
      const _CharT* __s, size_type __pos, size_type __n) const noexcept {
    ;
    for (; __n && __pos < this->size(); ++__pos) {
      const _CharT* __p = traits_type::find(__s, __n, _M_data()[__pos]);
      if (__p)
        return __pos;
    }
    return npos;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  typename basic_string<_CharT, _Traits, _Alloc>::size_type
  basic_string<_CharT, _Traits, _Alloc>::find_last_of(
      const _CharT* __s, size_type __pos, size_type __n) const noexcept {
    ;
    size_type __size = this->size();
    if (__size && __n) {
      if (--__size > __pos)
        __size = __pos;
      do {
        if (traits_type::find(__s, __n, _M_data()[__size]))
          return __size;
      } while (__size-- != 0);
    }
    return npos;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  typename basic_string<_CharT, _Traits, _Alloc>::size_type
  basic_string<_CharT, _Traits, _Alloc>::find_first_not_of(
      const _CharT* __s, size_type __pos, size_type __n) const noexcept {
    ;
    for (; __pos < this->size(); ++__pos)
      if (!traits_type::find(__s, __n, _M_data()[__pos]))
        return __pos;
    return npos;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  typename basic_string<_CharT, _Traits, _Alloc>::size_type
  basic_string<_CharT, _Traits, _Alloc>::find_first_not_of(
      _CharT __c, size_type __pos) const noexcept {
    for (; __pos < this->size(); ++__pos)
      if (!traits_type::eq(_M_data()[__pos], __c))
        return __pos;
    return npos;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  typename basic_string<_CharT, _Traits, _Alloc>::size_type
  basic_string<_CharT, _Traits, _Alloc>::find_last_not_of(
      const _CharT* __s, size_type __pos, size_type __n) const noexcept {
    ;
    size_type __size = this->size();
    if (__size) {
      if (--__size > __pos)
        __size = __pos;
      do {
        if (!traits_type::find(__s, __n, _M_data()[__size]))
          return __size;
      } while (__size--);
    }
    return npos;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  typename basic_string<_CharT, _Traits, _Alloc>::size_type
  basic_string<_CharT, _Traits, _Alloc>::find_last_not_of(
      _CharT __c, size_type __pos) const noexcept {
    size_type __size = this->size();
    if (__size) {
      if (--__size > __pos)
        __size = __pos;
      do {
        if (!traits_type::eq(_M_data()[__size], __c))
          return __size;
      } while (__size--);
    }
    return npos;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  int basic_string<_CharT, _Traits, _Alloc>::compare(
      size_type __pos, size_type __n, const basic_string& __str) const {
    _M_check(__pos, "basic_string::compare");
    __n = _M_limit(__pos, __n);
    const size_type __osize = __str.size();
    const size_type __len = std::min(__n, __osize);
    int __r = traits_type::compare(_M_data() + __pos, __str.data(), __len);
    if (!__r)
      __r = _S_compare(__n, __osize);
    return __r;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  int basic_string<_CharT, _Traits, _Alloc>::compare(
      size_type __pos1, size_type __n1, const basic_string& __str,
      size_type __pos2, size_type __n2) const {
    _M_check(__pos1, "basic_string::compare");
    __str._M_check(__pos2, "basic_string::compare");
    __n1 = _M_limit(__pos1, __n1);
    __n2 = __str._M_limit(__pos2, __n2);
    const size_type __len = std::min(__n1, __n2);
    int __r =
        traits_type::compare(_M_data() + __pos1, __str.data() + __pos2, __len);
    if (!__r)
      __r = _S_compare(__n1, __n2);
    return __r;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  int basic_string<_CharT, _Traits, _Alloc>::compare(const _CharT* __s)
      const noexcept {
    ;
    const size_type __size = this->size();
    const size_type __osize = traits_type::length(__s);
    const size_type __len = std::min(__size, __osize);
    int __r = traits_type::compare(_M_data(), __s, __len);
    if (!__r)
      __r = _S_compare(__size, __osize);
    return __r;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  int basic_string<_CharT, _Traits, _Alloc>::compare(
      size_type __pos, size_type __n1, const _CharT* __s) const {
    ;
    _M_check(__pos, "basic_string::compare");
    __n1 = _M_limit(__pos, __n1);
    const size_type __osize = traits_type::length(__s);
    const size_type __len = std::min(__n1, __osize);
    int __r = traits_type::compare(_M_data() + __pos, __s, __len);
    if (!__r)
      __r = _S_compare(__n1, __osize);
    return __r;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  int basic_string<_CharT, _Traits, _Alloc>::compare(
      size_type __pos, size_type __n1, const _CharT* __s, size_type __n2)
      const {
    ;
    _M_check(__pos, "basic_string::compare");
    __n1 = _M_limit(__pos, __n1);
    const size_type __len = std::min(__n1, __n2);
    int __r = traits_type::compare(_M_data() + __pos, __s, __len);
    if (!__r)
      __r = _S_compare(__n1, __n2);
    return __r;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  basic_istream<_CharT, _Traits>& operator>>(
      basic_istream<_CharT, _Traits>& __in,
      basic_string<_CharT, _Traits, _Alloc>& __str) {
    typedef basic_istream<_CharT, _Traits> __istream_type;
    typedef basic_string<_CharT, _Traits, _Alloc> __string_type;
    typedef typename __istream_type::ios_base __ios_base;
    typedef typename __istream_type::int_type __int_type;
    typedef typename __string_type::size_type __size_type;
    typedef ctype<_CharT> __ctype_type;
    typedef typename __ctype_type::ctype_base __ctype_base;

    __size_type __extracted = 0;
    typename __ios_base::iostate __err = __ios_base::goodbit;
    typename __istream_type::sentry __cerb(__in, false);
    if (__cerb) {
      try {
        __str.erase();
        _CharT __buf[128];
        __size_type __len = 0;
        const streamsize __w = __in.width();
        const __size_type __n =
            __w > 0 ? static_cast<__size_type>(__w) : __str.max_size();
        const __ctype_type& __ct = use_facet<__ctype_type>(__in.getloc());
        const __int_type __eof = _Traits::eof();
        __int_type __c = __in.rdbuf()->sgetc();

        while (__extracted < __n && !_Traits::eq_int_type(__c, __eof) &&
               !__ct.is(__ctype_base::space, _Traits::to_char_type(__c))) {
          if (__len == sizeof(__buf) / sizeof(_CharT)) {
            __str.append(__buf, sizeof(__buf) / sizeof(_CharT));
            __len = 0;
          }
          __buf[__len++] = _Traits::to_char_type(__c);
          ++__extracted;
          __c = __in.rdbuf()->snextc();
        }
        __str.append(__buf, __len);

        if (_Traits::eq_int_type(__c, __eof))
          __err |= __ios_base::eofbit;
        __in.width(0);
      } catch (__cxxabiv1::__forced_unwind&) {
        __in._M_setstate(__ios_base::badbit);
        throw;
      } catch (...) {
        __in._M_setstate(__ios_base::badbit);
      }
    }

    if (!__extracted)
      __err |= __ios_base::failbit;
    if (__err)
      __in.setstate(__err);
    return __in;
  }

  template <typename _CharT, typename _Traits, typename _Alloc>
  basic_istream<_CharT, _Traits>& getline(
      basic_istream<_CharT, _Traits> & __in,
      basic_string<_CharT, _Traits, _Alloc> & __str, _CharT __delim) {
    typedef basic_istream<_CharT, _Traits> __istream_type;
    typedef basic_string<_CharT, _Traits, _Alloc> __string_type;
    typedef typename __istream_type::ios_base __ios_base;
    typedef typename __istream_type::int_type __int_type;
    typedef typename __string_type::size_type __size_type;

    __size_type __extracted = 0;
    const __size_type __n = __str.max_size();
    typename __ios_base::iostate __err = __ios_base::goodbit;
    typename __istream_type::sentry __cerb(__in, true);
    if (__cerb) {
      try {
        __str.erase();
        const __int_type __idelim = _Traits::to_int_type(__delim);
        const __int_type __eof = _Traits::eof();
        __int_type __c = __in.rdbuf()->sgetc();

        while (__extracted < __n && !_Traits::eq_int_type(__c, __eof) &&
               !_Traits::eq_int_type(__c, __idelim)) {
          __str += _Traits::to_char_type(__c);
          ++__extracted;
          __c = __in.rdbuf()->snextc();
        }

        if (_Traits::eq_int_type(__c, __eof))
          __err |= __ios_base::eofbit;
        else if (_Traits::eq_int_type(__c, __idelim)) {
          ++__extracted;
          __in.rdbuf()->sbumpc();
        } else
          __err |= __ios_base::failbit;
      } catch (__cxxabiv1::__forced_unwind&) {
        __in._M_setstate(__ios_base::badbit);
        throw;
      } catch (...) {
        __in._M_setstate(__ios_base::badbit);
      }
    }
    if (!__extracted)
      __err |= __ios_base::failbit;
    if (__err)
      __in.setstate(__err);
    return __in;
  }

  extern template class basic_string<char>;
  extern template basic_istream<char>& operator>>(basic_istream<char>&,
                                                  string&);
  extern template basic_ostream<char>& operator<<(basic_ostream<char>&,
                                                  const string&);
  extern template basic_istream<char>& getline(basic_istream<char>&, string&,
                                               char);
  extern template basic_istream<char>& getline(basic_istream<char>&, string&);

  extern template class basic_string<wchar_t>;
  extern template basic_istream<wchar_t>& operator>>(basic_istream<wchar_t>&,
                                                     wstring&);
  extern template basic_ostream<wchar_t>& operator<<(basic_ostream<wchar_t>&,
                                                     const wstring&);
  extern template basic_istream<wchar_t>& getline(basic_istream<wchar_t>&,
                                                  wstring&, wchar_t);
  extern template basic_istream<wchar_t>& getline(basic_istream<wchar_t>&,
                                                  wstring&);

}  // namespace std__attribute__((__visibility__("default")))

extern "C" {

extern void* memcpy(void* __restrict __dest,
                    const void* __restrict __src,
                    size_t __n) throw() __attribute__((__nonnull__(1, 2)));

extern void* memmove(void* __dest, const void* __src, size_t __n) throw()
    __attribute__((__nonnull__(1, 2)));

extern void* memccpy(void* __restrict __dest,
                     const void* __restrict __src,
                     int __c,
                     size_t __n) throw() __attribute__((__nonnull__(1, 2)));

extern void* memset(void* __s, int __c, size_t __n) throw()
    __attribute__((__nonnull__(1)));

extern int memcmp(const void* __s1, const void* __s2, size_t __n) throw()
    __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));

extern "C++" {
extern void* memchr(void* __s, int __c, size_t __n) throw() __asm("memchr")
    __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern const void* memchr(const void* __s,
                          int __c,
                          size_t __n) throw() __asm("memchr")
    __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}
extern "C++" void* rawmemchr(void* __s, int __c) throw() __asm("rawmemchr")
    __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern "C++" const void* rawmemchr(const void* __s,
                                   int __c) throw() __asm("rawmemchr")
    __attribute__((__pure__)) __attribute__((__nonnull__(1)));

extern "C++" void* memrchr(void* __s,
                           int __c,
                           size_t __n) throw() __asm("memrchr")
    __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern "C++" const void* memrchr(const void* __s,
                                 int __c,
                                 size_t __n) throw() __asm("memrchr")
    __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern char* strcpy(char* __restrict __dest,
                    const char* __restrict __src) throw()
    __attribute__((__nonnull__(1, 2)));

extern char* strncpy(char* __restrict __dest,
                     const char* __restrict __src,
                     size_t __n) throw() __attribute__((__nonnull__(1, 2)));

extern char* strcat(char* __restrict __dest,
                    const char* __restrict __src) throw()
    __attribute__((__nonnull__(1, 2)));

extern char* strncat(char* __restrict __dest,
                     const char* __restrict __src,
                     size_t __n) throw() __attribute__((__nonnull__(1, 2)));

extern int strcmp(const char* __s1, const char* __s2) throw()
    __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));

extern int strncmp(const char* __s1, const char* __s2, size_t __n) throw()
    __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));

extern int strcoll(const char* __s1, const char* __s2) throw()
    __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));

extern size_t strxfrm(char* __restrict __dest,
                      const char* __restrict __src,
                      size_t __n) throw() __attribute__((__nonnull__(2)));

extern int strcoll_l(const char* __s1, const char* __s2, locale_t __l) throw()
    __attribute__((__pure__)) __attribute__((__nonnull__(1, 2, 3)));

extern size_t strxfrm_l(char* __dest,
                        const char* __src,
                        size_t __n,
                        locale_t __l) throw()
    __attribute__((__nonnull__(2, 4)));

extern char* strdup(const char* __s) throw() __attribute__((__malloc__))
__attribute__((__nonnull__(1)));

extern char* strndup(const char* __string, size_t __n) throw()
    __attribute__((__malloc__)) __attribute__((__nonnull__(1)));
extern "C++" {
extern char* strchr(char* __s, int __c) throw() __asm("strchr")
    __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern const char* strchr(const char* __s, int __c) throw() __asm("strchr")
    __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}

extern "C++" {
extern char* strrchr(char* __s, int __c) throw() __asm("strrchr")
    __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern const char* strrchr(const char* __s, int __c) throw() __asm("strrchr")
    __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}
extern "C++" char* strchrnul(char* __s, int __c) throw() __asm("strchrnul")
    __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern "C++" const char* strchrnul(const char* __s,
                                   int __c) throw() __asm("strchrnul")
    __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern size_t strcspn(const char* __s, const char* __reject) throw()
    __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));

extern size_t strspn(const char* __s, const char* __accept) throw()
    __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));

extern "C++" {
extern char* strpbrk(char* __s, const char* __accept) throw() __asm("strpbrk")
    __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern const char* strpbrk(const char* __s,
                           const char* __accept) throw() __asm("strpbrk")
    __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}

extern "C++" {
extern char* strstr(char* __haystack,
                    const char* __needle) throw() __asm("strstr")
    __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern const char* strstr(const char* __haystack,
                          const char* __needle) throw() __asm("strstr")
    __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
}

extern char* strtok(char* __restrict __s,
                    const char* __restrict __delim) throw()
    __attribute__((__nonnull__(2)));

extern char* __strtok_r(char* __restrict __s,
                        const char* __restrict __delim,
                        char** __restrict __save_ptr) throw()
    __attribute__((__nonnull__(2, 3)));

extern char* strtok_r(char* __restrict __s,
                      const char* __restrict __delim,
                      char** __restrict __save_ptr) throw()
    __attribute__((__nonnull__(2, 3)));

extern "C++" char* strcasestr(char* __haystack,
                              const char* __needle) throw() __asm("strcasestr")
    __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern "C++" const char* strcasestr(
    const char* __haystack,
    const char* __needle) throw() __asm("strcasestr") __attribute__((__pure__))
__attribute__((__nonnull__(1, 2)));
extern void* memmem(const void* __haystack,
                    size_t __haystacklen,
                    const void* __needle,
                    size_t __needlelen) throw() __attribute__((__pure__))
__attribute__((__nonnull__(1, 3)));

extern void* __mempcpy(void* __restrict __dest,
                       const void* __restrict __src,
                       size_t __n) throw() __attribute__((__nonnull__(1, 2)));
extern void* mempcpy(void* __restrict __dest,
                     const void* __restrict __src,
                     size_t __n) throw() __attribute__((__nonnull__(1, 2)));

extern size_t strlen(const char* __s) throw() __attribute__((__pure__))
__attribute__((__nonnull__(1)));

extern size_t strnlen(const char* __string, size_t __maxlen) throw()
    __attribute__((__pure__)) __attribute__((__nonnull__(1)));

extern char* strerror(int __errnum) throw();
extern char* strerror_r(int __errnum, char* __buf, size_t __buflen) throw()
    __attribute__((__nonnull__(2)));

extern char* strerror_l(int __errnum, locale_t __l) throw();

extern "C" {

extern int bcmp(const void* __s1, const void* __s2, size_t __n) throw()
    __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));

extern void bcopy(const void* __src, void* __dest, size_t __n) throw()
    __attribute__((__nonnull__(1, 2)));

extern void bzero(void* __s, size_t __n) throw()
    __attribute__((__nonnull__(1)));

extern "C++" {
extern char* index(char* __s, int __c) throw() __asm("index")
    __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern const char* index(const char* __s, int __c) throw() __asm("index")
    __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}

extern "C++" {
extern char* rindex(char* __s, int __c) throw() __asm("rindex")
    __attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern const char* rindex(const char* __s, int __c) throw() __asm("rindex")
    __attribute__((__pure__)) __attribute__((__nonnull__(1)));
}
extern int ffs(int __i) throw() __attribute__((__const__));

extern int ffsl(long int __l) throw() __attribute__((__const__));
__extension__ extern int ffsll(long long int __ll) throw()
    __attribute__((__const__));

extern int strcasecmp(const char* __s1, const char* __s2) throw()
    __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));

extern int strncasecmp(const char* __s1, const char* __s2, size_t __n) throw()
    __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));

extern int strcasecmp_l(const char* __s1,
                        const char* __s2,
                        locale_t __loc) throw() __attribute__((__pure__))
__attribute__((__nonnull__(1, 2, 3)));

extern int strncasecmp_l(const char* __s1,
                         const char* __s2,
                         size_t __n,
                         locale_t __loc) throw() __attribute__((__pure__))
__attribute__((__nonnull__(1, 2, 4)));
}

extern void explicit_bzero(void* __s, size_t __n) throw()
    __attribute__((__nonnull__(1)));

extern char* strsep(char** __restrict __stringp,
                    const char* __restrict __delim) throw()
    __attribute__((__nonnull__(1, 2)));

extern char* strsignal(int __sig) throw();

extern char* __stpcpy(char* __restrict __dest,
                      const char* __restrict __src) throw()
    __attribute__((__nonnull__(1, 2)));
extern char* stpcpy(char* __restrict __dest,
                    const char* __restrict __src) throw()
    __attribute__((__nonnull__(1, 2)));

extern char* __stpncpy(char* __restrict __dest,
                       const char* __restrict __src,
                       size_t __n) throw() __attribute__((__nonnull__(1, 2)));
extern char* stpncpy(char* __restrict __dest,
                     const char* __restrict __src,
                     size_t __n) throw() __attribute__((__nonnull__(1, 2)));

extern int strverscmp(const char* __s1, const char* __s2) throw()
    __attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));

extern char* strfry(char* __string) throw() __attribute__((__nonnull__(1)));

extern void* memfrob(void* __s, size_t __n) throw()
    __attribute__((__nonnull__(1)));

extern "C++" char* basename(char* __filename) throw() __asm("basename")
    __attribute__((__nonnull__(1)));
extern "C++" const char* basename(const char* __filename) throw() __asm(
    "basename") __attribute__((__nonnull__(1)));
}
namespace std __attribute__((__visibility__("default"))) {

  using ::memchr;
  using ::memcmp;
  using ::memcpy;
  using ::memmove;
  using ::memset;
  using ::strcat;
  using ::strchr;
  using ::strcmp;
  using ::strcoll;
  using ::strcpy;
  using ::strcspn;
  using ::strerror;
  using ::strlen;
  using ::strncat;
  using ::strncmp;
  using ::strncpy;
  using ::strpbrk;
  using ::strrchr;
  using ::strspn;
  using ::strstr;
  using ::strtok;
  using ::strxfrm;

}  // namespace std__attribute__((__visibility__("default")))

extern "C" {

extern void __assert_fail(const char* __assertion,
                          const char* __file,
                          unsigned int __line,
                          const char* __function) throw()
    __attribute__((__noreturn__));

extern void __assert_perror_fail(int __errnum,
                                 const char* __file,
                                 unsigned int __line,
                                 const char* __function) throw()
    __attribute__((__noreturn__));

extern void __assert(const char* __assertion,
                     const char* __file,
                     int __line) throw() __attribute__((__noreturn__));
}

namespace std __attribute__((__visibility__("default"))) {
  namespace rel_ops {

  template <class _Tp>
  inline bool operator!=(const _Tp& __x, const _Tp& __y) {
    return !(__x == __y);
  }
  template <class _Tp>
  inline bool operator>(const _Tp& __x, const _Tp& __y) {
    return __y < __x;
  }
  template <class _Tp>
  inline bool operator<=(const _Tp& __x, const _Tp& __y) {
    return !(__y < __x);
  }
  template <class _Tp>
  inline bool operator>=(const _Tp& __x, const _Tp& __y) {
    return !(__x < __y);
  }

  }  // namespace rel_ops

}  // namespace std__attribute__((__visibility__("default")))
namespace std __attribute__((__visibility__("default"))) {

  template <typename _Tp>
  struct tuple_size;

  template <typename _Tp, typename = void>
  struct __tuple_size_cv_impl {};

  template <typename _Tp>
  struct __tuple_size_cv_impl<_Tp, __void_t<decltype(tuple_size<_Tp>::value)>>
      : integral_constant<size_t, tuple_size<_Tp>::value> {};

  template <typename _Tp>
  struct tuple_size<const _Tp> : __tuple_size_cv_impl<_Tp> {};

  template <typename _Tp>
  struct tuple_size<volatile _Tp> : __tuple_size_cv_impl<_Tp> {};

  template <typename _Tp>
  struct tuple_size<const volatile _Tp> : __tuple_size_cv_impl<_Tp> {};
  template <std::size_t __i, typename _Tp>
  struct tuple_element;

  template <std::size_t __i, typename _Tp>
  using __tuple_element_t = typename tuple_element<__i, _Tp>::type;

  template <std::size_t __i, typename _Tp>
  struct tuple_element<__i, const _Tp> {
    typedef typename add_const<__tuple_element_t<__i, _Tp>>::type type;
  };

  template <std::size_t __i, typename _Tp>
  struct tuple_element<__i, volatile _Tp> {
    typedef typename add_volatile<__tuple_element_t<__i, _Tp>>::type type;
  };

  template <std::size_t __i, typename _Tp>
  struct tuple_element<__i, const volatile _Tp> {
    typedef typename add_cv<__tuple_element_t<__i, _Tp>>::type type;
  };

  template <std::size_t __i, typename _Tp>
  using tuple_element_t = typename tuple_element<__i, _Tp>::type;

  template <typename _T1, typename _T2>
  struct __is_tuple_like_impl<std::pair<_T1, _T2>> : true_type {};

  template <class _Tp1, class _Tp2>
  struct tuple_size<std::pair<_Tp1, _Tp2>>
      : public integral_constant<std::size_t, 2> {};

  template <class _Tp1, class _Tp2>
  struct tuple_element<0, std::pair<_Tp1, _Tp2>> {
    typedef _Tp1 type;
  };

  template <class _Tp1, class _Tp2>
  struct tuple_element<1, std::pair<_Tp1, _Tp2>> {
    typedef _Tp2 type;
  };

  template <std::size_t _Int>
  struct __pair_get;

  template <>
  struct __pair_get<0> {
    template <typename _Tp1, typename _Tp2>
    static constexpr _Tp1& __get(std::pair<_Tp1, _Tp2>& __pair) noexcept {
      return __pair.first;
    }

    template <typename _Tp1, typename _Tp2>
    static constexpr _Tp1&& __move_get(
        std::pair<_Tp1, _Tp2>&& __pair) noexcept {
      return std::forward<_Tp1>(__pair.first);
    }

    template <typename _Tp1, typename _Tp2>
    static constexpr const _Tp1& __const_get(
        const std::pair<_Tp1, _Tp2>& __pair) noexcept {
      return __pair.first;
    }
  };

  template <>
  struct __pair_get<1> {
    template <typename _Tp1, typename _Tp2>
    static constexpr _Tp2& __get(std::pair<_Tp1, _Tp2>& __pair) noexcept {
      return __pair.second;
    }

    template <typename _Tp1, typename _Tp2>
    static constexpr _Tp2&& __move_get(
        std::pair<_Tp1, _Tp2>&& __pair) noexcept {
      return std::forward<_Tp2>(__pair.second);
    }

    template <typename _Tp1, typename _Tp2>
    static constexpr const _Tp2& __const_get(
        const std::pair<_Tp1, _Tp2>& __pair) noexcept {
      return __pair.second;
    }
  };

  template <std::size_t _Int, class _Tp1, class _Tp2>
  constexpr typename tuple_element<_Int, std::pair<_Tp1, _Tp2>>::type& get(
      std::pair<_Tp1, _Tp2> & __in) noexcept {
    return __pair_get<_Int>::__get(__in);
  }

  template <std::size_t _Int, class _Tp1, class _Tp2>
  constexpr typename tuple_element<_Int, std::pair<_Tp1, _Tp2>>::type&& get(
      std::pair<_Tp1, _Tp2> && __in) noexcept {
    return __pair_get<_Int>::__move_get(std::move(__in));
  }

  template <std::size_t _Int, class _Tp1, class _Tp2>
  constexpr const typename tuple_element<_Int, std::pair<_Tp1, _Tp2>>::type&
  get(const std::pair<_Tp1, _Tp2>& __in) noexcept {
    return __pair_get<_Int>::__const_get(__in);
  }

  template <typename _Tp, typename _Up>
  constexpr _Tp& get(pair<_Tp, _Up> & __p) noexcept {
    return __p.first;
  }

  template <typename _Tp, typename _Up>
  constexpr const _Tp& get(const pair<_Tp, _Up>& __p) noexcept {
    return __p.first;
  }

  template <typename _Tp, typename _Up>
  constexpr _Tp&& get(pair<_Tp, _Up> && __p) noexcept {
    return std::move(__p.first);
  }

  template <typename _Tp, typename _Up>
  constexpr _Tp& get(pair<_Up, _Tp> & __p) noexcept {
    return __p.second;
  }

  template <typename _Tp, typename _Up>
  constexpr const _Tp& get(const pair<_Up, _Tp>& __p) noexcept {
    return __p.second;
  }

  template <typename _Tp, typename _Up>
  constexpr _Tp&& get(pair<_Up, _Tp> && __p) noexcept {
    return std::move(__p.second);
  }

  template <typename _Tp, typename _Up = _Tp>
  inline _Tp exchange(_Tp & __obj, _Up && __new_val) {
    return std::__exchange(__obj, std::forward<_Up>(__new_val));
  }

  template <size_t... _Indexes>
  struct _Index_tuple {};

  template <typename _Itup1, typename _Itup2>
  struct _Itup_cat;

  template <size_t... _Ind1, size_t... _Ind2>
  struct _Itup_cat<_Index_tuple<_Ind1...>, _Index_tuple<_Ind2...>> {
    using __type = _Index_tuple<_Ind1..., (_Ind2 + sizeof...(_Ind1))...>;
  };

  template <size_t _Num>
  struct _Build_index_tuple
      : _Itup_cat<typename _Build_index_tuple<_Num / 2>::__type,
                  typename _Build_index_tuple<_Num - _Num / 2>::__type> {};

  template <>
  struct _Build_index_tuple<1> {
    typedef _Index_tuple<0> __type;
  };

  template <>
  struct _Build_index_tuple<0> {
    typedef _Index_tuple<> __type;
  };

  template <typename _Tp, _Tp... _Idx>
  struct integer_sequence {
    typedef _Tp value_type;
    static constexpr size_t size() { return sizeof...(_Idx); }
  };

  template <typename _Tp, _Tp _Num,
            typename _ISeq = typename _Build_index_tuple<_Num>::__type>
  struct _Make_integer_sequence;

  template <typename _Tp, _Tp _Num, size_t... _Idx>
  struct _Make_integer_sequence<_Tp, _Num, _Index_tuple<_Idx...>> {
    static_assert(_Num >= 0, "Cannot make integer sequence of negative length");

    typedef integer_sequence<_Tp, static_cast<_Tp>(_Idx)...> __type;
  };

  template <typename _Tp, _Tp _Num>
  using make_integer_sequence =
      typename _Make_integer_sequence<_Tp, _Num>::__type;

  template <size_t... _Idx>
  using index_sequence = integer_sequence<size_t, _Idx...>;

  template <size_t _Num>
  using make_index_sequence = make_integer_sequence<size_t, _Num>;

  template <typename... _Types>
  using index_sequence_for = make_index_sequence<sizeof...(_Types)>;

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <typename _IIter, typename _Predicate>
  bool all_of(_IIter, _IIter, _Predicate);

  template <typename _IIter, typename _Predicate>
  bool any_of(_IIter, _IIter, _Predicate);

  template <typename _FIter, typename _Tp>
  bool binary_search(_FIter, _FIter, const _Tp&);

  template <typename _FIter, typename _Tp, typename _Compare>
  bool binary_search(_FIter, _FIter, const _Tp&, _Compare);
  template <typename _IIter, typename _OIter>
  _OIter copy(_IIter, _IIter, _OIter);

  template <typename _BIter1, typename _BIter2>
  _BIter2 copy_backward(_BIter1, _BIter1, _BIter2);

  template <typename _IIter, typename _OIter, typename _Predicate>
  _OIter copy_if(_IIter, _IIter, _OIter, _Predicate);

  template <typename _IIter, typename _Size, typename _OIter>
  _OIter copy_n(_IIter, _Size, _OIter);

  template <typename _FIter, typename _Tp>
  pair<_FIter, _FIter> equal_range(_FIter, _FIter, const _Tp&);

  template <typename _FIter, typename _Tp, typename _Compare>
  pair<_FIter, _FIter> equal_range(_FIter, _FIter, const _Tp&, _Compare);

  template <typename _FIter, typename _Tp>
  void fill(_FIter, _FIter, const _Tp&);

  template <typename _OIter, typename _Size, typename _Tp>
  _OIter fill_n(_OIter, _Size, const _Tp&);

  template <typename _FIter1, typename _FIter2>
  _FIter1 find_end(_FIter1, _FIter1, _FIter2, _FIter2);

  template <typename _FIter1, typename _FIter2, typename _BinaryPredicate>
  _FIter1 find_end(_FIter1, _FIter1, _FIter2, _FIter2, _BinaryPredicate);

  template <typename _IIter, typename _Predicate>
  _IIter find_if_not(_IIter, _IIter, _Predicate);

  template <typename _IIter1, typename _IIter2>
  bool includes(_IIter1, _IIter1, _IIter2, _IIter2);

  template <typename _IIter1, typename _IIter2, typename _Compare>
  bool includes(_IIter1, _IIter1, _IIter2, _IIter2, _Compare);

  template <typename _BIter>
  void inplace_merge(_BIter, _BIter, _BIter);

  template <typename _BIter, typename _Compare>
  void inplace_merge(_BIter, _BIter, _BIter, _Compare);

  template <typename _RAIter>
  bool is_heap(_RAIter, _RAIter);

  template <typename _RAIter, typename _Compare>
  bool is_heap(_RAIter, _RAIter, _Compare);

  template <typename _RAIter>
  _RAIter is_heap_until(_RAIter, _RAIter);

  template <typename _RAIter, typename _Compare>
  _RAIter is_heap_until(_RAIter, _RAIter, _Compare);

  template <typename _IIter, typename _Predicate>
  bool is_partitioned(_IIter, _IIter, _Predicate);

  template <typename _FIter1, typename _FIter2>
  bool is_permutation(_FIter1, _FIter1, _FIter2);

  template <typename _FIter1, typename _FIter2, typename _BinaryPredicate>
  bool is_permutation(_FIter1, _FIter1, _FIter2, _BinaryPredicate);

  template <typename _FIter>
  bool is_sorted(_FIter, _FIter);

  template <typename _FIter, typename _Compare>
  bool is_sorted(_FIter, _FIter, _Compare);

  template <typename _FIter>
  _FIter is_sorted_until(_FIter, _FIter);

  template <typename _FIter, typename _Compare>
  _FIter is_sorted_until(_FIter, _FIter, _Compare);

  template <typename _FIter1, typename _FIter2>
  void iter_swap(_FIter1, _FIter2);

  template <typename _FIter, typename _Tp>
  _FIter lower_bound(_FIter, _FIter, const _Tp&);

  template <typename _FIter, typename _Tp, typename _Compare>
  _FIter lower_bound(_FIter, _FIter, const _Tp&, _Compare);

  template <typename _RAIter>
  void make_heap(_RAIter, _RAIter);

  template <typename _RAIter, typename _Compare>
  void make_heap(_RAIter, _RAIter, _Compare);

  template <typename _Tp>
  constexpr const _Tp& max(const _Tp&, const _Tp&);

  template <typename _Tp, typename _Compare>
  constexpr const _Tp& max(const _Tp&, const _Tp&, _Compare);

  template <typename _Tp>
  constexpr const _Tp& min(const _Tp&, const _Tp&);

  template <typename _Tp, typename _Compare>
  constexpr const _Tp& min(const _Tp&, const _Tp&, _Compare);

  template <typename _Tp>
  constexpr pair<const _Tp&, const _Tp&> minmax(const _Tp&, const _Tp&);

  template <typename _Tp, typename _Compare>
  constexpr pair<const _Tp&, const _Tp&> minmax(const _Tp&, const _Tp&,
                                                _Compare);

  template <typename _FIter>
  constexpr pair<_FIter, _FIter> minmax_element(_FIter, _FIter);

  template <typename _FIter, typename _Compare>
  constexpr pair<_FIter, _FIter> minmax_element(_FIter, _FIter, _Compare);

  template <typename _Tp>
  constexpr _Tp min(initializer_list<_Tp>);

  template <typename _Tp, typename _Compare>
  constexpr _Tp min(initializer_list<_Tp>, _Compare);

  template <typename _Tp>
  constexpr _Tp max(initializer_list<_Tp>);

  template <typename _Tp, typename _Compare>
  constexpr _Tp max(initializer_list<_Tp>, _Compare);

  template <typename _Tp>
  constexpr pair<_Tp, _Tp> minmax(initializer_list<_Tp>);

  template <typename _Tp, typename _Compare>
  constexpr pair<_Tp, _Tp> minmax(initializer_list<_Tp>, _Compare);

  template <typename _BIter>
  bool next_permutation(_BIter, _BIter);

  template <typename _BIter, typename _Compare>
  bool next_permutation(_BIter, _BIter, _Compare);

  template <typename _IIter, typename _Predicate>
  bool none_of(_IIter, _IIter, _Predicate);

  template <typename _IIter, typename _RAIter>
  _RAIter partial_sort_copy(_IIter, _IIter, _RAIter, _RAIter);

  template <typename _IIter, typename _RAIter, typename _Compare>
  _RAIter partial_sort_copy(_IIter, _IIter, _RAIter, _RAIter, _Compare);

  template <typename _IIter, typename _OIter1, typename _OIter2,
            typename _Predicate>
  pair<_OIter1, _OIter2> partition_copy(_IIter, _IIter, _OIter1, _OIter2,
                                        _Predicate);

  template <typename _FIter, typename _Predicate>
  _FIter partition_point(_FIter, _FIter, _Predicate);

  template <typename _RAIter>
  void pop_heap(_RAIter, _RAIter);

  template <typename _RAIter, typename _Compare>
  void pop_heap(_RAIter, _RAIter, _Compare);

  template <typename _BIter>
  bool prev_permutation(_BIter, _BIter);

  template <typename _BIter, typename _Compare>
  bool prev_permutation(_BIter, _BIter, _Compare);

  template <typename _RAIter>
  void push_heap(_RAIter, _RAIter);

  template <typename _RAIter, typename _Compare>
  void push_heap(_RAIter, _RAIter, _Compare);

  template <typename _FIter, typename _Tp>
  _FIter remove(_FIter, _FIter, const _Tp&);

  template <typename _FIter, typename _Predicate>
  _FIter remove_if(_FIter, _FIter, _Predicate);

  template <typename _IIter, typename _OIter, typename _Tp>
  _OIter remove_copy(_IIter, _IIter, _OIter, const _Tp&);

  template <typename _IIter, typename _OIter, typename _Predicate>
  _OIter remove_copy_if(_IIter, _IIter, _OIter, _Predicate);

  template <typename _IIter, typename _OIter, typename _Tp>
  _OIter replace_copy(_IIter, _IIter, _OIter, const _Tp&, const _Tp&);

  template <typename _Iter, typename _OIter, typename _Predicate, typename _Tp>
  _OIter replace_copy_if(_Iter, _Iter, _OIter, _Predicate, const _Tp&);

  template <typename _BIter>
  void reverse(_BIter, _BIter);

  template <typename _BIter, typename _OIter>
  _OIter reverse_copy(_BIter, _BIter, _OIter);

  inline namespace _V2 {
  template <typename _FIter>
  _FIter rotate(_FIter, _FIter, _FIter);
  }

  template <typename _FIter, typename _OIter>
  _OIter rotate_copy(_FIter, _FIter, _FIter, _OIter);
  template <typename _RAIter, typename _UGenerator>
  void shuffle(_RAIter, _RAIter, _UGenerator &&);

  template <typename _RAIter>
  void sort_heap(_RAIter, _RAIter);

  template <typename _RAIter, typename _Compare>
  void sort_heap(_RAIter, _RAIter, _Compare);

  template <typename _BIter, typename _Predicate>
  _BIter stable_partition(_BIter, _BIter, _Predicate);
  template <typename _FIter1, typename _FIter2>
  _FIter2 swap_ranges(_FIter1, _FIter1, _FIter2);

  template <typename _FIter>
  _FIter unique(_FIter, _FIter);

  template <typename _FIter, typename _BinaryPredicate>
  _FIter unique(_FIter, _FIter, _BinaryPredicate);

  template <typename _FIter, typename _Tp>
  _FIter upper_bound(_FIter, _FIter, const _Tp&);

  template <typename _FIter, typename _Tp, typename _Compare>
  _FIter upper_bound(_FIter, _FIter, const _Tp&, _Compare);

  template <typename _FIter>
  _FIter adjacent_find(_FIter, _FIter);

  template <typename _FIter, typename _BinaryPredicate>
  _FIter adjacent_find(_FIter, _FIter, _BinaryPredicate);

  template <typename _IIter, typename _Tp>
  typename iterator_traits<_IIter>::difference_type count(_IIter, _IIter,
                                                          const _Tp&);

  template <typename _IIter, typename _Predicate>
  typename iterator_traits<_IIter>::difference_type count_if(_IIter, _IIter,
                                                             _Predicate);

  template <typename _IIter1, typename _IIter2>
  bool equal(_IIter1, _IIter1, _IIter2);

  template <typename _IIter1, typename _IIter2, typename _BinaryPredicate>
  bool equal(_IIter1, _IIter1, _IIter2, _BinaryPredicate);

  template <typename _IIter, typename _Tp>
  _IIter find(_IIter, _IIter, const _Tp&);

  template <typename _FIter1, typename _FIter2>
  _FIter1 find_first_of(_FIter1, _FIter1, _FIter2, _FIter2);

  template <typename _FIter1, typename _FIter2, typename _BinaryPredicate>
  _FIter1 find_first_of(_FIter1, _FIter1, _FIter2, _FIter2, _BinaryPredicate);

  template <typename _IIter, typename _Predicate>
  _IIter find_if(_IIter, _IIter, _Predicate);

  template <typename _IIter, typename _Funct>
  _Funct for_each(_IIter, _IIter, _Funct);

  template <typename _FIter, typename _Generator>
  void generate(_FIter, _FIter, _Generator);

  template <typename _OIter, typename _Size, typename _Generator>
  _OIter generate_n(_OIter, _Size, _Generator);

  template <typename _IIter1, typename _IIter2>
  bool lexicographical_compare(_IIter1, _IIter1, _IIter2, _IIter2);

  template <typename _IIter1, typename _IIter2, typename _Compare>
  bool lexicographical_compare(_IIter1, _IIter1, _IIter2, _IIter2, _Compare);

  template <typename _FIter>
  constexpr _FIter max_element(_FIter, _FIter);

  template <typename _FIter, typename _Compare>
  constexpr _FIter max_element(_FIter, _FIter, _Compare);

  template <typename _IIter1, typename _IIter2, typename _OIter>
  _OIter merge(_IIter1, _IIter1, _IIter2, _IIter2, _OIter);

  template <typename _IIter1, typename _IIter2, typename _OIter,
            typename _Compare>
  _OIter merge(_IIter1, _IIter1, _IIter2, _IIter2, _OIter, _Compare);

  template <typename _FIter>
  constexpr _FIter min_element(_FIter, _FIter);

  template <typename _FIter, typename _Compare>
  constexpr _FIter min_element(_FIter, _FIter, _Compare);

  template <typename _IIter1, typename _IIter2>
  pair<_IIter1, _IIter2> mismatch(_IIter1, _IIter1, _IIter2);

  template <typename _IIter1, typename _IIter2, typename _BinaryPredicate>
  pair<_IIter1, _IIter2> mismatch(_IIter1, _IIter1, _IIter2, _BinaryPredicate);

  template <typename _RAIter>
  void nth_element(_RAIter, _RAIter, _RAIter);

  template <typename _RAIter, typename _Compare>
  void nth_element(_RAIter, _RAIter, _RAIter, _Compare);

  template <typename _RAIter>
  void partial_sort(_RAIter, _RAIter, _RAIter);

  template <typename _RAIter, typename _Compare>
  void partial_sort(_RAIter, _RAIter, _RAIter, _Compare);

  template <typename _BIter, typename _Predicate>
  _BIter partition(_BIter, _BIter, _Predicate);

  template <typename _RAIter>
  void random_shuffle(_RAIter, _RAIter);

  template <typename _RAIter, typename _Generator>
  void random_shuffle(_RAIter, _RAIter,

                      _Generator &&);

  template <typename _FIter, typename _Tp>
  void replace(_FIter, _FIter, const _Tp&, const _Tp&);

  template <typename _FIter, typename _Predicate, typename _Tp>
  void replace_if(_FIter, _FIter, _Predicate, const _Tp&);

  template <typename _FIter1, typename _FIter2>
  _FIter1 search(_FIter1, _FIter1, _FIter2, _FIter2);

  template <typename _FIter1, typename _FIter2, typename _BinaryPredicate>
  _FIter1 search(_FIter1, _FIter1, _FIter2, _FIter2, _BinaryPredicate);

  template <typename _FIter, typename _Size, typename _Tp>
  _FIter search_n(_FIter, _FIter, _Size, const _Tp&);

  template <typename _FIter, typename _Size, typename _Tp,
            typename _BinaryPredicate>
  _FIter search_n(_FIter, _FIter, _Size, const _Tp&, _BinaryPredicate);

  template <typename _IIter1, typename _IIter2, typename _OIter>
  _OIter set_difference(_IIter1, _IIter1, _IIter2, _IIter2, _OIter);

  template <typename _IIter1, typename _IIter2, typename _OIter,
            typename _Compare>
  _OIter set_difference(_IIter1, _IIter1, _IIter2, _IIter2, _OIter, _Compare);

  template <typename _IIter1, typename _IIter2, typename _OIter>
  _OIter set_intersection(_IIter1, _IIter1, _IIter2, _IIter2, _OIter);

  template <typename _IIter1, typename _IIter2, typename _OIter,
            typename _Compare>
  _OIter set_intersection(_IIter1, _IIter1, _IIter2, _IIter2, _OIter, _Compare);

  template <typename _IIter1, typename _IIter2, typename _OIter>
  _OIter set_symmetric_difference(_IIter1, _IIter1, _IIter2, _IIter2, _OIter);

  template <typename _IIter1, typename _IIter2, typename _OIter,
            typename _Compare>
  _OIter set_symmetric_difference(_IIter1, _IIter1, _IIter2, _IIter2, _OIter,
                                  _Compare);

  template <typename _IIter1, typename _IIter2, typename _OIter>
  _OIter set_union(_IIter1, _IIter1, _IIter2, _IIter2, _OIter);

  template <typename _IIter1, typename _IIter2, typename _OIter,
            typename _Compare>
  _OIter set_union(_IIter1, _IIter1, _IIter2, _IIter2, _OIter, _Compare);

  template <typename _RAIter>
  void sort(_RAIter, _RAIter);

  template <typename _RAIter, typename _Compare>
  void sort(_RAIter, _RAIter, _Compare);

  template <typename _RAIter>
  void stable_sort(_RAIter, _RAIter);

  template <typename _RAIter, typename _Compare>
  void stable_sort(_RAIter, _RAIter, _Compare);

  template <typename _IIter, typename _OIter, typename _UnaryOperation>
  _OIter transform(_IIter, _IIter, _OIter, _UnaryOperation);

  template <typename _IIter1, typename _IIter2, typename _OIter,
            typename _BinaryOperation>
  _OIter transform(_IIter1, _IIter1, _IIter2, _OIter, _BinaryOperation);

  template <typename _IIter, typename _OIter>
  _OIter unique_copy(_IIter, _IIter, _OIter);

  template <typename _IIter, typename _OIter, typename _BinaryPredicate>
  _OIter unique_copy(_IIter, _IIter, _OIter, _BinaryPredicate);

}  // namespace std__attribute__((__visibility__("default")))
namespace std __attribute__((__visibility__("default"))) {

  template <typename _RandomAccessIterator, typename _Distance,
            typename _Compare>
  _Distance __is_heap_until(_RandomAccessIterator __first, _Distance __n,
                            _Compare & __comp) {
    _Distance __parent = 0;
    for (_Distance __child = 1; __child < __n; ++__child) {
      if (__comp(__first + __parent, __first + __child))
        return __child;
      if ((__child & 1) == 0)
        ++__parent;
    }
    return __n;
  }

  template <typename _RandomAccessIterator, typename _Distance>
  inline bool __is_heap(_RandomAccessIterator __first, _Distance __n) {
    __gnu_cxx::__ops::_Iter_less_iter __comp;
    return std::__is_heap_until(__first, __n, __comp) == __n;
  }

  template <typename _RandomAccessIterator, typename _Compare,
            typename _Distance>
  inline bool __is_heap(_RandomAccessIterator __first, _Compare __comp,
                        _Distance __n) {
    typedef __decltype(__comp) _Cmp;
    __gnu_cxx::__ops::_Iter_comp_iter<_Cmp> __cmp(std::move(__comp));
    return std::__is_heap_until(__first, __n, __cmp) == __n;
  }

  template <typename _RandomAccessIterator>
  inline bool __is_heap(_RandomAccessIterator __first,
                        _RandomAccessIterator __last) {
    return std::__is_heap(__first, std::distance(__first, __last));
  }

  template <typename _RandomAccessIterator, typename _Compare>
  inline bool __is_heap(_RandomAccessIterator __first,
                        _RandomAccessIterator __last, _Compare __comp) {
    return std::__is_heap(__first, std::move(__comp),
                          std::distance(__first, __last));
  }

  template <typename _RandomAccessIterator, typename _Distance, typename _Tp,
            typename _Compare>
  void __push_heap(_RandomAccessIterator __first, _Distance __holeIndex,
                   _Distance __topIndex, _Tp __value, _Compare & __comp) {
    _Distance __parent = (__holeIndex - 1) / 2;
    while (__holeIndex > __topIndex && __comp(__first + __parent, __value)) {
      *(__first + __holeIndex) = std::move(*(__first + __parent));
      __holeIndex = __parent;
      __parent = (__holeIndex - 1) / 2;
    }
    *(__first + __holeIndex) = std::move(__value);
  }
  template <typename _RandomAccessIterator>
  inline void push_heap(_RandomAccessIterator __first,
                        _RandomAccessIterator __last) {
    typedef
        typename iterator_traits<_RandomAccessIterator>::value_type _ValueType;
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type
        _DistanceType;

    ;
    ;
    ;

    __gnu_cxx::__ops::_Iter_less_val __comp;
    _ValueType __value = std::move(*(__last - 1));
    std::__push_heap(__first, _DistanceType((__last - __first) - 1),
                     _DistanceType(0), std::move(__value), __comp);
  }
  template <typename _RandomAccessIterator, typename _Compare>
  inline void push_heap(_RandomAccessIterator __first,
                        _RandomAccessIterator __last, _Compare __comp) {
    typedef
        typename iterator_traits<_RandomAccessIterator>::value_type _ValueType;
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type
        _DistanceType;

    ;
    ;
    ;

    __decltype(__gnu_cxx::__ops::__iter_comp_val(std::move(__comp))) __cmp(
        std::move(__comp));
    _ValueType __value = std::move(*(__last - 1));
    std::__push_heap(__first, _DistanceType((__last - __first) - 1),
                     _DistanceType(0), std::move(__value), __cmp);
  }

  template <typename _RandomAccessIterator, typename _Distance, typename _Tp,
            typename _Compare>
  void __adjust_heap(_RandomAccessIterator __first, _Distance __holeIndex,
                     _Distance __len, _Tp __value, _Compare __comp) {
    const _Distance __topIndex = __holeIndex;
    _Distance __secondChild = __holeIndex;
    while (__secondChild < (__len - 1) / 2) {
      __secondChild = 2 * (__secondChild + 1);
      if (__comp(__first + __secondChild, __first + (__secondChild - 1)))
        __secondChild--;
      *(__first + __holeIndex) = std::move(*(__first + __secondChild));
      __holeIndex = __secondChild;
    }
    if ((__len & 1) == 0 && __secondChild == (__len - 2) / 2) {
      __secondChild = 2 * (__secondChild + 1);
      *(__first + __holeIndex) = std::move(*(__first + (__secondChild - 1)));
      __holeIndex = __secondChild - 1;
    }
    __decltype(__gnu_cxx::__ops::__iter_comp_val(std::move(__comp))) __cmp(
        std::move(__comp));
    std::__push_heap(__first, __holeIndex, __topIndex, std::move(__value),
                     __cmp);
  }

  template <typename _RandomAccessIterator, typename _Compare>
  inline void __pop_heap(_RandomAccessIterator __first,
                         _RandomAccessIterator __last,
                         _RandomAccessIterator __result, _Compare & __comp) {
    typedef
        typename iterator_traits<_RandomAccessIterator>::value_type _ValueType;
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type
        _DistanceType;

    _ValueType __value = std::move(*__result);
    *__result = std::move(*__first);
    std::__adjust_heap(__first, _DistanceType(0),
                       _DistanceType(__last - __first), std::move(__value),
                       __comp);
  }
  template <typename _RandomAccessIterator>
  inline void pop_heap(_RandomAccessIterator __first,
                       _RandomAccessIterator __last) {
    ;
    ;
    ;
    ;

    if (__last - __first > 1) {
      --__last;
      __gnu_cxx::__ops::_Iter_less_iter __comp;
      std::__pop_heap(__first, __last, __last, __comp);
    }
  }
  template <typename _RandomAccessIterator, typename _Compare>
  inline void pop_heap(_RandomAccessIterator __first,
                       _RandomAccessIterator __last, _Compare __comp) {
    ;
    ;
    ;
    ;

    if (__last - __first > 1) {
      typedef __decltype(__comp) _Cmp;
      __gnu_cxx::__ops::_Iter_comp_iter<_Cmp> __cmp(std::move(__comp));
      --__last;
      std::__pop_heap(__first, __last, __last, __cmp);
    }
  }

  template <typename _RandomAccessIterator, typename _Compare>
  void __make_heap(_RandomAccessIterator __first, _RandomAccessIterator __last,
                   _Compare & __comp) {
    typedef
        typename iterator_traits<_RandomAccessIterator>::value_type _ValueType;
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type
        _DistanceType;

    if (__last - __first < 2)
      return;

    const _DistanceType __len = __last - __first;
    _DistanceType __parent = (__len - 2) / 2;
    while (true) {
      _ValueType __value = std::move(*(__first + __parent));
      std::__adjust_heap(__first, __parent, __len, std::move(__value), __comp);
      if (__parent == 0)
        return;
      __parent--;
    }
  }
  template <typename _RandomAccessIterator>
  inline void make_heap(_RandomAccessIterator __first,
                        _RandomAccessIterator __last) {
    ;
    ;

    __gnu_cxx::__ops::_Iter_less_iter __comp;
    std::__make_heap(__first, __last, __comp);
  }
  template <typename _RandomAccessIterator, typename _Compare>
  inline void make_heap(_RandomAccessIterator __first,
                        _RandomAccessIterator __last, _Compare __comp) {
    ;
    ;

    typedef __decltype(__comp) _Cmp;
    __gnu_cxx::__ops::_Iter_comp_iter<_Cmp> __cmp(std::move(__comp));
    std::__make_heap(__first, __last, __cmp);
  }

  template <typename _RandomAccessIterator, typename _Compare>
  void __sort_heap(_RandomAccessIterator __first, _RandomAccessIterator __last,
                   _Compare & __comp) {
    while (__last - __first > 1) {
      --__last;
      std::__pop_heap(__first, __last, __last, __comp);
    }
  }
  template <typename _RandomAccessIterator>
  inline void sort_heap(_RandomAccessIterator __first,
                        _RandomAccessIterator __last) {
    ;
    ;
    ;

    __gnu_cxx::__ops::_Iter_less_iter __comp;
    std::__sort_heap(__first, __last, __comp);
  }
  template <typename _RandomAccessIterator, typename _Compare>
  inline void sort_heap(_RandomAccessIterator __first,
                        _RandomAccessIterator __last, _Compare __comp) {
    ;
    ;
    ;

    typedef __decltype(__comp) _Cmp;
    __gnu_cxx::__ops::_Iter_comp_iter<_Cmp> __cmp(std::move(__comp));
    std::__sort_heap(__first, __last, __cmp);
  }
  template <typename _RandomAccessIterator>
  inline _RandomAccessIterator is_heap_until(_RandomAccessIterator __first,
                                             _RandomAccessIterator __last) {
    ;
    ;

    __gnu_cxx::__ops::_Iter_less_iter __comp;
    return __first + std::__is_heap_until(
                         __first, std::distance(__first, __last), __comp);
  }
  template <typename _RandomAccessIterator, typename _Compare>
  inline _RandomAccessIterator is_heap_until(_RandomAccessIterator __first,
                                             _RandomAccessIterator __last,
                                             _Compare __comp) {
    ;
    ;

    typedef __decltype(__comp) _Cmp;
    __gnu_cxx::__ops::_Iter_comp_iter<_Cmp> __cmp(std::move(__comp));
    return __first +
           std::__is_heap_until(__first, std::distance(__first, __last), __cmp);
  }
  template <typename _RandomAccessIterator>
  inline bool is_heap(_RandomAccessIterator __first,
                      _RandomAccessIterator __last) {
    return std::is_heap_until(__first, __last) == __last;
  }
  template <typename _RandomAccessIterator, typename _Compare>
  inline bool is_heap(_RandomAccessIterator __first,
                      _RandomAccessIterator __last, _Compare __comp) {
    ;
    ;

    const auto __dist = std::distance(__first, __last);
    typedef __decltype(__comp) _Cmp;
    __gnu_cxx::__ops::_Iter_comp_iter<_Cmp> __cmp(std::move(__comp));
    return std::__is_heap_until(__first, __dist, __cmp) == __dist;
  }

}  // namespace std__attribute__((__visibility__("default")))
namespace std __attribute__((__visibility__("default"))) {

  template <typename _Tp>
  pair<_Tp*, ptrdiff_t> get_temporary_buffer(ptrdiff_t __len) noexcept {
    const ptrdiff_t __max =
        __gnu_cxx::__numeric_traits<ptrdiff_t>::__max / sizeof(_Tp);
    if (__len > __max)
      __len = __max;

    while (__len > 0) {
      _Tp* __tmp =
          static_cast<_Tp*>(::operator new(__len * sizeof(_Tp), std::nothrow));
      if (__tmp != 0)
        return std::pair<_Tp*, ptrdiff_t>(__tmp, __len);
      __len /= 2;
    }
    return std::pair<_Tp*, ptrdiff_t>(static_cast<_Tp*>(0), 0);
  }
  template <typename _Tp>
  inline void return_temporary_buffer(_Tp * __p) {
    ::operator delete(__p, std::nothrow);
  }

  template <typename _ForwardIterator, typename _Tp>
  class _Temporary_buffer {
   public:
    typedef _Tp value_type;
    typedef value_type* pointer;
    typedef pointer iterator;
    typedef ptrdiff_t size_type;

   protected:
    size_type _M_original_len;
    size_type _M_len;
    pointer _M_buffer;

   public:
    size_type size() const { return _M_len; }

    size_type requested_size() const { return _M_original_len; }

    iterator begin() { return _M_buffer; }

    iterator end() { return _M_buffer + _M_len; }

    _Temporary_buffer(_ForwardIterator __first, _ForwardIterator __last);

    ~_Temporary_buffer() {
      std::_Destroy(_M_buffer, _M_buffer + _M_len);
      std::return_temporary_buffer(_M_buffer);
    }

   private:
    _Temporary_buffer(const _Temporary_buffer&);

    void operator=(const _Temporary_buffer&);
  };

  template <bool>
  struct __uninitialized_construct_buf_dispatch {
    template <typename _Pointer, typename _ForwardIterator>
    static void __ucr(_Pointer __first,
                      _Pointer __last,
                      _ForwardIterator __seed) {
      if (__first == __last)
        return;

      _Pointer __cur = __first;
      try {
        std::_Construct(std::__addressof(*__first), std::move(*__seed));
        _Pointer __prev = __cur;
        ++__cur;
        for (; __cur != __last; ++__cur, ++__prev)
          std::_Construct(std::__addressof(*__cur), std::move(*__prev));
        *__seed = std::move(*__prev);
      } catch (...) {
        std::_Destroy(__first, __cur);
        throw;
      }
    }
  };

  template <>
  struct __uninitialized_construct_buf_dispatch<true> {
    template <typename _Pointer, typename _ForwardIterator>
    static void __ucr(_Pointer, _Pointer, _ForwardIterator) {}
  };
  template <typename _Pointer, typename _ForwardIterator>
  inline void __uninitialized_construct_buf(_Pointer __first, _Pointer __last,
                                            _ForwardIterator __seed) {
    typedef typename std::iterator_traits<_Pointer>::value_type _ValueType;

    std::__uninitialized_construct_buf_dispatch<__has_trivial_constructor(
        _ValueType)>::__ucr(__first, __last, __seed);
  }

  template <typename _ForwardIterator, typename _Tp>
  _Temporary_buffer<_ForwardIterator, _Tp>::_Temporary_buffer(
      _ForwardIterator __first, _ForwardIterator __last)
      : _M_original_len(std::distance(__first, __last)),
        _M_len(0),
        _M_buffer(0) {
    try {
      std::pair<pointer, size_type> __p(
          std::get_temporary_buffer<value_type>(_M_original_len));
      _M_buffer = __p.first;
      _M_len = __p.second;
      if (_M_buffer)
        std::__uninitialized_construct_buf(_M_buffer, _M_buffer + _M_len,
                                           __first);
    } catch (...) {
      std::return_temporary_buffer(_M_buffer);
      _M_buffer = 0;
      _M_len = 0;
      throw;
    }
  }

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  enum float_round_style {
    round_indeterminate = -1,
    round_toward_zero = 0,
    round_to_nearest = 1,
    round_toward_infinity = 2,
    round_toward_neg_infinity = 3
  };

  enum float_denorm_style {

    denorm_indeterminate = -1,

    denorm_absent = 0,

    denorm_present = 1
  };
  struct __numeric_limits_base {
    static constexpr bool is_specialized = false;

    static constexpr int digits = 0;

    static constexpr int digits10 = 0;

    static constexpr int max_digits10 = 0;

    static constexpr bool is_signed = false;

    static constexpr bool is_integer = false;

    static constexpr bool is_exact = false;

    static constexpr int radix = 0;

    static constexpr int min_exponent = 0;

    static constexpr int min_exponent10 = 0;

    static constexpr int max_exponent = 0;

    static constexpr int max_exponent10 = 0;

    static constexpr bool has_infinity = false;

    static constexpr bool has_quiet_NaN = false;

    static constexpr bool has_signaling_NaN = false;

    static constexpr float_denorm_style has_denorm = denorm_absent;

    static constexpr bool has_denorm_loss = false;

    static constexpr bool is_iec559 = false;

    static constexpr bool is_bounded = false;
    static constexpr bool is_modulo = false;

    static constexpr bool traps = false;

    static constexpr bool tinyness_before = false;

    static constexpr float_round_style round_style = round_toward_zero;
  };
  template <typename _Tp>
  struct numeric_limits : public __numeric_limits_base {
    static constexpr _Tp min() noexcept { return _Tp(); }

    static constexpr _Tp max() noexcept { return _Tp(); }

    static constexpr _Tp lowest() noexcept { return _Tp(); }

    static constexpr _Tp epsilon() noexcept { return _Tp(); }

    static constexpr _Tp round_error() noexcept { return _Tp(); }

    static constexpr _Tp infinity() noexcept { return _Tp(); }

    static constexpr _Tp quiet_NaN() noexcept { return _Tp(); }

    static constexpr _Tp signaling_NaN() noexcept { return _Tp(); }

    static constexpr _Tp denorm_min() noexcept { return _Tp(); }
  };

  template <typename _Tp>
  struct numeric_limits<const _Tp> : public numeric_limits<_Tp> {};

  template <typename _Tp>
  struct numeric_limits<volatile _Tp> : public numeric_limits<_Tp> {};

  template <typename _Tp>
  struct numeric_limits<const volatile _Tp> : public numeric_limits<_Tp> {};
  template <>
  struct numeric_limits<bool> {
    static constexpr bool is_specialized = true;

    static constexpr bool min() noexcept { return false; }

    static constexpr bool max() noexcept { return true; }

    static constexpr bool lowest() noexcept { return min(); }

    static constexpr int digits = 1;
    static constexpr int digits10 = 0;

    static constexpr int max_digits10 = 0;

    static constexpr bool is_signed = false;
    static constexpr bool is_integer = true;
    static constexpr bool is_exact = true;
    static constexpr int radix = 2;

    static constexpr bool epsilon() noexcept { return false; }

    static constexpr bool round_error() noexcept { return false; }

    static constexpr int min_exponent = 0;
    static constexpr int min_exponent10 = 0;
    static constexpr int max_exponent = 0;
    static constexpr int max_exponent10 = 0;

    static constexpr bool has_infinity = false;
    static constexpr bool has_quiet_NaN = false;
    static constexpr bool has_signaling_NaN = false;
    static constexpr float_denorm_style has_denorm = denorm_absent;
    static constexpr bool has_denorm_loss = false;

    static constexpr bool infinity() noexcept { return false; }

    static constexpr bool quiet_NaN() noexcept { return false; }

    static constexpr bool signaling_NaN() noexcept { return false; }

    static constexpr bool denorm_min() noexcept { return false; }

    static constexpr bool is_iec559 = false;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = false;

    static constexpr bool traps = true;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_toward_zero;
  };

  template <>
  struct numeric_limits<char> {
    static constexpr bool is_specialized = true;

    static constexpr char min() noexcept {
      return (
          ((char)(-1) < 0)
              ? -(((char)(-1) < 0)
                      ? (((((char)1
                            << ((sizeof(char) * 8 - ((char)(-1) < 0)) - 1)) -
                           1)
                          << 1) +
                         1)
                      : ~(char)0) -
                    1
              : (char)0);
    }

    static constexpr char max() noexcept {
      return (
          ((char)(-1) < 0)
              ? (((((char)1 << ((sizeof(char) * 8 - ((char)(-1) < 0)) - 1)) - 1)
                  << 1) +
                 1)
              : ~(char)0);
    }

    static constexpr char lowest() noexcept { return min(); }

    static constexpr int digits = (sizeof(char) * 8 - ((char)(-1) < 0));
    static constexpr int digits10 =
        ((sizeof(char) * 8 - ((char)(-1) < 0)) * 643L / 2136);

    static constexpr int max_digits10 = 0;

    static constexpr bool is_signed = ((char)(-1) < 0);
    static constexpr bool is_integer = true;
    static constexpr bool is_exact = true;
    static constexpr int radix = 2;

    static constexpr char epsilon() noexcept { return 0; }

    static constexpr char round_error() noexcept { return 0; }

    static constexpr int min_exponent = 0;
    static constexpr int min_exponent10 = 0;
    static constexpr int max_exponent = 0;
    static constexpr int max_exponent10 = 0;

    static constexpr bool has_infinity = false;
    static constexpr bool has_quiet_NaN = false;
    static constexpr bool has_signaling_NaN = false;
    static constexpr float_denorm_style has_denorm = denorm_absent;
    static constexpr bool has_denorm_loss = false;

    static constexpr char infinity() noexcept { return char(); }

    static constexpr char quiet_NaN() noexcept { return char(); }

    static constexpr char signaling_NaN() noexcept { return char(); }

    static constexpr char denorm_min() noexcept { return static_cast<char>(0); }

    static constexpr bool is_iec559 = false;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = !is_signed;

    static constexpr bool traps = true;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_toward_zero;
  };

  template <>
  struct numeric_limits<signed char> {
    static constexpr bool is_specialized = true;

    static constexpr signed char min() noexcept { return -0x7f - 1; }

    static constexpr signed char max() noexcept { return 0x7f; }

    static constexpr signed char lowest() noexcept { return min(); }

    static constexpr int digits =
        (sizeof(signed char) * 8 - ((signed char)(-1) < 0));
    static constexpr int digits10 =
        ((sizeof(signed char) * 8 - ((signed char)(-1) < 0)) * 643L / 2136);

    static constexpr int max_digits10 = 0;

    static constexpr bool is_signed = true;
    static constexpr bool is_integer = true;
    static constexpr bool is_exact = true;
    static constexpr int radix = 2;

    static constexpr signed char epsilon() noexcept { return 0; }

    static constexpr signed char round_error() noexcept { return 0; }

    static constexpr int min_exponent = 0;
    static constexpr int min_exponent10 = 0;
    static constexpr int max_exponent = 0;
    static constexpr int max_exponent10 = 0;

    static constexpr bool has_infinity = false;
    static constexpr bool has_quiet_NaN = false;
    static constexpr bool has_signaling_NaN = false;
    static constexpr float_denorm_style has_denorm = denorm_absent;
    static constexpr bool has_denorm_loss = false;

    static constexpr signed char infinity() noexcept {
      return static_cast<signed char>(0);
    }

    static constexpr signed char quiet_NaN() noexcept {
      return static_cast<signed char>(0);
    }

    static constexpr signed char signaling_NaN() noexcept {
      return static_cast<signed char>(0);
    }

    static constexpr signed char denorm_min() noexcept {
      return static_cast<signed char>(0);
    }

    static constexpr bool is_iec559 = false;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = false;

    static constexpr bool traps = true;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_toward_zero;
  };

  template <>
  struct numeric_limits<unsigned char> {
    static constexpr bool is_specialized = true;

    static constexpr unsigned char min() noexcept { return 0; }

    static constexpr unsigned char max() noexcept { return 0x7f * 2U + 1; }

    static constexpr unsigned char lowest() noexcept { return min(); }

    static constexpr int digits =
        (sizeof(unsigned char) * 8 - ((unsigned char)(-1) < 0));
    static constexpr int digits10 =
        ((sizeof(unsigned char) * 8 - ((unsigned char)(-1) < 0)) * 643L / 2136);

    static constexpr int max_digits10 = 0;

    static constexpr bool is_signed = false;
    static constexpr bool is_integer = true;
    static constexpr bool is_exact = true;
    static constexpr int radix = 2;

    static constexpr unsigned char epsilon() noexcept { return 0; }

    static constexpr unsigned char round_error() noexcept { return 0; }

    static constexpr int min_exponent = 0;
    static constexpr int min_exponent10 = 0;
    static constexpr int max_exponent = 0;
    static constexpr int max_exponent10 = 0;

    static constexpr bool has_infinity = false;
    static constexpr bool has_quiet_NaN = false;
    static constexpr bool has_signaling_NaN = false;
    static constexpr float_denorm_style has_denorm = denorm_absent;
    static constexpr bool has_denorm_loss = false;

    static constexpr unsigned char infinity() noexcept {
      return static_cast<unsigned char>(0);
    }

    static constexpr unsigned char quiet_NaN() noexcept {
      return static_cast<unsigned char>(0);
    }

    static constexpr unsigned char signaling_NaN() noexcept {
      return static_cast<unsigned char>(0);
    }

    static constexpr unsigned char denorm_min() noexcept {
      return static_cast<unsigned char>(0);
    }

    static constexpr bool is_iec559 = false;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = true;

    static constexpr bool traps = true;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_toward_zero;
  };

  template <>
  struct numeric_limits<wchar_t> {
    static constexpr bool is_specialized = true;

    static constexpr wchar_t min() noexcept {
      return (((wchar_t)(-1) < 0)
                  ? -(((wchar_t)(-1) < 0)
                          ? (((((wchar_t)1 << ((sizeof(wchar_t) * 8 -
                                                ((wchar_t)(-1) < 0)) -
                                               1)) -
                               1)
                              << 1) +
                             1)
                          : ~(wchar_t)0) -
                        1
                  : (wchar_t)0);
    }

    static constexpr wchar_t max() noexcept {
      return (((wchar_t)(-1) < 0)
                  ? (((((wchar_t)1
                        << ((sizeof(wchar_t) * 8 - ((wchar_t)(-1) < 0)) - 1)) -
                       1)
                      << 1) +
                     1)
                  : ~(wchar_t)0);
    }

    static constexpr wchar_t lowest() noexcept { return min(); }

    static constexpr int digits = (sizeof(wchar_t) * 8 - ((wchar_t)(-1) < 0));
    static constexpr int digits10 =
        ((sizeof(wchar_t) * 8 - ((wchar_t)(-1) < 0)) * 643L / 2136);

    static constexpr int max_digits10 = 0;

    static constexpr bool is_signed = ((wchar_t)(-1) < 0);
    static constexpr bool is_integer = true;
    static constexpr bool is_exact = true;
    static constexpr int radix = 2;

    static constexpr wchar_t epsilon() noexcept { return 0; }

    static constexpr wchar_t round_error() noexcept { return 0; }

    static constexpr int min_exponent = 0;
    static constexpr int min_exponent10 = 0;
    static constexpr int max_exponent = 0;
    static constexpr int max_exponent10 = 0;

    static constexpr bool has_infinity = false;
    static constexpr bool has_quiet_NaN = false;
    static constexpr bool has_signaling_NaN = false;
    static constexpr float_denorm_style has_denorm = denorm_absent;
    static constexpr bool has_denorm_loss = false;

    static constexpr wchar_t infinity() noexcept { return wchar_t(); }

    static constexpr wchar_t quiet_NaN() noexcept { return wchar_t(); }

    static constexpr wchar_t signaling_NaN() noexcept { return wchar_t(); }

    static constexpr wchar_t denorm_min() noexcept { return wchar_t(); }

    static constexpr bool is_iec559 = false;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = !is_signed;

    static constexpr bool traps = true;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_toward_zero;
  };

  template <>
  struct numeric_limits<char16_t> {
    static constexpr bool is_specialized = true;

    static constexpr char16_t min() noexcept {
      return (((char16_t)(-1) < 0)
                  ? -(((char16_t)(-1) < 0)
                          ? (((((char16_t)1 << ((sizeof(char16_t) * 8 -
                                                 ((char16_t)(-1) < 0)) -
                                                1)) -
                               1)
                              << 1) +
                             1)
                          : ~(char16_t)0) -
                        1
                  : (char16_t)0);
    }

    static constexpr char16_t max() noexcept {
      return (
          ((char16_t)(-1) < 0)
              ? (((((char16_t)1
                    << ((sizeof(char16_t) * 8 - ((char16_t)(-1) < 0)) - 1)) -
                   1)
                  << 1) +
                 1)
              : ~(char16_t)0);
    }

    static constexpr char16_t lowest() noexcept { return min(); }

    static constexpr int digits = (sizeof(char16_t) * 8 - ((char16_t)(-1) < 0));
    static constexpr int digits10 =
        ((sizeof(char16_t) * 8 - ((char16_t)(-1) < 0)) * 643L / 2136);
    static constexpr int max_digits10 = 0;
    static constexpr bool is_signed = ((char16_t)(-1) < 0);
    static constexpr bool is_integer = true;
    static constexpr bool is_exact = true;
    static constexpr int radix = 2;

    static constexpr char16_t epsilon() noexcept { return 0; }

    static constexpr char16_t round_error() noexcept { return 0; }

    static constexpr int min_exponent = 0;
    static constexpr int min_exponent10 = 0;
    static constexpr int max_exponent = 0;
    static constexpr int max_exponent10 = 0;

    static constexpr bool has_infinity = false;
    static constexpr bool has_quiet_NaN = false;
    static constexpr bool has_signaling_NaN = false;
    static constexpr float_denorm_style has_denorm = denorm_absent;
    static constexpr bool has_denorm_loss = false;

    static constexpr char16_t infinity() noexcept { return char16_t(); }

    static constexpr char16_t quiet_NaN() noexcept { return char16_t(); }

    static constexpr char16_t signaling_NaN() noexcept { return char16_t(); }

    static constexpr char16_t denorm_min() noexcept { return char16_t(); }

    static constexpr bool is_iec559 = false;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = !is_signed;

    static constexpr bool traps = true;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_toward_zero;
  };

  template <>
  struct numeric_limits<char32_t> {
    static constexpr bool is_specialized = true;

    static constexpr char32_t min() noexcept {
      return (((char32_t)(-1) < 0)
                  ? -(((char32_t)(-1) < 0)
                          ? (((((char32_t)1 << ((sizeof(char32_t) * 8 -
                                                 ((char32_t)(-1) < 0)) -
                                                1)) -
                               1)
                              << 1) +
                             1)
                          : ~(char32_t)0) -
                        1
                  : (char32_t)0);
    }

    static constexpr char32_t max() noexcept {
      return (
          ((char32_t)(-1) < 0)
              ? (((((char32_t)1
                    << ((sizeof(char32_t) * 8 - ((char32_t)(-1) < 0)) - 1)) -
                   1)
                  << 1) +
                 1)
              : ~(char32_t)0);
    }

    static constexpr char32_t lowest() noexcept { return min(); }

    static constexpr int digits = (sizeof(char32_t) * 8 - ((char32_t)(-1) < 0));
    static constexpr int digits10 =
        ((sizeof(char32_t) * 8 - ((char32_t)(-1) < 0)) * 643L / 2136);
    static constexpr int max_digits10 = 0;
    static constexpr bool is_signed = ((char32_t)(-1) < 0);
    static constexpr bool is_integer = true;
    static constexpr bool is_exact = true;
    static constexpr int radix = 2;

    static constexpr char32_t epsilon() noexcept { return 0; }

    static constexpr char32_t round_error() noexcept { return 0; }

    static constexpr int min_exponent = 0;
    static constexpr int min_exponent10 = 0;
    static constexpr int max_exponent = 0;
    static constexpr int max_exponent10 = 0;

    static constexpr bool has_infinity = false;
    static constexpr bool has_quiet_NaN = false;
    static constexpr bool has_signaling_NaN = false;
    static constexpr float_denorm_style has_denorm = denorm_absent;
    static constexpr bool has_denorm_loss = false;

    static constexpr char32_t infinity() noexcept { return char32_t(); }

    static constexpr char32_t quiet_NaN() noexcept { return char32_t(); }

    static constexpr char32_t signaling_NaN() noexcept { return char32_t(); }

    static constexpr char32_t denorm_min() noexcept { return char32_t(); }

    static constexpr bool is_iec559 = false;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = !is_signed;

    static constexpr bool traps = true;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_toward_zero;
  };

  template <>
  struct numeric_limits<short> {
    static constexpr bool is_specialized = true;

    static constexpr short min() noexcept { return -0x7fff - 1; }

    static constexpr short max() noexcept { return 0x7fff; }

    static constexpr short lowest() noexcept { return min(); }

    static constexpr int digits = (sizeof(short) * 8 - ((short)(-1) < 0));
    static constexpr int digits10 =
        ((sizeof(short) * 8 - ((short)(-1) < 0)) * 643L / 2136);

    static constexpr int max_digits10 = 0;

    static constexpr bool is_signed = true;
    static constexpr bool is_integer = true;
    static constexpr bool is_exact = true;
    static constexpr int radix = 2;

    static constexpr short epsilon() noexcept { return 0; }

    static constexpr short round_error() noexcept { return 0; }

    static constexpr int min_exponent = 0;
    static constexpr int min_exponent10 = 0;
    static constexpr int max_exponent = 0;
    static constexpr int max_exponent10 = 0;

    static constexpr bool has_infinity = false;
    static constexpr bool has_quiet_NaN = false;
    static constexpr bool has_signaling_NaN = false;
    static constexpr float_denorm_style has_denorm = denorm_absent;
    static constexpr bool has_denorm_loss = false;

    static constexpr short infinity() noexcept { return short(); }

    static constexpr short quiet_NaN() noexcept { return short(); }

    static constexpr short signaling_NaN() noexcept { return short(); }

    static constexpr short denorm_min() noexcept { return short(); }

    static constexpr bool is_iec559 = false;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = false;

    static constexpr bool traps = true;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_toward_zero;
  };

  template <>
  struct numeric_limits<unsigned short> {
    static constexpr bool is_specialized = true;

    static constexpr unsigned short min() noexcept { return 0; }

    static constexpr unsigned short max() noexcept { return 0x7fff * 2U + 1; }

    static constexpr unsigned short lowest() noexcept { return min(); }

    static constexpr int digits =
        (sizeof(unsigned short) * 8 - ((unsigned short)(-1) < 0));
    static constexpr int digits10 =
        ((sizeof(unsigned short) * 8 - ((unsigned short)(-1) < 0)) * 643L /
         2136);

    static constexpr int max_digits10 = 0;

    static constexpr bool is_signed = false;
    static constexpr bool is_integer = true;
    static constexpr bool is_exact = true;
    static constexpr int radix = 2;

    static constexpr unsigned short epsilon() noexcept { return 0; }

    static constexpr unsigned short round_error() noexcept { return 0; }

    static constexpr int min_exponent = 0;
    static constexpr int min_exponent10 = 0;
    static constexpr int max_exponent = 0;
    static constexpr int max_exponent10 = 0;

    static constexpr bool has_infinity = false;
    static constexpr bool has_quiet_NaN = false;
    static constexpr bool has_signaling_NaN = false;
    static constexpr float_denorm_style has_denorm = denorm_absent;
    static constexpr bool has_denorm_loss = false;

    static constexpr unsigned short infinity() noexcept {
      return static_cast<unsigned short>(0);
    }

    static constexpr unsigned short quiet_NaN() noexcept {
      return static_cast<unsigned short>(0);
    }

    static constexpr unsigned short signaling_NaN() noexcept {
      return static_cast<unsigned short>(0);
    }

    static constexpr unsigned short denorm_min() noexcept {
      return static_cast<unsigned short>(0);
    }

    static constexpr bool is_iec559 = false;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = true;

    static constexpr bool traps = true;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_toward_zero;
  };

  template <>
  struct numeric_limits<int> {
    static constexpr bool is_specialized = true;

    static constexpr int min() noexcept { return -0x7fffffff - 1; }

    static constexpr int max() noexcept { return 0x7fffffff; }

    static constexpr int lowest() noexcept { return min(); }

    static constexpr int digits = (sizeof(int) * 8 - ((int)(-1) < 0));
    static constexpr int digits10 =
        ((sizeof(int) * 8 - ((int)(-1) < 0)) * 643L / 2136);

    static constexpr int max_digits10 = 0;

    static constexpr bool is_signed = true;
    static constexpr bool is_integer = true;
    static constexpr bool is_exact = true;
    static constexpr int radix = 2;

    static constexpr int epsilon() noexcept { return 0; }

    static constexpr int round_error() noexcept { return 0; }

    static constexpr int min_exponent = 0;
    static constexpr int min_exponent10 = 0;
    static constexpr int max_exponent = 0;
    static constexpr int max_exponent10 = 0;

    static constexpr bool has_infinity = false;
    static constexpr bool has_quiet_NaN = false;
    static constexpr bool has_signaling_NaN = false;
    static constexpr float_denorm_style has_denorm = denorm_absent;
    static constexpr bool has_denorm_loss = false;

    static constexpr int infinity() noexcept { return static_cast<int>(0); }

    static constexpr int quiet_NaN() noexcept { return static_cast<int>(0); }

    static constexpr int signaling_NaN() noexcept {
      return static_cast<int>(0);
    }

    static constexpr int denorm_min() noexcept { return static_cast<int>(0); }

    static constexpr bool is_iec559 = false;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = false;

    static constexpr bool traps = true;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_toward_zero;
  };

  template <>
  struct numeric_limits<unsigned int> {
    static constexpr bool is_specialized = true;

    static constexpr unsigned int min() noexcept { return 0; }

    static constexpr unsigned int max() noexcept { return 0x7fffffff * 2U + 1; }

    static constexpr unsigned int lowest() noexcept { return min(); }

    static constexpr int digits =
        (sizeof(unsigned int) * 8 - ((unsigned int)(-1) < 0));
    static constexpr int digits10 =
        ((sizeof(unsigned int) * 8 - ((unsigned int)(-1) < 0)) * 643L / 2136);

    static constexpr int max_digits10 = 0;

    static constexpr bool is_signed = false;
    static constexpr bool is_integer = true;
    static constexpr bool is_exact = true;
    static constexpr int radix = 2;

    static constexpr unsigned int epsilon() noexcept { return 0; }

    static constexpr unsigned int round_error() noexcept { return 0; }

    static constexpr int min_exponent = 0;
    static constexpr int min_exponent10 = 0;
    static constexpr int max_exponent = 0;
    static constexpr int max_exponent10 = 0;

    static constexpr bool has_infinity = false;
    static constexpr bool has_quiet_NaN = false;
    static constexpr bool has_signaling_NaN = false;
    static constexpr float_denorm_style has_denorm = denorm_absent;
    static constexpr bool has_denorm_loss = false;

    static constexpr unsigned int infinity() noexcept {
      return static_cast<unsigned int>(0);
    }

    static constexpr unsigned int quiet_NaN() noexcept {
      return static_cast<unsigned int>(0);
    }

    static constexpr unsigned int signaling_NaN() noexcept {
      return static_cast<unsigned int>(0);
    }

    static constexpr unsigned int denorm_min() noexcept {
      return static_cast<unsigned int>(0);
    }

    static constexpr bool is_iec559 = false;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = true;

    static constexpr bool traps = true;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_toward_zero;
  };

  template <>
  struct numeric_limits<long> {
    static constexpr bool is_specialized = true;

    static constexpr long min() noexcept { return -0x7fffffffffffffffL - 1; }

    static constexpr long max() noexcept { return 0x7fffffffffffffffL; }

    static constexpr long lowest() noexcept { return min(); }

    static constexpr int digits = (sizeof(long) * 8 - ((long)(-1) < 0));
    static constexpr int digits10 =
        ((sizeof(long) * 8 - ((long)(-1) < 0)) * 643L / 2136);

    static constexpr int max_digits10 = 0;

    static constexpr bool is_signed = true;
    static constexpr bool is_integer = true;
    static constexpr bool is_exact = true;
    static constexpr int radix = 2;

    static constexpr long epsilon() noexcept { return 0; }

    static constexpr long round_error() noexcept { return 0; }

    static constexpr int min_exponent = 0;
    static constexpr int min_exponent10 = 0;
    static constexpr int max_exponent = 0;
    static constexpr int max_exponent10 = 0;

    static constexpr bool has_infinity = false;
    static constexpr bool has_quiet_NaN = false;
    static constexpr bool has_signaling_NaN = false;
    static constexpr float_denorm_style has_denorm = denorm_absent;
    static constexpr bool has_denorm_loss = false;

    static constexpr long infinity() noexcept { return static_cast<long>(0); }

    static constexpr long quiet_NaN() noexcept { return static_cast<long>(0); }

    static constexpr long signaling_NaN() noexcept {
      return static_cast<long>(0);
    }

    static constexpr long denorm_min() noexcept { return static_cast<long>(0); }

    static constexpr bool is_iec559 = false;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = false;

    static constexpr bool traps = true;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_toward_zero;
  };

  template <>
  struct numeric_limits<unsigned long> {
    static constexpr bool is_specialized = true;

    static constexpr unsigned long min() noexcept { return 0; }

    static constexpr unsigned long max() noexcept {
      return 0x7fffffffffffffffL * 2UL + 1;
    }

    static constexpr unsigned long lowest() noexcept { return min(); }

    static constexpr int digits =
        (sizeof(unsigned long) * 8 - ((unsigned long)(-1) < 0));
    static constexpr int digits10 =
        ((sizeof(unsigned long) * 8 - ((unsigned long)(-1) < 0)) * 643L / 2136);

    static constexpr int max_digits10 = 0;

    static constexpr bool is_signed = false;
    static constexpr bool is_integer = true;
    static constexpr bool is_exact = true;
    static constexpr int radix = 2;

    static constexpr unsigned long epsilon() noexcept { return 0; }

    static constexpr unsigned long round_error() noexcept { return 0; }

    static constexpr int min_exponent = 0;
    static constexpr int min_exponent10 = 0;
    static constexpr int max_exponent = 0;
    static constexpr int max_exponent10 = 0;

    static constexpr bool has_infinity = false;
    static constexpr bool has_quiet_NaN = false;
    static constexpr bool has_signaling_NaN = false;
    static constexpr float_denorm_style has_denorm = denorm_absent;
    static constexpr bool has_denorm_loss = false;

    static constexpr unsigned long infinity() noexcept {
      return static_cast<unsigned long>(0);
    }

    static constexpr unsigned long quiet_NaN() noexcept {
      return static_cast<unsigned long>(0);
    }

    static constexpr unsigned long signaling_NaN() noexcept {
      return static_cast<unsigned long>(0);
    }

    static constexpr unsigned long denorm_min() noexcept {
      return static_cast<unsigned long>(0);
    }

    static constexpr bool is_iec559 = false;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = true;

    static constexpr bool traps = true;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_toward_zero;
  };

  template <>
  struct numeric_limits<long long> {
    static constexpr bool is_specialized = true;

    static constexpr long long min() noexcept {
      return -0x7fffffffffffffffLL - 1;
    }

    static constexpr long long max() noexcept { return 0x7fffffffffffffffLL; }

    static constexpr long long lowest() noexcept { return min(); }

    static constexpr int digits =
        (sizeof(long long) * 8 - ((long long)(-1) < 0));
    static constexpr int digits10 =
        ((sizeof(long long) * 8 - ((long long)(-1) < 0)) * 643L / 2136);

    static constexpr int max_digits10 = 0;

    static constexpr bool is_signed = true;
    static constexpr bool is_integer = true;
    static constexpr bool is_exact = true;
    static constexpr int radix = 2;

    static constexpr long long epsilon() noexcept { return 0; }

    static constexpr long long round_error() noexcept { return 0; }

    static constexpr int min_exponent = 0;
    static constexpr int min_exponent10 = 0;
    static constexpr int max_exponent = 0;
    static constexpr int max_exponent10 = 0;

    static constexpr bool has_infinity = false;
    static constexpr bool has_quiet_NaN = false;
    static constexpr bool has_signaling_NaN = false;
    static constexpr float_denorm_style has_denorm = denorm_absent;
    static constexpr bool has_denorm_loss = false;

    static constexpr long long infinity() noexcept {
      return static_cast<long long>(0);
    }

    static constexpr long long quiet_NaN() noexcept {
      return static_cast<long long>(0);
    }

    static constexpr long long signaling_NaN() noexcept {
      return static_cast<long long>(0);
    }

    static constexpr long long denorm_min() noexcept {
      return static_cast<long long>(0);
    }

    static constexpr bool is_iec559 = false;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = false;

    static constexpr bool traps = true;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_toward_zero;
  };

  template <>
  struct numeric_limits<unsigned long long> {
    static constexpr bool is_specialized = true;

    static constexpr unsigned long long min() noexcept { return 0; }

    static constexpr unsigned long long max() noexcept {
      return 0x7fffffffffffffffLL * 2ULL + 1;
    }

    static constexpr unsigned long long lowest() noexcept { return min(); }

    static constexpr int digits =
        (sizeof(unsigned long long) * 8 - ((unsigned long long)(-1) < 0));
    static constexpr int digits10 =
        ((sizeof(unsigned long long) * 8 - ((unsigned long long)(-1) < 0)) *
         643L / 2136);

    static constexpr int max_digits10 = 0;

    static constexpr bool is_signed = false;
    static constexpr bool is_integer = true;
    static constexpr bool is_exact = true;
    static constexpr int radix = 2;

    static constexpr unsigned long long epsilon() noexcept { return 0; }

    static constexpr unsigned long long round_error() noexcept { return 0; }

    static constexpr int min_exponent = 0;
    static constexpr int min_exponent10 = 0;
    static constexpr int max_exponent = 0;
    static constexpr int max_exponent10 = 0;

    static constexpr bool has_infinity = false;
    static constexpr bool has_quiet_NaN = false;
    static constexpr bool has_signaling_NaN = false;
    static constexpr float_denorm_style has_denorm = denorm_absent;
    static constexpr bool has_denorm_loss = false;

    static constexpr unsigned long long infinity() noexcept {
      return static_cast<unsigned long long>(0);
    }

    static constexpr unsigned long long quiet_NaN() noexcept {
      return static_cast<unsigned long long>(0);
    }

    static constexpr unsigned long long signaling_NaN() noexcept {
      return static_cast<unsigned long long>(0);
    }

    static constexpr unsigned long long denorm_min() noexcept {
      return static_cast<unsigned long long>(0);
    }

    static constexpr bool is_iec559 = false;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = true;

    static constexpr bool traps = true;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_toward_zero;
  };
  template <>
  struct numeric_limits<__int128> {
    static constexpr bool is_specialized = true;
    static constexpr __int128 min() noexcept {
      return (
          ((__int128)(-1) < 0)
              ? -(((__int128)(-1) < 0)
                      ? (((((__int128)1 << ((128 - ((__int128)(-1) < 0)) - 1)) -
                           1)
                          << 1) +
                         1)
                      : ~(__int128)0) -
                    1
              : (__int128)0);
    }
    static constexpr __int128 max() noexcept {
      return (((__int128)(-1) < 0)
                  ? (((((__int128)1 << ((128 - ((__int128)(-1) < 0)) - 1)) - 1)
                      << 1) +
                     1)
                  : ~(__int128)0);
    }
    static constexpr int digits = 128 - 1;
    static constexpr int digits10 = (128 - 1) * 643L / 2136;
    static constexpr bool is_signed = true;
    static constexpr bool is_integer = true;
    static constexpr bool is_exact = true;
    static constexpr int radix = 2;
    static constexpr __int128 epsilon() noexcept { return 0; }
    static constexpr __int128 round_error() noexcept { return 0; }
    static constexpr __int128 lowest() noexcept { return min(); }
    static constexpr int max_digits10 = 0;
    static constexpr int min_exponent = 0;
    static constexpr int min_exponent10 = 0;
    static constexpr int max_exponent = 0;
    static constexpr int max_exponent10 = 0;
    static constexpr bool has_infinity = false;
    static constexpr bool has_quiet_NaN = false;
    static constexpr bool has_signaling_NaN = false;
    static constexpr float_denorm_style has_denorm = denorm_absent;
    static constexpr bool has_denorm_loss = false;
    static constexpr __int128 infinity() noexcept {
      return static_cast<__int128>(0);
    }
    static constexpr __int128 quiet_NaN() noexcept {
      return static_cast<__int128>(0);
    }
    static constexpr __int128 signaling_NaN() noexcept {
      return static_cast<__int128>(0);
    }
    static constexpr __int128 denorm_min() noexcept {
      return static_cast<__int128>(0);
    }
    static constexpr bool is_iec559 = false;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = false;
    static constexpr bool traps = true;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_toward_zero;
  };
  template <>
  struct numeric_limits<unsigned __int128> {
    static constexpr bool is_specialized = true;
    static constexpr unsigned __int128 min() noexcept { return 0; }
    static constexpr unsigned __int128 max() noexcept {
      return (((unsigned __int128)(-1) < 0)
                  ? (((((unsigned __int128)1
                        << ((128 - ((unsigned __int128)(-1) < 0)) - 1)) -
                       1)
                      << 1) +
                     1)
                  : ~(unsigned __int128)0);
    }
    static constexpr unsigned __int128 lowest() noexcept { return min(); }
    static constexpr int max_digits10 = 0;
    static constexpr int digits = 128;
    static constexpr int digits10 = 128 * 643L / 2136;
    static constexpr bool is_signed = false;
    static constexpr bool is_integer = true;
    static constexpr bool is_exact = true;
    static constexpr int radix = 2;
    static constexpr unsigned __int128 epsilon() noexcept { return 0; }
    static constexpr unsigned __int128 round_error() noexcept { return 0; }
    static constexpr int min_exponent = 0;
    static constexpr int min_exponent10 = 0;
    static constexpr int max_exponent = 0;
    static constexpr int max_exponent10 = 0;
    static constexpr bool has_infinity = false;
    static constexpr bool has_quiet_NaN = false;
    static constexpr bool has_signaling_NaN = false;
    static constexpr float_denorm_style has_denorm = denorm_absent;
    static constexpr bool has_denorm_loss = false;
    static constexpr unsigned __int128 infinity() noexcept {
      return static_cast<unsigned __int128>(0);
    }
    static constexpr unsigned __int128 quiet_NaN() noexcept {
      return static_cast<unsigned __int128>(0);
    }
    static constexpr unsigned __int128 signaling_NaN() noexcept {
      return static_cast<unsigned __int128>(0);
    }
    static constexpr unsigned __int128 denorm_min() noexcept {
      return static_cast<unsigned __int128>(0);
    }
    static constexpr bool is_iec559 = false;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = true;
    static constexpr bool traps = true;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_toward_zero;
  };
  template <>
  struct numeric_limits<float> {
    static constexpr bool is_specialized = true;

    static constexpr float min() noexcept {
      return 1.17549435082228750796873653722224568e-38F;
    }

    static constexpr float max() noexcept {
      return 3.40282346638528859811704183484516925e+38F;
    }

    static constexpr float lowest() noexcept {
      return -3.40282346638528859811704183484516925e+38F;
    }

    static constexpr int digits = 24;
    static constexpr int digits10 = 6;

    static constexpr int max_digits10 = (2 + (24) * 643L / 2136);

    static constexpr bool is_signed = true;
    static constexpr bool is_integer = false;
    static constexpr bool is_exact = false;
    static constexpr int radix = 2;

    static constexpr float epsilon() noexcept {
      return 1.19209289550781250000000000000000000e-7F;
    }

    static constexpr float round_error() noexcept { return 0.5F; }

    static constexpr int min_exponent = (-125);
    static constexpr int min_exponent10 = (-37);
    static constexpr int max_exponent = 128;
    static constexpr int max_exponent10 = 38;

    static constexpr bool has_infinity = 1;
    static constexpr bool has_quiet_NaN = 1;
    static constexpr bool has_signaling_NaN = has_quiet_NaN;
    static constexpr float_denorm_style has_denorm =
        bool(1) ? denorm_present : denorm_absent;
    static constexpr bool has_denorm_loss = false;

    static constexpr float infinity() noexcept { return __builtin_huge_valf(); }

    static constexpr float quiet_NaN() noexcept { return __builtin_nanf(""); }

    static constexpr float signaling_NaN() noexcept {
      return __builtin_nansf("");
    }

    static constexpr float denorm_min() noexcept {
      return 1.40129846432481707092372958328991613e-45F;
    }

    static constexpr bool is_iec559 =
        has_infinity && has_quiet_NaN && has_denorm == denorm_present;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = false;

    static constexpr bool traps = false;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_to_nearest;
  };

  template <>
  struct numeric_limits<double> {
    static constexpr bool is_specialized = true;

    static constexpr double min() noexcept {
      return double(2.22507385850720138309023271733240406e-308L);
    }

    static constexpr double max() noexcept {
      return double(1.79769313486231570814527423731704357e+308L);
    }

    static constexpr double lowest() noexcept {
      return -double(1.79769313486231570814527423731704357e+308L);
    }

    static constexpr int digits = 53;
    static constexpr int digits10 = 15;

    static constexpr int max_digits10 = (2 + (53) * 643L / 2136);

    static constexpr bool is_signed = true;
    static constexpr bool is_integer = false;
    static constexpr bool is_exact = false;
    static constexpr int radix = 2;

    static constexpr double epsilon() noexcept {
      return double(2.22044604925031308084726333618164062e-16L);
    }

    static constexpr double round_error() noexcept { return 0.5; }

    static constexpr int min_exponent = (-1021);
    static constexpr int min_exponent10 = (-307);
    static constexpr int max_exponent = 1024;
    static constexpr int max_exponent10 = 308;

    static constexpr bool has_infinity = 1;
    static constexpr bool has_quiet_NaN = 1;
    static constexpr bool has_signaling_NaN = has_quiet_NaN;
    static constexpr float_denorm_style has_denorm =
        bool(1) ? denorm_present : denorm_absent;
    static constexpr bool has_denorm_loss = false;

    static constexpr double infinity() noexcept { return __builtin_huge_val(); }

    static constexpr double quiet_NaN() noexcept { return __builtin_nan(""); }

    static constexpr double signaling_NaN() noexcept {
      return __builtin_nans("");
    }

    static constexpr double denorm_min() noexcept {
      return double(4.94065645841246544176568792868221372e-324L);
    }

    static constexpr bool is_iec559 =
        has_infinity && has_quiet_NaN && has_denorm == denorm_present;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = false;

    static constexpr bool traps = false;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_to_nearest;
  };

  template <>
  struct numeric_limits<long double> {
    static constexpr bool is_specialized = true;

    static constexpr long double min() noexcept {
      return 3.36210314311209350626267781732175260e-4932L;
    }

    static constexpr long double max() noexcept {
      return 1.18973149535723176502126385303097021e+4932L;
    }

    static constexpr long double lowest() noexcept {
      return -1.18973149535723176502126385303097021e+4932L;
    }

    static constexpr int digits = 64;
    static constexpr int digits10 = 18;

    static constexpr int max_digits10 = (2 + (64) * 643L / 2136);

    static constexpr bool is_signed = true;
    static constexpr bool is_integer = false;
    static constexpr bool is_exact = false;
    static constexpr int radix = 2;

    static constexpr long double epsilon() noexcept {
      return 1.08420217248550443400745280086994171e-19L;
    }

    static constexpr long double round_error() noexcept { return 0.5L; }

    static constexpr int min_exponent = (-16381);
    static constexpr int min_exponent10 = (-4931);
    static constexpr int max_exponent = 16384;
    static constexpr int max_exponent10 = 4932;

    static constexpr bool has_infinity = 1;
    static constexpr bool has_quiet_NaN = 1;
    static constexpr bool has_signaling_NaN = has_quiet_NaN;
    static constexpr float_denorm_style has_denorm =
        bool(1) ? denorm_present : denorm_absent;
    static constexpr bool has_denorm_loss = false;

    static constexpr long double infinity() noexcept {
      return __builtin_huge_vall();
    }

    static constexpr long double quiet_NaN() noexcept {
      return __builtin_nanl("");
    }

    static constexpr long double signaling_NaN() noexcept {
      return __builtin_nansl("");
    }

    static constexpr long double denorm_min() noexcept {
      return 3.64519953188247460252840593361941982e-4951L;
    }

    static constexpr bool is_iec559 =
        has_infinity && has_quiet_NaN && has_denorm == denorm_present;
    static constexpr bool is_bounded = true;
    static constexpr bool is_modulo = false;

    static constexpr bool traps = false;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_to_nearest;
  };

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  namespace __detail {

  template <typename _Tp>
  inline bool _Power_of_2(_Tp __x) {
    return ((__x - 1) & __x) == 0;
  };

  }  // namespace __detail

  template <typename _IntType = int>
  class uniform_int_distribution {
    static_assert(std::is_integral<_IntType>::value,
                  "template argument must be an integral type");

   public:
    typedef _IntType result_type;

    struct param_type {
      typedef uniform_int_distribution<_IntType> distribution_type;

      explicit param_type(_IntType __a = 0,
                          _IntType __b = std::numeric_limits<_IntType>::max())
          : _M_a(__a), _M_b(__b) {
        ;
      }

      result_type a() const { return _M_a; }

      result_type b() const { return _M_b; }

      friend bool operator==(const param_type& __p1, const param_type& __p2) {
        return __p1._M_a == __p2._M_a && __p1._M_b == __p2._M_b;
      }

      friend bool operator!=(const param_type& __p1, const param_type& __p2) {
        return !(__p1 == __p2);
      }

     private:
      _IntType _M_a;
      _IntType _M_b;
    };

   public:
    explicit uniform_int_distribution(
        _IntType __a = 0,
        _IntType __b = std::numeric_limits<_IntType>::max())
        : _M_param(__a, __b) {}

    explicit uniform_int_distribution(const param_type& __p) : _M_param(__p) {}

    void reset() {}

    result_type a() const { return _M_param.a(); }

    result_type b() const { return _M_param.b(); }

    param_type param() const { return _M_param; }

    void param(const param_type& __param) { _M_param = __param; }

    result_type min() const { return this->a(); }

    result_type max() const { return this->b(); }

    template <typename _UniformRandomNumberGenerator>
    result_type operator()(_UniformRandomNumberGenerator& __urng) {
      return this->operator()(__urng, _M_param);
    }

    template <typename _UniformRandomNumberGenerator>
    result_type operator()(_UniformRandomNumberGenerator& __urng,
                           const param_type& __p);

    template <typename _ForwardIterator, typename _UniformRandomNumberGenerator>
    void __generate(_ForwardIterator __f,
                    _ForwardIterator __t,
                    _UniformRandomNumberGenerator& __urng) {
      this->__generate(__f, __t, __urng, _M_param);
    }

    template <typename _ForwardIterator, typename _UniformRandomNumberGenerator>
    void __generate(_ForwardIterator __f,
                    _ForwardIterator __t,
                    _UniformRandomNumberGenerator& __urng,
                    const param_type& __p) {
      this->__generate_impl(__f, __t, __urng, __p);
    }

    template <typename _UniformRandomNumberGenerator>
    void __generate(result_type* __f,
                    result_type* __t,
                    _UniformRandomNumberGenerator& __urng,
                    const param_type& __p) {
      this->__generate_impl(__f, __t, __urng, __p);
    }

    friend bool operator==(const uniform_int_distribution& __d1,
                           const uniform_int_distribution& __d2) {
      return __d1._M_param == __d2._M_param;
    }

   private:
    template <typename _ForwardIterator, typename _UniformRandomNumberGenerator>
    void __generate_impl(_ForwardIterator __f,
                         _ForwardIterator __t,
                         _UniformRandomNumberGenerator& __urng,
                         const param_type& __p);

    param_type _M_param;
  };

  template <typename _IntType>
  template <typename _UniformRandomNumberGenerator>
  typename uniform_int_distribution<_IntType>::result_type
  uniform_int_distribution<_IntType>::operator()(
      _UniformRandomNumberGenerator& __urng, const param_type& __param) {
    typedef typename _UniformRandomNumberGenerator::result_type _Gresult_type;
    typedef typename std::make_unsigned<result_type>::type __utype;
    typedef typename std::common_type<_Gresult_type, __utype>::type __uctype;

    const __uctype __urngmin = __urng.min();
    const __uctype __urngmax = __urng.max();
    const __uctype __urngrange = __urngmax - __urngmin;
    const __uctype __urange = __uctype(__param.b()) - __uctype(__param.a());

    __uctype __ret;

    if (__urngrange > __urange) {
      const __uctype __uerange = __urange + 1;
      const __uctype __scaling = __urngrange / __uerange;
      const __uctype __past = __uerange * __scaling;
      do
        __ret = __uctype(__urng()) - __urngmin;
      while (__ret >= __past);
      __ret /= __scaling;
    } else if (__urngrange < __urange) {
      __uctype __tmp;
      do {
        const __uctype __uerngrange = __urngrange + 1;
        __tmp =
            (__uerngrange * operator()(__urng,
                                       param_type(0, __urange / __uerngrange)));
        __ret = __tmp + (__uctype(__urng()) - __urngmin);
      } while (__ret > __urange || __ret < __tmp);
    } else
      __ret = __uctype(__urng()) - __urngmin;

    return __ret + __param.a();
  }

  template <typename _IntType>
  template <typename _ForwardIterator, typename _UniformRandomNumberGenerator>
  void uniform_int_distribution<_IntType>::__generate_impl(
      _ForwardIterator __f, _ForwardIterator __t,
      _UniformRandomNumberGenerator & __urng, const param_type& __param) {
    typedef typename _UniformRandomNumberGenerator::result_type _Gresult_type;
    typedef typename std::make_unsigned<result_type>::type __utype;
    typedef typename std::common_type<_Gresult_type, __utype>::type __uctype;

    const __uctype __urngmin = __urng.min();
    const __uctype __urngmax = __urng.max();
    const __uctype __urngrange = __urngmax - __urngmin;
    const __uctype __urange = __uctype(__param.b()) - __uctype(__param.a());

    __uctype __ret;

    if (__urngrange > __urange) {
      if (__detail::_Power_of_2(__urngrange + 1) &&
          __detail::_Power_of_2(__urange + 1)) {
        while (__f != __t) {
          __ret = __uctype(__urng()) - __urngmin;
          *__f++ = (__ret & __urange) + __param.a();
        }
      } else {
        const __uctype __uerange = __urange + 1;
        const __uctype __scaling = __urngrange / __uerange;
        const __uctype __past = __uerange * __scaling;
        while (__f != __t) {
          do
            __ret = __uctype(__urng()) - __urngmin;
          while (__ret >= __past);
          *__f++ = __ret / __scaling + __param.a();
        }
      }
    } else if (__urngrange < __urange) {
      __uctype __tmp;
      while (__f != __t) {
        do {
          const __uctype __uerngrange = __urngrange + 1;
          __tmp = (__uerngrange * operator()(
                                      __urng,
                                      param_type(0, __urange / __uerngrange)));
          __ret = __tmp + (__uctype(__urng()) - __urngmin);
        } while (__ret > __urange || __ret < __tmp);
        *__f++ = __ret;
      }
    } else
      while (__f != __t)
        *__f++ = __uctype(__urng()) - __urngmin + __param.a();
  }

}  // namespace std__attribute__((__visibility__("default")))

namespace std __attribute__((__visibility__("default"))) {

  template <typename _Iterator, typename _Compare>
  void __move_median_to_first(_Iterator __result, _Iterator __a, _Iterator __b,
                              _Iterator __c, _Compare __comp) {
    if (__comp(__a, __b)) {
      if (__comp(__b, __c))
        std::iter_swap(__result, __b);
      else if (__comp(__a, __c))
        std::iter_swap(__result, __c);
      else
        std::iter_swap(__result, __a);
    } else if (__comp(__a, __c))
      std::iter_swap(__result, __a);
    else if (__comp(__b, __c))
      std::iter_swap(__result, __c);
    else
      std::iter_swap(__result, __b);
  }

  template <typename _InputIterator, typename _Predicate>
  inline _InputIterator __find_if(_InputIterator __first, _InputIterator __last,
                                  _Predicate __pred, input_iterator_tag) {
    while (__first != __last && !__pred(__first))
      ++__first;
    return __first;
  }

  template <typename _RandomAccessIterator, typename _Predicate>
  _RandomAccessIterator __find_if(
      _RandomAccessIterator __first, _RandomAccessIterator __last,
      _Predicate __pred, random_access_iterator_tag) {
    typename iterator_traits<_RandomAccessIterator>::difference_type
        __trip_count = (__last - __first) >> 2;

    for (; __trip_count > 0; --__trip_count) {
      if (__pred(__first))
        return __first;
      ++__first;

      if (__pred(__first))
        return __first;
      ++__first;

      if (__pred(__first))
        return __first;
      ++__first;

      if (__pred(__first))
        return __first;
      ++__first;
    }

    switch (__last - __first) {
      case 3:
        if (__pred(__first))
          return __first;
        ++__first;
      case 2:
        if (__pred(__first))
          return __first;
        ++__first;
      case 1:
        if (__pred(__first))
          return __first;
        ++__first;
      case 0:
      default:
        return __last;
    }
  }

  template <typename _Iterator, typename _Predicate>
  inline _Iterator __find_if(_Iterator __first, _Iterator __last,
                             _Predicate __pred) {
    return __find_if(__first, __last, __pred,
                     std::__iterator_category(__first));
  }

  template <typename _InputIterator, typename _Predicate>
  inline _InputIterator __find_if_not(
      _InputIterator __first, _InputIterator __last, _Predicate __pred) {
    return std::__find_if(__first, __last, __gnu_cxx::__ops::__negate(__pred),
                          std::__iterator_category(__first));
  }

  template <typename _InputIterator, typename _Predicate, typename _Distance>
  _InputIterator __find_if_not_n(_InputIterator __first, _Distance & __len,
                                 _Predicate __pred) {
    for (; __len; --__len, ++__first)
      if (!__pred(__first))
        break;
    return __first;
  }
  template <typename _ForwardIterator1, typename _ForwardIterator2,
            typename _BinaryPredicate>
  _ForwardIterator1 __search(
      _ForwardIterator1 __first1, _ForwardIterator1 __last1,
      _ForwardIterator2 __first2, _ForwardIterator2 __last2,
      _BinaryPredicate __predicate) {
    if (__first1 == __last1 || __first2 == __last2)
      return __first1;

    _ForwardIterator2 __p1(__first2);
    if (++__p1 == __last2)
      return std::__find_if(
          __first1, __last1,
          __gnu_cxx::__ops::__iter_comp_iter(__predicate, __first2));

    _ForwardIterator2 __p;
    _ForwardIterator1 __current = __first1;

    for (;;) {
      __first1 = std::__find_if(
          __first1, __last1,
          __gnu_cxx::__ops::__iter_comp_iter(__predicate, __first2));

      if (__first1 == __last1)
        return __last1;

      __p = __p1;
      __current = __first1;
      if (++__current == __last1)
        return __last1;

      while (__predicate(__current, __p)) {
        if (++__p == __last2)
          return __first1;
        if (++__current == __last1)
          return __last1;
      }
      ++__first1;
    }
    return __first1;
  }

  template <typename _ForwardIterator, typename _Integer,
            typename _UnaryPredicate>
  _ForwardIterator __search_n_aux(
      _ForwardIterator __first, _ForwardIterator __last, _Integer __count,
      _UnaryPredicate __unary_pred, std::forward_iterator_tag) {
    __first = std::__find_if(__first, __last, __unary_pred);
    while (__first != __last) {
      typename iterator_traits<_ForwardIterator>::difference_type __n = __count;
      _ForwardIterator __i = __first;
      ++__i;
      while (__i != __last && __n != 1 && __unary_pred(__i)) {
        ++__i;
        --__n;
      }
      if (__n == 1)
        return __first;
      if (__i == __last)
        return __last;
      __first = std::__find_if(++__i, __last, __unary_pred);
    }
    return __last;
  }

  template <typename _RandomAccessIter, typename _Integer,
            typename _UnaryPredicate>
  _RandomAccessIter __search_n_aux(
      _RandomAccessIter __first, _RandomAccessIter __last, _Integer __count,
      _UnaryPredicate __unary_pred, std::random_access_iterator_tag) {
    typedef typename std::iterator_traits<_RandomAccessIter>::difference_type
        _DistanceType;

    _DistanceType __tailSize = __last - __first;
    _DistanceType __remainder = __count;

    while (__remainder <= __tailSize) {
      __first += __remainder;
      __tailSize -= __remainder;

      _RandomAccessIter __backTrack = __first;
      while (__unary_pred(--__backTrack)) {
        if (--__remainder == 0)
          return (__first - __count);
      }
      __remainder = __count + 1 - (__first - __backTrack);
    }
    return __last;
  }

  template <typename _ForwardIterator, typename _Integer,
            typename _UnaryPredicate>
  _ForwardIterator __search_n(_ForwardIterator __first, _ForwardIterator __last,
                              _Integer __count, _UnaryPredicate __unary_pred) {
    if (__count <= 0)
      return __first;

    if (__count == 1)
      return std::__find_if(__first, __last, __unary_pred);

    return std::__search_n_aux(__first, __last, __count, __unary_pred,
                               std::__iterator_category(__first));
  }

  template <typename _ForwardIterator1, typename _ForwardIterator2,
            typename _BinaryPredicate>
  _ForwardIterator1 __find_end(
      _ForwardIterator1 __first1, _ForwardIterator1 __last1,
      _ForwardIterator2 __first2, _ForwardIterator2 __last2,
      forward_iterator_tag, forward_iterator_tag, _BinaryPredicate __comp) {
    if (__first2 == __last2)
      return __last1;

    _ForwardIterator1 __result = __last1;
    while (1) {
      _ForwardIterator1 __new_result =
          std::__search(__first1, __last1, __first2, __last2, __comp);
      if (__new_result == __last1)
        return __result;
      else {
        __result = __new_result;
        __first1 = __new_result;
        ++__first1;
      }
    }
  }

  template <typename _BidirectionalIterator1, typename _BidirectionalIterator2,
            typename _BinaryPredicate>
  _BidirectionalIterator1 __find_end(
      _BidirectionalIterator1 __first1, _BidirectionalIterator1 __last1,
      _BidirectionalIterator2 __first2, _BidirectionalIterator2 __last2,
      bidirectional_iterator_tag, bidirectional_iterator_tag,
      _BinaryPredicate __comp) {
    typedef reverse_iterator<_BidirectionalIterator1> _RevIterator1;
    typedef reverse_iterator<_BidirectionalIterator2> _RevIterator2;

    _RevIterator1 __rlast1(__first1);
    _RevIterator2 __rlast2(__first2);
    _RevIterator1 __rresult =
        std::__search(_RevIterator1(__last1), __rlast1, _RevIterator2(__last2),
                      __rlast2, __comp);

    if (__rresult == __rlast1)
      return __last1;
    else {
      _BidirectionalIterator1 __result = __rresult.base();
      std::advance(__result, -std::distance(__first2, __last2));
      return __result;
    }
  }
  template <typename _ForwardIterator1, typename _ForwardIterator2>
  inline _ForwardIterator1 find_end(
      _ForwardIterator1 __first1, _ForwardIterator1 __last1,
      _ForwardIterator2 __first2, _ForwardIterator2 __last2) {
    ;
    ;

    return std::__find_end(__first1, __last1, __first2, __last2,
                           std::__iterator_category(__first1),
                           std::__iterator_category(__first2),
                           __gnu_cxx::__ops::__iter_equal_to_iter());
  }
  template <typename _ForwardIterator1, typename _ForwardIterator2,
            typename _BinaryPredicate>
  inline _ForwardIterator1 find_end(
      _ForwardIterator1 __first1, _ForwardIterator1 __last1,
      _ForwardIterator2 __first2, _ForwardIterator2 __last2,
      _BinaryPredicate __comp) {
    ;
    ;

    return std::__find_end(__first1, __last1, __first2, __last2,
                           std::__iterator_category(__first1),
                           std::__iterator_category(__first2),
                           __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }
  template <typename _InputIterator, typename _Predicate>
  inline bool all_of(_InputIterator __first, _InputIterator __last,
                     _Predicate __pred) {
    return __last == std::find_if_not(__first, __last, __pred);
  }
  template <typename _InputIterator, typename _Predicate>
  inline bool none_of(_InputIterator __first, _InputIterator __last,
                      _Predicate __pred) {
    return __last == std::find_if(__first, __last, __pred);
  }
  template <typename _InputIterator, typename _Predicate>
  inline bool any_of(_InputIterator __first, _InputIterator __last,
                     _Predicate __pred) {
    return !std::none_of(__first, __last, __pred);
  }
  template <typename _InputIterator, typename _Predicate>
  inline _InputIterator find_if_not(_InputIterator __first,
                                    _InputIterator __last, _Predicate __pred) {
    ;
    return std::__find_if_not(__first, __last,
                              __gnu_cxx::__ops::__pred_iter(__pred));
  }
  template <typename _InputIterator, typename _Predicate>
  inline bool is_partitioned(_InputIterator __first, _InputIterator __last,
                             _Predicate __pred) {
    __first = std::find_if_not(__first, __last, __pred);
    if (__first == __last)
      return true;
    ++__first;
    return std::none_of(__first, __last, __pred);
  }
  template <typename _ForwardIterator, typename _Predicate>
  _ForwardIterator partition_point(_ForwardIterator __first,
                                   _ForwardIterator __last, _Predicate __pred) {
    ;

    typedef typename iterator_traits<_ForwardIterator>::difference_type
        _DistanceType;

    _DistanceType __len = std::distance(__first, __last);
    _DistanceType __half;
    _ForwardIterator __middle;

    while (__len > 0) {
      __half = __len >> 1;
      __middle = __first;
      std::advance(__middle, __half);
      if (__pred(*__middle)) {
        __first = __middle;
        ++__first;
        __len = __len - __half - 1;
      } else
        __len = __half;
    }
    return __first;
  }

  template <typename _InputIterator, typename _OutputIterator,
            typename _Predicate>
  _OutputIterator __remove_copy_if(
      _InputIterator __first, _InputIterator __last, _OutputIterator __result,
      _Predicate __pred) {
    for (; __first != __last; ++__first)
      if (!__pred(__first)) {
        *__result = *__first;
        ++__result;
      }
    return __result;
  }
  template <typename _InputIterator, typename _OutputIterator, typename _Tp>
  inline _OutputIterator remove_copy(
      _InputIterator __first, _InputIterator __last, _OutputIterator __result,
      const _Tp& __value) {
    ;

    return std::__remove_copy_if(__first, __last, __result,
                                 __gnu_cxx::__ops::__iter_equals_val(__value));
  }
  template <typename _InputIterator, typename _OutputIterator,
            typename _Predicate>
  inline _OutputIterator remove_copy_if(
      _InputIterator __first, _InputIterator __last, _OutputIterator __result,
      _Predicate __pred) {
    ;

    return std::__remove_copy_if(__first, __last, __result,
                                 __gnu_cxx::__ops::__pred_iter(__pred));
  }
  template <typename _InputIterator, typename _OutputIterator,
            typename _Predicate>
  _OutputIterator copy_if(_InputIterator __first, _InputIterator __last,
                          _OutputIterator __result, _Predicate __pred) {
    ;

    for (; __first != __last; ++__first)
      if (__pred(*__first)) {
        *__result = *__first;
        ++__result;
      }
    return __result;
  }

  template <typename _InputIterator, typename _Size, typename _OutputIterator>
  _OutputIterator __copy_n(_InputIterator __first, _Size __n,
                           _OutputIterator __result, input_iterator_tag) {
    if (__n > 0) {
      while (true) {
        *__result = *__first;
        ++__result;
        if (--__n > 0)
          ++__first;
        else
          break;
      }
    }
    return __result;
  }

  template <typename _RandomAccessIterator, typename _Size,
            typename _OutputIterator>
  inline _OutputIterator __copy_n(_RandomAccessIterator __first, _Size __n,
                                  _OutputIterator __result,
                                  random_access_iterator_tag) {
    return std::copy(__first, __first + __n, __result);
  }
  template <typename _InputIterator, typename _Size, typename _OutputIterator>
  inline _OutputIterator copy_n(_InputIterator __first, _Size __n,
                                _OutputIterator __result) {
    return std::__copy_n(__first, __n, __result,
                         std::__iterator_category(__first));
  }
  template <typename _InputIterator, typename _OutputIterator1,
            typename _OutputIterator2, typename _Predicate>
  pair<_OutputIterator1, _OutputIterator2> partition_copy(
      _InputIterator __first, _InputIterator __last,
      _OutputIterator1 __out_true, _OutputIterator2 __out_false,
      _Predicate __pred) {
    ;

    for (; __first != __last; ++__first)
      if (__pred(*__first)) {
        *__out_true = *__first;
        ++__out_true;
      } else {
        *__out_false = *__first;
        ++__out_false;
      }

    return pair<_OutputIterator1, _OutputIterator2>(__out_true, __out_false);
  }

  template <typename _ForwardIterator, typename _Predicate>
  _ForwardIterator __remove_if(_ForwardIterator __first,
                               _ForwardIterator __last, _Predicate __pred) {
    __first = std::__find_if(__first, __last, __pred);
    if (__first == __last)
      return __first;
    _ForwardIterator __result = __first;
    ++__first;
    for (; __first != __last; ++__first)
      if (!__pred(__first)) {
        *__result = std::move(*__first);
        ++__result;
      }
    return __result;
  }
  template <typename _ForwardIterator, typename _Tp>
  inline _ForwardIterator remove(_ForwardIterator __first,
                                 _ForwardIterator __last, const _Tp& __value) {
    ;

    return std::__remove_if(__first, __last,
                            __gnu_cxx::__ops::__iter_equals_val(__value));
  }
  template <typename _ForwardIterator, typename _Predicate>
  inline _ForwardIterator remove_if(
      _ForwardIterator __first, _ForwardIterator __last, _Predicate __pred) {
    ;

    return std::__remove_if(__first, __last,
                            __gnu_cxx::__ops::__pred_iter(__pred));
  }

  template <typename _ForwardIterator, typename _BinaryPredicate>
  _ForwardIterator __adjacent_find(_ForwardIterator __first,
                                   _ForwardIterator __last,
                                   _BinaryPredicate __binary_pred) {
    if (__first == __last)
      return __last;
    _ForwardIterator __next = __first;
    while (++__next != __last) {
      if (__binary_pred(__first, __next))
        return __first;
      __first = __next;
    }
    return __last;
  }

  template <typename _ForwardIterator, typename _BinaryPredicate>
  _ForwardIterator __unique(_ForwardIterator __first, _ForwardIterator __last,
                            _BinaryPredicate __binary_pred) {
    __first = std::__adjacent_find(__first, __last, __binary_pred);
    if (__first == __last)
      return __last;

    _ForwardIterator __dest = __first;
    ++__first;
    while (++__first != __last)
      if (!__binary_pred(__dest, __first))
        *++__dest = std::move(*__first);
    return ++__dest;
  }
  template <typename _ForwardIterator>
  inline _ForwardIterator unique(_ForwardIterator __first,
                                 _ForwardIterator __last) {
    ;

    return std::__unique(__first, __last,
                         __gnu_cxx::__ops::__iter_equal_to_iter());
  }
  template <typename _ForwardIterator, typename _BinaryPredicate>
  inline _ForwardIterator unique(_ForwardIterator __first,
                                 _ForwardIterator __last,
                                 _BinaryPredicate __binary_pred) {
    ;

    return std::__unique(__first, __last,
                         __gnu_cxx::__ops::__iter_comp_iter(__binary_pred));
  }

  template <typename _ForwardIterator, typename _OutputIterator,
            typename _BinaryPredicate>
  _OutputIterator __unique_copy(
      _ForwardIterator __first, _ForwardIterator __last,
      _OutputIterator __result, _BinaryPredicate __binary_pred,
      forward_iterator_tag, output_iterator_tag) {
    _ForwardIterator __next = __first;
    *__result = *__first;
    while (++__next != __last)
      if (!__binary_pred(__first, __next)) {
        __first = __next;
        *++__result = *__first;
      }
    return ++__result;
  }

  template <typename _InputIterator, typename _OutputIterator,
            typename _BinaryPredicate>
  _OutputIterator __unique_copy(
      _InputIterator __first, _InputIterator __last, _OutputIterator __result,
      _BinaryPredicate __binary_pred, input_iterator_tag, output_iterator_tag) {
    typename iterator_traits<_InputIterator>::value_type __value = *__first;
    __decltype(
        __gnu_cxx::__ops::__iter_comp_val(__binary_pred)) __rebound_pred =
        __gnu_cxx::__ops::__iter_comp_val(__binary_pred);
    *__result = __value;
    while (++__first != __last)
      if (!__rebound_pred(__first, __value)) {
        __value = *__first;
        *++__result = __value;
      }
    return ++__result;
  }

  template <typename _InputIterator, typename _ForwardIterator,
            typename _BinaryPredicate>
  _ForwardIterator __unique_copy(_InputIterator __first, _InputIterator __last,
                                 _ForwardIterator __result,
                                 _BinaryPredicate __binary_pred,
                                 input_iterator_tag, forward_iterator_tag) {
    *__result = *__first;
    while (++__first != __last)
      if (!__binary_pred(__result, __first))
        *++__result = *__first;
    return ++__result;
  }

  template <typename _BidirectionalIterator>
  void __reverse(_BidirectionalIterator __first, _BidirectionalIterator __last,
                 bidirectional_iterator_tag) {
    while (true)
      if (__first == __last || __first == --__last)
        return;
      else {
        std::iter_swap(__first, __last);
        ++__first;
      }
  }

  template <typename _RandomAccessIterator>
  void __reverse(_RandomAccessIterator __first, _RandomAccessIterator __last,
                 random_access_iterator_tag) {
    if (__first == __last)
      return;
    --__last;
    while (__first < __last) {
      std::iter_swap(__first, __last);
      ++__first;
      --__last;
    }
  }
  template <typename _BidirectionalIterator>
  inline void reverse(_BidirectionalIterator __first,
                      _BidirectionalIterator __last) {
    ;
    std::__reverse(__first, __last, std::__iterator_category(__first));
  }
  template <typename _BidirectionalIterator, typename _OutputIterator>
  _OutputIterator reverse_copy(_BidirectionalIterator __first,
                               _BidirectionalIterator __last,
                               _OutputIterator __result) {
    ;

    while (__first != __last) {
      --__last;
      *__result = *__last;
      ++__result;
    }
    return __result;
  }

  template <typename _EuclideanRingElement>
  _EuclideanRingElement __gcd(_EuclideanRingElement __m,
                              _EuclideanRingElement __n) {
    while (__n != 0) {
      _EuclideanRingElement __t = __m % __n;
      __m = __n;
      __n = __t;
    }
    return __m;
  }

  inline namespace _V2 {
  template <typename _ForwardIterator>
  _ForwardIterator __rotate(_ForwardIterator __first,
                            _ForwardIterator __middle,
                            _ForwardIterator __last,
                            forward_iterator_tag) {
    if (__first == __middle)
      return __last;
    else if (__last == __middle)
      return __first;

    _ForwardIterator __first2 = __middle;
    do {
      std::iter_swap(__first, __first2);
      ++__first;
      ++__first2;
      if (__first == __middle)
        __middle = __first2;
    } while (__first2 != __last);

    _ForwardIterator __ret = __first;

    __first2 = __middle;

    while (__first2 != __last) {
      std::iter_swap(__first, __first2);
      ++__first;
      ++__first2;
      if (__first == __middle)
        __middle = __first2;
      else if (__first2 == __last)
        __first2 = __middle;
    }
    return __ret;
  }

  template <typename _BidirectionalIterator>
  _BidirectionalIterator __rotate(_BidirectionalIterator __first,
                                  _BidirectionalIterator __middle,
                                  _BidirectionalIterator __last,
                                  bidirectional_iterator_tag) {
    if (__first == __middle)
      return __last;
    else if (__last == __middle)
      return __first;

    std::__reverse(__first, __middle, bidirectional_iterator_tag());
    std::__reverse(__middle, __last, bidirectional_iterator_tag());

    while (__first != __middle && __middle != __last) {
      std::iter_swap(__first, --__last);
      ++__first;
    }

    if (__first == __middle) {
      std::__reverse(__middle, __last, bidirectional_iterator_tag());
      return __last;
    } else {
      std::__reverse(__first, __middle, bidirectional_iterator_tag());
      return __first;
    }
  }

  template <typename _RandomAccessIterator>
  _RandomAccessIterator __rotate(_RandomAccessIterator __first,
                                 _RandomAccessIterator __middle,
                                 _RandomAccessIterator __last,
                                 random_access_iterator_tag) {
    if (__first == __middle)
      return __last;
    else if (__last == __middle)
      return __first;

    typedef typename iterator_traits<_RandomAccessIterator>::difference_type
        _Distance;
    typedef
        typename iterator_traits<_RandomAccessIterator>::value_type _ValueType;

    _Distance __n = __last - __first;
    _Distance __k = __middle - __first;

    if (__k == __n - __k) {
      std::swap_ranges(__first, __middle, __middle);
      return __middle;
    }

    _RandomAccessIterator __p = __first;
    _RandomAccessIterator __ret = __first + (__last - __middle);

    for (;;) {
      if (__k < __n - __k) {
        if (__is_pod(_ValueType) && __k == 1) {
          _ValueType __t = std::move(*__p);
          std::move(__p + 1, __p + __n, __p);
          *(__p + __n - 1) = std::move(__t);
          return __ret;
        }
        _RandomAccessIterator __q = __p + __k;
        for (_Distance __i = 0; __i < __n - __k; ++__i) {
          std::iter_swap(__p, __q);
          ++__p;
          ++__q;
        }
        __n %= __k;
        if (__n == 0)
          return __ret;
        std::swap(__n, __k);
        __k = __n - __k;
      } else {
        __k = __n - __k;
        if (__is_pod(_ValueType) && __k == 1) {
          _ValueType __t = std::move(*(__p + __n - 1));
          std::move_backward(__p, __p + __n - 1, __p + __n);
          *__p = std::move(__t);
          return __ret;
        }
        _RandomAccessIterator __q = __p + __n;
        __p = __q - __k;
        for (_Distance __i = 0; __i < __n - __k; ++__i) {
          --__p;
          --__q;
          std::iter_swap(__p, __q);
        }
        __n %= __k;
        if (__n == 0)
          return __ret;
        std::swap(__n, __k);
      }
    }
  }
  template <typename _ForwardIterator>
  inline _ForwardIterator rotate(_ForwardIterator __first,
                                 _ForwardIterator __middle,
                                 _ForwardIterator __last) {
    ;
    ;

    return std::__rotate(__first, __middle, __last,
                         std::__iterator_category(__first));
  }

  }  // namespace _V2
  template <typename _ForwardIterator, typename _OutputIterator>
  inline _OutputIterator rotate_copy(
      _ForwardIterator __first, _ForwardIterator __middle,
      _ForwardIterator __last, _OutputIterator __result) {
    ;
    ;

    return std::copy(__first, __middle, std::copy(__middle, __last, __result));
  }

  template <typename _ForwardIterator, typename _Predicate>
  _ForwardIterator __partition(_ForwardIterator __first,
                               _ForwardIterator __last, _Predicate __pred,
                               forward_iterator_tag) {
    if (__first == __last)
      return __first;

    while (__pred(*__first))
      if (++__first == __last)
        return __first;

    _ForwardIterator __next = __first;

    while (++__next != __last)
      if (__pred(*__next)) {
        std::iter_swap(__first, __next);
        ++__first;
      }

    return __first;
  }

  template <typename _BidirectionalIterator, typename _Predicate>
  _BidirectionalIterator __partition(
      _BidirectionalIterator __first, _BidirectionalIterator __last,
      _Predicate __pred, bidirectional_iterator_tag) {
    while (true) {
      while (true)
        if (__first == __last)
          return __first;
        else if (__pred(*__first))
          ++__first;
        else
          break;
      --__last;
      while (true)
        if (__first == __last)
          return __first;
        else if (!bool(__pred(*__last)))
          --__last;
        else
          break;
      std::iter_swap(__first, __last);
      ++__first;
    }
  }
  template <typename _ForwardIterator, typename _Pointer, typename _Predicate,
            typename _Distance>
  _ForwardIterator __stable_partition_adaptive(
      _ForwardIterator __first, _ForwardIterator __last, _Predicate __pred,
      _Distance __len, _Pointer __buffer, _Distance __buffer_size) {
    if (__len == 1)
      return __first;

    if (__len <= __buffer_size) {
      _ForwardIterator __result1 = __first;
      _Pointer __result2 = __buffer;

      *__result2 = std::move(*__first);
      ++__result2;
      ++__first;
      for (; __first != __last; ++__first)
        if (__pred(__first)) {
          *__result1 = std::move(*__first);
          ++__result1;
        } else {
          *__result2 = std::move(*__first);
          ++__result2;
        }

      std::move(__buffer, __result2, __result1);
      return __result1;
    }

    _ForwardIterator __middle = __first;
    std::advance(__middle, __len / 2);
    _ForwardIterator __left_split = std::__stable_partition_adaptive(
        __first, __middle, __pred, __len / 2, __buffer, __buffer_size);

    _Distance __right_len = __len - __len / 2;
    _ForwardIterator __right_split =
        std::__find_if_not_n(__middle, __right_len, __pred);

    if (__right_len)
      __right_split = std::__stable_partition_adaptive(
          __right_split, __last, __pred, __right_len, __buffer, __buffer_size);

    std::rotate(__left_split, __middle, __right_split);
    std::advance(__left_split, std::distance(__middle, __right_split));
    return __left_split;
  }

  template <typename _ForwardIterator, typename _Predicate>
  _ForwardIterator __stable_partition(
      _ForwardIterator __first, _ForwardIterator __last, _Predicate __pred) {
    __first = std::__find_if_not(__first, __last, __pred);

    if (__first == __last)
      return __first;

    typedef typename iterator_traits<_ForwardIterator>::value_type _ValueType;
    typedef typename iterator_traits<_ForwardIterator>::difference_type
        _DistanceType;

    _Temporary_buffer<_ForwardIterator, _ValueType> __buf(__first, __last);
    return std::__stable_partition_adaptive(
        __first, __last, __pred, _DistanceType(__buf.requested_size()),
        __buf.begin(), _DistanceType(__buf.size()));
  }
  template <typename _ForwardIterator, typename _Predicate>
  inline _ForwardIterator stable_partition(
      _ForwardIterator __first, _ForwardIterator __last, _Predicate __pred) {
    ;

    return std::__stable_partition(__first, __last,
                                   __gnu_cxx::__ops::__pred_iter(__pred));
  }

  template <typename _RandomAccessIterator, typename _Compare>
  void __heap_select(_RandomAccessIterator __first,
                     _RandomAccessIterator __middle,
                     _RandomAccessIterator __last, _Compare __comp) {
    std::__make_heap(__first, __middle, __comp);
    for (_RandomAccessIterator __i = __middle; __i < __last; ++__i)
      if (__comp(__i, __first))
        std::__pop_heap(__first, __middle, __i, __comp);
  }

  template <typename _InputIterator, typename _RandomAccessIterator,
            typename _Compare>
  _RandomAccessIterator __partial_sort_copy(
      _InputIterator __first, _InputIterator __last,
      _RandomAccessIterator __result_first, _RandomAccessIterator __result_last,
      _Compare __comp) {
    typedef
        typename iterator_traits<_InputIterator>::value_type _InputValueType;
    typedef iterator_traits<_RandomAccessIterator> _RItTraits;
    typedef typename _RItTraits::difference_type _DistanceType;

    if (__result_first == __result_last)
      return __result_last;
    _RandomAccessIterator __result_real_last = __result_first;
    while (__first != __last && __result_real_last != __result_last) {
      *__result_real_last = *__first;
      ++__result_real_last;
      ++__first;
    }

    std::__make_heap(__result_first, __result_real_last, __comp);
    while (__first != __last) {
      if (__comp(__first, __result_first))
        std::__adjust_heap(__result_first, _DistanceType(0),
                           _DistanceType(__result_real_last - __result_first),
                           _InputValueType(*__first), __comp);
      ++__first;
    }
    std::__sort_heap(__result_first, __result_real_last, __comp);
    return __result_real_last;
  }
  template <typename _InputIterator, typename _RandomAccessIterator>
  inline _RandomAccessIterator partial_sort_copy(
      _InputIterator __first, _InputIterator __last,
      _RandomAccessIterator __result_first,
      _RandomAccessIterator __result_last) {
    ;
    ;
    ;

    return std::__partial_sort_copy(__first, __last, __result_first,
                                    __result_last,
                                    __gnu_cxx::__ops::__iter_less_iter());
  }
  template <typename _InputIterator, typename _RandomAccessIterator,
            typename _Compare>
  inline _RandomAccessIterator partial_sort_copy(
      _InputIterator __first, _InputIterator __last,
      _RandomAccessIterator __result_first, _RandomAccessIterator __result_last,
      _Compare __comp) {
    ;
    ;
    ;

    return std::__partial_sort_copy(__first, __last, __result_first,
                                    __result_last,
                                    __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }

  template <typename _RandomAccessIterator, typename _Compare>
  void __unguarded_linear_insert(_RandomAccessIterator __last,
                                 _Compare __comp) {
    typename iterator_traits<_RandomAccessIterator>::value_type __val =
        std::move(*__last);
    _RandomAccessIterator __next = __last;
    --__next;
    while (__comp(__val, __next)) {
      *__last = std::move(*__next);
      __last = __next;
      --__next;
    }
    *__last = std::move(__val);
  }

  template <typename _RandomAccessIterator, typename _Compare>
  void __insertion_sort(_RandomAccessIterator __first,
                        _RandomAccessIterator __last, _Compare __comp) {
    if (__first == __last)
      return;

    for (_RandomAccessIterator __i = __first + 1; __i != __last; ++__i) {
      if (__comp(__i, __first)) {
        typename iterator_traits<_RandomAccessIterator>::value_type __val =
            std::move(*__i);
        std::move_backward(__first, __i, __i + 1);
        *__first = std::move(__val);
      } else
        std::__unguarded_linear_insert(
            __i, __gnu_cxx::__ops::__val_comp_iter(__comp));
    }
  }

  template <typename _RandomAccessIterator, typename _Compare>
  inline void __unguarded_insertion_sort(_RandomAccessIterator __first,
                                         _RandomAccessIterator __last,
                                         _Compare __comp) {
    for (_RandomAccessIterator __i = __first; __i != __last; ++__i)
      std::__unguarded_linear_insert(__i,
                                     __gnu_cxx::__ops::__val_comp_iter(__comp));
  }

  enum { _S_threshold = 16 };

  template <typename _RandomAccessIterator, typename _Compare>
  void __final_insertion_sort(_RandomAccessIterator __first,
                              _RandomAccessIterator __last, _Compare __comp) {
    if (__last - __first > int(_S_threshold)) {
      std::__insertion_sort(__first, __first + int(_S_threshold), __comp);
      std::__unguarded_insertion_sort(__first + int(_S_threshold), __last,
                                      __comp);
    } else
      std::__insertion_sort(__first, __last, __comp);
  }

  template <typename _RandomAccessIterator, typename _Compare>
  _RandomAccessIterator __unguarded_partition(
      _RandomAccessIterator __first, _RandomAccessIterator __last,
      _RandomAccessIterator __pivot, _Compare __comp) {
    while (true) {
      while (__comp(__first, __pivot))
        ++__first;
      --__last;
      while (__comp(__pivot, __last))
        --__last;
      if (!(__first < __last))
        return __first;
      std::iter_swap(__first, __last);
      ++__first;
    }
  }

  template <typename _RandomAccessIterator, typename _Compare>
  inline _RandomAccessIterator __unguarded_partition_pivot(
      _RandomAccessIterator __first, _RandomAccessIterator __last,
      _Compare __comp) {
    _RandomAccessIterator __mid = __first + (__last - __first) / 2;
    std::__move_median_to_first(__first, __first + 1, __mid, __last - 1,
                                __comp);
    return std::__unguarded_partition(__first + 1, __last, __first, __comp);
  }

  template <typename _RandomAccessIterator, typename _Compare>
  inline void __partial_sort(_RandomAccessIterator __first,
                             _RandomAccessIterator __middle,
                             _RandomAccessIterator __last, _Compare __comp) {
    std::__heap_select(__first, __middle, __last, __comp);
    std::__sort_heap(__first, __middle, __comp);
  }

  template <typename _RandomAccessIterator, typename _Size, typename _Compare>
  void __introsort_loop(_RandomAccessIterator __first,
                        _RandomAccessIterator __last, _Size __depth_limit,
                        _Compare __comp) {
    while (__last - __first > int(_S_threshold)) {
      if (__depth_limit == 0) {
        std::__partial_sort(__first, __last, __last, __comp);
        return;
      }
      --__depth_limit;
      _RandomAccessIterator __cut =
          std::__unguarded_partition_pivot(__first, __last, __comp);
      std::__introsort_loop(__cut, __last, __depth_limit, __comp);
      __last = __cut;
    }
  }

  template <typename _RandomAccessIterator, typename _Compare>
  inline void __sort(_RandomAccessIterator __first,
                     _RandomAccessIterator __last, _Compare __comp) {
    if (__first != __last) {
      std::__introsort_loop(__first, __last, std::__lg(__last - __first) * 2,
                            __comp);
      std::__final_insertion_sort(__first, __last, __comp);
    }
  }

  template <typename _RandomAccessIterator, typename _Size, typename _Compare>
  void __introselect(_RandomAccessIterator __first, _RandomAccessIterator __nth,
                     _RandomAccessIterator __last, _Size __depth_limit,
                     _Compare __comp) {
    while (__last - __first > 3) {
      if (__depth_limit == 0) {
        std::__heap_select(__first, __nth + 1, __last, __comp);

        std::iter_swap(__first, __nth);
        return;
      }
      --__depth_limit;
      _RandomAccessIterator __cut =
          std::__unguarded_partition_pivot(__first, __last, __comp);
      if (__cut <= __nth)
        __first = __cut;
      else
        __last = __cut;
    }
    std::__insertion_sort(__first, __last, __comp);
  }
  template <typename _ForwardIterator, typename _Tp, typename _Compare>
  inline _ForwardIterator lower_bound(_ForwardIterator __first,
                                      _ForwardIterator __last, const _Tp& __val,
                                      _Compare __comp) {
    ;

    return std::__lower_bound(__first, __last, __val,
                              __gnu_cxx::__ops::__iter_comp_val(__comp));
  }

  template <typename _ForwardIterator, typename _Tp, typename _Compare>
  _ForwardIterator __upper_bound(_ForwardIterator __first,
                                 _ForwardIterator __last, const _Tp& __val,
                                 _Compare __comp) {
    typedef typename iterator_traits<_ForwardIterator>::difference_type
        _DistanceType;

    _DistanceType __len = std::distance(__first, __last);

    while (__len > 0) {
      _DistanceType __half = __len >> 1;
      _ForwardIterator __middle = __first;
      std::advance(__middle, __half);
      if (__comp(__val, __middle))
        __len = __half;
      else {
        __first = __middle;
        ++__first;
        __len = __len - __half - 1;
      }
    }
    return __first;
  }
  template <typename _ForwardIterator, typename _Tp>
  inline _ForwardIterator upper_bound(
      _ForwardIterator __first, _ForwardIterator __last, const _Tp& __val) {
    ;

    return std::__upper_bound(__first, __last, __val,
                              __gnu_cxx::__ops::__val_less_iter());
  }
  template <typename _ForwardIterator, typename _Tp, typename _Compare>
  inline _ForwardIterator upper_bound(_ForwardIterator __first,
                                      _ForwardIterator __last, const _Tp& __val,
                                      _Compare __comp) {
    ;

    return std::__upper_bound(__first, __last, __val,
                              __gnu_cxx::__ops::__val_comp_iter(__comp));
  }

  template <typename _ForwardIterator, typename _Tp, typename _CompareItTp,
            typename _CompareTpIt>
  pair<_ForwardIterator, _ForwardIterator> __equal_range(
      _ForwardIterator __first, _ForwardIterator __last, const _Tp& __val,
      _CompareItTp __comp_it_val, _CompareTpIt __comp_val_it) {
    typedef typename iterator_traits<_ForwardIterator>::difference_type
        _DistanceType;

    _DistanceType __len = std::distance(__first, __last);

    while (__len > 0) {
      _DistanceType __half = __len >> 1;
      _ForwardIterator __middle = __first;
      std::advance(__middle, __half);
      if (__comp_it_val(__middle, __val)) {
        __first = __middle;
        ++__first;
        __len = __len - __half - 1;
      } else if (__comp_val_it(__val, __middle))
        __len = __half;
      else {
        _ForwardIterator __left =
            std::__lower_bound(__first, __middle, __val, __comp_it_val);
        std::advance(__first, __len);
        _ForwardIterator __right =
            std::__upper_bound(++__middle, __first, __val, __comp_val_it);
        return pair<_ForwardIterator, _ForwardIterator>(__left, __right);
      }
    }
    return pair<_ForwardIterator, _ForwardIterator>(__first, __first);
  }
  template <typename _ForwardIterator, typename _Tp>
  inline pair<_ForwardIterator, _ForwardIterator> equal_range(
      _ForwardIterator __first, _ForwardIterator __last, const _Tp& __val) {
    ;
    ;

    return std::__equal_range(__first, __last, __val,
                              __gnu_cxx::__ops::__iter_less_val(),
                              __gnu_cxx::__ops::__val_less_iter());
  }
  template <typename _ForwardIterator, typename _Tp, typename _Compare>
  inline pair<_ForwardIterator, _ForwardIterator> equal_range(
      _ForwardIterator __first, _ForwardIterator __last, const _Tp& __val,
      _Compare __comp) {
    ;

    ;

    return std::__equal_range(__first, __last, __val,
                              __gnu_cxx::__ops::__iter_comp_val(__comp),
                              __gnu_cxx::__ops::__val_comp_iter(__comp));
  }
  template <typename _ForwardIterator, typename _Tp>
  bool binary_search(_ForwardIterator __first, _ForwardIterator __last,
                     const _Tp& __val) {
    ;
    ;

    _ForwardIterator __i = std::__lower_bound(
        __first, __last, __val, __gnu_cxx::__ops::__iter_less_val());
    return __i != __last && !(__val < *__i);
  }
  template <typename _ForwardIterator, typename _Tp, typename _Compare>
  bool binary_search(_ForwardIterator __first, _ForwardIterator __last,
                     const _Tp& __val, _Compare __comp) {
    ;

    ;

    _ForwardIterator __i = std::__lower_bound(
        __first, __last, __val, __gnu_cxx::__ops::__iter_comp_val(__comp));
    return __i != __last && !bool(__comp(__val, *__i));
  }

  template <typename _InputIterator1, typename _InputIterator2,
            typename _OutputIterator, typename _Compare>
  void __move_merge_adaptive(_InputIterator1 __first1, _InputIterator1 __last1,
                             _InputIterator2 __first2, _InputIterator2 __last2,
                             _OutputIterator __result, _Compare __comp) {
    while (__first1 != __last1 && __first2 != __last2) {
      if (__comp(__first2, __first1)) {
        *__result = std::move(*__first2);
        ++__first2;
      } else {
        *__result = std::move(*__first1);
        ++__first1;
      }
      ++__result;
    }
    if (__first1 != __last1)
      std::move(__first1, __last1, __result);
  }

  template <typename _BidirectionalIterator1, typename _BidirectionalIterator2,
            typename _BidirectionalIterator3, typename _Compare>
  void __move_merge_adaptive_backward(
      _BidirectionalIterator1 __first1, _BidirectionalIterator1 __last1,
      _BidirectionalIterator2 __first2, _BidirectionalIterator2 __last2,
      _BidirectionalIterator3 __result, _Compare __comp) {
    if (__first1 == __last1) {
      std::move_backward(__first2, __last2, __result);
      return;
    } else if (__first2 == __last2)
      return;

    --__last1;
    --__last2;
    while (true) {
      if (__comp(__last2, __last1)) {
        *--__result = std::move(*__last1);
        if (__first1 == __last1) {
          std::move_backward(__first2, ++__last2, __result);
          return;
        }
        --__last1;
      } else {
        *--__result = std::move(*__last2);
        if (__first2 == __last2)
          return;
        --__last2;
      }
    }
  }

  template <typename _BidirectionalIterator1, typename _BidirectionalIterator2,
            typename _Distance>
  _BidirectionalIterator1 __rotate_adaptive(
      _BidirectionalIterator1 __first, _BidirectionalIterator1 __middle,
      _BidirectionalIterator1 __last, _Distance __len1, _Distance __len2,
      _BidirectionalIterator2 __buffer, _Distance __buffer_size) {
    _BidirectionalIterator2 __buffer_end;
    if (__len1 > __len2 && __len2 <= __buffer_size) {
      if (__len2) {
        __buffer_end = std::move(__middle, __last, __buffer);
        std::move_backward(__first, __middle, __last);
        return std::move(__buffer, __buffer_end, __first);
      } else
        return __first;
    } else if (__len1 <= __buffer_size) {
      if (__len1) {
        __buffer_end = std::move(__first, __middle, __buffer);
        std::move(__middle, __last, __first);
        return std::move_backward(__buffer, __buffer_end, __last);
      } else
        return __last;
    } else {
      std::rotate(__first, __middle, __last);
      std::advance(__first, std::distance(__middle, __last));
      return __first;
    }
  }

  template <typename _BidirectionalIterator, typename _Distance,
            typename _Pointer, typename _Compare>
  void __merge_adaptive(
      _BidirectionalIterator __first, _BidirectionalIterator __middle,
      _BidirectionalIterator __last, _Distance __len1, _Distance __len2,
      _Pointer __buffer, _Distance __buffer_size, _Compare __comp) {
    if (__len1 <= __len2 && __len1 <= __buffer_size) {
      _Pointer __buffer_end = std::move(__first, __middle, __buffer);
      std::__move_merge_adaptive(__buffer, __buffer_end, __middle, __last,
                                 __first, __comp);
    } else if (__len2 <= __buffer_size) {
      _Pointer __buffer_end = std::move(__middle, __last, __buffer);
      std::__move_merge_adaptive_backward(__first, __middle, __buffer,
                                          __buffer_end, __last, __comp);
    } else {
      _BidirectionalIterator __first_cut = __first;
      _BidirectionalIterator __second_cut = __middle;
      _Distance __len11 = 0;
      _Distance __len22 = 0;
      if (__len1 > __len2) {
        __len11 = __len1 / 2;
        std::advance(__first_cut, __len11);
        __second_cut =
            std::__lower_bound(__middle, __last, *__first_cut,
                               __gnu_cxx::__ops::__iter_comp_val(__comp));
        __len22 = std::distance(__middle, __second_cut);
      } else {
        __len22 = __len2 / 2;
        std::advance(__second_cut, __len22);
        __first_cut =
            std::__upper_bound(__first, __middle, *__second_cut,
                               __gnu_cxx::__ops::__val_comp_iter(__comp));
        __len11 = std::distance(__first, __first_cut);
      }

      _BidirectionalIterator __new_middle = std::__rotate_adaptive(
          __first_cut, __middle, __second_cut, __len1 - __len11, __len22,
          __buffer, __buffer_size);
      std::__merge_adaptive(__first, __first_cut, __new_middle, __len11,
                            __len22, __buffer, __buffer_size, __comp);
      std::__merge_adaptive(__new_middle, __second_cut, __last,
                            __len1 - __len11, __len2 - __len22, __buffer,
                            __buffer_size, __comp);
    }
  }

  template <typename _BidirectionalIterator, typename _Distance,
            typename _Compare>
  void __merge_without_buffer(_BidirectionalIterator __first,
                              _BidirectionalIterator __middle,
                              _BidirectionalIterator __last, _Distance __len1,
                              _Distance __len2, _Compare __comp) {
    if (__len1 == 0 || __len2 == 0)
      return;

    if (__len1 + __len2 == 2) {
      if (__comp(__middle, __first))
        std::iter_swap(__first, __middle);
      return;
    }

    _BidirectionalIterator __first_cut = __first;
    _BidirectionalIterator __second_cut = __middle;
    _Distance __len11 = 0;
    _Distance __len22 = 0;
    if (__len1 > __len2) {
      __len11 = __len1 / 2;
      std::advance(__first_cut, __len11);
      __second_cut =
          std::__lower_bound(__middle, __last, *__first_cut,
                             __gnu_cxx::__ops::__iter_comp_val(__comp));
      __len22 = std::distance(__middle, __second_cut);
    } else {
      __len22 = __len2 / 2;
      std::advance(__second_cut, __len22);
      __first_cut =
          std::__upper_bound(__first, __middle, *__second_cut,
                             __gnu_cxx::__ops::__val_comp_iter(__comp));
      __len11 = std::distance(__first, __first_cut);
    }

    std::rotate(__first_cut, __middle, __second_cut);
    _BidirectionalIterator __new_middle = __first_cut;
    std::advance(__new_middle, std::distance(__middle, __second_cut));
    std::__merge_without_buffer(__first, __first_cut, __new_middle, __len11,
                                __len22, __comp);
    std::__merge_without_buffer(__new_middle, __second_cut, __last,
                                __len1 - __len11, __len2 - __len22, __comp);
  }

  template <typename _BidirectionalIterator, typename _Compare>
  void __inplace_merge(_BidirectionalIterator __first,
                       _BidirectionalIterator __middle,
                       _BidirectionalIterator __last, _Compare __comp) {
    typedef
        typename iterator_traits<_BidirectionalIterator>::value_type _ValueType;
    typedef typename iterator_traits<_BidirectionalIterator>::difference_type
        _DistanceType;

    if (__first == __middle || __middle == __last)
      return;

    const _DistanceType __len1 = std::distance(__first, __middle);
    const _DistanceType __len2 = std::distance(__middle, __last);

    typedef _Temporary_buffer<_BidirectionalIterator, _ValueType> _TmpBuf;
    _TmpBuf __buf(__first, __last);

    if (__buf.begin() == 0)
      std::__merge_without_buffer(__first, __middle, __last, __len1, __len2,
                                  __comp);
    else
      std::__merge_adaptive(__first, __middle, __last, __len1, __len2,
                            __buf.begin(), _DistanceType(__buf.size()), __comp);
  }
  template <typename _BidirectionalIterator>
  inline void inplace_merge(_BidirectionalIterator __first,
                            _BidirectionalIterator __middle,
                            _BidirectionalIterator __last) {
    ;
    ;
    ;

    std::__inplace_merge(__first, __middle, __last,
                         __gnu_cxx::__ops::__iter_less_iter());
  }
  template <typename _BidirectionalIterator, typename _Compare>
  inline void inplace_merge(_BidirectionalIterator __first,
                            _BidirectionalIterator __middle,
                            _BidirectionalIterator __last, _Compare __comp) {
    ;
    ;
    ;

    std::__inplace_merge(__first, __middle, __last,
                         __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }

  template <typename _InputIterator, typename _OutputIterator,
            typename _Compare>
  _OutputIterator __move_merge(_InputIterator __first1, _InputIterator __last1,
                               _InputIterator __first2, _InputIterator __last2,
                               _OutputIterator __result, _Compare __comp) {
    while (__first1 != __last1 && __first2 != __last2) {
      if (__comp(__first2, __first1)) {
        *__result = std::move(*__first2);
        ++__first2;
      } else {
        *__result = std::move(*__first1);
        ++__first1;
      }
      ++__result;
    }
    return std::move(__first2, __last2, std::move(__first1, __last1, __result))

        ;
  }

  template <typename _RandomAccessIterator1, typename _RandomAccessIterator2,
            typename _Distance, typename _Compare>
  void __merge_sort_loop(
      _RandomAccessIterator1 __first, _RandomAccessIterator1 __last,
      _RandomAccessIterator2 __result, _Distance __step_size, _Compare __comp) {
    const _Distance __two_step = 2 * __step_size;

    while (__last - __first >= __two_step) {
      __result = std::__move_merge(__first, __first + __step_size,
                                   __first + __step_size, __first + __two_step,
                                   __result, __comp);
      __first += __two_step;
    }
    __step_size = std::min(_Distance(__last - __first), __step_size);

    std::__move_merge(__first, __first + __step_size, __first + __step_size,
                      __last, __result, __comp);
  }

  template <typename _RandomAccessIterator, typename _Distance,
            typename _Compare>
  void __chunk_insertion_sort(_RandomAccessIterator __first,
                              _RandomAccessIterator __last,
                              _Distance __chunk_size, _Compare __comp) {
    while (__last - __first >= __chunk_size) {
      std::__insertion_sort(__first, __first + __chunk_size, __comp);
      __first += __chunk_size;
    }
    std::__insertion_sort(__first, __last, __comp);
  }

  enum { _S_chunk_size = 7 };

  template <typename _RandomAccessIterator, typename _Pointer,
            typename _Compare>
  void __merge_sort_with_buffer(_RandomAccessIterator __first,
                                _RandomAccessIterator __last, _Pointer __buffer,
                                _Compare __comp) {
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type
        _Distance;

    const _Distance __len = __last - __first;
    const _Pointer __buffer_last = __buffer + __len;

    _Distance __step_size = _S_chunk_size;
    std::__chunk_insertion_sort(__first, __last, __step_size, __comp);

    while (__step_size < __len) {
      std::__merge_sort_loop(__first, __last, __buffer, __step_size, __comp);
      __step_size *= 2;
      std::__merge_sort_loop(__buffer, __buffer_last, __first, __step_size,
                             __comp);
      __step_size *= 2;
    }
  }

  template <typename _RandomAccessIterator, typename _Pointer,
            typename _Distance, typename _Compare>
  void __stable_sort_adaptive(_RandomAccessIterator __first,
                              _RandomAccessIterator __last, _Pointer __buffer,
                              _Distance __buffer_size, _Compare __comp) {
    const _Distance __len = (__last - __first + 1) / 2;
    const _RandomAccessIterator __middle = __first + __len;
    if (__len > __buffer_size) {
      std::__stable_sort_adaptive(__first, __middle, __buffer, __buffer_size,
                                  __comp);
      std::__stable_sort_adaptive(__middle, __last, __buffer, __buffer_size,
                                  __comp);
    } else {
      std::__merge_sort_with_buffer(__first, __middle, __buffer, __comp);
      std::__merge_sort_with_buffer(__middle, __last, __buffer, __comp);
    }
    std::__merge_adaptive(
        __first, __middle, __last, _Distance(__middle - __first),
        _Distance(__last - __middle), __buffer, __buffer_size, __comp);
  }

  template <typename _RandomAccessIterator, typename _Compare>
  void __inplace_stable_sort(_RandomAccessIterator __first,
                             _RandomAccessIterator __last, _Compare __comp) {
    if (__last - __first < 15) {
      std::__insertion_sort(__first, __last, __comp);
      return;
    }
    _RandomAccessIterator __middle = __first + (__last - __first) / 2;
    std::__inplace_stable_sort(__first, __middle, __comp);
    std::__inplace_stable_sort(__middle, __last, __comp);
    std::__merge_without_buffer(__first, __middle, __last, __middle - __first,
                                __last - __middle, __comp);
  }
  template <typename _InputIterator1, typename _InputIterator2,
            typename _Compare>
  bool __includes(_InputIterator1 __first1, _InputIterator1 __last1,
                  _InputIterator2 __first2, _InputIterator2 __last2,
                  _Compare __comp) {
    while (__first1 != __last1 && __first2 != __last2)
      if (__comp(__first2, __first1))
        return false;
      else if (__comp(__first1, __first2))
        ++__first1;
      else {
        ++__first1;
        ++__first2;
      }

    return __first2 == __last2;
  }
  template <typename _InputIterator1, typename _InputIterator2>
  inline bool includes(_InputIterator1 __first1, _InputIterator1 __last1,
                       _InputIterator2 __first2, _InputIterator2 __last2) {
    ;
    ;
    ;
    ;

    return std::__includes(__first1, __last1, __first2, __last2,
                           __gnu_cxx::__ops::__iter_less_iter());
  }
  template <typename _InputIterator1, typename _InputIterator2,
            typename _Compare>
  inline bool includes(_InputIterator1 __first1, _InputIterator1 __last1,
                       _InputIterator2 __first2, _InputIterator2 __last2,
                       _Compare __comp) {
    ;
    ;
    ;
    ;

    return std::__includes(__first1, __last1, __first2, __last2,
                           __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }
  template <typename _BidirectionalIterator, typename _Compare>
  bool __next_permutation(_BidirectionalIterator __first,
                          _BidirectionalIterator __last, _Compare __comp) {
    if (__first == __last)
      return false;
    _BidirectionalIterator __i = __first;
    ++__i;
    if (__i == __last)
      return false;
    __i = __last;
    --__i;

    for (;;) {
      _BidirectionalIterator __ii = __i;
      --__i;
      if (__comp(__i, __ii)) {
        _BidirectionalIterator __j = __last;
        while (!__comp(__i, --__j)) {
        }
        std::iter_swap(__i, __j);
        std::__reverse(__ii, __last, std::__iterator_category(__first));
        return true;
      }
      if (__i == __first) {
        std::__reverse(__first, __last, std::__iterator_category(__first));
        return false;
      }
    }
  }
  template <typename _BidirectionalIterator>
  inline bool next_permutation(_BidirectionalIterator __first,
                               _BidirectionalIterator __last) {
    ;
    ;

    return std::__next_permutation(__first, __last,
                                   __gnu_cxx::__ops::__iter_less_iter());
  }
  template <typename _BidirectionalIterator, typename _Compare>
  inline bool next_permutation(_BidirectionalIterator __first,
                               _BidirectionalIterator __last, _Compare __comp) {
    ;
    ;

    return std::__next_permutation(__first, __last,
                                   __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }

  template <typename _BidirectionalIterator, typename _Compare>
  bool __prev_permutation(_BidirectionalIterator __first,
                          _BidirectionalIterator __last, _Compare __comp) {
    if (__first == __last)
      return false;
    _BidirectionalIterator __i = __first;
    ++__i;
    if (__i == __last)
      return false;
    __i = __last;
    --__i;

    for (;;) {
      _BidirectionalIterator __ii = __i;
      --__i;
      if (__comp(__ii, __i)) {
        _BidirectionalIterator __j = __last;
        while (!__comp(--__j, __i)) {
        }
        std::iter_swap(__i, __j);
        std::__reverse(__ii, __last, std::__iterator_category(__first));
        return true;
      }
      if (__i == __first) {
        std::__reverse(__first, __last, std::__iterator_category(__first));
        return false;
      }
    }
  }
  template <typename _BidirectionalIterator>
  inline bool prev_permutation(_BidirectionalIterator __first,
                               _BidirectionalIterator __last) {
    ;
    ;

    return std::__prev_permutation(__first, __last,
                                   __gnu_cxx::__ops::__iter_less_iter());
  }
  template <typename _BidirectionalIterator, typename _Compare>
  inline bool prev_permutation(_BidirectionalIterator __first,
                               _BidirectionalIterator __last, _Compare __comp) {
    ;
    ;

    return std::__prev_permutation(__first, __last,
                                   __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }

  template <typename _InputIterator, typename _OutputIterator,
            typename _Predicate, typename _Tp>
  _OutputIterator __replace_copy_if(
      _InputIterator __first, _InputIterator __last, _OutputIterator __result,
      _Predicate __pred, const _Tp& __new_value) {
    for (; __first != __last; ++__first, (void)++__result)
      if (__pred(__first))
        *__result = __new_value;
      else
        *__result = *__first;
    return __result;
  }
  template <typename _InputIterator, typename _OutputIterator, typename _Tp>
  inline _OutputIterator replace_copy(
      _InputIterator __first, _InputIterator __last, _OutputIterator __result,
      const _Tp& __old_value, const _Tp& __new_value) {
    ;

    return std::__replace_copy_if(
        __first, __last, __result,
        __gnu_cxx::__ops::__iter_equals_val(__old_value), __new_value);
  }
  template <typename _InputIterator, typename _OutputIterator,
            typename _Predicate, typename _Tp>
  inline _OutputIterator replace_copy_if(
      _InputIterator __first, _InputIterator __last, _OutputIterator __result,
      _Predicate __pred, const _Tp& __new_value) {
    ;

    return std::__replace_copy_if(__first, __last, __result,
                                  __gnu_cxx::__ops::__pred_iter(__pred),
                                  __new_value);
  }

  template <typename _InputIterator, typename _Predicate>
  typename iterator_traits<_InputIterator>::difference_type __count_if(
      _InputIterator __first, _InputIterator __last, _Predicate __pred) {
    typename iterator_traits<_InputIterator>::difference_type __n = 0;
    for (; __first != __last; ++__first)
      if (__pred(__first))
        ++__n;
    return __n;
  }
  template <typename _ForwardIterator>
  inline bool is_sorted(_ForwardIterator __first, _ForwardIterator __last) {
    return std::is_sorted_until(__first, __last) == __last;
  }
  template <typename _ForwardIterator, typename _Compare>
  inline bool is_sorted(_ForwardIterator __first, _ForwardIterator __last,
                        _Compare __comp) {
    return std::is_sorted_until(__first, __last, __comp) == __last;
  }

  template <typename _ForwardIterator, typename _Compare>
  _ForwardIterator __is_sorted_until(_ForwardIterator __first,
                                     _ForwardIterator __last, _Compare __comp) {
    if (__first == __last)
      return __last;

    _ForwardIterator __next = __first;
    for (++__next; __next != __last; __first = __next, (void)++__next)
      if (__comp(__next, __first))
        return __next;
    return __next;
  }
  template <typename _ForwardIterator>
  inline _ForwardIterator is_sorted_until(_ForwardIterator __first,
                                          _ForwardIterator __last) {
    ;
    ;

    return std::__is_sorted_until(__first, __last,
                                  __gnu_cxx::__ops::__iter_less_iter());
  }
  template <typename _ForwardIterator, typename _Compare>
  inline _ForwardIterator is_sorted_until(
      _ForwardIterator __first, _ForwardIterator __last, _Compare __comp) {
    ;
    ;

    return std::__is_sorted_until(__first, __last,
                                  __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }
  template <typename _Tp>
  constexpr inline pair<const _Tp&, const _Tp&> minmax(const _Tp& __a,
                                                       const _Tp& __b) {
    return __b < __a ? pair<const _Tp&, const _Tp&>(__b, __a)
                     : pair<const _Tp&, const _Tp&>(__a, __b);
  }
  template <typename _Tp, typename _Compare>
  constexpr inline pair<const _Tp&, const _Tp&> minmax(
      const _Tp& __a, const _Tp& __b, _Compare __comp) {
    return __comp(__b, __a) ? pair<const _Tp&, const _Tp&>(__b, __a)
                            : pair<const _Tp&, const _Tp&>(__a, __b);
  }

  template <typename _ForwardIterator, typename _Compare>
  constexpr pair<_ForwardIterator, _ForwardIterator> __minmax_element(
      _ForwardIterator __first, _ForwardIterator __last, _Compare __comp) {
    _ForwardIterator __next = __first;
    if (__first == __last || ++__next == __last)
      return std::make_pair(__first, __first);

    _ForwardIterator __min{}, __max{};
    if (__comp(__next, __first)) {
      __min = __next;
      __max = __first;
    } else {
      __min = __first;
      __max = __next;
    }

    __first = __next;
    ++__first;

    while (__first != __last) {
      __next = __first;
      if (++__next == __last) {
        if (__comp(__first, __min))
          __min = __first;
        else if (!__comp(__first, __max))
          __max = __first;
        break;
      }

      if (__comp(__next, __first)) {
        if (__comp(__next, __min))
          __min = __next;
        if (!__comp(__first, __max))
          __max = __first;
      } else {
        if (__comp(__first, __min))
          __min = __first;
        if (!__comp(__next, __max))
          __max = __next;
      }

      __first = __next;
      ++__first;
    }

    return std::make_pair(__min, __max);
  }
  template <typename _ForwardIterator>
  constexpr inline pair<_ForwardIterator, _ForwardIterator> minmax_element(
      _ForwardIterator __first, _ForwardIterator __last) {
    ;
    ;

    return std::__minmax_element(__first, __last,
                                 __gnu_cxx::__ops::__iter_less_iter());
  }
  template <typename _ForwardIterator, typename _Compare>
  constexpr inline pair<_ForwardIterator, _ForwardIterator> minmax_element(
      _ForwardIterator __first, _ForwardIterator __last, _Compare __comp) {
    ;
    ;

    return std::__minmax_element(__first, __last,
                                 __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }

  template <typename _Tp>
  constexpr inline _Tp min(initializer_list<_Tp> __l) {
    return *std::min_element(__l.begin(), __l.end());
  }

  template <typename _Tp, typename _Compare>
  constexpr inline _Tp min(initializer_list<_Tp> __l, _Compare __comp) {
    return *std::min_element(__l.begin(), __l.end(), __comp);
  }

  template <typename _Tp>
  constexpr inline _Tp max(initializer_list<_Tp> __l) {
    return *std::max_element(__l.begin(), __l.end());
  }

  template <typename _Tp, typename _Compare>
  constexpr inline _Tp max(initializer_list<_Tp> __l, _Compare __comp) {
    return *std::max_element(__l.begin(), __l.end(), __comp);
  }

  template <typename _Tp>
  constexpr inline pair<_Tp, _Tp> minmax(initializer_list<_Tp> __l) {
    pair<const _Tp*, const _Tp*> __p =
        std::minmax_element(__l.begin(), __l.end());
    return std::make_pair(*__p.first, *__p.second);
  }

  template <typename _Tp, typename _Compare>
  constexpr inline pair<_Tp, _Tp> minmax(initializer_list<_Tp> __l,
                                         _Compare __comp) {
    pair<const _Tp*, const _Tp*> __p =
        std::minmax_element(__l.begin(), __l.end(), __comp);
    return std::make_pair(*__p.first, *__p.second);
  }

  template <typename _ForwardIterator1, typename _ForwardIterator2,
            typename _BinaryPredicate>
  bool __is_permutation(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
                        _ForwardIterator2 __first2, _BinaryPredicate __pred) {
    for (; __first1 != __last1; ++__first1, (void)++__first2)
      if (!__pred(__first1, __first2))
        break;

    if (__first1 == __last1)
      return true;

    _ForwardIterator2 __last2 = __first2;
    std::advance(__last2, std::distance(__first1, __last1));
    for (_ForwardIterator1 __scan = __first1; __scan != __last1; ++__scan) {
      if (__scan !=
          std::__find_if(__first1, __scan,
                         __gnu_cxx::__ops::__iter_comp_iter(__pred, __scan)))
        continue;

      auto __matches =
          std::__count_if(__first2, __last2,
                          __gnu_cxx::__ops::__iter_comp_iter(__pred, __scan));
      if (0 == __matches || std::__count_if(__scan, __last1,
                                            __gnu_cxx::__ops::__iter_comp_iter(
                                                __pred, __scan)) != __matches)
        return false;
    }
    return true;
  }
  template <typename _ForwardIterator1, typename _ForwardIterator2>
  inline bool is_permutation(_ForwardIterator1 __first1,
                             _ForwardIterator1 __last1,
                             _ForwardIterator2 __first2) {
    ;

    return std::__is_permutation(__first1, __last1, __first2,
                                 __gnu_cxx::__ops::__iter_equal_to_iter());
  }
  template <typename _ForwardIterator1, typename _ForwardIterator2,
            typename _BinaryPredicate>
  inline bool is_permutation(
      _ForwardIterator1 __first1, _ForwardIterator1 __last1,
      _ForwardIterator2 __first2, _BinaryPredicate __pred) {
    ;

    return std::__is_permutation(__first1, __last1, __first2,
                                 __gnu_cxx::__ops::__iter_comp_iter(__pred));
  }

  template <typename _ForwardIterator1, typename _ForwardIterator2,
            typename _BinaryPredicate>
  bool __is_permutation(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
                        _ForwardIterator2 __first2, _ForwardIterator2 __last2,
                        _BinaryPredicate __pred) {
    using _Cat1 =
        typename iterator_traits<_ForwardIterator1>::iterator_category;
    using _Cat2 =
        typename iterator_traits<_ForwardIterator2>::iterator_category;
    using _It1_is_RA = is_same<_Cat1, random_access_iterator_tag>;
    using _It2_is_RA = is_same<_Cat2, random_access_iterator_tag>;
    constexpr bool __ra_iters = _It1_is_RA() && _It2_is_RA();
    if (__ra_iters) {
      auto __d1 = std::distance(__first1, __last1);
      auto __d2 = std::distance(__first2, __last2);
      if (__d1 != __d2)
        return false;
    }

    for (; __first1 != __last1 && __first2 != __last2;
         ++__first1, (void)++__first2)
      if (!__pred(__first1, __first2))
        break;

    if (__ra_iters) {
      if (__first1 == __last1)
        return true;
    } else {
      auto __d1 = std::distance(__first1, __last1);
      auto __d2 = std::distance(__first2, __last2);
      if (__d1 == 0 && __d2 == 0)
        return true;
      if (__d1 != __d2)
        return false;
    }

    for (_ForwardIterator1 __scan = __first1; __scan != __last1; ++__scan) {
      if (__scan !=
          std::__find_if(__first1, __scan,
                         __gnu_cxx::__ops::__iter_comp_iter(__pred, __scan)))
        continue;

      auto __matches =
          std::__count_if(__first2, __last2,
                          __gnu_cxx::__ops::__iter_comp_iter(__pred, __scan));
      if (0 == __matches || std::__count_if(__scan, __last1,
                                            __gnu_cxx::__ops::__iter_comp_iter(
                                                __pred, __scan)) != __matches)
        return false;
    }
    return true;
  }
  template <typename _ForwardIterator1, typename _ForwardIterator2>
  inline bool is_permutation(
      _ForwardIterator1 __first1, _ForwardIterator1 __last1,
      _ForwardIterator2 __first2, _ForwardIterator2 __last2) {
    ;
    ;

    return std::__is_permutation(__first1, __last1, __first2, __last2,
                                 __gnu_cxx::__ops::__iter_equal_to_iter());
  }
  template <typename _ForwardIterator1, typename _ForwardIterator2,
            typename _BinaryPredicate>
  inline bool is_permutation(
      _ForwardIterator1 __first1, _ForwardIterator1 __last1,
      _ForwardIterator2 __first2, _ForwardIterator2 __last2,
      _BinaryPredicate __pred) {
    ;
    ;

    return std::__is_permutation(__first1, __last1, __first2, __last2,
                                 __gnu_cxx::__ops::__iter_comp_iter(__pred));
  }
  template <typename _IntType, typename _UniformRandomBitGenerator>
  pair<_IntType, _IntType> __gen_two_uniform_ints(
      _IntType __b0, _IntType __b1, _UniformRandomBitGenerator && __g) {
    _IntType __x =
        uniform_int_distribution<_IntType>{0, (__b0 * __b1) - 1}(__g);
    return std::make_pair(__x / __b1, __x % __b1);
  }
  template <typename _RandomAccessIterator,
            typename _UniformRandomNumberGenerator>
  void shuffle(_RandomAccessIterator __first, _RandomAccessIterator __last,
               _UniformRandomNumberGenerator && __g) {
    ;

    if (__first == __last)
      return;

    typedef typename iterator_traits<_RandomAccessIterator>::difference_type
        _DistanceType;

    typedef typename std::make_unsigned<_DistanceType>::type __ud_type;
    typedef typename std::uniform_int_distribution<__ud_type> __distr_type;
    typedef typename __distr_type::param_type __p_type;

    typedef typename remove_reference<_UniformRandomNumberGenerator>::type _Gen;
    typedef typename common_type<typename _Gen::result_type, __ud_type>::type
        __uc_type;

    const __uc_type __urngrange = __g.max() - __g.min();
    const __uc_type __urange = __uc_type(__last - __first);

    if (__urngrange / __urange >= __urange)

    {
      _RandomAccessIterator __i = __first + 1;

      if ((__urange % 2) == 0) {
        __distr_type __d{0, 1};
        std::iter_swap(__i++, __first + __d(__g));
      }

      while (__i != __last) {
        const __uc_type __swap_range = __uc_type(__i - __first) + 1;

        const pair<__uc_type, __uc_type> __pospos =
            __gen_two_uniform_ints(__swap_range, __swap_range + 1, __g);

        std::iter_swap(__i++, __first + __pospos.first);
        std::iter_swap(__i++, __first + __pospos.second);
      }

      return;
    }

    __distr_type __d;

    for (_RandomAccessIterator __i = __first + 1; __i != __last; ++__i)
      std::iter_swap(__i, __first + __d(__g, __p_type(0, __i - __first)));
  }

  template <typename _InputIterator, typename _Function>
  _Function for_each(_InputIterator __first, _InputIterator __last,
                     _Function __f) {
    ;
    for (; __first != __last; ++__first)
      __f(*__first);
    return __f;
  }
  template <typename _InputIterator, typename _Tp>
  inline _InputIterator find(_InputIterator __first, _InputIterator __last,
                             const _Tp& __val) {
    ;
    return std::__find_if(__first, __last,
                          __gnu_cxx::__ops::__iter_equals_val(__val));
  }
  template <typename _InputIterator, typename _Predicate>
  inline _InputIterator find_if(_InputIterator __first, _InputIterator __last,
                                _Predicate __pred) {
    ;

    return std::__find_if(__first, __last,
                          __gnu_cxx::__ops::__pred_iter(__pred));
  }
  template <typename _InputIterator, typename _ForwardIterator>
  _InputIterator find_first_of(_InputIterator __first1, _InputIterator __last1,
                               _ForwardIterator __first2,
                               _ForwardIterator __last2) {
    ;
    ;

    for (; __first1 != __last1; ++__first1)
      for (_ForwardIterator __iter = __first2; __iter != __last2; ++__iter)
        if (*__first1 == *__iter)
          return __first1;
    return __last1;
  }
  template <typename _InputIterator, typename _ForwardIterator,
            typename _BinaryPredicate>
  _InputIterator find_first_of(_InputIterator __first1, _InputIterator __last1,
                               _ForwardIterator __first2,
                               _ForwardIterator __last2,
                               _BinaryPredicate __comp) {
    ;
    ;

    for (; __first1 != __last1; ++__first1)
      for (_ForwardIterator __iter = __first2; __iter != __last2; ++__iter)
        if (__comp(*__first1, *__iter))
          return __first1;
    return __last1;
  }
  template <typename _ForwardIterator>
  inline _ForwardIterator adjacent_find(_ForwardIterator __first,
                                        _ForwardIterator __last) {
    ;

    return std::__adjacent_find(__first, __last,
                                __gnu_cxx::__ops::__iter_equal_to_iter());
  }
  template <typename _ForwardIterator, typename _BinaryPredicate>
  inline _ForwardIterator adjacent_find(_ForwardIterator __first,
                                        _ForwardIterator __last,
                                        _BinaryPredicate __binary_pred) {
    ;

    return std::__adjacent_find(
        __first, __last, __gnu_cxx::__ops::__iter_comp_iter(__binary_pred));
  }
  template <typename _InputIterator, typename _Tp>
  inline typename iterator_traits<_InputIterator>::difference_type count(
      _InputIterator __first, _InputIterator __last, const _Tp& __value) {
    ;

    return std::__count_if(__first, __last,
                           __gnu_cxx::__ops::__iter_equals_val(__value));
  }
  template <typename _InputIterator, typename _Predicate>
  inline typename iterator_traits<_InputIterator>::difference_type count_if(
      _InputIterator __first, _InputIterator __last, _Predicate __pred) {
    ;

    return std::__count_if(__first, __last,
                           __gnu_cxx::__ops::__pred_iter(__pred));
  }
  template <typename _ForwardIterator1, typename _ForwardIterator2>
  inline _ForwardIterator1 search(
      _ForwardIterator1 __first1, _ForwardIterator1 __last1,
      _ForwardIterator2 __first2, _ForwardIterator2 __last2) {
    ;
    ;

    return std::__search(__first1, __last1, __first2, __last2,
                         __gnu_cxx::__ops::__iter_equal_to_iter());
  }
  template <typename _ForwardIterator1, typename _ForwardIterator2,
            typename _BinaryPredicate>
  inline _ForwardIterator1 search(
      _ForwardIterator1 __first1, _ForwardIterator1 __last1,
      _ForwardIterator2 __first2, _ForwardIterator2 __last2,
      _BinaryPredicate __predicate) {
    ;
    ;

    return std::__search(__first1, __last1, __first2, __last2,
                         __gnu_cxx::__ops::__iter_comp_iter(__predicate));
  }
  template <typename _ForwardIterator, typename _Integer, typename _Tp>
  inline _ForwardIterator search_n(_ForwardIterator __first,
                                   _ForwardIterator __last, _Integer __count,
                                   const _Tp& __val) {
    ;

    return std::__search_n(__first, __last, __count,
                           __gnu_cxx::__ops::__iter_equals_val(__val));
  }
  template <typename _ForwardIterator, typename _Integer, typename _Tp,
            typename _BinaryPredicate>
  inline _ForwardIterator search_n(
      _ForwardIterator __first, _ForwardIterator __last, _Integer __count,
      const _Tp& __val, _BinaryPredicate __binary_pred) {
    ;

    return std::__search_n(
        __first, __last, __count,
        __gnu_cxx::__ops::__iter_comp_val(__binary_pred, __val));
  }
  template <typename _InputIterator, typename _OutputIterator,
            typename _UnaryOperation>
  _OutputIterator transform(_InputIterator __first, _InputIterator __last,
                            _OutputIterator __result,
                            _UnaryOperation __unary_op) {
    ;

    for (; __first != __last; ++__first, (void)++__result)
      *__result = __unary_op(*__first);
    return __result;
  }
  template <typename _InputIterator1, typename _InputIterator2,
            typename _OutputIterator, typename _BinaryOperation>
  _OutputIterator transform(_InputIterator1 __first1, _InputIterator1 __last1,
                            _InputIterator2 __first2, _OutputIterator __result,
                            _BinaryOperation __binary_op) {
    ;

    for (; __first1 != __last1; ++__first1, (void)++__first2, ++__result)
      *__result = __binary_op(*__first1, *__first2);
    return __result;
  }
  template <typename _ForwardIterator, typename _Tp>
  void replace(_ForwardIterator __first, _ForwardIterator __last,
               const _Tp& __old_value, const _Tp& __new_value) {
    ;

    for (; __first != __last; ++__first)
      if (*__first == __old_value)
        *__first = __new_value;
  }
  template <typename _ForwardIterator, typename _Predicate, typename _Tp>
  void replace_if(_ForwardIterator __first, _ForwardIterator __last,
                  _Predicate __pred, const _Tp& __new_value) {
    ;

    for (; __first != __last; ++__first)
      if (__pred(*__first))
        *__first = __new_value;
  }
  template <typename _ForwardIterator, typename _Generator>
  void generate(_ForwardIterator __first, _ForwardIterator __last,
                _Generator __gen) {
    ;

    for (; __first != __last; ++__first)
      *__first = __gen();
  }
  template <typename _OutputIterator, typename _Size, typename _Generator>
  _OutputIterator generate_n(_OutputIterator __first, _Size __n,
                             _Generator __gen) {
    for (__decltype(__n + 0) __niter = __n; __niter > 0; --__niter, ++__first)
      *__first = __gen();
    return __first;
  }
  template <typename _InputIterator, typename _OutputIterator>
  inline _OutputIterator unique_copy(
      _InputIterator __first, _InputIterator __last, _OutputIterator __result) {
    ;

    if (__first == __last)
      return __result;
    return std::__unique_copy(
        __first, __last, __result, __gnu_cxx::__ops::__iter_equal_to_iter(),
        std::__iterator_category(__first), std::__iterator_category(__result));
  }
  template <typename _InputIterator, typename _OutputIterator,
            typename _BinaryPredicate>
  inline _OutputIterator unique_copy(
      _InputIterator __first, _InputIterator __last, _OutputIterator __result,
      _BinaryPredicate __binary_pred) {
    ;

    if (__first == __last)
      return __result;
    return std::__unique_copy(__first, __last, __result,
                              __gnu_cxx::__ops::__iter_comp_iter(__binary_pred),
                              std::__iterator_category(__first),
                              std::__iterator_category(__result));
  }
  template <typename _RandomAccessIterator>
  inline void random_shuffle(_RandomAccessIterator __first,
                             _RandomAccessIterator __last) {
    ;

    if (__first != __last)
      for (_RandomAccessIterator __i = __first + 1; __i != __last; ++__i) {
        _RandomAccessIterator __j =
            __first + std::rand() % ((__i - __first) + 1);
        if (__i != __j)
          std::iter_swap(__i, __j);
      }
  }
  template <typename _RandomAccessIterator, typename _RandomNumberGenerator>
  void random_shuffle(_RandomAccessIterator __first,
                      _RandomAccessIterator __last,

                      _RandomNumberGenerator && __rand)

  {
    ;

    if (__first == __last)
      return;
    for (_RandomAccessIterator __i = __first + 1; __i != __last; ++__i) {
      _RandomAccessIterator __j = __first + __rand((__i - __first) + 1);
      if (__i != __j)
        std::iter_swap(__i, __j);
    }
  }
  template <typename _ForwardIterator, typename _Predicate>
  inline _ForwardIterator partition(
      _ForwardIterator __first, _ForwardIterator __last, _Predicate __pred) {
    ;

    return std::__partition(__first, __last, __pred,
                            std::__iterator_category(__first));
  }
  template <typename _RandomAccessIterator>
  inline void partial_sort(_RandomAccessIterator __first,
                           _RandomAccessIterator __middle,
                           _RandomAccessIterator __last) {
    ;
    ;
    ;

    std::__partial_sort(__first, __middle, __last,
                        __gnu_cxx::__ops::__iter_less_iter());
  }
  template <typename _RandomAccessIterator, typename _Compare>
  inline void partial_sort(_RandomAccessIterator __first,
                           _RandomAccessIterator __middle,
                           _RandomAccessIterator __last, _Compare __comp) {
    ;
    ;
    ;

    std::__partial_sort(__first, __middle, __last,
                        __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }
  template <typename _RandomAccessIterator>
  inline void nth_element(_RandomAccessIterator __first,
                          _RandomAccessIterator __nth,
                          _RandomAccessIterator __last) {
    ;
    ;
    ;

    if (__first == __last || __nth == __last)
      return;

    std::__introselect(__first, __nth, __last, std::__lg(__last - __first) * 2,
                       __gnu_cxx::__ops::__iter_less_iter());
  }
  template <typename _RandomAccessIterator, typename _Compare>
  inline void nth_element(_RandomAccessIterator __first,
                          _RandomAccessIterator __nth,
                          _RandomAccessIterator __last, _Compare __comp) {
    ;
    ;
    ;

    if (__first == __last || __nth == __last)
      return;

    std::__introselect(__first, __nth, __last, std::__lg(__last - __first) * 2,
                       __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }
  template <typename _RandomAccessIterator>
  inline void sort(_RandomAccessIterator __first,
                   _RandomAccessIterator __last) {
    ;
    ;

    std::__sort(__first, __last, __gnu_cxx::__ops::__iter_less_iter());
  }
  template <typename _RandomAccessIterator, typename _Compare>
  inline void sort(_RandomAccessIterator __first, _RandomAccessIterator __last,
                   _Compare __comp) {
    ;
    ;

    std::__sort(__first, __last, __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }

  template <typename _InputIterator1, typename _InputIterator2,
            typename _OutputIterator, typename _Compare>
  _OutputIterator __merge(_InputIterator1 __first1, _InputIterator1 __last1,
                          _InputIterator2 __first2, _InputIterator2 __last2,
                          _OutputIterator __result, _Compare __comp) {
    while (__first1 != __last1 && __first2 != __last2) {
      if (__comp(__first2, __first1)) {
        *__result = *__first2;
        ++__first2;
      } else {
        *__result = *__first1;
        ++__first1;
      }
      ++__result;
    }
    return std::copy(__first2, __last2, std::copy(__first1, __last1, __result));
  }
  template <typename _InputIterator1, typename _InputIterator2,
            typename _OutputIterator>
  inline _OutputIterator merge(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2,
      _OutputIterator __result) {
    ;
    ;
    ;
    ;

    return std::__merge(__first1, __last1, __first2, __last2, __result,
                        __gnu_cxx::__ops::__iter_less_iter());
  }
  template <typename _InputIterator1, typename _InputIterator2,
            typename _OutputIterator, typename _Compare>
  inline _OutputIterator merge(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2,
      _OutputIterator __result, _Compare __comp) {
    ;
    ;
    ;
    ;

    return std::__merge(__first1, __last1, __first2, __last2, __result,
                        __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }

  template <typename _RandomAccessIterator, typename _Compare>
  inline void __stable_sort(_RandomAccessIterator __first,
                            _RandomAccessIterator __last, _Compare __comp) {
    typedef
        typename iterator_traits<_RandomAccessIterator>::value_type _ValueType;
    typedef typename iterator_traits<_RandomAccessIterator>::difference_type
        _DistanceType;

    typedef _Temporary_buffer<_RandomAccessIterator, _ValueType> _TmpBuf;
    _TmpBuf __buf(__first, __last);

    if (__buf.begin() == 0)
      std::__inplace_stable_sort(__first, __last, __comp);
    else
      std::__stable_sort_adaptive(__first, __last, __buf.begin(),
                                  _DistanceType(__buf.size()), __comp);
  }
  template <typename _RandomAccessIterator>
  inline void stable_sort(_RandomAccessIterator __first,
                          _RandomAccessIterator __last) {
    ;
    ;

    std::__stable_sort(__first, __last, __gnu_cxx::__ops::__iter_less_iter());
  }
  template <typename _RandomAccessIterator, typename _Compare>
  inline void stable_sort(_RandomAccessIterator __first,
                          _RandomAccessIterator __last, _Compare __comp) {
    ;
    ;

    std::__stable_sort(__first, __last,
                       __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }

  template <typename _InputIterator1, typename _InputIterator2,
            typename _OutputIterator, typename _Compare>
  _OutputIterator __set_union(_InputIterator1 __first1, _InputIterator1 __last1,
                              _InputIterator2 __first2, _InputIterator2 __last2,
                              _OutputIterator __result, _Compare __comp) {
    while (__first1 != __last1 && __first2 != __last2) {
      if (__comp(__first1, __first2)) {
        *__result = *__first1;
        ++__first1;
      } else if (__comp(__first2, __first1)) {
        *__result = *__first2;
        ++__first2;
      } else {
        *__result = *__first1;
        ++__first1;
        ++__first2;
      }
      ++__result;
    }
    return std::copy(__first2, __last2, std::copy(__first1, __last1, __result));
  }
  template <typename _InputIterator1, typename _InputIterator2,
            typename _OutputIterator>
  inline _OutputIterator set_union(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2,
      _OutputIterator __result) {
    ;
    ;
    ;
    ;

    return std::__set_union(__first1, __last1, __first2, __last2, __result,
                            __gnu_cxx::__ops::__iter_less_iter());
  }
  template <typename _InputIterator1, typename _InputIterator2,
            typename _OutputIterator, typename _Compare>
  inline _OutputIterator set_union(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2,
      _OutputIterator __result, _Compare __comp) {
    ;
    ;
    ;
    ;

    return std::__set_union(__first1, __last1, __first2, __last2, __result,
                            __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }

  template <typename _InputIterator1, typename _InputIterator2,
            typename _OutputIterator, typename _Compare>
  _OutputIterator __set_intersection(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2,
      _OutputIterator __result, _Compare __comp) {
    while (__first1 != __last1 && __first2 != __last2)
      if (__comp(__first1, __first2))
        ++__first1;
      else if (__comp(__first2, __first1))
        ++__first2;
      else {
        *__result = *__first1;
        ++__first1;
        ++__first2;
        ++__result;
      }
    return __result;
  }
  template <typename _InputIterator1, typename _InputIterator2,
            typename _OutputIterator>
  inline _OutputIterator set_intersection(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2,
      _OutputIterator __result) {
    ;
    ;
    ;
    ;

    return std::__set_intersection(__first1, __last1, __first2, __last2,
                                   __result,
                                   __gnu_cxx::__ops::__iter_less_iter());
  }
  template <typename _InputIterator1, typename _InputIterator2,
            typename _OutputIterator, typename _Compare>
  inline _OutputIterator set_intersection(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2,
      _OutputIterator __result, _Compare __comp) {
    ;
    ;
    ;
    ;

    return std::__set_intersection(__first1, __last1, __first2, __last2,
                                   __result,
                                   __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }

  template <typename _InputIterator1, typename _InputIterator2,
            typename _OutputIterator, typename _Compare>
  _OutputIterator __set_difference(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2,
      _OutputIterator __result, _Compare __comp) {
    while (__first1 != __last1 && __first2 != __last2)
      if (__comp(__first1, __first2)) {
        *__result = *__first1;
        ++__first1;
        ++__result;
      } else if (__comp(__first2, __first1))
        ++__first2;
      else {
        ++__first1;
        ++__first2;
      }
    return std::copy(__first1, __last1, __result);
  }
  template <typename _InputIterator1, typename _InputIterator2,
            typename _OutputIterator>
  inline _OutputIterator set_difference(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2,
      _OutputIterator __result) {
    ;
    ;
    ;
    ;

    return std::__set_difference(__first1, __last1, __first2, __last2, __result,
                                 __gnu_cxx::__ops::__iter_less_iter());
  }
  template <typename _InputIterator1, typename _InputIterator2,
            typename _OutputIterator, typename _Compare>
  inline _OutputIterator set_difference(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2,
      _OutputIterator __result, _Compare __comp) {
    ;
    ;
    ;
    ;

    return std::__set_difference(__first1, __last1, __first2, __last2, __result,
                                 __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }

  template <typename _InputIterator1, typename _InputIterator2,
            typename _OutputIterator, typename _Compare>
  _OutputIterator __set_symmetric_difference(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2,
      _OutputIterator __result, _Compare __comp) {
    while (__first1 != __last1 && __first2 != __last2)
      if (__comp(__first1, __first2)) {
        *__result = *__first1;
        ++__first1;
        ++__result;
      } else if (__comp(__first2, __first1)) {
        *__result = *__first2;
        ++__first2;
        ++__result;
      } else {
        ++__first1;
        ++__first2;
      }
    return std::copy(__first2, __last2, std::copy(__first1, __last1, __result));
  }
  template <typename _InputIterator1, typename _InputIterator2,
            typename _OutputIterator>
  inline _OutputIterator set_symmetric_difference(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2,
      _OutputIterator __result) {
    ;
    ;
    ;
    ;

    return std::__set_symmetric_difference(
        __first1, __last1, __first2, __last2, __result,
        __gnu_cxx::__ops::__iter_less_iter());
  }
  template <typename _InputIterator1, typename _InputIterator2,
            typename _OutputIterator, typename _Compare>
  inline _OutputIterator set_symmetric_difference(
      _InputIterator1 __first1, _InputIterator1 __last1,
      _InputIterator2 __first2, _InputIterator2 __last2,
      _OutputIterator __result, _Compare __comp) {
    ;
    ;
    ;
    ;

    return std::__set_symmetric_difference(
        __first1, __last1, __first2, __last2, __result,
        __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }

  template <typename _ForwardIterator, typename _Compare>
  constexpr _ForwardIterator __min_element(
      _ForwardIterator __first, _ForwardIterator __last, _Compare __comp) {
    if (__first == __last)
      return __first;
    _ForwardIterator __result = __first;
    while (++__first != __last)
      if (__comp(__first, __result))
        __result = __first;
    return __result;
  }
  template <typename _ForwardIterator>
  constexpr _ForwardIterator inline min_element(_ForwardIterator __first,
                                                _ForwardIterator __last) {
    ;
    ;

    return std::__min_element(__first, __last,
                              __gnu_cxx::__ops::__iter_less_iter());
  }
  template <typename _ForwardIterator, typename _Compare>
  constexpr inline _ForwardIterator min_element(
      _ForwardIterator __first, _ForwardIterator __last, _Compare __comp) {
    ;
    ;

    return std::__min_element(__first, __last,
                              __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }

  template <typename _ForwardIterator, typename _Compare>
  constexpr _ForwardIterator __max_element(
      _ForwardIterator __first, _ForwardIterator __last, _Compare __comp) {
    if (__first == __last)
      return __first;
    _ForwardIterator __result = __first;
    while (++__first != __last)
      if (__comp(__result, __first))
        __result = __first;
    return __result;
  }
  template <typename _ForwardIterator>
  constexpr inline _ForwardIterator max_element(_ForwardIterator __first,
                                                _ForwardIterator __last) {
    ;
    ;

    return std::__max_element(__first, __last,
                              __gnu_cxx::__ops::__iter_less_iter());
  }
  template <typename _ForwardIterator, typename _Compare>
  constexpr inline _ForwardIterator max_element(
      _ForwardIterator __first, _ForwardIterator __last, _Compare __comp) {
    ;
    ;

    return std::__max_element(__first, __last,
                              __gnu_cxx::__ops::__iter_comp_iter(__comp));
  }

  template <typename _InputIterator, typename _RandomAccessIterator,
            typename _Size, typename _UniformRandomBitGenerator>
  _RandomAccessIterator __sample(
      _InputIterator __first, _InputIterator __last, input_iterator_tag,
      _RandomAccessIterator __out, random_access_iterator_tag, _Size __n,
      _UniformRandomBitGenerator && __g) {
    using __distrib_type = uniform_int_distribution<_Size>;
    using __param_type = typename __distrib_type::param_type;
    __distrib_type __d{};
    _Size __sample_sz = 0;
    while (__first != __last && __sample_sz != __n) {
      __out[__sample_sz++] = *__first;
      ++__first;
    }
    for (auto __pop_sz = __sample_sz; __first != __last;
         ++__first, (void)++__pop_sz) {
      const auto __k = __d(__g, __param_type{0, __pop_sz});
      if (__k < __n)
        __out[__k] = *__first;
    }
    return __out + __sample_sz;
  }

  template <typename _ForwardIterator, typename _OutputIterator, typename _Cat,
            typename _Size, typename _UniformRandomBitGenerator>
  _OutputIterator __sample(_ForwardIterator __first, _ForwardIterator __last,
                           forward_iterator_tag, _OutputIterator __out, _Cat,
                           _Size __n, _UniformRandomBitGenerator && __g) {
    using __distrib_type = uniform_int_distribution<_Size>;
    using __param_type = typename __distrib_type::param_type;
    using _USize = make_unsigned_t<_Size>;
    using _Gen = remove_reference_t<_UniformRandomBitGenerator>;
    using __uc_type = common_type_t<typename _Gen::result_type, _USize>;

    __distrib_type __d{};
    _Size __unsampled_sz = std::distance(__first, __last);
    __n = std::min(__n, __unsampled_sz);

    const __uc_type __urngrange = __g.max() - __g.min();
    if (__urngrange / __uc_type(__unsampled_sz) >= __uc_type(__unsampled_sz))

    {
      while (__n != 0 && __unsampled_sz >= 2) {
        const pair<_Size, _Size> __p =
            __gen_two_uniform_ints(__unsampled_sz, __unsampled_sz - 1, __g);

        --__unsampled_sz;
        if (__p.first < __n) {
          *__out++ = *__first;
          --__n;
        }

        ++__first;

        if (__n == 0)
          break;

        --__unsampled_sz;
        if (__p.second < __n) {
          *__out++ = *__first;
          --__n;
        }

        ++__first;
      }
    }

    for (; __n != 0; ++__first)
      if (__d(__g, __param_type{0, --__unsampled_sz}) < __n) {
        *__out++ = *__first;
        --__n;
      }
    return __out;
  }

}  // namespace std__attribute__((__visibility__("default")))

template <typename T>
T byte_order_to_le(T x) {
  return x;
}
template <typename T>
T byte_order_from_le(T x) {
  return x;
}

typedef uint64_t u64;
typedef uint32_t u32;
typedef int64_t i64;
typedef int32_t i32;
typedef float f32;
typedef double f64;
typedef uint16_t u16;
typedef int16_t i16;
typedef uint8_t u8;
typedef int8_t i8;

struct First {};

template <typename field>
struct calcStaticOffset {
  enum {
    V = field::staticSize + calcStaticOffset<typename field::previous>::V
  };
};

template <>
struct calcStaticOffset<First> {
  enum { V = 0 };
};

template <typename field>
struct calcDynamicOffset {
  enum {
    V = field::headerSize + calcDynamicOffset<typename field::previous>::V
  };
};

template <>
struct calcDynamicOffset<First> {
  enum { V = 0 };
};

struct __Last {
  typedef __Last F;
  typedef __Last N;
};
struct __LastRecursive {
  typedef __LastRecursive F;
  typedef __LastRecursive N;
};
struct __Finish {
  typedef __Finish F;
  typedef __Finish N;
};

class SerializedData;

class RecordConstructor {
 public:
  RecordConstructor(SerializedData* data, size_t staticSize, size_t headerSize);

  char* staticData(size_t size);
  char* dynamicData(size_t size);
  void finishDynamicSize();

  RecordConstructor* beginNested(u16 id,
                                 size_t staticSize,
                                 size_t headerSize,
                                 bool last);
  RecordConstructor* finishNested();

  SerializedData* root();

 protected:
  SerializedData* data;

  size_t dynamicOffset;

  std::vector<size_t> staticOffset;
  std::vector<size_t> dynamicSizeOffset;
  std::vector<bool> finishDynamic;
};

template <int recordId, typename self>
struct Record {
  enum { ID = recordId };

  template <typename type, typename parent>
  struct Field {
    typedef type T;
    typedef bool isField;

    enum {
      staticOffset = calcStaticOffset<parent>::V,
      dynamicOffset = calcDynamicOffset<parent>::V,
      headerSize = 0,
      staticSize = sizeof(T)
    };

    typedef parent previous;
    typedef self record;
  };

  template <typename type, typename parent>
  struct Vector {
    typedef type Tv;
    typedef type* V;
    typedef bool isVector;

    enum {
      staticOffset = calcStaticOffset<parent>::V,
      dynamicOffset = calcDynamicOffset<parent>::V,
      headerSize = 1,
      staticSize = 0
    };

    typedef parent previous;
    typedef self record;
  };

  template <typename notused, typename parent>
  struct Any {
    typedef bool isAny;

    enum {
      staticOffset = calcStaticOffset<parent>::V,
      dynamicOffset = calcDynamicOffset<parent>::V,
      headerSize = 1,
      staticSize = 0
    };

    typedef parent previous;
    typedef self record;
  };

  template <typename notused, typename parent>
  struct Void {
    typedef bool isVoid;

    enum {
      staticOffset = calcStaticOffset<parent>::V,
      dynamicOffset = calcDynamicOffset<parent>::V,
      headerSize = 0,
      staticSize = 0
    };

    typedef parent previous;
    typedef self record;
  };

  template <typename notused, typename parent>
  struct AnyVector {
    typedef bool isAnyVector;

    enum {
      staticOffset = calcStaticOffset<parent>::V,
      dynamicOffset = calcDynamicOffset<parent>::V,
      headerSize = 1,
      staticSize = 0
    };

    typedef parent previous;
    typedef self record;
  };
};

struct SerializedException {};
struct WrongType : SerializedException {};
struct WrongIndex : SerializedException {};

template <typename Field, typename Next, typename Dummy = void>
class ValueSetter {};
typedef ValueSetter<__LastRecursive, SerializedData*> LastRecursive;

template <typename T>
class stringConvert {
 public:
  typedef T IteratorType;

  stringConvert(T& in);

  IteratorType begin();
  IteratorType end();
};

template <typename T>
class vectorConvert {
 public:
  typedef T IteratorType;

  vectorConvert(T& in);

  IteratorType begin();
  IteratorType end();
};
template <typename T>
class vectorConvert<::std::vector<T>> {
 public:
  typedef typename ::std::vector<T>::const_iterator IteratorType;

  vectorConvert(::std::vector<T>& in) : vec(in) {}

  IteratorType begin() { return vec.begin(); }

  IteratorType end() { return vec.end(); }

 private:
  ::std::vector<T>& vec;
};

template <typename T>
struct VectorContainer {
  VectorContainer(T* data, ::std::size_t size) : data(data), size(size) {}

  T* data;
  ::std::size_t size;
};

template <typename T>
class vectorConvert<VectorContainer<T>> {
 public:
  typedef T* IteratorType;

  vectorConvert(VectorContainer<T> in) : vec(in) {}

  IteratorType begin() { return vec.data; }

  IteratorType end() { return vec.data + vec.size; }

 private:
  VectorContainer<T> vec;
};
template <>
class vectorConvert<::std::string> {
 public:
  typedef std::string::const_iterator IteratorType;

  vectorConvert(::std::string& in) : str(in) {}

  IteratorType begin() { return str.begin(); }

  IteratorType end() { return str.end(); }

 private:
  ::std::string& str;
};

template <>
class vectorConvert<const char*> {
 public:
  typedef const char* IteratorType;

  vectorConvert(const char*& in) : str(in) {}

  IteratorType begin() { return str; }

  IteratorType end() { return str + strlen(str); }

 private:
  const char* str;
};

template <>
class vectorConvert<char*> {
 public:
  typedef char* IteratorType;

  vectorConvert(char*& in) : str(in) {}

  IteratorType begin() { return str; }

  IteratorType end() { return str + strlen(str); }

 private:
  char* str;
};
struct PODcontainer : Record<0 + 1, PODcontainer> {
  struct I8 : Field<i8, First> {};
  struct U64 : Field<u64, I8> {};
  enum {
    headerSize = 0 + I8::headerSize + U64::headerSize,
    staticSize = 0 + sizeof(I8::T) + sizeof(U64::T)
  };
  template <typename Continue>
  struct constructor {
    typedef ValueSetter<PODcontainer::I8,
                        ValueSetter<PODcontainer::U64, Continue>>
        type;
  };
  typedef ValueSetter<
      PODcontainer::I8,
      ValueSetter<PODcontainer::U64,
                  ValueSetter<__LastRecursive, __LastRecursive>>>
      recursive;
  static PODcontainer::constructor<ValueSetter<__Last, __Last>>::type create();
  static recursive createRecursive();
};
struct OneBool : Record<1 + 1, OneBool> {
  struct B : Field<bool, First> {};
  enum { headerSize = 0 + B::headerSize, staticSize = 0 + sizeof(B::T) };
  template <typename Continue>
  struct constructor {
    typedef ValueSetter<OneBool::B, Continue> type;
  };
  typedef ValueSetter<OneBool::B, ValueSetter<__LastRecursive, __LastRecursive>>
      recursive;
  static OneBool::constructor<ValueSetter<__Last, __Last>>::type create();
  static recursive createRecursive();
};
struct Empty : Record<2 + 1, Empty> {
  struct __void : Void<First, First> {};
  enum { headerSize = 0 + __void::headerSize, staticSize = 0 };
  template <typename Continue>
  struct constructor {
    typedef ValueSetter<Empty::__void, Continue> type;
  };
  typedef ValueSetter<Empty::__void,
                      ValueSetter<__LastRecursive, __LastRecursive>>
      recursive;
  static Empty::constructor<ValueSetter<__Last, __Last>>::type create();
  static recursive createRecursive();
};
struct PodVector : Record<3 + 1, PodVector> {
  struct vals : Vector<i32, First> {};
  enum { headerSize = 0 + vals::headerSize, staticSize = 0 };
  template <typename Continue>
  struct constructor {
    typedef ValueSetter<PodVector::vals, Continue> type;
  };
  typedef ValueSetter<PodVector::vals,
                      ValueSetter<__LastRecursive, __LastRecursive>>
      recursive;
  static PodVector::constructor<ValueSetter<__Last, __Last>>::type create();
  static recursive createRecursive();
};
struct AVector : Record<4 + 1, AVector> {
  struct str : AnyVector<First, First> {};
  enum { headerSize = 0 + str::headerSize, staticSize = 0 };
  template <typename Continue>
  struct constructor {
    typedef ValueSetter<AVector::str, Continue> type;
  };
  typedef ValueSetter<AVector::str,
                      ValueSetter<__LastRecursive, __LastRecursive>>
      recursive;
  static AVector::constructor<ValueSetter<__Last, __Last>>::type create();
  static recursive createRecursive();
};
struct String : Record<5 + 1, String> {
  struct str : Vector<char, First> {};
  enum { headerSize = 0 + str::headerSize, staticSize = 0 };
  template <typename Continue>
  struct constructor {
    typedef ValueSetter<String::str, Continue> type;
  };
  typedef ValueSetter<String::str,
                      ValueSetter<__LastRecursive, __LastRecursive>>
      recursive;
  static String::constructor<ValueSetter<__Last, __Last>>::type create();
  static recursive createRecursive();
};
class SerializedData {
  friend class RecordConstructor;

 public:
  typedef u16 rid;
  typedef u32 hel;

  template <typename Field>
  typename Field::T extractField() const {
    if (id() != Field::record::ID)
      throw WrongType();

    const char* offset =
        data() + sizeof(rid) + sizeof(hel) * Field::record::headerSize;

    offset += Field::staticOffset;
    for (int i = Field::dynamicOffset - 1; i >= 0; --i) {
      offset += byte_order_from_le(
          reinterpret_cast<const hel*>(data() + sizeof(rid))[i]);
    }
    return byte_order_from_le(
        *(reinterpret_cast<const typename Field::T*>(offset)));
  }

  template <typename Field>
  void setField(const typename Field::T t) {
    if (id() != Field::record::ID)
      throw WrongType();

    char* offset =
        data() + sizeof(rid) + sizeof(hel) * Field::record::headerSize;

    offset += Field::staticOffset;
    for (int i = Field::dynamicOffset - 1; i >= 0; --i) {
      offset +=
          byte_order_from_le(reinterpret_cast<hel*>(data() + sizeof(rid))[i]);
    }
    *(reinterpret_cast<typename Field::T*>(offset)) = byte_order_to_le(t);
  }

  template <typename Vector>
  std::vector<typename Vector::Tv> extractVector() const {
    if (id() != Vector::record::ID)
      throw WrongType();

    const char* offset =
        data() + sizeof(rid) + sizeof(hel) * Vector::record::headerSize;

    offset += Vector::staticOffset;
    for (int i = Vector::dynamicOffset - 1; i >= 0; --i) {
      offset += byte_order_from_le(
          reinterpret_cast<const hel*>(data() + sizeof(rid))[i]);
    }

    std::vector<typename Vector::Tv> result;

    hel size = reinterpret_cast<const hel*>(data() +
                                            sizeof(rid))[Vector::dynamicOffset];
    result.resize(size / sizeof(typename Vector::Tv));

    typename Vector::V first =
        reinterpret_cast<typename Vector::V>(const_cast<char*>(offset));
    typename Vector::V last = first + size / sizeof(typename Vector::Tv);

    typename std::vector<typename Vector::Tv>::iterator rp = result.begin();

    while (first != last) {
      *rp = byte_order_from_le(*first);
      ++rp;
      ++first;
    }
    return result;
  }

  template <typename Any>
  SerializedData extractAny() const {
    if (id() != Any::record::ID)
      throw WrongType();
    const char* offset =
        data() + sizeof(rid) + sizeof(hel) * Any::record::headerSize;
    offset += Any::staticOffset;
    for (int i = Any::dynamicOffset - 1; i >= 0; --i) {
      offset += byte_order_from_le(
          reinterpret_cast<const hel*>(data() + sizeof(rid))[i]);
    }
    return SerializedData(offset,
                          byte_order_from_le(reinterpret_cast<const hel*>(
                              data() + sizeof(rid))[Any::dynamicOffset]));
  }

  template <typename Vector>
  std::string extractString() const {
    if (id() != Vector::record::ID)
      throw WrongType();

    const char* offset =
        data() + sizeof(rid) + sizeof(hel) * Vector::record::headerSize;

    offset += Vector::staticOffset;
    for (int i = Vector::dynamicOffset - 1; i >= 0; --i) {
      offset += byte_order_from_le(
          reinterpret_cast<const hel*>(data() + sizeof(rid))[i]);
    }

    hel size = byte_order_from_le(reinterpret_cast<const hel*>(
        data() + sizeof(rid))[Vector::dynamicOffset]);

    return std::string(offset, size);
  }
  template <typename AnyVector>
  SerializedData extractAnyVectorElement(size_t index) const {
    if (id() != AnyVector::record::ID)
      throw WrongType();

    const char* offset =
        data() + sizeof(rid) + sizeof(hel) * AnyVector::record::headerSize;

    hel self_size = byte_order_from_le(reinterpret_cast<const hel*>(
        data() + sizeof(rid))[AnyVector::dynamicOffset]);

    if (self_size == 0)
      throw WrongIndex();

    offset += AnyVector::staticOffset;
    for (int i = AnyVector::dynamicOffset - 1; i >= 0; --i) {
      offset += byte_order_from_le(
          reinterpret_cast<const hel*>(data() + sizeof(rid))[i]);
    }

    for (size_t i = index; i > 0; --i) {
      rid id = byte_order_from_le(*reinterpret_cast<const rid*>(offset));
      offset += sizeof(rid);

      size_t sz = 0;
      for (int i = headerSize(id) - 1; i >= 0; --i, offset += sizeof(hel)) {
        sz += reinterpret_cast<const hel*>(data() + sizeof(rid))[i];
      }
      offset += sz + staticSizes[id];

      if (offset > data() + self_size)
        throw WrongIndex();
    }

    return SerializedData(offset, 2);
  }

  template <typename AnyVector>
  std::vector<SerializedData> extractAnyVector() const {
    if (id() != AnyVector::record::ID)
      throw WrongType();

    const char* offset =
        data() + sizeof(rid) + sizeof(hel) * AnyVector::record::headerSize;


    std::vector<SerializedData> result;

    offset += AnyVector::staticOffset;
    for (int i = AnyVector::dynamicOffset - 1; i >= 0; --i) {
      offset += byte_order_from_le(
          reinterpret_cast<const hel*>(data() + sizeof(rid))[i]);
    }

    const char* end =
        offset + byte_order_from_le(reinterpret_cast<const hel*>(
                     data() + sizeof(rid))[AnyVector::dynamicOffset]);

    while (offset < end) {
      SerializedData extr(offset, 2);
      result.push_back(extr);
      offset += extr.size();
    }

    return result;
  }

  typedef void (*reader)(char* memory, size_t size, void* opt);

  SerializedData(reader readdata, void* opt = 0);
  SerializedData(const char* block, size_t size);

  inline const char* data() const {
    if (block == 0) {
      return &vec[0];
    } else {
      return block;
    }
  }

  inline char* data() {
    if (block == 0) {
      return &vec[0];
    } else {
      return block;
    }
  }

  inline rid id() const {
    if (allocated == 0)
      return 0;
    return *(reinterpret_cast<const rid*>(data()));
  }

  std::size_t size() const;
  enum { __LastType = String::ID };
  friend struct PODcontainer;
  friend struct OneBool;
  friend struct Empty;
  friend struct PodVector;
  friend struct AVector;
  friend struct String;

 protected:
  char* block;
  size_t allocated;
  std::vector<char> vec;

  static const hel headerSizes[];
  static const hel staticSizes[];

  SerializedData(size_t allocate);
  void requireSize(size_t size);
  hel headerSize(rid id) const;
};

template <bool, class T = void>
struct enable_if {};
template <class T>
struct enable_if<true, T> {
  typedef T type;
};

template <typename T>
struct CheckIfField {
  template <typename C>
  static char test(typename C::isField);
  template <typename C>
  static long test(...);

  enum { value = sizeof(test<T>(0)) == sizeof(char) };
};

template <typename T>
struct CheckIfAny {
  template <typename C>
  static char test(typename C::isAny);
  template <typename C>
  static long test(...);

  enum { value = sizeof(test<T>(0)) == sizeof(char) };
};

template <typename T>
struct CheckIfVector {
  template <typename C>
  static char test(typename C::isVector);
  template <typename C>
  static long test(...);

  enum { value = sizeof(test<T>(0)) == sizeof(char) };
};

template <typename T>
struct CheckIfAnyVector {
  template <typename C>
  static char test(typename C::isAnyVector);
  template <typename C>
  static long test(...);

  enum { value = sizeof(test<T>(0)) == sizeof(char) };
};

template <typename T>
struct CheckIfVoid {
  template <typename C>
  static char test(typename C::isVoid);
  template <typename C>
  static long test(...);

  enum { value = sizeof(test<T>(0)) == sizeof(char) };
};

template <typename Field, typename Next>
class ValueSetter<Field,
                  Next,
                  typename enable_if<CheckIfField<Field>::value>::type> {
  template <typename _Field, typename _Next, typename _Dummy>
  friend class ValueSetter;

 public:
  typedef Field F;
  typedef Next N;

  ValueSetter<typename Next::F, typename Next::N> set(
      const typename Field::T value) {
    *(reinterpret_cast<typename Field::T*>(
        constructor->staticData(Field::staticSize))) = byte_order_to_le(value);

    return ValueSetter<typename Next::F, typename Next::N>(constructor);
  }

  ValueSetter(RecordConstructor* constructor) : constructor(constructor) {}

 protected:
  RecordConstructor* constructor;
};

template <typename Field, typename Next>
class ValueSetter<Field,
                  Next,
                  typename enable_if<CheckIfAny<Field>::value>::type> {
  template <typename _Field, typename _Next, typename _Dummy>
  friend class ValueSetter;

 public:
  typedef Field F;
  typedef Next N;

  template <typename Record>
  typename Record::template constructor<ValueSetter<__Finish, Next>>::type
  begin() {
    return typename Record::template constructor<ValueSetter<__Finish, Next>>::
        type(constructor->beginNested(Record::ID, Record::staticSize,
                                      Record::headerSize, true));
  }

  template <typename Record>
  typename Record::recursive beginRecursive() {
    return typename Record::recursive(constructor->beginNested(
        Record::ID, Record::staticSize, Record::headerSize, true));
  }

  ValueSetter<typename Next::F, typename Next::N> set(
      const SerializedData* data) {
    size_t size = data->size();
    char* to = constructor->dynamicData(size);

    const char* begin = data->data();
    const char* end = begin + size;

    std::copy(begin, end, to);

    constructor->finishDynamicSize();
    return ValueSetter<typename Next::F, typename Next::N>(constructor);
  }

  ValueSetter<typename Next::F, typename Next::N> skip() {
    constructor->finishDynamicSize();
    return ValueSetter<typename Next::F, typename Next::N>(constructor);
  }

  ValueSetter(RecordConstructor* constructor) : constructor(constructor) {}

 protected:
  RecordConstructor* constructor;
};

template <typename Field, typename Next>
class ValueSetter<Field,
                  Next,
                  typename enable_if<CheckIfVector<Field>::value>::type> {
  template <typename _Field, typename _Next, typename _Dummy>
  friend class ValueSetter;

 public:
  typedef Field F;
  typedef Next N;

  ValueSetter<typename Next::F, typename Next::N> finish() {
    constructor->finishDynamicSize();
    return ValueSetter<typename Next::F, typename Next::N>(constructor);
  }

  ValueSetter<Field, Next> add(const typename Field::Tv value) {
    *reinterpret_cast<typename Field::Tv*>(
        constructor->dynamicData(sizeof(value))) = byte_order_to_le(value);

    return ValueSetter<Field, Next>(constructor);
  }

  template <typename VectorType>
  ValueSetter<Field, Next> addVector(VectorType value) {
    vectorConvert<VectorType> vector(value);

    size_t reqiredSize =
        (vector.end() - vector.begin()) * sizeof(*vector.begin());

    typename Field::Tv* offset = reinterpret_cast<typename Field::Tv*>(
        constructor->dynamicData(reqiredSize));

    for (typename vectorConvert<VectorType>::IteratorType i = vector.begin();
         i < vector.end(); ++i, ++offset) {
      *offset = byte_order_to_le(*i);
    }

    return ValueSetter<Field, Next>(constructor);
  }

  template <typename VectorType>
  ValueSetter<typename Next::F, typename Next::N> set(VectorType value) {
    return addVector(value).finish();
  }

  ValueSetter(RecordConstructor* constructor) : constructor(constructor) {}

 protected:
  RecordConstructor* constructor;
};

template <typename Field, typename Next>
class ValueSetter<Field,
                  Next,
                  typename enable_if<CheckIfAnyVector<Field>::value>::type> {
  template <typename _Field, typename _Next, typename _Dummy>
  friend class ValueSetter;

 public:
  typedef Field F;
  typedef Next N;

  template <typename Record>
  typename Record::template constructor<
      ValueSetter<__Finish, ValueSetter<Field, Next>>>::type
  begin() {
    return typename Record::template constructor<
        ValueSetter<__Finish, ValueSetter<Field, Next>>>::
        type(constructor->beginNested(Record::ID, Record::staticSize,
                                      Record::headerSize, false));
  }

  template <typename Record>
  typename Record::recursive beginRecursive() {
    return typename Record::recursive(constructor->beginNested(
        Record::ID, Record::staticSize, Record::headerSize, false));
  }

  ValueSetter<typename Next::F, typename Next::N> finish() {
    constructor->finishDynamicSize();
    return ValueSetter<typename Next::F, typename Next::N>(constructor);
  }

  ValueSetter(RecordConstructor* constructor) : constructor(constructor) {}

 protected:
  RecordConstructor* constructor;
};

template <typename Field, typename Next>
class ValueSetter<Field,
                  Next,
                  typename enable_if<CheckIfVoid<Field>::value>::type> {
  template <typename _Field, typename _Next, typename _Dummy>
  friend class ValueSetter;

 public:
  typedef Field F;
  typedef Next N;

  ValueSetter<typename Next::F, typename Next::N> finish() {
    return ValueSetter<typename Next::F, typename Next::N>(constructor);
  }

  ValueSetter(RecordConstructor* constructor) : constructor(constructor) {}

 protected:
  RecordConstructor* constructor;
};

template <typename Next>
class ValueSetter<__Last, Next> {
  template <typename _Field, typename _Next, typename _Dummy>
  friend class ValueSetter;

 public:
  typedef __Last F;
  typedef SerializedData* N;

  SerializedData* finish() { return result; }

  ValueSetter(RecordConstructor* constructor) {
    result = constructor->root();
    delete constructor;
  }

 protected:
  SerializedData* result;
};

template <typename Next>
class ValueSetter<__LastRecursive, Next> {
  template <typename _Field, typename _Next, typename _Dummy>
  friend class ValueSetter;

 public:
  typedef __LastRecursive F;
  typedef SerializedData* N;

  SerializedData* finish() { return result; }

  SerializedData* clear() {
    delete constructor;
    constructor = 0;
    return result;
  }

  ValueSetter(RecordConstructor* constructor) : constructor(constructor) {
    result = constructor->root();
  }

 protected:
  RecordConstructor* constructor;
  SerializedData* result;
};

template <typename Next>
class ValueSetter<__Finish, Next> {
  template <typename _Field, typename _Next, typename _Dummy>
  friend class ValueSetter;

 public:
  typedef __Finish F;
  typedef Next N;

  ValueSetter<typename Next::F, typename Next::N> finish() {
    return ValueSetter<typename Next::F, typename Next::N>(
        constructor->finishNested());
  }

  ValueSetter(RecordConstructor* constructor) : constructor(constructor) {}

 protected:
  RecordConstructor* constructor;
};

SerializedData::SerializedData(size_t allocate)
    : block(0), allocated(allocate), vec(allocate) {}

SerializedData::SerializedData(const char* block, size_t allocate)
    : block(const_cast<char*>(block)), allocated(allocate), vec() {}

void SerializedData::requireSize(size_t size) {
  if (block)
    throw SerializedException();
  vec.resize(size);
  allocated = size;
}

inline SerializedData::hel SerializedData::headerSize(rid id) const {
  if (id < 1 || id > __LastType)
    throw WrongType();
  return headerSizes[id];
}
std::size_t SerializedData::size() const {
  if (id() == 0)
    return 0;
  std::size_t sz =
      sizeof(rid) + headerSize(id()) * sizeof(hel) + staticSizes[id()];
  for (int i = headerSize(id()) - 1; i >= 0; --i) {
    sz += reinterpret_cast<const hel*>(data() + sizeof(rid))[i];
  }
  return sz;
}

SerializedData::SerializedData(reader readdata, void* opt)
    : block(0), allocated(sizeof(rid)), vec(allocated) {
  readdata(data(), sizeof(rid), opt);

  rid id = byte_order_from_le(*reinterpret_cast<rid*>(data()));

  size_t hs = headerSize(id);

  allocated += hs * sizeof(hel);
  requireSize(allocated);

  hel* header = reinterpret_cast<hel*>(data() + sizeof(rid));

  readdata((char*)header, sizeof(hel) * hs, opt);
  std::size_t bulkSize = staticSizes[id];
  for (unsigned int i = 0; i < hs; ++i) {
    bulkSize += byte_order_from_le(header[i]);
  }

  allocated += bulkSize;
  requireSize(allocated);

  readdata(data() + sizeof(rid) + sizeof(hel) * hs, bulkSize, opt);
}

RecordConstructor::RecordConstructor(SerializedData* data,
                                     size_t staticSize,
                                     size_t headerSize)
    : data(data),
      dynamicOffset(sizeof(SerializedData::rid) +
                    sizeof(SerializedData::hel) * headerSize + staticSize) {
  staticOffset.push_back(sizeof(SerializedData::rid) +
                         sizeof(SerializedData::hel) * headerSize);
  dynamicSizeOffset.push_back(sizeof(SerializedData::rid));
  finishDynamic.push_back(headerSize > 0);
}

char* RecordConstructor::staticData(size_t size) {
  char* ptr = data->data() + staticOffset.back();
  staticOffset.back() += size;
  return ptr;
}

char* RecordConstructor::dynamicData(size_t size) {
  data->requireSize(dynamicOffset + size);
  char* ptr = data->data() + dynamicOffset;
  dynamicOffset += size;

  for (std::vector<size_t>::iterator i = dynamicSizeOffset.begin();
       i != dynamicSizeOffset.end(); ++i) {
    *reinterpret_cast<SerializedData::hel*>(data->data() + *i) += size;
  }

  return ptr;
}

void RecordConstructor::finishDynamicSize() {
  *reinterpret_cast<SerializedData::hel*>(data->data() +
                                          dynamicSizeOffset.back()) =
      byte_order_to_le(*reinterpret_cast<SerializedData::hel*>(
          data->data() + dynamicSizeOffset.back()));
  dynamicSizeOffset.back() += sizeof(SerializedData::hel);
}

SerializedData* RecordConstructor::root() {
  finishNested();
  return data;
}

RecordConstructor* RecordConstructor::beginNested(u16 id,
                                                  size_t staticSize,
                                                  size_t headerSize,
                                                  bool last) {
  size_t nestedSize =
      sizeof(id) + staticSize + headerSize * sizeof(SerializedData::hel);
  char* obj = dynamicData(nestedSize);
  *reinterpret_cast<u16*>(obj) = byte_order_to_le(id);

  SerializedData::hel* dyn =
      reinterpret_cast<SerializedData::hel*>(obj + sizeof(SerializedData::rid));
  for (size_t j = headerSize; j > 0; --j, ++dyn)
    *dyn = 0;

  size_t hOffset = sizeof(id) + (obj - data->data());
  size_t sOffset = hOffset + headerSize * sizeof(SerializedData::hel);

  staticOffset.push_back(sOffset);
  dynamicSizeOffset.push_back(hOffset);
  finishDynamic.push_back(last && headerSize > 0);

  return this;
}

RecordConstructor* RecordConstructor::finishNested() {
  if (finishDynamic.size() == 0)
    return this;
  if (finishDynamic.back())
    finishDynamicSize();

  staticOffset.pop_back();
  dynamicSizeOffset.pop_back();
  finishDynamic.pop_back();

  return this;
}
PODcontainer::constructor<ValueSetter<__Last, __Last>>::type
PODcontainer::create() {
  SerializedData* sd = new SerializedData(sizeof(SerializedData::rid) +
                                          PODcontainer::headerSize *
                                              sizeof(SerializedData::hel) +
                                          PODcontainer::staticSize);
  *reinterpret_cast<SerializedData::rid*>(sd->data()) =
      byte_order_to_le((SerializedData::rid)PODcontainer::ID);
  SerializedData::hel* dyn = reinterpret_cast<SerializedData::hel*>(
      sd->data() + sizeof(SerializedData::rid));
  for (size_t j = PODcontainer::headerSize; j > 0; --j, ++dyn)
    *dyn = 0;
  return PODcontainer::constructor<ValueSetter<__Last, __Last>>::type(
      new RecordConstructor(sd, PODcontainer::staticSize,
                            PODcontainer::headerSize));
}
PODcontainer::recursive PODcontainer::createRecursive() {
  SerializedData* sd = new SerializedData(sizeof(SerializedData::rid) +
                                          PODcontainer::headerSize *
                                              sizeof(SerializedData::hel) +
                                          PODcontainer::staticSize);
  *reinterpret_cast<SerializedData::rid*>(sd->data()) =
      byte_order_to_le((SerializedData::rid)PODcontainer::ID);
  SerializedData::hel* dyn = reinterpret_cast<SerializedData::hel*>(
      sd->data() + sizeof(SerializedData::rid));
  for (size_t j = PODcontainer::headerSize; j > 0; --j, ++dyn)
    *dyn = 0;
  return PODcontainer::recursive(new RecordConstructor(
      sd, PODcontainer::staticSize, PODcontainer::headerSize));
}
OneBool::constructor<ValueSetter<__Last, __Last>>::type OneBool::create() {
  SerializedData* sd = new SerializedData(
      sizeof(SerializedData::rid) +
      OneBool::headerSize * sizeof(SerializedData::hel) + OneBool::staticSize);
  *reinterpret_cast<SerializedData::rid*>(sd->data()) =
      byte_order_to_le((SerializedData::rid)OneBool::ID);
  SerializedData::hel* dyn = reinterpret_cast<SerializedData::hel*>(
      sd->data() + sizeof(SerializedData::rid));
  for (size_t j = OneBool::headerSize; j > 0; --j, ++dyn)
    *dyn = 0;
  return OneBool::constructor<ValueSetter<__Last, __Last>>::type(
      new RecordConstructor(sd, OneBool::staticSize, OneBool::headerSize));
}
OneBool::recursive OneBool::createRecursive() {
  SerializedData* sd = new SerializedData(
      sizeof(SerializedData::rid) +
      OneBool::headerSize * sizeof(SerializedData::hel) + OneBool::staticSize);
  *reinterpret_cast<SerializedData::rid*>(sd->data()) =
      byte_order_to_le((SerializedData::rid)OneBool::ID);
  SerializedData::hel* dyn = reinterpret_cast<SerializedData::hel*>(
      sd->data() + sizeof(SerializedData::rid));
  for (size_t j = OneBool::headerSize; j > 0; --j, ++dyn)
    *dyn = 0;
  return OneBool::recursive(
      new RecordConstructor(sd, OneBool::staticSize, OneBool::headerSize));
}
Empty::constructor<ValueSetter<__Last, __Last>>::type Empty::create() {
  SerializedData* sd = new SerializedData(
      sizeof(SerializedData::rid) +
      Empty::headerSize * sizeof(SerializedData::hel) + Empty::staticSize);
  *reinterpret_cast<SerializedData::rid*>(sd->data()) =
      byte_order_to_le((SerializedData::rid)Empty::ID);
  SerializedData::hel* dyn = reinterpret_cast<SerializedData::hel*>(
      sd->data() + sizeof(SerializedData::rid));
  for (size_t j = Empty::headerSize; j > 0; --j, ++dyn)
    *dyn = 0;
  return Empty::constructor<ValueSetter<__Last, __Last>>::type(
      new RecordConstructor(sd, Empty::staticSize, Empty::headerSize));
}
Empty::recursive Empty::createRecursive() {
  SerializedData* sd = new SerializedData(
      sizeof(SerializedData::rid) +
      Empty::headerSize * sizeof(SerializedData::hel) + Empty::staticSize);
  *reinterpret_cast<SerializedData::rid*>(sd->data()) =
      byte_order_to_le((SerializedData::rid)Empty::ID);
  SerializedData::hel* dyn = reinterpret_cast<SerializedData::hel*>(
      sd->data() + sizeof(SerializedData::rid));
  for (size_t j = Empty::headerSize; j > 0; --j, ++dyn)
    *dyn = 0;
  return Empty::recursive(
      new RecordConstructor(sd, Empty::staticSize, Empty::headerSize));
}
PodVector::constructor<ValueSetter<__Last, __Last>>::type PodVector::create() {
  SerializedData* sd =
      new SerializedData(sizeof(SerializedData::rid) +
                         PodVector::headerSize * sizeof(SerializedData::hel) +
                         PodVector::staticSize);
  *reinterpret_cast<SerializedData::rid*>(sd->data()) =
      byte_order_to_le((SerializedData::rid)PodVector::ID);
  SerializedData::hel* dyn = reinterpret_cast<SerializedData::hel*>(
      sd->data() + sizeof(SerializedData::rid));
  for (size_t j = PodVector::headerSize; j > 0; --j, ++dyn)
    *dyn = 0;
  return PodVector::constructor<ValueSetter<__Last, __Last>>::type(
      new RecordConstructor(sd, PodVector::staticSize, PodVector::headerSize));
}
PodVector::recursive PodVector::createRecursive() {
  SerializedData* sd =
      new SerializedData(sizeof(SerializedData::rid) +
                         PodVector::headerSize * sizeof(SerializedData::hel) +
                         PodVector::staticSize);
  *reinterpret_cast<SerializedData::rid*>(sd->data()) =
      byte_order_to_le((SerializedData::rid)PodVector::ID);
  SerializedData::hel* dyn = reinterpret_cast<SerializedData::hel*>(
      sd->data() + sizeof(SerializedData::rid));
  for (size_t j = PodVector::headerSize; j > 0; --j, ++dyn)
    *dyn = 0;
  return PodVector::recursive(
      new RecordConstructor(sd, PodVector::staticSize, PodVector::headerSize));
}
AVector::constructor<ValueSetter<__Last, __Last>>::type AVector::create() {
  SerializedData* sd = new SerializedData(
      sizeof(SerializedData::rid) +
      AVector::headerSize * sizeof(SerializedData::hel) + AVector::staticSize);
  *reinterpret_cast<SerializedData::rid*>(sd->data()) =
      byte_order_to_le((SerializedData::rid)AVector::ID);
  SerializedData::hel* dyn = reinterpret_cast<SerializedData::hel*>(
      sd->data() + sizeof(SerializedData::rid));
  for (size_t j = AVector::headerSize; j > 0; --j, ++dyn)
    *dyn = 0;
  return AVector::constructor<ValueSetter<__Last, __Last>>::type(
      new RecordConstructor(sd, AVector::staticSize, AVector::headerSize));
}
AVector::recursive AVector::createRecursive() {
  SerializedData* sd = new SerializedData(
      sizeof(SerializedData::rid) +
      AVector::headerSize * sizeof(SerializedData::hel) + AVector::staticSize);
  *reinterpret_cast<SerializedData::rid*>(sd->data()) =
      byte_order_to_le((SerializedData::rid)AVector::ID);
  SerializedData::hel* dyn = reinterpret_cast<SerializedData::hel*>(
      sd->data() + sizeof(SerializedData::rid));
  for (size_t j = AVector::headerSize; j > 0; --j, ++dyn)
    *dyn = 0;
  return AVector::recursive(
      new RecordConstructor(sd, AVector::staticSize, AVector::headerSize));
}
String::constructor<ValueSetter<__Last, __Last>>::type String::create() {
  SerializedData* sd = new SerializedData(
      sizeof(SerializedData::rid) +
      String::headerSize * sizeof(SerializedData::hel) + String::staticSize);
  *reinterpret_cast<SerializedData::rid*>(sd->data()) =
      byte_order_to_le((SerializedData::rid)String::ID);
  SerializedData::hel* dyn = reinterpret_cast<SerializedData::hel*>(
      sd->data() + sizeof(SerializedData::rid));
  for (size_t j = String::headerSize; j > 0; --j, ++dyn)
    *dyn = 0;
  return String::constructor<ValueSetter<__Last, __Last>>::type(
      new RecordConstructor(sd, String::staticSize, String::headerSize));
}
String::recursive String::createRecursive() {
  SerializedData* sd = new SerializedData(
      sizeof(SerializedData::rid) +
      String::headerSize * sizeof(SerializedData::hel) + String::staticSize);
  *reinterpret_cast<SerializedData::rid*>(sd->data()) =
      byte_order_to_le((SerializedData::rid)String::ID);
  SerializedData::hel* dyn = reinterpret_cast<SerializedData::hel*>(
      sd->data() + sizeof(SerializedData::rid));
  for (size_t j = String::headerSize; j > 0; --j, ++dyn)
    *dyn = 0;
  return String::recursive(
      new RecordConstructor(sd, String::staticSize, String::headerSize));
}
const SerializedData::hel SerializedData::headerSizes[] = {
    0,
    PODcontainer::headerSize,
    OneBool::headerSize,
    Empty::headerSize,
    PodVector::headerSize,
    AVector::headerSize,
    String::headerSize};
const SerializedData::hel SerializedData::staticSizes[] = {
    0,
    PODcontainer::staticSize,
    OneBool::staticSize,
    Empty::staticSize,
    PodVector::staticSize,
    AVector::staticSize,
    String::staticSize};
