#include "racket/escheme.h"

Scheme_Object* scheme_initialize(Scheme_Env* global_env) {
    Scheme_Env* mod_env;
    mod_env = scheme_primitive_module(scheme_intern_symbol("hw"),
	    global_env);
    scheme_add_global("greeting", scheme_make_utf8_string("hello"), mod_env);
    scheme_finish_primitive_module(mod_env);
    return scheme_void;
}

Scheme_Object* scheme_reload(Scheme_Env* global_env) {
    return scheme_initialize(global_env);
}

Scheme_Object* scheme_module_name() {
    return scheme_intern_symbol("hw");
}
