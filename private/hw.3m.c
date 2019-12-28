#define GC_VARIABLE_STACK ((&scheme_thread_locals)->GC_variable_stack_)
#define GET_GC_VARIABLE_STACK() GC_VARIABLE_STACK
#define SET_GC_VARIABLE_STACK(v) (GC_VARIABLE_STACK = (v))
#define PREPARE_VAR_STACK(size) void *__gc_var_stack__[size+2]; __gc_var_stack__[0] = GET_GC_VARIABLE_STACK(); SET_GC_VARIABLE_STACK(__gc_var_stack__);
#define PREPARE_VAR_STACK_ONCE(size) PREPARE_VAR_STACK(size); __gc_var_stack__[1] = (void *)size;
#define SETUP(x) (__gc_var_stack__[1] = (void *)x)
#ifdef MZ_3M_CHECK_VAR_STACK
static int _bad_var_stack_() { *(long *)0x0 = 1; return 0; }
# define CHECK_GC_V_S ((GC_VARIABLE_STACK == __gc_var_stack__) ? 0 : _bad_var_stack_()),
#else
# define CHECK_GC_V_S /*empty*/
#endif
#define FUNCCALL_each(setup, x) (CHECK_GC_V_S setup, x)
#define FUNCCALL_EMPTY_each(x) (SET_GC_VARIABLE_STACK((void **)__gc_var_stack__[0]), x)
#define FUNCCALL_AGAIN_each(x) (CHECK_GC_V_S x)
#define FUNCCALL_once(setup, x) FUNCCALL_AGAIN_each(x)
#define FUNCCALL_EMPTY_once(x) FUNCCALL_EMPTY_each(x)
#define FUNCCALL_AGAIN_once(x) FUNCCALL_AGAIN_each(x)
#define PUSH(v, x) (__gc_var_stack__[x+2] = (void *)&(v))
#define PUSHARRAY(v, l, x) (__gc_var_stack__[x+2] = (void *)0, __gc_var_stack__[x+3] = (void *)&(v), __gc_var_stack__[x+4] = (void *)l)
#define BLOCK_SETUP_TOP(x) x
#define BLOCK_SETUP_each(x) BLOCK_SETUP_TOP(x)
#define BLOCK_SETUP_once(x) /* no effect */
#define RET_VALUE_START return (__ret__val__ = 
#define RET_VALUE_END , SET_GC_VARIABLE_STACK((void **)__gc_var_stack__[0]), __ret__val__)
#define RET_VALUE_EMPTY_START return
#define RET_VALUE_EMPTY_END 
#define RET_NOTHING { SET_GC_VARIABLE_STACK((void **)__gc_var_stack__[0]); return; }
#define RET_NOTHING_AT_END RET_NOTHING
#define DECL_RET_SAVE(type) type __ret__val__;
#define NULLED_OUT 0
#define NULL_OUT_ARRAY(a) memset(a, 0, sizeof(a))
#define GC_CAN_IGNORE /**/
#define XFORM_CAN_IGNORE /**/
#define __xform_nongcing__ /**/
#define __xform_nongcing_nonaliasing__ /**/
#define HIDE_FROM_XFORM(x) x
#define XFORM_HIDE_EXPR(x) x
#define HIDE_NOTHING_FROM_XFORM() /**/
#define START_XFORM_SKIP /**/
#define END_XFORM_SKIP /**/
#define START_XFORM_SUSPEND /**/
#define END_XFORM_SUSPEND /**/
#define XFORM_START_SKIP /**/
#define XFORM_END_SKIP /**/
#define XFORM_START_SUSPEND /**/
#define XFORM_END_SUSPEND /**/
#define XFORM_SKIP_PROC /**/
#define XFORM_ASSERT_NO_CONVERSION /**/
#define XFORM_OK_PLUS +
#define XFORM_OK_MINUS -
#define XFORM_TRUST_PLUS +
#define XFORM_TRUST_MINUS -
#define XFORM_OK_ASSIGN /**/

#define NEW_OBJ(t) new (UseGC) t
#define NEW_ARRAY(t, array) (new (UseGC) t array)
#define NEW_ATOM(t) (new (AtomicGC) t)
#define NEW_PTR(t) (new (UseGC) t)
#define NEW_ATOM_ARRAY(t, array) (new (AtomicGC) t array)
#define NEW_PTR_ARRAY(t, array) (new (UseGC) t* array)
#define DELETE(x) (delete x)
#define DELETE_ARRAY(x) (delete[] x)
#define XFORM_RESET_VAR_STACK /* empty */
#define scheme_mz_setjmp_post_xform(s) ((scheme_get_mz_setjmp())(s))

typedef unsigned char __u_char ; 
typedef unsigned short int __u_short ; 
typedef unsigned int __u_int ; 
typedef unsigned long int __u_long ; 
typedef signed char __int8_t ; 
typedef unsigned char __uint8_t ; 
typedef signed short int __int16_t ; 
typedef unsigned short int __uint16_t ; 
typedef signed int __int32_t ; 
typedef unsigned int __uint32_t ; 
typedef signed long int __int64_t ; 
typedef unsigned long int __uint64_t ; 
typedef __int8_t __int_least8_t ; 
typedef __uint8_t __uint_least8_t ; 
typedef __int16_t __int_least16_t ; 
typedef __uint16_t __uint_least16_t ; 
typedef __int32_t __int_least32_t ; 
typedef __uint32_t __uint_least32_t ; 
typedef __int64_t __int_least64_t ; 
typedef __uint64_t __uint_least64_t ; 
typedef long int __quad_t ; 
typedef unsigned long int __u_quad_t ; 
typedef long int __intmax_t ; 
typedef unsigned long int __uintmax_t ; 
typedef unsigned long int __dev_t ; 
typedef unsigned int __uid_t ; 
typedef unsigned int __gid_t ; 
typedef unsigned long int __ino_t ; 
typedef unsigned int __mode_t ; 
typedef unsigned long int __nlink_t ; 
typedef long int __off_t ; 
typedef long int __off64_t ; 
typedef int __pid_t ; 
typedef struct {
  int __val [2 ] ; 
}
__fsid_t ; 
typedef long int __clock_t ; 
typedef unsigned int __id_t ; 
typedef long int __time_t ; 
typedef long int __suseconds_t ; 
typedef int __daddr_t ; 
typedef int __key_t ; 
typedef int __clockid_t ; 
typedef void * __timer_t ; 
typedef long int __blksize_t ; 
typedef long int __blkcnt_t ; 
typedef unsigned long int __fsblkcnt_t ; 
typedef unsigned long int __fsfilcnt_t ; 
typedef long int __ssize_t ; 
typedef long int __syscall_slong_t ; 
typedef __off64_t __loff_t ; 
typedef char * __caddr_t ; 
typedef __int32_t int32_t ; 
typedef long int intptr_t ; 
typedef unsigned long int uintptr_t ; 
typedef __intmax_t intmax_t ; 
typedef __uintmax_t uintmax_t ; 
typedef int __gwchar_t ; 
typedef struct {
  long int quot ; 
  long int rem ; 
}
imaxdiv_t ; 
typedef long double mz_long_double ; 
typedef long unsigned int size_t ; 
typedef __builtin_va_list __gnuc_va_list ; 
typedef struct {
  int __count ; 
  union {
    unsigned int __wch ; 
    char __wchb [4 ] ; 
  }
  __value ; 
}
__mbstate_t ; 
typedef struct _G_fpos_t {
  __off_t __pos ; 
  __mbstate_t __state ; 
}
__fpos_t ; 
typedef struct _G_fpos64_t {
  __off64_t __pos ; 
  __mbstate_t __state ; 
}
__fpos64_t ; 
struct _IO_FILE ; 
struct _IO_FILE ; 
typedef struct _IO_FILE FILE ; 
struct _IO_FILE ; 
struct _IO_marker ; 
struct _IO_codecvt ; 
struct _IO_wide_data ; 
typedef void _IO_lock_t ; 
struct _IO_FILE {
  int _flags ; 
  char * _IO_read_ptr ; 
  char * _IO_read_end ; 
  char * _IO_read_base ; 
  char * _IO_write_base ; 
  char * _IO_write_ptr ; 
  char * _IO_write_end ; 
  char * _IO_buf_base ; 
  char * _IO_buf_end ; 
  char * _IO_save_base ; 
  char * _IO_backup_base ; 
  char * _IO_save_end ; 
  struct _IO_marker * _markers ; 
  struct _IO_FILE * _chain ; 
  int _fileno ; 
  int _flags2 ; 
  __off_t _old_offset ; 
  unsigned short _cur_column ; 
  signed char _vtable_offset ; 
  char _shortbuf [1 ] ; 
  _IO_lock_t * _lock ; 
  __off64_t _offset ; 
  struct _IO_codecvt * _codecvt ; 
  struct _IO_wide_data * _wide_data ; 
  struct _IO_FILE * _freeres_list ; 
  void * _freeres_buf ; 
  size_t __pad5 ; 
  int _mode ; 
  char _unused2 [15 * sizeof (int ) - 4 * sizeof (void * ) - sizeof (size_t ) ] ; 
}
; 
typedef __fpos_t fpos_t ; 
extern int fscanf (FILE * __restrict __stream , const char * __restrict __format , ... ) ; 
extern int scanf (const char * __restrict __format , ... ) ; 
extern int sscanf (const char * __restrict __s , const char * __restrict __format , ... ) __attribute__ ((__nothrow__ , __leaf__ ) ) ; 
extern int fscanf (FILE * __restrict __stream , const char * __restrict __format , ... ) __asm__ ("" "__isoc99_fscanf" ) ; 
extern int scanf (const char * __restrict __format , ... ) __asm__ ("" "__isoc99_scanf" ) ; 
extern int sscanf (const char * __restrict __s , const char * __restrict __format , ... ) __asm__ ("" "__isoc99_sscanf" ) __attribute__ ((__nothrow__ , __leaf__ ) ) ; 
extern int vfscanf (FILE * __restrict __s , const char * __restrict __format , __gnuc_va_list __arg ) __attribute__ ((__format__ (__scanf__ , 2 , 0 ) ) ) ; 
extern int vscanf (const char * __restrict __format , __gnuc_va_list __arg ) __attribute__ ((__format__ (__scanf__ , 1 , 0 ) ) ) ; 
extern int vsscanf (const char * __restrict __s , const char * __restrict __format , __gnuc_va_list __arg ) __attribute__ ((__nothrow__ , __leaf__ ) ) __attribute__ ((__format__ (__scanf__ , 2 , 0 ) ) ) ; 
extern int vfscanf (FILE * __restrict __s , const char * __restrict __format , __gnuc_va_list __arg ) __asm__ ("" "__isoc99_vfscanf" ) __attribute__ ((__format__ (__scanf__ , 2 , 0 ) ) ) ; 
extern int vscanf (const char * __restrict __format , __gnuc_va_list __arg ) __asm__ ("" "__isoc99_vscanf" ) __attribute__ ((__format__ (__scanf__ , 1 , 0 ) ) ) ; 
extern int vsscanf (const char * __restrict __s , const char * __restrict __format , __gnuc_va_list __arg ) __asm__ ("" "__isoc99_vsscanf" ) __attribute__ ((__nothrow__ , __leaf__ ) ) __attribute__ ((__format__ (__scanf__ , 2 , 0 ) ) ) ; 
extern const char * const sys_errlist [] ; 
typedef long int __jmp_buf [8 ] ; 
typedef struct {
  unsigned long int __val [(1024 / (8 * sizeof (unsigned long int ) ) ) ] ; 
}
__sigset_t ; 
struct __jmp_buf_tag {
  __jmp_buf __jmpbuf ; 
  int __mask_was_saved ; 
  __sigset_t __saved_mask ; 
}
; 
typedef struct __jmp_buf_tag jmp_buf [1 ] ; 
typedef struct __jmp_buf_tag sigjmp_buf [1 ] ; 
typedef int wchar_t ; 
typedef struct {
  int quot ; 
  int rem ; 
}
div_t ; 
typedef struct {
  long int quot ; 
  long int rem ; 
}
ldiv_t ; 
__extension__ typedef struct {
  long long int quot ; 
  long long int rem ; 
}
lldiv_t ; 
typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__ ) ) ) ; 
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__ ) ) ) ; 
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__ ) ) ) ; 
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__ ) ) ) ; 
typedef int register_t __attribute__ ((__mode__ (__word__ ) ) ) ; 
static __inline __uint16_t __bswap_16 (__uint16_t __bsx ) {
  return __builtin_bswap16 (__bsx ) ; 
}
static __inline __uint32_t __bswap_32 (__uint32_t __bsx ) {
  return __builtin_bswap32 (__bsx ) ; 
}
__extension__ static __inline __uint64_t __bswap_64 (__uint64_t __bsx ) {
  return __builtin_bswap64 (__bsx ) ; 
}
static __inline __uint16_t __uint16_identity (__uint16_t __x ) {
  return __x ; 
}
static __inline __uint32_t __uint32_identity (__uint32_t __x ) {
  return __x ; 
}
static __inline __uint64_t __uint64_identity (__uint64_t __x ) {
  return __x ; 
}
struct timeval {
  __time_t tv_sec ; 
  __suseconds_t tv_usec ; 
}
; 
struct timespec {
  __time_t tv_sec ; 
  __syscall_slong_t tv_nsec ; 
}
; 
typedef long int __fd_mask ; 
typedef struct {
  __fd_mask __fds_bits [1024 / (8 * (int ) sizeof (__fd_mask ) ) ] ; 
}
fd_set ; 
struct __pthread_rwlock_arch_t {
  unsigned int __readers ; 
  unsigned int __writers ; 
  unsigned int __wrphase_futex ; 
  unsigned int __writers_futex ; 
  unsigned int __pad3 ; 
  unsigned int __pad4 ; 
  int __cur_writer ; 
  int __shared ; 
  signed char __rwelision ; 
  unsigned char __pad1 [7 ] ; 
  unsigned long int __pad2 ; 
  unsigned int __flags ; 
}
; 
typedef struct __pthread_internal_list {
  struct __pthread_internal_list * __prev ; 
  struct __pthread_internal_list * __next ; 
}
__pthread_list_t ; 
struct __pthread_mutex_s {
  int __lock ; 
  unsigned int __count ; 
  int __owner ; 
  unsigned int __nusers ; 
  int __kind ; 
  short __spins ; 
  short __elision ; 
  __pthread_list_t __list ; 
}
; 
struct __pthread_cond_s {
  __extension__ union {
    __extension__ unsigned long long int __wseq ; 
    struct {
      unsigned int __low ; 
      unsigned int __high ; 
    }
    __wseq32 ; 
  }
  ; 
  __extension__ union {
    __extension__ unsigned long long int __g1_start ; 
    struct {
      unsigned int __low ; 
      unsigned int __high ; 
    }
    __g1_start32 ; 
  }
  ; 
  unsigned int __g_refs [2 ] ; 
  unsigned int __g_size [2 ] ; 
  unsigned int __g1_orig_size ; 
  unsigned int __wrefs ; 
  unsigned int __g_signals [2 ] ; 
}
; 
typedef union {
  char __size [4 ] ; 
  int __align ; 
}
pthread_mutexattr_t ; 
typedef union {
  char __size [4 ] ; 
  int __align ; 
}
pthread_condattr_t ; 
union pthread_attr_t {
  char __size [56 ] ; 
  long int __align ; 
}
; 
typedef union pthread_attr_t pthread_attr_t ; 
typedef union {
  struct __pthread_mutex_s __data ; 
  char __size [40 ] ; 
  long int __align ; 
}
pthread_mutex_t ; 
typedef union {
  struct __pthread_cond_s __data ; 
  char __size [48 ] ; 
  __extension__ long long int __align ; 
}
pthread_cond_t ; 
typedef union {
  struct __pthread_rwlock_arch_t __data ; 
  char __size [56 ] ; 
  long int __align ; 
}
pthread_rwlock_t ; 
typedef union {
  char __size [8 ] ; 
  long int __align ; 
}
pthread_rwlockattr_t ; 
typedef union {
  char __size [32 ] ; 
  long int __align ; 
}
pthread_barrier_t ; 
typedef union {
  char __size [4 ] ; 
  int __align ; 
}
pthread_barrierattr_t ; 
struct random_data {
  int32_t * fptr ; 
  int32_t * rptr ; 
  int32_t * state ; 
  int rand_type ; 
  int rand_deg ; 
  int rand_sep ; 
  int32_t * end_ptr ; 
}
; 
struct drand48_data {
  unsigned short int __x [3 ] ; 
  unsigned short int __old_x [3 ] ; 
  unsigned short int __c ; 
  unsigned short int __init ; 
  __extension__ unsigned long long int __a ; 
}
; 
typedef int (* __compar_fn_t ) (const void * , const void * ) ; 
extern void * memset (void * __s , int __c , size_t __n ) __attribute__ ((__nothrow__ , __leaf__ ) ) __attribute__ ((__nonnull__ (1 ) ) ) ; 
struct __locale_struct {
  struct __locale_data * __locales [13 ] ; 
  const unsigned short int * __ctype_b ; 
  const int * __ctype_tolower ; 
  const int * __ctype_toupper ; 
  const char * __names [13 ] ; 
}
; 
typedef struct __locale_struct * __locale_t ; 
typedef __locale_t locale_t ; 
typedef struct {
  long long __max_align_ll __attribute__ ((__aligned__ (__alignof__ (long long ) ) ) ) ; 
  long double __max_align_ld __attribute__ ((__aligned__ (__alignof__ (long double ) ) ) ) ; 
}
max_align_t ; 
typedef short Scheme_Type ; 
typedef int mzshort ; 
typedef unsigned int mzchar ; 
typedef intptr_t mzlonglong ; 
typedef uintptr_t umzlonglong ; 
typedef struct Scheme_Object {
  Scheme_Type type ; 
  short keyex ; 
}
Scheme_Object ; 
typedef struct Scheme_Inclhash_Object {
  Scheme_Object so ; 
}
Scheme_Inclhash_Object ; 
typedef struct Scheme_Simple_Object {
  Scheme_Inclhash_Object iso ; 
  union {
    struct {
      mzchar * string_val ; 
      intptr_t tag_val ; 
    }
    char_str_val ; 
    struct {
      char * string_val ; 
      intptr_t tag_val ; 
    }
    byte_str_val ; 
    struct {
      void * ptr1 , * ptr2 ; 
    }
    two_ptr_val ; 
    struct {
      int int1 ; 
      int int2 ; 
    }
    two_int_val ; 
    struct {
      void * ptr ; 
      int pint ; 
    }
    ptr_int_val ; 
    struct {
      void * ptr ; 
      intptr_t pint ; 
    }
    ptr_long_val ; 
    struct {
      struct Scheme_Object * car , * cdr ; 
    }
    pair_val ; 
    struct {
      mzshort len ; 
      mzshort * vec ; 
    }
    svector_val ; 
    struct {
      void * val ; 
      Scheme_Object * type ; 
    }
    cptr_val ; 
  }
  u ; 
}
Scheme_Simple_Object ; 
typedef struct Scheme_Object * (* Scheme_Closure_Func ) (struct Scheme_Object * ) ; 
typedef struct {
  Scheme_Inclhash_Object iso ; 
  union {
    mzchar char_val ; 
    Scheme_Object * ptr_value ; 
    intptr_t int_val ; 
    Scheme_Object * ptr_val ; 
  }
  u ; 
}
Scheme_Small_Object ; 
typedef struct {
  Scheme_Object so ; 
  double double_val ; 
}
Scheme_Double ; 
typedef struct {
  Scheme_Object so ; 
  mz_long_double long_double_val ; 
}
Scheme_Long_Double ; 
typedef struct {
  Scheme_Object so ; 
  float float_val ; 
}
Scheme_Float ; 
typedef struct Scheme_Symbol {
  Scheme_Inclhash_Object iso ; 
  intptr_t len ; 
  char s [] ; 
}
Scheme_Symbol ; 
typedef struct Scheme_Vector {
  Scheme_Inclhash_Object iso ; 
  intptr_t size ; 
  Scheme_Object * els [] ; 
}
Scheme_Vector ; 
typedef struct Scheme_Double_Vector {
  Scheme_Inclhash_Object iso ; 
  intptr_t size ; 
  double els [] ; 
}
Scheme_Double_Vector ; 
typedef struct Scheme_Long_Double_Vector {
  Scheme_Inclhash_Object iso ; 
  intptr_t size ; 
  mz_long_double els [] ; 
}
Scheme_Long_Double_Vector ; 
typedef struct Scheme_Print_Params Scheme_Print_Params ; 
typedef void (* Scheme_Type_Printer ) (Scheme_Object * v , int for_display , Scheme_Print_Params * pp ) ; 
typedef int (* Scheme_Equal_Proc ) (Scheme_Object * obj1 , Scheme_Object * obj2 , void * cycle_data ) ; 
typedef intptr_t (* Scheme_Primary_Hash_Proc ) (Scheme_Object * obj , intptr_t base , void * cycle_data ) ; 
typedef intptr_t (* Scheme_Secondary_Hash_Proc ) (Scheme_Object * obj , void * cycle_data ) ; 
enum {
  scheme_toplevel_type , scheme_static_toplevel_type , scheme_local_type , scheme_local_unbox_type , scheme_application_type , scheme_application2_type , scheme_application3_type , scheme_sequence_type , scheme_branch_type , scheme_lambda_type , scheme_let_value_type , scheme_let_void_type , scheme_letrec_type , scheme_let_one_type , scheme_with_cont_mark_type , scheme_define_values_type , scheme_set_bang_type , scheme_boxenv_type , scheme_begin0_sequence_type , scheme_varref_form_type , scheme_apply_values_type , scheme_with_immed_mark_type , scheme_case_lambda_sequence_type , scheme_inline_variant_type , _scheme_values_types_ , scheme_linklet_type , scheme_ir_local_type , scheme_ir_lambda_type , scheme_ir_let_value_type , scheme_ir_let_header_type , scheme_ir_toplevel_type , scheme_quote_compilation_type , scheme_variable_type , _scheme_ir_values_types_ , scheme_linklet_bundle_type , scheme_linklet_directory_type , scheme_instance_type , scheme_prim_type , scheme_closed_prim_type , scheme_closure_type , scheme_case_closure_type , scheme_cont_type , scheme_escaping_cont_type , scheme_proc_struct_type , scheme_native_closure_type , scheme_proc_chaperone_type , scheme_chaperone_type , scheme_structure_type , scheme_integer_type , scheme_bignum_type , scheme_rational_type , scheme_float_type , scheme_double_type , scheme_complex_type , scheme_char_type , scheme_long_double_type , scheme_char_string_type , scheme_byte_string_type , scheme_unix_path_type , scheme_windows_path_type , scheme_symbol_type , scheme_keyword_type , scheme_null_type , scheme_pair_type , scheme_mutable_pair_type , scheme_vector_type , scheme_inspector_type , scheme_input_port_type , scheme_output_port_type , scheme_eof_type , scheme_true_type , scheme_false_type , scheme_void_type , scheme_primitive_syntax_type , scheme_macro_type , scheme_box_type , scheme_thread_type , scheme_cont_mark_set_type , scheme_sema_type , scheme_hash_table_type , scheme_hash_tree_type , scheme_eq_hash_tree_type , scheme_eqv_hash_tree_type , scheme_hash_tree_subtree_type , scheme_hash_tree_collision_type , scheme_hash_tree_indirection_type , scheme_bucket_type , scheme_bucket_table_type , scheme_cpointer_type , scheme_prefix_type , scheme_weak_box_type , scheme_ephemeron_type , scheme_struct_type_type , scheme_set_macro_type , scheme_listener_type , scheme_env_type , scheme_startup_env_type , scheme_config_type , scheme_stx_type , scheme_will_executor_type , scheme_custodian_type , scheme_random_state_type , scheme_regexp_type , scheme_subprocess_type , scheme_eval_waiting_type , scheme_tail_call_waiting_type , scheme_undefined_type , scheme_struct_property_type , scheme_chaperone_property_type , scheme_multiple_values_type , scheme_placeholder_type , scheme_table_placeholder_type , scheme_svector_type , scheme_resolve_prefix_type , scheme_security_guard_type , scheme_indent_type , scheme_udp_type , scheme_udp_evt_type , scheme_tcp_accept_evt_type , scheme_id_macro_type , scheme_evt_set_type , scheme_wrap_evt_type , scheme_handle_evt_type , scheme_replace_evt_type , scheme_active_replace_evt_type , scheme_nack_guard_evt_type , scheme_semaphore_repost_type , scheme_channel_type , scheme_channel_put_type , scheme_thread_resume_type , scheme_thread_suspend_type , scheme_thread_dead_type , scheme_poll_evt_type , scheme_nack_evt_type , scheme_thread_set_type , scheme_string_converter_type , scheme_alarm_type , scheme_thread_recv_evt_type , scheme_thread_cell_type , scheme_channel_syncer_type , scheme_write_evt_type , scheme_always_evt_type , scheme_never_evt_type , scheme_progress_evt_type , scheme_place_dead_type , scheme_already_comp_type , scheme_readtable_type , scheme_thread_cell_values_type , scheme_global_ref_type , scheme_cont_mark_chain_type , scheme_raw_pair_type , scheme_prompt_type , scheme_prompt_tag_type , scheme_continuation_mark_key_type , scheme_delay_syntax_type , scheme_cust_box_type , scheme_logger_type , scheme_log_reader_type , scheme_noninline_proc_type , scheme_future_type , scheme_flvector_type , scheme_extflvector_type , scheme_fxvector_type , scheme_place_type , scheme_place_object_type , scheme_place_async_channel_type , scheme_place_bi_channel_type , scheme_once_used_type , scheme_serialized_symbol_type , scheme_serialized_keyword_type , scheme_serialized_structure_type , scheme_fsemaphore_type , scheme_serialized_tcp_fd_type , scheme_serialized_file_fd_type , scheme_port_closed_evt_type , scheme_proc_shape_type , scheme_struct_prop_proc_shape_type , scheme_struct_proc_shape_type , scheme_phantom_bytes_type , scheme_environment_variables_type , scheme_filesystem_change_evt_type , scheme_ctype_type , scheme_plumber_type , scheme_plumber_handle_type , scheme_deferred_expr_type , scheme_unquoted_printing_string_type , scheme_will_be_lambda_type , _scheme_last_normal_type_ , scheme_rt_weak_array , scheme_rt_comp_env , scheme_rt_constant_binding , scheme_rt_resolve_info , scheme_rt_unresolve_info , scheme_rt_optimize_info , scheme_rt_cont_mark , scheme_rt_saved_stack , scheme_rt_reply_item , scheme_rt_ir_lambda_info , scheme_rt_overflow , scheme_rt_overflow_jmp , scheme_rt_meta_cont , scheme_rt_dyn_wind_cell , scheme_rt_dyn_wind_info , scheme_rt_dyn_wind , scheme_rt_dup_check , scheme_rt_thread_memory , scheme_rt_input_file , scheme_rt_input_fd , scheme_rt_oskit_console_input , scheme_rt_tested_input_file , scheme_rt_tested_output_file , scheme_rt_indexed_string , scheme_rt_output_file , scheme_rt_pipe , scheme_rt_system_child , scheme_rt_tcp , scheme_rt_write_data , scheme_rt_tcp_select_info , scheme_rt_param_data , scheme_rt_will , scheme_rt_finalization , scheme_rt_finalizations , scheme_rt_cpp_object , scheme_rt_cpp_array_object , scheme_rt_stack_object , scheme_thread_hop_type , scheme_rt_srcloc , scheme_rt_evt , scheme_rt_syncing , scheme_rt_comp_prefix , scheme_rt_user_input , scheme_rt_user_output , scheme_rt_compact_port , scheme_rt_read_special_dw , scheme_rt_regwork , scheme_rt_rx_lazy_string , scheme_rt_buf_holder , scheme_rt_parameterization , scheme_rt_print_params , scheme_rt_read_params , scheme_rt_native_code , scheme_rt_native_code_plus_case , scheme_rt_jitter_data , scheme_rt_module_exports , scheme_rt_delay_load_info , scheme_rt_marshal_info , scheme_rt_unmarshal_info , scheme_rt_runstack , scheme_rt_sfs_info , scheme_rt_validate_clearing , scheme_rt_lightweight_cont , scheme_rt_export_info , scheme_rt_cont_jmp , scheme_rt_letrec_check_frame , _scheme_last_type_ }
; 
typedef struct Scheme_Cptr {
  Scheme_Inclhash_Object so ; 
  void * val ; 
  Scheme_Object * type ; 
}
Scheme_Cptr ; 
typedef struct Scheme_Offset_Cptr {
  Scheme_Cptr cptr ; 
  intptr_t offset ; 
}
Scheme_Offset_Cptr ; 
typedef struct Scheme_Object * (Scheme_Prim ) (int argc , Scheme_Object * argv [] ) ; 
typedef struct Scheme_Object * (Scheme_Primitive_Closure_Proc ) (int argc , struct Scheme_Object * argv [] , Scheme_Object * p ) ; 
typedef struct {
  Scheme_Object so ; 
  unsigned short flags ; 
}
Scheme_Prim_Proc_Header ; 
typedef struct {
  Scheme_Prim_Proc_Header pp ; 
  Scheme_Primitive_Closure_Proc * prim_val ; 
  const char * name ; 
  mzshort mina ; 
  union {
    mzshort * cases ; 
    mzshort maxa ; 
  }
  mu ; 
}
Scheme_Primitive_Proc ; 
typedef struct {
  Scheme_Primitive_Proc pp ; 
  mzshort minr , maxr ; 
}
Scheme_Prim_W_Result_Arity ; 
typedef struct Scheme_Primitive_Closure {
  Scheme_Primitive_Proc p ; 
  mzshort count ; 
  Scheme_Object * val [] ; 
}
Scheme_Primitive_Closure ; 
typedef struct Scheme_Object * (Scheme_Closed_Prim ) (void * d , int argc , struct Scheme_Object * argv [] ) ; 
typedef struct {
  Scheme_Prim_Proc_Header pp ; 
  Scheme_Closed_Prim * prim_val ; 
  void * data ; 
  const char * name ; 
  mzshort mina , maxa ; 
}
Scheme_Closed_Primitive_Proc ; 
typedef struct {
  Scheme_Closed_Primitive_Proc p ; 
  mzshort * cases ; 
}
Scheme_Closed_Case_Primitive_Proc ; 
typedef struct {
  Scheme_Closed_Primitive_Proc p ; 
  mzshort minr , maxr ; 
}
Scheme_Closed_Prim_W_Result_Arity ; 
typedef struct Scheme_Hash_Table {
  Scheme_Inclhash_Object iso ; 
  intptr_t size ; 
  intptr_t count ; 
  Scheme_Object * * keys ; 
  Scheme_Object * * vals ; 
  void (* make_hash_indices ) (void * v , intptr_t * h1 , intptr_t * h2 ) ; 
  int (* compare ) (void * v1 , void * v2 ) ; 
  Scheme_Object * mutex ; 
  intptr_t mcount ; 
}
Scheme_Hash_Table ; 
typedef struct Scheme_Hash_Tree Scheme_Hash_Tree ; 
typedef struct Scheme_Bucket {
  Scheme_Object so ; 
  void * val ; 
  char * key ; 
}
Scheme_Bucket ; 
typedef struct Scheme_Bucket_Table {
  Scheme_Object so ; 
  intptr_t size ; 
  intptr_t count ; 
  Scheme_Bucket * * buckets ; 
  char weak ; 
  char with_home ; 
  void (* make_hash_indices ) (void * v , intptr_t * h1 , intptr_t * h2 ) ; 
  int (* compare ) (void * v1 , void * v2 ) ; 
  Scheme_Object * mutex ; 
}
Scheme_Bucket_Table ; 
enum {
  SCHEME_hash_string , SCHEME_hash_ptr , SCHEME_hash_weak_ptr , SCHEME_hash_late_weak_ptr }
; 
enum {
  SCHEME_hashtr_eq , SCHEME_hashtr_equal , SCHEME_hashtr_eqv }
; 
typedef struct Scheme_Env Scheme_Env ; 
typedef struct {
  jmp_buf jb ; 
  uintptr_t stack_frame ; 
}
mz_one_jit_jmp_buf ; 
typedef mz_one_jit_jmp_buf mz_jit_jmp_buf [1 ] ; 
typedef struct {
  XFORM_CAN_IGNORE mz_jit_jmp_buf jb ; 
  intptr_t gcvs ; 
  intptr_t gcvs_cnt ; 
}
mz_jmp_buf ; 
typedef struct Scheme_Jumpup_Buf {
  void * stack_from , * stack_copy ; 
  intptr_t stack_size , stack_max_size ; 
  struct Scheme_Cont * cont ; 
  mz_jmp_buf buf ; 
  void * gc_var_stack ; 
  void * external_stack ; 
}
Scheme_Jumpup_Buf ; 
typedef struct Scheme_Jumpup_Buf_Holder {
  Scheme_Type type ; 
  Scheme_Jumpup_Buf buf ; 
}
Scheme_Jumpup_Buf_Holder ; 
typedef struct Scheme_Continuation_Jump_State {
  struct Scheme_Object * jumping_to_continuation ; 
  struct Scheme_Object * alt_full_continuation ; 
  Scheme_Object * val ; 
  mzshort num_vals ; 
  char is_kill , is_escape , skip_dws ; 
}
Scheme_Continuation_Jump_State ; 
typedef int (* Scheme_Setjmp_Proc ) (void * ) ; 
typedef struct Scheme_Cont_Frame_Data {
  intptr_t cont_mark_pos ; 
  intptr_t cont_mark_stack ; 
  void * cache ; 
}
Scheme_Cont_Frame_Data ; 
typedef struct objhead {
  uintptr_t type : 3 ; 
  uintptr_t mark : 1 ; 
  uintptr_t btc_mark : 1 ; 
  uintptr_t moved : 1 ; 
  uintptr_t dead : 1 ; 
  uintptr_t size : 14 ; 
  uintptr_t hash : ((8 * sizeof (intptr_t ) ) - (4 + 3 + 14 ) ) ; 
}
objhead ; 
typedef void (Scheme_Close_Custodian_Client ) (Scheme_Object * o , void * data ) ; 
typedef void (* Scheme_Exit_Closer_Func ) (Scheme_Object * , Scheme_Close_Custodian_Client * , void * ) ; 
typedef Scheme_Object * (* Scheme_Custodian_Extractor ) (Scheme_Object * o ) ; 
typedef struct Scheme_Object Scheme_Custodian_Reference ; 
typedef struct Scheme_Custodian Scheme_Custodian ; 
typedef Scheme_Bucket_Table Scheme_Thread_Cell_Table ; 
typedef struct Scheme_Config Scheme_Config ; 
typedef struct Scheme_Plumber Scheme_Plumber ; 
typedef int (* Scheme_Ready_Fun ) (Scheme_Object * o ) ; 
typedef void (* Scheme_Needs_Wakeup_Fun ) (Scheme_Object * , void * ) ; 
typedef Scheme_Object * (* Scheme_Sync_Sema_Fun ) (Scheme_Object * , int * repost ) ; 
typedef int (* Scheme_Sync_Filter_Fun ) (Scheme_Object * ) ; 
typedef struct Scheme_Thread {
  Scheme_Object so ; 
  struct Scheme_Thread * next ; 
  struct Scheme_Thread * prev ; 
  struct Scheme_Thread_Set * t_set_parent ; 
  Scheme_Object * t_set_next ; 
  Scheme_Object * t_set_prev ; 
  mz_jmp_buf * error_buf ; 
  Scheme_Continuation_Jump_State cjs ; 
  struct Scheme_Meta_Continuation * decompose_mc ; 
  Scheme_Thread_Cell_Table * cell_values ; 
  Scheme_Config * init_config ; 
  Scheme_Object * init_break_cell ; 
  int can_break_at_swap ; 
  Scheme_Object * * runstack ; 
  Scheme_Object * * runstack_start ; 
  intptr_t runstack_size ; 
  struct Scheme_Saved_Stack * runstack_saved ; 
  Scheme_Object * * runstack_tmp_keep ; 
  Scheme_Object * * spare_runstack ; 
  intptr_t spare_runstack_size ; 
  struct Scheme_Thread * * runstack_owner ; 
  struct Scheme_Saved_Stack * runstack_swapped ; 
  intptr_t cont_mark_pos ; 
  intptr_t cont_mark_stack ; 
  struct Scheme_Cont_Mark * * cont_mark_stack_segments ; 
  intptr_t cont_mark_seg_count ; 
  intptr_t cont_mark_stack_bottom ; 
  intptr_t cont_mark_pos_bottom ; 
  struct Scheme_Thread * * cont_mark_stack_owner ; 
  struct Scheme_Cont_Mark * cont_mark_stack_swapped ; 
  struct Scheme_Prompt * meta_prompt ; 
  struct Scheme_Meta_Continuation * meta_continuation ; 
  struct Scheme_Prompt * acting_barrier_prompt ; 
  intptr_t engine_weight ; 
  void * stack_start ; 
  void * stack_end ; 
  Scheme_Jumpup_Buf jmpup_buf ; 
  struct Scheme_Dynamic_Wind * dw ; 
  int next_meta ; 
  int running ; 
  Scheme_Object * suspended_box ; 
  Scheme_Object * resumed_box ; 
  Scheme_Object * dead_box ; 
  Scheme_Object * running_box ; 
  Scheme_Object * sync_box ; 
  struct Scheme_Thread * gc_prep_chain ; 
  struct Scheme_Thread * nester , * nestee ; 
  struct future_t * current_ft ; 
  double sleep_end ; 
  int block_descriptor ; 
  Scheme_Object * blocker ; 
  Scheme_Ready_Fun block_check ; 
  Scheme_Needs_Wakeup_Fun block_needs_wakeup ; 
  char ran_some ; 
  char suspend_to_kill ; 
  struct Scheme_Thread * return_marks_to ; 
  Scheme_Object * returned_marks ; 
  struct Scheme_Overflow * overflow ; 
  struct Scheme_Marshal_Tables * current_mt ; 
  struct Optimize_Info * constant_folding ; 
  Scheme_Object * reading_delayed ; 
  Scheme_Object * (* overflow_k ) (void ) ; 
  Scheme_Object * overflow_reply ; 
  Scheme_Object * * tail_buffer ; 
  int tail_buffer_size ; 
  Scheme_Object * * values_buffer ; 
  int values_buffer_size ; 
  struct {
    struct {
      Scheme_Object * wait_expr ; 
    }
    eval ; 
    struct {
      Scheme_Object * tail_rator ; 
      Scheme_Object * * tail_rands ; 
      intptr_t tail_num_rands ; 
    }
    apply ; 
    struct {
      Scheme_Object * * array ; 
      intptr_t count ; 
    }
    multiple ; 
    struct {
      void * p1 , * p2 , * p3 , * p4 , * p5 ; 
      intptr_t i1 , i2 , i3 , i4 ; 
    }
    k ; 
  }
  ku ; 
  Scheme_Object * self_for_proc_chaperone ; 
  short suspend_break ; 
  short external_break ; 
  void (* on_kill ) (struct Scheme_Thread * p ) ; 
  void * kill_data ; 
  void (* private_on_kill ) (void * ) ; 
  void * private_kill_data ; 
  void * * private_kill_next ; 
  void * * user_tls ; 
  int user_tls_size ; 
  intptr_t gmp_tls [6 ] ; 
  void * gmp_tls_data ; 
  intptr_t accum_process_msec ; 
  intptr_t current_start_process_msec ; 
  struct Scheme_Thread_Custodian_Hop * mr_hop ; 
  Scheme_Custodian_Reference * mref ; 
  Scheme_Object * extra_mrefs ; 
  Scheme_Object * transitive_resumes ; 
  Scheme_Object * name ; 
  Scheme_Object * mbox_first ; 
  Scheme_Object * mbox_last ; 
  Scheme_Object * mbox_sema ; 
  long saved_errno ; 
  int futures_slow_path_tracing ; 
  struct GC_Thread_Info * gc_info ; 
  void * place_channel_msg_in_flight ; 
  void * place_channel_msg_chain_in_flight ; 
}
Scheme_Thread ; 
typedef struct {
  void * orig_return_address ; 
  void * stack_frame ; 
  struct Scheme_Object * cache ; 
  void * orig_result ; 
}
Stack_Cache_Elem ; 
typedef intptr_t rxpos ; 
struct gmp_tmp_stack {
  void * end ; 
  void * alloc_point ; 
  struct gmp_tmp_stack * prev ; 
}
; 
typedef void (* Scheme_Sleep_Proc ) (float seconds , void * fds ) ; 
typedef void (* Scheme_On_Atomic_Timeout_Proc ) (void * data , int must_give_up ) ; 
typedef struct Thread_Local_Variables {
  int scheme_current_place_id_ ; 
  void * * GC_variable_stack_ ; 
  struct NewGC * GC_instance_ ; 
  uintptr_t GC_gen0_alloc_page_ptr_ ; 
  uintptr_t GC_gen0_alloc_page_end_ ; 
  int GC_gen0_alloc_only_ ; 
  uintptr_t force_gc_for_place_accounting_ ; 
  uintptr_t scheme_os_thread_id_ ; 
  int scheme_starting_up_ ; 
  struct rktio_t * scheme_rktio_ ; 
  void * bignum_cache_ [16 ] ; 
  int cache_count_ ; 
  struct Scheme_Hash_Table * toplevels_ht_ ; 
  struct Scheme_Hash_Table * locals_ht_ [2 ] ; 
  volatile int scheme_fuel_counter_ ; 
  uintptr_t scheme_stack_boundary_ ; 
  uintptr_t volatile scheme_jit_stack_boundary_ ; 
  volatile int scheme_future_need_gc_pause_ ; 
  int scheme_use_rtcall_ ; 
  int in_jit_critical_section_ ; 
  void * jit_buffer_cache_ ; 
  intptr_t jit_buffer_cache_size_ ; 
  int jit_buffer_cache_registered_ ; 
  int scheme_continuation_application_count_ ; 
  int scheme_cont_capture_count_ ; 
  int scheme_prompt_capture_count_ ; 
  struct Scheme_Prompt * available_prompt_ ; 
  struct Scheme_Prompt * available_cws_prompt_ ; 
  struct Scheme_Prompt * available_regular_prompt_ ; 
  struct Scheme_Dynamic_Wind * available_prompt_dw_ ; 
  struct Scheme_Meta_Continuation * available_prompt_mc_ ; 
  struct Scheme_Cont * offstack_cont_ ; 
  struct Scheme_Overflow * offstack_overflow_ ; 
  struct Scheme_Overflow_Jmp * scheme_overflow_jmp_ ; 
  void * scheme_overflow_stack_start_ ; 
  void * * codetab_tree_ ; 
  int during_set_ ; 
  Stack_Cache_Elem stack_cache_stack_ [32 ] ; 
  intptr_t stack_cache_stack_pos_ ; 
  struct Scheme_Object * * fixup_runstack_base_ ; 
  int fixup_already_in_place_ ; 
  void * retry_alloc_r1_ ; 
  double scheme_jit_save_fp_ ; 
  double scheme_jit_save_fp2_ ; 
  mz_long_double scheme_jit_save_extfp_ ; 
  mz_long_double scheme_jit_save_extfp2_ ; 
  struct Scheme_Bucket_Table * starts_table_ ; 
  struct mz_proc_thread * proc_thread_self_ ; 
  struct Scheme_Object * scheme_orig_stdout_port_ ; 
  struct Scheme_Object * scheme_orig_stderr_port_ ; 
  struct Scheme_Object * scheme_orig_stdin_port_ ; 
  struct rktio_ltps_t * scheme_semaphore_fd_set_ ; 
  struct Scheme_Object * fs_change_props_ ; 
  struct Scheme_Custodian * new_port_cust_ ; 
  char * read_string_byte_buffer_ ; 
  struct ITimer_Data * itimerdata_ ; 
  char * quick_buffer_ ; 
  char * quick_encode_buffer_ ; 
  char * quick_print_buffer_ ; 
  struct Scheme_Hash_Table * cache_ht_ ; 
  char * regstr_ ; 
  char * regparsestr_ ; 
  int regmatchmin_ ; 
  int regmatchmax_ ; 
  int regmaxbackposn_ ; 
  int regsavepos_ ; 
  struct Scheme_Hash_Table * regbackknown_ ; 
  struct Scheme_Hash_Table * regbackdepends_ ; 
  rxpos regparse_ ; 
  rxpos regparse_end_ ; 
  int regnpar_ ; 
  int regncounter_ ; 
  rxpos regcode_ ; 
  rxpos regcodesize_ ; 
  rxpos regcodemax_ ; 
  intptr_t regmaxlookback_ ; 
  const char * regerrorwho_ ; 
  Scheme_Object * regerrorproc_ ; 
  Scheme_Object * regerrorval_ ; 
  intptr_t rx_buffer_size_ ; 
  rxpos * startp_buffer_cache_ ; 
  rxpos * endp_buffer_cache_ ; 
  rxpos * maybep_buffer_cache_ ; 
  rxpos * match_stack_buffer_cache_ ; 
  uintptr_t scheme_os_thread_stack_base_ ; 
  struct Scheme_Object * scheme_system_idle_channel_ ; 
  struct Scheme_Object * system_idle_put_evt_ ; 
  void * stack_copy_cache_ [10 ] ; 
  intptr_t stack_copy_size_cache_ [10 ] ; 
  int scc_pos_ ; 
  struct Scheme_Instance * scheme_startup_instance_ ; 
  struct startup_instance_top_t * c_startup_instance_top_ ; 
  struct Scheme_Thread * scheme_current_thread_ ; 
  struct Scheme_Thread * scheme_main_thread_ ; 
  struct Scheme_Thread * scheme_first_thread_ ; 
  struct Scheme_Thread * gc_prep_thread_chain_ ; 
  struct Scheme_Thread_Set * scheme_thread_set_top_ ; 
  struct Scheme_Current_LWC * scheme_current_lwc_ ; 
  intptr_t process_time_at_swap_ ; 
  int num_running_threads_ ; 
  int swap_no_setjmp_ ; 
  int thread_swap_count_ ; 
  int scheme_did_gc_count_ ; 
  struct Scheme_Future_State * scheme_future_state_ ; 
  struct Scheme_Future_Thread_State * scheme_future_thread_state_ ; 
  void * jit_future_storage_ [4 ] ; 
  struct Scheme_Object * * scheme_current_runstack_start_ ; 
  struct Scheme_Object * * scheme_current_runstack_ ; 
  intptr_t scheme_current_cont_mark_stack_ ; 
  intptr_t scheme_current_cont_mark_pos_ ; 
  struct Scheme_Custodian * main_custodian_ ; 
  struct Scheme_Hash_Table * limited_custodians_ ; 
  struct Scheme_Plumber * initial_plumber_ ; 
  struct Scheme_Config * initial_config_ ; 
  struct Scheme_Thread * swap_target_ ; 
  struct Scheme_Object * scheduled_kills_ ; 
  int do_atomic_ ; 
  int missed_context_switch_ ; 
  int all_breaks_disabled_ ; 
  int have_activity_ ; 
  int scheme_active_but_sleeping_ ; 
  int thread_ended_with_activity_ ; 
  int scheme_no_stack_overflow_ ; 
  int needs_sleep_cancelled_ ; 
  double needs_sleep_time_end_ ; 
  int tls_pos_ ; 
  struct Scheme_Object * the_nested_exn_handler_ ; 
  struct Scheme_Object * cust_closers_ ; 
  struct Scheme_Object * thread_swap_callbacks_ ; 
  struct Scheme_Object * thread_swap_out_callbacks_ ; 
  struct Scheme_Object * recycle_cell_ ; 
  struct Scheme_Object * maybe_recycle_cell_ ; 
  int recycle_cc_count_ ; 
  void * gmp_mem_pool_ ; 
  uintptr_t max_total_allocation_ ; 
  uintptr_t current_total_allocation_ ; 
  struct gmp_tmp_stack gmp_tmp_xxx_ ; 
  struct gmp_tmp_stack * gmp_tmp_current_ ; 
  struct Scheme_Logger * scheme_main_logger_ ; 
  struct Scheme_Logger * scheme_gc_logger_ ; 
  struct Scheme_Logger * scheme_future_logger_ ; 
  struct Scheme_Logger * scheme_place_logger_ ; 
  int scheme_overflow_count_ ; 
  struct Scheme_Object * original_pwd_ ; 
  void * file_path_wc_buffer_ ; 
  intptr_t scheme_hash_request_count_ ; 
  intptr_t scheme_hash_iteration_count_ ; 
  struct Scheme_Bucket_Table * scheme_namespace_to_env_ ; 
  int special_is_ok_ ; 
  int scheme_force_port_closed_ ; 
  int fd_reserved_ ; 
  struct rktio_fd_t * the_fd_ ; 
  int scheme_num_read_syntax_objects_ ; 
  struct Scheme_Load_Delay * clear_bytes_chain_ ; 
  const char * failure_msg_for_read_ ; 
  void * * dgc_array_ ; 
  int * dgc_count_ ; 
  int dgc_size_ ; 
  void (* save_oom_ ) (void ) ; 
  int current_lifetime_ ; 
  int scheme_main_was_once_suspended_ ; 
  int buffer_init_size_ ; 
  intptr_t scheme_total_gc_time_ ; 
  intptr_t start_this_gc_time_ ; 
  intptr_t end_this_gc_time_ ; 
  double start_this_gc_real_time_ ; 
  double end_this_gc_real_time_ ; 
  struct Scheme_Struct_Type * gc_info_prefab_ ; 
  struct Scheme_Struct_Type * place_event_prefab_ ; 
  volatile short delayed_break_ready_ ; 
  struct Scheme_Thread * main_break_target_thread_ ; 
  intptr_t scheme_code_page_total_ ; 
  intptr_t max_gc_pre_used_bytes_ ; 
  int num_major_garbage_collections_ ; 
  int num_minor_garbage_collections_ ; 
  int locale_on_ ; 
  void * current_locale_name_ptr_ ; 
  int gensym_counter_ ; 
  struct Scheme_Object * dummy_input_port_ ; 
  struct Scheme_Object * dummy_output_port_ ; 
  struct Scheme_Hash_Table * opened_libs_ ; 
  struct mzrt_mutex * jit_lock_ ; 
  struct free_list_entry * free_list_ ; 
  int free_list_bucket_count_ ; 
  void * code_allocation_page_list_ ; 
  struct Scheme_Bucket_Table * prefab_table_ ; 
  struct Scheme_Hash_Table * place_local_symbol_table_ ; 
  struct Scheme_Hash_Table * place_local_keyword_table_ ; 
  struct Scheme_Hash_Table * place_local_parallel_symbol_table_ ; 
  struct Scheme_Bucket_Table * literal_string_table_ ; 
  struct Scheme_Bucket_Table * literal_number_table_ ; 
  struct FFI_Sync_Queue * ffi_sync_queue_ ; 
  struct Scheme_GC_Pre_Post_Callback_Desc * gc_prepost_callback_descs_ ; 
  struct Scheme_Hash_Table * place_local_misc_table_ ; 
  int place_evts_array_size_ ; 
  struct Evt * * place_evts_ ; 
  struct Scheme_Place_Object * place_object_ ; 
  struct Scheme_Place * all_child_places_ ; 
  struct Scheme_Place_Bi_Channel_Link * place_channel_links_ ; 
  struct Scheme_Object * * reusable_ifs_stack_ ; 
  struct Scheme_Object * group_member_cache_ ; 
  struct Scheme_Prefix * scheme_prefix_finalize_ ; 
  struct Scheme_Prefix * scheme_inc_prefix_finalize_ ; 
  struct Scheme_Hash_Table * loaded_extensions_ ; 
  struct Scheme_Hash_Table * fullpath_loaded_extensions_ ; 
  Scheme_Sleep_Proc scheme_place_sleep_ ; 
  struct Scheme_Object * thread_sleep_callback_ ; 
  int thread_sleep_callback_fd_ ; 
  struct GHBN_Thread_Data * ghbn_thread_data_ ; 
  Scheme_On_Atomic_Timeout_Proc on_atomic_timeout_ ; 
  void * on_atomic_timeout_data_ ; 
  int atomic_timeout_auto_suspend_ ; 
  int atomic_timeout_atomic_level_ ; 
  struct Scheme_Object * configuration_callback_cache_ [2 ] ; 
  struct FFI_Orig_Place_Call * cached_orig_place_todo_ ; 
  struct Scheme_Hash_Table * ffi_lock_ht_ ; 
  struct Scheme_Object * is_syntax_proc_ ; 
  struct Scheme_Object * expander_syntax_to_datum_proc_ ; 
  struct Scheme_Hash_Table * local_primitive_tables_ ; 
}
Thread_Local_Variables ; 
extern __thread Thread_Local_Variables scheme_thread_locals ; 
typedef void (* Scheme_Kill_Action_Func ) (void * ) ; 
typedef int (* Scheme_Frozen_Stack_Proc ) (void * ) ; 
enum {
  MZCONFIG_ENV , MZCONFIG_INPUT_PORT , MZCONFIG_OUTPUT_PORT , MZCONFIG_ERROR_PORT , MZCONFIG_ERROR_DISPLAY_HANDLER , MZCONFIG_ERROR_PRINT_VALUE_HANDLER , MZCONFIG_EXIT_HANDLER , MZCONFIG_INIT_EXN_HANDLER , MZCONFIG_PRINT_HANDLER , MZCONFIG_PROMPT_READ_HANDLER , MZCONFIG_READ_HANDLER , MZCONFIG_READ_INPUT_PORT_HANDLER , MZCONFIG_CASE_SENS , MZCONFIG_CAN_READ_PIPE_QUOTE , MZCONFIG_PRINT_GRAPH , MZCONFIG_PRINT_STRUCT , MZCONFIG_PRINT_BOX , MZCONFIG_PRINT_VEC_SHORTHAND , MZCONFIG_PRINT_HASH_TABLE , MZCONFIG_PRINT_UNREADABLE , MZCONFIG_PRINT_PAIR_CURLY , MZCONFIG_PRINT_MPAIR_CURLY , MZCONFIG_PRINT_SYNTAX_WIDTH , MZCONFIG_PRINT_READER , MZCONFIG_PRINT_LONG_BOOLEAN , MZCONFIG_PRINT_AS_QQ , MZCONFIG_ERROR_PRINT_WIDTH , MZCONFIG_ERROR_PRINT_CONTEXT_LENGTH , MZCONFIG_ERROR_ESCAPE_HANDLER , MZCONFIG_EXE_YIELD_HANDLER , MZCONFIG_ALLOW_SET_UNDEFINED , MZCONFIG_COMPILE_MODULE_CONSTS , MZCONFIG_USE_JIT , MZCONFIG_DISALLOW_INLINE , MZCONFIG_CUSTODIAN , MZCONFIG_INSPECTOR , MZCONFIG_CODE_INSPECTOR , MZCONFIG_PLUMBER , MZCONFIG_LOAD_DIRECTORY , MZCONFIG_WRITE_DIRECTORY , MZCONFIG_PORT_PRINT_HANDLER , MZCONFIG_LOAD_EXTENSION_HANDLER , MZCONFIG_CURRENT_DIRECTORY , MZCONFIG_CURRENT_ENV_VARS , MZCONFIG_FORCE_DELETE_PERMS , MZCONFIG_CURRENT_USER_DIRECTORY , MZCONFIG_RANDOM_STATE , MZCONFIG_CURRENT_MODULE_SRC , MZCONFIG_ERROR_PRINT_SRCLOC , MZCONFIG_CMDLINE_ARGS , MZCONFIG_LOCALE , MZCONFIG_SECURITY_GUARD , MZCONFIG_PORT_COUNT_LINES , MZCONFIG_SCHEDULER_RANDOM_STATE , MZCONFIG_THREAD_SET , MZCONFIG_THREAD_INIT_STACK_SIZE , MZCONFIG_SUBPROC_CUSTODIAN_MODE , MZCONFIG_SUBPROC_GROUP_ENABLED , MZCONFIG_LOAD_DELAY_ENABLED , MZCONFIG_DELAY_LOAD_INFO , MZCONFIG_LOGGER , __MZCONFIG_BUILTIN_COUNT__ }
; 
typedef struct Scheme_Input_Port Scheme_Input_Port ; 
typedef struct Scheme_Output_Port Scheme_Output_Port ; 
typedef struct Scheme_Port Scheme_Port ; 
typedef intptr_t (* Scheme_Get_String_Fun ) (Scheme_Input_Port * port , char * buffer , intptr_t offset , intptr_t size , int nonblock , Scheme_Object * unless ) ; 
typedef intptr_t (* Scheme_Peek_String_Fun ) (Scheme_Input_Port * port , char * buffer , intptr_t offset , intptr_t size , Scheme_Object * skip , int nonblock , Scheme_Object * unless ) ; 
typedef Scheme_Object * (* Scheme_Progress_Evt_Fun ) (Scheme_Input_Port * port ) ; 
typedef int (* Scheme_Peeked_Read_Fun ) (Scheme_Input_Port * port , intptr_t amount , Scheme_Object * unless_evt , Scheme_Object * target_ch ) ; 
typedef int (* Scheme_In_Ready_Fun ) (Scheme_Input_Port * port ) ; 
typedef void (* Scheme_Close_Input_Fun ) (Scheme_Input_Port * port ) ; 
typedef void (* Scheme_Need_Wakeup_Input_Fun ) (Scheme_Input_Port * , void * ) ; 
typedef Scheme_Object * (* Scheme_Location_Fun ) (Scheme_Port * ) ; 
typedef void (* Scheme_Count_Lines_Fun ) (Scheme_Port * ) ; 
typedef int (* Scheme_Buffer_Mode_Fun ) (Scheme_Port * , int m ) ; 
typedef Scheme_Object * (* Scheme_Write_String_Evt_Fun ) (Scheme_Output_Port * , const char * str , intptr_t offset , intptr_t size ) ; 
typedef intptr_t (* Scheme_Write_String_Fun ) (Scheme_Output_Port * , const char * str , intptr_t offset , intptr_t size , int rarely_block , int enable_break ) ; 
typedef int (* Scheme_Out_Ready_Fun ) (Scheme_Output_Port * port ) ; 
typedef void (* Scheme_Close_Output_Fun ) (Scheme_Output_Port * port ) ; 
typedef void (* Scheme_Need_Wakeup_Output_Fun ) (Scheme_Output_Port * , void * ) ; 
typedef Scheme_Object * (* Scheme_Write_Special_Evt_Fun ) (Scheme_Output_Port * , Scheme_Object * ) ; 
typedef int (* Scheme_Write_Special_Fun ) (Scheme_Output_Port * , Scheme_Object * , int nonblock ) ; 
struct Scheme_Port {
  Scheme_Object so ; 
  char count_lines , was_cr ; 
  intptr_t position , readpos , lineNumber , charsSinceNewline ; 
  intptr_t column , oldColumn ; 
  int utf8state ; 
  Scheme_Location_Fun location_fun ; 
  Scheme_Count_Lines_Fun count_lines_fun ; 
  Scheme_Buffer_Mode_Fun buffer_mode_fun ; 
  Scheme_Object * position_redirect ; 
}
; 
struct Scheme_Input_Port {
  struct Scheme_Port p ; 
  char slow ; 
  char closed , pending_eof ; 
  Scheme_Object * sub_type ; 
  Scheme_Object * closed_evt ; 
  Scheme_Custodian_Reference * mref ; 
  void * port_data ; 
  Scheme_Get_String_Fun get_string_fun ; 
  Scheme_Peek_String_Fun peek_string_fun ; 
  Scheme_Progress_Evt_Fun progress_evt_fun ; 
  Scheme_Peeked_Read_Fun peeked_read_fun ; 
  Scheme_In_Ready_Fun byte_ready_fun ; 
  Scheme_Close_Input_Fun close_fun ; 
  Scheme_Need_Wakeup_Input_Fun need_wakeup_fun ; 
  Scheme_Object * read_handler ; 
  Scheme_Object * name ; 
  Scheme_Object * peeked_read , * peeked_write ; 
  Scheme_Object * progress_evt , * input_lock , * input_giveup , * input_extras , * input_extras_ready ; 
  unsigned char ungotten [24 ] ; 
  int ungotten_count ; 
  Scheme_Object * special , * ungotten_special ; 
  Scheme_Object * unless , * unless_cache ; 
  struct Scheme_Output_Port * output_half ; 
}
; 
struct Scheme_Output_Port {
  struct Scheme_Port p ; 
  short closed ; 
  Scheme_Object * sub_type ; 
  Scheme_Object * closed_evt ; 
  Scheme_Custodian_Reference * mref ; 
  void * port_data ; 
  Scheme_Write_String_Evt_Fun write_string_evt_fun ; 
  Scheme_Write_String_Fun write_string_fun ; 
  Scheme_Close_Output_Fun close_fun ; 
  Scheme_Out_Ready_Fun ready_fun ; 
  Scheme_Need_Wakeup_Output_Fun need_wakeup_fun ; 
  Scheme_Write_Special_Evt_Fun write_special_evt_fun ; 
  Scheme_Write_Special_Fun write_special_fun ; 
  intptr_t pos ; 
  Scheme_Object * name ; 
  Scheme_Object * display_handler ; 
  Scheme_Object * write_handler ; 
  Scheme_Object * print_handler ; 
  struct Scheme_Input_Port * input_half ; 
}
; 
enum {
  MZEXN , MZEXN_FAIL , MZEXN_FAIL_CONTRACT , MZEXN_FAIL_CONTRACT_ARITY , MZEXN_FAIL_CONTRACT_DIVIDE_BY_ZERO , MZEXN_FAIL_CONTRACT_NON_FIXNUM_RESULT , MZEXN_FAIL_CONTRACT_CONTINUATION , MZEXN_FAIL_CONTRACT_VARIABLE , MZEXN_FAIL_READ , MZEXN_FAIL_READ_EOF , MZEXN_FAIL_READ_NON_CHAR , MZEXN_FAIL_FILESYSTEM , MZEXN_FAIL_FILESYSTEM_EXISTS , MZEXN_FAIL_FILESYSTEM_VERSION , MZEXN_FAIL_FILESYSTEM_ERRNO , MZEXN_FAIL_NETWORK , MZEXN_FAIL_NETWORK_ERRNO , MZEXN_FAIL_OUT_OF_MEMORY , MZEXN_FAIL_UNSUPPORTED , MZEXN_FAIL_USER , MZEXN_BREAK , MZEXN_BREAK_HANG_UP , MZEXN_BREAK_TERMINATE , MZEXN_OTHER }
; 
typedef struct Scheme_Logger Scheme_Logger ; 
struct NewGC ; 
typedef int (* Size_Proc ) (void * obj ) ; 
typedef int (* Size2_Proc ) (void * obj , struct NewGC * ) ; 
typedef int (* Mark_Proc ) (void * obj ) ; 
typedef int (* Mark2_Proc ) (void * obj , struct NewGC * ) ; 
typedef int (* Fixup_Proc ) (void * obj ) ; 
typedef int (* Fixup2_Proc ) (void * obj , struct NewGC * ) ; 
typedef void (* GC_collect_start_callback_Proc ) (void ) ; 
typedef void (* GC_collect_end_callback_Proc ) (void ) ; 
typedef void (* GC_collect_inform_callback_Proc ) (int master_gc , int major_gc , int inc_gc , intptr_t pre_used , intptr_t post_used , intptr_t pre_admin , intptr_t post_admin , intptr_t post_child_places_used ) ; 
typedef uintptr_t (* GC_get_thread_stack_base_Proc ) (void ) ; 
typedef void (* GC_Post_Propagate_Hook_Proc ) (struct NewGC * ) ; 
typedef int (* GC_Treat_As_Incremental_Mark_Proc ) (void * p ) ; 
typedef void (* Scheme_Signal_Handler_Proc ) (int ) ; 
struct mz_addrinfo {
  int ai_flags ; 
  int ai_family ; 
  int ai_socktype ; 
  int ai_protocol ; 
  size_t ai_addrlen ; 
  struct sockaddr * ai_addr ; 
  struct mz_addrinfo * ai_next ; 
}
; 
extern Scheme_Object scheme_eof [1 ] ; 
extern Scheme_Object scheme_null [1 ] ; 
extern Scheme_Object scheme_true [1 ] ; 
extern Scheme_Object scheme_false [1 ] ; 
extern Scheme_Object scheme_void [1 ] ; 
extern Scheme_Object scheme_undefined [1 ] ; 
extern unsigned short * scheme_uchar_table [] ; 
extern unsigned char * scheme_uchar_cases_table [] ; 
extern unsigned char * scheme_uchar_cats_table [] ; 
extern int scheme_uchar_ups [] ; 
extern int scheme_uchar_downs [] ; 
extern int scheme_uchar_titles [] ; 
extern int scheme_uchar_folds [] ; 
extern unsigned char scheme_uchar_combining_classes [] ; 
extern Scheme_Object * scheme_make_utf8_string (const char * chars ) ; 
extern void scheme_add_global (const char * name , Scheme_Object * val , Scheme_Env * env ) ; 
extern Scheme_Env * scheme_primitive_module (Scheme_Object * name , Scheme_Env * for_env ) ; 
extern void scheme_finish_primitive_module (Scheme_Env * env ) ; 
extern Scheme_Object * scheme_intern_symbol (const char * name ) ; 
extern Scheme_Object * scheme_initialize (Scheme_Env * global_env ) ; 
extern Scheme_Object * scheme_reload (Scheme_Env * global_env ) ; 
extern Scheme_Object * scheme_module_name (void ) ; 
Scheme_Object * scheme_initialize (Scheme_Env * global_env ) {
  Scheme_Env * mod_env ; 
  Scheme_Object * __funcarg108 = NULLED_OUT ; 
  Scheme_Object * __funcarg107 = NULLED_OUT ; 
  DECL_RET_SAVE (Scheme_Object * ) PREPARE_VAR_STACK_ONCE(2);
  BLOCK_SETUP_TOP((PUSH(mod_env, 0), PUSH(global_env, 1)));
# define XfOrM1_COUNT (2)
# define SETUP_XfOrM1(x) SETUP(XfOrM1_COUNT)
# define BLOCK_SETUP(x) BLOCK_SETUP_once(x)
# define FUNCCALL(s, x) FUNCCALL_once(s, x)
# define FUNCCALL_EMPTY(x) FUNCCALL_EMPTY_once(x)
# define FUNCCALL_AGAIN(x) FUNCCALL_AGAIN_once(x)
  mod_env = NULLED_OUT ; 
  mod_env = (__funcarg108 = FUNCCALL(SETUP_XfOrM1(_), scheme_intern_symbol ("hw" ) ), FUNCCALL_AGAIN(scheme_primitive_module (__funcarg108 , global_env ) )) ; 
  (__funcarg107 = FUNCCALL(SETUP_XfOrM1(_), scheme_make_utf8_string ("hello" ) ), FUNCCALL_AGAIN(scheme_add_global ("greeting" , __funcarg107 , mod_env ) )) ; 
  FUNCCALL_EMPTY(scheme_finish_primitive_module (mod_env ) ); 
  RET_VALUE_START (scheme_void ) RET_VALUE_END ; 
# undef BLOCK_SETUP
# undef FUNCCALL
# undef FUNCCALL_EMPTY
# undef FUNCCALL_AGAIN
}
Scheme_Object * scheme_reload (Scheme_Env * global_env ) {
  /* No conversion */
  return scheme_initialize (global_env ) ; 
}
Scheme_Object * scheme_module_name () {
  /* No conversion */
  return scheme_intern_symbol ("hw" ) ; 
}
