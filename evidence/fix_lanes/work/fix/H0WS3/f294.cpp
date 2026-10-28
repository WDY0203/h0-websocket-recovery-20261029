#include "H0WS3_shim.hpp"

// ===================== type repair prelude (fixes.cpp) =====================
// Missing aggregate types that the generator referenced but did not emit.
struct arr_undefined1_4  { undefined1 v[4];  arr_undefined1_4() = default;  undefined1 &operator[](int i) { return v[i]; }  template<class U> arr_undefined1_4(U)  {} };
struct arr_undefined1_8  { undefined1 v[8];  arr_undefined1_8() = default;  undefined1 &operator[](int i) { return v[i]; }  template<class U> arr_undefined1_8(U)  {} };
struct arr_undefined1_15 { undefined1 v[15]; arr_undefined1_15() = default; undefined1 &operator[](int i) { return v[i]; } template<class U> arr_undefined1_15(U) {} };

// Ghidra integer types that the shim omitted.  Widths are the closest native
// type (3 -> 32 bit, 5 -> 64 bit, 10-byte unsigned -> 128 bit so that the
// `<< 0x40` / `<< 0x38` the pseudocode applies to it stays a legal shift).
// See NOTES.md.
typedef uint32_t uint3;
typedef int32_t  int3;
typedef int64_t  int5;
typedef unsigned __int128 unkuint10;

// 128-bit scratch values.  Ghidra emits `<<`, `>>` and `|` on the 16-byte
// return slots and on the arr_undefined1_N slices of them.  C++ has no
// operators for raw arrays, so those slots are addressed through the shim's
// arr_undefined1_N aggregates and the operators below.
struct rea_wide { uint8_t v[16];
  rea_wide() = default;
  template <class U> rea_wide(U) {}
  operator uint64_t() const { uint64_t x; memcpy(&x, v, 8); return x; }
};

template <class T> struct rea_has_v {
  template <class U> static char probe(decltype(&U::v) *);
  template <class U> static long probe(...);
  enum { value = sizeof(probe<T>(0)) == 1 };
};

static inline rea_wide rea_shift_bytes(const void *p, size_t nbytes, unsigned cnt, int left)
{
  uint8_t out[16] = {0};
  unsigned by = cnt / 8;
  if (cnt % 8 == 0) {
    for (int i = 0; i < 16; ++i) {
      long src = left ? (long)i - (long)by : (long)i + (long)by;
      if (src >= 0 && (size_t)src < nbytes && (size_t)src < 16)
        out[i] = ((const uint8_t *)p)[src];
    }
  }
  rea_wide r; memcpy(r.v, out, 16); return r;
}
static inline rea_wide rea_or_bytes(const void *a, size_t na, const void *b, size_t nb)
{
  uint8_t out[16];
  for (int i = 0; i < 16; ++i) {
    uint8_t x = i < (int)na ? ((const uint8_t *)a)[i] : 0;
    uint8_t y = i < (int)nb ? ((const uint8_t *)b)[i] : 0;
    out[i] = (uint8_t)(x | y);
  }
  rea_wide r; memcpy(r.v, out, 16); return r;
}

template <class A> inline typename std::enable_if<rea_has_v<A>::value || std::is_same<A, rea_wide>::value, rea_wide>::type
operator<<(const A &a, int cnt) { return rea_shift_bytes(&a, sizeof(A), (unsigned)cnt, 1); }

template <class A> inline typename std::enable_if<rea_has_v<A>::value || std::is_same<A, rea_wide>::value, rea_wide>::type
operator>>(const A &a, int cnt) { return rea_shift_bytes(&a, sizeof(A), (unsigned)cnt, 0); }

template <class A, class B> inline typename std::enable_if<(rea_has_v<A>::value || std::is_same<A, rea_wide>::value) &&
                                                           (rea_has_v<B>::value || std::is_same<B, rea_wide>::value), rea_wide>::type
operator|(const A &a, const B &b) { return rea_or_bytes(&a, sizeof(A), &b, sizeof(B)); }
// =================== end type repair prelude ===================

// ------------------------------------------------------------------
// IDX 294  0011d280  UnixClient__UnixClient
// ------------------------------------------------------------------
void rea_UnixClient__UnixClient__dup2(UnixClient * this_ptr, string * param_1, long long param_3, long long param_4)
{
  long long *plVar1;
  undefined *puVar2;
  int __fd;
  int iVar3;
  TcpConn *this_00;
  int *piVar4;
  undefined1 local_a8[7][0x10];
  
  *(UnixClient **)(this_ptr + 0x20) = this_ptr + 0x10;
  *(UnixClient **)(this_ptr + 0x28) = this_ptr + 0x10;
  *(undefined4 *)(this_ptr + 0x10) = 0;
  *(undefined8 *)(this_ptr + 0x18) = 0;
  *(undefined8 *)(this_ptr + 0x30) = 0;
  *(undefined4 *)(this_ptr + 0x40) = 0;
  *(UnixClient **)(this_ptr + 0x50) = this_ptr + 0x40;
  *(UnixClient **)(this_ptr + 0x58) = this_ptr + 0x40;
  *(undefined8 *)(this_ptr + 0x48) = 0;
  *(undefined8 *)(this_ptr + 0x60) = 0;
  *(UnixClient **)(this_ptr + 0x80) = this_ptr + 0x70;
  *(UnixClient **)(this_ptr + 0x88) = this_ptr + 0x70;
  puVar2 = PTR_vtable_00324f70;
  *(undefined4 *)(this_ptr + 0x70) = 0;
  *(undefined8 *)(this_ptr + 0x78) = 0;
  *(undefined8 *)(this_ptr + 0x90) = 0;
  *(undefined4 *)(this_ptr + 0x98) = 0;
  *(undefined8 *)(this_ptr + 0xa0) = 0;
  *(undefined8 *)(this_ptr + 0xb8) = 0;
  *(undefined **)this_ptr = puVar2 + 0x10;
  if (*(code **)(param_3 + 0x10) != 0x0) {
    (**(code **)(param_3 + 0x10))(this_ptr + 0xa8,param_3,2);
    *(undefined8 *)(this_ptr + 0xc0) = *(undefined8 *)(param_3 + 0x18);
    *(undefined8 *)(this_ptr + 0xb8) = *(undefined8 *)(param_3 + 0x10);
  }
  *(undefined8 *)(this_ptr + 0xd8) = 0;
  if (*(code **)(param_4 + 0x10) != 0x0) {
    (**(code **)(param_4 + 0x10))(this_ptr + 200,param_4,2);
    *(undefined8 *)(this_ptr + 0xe0) = *(undefined8 *)(param_4 + 0x18);
    *(undefined8 *)(this_ptr + 0xd8) = *(undefined8 *)(param_4 + 0x10);
  }
  rea_bzero(local_a8,0x6e);
  (*(undefined2 *)((uint8_t *)&local_a8[0] + 0x0)) = 1;
  rea_strncpy(((char*)(uintptr_t)((uint8_t *)&local_a8[0]) + 0x2),*(char **)param_1,0x6b);
  __fd = rea_socket(1,1,0);
  if (__fd < 0) {
    rea_perror("socket");
                    /* WARNING: Subroutine does not return */
    rea_abort();
  }
  rea_setcloexec(__fd);
  iVar3 = rea_connect(__fd,(sockaddr*)(uintptr_t)(local_a8),0x6e);
  if (iVar3 < 0) {
    piVar4 = rea___errno_location();
    iVar3 = *piVar4;
    *(undefined4 *)(this_ptr + 0x98) = 2;
    rea_perror("connect");
    rea_close(__fd);
    if (*(long long *)(param_4 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
      rea_std____throw_bad_function_call();
    }
    (**(code **)(param_4 + 0x18))(param_4,iVar3);
  }
  rea_setnonblock(__fd);
  this_00 = rea_operator_new(0xd0);
  rea_TcpConn__TcpConn(this_00,__fd,param_1,param_1,(EventHandler *)this_ptr);
  plVar1 = *(long long **)(this_ptr + 0xa0);
  *(TcpConn **)(this_ptr + 0xa0) = this_00;
  if (plVar1 != 0x0) {
    (**(code **)(*plVar1 + 8))();
    this_00 = *(TcpConn **)(this_ptr + 0xa0);
  }
  *(undefined4 *)(this_ptr + 0x98) = 1;
  if (*(long long *)(param_3 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
    rea_std____throw_bad_function_call();
  }
  (**(code **)(param_3 + 0x18))(param_3,this_00);
  return;
}
