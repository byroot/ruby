#include "ruby.h"
#include "ruby/encoding.h"

VALUE rb_fstring(VALUE str);
// VALUE rb_enc_interned_str(const char *ptr, long len, rb_encoding *enc);
// rb_encoding * rb_to_encoding(VALUE enc);

VALUE
bug_s_fstring(VALUE self, VALUE str)
{
    return rb_fstring(str);
}

VALUE
bug_s_rb_enc_interned_str(VALUE self, VALUE str, VALUE enc)
{
    const char *foo = "foo\0";
    return rb_enc_interned_str(foo, 4, rb_to_encoding(enc));
}

void
Init_string_fstring(VALUE klass)
{
    rb_define_singleton_method(klass, "fstring", bug_s_fstring, 1);
    rb_define_singleton_method(klass, "rb_enc_interned_str", bug_s_rb_enc_interned_str, 2);
}
